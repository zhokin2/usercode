#!/bin/csh

### set DAT=`date '+%Y-%m-%d_%H_%M_%S'`
set DAT="2015-03-22_14_15_47"
### Get list of done from RDM webpage ###
set TYPE=${1}
echo ${TYPE}
if( ${TYPE} != "LED" && ${TYPE} != "LASER" && ${TYPE} != "PEDESTAL" ) then
echo "Please check type " ${TYPE} "should be LED or LASER or PEDESTAL"
exit
endif

set WD='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21_STABLE/src/RecoHcal/HcalPromptAnalysis/test/RDM'

#${WD}/myselect.csh ${DAT}
ls ${WD}/${TYPE}_LIST/runlist.tmp.${DAT}

set jold=194165
foreach i (`cat ${WD}/${TYPE}_LIST/runlist.tmp.${DAT}`)
set iold=`echo ${i} | awk -F _ '{print $1}'`
set jold=`echo ${i} | awk -F _ '{print $2}'`
set year=`echo ${i} | awk -F _ '{print $3}' | awk -F - '{print $1}'`
set nevent=`echo ${i} | awk -F _ '{print $5}'`
echo ${iold} ${jold} ${year}
#if( ${year} == "2011" ) then
if( ${nevent} >= "500") then  
echo  "Start job "
##${WD}/HcalRemoteMonitoringNewt.csh ${iold} ${DAT} ${jold} ${nevent}
ls ${WD}/HcalRemoteMonitoringNewNew.csh
/afs/cern.ch/cms/caf/scripts/cmsbsub -q 8nh -o ${WD}/LOG1/batchlog_${iold}.log -e ${WD}/LOG1/ebatchlog_${iold}.log ${WD}/HcalRemoteMonitoringNewNew.csh ${iold} ${DAT} ${jold} ${nevent} ${TYPE}
echo  "End job "
sleep 30
endif
end
