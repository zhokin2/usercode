#!/bin/csh

set WebDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb'
set WD='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMScript/CMSSW_5_3_21/src/RecoHcal/HcalPromptAnalysis/test/RDM'

#set PREV=`cat ${WebDir}/index.html | grep 'class="s1"' | tail -1 | awk -F ">" '{print $2}' | awk -F "<" '{print $1}'`
#sed '$d' < ${WebDir}/index.html > ${WD}/index_test.html
#set j=${PREV}
#echo "Last record" ${PREV} >> ${WD}/LOG/log

touch ${WD}/index_test.html
cat ${WD}/header.txt >> ${WD}/index_test.html
ls ${WebDir} | grep LED_ | sort -r > ${WD}/currentlist

set j=0
foreach i (`cat ${WD}/currentlist`)
@ j = ${j} + "1"
cat ${WebDir}/${i}/index_draft.html | sed s/ktemp/${j}/ >> ${WD}/index_test.html
end

cat ${WD}/footer.txt >> ${WD}/index_test.html
mv ${WebDir}/index.html ${WebDir}/index.html.orig
mv ${WD}/index_test.html ${WebDir}/index.html
rm ${WD}/currentlist

