# choose run in /store/group/dpg_hcal/comm_hcal/USC/run291959/
#how to run: cmsRun remoteMonitoring_LASER_TEST_cfg.py 
import sys
import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras
process = cms.Process('TEST',eras.Run2_2017 )

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('RecoLocalCalo.Configuration.hcalLocalReco_cff')

#runnumber = sys.argv[2][4:-5]
#
#runnumber = sys.argv[2]
#rundir = sys.argv[3]
#histodir = sys.argv[4]

#print 'RUN = '+runnumber
#print 'Input file = '+rundir+'/USC_'+runnumber+'.root'
#print 'Output file = '+histodir+'/LED_'+runnumber+'.root'

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(1000)
  input = cms.untracked.int32(-1)
  )

# readme: on lxplus:
# eos ls /store/group/dpg_hcal/comm_hcal/USC/
# eos ls /store/group/dpg_hcal/comm_hcal/USC/run309445
#result is  USC_309445.root

#process.source = cms.Source("PoolSource",
process.source = cms.Source("HcalTBSource",
    fileNames = cms.untracked.vstring(
#	       'file:/afs/cern.ch/work/d/dtlisov/private/Monitoring/data/USC_209311.root'
#              '/store/group/comm_hcal/USC/USC_212179.root'
#                rundir+'/USC_'+runnumber+'.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run307782/USC_307782.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run307826/USC_307826.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run307856/USC_307856.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run307892/USC_307892.root'
#
### 
#                '/store/group/dpg_hcal/comm_hcal/USC/run307971/USC_307971.root'
                '/store/group/dpg_hcal/comm_hcal/USC/run308701/USC_308701.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run308234/USC_308234.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run308383/USC_308383.root'

#                '/store/group/dpg_hcal/comm_hcal/USC/run308543/USC_308543.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run308882/USC_308882.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run309064/USC_309064.root'

#                '/store/group/dpg_hcal/comm_hcal/USC/run308786/USC_308786.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run309592/USC_309592.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run309821/USC_309821.root'
#
#               '/store/group/dpg_hcal/comm_hcal/USC/run309669/USC_309669.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309672/USC_309672.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run309676/USC_309676.root'
#            
#               '/store/group/dpg_hcal/comm_hcal/USC/run309573/USC_309573.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309924/USC_309924.root'
#            
#               '/store/group/dpg_hcal/comm_hcal/USC/run310262/USC_310262.root'
#              '/store/group/dpg_hcal/comm_hcal/USC/run310268/USC_310268.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310403/USC_310403.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310410/USC_310410.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310427/USC_310427.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310452/USC_310452.root'
#              '/store/group/dpg_hcal/comm_hcal/USC/run310454/USC_310454.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310456/USC_310456.root'
#
#               '/store/group/dpg_hcal/comm_hcal/USC/run308784/USC_308784.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run308882/USC_308882.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309237/USC_309237.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309238/USC_309238.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309318/USC_309318.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309321/USC_309321.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309370/USC_309370.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309573/USC_309573.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run309704/USC_309704.root'
#
#               '/store/group/dpg_hcal/comm_hcal/USC/run310847/USC_310847.root'
#                '/store/group/dpg_hcal/comm_hcal/USC/run310973/USC_310973.root'
#
#               '/store/group/dpg_hcal/comm_hcal/USC/run310244/USC_310244.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310387/USC_310387.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run310587/USC_310587.root'
#              '/store/group/dpg_hcal/comm_hcal/USC/run310650/USC_310650.root'
#
#               '/store/group/dpg_hcal/comm_hcal/USC/run311369/USC_311369.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run311413/USC_311413.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run311457/USC_311457.root'
#               '/store/group/dpg_hcal/comm_hcal/USC/run311566/USC_311566.root'


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
                                  ratioHBMin = cms.double(0.70),
                                  ratioHBMax = cms.double(0.94),
                                  ratioHEMin = cms.double(0.60),
                                  ratioHEMax = cms.double(0.95),
                                  ratioHFMin = cms.double(0.45),
                                  ratioHFMax = cms.double(1.02),
                                  ratioHOMin = cms.double(0.40),
                                  ratioHOMax = cms.double(1.04),
                                  # -54 for  BAD HBHEHF channels from study on RMS of shapes
                                  #Verbosity = cms.untracked.int32(-54),
                                  rmsHBMin = cms.double(0.7),
                                  rmsHBMax = cms.double(2.5),
                                  rmsHEMin = cms.double(0.7),
                                  rmsHEMax = cms.double(2.2),
                                  rmsHFMin = cms.double(0.1),
                                  rmsHFMax = cms.double(2.6),
                                  rmsHOMin = cms.double(0.1),
                                  rmsHOMax = cms.double(2.8),
                                  # -55 for  BAD HBHEHF channels from study on TSmean of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSmeanHBMin = cms.double(2.5),
                                  TSmeanHBMax = cms.double(5.5),
                                  TSmeanHEMin = cms.double(1.0),
                                  TSmeanHEMax = cms.double(5.2),
                                  TSmeanHFMin = cms.double(1.0),
                                  TSmeanHFMax = cms.double(4.2),
                                  TSmeanHOMin = cms.double(1.0),
                                  TSmeanHOMax = cms.double(4.8),
                                  # -55 for  BAD HBHEHF channels from study on TSmax of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSpeakHBMin = cms.double(2.2),
                                  TSpeakHBMax = cms.double(5.5),
                                  TSpeakHEMin = cms.double(1.5),
                                  TSpeakHEMax = cms.double(6.5),
                                  TSpeakHFMin = cms.double(0.5),
                                  TSpeakHFMax = cms.double(4.5),
                                  TSpeakHOMin = cms.double(0.5),
                                  TSpeakHOMax = cms.double(7.5),
                                  # -56 for  BAD HBHEHOHF channels from study on ADC Amplitude
                                  #Verbosity = cms.untracked.int32(-56),
                                  ADCAmplHBMin = cms.double(100.),
                                  ADCAmplHBMax = cms.double(3000.),
                                  ADCAmplHEMin = cms.double(70.),
                                  ADCAmplHEMax = cms.double(3000.),
                                  ADCAmplHFMin = cms.double(30.),
                                  ADCAmplHFMax = cms.double(3000.),
                                  ADCAmplHOMin = cms.double(40.),
                                  ADCAmplHOMax = cms.double(3000.),
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
				  
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on shape Ratio
                                  calibrRatioHBMin = cms.double(0.76),
				  calibrRatioHBMax = cms.double(0.94),
                                  calibrRatioHEMin = cms.double(0.76),
				  calibrRatioHEMax = cms.double(0.94),
                                  calibrRatioHOMin = cms.double(0.85),
				  calibrRatioHOMax = cms.double(0.99),
                                  calibrRatioHFMin = cms.double(0.5),
				  calibrRatioHFMax = cms.double(0.8),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on TSmax
                                  calibrTSmaxHBMin = cms.double(1.50),
                                  calibrTSmaxHBMax = cms.double(2.50),
                                  calibrTSmaxHEMin = cms.double(1.50),
                                  calibrTSmaxHEMax = cms.double(2.50),
                                  calibrTSmaxHOMin = cms.double(1.50),
                                  calibrTSmaxHOMax = cms.double(2.50),
                                  calibrTSmaxHFMin = cms.double(3.50),
                                  calibrTSmaxHFMax = cms.double(4.50),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on TSmean
                                  calibrTSmeanHBMin = cms.double(2.40),
                                  calibrTSmeanHBMax = cms.double(3.70),
                                  calibrTSmeanHEMin = cms.double(2.40),
                                  calibrTSmeanHEMax = cms.double(3.70),
                                  calibrTSmeanHOMin = cms.double(1.50),
                                  calibrTSmeanHOMax = cms.double(2.70),
                                  calibrTSmeanHFMin = cms.double(3.50),
                                  calibrTSmeanHFMax = cms.double(4.50),
                                  # for  BAD HBHEHOHF CALIBRATION channels from study on Width
                                  calibrWidthHBMin = cms.double(1.30),
                                  calibrWidthHBMax = cms.double(1.90),
                                  calibrWidthHEMin = cms.double(1.30),
                                  calibrWidthHEMax = cms.double(1.90),
                                  calibrWidthHOMin = cms.double(0.70),
                                  calibrWidthHOMax = cms.double(1.65),
                                  calibrWidthHFMin = cms.double(0.30),
                                  calibrWidthHFMax = cms.double(1.50),
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
                                  #=0-all plots, =1-optimized number of plots (for Global runs)
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
                                  lsdep_estimator1_HEdepth4 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth5 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth6 = cms.double(2500.),
                                  lsdep_estimator1_HEdepth7 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth1 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth2 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth3 = cms.double(2500.),
                                  lsdep_estimator1_HFdepth4 = cms.double(2500.),
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
                                  #
                                  hcalCalibDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hbheDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hoDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hfDigiCollectionTag = cms.InputTag('hcalDigis'),
                                  #
                                  #
                                  #
                                  #
                                  #for upgrade: ---------------------------------------------------------
                                  hbheQIE11DigiCollectionTag = cms.InputTag('hcalDigis'),
                                  hbheQIE10DigiCollectionTag = cms.InputTag('hcalDigis'),
                                  # flag to use either only old QIE8 digiCollections or only new QIE10,11 digiCollections
                                  #=0-all digiCollections(default for normal running), =1-only old QIE8 digiCollections, 
                                  #=2-only new QIE1011 digiCollections, =3-only new QIE1011 digiCollections w/o new high depthes
                                  #=4-2016fall, =5-2016fall w/o new high depthes, =6-2017bebin, =7-2017bebin w/o new high depthes in HEonly
                                  #=8--2017bebin w/o new high depthes, =9-all digiCollections  w/o new high depthes
                                  # flag   HBHE8    HBHE11   HF8   HF10  comments:
                                  #  0       +        +       +     +     all
                                  #  1       +        -       +     -     old
                                  #  2       -        +       -     +     new
                                  #  3       -        +       -     +     new w/o high depthes
                                  #  4       +        -       +     +     2016fall
                                  #  5       +        -       +     +     2016fall w/o high depthes
                                  #  6       +        +       -     +     2017 &&  2018
                                  #  7       +        +       -     +     2017begin w/o high depthes in HEonly
                                  #  8       +        +       -     +     2017begin w/o high depthes
                                  #  9       +        +       +     +     all  w/o high depthes
                                  # 10       +        -       -     +     2017 w/o HEP17
                                  # 
                                  flagupgradeqie1011 = cms.int32(6),
                                  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
                                  #end upgrade: --------------------------------------------------------- end upgrade
                                  # flaguseshunt = 1 or 6 (6 is default for global runs) 
                                  flaguseshunt = cms.int32(1),
                                  # flagsipmcorrection: != 0 yes,apply; = 0 do not use;
                                  flagsipmcorrection = cms.int32(1),
                                  #
                                  #
                                  # for local LASER runs ONLY!!! to be > 0    (,else = 0)
                                  flagLaserRaddam = cms.int32(0),
                                  # for gaussian fit for local shunt1 (Gsel0) led low-intensity or ped ONLY!!! to be  > 0    (,else = 0)
                                  flagfitshunt1pedorledlowintensity = cms.int32(1),
                                  #
                                  #
                                  #
                                  splashesUpperLimit = cms.int32(10000),
                                  #
                                  #
                                  #
                                  #HistOutFile = cms.untracked.string(histodir+'/LED_'+runnumber+'.root'),
                                  #
                                  #HistOutFile = cms.untracked.string(histodir+'/LED_'+runnumber+'.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest307971.root'),
                                  HistOutFile = cms.untracked.string('LEDtest308701.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest308234.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest308383.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest308543.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest308882.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309064.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest308786.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309592.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309821.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest309669.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309672.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309676.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest309573.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309924.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest310262.root'),
                                  #istOutFile = cms.untracked.string('LEDtest310268.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310403.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310410.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310427.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310452.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310454.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310456.root'),
                                  #                                 
                                  #HistOutFile = cms.untracked.string('LEDtest308784.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest308882.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309237.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309238.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309318.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309321.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309370.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309573.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest309704.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest310847.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310973.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest310244.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310387.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310587.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest310650.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('LEDtest311369.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest311413.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest311457.root'),
                                  #HistOutFile = cms.untracked.string('LEDtest311566.root'),

                                  #
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


#from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_data_FULL', '')
############################################################################
# V.EPSHTEIN:
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = '100X_dataRun2_Prompt_Candidate_2018_01_31_16_01_36'
###
process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)

process.es_hardcode = cms.ESSource("HcalHardcodeCalibrations",
    toGet = cms.untracked.vstring('QIEShape',
        'QIEData',
        'ChannelQuality',
        'HcalQIEData',
        'Pedestals',
        'PedestalWidths',
        'Gains',
        'GainWidths',
        'ZSThresholds',
        'RespCorrs')
)
###
process.hcalDigis= cms.EDProducer("HcalRawToDigi",
    FilterDataQuality = cms.bool(True),
    HcalFirstFED = cms.untracked.int32(700),
    InputLabel = cms.InputTag("source"),
    UnpackCalib = cms.untracked.bool(True),
    FEDs = cms.untracked.vint32(1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117),
)
###
############################################################################
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
############################################################################

