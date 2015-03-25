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
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/001F151C-B5C3-E411-BDC4-02163E012632.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/007A9BE4-DDC3-E411-9DA9-02163E0118D4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/02A816FE-C3C3-E411-852D-02163E011DE8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/0618FCC3-B8C3-E411-BCB1-02163E012628.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/081A99FE-E1C3-E411-965A-02163E012A42.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/08224621-ECC3-E411-9859-02163E0126E7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/084C1503-DAC3-E411-B1D6-02163E012696.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/0C20E8F1-B8C3-E411-A4A8-02163E011D3D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/10DA2644-D3C3-E411-A4D2-02163E0127F8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/120049C9-B8C3-E411-AE6E-02163E0121FD.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1430E3DB-BBC3-E411-A898-02163E011885.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/18E776E0-D6C3-E411-9A7E-02163E0123EF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1A12ABC5-B8C3-E411-B9A7-02163E012AEA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1AC39CD4-C5C3-E411-9E79-02163E011885.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1CA04192-EDC3-E411-A889-02163E012B7E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1E9978CB-B9C3-E411-9394-02163E012123.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1EAE290B-BEC3-E411-92F1-02163E0122E8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/1EC387CA-B8C3-E411-9120-02163E011D20.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/225C1975-94C3-E411-8E24-02163E01181B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/229C2211-C3C3-E411-A64D-02163E0129EA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/22BD64C2-B8C3-E411-B74D-02163E011DD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/2A679821-ECC3-E411-8857-02163E012807.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/324E93C0-B8C3-E411-BDC6-02163E0126E7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/3490A3C1-B8C3-E411-9566-02163E01222D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/361D2122-ECC3-E411-8B68-02163E011DA2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/366C3628-E1C3-E411-973B-02163E0126F3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/3AD68CCD-C7C3-E411-912B-02163E011DFE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/3C8E3FFC-BDC3-E411-BFFE-02163E012AF1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/3CB7DA2A-BCC3-E411-97C6-02163E0118E4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/46BCA12E-97C3-E411-8C41-02163E0120DE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/4E960FD1-B8C3-E411-836C-02163E0118D4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/5C28081E-96C4-E411-8450-02163E012120.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/60603DCC-C7C3-E411-9748-02163E011DE0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/62C40C77-D3C3-E411-A553-02163E011DA9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/64AB1C90-E4C3-E411-9CF9-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/6CC71421-ECC3-E411-BE60-02163E01279E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/7A5DD4C3-B8C3-E411-B3FB-02163E011DF5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/7C7ECAFA-BDC3-E411-A278-02163E012426.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/7E7B3B43-D3C3-E411-A652-02163E0121F7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/80C440DB-B8C3-E411-965A-02163E01261F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/845676DD-B8C3-E411-A462-02163E012380.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/849EC7DC-C5C3-E411-8D38-02163E011DD7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/867029A3-A6C3-E411-98CE-02163E012593.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/8676CBCA-B8C3-E411-8F03-02163E0127C3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/88F36618-ABC3-E411-B525-02163E012BD2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/960C7AFF-B1C3-E411-987E-02163E01223F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/964FA7CE-B8C3-E411-95E7-02163E011DFE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/9AAB9DE4-DDC3-E411-A970-02163E01185F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/9C2E8911-C3C3-E411-B323-02163E012720.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/9C61FC05-97C3-E411-A311-02163E012A1C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/9E5E6FC2-B8C3-E411-9455-02163E0127F8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/A0DAFBFC-C3C3-E411-A836-02163E012807.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/A2080AFC-BDC3-E411-92B2-02163E012BD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/A2CCE959-94C3-E411-82D9-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/A6225BE5-DDC3-E411-A72C-02163E011849.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/AAA351D9-C8C3-E411-BFBD-02163E012123.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/AAE38F94-DFC3-E411-9870-02163E0127C3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/B4323AE0-D6C3-E411-9B86-02163E011DD4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/BC76A2C7-B8C3-E411-BD9F-02163E012957.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/C817C320-ECC3-E411-9B45-02163E012A65.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/CA6FFCFB-C3C3-E411-96B8-02163E011897.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/CC883CC0-B8C3-E411-9E10-02163E012AF1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/CE05A7C6-B9C3-E411-9D2C-02163E01222D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/CE229CC9-B8C3-E411-9948-02163E012426.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/D018A252-D7C3-E411-A529-02163E012AF1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/D0733A4B-D7C3-E411-8858-02163E012AEA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/D0B84D6A-D3C3-E411-9D75-02163E0124A0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/D4F508F9-BBC3-E411-9008-02163E011DF8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/DC1AC71F-E1C3-E411-BB89-02163E012A42.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E2BFD90D-CCC3-E411-A8DF-02163E011DE0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E41F30CB-BFC3-E411-8D40-02163E012A56.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E42A7044-D3C3-E411-9866-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E4792DDC-BBC3-E411-823D-02163E011CE6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E8874AD6-C9C3-E411-B92D-02163E011DC0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/E8C53B1B-D8C3-E411-ADB6-02163E011885.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/EA01E8B3-BEC3-E411-8CE5-02163E012188.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/EC6F8523-ECC3-E411-932E-02163E01248B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/F2B6BDDD-BBC3-E411-AF2E-02163E012209.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/F6FA4CFF-BDC3-E411-B58B-02163E011E06.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/F87CB122-BCC3-E411-B25C-02163E011DC9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/FA8E720B-CCC3-E411-BCBC-02163E0122AB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/FADCB121-ECC3-E411-9DAA-02163E0125EB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/FCA47CF9-BBC3-E411-8B67-02163E011DC0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/068/00000/FCF8C0DE-BBC3-E411-99B9-02163E012B7B.root',

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
