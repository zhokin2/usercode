// How to run:
//root -b -q -l RemoteMonitoringGLOBAL.C+
//root -b -q -l 'RemoteMonitoringGLOBAL.C+("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_190707.root")'

#include "LogEleMapdb.h"

#include <iostream>
#include <fstream>

#include "TH1.h"
#include "TH2.h"
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
#include <THStack.h>
#include <TPaveText.h>

using namespace std;
//inline void HERE(const char *msg) { std::cout << msg << std::endl; }    kfitq
int copyContents(TH1F **hDest, TString hname, TString htitle,
		 const TH1F *hSrc, int lastBin);

// -----------------------------------------------------   

int main(int argc, char *argv[])
{

    gROOT->Reset();
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(1);

    if(argc<1) return 1;
    char fname[300];
    sprintf(fname,"%s",argv[1]);
    std::cout<<fname<<std::endl;


//======================================================================
// Connect the input files, parameters and get the 2-d histogram in memory
//    TFile *hfile= new TFile("GlobalHist.root", "READ");
    string promt = (string) fname;
    string runnumber ="";
    for (unsigned int i=promt.size()-11; i<promt.size()-5 ; i++) runnumber += fname[i];
    
    TFile *hfile= new TFile( fname, "READ");
    // Cut [test][sub][depth]
    //                              Empty                         HB                           HE                                                     HO                          HF
    double Cut0[7][5][8]={{{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,1.0,1.0,0.,0.,0.,0.,0.}, {0.,1.,1.,1.,0.,0.,0.,0.},                                {0.,0.,0.,0.,1.,0.,0.,0.},   {0.,1.,1.,0.,0.,0.,0.,0.}         },  //CapID  0,HB,HE,HO,HF 
		  //      {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,35.,35.,0.,0.,0.,0.,0.}, {0.,100.,140.,150.,0.,0.,0.,0.},                         {0.,0.,0.,0.,100.,0.,0.,0.}, {0.,170.,110.,170.,110.,0.,0.,0.} },  //Amplitude  0,HB,HE,HO,HF 
                          {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,35.,35.,0.,0.,0.,0.,0.}, {0.,12000.,4500.,3500.,3500.,4000.,4500.,5500.}, 
{0.,0.,0.,0.,200.,0.,0.,0.}, {0.,4500.,4500.,4500.,4500.,0.,0.,0.} },  //Amplitude  0,HB,HE,HO,HF 
			  {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,3.,3.,0.,0.,0.,0.,0.},   {0.,3.,3.,3.,0.,0.,0.,0.},                               {0.,0.,0.,0.,3.,0.,0.,0.},   {0.,2.,2.,0.,0.,0.,0.,0.}         }, //Width  0,HB,HE,HO,HF 
			  {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,0.4,0.4,0.,0.,0.,0.,0.}, {0.,0.4,0.4,0.4,0.,0.,0.,0.},                            {0.,0.,0.,0.,0.4,0.,0.,0.},  {0.,0.8,0.8,0.,0.,0.,0.,0.}       }, //Ratio  0,HB,HE,HO,HF 
			  {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,4.7,4.7,0.,0.,0.,0.,0.}, {0.,4.8,4.8,5.0,0.,0.,0.,0.},                            {0.,0.,0.,0.,4.8,0.,0.,0.},  {0.,4.0,4.0,0.,0.,0.,0.,0.}       }, //TSn  0,HB,HE,HO,HF 
			  {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,3.5,3.5,0.,0.,0.,0.,0.}, {0.,4.0,4.0,4.0,0.,0.,0.,0.},                            {0.,0.,0.,0.,3.,0.,0.,0.},   {0.,3.5,3.5,0.,0.,0.,0.,0.}       }, //TSx  0,HB,HE,HO,HF 
			  {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,0.,0.,0.,0.,0.,0.,0.},   {0.,0.,0.,0.,0.,0.,0.,0.},                               {0.,0.,0.,0.,0.,0.,0.,0.},   {0.,0.,0.,0.,0.,0.,0.,0.}         }  }; //Empty

    double CutAb[5][8]=   {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,20.,7.,0.,0.,0.,0.,0.},  {0.,16.,13.,4.,0.,0.,0.,0.},                             {0.,0.,0.,0.,45.,0.,0.,0.},  {0.,10.,5.,0.,0.,0.,0.,0.}        }; // cut 1 for CapIdErrors 0,HB,HE,HO,HF 

    double CutPo[5][8]=   {{0.,0.,0.,0.,0.,0.,0.,0.}, {0.,9.,3.,0.,0.,0.,0.,0.},   {0.,8.,6.,2.,0.,0.,0.,0.},                               {0.,0.,0.,0.,20.,0.,0.,0.},  {0.,5.,3.,0.,0.,0.,0.,0.}         }; //cut 3 for CapIdErrors (portions) 0,HB,HE,HO,HF 

//======================================================================



//======================================================================
// Prepare histograms and plot them to .png files
	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);

 
  TCanvas *cHB = new TCanvas("cHB","cHB",1000,500);
  TCanvas *cHE = new TCanvas("cHE","cHE",1500,500);
  TCanvas *cONE = new TCanvas("cONE","cONE",500,500);
  TCanvas *cFour = new TCanvas("cFour","cFour",1500,1000);
  TCanvas *cFour1 = new TCanvas("cFour1","cFour1",1200,800);
  TCanvas *cNine = new TCanvas("cNine","cNine",1500,1500);
  // RBX:  
//  TCanvas *c4x6 = new TCanvas("c4x6","c4x6",1500,3000);
  TCanvas *c4x6 = new TCanvas("c4x6","c4x6",1200,2400);
  //TCanvas *c5x6 = new TCanvas("c5x6","c5x6",2000,3000);
  TCanvas *c5x6 = new TCanvas("c5x6","c5x6",1500,2400);
  //  TCanvas *cRBX1 = new TCanvas("cRBX1","cRBX1",200,10,1300,1110);
    TCanvas *cRBX1 = new TCanvas("cRBX1","cRBX1",1200,1000);
  
//  char *str = (char*)alloca(10000);
  
  int k_min[5]={0,1,1,4,1}; // minimum depth for each subdet HB HE HO HF

  int k_max[5]         ={0,2,3,4,2}; // maximum depth for each subdet HB HE HO HF	
  //  int k_maxHFupgrade[5]={0,2,3,4,4}; // maximum depth for each subdet HB HE HO HF	
  int k_maxHFupgrade[5]={0,2,7,4,4}; // maximum depth for each subdet HB HE HO HF	

//+++++++++++++++++++++++++++++  
// Lumi iLumi and number of events  
//+++++++++++++++++++++++++++++ 
      cHB->Divide(2,1);
      cHB->cd(1);
      TH1F *LumLum= (TH1F*)hfile->Get("h_lsnumber_per_eachLS");
      int MaxLumDanila= LumLum->GetBinContent(LumLum->GetMaximumBin());// old variant of Danila
      cout<<" MaxLumDanila=     "<< MaxLumDanila <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
      LumLum->SetMarkerStyle(10);
      LumLum->SetMarkerSize(0.8);
      LumLum->GetYaxis()->SetLabelSize(0.04);
      LumLum->SetTitle("Cont. number per LS  \b");
      LumLum->SetXTitle("Cont.number \b");
      LumLum->SetYTitle("Ls \b");
      LumLum->SetMarkerColor(4);
      LumLum->SetLineColor(0);
      LumLum->SetMinimum(0.8);
      LumLum->GetXaxis()->SetRangeUser(0, MaxLumDanila);
      LumLum->Draw("Error");

      cHB->cd(2);
      TH1F *LumiEv= (TH1F*)hfile->Get("h_nevents_per_eachRealLS");
      int MaxLum0= LumiEv->GetBinContent(LumiEv->GetMaximumBin());
      int MaxLum = 0;for (int i=1;i<=LumiEv->GetXaxis()->GetNbins();i++) {if(LumiEv->GetBinContent(i)) {MaxLum = i; }}
      cout<<" MaxLum0=     "<< MaxLum0 <<" MaxLum=     "<< MaxLum <<endl;

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      //            gPad->SetLogx();
      LumiEv->GetYaxis()->SetLabelSize(0.04);
      LumiEv->SetTitle("Number of events per LS");
      LumiEv->SetXTitle("LS");
      LumiEv->SetYTitle("Number of events ");
      LumiEv->SetMarkerStyle(10);
      LumiEv->SetMarkerSize(0.8);
      LumiEv->SetMarkerColor(4);
      LumiEv->SetLineColor(0);
//      LumiEv->SetMinimum(0.8);
      LumiEv->GetXaxis()->SetRangeUser(0, MaxLum);
      LumiEv->Draw("Error");

      cHB->Print("LumiEvent.png"); cHB->Clear();




//=======================================================================================================
// Shape criteria: 1d histogram first definition
//=======================================================================================================
      TH1F *H_NumBadChanDepth[7][5][5];    // 1d histogramm for test,subdet, depth 
     
 //+++++++++++++++++++++++++++++  
// ADC Amplitude   
//+++++++++++++++++++++++++++++  
 
      H_NumBadChanDepth[1][1][1] = (TH1F*)hfile->Get("h_sumADCAmplLS1");
      H_NumBadChanDepth[1][1][2] = (TH1F*)hfile->Get("h_sumADCAmplLS2");
 
      H_NumBadChanDepth[1][2][1] = (TH1F*)hfile->Get("h_sumADCAmplLS3");
      H_NumBadChanDepth[1][2][2] = (TH1F*)hfile->Get("h_sumADCAmplLS4"); 
      H_NumBadChanDepth[1][2][3] = (TH1F*)hfile->Get("h_sumADCAmplLS5");
      
      H_NumBadChanDepth[1][3][4] = (TH1F*)hfile->Get("h_sumADCAmplLS8");
      
      H_NumBadChanDepth[1][4][1] = (TH1F*)hfile->Get("h_sumADCAmplLS6");
      H_NumBadChanDepth[1][4][2] = (TH1F*)hfile->Get("h_sumADCAmplLS7"); 
         
//+++++++++++++++++++++++++++++  
// Width  
//+++++++++++++++++++++++++++++  
 
      H_NumBadChanDepth[2][1][1] = (TH1F*)hfile->Get("h_sumAmplitudeLS1");
      H_NumBadChanDepth[2][1][2] = (TH1F*)hfile->Get("h_sumAmplitudeLS2");
 
      H_NumBadChanDepth[2][2][1] = (TH1F*)hfile->Get("h_sumAmplitudeLS3");
      H_NumBadChanDepth[2][2][2] = (TH1F*)hfile->Get("h_sumAmplitudeLS4"); 
      H_NumBadChanDepth[2][2][3] = (TH1F*)hfile->Get("h_sumAmplitudeLS5");
      
      H_NumBadChanDepth[2][3][4] = (TH1F*)hfile->Get("h_sumAmplitudeLS8");
      
      H_NumBadChanDepth[2][4][1] = (TH1F*)hfile->Get("h_sumAmplitudeLS6");
      H_NumBadChanDepth[2][4][2] = (TH1F*)hfile->Get("h_sumAmplitudeLS7");        
      
//+++++++++++++++++++++++++++++  
// Ratio   
//+++++++++++++++++++++++++++++   
 
      H_NumBadChanDepth[3][1][1] = (TH1F*)hfile->Get("h_sumAmplLS1");
      H_NumBadChanDepth[3][1][2] = (TH1F*)hfile->Get("h_sumAmplLS2");
 
      H_NumBadChanDepth[3][2][1] = (TH1F*)hfile->Get("h_sumAmplLS3");
      H_NumBadChanDepth[3][2][2] = (TH1F*)hfile->Get("h_sumAmplLS4"); 
      H_NumBadChanDepth[3][2][3] = (TH1F*)hfile->Get("h_sumAmplLS5");
      
      H_NumBadChanDepth[3][3][4] = (TH1F*)hfile->Get("h_sumAmplLS8");
      
      H_NumBadChanDepth[3][4][1] = (TH1F*)hfile->Get("h_sumAmplLS6");
      H_NumBadChanDepth[3][4][2] = (TH1F*)hfile->Get("h_sumAmplLS7"); 
      
//+++++++++++++++++++++++++++++  
// Tmean   
//+++++++++++++++++++++++++++++   
 
      H_NumBadChanDepth[4][1][1] = (TH1F*)hfile->Get("h_sumTSmeanALS1");
      H_NumBadChanDepth[4][1][2] = (TH1F*)hfile->Get("h_sumTSmeanALS2");
 
      H_NumBadChanDepth[4][2][1] = (TH1F*)hfile->Get("h_sumTSmeanALS3");
      H_NumBadChanDepth[4][2][2] = (TH1F*)hfile->Get("h_sumTSmeanALS4"); 
      H_NumBadChanDepth[4][2][3] = (TH1F*)hfile->Get("h_sumTSmeanALS5");
      
      H_NumBadChanDepth[4][3][4] = (TH1F*)hfile->Get("h_sumTSmeanALS8");
     
      H_NumBadChanDepth[4][4][1] = (TH1F*)hfile->Get("h_sumTSmeanALS6");
      H_NumBadChanDepth[4][4][2] = (TH1F*)hfile->Get("h_sumTSmeanALS7"); 
             
//+++++++++++++++++++++++++++++  
// Tmax   
//+++++++++++++++++++++++++++++   
 
      H_NumBadChanDepth[5][1][1] = (TH1F*)hfile->Get("h_sumTSmaxALS1");
      H_NumBadChanDepth[5][1][2] = (TH1F*)hfile->Get("h_sumTSmaxALS2");
 
      H_NumBadChanDepth[5][2][1] = (TH1F*)hfile->Get("h_sumTSmaxALS3");
      H_NumBadChanDepth[5][2][2] = (TH1F*)hfile->Get("h_sumTSmaxALS4"); 
      H_NumBadChanDepth[5][2][3] = (TH1F*)hfile->Get("h_sumTSmaxALS5");
      
      H_NumBadChanDepth[5][3][4] = (TH1F*)hfile->Get("h_sumTSmaxALS8");
      
      H_NumBadChanDepth[5][4][1] = (TH1F*)hfile->Get("h_sumTSmaxALS6");
      H_NumBadChanDepth[5][4][2] = (TH1F*)hfile->Get("h_sumTSmaxALS7");

    gStyle->SetOptStat(110000);                     
                            
    for (int test=1;test<=5;test++) { //Test: 0, 
        for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
            if (sub==1) cHB->Divide(2,1);
            if (sub==2) cHE->Divide(3,1);
            if (sub==3) cONE->Divide(1,1);
            if (sub==4) cHB->Divide(2,1);
            for (int k=k_min[sub];k<=k_max[sub];k++) {  //Depth 
                if (sub==1) cHB->cd(k); 
                if (sub==2) cHE->cd(k);
	        if (sub==3) cONE->cd(k-3);
	        if (sub==4) cHB->cd(k);   
		gPad->SetGridy();
                gPad->SetGridx();
                gPad->SetLogy();   
                H_NumBadChanDepth[test][sub][k]->SetMarkerStyle(20);
                H_NumBadChanDepth[test][sub][k]->SetMarkerSize(0.8);
                if (k == 1) H_NumBadChanDepth[test][sub][k]->SetTitle("Depth 1\b");
		if (k == 2) H_NumBadChanDepth[test][sub][k]->SetTitle("Depth 2\b");
		if (k == 3) H_NumBadChanDepth[test][sub][k]->SetTitle("Depth 3\b");
		if (k == 4) H_NumBadChanDepth[test][sub][k]->SetTitle("Depth 4\b");
		if (test==1) H_NumBadChanDepth[test][sub][k]->SetXTitle(" <Amplitude> \b");
		if (test==2) H_NumBadChanDepth[test][sub][k]->SetXTitle(" <Width> \b");
		if (test==3) H_NumBadChanDepth[test][sub][k]->SetXTitle(" <Ratio> \b");
		if (test==4) H_NumBadChanDepth[test][sub][k]->SetXTitle(" <TS mean> \b");
		if (test==5) H_NumBadChanDepth[test][sub][k]->SetXTitle(" <TS max> \b");
		H_NumBadChanDepth[test][sub][k]->SetYTitle("Number of channel-LSs\b");
		H_NumBadChanDepth[test][sub][k]->SetMarkerColor(4);
                H_NumBadChanDepth[test][sub][k]->SetLineColor(0);
		//                H_NumBadChanDepth[test][sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
		H_NumBadChanDepth[test][sub][k]->SetMinimum(0.8);
		H_NumBadChanDepth[test][sub][k]->Draw("Error");
		  	   
	    }    
	    if (test==0){ 
	        if (sub==1) {cHB->Print("H_NBCMNHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_NBCMNHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_NBCMNHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_NBCMNHF.png"); cHB->Clear();}  
	    } 
	    
	    if (test==1){ 
	        if (sub==1) {cHB->Print("H_ADCamplHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_ADCamplHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_ADCamplHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_ADCamplHF.png"); cHB->Clear();}  
	    } 
	    if (test==2){ 
	        if (sub==1) {cHB->Print("H_WidthHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_WidthHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_WidthHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_WidthHF.png"); cHB->Clear();}  
	    } 
	    if (test==3){ 
	        if (sub==1) {cHB->Print("H_RatioHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_RatioHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_RatioHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_RatioHF.png"); cHB->Clear();}  
	    } 
	    if (test==4){ 
	        if (sub==1) {cHB->Print("H_TmeanHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_TmeanHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_TmeanHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_TmeanHF.png"); cHB->Clear();}  
	    } 
	    if (test==5){ 
	        if (sub==1) {cHB->Print("H_TmaxHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("H_TmaxHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("H_TmaxHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("H_TmaxHF.png"); cHB->Clear();}  
	    } 	    	   	                  
         }// end sub 
     }//end test	          
      
    gStyle->SetOptStat(0);
//================================================================================================================================ 
 
 
//=======================================================================================================
// 2-d histograms second definition
//=========================================================
      TH2F *MapNumBadChanDepth[7][5][5];    // 1d Mapogramm for test,subdet, depth 
      TH2F *MapNumChanDepth[7][5][5];    // 1d Mapogramm for test,subdet, depth   
      TH2F *MapNumBadChanFull[7];    // 1d Mapogramm for test
      TH2F *MapNumChanFull[7];    // 1d Mapogramm for test  

//+++++++++++++++++++++++++++++  
// CapID    
//+++++++++++++++++++++++++++++   
 
 
      MapNumBadChanDepth[0][1][1] = (TH2F*)hfile->Get("h_mapDepth1Error_HB");
      MapNumBadChanDepth[0][1][2] = (TH2F*)hfile->Get("h_mapDepth2Error_HB");
 
      MapNumBadChanDepth[0][2][1] = (TH2F*)hfile->Get("h_mapDepth1Error_HE");
      MapNumBadChanDepth[0][2][2] = (TH2F*)hfile->Get("h_mapDepth2Error_HE"); 
      MapNumBadChanDepth[0][2][3] = (TH2F*)hfile->Get("h_mapDepth3Error_HE");
      
      MapNumBadChanDepth[0][3][4] = (TH2F*)hfile->Get("h_mapDepth4Error_HO");
      
      MapNumBadChanDepth[0][4][1] = (TH2F*)hfile->Get("h_mapDepth1Error_HF");
      MapNumBadChanDepth[0][4][2] = (TH2F*)hfile->Get("h_mapDepth2Error_HF");  
     
      MapNumBadChanFull[0] = (TH2F*) MapNumBadChanDepth[0][1][1]->Clone();  
      
      
      MapNumChanDepth[0][1][1] = (TH2F*)hfile->Get("h_mapDepth1_HB");     
      MapNumChanDepth[0][1][2] = (TH2F*)hfile->Get("h_mapDepth2_HB");                                               
 
      MapNumChanDepth[0][2][1] = (TH2F*)hfile->Get("h_mapDepth1_HE");     
      MapNumChanDepth[0][2][2] = (TH2F*)hfile->Get("h_mapDepth2_HE"); 
      MapNumChanDepth[0][2][3] = (TH2F*)hfile->Get("h_mapDepth3_HE");     
      
      MapNumChanDepth[0][3][4] = (TH2F*)hfile->Get("h_mapDepth4_HO"); 
      
      MapNumChanDepth[0][4][1] = (TH2F*)hfile->Get("h_mapDepth1_HF");     
      MapNumChanDepth[0][4][2] = (TH2F*)hfile->Get("h_mapDepth2_HF");
      
      MapNumChanFull[0] = (TH2F*) MapNumChanDepth[0][1][1]->Clone();

      
 //+++++++++++++++++++++++++++++  
// ADC Amplitude   
//+++++++++++++++++++++++++++++   
 
 
      MapNumBadChanDepth[1][1][1] = (TH2F*)hfile->Get("h_2DsumADCAmplLS1");
      MapNumBadChanDepth[1][1][2] = (TH2F*)hfile->Get("h_2DsumADCAmplLS2");
 
      MapNumBadChanDepth[1][2][1] = (TH2F*)hfile->Get("h_2DsumADCAmplLS3");
      MapNumBadChanDepth[1][2][2] = (TH2F*)hfile->Get("h_2DsumADCAmplLS4"); 
      MapNumBadChanDepth[1][2][3] = (TH2F*)hfile->Get("h_2DsumADCAmplLS5");
      
      MapNumBadChanDepth[1][3][4] = (TH2F*)hfile->Get("h_2DsumADCAmplLS8");
      
      MapNumBadChanDepth[1][4][1] = (TH2F*)hfile->Get("h_2DsumADCAmplLS6");
      MapNumBadChanDepth[1][4][2] = (TH2F*)hfile->Get("h_2DsumADCAmplLS7");  
     
      MapNumBadChanFull[1] = (TH2F*) MapNumBadChanDepth[1][1][1]->Clone();  
      
      
      MapNumChanDepth[1][1][1] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS1");     
      MapNumChanDepth[1][1][2] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS2");                                               
 
      MapNumChanDepth[1][2][1] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS3");     
      MapNumChanDepth[1][2][2] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS4"); 
      MapNumChanDepth[1][2][3] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS5");     
      
      MapNumChanDepth[1][3][4] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS8"); 
      
      MapNumChanDepth[1][4][1] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS6");     
      MapNumChanDepth[1][4][2] = (TH2F*)hfile->Get("h_2D0sumADCAmplLS7");
      
      MapNumChanFull[1] = (TH2F*) MapNumChanDepth[1][1][1]->Clone();
           
//+++++++++++++++++++++++++++++  
// Width  
//+++++++++++++++++++++++++++++   
 
      MapNumBadChanDepth[2][1][1] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS1");
      MapNumBadChanDepth[2][1][2] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS2");
 
      MapNumBadChanDepth[2][2][1] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS3");
      MapNumBadChanDepth[2][2][2] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS4"); 
      MapNumBadChanDepth[2][2][3] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS5");
      
      MapNumBadChanDepth[2][3][4] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS8");
      
      MapNumBadChanDepth[2][4][1] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS6");
      MapNumBadChanDepth[2][4][2] = (TH2F*)hfile->Get("h_2DsumAmplitudeLS7");    
      
      MapNumBadChanFull[2] = (TH2F*) MapNumBadChanDepth[2][1][1]->Clone(); 
      
      MapNumChanDepth[2][1][1] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS1");     
      MapNumChanDepth[2][1][2] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS2"); 
 
      MapNumChanDepth[2][2][1] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS3");     
      MapNumChanDepth[2][2][2] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS4"); 
      MapNumChanDepth[2][2][3] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS5");     
      
      MapNumChanDepth[2][3][4] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS8"); 
      
      MapNumChanDepth[2][4][1] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS6");     
      MapNumChanDepth[2][4][2] = (TH2F*)hfile->Get("h_2D0sumAmplitudeLS7");
      
      MapNumChanFull[2] = (TH2F*) MapNumChanDepth[2][1][1]->Clone();
      
//+++++++++++++++++++++++++++++  
// Ratio   
//+++++++++++++++++++++++++++++  
 
      MapNumBadChanDepth[3][1][1] = (TH2F*)hfile->Get("h_2DsumAmplLS1");
      MapNumBadChanDepth[3][1][2] = (TH2F*)hfile->Get("h_2DsumAmplLS2");
 
      MapNumBadChanDepth[3][2][1] = (TH2F*)hfile->Get("h_2DsumAmplLS3");
      MapNumBadChanDepth[3][2][2] = (TH2F*)hfile->Get("h_2DsumAmplLS4"); 
      MapNumBadChanDepth[3][2][3] = (TH2F*)hfile->Get("h_2DsumAmplLS5");
      
      MapNumBadChanDepth[3][3][4] = (TH2F*)hfile->Get("h_2DsumAmplLS8");
      
      MapNumBadChanDepth[3][4][1] = (TH2F*)hfile->Get("h_2DsumAmplLS6");
      MapNumBadChanDepth[3][4][2] = (TH2F*)hfile->Get("h_2DsumAmplLS7"); 
      
      MapNumBadChanFull[3] = (TH2F*) MapNumBadChanDepth[3][1][1]->Clone(); 
      
      
      MapNumChanDepth[3][1][1] = (TH2F*)hfile->Get("h_2D0sumAmplLS1");     
      MapNumChanDepth[3][1][2] = (TH2F*)hfile->Get("h_2D0sumAmplLS2"); 
 
      MapNumChanDepth[3][2][1] = (TH2F*)hfile->Get("h_2D0sumAmplLS3");     
      MapNumChanDepth[3][2][2] = (TH2F*)hfile->Get("h_2D0sumAmplLS4"); 
      MapNumChanDepth[3][2][3] = (TH2F*)hfile->Get("h_2D0sumAmplLS5");     
      
      MapNumChanDepth[3][3][4] = (TH2F*)hfile->Get("h_2D0sumAmplLS8"); 
      
      MapNumChanDepth[3][4][1] = (TH2F*)hfile->Get("h_2D0sumAmplLS6");     
      MapNumChanDepth[3][4][2] = (TH2F*)hfile->Get("h_2D0sumAmplLS7");
      
      MapNumChanFull[3] = (TH2F*) MapNumChanDepth[3][1][1]->Clone();
      
//+++++++++++++++++++++++++++++  
// Tmean   
//+++++++++++++++++++++++++++++ 
  
      MapNumBadChanDepth[4][1][1] = (TH2F*)hfile->Get("h_2DsumTSmeanALS1");
      MapNumBadChanDepth[4][1][2] = (TH2F*)hfile->Get("h_2DsumTSmeanALS2");
 
      MapNumBadChanDepth[4][2][1] = (TH2F*)hfile->Get("h_2DsumTSmeanALS3");
      MapNumBadChanDepth[4][2][2] = (TH2F*)hfile->Get("h_2DsumTSmeanALS4"); 
      MapNumBadChanDepth[4][2][3] = (TH2F*)hfile->Get("h_2DsumTSmeanALS5");
      
      MapNumBadChanDepth[4][3][4] = (TH2F*)hfile->Get("h_2DsumTSmeanALS8");
     
      MapNumBadChanDepth[4][4][1] = (TH2F*)hfile->Get("h_2DsumTSmeanALS6");
      MapNumBadChanDepth[4][4][2] = (TH2F*)hfile->Get("h_2DsumTSmeanALS7");
      
      MapNumBadChanFull[4] = (TH2F*) MapNumBadChanDepth[4][1][1]->Clone();  
      
      
      MapNumChanDepth[4][1][1] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS1");     
      MapNumChanDepth[4][1][2] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS2"); 
 
      MapNumChanDepth[4][2][1] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS3");     
      MapNumChanDepth[4][2][2] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS4"); 
      MapNumChanDepth[4][2][3] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS5");     
      
      MapNumChanDepth[4][3][4] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS8"); 
      
      MapNumChanDepth[4][4][1] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS6");     
      MapNumChanDepth[4][4][2] = (TH2F*)hfile->Get("h_2D0sumTSmeanALS7");
      
      MapNumChanFull[4] = (TH2F*) MapNumChanDepth[4][1][1]->Clone(); 
      
//+++++++++++++++++++++++++++++  
// Tmax   
//+++++++++++++++++++++++++++++   
 
      MapNumBadChanDepth[5][1][1] = (TH2F*)hfile->Get("h_2DsumTSmaxALS1");
      MapNumBadChanDepth[5][1][2] = (TH2F*)hfile->Get("h_2DsumTSmaxALS2");
 
      MapNumBadChanDepth[5][2][1] = (TH2F*)hfile->Get("h_2DsumTSmaxALS3");
      MapNumBadChanDepth[5][2][2] = (TH2F*)hfile->Get("h_2DsumTSmaxALS4"); 
      MapNumBadChanDepth[5][2][3] = (TH2F*)hfile->Get("h_2DsumTSmaxALS5");
      
      MapNumBadChanDepth[5][3][4] = (TH2F*)hfile->Get("h_2DsumTSmaxALS8");
      
      MapNumBadChanDepth[5][4][1] = (TH2F*)hfile->Get("h_2DsumTSmaxALS6");
      MapNumBadChanDepth[5][4][2] = (TH2F*)hfile->Get("h_2DsumTSmaxALS7"); 
      
      MapNumBadChanFull[5] = (TH2F*) MapNumBadChanDepth[5][1][1]->Clone();   
           
      MapNumChanDepth[5][1][1] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS1");     
      MapNumChanDepth[5][1][2] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS2"); 
 
      MapNumChanDepth[5][2][1] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS3");     
      MapNumChanDepth[5][2][2] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS4"); 
      MapNumChanDepth[5][2][3] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS5");     
      
      MapNumChanDepth[5][3][4] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS8"); 
      
      MapNumChanDepth[5][4][1] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS6");     
      MapNumChanDepth[5][4][2] = (TH2F*)hfile->Get("h_2D0sumTSmaxALS7");
      
      MapNumChanFull[5] = (TH2F*) MapNumChanDepth[5][1][1]->Clone(); 
                  
      
    for (int test=0;test<=5;test++) { //Test: 0, 
        for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
            if (sub==1) cHB->Divide(2,1);
            if (sub==2) cHE->Divide(3,1);
            if (sub==3) cONE->Divide(1,1);
            if (sub==4) cHB->Divide(2,1);
            for (int k=k_min[sub];k<=k_max[sub];k++) {  //Depth 		                
                if (sub==1) cHB->cd(k); 
                if (sub==2) cHE->cd(k);
	        if (sub==3) cONE->cd(k-3);
	        if (sub==4) cHB->cd(k);            
		MapNumBadChanDepth[test][sub][k]->Divide(MapNumBadChanDepth[test][sub][k],MapNumChanDepth[test][sub][k], 1, 1, "B");

                for (int x=1;x<=MapNumBadChanFull[test]->GetXaxis()->GetNbins();x++) {
                   for (int y=1;y<=MapNumBadChanFull[test]->GetYaxis()->GetNbins(); y++) {
	               double ccc1 =  MapNumBadChanDepth[test][sub][k]->GetBinContent(x,y);
		       MapNumBadChanFull[test]->SetBinContent(x,y,MapNumBadChanFull[test]->GetBinContent(x,y) + ccc1);
                   }//end y
                }//end x
  		    
                if (k == 1) MapNumBadChanDepth[test][sub][k]->SetTitle("Depth 1\b");
		if (k == 2) MapNumBadChanDepth[test][sub][k]->SetTitle("Depth 2\b");
		if (k == 3) MapNumBadChanDepth[test][sub][k]->SetTitle("Depth 3\b");
		if (k == 4) MapNumBadChanDepth[test][sub][k]->SetTitle("Depth 4\b");
		gPad->SetGridy();
                gPad->SetGridx();
                gPad->SetLogz();
                MapNumBadChanDepth[test][sub][k]->SetXTitle("#eta \b");
                MapNumBadChanDepth[test][sub][k]->SetYTitle("#phi \b");
                MapNumBadChanDepth[test][sub][k]->SetZTitle("Average estimator \b");
	        MapNumBadChanDepth[test][sub][k]->SetTitleOffset(0.75,"Z");
                MapNumBadChanDepth[test][sub][k]->Draw("COLZ");
                MapNumBadChanDepth[test][sub][k]->GetYaxis()->SetRangeUser(0, 72.);
//                MapNumBadChanDepth[test][sub][k]->GetZaxis()->SetRangeUser(0.0001, 1.);
	    }    
	    if (test==0){ 
	        if (sub==1) {cHB->Print("MapCapIdErrorHB.png"); cHB->Clear();}
                if (sub==2) {cHE->Print("MapCapIdErrorHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapCapIdErrorHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapCapIdErrorHF.png"); cHB->Clear();}  	    
	    }
	    if (test==1){ 
	        if (sub==1) {cHB->Print("MapADCamplHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("MapADCamplHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapADCamplHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapADCamplHF.png"); cHB->Clear();}  
	    } 
	    if (test==2){ 
	        if (sub==1) {cHB->Print("MapWidthHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("MapWidthHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapWidthHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapWidthHF.png"); cHB->Clear();}  
	    } 
	    if (test==3){ 
	        if (sub==1) {cHB->Print("MapRatioHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("MapRatioHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapRatioHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapRatioHF.png"); cHB->Clear();}  
	    } 
	    if (test==4){ 
	        if (sub==1) {cHB->Print("MapTmeanHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("MapTmeanHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapTmeanHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapTmeanHF.png"); cHB->Clear();}  
	    } 
	    if (test==5){ 
	        if (sub==1) {cHB->Print("MapTmaxHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("MapTmaxHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("MapTmaxHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("MapTmaxHF.png"); cHB->Clear();}  
	    } 	    	    	   	                  
         }// end sub	 
         cONE->Divide(1,1);
	 cONE->cd(1);
	 gPad->SetGridy();
         gPad->SetGridx();
         gPad->SetLogz();
         MapNumBadChanFull[test]->SetTitle("All subdetectors\b");
	 MapNumBadChanFull[test]->SetXTitle("#eta \b");
         MapNumBadChanFull[test]->SetYTitle("#phi \b");
         if (test==0) MapNumBadChanFull[test]->SetZTitle("Average Nbcs \b");
         if (test!=0) MapNumBadChanFull[test]->SetZTitle("Average estimator \b");
	 //	 MapNumBadChanFull[test]->GetZaxis()->SetLabelSize(0.008);
	 MapNumBadChanFull[test]->SetTitleOffset(0.75,"Z");
	 MapNumBadChanFull[test]->Draw("COLZ");
         MapNumBadChanFull[test]->GetYaxis()->SetRangeUser(0, 72.);
//         MapNumBadChanFull[test]->GetZaxis()->SetRangeUser(0.0001, 1.);
	 if (test==0) {cONE->Print("MapCapIdError.png"); cONE->Clear();}	  
         if (test==1) {cONE->Print("MapADCAmpl.png"); cONE->Clear();}
         if (test==2) {cONE->Print("MapWidth.png"); cONE->Clear();}
         if (test==3) {cONE->Print("MapRatio.png"); cONE->Clear();}
	 if (test==4) {cONE->Print("MapTmean.png"); cONE->Clear();}
	 if (test==5) {cONE->Print("MapTmax.png"); cONE->Clear();}			      
     }//end test	          

      
//================================================================================================================================ 
  
 
//=======================================================================================================
// 1-d histograms third definition

      TH1F *HistNumBadChanDepth[7][5][8];    // 1d histogramm for test,subdet, depth 
      TH1F *HistCutNumBadChanDepth[7][5][8];    // 1d histogramm for test,subdet, depth 
      TH1F *HistNumChanDepth[7][5][8];    // 1d histogramm for test,subdet, depth   

      //      TH1F *HistNumBadChanDepth[7][5][5];    // 1d histogramm for test,subdet, depth 
      //      TH1F *HistCutNumBadChanDepth[7][5][5];    // 1d histogramm for test,subdet, depth 
      //      TH1F *HistNumChanDepth[7][5][5];    // 1d histogramm for test,subdet, depth   

      TH1F *HistNumBadChanFull[7];    // 1d histogramm for test
      TH1F *HistNumChanFull[7];    // 1d histogramm for test  

//+++++++++++++++++++++++++++++  
// Rate of Cap ID errors   
//+++++++++++++++++++++++++++++  
 
      HistNumBadChanDepth[0][1][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HB");
      HistNumBadChanDepth[0][1][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HB");
 
      HistNumBadChanDepth[0][2][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HE");
      HistNumBadChanDepth[0][2][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HE"); 
      HistNumBadChanDepth[0][2][3] = (TH1F*)hfile->Get("h_runnbadchannels_depth3_HE");
      
      HistNumBadChanDepth[0][3][4] = (TH1F*)hfile->Get("h_runnbadchannels_depth4_HO");
      
      HistNumBadChanDepth[0][4][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HF");
      HistNumBadChanDepth[0][4][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HF");    
       
      HistNumBadChanFull[0] = (TH1F*) HistNumBadChanDepth[0][1][1]->Clone();
      
      HistCutNumBadChanDepth[0][1][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HB");
      HistCutNumBadChanDepth[0][1][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HB");
 
      HistCutNumBadChanDepth[0][2][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HE");
      HistCutNumBadChanDepth[0][2][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HE"); 
      HistCutNumBadChanDepth[0][2][3] = (TH1F*)hfile->Get("h_runnbadchannels_depth3_HE");
      
      HistCutNumBadChanDepth[0][3][4] = (TH1F*)hfile->Get("h_runnbadchannels_depth4_HO");
      
      HistCutNumBadChanDepth[0][4][1] = (TH1F*)hfile->Get("h_runnbadchannels_depth1_HF");
      HistCutNumBadChanDepth[0][4][2] = (TH1F*)hfile->Get("h_runnbadchannels_depth2_HF"); 
            
      
      HistNumChanDepth[0][1][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HB");     
      HistNumChanDepth[0][1][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HB"); 
 
      HistNumChanDepth[0][2][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HE");     
      HistNumChanDepth[0][2][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HE"); 
      HistNumChanDepth[0][2][3] = (TH1F*)hfile->Get("h_runbadrate0_depth3_HE");     
      
      HistNumChanDepth[0][3][4] = (TH1F*)hfile->Get("h_runbadrate0_depth4_HO"); 
      
      HistNumChanDepth[0][4][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HF");     
      HistNumChanDepth[0][4][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HF");
                                                           
      HistNumChanFull[0] = (TH1F*) HistNumChanDepth[0][1][1]->Clone();
      
 //+++++++++++++++++++++++++++++  
// ADC Amplitude   
//+++++++++++++++++++++++++++++  
 
//////////////////////
      // HB:
      HistNumBadChanDepth[1][1][1] = (TH1F*)hfile->Get("h_sumADCAmplperLS1");
      HistNumBadChanDepth[1][1][2] = (TH1F*)hfile->Get("h_sumADCAmplperLS2");
 
      // HE:
      HistNumBadChanDepth[1][2][1] = (TH1F*)hfile->Get("h_sumADCAmplperLS3");
      HistNumBadChanDepth[1][2][2] = (TH1F*)hfile->Get("h_sumADCAmplperLS4"); 
      HistNumBadChanDepth[1][2][3] = (TH1F*)hfile->Get("h_sumADCAmplperLS5");
      // HE upgrade:
      HistNumBadChanDepth[1][2][4] = (TH1F*)hfile->Get("h_sumADCAmplperLSdepth4HEu");
      HistNumBadChanDepth[1][2][5] = (TH1F*)hfile->Get("h_sumADCAmplperLSdepth5HEu"); 
      HistNumBadChanDepth[1][2][6] = (TH1F*)hfile->Get("h_sumADCAmplperLSdepth6HEu");
      HistNumBadChanDepth[1][2][7] = (TH1F*)hfile->Get("h_sumADCAmplperLSdepth7HEu");
      
      // HO:
      HistNumBadChanDepth[1][3][4] = (TH1F*)hfile->Get("h_sumADCAmplperLS8");
      
      // HF:
      HistNumBadChanDepth[1][4][1] = (TH1F*)hfile->Get("h_sumADCAmplperLS6");
      HistNumBadChanDepth[1][4][2] = (TH1F*)hfile->Get("h_sumADCAmplperLS7");
      // HF upgrade:
      HistNumBadChanDepth[1][4][3] = (TH1F*)hfile->Get("h_sumADCAmplperLS6u");
      HistNumBadChanDepth[1][4][4] = (TH1F*)hfile->Get("h_sumADCAmplperLS7u");
      
      // other cases:
      HistNumBadChanFull[1] = (TH1F*) HistNumBadChanDepth[1][1][1]->Clone();
      
//////////////////////
      // HB:
      HistCutNumBadChanDepth[1][1][1] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS1");
      HistCutNumBadChanDepth[1][1][2] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS2");
 
      // HE:
      HistCutNumBadChanDepth[1][2][1] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS3");
      HistCutNumBadChanDepth[1][2][2] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS4"); 
      HistCutNumBadChanDepth[1][2][3] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS5");
      // HE upgrade:
      HistCutNumBadChanDepth[1][2][4] = (TH1F*)hfile->Get("h_sumCutADCAmplperLSdepth4HEu");
      HistCutNumBadChanDepth[1][2][5] = (TH1F*)hfile->Get("h_sumCutADCAmplperLSdepth5HEu"); 
      HistCutNumBadChanDepth[1][2][6] = (TH1F*)hfile->Get("h_sumCutADCAmplperLSdepth6HEu");
      HistCutNumBadChanDepth[1][2][7] = (TH1F*)hfile->Get("h_sumCutADCAmplperLSdepth7HEu");
      
      // HO:
      HistCutNumBadChanDepth[1][3][4] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS8");
      
      // HF:
      HistCutNumBadChanDepth[1][4][1] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS6");
      HistCutNumBadChanDepth[1][4][2] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS7");    
      // HF upgrade:
      HistCutNumBadChanDepth[1][4][3] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS6u");
      HistCutNumBadChanDepth[1][4][4] = (TH1F*)hfile->Get("h_sumCutADCAmplperLS7u");
      
      
//////////////////////
      // HB:
      HistNumChanDepth[1][1][1] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS1");     
      HistNumChanDepth[1][1][2] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS2"); 
 
      // HE:
      HistNumChanDepth[1][2][1] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS3");     
      HistNumChanDepth[1][2][2] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS4"); 
      HistNumChanDepth[1][2][3] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS5");     
      // HE upgrade:
      HistNumChanDepth[1][2][4] = (TH1F*)hfile->Get("h_sum0ADCAmplperLSdepth4HEu");
      HistNumChanDepth[1][2][5] = (TH1F*)hfile->Get("h_sum0ADCAmplperLSdepth5HEu"); 
      HistNumChanDepth[1][2][6] = (TH1F*)hfile->Get("h_sum0ADCAmplperLSdepth6HEu");
      HistNumChanDepth[1][2][7] = (TH1F*)hfile->Get("h_sum0ADCAmplperLSdepth7HEu");
      
      // HO:
      HistNumChanDepth[1][3][4] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS8"); 
      
      // HF:
      HistNumChanDepth[1][4][1] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS6");     
      HistNumChanDepth[1][4][2] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS7");
      // HF upgrade:
      HistNumChanDepth[1][4][3] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS6u");
      HistNumChanDepth[1][4][4] = (TH1F*)hfile->Get("h_sum0ADCAmplperLS7u");
           
      // other cases:
      HistNumChanFull[1] = (TH1F*) HistNumChanDepth[1][1][1]->Clone();
      // just initialization of [6] massive for alternative <A> calculation
      HistNumChanFull[6] = (TH1F*) HistNumChanDepth[1][1][1]->Clone();

//+++++++++++++++++++++++++++++  
// Width  
//+++++++++++++++++++++++++++++  
 
      HistNumBadChanDepth[2][1][1] = (TH1F*)hfile->Get("h_sumAmplitudeperLS1");
      HistNumBadChanDepth[2][1][2] = (TH1F*)hfile->Get("h_sumAmplitudeperLS2");
 
      HistNumBadChanDepth[2][2][1] = (TH1F*)hfile->Get("h_sumAmplitudeperLS3");
      HistNumBadChanDepth[2][2][2] = (TH1F*)hfile->Get("h_sumAmplitudeperLS4"); 
      HistNumBadChanDepth[2][2][3] = (TH1F*)hfile->Get("h_sumAmplitudeperLS5");
      
      HistNumBadChanDepth[2][3][4] = (TH1F*)hfile->Get("h_sumAmplitudeperLS8");
      
      HistNumBadChanDepth[2][4][1] = (TH1F*)hfile->Get("h_sumAmplitudeperLS6");
      HistNumBadChanDepth[2][4][2] = (TH1F*)hfile->Get("h_sumAmplitudeperLS7");    
       
      HistNumBadChanFull[2] = (TH1F*) HistNumBadChanDepth[2][1][1]->Clone();  
      
      HistCutNumBadChanDepth[2][1][1] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS1");
      HistCutNumBadChanDepth[2][1][2] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS2");
 
      HistCutNumBadChanDepth[2][2][1] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS3");
      HistCutNumBadChanDepth[2][2][2] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS4"); 
      HistCutNumBadChanDepth[2][2][3] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS5");
      
      HistCutNumBadChanDepth[2][3][4] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS8");
      
      HistCutNumBadChanDepth[2][4][1] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS6");
      HistCutNumBadChanDepth[2][4][2] = (TH1F*)hfile->Get("h_sumCutAmplitudeperLS7"); 
           
      
      HistNumChanDepth[2][1][1] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS1");     
      HistNumChanDepth[2][1][2] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS2"); 
 
      HistNumChanDepth[2][2][1] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS3");     
      HistNumChanDepth[2][2][2] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS4"); 
      HistNumChanDepth[2][2][3] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS5");     
      
      HistNumChanDepth[2][3][4] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS8"); 
      
      HistNumChanDepth[2][4][1] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS6");     
      HistNumChanDepth[2][4][2] = (TH1F*)hfile->Get("h_sum0AmplitudeperLS7");
      
      HistNumChanFull[2] = (TH1F*) HistNumChanDepth[2][1][1]->Clone();
//+++++++++++++++++++++++++++++  
// Ratio   
//+++++++++++++++++++++++++++++  
 
      HistNumBadChanDepth[3][1][1] = (TH1F*)hfile->Get("h_sumAmplperLS1");
      HistNumBadChanDepth[3][1][2] = (TH1F*)hfile->Get("h_sumAmplperLS2");
 
      HistNumBadChanDepth[3][2][1] = (TH1F*)hfile->Get("h_sumAmplperLS3");
      HistNumBadChanDepth[3][2][2] = (TH1F*)hfile->Get("h_sumAmplperLS4"); 
      HistNumBadChanDepth[3][2][3] = (TH1F*)hfile->Get("h_sumAmplperLS5");
      
      HistNumBadChanDepth[3][3][4] = (TH1F*)hfile->Get("h_sumAmplperLS8");
      
      HistNumBadChanDepth[3][4][1] = (TH1F*)hfile->Get("h_sumAmplperLS6");
      HistNumBadChanDepth[3][4][2] = (TH1F*)hfile->Get("h_sumAmplperLS7");    
      
      HistNumBadChanFull[3] = (TH1F*) HistNumBadChanDepth[3][1][1]->Clone();
      
      HistCutNumBadChanDepth[3][1][1] = (TH1F*)hfile->Get("h_sumCutAmplperLS1");
      HistCutNumBadChanDepth[3][1][2] = (TH1F*)hfile->Get("h_sumCutAmplperLS2");
 
      HistCutNumBadChanDepth[3][2][1] = (TH1F*)hfile->Get("h_sumCutAmplperLS3");
      HistCutNumBadChanDepth[3][2][2] = (TH1F*)hfile->Get("h_sumCutAmplperLS4"); 
      HistCutNumBadChanDepth[3][2][3] = (TH1F*)hfile->Get("h_sumCutAmplperLS5");
      
      HistCutNumBadChanDepth[3][3][4] = (TH1F*)hfile->Get("h_sumCutAmplperLS8");
      
      HistCutNumBadChanDepth[3][4][1] = (TH1F*)hfile->Get("h_sumCutAmplperLS6");
      HistCutNumBadChanDepth[3][4][2] = (TH1F*)hfile->Get("h_sumCutAmplperLS7");       
      
      
      HistNumChanDepth[3][1][1] = (TH1F*)hfile->Get("h_sum0AmplperLS1");     
      HistNumChanDepth[3][1][2] = (TH1F*)hfile->Get("h_sum0AmplperLS2"); 
 
      HistNumChanDepth[3][2][1] = (TH1F*)hfile->Get("h_sum0AmplperLS3");     
      HistNumChanDepth[3][2][2] = (TH1F*)hfile->Get("h_sum0AmplperLS4"); 
      HistNumChanDepth[3][2][3] = (TH1F*)hfile->Get("h_sum0AmplperLS5");     
      
      HistNumChanDepth[3][3][4] = (TH1F*)hfile->Get("h_sum0AmplperLS8"); 
      
      HistNumChanDepth[3][4][1] = (TH1F*)hfile->Get("h_sum0AmplperLS6");     
      HistNumChanDepth[3][4][2] = (TH1F*)hfile->Get("h_sum0AmplperLS7");
      
      HistNumChanFull[3] = (TH1F*) HistNumChanDepth[3][1][1]->Clone();
//+++++++++++++++++++++++++++++  
// Tmean   
//+++++++++++++++++++++++++++++  
 
      HistNumBadChanDepth[4][1][1] = (TH1F*)hfile->Get("h_sumTSmeanAperLS1");
      HistNumBadChanDepth[4][1][2] = (TH1F*)hfile->Get("h_sumTSmeanAperLS2");
 
      HistNumBadChanDepth[4][2][1] = (TH1F*)hfile->Get("h_sumTSmeanAperLS3");
      HistNumBadChanDepth[4][2][2] = (TH1F*)hfile->Get("h_sumTSmeanAperLS4"); 
      HistNumBadChanDepth[4][2][3] = (TH1F*)hfile->Get("h_sumTSmeanAperLS5");
      
      HistNumBadChanDepth[4][3][4] = (TH1F*)hfile->Get("h_sumTSmeanAperLS8");
     
      HistNumBadChanDepth[4][4][1] = (TH1F*)hfile->Get("h_sumTSmeanAperLS6");
      HistNumBadChanDepth[4][4][2] = (TH1F*)hfile->Get("h_sumTSmeanAperLS7");    
            
      HistNumBadChanFull[4] = (TH1F*) HistNumBadChanDepth[4][1][1]->Clone();
      
      HistCutNumBadChanDepth[4][1][1] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS1");
      HistCutNumBadChanDepth[4][1][2] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS2");
 
      HistCutNumBadChanDepth[4][2][1] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS3");
      HistCutNumBadChanDepth[4][2][2] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS4"); 
      HistCutNumBadChanDepth[4][2][3] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS5");
      
      HistCutNumBadChanDepth[4][3][4] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS8");
     
      HistCutNumBadChanDepth[4][4][1] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS6");
      HistCutNumBadChanDepth[4][4][2] = (TH1F*)hfile->Get("h_sumCutTSmeanAperLS7");       
      
      
      HistNumChanDepth[4][1][1] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS1");     
      HistNumChanDepth[4][1][2] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS2"); 
 
      HistNumChanDepth[4][2][1] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS3");     
      HistNumChanDepth[4][2][2] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS4"); 
      HistNumChanDepth[4][2][3] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS5");     
      
      HistNumChanDepth[4][3][4] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS8"); 
      
      HistNumChanDepth[4][4][1] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS6");     
      HistNumChanDepth[4][4][2] = (TH1F*)hfile->Get("h_sum0TSmeanAperLS7");
      
      HistNumChanFull[4] = (TH1F*) HistNumChanDepth[4][1][1]->Clone();
//+++++++++++++++++++++++++++++  
// Tmax   
//+++++++++++++++++++++++++++++  
 
      HistNumBadChanDepth[5][1][1] = (TH1F*)hfile->Get("h_sumTSmaxAperLS1");
      HistNumBadChanDepth[5][1][2] = (TH1F*)hfile->Get("h_sumTSmaxAperLS2");
 
      HistNumBadChanDepth[5][2][1] = (TH1F*)hfile->Get("h_sumTSmaxAperLS3");
      HistNumBadChanDepth[5][2][2] = (TH1F*)hfile->Get("h_sumTSmaxAperLS4"); 
      HistNumBadChanDepth[5][2][3] = (TH1F*)hfile->Get("h_sumTSmaxAperLS5");
      
      HistNumBadChanDepth[5][3][4] = (TH1F*)hfile->Get("h_sumTSmaxAperLS8");
      
      HistNumBadChanDepth[5][4][1] = (TH1F*)hfile->Get("h_sumTSmaxAperLS6");
      HistNumBadChanDepth[5][4][2] = (TH1F*)hfile->Get("h_sumTSmaxAperLS7");    
      
      HistNumBadChanFull[5] = (TH1F*) HistNumBadChanDepth[5][1][1]->Clone();
      
      HistCutNumBadChanDepth[5][1][1] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS1");
      HistCutNumBadChanDepth[5][1][2] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS2");
 
      HistCutNumBadChanDepth[5][2][1] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS3");
      HistCutNumBadChanDepth[5][2][2] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS4"); 
      HistCutNumBadChanDepth[5][2][3] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS5");
      
      HistCutNumBadChanDepth[5][3][4] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS8");
      
      HistCutNumBadChanDepth[5][4][1] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS6");
      HistCutNumBadChanDepth[5][4][2] = (TH1F*)hfile->Get("h_sumCutTSmaxAperLS7"); 
            
      
      HistNumChanDepth[5][1][1] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS1");     
      HistNumChanDepth[5][1][2] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS2"); 
 
      HistNumChanDepth[5][2][1] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS3");     
      HistNumChanDepth[5][2][2] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS4"); 
      HistNumChanDepth[5][2][3] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS5");     
      
      HistNumChanDepth[5][3][4] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS8"); 
      
      HistNumChanDepth[5][4][1] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS6");     
      HistNumChanDepth[5][4][2] = (TH1F*)hfile->Get("h_sum0TSmaxAperLS7");

      HistNumChanFull[5] = (TH1F*) HistNumChanDepth[5][1][1]->Clone();
      
      for (int test=0;test<=5;test++) { //Test: =0(CapIdErrors), =1(Amplitude), =2... 
	for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HO, 4-HF
	  if (sub==1) cHE->Divide(2,1);//HB
	  if (sub==2 && test!=1) cHE->Divide(3,1);//HE
	  if (sub==2 && test==1) {cNine->Clear();cNine->Divide(3,3);}//HE upgrade with new depthes 4,5,6,7 for Amplitude test only
	  if (sub==3) cHB->Divide(1,1);//HO
	  if (sub==4 && test!=1) cHE->Divide(2,1);//HF
	  if (sub==4 && test==1) {cFour1->Clear();cFour1->Divide(2,2);} // HF upgrade with new depthes 3 and 4 for Amplitude test only
	  
	  int kkkkkkmax = k_max[sub];
	  if ( (sub==4 || sub==2) && test==1) kkkkkkmax = k_maxHFupgrade[sub];
	  for (int k=k_min[sub];k<=kkkkkkmax;k++) {  //Depth 
	    if (sub==1) cHE->cd(k);//HB 
	    if (sub==2 && test!=1) cHE->cd(k);//HE
	    if (sub==2 && test==1) cNine->cd(k);//HE upgrade with new depthes 4,5,6,7 for Amplitude test only
	    if (sub==3) cHB->cd(k-3);//HO
	    if (sub==4 && test!=1) cHE->cd(k);//HF
	    if (sub==4 && test==1) cFour1->cd(k);// HF upgrade with new depthes 3 and 4 for Amplitude test only
	    gPad->SetGridy();
	    gPad->SetGridx();
	    //                gPad->SetLogy();      
	    
	    if(sub==1 && k== 1 ) {} else {
	      // use "else" because ...Full[test] are filled by estimastor for sub==1 && k== 1 at initialization of ...Full[test] variables
	      for (int x=1;x<=HistNumBadChanFull[test]->GetXaxis()->GetNbins();x++) {
		double ccc1 =  HistNumBadChanDepth[test][sub][k]->GetBinContent(x);
		HistNumBadChanFull[test]->SetBinContent(x,HistNumBadChanFull[test]->GetBinContent(x) + ccc1);
		double ccc2 =  HistNumChanDepth[test][sub][k]->GetBinContent(x);
		HistNumChanFull[test]->SetBinContent(x,HistNumChanFull[test]->GetBinContent(x) + ccc2);
	      }}//end x
	    
		// !!!!!!     change the sense of HistNumBadChanDepth: now it's averaged values(estimators)
	    HistNumBadChanDepth[test][sub][k]->Divide(HistNumBadChanDepth[test][sub][k],HistNumChanDepth[test][sub][k], 1, 1, "B");	
	    //		int myMaxLum= HistNumBadChanDepth[test][sub][k]->GetBinContent(HistNumBadChanDepth[test][sub][k]->GetMaximumBin());
	    //		cout<<"********************>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     myMaxLum = "<<myMaxLum<<"        MaxLum = "<<MaxLum<<endl;
	    HistNumBadChanDepth[test][sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
	    
	    
	    //   //    //   //   //   //   //   //   //   //   //   //   //   //   //   //   //  //
	    HistNumBadChanDepth[test][sub][k]->SetMarkerStyle(20);
	    HistNumBadChanDepth[test][sub][k]->SetMarkerSize(0.4);
	    HistNumBadChanDepth[test][sub][k]->GetYaxis()->SetLabelSize(0.04);
	    if (k == 1) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 1\b");
	    if (k == 2) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 2\b");
	    if (k == 3) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 3\b");
	    if (k == 4) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 4\b");
	    if (k == 5) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 5\b");
	    if (k == 6) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 6\b");
	    if (k == 7) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 7\b");
	    HistNumBadChanDepth[test][sub][k]->SetXTitle("LS \b");
	    if (test == 0) HistNumBadChanDepth[test][sub][k]->SetYTitle("<Number of bad channels> \b");
	    if (test != 0) HistNumBadChanDepth[test][sub][k]->SetYTitle("Averaged estimator \b");
	    HistNumBadChanDepth[test][sub][k]->SetMarkerColor(2);
	    HistNumBadChanDepth[test][sub][k]->SetLineColor(0);
	    //	    gPad->SetGridx();
	    gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();  
	    //	    if (test == 1) HistNumBadChanDepth[test][sub][k]->SetMinimum(0.1);
	    HistNumBadChanDepth[test][sub][k]->Draw("Error");
	    /*
		  if (k == 1) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 1\b");
		  if (k == 2) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 2\b");
		  if (k == 3) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 3\b");
		  if (k == 4) HistNumBadChanDepth[test][sub][k]->SetTitle("Depth 4\b");
		  HistNumBadChanDepth[test][sub][k]->SetXTitle("LS \b");
		  if (test == 0) HistNumBadChanDepth[test][sub][k]->SetYTitle("<Number of bad channels> \b");
		  if (test != 0) HistNumBadChanDepth[test][sub][k]->SetYTitle("Averaged estimator \b");
		  
		  if (MaxLum<=1000){
		  HistNumBadChanDepth[test][sub][k]->SetMarkerStyle(20);
		  HistNumBadChanDepth[test][sub][k]->SetMarkerSize(0.5);	
		  HistNumBadChanDepth[test][sub][k]->SetMarkerColor(2);
		  HistNumBadChanDepth[test][sub][k]->SetLineColor(0);
		  HistNumBadChanDepth[test][sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
		  HistNumBadChanDepth[test][sub][k]->Draw("P");
		  }
		  else{
		  HistNumBadChanDepth[test][sub][k]->SetLineColor(2);
		  HistNumBadChanDepth[test][sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
		  HistNumBadChanDepth[test][sub][k]->Draw("L");
		  }	
	    */
	    /*
	    float min_x[] = {0,10000};
	    float min_y[] = {(float)(Cut0[test][sub][k]),(float)(Cut0[test][sub][k])};
	    TGraph* MIN = new TGraph(2, min_x, min_y);
	    MIN->SetLineStyle(2);
	    MIN->SetLineColor(5);
	    MIN->SetLineWidth(2 + 100*100);
	    MIN->SetFillStyle(3005);
	    MIN->SetFillColor(5);
	    gPad->SetGridy();
	    gPad->SetGridx();
	    MIN->Draw("L");
*/

 
	    if (sub==1) { cHE->Modified();} 
	    if (sub==2 && test!=1) { cHE->Modified();}
	    if (sub==2 && test==1) { cNine->Modified();}  // HE upgrade
	    if (sub==3) { cHB->Modified();}
	    if (sub==4 && test!=1) { cHE->Modified();} 
	    if (sub==4 && test==1) { cFour1->Modified();}   // HF upgrade
	    
	  }    // k loop
	  
	  if (test==0){ 
	    if (sub==1) {cHE->Print("HistNBCMNHB.png"); cHE->Clear();} 
	    if (sub==2) {cHE->Print("HistNBCMNHE.png"); cHE->Clear();}
	    if (sub==3) {cHB->Print("HistNBCMNHO.png"); cHB->Clear();}
	    if (sub==4) {cHE->Print("HistNBCMNHF.png"); cHE->Clear();}  
	  } 
	  // Amplitude:	  
	  if (test==1){ 
	    if (sub==1) {cHE->Print("HistADCamplHB.png"); cHE->Clear();} 
	    //	    if (sub==2) {cHE->Print("HistADCamplHE.png"); cHE->Clear();}
	    if (sub==2) {cNine->Print("HistADCamplHE.png"); cNine->Clear();}  // HE upgrade
	    if (sub==3) {cHB->Print("HistADCamplHO.png"); cHB->Clear();}
	    if (sub==4) {cFour1->Print("HistADCamplHF.png"); cFour1->Clear();}  // HF upgrade
	  } 
	  if (test==2){ 
	    if (sub==1) {cHE->Print("HistWidthHB.png"); cHE->Clear();} 
	    if (sub==2) {cHE->Print("HistWidthHE.png"); cHE->Clear();}
	    if (sub==3) {cHB->Print("HistWidthHO.png"); cHB->Clear();}
	    if (sub==4) {cHE->Print("HistWidthHF.png"); cHE->Clear();}  
	  } 
	  if (test==3){ 
	    if (sub==1) {cHE->Print("HistRatioHB.png"); cHE->Clear();} 
	    if (sub==2) {cHE->Print("HistRatioHE.png"); cHE->Clear();}
	    if (sub==3) {cHB->Print("HistRatioHO.png"); cHB->Clear();}
	    if (sub==4) {cHE->Print("HistRatioHF.png"); cHE->Clear();}  
	  } 
	  if (test==4){ 
	    if (sub==1) {cHE->Print("HistTmeanHB.png"); cHE->Clear();} 
	    if (sub==2) {cHE->Print("HistTmeanHE.png"); cHE->Clear();}
	    if (sub==3) {cHB->Print("HistTmeanHO.png"); cHB->Clear();}
	    if (sub==4) {cHE->Print("HistTmeanHF.png"); cHE->Clear();}  
	  } 
	  if (test==5){ 
	    if (sub==1) {cHE->Print("HistTmaxHB.png"); cHE->Clear();} 
	    if (sub==2) {cHE->Print("HistTmaxHE.png"); cHE->Clear();}
	    if (sub==3) {cHB->Print("HistTmaxHO.png"); cHB->Clear();}
	    if (sub==4) {cHE->Print("HistTmaxHF.png"); cHE->Clear();}  
	  } 
	}// end sub 
	///////////////////////////////////////////// other cases:
	if(test==1){
	  for (int x=1;x<=HistNumChanFull[6]->GetXaxis()->GetNbins();x++) {
	    
	    HistNumChanFull[6]->SetBinContent(x,0.0 );
	    int depthsubcount = 0.;
	    for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HO, 4-HF
	      int kkkkkkmax = k_max[sub];
	      if ( sub==4 || sub==2) kkkkkkmax = k_maxHFupgrade[sub];
	      for (int k=k_min[sub];k<=kkkkkkmax;k++) {  //Depth 
		// line below is temporary, just to avoid contribution of HEP(M)17 in depthes 4,5,6,7 but keep in depthes 1,2,3
		if(sub==2 && k>3 ) break;
		depthsubcount++;
		double ccc1 =  HistNumBadChanDepth[test][sub][k]->GetBinContent(x);
		HistNumChanFull[6]->SetBinContent(x,HistNumChanFull[6]->GetBinContent(x) + ccc1);
	      }//depth
	    }//sub
	    if(depthsubcount > 0.) {HistNumChanFull[6]->SetBinContent(x, (HistNumChanFull[6]->GetBinContent(x))/depthsubcount);}
	    else{HistNumChanFull[6]->SetBinContent(x, (HistNumChanFull[6]->GetBinContent(x))/8.);}
	  }//x
	}//test=1
	////////////  //////   //////  //////  ////// //////
	if (test!=1) {cHB->Divide(1,1);cHB->cd(1);}else {cHE->Divide(2,1);cHE->cd(1);}
	HistNumBadChanFull[test]->Divide(HistNumBadChanFull[test],HistNumChanFull[test], 1, 1, "B");	
	TH1F* kfitq = new TH1F("kfitq","", MaxLum, 1., MaxLum+1.);
	int nx = kfitq->GetXaxis()->GetNbins();
	for (int i=1;i<=nx;i++) {
	  double ccc1 =  HistNumBadChanFull[test]->GetBinContent(i);
	  if(ccc1>0.) {kfitq->Fill(float(i), ccc1);kfitq->SetBinError(float(i),0.01);}
	}
	kfitq->SetMarkerStyle(20);
	kfitq->SetMarkerSize(0.4);
	kfitq->GetYaxis()->SetLabelSize(0.04);
	if(test == 0) kfitq->SetTitle("Average Nbch for whole Hcal \b");
	if(test != 0) kfitq->SetTitle("Averaged estimator for whole Hcal \b");
	kfitq->SetXTitle("LS \b");
	if (test == 0) kfitq->SetYTitle("<Number of bad channels> \b");
	if (test != 0) kfitq->SetYTitle("Averaged estimator \b");
	kfitq->SetMarkerColor(2);
	kfitq->SetLineColor(0);
	gPad->SetGridx();
	kfitq->Draw("Error");
	/* 
	   HistNumBadChanFull[test]->SetMarkerStyle(20);
	   HistNumBadChanFull[test]->SetMarkerSize(0.8);
	   HistNumBadChanFull[test]->SetTitle("Averaged estimator for whole Hcal \b");
	   HistNumBadChanFull[test]->SetXTitle("LS \b");
	   if (test == 0) HistNumBadChanFull[test]->SetYTitle("<Number of bad channels> \b");
	   if (test != 0) HistNumBadChanFull[test]->SetYTitle("Averaged estimator \b");
	   if (MaxLum<=1000){
	   HistNumBadChanFull[test]->SetMarkerColor(1);
	   HistNumBadChanFull[test]->SetLineColor(0);
	   HistNumBadChanFull[test]->Draw("P"); 
	   }
	   else {
	   HistNumBadChanFull[test]->SetLineColor(1);
	   HistNumBadChanFull[test]->Draw("L"); 
	   }
	*/
	if(test == 1) {
	  cHE->cd(2);
	  TH1F* lpuio = new TH1F("lpuio","", MaxLum, 1., MaxLum+1.);
	  int nx = lpuio->GetXaxis()->GetNbins();
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  HistNumChanFull[6]->GetBinContent(i);
	    if(ccc1>0.) {lpuio->Fill(float(i), ccc1);lpuio->SetBinError(float(i),0.01);}
	  }
	  lpuio->SetMarkerStyle(20);
	  lpuio->SetMarkerSize(0.4);
	  lpuio->GetYaxis()->SetLabelSize(0.04);
	  lpuio->SetTitle("Mean of Averaged Amplitudes over all Hcal sub-detectors \b");
	  lpuio->SetXTitle("LS \b");
	  lpuio->SetYTitle("Mean of Averaged estimator \b");
	  lpuio->SetMarkerColor(2);
	  lpuio->SetLineColor(0);
	  gPad->SetGridx();
	  lpuio->Draw("Error");
	}
	if (test==0) {cHB->Print("HistCapID.png"); cHB->Clear();}
	if (test==1) {cHE->Print("HistADCAmpl.png"); cHE->Clear();}
	if (test==2) {cHB->Print("HistWidth.png"); cHB->Clear();}
	if (test==3) {cHB->Print("HistRatio.png"); cHB->Clear();}
	if (test==4) {cHB->Print("HistTmean.png"); cHB->Clear();}
	if (test==5) {cHB->Print("HistTmax.png"); cHB->Clear();}
	
    // clean-up
    if (kfitq) delete kfitq;
    }//end test	          
      
//================================================================================================================================ 
 
 
  
 
 
 
//=======================================================================================================333
//CapID 1-d histograms

      TH1F *HistAbnormNumBadChanDepth[5][5];    // 1d histogramm for subdet, depth 


//+++++++++++++++++++++++++++++  
// Abnormal Bad Channels Rate of Cap ID errors  first set of histograms   
//+++++++++++++++++++++++++++++  
 
      HistAbnormNumBadChanDepth[1][1] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth1_HB");
      HistAbnormNumBadChanDepth[1][2] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth2_HB");
      HistAbnormNumBadChanDepth[2][1] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth1_HE");
      HistAbnormNumBadChanDepth[2][2] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth2_HE");
      HistAbnormNumBadChanDepth[2][3] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth3_HE");
      HistAbnormNumBadChanDepth[3][4] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth4_HO");
      HistAbnormNumBadChanDepth[4][1] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth1_HF");
      HistAbnormNumBadChanDepth[4][2] = (TH1F*)hfile->Get("h_runnbadchannelsC_depth2_HF");
                                                           
      for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
	if (sub==1) cHB->Divide(2,1);
	if (sub==2) cHE->Divide(3,1);
	if (sub==3) cONE->Divide(1,1);
	if (sub==4) cHB->Divide(2,1);
	for (int k=k_min[sub];k<=k_max[sub];k++) {  //Depth 
	  if (sub==1) cHB->cd(k); 
	  if (sub==2) cHE->cd(k);
	  if (sub==3) cONE->cd(k-3);
	  if (sub==4) cHB->cd(k);
	  gPad->SetGridy();
	  gPad->SetGridx();
	  //  gPad->SetLogy();      
	  HistAbnormNumBadChanDepth[sub][k]->Divide(HistAbnormNumBadChanDepth[sub][k],HistNumChanDepth[0][sub][k], 1, 1, "B");		
	  if (k == 1)  HistAbnormNumBadChanDepth[sub][k]->SetTitle("Depth 1\b");
	  if (k == 2)  HistAbnormNumBadChanDepth[sub][k]->SetTitle("Depth 2\b");
	  if (k == 3)  HistAbnormNumBadChanDepth[sub][k]->SetTitle("Depth 3\b");
	  if (k == 4)  HistAbnormNumBadChanDepth[sub][k]->SetTitle("Depth 4\b");
	  HistAbnormNumBadChanDepth[sub][k]->SetXTitle("LS \b");
	  HistAbnormNumBadChanDepth[sub][k]->SetYTitle("< Number of bad channels > \b");
	  if (MaxLum<=1000){
	     HistAbnormNumBadChanDepth[sub][k]->SetMarkerStyle(20);
	     HistAbnormNumBadChanDepth[sub][k]->SetMarkerSize(0.5);
             HistAbnormNumBadChanDepth[sub][k]->SetMarkerColor(1);
             HistAbnormNumBadChanDepth[sub][k]->SetLineColor(0);
             HistAbnormNumBadChanDepth[sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
             HistAbnormNumBadChanDepth[sub][k]->Draw("P");
	  }
	  else {
	     HistAbnormNumBadChanDepth[sub][k]->SetLineColor(1);
             HistAbnormNumBadChanDepth[sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
             HistAbnormNumBadChanDepth[sub][k]->Draw("L");
	  }	  
	 }     
	        if (sub==1) {cHB->Print("Hist_CAPID_Abnorm_HB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("Hist_CAPID_Abnorm_HE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("Hist_CAPID_Abnorm_HO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("Hist_CAPID_Abnorm_HF.png"); cHB->Clear();}  	    	    
         }// end sub 



//+++++++++++++++++++++++++++++  
// Portions of bad channels events identified by Cap ID errors   third set of histograms 
//+++++++++++++++++++++++++++++  

      TH1F *HistPortBadEventsDepth[5][5];    // 1d histogramm for subdet, depth 

      HistPortBadEventsDepth[1][1] = (TH1F*)hfile->Get("h_runbadrateC_depth1_HB");
      HistPortBadEventsDepth[1][2] = (TH1F*)hfile->Get("h_runbadrateC_depth2_HB");
      HistPortBadEventsDepth[2][1] = (TH1F*)hfile->Get("h_runbadrateC_depth1_HE");
      HistPortBadEventsDepth[2][2] = (TH1F*)hfile->Get("h_runbadrateC_depth2_HE");
      HistPortBadEventsDepth[2][3] = (TH1F*)hfile->Get("h_runbadrateC_depth3_HE");
      HistPortBadEventsDepth[3][4] = (TH1F*)hfile->Get("h_runbadrateC_depth4_HO");
      HistPortBadEventsDepth[4][1] = (TH1F*)hfile->Get("h_runbadrateC_depth1_HF");
      HistPortBadEventsDepth[4][2] = (TH1F*)hfile->Get("h_runbadrateC_depth2_HF");
     
      
      TH1F *HistNumRateDepth[5][5];
      HistNumRateDepth[1][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HB");
      HistNumRateDepth[1][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HB");
      HistNumRateDepth[2][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HE");
      HistNumRateDepth[2][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HE");
      HistNumRateDepth[2][3] = (TH1F*)hfile->Get("h_runbadrate0_depth3_HE");
      HistNumRateDepth[3][4] = (TH1F*)hfile->Get("h_runbadrate0_depth4_HO");
      HistNumRateDepth[4][1] = (TH1F*)hfile->Get("h_runbadrate0_depth1_HF");
      HistNumRateDepth[4][2] = (TH1F*)hfile->Get("h_runbadrate0_depth2_HF");
     
      for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
	if (sub==1) cHB->Divide(2,1);
	if (sub==2) cHE->Divide(3,1);
	if (sub==3) cONE->Divide(1,1);
	if (sub==4) cHB->Divide(2,1);
	for (int k=k_min[sub];k<=k_max[sub];k++) {  //Depth 
	  if (sub==1) cHB->cd(k); 
	  if (sub==2) cHE->cd(k);
	  if (sub==3) cONE->cd(k-3);
	  if (sub==4) cHB->cd(k);
	  gPad->SetGridy();
	  gPad->SetGridx();
	  //  gPad->SetLogy();      
 	  HistPortBadEventsDepth[sub][k]->Divide(HistPortBadEventsDepth[sub][k],HistNumRateDepth[sub][k], 1, 1, "B");
	 		
	  if (k == 1)  HistPortBadEventsDepth[sub][k]->SetTitle("Depth 1\b");
	  if (k == 2)  HistPortBadEventsDepth[sub][k]->SetTitle("Depth 2\b");
	  if (k == 3)  HistPortBadEventsDepth[sub][k]->SetTitle("Depth 3\b");
	  if (k == 4)  HistPortBadEventsDepth[sub][k]->SetTitle("Depth 4\b");
	  HistPortBadEventsDepth[sub][k]->SetXTitle("LS \b");
	  HistPortBadEventsDepth[sub][k]->SetYTitle("< Number of bad channels > \b");
	  if (MaxLum<=1000){
	     HistPortBadEventsDepth[sub][k]->SetMarkerStyle(20);
	     HistPortBadEventsDepth[sub][k]->SetMarkerSize(0.5);	  
	     HistPortBadEventsDepth[sub][k]->SetMarkerColor(1);
	     HistPortBadEventsDepth[sub][k]->SetLineColor(0);
	     HistPortBadEventsDepth[sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
	     HistPortBadEventsDepth[sub][k]->Draw("P");
	  }
	  else {
	     HistPortBadEventsDepth[sub][k]->SetLineColor(1);
	     HistPortBadEventsDepth[sub][k]->GetXaxis()->SetRangeUser(0, MaxLum);
	     HistPortBadEventsDepth[sub][k]->Draw("L");
	  }
	}     
	        if (sub==1) {cHB->Print("HistPortHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("HistPortHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("HistPortHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("HistPortHF.png"); cHB->Clear();}  	    	    
         }// end sub 

//================================================================================================================================  

//+++++++++++++++++++++++++++++  
// Number of bad channels events identified by Cap ID errors   third set of histograms 
//+++++++++++++++++++++++++++++  

      TH1F *HistNBadChsDepth[5][5];    // 1d histogramm for subdet, depth 

      HistNBadChsDepth[1][1] = (TH1F*)hfile->Get("h_nbadchannels_depth1_HB");
      HistNBadChsDepth[1][2] = (TH1F*)hfile->Get("h_nbadchannels_depth2_HB");
      HistNBadChsDepth[2][1] = (TH1F*)hfile->Get("h_nbadchannels_depth1_HE");
      HistNBadChsDepth[2][2] = (TH1F*)hfile->Get("h_nbadchannels_depth2_HE");
      HistNBadChsDepth[2][3] = (TH1F*)hfile->Get("h_nbadchannels_depth3_HE");
      HistNBadChsDepth[3][4] = (TH1F*)hfile->Get("h_nbadchannels_depth4_HO");
      HistNBadChsDepth[4][1] = (TH1F*)hfile->Get("h_nbadchannels_depth1_HF");
      HistNBadChsDepth[4][2] = (TH1F*)hfile->Get("h_nbadchannels_depth2_HF");
     
      for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
	if (sub==1) cHB->Divide(2,1);
	if (sub==2) cHE->Divide(3,1);
	if (sub==3) cONE->Divide(1,1);
	if (sub==4) cHB->Divide(2,1);
	for (int k=k_min[sub];k<=k_max[sub];k++) {  //Depth 
	  if (sub==1) cHB->cd(k); 
	  if (sub==2) cHE->cd(k);
	  if (sub==3) cONE->cd(k-3);
	  if (sub==4) cHB->cd(k);
	  gPad->SetGridy();
	  gPad->SetGridx();
	  gPad->SetLogy();      
	 		
	  if (k == 1)  HistNBadChsDepth[sub][k]->SetTitle("Depth 1\b");
	  if (k == 2)  HistNBadChsDepth[sub][k]->SetTitle("Depth 2\b");
	  if (k == 3)  HistNBadChsDepth[sub][k]->SetTitle("Depth 3\b");
	  if (k == 4)  HistNBadChsDepth[sub][k]->SetTitle("Depth 4\b");
	  HistNBadChsDepth[sub][k]->SetXTitle("Number of bad channels\b");
	  HistNBadChsDepth[sub][k]->SetYTitle("Number of events\b");
//	     HistNBadChsDepth[sub][k]->SetMarkerStyle(20);
//	     HistNBadChsDepth[sub][k]->SetMarkerSize(0.5);	  
//	     HistNBadChsDepth[sub][k]->SetMarkerColor(1);
//	     HistNBadChsDepth[sub][k]->SetLineColor(0);
	     HistNBadChsDepth[sub][k]->Draw("");
	}     
	        if (sub==1) {cHB->Print("HistNBadChsHB.png"); cHB->Clear();} 
                if (sub==2) {cHE->Print("HistNBadChsHE.png"); cHE->Clear();}
                if (sub==3) {cONE->Print("HistNBadChsHO.png"); cONE->Clear();}
                if (sub==4) {cHB->Print("HistNBadChsHF.png"); cHB->Clear();}  	    	    
         }// end sub 


//====================================================================== HB                    :
//====================================================================== HB                    :
//====================================================================== HB                    :
// Special test of errors type A and B in HB
// AZ 08.02.2016

  int flagErrAB_HB[2];
  flagErrAB_HB[0]=-1;
  flagErrAB_HB[1]=-1;
  double avedelta_HB = 0.;
  int lastLumiBin_HB=-1;
  int LSofFirstErrB_HB = -1;
  {
    const int specCountA=4;
    const int specColors[specCountA] = { 1, 2, 3, 4 };
    const TString hnames[specCountA][2] =
      { { "h_sumADCAmplperLS1_P1", "h_sum0ADCAmplperLS1_P1" },
	{ "h_sumADCAmplperLS1_P2", "h_sum0ADCAmplperLS1_P2" },
	{ "h_sumADCAmplperLS1_M1", "h_sum0ADCAmplperLS1_M1" },
	{ "h_sumADCAmplperLS1_M2", "h_sum0ADCAmplperLS1_M2" } };

    std::vector<TH1F*> hV;
    THStack *hs= new THStack("hs","ADCAmplerLS1");
    cHB->Clear();
    //    cHB->cd();
    cHB->Divide(2,1);
    cHB->cd(1);

    ///////////////////////////////////////////////////////////////////////////
    for (int i=0; i<specCountA; i++) {
      if (1) std::cout << "debugger: errA_HB : get histos for i=" << i  << " " << hnames[i][0] << " and " << hnames[i][1] << "\n";
      TH1F *h1= (TH1F*)hfile->Get(hnames[i][0]);
      TH1F *h0= (TH1F*)hfile->Get(hnames[i][1]);
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hnames[i][0] << "\n";
	  ptext->AddText(hnames[i][0]);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hnames[i][1] << "\n";
	  ptext->AddText(hnames[i][1]);
	}
	ptext->Draw();
	continue;
      }
      TH1F *hERT1orig= (TH1F*)h1->Clone(Form("ERT1orig_%d",i));
      hERT1orig->Divide(h1, h0, 1,1, "B");

      if ((lastLumiBin_HB<0) && (i==0)) {
	for (int ibin=hERT1orig->GetNbinsX(); ibin>=1; ibin--) {
	  if (hERT1orig->GetBinContent(ibin)==0) lastLumiBin_HB=ibin;
	  else break;
	}
	lastLumiBin_HB+=3; // show more bins
	if (lastLumiBin_HB >= hERT1orig->GetNbinsX()) lastLumiBin_HB=-1;
      }
      TH1F *hERT1=NULL;
      if (lastLumiBin_HB>1) {
	if (!copyContents(&hERT1,Form("ERT1_%d",i),"", hERT1orig,lastLumiBin_HB)) {
	  std::cout << "code failed"<<std::endl;
	  gSystem->Exit(1);
	}
      }
      else hERT1=hERT1orig;

      hERT1->GetXaxis()->SetTitle("<ADCAmpl> per LS HB: black-P1, red-P2,green-M1,blue-M2");
      hV.push_back(hERT1);
      hERT1->SetMarkerStyle(20);
      hERT1->SetMarkerSize(0.4);
      hERT1->SetXTitle("<A>(ev.in LS & ch.) - HB P1     -    iLS \b");
      hERT1->SetMarkerColor(specColors[i]);
      hERT1->SetLineColor(0);
      hs->Add(hERT1);
      delete h1;
      delete h0;
      if (hERT1!=hERT1orig) delete hERT1orig;
    } /////////////////////////////////////////////////////////////////////////
    hs->Draw("LPE1 nostack"); 
    cHB->Update(); // activate the axes
    hs->GetXaxis()->SetTitle("<A> per LS: black-P1, red-P2,green-M1,blue-M2");
    hs->Draw("LPE1 nostack");
    gPad->SetGridy();
    /////////////////////////////////////////////////////////////////////////////////////////

    // AZ corrections 08.02.2016
    cHB->cd(2);
    TH1F* diff = new TH1F("diff","", 100, 0., 4.);

    if (int(hV.size())==specCountA) {
      flagErrAB_HB[0]=0;// If we have the expected number of histograms, set the flag
      double sumdelta = 0.;
      int nnndelta = 0;
      for (int ibin=1; ibin<=hV[0]->GetNbinsX(); ibin++) {
	double delta = 0.; 
	double maxdelta = 0.; 
	for (unsigned int i=0; i<hV.size(); i++) {
	  const TH1F* hi= hV[i];
	  for (unsigned int j=1; j<hV.size(); j++) {
	    const TH1F* hj= hV[j];
	    delta = fabs(hi->GetBinContent(ibin) - hj->GetBinContent(ibin));
	    if(delta > maxdelta) maxdelta=delta;
	  }//for
	}//for
	if(maxdelta> 0.) {
	  diff->Fill(maxdelta);
	  sumdelta+=maxdelta;
	  nnndelta++;
	}
      }//for ibin
      //      avedelta_HB = sumdelta/hV[0]->GetNbinsX();
      avedelta_HB = sumdelta/nnndelta;
      std::cout << "******************>>>>>>      ErrA_HB:  avedelta_HB = " << avedelta_HB <<std::endl;
      if (avedelta_HB>0.24 || (avedelta_HB<0.14 && avedelta_HB>0.)) {
	flagErrAB_HB[0]=1;
      }//if
    }//hV.size
    diff->SetMarkerStyle(20);
    diff->SetMarkerSize(0.8);
    diff->SetXTitle("max difference \b");
    diff->SetMarkerColor(2);
    diff->SetLineColor(0);
    gPad->SetGridx();
    gPad->SetLogy();
    diff->Draw("Error");
    /////////////////////////////////////////////////////////////////////////
    cHB->Update();
    cHB->Print("HistErrA_HB.png");
    cHB->Clear();
    /////////////////////////////////////////////////////////////////////////
    
    // clean-up
    if (diff) delete diff;
    for (unsigned int i=0; i<hV.size(); i++) delete hV[i];
  } // ErrorA in HB


  ///////////////////////////////////////////////////////////////////////// errors B:


  { // errors type B
    const int specCountB=4;
    const TString hnames[specCountB][2] =
      { { "h_2DsumErrorBLS1", "h_2D0sumErrorBLS1" },
	{ "h_sumErrorBperLS1", "h_sum0ErrorBperLS1" },
	{ "h_2DsumErrorBLS2", "h_2D0sumErrorBLS2" },
	{ "h_sumErrorBperLS2", "h_sum0ErrorBperLS2" } };

    for (int depth=1; depth<=2; depth++) {

      cHB->Clear();
      cHB->Divide(2,1);
      cHB->cd(1);

      TH1F *hRate2orig= NULL;
      TH2F *h2Cefz6= NULL;
      TString hname1= hnames[2*depth-2][0];
      TString hname0= hnames[2*depth-2][1];
      TH2F *twod1= (TH2F*)hfile->Get(hname1);
      TH2F *twod0= (TH2F*)hfile->Get(hname0);
      if (1) std::cout << "debugger: errB_HB depth=" << depth << ". get 2D histos "  << hname1 << " and " << hname0 << "\n";
      if (!twod1 || !twod0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histos");
	if (!twod1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!twod0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	h2Cefz6= (TH2F*)twod1->Clone(Form("Cefz6_%d",depth));
	h2Cefz6->SetTitle(Form("HB Depth %d \b",depth));
	h2Cefz6->Divide(twod1,twod0, 1, 1, "B");

	gPad->SetGridy();
	gPad->SetGridx();
	gPad->SetLogz();
	h2Cefz6->SetTitle(Form("Depth %d \b",depth));
	h2Cefz6->SetMarkerStyle(20);
	h2Cefz6->SetMarkerSize(0.4);
	//	h2Cefz6->GetZaxis()->SetLabelSize(0.04);
	h2Cefz6->SetXTitle("#eta \b");
	h2Cefz6->SetYTitle("#phi \b");
	h2Cefz6->SetZTitle(Form("<ErrorB>  - HB Depth%d \b",depth));
	h2Cefz6->SetMarkerColor(2);
	h2Cefz6->SetLineColor(2);
	h2Cefz6->Draw("COLZ");

	delete twod1;
	delete twod0;
      } // histos ok

      cHB->cd(2);
      hname1=hnames[2*depth-1][0];
      hname0=hnames[2*depth-1][1];
      TH1F *h1= (TH1F*)hfile->Get(hname1);
      TH1F *h0= (TH1F*)hfile->Get(hname0);
      if (1) std::cout << "errB_HB depth=" << depth << ". get 2D histos "
		       << hname1 << " and " << hname0 << "\n";
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	gPad->SetGridx();
	gPad->SetGridy();
	//	gPad->SetLogy();
	hRate2orig = (TH1F*)h1->Clone(Form("Rate2orig_%d",depth));
	hRate2orig->Divide(h1,h0, 1, 1, "B");

	TH1F* hRate2=NULL;
	if (lastLumiBin_HB>1) {
	  if (!copyContents(&hRate2,Form("Rate2_%d",depth),"",hRate2orig,lastLumiBin_HB)) {
	    std::cout << "code failed" << std::endl;
	    gSystem->Exit(1);
	  }
	}
	else hRate2=hRate2orig;

	hRate2->SetTitle(Form("Depth %d \b",depth));
	hRate2->SetMarkerStyle(20);
	hRate2->SetMarkerSize(0.8);
	//	hRate2->GetZaxis()->SetLabelSize(0.04);
	hRate2->SetXTitle(Form("<ErrorB>(ev.in LS & ch.) - HB depth%d -    iLS \b",depth));
	hRate2->SetMarkerColor(2);
	hRate2->SetLineColor(0);
	hRate2->Draw("Error");


	if(LSofFirstErrB_HB == -1) {
	  int nx = hRate2->GetXaxis()->GetNbins();
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  hRate2->GetBinContent(i);
	    if(ccc1>0.) {
	      cout<<"****************>>>>>>>>>>> ErrB_HB bad LS start at iLS = "<<i<<" with rate = "<< ccc1 <<endl;
	      LSofFirstErrB_HB = i;
	      break;
	    }
	  }
	}	
	

	delete h1;
	delete h0;
	if (hRate2!=hRate2orig) { delete hRate2orig; hRate2orig=hRate2; }
      }

      cHB->Update();
      cHB->Print(Form("HistErrB_HB_%d.png",depth));
      cHB->Clear();
      if (h2Cefz6) delete h2Cefz6;
      if (hRate2orig) delete hRate2orig;
    }
  } // ErrorsB in HB


//====================================================================== HE                    :
//====================================================================== HE                    :
//====================================================================== HE                    :
// Special test of errors type A and B in HE
// AZ 08.02.2016

  int flagErrAB_HE[2];
  flagErrAB_HE[0]=-1;
  flagErrAB_HE[1]=-1;
  double avedelta_HE = 0.;
  int lastLumiBin_HE=-1;
  int LSofFirstErrB_HE = -1;
  {
    const int specCountA=4;
    const int specColors[specCountA] = { 1, 2, 3, 4 };
    const TString hnames[specCountA][2] =
      { { "h_sumADCAmplperLS3_P1", "h_sum0ADCAmplperLS3_P1" },
	{ "h_sumADCAmplperLS3_P2", "h_sum0ADCAmplperLS3_P2" },
	{ "h_sumADCAmplperLS3_M1", "h_sum0ADCAmplperLS3_M1" },
	{ "h_sumADCAmplperLS3_M2", "h_sum0ADCAmplperLS3_M2" } };

    std::vector<TH1F*> hV;
    THStack *hs= new THStack("hs","ADCAmplerLS1");
    cHB->Clear();
    //    cHB->cd();
    cHB->Divide(2,1);
    cHB->cd(1);

    ///////////////////////////////////////////////////////////////////////////
    for (int i=0; i<specCountA; i++) {
      if (1) std::cout << "debugger: errA_HE : get histos for i=" << i  << " " << hnames[i][0] << " and " << hnames[i][1] << "\n";
      TH1F *h1= (TH1F*)hfile->Get(hnames[i][0]);
      TH1F *h0= (TH1F*)hfile->Get(hnames[i][1]);
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hnames[i][0] << "\n";
	  ptext->AddText(hnames[i][0]);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hnames[i][1] << "\n";
	  ptext->AddText(hnames[i][1]);
	}
	ptext->Draw();
	continue;
      }
      TH1F *hERT1orig= (TH1F*)h1->Clone(Form("ERT1orig_%d",i));
      hERT1orig->Divide(h1, h0, 1,1, "B");

      if ((lastLumiBin_HE<0) && (i==0)) {
	for (int ibin=hERT1orig->GetNbinsX(); ibin>=1; ibin--) {
	  if (hERT1orig->GetBinContent(ibin)==0) lastLumiBin_HE=ibin;
	  else break;
	}
	lastLumiBin_HE+=3; // show more bins
	if (lastLumiBin_HE >= hERT1orig->GetNbinsX()) lastLumiBin_HE=-1;
      }
      TH1F *hERT1=NULL;
      if (lastLumiBin_HE>1) {
	if (!copyContents(&hERT1,Form("ERT1_%d",i),"", hERT1orig,lastLumiBin_HE)) {
	  std::cout << "code failed"<<std::endl;
	  gSystem->Exit(1);
	}
      }
      else hERT1=hERT1orig;

      hERT1->GetXaxis()->SetTitle("<ADCAmpl> per LS HE: black-P1, red-P2,green-M1,blue-M2");
      hV.push_back(hERT1);
      hERT1->SetMarkerStyle(20);
      hERT1->SetMarkerSize(0.4);
      hERT1->SetXTitle("<A>(ev.in LS & ch.) - HE P1     -    iLS \b");
      hERT1->SetMarkerColor(specColors[i]);
      hERT1->SetLineColor(0);
      hs->Add(hERT1);
      delete h1;
      delete h0;
      if (hERT1!=hERT1orig) delete hERT1orig;
    } /////////////////////////////////////////////////////////////////////////
    hs->Draw("LPE1 nostack"); 
    cHB->Update(); // activate the axes
    hs->GetXaxis()->SetTitle("<A> per LS: black-P1, red-P2,green-M1,blue-M2");
    hs->Draw("LPE1 nostack");
    gPad->SetGridy();
    /////////////////////////////////////////////////////////////////////////////////////////

    // AZ corrections 08.02.2016
    cHB->cd(2);
    TH1F* diff = new TH1F("diff","", 100, 0., 4.);

    if (int(hV.size())==specCountA) {
      flagErrAB_HE[0]=0;// If we have the expected number of histograms, set the flag
      double sumdelta = 0.;
      int nnndelta = 0;
      for (int ibin=1; ibin<=hV[0]->GetNbinsX(); ibin++) {
	double delta = 0.; 
	double maxdelta = 0.; 
	for (unsigned int i=0; i<hV.size(); i++) {
	  const TH1F* hi= hV[i];
	  for (unsigned int j=1; j<hV.size(); j++) {
	    const TH1F* hj= hV[j];
	    delta = fabs(hi->GetBinContent(ibin) - hj->GetBinContent(ibin));
	    if(delta > maxdelta) maxdelta=delta;
	  }//for
	}//for
	if(maxdelta> 0.) {
	  diff->Fill(maxdelta);
	  sumdelta+=maxdelta;
	  nnndelta++;
	}
      }//for ibin
      //      avedelta_HE = sumdelta/hV[0]->GetNbinsX();
      avedelta_HE = sumdelta/nnndelta;
      std::cout << "******************>>>>>>      ErrA_HE:  avedelta_HE = " << avedelta_HE <<std::endl;
      if (avedelta_HE>1.1 || (avedelta_HE<0.5 && avedelta_HE>0.)) {
	flagErrAB_HE[0]=1;
      }//if
    }//hV.size
    diff->SetMarkerStyle(20);
    diff->SetMarkerSize(0.8);
    diff->SetXTitle("max difference \b");
    diff->SetMarkerColor(2);
    diff->SetLineColor(0);
    gPad->SetGridx();
    gPad->SetLogy();
    diff->Draw("Error");
    /////////////////////////////////////////////////////////////////////////
    cHB->Update();
    cHB->Print("HistErrA_HE.png");
    cHB->Clear();
    /////////////////////////////////////////////////////////////////////////
    
    // clean-up
    if (diff) delete diff;
    for (unsigned int i=0; i<hV.size(); i++) delete hV[i];
  } // ErrorA in HE


  ///////////////////////////////////////////////////////////////////////// errors B:


  { // errors type B
    const int specCountB=6;
    const TString hnames[specCountB][2] =
      { { "h_2DsumErrorBLS3", "h_2D0sumErrorBLS3" },
	{ "h_sumErrorBperLS3", "h_sum0ErrorBperLS3" },
	{ "h_2DsumErrorBLS4", "h_2D0sumErrorBLS4" },
	{ "h_sumErrorBperLS4", "h_sum0ErrorBperLS4" },
	{ "h_2DsumErrorBLS5", "h_2D0sumErrorBLS5" },
	{ "h_sumErrorBperLS5", "h_sum0ErrorBperLS5" } };

    for (int depth=1; depth<=3; depth++) {

      cHB->Clear();
      cHB->Divide(2,1);
      cHB->cd(1);

      TH1F *hRate2orig= NULL;
      TH2F *h2Cefz6= NULL;
      TString hname1= hnames[2*depth-2][0];
      TString hname0= hnames[2*depth-2][1];
      TH2F *twod1= (TH2F*)hfile->Get(hname1);
      TH2F *twod0= (TH2F*)hfile->Get(hname0);
      if (1) std::cout << "debugger: errB_HE depth=" << depth << ". get 2D histos "  << hname1 << " and " << hname0 << "\n";
      if (!twod1 || !twod0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histos");
	if (!twod1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!twod0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	h2Cefz6= (TH2F*)twod1->Clone(Form("Cefz6_%d",depth));
	h2Cefz6->SetTitle(Form("HE Depth %d \b",depth));
	h2Cefz6->Divide(twod1,twod0, 1, 1, "B");

	gPad->SetGridy();
	gPad->SetGridx();
	gPad->SetLogz();
	h2Cefz6->SetTitle(Form("Depth %d \b",depth));
	h2Cefz6->SetMarkerStyle(20);
	h2Cefz6->SetMarkerSize(0.4);
	//	h2Cefz6->GetZaxis()->SetLabelSize(0.04);
	h2Cefz6->SetXTitle("#eta \b");
	h2Cefz6->SetYTitle("#phi \b");
	h2Cefz6->SetZTitle(Form("<ErrorB>  - HE Depth%d \b",depth));
	h2Cefz6->SetMarkerColor(2);
	h2Cefz6->SetLineColor(2);
	h2Cefz6->Draw("COLZ");

	delete twod1;
	delete twod0;
      } // histos ok

      cHB->cd(2);
      hname1=hnames[2*depth-1][0];
      hname0=hnames[2*depth-1][1];
      TH1F *h1= (TH1F*)hfile->Get(hname1);
      TH1F *h0= (TH1F*)hfile->Get(hname0);
      if (1) std::cout << "errB_HE depth=" << depth << ". get 2D histos "
		       << hname1 << " and " << hname0 << "\n";
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	gPad->SetGridx();
	gPad->SetGridy();
	//	gPad->SetLogy();
	hRate2orig = (TH1F*)h1->Clone(Form("Rate2orig_%d",depth));
	hRate2orig->Divide(h1,h0, 1, 1, "B");

	TH1F* hRate2=NULL;
	if (lastLumiBin_HE>1) {
	  if (!copyContents(&hRate2,Form("Rate2_%d",depth),"",hRate2orig,lastLumiBin_HE)) {
	    std::cout << "code failed" << std::endl;
	    gSystem->Exit(1);
	  }
	}
	else hRate2=hRate2orig;

	hRate2->SetTitle(Form("Depth %d \b",depth));
	hRate2->SetMarkerStyle(20);
	hRate2->SetMarkerSize(0.8);
	//	hRate2->GetZaxis()->SetLabelSize(0.04);
	hRate2->SetXTitle(Form("<ErrorB>(ev.in LS & ch.) - HE depth%d -    iLS \b",depth));
	hRate2->SetMarkerColor(2);
	hRate2->SetLineColor(0);
	hRate2->Draw("Error");


	if(LSofFirstErrB_HE == -1) {
	  int nx = hRate2->GetXaxis()->GetNbins();
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  hRate2->GetBinContent(i);
	    if(ccc1>0.) {
	      cout<<"****************>>>>>>>>>>> ErrB_HE bad LS start at iLS = "<<i<<" with rate = "<< ccc1 <<endl;
	      LSofFirstErrB_HE = i;
	      break;
	    }
	  }
	}	
	

	delete h1;
	delete h0;
	if (hRate2!=hRate2orig) { delete hRate2orig; hRate2orig=hRate2; }
      }

      cHB->Update();
      cHB->Print(Form("HistErrB_HE_%d.png",depth));
      cHB->Clear();
      if (h2Cefz6) delete h2Cefz6;
      if (hRate2orig) delete hRate2orig;
    }
  } // ErrorsB in HE


//====================================================================== HO                    :
//====================================================================== HO                    :
//====================================================================== HO                    :
// Special test of errors type A and B in HO
// AZ 08.02.2016

  int flagErrAB_HO[2];
  flagErrAB_HO[0]=-1;
  flagErrAB_HO[1]=-1;
  double avedelta_HO = 0.;
  int lastLumiBin_HO=-1;
  int LSofFirstErrB_HO = -1;
  {
    const int specCountA=4;
    const int specColors[specCountA] = { 1, 2, 3, 4 };
    const TString hnames[specCountA][2] =
      { { "h_sumADCAmplperLS8_P1", "h_sum0ADCAmplperLS8_P1" },
	{ "h_sumADCAmplperLS8_P2", "h_sum0ADCAmplperLS8_P2" },
	{ "h_sumADCAmplperLS8_M1", "h_sum0ADCAmplperLS8_M1" },
	{ "h_sumADCAmplperLS8_M2", "h_sum0ADCAmplperLS8_M2" } };

    std::vector<TH1F*> hV;
    THStack *hs= new THStack("hs","ADCAmplerLS1");
    cHB->Clear();
    //    cHB->cd();
    cHB->Divide(2,1);
    cHB->cd(1);

    ///////////////////////////////////////////////////////////////////////////
    for (int i=0; i<specCountA; i++) {
      if (1) std::cout << "debugger: errA_HO : get histos for i=" << i  << " " << hnames[i][0] << " and " << hnames[i][1] << "\n";
      TH1F *h1= (TH1F*)hfile->Get(hnames[i][0]);
      TH1F *h0= (TH1F*)hfile->Get(hnames[i][1]);
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hnames[i][0] << "\n";
	  ptext->AddText(hnames[i][0]);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hnames[i][1] << "\n";
	  ptext->AddText(hnames[i][1]);
	}
	ptext->Draw();
	continue;
      }
      TH1F *hoRT1orig= (TH1F*)h1->Clone(Form("ERT1orig_%d",i));
      hoRT1orig->Divide(h1, h0, 1,1, "B");

      if ((lastLumiBin_HO<0) && (i==0)) {
	for (int ibin=hoRT1orig->GetNbinsX(); ibin>=1; ibin--) {
	  if (hoRT1orig->GetBinContent(ibin)==0) lastLumiBin_HO=ibin;
	  else break;
	}
	lastLumiBin_HO+=3; // show more bins
	if (lastLumiBin_HO >= hoRT1orig->GetNbinsX()) lastLumiBin_HO=-1;
      }
      TH1F *hoRT1=NULL;
      if (lastLumiBin_HO>1) {
	if (!copyContents(&hoRT1,Form("ERT1_%d",i),"", hoRT1orig,lastLumiBin_HO)) {
	  std::cout << "code failed"<<std::endl;
	  gSystem->Exit(1);
	}
      }
      else hoRT1=hoRT1orig;

      hoRT1->GetXaxis()->SetTitle("<ADCAmpl> per LS HO: black-P1, red-P2,green-M1,blue-M2");
      hV.push_back(hoRT1);
      hoRT1->SetMarkerStyle(20);
      hoRT1->SetMarkerSize(0.4);
      hoRT1->SetXTitle("<A>(ev.in LS & ch.) - HO P1     -    iLS \b");
      hoRT1->SetMarkerColor(specColors[i]);
      hoRT1->SetLineColor(0);
      hs->Add(hoRT1);
      delete h1;
      delete h0;
      if (hoRT1!=hoRT1orig) delete hoRT1orig;
    } /////////////////////////////////////////////////////////////////////////
    hs->Draw("LPE1 nostack"); 
    cHB->Update(); // activate tho axes
    hs->GetXaxis()->SetTitle("<A> per LS: black-P1, red-P2,green-M1,blue-M2");
    hs->Draw("LPE1 nostack");
    gPad->SetGridy();
    /////////////////////////////////////////////////////////////////////////////////////////

    // AZ corrections 08.02.2016
    cHB->cd(2);
    TH1F* diff = new TH1F("diff","", 100, 0., 4.);

    if (int(hV.size())==specCountA) {
      flagErrAB_HO[0]=0;// If we have tho expected number of histograms, set tho flag
      double sumdelta = 0.;
      int nnndelta = 0;
      for (int ibin=1; ibin<=hV[0]->GetNbinsX(); ibin++) {
	double delta = 0.; 
	double maxdelta = 0.; 
	for (unsigned int i=0; i<hV.size(); i++) {
	  const TH1F* hi= hV[i];
	  for (unsigned int j=1; j<hV.size(); j++) {
	    const TH1F* hj= hV[j];
	    delta = fabs(hi->GetBinContent(ibin) - hj->GetBinContent(ibin));
	    if(delta > maxdelta) maxdelta=delta;
	  }//for
	}//for
	if(maxdelta> 0.) {
	  diff->Fill(maxdelta);
	  sumdelta+=maxdelta;
	  nnndelta++;
	}
      }//for ibin
      //      avedelta_HO = sumdelta/hV[0]->GetNbinsX();
      avedelta_HO = sumdelta/nnndelta;
      std::cout << "******************>>>>>>      ErrA_HO:  avedelta_HO = " << avedelta_HO <<std::endl;
      if (avedelta_HO>0.8 || (avedelta_HO<0.2 && avedelta_HO>0.)) {
	flagErrAB_HO[0]=1;
      }//if
    }//hV.size
    diff->SetMarkerStyle(20);
    diff->SetMarkerSize(0.8);
    diff->SetXTitle("max difference \b");
    diff->SetMarkerColor(2);
    diff->SetLineColor(0);
    gPad->SetGridx();
    gPad->SetLogy();
    diff->Draw("Error");
    /////////////////////////////////////////////////////////////////////////
    cHB->Update();
    cHB->Print("HistErrA_HO.png");
    cHB->Clear();
    /////////////////////////////////////////////////////////////////////////
    
    // clean-up
    if (diff) delete diff;
    for (unsigned int i=0; i<hV.size(); i++) delete hV[i];
  } // ErrorA in HO


  ///////////////////////////////////////////////////////////////////////// errors B:


  { // errors type B
    const int specCountB=2;
    const TString hnames[specCountB][2] =
      { { "h_2DsumErrorBLS8", "h_2D0sumErrorBLS8" },
	{ "h_sumErrorBperLS8", "h_sum0ErrorBperLS8" } };

    for (int depth=4; depth<=4; depth++) {

      cHB->Clear();
      cHB->Divide(2,1);
      cHB->cd(1);

      TH1F *hRate2orig= NULL;
      TH2F *h2Cefz6= NULL;
      TString hname1= hnames[2*depth-8][0];
      TString hname0= hnames[2*depth-8][1];
      TH2F *twod1= (TH2F*)hfile->Get(hname1);
      TH2F *twod0= (TH2F*)hfile->Get(hname0);
      if (1) std::cout << "debugger: errB_HO depth=" << depth << ". get 2D histos "  << hname1 << " and " << hname0 << "\n";
      if (!twod1 || !twod0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histos");
	if (!twod1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!twod0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	h2Cefz6= (TH2F*)twod1->Clone(Form("Cefz6_%d",depth));
	h2Cefz6->SetTitle(Form("HO Depth %d \b",depth));
	h2Cefz6->Divide(twod1,twod0, 1, 1, "B");

	gPad->SetGridy();
	gPad->SetGridx();
	gPad->SetLogz();
	h2Cefz6->SetTitle(Form("Depth %d \b",depth));
	h2Cefz6->SetMarkerStyle(20);
	h2Cefz6->SetMarkerSize(0.4);
	//	h2Cefz6->GetZaxis()->SetLabelSize(0.04);
	h2Cefz6->SetXTitle("#eta \b");
	h2Cefz6->SetYTitle("#phi \b");
	h2Cefz6->SetZTitle(Form("<ErrorB>  - HO Depth%d \b",depth));
	h2Cefz6->SetMarkerColor(2);
	h2Cefz6->SetLineColor(2);
	h2Cefz6->Draw("COLZ");

	delete twod1;
	delete twod0;
      } // histos ok

      cHB->cd(2);
      hname1=hnames[2*depth-7][0];
      hname0=hnames[2*depth-7][1];
      TH1F *h1= (TH1F*)hfile->Get(hname1);
      TH1F *h0= (TH1F*)hfile->Get(hname0);
      if (1) std::cout << "errB_HO depth=" << depth << ". get 2D histos "
		       << hname1 << " and " << hname0 << "\n";
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	gPad->SetGridx();
	gPad->SetGridy();
	//	gPad->SetLogy();
	hRate2orig = (TH1F*)h1->Clone(Form("Rate2orig_%d",depth));
	hRate2orig->Divide(h1,h0, 1, 1, "B");

	TH1F* hRate2=NULL;
	if (lastLumiBin_HO>1) {
	  if (!copyContents(&hRate2,Form("Rate2_%d",depth),"",hRate2orig,lastLumiBin_HO)) {
	    std::cout << "code failed" << std::endl;
	    gSystem->Exit(1);
	  }
	}
	else hRate2=hRate2orig;

	hRate2->SetTitle(Form("Depth %d \b",depth));
	hRate2->SetMarkerStyle(20);
	hRate2->SetMarkerSize(0.8);
	//	hRate2->GetZaxis()->SetLabelSize(0.04);
	hRate2->SetXTitle(Form("<ErrorB>(ev.in LS & ch.) - HO depth%d -    iLS \b",depth));
	hRate2->SetMarkerColor(2);
	hRate2->SetLineColor(0);
	hRate2->Draw("Error");


	if(LSofFirstErrB_HO == -1) {
	  int nx = hRate2->GetXaxis()->GetNbins();
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  hRate2->GetBinContent(i);
	    if(ccc1>0.) {
	      cout<<"****************>>>>>>>>>>> ErrB_HO bad LS start at iLS = "<<i<<" with rate = "<< ccc1 <<endl;
	      LSofFirstErrB_HO = i;
	      break;
	    }
	  }
	}	
	

	delete h1;
	delete h0;
	if (hRate2!=hRate2orig) { delete hRate2orig; hRate2orig=hRate2; }
      }

      cHB->Update();
      cHB->Print(Form("HistErrB_HO_%d.png",depth));
      cHB->Clear();
      if (h2Cefz6) delete h2Cefz6;
      if (hRate2orig) delete hRate2orig;
    }
  } // ErrorsB in HO


//====================================================================== done by Andrius for HF:
//====================================================================== done by Andrius for HF:
//====================================================================== done by Andrius for HF:
// Special test of errors type A and B in HF

  int flagErrAB_HF[2];
  flagErrAB_HF[0]=-1;
  flagErrAB_HF[1]=-1;
  double avedelta_HF = 0.;
  int lastLumiBin_HF=-1;
  int LSofFirstErrB_HF = -1;
  {
    const int specCountA=4;
    const int specColors[specCountA] = { 1, 2, 3, 4 };
    const TString hnames[specCountA][2] =
      { { "h_sumADCAmplperLS6_P1", "h_sum0ADCAmplperLS6_P1" },
	{ "h_sumADCAmplperLS6_P2", "h_sum0ADCAmplperLS6_P2" },
	{ "h_sumADCAmplperLS6_M1", "h_sum0ADCAmplperLS6_M1" },
	{ "h_sumADCAmplperLS6_M2", "h_sum0ADCAmplperLS6_M2" } };

    std::vector<TH1F*> hV;
    THStack *hs= new THStack("hs","ADCAmplerLS6");
    cHB->Clear();
    //    cHB->cd();
    cHB->Divide(2,1);
    cHB->cd(1);

    ///////////////////////////////////////////////////////////////////////////
    for (int i=0; i<specCountA; i++) {
      if (1) std::cout << "debugger: errA_HF : get histos for i=" << i  << " " << hnames[i][0] << " and " << hnames[i][1] << "\n";
      TH1F *h1= (TH1F*)hfile->Get(hnames[i][0]);
      TH1F *h0= (TH1F*)hfile->Get(hnames[i][1]);
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hnames[i][0] << "\n";
	  ptext->AddText(hnames[i][0]);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hnames[i][1] << "\n";
	  ptext->AddText(hnames[i][1]);
	}
	ptext->Draw();
	continue;
      }
      TH1F *hERT1orig= (TH1F*)h1->Clone(Form("ERT1orig_%d",i));
      hERT1orig->Divide(h1, h0, 1,1, "B");

      if ((lastLumiBin_HF<0) && (i==0)) {
	for (int ibin=hERT1orig->GetNbinsX(); ibin>=1; ibin--) {
	  if (hERT1orig->GetBinContent(ibin)==0) lastLumiBin_HF=ibin;
	  else break;
	}
	lastLumiBin_HF+=3; // show more bins
	if (lastLumiBin_HF >= hERT1orig->GetNbinsX()) lastLumiBin_HF=-1;
      }
      TH1F *hERT1=NULL;
      if (lastLumiBin_HF>1) {
	if (!copyContents(&hERT1,Form("ERT1_%d",i),"", hERT1orig,lastLumiBin_HF)) {
	  std::cout << "code failed"<<std::endl;
	  gSystem->Exit(1);
	}
      }
      else hERT1=hERT1orig;

      hERT1->GetXaxis()->SetTitle("<ADCAmpl> per LS HF: black-P1, red-P2,green-M1,blue-M2");
      hV.push_back(hERT1);
      hERT1->SetMarkerStyle(20);
      hERT1->SetMarkerSize(0.4);
      hERT1->SetXTitle("<A>(ev.in LS & ch.) - HF P1     -    iLS \b");
      hERT1->SetMarkerColor(specColors[i]);
      hERT1->SetLineColor(0);
      hs->Add(hERT1);
      delete h1;
      delete h0;
      if (hERT1!=hERT1orig) delete hERT1orig;
    } /////////////////////////////////////////////////////////////////////////
    hs->Draw("LPE1 nostack"); 
    cHB->Update(); // activate the axes
    hs->GetXaxis()->SetTitle("<A> per LS: black-P1, red-P2,green-M1,blue-M2");
    hs->Draw("LPE1 nostack");
    gPad->SetGridy();
    /////////////////////////////////////////////////////////////////////////////////////////

    // AZ corrections 04.02.2016
    cHB->cd(2);
    TH1F* diff = new TH1F("diff","", 100, 0., 4.);

    if (int(hV.size())==specCountA) {
      flagErrAB_HF[0]=0;// If we have the expected number of histograms, set the flag
      double sumdelta = 0.;
      int nnndelta = 0;
      std::cout << "********   GetNbinsX  = " << hV[0]->GetNbinsX() <<std::endl;
      for (int ibin=1; ibin<=hV[0]->GetNbinsX(); ibin++) {
	double delta = 0.; 
	double maxdelta = 0.; 
	for (unsigned int i=0; i<hV.size(); i++) {
	  const TH1F* hi= hV[i];
	  for (unsigned int j=1; j<hV.size(); j++) {
	    const TH1F* hj= hV[j];
	    delta = fabs(hi->GetBinContent(ibin) - hj->GetBinContent(ibin));
	    if(delta > maxdelta) maxdelta=delta;
	  }//for
	}//for
	//	std::cout << "*****      ibin = " << ibin << " nnndelta= " << nnndelta << " maxdelta= " << maxdelta <<std::endl;
	if(maxdelta> 0.) {
	  diff->Fill(maxdelta);
	  sumdelta+=maxdelta;
	  nnndelta++;
	}
      }//for ibin
      //      avedelta_HF = sumdelta/hV[0]->GetNbinsX();
      avedelta_HF = sumdelta/nnndelta;
      //      std::cout << "******************>>>>>>      ErrA_HF:  avedelta_HF = " << avedelta_HF << " Npoints for comparison= " << nnndelta <<std::endl;
      if (avedelta_HF>2.4 || (avedelta_HF<0.8 && avedelta_HF>0.)) {
	flagErrAB_HF[0]=1;
      }//if
    }//hV.size
    diff->SetMarkerStyle(20);
    diff->SetMarkerSize(0.8);
    diff->SetXTitle("max difference \b");
    diff->SetMarkerColor(2);
    diff->SetLineColor(0);
    gPad->SetGridx();
    gPad->SetLogy();
    diff->Draw("Error");
    /////////////////////////////////////////////////////////////////////////
    cHB->Update();
    cHB->Print("HistErrA_HF.png");
    cHB->Clear();
    /////////////////////////////////////////////////////////////////////////
    // clean-up
    if (diff) delete diff;
    for (unsigned int i=0; i<hV.size(); i++) delete hV[i];
  } // ErrorA in HF
  ////////////////////////////////////////////////////////// errors B:
  /////////////////////////
  { // errors type B
    const int specCountB=4;
    const TString hnames[specCountB][2] =
      { { "h_2DsumErrorBLS6", "h_2D0sumErrorBLS6" },
	{ "h_sumErrorBperLS6", "h_sum0ErrorBperLS6" },
	{ "h_2DsumErrorBLS7", "h_2D0sumErrorBLS7" },
	{ "h_sumErrorBperLS7", "h_sum0ErrorBperLS7" } };

    for (int depth=1; depth<=2; depth++) {
      cHB->Clear();
      cHB->Divide(2,1);
      cHB->cd(1);
      TH1F *hRate2orig= NULL;
      TH2F *h2Cefz6= NULL;
      TString hname1= hnames[2*depth-2][0];
      TString hname0= hnames[2*depth-2][1];
      TH2F *twod1= (TH2F*)hfile->Get(hname1);
      TH2F *twod0= (TH2F*)hfile->Get(hname0);
      if (1) std::cout << "debugger: errB_HF depth=" << depth << ". get 2D histos "  << hname1 << " and " << hname0 << "\n";
      if (!twod1 || !twod0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histos");
	if (!twod1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!twod0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	h2Cefz6= (TH2F*)twod1->Clone(Form("Cefz6_%d",depth));
	h2Cefz6->SetTitle(Form("HF Depth %d \b",depth));
	h2Cefz6->Divide(twod1,twod0, 1, 1, "B");

	gPad->SetGridy();
	gPad->SetGridx();
	gPad->SetLogz();
	h2Cefz6->SetTitle(Form("Depth %d \b",depth));
	h2Cefz6->SetMarkerStyle(20);
	h2Cefz6->SetMarkerSize(0.4);
	//	h2Cefz6->GetZaxis()->SetLabelSize(0.04);
	h2Cefz6->SetXTitle("#eta \b");
	h2Cefz6->SetYTitle("#phi \b");
	h2Cefz6->SetZTitle(Form("<ErrorB>  - HF Depth%d \b",depth));
	h2Cefz6->SetMarkerColor(2);
	h2Cefz6->SetLineColor(2);
	h2Cefz6->Draw("COLZ");
	delete twod1;
	delete twod0;
      } // histos ok
      cHB->cd(2);
      hname1=hnames[2*depth-1][0];
      hname0=hnames[2*depth-1][1];
      TH1F *h1= (TH1F*)hfile->Get(hname1);
      TH1F *h0= (TH1F*)hfile->Get(hname0);
      if (1) std::cout << "errB_HF depth=" << depth << ". get 2D histos "
		       << hname1 << " and " << hname0 << "\n";
      if (!h1 || !h0) {
	TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
	ptext->AddText("Missing histo");
	if (!h1) {
	  std::cout << "\tfailed to get " << hname1 << "\n";
	  ptext->AddText(hname1);
	}
	if (!h0) {
	  std::cout << "\tfailed to get " << hname0 << "\n";
	  ptext->AddText(hname0);
	}
	ptext->Draw();
      }
      else {
	gPad->SetGridx();
	gPad->SetGridy();
	//	gPad->SetLogy();
	hRate2orig = (TH1F*)h1->Clone(Form("Rate2orig_%d",depth));
	hRate2orig->Divide(h1,h0, 1, 1, "B");

	TH1F* hRate2=NULL;
	if (lastLumiBin_HF>1) {
	  if (!copyContents(&hRate2,Form("Rate2_%d",depth),"",hRate2orig,lastLumiBin_HF)) {
	    std::cout << "code failed" << std::endl;
	    gSystem->Exit(1);
	  }
	}
	else hRate2=hRate2orig;
	hRate2->SetTitle(Form("Depth %d \b",depth));
	hRate2->SetMarkerStyle(20);
	hRate2->SetMarkerSize(0.8);
	//	hRate2->GetZaxis()->SetLabelSize(0.04);
	hRate2->SetXTitle(Form("<ErrorB>(ev.in LS & ch.) - HF depth%d -    iLS \b",depth));
	hRate2->SetMarkerColor(2);
	hRate2->SetLineColor(0);
	hRate2->Draw("Error");
	if(LSofFirstErrB_HF == -1) {
	  int nx = hRate2->GetXaxis()->GetNbins();
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  hRate2->GetBinContent(i);
	    if(ccc1>0.) {
	      cout<<"****************>>>>>>>>>>> ErrB_HF bad LS start at iLS = "<<i<<" with rate = "<< ccc1 <<endl;
	      LSofFirstErrB_HF = i;
	      break;
	    }
	  }
	}	
	delete h1;
	delete h0;
	if (hRate2!=hRate2orig) { delete hRate2orig; hRate2orig=hRate2; }
      }
      cHB->Update();
      cHB->Print(Form("HistErrB_HF_%d.png",depth));
      cHB->Clear();
      if (h2Cefz6) delete h2Cefz6;
      if (hRate2orig) delete hRate2orig;
    }
  } // ErrorsB in HF

  /////////////////  Cross-check A-errors & Occupancies:



//===============================================================================  err A HB
/// errA with average Amplitudes 
// For  2D and  1D plots with Amplitude. Produces ChkErrA_HBx.png

  for (int depth=1; depth<=2; depth++) {
    TH2F *h2Ceff= NULL;
    TH2F *h2Diffe= NULL;
    //    TH1F* h1diffADCAmpl= NULL;
    TH2F *h3Ceff= NULL;
    
    cHE->Clear();
    cHE->Divide(3,1);
    
    cHE->cd(1);
    // h_mapDepth1ADCAmpl_HB div h_mapDepth1_HB
    TString hname1= Form("h_mapDepth%dADCAmpl_HB",depth);
    TString hname0= Form("h_mapDepth%d_HB",depth);
    TH2F *twod1= (TH2F*)hfile->Get(hname1);
    TH2F *twod0= (TH2F*)hfile->Get(hname0);
    if (!twod1 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHB test: failed to load " << hname1 << " and/or "
		<< hname0 << "\n";
      if (!twod1) ptext->AddText(hname1);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h2Ceff = (TH2F*)twod1->Clone(Form("Ceff_HB%d",depth));
      h2Ceff->SetTitle(Form("HB Depth %d. (No cut) \b",depth));
      h2Ceff->Divide(twod1,twod0, 1, 1, "B");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Ceff->SetMarkerStyle(20);
      h2Ceff->SetMarkerSize(0.4);
      //h2Ceff->GetZaxis()->SetLabelSize(0.08);
      h2Ceff->SetXTitle("#eta \b");
      h2Ceff->SetYTitle("#phi \b");
      h2Ceff->SetZTitle("h_mapDepth1ADCAmpl_HB \b");
      h2Ceff->SetMarkerColor(2);
      h2Ceff->SetLineColor(2);
      h2Ceff->Draw("COLZ");
    }

    cHE->cd(2);
    ///////////////////////////////////////
    if (h2Ceff) {
      // TO IDENTIFY: see red bins in eta-phi space 
      h2Diffe = (TH2F*)h2Ceff->Clone(Form("Diffe_Depth%d_HB",depth));
      h2Diffe->SetTitle(Form("HB Depth %d. Cut avg(ADCAmpl) > 25 \b",depth));
      int nx = h2Ceff->GetXaxis()->GetNbins();
      int ny = h2Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  h2Ceff->GetBinContent(i,j)   ;
	  h2Diffe->SetBinContent(i,j,0.);
	  if(ccc1 > 25.)  h2Diffe->SetBinContent(i,j,ccc1);
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Diffe->SetMarkerStyle(20);
      h2Diffe->SetMarkerSize(0.4);
      //h2Diffe->GetZaxis()->SetLabelSize(0.08);
      h2Diffe->SetXTitle("#eta \b");
      h2Diffe->SetYTitle("#phi \b");
      h2Diffe->SetZTitle("<ADCAmpl> bigger 25.- HB Depth1 \b");
      h2Diffe->SetMarkerColor(2);
      h2Diffe->SetLineColor(2);
      h2Diffe->Draw("COLZ");
    }

    cHE->cd(3);
    TString hname3= Form("h_mapDepth%dADCAmpl225Copy_HB",depth);
    TH2F *twod3= (TH2F*)hfile->Get(hname3);
    if (!twod3 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHB test: failed to load " << hname3 << " and/or "
		<< hname0 << "\n";
      if (!twod3) ptext->AddText(hname3);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h3Ceff = (TH2F*)twod3->Clone(Form("CeffA_HB%d",depth));
      h3Ceff->SetTitle(Form("HB Depth %d. \b",depth));
      h3Ceff->Divide(twod3,twod0, 1, 1, "B");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h3Ceff->SetMarkerStyle(20);
      h3Ceff->SetMarkerSize(0.4);
//      h3Ceff->GetZaxis()->SetLabelSize(0.08);
      h3Ceff->SetXTitle("#eta \b");
      h3Ceff->SetYTitle("#phi \b");
      h3Ceff->SetZTitle("rate for channels of HB \b");
      h3Ceff->SetMarkerColor(2);
      h3Ceff->SetLineColor(2);
      h3Ceff->Draw("COLZ");
    }

    cHE->Update();
    cHE->Print(Form("ChkErrA_HB%d.png",depth));
    cHE->Clear();

    if (h2Ceff) delete h2Ceff;
    if (h2Diffe) delete h2Diffe;
    //    if (h1diffADCAmpl) delete h1diffADCAmpl;
    //  if (twod0) delete twod0;// do not delete - sometimes causes trouble later
    if (twod1) delete twod1;
    if (twod3) delete twod3;
    if (h3Ceff) delete h3Ceff;
  } // depth

//===============================================================================  err A HE
/// errA with average Amplitudes
// For  2D and  1D plots with Amplitude. Produces ChkErrA_HEx.png

  for (int depth=1; depth<=3; depth++) {
    TH2F *h2Ceff= NULL;
    TH2F *h2Diffe= NULL;
    //    TH1F* h1diffADCAmpl= NULL;
    TH2F *h3Ceff= NULL;
    
    cHE->Clear();
    cHE->Divide(3,1);
    
    cHE->cd(1);
    // h_mapDepth1ADCAmpl_HE div h_mapDepth1_HE
    TString hname1= Form("h_mapDepth%dADCAmpl_HE",depth);
    TString hname0= Form("h_mapDepth%d_HE",depth);
    TH2F *twod1= (TH2F*)hfile->Get(hname1);
    TH2F *twod0= (TH2F*)hfile->Get(hname0);
    if (!twod1 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHE test: failed to load " << hname1 << " and/or "
		<< hname0 << "\n";
      if (!twod1) ptext->AddText(hname1);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h2Ceff = (TH2F*)twod1->Clone(Form("Ceff_HE%d",depth));
      h2Ceff->SetTitle(Form("HE Depth %d. (No cut) \b",depth));
      h2Ceff->Divide(twod1,twod0, 1, 1, "B");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Ceff->SetMarkerStyle(20);
      h2Ceff->SetMarkerSize(0.4);
      //h2Ceff->GetZaxis()->SetLabelSize(0.08);
      h2Ceff->SetXTitle("#eta \b");
      h2Ceff->SetYTitle("#phi \b");
      h2Ceff->SetZTitle("h_mapDepth1ADCAmpl_HE \b");
      h2Ceff->SetMarkerColor(2);
      h2Ceff->SetLineColor(2);
      h2Ceff->Draw("COLZ");
    }

    cHE->cd(2);
    ///////////////////////////////////////
    if (h2Ceff) {
      // TO IDENTIFY: see red bins in eta-phi space 
      h2Diffe = (TH2F*)h2Ceff->Clone(Form("Diffe_Depth%d_HE",depth));
      h2Diffe->SetTitle(Form("HE Depth %d. Cut avg(ADCAmpl) > 1000 fC \b",depth));
      int nx = h2Ceff->GetXaxis()->GetNbins();
      int ny = h2Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  h2Ceff->GetBinContent(i,j)   ;
	  h2Diffe->SetBinContent(i,j,0.);
	  if(ccc1 > 1000.)  h2Diffe->SetBinContent(i,j,ccc1);
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Diffe->SetMarkerStyle(20);
      h2Diffe->SetMarkerSize(0.4);
      //h2Diffe->GetZaxis()->SetLabelSize(0.08);
      h2Diffe->SetXTitle("#eta \b");
      h2Diffe->SetYTitle("#phi \b");
      h2Diffe->SetZTitle("<ADCAmpl> bigger 1000.fC - HE Depth1 \b");
      h2Diffe->SetMarkerColor(2);
      h2Diffe->SetLineColor(2);
      h2Diffe->Draw("COLZ");
    }

    cHE->cd(3);
    TString hname3= Form("h_mapDepth%dADCAmpl225Copy_HE",depth);
    TH2F *twod3= (TH2F*)hfile->Get(hname3);
    if (!twod3 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHE test: failed to load " << hname3 << " and/or "
		<< hname0 << "\n";
      if (!twod3) ptext->AddText(hname3);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h3Ceff = (TH2F*)twod3->Clone(Form("CeffA_HE%d",depth));
      h3Ceff->SetTitle(Form("HE Depth %d. \b",depth));
      h3Ceff->Divide(twod3,twod0, 1, 1, "B");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h3Ceff->SetMarkerStyle(20);
      h3Ceff->SetMarkerSize(0.4);
//      h3Ceff->GetZaxis()->SetLabelSize(0.08);
      h3Ceff->SetXTitle("#eta \b");
      h3Ceff->SetYTitle("#phi \b");
      h3Ceff->SetZTitle("rate for channels of HE \b");
      h3Ceff->SetMarkerColor(2);
      h3Ceff->SetLineColor(2);
      h3Ceff->Draw("COLZ");
    }

    cHE->Update();
    cHE->Print(Form("ChkErrA_HE%d.png",depth));
    cHE->Clear();

    if (h2Ceff) delete h2Ceff;
    if (h2Diffe) delete h2Diffe;
    //    if (h1diffADCAmpl) delete h1diffADCAmpl;
    //  if (twod0) delete twod0;// do not delete - sometimes causes trouble later
    if (twod1) delete twod1;
    if (twod3) delete twod3;
    if (h3Ceff) delete h3Ceff;
  } // depth

//===============================================================================  err A HO
/// errA with average Amplitudes
// For  2D and  1D plots with Amplitude. Produces ChkErrA_HOx.png

  for (int depth=4; depth<=4; depth++) {
    TH2F *h2Ceff= NULL;
    TH2F *h2Diffe= NULL;
    //    TH1F* h1diffADCAmpl= NULL;
    TH2F *h3Ceff= NULL;
    
    cHE->Clear();
    cHE->Divide(3,1);
    
    cHE->cd(1);
    // h_mapDepth1ADCAmpl_HO div h_mapDepth1_HO
    TString hname1= Form("h_mapDepth%dADCAmpl_HO",depth);
    TString hname0= Form("h_mapDepth%d_HO",depth);
    TH2F *twod1= (TH2F*)hfile->Get(hname1);
    TH2F *twod0= (TH2F*)hfile->Get(hname0);
    if (!twod1 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHO test: failed to load " << hname1 << " and/or "
		<< hname0 << "\n";
      if (!twod1) ptext->AddText(hname1);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h2Ceff = (TH2F*)twod1->Clone(Form("Ceff_HO%d",depth));
      h2Ceff->SetTitle(Form("HO Depth %d. (No cut) \b",depth));
      h2Ceff->Divide(twod1,twod0, 1, 1, "B");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Ceff->SetMarkerStyle(20);
      h2Ceff->SetMarkerSize(0.4);
      //h2Ceff->GetZaxis()->SetLabelSize(0.08);
      h2Ceff->SetXTitle("#eta \b");
      h2Ceff->SetYTitle("#phi \b");
      h2Ceff->SetZTitle("h_mapDepth1ADCAmpl_HO \b");
      h2Ceff->SetMarkerColor(2);
      h2Ceff->SetLineColor(2);
      h2Ceff->Draw("COLZ");
    }

    cHE->cd(2);
    ///////////////////////////////////////
    if (h2Ceff) {
      // TO IDENTIFY: see red bins in eta-phi space (applied cut on Aij: <20 || >3000
      h2Diffe = (TH2F*)h2Ceff->Clone(Form("Diffe_Depth%d_HO",depth));
      h2Diffe->SetTitle(Form("HO Depth %d. Cut avg(ADCAmpl) > 80 \b",depth));
      int nx = h2Ceff->GetXaxis()->GetNbins();
      int ny = h2Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  h2Ceff->GetBinContent(i,j)   ;
	  h2Diffe->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  h2Diffe->SetBinContent(i,j,ccc1);
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Diffe->SetMarkerStyle(20);
      h2Diffe->SetMarkerSize(0.4);
      //h2Diffe->GetZaxis()->SetLabelSize(0.08);
      h2Diffe->SetXTitle("#eta \b");
      h2Diffe->SetYTitle("#phi \b");
      h2Diffe->SetZTitle("<ADCAmpl> bigger 80.- HO Depth1 \b");
      h2Diffe->SetMarkerColor(2);
      h2Diffe->SetLineColor(2);
      h2Diffe->Draw("COLZ");
    }

    cHE->cd(3);
    TString hname3= Form("h_mapDepth%dADCAmpl225Copy_HO",depth);
    TH2F *twod3= (TH2F*)hfile->Get(hname3);
    if (!twod3 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHO test: failed to load " << hname3 << " and/or "
		<< hname0 << "\n";
      if (!twod3) ptext->AddText(hname3);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h3Ceff = (TH2F*)twod3->Clone(Form("CeffA_HO%d",depth));
      h3Ceff->SetTitle(Form("HO Depth %d. \b",depth));
      h3Ceff->Divide(twod3,twod0, 1, 1, "B");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h3Ceff->SetMarkerStyle(20);
      h3Ceff->SetMarkerSize(0.4);
//      h3Ceff->GetZaxis()->SetLabelSize(0.08);
      h3Ceff->SetXTitle("#eta \b");
      h3Ceff->SetYTitle("#phi \b");
      h3Ceff->SetZTitle("rate for channels of HO \b");
      h3Ceff->SetMarkerColor(2);
      h3Ceff->SetLineColor(2);
      h3Ceff->Draw("COLZ");
    }

    cHE->Update();
    cHE->Print(Form("ChkErrA_HO%d.png",depth));
    cHE->Clear();

    if (h2Ceff) delete h2Ceff;
    if (h2Diffe) delete h2Diffe;
    //    if (h1diffADCAmpl) delete h1diffADCAmpl;
    //  if (twod0) delete twod0;// do not delete - sometimes causes trouble later
    if (twod1) delete twod1;
    if (twod3) delete twod3;
    if (h3Ceff) delete h3Ceff;
  } // depth

//===============================================================================  err A HF
/// errA with average Amplitudes 
// For  2D and  1D plots with Amplitude. Produces ChkErrA_HFx.png

  for (int depth=1; depth<=2; depth++) {
    TH2F *h2Ceff= NULL;
    TH2F *h2Diffe= NULL;
    //    TH1F* h1diffADCAmpl= NULL;
    TH2F *h3Ceff= NULL;
    
    cHE->Clear();
    cHE->Divide(3,1);
    
    cHE->cd(1);
    // h_mapDepth1ADCAmpl_HF div h_mapDepth1_HF
    TString hname1= Form("h_mapDepth%dADCAmpl_HF",depth);
    TString hname0= Form("h_mapDepth%d_HF",depth);
    TH2F *twod1= (TH2F*)hfile->Get(hname1);
    TH2F *twod0= (TH2F*)hfile->Get(hname0);
    if (!twod1 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHF test: failed to load " << hname1 << " and/or "
		<< hname0 << "\n";
      if (!twod1) ptext->AddText(hname1);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h2Ceff = (TH2F*)twod1->Clone(Form("Ceff_HF%d",depth));
      h2Ceff->SetTitle(Form("HF Depth %d. (No cut) \b",depth));
      h2Ceff->Divide(twod1,twod0, 1, 1, "B");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Ceff->SetMarkerStyle(20);
      h2Ceff->SetMarkerSize(0.4);
      //h2Ceff->GetZaxis()->SetLabelSize(0.08);
      h2Ceff->SetXTitle("#eta \b");
      h2Ceff->SetYTitle("#phi \b");
      h2Ceff->SetZTitle("h_mapDepth1ADCAmpl_HF \b");
      h2Ceff->SetMarkerColor(2);
      h2Ceff->SetLineColor(2);
      h2Ceff->Draw("COLZ");
    }

    cHE->cd(2);
    ///////////////////////////////////////
    if (h2Ceff) {
      // TO IDENTIFY: see red bins in eta-phi space (applied cut on Aij: <20 || >3000
      h2Diffe = (TH2F*)h2Ceff->Clone(Form("Diffe_Depth%d_HF",depth));
      h2Diffe->SetTitle(Form("HF Depth %d. Cut avg(ADCAmpl) > 20 \b",depth));
      int nx = h2Ceff->GetXaxis()->GetNbins();
      int ny = h2Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  h2Ceff->GetBinContent(i,j)   ;
	  h2Diffe->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  h2Diffe->SetBinContent(i,j,ccc1);
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h2Diffe->SetMarkerStyle(20);
      h2Diffe->SetMarkerSize(0.4);
      //h2Diffe->GetZaxis()->SetLabelSize(0.08);
      h2Diffe->SetXTitle("#eta \b");
      h2Diffe->SetYTitle("#phi \b");
      h2Diffe->SetZTitle("<ADCAmpl> bigger 20.- HF Depth1 \b");
      h2Diffe->SetMarkerColor(2);
      h2Diffe->SetLineColor(2);
      h2Diffe->Draw("COLZ");
    }

    cHE->cd(3);
    /*
    if (h2Ceff) {
      h1diffADCAmpl = new TH1F(Form("diffADCAmpl_Depth%d_HF",depth),"",
			       100, -20.,200.);
      h1diffADCAmpl->SetTitle(Form("HF Depth %d \b",depth));
      int nx = h2Ceff->GetXaxis()->GetNbins();
      int ny = h2Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(h2Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  h2Ceff->GetBinContent(i,j) ;
	    h1diffADCAmpl->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      h1diffADCAmpl->SetMarkerStyle(20);
      h1diffADCAmpl->SetMarkerSize(0.4);
      h1diffADCAmpl->GetYaxis()->SetLabelSize(0.04);
      h1diffADCAmpl->SetXTitle("<ADCAmpl> in each cell \b");
      h1diffADCAmpl->SetMarkerColor(2);
      h1diffADCAmpl->SetLineColor(2);
      h1diffADCAmpl->Draw("");
    }
    */
    TString hname3= Form("h_mapDepth%dADCAmpl225Copy_HF",depth);
    TH2F *twod3= (TH2F*)hfile->Get(hname3);
    if (!twod3 || !twod0) {
      TPaveText *ptext= new TPaveText(0.05,0.85,0.95,0.95);
      ptext->AddText("Missing histo");
      std::cout << "specHF test: failed to load " << hname3 << " and/or "
		<< hname0 << "\n";
      if (!twod3) ptext->AddText(hname3);
      if (!twod0) ptext->AddText(hname0);
      ptext->Draw();
      continue;
    }
    else {
    // To IDENTIFY: see color different bins in eta-phi space
      h3Ceff = (TH2F*)twod3->Clone(Form("CeffA_HF%d",depth));
      h3Ceff->SetTitle(Form("HF Depth %d. \b",depth));
      h3Ceff->Divide(twod3,twod0, 1, 1, "B");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      h3Ceff->SetMarkerStyle(20);
      h3Ceff->SetMarkerSize(0.4);
//      h3Ceff->GetZaxis()->SetLabelSize(0.08);
      h3Ceff->SetXTitle("#eta \b");
      h3Ceff->SetYTitle("#phi \b");
      h3Ceff->SetZTitle("rate for channels of HF \b");
      h3Ceff->SetMarkerColor(2);
      h3Ceff->SetLineColor(2);
      h3Ceff->Draw("COLZ");
    }

    cHE->Update();
    cHE->Print(Form("ChkErrA_HF%d.png",depth));
    cHE->Clear();

    if (h2Ceff) delete h2Ceff;
    if (h2Diffe) delete h2Diffe;
    //    if (h1diffADCAmpl) delete h1diffADCAmpl;
    //  if (twod0) delete twod0;// do not delete - sometimes causes trouble later
    if (twod1) delete twod1;
    if (twod3) delete twod3;
    if (h3Ceff) delete h3Ceff;
  } // depth

  std::cout << "************>>>   average Amplitudes done" << std::endl;

  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
 


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// RBX study:
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// RBX study:
  //////////////////////////////////////////////////////////////////////////////////////////////////////// RBX study:
  //////////////////////////////////////////////////////////////////////////////////// RBX study:


      cout<<" RBX analysis START for HF **************************" <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
  int njeta = 22; int njphi = 18; int lsmax=2600;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>     int njeta = 22; int njphi = 18; int lsmax=2600;                        "              <<endl;
  double alexhf[njeta][njphi][lsmax];      
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>    alexhf[njeta][njphi][lsmax];                         "              <<endl;
  int maxbinsRBX = MaxLum;
  int nx = maxbinsRBX; // # LS
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>   maxbinsRBX = MaxLum;                          "              <<endl;
  if(MaxLum > 2600 ) cout<<"***********************************   ERROR ERROR ERROR ERROR:   MaxLum > 2600 "              <<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;

       for(int jphi=0;jphi<njphi;jphi++){for(int jeta=0;jeta<njeta;jeta++){for(int i=0;i<nx;i++){alexhf[jeta][jphi][i] = 0.;}}}


  //////////




  ////////////////////////////////////////////////////////////////////////////////////     HB::  HBSTART HB: j = 7,8,9,10            11,12,13,14
  //======================================================================
    //======================================================================
      //======================================================================
      cout<<" RBX general for HB **************************" <<endl;
      TH2F *Ghb1KKK= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs0");
      TH2F *Ghb1LLL= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs00");
      TH2F* Ghb1 = (TH2F*)Ghb1LLL->Clone("Ghb1");
      Ghb1->Divide(Ghb1KKK,Ghb1LLL, 1, 1, "B");// average A
      //    Ghb1->Sumw2();
      //      int nx = Ghb1->GetXaxis()->GetNbins(); // # LS
      int ny = Ghb1->GetYaxis()->GetNbins(); // # jetaphi indexes
       for (int j=1;j<=ny;j++) {
	 int jeta = (j-1)/njphi;// jeta = 0-21
	 if(jeta < 15 && jeta > 6 ) {
	   int jphi = (j-1)-njphi*jeta;// jphi=0-17 
	   //	   cout<<"HB 54        jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   // over LS:
	   for (int i=1;i<=nx;i++) {
	     double ccc1 =  Ghb1->GetBinContent(i,j);
	     alexhf[jeta][jphi][i-1] = ccc1;
	     //	     if( i == 1 ) cout<<"HB 54  for LS=1      ccc1=     "<< ccc1 <<endl;
	   }//i
	 }//if
       }//j
      // clean-up
      if (Ghb1KKK) delete Ghb1KKK;
      if (Ghb1LLL) delete Ghb1LLL;
      if (Ghb1) delete Ghb1;

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 11   HB:: 2D  jeta = 0 - 21       jphi =0 - 17
       //======================================================================
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HB  2D plot *****" <<endl;
      cRBX1->Clear();
      /////////////////
      cRBX1->Divide(1,1);
      cRBX1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
       TH2F* Ghb42D      = new TH2F("Ghb42D","",   22, -11., 11., 18, 0., 18. );
       TH2F* Ghb42D0     = new TH2F("Ghb42D0","",  22, -11., 11., 18, 0., 18. );
       TH2F* Ghb42DF = (TH2F*)Ghb42D0->Clone("Ghb42DF");
       for (int jphi=0;jphi<njphi;jphi++) {
	 for (int jeta=0;jeta<njeta;jeta++) {
	   for (int i=0;i<nx;i++) {
	     double ccc1 = alexhf[jeta][jphi][i];
	     if(ccc1>0.) {Ghb42D ->Fill(jeta-11,jphi,ccc1); Ghb42D0 ->Fill(jeta-11,jphi,1.); }
	   }}}
       Ghb42DF->Divide(Ghb42D,Ghb42D0, 1, 1, "B");// average A
       //    Ghb1->Sumw2();
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Ghb42DF->SetMarkerStyle(20); Ghb42DF->SetMarkerSize(0.4); Ghb42DF->GetZaxis()->SetLabelSize(0.04); Ghb42DF->SetXTitle("<A>_RBX         #eta  \b"); Ghb42DF->SetYTitle("      #phi \b"); Ghb42DF->SetZTitle("<A>_RBX  - All \b"); Ghb42DF->SetMarkerColor(2); Ghb42DF->SetLineColor(2);      //      Ghb42DF->SetMaximum(1.000);  //      Ghb42DF->SetMinimum(1.0);
       Ghb42DF->Draw("COLZ");
       
       /////////////////
       cRBX1->Update();
       cRBX1->Print("RBX-HB-2Dplot.png");
       cRBX1->Clear();
      // clean-up
      if (Ghb42D) delete Ghb42D;
      if (Ghb42D0) delete Ghb42D0;
      if (Ghb42DF) delete Ghb42DF;

    //========================================================================================== 13   HB:: j = 7,8,9,10            11,12,13,14     // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HB negative direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBnegativedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHBnegativedirection1 = new TH1F("h2CeffHBnegativedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HB 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HBnegativedirection1 = (TH1F*)h2CeffHBnegativedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBnegativedirection1 ->Fill(i,ccc4x6);HBnegativedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HB 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBnegativedirection1);
	   HBnegativedirection1 ->SetMarkerStyle(20);HBnegativedirection1 ->SetMarkerSize(0.4);HBnegativedirection1 ->GetYaxis()->SetLabelSize(0.04);HBnegativedirection1 ->SetMarkerColor(2);HBnegativedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    

	   if(kcountHBnegativedirection1 == 1) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  0 \b");
	   if(kcountHBnegativedirection1 == 5) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  1 \b");
	   if(kcountHBnegativedirection1 == 9) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  2 \b");
	   if(kcountHBnegativedirection1 ==13) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  3 \b");
	   if(kcountHBnegativedirection1 ==17) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  4 \b");
	   if(kcountHBnegativedirection1 ==21) HBnegativedirection1 ->SetXTitle("HB jeta = 7; jphi =  5 \b");
	   
	   if(kcountHBnegativedirection1 == 2) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  0 \b");
	   if(kcountHBnegativedirection1 == 6) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  1 \b");
	   if(kcountHBnegativedirection1 ==10) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  2 \b");
	   if(kcountHBnegativedirection1 ==14) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  3 \b");
	   if(kcountHBnegativedirection1 ==18) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  4 \b");
	   if(kcountHBnegativedirection1 ==22) HBnegativedirection1 ->SetXTitle("HB jeta = 8; jphi =  5 \b");
	   
	   if(kcountHBnegativedirection1 == 3) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  0 \b");
	   if(kcountHBnegativedirection1 == 7) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  1 \b");
	   if(kcountHBnegativedirection1 ==11) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  2 \b");
	   if(kcountHBnegativedirection1 ==15) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  3 \b");
	   if(kcountHBnegativedirection1 ==19) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  4 \b");
	   if(kcountHBnegativedirection1 ==23) HBnegativedirection1 ->SetXTitle("HB jeta = 9; jphi =  5 \b");
	   
	   if(kcountHBnegativedirection1 == 4) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  0 \b");
	   if(kcountHBnegativedirection1 == 8) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  1 \b");
	   if(kcountHBnegativedirection1 ==12) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  2 \b");
	   if(kcountHBnegativedirection1 ==16) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  3 \b");
	   if(kcountHBnegativedirection1 ==20) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  4 \b");
	   if(kcountHBnegativedirection1 ==24) HBnegativedirection1 ->SetXTitle("HB jeta =10; jphi =  5 \b");

	   HBnegativedirection1->Draw("Error");
	   kcountHBnegativedirection1++;
	   if(kcountHBnegativedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-negative-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBnegativedirection1) delete h2CeffHBnegativedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 14   HB:: j = 7,8,9,10            11,12,13,14      jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HB negative direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBnegativedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHBnegativedirection2 = new TH1F("h2CeffHBnegativedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	       	     cout<<"HB 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHBnegativedirection2   =     "<<kcountHBnegativedirection2  <<endl;
	   TH1F *HBnegativedirection2 = (TH1F*)h2CeffHBnegativedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBnegativedirection2 ->Fill(i,ccc4x6);HBnegativedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HB 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBnegativedirection2);
	   HBnegativedirection2 ->SetMarkerStyle(20);HBnegativedirection2 ->SetMarkerSize(0.4);HBnegativedirection2 ->GetYaxis()->SetLabelSize(0.04);HBnegativedirection2 ->SetMarkerColor(2);HBnegativedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();  
  
	   if(kcountHBnegativedirection2 == 1) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi =  6 \b");
	   if(kcountHBnegativedirection2 == 5) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi =  7 \b");
	   if(kcountHBnegativedirection2 == 9) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi =  8 \b");
	   if(kcountHBnegativedirection2 ==13) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi =  9 \b");
	   if(kcountHBnegativedirection2 ==17) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi = 10 \b");
	   if(kcountHBnegativedirection2 ==21) HBnegativedirection2 ->SetXTitle("HB jeta = 7; jphi = 11 \b");
	   
	   if(kcountHBnegativedirection2 == 2) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi =  6 \b");
	   if(kcountHBnegativedirection2 == 6) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi =  7 \b");
	   if(kcountHBnegativedirection2 ==10) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi =  8 \b");
	   if(kcountHBnegativedirection2 ==14) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi =  9 \b");
	   if(kcountHBnegativedirection2 ==18) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi = 10 \b");
	   if(kcountHBnegativedirection2 ==22) HBnegativedirection2 ->SetXTitle("HB jeta = 8; jphi = 11 \b");
	   
	   if(kcountHBnegativedirection2 == 3) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi =  6 \b");
	   if(kcountHBnegativedirection2 == 7) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi =  7 \b");
	   if(kcountHBnegativedirection2 ==11) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi =  8 \b");
	   if(kcountHBnegativedirection2 ==15) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi =  9 \b");
	   if(kcountHBnegativedirection2 ==19) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi = 10 \b");
	   if(kcountHBnegativedirection2 ==23) HBnegativedirection2 ->SetXTitle("HB jeta = 9; jphi = 11 \b");
	   
	   if(kcountHBnegativedirection2 == 4) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi =  6 \b");
	   if(kcountHBnegativedirection2 == 8) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi =  7 \b");
	   if(kcountHBnegativedirection2 ==12) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi =  8 \b");
	   if(kcountHBnegativedirection2 ==16) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi =  9 \b");
	   if(kcountHBnegativedirection2 ==20) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi = 10 \b");
	   if(kcountHBnegativedirection2 ==24) HBnegativedirection2 ->SetXTitle("HB jeta =10; jphi = 11 \b");

	   HBnegativedirection2->Draw("Error");
	   kcountHBnegativedirection2++;
	   if(kcountHBnegativedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-negative-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBnegativedirection2) delete h2CeffHBnegativedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 15   HB:: j = 7,8,9,10            11,12,13,14       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HB negative direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBnegativedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHBnegativedirection3 = new TH1F("h2CeffHBnegativedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	       	     cout<<"HB 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHBnegativedirection3   =     "<<kcountHBnegativedirection3  <<endl;
	   TH1F *HBnegativedirection3 = (TH1F*)h2CeffHBnegativedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBnegativedirection3 ->Fill(i,ccc4x6);HBnegativedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HB 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBnegativedirection3);
	   HBnegativedirection3 ->SetMarkerStyle(20);HBnegativedirection3 ->SetMarkerSize(0.4);HBnegativedirection3 ->GetYaxis()->SetLabelSize(0.04);HBnegativedirection3 ->SetMarkerColor(2);HBnegativedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHBnegativedirection3 == 1) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 12 \b");
	   if(kcountHBnegativedirection3 == 5) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 13 \b");
	   if(kcountHBnegativedirection3 == 9) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 14 \b");
	   if(kcountHBnegativedirection3 ==13) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 15 \b");
	   if(kcountHBnegativedirection3 ==17) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 16 \b");
	   if(kcountHBnegativedirection3 ==21) HBnegativedirection3 ->SetXTitle("HB jeta = 7; jphi = 17 \b");
	   
	   if(kcountHBnegativedirection3 == 2) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 12 \b");
	   if(kcountHBnegativedirection3 == 6) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 13 \b");
	   if(kcountHBnegativedirection3 ==10) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 14 \b");
	   if(kcountHBnegativedirection3 ==14) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 15 \b");
	   if(kcountHBnegativedirection3 ==18) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 16 \b");
	   if(kcountHBnegativedirection3 ==22) HBnegativedirection3 ->SetXTitle("HB jeta = 8; jphi = 17 \b");
	   
	   if(kcountHBnegativedirection3 == 3) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 12 \b");
	   if(kcountHBnegativedirection3 == 7) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 13 \b");
	   if(kcountHBnegativedirection3 ==11) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 14 \b");
	   if(kcountHBnegativedirection3 ==15) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 15 \b");
	   if(kcountHBnegativedirection3 ==19) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 16 \b");
	   if(kcountHBnegativedirection3 ==23) HBnegativedirection3 ->SetXTitle("HB jeta = 9; jphi = 17 \b");
	   
	   if(kcountHBnegativedirection3 == 4) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 12 \b");
	   if(kcountHBnegativedirection3 == 8) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 13 \b");
	   if(kcountHBnegativedirection3 ==12) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 14 \b");
	   if(kcountHBnegativedirection3 ==16) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 15 \b");
	   if(kcountHBnegativedirection3 ==20) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 16 \b");
	   if(kcountHBnegativedirection3 ==24) HBnegativedirection3 ->SetXTitle("HB jeta =10; jphi = 17 \b");
   
	   HBnegativedirection3->Draw("Error");
	   kcountHBnegativedirection3++;
	   if(kcountHBnegativedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-negative-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBnegativedirection3) delete h2CeffHBnegativedirection3;
       ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 16   HB:: j = 7,8,9,10            11,12,13,14     // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HB positive direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBpositivedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHBpositivedirection1 = new TH1F("h2CeffHBpositivedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HB 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HBpositivedirection1 = (TH1F*)h2CeffHBpositivedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBpositivedirection1 ->Fill(i,ccc4x6);HBpositivedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HB 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBpositivedirection1);
	   HBpositivedirection1 ->SetMarkerStyle(20);HBpositivedirection1 ->SetMarkerSize(0.4);HBpositivedirection1 ->GetYaxis()->SetLabelSize(0.04);HBpositivedirection1 ->SetMarkerColor(2);HBpositivedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHBpositivedirection1 == 1) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  0 \b");
	   if(kcountHBpositivedirection1 == 5) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  1 \b");
	   if(kcountHBpositivedirection1 == 9) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  2 \b");
	   if(kcountHBpositivedirection1 ==13) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  3 \b");
	   if(kcountHBpositivedirection1 ==17) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  4 \b");
	   if(kcountHBpositivedirection1 ==21) HBpositivedirection1 ->SetXTitle("HB jeta = 11; jphi =  5 \b");
	   
	   if(kcountHBpositivedirection1 == 2) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  0 \b");
	   if(kcountHBpositivedirection1 == 6) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  1 \b");
	   if(kcountHBpositivedirection1 ==10) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  2 \b");
	   if(kcountHBpositivedirection1 ==14) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  3 \b");
	   if(kcountHBpositivedirection1 ==18) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  4 \b");
	   if(kcountHBpositivedirection1 ==22) HBpositivedirection1 ->SetXTitle("HB jeta = 12; jphi =  5 \b");
	   
	   if(kcountHBpositivedirection1 == 3) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  0 \b");
	   if(kcountHBpositivedirection1 == 7) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  1 \b");
	   if(kcountHBpositivedirection1 ==11) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  2 \b");
	   if(kcountHBpositivedirection1 ==15) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  3 \b");
	   if(kcountHBpositivedirection1 ==19) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  4 \b");
	   if(kcountHBpositivedirection1 ==23) HBpositivedirection1 ->SetXTitle("HB jeta = 13; jphi =  5 \b");
	   
	   if(kcountHBpositivedirection1 == 4) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  0 \b");
	   if(kcountHBpositivedirection1 == 8) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  1 \b");
	   if(kcountHBpositivedirection1 ==12) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  2 \b");
	   if(kcountHBpositivedirection1 ==16) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  3 \b");
	   if(kcountHBpositivedirection1 ==20) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  4 \b");
	   if(kcountHBpositivedirection1 ==24) HBpositivedirection1 ->SetXTitle("HB jeta = 14; jphi =  5 \b");

	   HBpositivedirection1->Draw("Error");
	   kcountHBpositivedirection1++;
	   if(kcountHBpositivedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-positive-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBpositivedirection1) delete h2CeffHBpositivedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 17   HB:: j = 7,8,9,10            11,12,13,14       jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HB positive direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBpositivedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHBpositivedirection2 = new TH1F("h2CeffHBpositivedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	       	     cout<<"HB 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHBpositivedirection2   =     "<<kcountHBpositivedirection2  <<endl;
	   TH1F *HBpositivedirection2 = (TH1F*)h2CeffHBpositivedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBpositivedirection2 ->Fill(i,ccc4x6);HBpositivedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HB 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBpositivedirection2);
	   HBpositivedirection2 ->SetMarkerStyle(20);HBpositivedirection2 ->SetMarkerSize(0.4);HBpositivedirection2 ->GetYaxis()->SetLabelSize(0.04);HBpositivedirection2 ->SetMarkerColor(2);HBpositivedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHBpositivedirection2 == 1) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi =  6 \b");
	   if(kcountHBpositivedirection2 == 5) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi =  7 \b");
	   if(kcountHBpositivedirection2 == 9) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi =  8 \b");
	   if(kcountHBpositivedirection2 ==13) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi =  9 \b");
	   if(kcountHBpositivedirection2 ==17) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi = 10 \b");
	   if(kcountHBpositivedirection2 ==21) HBpositivedirection2 ->SetXTitle("HB jeta = 11; jphi = 11 \b");
	   
	   if(kcountHBpositivedirection2 == 2) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi =  6 \b");
	   if(kcountHBpositivedirection2 == 6) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi =  7 \b");
	   if(kcountHBpositivedirection2 ==10) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi =  8 \b");
	   if(kcountHBpositivedirection2 ==14) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi =  9 \b");
	   if(kcountHBpositivedirection2 ==18) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi = 10 \b");
	   if(kcountHBpositivedirection2 ==22) HBpositivedirection2 ->SetXTitle("HB jeta = 12; jphi = 11 \b");
	   
	   if(kcountHBpositivedirection2 == 3) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi =  6 \b");
	   if(kcountHBpositivedirection2 == 7) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi =  7 \b");
	   if(kcountHBpositivedirection2 ==11) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi =  8 \b");
	   if(kcountHBpositivedirection2 ==15) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi =  9 \b");
	   if(kcountHBpositivedirection2 ==19) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi = 10 \b");
	   if(kcountHBpositivedirection2 ==23) HBpositivedirection2 ->SetXTitle("HB jeta = 13; jphi = 11 \b");
	   
	   if(kcountHBpositivedirection2 == 4) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi =  6 \b");
	   if(kcountHBpositivedirection2 == 8) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi =  7 \b");
	   if(kcountHBpositivedirection2 ==12) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi =  8 \b");
	   if(kcountHBpositivedirection2 ==16) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi =  9 \b");
	   if(kcountHBpositivedirection2 ==20) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi = 10 \b");
	   if(kcountHBpositivedirection2 ==24) HBpositivedirection2 ->SetXTitle("HB jeta = 14; jphi = 11 \b");
   
	   HBpositivedirection2->Draw("Error");
	   kcountHBpositivedirection2++;
	   if(kcountHBpositivedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-positive-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBpositivedirection2) delete h2CeffHBpositivedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 18   HB:: j = 7,8,9,10            11,12,13,14       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HB positive direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHBpositivedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHBpositivedirection3 = new TH1F("h2CeffHBpositivedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	       	     cout<<"HB 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHBpositivedirection3   =     "<<kcountHBpositivedirection3  <<endl;
	   TH1F *HBpositivedirection3 = (TH1F*)h2CeffHBpositivedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HBpositivedirection3 ->Fill(i,ccc4x6);HBpositivedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HB 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHBpositivedirection3);
	   HBpositivedirection3 ->SetMarkerStyle(20);HBpositivedirection3 ->SetMarkerSize(0.4);HBpositivedirection3 ->GetYaxis()->SetLabelSize(0.04);HBpositivedirection3 ->SetMarkerColor(2);HBpositivedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHBpositivedirection3 == 1) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 12 \b");
	   if(kcountHBpositivedirection3 == 5) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 13 \b");
	   if(kcountHBpositivedirection3 == 9) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 14 \b");
	   if(kcountHBpositivedirection3 ==13) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 15 \b");
	   if(kcountHBpositivedirection3 ==17) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 16 \b");
	   if(kcountHBpositivedirection3 ==21) HBpositivedirection3 ->SetXTitle("HB jeta = 11; jphi = 17 \b");
	   
	   if(kcountHBpositivedirection3 == 2) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 12 \b");
	   if(kcountHBpositivedirection3 == 6) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 13 \b");
	   if(kcountHBpositivedirection3 ==10) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 14 \b");
	   if(kcountHBpositivedirection3 ==14) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 15 \b");
	   if(kcountHBpositivedirection3 ==18) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 16 \b");
	   if(kcountHBpositivedirection3 ==22) HBpositivedirection3 ->SetXTitle("HB jeta = 12; jphi = 17 \b");
	   
	   if(kcountHBpositivedirection3 == 3) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 12 \b");
	   if(kcountHBpositivedirection3 == 7) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 13 \b");
	   if(kcountHBpositivedirection3 ==11) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 14 \b");
	   if(kcountHBpositivedirection3 ==15) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 15 \b");
	   if(kcountHBpositivedirection3 ==19) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 16 \b");
	   if(kcountHBpositivedirection3 ==23) HBpositivedirection3 ->SetXTitle("HB jeta = 13; jphi = 17 \b");
	   
	   if(kcountHBpositivedirection3 == 4) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 12 \b");
	   if(kcountHBpositivedirection3 == 8) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 13 \b");
	   if(kcountHBpositivedirection3 ==12) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 14 \b");
	   if(kcountHBpositivedirection3 ==16) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 15 \b");
	   if(kcountHBpositivedirection3 ==20) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 16 \b");
	   if(kcountHBpositivedirection3 ==24) HBpositivedirection3 ->SetXTitle("HB jeta = 14; jphi = 17 \b");

	   HBpositivedirection3->Draw("Error");
	   kcountHBpositivedirection3++;
	   if(kcountHBpositivedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HB-positive-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHBpositivedirection3) delete h2CeffHBpositivedirection3;
       ////////////////////////////////////////////////////////////////////////////////////

       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       for(int jphi=0;jphi<njphi;jphi++){for(int jeta=0;jeta<njeta;jeta++){for(int i=0;i<nx;i++){alexhf[jeta][jphi][i] = 0.;}}}
       
       ////////////////////////////////////////////////////////////////////////////////////   end HB RBX  



  ////////////////////////////////////////////////////////////////////////////////////     HE::  HESTART HE: j = 3,4,5, 6, 7      14,15,16,17,18  
  //======================================================================
    //======================================================================
      //======================================================================
      cout<<" RBX general for HE **************************" <<endl;
      TH2F *Ghe1KKK= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs1");
      TH2F *Ghe1LLL= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs10");
      TH2F* Ghe1 = (TH2F*)Ghe1LLL->Clone("Ghe1");
      Ghe1->Divide(Ghe1KKK,Ghe1LLL, 1, 1, "B");// average A
      //    Ghe1->Sumw2();
      //      int nx = Ghe1->GetXaxis()->GetNbins(); // # LS
      //    nx = maxbinsRBX; // # LS
      ny = Ghe1->GetYaxis()->GetNbins(); // # jetaphi indexes
       for (int j=1;j<=ny;j++) {
	 int jeta = (j-1)/njphi;// jeta = 0-21
	 if( (jeta< 8 && jeta> 2) ||(jeta< 19 && jeta> 13)  ) {
	   int jphi = (j-1)-njphi*jeta;// jphi=0-17 
	   //	   cout<<"HE 54        jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   // over LS:
	   for (int i=1;i<=nx;i++) {
	     double ccc1 =  Ghe1->GetBinContent(i,j);
	     alexhf[jeta][jphi][i-1] = ccc1;
	     //	     if( i == 1 ) cout<<"HE 54  for LS=1      ccc1=     "<< ccc1 <<endl;
	   }//i
	 }//if
       }//j
      // clean-up
      if (Ghe1KKK) delete Ghe1KKK;
      if (Ghe1LLL) delete Ghe1LLL;
      if (Ghe1) delete Ghe1;

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 22   HE:: 2D  jeta = 0 - 21       jphi =0 - 17
       //======================================================================
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HE  2D plot *****" <<endl;
      cRBX1->Clear();
      /////////////////
      cRBX1->Divide(1,1);
      cRBX1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
       TH2F* Ghe42D      = new TH2F("Ghe42D","",   22, -11., 11., 18, 0., 18. );
       TH2F* Ghe42D0     = new TH2F("Ghe42D0","",  22, -11., 11., 18, 0., 18. );
       TH2F* Ghe42DF = (TH2F*)Ghe42D0->Clone("Ghe42DF");
       for (int jphi=0;jphi<njphi;jphi++) {
	 for (int jeta=0;jeta<njeta;jeta++) {
	   for (int i=0;i<nx;i++) {
	     double ccc1 = alexhf[jeta][jphi][i];
	     if(ccc1>0.) {Ghe42D ->Fill(jeta-11,jphi,ccc1); Ghe42D0 ->Fill(jeta-11,jphi,1.); }
	   }}}
       Ghe42DF->Divide(Ghe42D,Ghe42D0, 1, 1, "B");// average A
       //    Ghe1->Sumw2();
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Ghe42DF->SetMarkerStyle(20); Ghe42DF->SetMarkerSize(0.4); Ghe42DF->GetZaxis()->SetLabelSize(0.04); Ghe42DF->SetXTitle("<A>_RBX         #eta  \b"); Ghe42DF->SetYTitle("      #phi \b"); Ghe42DF->SetZTitle("<A>_RBX  - All \b"); Ghe42DF->SetMarkerColor(2); Ghe42DF->SetLineColor(2);      //      Ghe42DF->SetMaximum(1.000);  //      Ghe42DF->SetMinimum(1.0);
       Ghe42DF->Draw("COLZ");
       
       /////////////////
       cRBX1->Update();
       cRBX1->Print("RBX-HE-2Dplot.png");
       cRBX1->Clear();
      // clean-up
      if (Ghe42D) delete Ghe42D;
      if (Ghe42D0) delete Ghe42D0;
      if (Ghe42DF) delete Ghe42DF;

    //========================================================================================== 23   HE: j = 3,4,5, 6, 7      14,15,16,17,18      // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HE negative direction phisector 1 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEnegativedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHEnegativedirection1 = new TH1F("h2CeffHEnegativedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=3;jeta<8;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HE 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HEnegativedirection1 = (TH1F*)h2CeffHEnegativedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEnegativedirection1 ->Fill(i,ccc5x6);HEnegativedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HE 54 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEnegativedirection1);
	   HEnegativedirection1 ->SetMarkerStyle(20);HEnegativedirection1 ->SetMarkerSize(0.4);HEnegativedirection1 ->GetYaxis()->SetLabelSize(0.04);HEnegativedirection1 ->SetMarkerColor(2);HEnegativedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    

	   if(kcountHEnegativedirection1 == 1) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  0 \b");
	   if(kcountHEnegativedirection1 == 6) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  1 \b");
	   if(kcountHEnegativedirection1 ==11) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  2 \b");
	   if(kcountHEnegativedirection1 ==16) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  3 \b");
	   if(kcountHEnegativedirection1 ==21) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  4 \b");
	   if(kcountHEnegativedirection1 ==26) HEnegativedirection1 ->SetXTitle("HE jeta = 3; jphi =  5 \b");
	   
	   if(kcountHEnegativedirection1 == 2) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  0 \b");
	   if(kcountHEnegativedirection1 == 7) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  1 \b");
	   if(kcountHEnegativedirection1 ==12) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  2 \b");
	   if(kcountHEnegativedirection1 ==17) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  3 \b");
	   if(kcountHEnegativedirection1 ==22) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  4 \b");
	   if(kcountHEnegativedirection1 ==27) HEnegativedirection1 ->SetXTitle("HE jeta = 4; jphi =  5 \b");
	   
	   if(kcountHEnegativedirection1 == 3) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  0 \b");
	   if(kcountHEnegativedirection1 == 8) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  1 \b");
	   if(kcountHEnegativedirection1 ==13) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  2 \b");
	   if(kcountHEnegativedirection1 ==18) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  3 \b");
	   if(kcountHEnegativedirection1 ==23) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  4 \b");
	   if(kcountHEnegativedirection1 ==28) HEnegativedirection1 ->SetXTitle("HE jeta = 5; jphi =  5 \b");
	   
	   if(kcountHEnegativedirection1 == 4) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  0 \b");
	   if(kcountHEnegativedirection1 == 9) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  1 \b");
	   if(kcountHEnegativedirection1 ==14) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  2 \b");
	   if(kcountHEnegativedirection1 ==19) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  3 \b");
	   if(kcountHEnegativedirection1 ==24) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  4 \b");
	   if(kcountHEnegativedirection1 ==29) HEnegativedirection1 ->SetXTitle("HE jeta = 6; jphi =  5 \b");

	   if(kcountHEnegativedirection1 == 5) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  0 \b");
	   if(kcountHEnegativedirection1 ==10) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  1 \b");
	   if(kcountHEnegativedirection1 ==15) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  2 \b");
	   if(kcountHEnegativedirection1 ==20) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  3 \b");
	   if(kcountHEnegativedirection1 ==25) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  4 \b");
	   if(kcountHEnegativedirection1 ==30) HEnegativedirection1 ->SetXTitle("HE jeta = 7; jphi =  5 \b");

	   HEnegativedirection1->Draw("Error");
	   kcountHEnegativedirection1++;
	   if(kcountHEnegativedirection1>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-negative-phirange1.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEnegativedirection1) delete h2CeffHEnegativedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 24   HE:: j = 3,4,5, 6, 7      14,15,16,17,18      jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HE negative direction phisector 2 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEnegativedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHEnegativedirection2 = new TH1F("h2CeffHEnegativedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=3;jeta<8;jeta++) {
	   //	       	     cout<<"HE 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHEnegativedirection2   =     "<<kcountHEnegativedirection2  <<endl;
	   TH1F *HEnegativedirection2 = (TH1F*)h2CeffHEnegativedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEnegativedirection2 ->Fill(i,ccc5x6);HEnegativedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HE 55 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEnegativedirection2);
	   HEnegativedirection2 ->SetMarkerStyle(20);HEnegativedirection2 ->SetMarkerSize(0.4);HEnegativedirection2 ->GetYaxis()->SetLabelSize(0.04);HEnegativedirection2 ->SetMarkerColor(2);HEnegativedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();  
  
	   if(kcountHEnegativedirection2 == 1) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi =  6 \b");
	   if(kcountHEnegativedirection2 == 6) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi =  7 \b");
	   if(kcountHEnegativedirection2 ==11) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi =  8 \b");
	   if(kcountHEnegativedirection2 ==16) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi =  9 \b");
	   if(kcountHEnegativedirection2 ==21) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi = 10 \b");
	   if(kcountHEnegativedirection2 ==26) HEnegativedirection2 ->SetXTitle("HE jeta = 3; jphi = 11 \b");
	   
	   if(kcountHEnegativedirection2 == 2) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi =  6 \b");
	   if(kcountHEnegativedirection2 == 7) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi =  7 \b");
	   if(kcountHEnegativedirection2 ==12) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi =  8 \b");
	   if(kcountHEnegativedirection2 ==17) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi =  9 \b");
	   if(kcountHEnegativedirection2 ==22) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi = 10 \b");
	   if(kcountHEnegativedirection2 ==27) HEnegativedirection2 ->SetXTitle("HE jeta = 4; jphi = 11 \b");
	   
	   if(kcountHEnegativedirection2 == 3) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi =  6 \b");
	   if(kcountHEnegativedirection2 == 8) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi =  7 \b");
	   if(kcountHEnegativedirection2 ==13) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi =  8 \b");
	   if(kcountHEnegativedirection2 ==18) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi =  9 \b");
	   if(kcountHEnegativedirection2 ==23) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi = 10 \b");
	   if(kcountHEnegativedirection2 ==28) HEnegativedirection2 ->SetXTitle("HE jeta = 5; jphi = 11 \b");
	   
	   if(kcountHEnegativedirection2 == 4) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi =  6 \b");
	   if(kcountHEnegativedirection2 == 9) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi =  7 \b");
	   if(kcountHEnegativedirection2 ==14) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi =  8 \b");
	   if(kcountHEnegativedirection2 ==19) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi =  9 \b");
	   if(kcountHEnegativedirection2 ==24) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi = 10 \b");
	   if(kcountHEnegativedirection2 ==29) HEnegativedirection2 ->SetXTitle("HE jeta = 6; jphi = 11 \b");

	   if(kcountHEnegativedirection2 == 5) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi =  6 \b");
	   if(kcountHEnegativedirection2 ==10) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi =  7 \b");
	   if(kcountHEnegativedirection2 ==15) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi =  8 \b");
	   if(kcountHEnegativedirection2 ==20) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi =  9 \b");
	   if(kcountHEnegativedirection2 ==25) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi = 10 \b");
	   if(kcountHEnegativedirection2 ==30) HEnegativedirection2 ->SetXTitle("HE jeta = 7; jphi = 11 \b");

	   HEnegativedirection2->Draw("Error");
	   kcountHEnegativedirection2++;
	   if(kcountHEnegativedirection2>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-negative-phirange2.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEnegativedirection2) delete h2CeffHEnegativedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 25   HE:: j = 3,4,5, 6, 7      14,15,16,17,18       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HE negative direction phisector 3 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEnegativedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHEnegativedirection3 = new TH1F("h2CeffHEnegativedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=3;jeta<8;jeta++) {
	   //	       	     cout<<"HE 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHEnegativedirection3   =     "<<kcountHEnegativedirection3  <<endl;
	   TH1F *HEnegativedirection3 = (TH1F*)h2CeffHEnegativedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEnegativedirection3 ->Fill(i,ccc5x6);HEnegativedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HE 55 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEnegativedirection3);
	   HEnegativedirection3 ->SetMarkerStyle(20);HEnegativedirection3 ->SetMarkerSize(0.4);HEnegativedirection3 ->GetYaxis()->SetLabelSize(0.04);HEnegativedirection3 ->SetMarkerColor(2);HEnegativedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHEnegativedirection3 == 1) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 12 \b");
	   if(kcountHEnegativedirection3 == 6) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 13 \b");
	   if(kcountHEnegativedirection3 ==11) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 14 \b");
	   if(kcountHEnegativedirection3 ==16) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 15 \b");
	   if(kcountHEnegativedirection3 ==21) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 16 \b");
	   if(kcountHEnegativedirection3 ==26) HEnegativedirection3 ->SetXTitle("HE jeta = 3; jphi = 17 \b");
	   
	   if(kcountHEnegativedirection3 == 2) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 12 \b");
	   if(kcountHEnegativedirection3 == 7) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 13 \b");
	   if(kcountHEnegativedirection3 ==12) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 14 \b");
	   if(kcountHEnegativedirection3 ==17) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 15 \b");
	   if(kcountHEnegativedirection3 ==22) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 16 \b");
	   if(kcountHEnegativedirection3 ==27) HEnegativedirection3 ->SetXTitle("HE jeta = 4; jphi = 17 \b");
	   
	   if(kcountHEnegativedirection3 == 3) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 12 \b");
	   if(kcountHEnegativedirection3 == 8) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 13 \b");
	   if(kcountHEnegativedirection3 ==13) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 14 \b");
	   if(kcountHEnegativedirection3 ==18) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 15 \b");
	   if(kcountHEnegativedirection3 ==23) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 16 \b");
	   if(kcountHEnegativedirection3 ==28) HEnegativedirection3 ->SetXTitle("HE jeta = 5; jphi = 17 \b");
	   
	   if(kcountHEnegativedirection3 == 4) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 12 \b");
	   if(kcountHEnegativedirection3 == 9) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 13 \b");
	   if(kcountHEnegativedirection3 ==14) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 14 \b");
	   if(kcountHEnegativedirection3 ==19) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 15 \b");
	   if(kcountHEnegativedirection3 ==24) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 16 \b");
	   if(kcountHEnegativedirection3 ==29) HEnegativedirection3 ->SetXTitle("HE jeta = 6; jphi = 17 \b");

	   if(kcountHEnegativedirection3 == 5) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 12 \b");
	   if(kcountHEnegativedirection3 ==10) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 13 \b");
	   if(kcountHEnegativedirection3 ==15) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 14 \b");
	   if(kcountHEnegativedirection3 ==20) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 15 \b");
	   if(kcountHEnegativedirection3 ==25) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 16 \b");
	   if(kcountHEnegativedirection3 ==30) HEnegativedirection3 ->SetXTitle("HE jeta = 7; jphi = 17 \b");
   
	   HEnegativedirection3->Draw("Error");
	   kcountHEnegativedirection3++;
	   if(kcountHEnegativedirection3>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-negative-phirange3.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEnegativedirection3) delete h2CeffHEnegativedirection3;
       ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 26   HE:: j = 3,4,5, 6, 7      14,15,16,17,18     // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HE positive direction phisector 1 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEpositivedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHEpositivedirection1 = new TH1F("h2CeffHEpositivedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=14;jeta<19;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HE 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HEpositivedirection1 = (TH1F*)h2CeffHEpositivedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEpositivedirection1 ->Fill(i,ccc5x6);HEpositivedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HE 54 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEpositivedirection1);
	   HEpositivedirection1 ->SetMarkerStyle(20);HEpositivedirection1 ->SetMarkerSize(0.4);HEpositivedirection1 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection1 ->SetMarkerColor(2);HEpositivedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHEpositivedirection1 == 1) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  0 \b");
	   if(kcountHEpositivedirection1 == 6) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  1 \b");
	   if(kcountHEpositivedirection1 ==11) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  2 \b");
	   if(kcountHEpositivedirection1 ==16) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  3 \b");
	   if(kcountHEpositivedirection1 ==21) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  4 \b");
	   if(kcountHEpositivedirection1 ==26) HEpositivedirection1 ->SetXTitle("HE jeta = 3; jphi =  5 \b");
	   
	   if(kcountHEpositivedirection1 == 2) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  0 \b");
	   if(kcountHEpositivedirection1 == 7) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  1 \b");
	   if(kcountHEpositivedirection1 ==12) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  2 \b");
	   if(kcountHEpositivedirection1 ==17) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  3 \b");
	   if(kcountHEpositivedirection1 ==22) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  4 \b");
	   if(kcountHEpositivedirection1 ==27) HEpositivedirection1 ->SetXTitle("HE jeta = 4; jphi =  5 \b");
	   
	   if(kcountHEpositivedirection1 == 3) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  0 \b");
	   if(kcountHEpositivedirection1 == 8) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  1 \b");
	   if(kcountHEpositivedirection1 ==13) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  2 \b");
	   if(kcountHEpositivedirection1 ==18) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  3 \b");
	   if(kcountHEpositivedirection1 ==23) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  4 \b");
	   if(kcountHEpositivedirection1 ==28) HEpositivedirection1 ->SetXTitle("HE jeta = 5; jphi =  5 \b");
	   
	   if(kcountHEpositivedirection1 == 4) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  0 \b");
	   if(kcountHEpositivedirection1 == 9) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  1 \b");
	   if(kcountHEpositivedirection1 ==14) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  2 \b");
	   if(kcountHEpositivedirection1 ==19) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  3 \b");
	   if(kcountHEpositivedirection1 ==24) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  4 \b");
	   if(kcountHEpositivedirection1 ==29) HEpositivedirection1 ->SetXTitle("HE jeta = 6; jphi =  5 \b");

	   if(kcountHEpositivedirection1 == 5) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  0 \b");
	   if(kcountHEpositivedirection1 ==10) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  1 \b");
	   if(kcountHEpositivedirection1 ==15) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  2 \b");
	   if(kcountHEpositivedirection1 ==20) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  3 \b");
	   if(kcountHEpositivedirection1 ==25) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  4 \b");
	   if(kcountHEpositivedirection1 ==30) HEpositivedirection1 ->SetXTitle("HE jeta = 7; jphi =  5 \b");

	   HEpositivedirection1->Draw("Error");
	   kcountHEpositivedirection1++;
	   if(kcountHEpositivedirection1>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-positive-phirange1.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEpositivedirection1) delete h2CeffHEpositivedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 27   HE:: j = 3,4,5, 6, 7      14,15,16,17,18     jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HE positive direction phisector 2 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEpositivedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHEpositivedirection2 = new TH1F("h2CeffHEpositivedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=14;jeta<19;jeta++) {
	   //	       	     cout<<"HE 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHEpositivedirection2   =     "<<kcountHEpositivedirection2  <<endl;
	   TH1F *HEpositivedirection2 = (TH1F*)h2CeffHEpositivedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEpositivedirection2 ->Fill(i,ccc5x6);HEpositivedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HE 55 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEpositivedirection2);
	   HEpositivedirection2 ->SetMarkerStyle(20);HEpositivedirection2 ->SetMarkerSize(0.4);HEpositivedirection2 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection2 ->SetMarkerColor(2);HEpositivedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHEpositivedirection2 == 1) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi =  6 \b");
	   if(kcountHEpositivedirection2 == 6) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi =  7 \b");
	   if(kcountHEpositivedirection2 ==11) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi =  8 \b");
	   if(kcountHEpositivedirection2 ==16) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi =  9 \b");
	   if(kcountHEpositivedirection2 ==21) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi = 10 \b");
	   if(kcountHEpositivedirection2 ==26) HEpositivedirection2 ->SetXTitle("HE jeta = 3; jphi = 11 \b");
	   
	   if(kcountHEpositivedirection2 == 2) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi =  6 \b");
	   if(kcountHEpositivedirection2 == 7) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi =  7 \b");
	   if(kcountHEpositivedirection2 ==12) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi =  8 \b");
	   if(kcountHEpositivedirection2 ==17) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi =  9 \b");
	   if(kcountHEpositivedirection2 ==22) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi = 10 \b");
	   if(kcountHEpositivedirection2 ==27) HEpositivedirection2 ->SetXTitle("HE jeta = 4; jphi = 11 \b");
	   
	   if(kcountHEpositivedirection2 == 3) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi =  6 \b");
	   if(kcountHEpositivedirection2 == 8) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi =  7 \b");
	   if(kcountHEpositivedirection2 ==13) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi =  8 \b");
	   if(kcountHEpositivedirection2 ==18) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi =  9 \b");
	   if(kcountHEpositivedirection2 ==23) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi = 10 \b");
	   if(kcountHEpositivedirection2 ==28) HEpositivedirection2 ->SetXTitle("HE jeta = 5; jphi = 11 \b");
	   
	   if(kcountHEpositivedirection2 == 4) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi =  6 \b");
	   if(kcountHEpositivedirection2 == 9) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi =  7 \b");
	   if(kcountHEpositivedirection2 ==14) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi =  8 \b");
	   if(kcountHEpositivedirection2 ==19) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi =  9 \b");
	   if(kcountHEpositivedirection2 ==24) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi = 10 \b");
	   if(kcountHEpositivedirection2 ==29) HEpositivedirection2 ->SetXTitle("HE jeta = 6; jphi = 11 \b");

	   if(kcountHEpositivedirection2 == 5) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi =  6 \b");
	   if(kcountHEpositivedirection2 ==10) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi =  7 \b");
	   if(kcountHEpositivedirection2 ==15) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi =  8 \b");
	   if(kcountHEpositivedirection2 ==20) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi =  9 \b");
	   if(kcountHEpositivedirection2 ==25) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi = 10 \b");
	   if(kcountHEpositivedirection2 ==30) HEpositivedirection2 ->SetXTitle("HE jeta = 7; jphi = 11 \b");
   
	   HEpositivedirection2->Draw("Error");
	   kcountHEpositivedirection2++;
	   if(kcountHEpositivedirection2>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-positive-phirange2.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEpositivedirection2) delete h2CeffHEpositivedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 28   HE:: j = 3,4,5, 6, 7      14,15,16,17,18        jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HE positive direction phisector 3 *****" <<endl;
       c5x6->Clear();
       /////////////////
       c5x6->Divide(5,6);
       int kcountHEpositivedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHEpositivedirection3 = new TH1F("h2CeffHEpositivedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=14;jeta<19;jeta++) {
	   //	       	     cout<<"HE 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHEpositivedirection3   =     "<<kcountHEpositivedirection3  <<endl;
	   TH1F *HEpositivedirection3 = (TH1F*)h2CeffHEpositivedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc5x6 = alexhf[jeta][jphi][i];
	     if(ccc5x6>0.) {HEpositivedirection3 ->Fill(i,ccc5x6);HEpositivedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HE 55 PLOTTING  for LS=1      ccc5x6=     "<< ccc5x6 <<endl;
	   }// for i
	   c5x6->cd(kcountHEpositivedirection3);
	   HEpositivedirection3 ->SetMarkerStyle(20);HEpositivedirection3 ->SetMarkerSize(0.4);HEpositivedirection3 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection3 ->SetMarkerColor(2);HEpositivedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHEpositivedirection3 == 1) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 12 \b");
	   if(kcountHEpositivedirection3 == 6) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 13 \b");
	   if(kcountHEpositivedirection3 ==11) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 14 \b");
	   if(kcountHEpositivedirection3 ==16) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 15 \b");
	   if(kcountHEpositivedirection3 ==21) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 16 \b");
	   if(kcountHEpositivedirection3 ==26) HEpositivedirection3 ->SetXTitle("HE jeta = 3; jphi = 17 \b");
	   
	   if(kcountHEpositivedirection3 == 2) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 12 \b");
	   if(kcountHEpositivedirection3 == 7) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 13 \b");
	   if(kcountHEpositivedirection3 ==12) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 14 \b");
	   if(kcountHEpositivedirection3 ==17) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 15 \b");
	   if(kcountHEpositivedirection3 ==22) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 16 \b");
	   if(kcountHEpositivedirection3 ==27) HEpositivedirection3 ->SetXTitle("HE jeta = 4; jphi = 17 \b");
	   
	   if(kcountHEpositivedirection3 == 3) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 12 \b");
	   if(kcountHEpositivedirection3 == 8) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 13 \b");
	   if(kcountHEpositivedirection3 ==13) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 14 \b");
	   if(kcountHEpositivedirection3 ==18) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 15 \b");
	   if(kcountHEpositivedirection3 ==23) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 16 \b");
	   if(kcountHEpositivedirection3 ==28) HEpositivedirection3 ->SetXTitle("HE jeta = 5; jphi = 17 \b");
	   
	   if(kcountHEpositivedirection3 == 4) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 12 \b");
	   if(kcountHEpositivedirection3 == 9) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 13 \b");
	   if(kcountHEpositivedirection3 ==14) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 14 \b");
	   if(kcountHEpositivedirection3 ==19) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 15 \b");
	   if(kcountHEpositivedirection3 ==24) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 16 \b");
	   if(kcountHEpositivedirection3 ==29) HEpositivedirection3 ->SetXTitle("HE jeta = 6; jphi = 17 \b");

	   if(kcountHEpositivedirection3 == 5) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 12 \b");
	   if(kcountHEpositivedirection3 ==10) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 13 \b");
	   if(kcountHEpositivedirection3 ==15) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 14 \b");
	   if(kcountHEpositivedirection3 ==20) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 15 \b");
	   if(kcountHEpositivedirection3 ==25) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 16 \b");
	   if(kcountHEpositivedirection3 ==30) HEpositivedirection3 ->SetXTitle("HE jeta = 7; jphi = 17 \b");

	   HEpositivedirection3->Draw("Error");
	   kcountHEpositivedirection3++;
	   if(kcountHEpositivedirection3>30) break;// 5x6 = 30 
	 }// for jphi
       }//for jeta
       /////////////////
       c5x6->Update();
       c5x6->Print("RBX-HE-positive-phirange3.png");
       c5x6->Clear();
      // clean-up
      if (h2CeffHEpositivedirection3) delete h2CeffHEpositivedirection3;
       ////////////////////////////////////////////////////////////////////////////////////

       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       for(int jphi=0;jphi<njphi;jphi++){for(int jeta=0;jeta<njeta;jeta++){for(int i=0;i<nx;i++){alexhf[jeta][jphi][i] = 0.;}}}
       
       ////////////////////////////////////////////////////////////////////////////////////   end HE RBX  





  ////////////////////////////////////////////////////////////////////////////////////     HO::  HOSTART HO: j = 7,8,9,10            11,12,13,14
  //======================================================================
    //======================================================================
      //======================================================================
      cout<<" RBX general for HO **************************" <<endl;
      TH2F *Gho1KKK= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs2");
      TH2F *Gho1LLL= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs20");
      TH2F* Gho1 = (TH2F*)Gho1LLL->Clone("Gho1");
      Gho1->Divide(Gho1KKK,Gho1LLL, 1, 1, "B");// average A
      //    Gho1->Sumw2();
      //      int nx = Gho1->GetXaxis()->GetNbins(); // # LS
      //    nx = maxbinsRBX; // # LS
      ny = Gho1->GetYaxis()->GetNbins(); // # jetaphi indexes
       for (int j=1;j<=ny;j++) {
	 int jeta = (j-1)/njphi;// jeta = 0-21
	 if(jeta < 15 && jeta > 6 ) {
	   int jphi = (j-1)-njphi*jeta;// jphi=0-17 
	   //	   cout<<"HO 54        jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   // over LS:
	   for (int i=1;i<=nx;i++) {
	     double ccc1 =  Gho1->GetBinContent(i,j);
	     alexhf[jeta][jphi][i-1] = ccc1;
	     //	     if( i == 1 ) cout<<"HO 54  for LS=1      ccc1=     "<< ccc1 <<endl;
	   }//i
	 }//if
       }//j
      // clean-up
      if (Gho1KKK) delete Gho1KKK;
      if (Gho1LLL) delete Gho1LLL;
      if (Gho1) delete Gho1;

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 33   HO:: 2D  jeta = 0 - 21       jphi =0 - 17
       //======================================================================
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HO  2D plot *****" <<endl;
      cRBX1->Clear();
      /////////////////
      cRBX1->Divide(1,1);
      cRBX1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
       TH2F* Gho42D      = new TH2F("Gho42D","",   22, -11., 11., 18, 0., 18. );
       TH2F* Gho42D0     = new TH2F("Gho42D0","",  22, -11., 11., 18, 0., 18. );
       TH2F* Gho42DF = (TH2F*)Gho42D0->Clone("Gho42DF");
       for (int jphi=0;jphi<njphi;jphi++) {
	 for (int jeta=0;jeta<njeta;jeta++) {
	   for (int i=0;i<nx;i++) {
	     double ccc1 = alexhf[jeta][jphi][i];
	     if(ccc1>0.) {Gho42D ->Fill(jeta-11,jphi,ccc1); Gho42D0 ->Fill(jeta-11,jphi,1.); }
	   }}}
       Gho42DF->Divide(Gho42D,Gho42D0, 1, 1, "B");// average A
       //    Gho1->Sumw2();
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Gho42DF->SetMarkerStyle(20); Gho42DF->SetMarkerSize(0.4); Gho42DF->GetZaxis()->SetLabelSize(0.04); Gho42DF->SetXTitle("<A>_RBX         #eta  \b"); Gho42DF->SetYTitle("      #phi \b"); Gho42DF->SetZTitle("<A>_RBX  - All \b"); Gho42DF->SetMarkerColor(2); Gho42DF->SetLineColor(2);      //      Gho42DF->SetMaximum(1.000);  //      Gho42DF->SetMinimum(1.0);
       Gho42DF->Draw("COLZ");
       
       /////////////////
       cRBX1->Update();
       cRBX1->Print("RBX-HO-2Dplot.png");
       cRBX1->Clear();
      // clean-up
      if (Gho42D) delete Gho42D;
      if (Gho42D0) delete Gho42D0;
      if (Gho42DF) delete Gho42DF;

    //========================================================================================== 35   HO:: j = 7,8,9,10            11,12,13,14     // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HO negative direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOnegativedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHOnegativedirection1 = new TH1F("h2CeffHOnegativedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HO 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HOnegativedirection1 = (TH1F*)h2CeffHOnegativedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOnegativedirection1 ->Fill(i,ccc4x6);HOnegativedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HO 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOnegativedirection1);
	   HOnegativedirection1 ->SetMarkerStyle(20);HOnegativedirection1 ->SetMarkerSize(0.4);HOnegativedirection1 ->GetYaxis()->SetLabelSize(0.04);HOnegativedirection1 ->SetMarkerColor(2);HOnegativedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    

	   if(kcountHOnegativedirection1 == 1) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  0 \b");
	   if(kcountHOnegativedirection1 == 5) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  1 \b");
	   if(kcountHOnegativedirection1 == 9) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  2 \b");
	   if(kcountHOnegativedirection1 ==13) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  3 \b");
	   if(kcountHOnegativedirection1 ==17) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  4 \b");
	   if(kcountHOnegativedirection1 ==21) HOnegativedirection1 ->SetXTitle("HO jeta = 7; jphi =  5 \b");
	   
	   if(kcountHOnegativedirection1 == 2) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  0 \b");
	   if(kcountHOnegativedirection1 == 6) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  1 \b");
	   if(kcountHOnegativedirection1 ==10) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  2 \b");
	   if(kcountHOnegativedirection1 ==14) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  3 \b");
	   if(kcountHOnegativedirection1 ==18) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  4 \b");
	   if(kcountHOnegativedirection1 ==22) HOnegativedirection1 ->SetXTitle("HO jeta = 8; jphi =  5 \b");
	   
	   if(kcountHOnegativedirection1 == 3) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  0 \b");
	   if(kcountHOnegativedirection1 == 7) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  1 \b");
	   if(kcountHOnegativedirection1 ==11) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  2 \b");
	   if(kcountHOnegativedirection1 ==15) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  3 \b");
	   if(kcountHOnegativedirection1 ==19) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  4 \b");
	   if(kcountHOnegativedirection1 ==23) HOnegativedirection1 ->SetXTitle("HO jeta = 9; jphi =  5 \b");
	   
	   if(kcountHOnegativedirection1 == 4) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  0 \b");
	   if(kcountHOnegativedirection1 == 8) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  1 \b");
	   if(kcountHOnegativedirection1 ==12) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  2 \b");
	   if(kcountHOnegativedirection1 ==16) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  3 \b");
	   if(kcountHOnegativedirection1 ==20) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  4 \b");
	   if(kcountHOnegativedirection1 ==24) HOnegativedirection1 ->SetXTitle("HO jeta =10; jphi =  5 \b");

	   HOnegativedirection1->Draw("Error");
	   kcountHOnegativedirection1++;
	   if(kcountHOnegativedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-negative-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOnegativedirection1) delete h2CeffHOnegativedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 36   HO:: j = 7,8,9,10            11,12,13,14      jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HO negative direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOnegativedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHOnegativedirection2 = new TH1F("h2CeffHOnegativedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	       	     cout<<"HO 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHOnegativedirection2   =     "<<kcountHOnegativedirection2  <<endl;
	   TH1F *HOnegativedirection2 = (TH1F*)h2CeffHOnegativedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOnegativedirection2 ->Fill(i,ccc4x6);HOnegativedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HO 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOnegativedirection2);
	   HOnegativedirection2 ->SetMarkerStyle(20);HOnegativedirection2 ->SetMarkerSize(0.4);HOnegativedirection2 ->GetYaxis()->SetLabelSize(0.04);HOnegativedirection2 ->SetMarkerColor(2);HOnegativedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();  
  
	   if(kcountHOnegativedirection2 == 1) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi =  6 \b");
	   if(kcountHOnegativedirection2 == 5) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi =  7 \b");
	   if(kcountHOnegativedirection2 == 9) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi =  8 \b");
	   if(kcountHOnegativedirection2 ==13) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi =  9 \b");
	   if(kcountHOnegativedirection2 ==17) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi = 10 \b");
	   if(kcountHOnegativedirection2 ==21) HOnegativedirection2 ->SetXTitle("HO jeta = 7; jphi = 11 \b");
	   
	   if(kcountHOnegativedirection2 == 2) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi =  6 \b");
	   if(kcountHOnegativedirection2 == 6) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi =  7 \b");
	   if(kcountHOnegativedirection2 ==10) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi =  8 \b");
	   if(kcountHOnegativedirection2 ==14) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi =  9 \b");
	   if(kcountHOnegativedirection2 ==18) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi = 10 \b");
	   if(kcountHOnegativedirection2 ==22) HOnegativedirection2 ->SetXTitle("HO jeta = 8; jphi = 11 \b");
	   
	   if(kcountHOnegativedirection2 == 3) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi =  6 \b");
	   if(kcountHOnegativedirection2 == 7) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi =  7 \b");
	   if(kcountHOnegativedirection2 ==11) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi =  8 \b");
	   if(kcountHOnegativedirection2 ==15) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi =  9 \b");
	   if(kcountHOnegativedirection2 ==19) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi = 10 \b");
	   if(kcountHOnegativedirection2 ==23) HOnegativedirection2 ->SetXTitle("HO jeta = 9; jphi = 11 \b");
	   
	   if(kcountHOnegativedirection2 == 4) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi =  6 \b");
	   if(kcountHOnegativedirection2 == 8) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi =  7 \b");
	   if(kcountHOnegativedirection2 ==12) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi =  8 \b");
	   if(kcountHOnegativedirection2 ==16) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi =  9 \b");
	   if(kcountHOnegativedirection2 ==20) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi = 10 \b");
	   if(kcountHOnegativedirection2 ==24) HOnegativedirection2 ->SetXTitle("HO jeta =10; jphi = 11 \b");

	   HOnegativedirection2->Draw("Error");
	   kcountHOnegativedirection2++;
	   if(kcountHOnegativedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-negative-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOnegativedirection2) delete h2CeffHOnegativedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 37   HO:: j = 7,8,9,10            11,12,13,14       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HO negative direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOnegativedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHOnegativedirection3 = new TH1F("h2CeffHOnegativedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=7;jeta<11;jeta++) {
	   //	       	     cout<<"HO 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHOnegativedirection3   =     "<<kcountHOnegativedirection3  <<endl;
	   TH1F *HOnegativedirection3 = (TH1F*)h2CeffHOnegativedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOnegativedirection3 ->Fill(i,ccc4x6);HOnegativedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HO 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOnegativedirection3);
	   HOnegativedirection3 ->SetMarkerStyle(20);HOnegativedirection3 ->SetMarkerSize(0.4);HOnegativedirection3 ->GetYaxis()->SetLabelSize(0.04);HOnegativedirection3 ->SetMarkerColor(2);HOnegativedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHOnegativedirection3 == 1) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 12 \b");
	   if(kcountHOnegativedirection3 == 5) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 13 \b");
	   if(kcountHOnegativedirection3 == 9) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 14 \b");
	   if(kcountHOnegativedirection3 ==13) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 15 \b");
	   if(kcountHOnegativedirection3 ==17) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 16 \b");
	   if(kcountHOnegativedirection3 ==21) HOnegativedirection3 ->SetXTitle("HO jeta = 7; jphi = 17 \b");
	   
	   if(kcountHOnegativedirection3 == 2) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 12 \b");
	   if(kcountHOnegativedirection3 == 6) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 13 \b");
	   if(kcountHOnegativedirection3 ==10) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 14 \b");
	   if(kcountHOnegativedirection3 ==14) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 15 \b");
	   if(kcountHOnegativedirection3 ==18) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 16 \b");
	   if(kcountHOnegativedirection3 ==22) HOnegativedirection3 ->SetXTitle("HO jeta = 8; jphi = 17 \b");
	   
	   if(kcountHOnegativedirection3 == 3) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 12 \b");
	   if(kcountHOnegativedirection3 == 7) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 13 \b");
	   if(kcountHOnegativedirection3 ==11) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 14 \b");
	   if(kcountHOnegativedirection3 ==15) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 15 \b");
	   if(kcountHOnegativedirection3 ==19) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 16 \b");
	   if(kcountHOnegativedirection3 ==23) HOnegativedirection3 ->SetXTitle("HO jeta = 9; jphi = 17 \b");
	   
	   if(kcountHOnegativedirection3 == 4) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 12 \b");
	   if(kcountHOnegativedirection3 == 8) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 13 \b");
	   if(kcountHOnegativedirection3 ==12) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 14 \b");
	   if(kcountHOnegativedirection3 ==16) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 15 \b");
	   if(kcountHOnegativedirection3 ==20) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 16 \b");
	   if(kcountHOnegativedirection3 ==24) HOnegativedirection3 ->SetXTitle("HO jeta =10; jphi = 17 \b");
   
	   HOnegativedirection3->Draw("Error");
	   kcountHOnegativedirection3++;
	   if(kcountHOnegativedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-negative-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOnegativedirection3) delete h2CeffHOnegativedirection3;
       ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 38   HO:: j = 7,8,9,10            11,12,13,14     // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HO positive direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOpositivedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHOpositivedirection1 = new TH1F("h2CeffHOpositivedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HO 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HOpositivedirection1 = (TH1F*)h2CeffHOpositivedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOpositivedirection1 ->Fill(i,ccc4x6);HOpositivedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HO 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOpositivedirection1);
	   HOpositivedirection1 ->SetMarkerStyle(20);HOpositivedirection1 ->SetMarkerSize(0.4);HOpositivedirection1 ->GetYaxis()->SetLabelSize(0.04);HOpositivedirection1 ->SetMarkerColor(2);HOpositivedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHOpositivedirection1 == 1) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  0 \b");
	   if(kcountHOpositivedirection1 == 5) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  1 \b");
	   if(kcountHOpositivedirection1 == 9) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  2 \b");
	   if(kcountHOpositivedirection1 ==13) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  3 \b");
	   if(kcountHOpositivedirection1 ==17) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  4 \b");
	   if(kcountHOpositivedirection1 ==21) HOpositivedirection1 ->SetXTitle("HO jeta = 11; jphi =  5 \b");
	   
	   if(kcountHOpositivedirection1 == 2) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  0 \b");
	   if(kcountHOpositivedirection1 == 6) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  1 \b");
	   if(kcountHOpositivedirection1 ==10) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  2 \b");
	   if(kcountHOpositivedirection1 ==14) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  3 \b");
	   if(kcountHOpositivedirection1 ==18) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  4 \b");
	   if(kcountHOpositivedirection1 ==22) HOpositivedirection1 ->SetXTitle("HO jeta = 12; jphi =  5 \b");
	   
	   if(kcountHOpositivedirection1 == 3) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  0 \b");
	   if(kcountHOpositivedirection1 == 7) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  1 \b");
	   if(kcountHOpositivedirection1 ==11) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  2 \b");
	   if(kcountHOpositivedirection1 ==15) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  3 \b");
	   if(kcountHOpositivedirection1 ==19) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  4 \b");
	   if(kcountHOpositivedirection1 ==23) HOpositivedirection1 ->SetXTitle("HO jeta = 13; jphi =  5 \b");
	   
	   if(kcountHOpositivedirection1 == 4) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  0 \b");
	   if(kcountHOpositivedirection1 == 8) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  1 \b");
	   if(kcountHOpositivedirection1 ==12) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  2 \b");
	   if(kcountHOpositivedirection1 ==16) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  3 \b");
	   if(kcountHOpositivedirection1 ==20) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  4 \b");
	   if(kcountHOpositivedirection1 ==24) HOpositivedirection1 ->SetXTitle("HO jeta = 14; jphi =  5 \b");

	   HOpositivedirection1->Draw("Error");
	   kcountHOpositivedirection1++;
	   if(kcountHOpositivedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-positive-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOpositivedirection1) delete h2CeffHOpositivedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 39   HO:: j = 7,8,9,10            11,12,13,14       jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HO positive direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOpositivedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHOpositivedirection2 = new TH1F("h2CeffHOpositivedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	       	     cout<<"HO 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHOpositivedirection2   =     "<<kcountHOpositivedirection2  <<endl;
	   TH1F *HOpositivedirection2 = (TH1F*)h2CeffHOpositivedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOpositivedirection2 ->Fill(i,ccc4x6);HOpositivedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HO 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOpositivedirection2);
	   HOpositivedirection2 ->SetMarkerStyle(20);HOpositivedirection2 ->SetMarkerSize(0.4);HOpositivedirection2 ->GetYaxis()->SetLabelSize(0.04);HOpositivedirection2 ->SetMarkerColor(2);HOpositivedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHOpositivedirection2 == 1) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi =  6 \b");
	   if(kcountHOpositivedirection2 == 5) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi =  7 \b");
	   if(kcountHOpositivedirection2 == 9) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi =  8 \b");
	   if(kcountHOpositivedirection2 ==13) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi =  9 \b");
	   if(kcountHOpositivedirection2 ==17) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi = 10 \b");
	   if(kcountHOpositivedirection2 ==21) HOpositivedirection2 ->SetXTitle("HO jeta = 11; jphi = 11 \b");
	   
	   if(kcountHOpositivedirection2 == 2) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi =  6 \b");
	   if(kcountHOpositivedirection2 == 6) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi =  7 \b");
	   if(kcountHOpositivedirection2 ==10) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi =  8 \b");
	   if(kcountHOpositivedirection2 ==14) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi =  9 \b");
	   if(kcountHOpositivedirection2 ==18) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi = 10 \b");
	   if(kcountHOpositivedirection2 ==22) HOpositivedirection2 ->SetXTitle("HO jeta = 12; jphi = 11 \b");
	   
	   if(kcountHOpositivedirection2 == 3) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi =  6 \b");
	   if(kcountHOpositivedirection2 == 7) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi =  7 \b");
	   if(kcountHOpositivedirection2 ==11) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi =  8 \b");
	   if(kcountHOpositivedirection2 ==15) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi =  9 \b");
	   if(kcountHOpositivedirection2 ==19) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi = 10 \b");
	   if(kcountHOpositivedirection2 ==23) HOpositivedirection2 ->SetXTitle("HO jeta = 13; jphi = 11 \b");
	   
	   if(kcountHOpositivedirection2 == 4) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi =  6 \b");
	   if(kcountHOpositivedirection2 == 8) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi =  7 \b");
	   if(kcountHOpositivedirection2 ==12) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi =  8 \b");
	   if(kcountHOpositivedirection2 ==16) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi =  9 \b");
	   if(kcountHOpositivedirection2 ==20) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi = 10 \b");
	   if(kcountHOpositivedirection2 ==24) HOpositivedirection2 ->SetXTitle("HO jeta = 14; jphi = 11 \b");
   
	   HOpositivedirection2->Draw("Error");
	   kcountHOpositivedirection2++;
	   if(kcountHOpositivedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-positive-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOpositivedirection2) delete h2CeffHOpositivedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 40   HO:: j = 7,8,9,10            11,12,13,14       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HO positive direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHOpositivedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHOpositivedirection3 = new TH1F("h2CeffHOpositivedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=11;jeta<15;jeta++) {
	   //	       	     cout<<"HO 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHOpositivedirection3   =     "<<kcountHOpositivedirection3  <<endl;
	   TH1F *HOpositivedirection3 = (TH1F*)h2CeffHOpositivedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HOpositivedirection3 ->Fill(i,ccc4x6);HOpositivedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HO 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHOpositivedirection3);
	   HOpositivedirection3 ->SetMarkerStyle(20);HOpositivedirection3 ->SetMarkerSize(0.4);HOpositivedirection3 ->GetYaxis()->SetLabelSize(0.04);HOpositivedirection3 ->SetMarkerColor(2);HOpositivedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHOpositivedirection3 == 1) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 12 \b");
	   if(kcountHOpositivedirection3 == 5) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 13 \b");
	   if(kcountHOpositivedirection3 == 9) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 14 \b");
	   if(kcountHOpositivedirection3 ==13) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 15 \b");
	   if(kcountHOpositivedirection3 ==17) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 16 \b");
	   if(kcountHOpositivedirection3 ==21) HOpositivedirection3 ->SetXTitle("HO jeta = 11; jphi = 17 \b");
	   
	   if(kcountHOpositivedirection3 == 2) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 12 \b");
	   if(kcountHOpositivedirection3 == 6) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 13 \b");
	   if(kcountHOpositivedirection3 ==10) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 14 \b");
	   if(kcountHOpositivedirection3 ==14) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 15 \b");
	   if(kcountHOpositivedirection3 ==18) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 16 \b");
	   if(kcountHOpositivedirection3 ==22) HOpositivedirection3 ->SetXTitle("HO jeta = 12; jphi = 17 \b");
	   
	   if(kcountHOpositivedirection3 == 3) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 12 \b");
	   if(kcountHOpositivedirection3 == 7) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 13 \b");
	   if(kcountHOpositivedirection3 ==11) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 14 \b");
	   if(kcountHOpositivedirection3 ==15) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 15 \b");
	   if(kcountHOpositivedirection3 ==19) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 16 \b");
	   if(kcountHOpositivedirection3 ==23) HOpositivedirection3 ->SetXTitle("HO jeta = 13; jphi = 17 \b");
	   
	   if(kcountHOpositivedirection3 == 4) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 12 \b");
	   if(kcountHOpositivedirection3 == 8) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 13 \b");
	   if(kcountHOpositivedirection3 ==12) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 14 \b");
	   if(kcountHOpositivedirection3 ==16) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 15 \b");
	   if(kcountHOpositivedirection3 ==20) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 16 \b");
	   if(kcountHOpositivedirection3 ==24) HOpositivedirection3 ->SetXTitle("HO jeta = 14; jphi = 17 \b");

	   HOpositivedirection3->Draw("Error");
	   kcountHOpositivedirection3++;
	   if(kcountHOpositivedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HO-positive-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHOpositivedirection3) delete h2CeffHOpositivedirection3;
       ////////////////////////////////////////////////////////////////////////////////////

       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       for(int jphi=0;jphi<njphi;jphi++){for(int jeta=0;jeta<njeta;jeta++){for(int i=0;i<nx;i++){alexhf[jeta][jphi][i] = 0.;}}}
       
       ////////////////////////////////////////////////////////////////////////////////////   end HO RBX  










  ////////////////////////////////////////////////////////////////////////////////////     HF::   HFSTART
  //======================================================================
    //======================================================================
      //======================================================================
      cout<<" RBX general for HF **************************" <<endl;
      TH2F *Ghf1KKK= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs3");
      TH2F *Ghf1LLL= (TH2F*)hfile->Get("h_2DsumADCAmplEtaPhiLs30");
      TH2F* Ghf1 = (TH2F*)Ghf1LLL->Clone("Ghf1");
      Ghf1->Divide(Ghf1KKK,Ghf1LLL, 1, 1, "B");// average A
      //    Ghf1->Sumw2();
      //      int nx = Ghf1->GetXaxis()->GetNbins(); // # LS
      //    nx = maxbinsRBX; // # LS
      ny = Ghf1->GetYaxis()->GetNbins(); // # jetaphi indexes
       for (int j=1;j<=ny;j++) {
	 int jeta = (j-1)/njphi;// jeta = 0-21
	 if(jeta < 4 || jeta > 17 ) {
	   int jphi = (j-1)-njphi*jeta;// jphi=0-17 
	   //	   cout<<"HF 54        jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   // over LS:
	   for (int i=1;i<=nx;i++) {
	     double ccc1 =  Ghf1->GetBinContent(i,j);
	     alexhf[jeta][jphi][i-1] = ccc1;
	     //	     if( i == 1 ) cout<<"HF 54  for LS=1      ccc1=     "<< ccc1 <<endl;
	   }//i
	 }//if
       }//j
      // clean-up
      if (Ghf1KKK) delete Ghf1KKK;
      if (Ghf1LLL) delete Ghf1LLL;
      if (Ghf1) delete Ghf1;

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 60   HF:: 2D  jeta = 0 - 21       jphi =0 - 17
       //======================================================================
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HF  2D plot *****" <<endl;
      cRBX1->Clear();
      /////////////////
      cRBX1->Divide(1,1);
      cRBX1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
       TH2F* Ghf42D      = new TH2F("Ghf42D","",   22, -11., 11., 18, 0., 18. );
       TH2F* Ghf42D0     = new TH2F("Ghf42D0","",  22, -11., 11., 18, 0., 18. );
       TH2F* Ghf42DF = (TH2F*)Ghf42D0->Clone("Ghf42DF");
       for (int jphi=0;jphi<njphi;jphi++) {
	 for (int jeta=0;jeta<njeta;jeta++) {
	   for (int i=0;i<nx;i++) {
	     double ccc1 = alexhf[jeta][jphi][i];
	     if(ccc1>0.) {Ghf42D ->Fill(jeta-11,jphi,ccc1); Ghf42D0 ->Fill(jeta-11,jphi,1.); }
	   }}}
       Ghf42DF->Divide(Ghf42D,Ghf42D0, 1, 1, "B");// average A
       //    Ghf1->Sumw2();
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Ghf42DF->SetMarkerStyle(20); Ghf42DF->SetMarkerSize(0.4); Ghf42DF->GetZaxis()->SetLabelSize(0.04); Ghf42DF->SetXTitle("<A>_RBX         #eta  \b"); Ghf42DF->SetYTitle("      #phi \b"); Ghf42DF->SetZTitle("<A>_RBX  - All \b"); Ghf42DF->SetMarkerColor(2); Ghf42DF->SetLineColor(2);      //      Ghf42DF->SetMaximum(1.000);  //      Ghf42DF->SetMinimum(1.0);
       Ghf42DF->Draw("COLZ");
       
       /////////////////
       cRBX1->Update();
       cRBX1->Print("RBX-HF-2Dplot.png");
       cRBX1->Clear();
      // clean-up
      if (Ghf42D) delete Ghf42D;
      if (Ghf42D0) delete Ghf42D0;
      if (Ghf42DF) delete Ghf42DF;

    //========================================================================================== 54   HF:: jeta = 0,1,2, 3            18,19,20,21       // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
       cout<<"      RBX HF negative direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFnegativedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHFnegativedirection1 = new TH1F("h2CeffHFnegativedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=0;jeta<4;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HF 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HFnegativedirection1 = (TH1F*)h2CeffHFnegativedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFnegativedirection1 ->Fill(i,ccc4x6);HFnegativedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HF 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFnegativedirection1);
	   HFnegativedirection1 ->SetMarkerStyle(20);HFnegativedirection1 ->SetMarkerSize(0.4);HFnegativedirection1 ->GetYaxis()->SetLabelSize(0.04);HFnegativedirection1 ->SetMarkerColor(2);HFnegativedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    

	   if(kcountHFnegativedirection1 == 1) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  0 \b");
	   if(kcountHFnegativedirection1 == 5) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  1 \b");
	   if(kcountHFnegativedirection1 == 9) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  2 \b");
	   if(kcountHFnegativedirection1 ==13) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  3 \b");
	   if(kcountHFnegativedirection1 ==17) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  4 \b");
	   if(kcountHFnegativedirection1 ==21) HFnegativedirection1 ->SetXTitle("HF jeta = 0; jphi =  5 \b");
	   
	   if(kcountHFnegativedirection1 == 2) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  0 \b");
	   if(kcountHFnegativedirection1 == 6) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  1 \b");
	   if(kcountHFnegativedirection1 ==10) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  2 \b");
	   if(kcountHFnegativedirection1 ==14) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  3 \b");
	   if(kcountHFnegativedirection1 ==18) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  4 \b");
	   if(kcountHFnegativedirection1 ==22) HFnegativedirection1 ->SetXTitle("HF jeta = 1; jphi =  5 \b");
	   
	   if(kcountHFnegativedirection1 == 3) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  0 \b");
	   if(kcountHFnegativedirection1 == 7) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  1 \b");
	   if(kcountHFnegativedirection1 ==11) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  2 \b");
	   if(kcountHFnegativedirection1 ==15) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  3 \b");
	   if(kcountHFnegativedirection1 ==19) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  4 \b");
	   if(kcountHFnegativedirection1 ==23) HFnegativedirection1 ->SetXTitle("HF jeta = 2; jphi =  5 \b");
	   
	   if(kcountHFnegativedirection1 == 4) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  0 \b");
	   if(kcountHFnegativedirection1 == 8) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  1 \b");
	   if(kcountHFnegativedirection1 ==12) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  2 \b");
	   if(kcountHFnegativedirection1 ==16) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  3 \b");
	   if(kcountHFnegativedirection1 ==20) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  4 \b");
	   if(kcountHFnegativedirection1 ==24) HFnegativedirection1 ->SetXTitle("HF jeta = 3; jphi =  5 \b");

	   HFnegativedirection1->Draw("Error");
	   kcountHFnegativedirection1++;
	   if(kcountHFnegativedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-negative-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFnegativedirection1) delete h2CeffHFnegativedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 55   HF:: jeta = 0,1,2, 3            18,19,20,21       jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
       cout<<"      RBX HF negative direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFnegativedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHFnegativedirection2 = new TH1F("h2CeffHFnegativedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=0;jeta<4;jeta++) {
	   //	       	     cout<<"HF 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHFnegativedirection2   =     "<<kcountHFnegativedirection2  <<endl;
	   TH1F *HFnegativedirection2 = (TH1F*)h2CeffHFnegativedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFnegativedirection2 ->Fill(i,ccc4x6);HFnegativedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HF 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFnegativedirection2);
	   HFnegativedirection2 ->SetMarkerStyle(20);HFnegativedirection2 ->SetMarkerSize(0.4);HFnegativedirection2 ->GetYaxis()->SetLabelSize(0.04);HFnegativedirection2 ->SetMarkerColor(2);HFnegativedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();  
  
	   if(kcountHFnegativedirection2 == 1) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi =  6 \b");
	   if(kcountHFnegativedirection2 == 5) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi =  7 \b");
	   if(kcountHFnegativedirection2 == 9) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi =  8 \b");
	   if(kcountHFnegativedirection2 ==13) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi =  9 \b");
	   if(kcountHFnegativedirection2 ==17) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi = 10 \b");
	   if(kcountHFnegativedirection2 ==21) HFnegativedirection2 ->SetXTitle("HF jeta = 0; jphi = 11 \b");
	   
	   if(kcountHFnegativedirection2 == 2) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi =  6 \b");
	   if(kcountHFnegativedirection2 == 6) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi =  7 \b");
	   if(kcountHFnegativedirection2 ==10) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi =  8 \b");
	   if(kcountHFnegativedirection2 ==14) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi =  9 \b");
	   if(kcountHFnegativedirection2 ==18) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi = 10 \b");
	   if(kcountHFnegativedirection2 ==22) HFnegativedirection2 ->SetXTitle("HF jeta = 1; jphi = 11 \b");
	   
	   if(kcountHFnegativedirection2 == 3) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi =  6 \b");
	   if(kcountHFnegativedirection2 == 7) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi =  7 \b");
	   if(kcountHFnegativedirection2 ==11) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi =  8 \b");
	   if(kcountHFnegativedirection2 ==15) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi =  9 \b");
	   if(kcountHFnegativedirection2 ==19) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi = 10 \b");
	   if(kcountHFnegativedirection2 ==23) HFnegativedirection2 ->SetXTitle("HF jeta = 2; jphi = 11 \b");
	   
	   if(kcountHFnegativedirection2 == 4) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi =  6 \b");
	   if(kcountHFnegativedirection2 == 8) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi =  7 \b");
	   if(kcountHFnegativedirection2 ==12) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi =  8 \b");
	   if(kcountHFnegativedirection2 ==16) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi =  9 \b");
	   if(kcountHFnegativedirection2 ==20) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi = 10 \b");
	   if(kcountHFnegativedirection2 ==24) HFnegativedirection2 ->SetXTitle("HF jeta = 3; jphi = 11 \b");

	   HFnegativedirection2->Draw("Error");
	   kcountHFnegativedirection2++;
	   if(kcountHFnegativedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-negative-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFnegativedirection2) delete h2CeffHFnegativedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 56   HF:: jeta = 0,1,2, 3            18,19,20,21       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HF negative direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFnegativedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHFnegativedirection3 = new TH1F("h2CeffHFnegativedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=0;jeta<4;jeta++) {
	   //	       	     cout<<"HF 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHFnegativedirection3   =     "<<kcountHFnegativedirection3  <<endl;
	   TH1F *HFnegativedirection3 = (TH1F*)h2CeffHFnegativedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFnegativedirection3 ->Fill(i,ccc4x6);HFnegativedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HF 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFnegativedirection3);
	   HFnegativedirection3 ->SetMarkerStyle(20);HFnegativedirection3 ->SetMarkerSize(0.4);HFnegativedirection3 ->GetYaxis()->SetLabelSize(0.04);HFnegativedirection3 ->SetMarkerColor(2);HFnegativedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHFnegativedirection3 == 1) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 12 \b");
	   if(kcountHFnegativedirection3 == 5) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 13 \b");
	   if(kcountHFnegativedirection3 == 9) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 14 \b");
	   if(kcountHFnegativedirection3 ==13) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 15 \b");
	   if(kcountHFnegativedirection3 ==17) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 16 \b");
	   if(kcountHFnegativedirection3 ==21) HFnegativedirection3 ->SetXTitle("HF jeta = 0; jphi = 17 \b");
	   
	   if(kcountHFnegativedirection3 == 2) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 12 \b");
	   if(kcountHFnegativedirection3 == 6) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 13 \b");
	   if(kcountHFnegativedirection3 ==10) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 14 \b");
	   if(kcountHFnegativedirection3 ==14) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 15 \b");
	   if(kcountHFnegativedirection3 ==18) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 16 \b");
	   if(kcountHFnegativedirection3 ==22) HFnegativedirection3 ->SetXTitle("HF jeta = 1; jphi = 17 \b");
	   
	   if(kcountHFnegativedirection3 == 3) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 12 \b");
	   if(kcountHFnegativedirection3 == 7) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 13 \b");
	   if(kcountHFnegativedirection3 ==11) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 14 \b");
	   if(kcountHFnegativedirection3 ==15) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 15 \b");
	   if(kcountHFnegativedirection3 ==19) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 16 \b");
	   if(kcountHFnegativedirection3 ==23) HFnegativedirection3 ->SetXTitle("HF jeta = 2; jphi = 17 \b");
	   
	   if(kcountHFnegativedirection3 == 4) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 12 \b");
	   if(kcountHFnegativedirection3 == 8) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 13 \b");
	   if(kcountHFnegativedirection3 ==12) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 14 \b");
	   if(kcountHFnegativedirection3 ==16) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 15 \b");
	   if(kcountHFnegativedirection3 ==20) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 16 \b");
	   if(kcountHFnegativedirection3 ==24) HFnegativedirection3 ->SetXTitle("HF jeta = 3; jphi = 17 \b");
   
	   HFnegativedirection3->Draw("Error");
	   kcountHFnegativedirection3++;
	   if(kcountHFnegativedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-negative-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFnegativedirection3) delete h2CeffHFnegativedirection3;
       ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 57   HF:: jeta = 0,1,2, 3            18,19,20,21       // jphi = 0,1,2,3,4,5
    //======================================================================
    //======================================================================
    //======================================================================
      cout<<"      RBX HF positive direction phisector 1 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFpositivedirection1=1;
       // j - etaphi index:
       TH1F* h2CeffHFpositivedirection1 = new TH1F("h2CeffHFpositivedirection1","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=0;jphi<6;jphi++) {
	 for (int jeta=18;jeta<22;jeta++) {
	   //	   for (int jphi=0;jphi<njphi;jphi++) {
	   //	     cout<<"HF 54 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	   TH1F *HFpositivedirection1 = (TH1F*)h2CeffHFpositivedirection1->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFpositivedirection1 ->Fill(i,ccc4x6);HFpositivedirection1->SetBinError(i,0.01);}
	     //	       if( i == 0 ) cout<<"HF 54 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFpositivedirection1);
	   HFpositivedirection1 ->SetMarkerStyle(20);HFpositivedirection1 ->SetMarkerSize(0.4);HFpositivedirection1 ->GetYaxis()->SetLabelSize(0.04);HFpositivedirection1 ->SetMarkerColor(2);HFpositivedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHFpositivedirection1 == 1) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  0 \b");
	   if(kcountHFpositivedirection1 == 5) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  1 \b");
	   if(kcountHFpositivedirection1 == 9) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  2 \b");
	   if(kcountHFpositivedirection1 ==13) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  3 \b");
	   if(kcountHFpositivedirection1 ==17) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  4 \b");
	   if(kcountHFpositivedirection1 ==21) HFpositivedirection1 ->SetXTitle("HF jeta = 18; jphi =  5 \b");
	   
	   if(kcountHFpositivedirection1 == 2) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  0 \b");
	   if(kcountHFpositivedirection1 == 6) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  1 \b");
	   if(kcountHFpositivedirection1 ==10) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  2 \b");
	   if(kcountHFpositivedirection1 ==14) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  3 \b");
	   if(kcountHFpositivedirection1 ==18) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  4 \b");
	   if(kcountHFpositivedirection1 ==22) HFpositivedirection1 ->SetXTitle("HF jeta = 19; jphi =  5 \b");
	   
	   if(kcountHFpositivedirection1 == 3) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  0 \b");
	   if(kcountHFpositivedirection1 == 7) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  1 \b");
	   if(kcountHFpositivedirection1 ==11) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  2 \b");
	   if(kcountHFpositivedirection1 ==15) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  3 \b");
	   if(kcountHFpositivedirection1 ==19) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  4 \b");
	   if(kcountHFpositivedirection1 ==23) HFpositivedirection1 ->SetXTitle("HF jeta = 20; jphi =  5 \b");
	   
	   if(kcountHFpositivedirection1 == 4) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  0 \b");
	   if(kcountHFpositivedirection1 == 8) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  1 \b");
	   if(kcountHFpositivedirection1 ==12) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  2 \b");
	   if(kcountHFpositivedirection1 ==16) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  3 \b");
	   if(kcountHFpositivedirection1 ==20) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  4 \b");
	   if(kcountHFpositivedirection1 ==24) HFpositivedirection1 ->SetXTitle("HF jeta = 21; jphi =  5 \b");

	   HFpositivedirection1->Draw("Error");
	   kcountHFpositivedirection1++;
	   if(kcountHFpositivedirection1>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-positive-phirange1.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFpositivedirection1) delete h2CeffHFpositivedirection1;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 58   HF:: jeta = 0,1,2, 3            18,19,20,21       jphi = 6,7,8,9,10,11
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HF positive direction phisector 2 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFpositivedirection2=1;
       // j - etaphi index:
       TH1F* h2CeffHFpositivedirection2 = new TH1F("h2CeffHFpositivedirection2","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=6;jphi<12;jphi++) {
	 for (int jeta=18;jeta<22;jeta++) {
	   //	       	     cout<<"HF 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHFpositivedirection2   =     "<<kcountHFpositivedirection2  <<endl;
	   TH1F *HFpositivedirection2 = (TH1F*)h2CeffHFpositivedirection2->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFpositivedirection2 ->Fill(i,ccc4x6);HFpositivedirection2->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HF 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFpositivedirection2);
	   HFpositivedirection2 ->SetMarkerStyle(20);HFpositivedirection2 ->SetMarkerSize(0.4);HFpositivedirection2 ->GetYaxis()->SetLabelSize(0.04);HFpositivedirection2 ->SetMarkerColor(2);HFpositivedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy(); 

	   if(kcountHFpositivedirection2 == 1) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi =  6 \b");
	   if(kcountHFpositivedirection2 == 5) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi =  7 \b");
	   if(kcountHFpositivedirection2 == 9) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi =  8 \b");
	   if(kcountHFpositivedirection2 ==13) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi =  9 \b");
	   if(kcountHFpositivedirection2 ==17) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi = 10 \b");
	   if(kcountHFpositivedirection2 ==21) HFpositivedirection2 ->SetXTitle("HF jeta = 18; jphi = 11 \b");
	   
	   if(kcountHFpositivedirection2 == 2) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi =  6 \b");
	   if(kcountHFpositivedirection2 == 6) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi =  7 \b");
	   if(kcountHFpositivedirection2 ==10) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi =  8 \b");
	   if(kcountHFpositivedirection2 ==14) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi =  9 \b");
	   if(kcountHFpositivedirection2 ==18) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi = 10 \b");
	   if(kcountHFpositivedirection2 ==22) HFpositivedirection2 ->SetXTitle("HF jeta = 19; jphi = 11 \b");
	   
	   if(kcountHFpositivedirection2 == 3) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi =  6 \b");
	   if(kcountHFpositivedirection2 == 7) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi =  7 \b");
	   if(kcountHFpositivedirection2 ==11) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi =  8 \b");
	   if(kcountHFpositivedirection2 ==15) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi =  9 \b");
	   if(kcountHFpositivedirection2 ==19) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi = 10 \b");
	   if(kcountHFpositivedirection2 ==23) HFpositivedirection2 ->SetXTitle("HF jeta = 20; jphi = 11 \b");
	   
	   if(kcountHFpositivedirection2 == 4) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi =  6 \b");
	   if(kcountHFpositivedirection2 == 8) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi =  7 \b");
	   if(kcountHFpositivedirection2 ==12) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi =  8 \b");
	   if(kcountHFpositivedirection2 ==16) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi =  9 \b");
	   if(kcountHFpositivedirection2 ==20) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi = 10 \b");
	   if(kcountHFpositivedirection2 ==24) HFpositivedirection2 ->SetXTitle("HF jeta = 21; jphi = 11 \b");
   
	   HFpositivedirection2->Draw("Error");
	   kcountHFpositivedirection2++;
	   if(kcountHFpositivedirection2>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-positive-phirange2.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFpositivedirection2) delete h2CeffHFpositivedirection2;
       ////////////////////////////////////////////////////////////////////////////////////
       //========================================================================================== 59   HF:: jeta = 0,1,2, 3            18,19,20,21       jphi =12,13,14,15,16,17
       //======================================================================
       //======================================================================
       //======================================================================
      cout<<"      RBX HF positive direction phisector 3 *****" <<endl;
       c4x6->Clear();
       /////////////////
       c4x6->Divide(4,6);
       int kcountHFpositivedirection3=1;
       // j - etaphi index:
       TH1F* h2CeffHFpositivedirection3 = new TH1F("h2CeffHFpositivedirection3","", maxbinsRBX, 1., maxbinsRBX+1.);
       for (int jphi=12;jphi<18;jphi++) {
	 for (int jeta=18;jeta<22;jeta++) {
	   //	       	     cout<<"HF 55 PLOTTING       jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"   kcountHFpositivedirection3   =     "<<kcountHFpositivedirection3  <<endl;
	   TH1F *HFpositivedirection3 = (TH1F*)h2CeffHFpositivedirection3->Clone("twod1");
	   for (int i=0;i<nx;i++) {
	     double ccc4x6 = alexhf[jeta][jphi][i];
	     if(ccc4x6>0.) {HFpositivedirection3 ->Fill(i,ccc4x6);HFpositivedirection3->SetBinError(i,0.01);}
	     //		 	       if( i == 0 ) cout<<"HF 55 PLOTTING  for LS=1      ccc4x6=     "<< ccc4x6 <<endl;
	   }// for i
	   c4x6->cd(kcountHFpositivedirection3);
	   HFpositivedirection3 ->SetMarkerStyle(20);HFpositivedirection3 ->SetMarkerSize(0.4);HFpositivedirection3 ->GetYaxis()->SetLabelSize(0.04);HFpositivedirection3 ->SetMarkerColor(2);HFpositivedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	   //	   gPad->SetLogy();    
	   if(kcountHFpositivedirection3 == 1) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 12 \b");
	   if(kcountHFpositivedirection3 == 5) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 13 \b");
	   if(kcountHFpositivedirection3 == 9) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 14 \b");
	   if(kcountHFpositivedirection3 ==13) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 15 \b");
	   if(kcountHFpositivedirection3 ==17) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 16 \b");
	   if(kcountHFpositivedirection3 ==21) HFpositivedirection3 ->SetXTitle("HF jeta = 18; jphi = 17 \b");
	   
	   if(kcountHFpositivedirection3 == 2) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 12 \b");
	   if(kcountHFpositivedirection3 == 6) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 13 \b");
	   if(kcountHFpositivedirection3 ==10) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 14 \b");
	   if(kcountHFpositivedirection3 ==14) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 15 \b");
	   if(kcountHFpositivedirection3 ==18) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 16 \b");
	   if(kcountHFpositivedirection3 ==22) HFpositivedirection3 ->SetXTitle("HF jeta = 19; jphi = 17 \b");
	   
	   if(kcountHFpositivedirection3 == 3) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 12 \b");
	   if(kcountHFpositivedirection3 == 7) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 13 \b");
	   if(kcountHFpositivedirection3 ==11) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 14 \b");
	   if(kcountHFpositivedirection3 ==15) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 15 \b");
	   if(kcountHFpositivedirection3 ==19) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 16 \b");
	   if(kcountHFpositivedirection3 ==23) HFpositivedirection3 ->SetXTitle("HF jeta = 20; jphi = 17 \b");
	   
	   if(kcountHFpositivedirection3 == 4) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 12 \b");
	   if(kcountHFpositivedirection3 == 8) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 13 \b");
	   if(kcountHFpositivedirection3 ==12) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 14 \b");
	   if(kcountHFpositivedirection3 ==16) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 15 \b");
	   if(kcountHFpositivedirection3 ==20) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 16 \b");
	   if(kcountHFpositivedirection3 ==24) HFpositivedirection3 ->SetXTitle("HF jeta = 21; jphi = 17 \b");

	   HFpositivedirection3->Draw("Error");
	   kcountHFpositivedirection3++;
	   if(kcountHFpositivedirection3>24) break;// 4x6 = 24 
	 }// for jphi
       }//for jeta
       /////////////////
       c4x6->Update();
       c4x6->Print("RBX-HF-positive-phirange3.png");
       c4x6->Clear();
      // clean-up
      if (h2CeffHFpositivedirection3) delete h2CeffHFpositivedirection3;
       ////////////////////////////////////////////////////////////////////////////////////

       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       cout<<">>>>>>>>>>>>>>>>>>>>>>>>                             "              <<endl;
       //////////////////////////////////////////////////////////////////////////////////// RBX  HF  study END:
       









       //////////////////////////////////////////////////////////////////////////////////// RBX study END:


//////////////////////////////////////////////////////////////////////////////////// Special tests:
//===============================================================================   occupancyHB
// For occupancy plots. Produces OccPlots_HBx.png (x=1)
  int mymaxbins = MaxLum;
  {
    cHB->Clear();
      cHB->Divide(2,1);
      /////////
      cHB->cd(1);
      TH2F *occhbm= (TH2F*)hfile->Get("h_RatioOccupancy_HBM");
      TH1F* uyhbm = new TH1F("uyhbm","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhbm->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhbm->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhbm->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhbm->SetMarkerStyle(20);
      uyhbm->SetMarkerSize(0.6);
      uyhbm->GetYaxis()->SetLabelSize(0.04);
      uyhbm->SetXTitle("min/av occupancy - HBM \b");
      uyhbm->SetMarkerColor(2);
      uyhbm->SetLineColor(0);
      uyhbm->SetMaximum(1.0);
      uyhbm->SetMinimum(0.2);
      gPad->SetGridy();
      uyhbm->Draw("Error");
      /////////
      cHB->cd(2);
      TH2F *occhbp= (TH2F*)hfile->Get("h_RatioOccupancy_HBP");
      TH1F* uyhbp = new TH1F("uyhbp","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhbp->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhbp->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhbp->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhbp->SetMarkerStyle(20);
      uyhbp->SetMarkerSize(0.6);
      uyhbp->GetYaxis()->SetLabelSize(0.04);
      uyhbp->SetXTitle("min/av occupancy - HBP \b");
      uyhbp->SetMarkerColor(2);
      uyhbp->SetLineColor(0);
      uyhbp->SetMaximum(1.0);
      uyhbp->SetMinimum(0.2);
      gPad->SetGridy();
      uyhbp->Draw("Error");
      /////////
      
      /////////
      cHB->Update();
      cHB->Print(Form("OccPlots_HB.png"));
      cHB->Clear();
      
      // clean-up
      if (occhbm) delete occhbm;
      if (uyhbm) delete uyhbm;
      if (occhbp) delete occhbp;
      if (uyhbp) delete uyhbp;
    }     
//===============================================================================   occupancyHE
// For occupancy plots. Produces OccPlots_HEx.png (x=1)
    {
      cHB->Clear();
      cHB->Divide(2,1);
      /////////
      cHB->cd(1);
      TH2F *occhem= (TH2F*)hfile->Get("h_RatioOccupancy_HEM");
      TH1F* uyhem = new TH1F("uyhem","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhem->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhem->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhem->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhem->SetMarkerStyle(20);
      uyhem->SetMarkerSize(0.6);
      uyhem->GetYaxis()->SetLabelSize(0.04);
      uyhem->SetXTitle("min/av occupancy - HEM \b");
      uyhem->SetMarkerColor(2);
      uyhem->SetLineColor(0);
      uyhem->SetMaximum(1.0);
      uyhem->SetMinimum(0.2);
      gPad->SetGridy();
      uyhem->Draw("Error");
      /////////
      cHB->cd(2);
      TH2F *occhep= (TH2F*)hfile->Get("h_RatioOccupancy_HEP");
      TH1F* uyhep = new TH1F("uyhep","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhep->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhep->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhep->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhep->SetMarkerStyle(20);
      uyhep->SetMarkerSize(0.6);
      uyhep->GetYaxis()->SetLabelSize(0.04);
      uyhep->SetXTitle("min/av occupancy - HEP \b");
      uyhep->SetMarkerColor(2);
      uyhep->SetLineColor(0);
      uyhep->SetMaximum(1.0);
      uyhep->SetMinimum(0.2);
      gPad->SetGridy();
      uyhep->Draw("Error");
      /////////
      
      /////////
      cHB->Update();
      cHB->Print(Form("OccPlots_HE.png"));
      cHB->Clear();
      
      // clean-up
      if (occhem) delete occhem;
      if (uyhem) delete uyhem;
      if (occhep) delete occhep;
      if (uyhep) delete uyhep;
    }     
//===============================================================================   occupancyHO
// For occupancy plots. Produces OccPlots_HOx.png (x=1)
    {
      cHB->Clear();
      cHB->Divide(2,1);
      /////////
      cHB->cd(1);
      TH2F *occhom= (TH2F*)hfile->Get("h_RatioOccupancy_HOM");
      TH1F* uyhom = new TH1F("uyhom","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhom->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhom->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhom->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhom->SetMarkerStyle(20);
      uyhom->SetMarkerSize(0.6);
      uyhom->GetYaxis()->SetLabelSize(0.04);
      uyhom->SetXTitle("min/av occupancy - HOM \b");
      uyhom->SetMarkerColor(2);
      uyhom->SetLineColor(0);
      uyhom->SetMaximum(1.0);
      uyhom->SetMinimum(0.2);
      gPad->SetGridy();
      uyhom->Draw("Error");
      /////////
      cHB->cd(2);
      TH2F *occhop= (TH2F*)hfile->Get("h_RatioOccupancy_HOP");
      TH1F* uyhop = new TH1F("uyhop","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhop->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhop->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhop->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhop->SetMarkerStyle(20);
      uyhop->SetMarkerSize(0.6);
      uyhop->GetYaxis()->SetLabelSize(0.04);
      uyhop->SetXTitle("min/av occupancy - HOP \b");
      uyhop->SetMarkerColor(2);
      uyhop->SetLineColor(0);
      uyhop->SetMaximum(1.0);
      uyhop->SetMinimum(0.2);
      gPad->SetGridy();
      uyhop->Draw("Error");
      /////////
      
      /////////
      cHB->Update();
      cHB->Print(Form("OccPlots_HO.png"));
      cHB->Clear();
      
      // clean-up
      if (occhom) delete occhom;
      if (uyhom) delete uyhom;
      if (occhop) delete occhop;
      if (uyhop) delete uyhop;
    }     
//===============================================================================   occupancyHF   
// For occupancy plots. Produces OccPlots_HFx.png (x=1)
    {
      cHB->Clear();
      cHB->Divide(2,1);
      /////////
      cHB->cd(1);
      TH2F *occhfm= (TH2F*)hfile->Get("h_RatioOccupancy_HFM");
      TH1F* uyhfm = new TH1F("uyhfm","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhfm->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhfm->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhfm->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhfm->SetMarkerStyle(20);
      uyhfm->SetMarkerSize(0.6);
      uyhfm->GetYaxis()->SetLabelSize(0.04);
      uyhfm->SetXTitle("min/av occupancy - HFM \b");
      uyhfm->SetMarkerColor(2);
      uyhfm->SetLineColor(0);
      uyhfm->SetMaximum(1.0);
      uyhfm->SetMinimum(0.2);
      gPad->SetGridy();
      uyhfm->Draw("Error");
      /////////
      cHB->cd(2);
      TH2F *occhfp= (TH2F*)hfile->Get("h_RatioOccupancy_HFP");
      TH1F* uyhfp = new TH1F("uyhfp","", mymaxbins, 1., mymaxbins+1.);
      for (int i=1;i<=occhfp->GetXaxis()->GetNbins();i++) {
	double ccc1 =  occhfp->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	if(ccc1>0.) uyhfp->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uyhfp->SetMarkerStyle(20);
      uyhfp->SetMarkerSize(0.6);
      uyhfp->GetYaxis()->SetLabelSize(0.04);
      uyhfp->SetXTitle("min/av occupancy - HFP \b");
      uyhfp->SetMarkerColor(2);
      uyhfp->SetLineColor(0);
      uyhfp->SetMaximum(1.0);
      uyhfp->SetMinimum(0.2);
      gPad->SetGridy();
      uyhfp->Draw("Error");
      /////////
      
      /////////
      cHB->Update();
      cHB->Print(Form("OccPlots_HF.png"));
      cHB->Clear();
      
      // clean-up
      if (occhfm) delete occhfm;
      if (uyhfm) delete uyhfm;
      if (occhfp) delete occhfp;
      if (uyhfp) delete uyhfp;
    }     
    std::cout << "************>>>   occupancy plots done" << std::endl;






  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// Summed Amplitude Plots:
  //*************************                        *****     Signal                   *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>start Summed Amplitude Plots "<<endl;
  int maxbins = MaxLum;
  cout<<">>>>   maxbins =     "<< maxbins <<endl;
  TH1F *SummedAmplitudeHisto[4];    // 1d histogramm for subdet
  SummedAmplitudeHisto[0] = (TH1F*)hfile->Get("h_averSIGNALsumamplitude_HB");
  SummedAmplitudeHisto[1] = (TH1F*)hfile->Get("h_averSIGNALsumamplitude_HE");
  SummedAmplitudeHisto[2] = (TH1F*)hfile->Get("h_averSIGNALsumamplitude_HO");
  SummedAmplitudeHisto[3] = (TH1F*)hfile->Get("h_averSIGNALsumamplitude_HF");
  TH1F *SummedAmplitudeOccupancyHisto[4];    // 1d histogramm for subdet
  SummedAmplitudeOccupancyHisto[0] = (TH1F*)hfile->Get("h_averSIGNALoccupancy_HB");
  SummedAmplitudeOccupancyHisto[1] = (TH1F*)hfile->Get("h_averSIGNALoccupancy_HE");
  SummedAmplitudeOccupancyHisto[2] = (TH1F*)hfile->Get("h_averSIGNALoccupancy_HO");
  SummedAmplitudeOccupancyHisto[3] = (TH1F*)hfile->Get("h_averSIGNALoccupancy_HF");
  for (int sub=0; sub<4; sub++) {
    cHE->Clear();
    cHE->Divide(2,1);
    cHE->cd(1);
    TH1F* kslpq = new TH1F("kslpq","", maxbins, 1., maxbins+1.);
    //    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   sub =     "<< sub <<endl;
    for (int i=1;i<=kslpq->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(SummedAmplitudeHisto[sub]) ccc1 =  SummedAmplitudeHisto[sub]->GetBinContent(i);
      //      	  if(ccc1>0.)	  cout<<"  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) kslpq->Fill(float(i), ccc1);
    }
    //      gPad->SetLogy();
    kslpq->SetMarkerStyle(20);
    kslpq->SetMarkerSize(0.8);
    kslpq->GetYaxis()->SetLabelSize(0.04);
    kslpq->SetXTitle("SumA of channels w/ signal per LS \b");
    kslpq->SetMarkerColor(2);
    kslpq->SetLineColor(0);
    //  kslpq->SetMinimum(0.8);
    gPad->SetGridx();
    kslpq->Draw("Error");
    /////////
    cHE->cd(2);
    TH1F* pqmks = new TH1F("pqmks","", maxbins, 1., maxbins+1.);
    for (int i=1;i<=pqmks->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(SummedAmplitudeOccupancyHisto[sub]) ccc1 =  SummedAmplitudeOccupancyHisto[sub]->GetBinContent(i);
      //	  if(ccc1>0.)	  cout<<"  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) pqmks->Fill(float(i), ccc1);
    }
    //      gPad->SetLogy();
    pqmks->SetMarkerStyle(20);
    pqmks->SetMarkerSize(0.8);
    pqmks->GetYaxis()->SetLabelSize(0.04);
    pqmks->SetXTitle("Occupancy of channels w/ signal per LS  \b");
    pqmks->SetMarkerColor(4);
    pqmks->SetLineColor(0);
    //  pqmks->SetMinimum(0.8);
    gPad->SetGridx();
    pqmks->Draw("Error");
    cHE->Update();
    if(sub==0)  cHE->Print("SummedAmplitudesSignal_HB.png");
    if(sub==1)  cHE->Print("SummedAmplitudesSignal_HE.png");
    if(sub==2)  cHE->Print("SummedAmplitudesSignal_HO.png");
    if(sub==3)  cHE->Print("SummedAmplitudesSignal_HF.png");
    cHE->Clear();
    if (kslpq) delete kslpq;
    if (pqmks) delete pqmks;
  }//for    
  // clean-up
  //for (unsigned int i=0; i<4; i++) {delete SummedAmplitudeHisto[i];delete SummedAmplitudeOccupancyHisto[i];}

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// Summed Amplitude Plots:
  //*************************                        *****     NoSignal                   *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>start Summed Amplitude Plots NoSignal "<<endl;
  TH1F *NoSignalSummedAmplitudeHisto[4];    // 1d histogramm for subdet
  NoSignalSummedAmplitudeHisto[0] = (TH1F*)hfile->Get("h_averNOSIGNALsumamplitude_HB");
  NoSignalSummedAmplitudeHisto[1] = (TH1F*)hfile->Get("h_averNOSIGNALsumamplitude_HE");
  NoSignalSummedAmplitudeHisto[2] = (TH1F*)hfile->Get("h_averNOSIGNALsumamplitude_HO");
  NoSignalSummedAmplitudeHisto[3] = (TH1F*)hfile->Get("h_averNOSIGNALsumamplitude_HF");
  TH1F *NoSignalSummedAmplitudeOccupancyHisto[4];    // 1d histogramm for subdet
  NoSignalSummedAmplitudeOccupancyHisto[0] = (TH1F*)hfile->Get("h_averNOSIGNALoccupancy_HB");
  NoSignalSummedAmplitudeOccupancyHisto[1] = (TH1F*)hfile->Get("h_averNOSIGNALoccupancy_HE");
  NoSignalSummedAmplitudeOccupancyHisto[2] = (TH1F*)hfile->Get("h_averNOSIGNALoccupancy_HO");
  NoSignalSummedAmplitudeOccupancyHisto[3] = (TH1F*)hfile->Get("h_averNOSIGNALoccupancy_HF");
  for (int sub=0; sub<4; sub++) {
    cHE->Clear();
    cHE->Divide(2,1);
    
    cHE->cd(1);
    TH1F* kslpq = new TH1F("kslpq","", maxbins, 1., maxbins+1.);
    for (int i=1;i<=kslpq->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(NoSignalSummedAmplitudeHisto[sub]) ccc1 =  NoSignalSummedAmplitudeHisto[sub]->GetBinContent(i);
      //	  if(ccc1>0.)	  cout<<"  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) kslpq->Fill(float(i), ccc1);
    }
    //      gPad->SetLogy();
    kslpq->SetMarkerStyle(20);
    kslpq->SetMarkerSize(0.8);
    kslpq->GetYaxis()->SetLabelSize(0.04);
    kslpq->SetXTitle("SumA of channels w/o signal per LS \b");
    kslpq->SetMarkerColor(2);
    kslpq->SetLineColor(0);
    if(sub==0) {
      kslpq->SetMaximum(20000.);
      kslpq->SetMinimum(5000.);
    }
    else if(sub==1) {
      kslpq->SetMaximum(40000.);
      kslpq->SetMinimum(0.);
    }
    else if(sub==2) {
      kslpq->SetMaximum(10000.);
      kslpq->SetMinimum(15000.);
    }
    else if(sub==3) {
      kslpq->SetMaximum(100000.);
      kslpq->SetMinimum(0.);
    }
    gPad->SetGridx();
    kslpq->Draw("Error");
    /////////
    cHE->cd(2);
    TH1F* pqmks = new TH1F("pqmks","", maxbins, 1., maxbins+1.);
    for (int i=1;i<=pqmks->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(NoSignalSummedAmplitudeOccupancyHisto[sub]) ccc1 =  NoSignalSummedAmplitudeOccupancyHisto[sub]->GetBinContent(i);
      //	  if(ccc1>0.)	  cout<<"  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) pqmks->Fill(float(i), ccc1);
    }
    //      gPad->SetLogy();
    pqmks->SetMarkerStyle(20);
    pqmks->SetMarkerSize(0.8);
    pqmks->GetYaxis()->SetLabelSize(0.04);
    pqmks->SetXTitle("Occupancy of channels w/o signal per LS  \b");
    pqmks->SetMarkerColor(4);
    pqmks->SetLineColor(0);
    if(sub==0) {
      pqmks->SetMaximum(600.);
      pqmks->SetMinimum(200.);
    }
    else if(sub==1) {
      pqmks->SetMaximum(910.);
      pqmks->SetMinimum(10.);
    }
    else if(sub==2) {
      pqmks->SetMaximum(200.);
      pqmks->SetMinimum(50.);
    }
    else if(sub==3) {
      pqmks->SetMaximum(866.);
      pqmks->SetMinimum(856.);
    }
    gPad->SetGridx();
    pqmks->Draw("Error");
    cHE->Update();
    if(sub==0)  cHE->Print("NoSignalSummedAmplitudes_HB.png");
    if(sub==1)  cHE->Print("NoSignalSummedAmplitudes_HE.png");
    if(sub==2)  cHE->Print("NoSignalSummedAmplitudes_HO.png");
    if(sub==3)  cHE->Print("NoSignalSummedAmplitudes_HF.png");
    cHE->Clear();
    if (kslpq) delete kslpq;
    if (pqmks) delete pqmks;
  }//for    
  // clean-up
  //for (unsigned int i=0; i<4; i++) {delete NoSignalSummedAmplitudeHisto[i];delete NoSignalSummedAmplitudeOccupancyHisto[i];}
  //////////
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  /// Summed Amplitude Plots:
  //*************************                        *****     MaxxValues                   *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>start Summed Amplitude Plots Maxx "<<endl;
  TH1F *MaxxSummedAmplitudeHisto[4];    // 1d histogramm for subdet
  MaxxSummedAmplitudeHisto[0] = (TH1F*)hfile->Get("h_maxxSUMAmpl_HB");
  MaxxSummedAmplitudeHisto[1] = (TH1F*)hfile->Get("h_maxxSUMAmpl_HE");
  MaxxSummedAmplitudeHisto[2] = (TH1F*)hfile->Get("h_maxxSUMAmpl_HO");
  MaxxSummedAmplitudeHisto[3] = (TH1F*)hfile->Get("h_maxxSUMAmpl_HF");
  TH1F *MaxxSummedAmplitudeOccupancyHisto[4];    // 1d histogramm for subdet
  MaxxSummedAmplitudeOccupancyHisto[0] = (TH1F*)hfile->Get("h_maxxOCCUP_HB");
  MaxxSummedAmplitudeOccupancyHisto[1] = (TH1F*)hfile->Get("h_maxxOCCUP_HE");
  MaxxSummedAmplitudeOccupancyHisto[2] = (TH1F*)hfile->Get("h_maxxOCCUP_HO");
  MaxxSummedAmplitudeOccupancyHisto[3] = (TH1F*)hfile->Get("h_maxxOCCUP_HF");
  TH1F *SAmplitudeHisto[4];    // 1d histogramm for subdet
  SAmplitudeHisto[0] = (TH1F*)hfile->Get("h_eventamplitude_HB");
  SAmplitudeHisto[1] = (TH1F*)hfile->Get("h_eventamplitude_HE");
  SAmplitudeHisto[2] = (TH1F*)hfile->Get("h_eventamplitude_HO");
  SAmplitudeHisto[3] = (TH1F*)hfile->Get("h_eventamplitude_HF");
  TH1F *OccupancyHisto[4];    // 1d histogramm for subdet
  OccupancyHisto[0] = (TH1F*)hfile->Get("h_eventoccupancy_HB");
  OccupancyHisto[1] = (TH1F*)hfile->Get("h_eventoccupancy_HE");
  OccupancyHisto[2] = (TH1F*)hfile->Get("h_eventoccupancy_HO");
  OccupancyHisto[3] = (TH1F*)hfile->Get("h_eventoccupancy_HF");


  int countamplmaxHB=0;int countamplmaxHE=0;int countamplmaxHO=0;int countamplmaxHF=0;
  int countoccumaxHB=0;int countoccumaxHE=0;int countoccumaxHO=0;int countoccumaxHF=0;
  unsigned long int countamplHB=0;unsigned long int countamplHE=0;unsigned long int countamplHO=0;unsigned long int countamplHF=0;
  unsigned long int countoccuHB=0;unsigned long int countoccuHE=0;unsigned long int countoccuHO=0;unsigned long int countoccuHF=0;
  gStyle->SetOptStat(110000);                     
  for (int sub=0; sub<4; sub++) {
    cFour->Clear();
    cFour->Divide(2,2);
    
    cFour->cd(1);
    TH1F* lpqxc = new TH1F("lpqxc","", maxbins, 1., maxbins+1.);
    for (int i=1;i<=lpqxc->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(MaxxSummedAmplitudeHisto[sub]) ccc1 =  MaxxSummedAmplitudeHisto[sub]->GetBinContent(i);
      //   	  if(ccc1>0.)	  cout<<"111111111111111111111111111  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) lpqxc->Fill(float(i), ccc1);
      if(sub==0 && ccc1> 60000.) countamplmaxHB++;
      if(sub==1 && ccc1> 60000.) countamplmaxHE++;
      if(sub==2 && ccc1>150000.) countamplmaxHO++;
      if(sub==3 && ccc1> 22000.) countamplmaxHF++;
    }
    //      gPad->SetLogy();
    lpqxc->SetMarkerStyle(20);
    lpqxc->SetMarkerSize(0.8);
//    lpqxc->GetYaxis()->SetLabelSize(0.08);
    if(sub==0) lpqxc->SetXTitle("HB: max SA over LS-events per LS \b");
    if(sub==1) lpqxc->SetXTitle("HE: max SA over LS-events per LS \b");
    if(sub==2) lpqxc->SetXTitle("HO: max SA over LS-events per LS \b");
    if(sub==3) lpqxc->SetXTitle("HF: max SA over LS-events per LS \b");
    lpqxc->SetMarkerColor(2);
    lpqxc->SetLineColor(0);
    gPad->SetGridx();
    lpqxc->Draw("Error");


    /////////
    cFour->cd(2);
    TH1F* hpzlm = new TH1F("hpzlm","", maxbins, 1., maxbins+1.);
    for (int i=1;i<=hpzlm->GetXaxis()->GetNbins();i++) {
      double ccc1 =  0.;
      if(MaxxSummedAmplitudeOccupancyHisto[sub]) ccc1 =  MaxxSummedAmplitudeOccupancyHisto[sub]->GetBinContent(i);
      //    if(ccc1>0.)	  cout<<"2222222222222222222222222  iLS = "<<i<<"  LS= "<<ccc1<<endl;
      if(ccc1>0.) hpzlm->Fill(float(i), ccc1);
      if(sub==0 && ccc1> 2000.) countoccumaxHB++;
      if(sub==1 && ccc1> 1200.) countoccumaxHE++;
      if(sub==2 && ccc1> 2000.) countoccumaxHO++;
      if(sub==3 && ccc1>  860.) countoccumaxHF++;
    }
    //      gPad->SetLogy();
    hpzlm->SetMarkerStyle(20);
    hpzlm->SetMarkerSize(0.8);
//    hpzlm->GetYaxis()->SetLabelSize(0.08);
    if(sub==0) hpzlm->SetXTitle("HB: max Occupancy over LS-events per LS \b");
    if(sub==1) hpzlm->SetXTitle("HE: max Occupancy over LS-events per LS \b");
    if(sub==2) hpzlm->SetXTitle("HO: max Occupancy over LS-events per LS \b");
    if(sub==3) hpzlm->SetXTitle("HF: max Occupancy over LS-events per LS \b");
    hpzlm->SetMarkerColor(4);
    hpzlm->SetLineColor(0);
    gPad->SetGridx();
    if(sub==3) {
      hpzlm->SetMaximum(866.);
      hpzlm->SetMinimum(856.);
    }
    hpzlm->Draw("Error");

    /////////
    cFour->cd(3);
    gPad->SetLogy();
    if(SAmplitudeHisto[sub]) {
    for (int i=1;i<=SAmplitudeHisto[sub]->GetXaxis()->GetNbins();i++) {
//      if(sub==0 && i * 800> 60000.) {
//	cout<<">=>=>>=> countamplHB= "<<countamplHB<<" content = "<<SAmplitudeHisto[sub]->GetBinContent(i)<<" sub= "<<sub<<" i= "<<i<<  endl;
//	countamplHB+=SAmplitudeHisto[sub]->GetBinContent(i);
//      }
      if(sub==0 && i * 800> 60000. ) countamplHB+=SAmplitudeHisto[sub]->GetBinContent(i);
      if(sub==1 && i *1000> 60000. ) countamplHE+=SAmplitudeHisto[sub]->GetBinContent(i);
      if(sub==2 && i *2500>150000. ) countamplHO+=SAmplitudeHisto[sub]->GetBinContent(i);
      if(sub==3 && i *1400> 22000. ) countamplHF+=SAmplitudeHisto[sub]->GetBinContent(i);
    }
    SAmplitudeHisto[sub]->SetMarkerStyle(20);
    SAmplitudeHisto[sub]->SetMarkerSize(0.8);
         if(sub==0) SAmplitudeHisto[sub]->SetTitle("HB event Amplitude\b");
         if(sub==1) SAmplitudeHisto[sub]->SetTitle("HE event Amplitude\b");
         if(sub==2) SAmplitudeHisto[sub]->SetTitle("HO event Amplitude\b");
         if(sub==3) SAmplitudeHisto[sub]->SetTitle("HF event Amplitude\b");
//    SAmplitudeHisto[sub]->GetYaxis()->SetLabelSize(0.08);
    SAmplitudeHisto[sub]->SetXTitle("event amplitude \b");
    SAmplitudeHisto[sub]->SetMarkerColor(2);
    SAmplitudeHisto[sub]->SetLineColor(2);
    SAmplitudeHisto[sub]->Draw("");
 }    
    /////////
    cFour->cd(4);
    gPad->SetLogy();
    if(OccupancyHisto[sub]) {
    for (int i=1;i<=OccupancyHisto[sub]->GetXaxis()->GetNbins();i++) {
      if(sub==0 && i * 30 > 2000. ) countoccuHB+=OccupancyHisto[sub]->GetBinContent(i);
      if(sub==1 && i * 20 > 1200. ) countoccuHE+=OccupancyHisto[sub]->GetBinContent(i);
      if(sub==2 && i * 25 > 2000. ) countoccuHO+=OccupancyHisto[sub]->GetBinContent(i);
      if(sub==3 && i * 10 >  860. ) countoccuHF+=OccupancyHisto[sub]->GetBinContent(i);
    }
    OccupancyHisto[sub]->SetMarkerStyle(20);
    OccupancyHisto[sub]->SetMarkerSize(0.8);
         if(sub==0) OccupancyHisto[sub]->SetTitle("HB event Occupancy\b");
         if(sub==1) OccupancyHisto[sub]->SetTitle("HE event Occupancy\b");
         if(sub==2) OccupancyHisto[sub]->SetTitle("HO event Occupancy\b");
         if(sub==3) OccupancyHisto[sub]->SetTitle("HF event Occupancy\b");
//    OccupancyHisto[sub]->GetYaxis()->SetLabelSize(0.08);
    OccupancyHisto[sub]->SetXTitle("event occupancy \b");
    OccupancyHisto[sub]->SetMarkerColor(4);
    OccupancyHisto[sub]->SetLineColor(4);
    OccupancyHisto[sub]->Draw("");
 }    

    cFour->Update();
    if(sub==0)  cFour->Print("MaxxSummedAmplitudes_HB.png");
    if(sub==1)  cFour->Print("MaxxSummedAmplitudes_HE.png");
    if(sub==2)  cFour->Print("MaxxSummedAmplitudes_HO.png");
    if(sub==3)  cFour->Print("MaxxSummedAmplitudes_HF.png");
    cFour->Clear();
    if (lpqxc) delete lpqxc;
    if (hpzlm) delete hpzlm;
  }//for    
    gStyle->SetOptStat(0);                     
  //////////
  cout<<">=>=>>=> countamplmaxHB= "<<countamplmaxHB<<" countamplmaxHE= "<<countamplmaxHE<<" countamplmaxHO= "<<countamplmaxHO<<" countamplmaxHF= "<<countamplmaxHF<<  endl;
  cout<<">=>=>>=> countoccumaxHB= "<<countoccumaxHB<<" countoccumaxHE= "<<countoccumaxHE<<" countoccumaxHO= "<<countoccumaxHO<<" countoccumaxHF= "<<countoccumaxHF<<  endl;
  cout<<">=>=>>=> countamplHB= "<<countamplHB<<" countamplHE= "<<countamplHE<<" countamplHO= "<<countamplHO<<" countamplHF= "<<countamplHF<<  endl;
  cout<<">=>=>>=> countoccuHB= "<<countoccuHB<<" countoccuHE= "<<countoccuHE<<" countoccuHO= "<<countoccuHO<<" countoccuHF= "<<countoccuHF<<  endl;
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  /// Summed Amplitude Plots:
  //*************************                        *****     channelsummedA over depths                   *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>channelsummedA over depths "<<endl;
  TH1F *ChannelDepthsummedAmplitudesPlots[4];    // 1d histogramm for subdet
  ChannelDepthsummedAmplitudesPlots[0] = (TH1F*)hfile->Get("h_sumamplitudechannel_HB");
  ChannelDepthsummedAmplitudesPlots[1] = (TH1F*)hfile->Get("h_sumamplitudechannel_HE");
  ChannelDepthsummedAmplitudesPlots[2] = (TH1F*)hfile->Get("h_sumamplitudechannel_HO");
  ChannelDepthsummedAmplitudesPlots[3] = (TH1F*)hfile->Get("h_sumamplitudechannel_HF");
  TLine *litebdt[4];
  if(ChannelDepthsummedAmplitudesPlots[0]) litebdt[0]=new TLine(  80., 0.8,   80., ChannelDepthsummedAmplitudesPlots[0]->GetBinContent(4) +100.);
  if(ChannelDepthsummedAmplitudesPlots[1]) litebdt[1]=new TLine( 200., 0.8,  200., ChannelDepthsummedAmplitudesPlots[1]->GetBinContent(7) +100.);
  if(ChannelDepthsummedAmplitudesPlots[2]) litebdt[2]=new TLine(1200., 0.8, 1200., ChannelDepthsummedAmplitudesPlots[2]->GetBinContent(17)+100.);
  if(ChannelDepthsummedAmplitudesPlots[3]) litebdt[3]=new TLine( 600., 0.8,  600., ChannelDepthsummedAmplitudesPlots[3]->GetBinContent(6) +100.);
  
  gStyle->SetOptStat(110000);                     
  cFour1->Clear();
  cFour1->Divide(2,2);
  for (int sub=0; sub<4; sub++) {
    
    if(sub==0)  cFour1->cd(1);
    if(sub==1)  cFour1->cd(2);
    if(sub==2)  cFour1->cd(3);
    if(sub==3)  cFour1->cd(4);
    gPad->SetLogy();
    ChannelDepthsummedAmplitudesPlots[sub]->SetMarkerStyle(20);
    ChannelDepthsummedAmplitudesPlots[sub]->SetMarkerSize(0.8);
    if(sub==0) ChannelDepthsummedAmplitudesPlots[sub]->SetTitle("HB channel Amplitudes\b");
    if(sub==1) ChannelDepthsummedAmplitudesPlots[sub]->SetTitle("HE channel Amplitudes\b");
    if(sub==2) ChannelDepthsummedAmplitudesPlots[sub]->SetTitle("HO channel Amplitudes\b");
    if(sub==3) ChannelDepthsummedAmplitudesPlots[sub]->SetTitle("HF channel Amplitudes\b");
    if(sub==0) ChannelDepthsummedAmplitudesPlots[sub]->SetXTitle("HB channel depths summed Amplitudes \b");
    if(sub==1) ChannelDepthsummedAmplitudesPlots[sub]->SetXTitle("HE channel depths summed Amplitudes \b");
    if(sub==2) ChannelDepthsummedAmplitudesPlots[sub]->SetXTitle("HO channel depths summed Amplitudes \b");
    if(sub==3) ChannelDepthsummedAmplitudesPlots[sub]->SetXTitle("HF channel depths summed Amplitudes \b");
    ChannelDepthsummedAmplitudesPlots[sub]->SetMarkerColor(2);
    ChannelDepthsummedAmplitudesPlots[sub]->SetLineColor(2);
    ChannelDepthsummedAmplitudesPlots[sub]->Draw("");
    litebdt[sub]->SetLineColor(kBlue);
    litebdt[sub]->Draw("s");
  }//for    
  cFour1->Update();
  cFour1->Print("ChannelDepthsummedAmplitudes.png");
  cFour1->Clear();
  gStyle->SetOptStat(0);                     


  //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  /// Summed Amplitude Plots:
  //*************************                        *****     Ataildepth1_HB                 *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>2DAtaildepth "<<endl;
  //////////
  cHB->Clear();
  cHB->Divide(2,1);

  TH2F *DAtaildepth1[2];    // 1d histogramm for subdet
  DAtaildepth1[0] = (TH2F*)hfile->Get("h_2DAtaildepth1_HB");
  DAtaildepth1[1] = (TH2F*)hfile->Get("h_2D0Ataildepth1_HB");
  cHB->cd(1);
  if(!DAtaildepth1[0] || !DAtaildepth1[1] ) {
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>Ataildepth1_HB EMPTY histoes for 2DAtaildepth 1"<<endl;
  }
  else {
    TH2F *tail1= (TH2F*)DAtaildepth1[0]->Clone("tail1");
    tail1->Divide(DAtaildepth1[0],DAtaildepth1[1], 1, 1, "B");
    //  tail1->Sumw2();
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    tail1->SetMarkerStyle(20);
    tail1->SetMarkerSize(0.4);
    tail1->SetTitle("Amplitudes for tail-events (HBdepth1) \b");
    tail1->SetXTitle("#eta \b");
    tail1->SetYTitle("#phi \b");
    tail1->SetZTitle("2D <A> in the tail - HB Depth1 \b");
    tail1->SetMarkerColor(2);
    tail1->SetLineColor(2);
    tail1->Draw("COLZ");
  }
  TH2F *DAtaildepth2[2];    // 1d histogramm for subdet
  DAtaildepth2[0] = (TH2F*)hfile->Get("h_2DAtaildepth2_HB");
  DAtaildepth2[1] = (TH2F*)hfile->Get("h_2D0Ataildepth2_HB");
  cHB->cd(2);
  if(!DAtaildepth2[0] || !DAtaildepth2[1] ) {
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>Ataildepth1_HB EMPTY histoes for 2DAtaildepth 2"<<endl;
  }
  else {
    TH2F *tail2= (TH2F*)DAtaildepth2[0]->Clone("tail2");
    tail2->Divide(DAtaildepth2[0],DAtaildepth2[1], 1, 1, "B");
    //  tail2->Sumw2();
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    tail2->SetMarkerStyle(20);
    tail2->SetMarkerSize(0.4);
    tail2->SetTitle("Amplitudes for tail-events (HBdepth2) \b");
    tail2->SetXTitle("#eta \b");
    tail2->SetYTitle("#phi \b");
    tail2->SetZTitle("2D <A> in the tail - HB Depth2 \b");
    tail2->SetMarkerColor(2);
    tail2->SetLineColor(2);
    tail2->Draw("COLZ");
  }
  
  cHB->Update();
  cHB->Print("AtaildepthHB.png");
  cHB->Clear();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  /// Summed Amplitude Plots:
  //*************************                        *****     sum(Signal+NoSignal) occupancy for HF                *****
  cout<<">>>>>>>>>>>>>>>>>>>>>>>>sumOccupancyHF "<<endl;
  //////////
  cHB->Clear();
  cHB->Divide(1,1);
  cHB->cd(1);
  if(SummedAmplitudeOccupancyHisto[3]) {
  TH1F* ufrew1= (TH1F*)SummedAmplitudeOccupancyHisto[3]->Clone("ufrew1");
  if(SummedAmplitudeOccupancyHisto[3] && NoSignalSummedAmplitudeOccupancyHisto[3]  ) ufrew1->Add(SummedAmplitudeOccupancyHisto[3],NoSignalSummedAmplitudeOccupancyHisto[3], 1, 1);
  ufrew1->GetXaxis()->SetRangeUser(1., maxbins+1.);
  gPad->SetGridx();
  ufrew1->SetMarkerStyle(20);
  ufrew1->SetMarkerSize(0.8);
  ufrew1->GetYaxis()->SetLabelSize(0.04);
  ufrew1->SetTitle("HF Occupancy vs LS\b");      
  ufrew1->SetXTitle("average occupancy per LS HF\b");
  ufrew1->SetMarkerColor(4);
  ufrew1->SetLineColor(0);
  ufrew1->SetMaximum(866.);
  ufrew1->SetMinimum(856.);
  ufrew1->Draw("Error");
  cHB->Update();
  cHB->Print("sumOccupancyHF.png");
  cHB->Clear();
  if (ufrew1) delete ufrew1;
  } 
  
  //////////
  //////////
  //////////
  //////////
  //////////
  //////////
  //////////
  //====================================================================================================================
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> ====================================================================="<<endl;

//=====================================================================================================
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> =================================================="<<endl;

//=====================================================================================
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> ================================="<<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> ================================="<<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> ================================="<<endl;
  cout<<">>>>>>>>>>>>>>>>>>>>>>>> ================================="<<endl;

  cout<<">>>>>>>             START NOW CREATING OF HTML PAGES      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
//======================================================================
// Creating each test kind for each subdet html pages:
  std::string raw_class;  
  int ind = 0; 
  ofstream htmlFile;
  for (int test=0;test<=5;test++) { //Test: 0,   
      for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HO, 4-HF
           
	//	cout<<"Creating each test kind for each subdet html pages:  test=  "<< test << "  sub= "  << sub <<    endl;
           if (test==0){
	      if (sub==1) {htmlFile.open("HB_CapID.html");}
              if (sub==2) {htmlFile.open("HE_CapID.html");}
              if (sub==3) {htmlFile.open("HO_CapID.html");}
              if (sub==4) {htmlFile.open("HF_CapID.html");}
	   }	   
	   if (test==1){
	      if (sub==1) {htmlFile.open("HB_ADCampl.html");}
              if (sub==2) {htmlFile.open("HE_ADCampl.html");}
              if (sub==3) {htmlFile.open("HO_ADCampl.html");}
              if (sub==4) {htmlFile.open("HF_ADCampl.html");}
	   }
	   if (test==2){
	      if (sub==1) {htmlFile.open("HB_Width.html");}
              if (sub==2) {htmlFile.open("HE_Width.html");}
              if (sub==3) {htmlFile.open("HO_Width.html");}
              if (sub==4) {htmlFile.open("HF_Width.html");}
	   }
	   if (test==3){
	      if (sub==1) {htmlFile.open("HB_Ratio.html");}
              if (sub==2) {htmlFile.open("HE_Ratio.html");}
              if (sub==3) {htmlFile.open("HO_Ratio.html");}
              if (sub==4) {htmlFile.open("HF_Ratio.html");}
	   }
	   if (test==4){
	      if (sub==1) {htmlFile.open("HB_Tmean.html");}
              if (sub==2) {htmlFile.open("HE_Tmean.html");}
              if (sub==3) {htmlFile.open("HO_Tmean.html");}
              if (sub==4) {htmlFile.open("HF_Tmean.html");}
	   }
	   if (test==5){
	      if (sub==1) {htmlFile.open("HB_Tmax.html");}
              if (sub==2) {htmlFile.open("HE_Tmax.html");}
              if (sub==3) {htmlFile.open("HO_Tmax.html");}
              if (sub==4) {htmlFile.open("HF_Tmax.html");}
	   }

           htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
           htmlFile << "<head>"<< std::endl;
           htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
           htmlFile << "<title> Certification Monitoring Tool </title>"<< std::endl;
           htmlFile << "<style type=\"text/css\">"<< std::endl;
           htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
           htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
           htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
           htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
           htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
           htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
	   htmlFile << "   td.s5 { font-family: arial, arial ce, helvetica; background-color: #00FF00; }"<< std::endl;
           htmlFile << "   td.s6 { font-family: arial, arial ce, helvetica; background-color: #FF0000; }"<< std::endl;
           htmlFile << "</style>"<< std::endl;
           htmlFile << "<body>"<< std::endl;

           if (test==0) {     
              if (sub==1) htmlFile << "<h1> Cap ID estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Cap ID estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Cap ID estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Cap ID estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }
           if (test==1) {     
              if (sub==1) htmlFile << "<h1> Mean ADC Amplitude estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Mean ADC Amplitude estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Mean ADC Amplitude estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Mean ADC Amplitude estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }     
           if (test==2) {     
              if (sub==1) htmlFile << "<h1> Width estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Width estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Width estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Width estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }     
           if (test==3) {     
              if (sub==1) htmlFile << "<h1> Ratio estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Ratio estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Ratio estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Ratio estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }     
           if (test==4) {     
              if (sub==1) htmlFile << "<h1> Mean bin timing estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Mean bin timing estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Mean bin timing estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Mean bin timing estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }     
           if (test==5) {     
              if (sub==1) htmlFile << "<h1> Maximum bin timing estimator for HB, RUN = "<< runnumber <<" </h1>"<< std::endl; 
              if (sub==2) htmlFile << "<h1> Maximum bin timing estimator for HE, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==3) htmlFile << "<h1> Maximum bin timing estimator for HO, RUN = "<< runnumber <<" </h1>"<< std::endl;
              if (sub==4) htmlFile << "<h1> Maximum bin timing estimator for HF, RUN = "<< runnumber <<" </h1>"<< std::endl; 
           }     
          

           if (test == 1) {
	     htmlFile << "<a name=\"Top\"></a>\n";
	     htmlFile << "<b>Contents:<br>\n";
	     htmlFile << "1. <a href=\"#Aij\">A_ij_LS (averaged over events in LS) </a><br>\n";
	     htmlFile << "2. <a href=\"#OverflowAij\">A_ij_LS in overflow & underflow</a><br>\n";
	     htmlFile << "3. <a href=\"#MainEstimator\">Main Estimator !!! </a><br>\n";
	     htmlFile << "4. <a href=\"#ErrorA\">Error type A </a><br>\n";
	     htmlFile << "5. <a href=\"#ErrorAaverage\">ErrorA cross check</a><br>\n";
	     htmlFile << "6. <a href=\"#ErrorAoccupancy\">ErrorA occupancy plots</a><br>\n";
	     htmlFile << "7. <a href=\"#ErrorB\">Error type B</a><br>\n";
	     htmlFile << "8. <a href=\"#LSstatus\">LS Status in the table</a><br>\n";
	     htmlFile << "9. <a href=\"#RBXstatus\">RBX Status </a><br>\n";
	   }
	   
	   //     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   
	   
           htmlFile << "<br>"<< std::endl;
           if (test==0) {
	     htmlFile << "<h2> 0. Rate of CapID failures over all events of Run </h2>"<< std::endl;
	     htmlFile << "<h3> Channel legend: green - good, other colour - suspicious  </h3>"<< std::endl; 
	     if (sub==1) htmlFile << " <img src=\"MapCapIdErrorHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapCapIdErrorHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapCapIdErrorHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapCapIdErrorHF.png\" />" << std::endl;
	   }
	   if (test == 1) htmlFile << "<a name=\"Aij\"></a>\n";
	   if (test !=0) htmlFile << "<h2> 1. Distribution of estimator averaged over events in LS, histogramed over all channels and all LSs </h2>"<< std::endl;
	   if (test ==0) {
	     if (sub==1) htmlFile << "<h2> 1.  Average Nbcs for only LS containing events with abnormal number of Bad channels >"<<CutAb[sub][1]<<" (Depth1), "<<CutAb[sub][2] <<" (Depth2).</h2>"<< std::endl;
	     if (sub==2) htmlFile << "<h2> 1.  Average Nbcs for only LS containing events with abnormal number of Bad channels >"<<CutAb[sub][1]<<" (Depth1), "<<CutAb[sub][2] <<" (Depth2), "<<CutAb[sub][3] <<" (Depth3).</h2>"<< std::endl;
	     if (sub==3) htmlFile << "<h2> 1.  Average Nbcs for only LS containing events with abnormal number of Bad channels >"<<CutAb[sub][1]<<" (Depth4).</h2>"<< std::endl;
	     if (sub==4) htmlFile << "<h2> 1.  Average Nbcs for only LS containing events with abnormal number of Bad channels >"<<CutAb[sub][1]<<" (Depth1), "<<CutAb[sub][2] <<" (Depth2).</h2>"<< std::endl;
             
	   }
	   
	   if (test !=0) htmlFile << "<h3> see Overflow and Underflow </h3>"<< std::endl;
	   if (test ==0) htmlFile << "<h3> Legend: dots correspond to BAD LS candidates.</h3>"<< std::endl; 
	   
	   if (test==0){
	     if (sub==1) htmlFile << " <img src=\"Hist_CAPID_Abnorm_HB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"Hist_CAPID_Abnorm_HE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"Hist_CAPID_Abnorm_HO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"Hist_CAPID_Abnorm_HF.png\" />" << std::endl;
	   }
	   if (test==1){
	     if (sub==1) htmlFile << " <img src=\"H_ADCamplHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"H_ADCamplHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"H_ADCamplHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"H_ADCamplHF.png\" />" << std::endl;
	   }
	   if (test==2){
	     if (sub==1) htmlFile << " <img src=\"H_WidthHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"H_WidthHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"H_WidthHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"H_WidthHF.png\" />" << std::endl;
	   }
	   if (test==3){
	     if (sub==1) htmlFile << " <img src=\"H_RatioHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"H_RatioHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"H_RatioHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"H_RatioHF.png\" />" << std::endl;
	   }
	   if (test==4){
	     if (sub==1) htmlFile << " <img src=\"H_TmeanHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"H_TmeanHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"H_TmeanHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"H_TmeanHF.png\" />" << std::endl;
	   }
	   if (test==5){
	     if (sub==1) htmlFile << " <img src=\"H_TmaxHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"H_TmaxHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"H_TmaxHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"H_TmaxHF.png\" />" << std::endl;
	   }	 
	   htmlFile << "<br>"<< std::endl; 
	   if (test ==1) 	  htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   
	   
	   if (test ==0) htmlFile << "<h2> 2a.  Number of bad channels per event distribution in Run</h2>"<< std::endl;
	   if (test ==0) htmlFile << "<h3> Legends: dots correspond to BAD LS candidates.  </h3>"<< std::endl;
	   if (test ==0){
	     if (sub==1) htmlFile << " <img src=\"HistNBadChsHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistNBadChsHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistNBadChsHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistNBadChsHF.png\" />" << std::endl;
	   }       
	   
	   if (test == 1) htmlFile << "<a name=\"OverflowAij\"></a>\n";
	   if (test !=0) htmlFile << "<h2> 2. Estimator averaged over all events in the RUN for entries in overflow and underflow of corresponding histogram above </h2>"<< std::endl;
	   //              if (test !=0) htmlFile << "<h2> 2. Estimator averaged over all events in the RUN </h2>"<< std::endl;
	   if (test ==0) htmlFile << "<h2> 2b. Averaged number of bad channels for each LS </h2>"<< std::endl;
	   //              if (test !=0) htmlFile << "<h3> Channel legend: white - good, other colour - bad.  </h3>"<< std::endl;
	   if (test ==0) {
	     if (sub==1) htmlFile << "<h3> Legends: dots selected with following cuts: <td class=\"s6\" align=\"center\">"<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2) correspond BAD LS.</td></h3>"<< std::endl;
	     if (sub==2) htmlFile << "<h3> Legends: dots selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2), "<<Cut0[test][sub][3]<<" (Depth3) correspond BAD LS.</h3>"<< std::endl;
	     if (sub==3) htmlFile << "<h3> Legends: dots selected with following cuts: "<<Cut0[test][sub][4]<<" (Depth4) correspond BAD LS.</h3>"<< std::endl;
	     if (sub==4) htmlFile << "<h3> Legends: dots selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2) correspond BAD LS.</h3>"<< std::endl;
	   }
	   if (test==0){
	     if (sub==1) htmlFile << " <img src=\"HistNBCMNHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistNBCMNHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistNBCMNHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistNBCMNHF.png\" />" << std::endl;
	   }
	   if (test==1){
	     if (sub==1) htmlFile << " <img src=\"MapADCamplHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapADCamplHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapADCamplHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapADCamplHF.png\" />" << std::endl;
	   }
	   if (test==2){
	     if (sub==1) htmlFile << " <img src=\"MapWidthHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapWidthHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapWidthHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapWidthHF.png\" />" << std::endl;
	   }
	   if (test==3){
	     if (sub==1) htmlFile << " <img src=\"MapRatioHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapRatioHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapRatioHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapRatioHF.png\" />" << std::endl;
	   }
	   if (test==4){
	     if (sub==1) htmlFile << " <img src=\"MapTmeanHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapTmeanHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapTmeanHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapTmeanHF.png\" />" << std::endl;
	   }
	   if (test==5){
	     if (sub==1) htmlFile << " <img src=\"MapTmaxHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"MapTmaxHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"MapTmaxHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"MapTmaxHF.png\" />" << std::endl;
	   }	 
	   htmlFile << "<br>"<< std::endl;
	   if (test == 1) htmlFile << "<a href=\"#Top\">to top</a><br>\n";
           
	   
	   if (test == 1) htmlFile << "<a name=\"MainEstimator\"></a>\n";
	   if (test !=0) htmlFile << "<h2> 3. Distribution of estimator averaged over events in LS and over all channels for each LS </h2>"<< std::endl;
	   if (test ==0) {
	     if (sub==1) htmlFile << "<h2> 3.  Portion of events with Nbcs>"<<CutPo[sub][1]<<" (Depth1), "<<CutPo[sub][2] <<" (Depth2) in each LS.</h2>"<< std::endl;
	     if (sub==2) htmlFile << "<h2> 3.  Portion of events with Nbcs>"<<CutPo[sub][1]<<" (Depth1), "<<CutPo[sub][2] <<" (Depth2), "<<CutPo[sub][3] <<" (Depth3) in each LS.</h2>"<< std::endl;
	     if (sub==3) htmlFile << "<h2> 3.  Portion of events with Nbcs>"<<CutPo[sub][4]<<" (Depth4) in each LS.</h2>"<< std::endl;
	     if (sub==4) htmlFile << "<h2> 3.  Portion of events with Nbcs>"<<CutPo[sub][1]<<" (Depth1), "<<CutPo[sub][2] <<" (Depth2) in each LS.</h2>"<< std::endl;
	     htmlFile << "<h3> Legend: dots correspond to BAD LS candidates.</h3>"<< std::endl;
	   }
	   if (test !=0){
	     if (sub==1) htmlFile << "<h3> Legends:  dots selected with following cuts: <td class=\"s6\" align=\"center\">"<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2) correspond BAD LS.</td></h3>"<< std::endl;
	     if (sub==2) htmlFile << "<h3> Legends:  dots selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2), "<<Cut0[test][sub][3]<<" (Depth3), "<<Cut0[test][sub][4]<<" (Depth4), "<<Cut0[test][sub][5]<<" (Depth5), "<<Cut0[test][sub][6]<<" (Depth6), "<<Cut0[test][sub][7]<<" (Depth7) correspond BAD LS. </h3>"<< std::endl;
	     if (sub==3) htmlFile << "<h3> Legends:  dots selected with following cuts: "<<Cut0[test][sub][4]<<" (Depth4) correspond BAD LS. </h3>"<< std::endl;
	     if (sub==4) htmlFile << "<h3> Legends:  dots selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2), "<<Cut0[test][sub][3]<<" (Depth3), "<<Cut0[test][sub][4]<<" (Depth4) correspond BAD LS. </h3>"<< std::endl;
	   }
	   if (test==0){
	     if (sub==1) htmlFile << " <img src=\"HistPortHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistPortHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistPortHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistPortHF.png\" />" << std::endl;
	   }
	   if (test==1){
	     if (sub==1) htmlFile << " <img src=\"HistADCamplHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistADCamplHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistADCamplHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistADCamplHF.png\" />" << std::endl;
	   }
	   if (test==2){
	     if (sub==1) htmlFile << " <img src=\"HistWidthHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistWidthHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistWidthHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistWidthHF.png\" />" << std::endl;
	   }
	   if (test==3){
	     if (sub==1) htmlFile << " <img src=\"HistRatioHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistRatioHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistRatioHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistRatioHF.png\" />" << std::endl;
	   }
	   if (test==4){
	     if (sub==1) htmlFile << " <img src=\"HistTmeanHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistTmeanHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistTmeanHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistTmeanHF.png\" />" << std::endl;
	   }
	   if (test==5){
	     if (sub==1) htmlFile << " <img src=\"HistTmaxHB.png\" />" << std::endl; 
	     if (sub==2) htmlFile << " <img src=\"HistTmaxHE.png\" />" << std::endl; 
	     if (sub==3) htmlFile << " <img src=\"HistTmaxHO.png\" />" << std::endl; 
	     if (sub==4) htmlFile << " <img src=\"HistTmaxHF.png\" />" << std::endl;
	   }	     	    	      
	   htmlFile << "<br>"<< std::endl;

	   if (test==1) {
	     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	     htmlFile << "<a name=\"ErrorA\"></a>\n";
	     htmlFile << "<h2> 4. Error type A</h2>\n";
	     htmlFile << "<h3> note: no sence to see plots of this item if max difference is too large(due to very high A of some channels)</h3>\n";
	     htmlFile << "<br>\n";
	     
     //HB:
	     if (sub==1) {
	       htmlFile << "<h3>Mean of max difference between dependencies to be within: 0.1-1.6 (p-p collisions) </h3>\n";
	       htmlFile << " <img src=\"HistErrA_HB.png\" />\n";
	       htmlFile << "<br>\n";
	       if (flagErrAB_HB[0]==-1) htmlFile<<"<h3>test was not possible</h3>\n";
	       else if (flagErrAB_HB[0]==0) htmlFile<<"<h3> Fine:NoErrorA_HB (Mean of max difference " << avedelta_HB  << "  is within 0.1-1.6) </h3>\n";
	       else if (flagErrAB_HB[0]==1) htmlFile<<"<<h3> ErrorA_HB is available once Mean of max difference " << avedelta_HB  << " is out 0.1-1.6 (p-p collisions)</font></h3>\n";
	       else htmlFile<<"<h3>auto-interpretation is not available</h3>\n";
	       htmlFile << "<a href=\"#Top\">to top</a><br>\n";

       htmlFile << "<a name=\"ErrorAaverage\"></a>\n";

       htmlFile << "<h2> 5. Error type A cross check: see 2D pattern of channels   </h2>\n";
       htmlFile << "<h2> 1) with average channel Amplitudes(No cut), 2) with average channel Amplitudes(<A> >25), 3) with channel Amplitude (A<35);  </h2>\n";
       htmlFile << " <img src=\"ChkErrA_HB1.png\" /><br><br>\n";
       htmlFile << " <img src=\"ChkErrA_HB2.png\" /><br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";

       htmlFile << "<a name=\"ErrorAoccupancy\"></a>\n";
       htmlFile << "<h2> 6. Error type A: min/ave ratio for occupancy distributions with Amplitude bigger 25 (HBM:neg.eta;HBP:pos.eta) </h2>\n";
       htmlFile << "<h2> FOR CROSS-CHECK OLNY !!!</h2>\n";
       htmlFile << "<h2> TO IDENTIFY A-type errors: for most of LSs the ratio to be lower 0.6 at least for HF- or HF+ </h2>\n";
       htmlFile << "<h2> For runs without A-type errors: for most of LSs the ratio is higher 0.6 and is the same for HF- and HF+ </h2>\n";
       htmlFile << " <img src=\"OccPlots_HB.png\" /><br><br>\n";
       htmlFile << "<br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";




	       htmlFile << "<a name=\"ErrorB\"></a>\n";
	       htmlFile << "<h2> 7. Error type B\n";
	       htmlFile << "<h3> ErrorB identification: digi-collection size != 10.</h3>\n";
	       htmlFile << " <img src=\"HistErrB_HB_1.png\" />\n<br>\n";
	       htmlFile << " <img src=\"HistErrB_HB_2.png\" />\n<br>\n";
	       htmlFile << "<br>\n";
	       htmlFile <<"<h3> if Error type B is available, it start from:    " << LSofFirstErrB_HB  << "  LS </h3>\n";
	       htmlFile << "<br>\n";
	     }
	     
     //HE:
	     if (sub==2) {
	       htmlFile << "<h3>Mean of max difference between dependencies to be within: 0.2-1.8 (p-p collisions) </h3>\n";
	       htmlFile << " <img src=\"HistErrA_HE.png\" />\n";
	       htmlFile << "<br>\n";
	       if (flagErrAB_HE[0]==-1) htmlFile<<"<h3>test was not possible</h3>\n";
	       else if (flagErrAB_HE[0]==0) htmlFile<<"<h3> Fine:NoErrorA_HE (Mean of max difference " << avedelta_HE  << "  is within 0.2-1.8) </h3>\n";
	       else if (flagErrAB_HE[0]==1) htmlFile<<"<<h3> ErrorA_HE is available once Mean of max difference " << avedelta_HE  << " is out 0.2-1.8 (p-p collisions)</font></h3>\n";
	       else htmlFile<<"<h3>auto-interpretation is not available</h3>\n";
	       htmlFile << "<a href=\"#Top\">to top</a><br>\n";


       htmlFile << "<a name=\"ErrorAaverage\"></a>\n";

       htmlFile << "<h2> 5. Error type A cross check: see 2D pattern of channels   </h2>\n";
       htmlFile << "<h2> 1) with average channel Amplitudes(No cut), 2) with average channel Amplitudes(<A> >1000.fC), 3) with channel Amplitude (A<500fC);  </h2>\n";
       htmlFile << " <img src=\"ChkErrA_HE1.png\" /><br><br>\n";
       htmlFile << " <img src=\"ChkErrA_HE2.png\" /><br>\n";
       htmlFile << " <img src=\"ChkErrA_HE3.png\" /><br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";

       htmlFile << "<a name=\"ErrorAoccupancy\"></a>\n";
       htmlFile << "<h2> 6. Error type A: min/ave ratio for occupancy distributions with Amplitude bigger 35 (HEM:neg.eta;HEP:pos.eta) </h2>\n";
       htmlFile << "<h2> FOR CROSS-CHECK OLNY !!!</h2>\n";
       htmlFile << "<h2> TO IDENTIFY A-type errors: for most of LSs the ratio to be lower 0.3 at least for HF- or HF+ </h2>\n";
       htmlFile << "<h2> For runs without A-type errors: for most of LSs the ratio is higher 0.3 and is the same for HF- and HF+ </h2>\n";
       htmlFile << " <img src=\"OccPlots_HE.png\" /><br><br>\n";
       htmlFile << "<br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";


	       htmlFile << "<a name=\"ErrorB\"></a>\n";
	       htmlFile << "<h2> 7. Error type B\n";
	       htmlFile << "<h3> ErrorB identification: digi-collection size != 8.</h3>\n";
	       htmlFile << " <img src=\"HistErrB_HE_1.png\" />\n<br>\n";
	       htmlFile << " <img src=\"HistErrB_HE_2.png\" />\n<br>\n";
	       htmlFile << " <img src=\"HistErrB_HE_3.png\" />\n<br>\n";
	       htmlFile << "<br>\n";
	       htmlFile <<"<h3> if Error type B is available, it start from:    " << LSofFirstErrB_HE  << "  LS </h3>\n";
	       htmlFile << "<br>\n";
	     }
	     
     //HO:
	     if (sub==3) {
	       htmlFile << "<h3>Mean of max difference between dependencies to be within: 0.1-1.5 (p-p collisions) </h3>\n";
	       htmlFile << " <img src=\"HistErrA_HO.png\" />\n";
	       htmlFile << "<br>\n";
	       if (flagErrAB_HO[0]==-1) htmlFile<<"<h3>test was not possible</h3>\n";
	       else if (flagErrAB_HO[0]==0) htmlFile<<"<h3> Fine:NoErrorA_HO (Mean of max difference " << avedelta_HO  << "  is within 0.1-1.5) </h3>\n";
	       else if (flagErrAB_HO[0]==1) htmlFile<<"<<h3> ErrorA_HO is available once Mean of max difference " << avedelta_HO  << " is out 0.1-1.5 (p-p collisions)</font></h3>\n";
	       else htmlFile<<"<h3>auto-interpretation is not available</h3>\n";
	       htmlFile << "<a href=\"#Top\">to top</a><br>\n";



       htmlFile << "<a name=\"ErrorAaverage\"></a>\n";

       htmlFile << "<h2> 5. Error type A cross check: see 2D pattern of channels   </h2>\n";
       htmlFile << "<h2> 1) with average channel Amplitudes(No cut), 2) with average channel Amplitudes(<A> >80), 3) with channel Amplitude (A<100);  </h2>\n";
       //       htmlFile << "<h2> 2D. Cross check for error A</h2>\n";
       htmlFile << " <img src=\"ChkErrA_HO4.png\" /><br><br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";

       htmlFile << "<a name=\"ErrorAoccupancy\"></a>\n";
       htmlFile << "<h2> 6. Error type A: min/ave ratio for occupancy distributions with Amplitude bigger 80 (HOM:neg.eta;HOP:pos.eta) </h2>\n";
       htmlFile << "<h2> FOR CROSS-CHECK OLNY !!!</h2>\n";
       htmlFile << "<h2> TO IDENTIFY A-type errors: for most of LSs the ratio to be lower 0.8 at least for HF- or HF+ </h2>\n";
       htmlFile << "<h2> For runs without A-type errors: for most of LSs the ratio is higher 0.8 and is the same for HF- and HF+ </h2>\n";
       htmlFile << " <img src=\"OccPlots_HO.png\" /><br><br>\n";
       htmlFile << "<br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";




	       htmlFile << "<a name=\"ErrorB\"></a>\n";
	       htmlFile << "<h2> 7. Error type B\n";
	       htmlFile << "<h3> ErrorB identification: digi-collection size != 10. </h3>\n";
	       htmlFile << " <img src=\"HistErrB_HO_4.png\" />\n<br>\n";
	       htmlFile << "<br>\n";
	       htmlFile <<"<h3> if Error type B is available, it start from:    " << LSofFirstErrB_HO  << "  LS </h3>\n";
	       htmlFile << "<br>\n";
	     }
	     
     //HF:
	     if (sub==4) {
	       //		flagSpecHF+=1;
	       htmlFile << "<h3>Mean of max difference between dependencies to be within: 0.8-2.4 (p-p collisions) </h3>\n";
	       htmlFile << " <img src=\"HistErrA_HF.png\" />\n";
	       htmlFile << "<br>\n";
	       if (flagErrAB_HF[0]==-1) htmlFile<<"<h3>test was not possible</h3>\n";
	       else if (flagErrAB_HF[0]==0) htmlFile<<"<h3> Fine:NoErrorA_HF (Mean of max difference " << avedelta_HF  << "  is within 0.8-2.4) </h3>\n";
	       else if (flagErrAB_HF[0]==1) htmlFile<<"<<h3> ErrorA_HF is available once Mean of max difference " << avedelta_HF  << " is out 0.8-2.4 (p-p collisions)</font></h3>\n";
	       else htmlFile<<"<h3>auto-interpretation is not available</h3>\n";
	       htmlFile << "<a href=\"#Top\">to top</a><br>\n";



       htmlFile << "<a name=\"ErrorAaverage\"></a>\n";

       htmlFile << "<h2> 5. Error type A cross check: see 2D pattern of channels   </h2>\n";
       htmlFile << "<h2> 1) with average channel Amplitudes(No cut), 2) with average channel Amplitudes(<A> >20), 3) with channel Amplitude (A<20);  </h2>\n";
       //       htmlFile << "<h2> 2D. Cross check for error A</h2>\n";
       htmlFile << " <img src=\"ChkErrA_HF1.png\" /><br><br>\n";
       htmlFile << " <img src=\"ChkErrA_HF2.png\" /><br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";

       htmlFile << "<a name=\"ErrorAoccupancy\"></a>\n";
       htmlFile << "<h2> 6. Error type A: min/ave ratio for occupancy distributions with Amplitude bigger 20 (HFM:neg.eta;HFP:pos.eta) </h2>\n";
       htmlFile << "<h2> FOR CROSS-CHECK OLNY !!!</h2>\n";
       htmlFile << "<h2> TO IDENTIFY A-type errors: for most of LSs the ratio to be lower 0.8 at least for HF- or HF+ </h2>\n";
       htmlFile << "<h2> For runs without A-type errors: for most of LSs the ratio is higher 0.8 and is the same for HF- and HF+ </h2>\n";
       htmlFile << " <img src=\"OccPlots_HF.png\" /><br><br>\n";
       htmlFile << "<br>\n";
       htmlFile << "<a href=\"#Top\">to top</a><br>\n";




	       htmlFile << "<a name=\"ErrorB\"></a>\n";
	       htmlFile << "<h2> 7. Error type B\n";
	       htmlFile << "<h3> ErrorB identification: digi-collection size != 4. </h3>\n";
	       htmlFile << " <img src=\"HistErrB_HF_1.png\" />\n<br>\n";
	       htmlFile << " <img src=\"HistErrB_HF_2.png\" />\n<br>\n";
	       htmlFile << "<br>\n";
	       htmlFile <<"<h3> if Error type B is available, it start from:    " << LSofFirstErrB_HF  << "  LS </h3>\n";
	       htmlFile << "<br>\n";
	     }
	     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	     
	   }//test=1 Amplitude
	   
	   if (test == 1) htmlFile << "<a name=\"LSstatus\"></a>\n";
	   // Continue with common sections
	   if (sub==1) { 
	     htmlFile << "<h2> 8.Lumisection Status for HB </h2>"<< std::endl;
	     htmlFile << "<h3> Legends: Red boxes correspond BAD LS selected with following cuts: <td class=\"s6\" align=\"center\">"<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2). </td></h3>"<< std::endl;
	   }  
	   if (sub==2) {
	     htmlFile << "<h2> 8.Lumisection Status for HE </h2>"<< std::endl;
	     htmlFile << "<h3> Legends: Red boxes correspond BAD LS selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2), "<<Cut0[test][sub][3]<<" (Depth3). </h3>"<< std::endl;
	   }
	   if (sub==3) {
	     //		htmlFile << Form("<h2> %d.Lumisection Status for HO </h2>",4+flagSpecHF)<< std::endl;
	     htmlFile << "<h2> 8.Lumisection Status for HO </h2>"<< std::endl;
	     htmlFile << "<h3> Legends: Red boxes correspond BAD LS selected with following cuts: "<<Cut0[test][sub][4]<<" (Depth4). </h3>"<< std::endl;
	   }
	   if (sub==4) {
	     htmlFile << "<h2> 8.Lumisection Status for HF </h2>"<< std::endl; 
	     htmlFile << "<h3> Legends: Red boxes correspond BAD LS selected with following cuts: "<<Cut0[test][sub][1]<<" (Depth1), "<<Cut0[test][sub][2]<<" (Depth2). </h3>"<< std::endl;
	   }	  	      
	   htmlFile << "<br>"<< std::endl;
	   htmlFile << "<table>"<< std::endl;        
	   htmlFile << "<tr>";
	   htmlFile << "<td class=\"s4\" align=\"center\">LS</td>"    << std::endl;
	   //              htmlFile << "<td class=\"s1\" align=\"center\">LS</td>"  << std::endl;
	   htmlFile << "<td class=\"s1\" align=\"center\">Number of events</td>"  << std::endl;
	   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	   int kkkkkkmax = k_max[sub];
	  if ( (sub==4 || sub==2) && test==1) kkkkkkmax = k_maxHFupgrade[sub];
	  //	   if (test==1 && sub==4) kkkkkkmax = k_maxHFupgrade[sub];

	   if (test==0) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< Nbcs > Depth "<< k <<" </td>"  << std::endl;
	   if (test==1) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > Depth "<< k <<" </td>"  << std::endl;
	   if (test==2) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< W > Depth "<< k <<" </td>"  << std::endl;
	   if (test==3) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< R > Depth "<< k <<" </td>"  << std::endl;
	   if (test==4) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSn > Depth "<< k <<" </td>"  << std::endl;
	   if (test==5) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSx > Depth "<< k <<" </td>"  << std::endl;
	   htmlFile << "</tr>"   << std::endl;    

	   ind = 0;              
	   for (int i=1;i<=MaxLum;i++) {
	     if ((ind%2)==1)   raw_class="<td class=\"s2\" align=\"center\">";
	     else              raw_class="<td class=\"s3\" align=\"center\">";              
	     htmlFile << "<tr>"<< std::endl;
	     htmlFile << "<td class=\"s4\" align=\"center\">" << i <<"</td>"<< std::endl;
	     //                  htmlFile << raw_class<< LumLum->GetBinContent(i)<<"</td>"<< std::endl;	
	     htmlFile << raw_class<< LumiEv->GetBinContent(i)<<"</td>"<< std::endl;	      
	     for (int k=k_min[sub];k<=kkkkkkmax; k++) {	              
	       if (HistNumBadChanDepth[test][sub][k]->GetBinContent(i) > Cut0[test][sub][k]) 
		 htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	       else  htmlFile << raw_class <<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	     }
	     htmlFile << "</tr>" << std::endl;
	     ind+=1;
	   }	                
	   htmlFile << "</table>" << std::endl; 
	   
	   htmlFile << "<br>"<< std::endl; 
	   if (test == 1) 	  htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   htmlFile << "<br>"<< std::endl; 


	   /// RBX:
	   if (test == 1) htmlFile << "<a name=\"RBXstatus\"></a>\n";
	   // Continue with common sections

	   //HB j = 7,8,9,10            11,12,13,14 
	   if (sub==1) { 
	     htmlFile << "<h2> 9. Averaged Amplitudes of RBX for HB </h2>"<< std::endl; 
	     htmlFile << "<h3> jeta = 7,8,9,10 (Negative direction); ............&& ............  jeta = 11,12,13,14 (Positive direction);  </h3>"<< std::endl; 
	     htmlFile << "<h3> jphi =  0, 1, 2, 3, 4, 5 (range 1) ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2) ............&& ............  jphi = 12,13,14,15,16,17 (range 3)</h3>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-2Dplot.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> LS dependencies for averaged Amplitudes of RBX </h2>"<< std::endl; 
	     htmlFile << "<h3> average A : Amplitude averaged over channels of RBX and over events of each LS"<< std::endl;
	     htmlFile << "<h3> (averaged over depthes as well)"<< std::endl;
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HB: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-negative-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HB: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-negative-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HB: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-negative-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-positive-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction);  ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-positive-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction); ............&& ............   jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HB-positive-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   }  
	   // HE: j = 3,4,5, 6, 7      14,15,16,17,18
	   if (sub==2) {
	     htmlFile << "<h2> 9. Averaged Amplitudes of RBX for HE </h2>"<< std::endl; 
	     htmlFile << "<h3> jeta = 3,4,5, 6, 7 (Negative direction); ............&& ............  jeta = 14,15,16,17,18 (Positive direction);  </h3>"<< std::endl; 
	     htmlFile << "<h3> jphi =  0, 1, 2, 3, 4, 5 (range 1) ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2) ............&& ............  jphi = 12,13,14,15,16,17 (range 3)</h3>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-2Dplot.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> LS dependencies for averaged Amplitudes of RBX </h2>"<< std::endl; 
	     htmlFile << "<h3> average A : Amplitude averaged over channels of RBX and over events of each LS"<< std::endl;
	     htmlFile << "<h3> (averaged over depthes as well)"<< std::endl;
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HE: jeta = 3,4,5, 6, 7 (Negative direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-negative-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HE: jeta = 3,4,5, 6, 7 (Negative direction); ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-negative-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HE: jeta = 3,4,5, 6, 7 (Negative direction); ............&& ............  jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-negative-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 14,15,16,17,18 (Positive direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-positive-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 14,15,16,17,18 (Positive direction);  ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-positive-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 14,15,16,17,18 (Positive direction); ............&& ............   jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HE-positive-phirange3.png\" />\n";
	     htmlFile << "<br>\n";
	   }
	   // HO:   j = 7,8,9,10            11,12,13,14
	   if (sub==3) {
	     htmlFile << "<h2> 9. Averaged Amplitudes of RBX for HO </h2>"<< std::endl; 
	     htmlFile << "<h3> jeta = 7,8,9,10 (Negative direction); ............&& ............  jeta = 11,12,13,14 (Positive direction);  </h3>"<< std::endl; 
	     htmlFile << "<h3> jphi =  0, 1, 2, 3, 4, 5 (range 1) ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2) ............&& ............  jphi = 12,13,14,15,16,17 (range 3)</h3>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-2Dplot.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> LS dependencies for averaged Amplitudes of RBX </h2>"<< std::endl; 
	     htmlFile << "<h3> average A : Amplitude averaged over channels of RBX and over events of each LS"<< std::endl;
	     htmlFile << "<h3> (averaged over depthes as well)"<< std::endl;
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HO: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-negative-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HO: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-negative-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HO: jeta = 7,8,9,10 (Negative direction); ............&& ............  jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-negative-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-positive-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction);  ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-positive-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 11,12,13,14 (Positive direction); ............&& ............   jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HO-positive-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   }
	   //HF:j = 0,1,2, 3            18,19,20,21 
	   if (sub==4) {

	     htmlFile << "<h2> 9. Averaged Amplitudes of RBX for HF </h2>"<< std::endl; 
	     htmlFile << "<h3> jeta = 0,1,2, 3 (Negative direction); ............&& ............  jeta = 18,19,20,21 (Positive direction);  </h3>"<< std::endl; 
	     htmlFile << "<h3> jphi =  0, 1, 2, 3, 4, 5 (range 1) ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2) ............&& ............  jphi = 12,13,14,15,16,17 (range 3)</h3>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-2Dplot.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> LS dependencies for averaged Amplitudes of RBX </h2>"<< std::endl; 
	     htmlFile << "<h3> average A : Amplitude averaged over channels of RBX and over events of each LS"<< std::endl;
	     htmlFile << "<h3> (averaged over depthes as well)"<< std::endl;
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HF: jeta = 0,1,2, 3 (Negative direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-negative-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HF: jeta = 0,1,2, 3 (Negative direction); ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-negative-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> HF: jeta = 0,1,2, 3 (Negative direction); ............&& ............  jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-negative-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 18,19,20,21 (Positive direction); ............&& ............  jphi =  0, 1, 2, 3, 4, 5 (range 1): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-positive-phirange1.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 18,19,20,21 (Positive direction);  ............&& ............  jphi =  6, 7, 8, 9,10,11 (range 2): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-positive-phirange2.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<h2> jeta = 18,19,20,21 (Positive direction); ............&& ............   jphi = 12,13,14,15,16,17 (range 3): </h2>"<< std::endl; 
	     htmlFile << " <img src=\"RBX-HF-positive-phirange3.png\" />\n";
	     htmlFile << "<br>\n";

	     htmlFile << "<a href=\"#Top\">to top</a><br>\n";
	   }	  	      
	   htmlFile << "<br>"<< std::endl;

	   htmlFile.close();	   
      }// sub main loop
  } //test main loop
  //===============================================================================
  
  
  //======================================================================
  // Creating tests  html pages:
  
  for (int test=0;test<=5;test++) { //Test: 0,   
    if (test==0) htmlFile.open("CapID_GL.html");
    if (test==1) htmlFile.open("ADCampl_GL.html");
    if (test==2) htmlFile.open("Width_GL.html");
    if (test==3) htmlFile.open("Ratio_GL.html");
    if (test==4) htmlFile.open("Tmean_GL.html");
    if (test==5) htmlFile.open("Tmax_GL.html");
    
    //	cout<<"Creating tests  html pages:  test=  "<< test <<     endl;


    htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
    htmlFile << "<head>"<< std::endl;
    htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
    htmlFile << "<title> Certification Monitoring Tool </title>"<< std::endl;
    htmlFile << "<style type=\"text/css\">"<< std::endl;
    htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
    htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
    htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
    htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
    htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
    htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
    htmlFile << "   td.s5 { font-family: arial, arial ce, helvetica; background-color: #00FF00; }"<< std::endl;
    htmlFile << "   td.s6 { font-family: arial, arial ce, helvetica; background-color: #FF0000; }"<< std::endl;
    htmlFile << "</style>"<< std::endl;
    htmlFile << "<body>"<< std::endl;
    if (test==0) htmlFile << "<h1> CAP ID ERRORS, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl; 
    if (test==1) htmlFile << "<h1> ADC AMPLITIDE, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl; 
    if (test==2) htmlFile << "<h1> WIDTH, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl;
    if (test==3) htmlFile << "<h1> RATIO, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl;
    if (test==4) htmlFile << "<h1> TIMING MEAN, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl;
    if (test==5) htmlFile << "<h1> TIMING MAX, GLOBAL RUN = "<< runnumber <<" </h1>"<< std::endl;  
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> 1.  Map of suspicious channels with this criterion for whole HCAL </h2>"<< std::endl; 
    htmlFile << "<h3> Channel legend: green - good, other colour - suspicious  </h3>"<< std::endl;  
    htmlFile << "<br>"<< std::endl;      
    if (test==0) htmlFile << " <img src=\"MapCapIdError.png\" />" << std::endl;
    if (test==1) htmlFile << " <img src=\"MapADCAmpl.png\" />" << std::endl;      
    if (test==2) htmlFile << " <img src=\"MapWidth.png\" />" << std::endl;      
    if (test==3) htmlFile << " <img src=\"MapRatio.png\" />" << std::endl;      
    if (test==4) htmlFile << " <img src=\"MapTmean.png\" />" << std::endl;   
    if (test==5) htmlFile << " <img src=\"MapTmax.png\" />" << std::endl;         
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> 2.  For whole HCAL: </h2>"<< std::endl;   
    htmlFile << "<br>"<< std::endl;      
    if (test==0) htmlFile << " <img src=\"HistCapID.png\" />" << std::endl; 
    if (test==1) htmlFile << " <img src=\"HistADCAmpl.png\" />" << std::endl;      
    if (test==2) htmlFile << " <img src=\"HistWidth.png\" />" << std::endl;      
    if (test==3) htmlFile << " <img src=\"HistRatio.png\" />" << std::endl;      
    if (test==4) htmlFile << " <img src=\"HistTmean.png\" />" << std::endl;   
    if (test==5) htmlFile << " <img src=\"HistTmax.png\" />" << std::endl;         
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> 3. Status of subdetectors </h2>"<< std::endl;   
    htmlFile << "<table width=\"400\">"<< std::endl;
    htmlFile << "<tr>"<< std::endl;
    if (test==0){
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_CapID.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_CapID.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_CapID.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_CapID.html\">HF</a></td>"<< std::endl;
    }
    if (test==1){
      // AZ 07.11.2018
      //    htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_ADCampl.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"HB_ADCampl.html\">HB</a></td>"<< std::endl;
      // AZ 18.03.2018
      //      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_ADCampl.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"HE_ADCampl.html\">HE</a></td>"<< std::endl;
      // AZ 07.11.2018
      //    htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_ADCampl.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"HO_ADCampl.html\">HO</a></td>"<< std::endl;
      // AZ 07.11.2018
      //    htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_ADCampl.html\">HF</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"HF_ADCampl.html\">HF</a></td>"<< std::endl;
    }
    if (test==2){
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_Width.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_Width.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_Width.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_Width.html\">HF</a></td>"<< std::endl;
    }
    if (test==3){
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_Ratio.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_Ratio.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_Ratio.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_Ratio.html\">HF</a></td>"<< std::endl;
    }
    if (test==4){
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_Tmean.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_Tmean.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_Tmean.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_Tmean.html\">HF</a></td>"<< std::endl;
    }
    if (test==5){
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HB_Tmax.html\">HB</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HE_Tmax.html\">HE</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HO_Tmax.html\">HO</a></td>"<< std::endl;
      htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HF_Tmax.html\">HF</a></td>"<< std::endl;
    }
    
    htmlFile << "</tr>"<< std::endl;
    htmlFile << "</table>"<< std::endl;
    htmlFile << "<br>"<< std::endl;    
    //	cout<<"Creating tests  html pages:  111111" <<     endl;
    
    if (test!=0) htmlFile << "<h2> 4. Table of estimator-values in sub-detectors for ONLY suspicious LSs </h3>"<< std::endl;   
    if (test==0) htmlFile << "<h2> 4. Table of average Nbcs in sub-detectors for ONLY suspicious LSs </h3>"<< std::endl;
    htmlFile << "<table>"<< std::endl;     
    htmlFile << "<tr>";
    htmlFile << "<td class=\"s4\" align=\"center\">LS</td>"    << std::endl;
    //     htmlFile << "<td class=\"s1\" align=\"center\">LS</td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">Number of events</td>"  << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HO, 4-HF
      
      //    cout<<"Creating each test kind for each subdet html pages:  test=  "<< test << "  sub= "  << sub <<    endl;
      int kkkkkkmax = k_max[sub];
      if ( (sub==4 || sub==2) && test==1) kkkkkkmax = k_maxHFupgrade[sub];
      //	   if (test==1 && sub==4) kkkkkkmax = k_maxHFupgrade[sub];
      if(sub==1) {
	if (test==0) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< Nbcs > HBdep "<< k <<" </td>"  << std::endl;
	if (test==1) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > HBdepth "<< k <<" </td>"  << std::endl;
	if (test==2) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< W > HBdepth "<< k <<" </td>"  << std::endl;
	if (test==3) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< R > HBdepth "<< k <<" </td>"  << std::endl;
	if (test==4) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSn > HBdep "<< k <<" </td>"  << std::endl;
	if (test==5) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSx > HBdep "<< k <<" </td>"  << std::endl;
      }//     
      if(sub==2) {
	if (test==0) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< Nbcs > HEdep "<< k <<" </td>"  << std::endl;
	if (test==1) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > HEdepth "<< k <<" </td>"  << std::endl;
	if (test==2) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< W > HEdepth "<< k <<" </td>"  << std::endl;
	if (test==3) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< R > HEdepth "<< k <<" </td>"  << std::endl;
	if (test==4) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSn > HEdep "<< k <<" </td>"  << std::endl;
	if (test==5) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSx > HEdep "<< k <<" </td>"  << std::endl;
      }//     
      if(sub==3) {
	if (test==0) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< Nbcs > HOdep "<< k <<" </td>"  << std::endl;
	if (test==1) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > HOdepth "<< k <<" </td>"  << std::endl;
	if (test==2) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< W > HOdepth "<< k <<" </td>"  << std::endl;
	if (test==3) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< R > HOdepth "<< k <<" </td>"  << std::endl;
	if (test==4) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSn > HOdep "<< k <<" </td>"  << std::endl;
	if (test==5) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSx > HOdep "<< k <<" </td>"  << std::endl;
      }//     
      if(sub==4) {
	if (test==0) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< Nbcs > HFdep "<< k <<" </td>"  << std::endl;
	if (test==1) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > HFdepth "<< k <<" </td>"  << std::endl;
	if (test==2) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< W > HFdepth "<< k <<" </td>"  << std::endl;
	if (test==3) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< R > HFdepth "<< k <<" </td>"  << std::endl;
	if (test==4) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSn > HFdep "<< k <<" </td>"  << std::endl;
	if (test==5) for (int k=k_min[sub];k<=kkkkkkmax; k++) htmlFile << "<td class=\"s1\" align=\"center\">< TSx > HFdep "<< k <<" </td>"  << std::endl;
      }//     
    }// sub
    htmlFile << "</tr>"   << std::endl;    
    
//    htmlFile << "<td class=\"s1\" align=\"center\">HB Depth 1</td>"<< std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HB Depth 2</td>"  << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 1</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 2</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 3</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 4</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 5</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 6</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HE Depth 7</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HO Depth 4</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HF Depth 1</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HF Depth 2</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HF Depth 3</td>"   << std::endl;
//    htmlFile << "<td class=\"s1\" align=\"center\">HF Depth 4</td>"   << std::endl;
//    htmlFile << "</tr>"   << std::endl;     
    
    ind = 0;
    //  cout<<"Creating tests  html pages:  222222" <<     endl;
    for (int i=1;i<=MaxLum;i++) {
      // define al least one exceed in any sub-detector
      int met =0;
      for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
	int kkkkkkmax = k_max[sub];
	if ( (sub==4 || sub==2) && test==1) kkkkkkmax = k_maxHFupgrade[sub];
	for (int k=k_min[sub];k<=kkkkkkmax; k++)  {
	  // line below is temporary, just to avoid contribution of HEP(M)17 in depthes 4,5,6,7 but keep in depthes 1,2,3
	  if(sub==2 && k>3 ) {}else{
	    if (HistNumBadChanDepth[test][sub][k]->GetBinContent(i) > Cut0[test][sub][k]) met = 1;}
	}//depth
      }//sub
      // if exceed then plot the line for all sub-detectors
      if (met==1) {
	if ((ind%2)==1)   raw_class="<td class=\"s2\" align=\"center\">";
	else              raw_class="<td class=\"s3\" align=\"center\">";                    
	htmlFile << "<tr>"<< std::endl;
	htmlFile << "<td class=\"s4\" align=\"center\">" << i <<"</td>"<< std::endl;
	//            htmlFile << raw_class<< LumLum->GetBinContent(i)<<"</td>"<< std::endl;
	htmlFile << raw_class<< LumiEv->GetBinContent(i)<<"</td>"<< std::endl;
	for (int sub=1;sub<=4;sub++) {  //Subdetector: 1-HB, 2-HE, 3-HF, 4-HO
	  int kkkkkkmax = k_max[sub];
	  if ( (sub==4 || sub==2) && test==1) kkkkkkmax = k_maxHFupgrade[sub];
	  for (int k=k_min[sub];k<=kkkkkkmax; k++)  {
	    if (HistNumBadChanDepth[test][sub][k]->GetBinContent(i) > Cut0[test][sub][k]) 
	      htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	    else  htmlFile << raw_class <<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	    //	     htmlFile << "</tr>" << std::endl;
	    /*
	      if (HistNumBadChanDepth[test][1][1]->GetBinContent(i) > Cut0[test][1][1])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][1][1]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][1][1]->GetBinContent(i)<<"</td>"<< std::endl;   
	      if (HistNumBadChanDepth[test][1][2]->GetBinContent(i) > Cut0[test][1][2])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][1][2]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][1][2]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][1]->GetBinContent(i) > Cut0[test][2][1])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][1]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][1]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][2]->GetBinContent(i) > Cut0[test][2][2])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][2]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][2]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][3]->GetBinContent(i) > Cut0[test][2][3])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][3]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][3]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][4]->GetBinContent(i) > Cut0[test][2][4])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][4]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][4]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][5]->GetBinContent(i) > Cut0[test][2][5])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][5]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][5]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][6]->GetBinContent(i) > Cut0[test][2][6])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][6]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][6]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][2][7]->GetBinContent(i) > Cut0[test][2][7])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][2][7]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][2][7]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][3][4]->GetBinContent(i) > Cut0[test][3][4])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][3][4]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][3][4]->GetBinContent(i)<<"</td>"<< std::endl;	    
	      if (HistNumBadChanDepth[test][4][1]->GetBinContent(i) > Cut0[test][4][1])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][4][1]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][4][1]->GetBinContent(i)<<"</td>"<< std::endl;	  
	      if (HistNumBadChanDepth[test][4][2]->GetBinContent(i) > Cut0[test][4][2])  htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][4][2]->GetBinContent(i)<<"</td>"<< std::endl;
	      else htmlFile <<raw_class<<HistNumBadChanDepth[test][4][2]->GetBinContent(i)<<"</td>"<< std::endl;
	    */
	  } //k depthes
	}//sub
	htmlFile << "</tr>" << std::endl;
	ind+=1;
      }// met=1
    }//i bin lines	
    //	cout<<"Creating tests  html pages:  333333" <<     endl;
    htmlFile << "</table>" << std::endl;
    htmlFile << "<br>"<< std::endl;
    htmlFile << "</body> " << std::endl;
    htmlFile << "</html> " << std::endl;
    htmlFile.close();
  }//test
  //======================================================================
  //	cout<<"for summed Amplitudes of each sub-detector" <<     endl;
  
  // for summed Amplitudes of each sub-detector
  htmlFile.open("SummedAmplitudes_GL.html");
    htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
    htmlFile << "<head>"<< std::endl;
    htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
    htmlFile << "<title> for summed Amplitudes of each sub-detector </title>"<< std::endl;
    htmlFile << "<style type=\"text/css\">"<< std::endl;
    htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
    htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
    htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
    htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
    htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
    htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
    htmlFile << "   td.s5 { font-family: arial, arial ce, helvetica; background-color: #00FF00; }"<< std::endl;
    htmlFile << "   td.s6 { font-family: arial, arial ce, helvetica; background-color: #FF0000; }"<< std::endl;


    htmlFile << "</style>"<< std::endl;
    htmlFile << "<body>"<< std::endl;
    htmlFile << "<h1> Averaged Summed Amplitudes & corresponding occupancy of each sub-detector in Global Run = "<< runnumber <<" </h1>"<< std::endl;  
	     htmlFile << "<a name=\"Top\"></a>\n";
	     htmlFile << "<b>Contents:<br>\n";
	     htmlFile << "1. <a href=\"#SAhigh\">average SA&Occupancy for Signal  </a><br>\n";
	     htmlFile << "2. <a href=\"#SAlow\">average SA&Occupancy for NoSignal </a><br>\n";
	     htmlFile << "3. <a href=\"#SAmax\"> maxSA & maxOccupancy; SA & Occupancy; </a><br>\n";
	     htmlFile << "4. <a href=\"#FullTable\">Table(avA; avSA; avOccupancy; maxSA; maxOccupancy;) </a><br>\n";

    htmlFile << "<h2> Clarifying on averaged Summed Amplitude (avSA) : </h2>"<< std::endl; 
    htmlFile << "<h3> Summed Amplitudes (SA) are averaged over all events of each LS: avSA_LS = SUM (SA_eventsInLS) / N_eventsInLS ,</h3>"<< std::endl; 
    htmlFile << "<h3> where SA = SUM(A_i) ,and means that Amplitude is summed over all sub-detector channels, </h3>"<< std::endl; 
    htmlFile << "<h3> where A_i = SUM(A_depth) denotes channel amplitude summed over depths;  </h3>"<< std::endl; 
//  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HELP.html\"> Description of criteria for bad channel selection</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/SAwriteup.html\"> see more details for SummedAmplitudes</a></td>"<< std::endl;
    htmlFile << "<h2> Apply cuts on A_i to take into account channels with or/and without a'la Signal: </h2>"<< std::endl; 
    htmlFile << " <img src=\"ChannelDepthsummedAmplitudes.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<br>"<< std::endl;
htmlFile << "<a name=\"SAhigh\"></a>\n";
    htmlFile << "<h1> 1.  for channels with signal </h1>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HB: A_i> 80; </h2>"<< std::endl; 
    htmlFile << " <img src=\"SummedAmplitudesSignal_HB.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HE: A_i> 200;</h2>"<< std::endl; 
    htmlFile << " <img src=\"SummedAmplitudesSignal_HE.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HO: A_i> 1200;</h2>"<< std::endl; 
    htmlFile << " <img src=\"SummedAmplitudesSignal_HO.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HF: A_i> 600;</h2>"<< std::endl; 
    htmlFile << " <img src=\"SummedAmplitudesSignal_HF.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
htmlFile << "<a href=\"#Top\">to top</a><br>\n";


htmlFile << "<a name=\"SAlow\"></a>\n";
    htmlFile << "<h1> 2.  for channels w/o signal </h1>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HB: A_i< 80;</h2>"<< std::endl; 
    htmlFile << " <img src=\"NoSignalSummedAmplitudes_HB.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HE:  A_i< 200;</h2>"<< std::endl; 
    htmlFile << " <img src=\"NoSignalSummedAmplitudes_HE.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HO: A_i< 1200;</h2>"<< std::endl; 
    htmlFile << " <img src=\"NoSignalSummedAmplitudes_HO.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> for HF: A_i< 600;</h2>"<< std::endl; 
    htmlFile << " <img src=\"NoSignalSummedAmplitudes_HF.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
htmlFile << "<a href=\"#Top\">to top</a><br>\n";
    
    
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<br>"<< std::endl;
htmlFile << "<a name=\"SAmax\"></a>\n";
    htmlFile << "<h1> 3. four plots: ---1--->  max SA ---2---> max Occupancy ---3--->  SA ---4---> Occupancy over all events of LS </h1>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;

    htmlFile << "<h2> for HB: maxSA vs LS, masOccupancy vs LS, SA, Occupancy </h2>"<< std::endl; 
    htmlFile << " <img src=\"MaxxSummedAmplitudes_HB.png\" />" << std::endl;      
    htmlFile << "<h2>" " ......(forCut:SAmax>60000) N= "<<countamplmaxHB<< " ...... (forCut:OCCUPmax>2000) N= "<<countoccumaxHB<< " </h2>"<< std::endl; 
    htmlFile << "<h2>" " ......(forCut:SA>60000) N= "<<countamplHB<< " ...... (forCut:OCCUP>2000) N= "<<countoccuHB<< " </h2>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h3> ONLY for HB (cross-check): channel Amplitudes for events in the Tail (averaged): </h3>"<< std::endl; 
    htmlFile << " <img src=\"AtaildepthHB.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;

    htmlFile << "<h2> for HE: maxSA vs LS, masOccupancy vs LS, SA, Occupancy </h2>"<< std::endl; 
    htmlFile << " <img src=\"MaxxSummedAmplitudes_HE.png\" />" << std::endl;      
    htmlFile << "<h2>" " ......(forCut:SAmax>60000) N= "<<countamplmaxHE<< " ...... (forCut:OCCUPmax>1200) N= "<<countoccumaxHE<< " </h2>"<< std::endl; 
    htmlFile << "<h2>" " ......(forCut:SA>60000) N= "<<countamplHE<< " ...... (forCut:OCCUP>1200) N= "<<countoccuHE<< " </h2>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;

    htmlFile << "<h2> for HO: maxSA vs LS, masOccupancy vs LS, SA, Occupancy </h2>"<< std::endl; 
    htmlFile << " <img src=\"MaxxSummedAmplitudes_HO.png\" />" << std::endl;      
    htmlFile << "<h2>" " ......(forCut:SAmax>150000) N= "<<countamplmaxHO<< " ...... (forCut:OCCUPmax>2000) N= "<<countoccumaxHO<< " </h2>"<< std::endl; 
    htmlFile << "<h2>" " ......(forCut:SA>150000) N= "<<countamplHO<< " ...... (forCut:OCCUP>2000) N= "<<countoccuHO<< " </h2>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;

    htmlFile << "<h2> for HF: maxSA vs LS, masOccupancy vs LS, SA, Occupancy </h2>"<< std::endl; 
    htmlFile << " <img src=\"MaxxSummedAmplitudes_HF.png\" />" << std::endl;      
    htmlFile << "<h2>" " ......(forCut:SAmax>22000) N= "<<countamplmaxHF<< " ...... (forCut:OCCUPmax>860) N= "<<countoccumaxHF<< " </h2>"<< std::endl; 
    htmlFile << "<h2>" " ......(forCut:SA>22000) N= "<<countamplHF<< " ...... (forCut:OCCUP>860) N= "<<countoccuHF<< " </h2>"<< std::endl; 
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<h2> Occupancy HF (ONLY) vs LS </h2>"<< std::endl; 
    htmlFile << " <img src=\"sumOccupancyHF.png\" />" << std::endl;      
    htmlFile << "<br>"<< std::endl;
htmlFile << "<a href=\"#Top\">to top</a><br>\n";
    
    
htmlFile << "<a name=\"FullTable\"></a>\n";
    htmlFile << "<h2> 4.Lumisection Status:  </h2>"<< std::endl;
    htmlFile << "<h3> Legends: HBdepth1 red boxes correspond LSs selected with cut: <td class=\"s6\" align=\"center\">"<<Cut0[1][1][1]<< std::endl;
    htmlFile << "<h3> Legends: HEdepth1 red boxes correspond LSs selected with cut: <td class=\"s6\" align=\"center\">"<<Cut0[1][2][1]<< std::endl;
    htmlFile << "<h3> Legends: HOdepth4 red boxes correspond LSs selected with cut: <td class=\"s6\" align=\"center\">"<<Cut0[1][3][4]<< std::endl;
    htmlFile << "<h3> Legends: HFdepth1 red boxes correspond LSs selected with cut: <td class=\"s6\" align=\"center\">"<<Cut0[1][4][1]<< std::endl;
    htmlFile << "<br>"<< std::endl;
    // SummedAmplitudeHisto[i]   SummedAmplitudeOccupancyHisto[i]      NoSignalSummedAmplitudeHisto[i]      NoSignalSummedAmplitudeOccupancyHisto[i]; i=0-3;(HF:i=3)
    htmlFile << "<br>"<< std::endl;
    htmlFile << "<table>"<< std::endl;        
    htmlFile << "<tr>";
    htmlFile << "<td class=\"s4\" align=\"center\">LS</td>"    << std::endl;
    //              htmlFile << "<td class=\"s1\" align=\"center\">LS</td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\"> Num.of ev.</td>"  << std::endl;
    
    //	   for (int k=k_min[sub];k<=k_max[sub]; k++) htmlFile << "<td class=\"s1\" align=\"center\">< A > Depth "<< k <<" </td>"  << std::endl;
    //	   for (int sub=1;sub<=4;sub++) htmlFile << "<td class=\"s1\" align=\"center\">< A > Depth1, sub "<< sub <<" </td>"  << std::endl;
    
    htmlFile << "<td class=\"s1\" align=\"center\">< A >HB Depth1</td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< A >HE Depth1</td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< A >HO Depth4</td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< A >HF Depth1</td>"  << std::endl;
    
    htmlFile << "<td class=\"s1\" align=\"center\">< SA >HB (Signal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< Occup. > HB (Signal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< SA >HF (Signal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< Occup. > HF (Signal) </td>"  << std::endl;

    htmlFile << "<td class=\"s1\" align=\"center\">< SA >HB (NoSignal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< Occup. > HB (NoSignal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< SA >HF (NoSignal) </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\">< Occup. > HF (NoSignal) </td>"  << std::endl;

    htmlFile << "<td class=\"s1\" align=\"center\"> maxSA HB  </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\"> maxOccup. HB </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\"> maxSA HF  </td>"  << std::endl;
    htmlFile << "<td class=\"s1\" align=\"center\"> maxOccup. HF </td>"  << std::endl;
    
    htmlFile << "</tr>"   << std::endl;    
    
    ind = 0;              
    for (int i=1;i<=MaxLum;i++) {
      if ((ind%2)==1)   raw_class="<td class=\"s2\" align=\"center\">";
      else              raw_class="<td class=\"s3\" align=\"center\">";              
      htmlFile << "<tr>"<< std::endl;
      
      htmlFile << "<td class=\"s4\" align=\"center\">" << i <<"</td>"<< std::endl;
      
      //                  htmlFile << raw_class<< LumLum->GetBinContent(i)<<"</td>"<< std::endl;
      htmlFile << raw_class<< LumiEv->GetBinContent(i)<<"</td>"<< std::endl;
      
      
      // (test==1)  <Amplitude> 
      int test=1;
      //	     for (int k=k_min[sub];k<=k_max[sub]; k++) {	              
      for (int sub=1;sub<=4; sub++) {	              
	for (int k=k_min[sub];k<=k_min[sub]; k++) {	              
	  
	  if (HistNumBadChanDepth[test][sub][k]->GetBinContent(i) > Cut0[test][sub][k]) 
	    htmlFile << "<td class=\"s6\" align=\"center\">"<<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	  
	  else  htmlFile << raw_class <<HistNumBadChanDepth[test][sub][k]->GetBinContent(i)<<"</td>"<< std::endl;
	}
      }
      if(SummedAmplitudeHisto[0]) {
      htmlFile << raw_class <<SummedAmplitudeHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<SummedAmplitudeOccupancyHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<SummedAmplitudeHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<SummedAmplitudeOccupancyHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     

      htmlFile << raw_class <<NoSignalSummedAmplitudeHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<NoSignalSummedAmplitudeOccupancyHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<NoSignalSummedAmplitudeHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<NoSignalSummedAmplitudeOccupancyHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     

      htmlFile << raw_class <<MaxxSummedAmplitudeHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<MaxxSummedAmplitudeOccupancyHisto[0]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<MaxxSummedAmplitudeHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     
      htmlFile << raw_class <<MaxxSummedAmplitudeOccupancyHisto[3]->GetBinContent(i)<<"</td>"<< std::endl;	     
      }  
      htmlFile << "</tr>" << std::endl;
      ind+=1;
    }	                
    htmlFile << "</table>" << std::endl; 
htmlFile << "<a href=\"#Top\">to top</a><br>\n";
    
    
    
    htmlFile << "<br>"<< std::endl;      
    htmlFile << "</body> " << std::endl;
    htmlFile << "</html> " << std::endl; 
    htmlFile.close();
    
    //====================================================================== // Creating description of html-files
    
    /*    
    //======================================================================
  // Creating description HELP.html file: 
  htmlFile.open("HELP.html");  
  htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
  htmlFile << "<head>"<< std::endl;
  htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
  htmlFile << "<title> Certification Monitoring Tool </title>"<< std::endl;
  htmlFile << "<style type=\"text/css\">"<< std::endl;
  htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
  htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
  htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
  htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
  htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
  htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
  htmlFile << "</style>"<< std::endl;
  htmlFile << "<body>"<< std::endl;
  htmlFile << "<h1>  Description of Remote Monitoring Tool criteria for bad channel selection</h1>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> -  CAPID Errors assuming we inspect CAPID non-rotation,error & validation bits, and for this criterion - no need to apply any cuts to select bcs.</h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> - Amplitude is full amplitude collected over all time slices </h3> "<< std::endl;
  htmlFile << "<h3> - Ratio criterion is where we define as a bad, the channels, for which the signal portion in 4 middle TSs(plus one, minus two around TS with maximal amplitude) is out of some range of reasonable values </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> - Width of shape distribution. Width is defined as square root from dispersion. </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> - Mean TS time slice position of adc signal. </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> - TS number of maximum signal </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl; 
  htmlFile << "<h3>  For more details see https://twiki.cern.ch/twiki/bin/viewauth/CMS/HcalRemoteCertificationMonitoring </h3> "<< std::endl;   
  htmlFile << "</body> " << std::endl;
  htmlFile << "</html> " << std::endl; 
  htmlFile.close();
*/  
  //======================================================================
  // Creating description CMTresults.html file: 
  htmlFile.open("CMTresults.html");  
  htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
  htmlFile << "<head>"<< std::endl;
  htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
  htmlFile << "<title> Certification Monitoring Tool </title>"<< std::endl;
  htmlFile << "<style type=\"text/css\">"<< std::endl;
  htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
  htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
  htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
  htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
  htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
  htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
  htmlFile << "</style>"<< std::endl;
  htmlFile << "<body>"<< std::endl;
  htmlFile << "<h1>  LS-certification (recommendation) from analysis of CMT-dependencies of THIS run </h1>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h2> - List of suspicious LSs:  </h2> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> to be added </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h2> - Comments: </h2> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<h3> to be added </h3> "<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl; 
  htmlFile << "</body> " << std::endl;
  htmlFile << "</html> " << std::endl; 
  htmlFile.close();
  
  //======================================================================
  // Creating main html file: 
  
  htmlFile.open("LumiList.html");  
  htmlFile << "</html><html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
  htmlFile << "<head>"<< std::endl;
  htmlFile << "<meta http-equiv=\"Content-Type\" content=\"text/html\"/>"<< std::endl;
  htmlFile << "<title> Certification Monitoring Tool </title>"<< std::endl;
  htmlFile << "<style type=\"text/css\">"<< std::endl;
  htmlFile << " body,td{ background-color: #FFFFCC; font-family: arial, arial ce, helvetica; font-size: 12px; }"<< std::endl;
  htmlFile << "   td.s0 { font-family: arial, arial ce, helvetica; }"<< std::endl;
  htmlFile << "   td.s1 { font-family: arial, arial ce, helvetica; font-weight: bold; background-color: #FFC169; text-align: center;}"<< std::endl;
  htmlFile << "   td.s2 { font-family: arial, arial ce, helvetica; background-color: #eeeeee; }"<< std::endl;
  htmlFile << "   td.s3 { font-family: arial, arial ce, helvetica; background-color: #d0d0d0; }"<< std::endl;
  htmlFile << "   td.s4 { font-family: arial, arial ce, helvetica; background-color: #FFC169; }"<< std::endl;
  htmlFile << "   td.s5 { font-family: arial, arial ce, helvetica; background-color: #00FF00; }"<< std::endl;
  htmlFile << "   td.s6 { font-family: arial, arial ce, helvetica; background-color: #FF0000; }"<< std::endl;
  
  htmlFile << "</style>"<< std::endl;
  htmlFile << "<body>"<< std::endl;
  
  htmlFile << "<h1> Certification Monitoring Tool, GLOBAL RUN = "<< runnumber <<". </h1>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/CMTresults.html\">  CMT-analysis RESULTS (for this run) </a></td>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<br>"<< std::endl; 

  //  htmlFile << "<h2> 1. General information </h2>"<< std::endl;   
  htmlFile << "<h2> 1. General information     (Full number of LS = "<< MaxLum <<" ). </h2>"<< std::endl;   
  htmlFile << " <img src=\"LumiEvent.png\" />" << std::endl;      
  htmlFile << "<br>"<< std::endl;
  
  
  htmlFile << "<h2> 2. HCAL status for different criteria </h2>"<< std::endl;   
  //  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/HELP.html\"> Description of criteria for bad channel selection</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/HELP.html\"> Description of criteria for bad channel selection</a></td>"<< std::endl;
  htmlFile << "<br>"<< std::endl;
  htmlFile << "<table width=\"600\">"<< std::endl;
  htmlFile << "<tr>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/CapID_GL.html\">Cap ID errors</a></td>"<< std::endl;
  // AZ 18.03.2018
  //  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/ADCampl_GL.html\">Amplitude</a></td>"<< std::endl;
  htmlFile << "  <td><a  href=\"ADCampl_GL.html\">Amplitude</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/Width_GL.html\">Width</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/Ratio_GL.html\">Ratio</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/Tmean_GL.html\">TS mean</a></td>"<< std::endl;
  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/Tmax_GL.html\">TS max</a></td>"<< std::endl;

  htmlFile << "  <td><a href=\"https://cms-cpt-software.web.cern.ch/cms-cpt-software/General/Validation/SVSuite/HcalRemoteMonitoring/CMT/GLOBAL_"<<runnumber<<"/SummedAmplitudes_GL.html\">SummedAmplitudes</a></td>"<< std::endl;

  htmlFile << "</tr>"<< std::endl;
  htmlFile << "</table>"<< std::endl;
  htmlFile << "<br>"<< std::endl;    
  htmlFile << "</body> " << std::endl;
  htmlFile << "</html> " << std::endl; 
  htmlFile.close();  
  //======================================================================
  
  //======================================================================
  // Close and delete all possible things:
  hfile->Close();    
  //  hfile->Delete();
  //  Exit Root
  gSystem->Exit(0);
  //======================================================================
  
}


// ------------------------------------------------------------

int copyContents(TH1F **hDest, TString hname, TString htitle,
		 const TH1F *hSrc, int lastBin)
{
  if (lastBin > hSrc->GetNbinsX()) {
    std::cout << "copyContents from " << hSrc->GetName() << ": histo has "
	      << hSrc->GetNbinsX() << " bins, when lastBin=" << lastBin
	      << " was requested\n";
    return 0;
  }
  
  (*hDest)= new TH1F(hname,htitle,lastBin,0,lastBin);
  (*hDest)->SetDirectory(0);
  (*hDest)->SetStats(0);
  
  for (int ibin=1; ibin<=lastBin; ibin++) {
    (*hDest)->SetBinContent(ibin, hSrc->GetBinContent(ibin));
    (*hDest)->SetBinError(ibin, hSrc->GetBinError(ibin));
  }
  return 1;
}

// ------------------------------------------------------------
