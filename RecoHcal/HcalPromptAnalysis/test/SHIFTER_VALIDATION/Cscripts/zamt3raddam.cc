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

//
using namespace std;
//
//  
int main(int argc, char *argv[])
{
  //______________________________________________________________________________
  //          TPostScript psfile ("zamt3raddam.ps", 111);
  //______________________________________________________________________________
  //TCanvas *c1;
  TGraph *gr1;
  //
  //

  //
  const Int_t NMethods =20;// total number of Methods (all-together 20 methods)
  const Int_t NMethodsStart =0;     // since which method to start ( min=  0)
  const Int_t NMethodsToUse =19;// choose Number of methods to use ( max= 19)
  //
  // LED:
  //
  //  TString LASERruns[NMAX] = {"194057","194124","194165","194807","195328","195470","195682","195778","195978","196150","196338","196385","196472","198091","198223","198084","198436","198552","198633","198806","198866","198964","199065","199124","199392","199419","199446","199668","199724","199778","199822","199932","200062","200552","200870","201017","201182","201305","201571","202066","202341","203339","203874","203902","204172","204584","204918","205058","205117","205225","205268","205441","205546","205637","205928","206456","207406","207545","207914","208361","208565","208959","209726","209997","210378","211006","211659"};
  //
//  Float_t XX[NMAX] = {91.,93.,94.,103.,110.,114.,117.,118.,121.,122.,124.,125.,127.,142.,144.,145.,146.,149.,150.,151.,152.,154.,156.,157.,161.,162.,163.,165.,166.,167.,168.,170.,172.,180.,185.,187.,189.,192.,194.,203.,209.,223.,231.,232.,235.,239.,244.,245.,246.,247.,248.,250.,251.,252.,261.,264.,279.,282.,288.,294.,298.,306.,334.,338.,342.,353.,365.};// days of year    time points (abscissa) !!!
  //
  // LASER: to be about just 60(instead 560) good laser runs for 2016 starting since 10.05
  //
  const Int_t NMAX =23;// number of LASER runs(time abscissa)
 TString LASERruns[NMAX] = {"272957","273329","273354",
"275799","275800","275802","275810","275814","275866","275867","275868","275874","275877",
"276084","276085","276087","276088","276089","276464","276465","276470","276478","276479",
 };
 Float_t XX[NMAX] = {1., 3., 4.,   
40.,40.,40.,40.,40.,40.,40.,40.,40.,40.,
40.,40.,40.,40.,40.,41.,41.,41.,41.,41.
 };// days of year    time points (abscissa) !!!
 //-----------------------------------------------------------------------------------------------------
 /*
   const Int_t NMAX =42;// number of LASER runs(time abscissa)
   "272957","272961","272962","272964","272967","272972","272973","272976","272977","272978",
   "273119","273121","273192","273196","273204","273209","273211","273223","273228","273232",
   "273240","273325","273329","273335","273342","273348","273354","273360","273456","273457",
   "273459","273460","273462","273465","273466","273559","273560","273561","273562","273563",
   "273565","273566","273568","273605","273607","273610","273611","273613","273895","273896",
   1.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,3.,4.,5.,5.,5.,6.,6.,6.,6.,6.,6.,6.,9.,9.,9.,9.,9.,9.,9.,9.,10.,10.,10.,10.,10.,16.,16
 */
 //---------------------------------------------------------------------------------------------------------------------
 //    Int_t NP = 7; // for loop over time points(LASER runs) NMAX is number of LASER runs(time abscissa)
 Int_t NP = NMAX;  // for loop over time points(LASER runs) NMAX is number of LASER runs(time abscissa)
 //
 TString MethodName[NMethods] = { "PLOT0", "PLOT1", "PLOT2", "PLOT3", "PLOT4", "PLOT5", "PLOT6", "PLOT7", "PLOT8", "PLOT9",
                                  "PLOT10","PLOT11","PLOT12","PLOT13","PLOT14","PLOT15","PLOT16","PLOT17","PLOT18","PLOT19"};
 //
 //
 //              x1   y1     x2     y2
 //    pad1->DrawFrame(1,   0.8,  370,   1.2);// all 
 Float_t x1=1.; Float_t x2=44.;
 Float_t y1=0.0; Float_t y2=1.1;
 //
 // take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
 //    int cutMinA = 100; int cutMaxA = 1000;   
 int cutMinA = 50; int cutMaxA = 2000;   
 // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //
    Int_t verbosity = 0;// no printout
  //
  // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //
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
  //========================================================================================== PLOT0:        Amplitude
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
  //========================================================================================== PLOT9:         Amplitude
  //========================================================================================== PLOT10:        Amplitude
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
  //========================================================================================== PLOT19:        Amplitude
  //----------------------------------------------------------------------------------------------------

  
  //  Float_t YY[NMAX][7][82];// ordinates !!!
  Double_t ZZM[NMAX][7][14];
  Double_t ZZP[NMAX][7][14];
  Float_t YY[NMAX]; 
  //  Int_t YY0[NMAX];
  //
  Double_t mapRADDAM_HE[8][83][73]; Double_t mapRADDAM_HED2[8][83]; Int_t mapRADDAM_HED20[8][83];
  Double_t normM[8][83][73]; Double_t normP[8][83][73]; 
  ///////////////////////////////////////////////////////////////////////// initial nulling:
  for(int iii = 1; iii<4; iii++) {
    for (int jjj=1;jjj<=82;jjj++) {
      mapRADDAM_HED2[iii][jjj] =  0.;
      mapRADDAM_HED20[iii][jjj] =  0.;
      for (int kkk=1;kkk<=72;kkk++) {
	mapRADDAM_HE[iii][jjj][kkk] = 0.;
	normM[iii][jjj][kkk] = 0.;
	normP[iii][jjj][kkk] = 0.;
      }
    }
  }
  /////////////////////////////////////////////////////////////////////////
  //______________________________________________________________________________
  //
  //---=[ SetCanvasDef           ]=----------------
  // Create a new canvas.
  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);

  c1->Range(0,0,25,18);
  c1->SetFillColor(40);
  c1->Clear();

  TLatex *t = new TLatex();
  t->SetTextFont(32);
  t->SetTextColor(4);
  t->SetTextSize(0.03);
  t->SetTextAlign(12);
  //______________________________________________________________________________
  t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LASER run for some random HE channels");
  
  
      TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LASER_";
//  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";
  
  // booking:
  TH1F* Ceff1D = new TH1F("Ceff1D","", 100, -100.,2000.);
//  TH1F* Ceff1D = new TH1F("Ceff1D","", 100, -1000.,4000.);
  //  TH1F* Ceff1D = new TH1F("Ceff1D","", 100, -1000.,9000.);
  Int_t kmm = 0;Int_t kpp = 0;  
    //    first runs:
    Int_t mk1f=4; Int_t pk1f=0;
  //
  //////////////////////////////////    raddam current
    for(int k1 = 0; k1<NP; k1++) {
      //______________________________________________________
    TString epsName = fname + LASERruns[k1] +".root";
    TFile *hfile= new TFile(epsName, "READ");

  //  	TFile *hfile= new TFile("LASER_226835.root", "READ");        
   //	TFile *hfile= new TFile("LASER_272957.root", "READ");        


    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! read LASER run with k1= " << k1   <<"  run:  " << LASERruns[k1] <<endl;
    //
    // Define nominator for some methods:
    // h_mapDepth1ADCAmpl12_HE means A within -1 max +1 +2
    TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12_HE");
    TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2ADCAmpl12_HE");
    TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3ADCAmpl12_HE");
    //    	TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1RADDAM_HE");
    //    	TH2F *twod2= (TH2F*)hfile->Get("h_mapDepth2RADDAM_HE");
    //    	TH2F *twod3= (TH2F*)hfile->Get("h_mapDepth3RADDAM_HE");
    // Define denominator for some methods and then, divide:
    //ini t0010
    TH2F *t0010= (TH2F*)hfile->Get("h_map_HE");
    TH2F *t0020= (TH2F*)hfile->Get("h_map_HE");
    TH2F *t0030= (TH2F*)hfile->Get("h_map_HE");
    // raddam:
    //     TH2F *t0010= (TH2F*)hfile->Get("h_mapDepth1RADDAM0_HE");
    //     TH2F *t0020= (TH2F*)hfile->Get("h_mapDepth2RADDAM0_HE");
    //     TH2F *t0030= (TH2F*)hfile->Get("h_mapDepth3RADDAM0_HE");
    //
    //
    // Divide  Divide  Divide  Divide  Divide  Divide  Divide  Divide:
    // for raddam get <Aijk>_runevents
    //
    //	if(t0010->IsA()->InheritsFrom("TH2F")) {
    TH2F* Ceff1= (TH2F*)twod1->Clone("Ceff1");
    TH2F* Ceff2= (TH2F*)twod2->Clone("Ceff2");
    TH2F* Ceff3= (TH2F*)twod3->Clone("Ceff3");
          cout<<"1 " <<endl;
    twod1->Sumw2();
          cout<<"2 " <<endl;
    twod2->Sumw2();
          cout<<"3 " <<endl;
    twod3->Sumw2();
          cout<<"4 " <<endl;
    t0010->Sumw2();
          cout<<"5 " <<endl;
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
    //////////////////////////////////////////////////////////////////////////////////   see raddam done
    
    // fill massive <Aijk>_runevents ,  where iii=depth, jjj=eta, kkk=phi
    int nx = Ceff1->GetXaxis()->GetNbins();
    int ny = Ceff1->GetYaxis()->GetNbins();
    //    if(k1==0 )cout<<"************* nx = " << nx <<" ny = " << ny <<endl;
    for (int jjj=1;jjj<=nx;jjj++) {
      for (int kkk=1;kkk<=ny;kkk++) {
	if(Ceff1->GetBinContent(jjj,kkk)!= 0.) Ceff1D->Fill(Ceff1->GetBinContent(jjj,kkk));
	if(Ceff2->GetBinContent(jjj,kkk)!= 0.) Ceff1D->Fill(Ceff2->GetBinContent(jjj,kkk));
	if(Ceff3->GetBinContent(jjj,kkk)!= 0.) Ceff1D->Fill(Ceff3->GetBinContent(jjj,kkk));

	// take into account for future treatment only channels with <Aijk>_runevents within cutMinA to cutMaxA:
	// apply cut on <Aijk>_runevents
	if(Ceff1->GetBinContent(jjj,kkk)> cutMinA && Ceff1->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[1][jjj][kkk] =  Ceff1->GetBinContent(jjj,kkk);
	if(Ceff2->GetBinContent(jjj,kkk)> cutMinA && Ceff2->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[2][jjj][kkk] =  Ceff2->GetBinContent(jjj,kkk);
	if(Ceff3->GetBinContent(jjj,kkk)> cutMinA && Ceff3->GetBinContent(jjj,kkk)< cutMaxA) mapRADDAM_HE[3][jjj][kkk] =  Ceff3->GetBinContent(jjj,kkk);
      }
    }
    //////////////////---------------------------------------
    //     refRun    Laser-megatile:           HEM : 272967 = [4] ,                     HEP : 272957 = [0],
    if(k1==mk1f && kmm==0) {
      kmm=1; //Int_t mcount=0;
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
    if(k1==pk1f && kpp==0) {
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
    //////////////////--------normalization------------------------------- find Rijk = <Aijk>_runevents /  <Aijk>_runevents(ref.run)
    for (int kkk=1;kkk<=72;kkk++) {
      for(int iii = 1; iii<4; iii++) {
	for (int jjj=1;jjj<=82;jjj++) {
	  if(normM[iii][jjj][kkk] != 0 && jjj < 42) {mapRADDAM_HE[iii][jjj][kkk] /= normM[iii][jjj][kkk];}
	  if(normP[iii][jjj][kkk] != 0 && jjj > 41) {mapRADDAM_HE[iii][jjj][kkk] /= normP[iii][jjj][kkk];}
	}//for  
      }//for 
    }//for 
    //
    //////////////////---------------------------------------

    //////////////////---------------------------------------
    // then, avereaging over phi, but first sum over phi before!!! any dividing:
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	for (int kkk=1;kkk<=72;kkk++) {
	  if(mapRADDAM_HE[iii][jjj][kkk] != 0 ) {
	    // ----------------------------------------   sum over phi before!!! any dividing:
	    mapRADDAM_HED2[iii][jjj] += mapRADDAM_HE[iii][jjj][kkk];
	    // N phi sectors w/ digihits
	    ++mapRADDAM_HED20[iii][jjj];
	  }//if
	}//for  
      }//for  
    }//for  
    //////////////------------------------------and now averaging per N-phi_sectors
    for(int iii = 1; iii<4; iii++) {
      for (int jjj=1;jjj<=82;jjj++) {
	if(mapRADDAM_HED20[iii][jjj] != 0 ) {
	  if(verbosity == 1)  cout<<"****aver per N-phi_sectors********* depth = " << iii <<" RunIndex = " << k1 <<" eta = " << jjj <<" Nphi = " << mapRADDAM_HED20[iii][jjj] <<endl;
	  mapRADDAM_HED2[iii][jjj] /= mapRADDAM_HED20[iii][jjj];
	  int jj = jjj-13;
	  if(jj> 13) jj -=44;
	  if(jj<0 || jj>13) cout<<"*** ERROR *** depth = " << iii <<" eta = " << jjj <<" new-eta = " << jj <<endl;
	  if(jjj<42) {
	    ZZM[k1][iii][jj] = mapRADDAM_HED2[iii][jjj];
	  }
	  else {
	    ZZP[k1][iii][jj] = mapRADDAM_HED2[iii][jjj];
	  }
	  //	  if(verbosity == 1)  cout<<"****aver per N-phi_sectors********* ZZM[k1][iii][jj] = " << ZZM[k1][iii][jj] <<" ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<endl;
	  //	  if(verbosity == 1)  cout<<"****aver per N-phi_sectors****** ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<endl;
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
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // =========================   normalization on first run:  M: k1 = 4; P: k1=0
  //    cout<<"****normalization on first run:  M: k1 = 0; P: k1=1 *** " <<endl;
  //  Double_t dormM = ZZM[mk1f][3][13];Double_t dormP = ZZP[pk1f][3][0];
  //
  for(int k1 = 0; k1<NP; k1++) {
    if(verbosity == 1) {cout<<" ********************************************************************time *************point = " << k1 <<endl;}
    for(int iii = 1; iii<4; iii++) {
      for (int jj=0;jj<=13;jj++) {
	if(ZZM[k1][3][13] != 0 ) {ZZM[k1][iii][jj] /= ZZM[k1][3][13];}
	if(ZZP[k1][3][0] != 0 ) {ZZP[k1][iii][jj] /= ZZP[k1][3][0];}
	//	if(verbosity == 1 && k1<3 && ZZM[k1][iii][jj] != 0 ) {cout<<"Normalized M Negative Direction ***** depth = " << iii <<" eta = " << jj <<" ZZM[k1][iii][jj] = " << ZZM[k1][iii][jj] <<endl;}
	if(verbosity == 1 && ZZP[k1][iii][jj] != 0 ) {cout<<"Normalized P Positive Direction ***** depth = " << iii <<" eta = " << jj <<" ZZP[k1][iii][jj] = " << ZZP[k1][iii][jj] <<endl;}
      }//for  
    }//for 
  }//for 
  //
  //=================================================================== normalization on first run channel 3,16:
  //           jjj =  1          |         82    | -41
  //                1- 41        -        42-82
  //                       26          57        | -41
  //HE
  // depth1         13-25        -        58-70        13-26 --> N=14, 57-70 --> N=14
  // depth2         13-24        -        59-70
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
  
  //
  //
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  cout<<"****  ****  ****  ****  ****     Draw Dependencies: *** " <<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Int_t Method = NMethodsStart ;
  while (Method<NMethodsToUse+1) {
    if( Method != 9 && Method != 10 && Method != 19 ) {
    cout<<" ****  START   Method " << Method <<endl;
    //======================================================================================================= PLOT0: <Aijk>_ev.run for all runs
    if(Method == 0 ) {
      cout<<"****Draw 0 Dependencies: draw <Aijk>_ev.run for all runs   *** " <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      //    Ceff1D->SetTitle("any Error, HE Depth1 \n");
      Ceff1D->SetMarkerStyle(20);
      Ceff1D->SetMarkerSize(0.4);
      Ceff1D->GetYaxis()->SetLabelSize(0.04);
      Ceff1D->SetXTitle("<Aijk>");
      Ceff1D->SetYTitle("N");
      Ceff1D->SetMarkerColor(4);
      Ceff1D->SetLineColor(4);
      //    Ceff1D->Draw("Error");
          Ceff1D->Draw("PL");
    }//Method = 0
    //  //////////////////////////////////////////////////////////////////////////
    //
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
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][2];}/// eta=27
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][4];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][6];}/// eta=23
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][7];}/// eta=22
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][8];}/// eta=21
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//1
    //======================================================================================================= PLOT2 r vs t negative direction:Depth1  and eta 17 18 19 20 24 26 29
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
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][0];}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][3];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][5];}/// eta=24
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][9];}/// eta=20
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][10];}/// eta=19
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][11];}/// eta=18
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][1][12];}/// eta=17
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//2
    //
    //======================================================================================================= PLOT3 r vs t negative direction:Depth2  and eta 21 22 23 25 27 28
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 3 Dependencies: M   r vs t for Depth2 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][1];}// eta=28
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][2];}/// eta=27
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][4];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][6];}/// eta=23
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][7];}/// eta=22
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][8];}/// eta=21
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//3
    //
    //======================================================================================================= PLOT4 r vs t negative direction:Depth2  and eta 17 18 19 20 24 26 29
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 4 Dependencies: M   r vs t for Depth2 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][0];}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][3];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][5];}/// eta=24
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][9];}/// eta=20
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][10];}/// eta=19
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][11];}/// eta=18
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZM[k1][2][12];}/// eta=17
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//4
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
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=27 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 2)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=25 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 4)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=23 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 6)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=22 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 7)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=21 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 8)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
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
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=26 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 3)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=24 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 5)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=20 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj == 9)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=19 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==10)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=18 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==11)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=17 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=0;jj<13;jj++) {int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1;if(LM1 == 1 && jj ==12)  {YY[k1] = ZZM[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
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
	                                                                                         int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==1){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=27 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==2){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=25 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==4){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=23 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==6){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=22 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==7){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=21 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==8){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 8 Dependencies:  M  r vs t for L7  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //======================================================= introduce Layers: negative direction
/// eta=29 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==0){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=26 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==3){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=24 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==5){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=20 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==9){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=19 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==10){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=18 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==11){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=17 L7=1
	    for(int k1 = 0; k1<NP; k1++){for(int iii=2;iii<4;iii++) {for (int jj=0;jj<=13;jj++) {int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj>1 && jj<4)) LM7=1;if(LM7==1 && jj==12){YY[k1]=ZZM[k1][iii][jj];}}}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
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
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][11];}/// eta=27
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][9];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][7];}/// eta=23
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][6];}/// eta=22
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][5];}/// eta=21
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//11
    //======================================================================================================= PLOT12 r vs t positive direction:Depth1  and eta 17 18 19 20 24 26 29
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
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][13];}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][10];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][8];}/// eta=24
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][4];}/// eta=20
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][3];}/// eta=19
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][2];}/// eta=18
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][1][1];}/// eta=17
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//12
    //
    //======================================================================================================= PLOT13 r vs t positive direction:Depth2  and eta 21 22 23 25 27 28
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 13 Dependencies: P   r vs t for Depth2 and some eta 21 22 23 25 27 28  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][12];}// eta=28
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][11];}/// eta=27
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][9];}/// eta=25
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][7];}/// eta=23
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][6];}/// eta=22
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][5];}/// eta=21
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      //
    }//13
    //
    //======================================================================================================= PLOT14 r vs t positive direction:Depth2  and eta 17 18 19 20 24 26 29
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 14 Dependencies: P   r vs t for Depth2 and some eta 17 18 19 20 24 26 29  *** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][13];}// eta=29
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][10];}/// eta=26
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][8];}/// eta=24
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][4];}/// eta=20
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][3];}/// eta=19
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][2];}/// eta=18
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
      for(int k1 = 0; k1<NP; k1++) {YY[k1] = ZZP[k1][2][1];}/// eta=17
      gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->Draw("PL");
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
      //======================================================= introduce Layers: negative direction
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
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=27 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 11)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=25 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 9)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=23 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 7)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=22 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 6)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=21 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 5)  {YY[k1] = ZZP[k1][iii][jj];} }}
	      // reject bad runs:
	    if (YY[k1]>1.05 || YY[k1]<0.95 ) cout<<"\"" << LASERruns[k1] <<"\"," << endl;
}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");


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
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=26 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 10)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=24 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 8)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=20 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 4)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=19 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 3)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=18 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 2)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=17 L1=1
	    for(int k1 = 0; k1<NP; k1++) {for(int iii = 1; iii<2; iii++) {for (int jj=1;jj<=13;jj++) {int LP1 = 0;if((iii==1 && jj>0)) LP1 = 1;if(LP1 == 1 && jj == 1)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
    }//if(Method == 16 
    //    
    //================================================================================
    //======================================================================================================= PLOT17 positive direction:r vs t for L7  and eta 21 22 23 25 27 28
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 17 Dependencies:  P  r vs t for L7  and eta 21 22 23 25 27 28   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: negative direction
// eta=28 L7=1
      for(int k1 = 0; k1<NP; k1++) {
	for(int iii = 2; iii<4; iii++) {
	  for (int jj=1;jj<13;jj++) {
	    //jj   M:    >0   >1   2  >3  <4   5   6   7   8   9   10    11    12   <13      P:    0>   1   2   3   4   5   6   7   8   9   10>  <11    12<   13<
	    // real N:   29- -28 -27  26- 25  24  23  22  21  20   19    18    17-   16           16   17- 18  19  20  21  22  23  24  25   26-   27-   28-   29-
	    //
	    // P: int LP7=0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7=1;
                                                                                             int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 12)  {YY[k1] = ZZP[k1][iii][jj];} }}}
            gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=27 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 11)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=25 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 9)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=23 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 7)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=22 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 6)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=21 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 5)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
    }//if(Method == 17 
   //
    //======================================================================================================= PLOT18 positive direction:r vs t for L7  and eta 17 18 19 20 24 26 29
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
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      cout<<"****Draw 18 Dependencies:  P  r vs t for L7  and eta 17 18 19 20 24 26 29   **** " <<endl;
      //jj   M:     0    1   2   3   4   5   6   7   8   9   10    11    12    13      P:    0    1   2   3   4   5   6   7   8   9   10    11    12    13
      // real N:   29   28  27  26  25  24  23  22  21  20   19    18    17    16           16   17  18  19  20  21  22  23  24  25   26    27    28    29
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      //======================================================= introduce Layers: negative direction
/// eta=29 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 13)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(1); gr1->SetMarkerColor(1); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=26 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 10)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(2); gr1->SetMarkerColor(2); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=24 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 8)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(3); gr1->SetMarkerColor(3); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=20 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 4)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(4); gr1->SetMarkerColor(4); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=19 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 3)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(5); gr1->SetMarkerColor(5); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=18 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 2)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(6); gr1->SetMarkerColor(6); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
/// eta=17 L7=1
    for(int k1 = 0; k1<NP; k1++) {for(int iii = 2; iii<4; iii++) {for (int jj=1;jj<13;jj++) {int LP7 = 0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7 = 1;if(LP7 == 1 && jj == 1)  {YY[k1] = ZZP[k1][iii][jj];} }}}
	    gr1 = new TGraph(NP,XX,YY); gr1->SetLineColor(7); gr1->SetMarkerColor(7); gr1->SetMarkerStyle(20); gr1->SetMarkerSize(0.9); gr1->Draw("PL");
    }//if(Method == 18 
   //    


  // L1: (iii=d1 & eta 17-29); 
  // M: int LM1 = 0;if((iii==1 && jj<13)) LM1 = 1; 
  // P: int LP1 = 0;if((iii==1 && jj> 0)) LP1 = 1;

  // :L7:  (iii=d2 & eta 17-26) && (iii=d3 & eta 27-28) 
  // M: int LM7=0;if((iii==2 && jj>3 && jj<13) || (iii==3 && jj> 1 && jj< 4)) LM7=1; 
  // P: int LP7=0;if((iii==2 && jj>0 && jj<11) || (iii==3 && jj>10 && jj<13)) LP7=1;
    
    
  //======================================================================================================= 
  //======================================================================================================= finish loop over Methods
  //======================================================================================================= 
    TString fdir = "testamt3/";
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

