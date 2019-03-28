#!/bin/tcsh
echo "Starting job on " `date` #Date/time of start of job
echo "Running on: `uname -a`" #Condor job is running on this node
echo "System software: `cat /etc/redhat-release`" #Operating System on that node
source /cvmfs/cms.cern.ch/cmsset_default.csh  ## if a bash script, use .sh instead of .csh

echo "myStart run_condor.csh"

echo "myStart: set dir pwd"
#echo "myStart: set dirs /afs/cern.ch/work/z/zhokin/hcal/soc7/CMSSW_10_4_0/src/RecoHcal/HcalPromptAnalysis/test/SHIFTER_VALIDATION and pwd"
#set my=`/afs/cern.ch/work/z/zhokin/hcal/soc7/CMSSW_10_4_0/src/RecoHcal/HcalPromptAnalysis/test/SHIFTER_VALIDATION`
#set my=`pwd`
set m=`pwd`


cd ${m}
#setenv MYWORKDIR ${m}/TMP_`date '+%Y-%m-%d_%H_%M_%S'`
#mkdir ${m}/TMP_`date '+%Y-%m-%d_%H_%M_%S'`
### Definitions
#setenv SRC ${my}
#setenv SCRIPTDIR ${my}
setenv SCRAM_ARCH slc6_amd64_gcc700
scram p -s CMSSW CMSSW_10_4_0
cd CMSSW_10_4_0/src 

mkdir RecoHcal
cd RecoHcal

mkdir HcalPromptAnalysis
cd HcalPromptAnalysis
mv ../../../../BuildFile* .
ls
mkdir src
mv ../../../../VeRawAnalyzer.cc src/.

cd src
ls
eval `scramv1 runtime -csh` # cmsenv is an alias not on the workers
echo "myStart: scram b"
scram b 
echo "myStart: scram b DONE"

cd -
mkdir test
cd test
cp ../../../../../* .
ls

#cp * CMSSW_10_4_0/src/.

#mv run_condor.csh CMSSW_10_4_0/src/.
#mv mkcfg_new120.csh CMSSW_10_4_0/src/.
#mv file_lists.csh CMSSW_10_4_0/src/.
#mv a.py.beg CMSSW_10_4_0/src/.
#mv a.py.end CMSSW_10_4_0/src/.
#mv runlist_3 CMSSW_10_4_0/src/.

#mv VeRawAnalyzer.cc CMSSW_10_4_0/src/.
#mv BuildFile* CMSSW_10_4_0/src/.

setenv X509_USER_PROXY ${4}
voms-proxy-info -all
voms-proxy-info -all -file ${4}

./mkcfg_new120.csh ${1}
ls PYTHON_${1}/*py

################################################################
echo "myStart: loop in run_condor.csh"
if( ${status} == "0" ) then
foreach i (`ls PYTHON_${1}`)

set j=`echo ${i} | awk -F _ '{print $2}'`
set k=`echo ${i} | awk -F _ '{print $3}'`

echo ${m} ${1} ${i} ${j} ${k} 

##condor_submit condor.jdl ${1} ${j} ${k}  ${m}
##bsub -q 8nh batchjobs120.csh ${1} ${j} ${k} `pwd`

### Run CMSSW
###cmsRun Reco_${j}_${k}_cfg.py > &log_${j}_${k}
eval `scramv1 runtime -csh` # cmsenv is an alias not on the workers 
cmsRun PYTHON_${1}/Reco_${j}_${k}_cfg.py 

#mv Global_${j}_${k}.root 
#ls -l * >> &log_${j}_${k}

### Copy output files to EOS
### xrdcp -f Global_${j}_${k}.root /eos/cms/store/user/zhokin/CMT/test/Global_${j}_${k}.root
# current:
#eoscp Global_${j}_${k}.root /eos/cms/store/user/zhokin/CMT/RootFilesToBeMarched/Global_${j}_${k}.root
##eoscp log_${j}_${k} /eos/cms/store/user/zhokin/CMT/RootFilesToBeMarched/log_${j}_${k}
##eoscp LogEleMapdb.h /eos/cms/store/user/zhokin/CMT/RootFilesToBeMarched/MAP/LogEleMapdb_${j}_${k}.h

# test:
eoscp Global_${j}_${k}.root /eos/cms/store/user/zhokin/CMT/test/Global_${j}_${k}.root
#eoscp log_${j}_${k} /eos/cms/store/user/zhokin/CMT/test/log_${j}_${k}
#eoscp LogEleMapdb.h /eos/cms/store/user/zhokin/CMT/test/MAP/LogEleMapdb_${j}_${k}.h

## rm all unnesecery
#rm log_${j}_${k}
#rm Global_${j}_${k}.root

################################################################
end
#rm -rf PYTHON_${1}
#rm -rf TXT_${1}
#rm Reco_*_cfg.py
else
echo "Problem: No jobs are created: check PYTHON_${1} directory: Notify developpers"
endif

