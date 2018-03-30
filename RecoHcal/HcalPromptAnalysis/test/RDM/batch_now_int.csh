#!/bin/csh


set valdas=${1}
if( ${1} == "PEDESTAL" ) then
set valdas=pedestal
endif

if( ${1} == "LASER" ) then
set valdas=laser
endif

echo ${valdas}
###2017-03-17_10_24_06
set DAT="2017-03-20_09_36_54"

set RELEASE=CMSSW_10_1_0
### Get list of done from RDM webpage ###
set TYPE=${1}
echo ${TYPE}
if( ${TYPE} != "LED" && ${TYPE} != "LASER" && ${TYPE} != "PEDESTAL" ) then
echo "Please check type " ${TYPE} "should be LED or LASER or PEDESTAL"
exit
endif

set WD="/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/${RELEASE}/src/RecoHcal/HcalPromptAnalysis/test/RDM"

#${WD}/parce_newsql_valdas.csh ${valdas} ${DAT}
ls ${WD}/${TYPE}_LIST/runlist.tmp.${DAT}

set jold=194165
foreach i (`cat ${WD}/${TYPE}_LIST/runlist.tmp.${DAT}`)
echo "Run" ${i}

set iold=`echo ${i} | awk -F _ '{print $1}'`
set jold=`echo ${i} | awk -F _ '{print $2}'`
set year=`echo ${i} | awk -F _ '{print $3}' | awk -F - '{print $1}'`
set nevent=`echo ${i} | awk -F _ '{print $5}'`
echo ${iold} ${jold} ${year} ${nevent}
if( ${nevent} != "None" ) then
echo "Start " ${nevent}
if( ${nevent} >= "500" && ${nevent} < "1000000") then  
echo  "Start job " ${nevent}
${WD}/HcalRemoteMonitoringNewNew.csh ${iold} ${DAT} ${jold} ${nevent} ${TYPE} 
echo  "End job "
sleep 1
endif
endif
end
