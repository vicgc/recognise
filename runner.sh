#!/bin/bash - 
#===============================================================================
#
#          FILE: runner.sh
# 
#         USAGE: ./runner.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 12/01/2013 08:22:48 PM EAT
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

echo "am here, doing nothing"

chmod +x get-intel-ocl.sh
chmod +x get-cl.sh

./get-cl.sh
./get-intel-ocl.sh
