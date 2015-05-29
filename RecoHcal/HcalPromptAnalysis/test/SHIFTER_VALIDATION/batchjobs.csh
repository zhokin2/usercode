#!/bin/csh
echo ${1} ${2} ${3}
setenv MYWORKDIR `pwd`
### Definitions
#setenv SRC /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21/src/RecoHcal/HcalPromptAnalysis/test
#setenv SCRIPTDIR ${SRC}/SHIFTER_VALIDATION/ 
setenv SRC ${3}
setenv SCRIPTDIR ${3}
##setenv SCRAM_ARCH slc6_amd64_gcc472
setenv SCRAM_ARCH slc6_amd64_gcc491

### Environment
cd ${SRC}
cmsenv

### Go back to WN
cd ${MYWORKDIR}
cp ${SRC}/PYTHON_${1}/Reco_${2}_cfg.py .
### Run CMSSW
cmsRun Reco_${2}_cfg.py > &log_${2}
ls * >> &log_${2}.txt

### Copy output files to EOS
 
cmsStage -f log_${2}.txt /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/CMT/histos/Logs/
cmsStage -f Global.root /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/CMT/histos/Global_${2}.root

## rm all unnesecery

rm log_${2}.txt 
rm Global.root

