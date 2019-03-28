#!/bin/csh
###############################################################################
###############
# to create dir. with py files, use: ./mkcfg_new.csh runlist_3  
# and then, if PYTHON_runlist_3 exist, use: 
#     ./run_interactive.csh runlist_3 
#  from main dir., changing 2 lines below: 
#set nn1=1
#set nn2=3
set nn1=36
set nn2=37
#set nn1=38
#set nn2=40
echo ${nn1} ${nn2} 
echo "Start..."
###############
#./mkcfg_new.csh ${1}
#ls PYTHON_${1}/*py
###############
################################################################ loop:
set nn=0
if( ${status} == "0" ) then
foreach i (`ls PYTHON_${1}`)

set j=`echo ${i} | awk -F _ '{print $2}'`
set k=`echo ${i} | awk -F _ '{print $3}'`


@ nn = ${nn} + "1"
#echo ${i} ${j} ${k} ${1} ${nn} 
#echo ${k} ${nn} 

if( ${nn} >= ${nn1} && ${nn} <= ${nn2}   ) then
#if( ${k} >= ${nn1} && ${k} <= ${nn2}   ) then
echo ${nn} ${k}
cmsRun PYTHON_${1}/Reco_${j}_${k}_cfg.py > CMTLOG/log_${j}_${k} &
endif

################################################################
end
else
##echo "Problem: No jobs are created: check PYTHON_${1} directory: Notify developpers"
endif

