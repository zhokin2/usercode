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
#include <TGaxis.h>

#include "TGraphErrors.h"
#include "TF1.h"
#include "TArrow.h"

//
using namespace std;
//
//  
int main(int argc, char *argv[])
{
  //______________________________________________________________________________________________________________________________    
  //TCanvas *c1;
  TGraph *gr1;  TGraph *gr2;TGraph *gr3;  TGraph *gr4;TGraph *gr5;  TGraph *gr6;TGraph *gr7;TGraph *gr8;TGraph *gr9;
  TGraphErrors* ge1;TGraphErrors* ge2;TGraphErrors* ge3;TGraphErrors* ge4;TGraphErrors* ge5;TGraphErrors* ge6;TGraphErrors* ge7;TGraphErrors* ge8;TGraphErrors* ge9;

  //
  const Int_t NMethods =16;// total number of Methods (all-together 37 methods)
  const Int_t NMethodsStart =0;     // since which method to start ( min=  0)
  const Int_t NMethodsToUse =15;// choose Number of methods to use ( max= 36)
  //
 TString MethodName[NMethods] = { "PLOT0", "PLOT1", "PLOT2", "PLOT3", "PLOT4", "PLOT5" , "PLOT6" , "PLOT7" , "PLOT8" , "PLOT9" , "PLOT10"  , "PLOT11" , "PLOT12" , "PLOT13", "PLOT14" , "PLOT15" };
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
  //______________________________________________________________________________________________________________________________   WORKABLE:
 
  //______________________________________________________________________________________________________________________________ 22+161=183   
// (306249 -> 07.11.2017)   164   +   DEL=23+31+11= 65    (307782 -> 11.01.2018)     = 229       
// const Int_t NMAXM =22;// 
// const Int_t NMAXM =17;// 
// const Int_t NMAXM =12;// 
// const Int_t NMAXM =2;// 
// const Int_t NMAXM =4;// 
 const Int_t NMAXM =1;// 
 TString LEDrunsM[NMAXM] = {

   /*
   // 2017 HEP17 shunt6
   "295401","295675","296185","296808","297082","297522","297571","297630","297687","298863",
   "299468","302183","302246","302585","304276","304432","304526","305142","305485","305711",
   "305886","306249" 
*/

     /*
   // 2018  shunt6
   "308784","308882","309238","309318","309321",
   "309370","309573","309704","310262","310456",
   "310847","310973"
   //        5.03.2018
*/

   // 2018
   //   "309370","310847"


   ////////////////////////////    shunt1

   // 2018 shunt1:
   //   "310244","310387","310587","310650"
   //
   //"309880"
"308701"



 };
 ///////////////////////////////
 Float_t X0M[NMAXM] = {
     /*
   // 2017 HEP17 shunt6
     1.,      4.,      10.,     18.,      21.,   30.,     31.,      32.,    33.,     46.,     
    54.,     97.,      98.,    106.,     128.,  130.,    132.,     142.,   149.,    152.,  
   156.,    164. 
*/

     /*
   // 2018   shunt6
   1.,        2.,      8.,     9.,      10.,   
   13.,      14.,     20.,    23.,      25., 
   31.,      34.
*/

   // 2018
//  13.,     31.

  1.


   ////////////////////////////    shunt1

   // 2018 shunt1:
   //   1.,     7.,     11.,     31.

     //850.,900.,950.,1000.,1050.,1100.,1150.,1200.
 };// days of year    time points (abscissa) !!!


  //______________________________________________________________________________________________________________________________   TEST
  //______________________________________________________________________________________________________________________________   TEST
  //______________________________________________________________________________________________________________________________   TEST
  //______________________________________________________________________________________________________________________________   TEST
 /*
 const Int_t NMAXM =1;// 
 TString LEDrunsM[NMAXM] = {
   // "309445"
   "309714"
 };
 ///////////////////////////////
 Float_t X0M[NMAXM] = {
     1.
 };// days of year    time points (abscissa) !!!
*/
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //______________________________________________________________________________
 //______________________________________________________________________________
 //______________________________________________________________________________
 //______________________________________________________________________________
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                           2017 only:                   yearcase=0 for test

 //                                           2016 only:                   yearcase=1
 //                                           2017 only:                   yearcase=2
 //                                           20167    :                   yearcase=3
 //                                           2018 only:                   yearcase=4
 //                                           201678   :                   yearcase=5
 
 //define yearcase:
 //         ____________________________________________________________________________                    THIS line below is MAIN to make a yearcase selection !!!!!!!!!!!!!!!!!!!!!!!!!!
 const Int_t yearcase = 0; 
 //
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //    Int_t verbosity = 2;//  
    //    Int_t verbosity = 3;//  
    //    Int_t verbosity = 4;//   to clarify # channels in HEP17
        Int_t verbosity = 0;//  
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//  const Int_t flagHEP17selection = 1;// ==1 HEP17;   else -> ALL channels
 const Int_t flagHEP17selection = 0;// ==1 HEP17;   else -> ALL channels
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //______________________________________________________________________________

  //______________________________________________________________________________
  //______________________________________________________________________________
  //
  //---=[ SetCanvasDef           ]=----------------
  // Create a new canvas.
 //TCanvas  *c1 = new TCanvas("c1","GSM",10,10,900,700);

 //TCanvas  *c1 = new TCanvas("c1","GSM",20,50,920,850);
  TCanvas  *c1 = new TCanvas("c1","GSM",10,10,1010,1010);


  //TCanvas  *c1 = new TCanvas("c1","GSM",200,10,700,900);
  //TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);

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
  t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LED run for some random HE channels");
  
  //-----------------------------------------------------------------------------------------------------
  //
  //              x1   y1     x2     y2
  //    pad1->DrawFrame(1,   0.8,  370,   1.2);// all 

  //
  //      Float_t x1=0.00; Float_t x2=170.00;
   //       Float_t x1=0.00; Float_t x2=850.00;
          Float_t x1=0.00; Float_t x2=35.00;


  // y(ordinate) for All Days
  //(yearcase == 1
  Float_t y1=0.9; Float_t y2=  1.1; //  for 1,2,5,6   for 11,12,15,16
  //  Float_t y1=0.95; Float_t y2=  1.05; //  for 1,2,5,6   for 11,12,15,16
  //  Float_t y1=0.5; Float_t y2=  1.5; //  for 1,2,5,6   for 11,12,15,16



  //
  //  Float_t RrangeMIN = 0.10;Float_t RrangeMAX = 1.9;
//  Float_t RrangeMIN = 0.80;Float_t RrangeMAX = 1.2;
//  Float_t RrangeMIN = 0.90;Float_t RrangeMAX = 1.1;
//  Float_t RrangeMIN = 0.985;Float_t RrangeMAX = 1.006;
//  Float_t RrangeMIN = 0.910;Float_t RrangeMAX = 1.033;
  // x(abscissa) for Days
  //(yearcase == 1
  Float_t RrangeMIN = y1;Float_t RrangeMAX = y2;

  

  // 
  Float_t xx1=0.35; Float_t xx2=0.55;
  Float_t yy1=0.76; Float_t yy2=0.88;
  // 
  //-----------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // define max size of massives (to be just NMAXSIZE ):
  Int_t NMAXSIZE = NMAXM;
  //----------------------------------------------------------------------
  Float_t X0[NMAXSIZE];TString LEDruns[NMAXSIZE]; Double_t XX[NMAXSIZE]; Double_t XXE[NMAXSIZE]; Double_t XXX[NMAXSIZE]; Double_t XXXE[NMAXSIZE]; Int_t indWAS[NMAXSIZE]; 
  const Int_t NDEP =8;const Int_t NETA0=83;const Int_t NPHI0=73;
  
  Double_t YY[NMAXSIZE]; Double_t YYE[NMAXSIZE]; 
  //
  Double_t mapRATIO[NDEP][NETA0][NPHI0]; Double_t mapRATIOD2[NETA0][NPHI0]; Int_t mapRATIOD20[NETA0][NPHI0]; Double_t GSMRATIOD2[NMAXSIZE][NETA0][NPHI0]; 

  //Double_t normalization[NDEP][NETA0][NPHI0]; 
  Double_t normalization[NETA0][NPHI0]; 
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
  // define where to run inside massives above:
  Int_t NMINmM= 0; Int_t NMAXmM= NMAXSIZE-1; Int_t NMAXaM= NMAXSIZE; 
  if(yearcase == 1 ) {
    //                                           2016 only:                     yearcase=1
    NMINmM = 0; NMAXmM = 46; NMAXaM = 47; // M  
  }
  else if(yearcase == 2 ) {
    //                                           2017 only::                    yearcase=2
    NMINmM = 53; NMAXmM = 93;  NMAXaM = 41; // M  
  }
  else if(yearcase == 3 ) {
    //                                           20167 only::                   yearcase=3
    NMINmM = 0; NMAXmM = 93;  NMAXaM = 94; // M  
  }
  else if(yearcase == 4 ) {
    //                                           2018 only::                    yearcase=4
    NMINmM =  94; NMAXmM = -1; NMAXaM = -1; // M  
  }
  else if(yearcase == 5 ) {
    //                                           20168 only::                   yearcase=5
    NMINmM = 0; NMAXmM = -1; NMAXaM = -1; // M  
  }
  
  if( NMINmM == -1 || NMAXmM == -1 || NMAXaM == -1   ) 
    cout << " STOP  !!!!!!     NMINmM == -1 || NMAXmM == -1 || NMAXaM == -1 " <<endl;
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Int_t NMAX = 0;
      NMAX = NMAXaM;
//      cout << "NMAX= " << NMAX << "NMINmM= " << NMINmM << "NMAXmM= " << NMAXmM <<endl;
      for(int jjj = NMINmM; jjj<=NMAXmM; jjj++){
	LEDruns[jjj-NMINmM]=LEDrunsM[jjj];
	X0[jjj-NMINmM]=X0M[jjj];
//	cout << "jjj= " << jjj << "     jjj-NMINmM= " << jjj-NMINmM << "     LEDrunsM[jjj]= " << LEDrunsM[jjj] << "     X0M[jjj]= " << X0M[jjj] <<endl;
      }
    //////////////////////////////////////////////////////
    //========================================================================================================================
    //---------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------------
      //      Int_t NP = 22; // for loop over time points(LED runs) NMAX is number of LED runs(time abscissa)
		     Int_t NP = NMAX;  // for loop over time points(LED runs) NMAX is number of LED runs(time abscissa)
    cout << " NP = " << NP <<endl;
    //
    //---------------------------------------------------------------------------------------------------------------------  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
    //    Double_t cutMinA =400.; Double_t cutMaxA = 1200.;  // HPD HE only

        Double_t cutMinA =0.; Double_t cutMaxA = 999999999999.;
// 	    	        Double_t cutMinA =50000.; Double_t cutMaxA = 350000.;

    //    Double_t cutMinA =9000.; Double_t cutMaxA = 40000.;  
  //
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //---------------------------------------------------------------------------------------------------------------------
  //------------------------------------ define DELTA (days) of current point wrt first point
    for(int kk1 = 0; kk1<NP; kk1++){ 
      XX[kk1] = X0[kk1];   
      int k10 = 0; 
      int z1=X0[k10];  
      XX[kk1] -= z1;  
      if(verbosity == 2 ){cout << "ORDINATE points:    kk1 =  " <<kk1   <<"  XX[kk1]= " << XX[kk1] <<endl;}
  
      XXE[kk1] = 0.001*XX[kk1];
    }//XXE - errors at fit
    //-----------------------------------------------------------------------------------------------------


  //----------------------------------------------------------------------------------------------------
  //----------------------------------------------------------------------------------------------------
  ///////////////////////////////////////////////////////////////////////// initial nulling:
  for (int jjj=0;jjj<=82;jjj++) {
    for (int kkk=0;kkk<=72;kkk++) {
      mapRATIOD2[jjj][kkk] =  0.;
      mapRATIOD20[jjj][kkk] =  0.;
      normalization[jjj][kkk] = 0.;

      for(int k1 = 0; k1<NP; k1++) {
	GSMRATIOD2[k1][jjj][kkk] = mapRATIOD2[jjj][kkk];
      }
      
      for(int iii = 0; iii<NDEP; iii++) {
	mapRATIO[iii][jjj][kkk] = 0.;
	//	normalization[iii][jjj][kkk] = 0.;
      }

    }// for
  }// for
  

  /////////////////////////////////////////////////////////////////////////

  //______________________________________________________________________________
  //     ls -latr /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_* | less  

  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";
//  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LASER_";

  // booking:
//  TH1F* Seff1D = new TH1F("Seff1D","", 1000, 10.,100010.);
//  TH1F* Ceff1D = new TH1F("Ceff1D","", 1500, 10.,500010.);
//    TH1F* Seff1D = new TH1F("Seff1D","", 1000, 0.,100000.);
//    TH1F* Ceff1D = new TH1F("Ceff1D","", 1500, 0.,1500000.);
// led shunt1 low-intensity Gsel0:
    TH1F* Seff1D = new TH1F("Seff1D","", 1000, 0.,1000.);
    TH1F* Ceff1D = new TH1F("Ceff1D","", 350, 0.,350.);



  TH2F* mapBADchannels = new TH2F("mapBADchannels"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapBADchannels0 = new TH2F("mapBADchannels0"," ", 82, -41., 41., 72, 0., 72.);

  TH2F* mapchannelsdepth1= new TH2F("mapchannelsdepth1"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth2= new TH2F("mapchannelsdepth2"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth3= new TH2F("mapchannelsdepth3"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth4= new TH2F("mapchannelsdepth4"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth5= new TH2F("mapchannelsdepth5"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth6= new TH2F("mapchannelsdepth6"," ", 82, -41., 41., 72, 0., 72.);
  TH2F* mapchannelsdepth7= new TH2F("mapchannelsdepth7"," ", 82, -41., 41., 72, 0., 72.);


  TH1F* gainkoeff = new TH1F("gainkoeff","", 100, y1,y2);
  TH1F* gainkoeff0= new TH1F("gainkoeff0","", 100, 0.9,1.1);
  TH1F* gainkoeff9= new TH1F("gainkoeff9","", 100, 0.1,1.9);
  TH1F* GOODruns = new TH1F("GOODruns","", NP, 0.,float(NP));
  TH1F* BADruns = new TH1F("BADruns","", NP, 0.,float(NP));
  TH1F* NotEmptyDepthes = new TH1F("NotEmptyDepthes","", 56, 0.,56.);

  //////////////////////////////////////////////////////////////////////  initial variables
  Int_t kmm = 0;
  Int_t firstrun=1; 
  //

  //////////////////////////////////////////////////////////////////////////////////////////////  LOOP    ratio current
  //////////////////////////////////////////////////////////////////////////  LOOP    ratio current
  //////////////////////////////////////////////////////////////////////////  LOOP    ratio current
    
  /////////////////////////////////////////////////////////////////////////////////////////      
  //    cout << "!!!!!!!!!!!!!!!!!!!!!! use root files from official RMT dir. " <<endl;
  //cout << "!!!!!!!!!!!!!!!!!!!!!! use root files from my shunt6 dir. " <<endl;
  cout << "!!!!!!!!!!!!!!!!!!!!!! use root files from my shunt1 dir. " <<endl;
  /////////////////////////////////////////////////////////////////////////////////////////      
  //  TH1F* Aeff1D = new TH1F("Aeff1D","", 300, 0.,300.);
  TH1F* Aeff1D = new TH1F("Aeff1D","", 200, 0.,2000000.);
  int ck1count = 0;
  for(int k1 = 0; k1<NP; k1++) {
    ck1count++;
    /////////////////////////////////////////////////////////////////////////////////////////      
    // my dir.
    //	  TString epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";
		     TString epsName = "rootshunt1/LEDtest" + LEDruns[k1] + ".root";
    
    //      if(k1 > 21) {epsName = fname + LEDruns[k1] + ".root";}// 2018 shunt1
    //    	  TString epsName = "rootshunt1/LEDtest" + LEDruns[k1] + ".root";
    
    /*
      TString epsName;
      if(k1 < 0) {epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";}// was used: shunt6 for HEP17 2017 channels !!!
      if(k1 == 0) {epsName = "rootshunt1/LEDtest" + LEDruns[k1] + ".root";}
      if(k1 == 1) {epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";}
*/
      //		  TString epsName = "LEDtest" + LEDruns[k1] + ".root";

      //	  TString epsName = "LEDtest309714.root";
		  //	  TString epsName = "LEDtest307971NEW.root";

      // RMT:
      //      	  	    TString epsName = fname + LEDruns[k1] +".root";

      /////////////////////////////////////////////////////////////////////////////////////////      
      
      TFile *hfile= new TFile(epsName, "READ");
      //      cout << "!!!! read LED run with k1= " << k1   <<"  run:  " << LEDruns[k1] <<endl;

      
      // display existing histoes: preparation for plotting all runs into Aeff1D
      //      TH1F * Aeff1= (TH1F*)hfile->Get("h_ADCAmpl_HE");
//    h_ADCAmpl345Zoom_HE = new TH1F("h_ADCAmpl345Zoom_HE"," ", 300, 0.,300.);
//    h_ADCAmpl345Zoom1_HE = new TH1F("h_ADCAmpl345Zoom1_HE"," ", 200, 0.,1200.);
//    h_ADCAmplZoom1_HE = new TH1F("h_ADCAmplZoom1_HE"," ", 500, 0.,500.);



//      TH1F * Aeff1= (TH1F*)hfile->Get("h_ADCAmpl345Zoom_HE");
//      TH1F * Aeff1= (TH1F*)hfile->Get("h_ADCAmpl345Zoom1_HE");
//      TH1F * Aeff1= (TH1F*)hfile->Get("h_ADCAmplZoom1_HE");
      TH1F * Aeff1= (TH1F*)hfile->Get("h_ADCAmpl_HE");


      int kx = Aeff1->GetXaxis()->GetNbins();
      //      cout  <<"BEGINNING k1= " << k1 <<" kx= " << kx <<endl;
      int maxvalueA = -1;
      for (int jjj=0;jjj<kx;jjj++) {
	if(double(Aeff1->GetBinContent(jjj))>0. && maxvalueA < jjj ) maxvalueA = jjj;
	//	cout  <<" k1= " << k1 <<" jjj= " << jjj <<" content= " << Aeff1->GetBinContent(jjj) <<endl;
	Aeff1D->Fill(float(jjj), double(Aeff1->GetBinContent(jjj)) );
      }// for
      cout  <<" run = " << LEDruns[k1]  <<" k1= " << k1 <<" max bin value= " << maxvalueA <<" ck1count= " << ck1count <<endl;
      
	
      // 
      // 
      // display last-run existing histoes:
       if(k1== NP-1 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy();
	gPad->SetGridx();
		gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff1->SetMarkerStyle(20);
	Aeff1->SetMarkerSize(0.4);
	Aeff1->GetYaxis()->SetLabelSize(0.04);
	//	Aeff1->SetTitle("Last run & events & channels");
	Aeff1->SetXTitle("Aijk");
	Aeff1->SetYTitle("N");
	Aeff1->SetMarkerColor(4);
	Aeff1->SetLineColor(4);
	Aeff1->SetMinimum(0.8);
	Aeff1->Draw("PL");
	c1->Update();
	TString fdir = "testamt9gsm2018/";
	//	TString plotName = fdir + "Aijk.png";
	TString plotName = fdir + "Aijk-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijkLastRun.png is drawn **** " <<endl;
       }
      // display first runt existing histoes:
      if(k1== 0 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy();
	gPad->SetGridx();
	//	gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff1->SetMarkerStyle(20);
	Aeff1->SetMarkerSize(0.4);
	Aeff1->GetYaxis()->SetLabelSize(0.04);
	Aeff1->SetTitle("First run & events & channels");
	Aeff1->SetXTitle("Aijk");
	Aeff1->SetYTitle("N");
	Aeff1->SetMarkerColor(4);
	Aeff1->SetLineColor(4);
	Aeff1->SetMinimum(0.8);
	Aeff1->Draw("PL");
	c1->Update();
	TString fdir = "testamt9gsm2018/";
	TString plotName = fdir + "AijkFirstRun.png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijkLAST.png is drawn **** " <<endl;
      }
      // 000000000000000000000000000000000000000000000000000000000000000000000000
      //      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl");
      //      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl");
      //      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl");
      // 111111111111111111111111111111111111111111111111111111111111111111111111
      // h_mapDepth1ADCAmpl12 means ADCcounts(massive) within -1 max +1 +2
      
    /*
    TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12_HE");
    TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl12_HE");
    TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl12_HE");
*/
      // HEP17 of 2017:
//      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12SiPM_HE");
//      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl12SiPM_HE");
//      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl12SiPM_HE");
// all:

      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12_HE");
      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl12_HE");
      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl12_HE");
      
      TH2F *twod4= (TH2F*)hfile->Get("h_mapDepth4ADCAmpl12_HE");
      TH2F *twod5= (TH2F*)hfile->Get("h_mapDepth5ADCAmpl12_HE");
      TH2F *twod6= (TH2F*)hfile->Get("h_mapDepth6ADCAmpl12_HE");
      TH2F *twod7= (TH2F*)hfile->Get("h_mapDepth7ADCAmpl12_HE");

// all TS bins:
//      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl_HE");
//      TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl_HE");
//      TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl_HE");
      
//      TH2F *twod4= (TH2F*)hfile->Get("h_mapDepth4ADCAmpl_HE");
//      TH2F *twod5= (TH2F*)hfile->Get("h_mapDepth5ADCAmpl_HE");
//      TH2F *twod6= (TH2F*)hfile->Get("h_mapDepth6ADCAmpl_HE");
//      TH2F *twod7= (TH2F*)hfile->Get("h_mapDepth7ADCAmpl_HE");

      int nx = twod1->GetXaxis()->GetNbins();
      int ny = twod1->GetYaxis()->GetNbins();
      //      cout  <<"BEGINNING k1= " << k1 <<" nx= " << nx <<" ny= " << ny   <<endl;
      
      TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth1_HE");
      TH2F *t0020= (TH2F*)hfile->Get("h_mapDepth2_HE");
      TH2F *t0030= (TH2F*)hfile->Get("h_mapDepth3_HE");
      TH2F *t0040= (TH2F*)hfile->Get("h_mapDepth4_HE");
      TH2F *t0050= (TH2F*)hfile->Get("h_mapDepth5_HE");
      TH2F *t0060= (TH2F*)hfile->Get("h_mapDepth6_HE");
      TH2F *t0070= (TH2F*)hfile->Get("h_mapDepth7_HE");

      TH2F* Ceff1= (TH2F*)twod1->Clone("Ceff1");
      TH2F* Ceff2= (TH2F*)twod2->Clone("Ceff2");
      TH2F* Ceff3= (TH2F*)twod3->Clone("Ceff3");
      TH2F* Ceff4= (TH2F*)twod4->Clone("Ceff4");
      TH2F* Ceff5= (TH2F*)twod5->Clone("Ceff5");
      TH2F* Ceff6= (TH2F*)twod6->Clone("Ceff6");
      TH2F* Ceff7= (TH2F*)twod7->Clone("Ceff7");

    // <Aijk>_runevents:
    Ceff1->Divide(twod1,t0010, 1, 1, "B");  
    Ceff2->Divide(twod2,t0020, 1, 1, "B");  
    Ceff3->Divide(twod3,t0030, 1, 1, "B");  
    Ceff4->Divide(twod4,t0040, 1, 1, "B");  
    Ceff5->Divide(twod5,t0050, 1, 1, "B");  
    Ceff6->Divide(twod6,t0060, 1, 1, "B");  
    Ceff7->Divide(twod7,t0070, 1, 1, "B");  
    //      Ceff1->Sumw2();Ceff2->Sumw2();Ceff3->Sumw2();
    ///////////////////////////////////////////////////////////////////////////////////////////
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	// HEP17 selection:   
	if(flagHEP17selection == 0 || (flagHEP17selection == 1 && ( (( jjj > 56 && jjj < 62 ) && (kkk >63 && kkk < 68 )) || (( jjj > 61 && jjj < 71 ) && (kkk == 64 || kkk == 66 )))) ) {
	  //	  if(Ceff1->GetBinContent(jjj,kkk) !=0.)  cout  <<" k1=111111 " << k1 <<" eta= " << jjj <<" phi= " << kkk   <<" Ceff1= " << Ceff1->GetBinContent(jjj,kkk)   <<endl;
	  //	  if(Ceff7->GetBinContent(jjj,kkk) !=0.)  cout  <<" k1=77777777777 " << k1 <<" eta= " << jjj <<" phi= " << kkk   <<" Ceff7= " << Ceff7->GetBinContent(jjj,kkk)   <<endl;
	  if(Ceff1->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth1->Fill(    double(jjj)-41., double(kkk), Ceff1->GetBinContent(jjj,kkk)      );
	  if(Ceff2->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth2->Fill(    double(jjj)-41., double(kkk), Ceff2->GetBinContent(jjj,kkk)      );
	  if(Ceff3->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth3->Fill(    double(jjj)-41., double(kkk), Ceff3->GetBinContent(jjj,kkk)      );
	  if(Ceff4->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth4->Fill(    double(jjj)-41., double(kkk), Ceff4->GetBinContent(jjj,kkk)      );
	  if(Ceff5->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth5->Fill(    double(jjj)-41., double(kkk), Ceff5->GetBinContent(jjj,kkk)      );
	  if(Ceff6->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth6->Fill(    double(jjj)-41., double(kkk), Ceff6->GetBinContent(jjj,kkk)      );
	  if(Ceff7->GetBinContent(jjj,kkk) >0. ) mapchannelsdepth7->Fill(    double(jjj)-41., double(kkk), Ceff7->GetBinContent(jjj,kkk)      );
	}// if HEP17 selection
      }// for
    }// for
    ///////////////////////////////////////////////////////////////////////////////////////////
    //	}

    //
    //
    // fill:
    // fill massive <Aijk>_runevents ,  where iii=depth, jjj=eta, kkk=phi
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	//
	// HEP17 selection:   
	if(flagHEP17selection == 0 || (flagHEP17selection == 1 && ( (( jjj > 56 && jjj < 62 ) && (kkk >63 && kkk < 68 )) || (( jjj > 61 && jjj < 71 ) && (kkk == 64 || kkk == 66 )))) ) {
	  // FILL NEW PLOTS:
	  // Aijk: Ceff1D & Seff1D plots 
	  if(Ceff1->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff1->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff1->GetBinContent(jjj,kkk));}
	  if(Ceff2->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff2->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff2->GetBinContent(jjj,kkk));}
	  if(Ceff3->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff3->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff3->GetBinContent(jjj,kkk));}
	  if(Ceff4->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff4->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff4->GetBinContent(jjj,kkk));}
	  if(Ceff5->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff5->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff5->GetBinContent(jjj,kkk));}
	  if(Ceff6->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff6->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff6->GetBinContent(jjj,kkk));}
	  if(Ceff7->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff7->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff7->GetBinContent(jjj,kkk));}
	}//if
      }
    }
    

    //--------------------------------------
    // take into account for future treatment only HEP17 channels and cuts on <Aijk>_runevents within cutMinA to cutMaxA:
    // apply cut on <Aijk>_runevents
  //             -41                                +41
  //                            82 bins
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	// HEP17 selection:   
	if(flagHEP17selection == 0 || (flagHEP17selection == 1 && ( (( jjj > 56 && jjj < 62 ) && (kkk >63 && kkk < 68 )) || (( jjj > 61 && jjj < 71 ) && (kkk == 64 || kkk == 66 )))) ) {
	  if(Ceff1->GetBinContent(jjj,kkk)> cutMinA && Ceff1->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[1][jjj][kkk] =  Ceff1->GetBinContent(jjj,kkk);
	  if(Ceff2->GetBinContent(jjj,kkk)> cutMinA && Ceff2->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[2][jjj][kkk] =  Ceff2->GetBinContent(jjj,kkk);
	  if(Ceff3->GetBinContent(jjj,kkk)> cutMinA && Ceff3->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[3][jjj][kkk] =  Ceff3->GetBinContent(jjj,kkk);
	  if(Ceff4->GetBinContent(jjj,kkk)> cutMinA && Ceff4->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[4][jjj][kkk] =  Ceff4->GetBinContent(jjj,kkk);
	  if(Ceff5->GetBinContent(jjj,kkk)> cutMinA && Ceff5->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[5][jjj][kkk] =  Ceff5->GetBinContent(jjj,kkk);
	  if(Ceff6->GetBinContent(jjj,kkk)> cutMinA && Ceff6->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[6][jjj][kkk] =  Ceff6->GetBinContent(jjj,kkk);
	  if(Ceff7->GetBinContent(jjj,kkk)> cutMinA && Ceff7->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[7][jjj][kkk] =  Ceff7->GetBinContent(jjj,kkk);
	}//if
      }// for
    }// for
    //////////////////---------------------------------------
      /*
    //         define A for refRun :  k1=[0]
    //////////////////---------------------------------------
    if(k1==firstrun && kmm==0 ) {
      kmm=1; //Int_t mcount=0;
      cout<<"* to be printed once only  CHECK IT please  ************ kmm = " << kmm <<endl;
      for(int iii = 1; iii<4; iii++) {
//	for (int jjj=1;jjj<=82;jjj++) {
//	  for (int kkk=1;kkk<=72;kkk++) {
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	    normalization[iii][jjj][kkk] = mapRATIO[iii][jjj][kkk];
	  }//for 
	}//for 
      }//for 
    }// if(k1=firstrun
*/
    //--------------------------------------
    //                                               then, averaging over depthes, but first sum over depthes before!!! any dividing.  Use mapRATIOD2[jjj][kkk] and mapRATIOD20[jjj][kkk]
    //////////////////---------------------------------------
    int totalhep17count = 0;int totalhep17count1 = 0;int totalhep17count2 = 0;int totalhep17count3 = 0;int totalhep17count4 = 0;int totalhep17count5 = 0;int totalhep17count6 = 0;int totalhep17count7 = 0;
    for(int iii = 1; iii<NDEP; iii++) {
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	//    for (int jjj=1;jjj<=82;jjj++) {
	//	for (int kkk=1;kkk<=72;kkk++) {
	  if(mapRATIO[iii][jjj][kkk] > 0 ) {
	    // calculate # channels in HEP17 for each depth:
	    totalhep17count++; 
	    if(verbosity == 4 && k1==0 ) {cout  <<" k1= " << k1 <<" depth= " << iii <<" eta= " << jjj <<" phi= " << kkk   <<" mapRATIO= " << mapRATIO[iii][jjj][kkk]   <<endl;}
	    if(iii==1)totalhep17count1++;if(iii==2)totalhep17count2++;if(iii==3)totalhep17count3++;if(iii==4)totalhep17count4++;if(iii==5)totalhep17count5++;if(iii==6)totalhep17count6++;if(iii==7)totalhep17count7++;
	      // ----------------------------------------   sum over depthes before!!! any dividing:
	      mapRATIOD2[jjj][kkk] += mapRATIO[iii][jjj][kkk];
	      // count entries with digis only:
	      mapRATIOD20[jjj][kkk]++;
	      if(verbosity == 3 && iii==3 )  cout<<"   depth = " << iii <<" k1 = " << k1 <<" eta = " << jjj <<" mapRATIOD2[jjj][kkk] = " << mapRATIOD2[jjj][kkk]     <<" #entries = " << mapRATIOD20[jjj][kkk] <<" mapRATIO[iii][jjj][kkk] = " <<     mapRATIO[iii][jjj][kkk] <<endl;
	  }// if mapRATIO[iii][jjj][kkk] != 0 
	}//for  
      }//for  
    }//for


    // ERROR printout !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
    //    if(totalhep17count != 184 ) {cout  <<"!!!!!! ERROR:NOT ALL CHANNELS HEP17 INVOLEVED FOR RUN WITH  k1= " << k1 <<" totalhep17count= " << totalhep17count <<endl;}



    if(verbosity == 4 && k1==0 ){cout  <<" k1= " << k1 <<" totalhep17count= " << totalhep17count <<endl;cout  <<" k1= " << k1 <<" totalhep17count1= " << totalhep17count1 <<endl;cout  <<" k1= " << k1 <<" totalhep17count2= " << totalhep17count2 <<endl;cout  <<" k1= " << k1 <<" totalhep17count3= " << totalhep17count3 <<endl;cout  <<" k1= " << k1 <<" totalhep17count4= " << totalhep17count4 <<endl;cout  <<" k1= " << k1 <<" totalhep17count5= " << totalhep17count5 <<endl;cout  <<" k1= " << k1 <<" totalhep17count6= " << totalhep17count6 <<endl;cout  <<" k1= " << k1 <<" totalhep17count7= " << totalhep17count7 <<endl;}


    //////////////------------------------------          and now averaging over depthes     and   get final mapRATIOD2[jjj][kkk]
    //////////////////---------------------------------------
    Int_t depthAVERAGEcount = 0;
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	//  for (int jjj=1;jjj<=82;jjj++) {
	//for(int kkk=1;kkk<=72;kkk++) {
	depthAVERAGEcount = 4 * (jjj-57) + (kkk-64);
	if(mapRATIOD20[jjj][kkk] != 0 ) {
	  NotEmptyDepthes->Fill(float(depthAVERAGEcount));
	  if(verbosity == 1)  cout<<"****aver per depthes********* phi = " << kkk <<" RunIndex = " << k1 <<" eta = " << jjj <<" #entries  = " << mapRATIOD20[jjj][kkk] <<endl;
	  mapRATIOD2[jjj][kkk] /= mapRATIOD20[jjj][kkk];
	  if(verbosity == 3 && kkk==3 ) cout<<"****aver per depthes********* phi = " << jjj <<" RunIndex = " << k1 <<" eta = " << jjj <<" Nphi = " << mapRATIOD20[jjj][kkk] <<endl;
	}// if(mapRATIOD20 != 0
      }//for kkk 
    }//for jjj
    //////////////////---------------------------------------
    //                                                 define A for refRun :  k1=[0]
    //////////////////---------------------------------------
    if(k1==firstrun && kmm==0 ) {
      kmm=1; //Int_t mcount=0;
      cout<<"* to be printed once only  CHECK IT please  ************ kmm = " << kmm <<endl;
      //      for (int jjj=1;jjj<=82;jjj++) {
      //	for (int kkk=1;kkk<=72;kkk++) {
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	  normalization[jjj][kkk] = mapRATIOD2[jjj][kkk];
	}//for 
      }//for 
    }// if(k1=firstrun
    //--------------------------------------
    //////////////------------------------------          get normalized ratio   GSMRATIOD2[k1][jjj][kkk]
    //////////////////---------------------------------------
    //   int etaphicount = 0;
    //    for (int jjj=1;jjj<=82;jjj++) {
    //      for (int kkk=1;kkk<=72;kkk++) {
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	if(normalization[jjj][kkk] != 0 ) {
	  GSMRATIOD2[k1][jjj][kkk] = mapRATIOD2[jjj][kkk]/normalization[jjj][kkk];
	  // plotting:
	  if(GSMRATIOD2[k1][jjj][kkk]< RrangeMAX && GSMRATIOD2[k1][jjj][kkk] > RrangeMIN ) {
	    gainkoeff->Fill(GSMRATIOD2[k1][jjj][kkk]);
	    gainkoeff0->Fill(GSMRATIOD2[k1][jjj][kkk]);
	    gainkoeff9->Fill(GSMRATIOD2[k1][jjj][kkk]);
	    // printout
	    //    etaphicount++;
	    //  if(etaphicount > 30 ) cout  <<"etaphicount =   " << etaphicount   << "for  k1= " << k1 <<endl;
	    //  	    if(etaphicount == 30 ) cout  <<"etaphicount == 30 for  k1= " << k1 <<endl;
	    //	    cout  <<" k1= " << k1 <<" eta= " << jjj <<" phi= " << kkk   <<endl;
	    GOODruns->Fill(float(k1));
	  }
	  else{if(GSMRATIOD2[k1][jjj][kkk]>0.) BADruns->Fill(float(k1));}
	  //	  else{if(GSMRATIOD2[k1][jjj][kkk]>0.) BADruns->Fill(float(k1));}
	  
	}// if(normalization[jjj][kkk] != 0 
      }//for kkk 
    }//for jjj
    
    //
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    //////////////////---------------------------------------
    /////////////////////////////////////////////////////////////////////////////////////////////// nulling :
    ///////////////////////////////////////////////////////////////// nulling :
    for (int jjj=0;jjj<=82;jjj++) {
      for (int kkk=0;kkk<=72;kkk++) {
	mapRATIOD2[jjj][kkk] =  0.;
	mapRATIOD20[jjj][kkk] =  0.;
	for(int iii = 0; iii<4; iii++) {
	  mapRATIO[iii][jjj][kkk] = 0.;
	}
      }// for
    }// for
    
    ///////////////////// hfile->Close();
    hfile->Close();
    ///////////////////// 

    
    //  }//if(k1==0 || (k1>37
    //  END OF LOOP OVER LED RUNS
      }//for k1 loop over time points(LED runs)
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                   DONE: last LED run READ " <<endl;

      //	c1->Clear();



      // ////////////////////////////////////////////////////////////////////////////////////////////////// END OF LOOP OVER LED RUNS
      ////////////////////////////////////////////////////////////////////////////////////////////////////  END OF LOOP OVER LED RUNS
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
      cout<<"****  ****  ****  ****  ****     Draw Dependencies: *** " <<endl;

      
      
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      Int_t Method = NMethodsStart ;
  while (Method<NMethodsToUse+1) {
    if( Method != 9999992 )
      {
	cout<<" ****  START   Method " << Method <<endl;
    //======================================================================================================= PLOT0:  <Aijk>  for each event and all LED runs 
	if(Method == 0 ) {
	  cout<<"****Draw 0 Dependencies: <Aijk>  for each event and all LED runs  *** " <<endl;
	  gPad->SetGridy();
	  gPad->SetGridx();
	  gPad->SetLogy();
	  gStyle->SetOptStat(101110); 
      Ceff1D->SetMarkerStyle(20);
      Ceff1D->SetMarkerSize(0.4);
      Ceff1D->GetYaxis()->SetLabelSize(0.04);
      Ceff1D->SetTitle("all runs & channels");
      Ceff1D->SetXTitle("<Aijk>");
      Ceff1D->SetYTitle("N");
      Ceff1D->SetMarkerColor(4);
      Ceff1D->SetLineColor(4);
      //    Ceff1D->Draw("Error");
          Ceff1D->Draw("PL");
    }//Method = 0
    //======================================================================================================= PLOT1: <Aijk>  for each event and all LED runs ZOOM
    if(Method == 1 ) {
      cout<<"****Draw 1 Dependencies: <Aijk>  for each event and all LED runs ZOOM  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //    Seff1D->SetTitle("any Error, HE Depth1 \n");
      Seff1D->SetMarkerStyle(20);
      Seff1D->SetMarkerSize(0.4);
      Seff1D->GetYaxis()->SetLabelSize(0.04);
      Seff1D->SetTitle("ZOOM all runs & channels");
      Seff1D->SetXTitle("<Aijk> ZOOM  ");
      Seff1D->SetYTitle("N");
      Seff1D->SetMarkerColor(4);
      Seff1D->SetLineColor(4);
      //    Seff1D->Draw("Error");
          Seff1D->Draw("PL");
    }//Method = 1
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT2  GSM ratio vs days
    if(Method == 2 ) {
      cout<<"****Draw 2 Dependencies: GSM ratio vs days  *** " <<endl;
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      //      c1->Range(0,0,25,18);
      //      c1->SetFillColor(0);
      //      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.99,0.99,0);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      Int_t colorlines = 0;      
      Int_t generalcount = 0;      
      //      for (int jjj=1;jjj<=82;jjj++) {
      //	for (int kkk=1;kkk<=72;kkk++) {
      for (int jjj=0;jjj<82;jjj++) {
	for (int kkk=0;kkk<72;kkk++) {
	  Int_t sscount = -1;
	  for(int k1 = 0; k1<NP; k1++) {
	    if(GSMRATIOD2[k1][jjj][kkk] != 0  ) {
	      //	      if(GSMRATIOD2[k1][jjj][kkk]< 1.033 && GSMRATIOD2[k1][jjj][kkk] > 0.91  ) {
	      //   if(GSMRATIOD2[k1][jjj][kkk]< 9. && GSMRATIOD2[k1][jjj][kkk] > 0.  ) {
	      if(GSMRATIOD2[k1][jjj][kkk]< RrangeMAX && GSMRATIOD2[k1][jjj][kkk] > RrangeMIN  ) {
		//     	      if(GSMRATIOD2[k1][jjj][kkk]< 1.05 && GSMRATIOD2[k1][jjj][kkk] > 0.91  ) {
		//   if(GSMRATIOD2[k1][jjj][kkk]< 1.15 && GSMRATIOD2[k1][jjj][kkk] > 0.85  ) {
		sscount++;
		YY[sscount] = GSMRATIOD2[k1][jjj][kkk];// 
		XXX[sscount] = XX[k1];
		indWAS[sscount] = k1;
		mapBADchannels->Fill(double(jjj)-42., double(kkk)-1., GSMRATIOD2[k1][jjj][kkk]);
		mapBADchannels0->Fill(double(jjj)-42., double(kkk)-1., 1.);
	      }// GSMRATIOD2[k1][jjj][kkk] < 1.05
	      else {
		//		mapBADchannels->Fill(double(jjj)-42., double(kkk)-1., GSMRATIOD2[k1][jjj][kkk]);
	      }
	    }// GSMRATIOD2[k1][jjj][kkk] != 0
	  }//for k1
	  Int_t MMcount = sscount+1;
	  if(MMcount>0) {
	    generalcount++;
	    if(generalcount == 1 && verbosity == 2 ) for(int k1 = 0; k1<MMcount; k1++) {cout<<"**** All GOOD runs: indWAS[k1](1,..) =  " << indWAS[k1]+1 <<" XXX[k1]+1 = " << XXX[k1]+1  <<   endl;}
	    gr1 = new TGraph(MMcount,XXX,YY); 
	    colorlines = generalcount/5.+2;
	    gr1->SetLineColor(colorlines);  gr1->SetMarkerColor(colorlines); 
	    gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetFillStyle(0); 
	    gr1->GetXaxis()->SetTitle("days"); gr1->GetYaxis()->SetTitle("R");
	    gr1->Draw("PL");
	  }// if
	  //	  else {cout<<"****ERROR for  PLOT2:  MMcount is lower 1,  MMcount =   *** " << MMcount  <<   endl;}
	}//for kkk 
      }//for jjj
      
      //      TLegend leg(.6,.67,.78,.88, " HEP Depth1");
      //   TLegend leg(xx1,yy1,xx2,yy2, "HEP17: R vs t");
      TLegend leg(xx1,yy1,xx2,yy2, "HE SiPM: R vs t(days)");
      //      leg.AddEntry(gr1);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      /*      
      // Draw labels on the y axis
      TText *t7 = new TText();
      t7->SetTextAlign(32);
      t7->SetTextSize(0.035);
      t7->SetTextFont(72);
      char *labels[NP+1] = {"31","1","7","7","8","9","12","13","19","22","22","24","24","24","24","24","24","Feb."};
      float X7[NP];
      for(int k1 = 0; k1<NP; k1++) {
	//	cout<<"**** XXX[k1] =  " << XXX[k1] <<"     YY[k1] =  " << YY[k1] <<   endl;
		t7->DrawText(0.2+XXX[k1],0.890,labels[k1]);
      }
            t7->DrawText(0.2+XXX[NP-1]+75.,0.890,labels[NP]);
*/

    }////Method = 2
    //
    
    //======================================================================================================= PLOT3: 2D SiPM channels
    if(Method == 3 ) {
      cout<<"****Draw 3 Dependencies: 2D SiPM channels  *** " <<endl;
	TH2F* Cdepth2hbff = (TH2F*)mapBADchannels->Clone("Cdepth2hbff");
	Cdepth2hbff->Divide(mapBADchannels,mapBADchannels0, 1, 1, "B");
	Cdepth2hbff->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gStyle->SetOptStat(0000000); 
      Cdepth2hbff->SetMarkerStyle(20);
      Cdepth2hbff->SetMarkerSize(0.4);
      Cdepth2hbff->GetYaxis()->SetLabelSize(0.04);
      Cdepth2hbff->SetTitle("within R & Weighted by R");
      Cdepth2hbff->SetXTitle("#eta \b");
      Cdepth2hbff->SetYTitle("#phi \b");
      Cdepth2hbff->SetMarkerColor(4);
      Cdepth2hbff->SetLineColor(4);
      Cdepth2hbff->Draw("COLZ");
    }//Method = 3
    //======================================================================================================= PLOT4:gains LED runs 
    if(Method == 4  ) {
      cout<<"****Draw 4 Dependencies: gains LED runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      //    gPad->SetLogy();
      //gStyle->SetOptStat(1110000); 
          gStyle->SetOptStat(1100);// only mean & rms
      //gStyle->SetOptStat(1111111);// only mean & rms
      gainkoeff->SetMarkerStyle(20);
      gainkoeff->SetMarkerSize(0.4);
      gainkoeff->GetYaxis()->SetLabelSize(0.04);
      gainkoeff->SetXTitle("gains");
      gainkoeff->SetYTitle("N");
      gainkoeff->SetMarkerColor(4);
      gainkoeff->SetLineColor(4);
      //    gainkoeff->Draw("Error");
          gainkoeff->Draw("PL");
    }//Method = 4
    //======================================================================================================= PLOT5:gains LED runs 
    if(Method == 5  ) {
      cout<<"****Draw 5 Dependencies: gains LED runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
          gPad->SetLogy();
      //gStyle->SetOptStat(1110000); 
          gStyle->SetOptStat(1100);// only mean & rms
      //gStyle->SetOptStat(1111111);// only mean & rms
      gainkoeff9->SetMarkerStyle(20);
      gainkoeff9->SetMarkerSize(0.4);
      gainkoeff9->GetYaxis()->SetLabelSize(0.04);
      gainkoeff9->SetXTitle("gains");
      gainkoeff9->SetYTitle("N");
      gainkoeff9->SetMarkerColor(4);
      gainkoeff9->SetLineColor(4);
      //    gainkoeff9->Draw("Error");
          gainkoeff9->Draw("PL");
    }//Method = 5
    //======================================================================================================= PLOT6:gains LED runs 
    if(Method == 6  ) {
      cout<<"****Draw 6 Dependencies: gains LED runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
          gPad->SetLogy();
      //gStyle->SetOptStat(1110000); 
          gStyle->SetOptStat(1100);// only mean & rms
      //gStyle->SetOptStat(1111111);// only mean & rms
      gainkoeff0->SetMarkerStyle(20);
      gainkoeff0->SetMarkerSize(0.4);
      gainkoeff0->GetYaxis()->SetLabelSize(0.04);
      gainkoeff0->SetXTitle("gains");
      gainkoeff0->SetYTitle("N");
      gainkoeff0->SetMarkerColor(4);
      gainkoeff0->SetLineColor(4);
      //    gainkoeff0->Draw("Error");
          gainkoeff0->Draw("PL");
    }//Method = 6
    //======================================================================================================= PLOT7: BADruns
    if(Method == 7 ) {
      cout<<"****Draw 7 Dependencies: BADruns  *** " <<endl;
      gPad->Update();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy(kFALSE);
      gStyle->SetOptStat(101110); 
      BADruns->SetMarkerStyle(20);
      BADruns->SetMarkerSize(0.4);
      BADruns->GetYaxis()->SetLabelSize(0.04);
      BADruns->SetTitle("#channels outside Rrange VS iRun");
      BADruns->SetXTitle("iRun");
      BADruns->SetYTitle("#channels");
      BADruns->SetMarkerColor(4);
      BADruns->SetLineColor(4);
      //    BADruns->Draw("Error");
      BADruns->Draw("PL");
      //  PRINTOUT ONLY:
//      if(verbosity == 4 ){
	int cx = BADruns->GetXaxis()->GetNbins();
	cout<<"************* cx = " << cx <<endl;
	for (int jjj=0;jjj<=cx;jjj++) {
	  //	  if( BADruns->GetBinContent(jjj) >100.) cout<<"BADruns:   k1= " <<      jjj      <<endl;
	  //	  if( BADruns->GetBinContent(jjj) >5.) cout<<"BADruns:   k1= " <<      jjj      <<endl;
	  if( BADruns->GetBinContent(jjj) >14.) cout<<"BADruns:   k1(0,...)= " <<      jjj      <<"  BADruns->GetBinContent(jjj)= " <<      BADruns->GetBinContent(jjj)      <<endl;
	}//jjj
//      }// if(verbosity == 2 )
    }//Method = 7
    
    //======================================================================================================= PLOT8: Goodruns
    if(Method == 8) {
      cout<<"****Draw 8 Dependencies: Goodruns  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      //      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      GOODruns->SetMarkerStyle(20);
      GOODruns->SetMarkerSize(0.4);
      GOODruns->GetYaxis()->SetLabelSize(0.04);
      GOODruns->SetTitle("#channels inside Rrange VS iRun");
      GOODruns->SetXTitle("iRun");
      GOODruns->SetYTitle("#channels");
      GOODruns->SetMarkerColor(4);
      GOODruns->SetLineColor(4);
      //    GOODruns->Draw("Error");
      GOODruns->Draw("PL");
      //  PRINTOUT ONLY:
//      if(verbosity == 4 ){
	int cx = GOODruns->GetXaxis()->GetNbins();
	cout<<"************* cx = " << cx <<endl;
	for (int jjj=0;jjj<=cx;jjj++) {
	  //	  if( GOODruns->GetBinContent(jjj) >100.) cout<<"GOODruns:   k1= " <<      jjj      <<endl;
	  //	  if( GOODruns->GetBinContent(jjj) >5.) cout<<"GOODruns:   k1= " <<      jjj      <<endl;
	  if( GOODruns->GetBinContent(jjj) >1400.) cout<<"GOODruns:   k1(0,...)= " <<      jjj      <<"  GOODruns->GetBinContent(jjj)= " <<      GOODruns->GetBinContent(jjj)      <<endl;
	}//jjj
//      }// if(verbosity == 2 )
    }//Method = 8
    

    //======================================================================================================= PLOT9:depthes with zero A
    if(Method == 9  ) {
      cout<<"****Draw 9 Dependencies: depthes with zero A   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy(kFALSE);
      gStyle->SetOptStat(1110000); 
      NotEmptyDepthes->SetMarkerStyle(20);
      NotEmptyDepthes->SetMarkerSize(0.4);
      NotEmptyDepthes->GetYaxis()->SetLabelSize(0.04);
      NotEmptyDepthes->SetTitle("# Not Empty Channels in etq-phi projection");
      NotEmptyDepthes->SetXTitle("4*(eta-57)+(phi-64)");
      NotEmptyDepthes->SetYTitle("N");
      NotEmptyDepthes->SetMarkerColor(4);
      NotEmptyDepthes->SetLineColor(4);
      //    NotEmptyDepthes->Draw("Error");
          NotEmptyDepthes->Draw("PL");
    }//Method = 9
    //======================================================================================================= PLOT10:  Aijk  for each event and all LED runs 
    if(Method == 10) {
      cout<<"****Draw 10 Dependencies: Aijk  for each event and all LED runs  *** " <<endl;


      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      //    	  TString epsName = fname + LEDruns[0] +".root";
      //    	  TFile *hfile= new TFile(epsName, "READ");
      //    	  TH1F * Aeff1D= (TH1F*)hfile->Get("h_ADCAmpl_HE");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      Aeff1D->SetStats(0);
      Aeff1D->SetMarkerStyle(20);
      Aeff1D->SetMarkerSize(0.4);
      Aeff1D->GetYaxis()->SetLabelSize(0.04);
      Aeff1D->SetTitle("all runs & events& channels");
      Aeff1D->SetXTitle("Aijk");
      Aeff1D->SetYTitle("N");
      Aeff1D->SetMarkerColor(4);
      Aeff1D->SetLineColor(4);
      //    Aeff1D->Draw("Error");
      //    Aeff1D->Draw("PL");
       Aeff1D->SetMinimum(0.8);
       Aeff1D->Draw("");



      c1->Update();


    }//Method = 10
    //======================================================================================================= PLOT11: 2D SiPM channels Depthes1,2,3,4
    if(Method == 11) {
      cout<<"****Draw 11 <A>: 2D Depthes1,2,3,4  *** " <<endl;
//      gPad->SetGridy();
//      gPad->SetGridx();
      //      gStyle->SetOptStat(0000000); 
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      mapchannelsdepth1->SetStats(0);
      mapchannelsdepth1->SetTitle("<A> Depth1");
      mapchannelsdepth1->SetXTitle("#eta \b");
      mapchannelsdepth1->SetYTitle("#phi \b");
      mapchannelsdepth1->Draw("COLZ");
      c1->cd(2);
      mapchannelsdepth2->SetStats(0);
      mapchannelsdepth2->SetTitle("<A> Depth2");
      mapchannelsdepth2->SetXTitle("#eta \b");
      mapchannelsdepth2->SetYTitle("#phi \b");
      mapchannelsdepth2->Draw("COLZ");
      c1->cd(3);
      mapchannelsdepth3->SetStats(0);
      mapchannelsdepth3->SetTitle("<A> Depth3");
      mapchannelsdepth3->SetXTitle("#eta \b");
      mapchannelsdepth3->SetYTitle("#phi \b");
      mapchannelsdepth3->Draw("COLZ");
      c1->cd(4);
      mapchannelsdepth4->SetStats(0);
      mapchannelsdepth4->SetTitle("<A> Depth4");
      mapchannelsdepth4->SetXTitle("#eta \b");
      mapchannelsdepth4->SetYTitle("#phi \b");
      mapchannelsdepth4->Draw("COLZ");

      c1->Update();


    }//Method = 11
    //======================================================================================================= PLOT12: 2D SiPM channels Depthes5,6,7
    if(Method == 12 ) {
      cout<<"****Draw 12 <A>: 2D Depthes5,6,7  *** " <<endl;
//      gPad->SetGridy();
//      gPad->SetGridx();
      //      gStyle->SetOptStat(0000000); 
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      mapchannelsdepth5->SetStats(0);
      mapchannelsdepth5->SetTitle("<A> Depth5");
      mapchannelsdepth5->SetXTitle("#eta \b");
      mapchannelsdepth5->SetYTitle("#phi \b");
      mapchannelsdepth5->Draw("COLZ");
      c1->cd(2);
      mapchannelsdepth6->SetStats(0);
      mapchannelsdepth6->SetTitle("<A> Depth6");
      mapchannelsdepth6->SetXTitle("#eta \b");
      mapchannelsdepth6->SetYTitle("#phi \b");
      mapchannelsdepth6->Draw("COLZ");
      c1->cd(3);
      mapchannelsdepth7->SetStats(0);
      mapchannelsdepth7->SetTitle("<A> Depth7");
      mapchannelsdepth7->SetXTitle("#eta \b");
      mapchannelsdepth7->SetYTitle("#phi \b");
      mapchannelsdepth7->Draw("COLZ");

      c1->Update();


    }//Method = 12

    //======================================================================================================= PLOT13: 2D SiPM channels Depthes5,6,7
    if(Method == 13 ) {
      cout<<"****Draw 13 function, fC *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      {
	double c0 = 1.000000;double b1 = 2.71238e-05;double a2 = 1.32877e-10;
	Int_t n = 50;
	Double_t x[n], y[n];
	for (Int_t i=0;i<n;i++) {
	  x[i] = (i+1)*20000.;
	  y[i] = a2*x[i]*x[i]/40./40. + b1*x[i]/40. + c0;
	}
	
	// create graph
	TGraph *gr  = new TGraph(n,x,y);
	
	// draw the graph with axis, continuous line, and put
	// a * at each point
      gPad->SetGridy();
      gPad->SetGridx();
      //    gPad->SetLogy();
	gr->Draw("AC*");
	/*
	  gr1 = new TGraph(MMcount,XXX,YY); 
	  colorlines = generalcount/5.+2;
	  gr1->SetLineColor(colorlines);  gr1->SetMarkerColor(colorlines); 
	  gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetFillStyle(0); gr1->Draw("PL");
	*/
	
      }
      
       c1->Update();
     
    }//Method = 13


    //======================================================================================================= PLOT14: gsm for low-intensity run
    if(Method == 14 ) {
      cout<<"****Draw 14 low-intencity  run ***** " <<endl;
      c1->Clear();
      c1->Divide(1,3);
             
      //    TString epsName = fname + LEDruns[0] +".root";
      TString epsName = "rootshunt1/LEDtest" + LEDruns[0] + ".root";
      TFile *hfile= new TFile(epsName, "READ");
      c1->cd(1);
      TH1F *plot3= (TH1F*)hfile->Get("h_ADCAmpl345Zoom_HE");
      gPad->SetLogy();
      plot3->SetStats(0);
      plot3->SetMarkerStyle(20);
      plot3->SetMarkerSize(0.8);
      plot3->GetXaxis()->SetLabelSize(0.05);
      plot3->GetXaxis()->SetTitleSize(0.08);
      plot3->SetXTitle("Aijk 4TSs HE \b");
      plot3->SetMarkerColor(2);
      plot3->SetLineColor(2);
      plot3->Draw("");
      //////////////////////////////////////
      TH2F *hdjem1= (TH2F*)hfile->Get("h_mapADCAmpl12firstpeak_HE");
      TH2F *hdjem0= (TH2F*)hfile->Get("h_mapADCAmpl12firstpeak0_HE");
      TH2F* M1zeff = (TH2F*)hdjem1->Clone("M1zeff");
      M1zeff->Divide(hdjem1,hdjem0, 1, 1, "B");
      M1zeff->Sumw2();
      //////////////////////////////////////
      TH2F *twod7he1= (TH2F*)hfile->Get("h_mapADCAmpl12secondpeak_HE");
      TH2F *twod7he0= (TH2F*)hfile->Get("h_mapADCAmpl12secondpeak0_HE");
      TH2F* C9zeff = (TH2F*)twod7he1->Clone("C9zeff");
      C9zeff->Divide(twod7he1,twod7he0, 1, 1, "B");
      C9zeff->Sumw2();
      ///////////////////////////////////
      c1->cd(2);
      TH1F* aiffsecondtofirst7 = new TH1F("aiffsecondtofirst7","", 220, 0.,220.);
      TH1F* biffsecondtofirst7 = new TH1F("biffsecondtofirst7","", 220, 0.,220.);
      TH1F* diffsecondtofirst7 = new TH1F("diffsecondtofirst7","", 100, 35.,55.);
      TH2F* C7hefw = (TH2F*)C9zeff->Clone("diffsecondtofirst7");
      for (int i=1;i<=C7hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=C7hefw->GetYaxis()->GetNbins();j++) {
	  double differ = C9zeff->GetBinContent(i,j) - M1zeff->GetBinContent(i,j) ;
	  double aiffer = C9zeff->GetBinContent(i,j);
	  double biffer = M1zeff->GetBinContent(i,j);
	  if(differ != 0.) diffsecondtofirst7->Fill(differ);
	  if(aiffer != 0.) aiffsecondtofirst7->Fill(aiffer);
	  if(biffer != 0.) biffsecondtofirst7->Fill(biffer);
	}
      }
      gPad->SetLogy(kFALSE);
      diffsecondtofirst7->SetMarkerStyle(20);
      diffsecondtofirst7->SetMarkerSize(0.4);
      diffsecondtofirst7->GetYaxis()->SetLabelSize(0.05);
      diffsecondtofirst7->SetXTitle("difference between 2 peaks for each depth-averaged channel \b");
      diffsecondtofirst7->SetMarkerColor(2);
      diffsecondtofirst7->SetLineColor(2);
      //    diffsecondtofirst7->Draw("");
      //    TF1* g7 = new TF1("m1","gaus",30,50);
      //    diffsecondtofirst7->Fit(g7,"R");

      //    c1->cd(3);
      gStyle->SetOptStat(1100);
      aiffsecondtofirst7->GetXaxis()->SetLabelSize(0.05);
      aiffsecondtofirst7->GetXaxis()->SetTitleSize(0.08);
      aiffsecondtofirst7->SetXTitle("Mean in range 87-127 fC for each depth-averaged channel \b");
      aiffsecondtofirst7->Draw("");





      c1->cd(3);
      gStyle->SetOptStat(1100);
      biffsecondtofirst7->GetXaxis()->SetLabelSize(0.05);
      biffsecondtofirst7->GetXaxis()->SetTitleSize(0.08);
      biffsecondtofirst7->SetXTitle("Mean in range 127-167 fC for each depth-averaged channel \b");
      biffsecondtofirst7->Draw("");
             
      c1->Update();
      
     
    }//Method = 14
    //======================================================================================================= PLOT15: gsm for low-intensity run
    if(Method == 15 ) {
      cout<<"****Draw 15 low-intencity  run ***** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      ///////////////////////////////////
      TString epsName = "rootshunt1/LEDtest" + LEDruns[0] + ".root";
      TFile *hfile= new TFile(epsName, "READ");
      //////////////////////////////////////
      TH2F *zdem1= (TH2F*)hfile->Get("h_mapADCAmpl12firstpeak_HE");
      TH2F *zdem0= (TH2F*)hfile->Get("h_mapADCAmpl12firstpeak0_HE");
      TH2F* M1zzff = (TH2F*)zdem1->Clone("M1zzff");
      M1zzff->Divide(zdem1,zdem0, 1, 1, "B");
      M1zzff->Sumw2();
      //////////////////////////////////////
      TH2F *twod7he1= (TH2F*)hfile->Get("h_mapADCAmpl12secondpeak_HE");
      TH2F *twod7he0= (TH2F*)hfile->Get("h_mapADCAmpl12secondpeak0_HE");
      TH2F* C9zzff = (TH2F*)twod7he1->Clone("C9zzff");
      C9zzff->Divide(twod7he1,twod7he0, 1, 1, "B");
      C9zzff->Sumw2();
      ///////////////////////////////////
      c1->cd(1);
      TH1F* diffsecondtofirst7 = new TH1F("diffsecondtofirst7","", 100, 35.,55.);
      TH2F* C7hefw = (TH2F*)C9zzff->Clone("diffsecondtofirst7");
      for (int i=1;i<=C7hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=C7hefw->GetYaxis()->GetNbins();j++) {
	  double differ = C9zzff->GetBinContent(i,j) - M1zzff->GetBinContent(i,j) ;
	  if(differ != 0.) diffsecondtofirst7->Fill(differ);
	}
      }
      gPad->SetLogy(kFALSE);
      gStyle->SetOptFit(0010);// constant, mean and sigma only !!
      diffsecondtofirst7->SetMarkerStyle(20);
      diffsecondtofirst7->SetMarkerSize(0.4);
      diffsecondtofirst7->GetYaxis()->SetLabelSize(0.04);
      //    diffsecondtofirst7->SetXTitle("dirrerence of second and first peaks for each channel (depth-averaged) \b");
      diffsecondtofirst7->SetXTitle("difference between 2 peaks for each depth-averaged channel \b");
      diffsecondtofirst7->SetMarkerColor(2);
      diffsecondtofirst7->SetLineColor(2);
      diffsecondtofirst7->Draw("");
      TF1* g7 = new TF1("m1","gaus",30,50);
      diffsecondtofirst7->Fit(g7,"R");
             
      c1->Update();
      
     
    }//Method = 15





    //  //////////////////////////////////////////////////////////////////////////



  //======================================================================================================= 
  //======================================================================================================= finish loop over Methods
  //======================================================================================================= 
    TString fdir = "testamt9gsm2018/";
    //
    TString plotName = fdir + MethodName[Method] +".png";
    c1->SaveAs(plotName);
    cout<<"****PLOT "   << Method  <<" drawn **** " <<endl;
    
    }//if( Method != 9 
    ++Method;
  }//while loop over Methods
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
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
