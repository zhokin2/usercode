# how to find input file:  eos ls -latr /eos/cms/store/data/Run2018A/HcalNZS/RAW/v1/000/316/
#how to run: cmsRun remoteMonitoring_Global_PSM_test_cfg.py
#-------------------------------------------------------------------------------------------
import sys
import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras
#process = cms.Process("TEST", eras.Run2_2018)
process = cms.Process("TEST", eras.Run3)
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("CondCore.CondDB.CondDB_cfi")
process.load("EventFilter.L1GlobalTriggerRawToDigi.l1GtUnpack_cfi")
process.l1GtUnpack.DaqGtInputTag = 'source'
#----------------------------------------------------------------------------
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
#----------------------------------------------------------------------------
process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(1000)
    input = cms.untracked.int32(-1)
)



#----------------------------------------------------------------------------
# Input source
process.source = cms.Source("PoolSource",
	       	skipBadFiles=cms.untracked.bool(True),	
    fileNames = cms.untracked.vstring(
