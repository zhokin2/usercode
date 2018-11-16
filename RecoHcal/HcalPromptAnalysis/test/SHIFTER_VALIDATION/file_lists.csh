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
#dasgoclient --query="file dataset=/Cosmics/Commissioning2018-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#dasgoclient --query="file dataset=/MinimumBias/Commissioning2018-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
##
##
#dasgoclient --query="file dataset=/HcalNZS/Commissioning2017-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}

#dasgoclient --query="file dataset=/Cosmics/Run2017C-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#dasgoclient --query="file dataset=/ZeroBias/Run2018A-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#dasgoclient --query="file dataset=/ZeroBias/Run2018B-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#dasgoclient --query="file dataset=/ZeroBias/Run2018C-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}
#dasgoclient --query="file dataset=/ZeroBias/Run2018D-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}

#dasgoclient --query="file dataset=/HIHcalNZS/HIRun2018A-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}

# to many jobs if use this dataset:
###dasgoclient --query="file dataset=/HIMinimumBias0/HIRun2018A-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}

dasgoclient --query="file dataset=/L1Accept/HIRun2018A-v1/RAW run=${i}" --limit=0 | sed "s/\/store/\'\/store/g" | sed "s/root/root\',/g"> TXT_${1}/run_${i}

##
##

end
