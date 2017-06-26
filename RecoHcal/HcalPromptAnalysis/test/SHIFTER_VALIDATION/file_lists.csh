#!/bin/tcsh
rm TXT_${1}/*
if (${1} == "") then
echo "No input run list. Please use command: ./file_lists.csh runsets"
exit
endif

foreach i (`cat $1`)
echo ${i}
##
##
##./das_client.py --query="file dataset=/ZeroBias/Run2017A-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
##
./das_client.py --query="file dataset=/ZeroBias/Run2017B-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
##
##
#./das_client.py --query="file dataset=/HcalNZS/Commissioning2017-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#./das_client.py --query="file dataset=/MinimumBias/Commissioning2017-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
##
##

end
