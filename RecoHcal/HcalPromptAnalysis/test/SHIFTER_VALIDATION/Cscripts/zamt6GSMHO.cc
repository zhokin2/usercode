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
//  
int main(int argc, char *argv[])
{
  //______________________________________________________________________________________________________________________________    
  //TCanvas *c1;
  TGraph *gr1;  TGraph *gr2;TGraph *gr3;  TGraph *gr4;TGraph *gr5;  TGraph *gr6;TGraph *gr7;TGraph *gr8;TGraph *gr9;
  TGraphErrors* ge1;TGraphErrors* ge2;TGraphErrors* ge3;TGraphErrors* ge4;TGraphErrors* ge5;TGraphErrors* ge6;TGraphErrors* ge7;TGraphErrors* ge8;TGraphErrors* ge9;

  //
  const Int_t NMethods =6;// total number of Methods (all-together 37 methods)
  const Int_t NMethodsStart =0;     // since which method to start ( min=  0)
  const Int_t NMethodsToUse =5;// choose Number of methods to use ( max= 36)
  //
 TString MethodName[NMethods] = { "PLOTHO0", "PLOTHO1", "PLOTHO2", "PLOTHO3", "PLOTHO4", "PLOTHO5" };
  //______________________________________________________________________________________________________________________________    
  //______________________________________________________________________________________________________________________________    
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////  LED runs:
 // always use maximal!!! value of massives dimention below:
 /*
//      2017: since 28.05 till 07.11 : since 295401 till 306249     126 runs  DONE
 const Int_t NMAXM =126;// 
 TString LEDrunsM[NMAXM] = {
   "295401","295675","296182","296185","296188","296221","296224","296228","296240","296246",
   "296310","296627","296808","296906","296909","296911","297026","297027","297028","297082",
   "297087","297522","297571","297630","297645","297687","297731","297732","297846","297915",
   "297924","297931","297964","297995","298014","298017","298055","298097","298122","298125",
   "298277","298284","298304","298305","298309","298317","298343","298350","298412","298413",
   "298428","298469","298475","298722","298806","298863","299229","299357","299457","299465",
   "299468","299975","300185","302115","302183","302217","302246","302253","302417","302418",
   "302419","302582","302585","302616","302803","302808","302812","302836","302958","302998",
   "303073","303076","303223","303374","303456","303860","303867","303869","303903","303912",
   "303913","304079","304229","304239","304260","304263","304264","304265","304266","304267",
   "304276","304324","304427","304432","304519","304526","304635","304636","304685","304753",
   "304852","305054","305131","305133","305142","305220","305478","305485","305704","305705",
   "305711","305882","305886","306068","306232","306249" 
 };//
 
 Float_t X0M[NMAXM] = {
   1.,    4.,    10.,  10.,    10.,  10.,    10.,  10.,    10.,  10.,
   11.,   16.,    18.,  19.,    19.,  19.,    20.,  20.,    20.,  21.,    
   21.,   30.,    31.,  32.,    32.,  33.,    34.,  34.,    37.,  37.,
   37.,   37.,    38.,  38.,    38.,  38.,    39.,  39.,    39.,  39., 
   40.,   40.,    40.,  40.,    40.,  40.,    40.,  40.,    41.,  41.,   
   41.,   41.,    41.,  44.,    45.,  46.,    51.,  52.,    54.,  54.,   
   54.,   61.,    65.,  96.,    97.,  97.,    98.,  98.,   102., 102.,   
  102.,  106.,   106., 107.,   111., 111.,   111., 111.,   112., 114.,  
  114.,  114.,   115., 116.,   116., 121.,   121., 121.,   122., 122.,   
  122.,  124.,   128., 128.,   128., 128.,   128., 128.,   128., 128., 
  128.,  129.,   130., 130.,   132., 132.,   133., 133.,   135., 136.,   
  138.,  140.,   142., 142.,   142., 144.,   149., 149.,   152., 152.,   
  152.,  156.,   156., 159.,   164., 164.
 };// days of year    time points (abscissa) !!!
*/

 /* 
 const Int_t NMAXM =99;// 
 TString LEDrunsM[NMAXM] = {
   "295401","295675","296182","296185","296188","296221","296224","296228","296240","296246",
   "296310","296627","296808","296906","296909","296911","297026","297027","297028","297082",
   "297087","297522","297571","297630","297645","297687","298055","298277","298305","298317",
   "298350","298412","298428","298469","298475","298722","298806","298863","299229","299357",
   "299457","299465","299468","299975","300185","302115","302183","302217","302246","302253",
   "302417","302418","302419","302582","302585","302616","303374","303860","303867","303869",
   "303903","303912","303913","304079","304079","304229","304239","304260","304263","304264",
   "304265","304266","304267","304276","304324","304427","304432","304519","304526","304635",
   "304636","304685","304753","304852","305054","305131","305133","305142","305220","305478",
   "305485","305704","305705","305711","305882","305886","306068","306232","306249" 
 };//
 
 Float_t X0M[NMAXM] = {
     1.,        4.,      10.,    10.,      10.,  10.,        10.,    10.,      10.,  10.,
     11.,       16.,     18.,    19.,      19.,  19.,        20.,    20.,      20.,  21.,        
     21.,       30.,     31.,    32.,      32.,  33.,        39.,    40.,      40.,  40.,    
     40.,       41.,     41.,    41.,      41.,  44.,        45.,    46.,      51.,  52.,      
     54.,       54.,     54.,    61.,      65.,  96.,        97.,    97.,      98.,  98.,
    102.,      102.,    102.,   106.,     106., 107.,       111.,   116.,     121., 121.,    
    121.,      122.,    122.,   122.,     124., 128.,       128.,   128.,     128., 128., 
    128.,      128.,    128.,   128.,     129., 130.,       130.,   132.,     132., 133., 
    133.,      135.,    136.,   138.,     140., 142.,       142.,   142.,     144., 149., 
    149.,      152.,    152.,   152.,     156., 156.,       159.,   164.,     164.
 };// days of year    time points (abscissa) !!!
*/
 // selection for HPD 2017 channels
 const Int_t NMAXM =22;// 
 TString LEDrunsM[NMAXM] = {
   "295401","295675",         "296185",
                     "296808",                                                      "297082",
            "297522","297571","297630",         "297687",                                    
                                                                  "298863",
                     "299468",                           "302183",         "302246",
                                       "302585",
                                                        
                             "304276",                  "304432",         "304526",         
                                                                  "305142",
   "305485",                  "305711",         "305886",                  "306249" 
 };//
 Float_t X0M[NMAXM] = {
     1.,        4.,              10.,                                                    
                         18.,                                                        21.,        
                30.,     31.,    32.,            33.,                                        
                                                                     46.,                      
                         54.,                                97.,              98.,       
                                          106.,                                              
                                                                                    
                                128.,                       130.,             132.,       
                                                                    142.,                 
    149.,                       152.,           156.,                         164. 
 };// days of year    time points (abscissa) !!!
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //______________________________________________________________________________
 //______________________________________________________________________________
 //______________________________________________________________________________
 //______________________________________________________________________________
 //                                           2017 only:                   yearcase=0 for test

 //                                           2016 only:                   yearcase=1
 //                                           2017 only:                   yearcase=2
 //                                           20167    :                   yearcase=3
 //                                           2018 only:                   yearcase=4
 //                                           201678   :                   yearcase=5
 
 //define yearcase:
 //         ____________________________________________________________________________                    THIS line below is MAIN to make a yearcase selection !!!!!!!!!!!!!!!!!!!!!!!!!!
 const Int_t yearcase = 0; 
 //______________________________________________________________________________

  //______________________________________________________________________________
  //______________________________________________________________________________
  //
  //---=[ SetCanvasDef           ]=----------------
  // Create a new canvas.
  TCanvas  *c1 = new TCanvas("c1","GSM",10,10,900,700);
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
  t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LED run for some random HO channels");
  
  //-----------------------------------------------------------------------------------------------------
  //
  //              x1   y1     x2     y2
  //    pad1->DrawFrame(1,   0.8,  370,   1.2);// all 

  //


  Float_t RrangeMIN = 0.90;Float_t RrangeMAX = 1.1;
  // x(abscissa) for Days
  //(yearcase == 1
  Float_t x1=0.00; Float_t x2=170.00;
  if(yearcase == 2  ) x2=170.00;
  if(yearcase == 3  ) x2=550.00;
  if(yearcase == 4  ) x2=200.00;
  if(yearcase == 5  ) x2=700.00;




  // y(ordinate) for All Days
  //(yearcase == 1
  Float_t y1=0.90; Float_t y2=  1.1; //  for 1,2,5,6   for 11,12,15,16
  if(yearcase == 2 ) {
    y1=0.60;
    y2=  1.4;
  }
  if(yearcase == 3  ) {
    y1=0.60;
    y2=  1.4;
  }
  if(yearcase == 4  ) {
    y1=0.60;
    y2=  1.4;
  }
  if(yearcase >4  ) {
    y1=0.60;
    y2=  1.4;
  }
  
  

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
    //     Int_t NP = 3; // for loop over time points(LED runs) NMAX is number of LED runs(time abscissa)
    Int_t NP = NMAX;  // for loop over time points(LED runs) NMAX is number of LED runs(time abscissa)
    cout << " NP = " << NP <<endl;
    //
    //---------------------------------------------------------------------------------------------------------------------  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
    Double_t cutMinA =150.; Double_t cutMaxA = 900.;  
  //
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //---------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------
    for(int kk1 = 0; kk1<NP; kk1++){ 
      XX[kk1] = X0[kk1];   
      int k10 = 0; 
      int z1=X0[k10];  
      XX[kk1] -= z1;  
      cout << "ORDINATE points:    kk1 =  " <<kk1   <<"  XX[kk1]= " << XX[kk1] <<endl;
  
      XXE[kk1] = 0.001*XX[kk1];
    }//XXE - errors at fit
    //-----------------------------------------------------------------------------------------------------


  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Int_t verbosity = 3;//  
  Int_t verbosity = 0;//  
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
      
      for(int iii = 4; iii<5; iii++) {
	mapRATIO[iii][jjj][kkk] = 0.;
	//	normalization[iii][jjj][kkk] = 0.;
      }

    }// for
  }// for
  

  /////////////////////////////////////////////////////////////////////////

  //______________________________________________________________________________
  //     ls -latr /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_* | less  
  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";

  // booking:
  TH1F* Ceff1D = new TH1F("Ceff1D","", 200, 0.,10000.);
  TH1F* Seff1D = new TH1F("Seff1D","", 200, 0.,2000.);
  TH2F* mapBADchannels = new TH2F("mapBADchannels"," ", 82, -41., 41., 72, 0., 72.);
  TH1F* gainkoeff = new TH1F("gainkoeff","", 100, 0.8,1.2);
  TH1F* BADruns = new TH1F("BADruns","", NP, 0.,float(NP));

  //////////////////////////////////////////////////////////////////////  initial variables
  Int_t kmm = 0;
    //    first runs:
    Int_t firstrun=0; 
  //

  //////////////////////////////////////////////////////////////////////////////////////////////  LOOP    ratio current
  //////////////////////////////////////////////////////////////////////////  LOOP    ratio current
  //////////////////////////////////////////////////////////////////////////  LOOP    ratio current
      for(int k1 = 0; k1<NP; k1++) {
	//  if(k1==0 || (k1 >37 && k1<42)) {

      //______________________________________________________
	  TString epsName = fname + LEDruns[k1] +".root";
	  TFile *hfile= new TFile(epsName, "READ");

    cout << "!!!! read LED run with k1= " << k1   <<"  run:  " << LEDruns[k1] <<endl;
     // Define nominator denominator for some methods:
    //---------------------------------------------------
    // 000000000000000000000000000000000000000000000000000000000000000000000000
      TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth4ADCAmpl_HO");
    // 111111111111111111111111111111111111111111111111111111111111111111111111
     // h_mapDepth4ADCAmpl12 means ADCcounts(massive) within -1 max +1 +2
    
      //TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth4ADCAmpl12_HO");

    
  //    TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth4ADCAmpl12SiPM_HO");

      TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth4_HO");

      TH2F* Ceff1= (TH2F*)twod1->Clone("Ceff1");


    // <Aijk>_runevents:
    Ceff1->Divide(twod1,t0010, 1, 1, "B");  

    //    twod1->Sumw2();
    //    twod2->Sumw2();
    //    t0010->Sumw2();

    // <Aijk>_runevents:
    Ceff1->Divide(twod1,t0010, 1, 1, "B");  
    //      Ceff1->Sumw2();Ceff2->Sumw2();
    //	}

    int nx = Ceff1->GetXaxis()->GetNbins();
    int ny = Ceff1->GetYaxis()->GetNbins();

    //  PRINTOUT ONLY:
    if(verbosity == 2 ){
      cout<<"************* nx = " << nx <<" ny = " << ny <<endl;
      for (int jjj=0;jjj<=nx;jjj++) {
	for (int kkk=0;kkk<=ny;kkk++) {
	  if( Ceff1->GetBinContent(jjj,kkk) != 0.) cout<<"*111111************ jjj = " << jjj<<   "************* kkk = " << kkk <<endl;
	}//jjj
      }//kkk
    }// if(verbosity == 2 )
    // fill:
    // fill massive <Aijk>_runevents ,  where iii=depth, jjj=eta, kkk=phi
    for (int jjj=0;jjj<nx;jjj++) {
      for (int kkk=0;kkk<ny;kkk++) {
	// FILL NEW PLOTS:
	// Aijk: Ceff1D & Seff1D plots 
	if(Ceff1->GetBinContent(jjj,kkk)!= 0.) {Ceff1D->Fill(Ceff1->GetBinContent(jjj,kkk));Seff1D->Fill(Ceff1->GetBinContent(jjj,kkk));}
      }
    }
    //--------------------------------------
    // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
    // apply cut on <Aijk>_runevents
  //             -41                                +41
  //                            82 bins
      for (int jjj=0;jjj<nx;jjj++) {
	for (int kkk=0;kkk<ny;kkk++) {
	  if(Ceff1->GetBinContent(jjj,kkk)> cutMinA && Ceff1->GetBinContent(jjj,kkk)< cutMaxA) mapRATIO[4][jjj][kkk+1] =  Ceff1->GetBinContent(jjj,kkk);
	}
      }
    //////////////////---------------------------------------
      /*
    //         define A for refRun :  k1=[0]
    //////////////////---------------------------------------
    if(k1==firstrun && kmm==0 ) {
      kmm=1; //Int_t mcount=0;
      cout<<"* to be printed once only  CHECK IT please  ************ kmm = " << kmm <<endl;
      for(int iii = 1; iii<4; iii++) {
	for (int jjj=1;jjj<=82;jjj++) {
	  for (int kkk=1;kkk<=72;kkk++) {
	    normalization[iii][jjj][kkk] = mapRATIO[iii][jjj][kkk];
	  }//for 
	}//for 
      }//for 
    }// if(k1=firstrun
*/
    //--------------------------------------
    //                                               then, averaging over depthes, but first sum over depthes before!!! any dividing.  Use mapRATIOD2[jjj][kkk] and mapRATIOD20[jjj][kkk]
    //////////////////---------------------------------------
    for(int iii = 4; iii<5; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  if(mapRATIO[iii][jjj][kkk] > 0 ) {
	      // ----------------------------------------   sum over depthes before!!! any dividing:
	      mapRATIOD2[jjj][kkk] += mapRATIO[iii][jjj][kkk];
	      // count entries with digis only:
	      mapRATIOD20[jjj][kkk]++;
	      if(verbosity == 3 && iii==3 )  cout<<"   depth = " << iii <<" k1 = " << k1 <<" eta = " << jjj <<" mapRATIOD2[jjj][kkk] = " << mapRATIOD2[jjj][kkk]     <<" #entries = " << mapRATIOD20[jjj][kkk] <<" mapRATIO[iii][jjj][kkk] = " <<     mapRATIO[iii][jjj][kkk] <<endl;
	  }// if mapRATIO[iii][jjj][kkk] != 0 
	}//for  
      }//for  
    }//for  
    //////////////------------------------------          and now averaging over depthes     and   get final mapRATIOD2[jjj][kkk]
    //////////////////---------------------------------------
    for (int jjj=1;jjj<=82;jjj++) {
      for (int kkk=1;kkk<=72;kkk++) {
	if(mapRATIOD20[jjj][kkk] != 0 ) {
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
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  normalization[jjj][kkk] = mapRATIOD2[jjj][kkk];
	}//for 
      }//for 
    }// if(k1=firstrun
    //--------------------------------------
    //////////////------------------------------          get normalized ratio   GSMRATIOD2[k1][jjj][kkk]
    //////////////////---------------------------------------
    for (int jjj=1;jjj<=82;jjj++) {
      for (int kkk=1;kkk<=72;kkk++) {
	if(normalization[jjj][kkk] != 0 ) {
	  GSMRATIOD2[k1][jjj][kkk] = mapRATIOD2[jjj][kkk]/normalization[jjj][kkk];
	  // plotting:
	  if(GSMRATIOD2[k1][jjj][kkk]< RrangeMAX && GSMRATIOD2[k1][jjj][kkk] > RrangeMIN ) {gainkoeff->Fill(GSMRATIOD2[k1][jjj][kkk]);}
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
	for(int iii = 4; iii<5; iii++) {
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
    if( Method != 9  )
      {
    cout<<" ****  START   Method " << Method <<endl;
    //======================================================================================================= PLOTHO0:  <Aijk>  for each event and all LED runs 
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
    //======================================================================================================= PLOTHO1: <Aijk>  for each event and all LED runs ZOOM
    if(Method == 1 ) {
      cout<<"****Draw 1 Dependencies: <Aijk>  for each event and all LED runs ZOOM  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //    Seff1D->SetTitle("any Error, HO Depth4 \n");
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
    //======================================================================================================= PLOTHO2  GSM ratio vs days
    if(Method == 2 ) {
      cout<<"****Draw 2 Dependencies: GSM ratio vs days  *** " <<endl;
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      c1->Range(0,0,25,18);
      c1->SetFillColor(0);
      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.98,0);
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
      Int_t generalcount = 0;      
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  Int_t sscount = -1;
	  for(int k1 = 0; k1<NP; k1++) {
	    if(GSMRATIOD2[k1][jjj][kkk] != 0  ) {
	      if(GSMRATIOD2[k1][jjj][kkk]< RrangeMAX && GSMRATIOD2[k1][jjj][kkk] > RrangeMIN  ) {
		//     	      if(GSMRATIOD2[k1][jjj][kkk]< 1.05 && GSMRATIOD2[k1][jjj][kkk] > 0.91  ) {
		//   if(GSMRATIOD2[k1][jjj][kkk]< 1.15 && GSMRATIOD2[k1][jjj][kkk] > 0.85  ) {
		sscount++;
		YY[sscount] = GSMRATIOD2[k1][jjj][kkk];// 
		XXX[sscount] = XX[k1];
		indWAS[sscount] = k1;
		mapBADchannels->Fill(double(jjj)-42., double(kkk)-1., GSMRATIOD2[k1][jjj][kkk]);
	      }// GSMRATIOD2[k1][jjj][kkk] < 1.05
	      else {
		//		mapBADchannels->Fill(double(jjj)-42., double(kkk)-1., GSMRATIOD2[k1][jjj][kkk]);
	      }
	    }// GSMRATIOD2[k1][jjj][kkk] != 0
	  }//for k1
	  Int_t MMcount = sscount+1;
	  if(MMcount>0) {
	    generalcount++;
	    if(generalcount == 1)    for(int k1 = 0; k1<MMcount; k1++) {cout<<"**** All GOOD runs:  indWAS[k1](1,..) =    " << indWAS[k1]+1 <<"      XXX[k1]+1 =    " << XXX[k1]+1  <<   endl;}
	    gr1 = new TGraph(MMcount,XXX,YY); 
	    Int_t colorlines=jjj+kkk;
	    gr1->SetLineColor(colorlines);  gr1->SetMarkerColor(colorlines); 
	    gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetFillStyle(0); gr1->Draw("PL");
	  }// if
	  //	  else {cout<<"****ERROR for  PLOTHO2:  MMcount is lower 1,  MMcount =   *** " << MMcount  <<   endl;}
	}//for kkk 
      }//for jjj
      
      //      TLegend leg(.6,.67,.78,.88, " HOP Depth4");
      TLegend leg(xx1,yy1,xx2,yy2, "HO: R vs t");
      //      leg.AddEntry(gr1);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      //
    }////Method = 2
    //
    
    //======================================================================================================= PLOTHO3: 2D bad channels
    if(Method == 3 ) {
      cout<<"****Draw 3 Dependencies: 2D bad channels  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gStyle->SetOptStat(0000000); 
      mapBADchannels->SetMarkerStyle(20);
      mapBADchannels->SetMarkerSize(0.4);
      mapBADchannels->GetYaxis()->SetLabelSize(0.04);
      mapBADchannels->SetXTitle("#eta \b");
      mapBADchannels->SetYTitle("#phi \b");
      mapBADchannels->SetMarkerColor(4);
      mapBADchannels->SetLineColor(4);
      mapBADchannels->Draw("COLZ");
    }//Method = 3
    //======================================================================================================= PLOTHO4:gains LED runs 
    if(Method == 4  ) {
      cout<<"****Draw 4 Dependencies: gains LED runs   *** " <<endl;
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
    }//Method = 4
    //======================================================================================================= PLOTHO5: BADruns
    if(Method == 5 ) {
      cout<<"****Draw 5 Dependencies: BADruns  *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      //      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      BADruns->SetMarkerStyle(20);
      BADruns->SetMarkerSize(0.4);
      BADruns->GetYaxis()->SetLabelSize(0.04);
      BADruns->SetXTitle("iRun");
      BADruns->SetYTitle("Nruns");
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
	  if( BADruns->GetBinContent(jjj) >1.) cout<<"BADruns:   k1(0,...)= " <<      jjj      <<"  BADruns->GetBinContent(jjj)= " <<      BADruns->GetBinContent(jjj)      <<endl;
	}//jjj
//      }// if(verbosity == 2 )
    }//Method = 5
    
    //  //////////////////////////////////////////////////////////////////////////
  //======================================================================================================= 
  //======================================================================================================= finish loop over Methods
  //======================================================================================================= 
    TString fdir = "testamt6/";
    //
    TString plotName = fdir + MethodName[Method] +".png";
    c1->SaveAs(plotName);
    cout<<"****PLOTHO "   << Method  <<" drawn **** " <<endl;
    
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
