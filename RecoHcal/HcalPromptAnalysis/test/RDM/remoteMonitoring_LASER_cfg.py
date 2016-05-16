#how to run: cmsRun remoteMonitoring_LED_cfg.py 211659 file:/afs/cern.ch/work/d/dtlisov/private/Monitoring/data /afs/cern.ch/work/d/dtlisov/private/Monitoring/histos
#how to run: cmsRun remoteMonitoring_LED_cfg.py 211659 /store/group/comm_hcal/USC /afs/cern.ch/work/d/dtlisov/private/Monitoring/histos

import sys
import FWCore.ParameterSet.Config as cms
process = cms.Process('OKRECO')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('RecoLocalCalo.Configuration.hcalLocalReco_cff')
#runnumber = sys.argv[2][4:-5]

runnumber = sys.argv[2]
rundir = sys.argv[3]
histodir = sys.argv[4]

print 'RUN = '+runnumber
print 'Input file = '+rundir+'/USC_'+runnumber+'.root'
print 'Output file = '+histodir+'/LED_'+runnumber+'.root'

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(1000)
  input = cms.untracked.int32(-1)
  )

#process.source = cms.Source("PoolSource",
process.source = cms.Source("HcalTBSource",
    fileNames = cms.untracked.vstring(
#	       'file:/afs/cern.ch/work/d/dtlisov/private/Monitoring/data/USC_209311.root'
#              '/store/group/comm_hcal/USC/USC_212179.root'
                rundir+'/USC_'+runnumber+'.root'
                ), 
    streams = cms.untracked.vstring(
		  "HCAL_Trigger",
		  "HCAL_DCC700","HCAL_DCC701","HCAL_DCC702","HCAL_DCC703","HCAL_DCC704","HCAL_DCC705",
		  "HCAL_DCC706","HCAL_DCC707","HCAL_DCC708","HCAL_DCC709","HCAL_DCC710","HCAL_DCC711",
		  "HCAL_DCC712","HCAL_DCC713","HCAL_DCC714","HCAL_DCC715","HCAL_DCC716","HCAL_DCC717",
		  "HCAL_DCC718","HCAL_DCC719","HCAL_DCC720","HCAL_DCC721","HCAL_DCC722","HCAL_DCC723",
		  "HCAL_DCC724","HCAL_DCC725","HCAL_DCC726","HCAL_DCC727","HCAL_DCC728","HCAL_DCC729",
		  "HCAL_DCC730","HCAL_DCC731"
		 )	
  )

process.Analyzer = cms.EDAnalyzer("VeRawAnalyzer",
                                  #
                                  Verbosity = cms.untracked.int32(0),
                                  #Verbosity = cms.untracked.int32(-84),
                                  #Verbosity = cms.untracked.int32(-91),
                                  #Verbosity = cms.untracked.int32(-92),
                                  #
                                  MapCreation = cms.untracked.int32(1),
                                  #
                                  recordNtuples = cms.untracked.bool(False),
                                  #recordNtuples = cms.untracked.bool(True),
                                  maxNeventsInNtuple = cms.int32(1),
                                  #
                                  #recordHistoes = cms.untracked.bool(False),
                                  recordHistoes = cms.untracked.bool(True),
                                  #
                                  ##scripts: zRunRatio34.C, zRunNbadchan.C
                                  studyRunDependenceHist = cms.untracked.bool(True),
                                  #studyRunDependenceHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zerrors.C
                                  studyCapIDErrorsHist = cms.untracked.bool(True),
                                  #studyCapIDErrorsHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zrms.C
                                  studyRMSshapeHist = cms.untracked.bool(True),
                                  #studyRMSshapeHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zratio34.C
                                  studyRatioShapeHist = cms.untracked.bool(True),
                                  #studyRatioShapeHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zadcamplitude.C
                                  studyADCAmplHist = cms.untracked.bool(True),
                                  #studyADCAmplHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: ztsmean.C
                                  studyTSmeanShapeHist = cms.untracked.bool(True),
                                  #studyTSmeanShapeHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: ztsmaxa.C
                                  studyTSmaxShapeHist = cms.untracked.bool(True),
                                  #studyTSmaxShapeHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zcalib....C
                                  studyCalibCellsHist = cms.untracked.bool(True),
                                  #studyCalibCellsHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zdifampl.C
                                  studyDiffAmplHist = cms.untracked.bool(True),
                                  #studyDiffAmplHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zadcamplitude.C
                                  studyPedestalsHist = cms.untracked.bool(True),
                                  #studyPedestalsHist = cms.untracked.bool(False),
                                  #
                                  ##scripts: zamplpedcorr.C
                                  studyPedestalCorrelations = cms.untracked.bool(True),
                                  #studyPedestalsHist = cms.untracked.bool(False),
                                  #
                                  #
                                  ##DigiCollectionLabel = cms.untracked.InputTag("hcalDigis"),
                                  #Verbosity = cms.untracked.int32(-54),
                                  #Verbosity = cms.untracked.int32(-22),
                                  #Verbosity = cms.untracked.int32(-11),
                                  #Verbosity = cms.untracked.int32(-12),
                                  #Verbosity = cms.untracked.int32(-13),
                                  #Verbosity = cms.untracked.int32(-51),
                                  #Verbosity = cms.untracked.int32(-24),
                                  #Verbosity = cms.untracked.int32(-244),
                                  #Verbosity = cms.untracked.int32(-233),
                                  #
                                  #
                                  #         Normal channels:
                                  #
                                  # -53 for  BAD HBHEHF channels from study on shape Ratio
                                  #Verbosity = cms.untracked.int32(-53),
                                  ratioHBMin = cms.double(0.50),
                                  ratioHBMax = cms.double(1.00),
                                  ratioHEMin = cms.double(0.55),
                                  ratioHEMax = cms.double(1.00),
                                  ratioHFMin = cms.double(0.60),
                                  ratioHFMax = cms.double(1.02),
                                  ratioHOMin = cms.double(0.55),
                                  ratioHOMax = cms.double(1.04),
                                  # -54 for  BAD HBHEHF channels from study on RMS of shapes
                                  #Verbosity = cms.untracked.int32(-54),
                                  rmsHBMin = cms.double(0.3),
                                  rmsHBMax = cms.double(2.5),
                                  rmsHEMin = cms.double(0.9),
                                  rmsHEMax = cms.double(3.6),
                                  rmsHFMin = cms.double(0.2),
                                  rmsHFMax = cms.double(2.1),
                                  rmsHOMin = cms.double(0.2),
                                  rmsHOMax = cms.double(2.6),
                                  # -55 for  BAD HBHEHF channels from study on TSmean of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSmeanHBMin = cms.double(5.0),
                                  TSmeanHBMax = cms.double(7.5),
                                  TSmeanHEMin = cms.double(2.5),
                                  TSmeanHEMax = cms.double(6.5),
                                  TSmeanHFMin = cms.double(5.5),
                                  TSmeanHFMax = cms.double(8.5),
                                  TSmeanHOMin = cms.double(1.5),
                                  TSmeanHOMax = cms.double(4.4),
                                  # -55 for  BAD HBHEHF channels from study on TSmax of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSpeakHBMin = cms.double(1.5),
                                  TSpeakHBMax = cms.double(8.5),
                                  TSpeakHEMin = cms.double(1.5),
                                  TSpeakHEMax = cms.double(8.5),
                                  TSpeakHFMin = cms.double(1.5),
                                  TSpeakHFMax = cms.double(8.5),
                                  TSpeakHOMin = cms.double(1.5),
                                  TSpeakHOMax = cms.double(6.5),
                                  # -56 for  BAD HBHEHOHF channels from study on ADC Amplitude
                                  #Verbosity = cms.untracked.int32(-56),
                                  ADCAmplHBMin = cms.double(40.),
                                  ADCAmplHBMax = cms.double(3500.),
                                  ADCAmplHEMin = cms.double(40.),
                                  ADCAmplHEMax = cms.double(3500.),
                                  ADCAmplHFMin = cms.double(40.),
                                  ADCAmplHFMax = cms.double(3500.),
                                  ADCAmplHOMin = cms.double(100.),
                                  ADCAmplHOMax = cms.double(3500.),
                                  #
                                  # to see channels w/ PedestalSigma < cut
                                  #Verbosity = cms.untracked.int32(-57),
                                  pedestalwHBMax = cms.double(0.1),
                                  pedestalwHEMax = cms.double(0.1),
                                  pedestalwHFMax = cms.double(0.4),
                                  pedestalwHOMax = cms.double(0.1),
                                  #
                                  # to see channels for pedestal < cut
                                  pedestalHBMax = cms.double(0.1),
                                  pedestalHEMax = cms.double(0.6),
                                  pedestalHFMax = cms.double(0.8),
                                  pedestalHOMax = cms.double(0.1),
                                  #
                                  #
                                  #             CALIBRATION channels:
                                  #
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on ADC amplitude
                                  # cuts for Laser runs:
                                  #calibrADCHBMin = cms.double(15.0),
                                  #calibrADCHEMin = cms.double(15.0),
                                  #calibrADCHOMin = cms.double(15.0),
                                  #calibrADCHFMin = cms.double(15.0),
                                  # cuts for LED runs:
                                  calibrADCHBMin = cms.double(1000.),
                                  calibrADCHBMax = cms.double(100000000.),
                                  calibrADCHEMin = cms.double(1000.),
                                  calibrADCHEMax = cms.double(100000000.),
                                  calibrADCHOMin = cms.double(1000.),
                                  calibrADCHOMax = cms.double(100000000.),
                                  calibrADCHFMin = cms.double(100.),
                                  calibrADCHFMax = cms.double(100000000.),
                                  # for  BAD HBHEHOHF CALIBRATION channels
                                  calibrRatioHBMin = cms.double(0.76),
                                  calibrRatioHBMax = cms.double(0.94),
                                  calibrRatioHEMin = cms.double(0.76),
                                  calibrRatioHEMax = cms.double(0.94),
                                  calibrRatioHOMin = cms.double(0.85),
                                  calibrRatioHOMax = cms.double(0.99),
                                  calibrRatioHFMin = cms.double(0.5),
                                  calibrRatioHFMax = cms.double(0.8),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on TSmax
                                  calibrTSmaxHBMin = cms.double(0.50),
                                  calibrTSmaxHBMax = cms.double(8.50),
                                  calibrTSmaxHEMin = cms.double(0.50),
                                  calibrTSmaxHEMax = cms.double(8.50),
                                  calibrTSmaxHOMin = cms.double(0.50),
                                  calibrTSmaxHOMax = cms.double(8.50),
                                  calibrTSmaxHFMin = cms.double(0.50),
                                  calibrTSmaxHFMax = cms.double(9.50),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on TSmean
                                  calibrTSmeanHBMin = cms.double(1.00),
                                  calibrTSmeanHBMax = cms.double(5.50),
                                  calibrTSmeanHEMin = cms.double(1.00),
                                  calibrTSmeanHEMax = cms.double(5.50),
                                  calibrTSmeanHOMin = cms.double(1.00),
                                  calibrTSmeanHOMax = cms.double(3.50),
                                  calibrTSmeanHFMin = cms.double(1.00),
                                  calibrTSmeanHFMax = cms.double(5.20),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on Width
                                  calibrWidthHBMin = cms.double(1.00),
                                  calibrWidthHBMax = cms.double(2.30),
                                  calibrWidthHEMin = cms.double(1.00),
                                  calibrWidthHEMax = cms.double(2.30),
                                  calibrWidthHOMin = cms.double(0.50),
                                  calibrWidthHOMax = cms.double(3.00),
                                  calibrWidthHFMin = cms.double(0.20),
                                  calibrWidthHFMax = cms.double(2.30),
                                  #
                                  # Special task of run or LS quality:
                                  #
                                  # flag for ask runs of LSs for RMT & CMT accordingly:
                                  #=0-runs, =1-LSs
                                  # keep for LED runs this flags =0 always
                                  flagtoaskrunsorls = cms.int32(0),
                                  #
                                  # flag for choice of criterion of bad channels:
                                  #=0-CapIdErr, =1-Ratio, =2-Width, =3-TSmax, =4-TSmean, =5-adcAmplitud
                                  # keep for CMT (global runs) this flags =0 always
                                  flagtodefinebadchannel = cms.int32(0),
                                  #how many bins you want on the plots:better to choice (#LS+1)
                                  howmanybinsonplots = cms.int32(25),
                                  #
                                  #
                                  flagabortgaprejected = cms.int32(1),
                                  bcnrejectedlow = cms.int32(3446),
                                  bcnrejectedhigh= cms.int32(3564),
                                  #
                                  # flag cpu time reducing
                                  #=0-all plots, =1-optimized number of plots  (for Global runs)
                                  flagcpuoptimization = cms.int32(0),
                                  #
                                  # flag for ask type of Normalization for CMT estimators:
                                  #=0-normalizationOn#evOfLS;   =1-averageVariable-normalizationOn#entriesInLS;
                                  flagestimatornormalization = cms.int32(1),
                                  #
                                  #
                                  # cuts on Nbadchannels to see LS dependences:
                                  # Verbosity = cms.untracked.int32(-77),
                                  # to select abnormal events,for which Nbcs > this limits
                                  lsdep_cut1_peak_HBdepth1 = cms.int32(20),
                                  lsdep_cut1_peak_HBdepth2 = cms.int32(7),
                                  lsdep_cut1_peak_HEdepth1 = cms.int32(16),
                                  lsdep_cut1_peak_HEdepth2 = cms.int32(13),
                                  lsdep_cut1_peak_HEdepth3 = cms.int32(4),
                                  lsdep_cut1_peak_HFdepth1 = cms.int32(10),
                                  lsdep_cut1_peak_HFdepth2 = cms.int32(5),
                                  lsdep_cut1_peak_HOdepth4 = cms.int32(45),
                                  # to select events with Nbcs > this limits
                                  lsdep_cut3_max_HBdepth1 = cms.int32(19),
                                  lsdep_cut3_max_HBdepth2 = cms.int32(6),
                                  lsdep_cut3_max_HEdepth1 = cms.int32(15),
                                  lsdep_cut3_max_HEdepth2 = cms.int32(12),
                                  lsdep_cut3_max_HEdepth3 = cms.int32(3),
                                  lsdep_cut3_max_HFdepth1 = cms.int32(9),
                                  lsdep_cut3_max_HFdepth2 = cms.int32(4),
                                  lsdep_cut3_max_HOdepth4 = cms.int32(40),
                                  #
                                  #
                                  #old was for runs:
                                  #                                  nbadchannels1 = cms.int32(7),
                                  #                                  nbadchannels2 = cms.int32(12),
                                  #                                  nbadchannels3 = cms.int32(50),
                                  #
                                  #Verbosity = cms.untracked.int32(-79),
                                  # cuts on Estimator1 to see LS dependences:
                                  lsdep_estimator1_HBdepth1 = cms.double(2500.),
                                  lsdep_estimator1_HBdepth2 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth1 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth2 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth3 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth1 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth2 = cms.double(2500.),
                                  lsdep_estimator1_HOdepth4 = cms.double(2500.),
                                  # cuts on Estimator2 to see LS dependences:
                                  lsdep_estimator2_HBdepth1 = cms.double(7.),
                                  lsdep_estimator2_HBdepth2 = cms.double(7.),
                                  lsdep_estimator2_HEdepth1 = cms.double(7.),
                                  lsdep_estimator2_HEdepth2 = cms.double(7.),
                                  lsdep_estimator2_HEdepth3 = cms.double(7.),
                                  lsdep_estimator2_HFdepth1 = cms.double(7.),
                                  lsdep_estimator2_HFdepth2 = cms.double(7.),
                                  lsdep_estimator2_HOdepth4 = cms.double(7.),
                                  # cuts on Estimator3 to see LS dependences:
                                  lsdep_estimator3_HBdepth1 = cms.double(7.),
                                  lsdep_estimator3_HBdepth2 = cms.double(7.),
                                  lsdep_estimator3_HEdepth1 = cms.double(7.),
                                  lsdep_estimator3_HEdepth2 = cms.double(7.),
                                  lsdep_estimator3_HEdepth3 = cms.double(7.),
                                  lsdep_estimator3_HFdepth1 = cms.double(7.),
                                  lsdep_estimator3_HFdepth2 = cms.double(7.),
                                  lsdep_estimator3_HOdepth4 = cms.double(7.),
                                  # cuts on Estimator4 to see LS dependences:
                                  lsdep_estimator4_HBdepth1 = cms.double(5.),
                                  lsdep_estimator4_HBdepth2 = cms.double(5.),
                                  lsdep_estimator4_HEdepth1 = cms.double(5.),
                                  lsdep_estimator4_HEdepth2 = cms.double(5.),
                                  lsdep_estimator4_HEdepth3 = cms.double(5.),
                                  lsdep_estimator4_HFdepth1 = cms.double(5.),
                                  lsdep_estimator4_HFdepth2 = cms.double(5.),
                                  lsdep_estimator4_HOdepth4 = cms.double(5.),
                                  # cuts on Estimator5 to see LS dependences:
                                  lsdep_estimator5_HBdepth1 = cms.double(1.8),
                                  lsdep_estimator5_HBdepth2 = cms.double(1.8),
                                  lsdep_estimator5_HEdepth1 = cms.double(1.8),
                                  lsdep_estimator5_HEdepth2 = cms.double(1.8),
                                  lsdep_estimator5_HEdepth3 = cms.double(1.8),
                                  lsdep_estimator5_HFdepth1 = cms.double(1.8),
                                  lsdep_estimator5_HFdepth2 = cms.double(1.8),
                                  lsdep_estimator5_HOdepth4 = cms.double(1.8),
                                  #
                                  # 
                                  #Verbosity = cms.untracked.int32(-81),
                                  #Verbosity = cms.untracked.int32(-82),
                                  #Verbosity = cms.untracked.int32(-83),
                                  # 
                                  # use ADC amplitude:
                                  useADCmassive = cms.untracked.bool(True),
                                  useADCfC = cms.untracked.bool(False),
                                  useADCcounts = cms.untracked.bool(False),
                                  # 
                                  # Pedestals in fC
                                  #usePedestalSubtraction = cms.untracked.bool(True),
                                  usePedestalSubtraction = cms.untracked.bool(False),
                                  #
                                  # for possible ignoring of channels w/o signal, apply same cut for
                                  # HBHEHFHO on Amplitude, usable for all Estimators 1,2,3,4,5:
                                  # forallestimators_amplitude_bigger = cms.double(10.),
                                  forallestimators_amplitude_bigger = cms.double(-100.),
                                  #
                                  #
                                  #
                                  #usecontinuousnumbering = cms.untracked.bool(False),
                                  usecontinuousnumbering = cms.untracked.bool(True),
                                  #
                                  #
                                  splashesUpperLimit = cms.int32(10000),
                                  #
                                  #
                                  #
                                  hcalCalibDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hbheDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hoDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hfDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  #
                                  #
                                   #
                                  #
                                  #
                                  HistOutFile = cms.untracked.string(histodir+'/LED_'+runnumber+'.root'),
#                                  HistOutFile = cms.untracked.string('testLaser178165.root'),
#                                  HistOutFile = cms.untracked.string('testLaser141849.root'),
#                                  HistOutFile = cms.untracked.string('testLaser133070.root'),
#                                  HistOutFile = cms.untracked.string('testLaser211875.root'),
                                  MAPOutFile = cms.untracked.string('LogEleMapdb.h')
                                  #
                                  ##OutputFilePath = cms.string('/tmp/zhokin/'),        
                                  ##OutputFileExt = cms.string(''),
                                  #
                                  )		



process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
  )
				
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v8', '')

process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.hcalDigis.FilterDataQuality = cms.bool(False)
process.hcalDigis.InputLabel = cms.InputTag("source")


process.p = cms.Path(process.hcalDigis*process.Analyzer)

process.MessageLogger = cms.Service("MessageLogger",
     categories   = cms.untracked.vstring(''),
     destinations = cms.untracked.vstring('cout'),
     debugModules = cms.untracked.vstring('*'),
     cout = cms.untracked.PSet(
         threshold = cms.untracked.string('WARNING'),
	 WARNING = cms.untracked.PSet(limit = cms.untracked.int32(0))
     )
 )



