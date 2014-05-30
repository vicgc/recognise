#!/bin/bash
# setup template

function check_install {
    if [ -z "`which "$1" 2>/dev/null`" ]
    then
        executable=$1
        shift
        while [ -n "$1" ]
        do
            DEBIAN_FRONTEND=noninteractive apt-get -q -y install "$1"
            print_info "$1 installed for $executable"
            shift
        done
    else
        print_warn "$2 already installed"
    fi
}

function install_libprotobuf {
    apt-get install libprotobuf-c0-dev
}

function check_remove {
    if [ -n "`which "$1" 2>/dev/null`" ]
    then
        DEBIAN_FRONTEND=noninteractive apt-get -q -y remove --purge "$2"
        print_info "$2 removed"
    else
        print_warn "$2 is not installed"
    fi
}

function check_sanity {
    # Do some sanity checking.
    if [ $(/usr/bin/id -u) != "0" ]
    then
        die 'Must be run by root user'
    fi

    if [ ! -f /etc/debian_version ]
    then
        die "Distribution is not supported"
    fi
}

function die {
    echo "ERROR: $1" > /dev/null 1>&2
    exit 1
}

function get_domain_name() {
    # Getting rid of the lowest part.
    domain=${1%.*}
    lowest=`expr "$domain" : '.*\.\([a-z][a-z]*\)'`
    case "$lowest" in
    com|net|org|gov|edu|co)
        domain=${domain%.*}
        ;;
    esac
    lowest=`expr "$domain" : '.*\.\([a-z][a-z]*\)'`
    [ -z "$lowest" ] && echo "$domain" || echo "$lowest"
}

function get_password() {
    # Check whether our local salt is present.
    SALT=/var/lib/radom_salt
    if [ ! -f "$SALT" ]
    then
        head -c 512 /dev/urandom > "$SALT"
        chmod 400 "$SALT"
    fi
    password=`(cat "$SALT"; echo $1) | md5sum | base64`
    echo ${password:0:13}
}

function install_dash {
    check_install dash dash
    rm -f /bin/sh
    ln -s dash /bin/sh
}


function install_redis {
    apt-get -q -y install redis-server
    apt-get install libpq-dev
    apt-get install libpq5
}

function install_dropbear {
    check_install dropbear dropbear
    check_install /usr/sbin/xinetd xinetd

    # Disable SSH
    touch /etc/ssh/sshd_not_to_be_run
    invoke-rc.d ssh stop

    # Enable dropbear to start. We are going to use xinetd as it is just
    # easier to configure and might be used for other things.
    cat > /etc/xinetd.d/dropbear <<END
service ssh
{
    socket_type     = stream
    only_from       = 0.0.0.0
    wait            = no
    user            = root
    protocol        = tcp
    server          = /usr/sbin/dropbear
    server_args     = -i
    disable         = no
}
END
    invoke-rc.d xinetd restart
}

function install_exim4 {
    check_install mail exim4
    if [ -f /etc/exim4/update-exim4.conf.conf ]
    then
        sed -i \
            "s/dc_eximconfig_configtype='local'/dc_eximconfig_configtype='internet'/" \
            /etc/exim4/update-exim4.conf.conf
        invoke-rc.d exim4 restart
    fi
}

function install_nginx {
    check_install nginx nginx

    # Need to increase the bucket size for Debian 5.
    cat > /etc/nginx/conf.d/lowendbox.conf <<END
server_names_hash_bucket_size 64;
END

    invoke-rc.d nginx restart
}

function install_syslogd {
    # We just need a simple vanilla syslogd. Also there is no need to log to
    # so many files (waste of fd). Just dump them into
    # /var/log/(cron/mail/messages)
    check_install /usr/sbin/syslogd inetutils-syslogd
    invoke-rc.d inetutils-syslogd stop

    for file in /var/log/*.log /var/log/mail.* /var/log/debug /var/log/syslog
    do
        [ -f "$file" ] && rm -f "$file"
    done
    for dir in fsck news
    do
        [ -d "/var/log/$dir" ] && rm -rf "/var/log/$dir"
    done

    cat > /etc/syslog.conf <<END
*.*;mail.none;cron.none -/var/log/messages
cron.*                  -/var/log/cron
mail.*                  -/var/log/mail
END

    [ -d /etc/logrotate.d ] || mkdir -p /etc/logrotate.d
    cat > /etc/logrotate.d/inetutils-syslogd <<END
/var/log/cron
/var/log/mail
/var/log/messages {
   rotate 4
   weekly
   missingok
   notifempty
   compress
   sharedscripts
   postrotate
      /etc/init.d/inetutils-syslogd reload >/dev/null
   endscript
}
END

    invoke-rc.d inetutils-syslogd start
}

function print_info {
    echo -n -e '\e[1;36m'
    echo -n $1
    echo -e '\e[0m'
}

function print_warn {
    echo -n -e '\e[1;33m'
    echo -n $1
    echo -e '\e[0m'
}

function remove_unneeded {
    # Some Debian have portmap installed. We don't need that.
    check_remove /sbin/portmap portmap

    # Remove rsyslogd, which allocates ~30MB privvmpages on an OpenVZ system,
    # which might make some low-end VPS inoperatable. We will do this even
    # before running apt-get update.
    check_remove /usr/sbin/rsyslogd rsyslog

    # Other packages that seem to be pretty common in standard OpenVZ
    # templates.
    check_remove /usr/sbin/apache2 'apache2*'
    check_remove /usr/sbin/named bind9
    check_remove /usr/sbin/smbd 'samba*'
    check_remove /usr/sbin/nscd nscd

    # Need to stop sendmail as removing the package does not seem to stop it.
    if [ -f /usr/lib/sm.bin/smtpd ]
    then
        invoke-rc.d sendmail stop
        check_remove /usr/lib/sm.bin/smtpd 'sendmail*'
    fi
}

function update_upgrade {
    # Run through the apt-get update/upgrade first. This should be done before
    # we try to install any package
    apt-get -q -y update
    apt-get -q -y upgrade
}

function config_network {

    sudo apt-get -q -y install bridge-utils hostapd avahi-daemon udhcpd

    wget http://www.daveconroy.com/wp3/wp-content/uploads/2013/07/hostapd.zip
    unzip hostapd.zip
    sudo rm  /usr/sbin/hostapd
    sudo mv hostapd /usr/sbin/hostapd.edimax
    sudo ln -sf /usr/sbin/hostapd.edimax /usr/sbin/hostapd
    sudo chown root.root /usr/sbin/hostapd
    sudo chmod 755 /usr/sbin/hostapd

    cat > "/etc/network/interfaces" <<END
auto lo

iface lo inet loopback
iface eth0 inet dhcp

iface wlan0 inet static
address 10.0.10.1
netmask 255.255.255.0

up iptables-restore < /etc/iptables.ipv4.nat
END

    cat > "/etc/hostapd/hostapd.conf" <<END
# Open network setup

interface=wlan0
driver=rtl871xdrv
ssid=VS-Pi Connect

#sets the mode of wifi, depends upon the devices you will be using. It can be a,b,g,n. Setting to g ensures backward compatiblity.
hw_mode=g

# Set the wi-fi channel:
channel=6

#Sets authentication algorithm
#1 - only open system authentication
auth_algs=1

wmm_enabled=0
END

    cat > "/etc/udhcpd.conf" <<END
start		10.0.10.10
end		10.0.10.200
interface	wlan0
remaining	yes
opt	dns	8.8.8.8 8.8.4.4 # Google Public DNS servers
option	subnet	255.255.255.0
opt	router	10.0.10.1
option	domain	local
option	lease	864000
END

    cat > "/etc/iptables.ipv4.nat" <<END

*filter
:INPUT ACCEPT [149:13529]
:FORWARD ACCEPT [0:0]
:OUTPUT ACCEPT [22:2208]
-A FORWARD -i eth0 -o wlan0 -m state --state RELATED,ESTABLISHED -j ACCEPT
-A FORWARD -i wlan0 -o eth0 -j ACCEPT
COMMIT
*nat
:PREROUTING ACCEPT [75:5274]
:INPUT ACCEPT [75:5274]
:OUTPUT ACCEPT [3:268]
:POSTROUTING ACCEPT [0:0]
-A POSTROUTING -o eth0 -j MASQUERADE
COMMIT
END
  sudo rm /etc/default/udhcpd
  echo -e "DHCPD_OPTS='-S'" > /etc/default/udhcpd
  sudo update-rc.d udhcpd enable
  echo -e "DAEMON_CONF='/etc/hostapd/hostapd.conf'" >> /etc/default/hostapd
  sudo update-rc.d hostapd enable

echo -e "vspi" > /etc/hostname
echo -e "127.0.0.1    vspi" > /etc/hosts
sudo /etc/init.d/hostname.sh

}

########################################################################
# START OF PROGRAM
########################################################################
export PATH=/bin:/usr/bin:/sbin:/usr/sbin

check_sanity
update_upgrade
install_nginx
remove_unneeded
install_syslogd
install_redis
vspi.local
config_network
sudo reboot
