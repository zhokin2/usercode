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
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/0018142C-17C3-E411-807C-02163E011CD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/0485705B-15C3-E411-B139-02163E012141.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/0807374A-16C3-E411-96C6-02163E012807.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/1201A7A1-13C3-E411-8643-02163E01263E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/144A234B-16C3-E411-87EB-02163E012B0D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/149F032B-15C3-E411-8C84-02163E011DE7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/165EF648-16C3-E411-BB6F-02163E012B81.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/1828E053-14C3-E411-BEA5-02163E011DD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/18CB7F46-16C3-E411-ADB8-02163E011DFB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/1C8FD749-16C3-E411-AFBB-02163E012A8E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/24146632-17C3-E411-9518-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/26BBEF5B-15C3-E411-9C56-02163E0118D4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/28EC7D31-15C3-E411-8006-02163E011DDA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/2EC57842-16C3-E411-9577-02163E01223F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/3481F648-16C3-E411-81EB-02163E011CF9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/36CCF349-16C3-E411-A1A2-02163E011D2D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/40827549-16C3-E411-A7E7-02163E0125D1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/428136A3-13C3-E411-BFDE-02163E01227C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/429E312D-17C3-E411-8D7C-02163E0120DE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/48190A26-15C3-E411-82C4-02163E012681.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/48784A49-16C3-E411-AFB8-02163E011CE7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/48C76449-16C3-E411-BD1A-02163E012562.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/52C98E2B-17C3-E411-ADF0-02163E01283D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/52FB364D-16C3-E411-813C-02163E011DF5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/548B3F2A-17C3-E411-8DDF-02163E012562.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/58F91C4A-16C3-E411-A5E1-02163E0129C9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/60520D53-16C3-E411-AD0F-02163E0118D4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/62A75E52-14C3-E411-BE3D-02163E0123EF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/649E532A-17C3-E411-BADD-02163E011CF9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/681944E1-13C3-E411-A431-02163E011DE7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/6A5FE21F-17C3-E411-A077-02163E0118D4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/6AD60064-15C3-E411-ABAC-02163E0127C8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/6AF5022D-17C3-E411-9594-02163E012069.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/7616464A-16C3-E411-A955-02163E012078.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/7838314A-16C3-E411-A352-02163E0123EA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/78C52C55-14C3-E411-8E1A-02163E01263E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/7A4B264A-16C3-E411-8F47-02163E0127F8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/7CF5282C-17C3-E411-9008-02163E0123EA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/8092AD29-17C3-E411-934F-02163E0127F8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/821CC759-14C3-E411-80B5-02163E012502.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/82E9E231-17C3-E411-8A63-02163E011DF5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/8AB8042A-17C3-E411-A7F9-02163E01223F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/9418DE46-16C3-E411-AE8B-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/94997349-16C3-E411-8599-02163E011D08.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/96103F4B-16C3-E411-8ABF-02163E01243C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/9CFB1849-16C3-E411-A15F-02163E012947.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/9EAD862B-17C3-E411-99D8-02163E0124F8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/A0419E2D-17C3-E411-B914-02163E011DD4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/AA208A2B-17C3-E411-B670-02163E012346.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/B6499B4A-16C3-E411-9B12-02163E012768.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/BA2D8C44-16C3-E411-945F-02163E0123EF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/BA68DD49-16C3-E411-A4A5-02163E012681.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/C07F302E-17C3-E411-AD15-02163E011E00.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/C2FC8B4A-16C3-E411-9603-02163E012502.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/C44B1A4D-16C3-E411-80B6-02163E012715.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/CE1C5744-16C3-E411-A03F-02163E012069.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/E216AC5A-15C3-E411-8A75-02163E01182D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/E26BD630-15C3-E411-8DA3-02163E01263E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/E83CCA2C-17C3-E411-9EAA-02163E0121FD.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/EA95074A-16C3-E411-BC4C-02163E012818.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/FADE3D2D-17C3-E411-95B5-02163E012A8E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/236/905/00000/FAF97F49-16C3-E411-B468-02163E012346.root',

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
                                  ratioHBMin = cms.double(0.10),
                                  ratioHBMax = cms.double(0.85),
                                  ratioHEMin = cms.double(0.10),
                                  ratioHEMax = cms.double(0.85),
                                  ratioHFMin = cms.double(0.10),
                                  ratioHFMax = cms.double(0.98),
                                  ratioHOMin = cms.double(0.10),
                                  ratioHOMax = cms.double(0.85),
                                  # -54 for  BAD HBHEHF channels from study on RMS of shapes
                                  #Verbosity = cms.untracked.int32(-54),
                                  rmsHBMin = cms.double(2.0),
                                  rmsHBMax = cms.double(4.5),
                                  rmsHEMin = cms.double(1.8),
                                  rmsHEMax = cms.double(4.5),
                                  rmsHFMin = cms.double(0.2),
                                  rmsHFMax = cms.double(3.8),
                                  rmsHOMin = cms.double(2.2),
                                  rmsHOMax = cms.double(3.8),
                                  # -55 for  BAD HBHEHF channels from study on TSmean of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSmeanHBMin = cms.double(2.2),
                                  TSmeanHBMax = cms.double(6.5),
                                  TSmeanHEMin = cms.double(2.2),
                                  TSmeanHEMax = cms.double(6.5),
                                  TSmeanHFMin = cms.double(0.5),
                                  TSmeanHFMax = cms.double(6.5),
                                  TSmeanHOMin = cms.double(2.2),
                                  TSmeanHOMax = cms.double(6.5),
                                  # -55 for  BAD HBHEHF channels from study on TSmax of shapes
                                  #Verbosity = cms.untracked.int32(-55),
                                  TSpeakHBMin = cms.double(-0.5),
                                  TSpeakHBMax = cms.double(6.5),
                                  TSpeakHEMin = cms.double(-0.5),
                                  TSpeakHEMax = cms.double(6.5),
                                  TSpeakHFMin = cms.double(-0.5),
                                  TSpeakHFMax = cms.double(6.5),
                                  TSpeakHOMin = cms.double(-0.5),
                                  TSpeakHOMax = cms.double(6.5),
                                  # -56 for  BAD HBHEHOHF channels from study on ADC Amplitude
                                  #Verbosity = cms.untracked.int32(-56),
                                  ADCAmplHBMin = cms.double(0.),
                                  ADCAmplHBMax = cms.double(2000.),
                                  ADCAmplHEMin = cms.double(0.),
                                  ADCAmplHEMax = cms.double(1500.),
                                  ADCAmplHFMin = cms.double(0.),
                                  ADCAmplHFMax = cms.double(1000.),
                                  ADCAmplHOMin = cms.double(0.),
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
                                  #howmanybinsonplots = cms.int32(1200),
                                  howmanybinsonplots = cms.int32(2600),
                                  #howmanybinsonplots = cms.int32(3600),
                                  #howmanybinsonplots = cms.int32(150),
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
                                  lsdep_cut1_peak_HOdepth4 = cms.int32(15),
                                  # to select events with Nbcs > this limits
                                  lsdep_cut3_max_HBdepth1 = cms.int32(9),
                                  lsdep_cut3_max_HBdepth2 = cms.int32(3),
                                  lsdep_cut3_max_HEdepth1 = cms.int32(8),
                                  lsdep_cut3_max_HEdepth2 = cms.int32(6),
                                  lsdep_cut3_max_HEdepth3 = cms.int32(2),
                                  lsdep_cut3_max_HFdepth1 = cms.int32(5),
                                  lsdep_cut3_max_HFdepth2 = cms.int32(3),
                                  lsdep_cut3_max_HOdepth4 = cms.int32(20),
##                                  lsdep_cut3_max_HBdepth1 = cms.int32(0),
##                                  lsdep_cut3_max_HBdepth2 = cms.int32(0),
##                                  lsdep_cut3_max_HEdepth1 = cms.int32(0),
##                                  lsdep_cut3_max_HEdepth2 = cms.int32(0),
##                                  lsdep_cut3_max_HEdepth3 = cms.int32(0),
##                                  lsdep_cut3_max_HFdepth1 = cms.int32(0),
##                                  lsdep_cut3_max_HFdepth2 = cms.int32(0),
##                                  lsdep_cut3_max_HOdepth4 = cms.int32(0),
#                                  lsdep_cut3_max_HBdepth1 = cms.int32(19),
#                                  lsdep_cut3_max_HBdepth2 = cms.int32(6),
#                                  lsdep_cut3_max_HEdepth1 = cms.int32(15),
#                                  lsdep_cut3_max_HEdepth2 = cms.int32(12),
#                                  lsdep_cut3_max_HEdepth3 = cms.int32(3),
#                                  lsdep_cut3_max_HFdepth1 = cms.int32(9),
#                                  lsdep_cut3_max_HFdepth2 = cms.int32(4),
#                                  lsdep_cut3_max_HOdepth4 = cms.int32(40),
                                  #
                                  #old was for runs:
                                  #                                  nbadchannels1 = cms.int32(7),
                                  #                                  nbadchannels2 = cms.int32(12),
                                  #                                  nbadchannels3 = cms.int32(50),
                                  # to see signal & pedestal in HB TSs
                                  # Verbosity = cms.untracked.int32(-80),
                                  #Verbosity = cms.untracked.int32(-79),
                                  # cuts on Estimator1 to see bcs & LS dependences:
                                  lsdep_estimator1_HBdepth1 = cms.double(0.),
                                  lsdep_estimator1_HBdepth2 = cms.double(0.),
                                  lsdep_estimator1_HEdepth1 = cms.double(0.),
                                  lsdep_estimator1_HEdepth2 = cms.double(0.),
                                  lsdep_estimator1_HEdepth3 = cms.double(0.),
                                  lsdep_estimator1_HFdepth1 = cms.double(0.),
                                  lsdep_estimator1_HFdepth2 = cms.double(0.),
                                  lsdep_estimator1_HOdepth4 = cms.double(0.),
                                  # cuts on Estimator2 to see bcs & LS dependences:
                                  lsdep_estimator2_HBdepth1 = cms.double(0.),
                                  lsdep_estimator2_HBdepth2 = cms.double(0.),
                                  lsdep_estimator2_HEdepth1 = cms.double(0.),
                                  lsdep_estimator2_HEdepth2 = cms.double(0.),
                                  lsdep_estimator2_HEdepth3 = cms.double(0.),
                                  lsdep_estimator2_HFdepth1 = cms.double(0.),
                                  lsdep_estimator2_HFdepth2 = cms.double(0.),
                                  lsdep_estimator2_HOdepth4 = cms.double(0.),
                                  # cuts on Estimator3 to see bcs & LS dependences:
                                  lsdep_estimator3_HBdepth1 = cms.double(0.),
                                  lsdep_estimator3_HBdepth2 = cms.double(0.),
                                  lsdep_estimator3_HEdepth1 = cms.double(0.),
                                  lsdep_estimator3_HEdepth2 = cms.double(0.),
                                  lsdep_estimator3_HEdepth3 = cms.double(0.),
                                  lsdep_estimator3_HFdepth1 = cms.double(0.),
                                  lsdep_estimator3_HFdepth2 = cms.double(0.),
                                  lsdep_estimator3_HOdepth4 = cms.double(0.),
                                  # cuts on Estimator4 to see bcs & LS dependences:
                                  lsdep_estimator4_HBdepth1 = cms.double(0.),
                                  lsdep_estimator4_HBdepth2 = cms.double(0.),
                                  lsdep_estimator4_HEdepth1 = cms.double(0.),
                                  lsdep_estimator4_HEdepth2 = cms.double(0.),
                                  lsdep_estimator4_HEdepth3 = cms.double(0.),
                                  lsdep_estimator4_HFdepth1 = cms.double(0.),
                                  lsdep_estimator4_HFdepth2 = cms.double(0.),
                                  lsdep_estimator4_HOdepth4 = cms.double(0.),
                                  # cuts on Estimator5 to see bcs & LS dependences:
                                  lsdep_estimator5_HBdepth1 = cms.double(0.),
                                  lsdep_estimator5_HBdepth2 = cms.double(0.),
                                  lsdep_estimator5_HEdepth1 = cms.double(0.),
                                  lsdep_estimator5_HEdepth2 = cms.double(0.),
                                  lsdep_estimator5_HEdepth3 = cms.double(0.),
                                  lsdep_estimator5_HFdepth1 = cms.double(0.),
                                  lsdep_estimator5_HFdepth2 = cms.double(0.),
                                  lsdep_estimator5_HOdepth4 = cms.double(0.),

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
                                  HistOutFile = cms.untracked.string('Global.root'),
                                  #HistOutFile = cms.untracked.string('Global_234193.root'),
                                  #HistOutFile = cms.untracked.string('Global_ALCA2011.root'),
                                  #                                  
                                  #HistOutFile = cms.untracked.string('Global_test.root'),
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
