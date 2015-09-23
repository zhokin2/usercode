#!/bin/bash

WebDir='/store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring'
WebSite='https://cms-conddb-dev.cern.ch/eosweb/hcal/HcalRemoteMonitoring'
HistoDir='/store/group/dpg_hcal/comm_hcal/www/HcalRemoteMonitoring/CMT/histos'

# print usage info
if [[ "$1" == "" ]]; then
  echo "Usage:"
  echo "  $0 [file] [comment]"
  echo "    [file] - file with run numbers"
  echo "example: ./GLOBAL.sh Run_List.txt TestRuns"
  exit
fi

cmsenv

k=0

echo 
echo 
echo 
echo 'Run numbers for processing:'
cat $1

#processing

for i in $(cat $1); do

runnumber=$i

# if [[ "$runnumber" > 233890 ]] ; then
    echo 
    echo 
    echo
    echo  "Run for processing $runnumber"
    echo  "file=root://eoscms//cms/$HistoDir/Global_$runnumber.root"
    xrdcp root://eoscms//eos/cms/$HistoDir/Global_$runnumber.root Global_$runnumber.root 
    
    #CMT processing
    ./RemoteMonitoringGLOBAL.cc.exe Global_$runnumber.root
    cmsMkdir $WebDir/CMT/GLOBAL_$runnumber
    cmsStage -f HELP.html $WebDir/CMT
    for j in $(ls -r *.html); do
       cat $j | sed 's#cms-cpt-software.web.cern.ch\/cms-cpt-software\/General\/Validation\/SVSuite#cms-conddb-dev.cern.ch\/eosweb\/hcal#g'> tmp.html
       cmsStage -f tmp.html $WebDir/CMT/GLOBAL_$runnumber/$j
       rm tmp.html
    done
    for j in $(ls -r *.png); do
       cmsStage -f $j $WebDir/CMT/GLOBAL_$runnumber
    done 

    rm *.html
    rm *.png    

    #RMT processing
    ./RemoteMonitoringMAP_Global.cc.exe Global_$runnumber.root Global_$runnumber.root
    cmsMkdir $WebDir/GlobalRMT/GLOBAL_$runnumber
    cmsStage -f HELP.html $WebDir/GlobalRMT
    for j in $(ls -r *.html); do
       cat $j | sed 's#cms-cpt-software.web.cern.ch\/cms-cpt-software\/General\/Validation\/SVSuite#cms-conddb-dev.cern.ch\/eosweb\/hcal#g'> tmp.html
       cmsStage -f tmp.html $WebDir/GlobalRMT/GLOBAL_$runnumber/$j
       rm tmp.html
    done
    for j in $(ls -r *.png); do
       cmsStage -f $j $WebDir/GlobalRMT/GLOBAL_$runnumber
    done 

    rm *.html
    rm *.png
   
#fi

done

cmsLs $HistoDir | grep root | awk  '{print $5}' | awk -F / '{print $10}' > rtmp

cat rtmp | awk -F _ '{print $2}' | awk -F . '{print $1}' > _runlist_
rm rtmp
echo 
echo 
echo 
echo 'Run numbers:'
cat _runlist_

#making table


# print header to index.html 
echo `cat header_GLOBAL_EOS.txt`> index_draft.html

#extract run numners
for i in $(cat _runlist_); do
 
#runnumber=$(echo $i | sed -e 's/[^0-9]*//g')
#runnumber=$(echo $i | awk -F 'run' '{print $2}'| awk -F '.' '{print $1}')
runnumber=${i}
#if [[ "$runnumber" > 243400 ]] ; then
let "k = k + 1"
echo
echo
echo
echo 'RUN number = '$runnumber

# extract the date of file
./das_client.py --query="run=${i} | grep run.beam_e,run.bfield,run.nlumis,run.lhcFill,run.delivered_lumi,run.duration,run.start_time,run.end_time" --limit=0 > tmp

#cat tmp
date=`cat tmp | awk '{print $7" "$8}'`
date_end=`cat tmp | awk '{print $9" "$10}'`
E=`cat tmp | awk '{print $1}'`
B=`cat tmp | awk '{print $2}'`
nL=`cat tmp | awk '{print $3}'`
Fill=`cat tmp | awk '{print $4}'`
dLumi=`cat tmp | awk '{print $5}'`
D=`cat tmp | awk '{print $6}'`
rm tmp

#cmsLs $HistoDir/Global_$i.root | awk '{print $3" "$4}'

Date_obr=`cmsLs $HistoDir/Global_$i.root | awk '{print $3" "$4}'`

# extract run type, data, time and number of events
type='Cosmic'
commentariy=''
#cat runs_info

#  for j in $(cat runs_info); do
#    echo $j
#    k= `echo $j | awk  '{print $1}'`
#    if [[ "$runnumber" == "$k" ]] ; then
#      type= `echo $i | awk  '{print $2}'`
#      commentariy=`echo $i | awk  '{print $3}'`
#    fi
#  done

#echo 'RUN Type = '$type
echo 'RUN Start Date = '$date
echo 'RUN Duration = '$D
echo 'RUN End Date = '$date_end
echo 'RUN Energy = '$E
echo 'RUN Magnet field = '$B
echo 'RUN LS number = '$nL
echo 'RUN LHC Fill = '$Fill
echo 'RUN Delivered Luminosity = '$dLumi
echo 'RUN Date processing = '$Date_obr
#echo 'RUN Comment = '$commentariy


#adding entry to list of file index_draft.html
let "raw = (k % 2) + 2"
echo '<tr>'>> index_draft.html
echo '<td class="s1" align="center">'$k'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$runnumber'</td>'>> index_draft.html
#echo '<td class="s'$raw'" align="center">'$type'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$nL'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$Fill'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$date'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$D'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$date_end'</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center"><a href="'$WebSite'/CMT/GLOBAL_'$runnumber'/LumiList.html">CMT_'$runnumber'</a></td>'>> index_draft.html
echo '<td class="s'$raw'" align="center"><a href="'$WebSite'/GlobalRMT/GLOBAL_'$runnumber'/MAP.html">RMT_'$runnumber'</a></td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$B' T</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$E' GeV</td>'>> index_draft.html
#echo '<td class="s'$raw'" align="center">'$dLumi' /nb</td>'>> index_draft.html
echo '<td class="s'$raw'" align="center">'$Date_obr' /nb</td>'>> index_draft.html
#echo '<td class="s'$raw'" align="center">'$commentariy'</td>'>> index_draft.html
echo '</tr>'>> index_draft.html
prev=$i

#fi
done


# print footer to index.html 
echo `cat footer.txt`>> index_draft.html

cmsStage -f index_draft.html $WebDir/CMT/index.html 
rm index_draft.html

# delete temp files

rm *.root
rm _runlist_

# check exit code
if [[ $? == 0 ]]; then
  echo "Successfully done!"
else
  rm $dst
  echo "ERROR: Processing failed!"
  exit 1
fi
