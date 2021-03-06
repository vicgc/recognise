#!/bin/bash - 
#          FILE: get-cl.sh
# 
#         USAGE: ./get-cl.sh 
set -o nounset


wget -r -c --tries=2 http://registrationcenter.intel.com/irc_nas/3555/intel_sdk_for_ocl_applications_xe_2013_r2_sdk_3.1.1.11385_x64.tgz

tar zxvf intel_sdk_for_ocl_applications_xe_2013_r2_sdk_3.1.1.11385_x64.tgz

cd intel_sdk_for_ocl_applications_xe_2013_r2_sdk_3.1.1.11385_x64


function fake() {
    fakeroot alien --to-deb opencl-1.2-intel-devel-3.1.1.11385-1.x86_64.rpm
    fakeroot alien --to-deb opencl-1.2-intel-mic-3.1.1.11385-1.x86_64.rpm
    fakeroot alien --to-deb opencl-1.2-base-3.1.1.11385-1.x86_64.rpm
    fakeroot alien --to-deb opencl-1.2-devel-3.1.1.11385-1.x86_64.rpm
    fakeroot alien --to-deb opencl-1.2-intel-cpu-3.1.1.11385-1.x86_64.rpm
}

function setDeps() {
    sudo dpkg -i opencl-1.2-base-3.1.1.11385-1.x86_64.deb
    sudo ln -s /usr/lib64/libOpenCL.so /usr/lib/libOpenCL.so
    sudo ldconfig
}

fake
setDeps
