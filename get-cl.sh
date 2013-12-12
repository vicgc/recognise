#!/bin/bash - 
#===============================================================================
#
#          FILE: get-cl.sh
# 
#         USAGE: ./get-cl.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Ian Juma,
#  ORGANIZATION: Synod
#       CREATED: 12/12/2013 12:41:52 PM EAT
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error


wget -r -c --tries=2 http://registrationcenter.intel.com/irc_nas/3555/intel_sdk_for_ocl_applications_xe_2013_r2_sdk_3.1.1.11385_x64.tgz

tar zxvf intel_sdk_for_ocl_applications_xe_2013_r2_sdk_3.1.1.11385_x64.tgz

