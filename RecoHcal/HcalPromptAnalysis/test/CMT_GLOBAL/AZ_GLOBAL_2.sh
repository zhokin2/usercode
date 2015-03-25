#!/bin/bash

WebDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/GlobalRMT'
WebSite='https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/GlobalRMT'
HistoDir='/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos'

# print usage info
if [[ "$1" == "" ]]; then
  echo "Usage:"
  echo "  $0 [path]"
  echo "    [path] - place, where histo files are situated"
  echo "example: ./GLOBAL_2.sh /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos"
  exit
fi

# 1st parameter - path to directory
src=$1

# check, does directory exists
if [[ ! -d $src ]]; then
  echo "ERROR: Directory $src dosn't exists"
  exit 1
fi

# expand path to absolute
fullSrc=$(cd $src; pwd)

echo "Source directory: $fullSrc"

# list all root files:
list=""
totalFiles="0"

for i in $(ls -r $fullSrc/*.root); do
#for i in $(ls -t $fullSrc/*.root); do
#for i in $(ls -r $fullSrc/*.root); do
  let "totalFiles += 1"
  list="$list $i"
done

echo "Total files     : $totalFiles"

# check, do we have output .root files
if [[ "$totalFiles" == "0" ]] ; then
  echo "ERROR: No *.root files found"
  exit 1
fi

# print header to index.html 
echo `cat header_GLOBAL_RMT.txt`> index_draft.html

k=0
cmsenv
#make processing for each file in folder
for i in $list ; do
runnumber=$(echo $i | sed -e 's/[^0-9]*//g')
#runnumber=$(echo $i | awk -F 'run' '{print $2}'| awk -F '.' '{print $1}')
let "k = k + 1"
echo
echo
echo
echo 'RUN number ='$runnumber
echo 'RAW file = '`basename $i`
date=''
# extract the date of file
date=$(ls --full-time $fullSrc |grep `basename $i` |awk '{print $6}')

# extract run type, data, time and number of events
type='GLOBAL'
echo 'RUN Date = '$date
echo 'RUN Type = '$type
################################################
#processing
 if [[ "$runnumber" == 237239 ||"$runnumber" == 237243   ]] ; then
# if [[ "$runnumber" > 236904 ]] ; then
#if [[ "$runnumber" > 233900 ]] ; then
#if [[ "$runnumber" > 234641 ]] ; then
#if [[ "$runnumber" == 235060 || "$runnumber" == 235068 || "$runnumber" == 235172   ]] ; then
#if [[ "$runnumber" >  235700  ]] ; then
#if [[ "$runnumber" == 235062 || "$runnumber" == 235185 ]] ; then
#if [[ "$runnumber" == 235699 || "$runnumber" == 235192|| "$runnumber" == 235691 ]] ; then   mkdir $WebDir/GLOBAL_$runnumber 
#if [[ "$runnumber" == 235316  ]] ; then
#if [[ "$runnumber" == 234530 || "$runnumber" > 235837  ]] ; then
#if [[ "$runnumber" == 235843 || "$runnumber" == 236234 || "$runnumber" == 236250 || "$runnumber" == 236241 || "$runnumber" == 236356 || "$runnumber" == 236545 || "$runnumber" == 236767  ]] ; then


####################################################


   mkdir $WebDir/GLOBAL_$runnumber 



  # cmsRun remoteMonitoring_NZS_cfg.py $runnumber file:$i $HistoDir
  # root -b -q -l 'RemoteMonitoringGLOBAL.C+("'$HistoDir'/Global_'$runnumber'.root")'
  # root -b -q -l 'RemoteMonitoringMAP_Global.C+("'$HistoDir'/Global_'$runnumber'.root","'$HistoDir'/Global_'$runnumber'.root")'



   ./RemoteMonitoringMAP_Global.cc.exe "$HistoDir/Global_$runnumber.root" "$HistoDir/Global_$runnumber.root"
   mv *.html $WebDir/GLOBAL_$runnumber
   mv *.png $WebDir/GLOBAL_$runnumber
   mv $WebDir/GLOBAL_$runnumber/index_draft.html .
fi


#adding entry to list of file index_draft.html
let "raw = (k % 2) + 2"
echo '<tr>'>> index_draft.html
echo '<td class="s1" align="center">'$k'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runnumber'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$type'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$Nevents'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$date'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$time'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center"><a href="'$WebSite'/GLOBAL_'$runnumber'/MAP.html">GLOBAL_'$runnumber'</a></td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">OK</td>'>> index_draft.html
echo '</tr>'>> index_draft.html
prev=$i
done
# print footer to index.html 
echo `cat footer.txt`>> index_draft.html

mv index_draft.html $WebDir/index.html 

# check exit code
if [[ $? == 0 ]]; then
  echo "Successfully done!"
else
  rm $dst
  echo "ERROR: Processing failed!"
  exit 1
fi
