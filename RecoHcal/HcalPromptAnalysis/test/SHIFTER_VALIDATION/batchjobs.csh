#!/bin/csh
echo ${1} ${2}
setenv MYWORKDIR `pwd`
### Definitions
setenv SRC /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21/src/RecoHcal/HcalPromptAnalysis/test
setenv SCRIPTDIR ${SRC}/SHIFTER_VALIDATION/ 
setenv SCRAM_ARCH slc6_amd64_gcc472

### Environment
cd ${SRC}
cmsenv

### Go back to WN
cd ${MYWORKDIR}
cp ${SRC}/SHIFTER_VALIDATION/PYTHON_${1}/Reco_${2}_cfg.py .

### Run CMSSW
cmsRun Reco_${2}_cfg.py > &log_${2}
ls * >> &log_${2}.txt

### Copy output files to EOS
 
cmsStage log_${2}.txt /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/CMT/histos/Logs/
cmsStage Global.root /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/CMT/histos/Global_${2}.root

## rm all unnesecery

rm log_*.txt 
rm Global.root

