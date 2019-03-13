#!/bin/csh

set CALIB=LASER


set WebDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb'
set WebSite='https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/RMT'



foreach j (`cat ledlist`)

foreach i (`ls *.html`)
cat ${i} | sed s/LED/LASER/g > ${i}_t
mv ${i}_t ${i} 
end

ls *.png
if(${status} == "0") then

cp *.html $WebDir/${CALIB}_$runnumber 
cp *.png $WebDir/${CALIB}_$runnumber 

mv $WebDir/${CALIB}_$runnumber/index_draft.html $WebDir/${CALIB}_$runnumber/index_draft.html.orig
cp index_draft.html $WebDir/${CALIB}_$runnumber

eos mkdir /eos/cms/store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
foreach i (`ls *.html`)
cat ${i} | sed 's#cms-cpt-software.web.cern.ch\/cms-cpt-software\/General\/Validation\/SVSuite#cms-conddb-dev.cern.ch\/eosweb\/hcal#g'> ${i}.n
xrdcp ${i}.n /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
end
foreach k (`ls *.png`)
xrdcp ${k} /store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/RMT/${CALIB}_$runnumber
end
endif
cd ..
end
cd /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_10_4_0/src/RecoHcal/HcalPromptAnalysis/test/RDM

