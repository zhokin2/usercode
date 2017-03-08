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
TCanvas *c1;
TGraph *gr1;
//
//const Int_t NMAX =44;// number of LED runs(time abscissa)
//const Int_t NMAX =23;// number of LED runs(time abscissa)
const Int_t NMAX =67;// number of LED runs(time abscissa)
//
const Int_t FlagOrdinateValue= 0;// =0 absolut_values; =1 normilized on 1st LED run
const Int_t FlagWhatToImpose= 0;// =0 random channels; =1 eta range selected
const Int_t NR0=99;  // number of imposed dependencies(only FlagWhatToImpose= 0 )
//
const Int_t NMethods =35;// total number of Methods (all-together 35 methods)
const Int_t NMethodsStart =1;     // since which method to start ( min=  1)
//const Int_t NMethodsToUse =35;// choose Number of methods to use ( max= 35)
const Int_t NMethodsToUse =2;// choose Number of methods to use ( max= 35)
//
//     1-   A,     2-TSn,        3-TSx,        4-W,        5-R, 
//     6-  <A>,    7-<TSn>,      8-<TSx>,      9-<W>,     10-<R>, 
//    11- <P0>,   12-<P1>,      13-<P2>,      14-<P3>,
//    15-<PW0>,   16-<PW1>,     17-<PW2>,     18-<PW3>, 
//    19-<A12>,   20-<AtoAc>,
//    21-A_calib, 22-TSn_calib, 23-TSx_calib, 24-W_calib, 25-R_calib, 
//    26- P0,     27-P1,        28-P2,        29-P3,
//    30- PW0,    31-PW1,       32-PW2,       33-PW3,
//    34- A12,    35-AtoAc
//
//______________________________________________________________________________
  //
  TString LEDruns[NMAX] = {"194057","194124","194165","194807","195328","195470","195682","195778","195978","196150","196338","196385","196472","198091","198223","198084","198436","198552","198633","198806","198866","198964","199065","199124","199392","199419","199446","199668","199724","199778","199822","199932","200062","200552","200870","201017","201182","201305","201571","202066","202341","203339","203874","203902","204172","204584","204918","205058","205117","205225","205268","205441","205546","205637","205928","206456","207406","207545","207914","208361","208565","208959","209726","209997","210378","211006","211659"};
  //
  TString MethodName[NMethods] = {"A","TSn","TSx","W","R","avA","avTSn","avTSx","avW","avR",
				  "avP0","avP1","avP2","avP3","avPW0","avPW1","avPW2","avPW3",
				  "avA12","avAtoAc","Acalib","TSncalib","TSxcalib","Wcalib",
				  "Rcalib","P0","P1","P2","P3","PW0","PW1","PW2","PW3","A12",
				  "AtoAc"};
  Float_t XX[NMAX] = {91.,93.,94.,103.,110.,114.,117.,118.,121.,122.,124.,125.,127.,142.,144.,145.,146.,149.,150.,151.,152.,154.,156.,157.,161.,162.,163.,165.,166.,167.,168.,170.,172.,180.,185.,187.,189.,192.,194.,203.,209.,223.,231.,232.,235.,239.,244.,245.,246.,247.,248.,250.,251.,252.,261.,264.,279.,282.,288.,294.,298.,306.,334.,338.,342.,353.,365.};// days of year    time points (abscissa) !!!
  //
  //
  Float_t YY[NMAX];// ordinates !!!
  Float_t YY2[NMAX];// ordinates !!!
  Float_t YY3[NMAX];// ordinates !!!
  //
  Float_t ZZ[NMAX];// ordinates !!! normilized on values of 1st run
  //______________________________________________________________________________
  Int_t irandom = 0;
  Int_t jrandom = 0;
  Int_t Method = NMethodsStart ;
  // 1st loop to define number of imposed dependencies(corresponding different channels)
  while (Method<NMethodsToUse+1) {
    //
    Int_t NR = 1;  // initialization: number of imposed dependencies of different channels 
    if(FlagWhatToImpose == 0){
      NR = NR0;  
    }
    else if(FlagWhatToImpose == 1){
      NR = 1;  
    }
    if(Method > 5 && Method < 21 ) NR = 1;// only averaged values, one dependence only
    //
    //---=[ SetCanvasDef           ]=----------------
    // Create a new canvas.
    c1 = new TCanvas("zamt3raddam_HE","Monte Carlo Study of Z scaling",10,40,800,600);
    c1->Range(0,0,25,18);
    c1->SetFillColor(40);
    c1->Clear();
    //      c1->Divide(2,2);
    //      c1->cd(1);
    TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.83,33);
    //  pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.48,0.83,33);
    //  pad2 = new TPad("pad2","This is pad2",0.52,0.02,0.98,0.83,33);
    TLatex *t = new TLatex();
    t->SetTextFont(32);
    t->SetTextColor(4);
    t->SetTextSize(0.03);
    t->SetTextAlign(12);
    cout<<"Method =  "<<Method<<" NR =  "<<NR<<endl;
    
    //______________________________________________________________________________
    if(Method == 1) t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LED run for some random HE channels");
    if(Method == 2) t->DrawLatex(0.9,15.5,"Time dependence of TSn averaged over events of each LED run for some random HE channels");
    if(Method == 3) t->DrawLatex(0.9,15.5,"Time dependence of TSx averaged over events of each LED run for some random HE channels");
    if(Method == 4) t->DrawLatex(0.9,15.5,"Time dependence of RMS averaged over events of each LED run for some random HE channels");
    if(Method == 5) t->DrawLatex(0.9,15.5,"Time dependence of amplitude Ratio averaged over events of each LED run for some random HE channels");
    if(Method == 6) t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LED run and over all HE channels");
    if(Method == 7) t->DrawLatex(0.9,15.5,"Time dependence of TSn averaged over events of each LED run and over all HE channels");
    if(Method == 8) t->DrawLatex(0.9,15.5,"Time dependence of TSx averaged over events of each LED run and over all HE channels");
    if(Method == 9) t->DrawLatex(0.9,15.5,"Time dependence of RMS averaged over events of each LED run and over all HE channels");
    if(Method ==10) t->DrawLatex(0.9,15.5,"Time dependence of amplitude Ratio averaged over events of each LED run and over all HE channels");
    if(Method ==11) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal(cap0) averaged over events of each LED run and over all HE channels");
    if(Method ==12) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal(cap1) averaged over events of each LED run and over all HE channels");
    if(Method ==13) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal(cap2) averaged over events of each LED run and over all HE channels");
    if(Method ==14) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal(cap3) averaged over events of each LED run and over all HE channels");
    if(Method ==15) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth(cap0) averaged over events of each LED run and over all HE channels");
    if(Method ==16) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth(cap1) averaged over events of each LED run and over all HE channels");
    if(Method ==17) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth(cap2) averaged over events of each LED run and over all HE channels");
    if(Method ==18) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth(cap3) averaged over events of each LED run and over all HE channels");
    if(Method == 19) t->DrawLatex(0.9,15.5,"Time dependence of Amplitude -1max+2 averaged over events of each LED run and over all HE channels");
    if(Method == 20) t->DrawLatex(0.9,15.5,"Time dependence of normilized fullAmplitude averaged over events of each LED run and over all HE channels");
    if(Method == 21) t->DrawLatex(0.9,15.5,"Time dependence of A_calib averaged over events of each LED run for some random HE channels");
    if(Method == 22) t->DrawLatex(0.9,15.5,"Time dependence of TSn_calib averaged over events of each LED run for some random HE channels");
    if(Method == 23) t->DrawLatex(0.9,15.5,"Time dependence of TSx_calib averaged over events of each LED run for some random HE channels");
    if(Method == 24) t->DrawLatex(0.9,15.5,"Time dependence of W_calib averaged over events of each LED run for some random HE channels");
    if(Method == 25) t->DrawLatex(0.9,15.5,"Time dependence of R_calib averaged over events of each LED run for some random HE channels");
    if(Method == 26) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal-cap0 averaged over events of each LED run for some random HE channels");
    if(Method == 27) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal-cap1 averaged over events of each LED run for some random HE channels");
    if(Method == 28) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal-cap2 averaged over events of each LED run for some random HE channels");
    if(Method == 29) t->DrawLatex(0.9,15.5,"Time dependence of Pedestal-cap3 averaged over events of each LED run for some random HE channels");
    if(Method == 30) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth-cap0 averaged over events of each LED run for some random HE channels");
    if(Method == 31) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth-cap1 averaged over events of each LED run for some random HE channels");
    if(Method == 32) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth-cap2 averaged over events of each LED run for some random HE channels");
    if(Method == 33) t->DrawLatex(0.9,15.5,"Time dependence of PedestalWidth-cap3 averaged over events of each LED run for some random HE channels");
    if(Method == 34) t->DrawLatex(0.9,15.5,"Time dependence of Amplitude -1max+2 averaged over events of each LED run for some random HE channels");
    if(Method == 35) t->DrawLatex(0.9,15.5,"Time dependence of normilized fullAmplitude averaged over events of each LED run for some random HE channels");
    
    //______________________________________________________________________________
    pad1->Draw();
    //  pad2->Draw();
    //______________________________________________________________________________
    pad1->cd();
    pad1->Range(-0.255174,-19.25,2.29657,-6.75);
    //    pad1->Range(-0.255174,  -19.25,  2.29657,  -6.75);
    ////  pad2->Range(-0.436420,  -23.75,  3.92778,  -6.25);
    //   pad1->SetLogx();
    //   pad1->SetLogy();
    
    // create a 2-d histogram to define the range
    //              x1   y1     x2     y2
    if(FlagOrdinateValue !=0 ) {
      if(Method== 1 || Method== 18  || Method== 34  || Method== 35  ) {
	pad1->DrawFrame(1,   0.8,  370,   1.2);// all 
      }
      else if(Method== 6 || Method== 9 || Method== 10|| Method== 19 || Method== 21 ){
	pad1->DrawFrame(1,   0.95,  370,   1.05);// all 
      }
      else if(Method== 20  ){
	pad1->DrawFrame(1,   0.90,  370,   1.10);// all 
      }
      else {
	pad1->DrawFrame(1,   0.99,  370,   1.01);// all 
      }
    }
    else {
      if(Method == 1) pad1->DrawFrame(1,   0.,  370,   2000.0);  // 1-A, 
      if(Method == 2) pad1->DrawFrame(1,   3.,  370,      6.0);  // 2-TSn, 
      if(Method == 3) pad1->DrawFrame(1,   2.,  370,      5.0);  // 3-TSx, 
      if(Method == 4) pad1->DrawFrame(1,   1.,  370,      2.0);  // 4-W, 
      if(Method == 5) pad1->DrawFrame(1,   0.5, 370,      1.0);  // 5-R,
      if(Method == 6) pad1->DrawFrame(1, 900.,  370,   1050.0);  // 6-<A>, 
      if(Method == 7) pad1->DrawFrame(1,   3.0,  370,      5.0);  // 7-<TSn>, 
      if(Method == 8) pad1->DrawFrame(1,   2.5,  370,      3.5);  // 8-<TSx>, 
      if(Method == 9) pad1->DrawFrame(1,   1.5,  370,      2.0);  // 9-<W>, 
      if(Method ==10) pad1->DrawFrame(1,   0.0,  370,      2.0);  //10-<R>,
      if(Method ==11) pad1->DrawFrame(1,   0.1,  370,      5.1);  //11-<P0>,
      if(Method ==12) pad1->DrawFrame(1,   0.1,  370,      5.1);  //12-<P1>,
      if(Method ==13) pad1->DrawFrame(1,   0.1,  370,      5.1);  //13-<P2>,
      if(Method ==14) pad1->DrawFrame(1,   0.1,  370,      5.1);  //14-<P3>,
      if(Method ==15) pad1->DrawFrame(1,   0.1,  370,      3.1);  //15-<PW0>,
      if(Method ==16) pad1->DrawFrame(1,   0.1,  370,      3.1);  //16-<PW1>,
      if(Method ==17) pad1->DrawFrame(1,   0.1,  370,      3.1);  //17-<PW2>,
      if(Method ==18) pad1->DrawFrame(1,   0.1,  370,      3.1);  //18-<PW3>,
      if(Method ==19) pad1->DrawFrame(1,   0.,  370,   1200.0);  //19-<A12>,
      if(Method ==20) pad1->DrawFrame(1,   0.,  370,      1.5);  //20-<AtoAc>,
      if(Method ==21) pad1->DrawFrame(1, 500.,  370,   5500.0);  //21-A_calib, 
      if(Method ==22) pad1->DrawFrame(1,    2.,  370,      5.0);  //22-TSn_calib, 
      if(Method ==23) pad1->DrawFrame(1,    1.0,  370,      3.5);  //23-TSx_calib, 
      if(Method ==24) pad1->DrawFrame(1,    1.3,  370,      2.3);  //24-W_calib, 
      if(Method ==25) pad1->DrawFrame(1,    0.0,  370,      2.0);  //25-R_calib,
      if(Method ==26) pad1->DrawFrame(1,    0.,  370,      6.0);  //26-P0, 
      if(Method ==27) pad1->DrawFrame(1,    0.,  370,      6.0);  //27-P1, 
      if(Method ==28) pad1->DrawFrame(1,    0.,  370,      6.0);  //28-P2, 
      if(Method ==29) pad1->DrawFrame(1,    0.,  370,      6.0);  //29-P3, 
      if(Method ==30) pad1->DrawFrame(1,    0.,  370,      1.0);  //30-PW0, 
      if(Method ==31) pad1->DrawFrame(1,    0.,  370,      1.0);  //31-PW1, 
      if(Method ==32) pad1->DrawFrame(1,    0.,  370,      1.0);  //32-PW2, 
      if(Method ==33) pad1->DrawFrame(1,    0.,  370,      1.0);  //33-PW3, 
      if(Method ==34) pad1->DrawFrame(1,    0.,  370,   2000.0);  //34-A12, 
      if(Method ==35) pad1->DrawFrame(1,    0.,  370,      1.0);  //35-AtoAc 
    }
    //______________________________________________________________________________
    pad1->GetFrame()->SetFillColor(0);// belyj
    //    pad1->GetFrame()->SetFillColor(19);// seryj
    //    pad1->GetFrame()->SetFillColor(38);// zeleno-temnyj
    //    pad1->GetFrame()->SetFillColor(41);// jelto-kori4nev-svetl
    //    pad1->GetFrame()->SetFillColor(5);// jeltyi
    //    pad1->GetFrame()->SetFillColor(17);// seryi
    //    pad1->GetFrame()->SetFillColor(18);// svetlo seryi
    //    pad1->GetFrame()->SetFillColor(20);// svetlo kori4nev
    //    pad1->GetFrame()->SetFillColor(33);// sine-seryi
    //    pad1->GetFrame()->SetFillColor(40);// fiolet-seryi
    //    pad1->GetFrame()->SetFillColor(23);// sv.kor
    //______________________________________________________________________________
    // 
    // 2nd loop to define number of imposed dependencies(corresponding different channels)
    Int_t r1=0;
    while (r1<NR) {
      //______________________________________________________________________________
      //
      // 3rd loop over time points (led runs)
      //
      //      const char* fname = "LED_194057.root";
      //            string promt = (string) fname;
      //          string runnumber ="";
      //          for (unsigned int i=promt.size()-11; i<promt.size()-5 ; i++) runnumber += fname[i];
      TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";
      //
      Int_t NP = NMAX;  // for loop over time points(LED runs)
      for(int k1 = 0; k1<NP; k1++) {
	//______________________________________________________
	TString epsName = fname + LEDruns[k1] +".root";
	TFile *hfile= new TFile(epsName, "READ");
	//   cout << " read LED run with k1= " << k1   <<"  run:  " << LEDruns[k1] <<endl;
	//
	// Define nominator for some methods:
	//ini twod1
	TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl_HE");
	//h_mapTSmaxCalib_HE
	// ADCAmpl   - fullAmplitude
	if(Method == 1) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl_HE");
	// TSmeanA   -    TSn
	if(Method == 2) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1TSmeanA_HE");
	// TSmaxA    -   TSx
	if(Method == 3) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1TSmaxA_HE");
	// Amplitude - W
	if(Method == 4) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Amplitude_HE");
	// Ampl      - Ratio
	if(Method == 5) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Ampl_HE");
	//
	//
	// Calibration channels:
	//
	//  - fullAmplitude
	if(Method == 21) TH2F *twod1= (TH2F*)hfile->Get("h_mapADCCalib_HE");
	//  -    TSn
	if(Method == 22) TH2F *twod1= (TH2F*)hfile->Get("h_mapTSmeanCalib_HE");
	//  -   TSx
	if(Method == 23) TH2F *twod1= (TH2F*)hfile->Get("h_mapTSmaxCalib_HE");
	//  - W
	if(Method == 24) TH2F *twod1= (TH2F*)hfile->Get("h_mapWidthCalib_HE");
	//  - Ratio
	if(Method == 25) TH2F *twod1= (TH2F*)hfile->Get("h_mapRatioCalib_HE");
	//
	//
	//
	//    Pedestals:
	//
	//  - P0
	if(Method == 26) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Ped0_HE");
	//  - P1
	if(Method == 27) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Ped1_HE");
	//  - P2
	if(Method == 28) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Ped2_HE");
	//  - P3
	if(Method == 29) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Ped3_HE");
	//
	//    Pedestal Widths :
	//
	//  - PW0
	if(Method == 30) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Pedw0_HE");
	//  - PW1
	if(Method == 31) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Pedw1_HE");
	//  - PW2
	if(Method == 32) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Pedw2_HE");
	//  - PW3
	if(Method == 33) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1Pedw3_HE");
	//
	//    Amplitude: -1 max +2:
	//
	//  - A12
	if(Method == 34 || Method == 19) TH2F *twod1= (TH2F*)hfile->Get("h_mapDepth1ADCAmpl12_HE");
	//
	// Ratio of normal channel fullAmplitude to fullAmplitude of corresponding calibration channel
	//
	//  - AtoAc
	if(Method == 35 || Method == 20) TH2F *twod1= (TH2F*)hfile->Get("h_mapGetRMSOverNormalizedSignal_HE");
	//
	//
	//
	// Define result of dividing for some methods(only! mean!) and put it into YY[]:
	//
	if(Method == 6) {
	  TH1F *Ceff6= (TH1F*)hfile->Get("h_ADCAmpl_HE");
	  YY[k1]  =  Ceff6->GetMean();
	  // if(k1==0 ) cout << "for LED run k1=" << k1   <<"GetMean = " << YY[k1] <<endl;
	}
	else if(Method == 7) {
	  TH1F *Ceff7= (TH1F*)hfile->Get("h_TSmeanA_HE");
	  YY[k1]  =  Ceff7->GetMean();
	}
	else if(Method == 8) {
	  TH1F *Ceff8= (TH1F*)hfile->Get("h_TSmaxA_HE");
	  YY[k1]  =  Ceff8->GetMean();
	}
	else if(Method == 9) {
	  TH1F *Ceff9= (TH1F*)hfile->Get("h_Amplitude_HE");
	  YY[k1]  =  Ceff9->GetMean();
	}
	else if(Method == 10) {
	  TH1F *Ceff10= (TH1F*)hfile->Get("h_Ampl_HE");
	  YY[k1]  =  Ceff10->GetMean();
	}
	else if(Method == 11) {
	  TH1F *Ceff11= (TH1F*)hfile->Get("h_pedestal0_HE");
	  YY[k1]  =  Ceff11->GetMean();
	}
	else if(Method == 12) {
	  TH1F *Ceff12= (TH1F*)hfile->Get("h_pedestal1_HE");
	  YY[k1]  =  Ceff12->GetMean();
	}
	else if(Method == 13) {
	  TH1F *Ceff13= (TH1F*)hfile->Get("h_pedestal2_HE");
	  YY[k1]  =  Ceff13->GetMean();
	}
	else if(Method == 14) {
	  TH1F *Ceff14= (TH1F*)hfile->Get("h_pedestal3_HE");
	  YY[k1]  =  Ceff14->GetMean();
	}
	else if(Method == 15) {
	  TH1F *Ceff15= (TH1F*)hfile->Get("h_pedestalw0_HE");
	  YY[k1]  =  Ceff15->GetMean();
	}
	else if(Method == 16) {
	  TH1F *Ceff16= (TH1F*)hfile->Get("h_pedestalw1_HE");
	  YY[k1]  =  Ceff16->GetMean();
	}
	else if(Method == 17) {
	  TH1F *Ceff17= (TH1F*)hfile->Get("h_pedestalw2_HE");
	  YY[k1]  =  Ceff17->GetMean();
	}
	else if(Method == 18) {
	  TH1F *Ceff18= (TH1F*)hfile->Get("h_pedestalw3_HE");
	  YY[k1]  =  Ceff18->GetMean();
	}
	//
	// Define denominator for some methods and then, divide:
	//
	else {
	  //ini twod0
	  TH2F *twod0= (TH2F*)hfile->Get("h_map_HE");
	  //
	  if(Method < 6 || Method == 34) TH2F *twod0= (TH2F*)hfile->Get("h_mapDepth1_HE");
	  if(Method > 20 && Method < 34) TH2F *twod0= (TH2F*)hfile->Get("h_map_HE");
	  if(Method == 19) TH2F *twod0= (TH2F*)hfile->Get("h_map_HE");
	  if(Method == 35 || Method == 20) TH2F *twod0= (TH2F*)hfile->Get("h_mapGetRMSOverNormalizedSignal0_HE");
	  //
	  // Divide:
	  //
	  //	if(twod0->IsA()->InheritsFrom("TH2F")) {
	  TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	  twod1->Sumw2();
	  twod0->Sumw2();
	  Ceff->Divide(twod1,twod0, 1, 1, "B");  
	  //	}
	  //
	  // find random channel with non zero values of ratio and put into YY[]
	  //
	  int nx = Ceff->GetXaxis()->GetNbins();
	  int ny = Ceff->GetYaxis()->GetNbins();
	  if(k1==0 && Method == 1 && r1 == 0 )cout<<"************* nx = " << nx <<" ny = " << ny <<endl;
	  if(Method != 19 && Method != 20) {
	    //
	    if(FlagWhatToImpose == 0 ) {
	      if(k1 != 0 ) {
		YY[k1]  =  Ceff->GetBinContent(irandom,jrandom);
	      }
	      else {                      // k1=0:
		//	       if(Method == 1 && r1 == 0) {
		Int_t rr=0;
		Int_t rrcount=0;
		while (rr==0) {
		  ++rrcount;
		  //      Int_t ra = (rand() % 100) ; // 0-99
		  Int_t i = nx*((rand()%100+2)/100.);
		  Int_t j = ny*((rand()%100+2)/100.);
		  YY[k1]  =  Ceff->GetBinContent(i,j);
		  //cout<<"Point:k1="<<k1<<" r1="<<r1<<" rr="<<rr<<" i="<<i<<" j="<<j<<" YY="<<YY[k1]<<endl;
		  if(rrcount>1000) {
		    rr=1;irandom=40;jrandom=35;
		    cout<<"rr exceed 1000, seems empty file = "<<k1<<endl;
		  }
		  if(YY[k1] >0.001){ rr=1; irandom=i;jrandom=j;
		    //  cout<<"random imposed channel = " << r1+1 <<"   i= "<<irandom<<"   j= "<<jrandom<<endl;
		  }
		}//while    rr
		//if(YY[k1]>0.001)cout<<"Point:k1="<<k1<<"r1="<<r1<<"rr="<<rr<<"i="<<i<<"j="<<j<<"YY="<<YY[k1]<<endl;
		//	       }// if(Method == 1 && r1 == 0)
	      }//else
	    }//FlagWhatToImpose == 0
	    
	    else if(FlagWhatToImpose == 1 ) {
	      YY[k1] = 0.; YY2[k1] = 0.; YY3[k1] = 0.; 
	      Int_t cicl1=0; Int_t cicl2=0; Int_t cicl3=0;
	      for (int i=1;i<=nx;i++) {
		for (int j=1;j<=ny;j++) {
		  if(i>19 && i< 61) {
		    YY[k1]  +=  Ceff->GetBinContent(i,j);++cicl1;
		  }
		  else if(i>14 && i< 66) {
		    YY2[k1]  +=  Ceff->GetBinContent(i,j);++cicl2;
		  }
		  else if(i>9 && i< 71) {
		    YY3[k1]  +=  Ceff->GetBinContent(i,j);++cicl3;
		  }
		}//for
	      }//for
	      //	     cout <<  "Point:k1="<<k1<<" cicl1="<<cicl1<<" cicl2="<<cicl2<<" cicl3="<<cicl3
	      //		 <<" YY[k1]="<<YY[k1]<<" YY2[k1]="<<YY2[k1]<<" YY3[k1]="<<YY3[k1]   <<endl;
	      if(cicl1>0) YY[k1] /= cicl1;
	      if(cicl2>0) YY2[k1] /= cicl2;
	      if(cicl3>0) YY3[k1] /= cicl3;
	      //	     
	    }//else if(FlagWhatToImpose == 1
	  } //if(Method != 19 && Method != 20)
	  else {
	    TH1F* Ceff1D = new TH1F("Ceff1D","", 100, 0.,3000.);
	    int nx = Ceff->GetXaxis()->GetNbins();int ny = Ceff->GetYaxis()->GetNbins();// ???
	    for (int i=1;i<=nx;i++) {
	      for (int j=1;j<=ny;j++) {
		if(Ceff->GetBinContent(i,j) !=0 ) {
		  double ccc1 =  Ceff->GetBinContent(i,j) ;
		  Ceff1D->Fill(ccc1);}}}
	    YY[k1]  =  Ceff1D->GetMean();
	  }// else if(Method != 19 && Method != 20)
	  //	 
	}// else if(Method ...
	//
	//
	hfile->Close();
	//
      }//for k1 loop over time points(LED runs)
      
      /*  
	  cout<<" gr1: NP= " << NP
	  <<"  X0="<<XX[0]<<"Y0="<<YY[0]<<"  X1="<<XX[1]<<"Y1="<<YY[1]<<"  X2="<<XX[2]<<"Y2="<<YY[2]  
	  <<"  X3="<<XX[3]<<"Y3="<<YY[3]<<"  X4="<<XX[4]<<"Y4="<<YY[4]<<"  X5="<<XX[5]<<"Y5="<<YY[5]  
	  <<"  X6="<<XX[6]<<"Y6="<<YY[6]<<"  X7="<<XX[7]<<"Y7="<<YY[7]<<"  X8="<<XX[8]<<"Y8="<<YY[8]  
	  <<"  X9="<<XX[9]<<"Y9="<<YY[9]<<"  X10="<<XX[10]<<"Y10="<<YY[10]<<"  X11="<<XX[11]<<"Y11="<<YY[11]  
	  <<"  X12="<<XX[12]<<"Y12="<<YY[12]<<"  X13="<<XX[13]<<"Y13="<<YY[13]<<"  X14="<<XX[14]<<"Y14="<<YY[14]  
	  <<"  X15="<<XX[15]<<"Y15="<<YY[15]<<"  X16="<<XX[16]<<"Y16="<<YY[16]<<"  X17="<<XX[17]<<"Y17="<<YY[17]  
	  <<"  X18="<<XX[18]<<"Y18="<<YY[18]<<"  X19="<<XX[19]<<"Y19="<<YY[19]<<"  X20="<<XX[20]<<"Y20="<<YY[20]  
	  <<"  X21="<<XX[21]<<"Y21="<<YY[21]<<"  X22="<<XX[22]<<"Y22="<<YY[22]<<"  X23="<<XX[23]<<"Y23="<<YY[23]  
	  <<"  X24="<<XX[24]<<"Y24="<<YY[24]
	  <<endl;
      */  
      //       cout<<" Drawing.... " <<endl;
      
      if(FlagOrdinateValue !=0 ) {
	for(int k2 = 0; k2<NP; k2++) {
	  ZZ[k2] = YY[k2]/YY[0];// normalization on 1st time point
	  //cout<<"Point:k2="<<k2<<" YY[k2]="<<YY[k2]<<" YY[0]="<<YY[0]<<" ZZ[k2]="<<ZZ[k2]<<endl;
	}//
	gr1 = new TGraph(NP,XX,ZZ);}
      else {gr1 = new TGraph(NP,XX,YY);}
      gr1->SetLineColor(r1+1);
      gr1->SetMarkerColor(r1+1);
      gr1->SetMarkerStyle(20);
      gr1->SetMarkerSize(0.9);
      gPad->SetGridy();
      gPad->SetGridx();
      gr1->Draw("PL");
      //     gr1->Draw("ErrorSame");
      
      //
      //       cout<<" Drawing2  r1 =  "<<r1 <<endl;
      
      if(Method<6 || Method > 20) {
	if(FlagWhatToImpose == 1 ) {
	  if(FlagOrdinateValue !=0 ) {
	    for(int k2 = 0; k2<NP; k2++) {
	      ZZ[k2] = YY2[k2]/YY2[0];// normalization on 1st time point
	      // cout<<"Point:k2="<<k2<<" YY2[k2]="<<YY2[k2]<<" YY2[0]="<<YY2[0]<<" ZZ[k2]="<<ZZ[k2]<<endl;
	    }//
	    gr1 = new TGraph(NP,XX,ZZ);}
	  else {gr1 = new TGraph(NP,XX,YY2);}
	  gr1->SetLineColor(2);
	  gr1->SetMarkerColor(2);
	  gr1->SetMarkerStyle(20);
	  gr1->SetMarkerSize(0.9);
	  gr1->Draw("PL");
	  //       gr1->Draw("ErrorSame");
	  //
	  if(FlagOrdinateValue !=0 ) {
	    for(int k2 = 0; k2<NP; k2++) {
	      ZZ[k2] = YY3[k2]/YY3[0];// normalization on 1st time point
	      //cout<<"Point:k2="<<k2<<" YY3[k2]="<<YY3[k2]<<" YY3[0]="<<YY3[0]<<" ZZ[k2]="<<ZZ[k2]<<endl;
	    }//
	    gr1 = new TGraph(NP,XX,ZZ);}
	  else {gr1 = new TGraph(NP,XX,YY3);}
	  gr1->SetLineColor(3);
	  gr1->SetMarkerColor(3);
	  gr1->SetMarkerStyle(20);
	  gr1->SetMarkerSize(0.9);
	  gr1->Draw("PL");
	  //       gr1->Draw("ErrorSame");
	}// if(FlagWhatToImpose == 1
      }//if(Method<6 || Method > 20)
      //
      ++r1;
      //     cout<<" r1 =  "<<r1 <<endl;
    }//r1
    //______________________________________________________________________________
    //______________________________________________________________________________
    //______________________________________________________________________________
    //  
//    TString fdir = "plots/";
//    TString fdir = "plots_HE_normalized_3etaRange/";
//    TString fdir = "plots_HE_normalized/";
//    TString fdir = "plots_HE_absolut/";
    TString fdir = "testamt3/";
//
    TString plotName = fdir + MethodName[Method-1] +".png";
    c1->SaveAs(plotName);
    
    //   c1->Modified();
    //   c1->Update();
    ++Method;
  }// loop over Methods
  
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

