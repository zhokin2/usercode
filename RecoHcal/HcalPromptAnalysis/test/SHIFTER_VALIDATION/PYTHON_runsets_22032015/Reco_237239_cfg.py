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
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/0633D9A7-49C5-E411-B5D8-02163E012978.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/06A21F83-FEC5-E411-8011-02163E012B7E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/087BB435-FFC5-E411-8BB0-02163E012637.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/0EA07586-FEC5-E411-915F-02163E011DA1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/1402DCE7-51C5-E411-8EB5-02163E012947.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/14FAFF67-51C5-E411-AA67-02163E012318.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/16976CE9-32C5-E411-B3A4-02163E0120A4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/18D07E3F-1BC6-E411-A703-02163E012B9E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/1AE24562-19C5-E411-BEC1-02163E0118AB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/1EB9ACFF-25C5-E411-97C5-02163E012AEA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/2603D0EB-32C5-E411-B975-02163E0129B3.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/287A1689-4EC5-E411-B0F2-02163E0129D9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/2AE7983D-1BC6-E411-BC3A-02163E012A42.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/2EFCA157-1BC6-E411-A672-02163E0123D6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/30CA7D3D-1BC6-E411-B3D9-02163E01250B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/320CD9BB-2BC5-E411-922B-02163E011DEA.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/34CBDB36-3DC5-E411-9C15-02163E011DF5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/364097A6-FEC5-E411-B025-02163E011CD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3AFBB419-5FC5-E411-A79F-02163E012B43.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3C85641A-5FC5-E411-9A6F-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3C98B835-FFC5-E411-B7C3-02163E012637.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3CFD707C-37C5-E411-81E9-02163E011876.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3E2B5CA8-FEC5-E411-B9D3-02163E012A42.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/3EA4B992-5CC5-E411-AA53-02163E0120E2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/40CFF3A7-49C5-E411-BA0E-02163E0125D1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/42C3689D-16C5-E411-98E7-02163E0123AE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/44DDEA5A-56C5-E411-B2B7-02163E011DD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/46494D0F-40C5-E411-8CAA-02163E012ABD.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/48915D42-1CC5-E411-BC90-02163E011DA2.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/4A96CA3C-1BC6-E411-A8E6-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/4E8EDCE9-60C5-E411-A2E3-02163E012094.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/564E3FB2-FEC5-E411-AF83-02163E0120A0.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/56B749EC-60C5-E411-9DEC-02163E01203C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/5ACA05E8-32C5-E411-83A2-02163E011CFB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/5E211BF6-FEC5-E411-B55A-02163E011879.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/5EAE920A-FFC5-E411-8E6C-02163E012B7E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/64EEEF03-54C5-E411-9ABB-02163E012947.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/6EE3DCF2-32C5-E411-969A-02163E012703.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/72640106-17C5-E411-AE3A-02163E0123B4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/767C3056-3AC5-E411-BF5C-02163E012703.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/7800C693-FEC5-E411-81E3-02163E011879.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/78A4144D-1BC6-E411-8D2B-02163E012760.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/7AC9A51C-4EC5-E411-A997-02163E0125C5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/806F327E-FEC5-E411-90DE-02163E012318.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/82C3493F-1BC6-E411-8D39-02163E0126BF.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/84848BAE-1BC5-E411-896B-02163E011885.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/84B89EF3-2FC5-E411-8901-02163E0129D9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/88F833FD-5BC5-E411-8A9C-02163E012094.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/8A8EBBD0-40C5-E411-8BE1-02163E0125D1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/8C2A0179-37C5-E411-9532-02163E012706.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/8E9F0BD8-2EC5-E411-939C-02163E012094.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/904FC0EA-32C5-E411-92BB-02163E011CEE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/906C1CEA-32C5-E411-B130-02163E0122AB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/9C0809DB-2FC5-E411-83CF-02163E011CFB.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/9E3A395A-56C5-E411-9473-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/9E9D2D0A-22C5-E411-AFB2-02163E011D46.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A49219A7-1BC5-E411-83C1-02163E0126E7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A4A3D267-1CC6-E411-A097-02163E011DD7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A624A206-54C5-E411-A03E-02163E012AA4.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A659C85F-59C5-E411-9321-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A6AD3008-22C5-E411-9506-02163E012751.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/A8EB9182-5BC5-E411-9060-02163E012094.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B077A43E-1BC6-E411-9712-02163E012069.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B0DC7308-FFC5-E411-95A0-02163E011D37.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B223563E-1BC6-E411-95F5-02163E012152.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B2974C36-FFC5-E411-BDC8-02163E012637.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B426F5ED-22C5-E411-8DBD-02163E012445.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B6AB20C3-54C5-E411-AFA1-02163E01203C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B8310BFD-25C5-E411-BCC0-02163E011890.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/B8E61BE7-52C5-E411-B38D-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/BC4441E9-32C5-E411-814D-02163E012094.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/C00FEF5F-3AC5-E411-9148-02163E012957.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/C04A69E9-32C5-E411-B654-02163E012543.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/C0F7819D-36C5-E411-AF72-02163E012957.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/C8E070F4-FEC5-E411-BE12-02163E011889.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/CA6A3BCB-FEC5-E411-961D-02163E01221B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/CE25AFD1-57C5-E411-B0B9-02163E0121D5.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/CE6AF27D-37C5-E411-A113-02163E011E06.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/D26422DA-2FC5-E411-A4D6-02163E0127FC.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/D2D71A09-22C5-E411-AFFC-02163E011DC9.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/D6159790-FEC5-E411-88CC-02163E012B8E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/D6EAA1DD-4AC5-E411-BD78-02163E011D9B.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/DA53F7EF-43C5-E411-8237-02163E01217E.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/DC56E2AE-49C5-E411-9779-02163E0123D6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/DCE04425-FFC5-E411-8FB4-02163E012B6C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E0ECA807-22C5-E411-9984-02163E012890.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E2386B45-24C5-E411-870D-02163E011DEE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E40BA4ED-FEC5-E411-B86F-02163E011DA1.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E42B13B9-3BC5-E411-94E2-02163E012A2C.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E46D3CF5-43C5-E411-84DF-02163E011E00.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/E4AA44F4-4AC5-E411-9AB5-02163E012785.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/F2DE6DDB-2FC5-E411-BE1F-02163E0123F7.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/F626675E-3AC5-E411-931E-02163E011876.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/F6B85419-FFC5-E411-8966-02163E011CD6.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/F6D81F3F-1BC6-E411-9914-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/F8B3D99F-47C5-E411-ACD1-02163E012A02.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/FA2061E8-26C5-E411-AF97-02163E01230A.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/FA351DED-41C5-E411-A1E6-02163E011DFE.root',
'/store/data/Commissioning2015/Cosmics/RAW/v1/000/237/239/00000/FC1703EE-62C5-E411-82BE-02163E011890.root',

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
