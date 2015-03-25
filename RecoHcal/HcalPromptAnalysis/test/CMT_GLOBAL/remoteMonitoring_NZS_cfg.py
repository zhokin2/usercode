import FWCore.ParameterSet.Config as cms

process = cms.Process("testAnalyzer")

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(100000)
    input = cms.untracked.int32(-1)
)

process.options = cms.untracked.PSet(
        SkipEvent = cms.untracked.vstring('ProductNotFound')
)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#     'file:/tmp/zhokin/2CDF0264-0847-E211-80F9-BCAEC5329703.root'
#
#'/store/data/Run2012C/HcalNZS/RAW/v1/000/199/975/24F29491-FADA-E111-A19B-BCAEC5329716.root'
#'/store/data/Run2012C/AlCaP0/RAW/v1/000/199/975/E2462995-FADA-E111-8DB3-0025B32036E2.root'
#
#'/store/data/Run2012D/AlCaP0/RAW/v1/000/209/106/2CDF0264-0847-E211-80F9-BCAEC5329703.root'
#'/store/data/Run2012D/AlCaP0/RAW/v1/000/208/686/2C849D4C-2E3F-E211-B454-BCAEC518FF30.root'
#'/store/data/Run2011A/HcalNZS/RAW/v1/000/160/338/2A0AE244-B74C-E011-8D99-0030487CD812.root'
#
#  25 nsec:
#
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209089.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209106.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209109.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209146.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209148.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Dv1HcalNZS25nsRAWrun209151.root'
#
#  50 nsec:
#
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun197724.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun197874.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun197875.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun197903.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun197929.root'
#
# long run 198487:
#
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun198487_part2.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun198487_part3.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Cv1HcalNZS50nsRAWrun198487_part1.root'



# long run 190707:
#
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part6.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part4.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part3.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part5.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part2.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/Run2012Av1HcalNZS50nsRAWrun190707_part1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_227391_part1.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_227391_part2.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_228591_1.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_228591_2.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_228637_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_228880_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229152_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229415_1.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229415_2.root'
############

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229514_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229528_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229621_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229653_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229669_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229672_1.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229685_1.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229685_2.root'

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229695_1.root'
######

#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_1.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_2.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_3.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_4.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_5.root',
#'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229702_6.root'

'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_1.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_2.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_3.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_4.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_5.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_6.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_7.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_8.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_9.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_10.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_11.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_12.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_13.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_14.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_15.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_16.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_17.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_18.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_19.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_20.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_21.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_22.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_23.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_24.root',
'file:/afs/cern.ch/work/z/zhokin/hcal/CMSSW_7_0_0_pre1/src/RecoHcal/HcalPromptAnalysis/test/rfiles/raw_run_229713_25.root'

   )
)

process.Analyzer = cms.EDAnalyzer("VeRawAnalyzer",
                                  #
                                  Verbosity = cms.untracked.int32(0),
                                  #Verbosity = cms.untracked.int32(-91),
                                  #Verbosity = cms.untracked.int32(-92),
                                  #
                                  MapCreation = cms.untracked.int32(1),
                                  #
                                  recordNtuples = cms.untracked.bool(False),
                                  #recordNtuples = cms.untracked.bool(True),
                                  maxNeventsInNtuple = cms.int32(100),
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
                                  # Verbosity = cms.untracked.int32(-78),
                                  #
                                  #
                                  #         Normal channels:
                                  #
                                  # -53 for  BAD HBHEHF channels from study on shape Ratio
                                  #Verbosity = cms.untracked.int32(-53),
                                  ratioHBMin = cms.double(0.12),
                                  ratioHBMax = cms.double(0.85),
                                  ratioHEMin = cms.double(0.12),
                                  ratioHEMax = cms.double(0.85),
                                  ratioHFMin = cms.double(0.10),
                                  ratioHFMax = cms.double(1.00),
                                  ratioHOMin = cms.double(0.12),
                                  ratioHOMax = cms.double(0.65),
                                  # -54 for  BAD HBHEHF channels from study on RMS of shapes
                                  #Verbosity = cms.untracked.int32(-54),
                                  rmsHBMin = cms.double(1.4),
                                  rmsHBMax = cms.double(4.5),
                                  rmsHEMin = cms.double(1.3),
                                  rmsHEMax = cms.double(4.5),
                                  rmsHFMin = cms.double(0.1),
                                  rmsHFMax = cms.double(2.5),
                                  rmsHOMin = cms.double(2.2),
                                  rmsHOMax = cms.double(4.5),
                                  # -55 for  BAD HBHEHF channels from study on TSmean of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSmeanHBMin = cms.double(2.0),
                                  TSmeanHBMax = cms.double(6.5),
                                  TSmeanHEMin = cms.double(2.0),
                                  TSmeanHEMax = cms.double(6.5),
                                  TSmeanHFMin = cms.double(0.5),
                                  TSmeanHFMax = cms.double(6.5),
                                  TSmeanHOMin = cms.double(1.8),
                                  TSmeanHOMax = cms.double(6.2),
                                  # -55 for  BAD HBHEHF channels from study on TSmax of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSpeakHBMin = cms.double(0.0),
                                  TSpeakHBMax = cms.double(8.8),
                                  TSpeakHEMin = cms.double(0.0),
                                  TSpeakHEMax = cms.double(8.8),
                                  TSpeakHFMin = cms.double(0.0),
                                  TSpeakHFMax = cms.double(8.8),
                                  TSpeakHOMin = cms.double(0.0),
                                  TSpeakHOMax = cms.double(8.8),
                                  # -56 for  BAD HBHEHOHF channels from study on ADC Amplitude
                                  #Verbosity = cms.untracked.int32(-56),
                                  ADCAmplHBMin = cms.double(15.),
                                  ADCAmplHBMax = cms.double(1000.),
                                  ADCAmplHEMin = cms.double(15.),
                                  ADCAmplHEMax = cms.double(1000.),
                                  ADCAmplHFMin = cms.double(0.),
                                  ADCAmplHFMax = cms.double(1000.),
                                  ADCAmplHOMin = cms.double(74.),
                                  ADCAmplHOMax = cms.double(9000.),
                                  #
                                  #
                                  # to see channels for pedestal tails (& < 1.0 hardcoded)
                                  pedestalHBMax = cms.double(0.2),
                                  pedestalHEMax = cms.double(0.9),
                                  pedestalHFMax = cms.double(0.1),
                                  pedestalHOMax = cms.double(0.2),
#                                  pedestalHBMax = cms.double(5.2),
#                                  pedestalHEMax = cms.double(5.4),
#                                  pedestalHFMax = cms.double(14.0),
#                                  pedestalHOMax = cms.double(14.0),
                                  #
                                  # to see channels w/ PedestalSigma > mean+5RMS(& < 0.10 hardcoded)
                                  #Verbosity = cms.untracked.int32(-57),
                                  #Verbosity = cms.untracked.int32(-57),
                                  pedestalwHBMax = cms.double(0.2),
                                  pedestalwHEMax = cms.double(0.2),
                                  pedestalwHFMax = cms.double(0.1),
                                  pedestalwHOMax = cms.double(0.16),
#                                  pedestalwHBMax = cms.double(1.20),
#                                  pedestalwHEMax = cms.double(1.50),
#                                  pedestalwHFMax = cms.double(1.30),
#                                  pedestalwHOMax = cms.double(0.80),
                                  #
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
                                   calibrADCHBMin = cms.double(120.),
                                   calibrADCHEMin = cms.double(120.),
                                   calibrADCHOMin = cms.double(120.),
                                   calibrADCHFMin = cms.double(60.),
                                   calibrADCHBMax = cms.double(3000.),
                                   calibrADCHEMax = cms.double(3000.),
                                   calibrADCHOMax = cms.double(3000.),
                                   calibrADCHFMax = cms.double(3000.),
                                   # for  BAD HBHEHOHF CALIBRATION channels 
                                   calibrRatioHBMin = cms.double(0.60),
                                   calibrRatioHEMin = cms.double(0.64),
                                   calibrRatioHOMin = cms.double(0.25),
                                   calibrRatioHFMin = cms.double(0.25),
                                   calibrRatioHBMax = cms.double(0.99),
                                   calibrRatioHEMax = cms.double(0.99),
                                   calibrRatioHOMax = cms.double(0.99),
                                   calibrRatioHFMax = cms.double(0.99),
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
                                  # flag for ask runs of LSs:
                                  #=0-runs, =1-LSs
                                  flagtoaskrunsorls = cms.int32(1),
                                  #
                                  # flag for choise of criterion of bad channels:
                                  #=0-CapIdErr, =1-Ratio, =2-Width, =3-TSmax, =4-TSmean, =5-adcAmplitud
                                  flagtodefinebadchannel = cms.int32(0),
                                  #how many bins you want on the plots:better to choice (#LS+1)
                                  #howmanybinsonplots = cms.int32(600),
                                  #howmanybinsonplots = cms.int32(350),
                                  #howmanybinsonplots = cms.int32(1810),
                                  howmanybinsonplots = cms.int32(2600),
                                  #howmanybinsonplots = cms.int32(100),
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
                                  #old was for runs:
                                  #                                  nbadchannels1 = cms.int32(7),
                                  #                                  nbadchannels2 = cms.int32(12),
                                  #                                  nbadchannels3 = cms.int32(50),
                                  # to see signal & pedestal in HB TSs
                                  # Verbosity = cms.untracked.int32(-80),
                                  #Verbosity = cms.untracked.int32(-79),
                                  # cuts on Estimator1 to see bcs & LS dependences:
                                  lsdep_estimator1_HBdepth1 = cms.double(100.),
                                  lsdep_estimator1_HBdepth2 = cms.double(100.),
                                  lsdep_estimator1_HEdepth1 = cms.double(100.),
                                  lsdep_estimator1_HEdepth2 = cms.double(100.),
                                  lsdep_estimator1_HEdepth3 = cms.double(100.),
                                  lsdep_estimator1_HFdepth1 = cms.double(350.),
                                  lsdep_estimator1_HFdepth2 = cms.double(240.),
                                  lsdep_estimator1_HOdepth4 = cms.double(250.),
                                  # cuts on Estimator2 to see bcs & LS dependences:
                                  lsdep_estimator2_HBdepth1 = cms.double(4.10),
                                  lsdep_estimator2_HBdepth2 = cms.double(4.10),
                                  lsdep_estimator2_HEdepth1 = cms.double(3.90),
                                  lsdep_estimator2_HEdepth2 = cms.double(4.00),
                                  lsdep_estimator2_HEdepth3 = cms.double(3.90),
                                  lsdep_estimator2_HFdepth1 = cms.double(0.90),
                                  lsdep_estimator2_HFdepth2 = cms.double(0.90),
                                  lsdep_estimator2_HOdepth4 = cms.double(4.10),
                                  # cuts on Estimator3 to see bcs & LS dependences:
                                  lsdep_estimator3_HBdepth1 = cms.double(0.2),
                                  lsdep_estimator3_HBdepth2 = cms.double(0.2),
                                  lsdep_estimator3_HEdepth1 = cms.double(0.2),
                                  lsdep_estimator3_HEdepth2 = cms.double(0.2),
                                  lsdep_estimator3_HEdepth3 = cms.double(0.2),
                                  lsdep_estimator3_HFdepth1 = cms.double(0.2),
                                  lsdep_estimator3_HFdepth2 = cms.double(0.2),
                                  lsdep_estimator3_HOdepth4 = cms.double(0.2),
                                  # cuts on Estimator4 to see bcs & LS dependences:
                                  lsdep_estimator4_HBdepth1 = cms.double(3.05),
                                  lsdep_estimator4_HBdepth2 = cms.double(3.00),
                                  lsdep_estimator4_HEdepth1 = cms.double(3.00),
                                  lsdep_estimator4_HEdepth2 = cms.double(3.00),
                                  lsdep_estimator4_HEdepth3 = cms.double(3.00),
                                  lsdep_estimator4_HFdepth1 = cms.double(1.80),
                                  lsdep_estimator4_HFdepth2 = cms.double(1.60),
                                  lsdep_estimator4_HOdepth4 = cms.double(3.30),
                                  # cuts on Estimator5 to see bcs & LS dependences:
                                  lsdep_estimator5_HBdepth1 = cms.double(0.21),
                                  lsdep_estimator5_HBdepth2 = cms.double(0.20),
                                  lsdep_estimator5_HEdepth1 = cms.double(0.20),
                                  lsdep_estimator5_HEdepth2 = cms.double(0.20),
                                  lsdep_estimator5_HEdepth3 = cms.double(0.20),
                                  lsdep_estimator5_HFdepth1 = cms.double(0.20),
                                  lsdep_estimator5_HFdepth2 = cms.double(0.20),
                                  lsdep_estimator5_HOdepth4 = cms.double(0.22),
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
                                  usecontinuousnumbering = cms.untracked.bool(False),
                                  #usecontinuousnumbering = cms.untracked.bool(True),
                                  #
                                  #
                                  #HistOutFile = cms.untracked.string('testNZS.root'),
                                  #HistOutFile = cms.untracked.string('Global_229514.root'),
                                  #HistOutFile = cms.untracked.string('Global_229528.root'),
                                  #HistOutFile = cms.untracked.string('Global_229621.root'),
                                  #HistOutFile = cms.untracked.string('Global_229653.root'),
                                  #HistOutFile = cms.untracked.string('Global_229669.root'),
                                  #HistOutFile = cms.untracked.string('Global_229672.root'),
                                  #HistOutFile = cms.untracked.string('Global_229685.root'),
                                  #HistOutFile = cms.untracked.string('Global_229695.root'),
                                  #
                                  #HistOutFile = cms.untracked.string('Global_229699.root'),
                                  #HistOutFile = cms.untracked.string('Global_229702.root'),
                                  #HistOutFile = cms.untracked.string('Global_229709.root'),
                                  HistOutFile = cms.untracked.string('Global_229713.root'),
                                  #HistOutFile = cms.untracked.string('Global_229714.root'),
                                  #HistOutFile = cms.untracked.string('Global_229715.root'),
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
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.hcalDigis.FilterDataQuality = cms.bool(False)

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'GR_P_V41::All'
process.es_prefer_GlobalTag = cms.ESPrefer('PoolDBESSource','GlobalTag')

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



