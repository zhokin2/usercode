#!/bin/csh

set runnumber=${1}
set refnumber=${3}
set runNevents=${4}
set CALIB=${5}

set fullSrc0='/store/group/dpg_hcal/comm_hcal/USC'
set fullSrc1='/store/group/dpg_hcal/comm_hcal/LS1'
set fullSrc='NO'
set WebDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb'
set WebSite='https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/RMT'
set HistoDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos'
set WD='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21/src/RecoHcal/HcalPromptAnalysis/test/RDM'

echo ${runnumber} >> ${WD}/LOG/batchlog
grep -q ${runnumber} ${WD}/${CALIB}_LIST/fullSrc0_list_${2}
if( ${status} == "0" ) then
set fullSrc=${fullSrc0}
endif

grep -q ${runnumber} ${WD}/${CALIB}_LIST/fullSrc1_list_${2}
if( ${status} == "0" ) then
set fullSrc=${fullSrc1}
endif

if( ${fullSrc} == "NO" ) then
echo "No Batch submission" ${runnumber} >> ${WD}/LOG/batchlog
exit
endif

echo "Batch submission" ${fullSrc} " " ${runnumber} >> ${WD}/LOG/batchlog

###exit

### We are at working node
mkdir ${runnumber}
setenv WORK `pwd`/${runnumber}

cd /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21/src/RecoHcal/HcalPromptAnalysis/test
cmsenv
cp remoteMonitoring_LED_cfg.py ${WORK}
cp RemoteMonitoringMAP.cc ${WORK}
cp compile.csh ${WORK}
cp LogEleMapdb.h ${WORK}
cp RDM/${CALIB}_LIST/runlist.tmp0.${2} ${WORK}/runlist.tmp

cd ${WORK}

#### cmsRun Start
### Temporarily
#rm LOG/log_${runnumber}
#rm ${HistoDir}/${CALIB}_${runnumber}.root

echo " Start CMS run ">${WD}/LOG/log_${runnumber}
echo ${LD_LIBRARY_PATH} >>${WD}/LOG/log_${runnumber}

cmsRun remoteMonitoring_LED_cfg.py ${runnumber} ${fullSrc} ${HistoDir} >> & ${WD}/LOG/log_${runnumber}

echo " After CMS run ">>${WD}/LOG/log_${runnumber}
rm -rf ${WebDir}/${CALIB}_${runnumber} 
mkdir ${WebDir}/${CALIB}_${runnumber} >> & ${WD}/LOG/log_${runnumber}
./compile.csh RemoteMonitoringMAP.cc  >> & ${WD}/LOG/log_${runnumber}
./RemoteMonitoringMAP.cc.exe "${HistoDir}/${CALIB}_${runnumber}.root" "${HistoDir}/${CALIB}_${refnumber}.root"

##root -b -q -l 'RemoteMonitoringMAP.C+("'${HistoDir}'/${CALIB}_'${runnumber}'.root","'${HistoDir}'/${CALIB}_'${refnumber}'.root")'
ls -l >> ${WD}/LOG/log_${runnumber}
echo " Start copy png " >> & ${WD}/LOG/log_${runnumber}
ls $WebDir/${CALIB}_$runnumber  >> & ${WD}/LOG/log_${runnumber}
cp *.html $WebDir/${CALIB}_$runnumber  >> & ${WD}/LOG/log_${runnumber}
cp *.png $WebDir/${CALIB}_$runnumber  >> & ${WD}/LOG/log_${runnumber}

#### CmsRun end

### extract the date of file
### set rundate=`cmsLs $fullSrc | grep ${1} | awk '{print $3}'`

set j=`cat runlist.tmp | grep ${runnumber}`
echo ${j} >> ${WD}/LOG/batchlog    
setenv runtype `echo $j | awk -F - '{print $13}'`
setenv runHTML `echo $j | awk -F - '{print $25}' | awk -F 'href=' '{print $2}'`
setenv runday `echo $j | awk -F - '{print $19}'`
setenv runmonth `echo $j | awk -F - '{print $18}'`
setenv runyear `echo $j | awk -F - '{print $17}'`
setenv runtime `echo $j | awk -F - '{print $20}'`
setenv rundate ${runday}"."${runmonth}"."${runyear} 
#wget ${runHTML} >> ${WD}/LOG/batchlog
#setenv runNevents `cat index.html | tail -n +14 | head -n 1 | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`
#rm index.html

echo 'RUN Date = '${rundate} ${runtime} >> ${WD}/LOG/batchlog    
echo 'RUN Type = '${runtype} >> ${WD}/LOG/batchlog    
echo 'Reference RUN number ='${refnumber} >> ${WD}/LOG/batchlog    

touch index_draft.html

#adding entry to list of file index_draft.html

####sed '$d' < /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/index.html > index.html.tmp

set raw=3
echo '<tr>'>> index_draft.html
echo '<td class="s1" align="center">'ktemp'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runnumber'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runtype'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runNevents'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$rundate'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runtime'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$refnumber'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center"><a href="'$WebSite'/${CALIB}_'$runnumber'/MAP.html">${CALIB}_'$runnumber'</a></td>'>> index_draft.html
echo '<td class="s'$raw'" align="center"><a href="'$runHTML'">DetDiag_'$runnumber'</a></td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">OK</td>'>> index_draft.html
echo '</tr>'>> index_draft.html

#######touch $WebDir/${CALIB}_$runnumber/new
####### Copy to the new site in parallel
ls *.png
if(${status} == "0") then
#### Copy to the old site
mv $WebDir/${CALIB}_$runnumber/index_draft.html $WebDir/${CALIB}_$runnumber/index_draft.html.orig
cp index_draft.html $WebDir/${CALIB}_$runnumber
#### Copy to the new site
cmsMkdir /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
cat index_draft.html | sed 's#cms-cpt-software.web.cern.ch\/cms-cpt-software\/General\/Validation\/SVSuite#cms-conddb-dev.cern.ch\/eosweb\/hcal#g'> index_draft.html.n
cmsStage index_draft.html.n /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
foreach k (`ls *.png`)
cmsStage ${k} /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
end
endif



