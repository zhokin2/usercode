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
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/0024F448-24C6-E411-9923-02163E012426.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/00964AFA-40C6-E411-A7B7-02163E011CD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/00F45AC7-23C6-E411-BBFF-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/042E9A53-24C6-E411-898E-02163E012271.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/08A6F9C3-23C6-E411-8AA7-02163E012271.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/0C8A8E01-41C6-E411-B099-02163E012408.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/1070BCB7-22C6-E411-9337-02163E0123F2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/14AB1050-42C6-E411-B16B-02163E011D37.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/18472951-42C6-E411-8CB3-02163E012926.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/1E783649-24C6-E411-B44B-02163E0123AE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/1ED04249-24C6-E411-BF84-02163E011DA1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/20CA3CD1-23C6-E411-95ED-02163E012760.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/26301861-42C6-E411-913C-02163E011DC1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/2EB6E848-24C6-E411-9DF7-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/34584DF7-40C6-E411-93F4-02163E012A0F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/3C493853-24C6-E411-87CF-02163E01250B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/3CFC1F4A-24C6-E411-89F4-02163E012753.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/3E9A24FC-40C6-E411-BCEA-02163E011801.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/3EB3CFF6-40C6-E411-97F2-02163E0126BF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/40E5FB49-24C6-E411-A9C2-02163E01243C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/44215FF8-40C6-E411-B180-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/48419655-42C6-E411-AAA0-02163E012337.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4864B0FB-40C6-E411-90D0-02163E011D32.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/48CC45F9-40C6-E411-99B8-02163E012103.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4AE56CF8-40C6-E411-A55C-02163E011DF8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4C0D3D70-42C6-E411-BF85-02163E011DA2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4C1CE3C5-23C6-E411-AC88-02163E01263E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4C6243F8-40C6-E411-A266-02163E012A6B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4CA4F449-24C6-E411-9C15-02163E0123F4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4E665AE1-35C6-E411-B8F7-02163E011DE7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4E8F3256-42C6-E411-9B4B-02163E012515.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/4ED7324A-24C6-E411-B1F2-02163E012014.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/505D3849-24C6-E411-9581-02163E012818.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/565BB8FD-40C6-E411-A807-02163E011D10.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/5831D250-24C6-E411-9DCB-02163E011DE7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/5C877202-41C6-E411-A22A-02163E01222D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/5E001AF9-40C6-E411-961B-02163E0122E8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/5E5F21FC-40C6-E411-ABD4-02163E011DA2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/6051244A-24C6-E411-A51E-02163E0129D9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/6073F952-42C6-E411-B9DD-02163E012408.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/6445EF4A-24C6-E411-A677-02163E012623.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/64D0E14A-24C6-E411-8B89-02163E01237F.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/66C2DAFA-40C6-E411-ABA7-02163E012901.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/6C322755-42C6-E411-9B15-02163E0126F3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/72D1E34D-42C6-E411-9D6D-02163E012A58.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/82D4FF01-41C6-E411-9E56-02163E0126F3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/8471F04D-24C6-E411-9975-02163E0124A6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/8C3B47FE-40C6-E411-82FE-02163E012748.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/8E3492F9-40C6-E411-A8B5-02163E0122D8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/92B883F8-40C6-E411-BC1C-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/92DD14C4-23C6-E411-AB8D-02163E011876.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/9638B4E0-35C6-E411-BB54-02163E0123F2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/96F0E251-24C6-E411-95ED-02163E01276D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/9E05E14A-24C6-E411-9B59-02163E0129B3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/9EDEA949-24C6-E411-80D2-02163E011CD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/A4B31C07-41C6-E411-B414-02163E01182D.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/A64207B4-22C6-E411-9CE4-02163E011DA1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/A8C9D370-42C6-E411-85EB-02163E012152.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/B0E5624A-24C6-E411-BDF8-02163E0120A0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/B44254F9-40C6-E411-A5DD-02163E012445.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/B8B2435D-42C6-E411-B2DE-02163E011D18.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/BA4A67CD-23C6-E411-B9F3-02163E012508.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/BC8D1CFC-40C6-E411-A0EA-02163E0123AE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/C40393C0-23C6-E411-88EE-02163E012141.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/C48D54F8-40C6-E411-A454-02163E012A58.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/C60F7949-24C6-E411-BC13-02163E0129EA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/C6A4AFF7-40C6-E411-8CB2-02163E0124FA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/CC0797C4-23C6-E411-A223-02163E011890.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/CC2312FC-40C6-E411-A8B2-02163E012406.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/D0D8CDFA-40C6-E411-AB20-02163E0121C8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/D2E0E8F8-40C6-E411-BEE7-02163E011D18.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/DA0FA2FE-40C6-E411-850B-02163E012515.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/DE0D2BBF-22C6-E411-94D3-02163E012511.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/DE8DAB49-24C6-E411-B7CA-02163E0121C8.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/E0EF7151-42C6-E411-850C-02163E012622.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/E22896C5-23C6-E411-851A-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/E480069C-37C6-E411-8FC8-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/E68BE04F-42C6-E411-AE3B-02163E011DEA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/E6CC73B4-22C6-E411-8767-02163E011D0E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/EE9E7EBA-23C6-E411-B750-02163E012760.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/F07594C1-23C6-E411-B37A-02163E0129EA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/F2FFC84B-24C6-E411-B16C-02163E012107.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/F4CB694B-24C6-E411-A42D-02163E012947.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/F6D2E363-24C6-E411-97D6-02163E0123F2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/F84559F8-40C6-E411-8CF3-02163E012464.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/FA454A54-24C6-E411-8583-02163E0123D6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/251/00000/FCED5F49-24C6-E411-A955-02163E012B9E.root',

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
