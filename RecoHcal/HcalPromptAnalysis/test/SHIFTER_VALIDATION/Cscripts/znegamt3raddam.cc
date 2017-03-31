#include <iostream>
#include <fstream>
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TROOT.h"
#include <TMath.h>
#include "TStyle.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TText.h"
#include "TAxis.h"
#include "TFile.h"
#include "TLine.h"
#include "TGraph.h"
#include <TPaveText.h>
#include <TPostScript.h>
#include <TClass.h>
#include <TLatex.h>
#include <TFrame.h>
#include <TPad.h>

#include "TGraphErrors.h"
#include "TF1.h"
#include "TArrow.h"

//
using namespace std;
//
/*

  Float_t X0[NMAX] = {
    1., 2., 3., 4., 5., 6., 7., 8., 9.,10.,
   11.,12.,13.,14.,15.,16.,17.,18.,19.,20.,      
   21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,   
   31.,32.,33.,34.,35.,36.,37.,38.,39.,40.,   
   41.,42.,43.,44.,45.,46.,47.,48.,49.,50.,   
   51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,
   61.,62.,63.,64.,65.,66.,67.,68.,69.,70.,
   71.,72.,73.,74.,75.,76.,77.,78.,79.,80.,   
   81.,82.,83.,84.,85.,86.,87.,88.,89.,90.,   
   91.,92.,93.,94.,95.,96.,97.,98.,99.,100
   };// days of year    time points (abscissa) !!!
*/
//  
int main(int argc, char *argv[])
{
  //______________________________________________________________________________________________________________________________    
  //TCanvas *c1;
  TGraph *gr1;  TGraph *gr2;TGraph *gr3;  TGraph *gr4;TGraph *gr5;  TGraph *gr6;TGraph *gr7;TGraph *gr8;TGraph *gr9;
  //
  const Int_t NMethods =24;// total number of Methods (all-together 24 methods)
  const Int_t NMethodsStart =0;     // since which method to start ( min=  0)
  const Int_t NMethodsToUse =23;// choose Number of methods to use ( max= 23)
  //
 TString MethodName[NMethods] = { "PLOT0", "PLOT1", "PLOT2", "PLOT3", "PLOT4", "PLOT5", "PLOT6", "PLOT7", "PLOT8", "PLOT9",
                                  "PLOT10","PLOT11","PLOT12","PLOT13","PLOT14","PLOT15","PLOT16","PLOT17","PLOT18","PLOT19","PLOT20","PLOT21","PLOT22","PLOT23"};
  //______________________________________________________________________________________________________________________________    
 //LUMI-DAYS:
 const Int_t NMAX0 =200;// number of DAYS(time abscissa)
 Float_t LU[NMAX0] = {
    0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.2, 1.3, 1.6, 1.9, 2.1, 2.4, 2.7, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 6.9,
     7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.4, 7.9, 8.3, 8.7, 9.1, 9.5,10.0,10.5,10.9,11.3,11.7,12.1,12.5,13.0,13.4,13.8,14.2,14.6,15.0,15.4,15.8,16.2,16.6,17.0,17.4,17.8,18.2,18.7,19.1,19.5,19.5,19.5,19.5,19.5,
    19.5,19.5,19.5,19.8,20.1,20.4,20.8,21.1,21.5,21.9,22.2,22.5,22.5,22.5,22.5,23.0,23.5,24.0,24.5,25.0,25.0,25.0,25.0,25.0,25.0,25.0,25.0,25.0,25.2,25.4,26.0,26.5,27.0,27.5,28.0,28.5,29.0,29.5,30.0,30.5,
    31.0,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,31.5,32.6,32.8,33.3,33.7,34.0,34.2,34.2,34.2,34.2,34.2,34.2,34.2,34.2,34.2,34.2,34.9,35.4,35.9,36.4,36.9,37.4,37.8,
    38.3,38.6,39.0,39.4,40.0,40.5,41.0,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3,41.3
}; 

		    // recorded LUMI:
                    Float_t LU0[NMAX0] = {24.6 ,50.4,47.7  ,28.0 ,122.5,0.   ,98.5 ,0.02 ,37.  ,256.6,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,9.4  ,5.1  ,101.8,130.6,
					  190. ,198.8,228.5,320.3,301. ,338.6,219.4,  0. ,  0. ,  0. ,  0. ,  0. ,443. ,464.6,0.   ,365. ,191.4,158.8,387.8,182. ,
					  740.1,0.   ,0.   ,0.   ,73.9 ,472. ,550. ,0.   ,237.4,345.1,104.9,0.   ,608.4,340.8,617.7,0.   ,500. ,532.6,485. ,360.6,
					  491.6,289.7,525. ,0.   ,541.5,481.4,529.1,172. ,470. ,611. ,0.   ,673.9,518.7,756.5,250.4,61.3 ,0.   ,0.   ,0.   ,0.   ,
					  0.   ,0.   ,385.4,0.   ,324.7,367.4,39.2 ,412.7,468. ,298. ,274. ,0.   ,0.   ,0.   ,580.7,482.4,200.2,249.9,407.3,126.6,
					  40.3 ,180. ,0.   ,0.   ,0.   ,0.   ,238.7,391.6,284.9,805.2,513.6,224.7,464.5,265.2,471.3,857.4,0.   ,286.5,428.7,0.   ,
					  505.5,374.3,0.   ,0.   ,0.   ,0.   ,0.   ,0.   ,0.   ,0.   ,0.   ,0.   ,   0.,   0.,   0.,   0.,   0., 17.4,519.7,469.4,
					  397.9,0.   ,752. ,0.   ,392.6,0.   ,0.   ,24.9 ,0.   ,10.4 ,494.4,441.7,211.8,152.6,217.4,600.7,350.8,434.6,500. ,127.6,
					  400. ,126.8,399. ,271.3,819. ,322.8,364.6,106.4,350. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,  0. ,
					    0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,  0. ,  0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,0.   ,  0. ,  0. 
		    };
		    // delivered LUMI: recorderLUMI*klumi    (=1.10 (41.3/37.4667)   )
                    Float_t LU1[NMAX0];Float_t klumi = 1.1023122;
		    int  ncounts=1; 
		    LU1[ncounts-1] = klumi*LU0[ncounts-1]/1000.; // fb-1
		    cout << "  ind = " <<      ncounts-1   << "     LU1 = " <<      LU1[ncounts-1]    << "     LU = " <<      LU[ncounts-1]    <<endl;
		    for (int jj=1;jj<NMAX0;jj++) { 
		      LU1[ncounts] = LU1[ncounts-1] +  klumi*LU0[jj]/1000.;
		      //           cout << "  ind = " <<      ncounts   << "     LU1 = " <<      LU1[ncounts]    << "     LU = " <<      LU[ncounts]    <<endl;
		      ++ncounts;
		    }
		    cout << "LU1[NMAX0-1] = " <<      LU1[NMAX0-1]    <<endl;
  //______________________________________________________________________________________________________________________________    
		    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////  runs for positive direction: P kdirection to be = 1
		    
  const Int_t NMAX =50;// number of LASER runs(time abscissa)
  TString LASERruns[NMAX] = {"272957","273354","273899","274185","274260","274357",
			     "274409","274462","274767","275273","275392","275707","275802","275877","276256","276424",
			     "276465","276479","276523","276556","276823","277134","277340","278074",
			     "278223","278326","278592","278901","279098","279610","279734","279804","280141","280204",
			     "280266","280378","282043","282777","282850","282854","282931","283117","283328","283365",
			     "283401","283445","283800","283840","283982","285355"};
//                                                                 25.10    15.11
  Float_t X0[NMAX] = {1.,4.,15.,20.,22.,25.,
		      26.,28.,30.,38.,43.,46.,48.,50.,55.,57.,
                      59.,59.,60.,62.,67.,74.,77.,85.,
		      87.,90.,93.,99.,103.,109.,112.,114.,119.,120.,
		      121.,123.,145.,154.,155.,155.,156.,157.,160.,161.,
		      161.,162.,165.,166.,169.,190. };// days of year    time points (abscissa) !!!

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// negative: M  kdirection to be = 0
/*
  const Int_t NMAX =47;// number of LASER runs(time abscissa)
  TString LASERruns[NMAX] = { 
    "272967","273211","273460","273562","273897","274355","274408","274765","275017","275272",
    "275357","275706","275874","276252","276420","276470","276478","276522","276532","276860",
    "277133","277174","277869","278071","278221","278325","278590","278898","279097","279701",
    "279802","279909","280138","280202","280207","280264","280376","282042","282243","283325",
    "283364","283400","283443","283799","283837","284735","285353"};
//                                       22.10     06.11    15.11  
  
  Float_t X0[NMAX] = {
    1.,3.,6.,9.,15.,25.,26.,30.,36.,38.,
    41.,46.,50.,55.,57.,59.,59.,60.,61.,68.,
    74.,75.,83.,85.,87.,90.,93.,99.,103.,111.,
    114.,116.,119.,120.,120.,121.,123.,145.,148.,159.,
    161.,161.,162.,165.,166.,181.,190.};// days of year    time points (abscissa) !!!
*/

  //    "283364","283400","283443","283799","283837","284735","285353","286399"};
  //    161.,161.,162.,165.,166.,181.,190.,217.};// days of year    time points (abscissa) !!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // kdirection:       negative dir M:=0 ;   positive dir P: =1  
  int kdirection= 1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //______________________________________________________________________________
  //
  //---=[ SetCanvasDef           ]=----------------
  // Create a new canvas.
  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);

  c1->Range(0,0,25,18);
  //c1->SetFillColor(40);
  c1->SetFillColor(0);
  c1->Clear();

  TLatex *t = new TLatex();
  t->SetTextFont(32);
  //t->SetTextColor(4);
  t->SetTextSize(0.03);
  t->SetTextAlign(12);
  //______________________________________________________________________________
  t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LASER run for some random HE channels");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //-----------------------------------------------------------------------------------------------------
  Float_t CutrwithphiMin = 0.; Float_t CutrwithphiMax = 4.;
  if(kdirection == 0 ){CutrwithphiMin = 0.; CutrwithphiMax = 3.5;}
  //---------------------------------------------------------------------------------------------------------------------
  //     Int_t NP = 3; // for loop over time points(LASER runs) NMAX is number of LASER runs(time abscissa)
  Int_t NP = NMAX;  // for loop over time points(LASER runs) NMAX is number of LASER runs(time abscissa)
  //
  
  // = 0 Acut     =1 meancut
  Int_t flagcutamplitude = 0;   Float_t kfaktor = 3.0;
  cout << "!!*********************        flagcutamplitude= " <<flagcutamplitude << "   kfaktor= " <<kfaktor <<endl;
  
  // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
  //    int cutMinA = 100; int cutMaxA = 1000;   
  // Float_t cutMinA = 50.; Float_t cutMaxA = 2500.;   
  Float_t cutMinA = 50.; Float_t cutMaxA = 3500.;  // only for flagcutamplitude=0
  if(kdirection == 0 ) cutMaxA = 4000.; 
  //
  // ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  //-----------------------------------------------------------------------------------------------------
  Float_t XX[NMAX]; for(int k1 = 0; k1<NP; k1++){XX[k1] = X0[k1];}
  // use lumi ??? :
//    Int_t flaglumiuse = 1; // =0-days; =1-lumi;
  Int_t flaglumiuse = 1; // =0-days; =1-lumi;
  cout << "!!*********************        flaglumiuse  = " <<  flaglumiuse <<endl;

  Int_t flaggaincorrections = 1; // =0 do not use; =1 use corrections
  cout << "     !!*********************        flaggaincorrections  = " <<  flaggaincorrections <<endl;
  //-----------------------------------------------------------------------------------------------------
  //
  //              x1   y1     x2     y2
  //    pad1->DrawFrame(1,   0.8,  370,   1.2);// all 
  
  Float_t x1=0.00; Float_t x2=200.00;
  
  Float_t y1=0.60; Float_t y2=  1.01;
  Float_t y3=0.85; Float_t y4=  1.01;
  Float_t y5=0.70; Float_t y6=  1.01;
  // 
  Float_t xx1=0.12; Float_t xx2=0.31;
  Float_t yy1=0.17; Float_t yy2=0.38;
//----------------------------------------------------------------------------------------------------- for test with test-LU
//  if(flaglumiuse == 1) {for(int k1 = 0; k1<NP; k1++){ int z1=X0[k1];  XX[k1] = LU[z1];}   x2= 45.0;   }
//-----------------------------------------------------------------------------------------------------
  if(flaglumiuse == 1) {for(int k1 = 0; k1<NP; k1++){ int z1=X0[k1];  XX[k1] = LU1[z1];} x2= 45.0;   }
  //-----------------------------------------------------------------------------------------------------
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Int_t verbosity = 0;// no printout
  //
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //
  // jj   M:    0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
  // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
  //
  //
  // M:L7 for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) { 
  // P:L7 for(int k1 = 0; k1<NP; k1++){for(int iii=???

  // L1: (iii=d1 & eta 17-29); 
  // M: int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1; 
  // P: int LP1 = 0;if((iii==1 && jj> 0)) LP1 = 1;

  // :L7:  (iii=d2 & eta 17-26) && (iii=d3 & eta 27-28) 
  // M: int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj> 1 && jj< 4)) LM7=1; 
  // P: int LP7=0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7=1;
  //
  //========================================================================================== PLOT0:        P   Amplitude -    100 5000   
  //----------------------------------------------------------------------------------------------------
  //========================================================================================== PLOT1:        M       r vs t for Depth1  and eta 21 22 23 25 27 28
  //========================================================================================== PLOT2:        M       r vs t for Depth1  and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT3:        M       r vs t for Depth2  and eta 21 22 23 25 27 28
  //========================================================================================== PLOT4:        M       r vs t for Depth2  and eta 17 18 19 20 24 26
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT5:        M       r vs t for L1      and eta 21 22 23 25 27 28
  //========================================================================================== PLOT6:        M       r vs t for L1      and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT7:        M       r vs t for L7      and eta 21 22 23 25 27 28
  //========================================================================================== PLOT8:        M       r vs t for L7      and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------
  //========================================================================================== PLOT9:         M Amplitude
  //========================================================================================== PLOT10:        P Amplitude Amplitude -    100 200 
  //----------------------------------------------------------------------------------------------------
  //========================================================================================== PLOT11:        P       r vs t for Depth1  and eta 21 22 23 25 27 28
  //========================================================================================== PLOT12:        P       r vs t for Depth1  and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT13:        P       r vs t for Depth2  and eta 21 22 23 25 27 28
  //========================================================================================== PLOT14:        P       r vs t for Depth2  and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT15:        P       r vs t for L1      and eta 21 22 23 25 27 28
  //========================================================================================== PLOT16:        P       r vs t for L1      and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT17:        P       r vs t for L7      and eta 21 22 23 25 27 28
  //========================================================================================== PLOT18:        P       r vs t for L7      and eta 17 18 19 20 24 26 29
  //----------------------------------------------------------------------------------------------------
  //========================================================================================== PLOT19:        M Amplitude
  //========================================================================================== PLOT20:        p mean Amplitude Depth3
  //----------------------------------------------------------------------------------------------------  
  //========================================================================================== PLOT21:        P       r vs t for Depth3  and 27 28
  //----------------------------------------------------------------------------------------------------
  const Int_t NDEP =8;const Int_t NETA =14;const Int_t NETA0=83;const Int_t NPHI0=73;

  Double_t ZZM[NMAX][NDEP][NETA];
  Double_t ZZP[NMAX][NDEP][NETA];
  Float_t YY[NMAX]; 
  //
  Double_t mapRADDAM_HE[NDEP][NETA0][NPHI0]; Double_t mapRADDAM_HED2[NDEP][NETA0]; Int_t mapRADDAM_HED20[NDEP][NETA0]; Float_t gainRADDAM_HE[NDEP][NETA0][NPHI0]; 
  Double_t normM[NDEP][NETA0][NPHI0]; 
  Double_t normP[NDEP][NETA0][NPHI0]; 
  ///////////////////////////////////////////////////////////////////////// initial nulling:
  for(int iii = 1; iii<4; iii++) {
    for (int jjj=1;jjj<=82;jjj++) {
      mapRADDAM_HED2[iii][jjj] =  0.;
      mapRADDAM_HED20[iii][jjj] =  0.;
      for (int kkk=1;kkk<=72;kkk++) {
	mapRADDAM_HE[iii][jjj][kkk] = 0.;
	normM[iii][jjj][kkk] = 0.;
	normP[iii][jjj][kkk] = 0.;
	gainRADDAM_HE[iii][jjj][kkk] = 0.;
      }
    }
  }
  /////////////////////////////////////////////////////////////////////////
  //______________________________________________________________________________ gain corrections: (time range: 187 days)
  Int_t timerange = 187;
  // ref.run:
  TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_272847.root", "READ"); // 2016-05-09       
  TH2F *xwod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HE");TH2F *xwod2= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl12_HE");TH2F *xwod3= (TH2F*)hfile1->Get("h_mapDepth3ADCAmpl12_HE");
  TH2F *x0010= (TH2F*)hfile1->Get("h_mapDepth1_HE");TH2F *x0020= (TH2F*)hfile1->Get("h_mapDepth2_HE");  TH2F *x0030= (TH2F*)hfile1->Get("h_mapDepth3_HE");
  TH2F* Xeff1= (TH2F*)xwod1->Clone("Xeff1");  TH2F* Xeff2= (TH2F*)xwod2->Clone("Xeff2");  TH2F* Xeff3= (TH2F*)xwod3->Clone("Xeff3");
  Xeff1->Divide(xwod1,x0010, 1, 1, "B");    Xeff2->Divide(xwod2,x0020, 1, 1, "B");    Xeff3->Divide(xwod3,x0030, 1, 1, "B");  
  // last.run:
  TFile *hfile2= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_285349.root", "READ");    //2016-11-15 	     
  TH2F *ywod1= (TH2F*)hfile2->Get("h_mapDepth1ADCAmpl12_HE");TH2F *ywod2= (TH2F*)hfile2->Get("h_mapDepth2ADCAmpl12_HE");TH2F *ywod3= (TH2F*)hfile2->Get("h_mapDepth3ADCAmpl12_HE");
  TH2F *y0010= (TH2F*)hfile2->Get("h_mapDepth1_HE");TH2F *y0020= (TH2F*)hfile2->Get("h_mapDepth2_HE");  TH2F *y0030= (TH2F*)hfile2->Get("h_mapDepth3_HE");
  TH2F* Yeff1= (TH2F*)ywod1->Clone("Yeff1");  TH2F* Yeff2= (TH2F*)ywod2->Clone("Yeff2");  TH2F* Yeff3= (TH2F*)ywod3->Clone("Yeff3");
  Yeff1->Divide(ywod1,y0010, 1, 1, "B");    Yeff2->Divide(ywod2,y0020, 1, 1, "B");    Yeff3->Divide(ywod3,y0030, 1, 1, "B");  

  // fill massive <Aijk>_runevents ,  where iii=depth, jjj=eta, kkk=phi
  int gx = Xeff1->GetXaxis()->GetNbins();
  int gy = Xeff1->GetYaxis()->GetNbins();
  for (int jjj=0;jjj<gx;jjj++) {
    for (int kkk=0;kkk<gy;kkk++) {
      if(Xeff1->GetBinContent(jjj,kkk)!= 0.) {gainRADDAM_HE[1][jjj][kkk+1] = (Yeff1->GetBinContent(jjj,kkk)/Xeff1->GetBinContent(jjj,kkk));}
      if(Xeff2->GetBinContent(jjj,kkk)!= 0.) {gainRADDAM_HE[2][jjj][kkk+1] = (Yeff2->GetBinContent(jjj,kkk)/Xeff2->GetBinContent(jjj,kkk));}
      if(Xeff3->GetBinContent(jjj,kkk)!= 0.) {gainRADDAM_HE[3][jjj][kkk+1] = (Yeff3->GetBinContent(jjj,kkk)/Xeff3->GetBinContent(jjj,kkk));}
    }
  }
  // fill massive gainkoeff ,  where iii=depth, jjj=eta, kkk=phi
  TH1F* gainkoeff = new TH1F("gainkoeff","", 100, 0.5,1.5);
  for(int iii = 1; iii<4; iii++) {
    for (int jjj=1;jjj<=82;jjj++) {
      for (int kkk=1;kkk<=72;kkk++) {
	if(gainRADDAM_HE[iii][jjj][kkk] !=0.) {
	  gainkoeff->Fill(gainRADDAM_HE[iii][jjj][kkk]);
	  if(flaggaincorrections == 0) gainRADDAM_HE[iii][jjj][kkk] = 1.;
	}
      }
    }
  }
  
  //______________________________________________________________________________
  //     ls -latr /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LASER_* | less  
      TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LASER_";
//  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";
  
  // booking:
  TH1F* Ceff1D = new TH1F("Ceff1D","", 1000, 0.,8000.);
  TH1F* Seff1D = new TH1F("Seff1D","", 100, 0.,400.);

  TH1F* Meff1D = new TH1F("Meff1D","", 100, 0.,4000.);
  TH1F* Meff2D = new TH1F("Meff2D","", 100, 0.,4000.);
  TH1F* Meff3D = new TH1F("Meff3D","", 100, 0.,4000.);

  TH1F* rwithphi = new TH1F("rwithphi","", 100, -1.,6.);



  Int_t kmm = 0;Int_t kpp = 0;  
    //    first runs:
    Int_t mk1f=0; Int_t pk1f=0;
  //
  //////////////////////////////////////////////////////////////////////////  LOOP    raddam current
      for(int k1 = 0; k1<NP; k1++) {
      //______________________________________________________
	  TString epsName = fname + LASERruns[k1] +".root";
	  TFile *hfile= new TFile(epsName, "READ");
	//  	TFile *hfile= new TFile("LASER_226835.root", "READ");        
	//	TFile *hfile= new TFile("LASER_272957.root", "READ");        


    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! read LASER run with k1= " << k1   <<"  run:  " << LASERruns[k1] <<endl;
     // Define nominator denominator for some methods:
    //---------------------------------------------------
    // 000000000000000000000000000000000000000000000000000000000000000000000000
//      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl_HE");
//      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl_HE");
//      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl_HE");
    // 111111111111111111111111111111111111111111111111111111111111111111111111
     // h_mapDepth1ADCAmpl12_HE means ADCcounts(massive) within -1 max +1 +2
    
      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12_HE");
      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl12_HE");
      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl12_HE");
      TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth1_HE");
      TH2F *t0020= (TH2F*)hfile->Get("h_mapDepth2_HE");
      TH2F *t0030= (TH2F*)hfile->Get("h_mapDepth3_HE");

    //
    // 222222222222222222222222222222222222222222222222222222222222222222222222
     //  h_mapDepth1linADCAmpl12_HE means ADCcounts(linearized) within -1 max +1 +2
    /*
      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1linADCAmpl12_HE");
      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2linADCAmpl12_HE");
      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3linADCAmpl12_HE");
      TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth1_HE");
      TH2F *t0020= (TH2F*)hfile->Get("h_mapDepth2_HE");
      TH2F *t0030= (TH2F*)hfile->Get("h_mapDepth3_HE");
*/
    //
/*
    // 3333333333333333333333333333333333333333333333333333333333333333333333
     // h_mapDepth1RADDAM_HE means ADCcounts(massive) within -1 max +1 +2
      // pedestal subtracted and cut(50 adcCounts) for each digi:
      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1RADDAM_HE");
      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2RADDAM_HE");
      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3RADDAM_HE");
      TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth1RADDAM0_HE");
      TH2F *t0020= (TH2F*)hfile->Get("h_mapDepth2RADDAM0_HE");
      TH2F *t0030= (TH2F*)hfile->Get("h_mapDepth3RADDAM0_HE");

    */
    //
      //
      // Divide  Divide  Divide  Divide  Divide  Divide  Divide  Divide:
      // for raddam get <Aijk>_runevents
      //
    //	if(t0010->IsA()->InheritsFrom("TH2F")) {
    TH2F* Ceff1= (TH2F*)twod1->Clone("Ceff1");
    TH2F* Ceff2= (TH2F*)twod2->Clone("Ceff2");
    TH2F* Ceff3= (TH2F*)twod3->Clone("Ceff3");
    //          cout<<"1 " <<endl;
    twod1->Sumw2();
//          cout<<"2 " <<endl;
    twod2->Sumw2();
//          cout<<"3 " <<endl;
    twod3->Sumw2();
//          cout<<"4 " <<endl;
    t0010->Sumw2();
//          cout<<"5 " <<endl;
    //      t0020->Sumw2();
    //      cout<<"6 " <<endl;
    //      t0030->Sumw2();
    //      cout<<"7 " <<endl;
    // <Aijk>_runevents:
    Ceff1->Divide(twod1,t0010, 1, 1, "B");  
    Ceff2->Divide(twod2,t0020, 1, 1, "B");  
    Ceff3->Divide(twod3,t0030, 1, 1, "B");  
    //      Ceff1->Sumw2();Ceff2->Sumw2();Ceff3->Sumw2();
    //	}


    int nx = Ceff1->GetXaxis()->GetNbins();
    int ny = Ceff1->GetYaxis()->GetNbins();
    if(verbosity == 2 ){
      cout<<"************* nx = " << nx <<" ny = " << ny <<endl;
      for (int jjj=0;jjj<=nx;jjj++) {
	for (int kkk=0;kkk<=ny;kkk++) {
	  if( Ceff1->GetBinContent(jjj,kkk) != 0.) cout<<"*111111************ jjj = " << jjj<<   "************* kkk = " << kkk <<endl;
	  if( Ceff2->GetBinContent(jjj,kkk) != 0.) cout<<"*******222****** jjj = " << jjj<<  "************* kkk = " << kkk <<endl;
	  if( Ceff3->GetBinContent(jjj,kkk) != 0.) cout<<"**********3*** jjj = " << jjj<<  "************* kkk = " << kkk <<endl;
	}
      }
    }
    //////////////////////////////////////////////////////////////////////////////////   see raddam done
    
    // fill massive <Aijk>_runevents ,  where iii=depth, jjj=eta, kkk=phi
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	// FILL NEW PLOTS:
	if(Ceff1->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff1->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff1->GetBinContent(jjj,kkk));}
	if(Ceff2->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff2->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff2->GetBinContent(jjj,kkk));}
	if(Ceff3->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff3->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff3->GetBinContent(jjj,kkk));}

	if(Ceff1->GetBinContent(jjj,kkk)>cutMinA) {Meff1D->Fill(Ceff1->GetBinContent(jjj,kkk));}
	if(Ceff2->GetBinContent(jjj,kkk)>cutMinA) {Meff2D->Fill(Ceff2->GetBinContent(jjj,kkk));}
	if(Ceff3->GetBinContent(jjj,kkk)>cutMinA) {Meff3D->Fill(Ceff3->GetBinContent(jjj,kkk));}


      }
    }

    // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
    // apply cut on <Aijk>_runevents
  //             -41                                +41
  //                            82 bins
    if(flagcutamplitude==1) {
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	  if(Ceff1->GetBinContent(jjj,kkk)> cutMinA && Ceff1->GetBinContent(jjj,kkk)< kfaktor*Meff1D->GetMean()) mapRADDAM_HE[1][jjj][kkk+1] =  Ceff1->GetBinContent(jjj,kkk);
	  if(Ceff2->GetBinContent(jjj,kkk)> cutMinA && Ceff2->GetBinContent(jjj,kkk)< kfaktor*Meff2D->GetMean()) mapRADDAM_HE[2][jjj][kkk+1] =  Ceff2->GetBinContent(jjj,kkk);
	  if(Ceff3->GetBinContent(jjj,kkk)> cutMinA && Ceff3->GetBinContent(jjj,kkk)< kfaktor*Meff3D->GetMean()) mapRADDAM_HE[3][jjj][kkk+1] =  Ceff3->GetBinContent(jjj,kkk);
	}
      }
    }// if
    else if(flagcutamplitude==0) { 
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	  if(Ceff1->GetBinContent(jjj,kkk)> cutMinA && Ceff1->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[1][jjj][kkk+1] =  Ceff1->GetBinContent(jjj,kkk);
	  if(Ceff2->GetBinContent(jjj,kkk)> cutMinA && Ceff2->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[2][jjj][kkk+1] =  Ceff2->GetBinContent(jjj,kkk);
	  if(Ceff3->GetBinContent(jjj,kkk)> cutMinA && Ceff3->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[3][jjj][kkk+1] =  Ceff3->GetBinContent(jjj,kkk);
	}
      }
    }// if
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    //////////////////--------------------------------------- gain corrections:
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  if(mapRADDAM_HE[iii][jjj][kkk] != 0 && gainRADDAM_HE[iii][jjj][kkk]!= 0 ) mapRADDAM_HE[iii][jjj][kkk] /= gainRADDAM_HE[iii][jjj][kkk];
	}
      }
    }
    //////////////////---------------------------------------
    //                                                            define A for refRun    Laser-megatile:           HEM : 272967 = [0] ,                     HEP : 272957 = [0],
    //////////////////---------------------------------------
    
    if(k1==mk1f && kmm==0 && kdirection == 0) {
      kmm=1; //Int_t mcount=0;
      cout<<"* to be printed once only  CHECK IT please  ************ kmm = " << kmm <<endl;
      for(int iii = 1; iii<4; iii++) {
	for (int jjj=1;jjj<=82;jjj++) {
	  for (int kkk=1;kkk<=72;kkk++) {
	    //	    if(mapRADDAM_HE[iii][jjj][kkk]!=0.) {dormM += mapRADDAM_HE[iii][jjj][kkk];++mcount;}
	    normM[iii][jjj][kkk] = mapRADDAM_HE[iii][jjj][kkk];
	  }//for 
	}//for 
      }//for 
      //      dormM /= mcount;
    }

    if(k1==pk1f && kpp==0 && kdirection == 1) {
      kpp=1; //Int_t pcount=0;
      cout<<"* to be printed once only  CHECK IT please  ************ kpp = " << kpp <<endl;
      for(int iii = 1; iii<4; iii++) {
	for (int jjj=1;jjj<=82;jjj++) {
	  for (int kkk=1;kkk<=72;kkk++) {
	    //	if(mapRADDAM_HE[iii][jjj][kkk]!=0.) {dormP += mapRADDAM_HE[iii][jjj][kkk];++pcount;}
	    normP[iii][jjj][kkk] = mapRADDAM_HE[iii][jjj][kkk];
	  }//for 
	}//for 
      }//for 
      //      dormP /= pcount;
    }
    //////////////////---------------------------------------
    //////////////////--------each run  normalization on first run  ----------------- find Rijk = <Aijk>_runevents /  <Aijk>_runevents(ref.run)
    //////////////////---------------------------------------
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  if(normM[iii][jjj][kkk] != 0 && jjj < 42 && kdirection == 0) {mapRADDAM_HE[iii][jjj][kkk] /= normM[iii][jjj][kkk];}
	  if(normP[iii][jjj][kkk] != 0 && jjj > 41 && kdirection == 1) {mapRADDAM_HE[iii][jjj][kkk] /= normP[iii][jjj][kkk];}
	}//for  
      }//for 
    }//for 
    //
    //////////////////---------------------------------------
    //                                               then, avereaging over phi, but first sum over phi before!!! any dividing:
    //////////////////---------------------------------------
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  if(mapRADDAM_HE[iii][jjj][kkk] != 0 ) rwithphi->Fill(mapRADDAM_HE[iii][jjj][kkk]);
	  if(mapRADDAM_HE[iii][jjj][kkk] > CutrwithphiMin && mapRADDAM_HE[iii][jjj][kkk] < CutrwithphiMax) {
	    
	    // ----------------------------------------   sum over phi before!!! any dividing:
	    mapRADDAM_HED2[iii][jjj] += mapRADDAM_HE[iii][jjj][kkk];
	    // N phi sectors w/ digihits
	    ++mapRADDAM_HED20[iii][jjj];

	    if(verbosity == 3 && iii==3 )  cout<<"   depth = " << iii <<" k1 = " << k1 <<" eta = " << jjj <<" mapRADDAM_HED2[iii][jjj] = " << mapRADDAM_HED2[iii][jjj]     <<" Nphi = " << mapRADDAM_HED20[iii][jjj] <<" mapRADDAM_HE[iii][jjj][kkk = " <<     mapRADDAM_HE[iii][jjj][kkk] <<endl;

	  }//if
	}//for  
      }//for  
    }//for  
  //===================================================================  clarify:
  //           jjj =  1          |         82    | -41
  //                1- 41        -        42-82
  //                       26          57        | -41
  //HE
  // depth1         13-25        -        58-70        13-26 --> N=14, 57-70 --> N=14
  // depth2         13-24        -        59-67
  // depth3       14,15,26*      -       *57,68,69
  //  jjj       13-26 --> N=14   -     57-70 --> N=14
  //   jj     M: 0-13                P: 0-13
  // real N:    16-29                  16,29
  // correspondence realN to jj:
  //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
  // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
  //                -   -       -        -   -  -                                                            -   -   -       -           -    -
  //
  //    ZZM[k1][depth]][jjj=eta] --> ZZM[k1][7][14] negative direction   ,  ZZP[k1][7][14] positive dir.  
  //                                            jj =  0 - 13                           jj =  0 - 13
  //                                           jjj = 13 - 26                          jjj = 57 - 70  
  //                          Cell = ZZM[k1][3][13]                  and    ZZP[k1][3][0]
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    //////////////------------------------------                                   and now averaging per N-phi_sectors
    //////////////////---------------------------------------
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {

	if(mapRADDAM_HED20[iii][jjj] != 0 ) {

	  if(verbosity == 1)  cout<<"****aver per N-phi_sectors********* depth = " << iii <<" RunIndex = " << k1 <<" eta = " << jjj <<" Nphi = " << mapRADDAM_HED20[iii][jjj] <<endl;
	  mapRADDAM_HED2[iii][jjj] /= mapRADDAM_HED20[iii][jjj];
	  if(verbosity == 3 && iii==3 ) cout<<"****aver per N-phi_sectors********* depth = " << iii <<" RunIndex = " << k1 <<" eta = " << jjj <<" Nphi = " << mapRADDAM_HED20[iii][jjj] <<endl;
	  //	  int jj = jjj-13;
	  //	  if(jj> 13) jj -=44;
	  //	  if(jj<0 || jj>13) cout<<"*** ERROR *** depth = " << iii <<" eta = " << jjj <<" new-eta = " << jj <<endl;
	  
	  if(jjj<42 ) {
	    if(kdirection == 0) {
	      int jj = jjj-13;
	      if(jj<0 || jj>13) cout<<"***ZZM ERROR *** depth = " << iii <<" eta = " << jjj <<" new-eta = " << jj <<endl;
	      ZZM[k1][iii][jj] = mapRADDAM_HED2[iii][jjj];
	      if(verbosity == 1)  cout<<"****aver per N-phi_sectors********* ZZM[k1][iii][jj] = " << ZZM[k1][iii][jj] <<endl;
	    }//if kdirection=0
	  }
	  else {
	    if(kdirection == 1) {
	      int jj = jjj-13;
	      jj -=44;
	      if(jj<0 || jj>13) cout<<"***ZZP ERROR *** depth = " << iii <<" eta = " << jjj <<" new-eta = " << jj <<endl;
	      ZZP[k1][iii][jj] = mapRADDAM_HED2[iii][jjj];
	      if(verbosity == 1)  cout<<"****aver per N-phi_sectors****** ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<endl;
	    }//if kdirection=1
	  }// if jjj<42

	}// if(mapRADDAM_HED20 != 0

      }//for  
    }//for 
    ///////////////////////////////////////////////////////////////// nulling :
    //
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	mapRADDAM_HED2[iii][jjj] =  0.;
	mapRADDAM_HED20[iii][jjj] =  0.;
	for (int kkk=1;kkk<=72;kkk++) {
	  mapRADDAM_HE[iii][jjj][kkk] = 0.;
	}
      }
    }
    ///////////////////////////////////////////////////////////////// hfile->Close();
    //
    hfile->Close();
    //
  }//for k1 loop over time points(LASER runs)
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                   DONE: last LASER run READ " <<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // =========================   normalization on channel:    ZZM[k1][3][13];   ZZP[k1][3][0];
  //
    for(int k1 = 0; k1<NP; k1++) {
      if(verbosity == 1) {cout<<" ********************************************************************time *************point = " << k1 <<endl;}
      for(int iii = 1; iii<4; iii++) {
	for (int jj=0;jj<=13;jj++) {

	  if(verbosity == 1) {cout<<" **** iii = " << iii <<" **** jj = " << jj <<endl;}
	  //    cout << "!!!!!!!!!!!!!!!!!!normalization on channel:!!!!!!!!!!!!!!   Positive Direction " <<endl;

	  if(kdirection == 1) {
	    if(iii==3&&jj==0) {} else{
	      if(ZZP[k1][3][0]  != 0 ) {ZZP[k1][iii][jj] /= ZZP[k1][3][0];}
	      if(verbosity == 1 && ZZP[k1][iii][jj] != 0 ) {cout<<"Normalized P Positive Direction ***** depth = " << iii <<" eta = " << jj <<" ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<endl;}
	      if(verbosity == 3 && ZZP[k1][iii][jj] != 0 && iii==3 ) {cout<<"Normalized P Positive Direction ***** depth = " << iii <<" eta = " << jj <<" ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<" ZZP[k1][3][0] = " << ZZP[k1][3][0]<<endl;}
	    }// if
	  }//if

	  else if(kdirection == 0) {
	    //    cout << "!!!!!!!!!!!!!!!!!normalization on channel:!!!!!!!!!!!!!!!   Negative Direction " <<endl;
	    if(iii==3&&jj==13) {} else{
	      if(ZZM[k1][3][13] != 0 ) {ZZM[k1][iii][jj] /= ZZM[k1][3][13];}
	      if(verbosity == 1 && ZZM[k1][iii][jj] != 0 ) {cout<<"Normalized M Negative Direction ***** depth = " << iii <<" eta = " << jj <<" ZZM[k1][iii][jj] = " << ZZM[k1][iii][jj] <<endl;}
	      if(verbosity == 3 && ZZM[k1][iii][jj] != 0 && iii==3 ) {cout<<"Normalized M Negative Direction ***** depth = " << iii <<" eta = " << jj <<" ZZM[k1][iii][jj] = " << ZZM[k1][iii][jj] <<" ZZM[k1][3][0] = " << ZZM[k1][3][0]<<endl;}
	    }// if


	  }// if

	}//for  
      }//for 
    }//for 
    //
  //============================= table   ====================================== normalization on first run channel 3,16:
  //             -41                                +41
  //                            82 bins
  //           jjj =  1          |         82    | -41
  //                1- 41        -        42-82
  //                       26          57        | -41
  //HE
  // depth1         13-25        -        58-70        13-26 --> N=14, 57-70 --> N=14
  // depth2         13-24        -        59-67
  // depth3       14,15,26*      -       *57,68,69
  //  jjj       13-26 --> N=14   -     57-70 --> N=14
  //   jj     M: 0-13                P: 0-13
  // real N:    16-29                  16,29
  // correspondence realN to jj:
  //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
  // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
  //                -   -       -        -   -  -                                                            -   -   -       -           -    -
  //             eta:
  //depth1                     0    -     12                                                          1       -             13   (+57)
  //depth2                       2  -     13                                                            2     -     10
  //depth3                     1,2  -     13*                                                       0*        -       11, 12      
  //    ZZM[k1][depth]][jjj=eta] --> ZZM[k1][7][14] negative direction   ,  ZZP[k1][7][14] positive dir.  
  //                                            jj =  0 - 13                           jj =  0 - 13
  //                                           jjj = 13 - 26                          jjj = 57 - 70  
  //                          Cell = ZZM[k1][3][13]                  and    ZZP[k1][3][0]
  
  //
  //
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  cout<<"****  ****  ****  ****  ****     Draw Dependencies: *** " <<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Int_t Method = NMethodsStart ;
  while (Method<NMethodsToUse+1) {
    if( (kdirection==1 && Method != 9 && Method != 19 &&Method!= 1&&Method!= 2&&Method!= 3&&Method!= 4&&Method!= 5&&Method!= 6&&Method!= 7&&Method!= 8) || 
        (kdirection==0 && Method != 0 && Method != 10 &&Method!=11&&Method!=12&&Method!=13&&Method!=14&&Method!=15&&Method!=16&&Method!=17&&Method!=18) )
      {
    cout<<" ****  START   Method " << Method <<endl;
    //======================================================================================================= PLOT0: P:    <Aijk>_ev.run for all runs
    if(Method == 0 ) {
      cout<<"****Draw 0 Dependencies: P: draw <Aijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //    Ceff1D->SetTitle("any Error, HE Depth1 \n");
      Ceff1D->SetMarkerStyle(20);
      Ceff1D->SetMarkerSize(0.4);
      Ceff1D->GetYaxis()->SetLabelSize(0.04);
      Ceff1D->SetTitle("P: all runs & channels");
      Ceff1D->SetXTitle("<Aijk>");
      Ceff1D->SetYTitle("N");
      Ceff1D->SetMarkerColor(4);
      Ceff1D->SetLineColor(4);
      //    Ceff1D->Draw("Error");
          Ceff1D->Draw("PL");
    }//Method = 0
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT10: P:   <Aijk>_ev.run for all runs
    if(Method == 10 ) {
      cout<<"****Draw 10 Dependencies: P: draw <Aijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //    Seff1D->SetTitle("any Error, HE Depth1 \n");
      Seff1D->SetMarkerStyle(20);
      Seff1D->SetMarkerSize(0.4);
      Seff1D->GetYaxis()->SetLabelSize(0.04);
      Seff1D->SetTitle("P: all runs & channels");
      Seff1D->SetXTitle("<Aijk>");
      Seff1D->SetYTitle("N");
      Seff1D->SetMarkerColor(4);
      Seff1D->SetLineColor(4);
      //    Seff1D->Draw("Error");
          Seff1D->Draw("PL");
    }//Method = 10
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT9: M:    <Aijk>_ev.run for all runs
    if(Method == 9 ) {
      cout<<"****Draw 9 Dependencies: M: draw <Aijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      c1->SetFillColor(40);
      //    Ceff1D->SetTitle("any Error, HE Depth1 \n");
      Ceff1D->SetMarkerStyle(20);
      Ceff1D->SetMarkerSize(0.4);
      Ceff1D->GetYaxis()->SetLabelSize(0.04);
      Ceff1D->SetTitle("M: all runs & channels");
      Ceff1D->SetXTitle("<Aijk>");
      Ceff1D->SetYTitle("N");
      Ceff1D->SetMarkerColor(4);
      Ceff1D->SetLineColor(4);
      //    Ceff1D->Draw("Error");
          Ceff1D->Draw("PL");
    }//Method = 9
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT19: M:   <Aijk>_ev.run for all runs
    if(Method == 19 ) {
      cout<<"****Draw 19 Dependencies: M: draw <Aijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      c1->SetFillColor(40);
      //    Seff1D->SetTitle("any Error, HE Depth1 \n");
      Seff1D->SetMarkerStyle(20);
      Seff1D->SetMarkerSize(0.4);
      Seff1D->GetYaxis()->SetLabelSize(0.04);
      Seff1D->SetTitle("M: all runs & channels");
      Seff1D->SetXTitle("<Aijk>");
      Seff1D->SetYTitle("N");
      Seff1D->SetMarkerColor(4);
      Seff1D->SetLineColor(4);
      //    Seff1D->Draw("Error");
          Seff1D->Draw("PL");
    }//Method = 19
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT20: mean <Aijk>_ev.run for all runs Depth3
    if(Method == 20 ) {
      cout<<"****Draw 20 Dependencies: draw mean <Aijk>_ev.run for all runs Depth3  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110);  
      //    Meff3D->SetTitle("any Error, HE Depth3 \n");
      Meff3D->SetMarkerStyle(20);
      Meff3D->SetMarkerSize(0.4);
      Meff3D->GetYaxis()->SetLabelSize(0.04);
      Meff3D->SetXTitle("for mean <Aijk>");
      Meff3D->SetYTitle("N");
      Meff3D->SetMarkerColor(4);
      Meff3D->SetLineColor(4);
      //    Meff3D->Draw("Error");
          Meff3D->Draw("PL");
    }//Method = 20
    //  ////////////////////////////////////////////////////////////////////////// 
 
    //
    /*
Draw("APL"); - w/ errors

    */
    //                                                                               PLOTS WITH ZZM[k1][iii][jj]   :
    //
    //======================================================================================================= PLOT1 r vs t negative direction:Depth1  and eta 21 22 23 25 27 28
    if(Method == 1 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 1 Dependencies: M   r vs t for Depth1 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][1];}// eta=28
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][2];}/// eta=27
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][4];}/// eta=25
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][6];}/// eta=23
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][7];}/// eta=22
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][8];}/// eta=21
      gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth1");
      TLegend leg(xx1,yy1,xx2,yy2, " HEM Depth1");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//1
    //======================================================================================================= PLOT2 r vs t negative direction:Depth1  and eta 17 18? 19 20? 24 26 29
    if(Method == 2 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 2 Dependencies: M   r vs t for Depth1 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][0];
	//    if (YY[k1]>1.001 || YY[k1]<0.1 ) cout<<"\"" << LASERruns[k1] <<"\"," << endl;
	//    if (YY[k1]<.64 ) cout<<" k1 = " << k1 <<"     \"," <<"\"" << LASERruns[k1] <<"\"," <<" XX[k1] = " << YY[k1] <<" XX[k1] = " << YY[k1] << endl;
	//	    if (k1> 30 ) cout<<" k1 = " << k1 <<"     \"," <<"\"" << LASERruns[k1] <<"\"," <<" XX[k1] = " << XX[k1] <<" YY[k1] = " << YY[k1] << endl;


}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 29"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][3];}/// eta=26
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 26"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][5];}/// eta=24
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 24"); gr3->SetFillStyle(0); gr3->Draw("P");
//      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][9];}/// eta=20
//      gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(4); gr6->SetMarkerColor(4); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 20"); gr6->SetFillStyle(0); gr6->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][10];}/// eta=19
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(5); gr4->SetMarkerColor(5); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
//      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][11];}/// eta=18
//      gr7 = new TGraph(NP,XX,YY); gr7->SetLineColor(6); gr7->SetMarkerColor(6); gr7->SetMarkerStyle(20); gr7->SetMarkerSize(1.2); gr7->SetTitle("ieta 18"); gr7->SetFillStyle(0); gr7->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][12];}/// eta=17
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(7); gr5->SetMarkerColor(7); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 17"); gr5->SetFillStyle(0); gr5->Draw("P");
      //      TLegend leg(.6,.67,.78,.88, " HEP Depth1");
      TLegend leg(xx1,yy1,xx2,yy2, " HEM Depth1");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//12
    //
    //======================================================================================================= PLOT3 r vs t negative direction:Depth2  and eta 21 22 23 25
    if(Method == 3 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y3,x2,y4);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 3 Dependencies: M   r vs t for Depth2 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][4];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 25"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][6];}/// eta=23
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 23"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][7];}/// eta=22
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 22"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][8];}/// eta=21
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 21"); gr4->SetFillStyle(0); gr4->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth2");
      TLegend leg(xx1,yy1,xx2,yy2, " HEM Depth2");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);//leg.AddEntry(gr5);leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//3
    //
    //======================================================================================================= PLOT4 r vs t negative direction:Depth2  and eta 17 18 19 20 24 26
    if(Method == 4 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y3,x2,y4);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 4 Dependencies: M   r vs t for Depth2 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][3];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 26"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][5];}/// eta=24
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 24"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][9];}/// eta=20
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 20"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][10];}/// eta=19
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][11];}/// eta=18
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 18"); gr5->SetFillStyle(0); gr5->Draw("P");
      //    for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][12];}/// eta=17
      //    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 17"); gr6->SetFillStyle(0); gr6->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth2");
      TLegend leg(xx1,yy1,xx2,yy2, " HEM Depth2");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }// 4
    //
    //
    //================================================================================
    //================================================================================
    //======================================================================================================= PLOT5 negative direction:r vs t for L1  and eta 21 22 23 25 27 28
    if(Method == 5 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 5 Dependencies:  M  r vs t for L1  and eta 21 22 23 25 27 28   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: negative direction
// eta=28 L1=1
      for(int k1 = 0; k1<NP; k1++) {
	//    if(k1<3) {cout<<" ************* *************point = " << k1 <<endl;}
	// L1 lie in Depth1 only and so iii=1
	//    for(int iii = 1; iii<4; iii++) {
	for(int iii = 1; iii<2; iii++) {
	  //	for (int jj=0;jj<=13;jj++) {
	  for (int jj=0;jj<13;jj++) {
	    //jj   M:    >0   >1   2  >3  <4   5   6   7   8   9   10    11    12   <13      P:    0>   1   2   3   4   5   6   7   8   9   10>  <11    12<   13<
	    // real N:   29- -28 -27  26- 25  24  23  22  21  20   19    18    17-   16           16   17- 18  19  20  21  22  23  24  25   26-   27-   28-   29-
	    //  iii=depth, jj=eta
	    // M:
	    // ZZM[k1][iii][jj]    (iii=d1 & eta 17-29)                       L1
	                                                                                             int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 1)  {YY[k1] = ZZM[k1][iii][jj];} }}}
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=27 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 2)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=25 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 4)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=23 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 6)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=22 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 7)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
/// eta=21 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 8)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L1");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEM L1");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);//leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");


    }//if(Method == 5 
    //
    //======================================================================================================= PLOT6 negative direction:r vs t for L1  and eta 17 18 19 20 24 26 29
    if(Method == 6 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 6 Dependencies:  M  r vs t for L1  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
/// eta=29 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 0)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 29"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=26 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 3)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 26"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=24 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 5)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 24"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=20 L1=1
//	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 9)  {YY[k1] = ZZM[k1][iii][jj];} }}}
//  	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(4); gr6->SetMarkerColor(4); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 20"); gr6->SetFillStyle(0); gr6->Draw("P");
/// eta=19 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==10)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(5); gr4->SetMarkerColor(5); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=18 L1=1
//	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==11)  {YY[k1] = ZZM[k1][iii][jj];} }}}
//  	    gr7 = new TGraph(NP,XX,YY); gr7->SetLineColor(6); gr7->SetMarkerColor(6); gr7->SetMarkerStyle(20); gr7->SetMarkerSize(1.2); gr7->SetTitle("ieta 18"); gr7->SetFillStyle(0); gr7->Draw("P");
/// eta=17 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==12)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(7); gr5->SetMarkerColor(7); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 17"); gr5->SetFillStyle(0); gr5->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L1");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEM L1");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 6 


    //
    //======================================================================================================= PLOT7 negative direction:r vs t for L7  and eta 21 22 23 25 27 28
    if(Method == 7 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y5,x2,y6);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 7 Dependencies:  M  r vs t for L7  and eta 21 22 23 25 27 28   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: negative direction
// eta=28 L7=1
      for(int k1 = 0; k1<NP; k1++) {
	//    if(k1<3) {cout<<" ************* *************point = " << k1 <<endl;}
	for(int iii = 2; iii<4; iii++) {
	  for (int jj=0;jj<=13;jj++) {
	    //jj   M:    >0   >1   2  >3  <4   5   6   7   8   9   10    11    12   <13      P:    0>   1   2   3   4   5   6   7   8   9   10>  <11    12<   13<
	    // real N:   29- -28 -27  26- 25  24  23  22  21  20   19    18    17-   16           16   17- 18  19  20  21  22  23  24  25   26-   27-   28-   29-
	    //  (iii=d2 & eta 17-26) && (iii=d3 & eta 27-28)   L7
	                                                                                         int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==1){YY[k1]=ZZM[k1][iii][jj];}}}}
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=27 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==2){YY[k1]=ZZM[k1][iii][jj];}}}
	      //            cout<<"****   Negative direction:  reject bad runs eta 22   **** " <<endl;
	      //	    if (YY[k1]>1.05 || YY[k1]<0.45 ) cout<<"\"" << LASERruns[k1] <<"\"," << endl;

}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=25 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==4){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=23 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==6){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=22 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==7){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
/// eta=21 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==8){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L7");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEM L7");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);//leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 7 
    //
    //======================================================================================================= PLOT8 negative direction:r vs t for L7  and eta 17 18 19 20 24 26 29
    if(Method == 8 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y5,x2,y6);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 8 Dependencies:  M  r vs t for L7  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //======================================================= introduce Layers: negative direction
      //                                     (iii=d2 & eta 17-26) && (iii=d3 & eta 27-28)   L7
/// eta=26 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==3){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetTitle("ieta 26"); gr1->SetFillStyle(0); gr1->SetMarkerSize(1.2); gr1->Draw("P");
/// eta=24 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==5){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetTitle("ieta 24"); gr2->SetFillStyle(0); gr2->SetMarkerSize(1.2); gr2->Draw("P");
/// eta=20 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==9){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetTitle("ieta 20"); gr3->SetFillStyle(0); gr3->SetMarkerSize(1.2); gr3->Draw("P");
/// eta=19 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==10){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->SetMarkerSize(1.2); gr4->Draw("P");
/// eta=18 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==11){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetTitle("ieta 18"); gr5->SetFillStyle(0); gr5->SetMarkerSize(1.2); gr5->Draw("P");
/// eta=17 L7=1
//	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>2 && jj<13) || (iii==3 && jj>0 && jj<3)) LM7=1;if(LM7==1 && jj==12){YY[k1]=ZZM[k1][iii][jj];}}}}
//            gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetTitle("ieta 17"); gr6->SetFillStyle(0); gr6->SetMarkerSize(1.2); gr6->Draw("P");
//	    //    TLegend leg(.6,.67,.78,.88, " HEP L7");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEM L7");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 8 
    //
  //======================================================================================================= 
   //======================================================================================================= positive direction:
  //======================================================================================================= 
    //  //////////////////////////////////////////////////////////////////////////
    //
    //                                                                               PLOTS WITH ZZP[k1][iii][jj]   :
    //
    //======================================================================================================= PLOT11 r vs t positive direction:Depth1  and eta 21 22 23 25 27 28
    if(Method == 11 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 11 Dependencies: P   r vs t for Depth1 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][12];}// eta=28
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][11];}/// eta=27
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][9];}/// eta=25
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][7];}/// eta=23
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][6];}/// eta=22
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][5];}/// eta=21
      gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth1");
      TLegend leg(xx1,yy1,xx2,yy2, " HEP Depth1");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//11
    //======================================================================================================= PLOT12 r vs t positive direction:Depth1  and eta 17 18? 19 20? 24 26 29
    if(Method == 12 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 12 Dependencies: P   r vs t for Depth1 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][13];
	//	    if (YY[k1]>1.001 || YY[k1]<0.1 ) cout<<" k1 = " << k1 <<"     \"," <<"\"" << LASERruns[k1] <<"\"," << endl;
	//    if (YY[k1]<.64 ) cout<<" k1 = " << k1 <<"     \"," <<"\"" << LASERruns[k1] <<"\"," <<" XX[k1] = " << YY[k1] <<" XX[k1] = " << YY[k1] << endl;
	//	    if (k1> 30 ) cout<<" k1 = " << k1 <<"     \"," <<"\"" << LASERruns[k1] <<"\"," <<" XX[k1] = " << XX[k1] <<" YY[k1] = " << YY[k1] << endl;


}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 29"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][10];}/// eta=26
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 26"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][8];}/// eta=24
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 24"); gr3->SetFillStyle(0); gr3->Draw("P");
//      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][4];}/// eta=20
//      gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(4); gr6->SetMarkerColor(4); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 20"); gr6->SetFillStyle(0); gr6->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][3];}/// eta=19
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(5); gr4->SetMarkerColor(5); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
//      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][2];}/// eta=18
//      gr7 = new TGraph(NP,XX,YY); gr7->SetLineColor(6); gr7->SetMarkerColor(6); gr7->SetMarkerStyle(20); gr7->SetMarkerSize(1.2); gr7->SetTitle("ieta 18"); gr7->SetFillStyle(0); gr7->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][1];}/// eta=17
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(7); gr5->SetMarkerColor(7); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 17"); gr5->SetFillStyle(0); gr5->Draw("P");
      //      TLegend leg(.6,.67,.78,.88, " HEP Depth1");
      TLegend leg(xx1,yy1,xx2,yy2, " HEP Depth1");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//12
    //
    //======================================================================================================= PLOT13 r vs t positive direction:Depth2  and eta 21 22 23 25
    if(Method == 13 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y3,x2,y4);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 13 Dependencies: P   r vs t for Depth2 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][9];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 25"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][7];}/// eta=23
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 23"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][6];}/// eta=22
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 22"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][5];}/// eta=21
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 21"); gr4->SetFillStyle(0); gr4->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth2");
      TLegend leg(xx1,yy1,xx2,yy2, " HEP Depth2");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);//leg.AddEntry(gr5);leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//13
    //
    //======================================================================================================= PLOT14 r vs t positive direction:Depth2  and eta 17 18 19 20 24 26
    if(Method == 14 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y3,x2,y4);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 14 Dependencies: P   r vs t for Depth2 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][10];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 26"); gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][8];}/// eta=24
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 24"); gr2->SetFillStyle(0); gr2->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][4];}/// eta=20
      gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 20"); gr3->SetFillStyle(0); gr3->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][3];}/// eta=19
      gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][2];}/// eta=18
      gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 18"); gr5->SetFillStyle(0); gr5->Draw("P");
      //    for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][1];}/// eta=17
      //    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 17"); gr6->SetFillStyle(0); gr6->Draw("P");
      //    TLegend leg(.6,.67,.78,.88, " HEP Depth2");
      TLegend leg(xx1,yy1,xx2,yy2, " HEP Depth2");
      leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }//14
    //
    //================================================================================
    //================================================================================
    //======================================================================================================= PLOT15 positive direction:r vs t for L1  and eta 21 22 23 25 27 28
    if(Method == 15 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 15 Dependencies:  P  r vs t for L1  and eta 21 22 23 25 27 28   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: positive direction
// eta=28 L1=1
      for(int k1 = 0; k1<NP; k1++) {
	//    if(k1<3) {cout<<" ************* *************point = " << k1 <<endl;}
	// L1 lie in Depth1 only and so iii=1
	//    for(int iii = 1; iii<4; iii++) {
	for(int iii = 1; iii<2; iii++) {
	  for (int jj=1;jj<=13;jj++) {
	    //jj   M:    >0   >1   2  >3  <4   5   6   7   8   9   10    11    12   <13      P:    0>   1   2   3   4   5   6   7   8   9   10>  <11    12<   13<
	    // real N:   29- -28 -27  26- 25  24  23  22  21  20   19    18    17-   16           16   17- 18  19  20  21  22  23  24  25   26-   27-   28-   29-
	    //  iii=depth, jj=eta
	    // P:
	    // ZZP[k1][iii][jj]    (iii=d1 & eta 17-29)                       L1
	                                                                                             int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 12)  {YY[k1] = ZZP[k1][iii][jj];} }}}
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=27 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 11)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=25 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 9)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=23 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 7)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=22 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 6)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
/// eta=21 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 5)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L1");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEP L1");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);//leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
	    

    }//if(Method == 15 
    //
    //======================================================================================================= PLOT16 positive direction:r vs t for L1  and eta 17 18 19 20 24 26 29
    if(Method == 16 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 16 Dependencies:  P  r vs t for L1  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: negative direction
/// eta=29 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 13)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 29"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=26 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 10)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 26"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=24 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 8)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 24"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=20 L1=1
//  	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 4)  {if(ZZP[k1][iii][jj]<1.) YY[k1] = ZZP[k1][iii][jj];} }}}
//  	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(4); gr6->SetMarkerColor(4); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 20"); gr6->SetFillStyle(0); gr6->Draw("P");
/// eta=19 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 3)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(5); gr4->SetMarkerColor(5); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=18 L1=1
//  	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 2)  {if(ZZP[k1][iii][jj]<1.) YY[k1] = ZZP[k1][iii][jj];} }}}
//  	    gr7 = new TGraph(NP,XX,YY); gr7->SetLineColor(6); gr7->SetMarkerColor(6); gr7->SetMarkerStyle(20); gr7->SetMarkerSize(1.2); gr7->SetTitle("ieta 18"); gr7->SetFillStyle(0); gr7->Draw("P");
/// eta=17 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 1)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(7); gr5->SetMarkerColor(7); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 17"); gr5->SetFillStyle(0); gr5->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L1");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEP L1");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 16 
    //    
    //================================================================================
    //======================================================================================================= PLOT17 positive direction:r vs t for L7  and eta 21 22 23 25 27? 28?
    if(Method == 17 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y5,x2,y6);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 17 Dependencies:  P  r vs t for L7  and eta 21 22 23 25 27 28   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: positive direction
  //             eta:
  //depth1                     0    -     12                                                          1       -             13   (+57)
  //depth2                       2  -     13                                                            2     -     10
  //depth3                     1,2  -     13*                                                       0*        -       11, 12      
// eta=28 L7=1
      for(int k1 = 0; k1<NP; k1++) {
	for(int iii = 2; iii<4; iii++) {
	  for (int jj=1;jj<13;jj++) {
	    //jj   M:    >0   >1   2  >3  <4   5   6   7   8   9   10    11    12   <13      P:    0>   1   2   3   4   5   6   7   8   9   10>  <11    12<   13<
	    // real N:   29- -28 -27  26- 25  24  23  22  21  20   19    18    17-   16           16   17- 18  19  20  21  22  23  24  25   26-   27-   28-   29-
	    //
	    // P: int LP7=0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7=1;
                                                                                             int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 12)  {YY[k1] = ZZP[k1][iii][jj];} }}}
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 28"); gr1->SetFillStyle(0); gr1->Draw("P");
/// eta=27 L7=1
  for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 11)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 27"); gr2->SetFillStyle(0); gr2->Draw("P");
/// eta=25 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 9)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetMarkerSize(1.2); gr3->SetTitle("ieta 25"); gr3->SetFillStyle(0); gr3->Draw("P");
/// eta=23 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 7)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetMarkerSize(1.2); gr4->SetTitle("ieta 23"); gr4->SetFillStyle(0); gr4->Draw("P");
/// eta=22 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 6)  {YY[k1] = ZZP[k1][iii][jj];} }}
	      // reject bad runs:
      //            cout<<"****   Positive direction:  reject bad runs eta 22   **** " <<endl;
	    if (YY[k1]>1.05 || YY[k1]<0.1 ) cout<<"\"" << LASERruns[k1] <<"\"," << endl;

}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetMarkerSize(1.2); gr5->SetTitle("ieta 22"); gr5->SetFillStyle(0); gr5->Draw("P");
/// eta=21 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 5)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetMarkerSize(1.2); gr6->SetTitle("ieta 21"); gr6->SetFillStyle(0); gr6->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L7");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEP L7");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);leg.AddEntry(gr6);//leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 17 
   //
    //======================================================================================================= PLOT18 positive direction:r vs t for L7  and eta 17 18 19 20 24 26
    if(Method == 18 ) {
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(40);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y5,x2,y6);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 18 Dependencies:  P  r vs t for L7  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: positive direction
/// eta=26 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 10)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetTitle("ieta 26"); gr1->SetFillStyle(0); gr1->SetMarkerSize(1.2); gr1->Draw("P");
/// eta=24 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 8)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetTitle("ieta 24"); gr2->SetFillStyle(0); gr2->SetMarkerSize(1.2); gr2->Draw("P");
/// eta=20 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 4)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr3 = new TGraph(NP,XX,YY); gr3->SetLineColor(3); gr3->SetMarkerColor(3); gr3->SetMarkerStyle(20); gr3->SetTitle("ieta 20"); gr3->SetFillStyle(0); gr3->SetMarkerSize(1.2); gr3->Draw("P");
/// eta=19 L7=1
  for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 3)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr4 = new TGraph(NP,XX,YY); gr4->SetLineColor(4); gr4->SetMarkerColor(4); gr4->SetMarkerStyle(20); gr4->SetTitle("ieta 19"); gr4->SetFillStyle(0); gr4->SetMarkerSize(1.2); gr4->Draw("P");
/// eta=18 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 2)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr5 = new TGraph(NP,XX,YY); gr5->SetLineColor(5); gr5->SetMarkerColor(5); gr5->SetMarkerStyle(20); gr5->SetTitle("ieta 18"); gr5->SetFillStyle(0); gr5->SetMarkerSize(1.2); gr5->Draw("P");
/// eta=17 L7=1
//   for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 1)  {YY[k1] = ZZP[k1][iii][jj];} }}}
        //    gr6 = new TGraph(NP,XX,YY); gr6->SetLineColor(6); gr6->SetMarkerColor(6); gr6->SetMarkerStyle(20); gr6->SetTitle("ieta 17"); gr6->SetFillStyle(0); gr6->SetMarkerSize(1.2); gr6->Draw("P");
	    //    TLegend leg(.6,.67,.78,.88, " HEP L7");
	    TLegend leg(xx1,yy1,xx2,yy2, " HEP L7");
	    leg.AddEntry(gr1);leg.AddEntry(gr2);leg.AddEntry(gr3);leg.AddEntry(gr4);leg.AddEntry(gr5);//leg.AddEntry(gr6);leg.AddEntry(gr7);leg.AddEntry(gr8);
	    leg.SetMargin( 0.3 );
	    leg.SetBorderSize(1);
	    leg.DrawClone("Same");
    }//if(Method == 18 
   //    
    //======================================================================================================= PLOT21 r vs t positive direction:Depth3  and eta 27 28
    if(Method == 21 ) {
   gStyle->SetOptTitle(kFALSE);
   gStyle->SetPalette(kSolar);
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      //    c1->SetFillColor(40);
      c1->SetFillColor(0);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
      pad1->Draw();pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);pad1->Draw();gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 21 Dependencies: P   r vs t for Depth3 and some eta 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][3][11];}/// eta=27
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetTitle("ieta 27"); gr1->SetName("gr1");gr1->SetFillStyle(0); gr1->Draw("P");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][3][12];}/// eta=28
      gr2 = new TGraph(NP,XX,YY); gr2->SetLineColor(2); gr2->SetMarkerColor(2); gr2->SetMarkerStyle(20); gr2->SetMarkerSize(1.2); gr2->SetTitle("ieta 28"); gr2->SetName("gr2"); gr2->SetFillStyle(0); gr2->Draw("P");
      //    TLegend leg(.5,.67,.88,.88,     "HEP Depth3");
      TLegend leg(xx1,yy1,xx2,yy2, " HEP Depth3");
      leg.AddEntry(gr1); leg.AddEntry(gr2);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      
      //            gPad->BuildLegend(.5,.67,.88,.88,"HEP L7");
//virtual TLegend * 	BuildLegend (Double_t x1=0.5, Double_t y1=0.67, Double_t x2=0.88, Double_t y2=0.88, const char *title="", Option_t *option="")      

   }//21
    //
    //================================================================================
    //======================================================================================================= PLOT22:
    if(Method == 22 ) {
      cout<<"****Draw 22 Dependencies: M: draw <Rijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(1110000); 
      rwithphi->SetMarkerStyle(20);
      rwithphi->SetMarkerSize(0.4);
      rwithphi->GetYaxis()->SetLabelSize(0.04);
      rwithphi->SetTitle("all runs & channels");
      rwithphi->SetXTitle("<Rijk>");
      rwithphi->SetYTitle("N");
      rwithphi->SetMarkerColor(4);
      rwithphi->SetLineColor(4);
      //    rwithphi->Draw("Error");
          rwithphi->Draw("PL");
    }//Method = 22

    //================================================================================
    //======================================================================================================= PLOT23:
    if(Method == 23 ) {
      cout<<"****Draw 23 Dependencies: gains LED runs used  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(1110000); 
      gainkoeff->SetMarkerStyle(20);
      gainkoeff->SetMarkerSize(0.4);
      gainkoeff->GetYaxis()->SetLabelSize(0.04);
      gainkoeff->SetTitle("all channels");
      gainkoeff->SetXTitle("gains");
      gainkoeff->SetYTitle("N");
      gainkoeff->SetMarkerColor(4);
      gainkoeff->SetLineColor(4);
      //    gainkoeff->Draw("Error");
          gainkoeff->Draw("PL");
    }//Method = 23
    //================================================================================
    //====================================================================================================================================================
    //================================================================================

	    /*
// Define a linear function
TF1 f("Linear law","[0]+x*[1]",.5,10.5);
// Lets make the funcion line nicer
f.SetLineColor(kRed); f.SetLineStyle(2);
// Fit it to the graph and draw it
//Fit(&f);
f.DrawClone("Same");
      // Build and Draw a legend
      TLegend leg(.1,.7,.3,.9,"Lab. Lesson 1");
      leg.SetFillColor(0);
      gPad->SetFillColor(0);
      leg.AddEntry("Exp. Points");
      leg.AddEntry("Th. Law");
      leg.DrawClone("Same");
// Draw an arrow on the canvas
TArrow arrow(8,8,6.2,23,0.02,"|>");
arrow.SetLineWidth(2);
arrow.DrawClone();
// Add some text to the plot
TLatex text(8.2,7.5,"#splitline{Maximum}{Deviation}");
text.DrawClone();

      TLegend *legend = new TLegend(.75,.80,.95,.95);
      legend->AddEntry(bg,"Background(WW)");
      legend->AddEntry(sig,"Signal(Higgs)");
      legend->Draw();

         // Draw legend               
         TLegend *legend= new TLegend( c->GetLeftMargin(), 1       - c->GetTopMargin() - 0.12, 
                                       c->GetLeftMargin() + 0.3, 1 - c->GetTopMargin() );
         legend->SetFillStyle( 1 );
         legend->AddEntry(sig,"Signal","F");
         legend->AddEntry(bgd,"Background","F");
         legend->SetBorderSize(1);
         legend->SetMargin( 0.3 );
         legend->Draw("same");


*/


  // L1: (iii=d1 & eta 17-29); 
  // M: int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1; 
  // P: int LP1 = 0;if((iii==1 && jj> 0)) LP1 = 1;

  // :L7:  (iii=d2 & eta 17-26) && (iii=d3 & eta 27-28) 
  // M: int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj> 1 && jj< 4)) LM7=1; 
  // P: int LP7=0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7=1;
    
    
  //======================================================================================================= 
  //======================================================================================================= finish loop over Methods
  //======================================================================================================= 
    TString fdir = "testamt3neg/";
    //
    TString plotName = fdir + MethodName[Method] +".png";
    c1->SaveAs(plotName);
    cout<<"****PLOT "   << Method  <<" drawn **** " <<endl;
    
    }//if( Method != 9 
    ++Method;
  }// loop over Methods
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
	    /*
// Define a linear function
TF1 f("Linear law","[0]+x*[1]",.5,10.5);
// Lets make the funcion line nicer
f.SetLineColor(kRed); f.SetLineStyle(2);
// Fit it to the graph and draw it
//Fit(&f);
f.DrawClone("Same");
      // Build and Draw a legend
      TLegend leg(.1,.7,.3,.9,"Lab. Lesson 1");
      leg.SetFillColor(0);
      gPad->SetFillColor(0);
      leg.AddEntry("Exp. Points");
      leg.AddEntry("Th. Law");
      leg.DrawClone("Same");
// Draw an arrow on the canvas
TArrow arrow(8,8,6.2,23,0.02,"|>");
arrow.SetLineWidth(2);
arrow.DrawClone();
// Add some text to the plot
TLatex text(8.2,7.5,"#splitline{Maximum}{Deviation}");
text.DrawClone();

      TLegend *legend = new TLegend(.75,.80,.95,.95);
      legend->AddEntry(bg,"Background(WW)");
      legend->AddEntry(sig,"Signal(Higgs)");
      legend->Draw();

         // Draw legend               
         TLegend *legend= new TLegend( c->GetLeftMargin(), 1       - c->GetTopMargin() - 0.12, 
                                       c->GetLeftMargin() + 0.3, 1 - c->GetTopMargin() );
         legend->SetFillStyle( 1 );
         legend->AddEntry(sig,"Signal","F");
         legend->AddEntry(bgd,"Background","F");
         legend->SetBorderSize(1);
         legend->SetMargin( 0.3 );
         legend->Draw("same");


*/
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //______________________________________________________________________________
  //______________________________________________________________________________
  //  
  //______________________________________________________________________________
  //______________________________________________________________________________
  //  
  gSystem->Exit(0);
  //______________________________________________________________________________
}
//______________________________________________________________________________
