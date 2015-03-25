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
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/04292E1B-EDC4-E411-A24A-02163E011D9B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/06FDFC24-CBC4-E411-B25D-02163E0128EC.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/1059CDEA-C4C4-E411-9EA7-02163E0118DC.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/2C4E1AD0-C7C4-E411-9052-02163E011876.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/32698301-C6C4-E411-A654-02163E012424.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/3610D8CA-B6C4-E411-9234-02163E01240D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/386B6DCC-C7C4-E411-A117-02163E011D88.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/3ACFF0C7-C9C4-E411-BA75-02163E0123B3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/4AE71A33-CBC4-E411-B7F9-02163E0128CE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/50150600-C6C4-E411-B675-02163E012712.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/523808F7-C5C4-E411-9A59-02163E012B75.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/56614028-B7C4-E411-B76A-02163E0120A4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/56A4F60E-C8C4-E411-ABF1-02163E01210C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/60D2F3E9-B7C4-E411-9939-02163E011851.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/665E0E4B-AAC4-E411-820C-02163E0122A0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/6ACE5E29-C6C4-E411-9F96-02163E011D2D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/70301B65-EDC4-E411-B6DC-02163E0124FA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/723A26EA-C4C4-E411-BE9E-02163E012AEF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/74B62481-EDC4-E411-9B66-02163E011DA3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/7CA23F79-AAC4-E411-80AA-02163E0128BC.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/7CB0CA34-B5C4-E411-ABE5-02163E012703.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/807A1439-CBC4-E411-B384-02163E0118BF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/8ABF3913-C8C4-E411-AC38-02163E011D60.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/96D4CBD6-C9C4-E411-929A-02163E01203C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/9C7101FD-C5C4-E411-9BB7-02163E011CFB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/A422EAEF-C7C4-E411-B8B6-02163E0126DC.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/AEC8AFDF-B7C4-E411-A405-02163E011CD9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/B6282417-EFC4-E411-936F-02163E011D7F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/B8A44401-C6C4-E411-97CC-02163E012120.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/BAD5C18F-AAC4-E411-9CF8-02163E012051.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/D45416C9-C9C4-E411-9A2E-02163E011876.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/D8B38A70-AAC4-E411-8959-02163E012418.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/EC8C3297-CBC4-E411-ACB1-02163E01238A.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/EE68EE08-EDC4-E411-8319-02163E011DE0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/205/00000/F287394F-B6C4-E411-BA4A-02163E012B43.root',

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
