#!/bin/csh
if (${1} == "") then
echo "No input run list. Please use command: ./run_date.csh runsets"
exit
endif
rm "$1_sets"
touch "$1_sets"
foreach i (`cat $1`)
echo ${i}
./das_client.py --query="run=${i} | grep run.start_time" | grep 20 > tmp
set DATE=`cat tmp`
./das_client.py --query="run=${i} | grep run.end_time" | grep 20 > tmp
set DATE_End=`cat tmp`
./das_client.py --query="run=${i} | grep run.duration"  > tmp
set D=`cat tmp`
echo ${D} > tmp
set D=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.beam_e"  > tmp
set E=`cat tmp`
echo ${E} > tmp
set E=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.bfield"  > tmp
set B=`cat tmp`
echo ${B} > tmp
set B=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.nlumis"  > tmp
set nL=`cat tmp`
echo ${nL} > tmp
set nL=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.lhcFill" > tmp
set Fill=`cat tmp`
echo ${Fill} > tmp
set Fill=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.delivered_lumi" > tmp
set dLumi=`cat tmp`
echo ${dLumi} > tmp
set dLumi=`cat tmp | awk  '{print $13}' `
./das_client.py --query="run=${i} | grep run.group_name" > tmp
set GN=`cat tmp`
echo ${GN} > tmp
set GN=`cat tmp | awk  '{print $13}' `

echo ${i} ${DATE} ${DATE_End} ${D} ${E} ${B} ${nL} ${Fill} ${dLumi} ${GN} >> "$1_sets"
 rm tmp 
end
