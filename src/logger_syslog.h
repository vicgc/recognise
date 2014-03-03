#include <syslog.h>
#include <unistd.h>
#include "gcc_attributes.h"

#include <stdarg.h>

__noreturn __pure void glogger(int log_L) {
    setlogmask(LOG_UPTO (LOG_NOTICE));
    openlog("TERMlogger", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog(LOG_NOTICE, "PROGRAM %d", getuid());
    syslog(log_L, "PID -> %d", getpid());
    syslog(log_L, "Debug >- -- -<");

    closelog();

}

__noreturn __pure void logger() {

    setlogmask(LOG_UPTO (LOG_NOTICE));
    openlog("TERMlogger", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog(LOG_NOTICE, "Program started by User %d", getuid ());
    syslog(LOG_INFO, "PID -> %d", getpid());
    syslog(LOG_INFO, "Debug --CRITICAL");

    closelog();
}


__noreturn __pure void errorLogger() {

	setlogmask(LOG_UPTO (LOG_NOTICE));
    openlog("TERMlogger", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog(LOG_ERR, "Program started by User %d", getuid ());
    syslog(LOG_DEBUG, "Check error on Event");

    syslog(LOG_INFO, "PID -> %d", getpid());
    syslog(LOG_INFO, "Debug --CRITICAL");

    closelog();
}
