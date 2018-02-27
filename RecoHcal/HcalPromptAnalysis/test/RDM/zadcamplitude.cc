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
#include <TPaveText.h>
#include <TPostScript.h>
#include <TClass.h>

//
using namespace std;
//
//  

//inline void HERE(const char *msg) { std::cout << msg << std::endl; }


int main(int argc, char *argv[])
{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	//			gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// name mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		gStyle->SetOptStat(101110);                                          // entries, mean, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		  			//	gStyle->SetOptStat(100000);//  over !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//
	//gStyle->SetOptFit(00010);// constant, mean and sigma only !!
		//	gStyle->SetOptFit(00001);// hi2/nu, constant, mean and sigma only !!
		gStyle->SetOptFit(0010);// constant, mean and sigma only !!
	//	gStyle->SetOptFit(00011);// constant, mean and sigma only !!
	// gStyle->SetOptFit(1101);
		//	   gStyle->SetOptFit(1011);
	//
	//gStyle->SetStatX(0.98);
	//gStyle->SetStatY(0.99);
	//gStyle->SetStatW(0.30);
	//gStyle->SetStatH(0.25);
	gStyle->SetStatX(0.91);
	gStyle->SetStatY(0.75);
	gStyle->SetStatW(0.20);
	gStyle->SetStatH(0.10);
	// gStyle->SetStatH(0.35);
        //

	//        Float_t LeftOffset = 0.12;
        //Float_t TopOffset = 0.12;
        Float_t LeftOffset = 0.12;
        Float_t TopOffset = 0.22;

        gStyle->SetLineWidth(1);
        gStyle->SetErrorX(0);

//---=[ Titles,Labels ]=-----------
        gStyle->SetOptTitle(0);             // title on/off
        //      gStyle->SetTitleColor(0);           // title color
        gStyle->SetTitleColor(1);           // title color
        //      gStyle->SetTitleX(0.35);            // title x-position
        gStyle->SetTitleX(0.15);            // title x-position
        gStyle->SetTitleH(0.15);             // title height
        //      gStyle->SetTitleW(0.53);            // title width
        gStyle->SetTitleW(0.60);            // title width
        gStyle->SetTitleFont(42);           // title font
        gStyle->SetTitleFontSize(0.07);     // title font size

	gStyle->SetPalette(1);
//---=[ Histogram style ]=----------
        //        gStyle->SetHistFillColor(38);
	//	        gStyle->SetFrameFillColor(41);// jelto-kori4nev-svetl
	//	gStyle->SetFrameFillColor(5);// jeltyi
	//	gStyle->SetFrameFillColor(17);// seryi
	//	gStyle->SetFrameFillColor(18);// svetlo seryi
	//	gStyle->SetFrameFillColor(20);// svetlo kori4nev
	//        gStyle->SetFrameFillColor(33);// sine-seryi
	//	gStyle->SetFrameFillColor(40);// fiolet-seryi
	//	gStyle->SetFrameFillColor(23);// sv.kor

//---=[ Pad style ]=----------------
        gStyle->SetPadTopMargin(TopOffset);
        gStyle->SetPadBottomMargin(LeftOffset);
        gStyle->SetPadRightMargin(TopOffset);
        gStyle->SetPadLeftMargin(LeftOffset);
//---=[ SetCanvasDef           ]=----------------
    //======================================================================
//
// Connect the input file and get the 2-d histogram in memory
    //======================================================================
//  TBrowser *b = new TBrowser

//	TFile *hfile1= new TFile("test.root", "READ"); 
//


//	TFile *hfile1= new TFile("testNZS.root", "READ"); 
//	TFile *hfile1= new TFile("test.root", "READ"); 


//	TFile *hfile1= new TFile("newruns/Global_234034.root", "READ");
//


//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234556.root", "READ");
//	TFile *hfile1= new TFile("Global_234034.root", "READ");
//	TFile *hfile1= new TFile("test211006.root", "READ");
//	TFile *hfile1= new TFile("test234457.root", "READ");

//	TFile *hfile1= new TFile("Global_51.root", "READ");
//	TFile *hfile1= new TFile("Global_235698.root", "READ");

//	TFile *hfile1= new TFile("Global_39.root", "READ");
//	TFile *hfile1= new TFile("test237165.root", "READ");
//
//	TFile *hfile1= new TFile("Laser_238187.root", "READ");
//	TFile *hfile1= new TFile("Laser_238183.root", "READ");

//	TFile *hfile1= new TFile("Global_255031.root", "READ");

//	TFile *hfile1= new TFile("Global_256001.root", "READ");
//	TFile *hfile1= new TFile("Global_256167.root", "READ");
// 	TFile *hfile1= new TFile("Global_256348.root", "READ");
//	TFile *hfile1= new TFile("Global_256630.root", "READ");

//	TFile *hfile1= new TFile("../PYTHON_runlist_test/Global_283884_1.root", "READ");
//        TFile *hfile1= new TFile("Global_test.root", "READ");

//	TFile *hfile1= new TFile("LED_280702.root", "READ");        
	//	TFile *hfile2= new TFile("LED_287824.root", "READ");

	//	TFile *hfile1= new TFile("LED_284352.root", "READ");        
	TFile *hfile1= new TFile("LEDtest.root", "READ");




	//	TFile *hfile2= new TFile("LED_284902.root", "READ");
	//	TFile *hfile2= new TFile("LED_284499.root", "READ");
	//	TFile *hfile2= new TFile("LED_284352.root", "READ");

	//	TFile *hfile2= new TFile("LED_286590.root", "READ");



	//    getchar();
	//
          TPostScript psfile ("zadcamplitude.ps", 111);


//

 TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth1hb1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
      TH2F *twoddepth1hb0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twoddepth1hb1->Sumw2();
      twoddepth1hb0->Sumw2();
      //    if(twoddepth1hb0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1hbff = (TH2F*)twoddepth1hb1->Clone("Cdepth1hbff");
	Cdepth1hbff->Divide(twoddepth1hb1,twoddepth1hb0, 1, 1, "B");
	Cdepth1hbff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth1hb1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HB");
      TH2F *twoedepth1hb0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twoedepth1hb1->Sumw2();
      twoedepth1hb0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1hbfz225= (TH2F*)twoedepth1hb1->Clone("Cdepth1hbfz225");
	Cdepth1hbfz225->Divide(twoedepth1hb1,twoedepth1hb0, 1, 1, "B");
	Cdepth1hbfz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth1hbfz225->SetMarkerStyle(20);
      Cdepth1hbfz225->SetMarkerSize(0.4);
      //    Cdepth1hbfz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth1hbfz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth1hbfz225->SetXTitle("#eta \b");
      Cdepth1hbfz225->SetYTitle("#phi \b");
      Cdepth1hbfz225->SetZTitle("Rate for ADCAmpl in each event & cell - HB Depth1 \b");
      Cdepth1hbfz225->SetMarkerColor(2);
      Cdepth1hbfz225->SetLineColor(2);
      Cdepth1hbfz225->SetMaximum(1.000);
      Cdepth1hbfz225->SetMinimum(0.00001);
//      Cdepth1hbfz225->SetMinimum(0.0001);
      Cdepth1hbfz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth1hb= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
      TH1F *adepth1hb= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HB");
//      TH1F *adepth1hb= (TH1F*)hfile1->Get("h_ADCAmplZoom_HB");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth1hb->SetMarkerStyle(20);
      adepth1hb->SetMarkerSize(0.8);
      adepth1hb->GetYaxis()->SetLabelSize(0.04);
      adepth1hb->SetXTitle("ADCAmpl in each event & cell HB \b");
      adepth1hb->SetMarkerColor(2);
      adepth1hb->SetLineColor(2);
      adepth1hb->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth1hb = (TH2F*)Cdepth1hbff->Clone("Diffe_Depth1hb");
    for (int i=1;i<=Cdepth1hbff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth1hbff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth1hbff = (TH2F*)twoddepth1hb1->Clone("Cdepth1hbff");
	double ccc1 =  Cdepth1hbff->GetBinContent(i,j)   ;
	Diffe_Depth1hb->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth1hb->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1hb->SetMarkerStyle(20);
      Diffe_Depth1hb->SetMarkerSize(0.4);
      Diffe_Depth1hb->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1hb->SetTitle("any Error, HB Depth1hb \n");
      Diffe_Depth1hb->SetXTitle("#eta \b");
      Diffe_Depth1hb->SetYTitle("#phi \b");
      Diffe_Depth1hb->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HB Depth1hb \b");
      Diffe_Depth1hb->SetMarkerColor(2);
      Diffe_Depth1hb->SetLineColor(2);
      //      Diffe_Depth1hb->SetMaximum(1.000);
      //      Diffe_Depth1hb->SetMinimum(0.0000001);
      Diffe_Depth1hb->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth1hb = new TH1F("diffADCAmpl_Depth1hb","", 100, 0.,3000.);
      TH2F* Cdepth1hbfw = (TH2F*)twoddepth1hb1->Clone("diffADCAmpl_Depth1hb");
      for (int i=1;i<=Cdepth1hbfw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth1hbfw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth1hbff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth1hbff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1hb->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1hb->SetMarkerStyle(20);
      diffADCAmpl_Depth1hb->SetMarkerSize(0.4);
      diffADCAmpl_Depth1hb->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1hb->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1hb->SetMarkerColor(2);
      diffADCAmpl_Depth1hb->SetLineColor(2);
      diffADCAmpl_Depth1hb->Draw("");
             
      c1->Update();

      delete twoddepth1hb0;     
      delete twoddepth1hb1;     
      delete adepth1hb;
      delete Cdepth1hbfz225;
      delete Cdepth1hbff;
      delete diffADCAmpl_Depth1hb;
      delete Diffe_Depth1hb;
            
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth2hb1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HB");
      TH2F *twoddepth2hb0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twoddepth2hb1->Sumw2();
      twoddepth2hb0->Sumw2();
      //    if(twoddepth2hb0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2hbff = (TH2F*)twoddepth2hb1->Clone("Cdepth2hbff");
	Cdepth2hbff->Divide(twoddepth2hb1,twoddepth2hb0, 1, 1, "B");
	Cdepth2hbff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth2hb1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225_HB");
      TH2F *twoedepth2hb0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twoedepth2hb1->Sumw2();
      twoedepth2hb0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2hbfz225= (TH2F*)twoedepth2hb1->Clone("Cdepth2hbfz225");
	Cdepth2hbfz225->Divide(twoedepth2hb1,twoedepth2hb0, 1, 1, "B");
	Cdepth2hbfz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth2hbfz225->SetMarkerStyle(20);
      Cdepth2hbfz225->SetMarkerSize(0.4);
      //    Cdepth2hbfz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth2hbfz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth2hbfz225->SetXTitle("#eta \b");
      Cdepth2hbfz225->SetYTitle("#phi \b");
      Cdepth2hbfz225->SetZTitle("Rate for ADCAmpl in each event & cell - HB Depth2 \b");
      Cdepth2hbfz225->SetMarkerColor(2);
      Cdepth2hbfz225->SetLineColor(2);
      Cdepth2hbfz225->SetMaximum(1.000);
      Cdepth2hbfz225->SetMinimum(0.00001);
//      Cdepth2hbfz225->SetMinimum(0.0001);
      Cdepth2hbfz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth2hb= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
      TH1F *adepth2hb= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HB");
//      TH1F *adepth2hb= (TH1F*)hfile1->Get("h_ADCAmplZoom_HB");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth2hb->SetMarkerStyle(20);
      adepth2hb->SetMarkerSize(0.8);
      adepth2hb->GetYaxis()->SetLabelSize(0.04);
      adepth2hb->SetXTitle("ADCAmpl in each event & cell HB \b");
      adepth2hb->SetMarkerColor(2);
      adepth2hb->SetLineColor(2);
      adepth2hb->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth2hb = (TH2F*)Cdepth2hbff->Clone("Diffe_Depth2hb");
    for (int i=1;i<=Cdepth2hbff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth2hbff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth2hbff = (TH2F*)twoddepth2hb1->Clone("Cdepth2hbff");
	double ccc1 =  Cdepth2hbff->GetBinContent(i,j)   ;
	Diffe_Depth2hb->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth2hb->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2hb->SetMarkerStyle(20);
      Diffe_Depth2hb->SetMarkerSize(0.4);
      Diffe_Depth2hb->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth2hb->SetTitle("any Error, HB Depth2hb \n");
      Diffe_Depth2hb->SetXTitle("#eta \b");
      Diffe_Depth2hb->SetYTitle("#phi \b");
      Diffe_Depth2hb->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HB Depth2hb \b");
      Diffe_Depth2hb->SetMarkerColor(2);
      Diffe_Depth2hb->SetLineColor(2);
      //      Diffe_Depth2hb->SetMaximum(1.000);
      //      Diffe_Depth2hb->SetMinimum(0.0000001);
      Diffe_Depth2hb->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth2hb = new TH1F("diffADCAmpl_Depth2hb","", 100, 0.,3000.);
      TH2F* Cdepth2hbfw = (TH2F*)twoddepth2hb1->Clone("diffADCAmpl_Depth2hb");
      for (int i=1;i<=Cdepth2hbfw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth2hbfw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth2hbff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth2hbff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth2hb->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth2hb->SetMarkerStyle(20);
      diffADCAmpl_Depth2hb->SetMarkerSize(0.4);
      diffADCAmpl_Depth2hb->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth2hb->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth2hb->SetMarkerColor(2);
      diffADCAmpl_Depth2hb->SetLineColor(2);
      diffADCAmpl_Depth2hb->Draw("");
             
      c1->Update();
      
      delete twoddepth2hb0;     
      delete twoddepth2hb1;     
      delete adepth2hb;
      delete Cdepth2hbfz225;
      delete Cdepth2hbff;
      delete diffADCAmpl_Depth2hb;
      delete Diffe_Depth2hb;
      
            
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth1he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      TH2F *twoddepth1he0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twoddepth1he1->Sumw2();
      twoddepth1he0->Sumw2();
      //    if(twoddepth1he0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1heff = (TH2F*)twoddepth1he1->Clone("Cdepth1heff");
	Cdepth1heff->Divide(twoddepth1he1,twoddepth1he0, 1, 1, "B");
	Cdepth1heff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth1he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HE");
      TH2F *twoedepth1he0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twoedepth1he1->Sumw2();
      twoedepth1he0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1hefz225= (TH2F*)twoedepth1he1->Clone("Cdepth1hefz225");
	Cdepth1hefz225->Divide(twoedepth1he1,twoedepth1he0, 1, 1, "B");
	Cdepth1hefz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth1hefz225->SetMarkerStyle(20);
      Cdepth1hefz225->SetMarkerSize(0.4);
      //    Cdepth1hefz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth1hefz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth1hefz225->SetXTitle("#eta \b");
      Cdepth1hefz225->SetYTitle("#phi \b");
      Cdepth1hefz225->SetZTitle("Rate for ADCAmpl in each event & cell - HE Depth1 \b");
      Cdepth1hefz225->SetMarkerColor(2);
      Cdepth1hefz225->SetLineColor(2);
      Cdepth1hefz225->SetMaximum(1.000);
      Cdepth1hefz225->SetMinimum(0.00001);
//      Cdepth1hefz225->SetMinimum(0.0001);
      Cdepth1hefz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth1he= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      TH1F *adepth1he= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
//      TH1F *adepth1he= (TH1F*)hfile1->Get("h_ADCAmplZoom_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth1he->SetMarkerStyle(20);
      adepth1he->SetMarkerSize(0.8);
      adepth1he->GetYaxis()->SetLabelSize(0.04);
      adepth1he->SetXTitle("ADCAmpl in each event & cell HE \b");
      adepth1he->SetMarkerColor(2);
      adepth1he->SetLineColor(2);
      adepth1he->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth1he = (TH2F*)Cdepth1heff->Clone("Diffe_Depth1he");
    for (int i=1;i<=Cdepth1heff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth1heff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth1heff = (TH2F*)twoddepth1he1->Clone("Cdepth1heff");
	double ccc1 =  Cdepth1heff->GetBinContent(i,j)   ;
	Diffe_Depth1he->SetBinContent(i,j,0.);
		if(ccc1 <18|| ccc1>30.)  Diffe_Depth1he->SetBinContent(i,j,ccc1);
	//	if(ccc1 <5000.)  Diffe_Depth1he->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1he->SetMarkerStyle(20);
      Diffe_Depth1he->SetMarkerSize(0.4);
      Diffe_Depth1he->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1he->SetTitle("any Error, HE Depth1he \n");
      Diffe_Depth1he->SetXTitle("#eta \b");
      Diffe_Depth1he->SetYTitle("#phi \b");
      Diffe_Depth1he->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HE Depth1he \b");
      Diffe_Depth1he->SetMarkerColor(2);
      Diffe_Depth1he->SetLineColor(2);
      //      Diffe_Depth1he->SetMaximum(1.000);
      //      Diffe_Depth1he->SetMinimum(0.0000001);
      Diffe_Depth1he->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth1he = new TH1F("diffADCAmpl_Depth1he","", 100, 0.,5000.);
      TH2F* Cdepth1hefw = (TH2F*)Cdepth1heff->Clone("diffADCAmpl_Depth1he");
      for (int i=1;i<=Cdepth1hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth1hefw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth1heff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth1heff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1he->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1he->SetMarkerStyle(20);
      diffADCAmpl_Depth1he->SetMarkerSize(0.4);
      diffADCAmpl_Depth1he->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1he->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1he->SetMarkerColor(2);
      diffADCAmpl_Depth1he->SetLineColor(2);
      diffADCAmpl_Depth1he->Draw("");
             
      c1->Update();
      
      delete twoddepth1he0;     
      delete twoddepth1he1;     
      delete adepth1he;
      delete Cdepth1hefz225;
      delete Cdepth1heff;
      delete diffADCAmpl_Depth1he;
      delete Diffe_Depth1he;
      
            
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth2he1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HE");
      TH2F *twoddepth2he0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twoddepth2he1->Sumw2();
      twoddepth2he0->Sumw2();
      //    if(twoddepth2he0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2heff = (TH2F*)twoddepth2he1->Clone("Cdepth2heff");
	Cdepth2heff->Divide(twoddepth2he1,twoddepth2he0, 1, 1, "B");
	Cdepth2heff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth2he1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225_HE");
      TH2F *twoedepth2he0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twoedepth2he1->Sumw2();
      twoedepth2he0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2hefz225= (TH2F*)twoedepth2he1->Clone("Cdepth2hefz225");
	Cdepth2hefz225->Divide(twoedepth2he1,twoedepth2he0, 1, 1, "B");
	Cdepth2hefz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth2hefz225->SetMarkerStyle(20);
      Cdepth2hefz225->SetMarkerSize(0.4);
      //    Cdepth2hefz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth2hefz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth2hefz225->SetXTitle("#eta \b");
      Cdepth2hefz225->SetYTitle("#phi \b");
      Cdepth2hefz225->SetZTitle("Rate for ADCAmpl in each event & cell - HE Depth2 \b");
      Cdepth2hefz225->SetMarkerColor(2);
      Cdepth2hefz225->SetLineColor(2);
      Cdepth2hefz225->SetMaximum(1.000);
      Cdepth2hefz225->SetMinimum(0.00001);
//      Cdepth2hefz225->SetMinimum(0.0001);
      Cdepth2hefz225->Draw("COLZ");
      
      c1->cd(2);
      
          TH1F *adepth2he= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
 //     TH1F *adepth2he= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
//      TH1F *adepth2he= (TH1F*)hfile1->Get("h_ADCAmplZoom_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth2he->SetMarkerStyle(20);
      adepth2he->SetMarkerSize(0.8);
      adepth2he->GetYaxis()->SetLabelSize(0.04);
      adepth2he->SetXTitle("ADCAmpl in each event & cell HE \b");
      adepth2he->SetMarkerColor(2);
      adepth2he->SetLineColor(2);
      adepth2he->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth2he = (TH2F*)Cdepth2heff->Clone("Diffe_Depth2he");
    for (int i=1;i<=Cdepth2heff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth2heff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth2heff = (TH2F*)twoddepth2he1->Clone("Cdepth2heff");
	double ccc1 =  Cdepth2heff->GetBinContent(i,j)   ;
	Diffe_Depth2he->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth2he->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2he->SetMarkerStyle(20);
      Diffe_Depth2he->SetMarkerSize(0.4);
      Diffe_Depth2he->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth2he->SetTitle("any Error, HE Depth2he \n");
      Diffe_Depth2he->SetXTitle("#eta \b");
      Diffe_Depth2he->SetYTitle("#phi \b");
      Diffe_Depth2he->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HE Depth2he \b");
      Diffe_Depth2he->SetMarkerColor(2);
      Diffe_Depth2he->SetLineColor(2);
      //      Diffe_Depth2he->SetMaximum(1.000);
      //      Diffe_Depth2he->SetMinimum(0.0000001);
      Diffe_Depth2he->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth2he = new TH1F("diffADCAmpl_Depth2he","", 100, 0.,3000.);
      TH2F* Cdepth2hefw = (TH2F*)twoddepth2he1->Clone("diffADCAmpl_Depth2he");
      for (int i=1;i<=Cdepth2hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth2hefw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth2heff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth2heff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth2he->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth2he->SetMarkerStyle(20);
      diffADCAmpl_Depth2he->SetMarkerSize(0.4);
      diffADCAmpl_Depth2he->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth2he->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth2he->SetMarkerColor(2);
      diffADCAmpl_Depth2he->SetLineColor(2);
      diffADCAmpl_Depth2he->Draw("");
             
      c1->Update();
      
      delete twoddepth2he0;     
      delete twoddepth2he1;     
      delete adepth2he;
      delete Cdepth2hefz225;
      delete Cdepth2heff;
      delete diffADCAmpl_Depth2he;
      delete Diffe_Depth2he;
      
            
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth3he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      TH2F *twoddepth3he0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twoddepth3he1->Sumw2();
      twoddepth3he0->Sumw2();
      //    if(twoddepth3he0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth3heff = (TH2F*)twoddepth3he1->Clone("Cdepth3heff");
	Cdepth3heff->Divide(twoddepth3he1,twoddepth3he0, 1, 1, "B");
	Cdepth3heff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth3he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HE");
      TH2F *twoedepth3he0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twoedepth3he1->Sumw2();
      twoedepth3he0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth3hefz225= (TH2F*)twoedepth3he1->Clone("Cdepth3hefz225");
	Cdepth3hefz225->Divide(twoedepth3he1,twoedepth3he0, 1, 1, "B");
	Cdepth3hefz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth3hefz225->SetMarkerStyle(20);
      Cdepth3hefz225->SetMarkerSize(0.4);
      //    Cdepth3hefz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth3hefz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth3hefz225->SetXTitle("#eta \b");
      Cdepth3hefz225->SetYTitle("#phi \b");
      Cdepth3hefz225->SetZTitle("Rate for ADCAmpl in each event & cell - HE Depth1 \b");
      Cdepth3hefz225->SetMarkerColor(2);
      Cdepth3hefz225->SetLineColor(2);
      Cdepth3hefz225->SetMaximum(1.000);
      Cdepth3hefz225->SetMinimum(0.00001);
//      Cdepth3hefz225->SetMinimum(0.0001);
      Cdepth3hefz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth3he= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      TH1F *adepth3he= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
//      TH1F *adepth3he= (TH1F*)hfile1->Get("h_ADCAmplZoom_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth3he->SetMarkerStyle(20);
      adepth3he->SetMarkerSize(0.8);
      adepth3he->GetYaxis()->SetLabelSize(0.04);
      adepth3he->SetXTitle("ADCAmpl in each event & cell HE \b");
      adepth3he->SetMarkerColor(2);
      adepth3he->SetLineColor(2);
      adepth3he->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth3he = (TH2F*)Cdepth3heff->Clone("Diffe_Depth3he");
    for (int i=1;i<=Cdepth3heff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth3heff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth3heff = (TH2F*)twoddepth3he1->Clone("Cdepth3heff");
	double ccc1 =  Cdepth3heff->GetBinContent(i,j)   ;
	Diffe_Depth3he->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth3he->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth3he->SetMarkerStyle(20);
      Diffe_Depth3he->SetMarkerSize(0.4);
      Diffe_Depth3he->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth3he->SetTitle("any Error, HE Depth3he \n");
      Diffe_Depth3he->SetXTitle("#eta \b");
      Diffe_Depth3he->SetYTitle("#phi \b");
      Diffe_Depth3he->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HE Depth3he \b");
      Diffe_Depth3he->SetMarkerColor(2);
      Diffe_Depth3he->SetLineColor(2);
      //      Diffe_Depth3he->SetMaximum(1.000);
      //      Diffe_Depth3he->SetMinimum(0.0000001);
      Diffe_Depth3he->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth3he = new TH1F("diffADCAmpl_Depth3he","", 100, 0.,3000.);
      TH2F* Cdepth3hefw = (TH2F*)twoddepth3he1->Clone("diffADCAmpl_Depth3he");
      for (int i=1;i<=Cdepth3hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth3hefw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth3heff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth3heff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth3he->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth3he->SetMarkerStyle(20);
      diffADCAmpl_Depth3he->SetMarkerSize(0.4);
      diffADCAmpl_Depth3he->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth3he->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth3he->SetMarkerColor(2);
      diffADCAmpl_Depth3he->SetLineColor(2);
      diffADCAmpl_Depth3he->Draw("");
             
      c1->Update();
      
      delete twoddepth3he0;     
      delete twoddepth3he1;     
      delete adepth3he;
      delete Cdepth3hefz225;
      delete Cdepth3heff;
      delete diffADCAmpl_Depth3he;
      delete Diffe_Depth3he;
      
      
            
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth1hf1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
      TH2F *twoddepth1hf0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twoddepth1hf1->Sumw2();
      twoddepth1hf0->Sumw2();
      //    if(twoddepth1hf0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1hfff = (TH2F*)twoddepth1hf1->Clone("Cdepth1hfff");
	Cdepth1hfff->Divide(twoddepth1hf1,twoddepth1hf0, 1, 1, "B");
	Cdepth1hfff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth1hf1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HF");
      TH2F *twoedepth1hf0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twoedepth1hf1->Sumw2();
      twoedepth1hf0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth1hffz225= (TH2F*)twoedepth1hf1->Clone("Cdepth1hffz225");
	Cdepth1hffz225->Divide(twoedepth1hf1,twoedepth1hf0, 1, 1, "B");
	Cdepth1hffz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth1hffz225->SetMarkerStyle(20);
      Cdepth1hffz225->SetMarkerSize(0.4);
      //    Cdepth1hffz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth1hffz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth1hffz225->SetXTitle("#eta \b");
      Cdepth1hffz225->SetYTitle("#phi \b");
      Cdepth1hffz225->SetZTitle("Rate for ADCAmpl in each event & cell - HF Depth1 \b");
      Cdepth1hffz225->SetMarkerColor(2);
      Cdepth1hffz225->SetLineColor(2);
      Cdepth1hffz225->SetMaximum(1.000);
      Cdepth1hffz225->SetMinimum(0.00001);
//      Cdepth1hffz225->SetMinimum(0.0001);
      Cdepth1hffz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth1hf= (TH1F*)hfile1->Get("h_ADCAmpl_HF");
      TH1F *adepth1hf= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HF");
//      TH1F *adepth1hf= (TH1F*)hfile1->Get("h_ADCAmplZoom_HF");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth1hf->SetMarkerStyle(20);
      adepth1hf->SetMarkerSize(0.8);
      adepth1hf->GetYaxis()->SetLabelSize(0.04);
      adepth1hf->SetXTitle("ADCAmpl in each event & cell HF \b");
      adepth1hf->SetMarkerColor(2);
      adepth1hf->SetLineColor(2);
      adepth1hf->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth1hf = (TH2F*)Cdepth1hfff->Clone("Diffe_Depth1hf");
    for (int i=1;i<=Cdepth1hfff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth1hfff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth1hfff = (TH2F*)twoddepth1hf1->Clone("Cdepth1hfff");
	double ccc1 =  Cdepth1hfff->GetBinContent(i,j)   ;
	Diffe_Depth1hf->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth1hf->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1hf->SetMarkerStyle(20);
      Diffe_Depth1hf->SetMarkerSize(0.4);
      Diffe_Depth1hf->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1hf->SetTitle("any Error, HF Depth1hf \n");
      Diffe_Depth1hf->SetXTitle("#eta \b");
      Diffe_Depth1hf->SetYTitle("#phi \b");
      Diffe_Depth1hf->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HF Depth1hf \b");
      Diffe_Depth1hf->SetMarkerColor(2);
      Diffe_Depth1hf->SetLineColor(2);
      //      Diffe_Depth1hf->SetMaximum(1.000);
      //      Diffe_Depth1hf->SetMinimum(0.0000001);
      Diffe_Depth1hf->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth1hf = new TH1F("diffADCAmpl_Depth1hf","", 100, 0.,3000.);
      TH2F* Cdepth1hffw = (TH2F*)twoddepth1hf1->Clone("diffADCAmpl_Depth1hf");
      for (int i=1;i<=Cdepth1hffw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth1hffw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth1hfff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth1hfff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1hf->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1hf->SetMarkerStyle(20);
      diffADCAmpl_Depth1hf->SetMarkerSize(0.4);
      diffADCAmpl_Depth1hf->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1hf->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1hf->SetMarkerColor(2);
      diffADCAmpl_Depth1hf->SetLineColor(2);
      diffADCAmpl_Depth1hf->Draw("");
             
      c1->Update();
      
      delete twoddepth1hf0;     
      delete twoddepth1hf1;     
      delete adepth1hf;
      delete Cdepth1hffz225;
      delete Cdepth1hfff;
      delete diffADCAmpl_Depth1hf;
      delete Diffe_Depth1hf;
      
            
    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth2hf1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HF");
      TH2F *twoddepth2hf0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twoddepth2hf1->Sumw2();
      twoddepth2hf0->Sumw2();
      //    if(twoddepth2hf0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2hfff = (TH2F*)twoddepth2hf1->Clone("Cdepth2hfff");
	Cdepth2hfff->Divide(twoddepth2hf1,twoddepth2hf0, 1, 1, "B");
	Cdepth2hfff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth2hf1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225_HF");
      TH2F *twoedepth2hf0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twoedepth2hf1->Sumw2();
      twoedepth2hf0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth2hffz225= (TH2F*)twoedepth2hf1->Clone("Cdepth2hffz225");
	Cdepth2hffz225->Divide(twoedepth2hf1,twoedepth2hf0, 1, 1, "B");
	Cdepth2hffz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth2hffz225->SetMarkerStyle(20);
      Cdepth2hffz225->SetMarkerSize(0.4);
      //    Cdepth2hffz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth2hffz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth2hffz225->SetXTitle("#eta \b");
      Cdepth2hffz225->SetYTitle("#phi \b");
      Cdepth2hffz225->SetZTitle("Rate for ADCAmpl in each event & cell - HF Depth2 \b");
      Cdepth2hffz225->SetMarkerColor(2);
      Cdepth2hffz225->SetLineColor(2);
      Cdepth2hffz225->SetMaximum(1.000);
      Cdepth2hffz225->SetMinimum(0.00001);
//      Cdepth2hffz225->SetMinimum(0.0001);
      Cdepth2hffz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *adepth2hf= (TH1F*)hfile1->Get("h_ADCAmpl_HF");
      TH1F *adepth2hf= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HF");
//      TH1F *adepth2hf= (TH1F*)hfile1->Get("h_ADCAmplZoom_HF");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth2hf->SetMarkerStyle(20);
      adepth2hf->SetMarkerSize(0.8);
      adepth2hf->GetYaxis()->SetLabelSize(0.04);
      adepth2hf->SetXTitle("ADCAmpl in each event & cell HF \b");
      adepth2hf->SetMarkerColor(2);
      adepth2hf->SetLineColor(2);
      adepth2hf->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth2hf = (TH2F*)Cdepth2hfff->Clone("Diffe_Depth2hf");
    for (int i=1;i<=Cdepth2hfff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth2hfff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth2hfff = (TH2F*)twoddepth2hf1->Clone("Cdepth2hfff");
	double ccc1 =  Cdepth2hfff->GetBinContent(i,j)   ;
	Diffe_Depth2hf->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth2hf->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2hf->SetMarkerStyle(20);
      Diffe_Depth2hf->SetMarkerSize(0.4);
      Diffe_Depth2hf->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth2hf->SetTitle("any Error, HF Depth2hf \n");
      Diffe_Depth2hf->SetXTitle("#eta \b");
      Diffe_Depth2hf->SetYTitle("#phi \b");
      Diffe_Depth2hf->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HF Depth2hf \b");
      Diffe_Depth2hf->SetMarkerColor(2);
      Diffe_Depth2hf->SetLineColor(2);
      //      Diffe_Depth2hf->SetMaximum(1.000);
      //      Diffe_Depth2hf->SetMinimum(0.0000001);
      Diffe_Depth2hf->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth2hf = new TH1F("diffADCAmpl_Depth2hf","", 100, 0.,3000.);
      TH2F* Cdepth2hffw = (TH2F*)twoddepth2hf1->Clone("diffADCAmpl_Depth2hf");
      for (int i=1;i<=Cdepth2hffw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth2hffw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth2hfff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth2hfff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth2hf->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth2hf->SetMarkerStyle(20);
      diffADCAmpl_Depth2hf->SetMarkerSize(0.4);
      diffADCAmpl_Depth2hf->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth2hf->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth2hf->SetMarkerColor(2);
      diffADCAmpl_Depth2hf->SetLineColor(2);
      diffADCAmpl_Depth2hf->Draw("");
             
      c1->Update();
      
      delete twoddepth2hf0;     
      delete twoddepth2hf1;     
      delete adepth2hf;
      delete Cdepth2hffz225;
      delete Cdepth2hfff;
      delete diffADCAmpl_Depth2hf;
      delete Diffe_Depth2hf;
      
            
    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twoddepth4ho1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
      TH2F *twoddepth4ho0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twoddepth4ho1->Sumw2();
      twoddepth4ho0->Sumw2();
      //    if(twoddepth4ho0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth4hoff = (TH2F*)twoddepth4ho1->Clone("Cdepth4hoff");
	Cdepth4hoff->Divide(twoddepth4ho1,twoddepth4ho0, 1, 1, "B");
	Cdepth4hoff->Sumw2();
	//    }
      c1->cd(1);
      TH2F *twoedepth4ho1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl225_HO");
      TH2F *twoedepth4ho0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twoedepth4ho1->Sumw2();
      twoedepth4ho0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdepth4hofz225= (TH2F*)twoedepth4ho1->Clone("Cdepth4hofz225");
	Cdepth4hofz225->Divide(twoedepth4ho1,twoedepth4ho0, 1, 1, "B");
	Cdepth4hofz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth4hofz225->SetMarkerStyle(20);
      Cdepth4hofz225->SetMarkerSize(0.4);
      //    Cdepth4hofz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth4hofz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth4hofz225->SetXTitle("#eta \b");
      Cdepth4hofz225->SetYTitle("#phi \b");
      Cdepth4hofz225->SetZTitle("Rate for ADCAmpl in each event & cell - HO Depth4 \b");
      Cdepth4hofz225->SetMarkerColor(2);
      Cdepth4hofz225->SetLineColor(2);
      Cdepth4hofz225->SetMaximum(1.000);
      Cdepth4hofz225->SetMinimum(0.00001);
//      Cdepth4hofz225->SetMinimum(0.0001);
      Cdepth4hofz225->Draw("COLZ");
      
      c1->cd(2);
      
          TH1F *adepth4ho= (TH1F*)hfile1->Get("h_ADCAmpl_HO");
 //     TH1F *adepth4ho= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HO");
//      TH1F *adepth4ho= (TH1F*)hfile1->Get("h_ADCAmplZoom_HO");
      gPad->SetLogy();
//      gPad->SetLogx();
      adepth4ho->SetMarkerStyle(20);
      adepth4ho->SetMarkerSize(0.8);
      adepth4ho->GetYaxis()->SetLabelSize(0.04);
      adepth4ho->SetXTitle("ADCAmpl in each event & cell HO \b");
      adepth4ho->SetMarkerColor(2);
      adepth4ho->SetLineColor(2);
      adepth4ho->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth4ho = (TH2F*)Cdepth4hoff->Clone("Diffe_Depth4ho");
    for (int i=1;i<=Cdepth4hoff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdepth4hoff->GetYaxis()->GetNbins();j++) {
	TH2F* Cdepth4hoff = (TH2F*)twoddepth4ho1->Clone("Cdepth4hoff");
	double ccc1 =  Cdepth4hoff->GetBinContent(i,j)   ;
	Diffe_Depth4ho->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth4ho->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth4ho->SetMarkerStyle(20);
      Diffe_Depth4ho->SetMarkerSize(0.4);
      Diffe_Depth4ho->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth4ho->SetTitle("any Error, HO Depth4ho \n");
      Diffe_Depth4ho->SetXTitle("#eta \b");
      Diffe_Depth4ho->SetYTitle("#phi \b");
      Diffe_Depth4ho->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HO Depth4ho \b");
      Diffe_Depth4ho->SetMarkerColor(2);
      Diffe_Depth4ho->SetLineColor(2);
      //      Diffe_Depth4ho->SetMaximum(1.000);
      //      Diffe_Depth4ho->SetMinimum(0.0000001);
      Diffe_Depth4ho->Draw("COLZ");
            

      c1->cd(4);
      TH1F* diffADCAmpl_Depth4ho = new TH1F("diffADCAmpl_Depth4ho","", 100, 0.,3000.);
      TH2F* Cdepth4hofw = (TH2F*)twoddepth4ho1->Clone("diffADCAmpl_Depth4ho");
      for (int i=1;i<=Cdepth4hofw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdepth4hofw->GetYaxis()->GetNbins();j++) {
	  if(Cdepth4hoff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdepth4hoff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth4ho->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth4ho->SetMarkerStyle(20);
      diffADCAmpl_Depth4ho->SetMarkerSize(0.4);
      diffADCAmpl_Depth4ho->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth4ho->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth4ho->SetMarkerColor(2);
      diffADCAmpl_Depth4ho->SetLineColor(2);
      diffADCAmpl_Depth4ho->Draw("");
             
      c1->Update();
      
      delete twoddepth4ho0;     
      delete twoddepth4ho1;     
      delete adepth4ho;
      delete Cdepth4hofz225;
      delete Cdepth4hoff;
      delete diffADCAmpl_Depth4ho;
      delete Diffe_Depth4ho;
      
            
    //========================================================================================== 9    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      TH1F *aaaaaa0= (TH1F*)hfile1->Get("h_ADCAmplZoom_HB");
      gPad->SetLogy();
      // gPad->SetLogx();
      aaaaaa0->SetMarkerStyle(20);
      aaaaaa0->SetMarkerSize(0.8);
      aaaaaa0->GetYaxis()->SetLabelSize(0.04);
      aaaaaa0->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa0->SetMarkerColor(2);
      aaaaaa0->SetLineColor(2);
      aaaaaa0->Draw("");
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom_HB");
      gPad->SetLogy();
      // gPad->SetLogx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(4);
      //      aaaaaa2->Draw("Same");
      
      c1->cd(2);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HB");
            gPad->SetLogy();
      //    gPad->SetLogx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa3->SetMarkerColor(2);
      aaaaaa3->SetLineColor(2);
      aaaaaa3->Draw("");
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom1_HB");
            gPad->SetLogy();
      //    gPad->SetLogx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(4);
      //      aaaaaa1->Draw("Same");
      
      c1->cd(3);
      TH1F *aaaaaa5= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
            gPad->SetLogy();
      //    gPad->SetLogx();
      aaaaaa5->SetMarkerStyle(20);
      aaaaaa5->SetMarkerSize(0.8);
      aaaaaa5->GetYaxis()->SetLabelSize(0.04);
      aaaaaa5->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa5->SetMarkerColor(2);
      aaaaaa5->SetLineColor(2);
      aaaaaa5->Draw("");
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_ADCAmpl345_HB");
            gPad->SetLogy();
      //    gPad->SetLogx();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(4);
      //      aaaaaa1->Draw("Same");
      
      c1->Update();
      
      
    //========================================================================================== 10   
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *kqlerd0= (TH1F*)hfile1->Get("h_ADCAmpl_HO_copy");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd0->SetMarkerStyle(20);
      kqlerd0->SetMarkerSize(0.8);
      kqlerd0->GetYaxis()->SetLabelSize(0.04);
      kqlerd0->SetXTitle("h_ADCAmpl_HO_copy \b");
      kqlerd0->SetMarkerColor(2);
      kqlerd0->SetLineColor(2);
      kqlerd0->Draw("");
      
      c1->cd(2);
      TH1F *kqlerd1= (TH1F*)hfile1->Get("h_ADCAmpl_HF");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd1->SetMarkerStyle(20);
      kqlerd1->SetMarkerSize(0.8);
      kqlerd1->GetYaxis()->SetLabelSize(0.04);
      kqlerd1->SetXTitle("h_ADCAmpl_HF \b");
      kqlerd1->SetMarkerColor(2);
      kqlerd1->SetLineColor(2);
      kqlerd1->Draw("");
      
      c1->cd(3);
      TH1F *kqlerd2= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd2->SetMarkerStyle(20);
      kqlerd2->SetMarkerSize(0.8);
      kqlerd2->GetYaxis()->SetLabelSize(0.04);
      kqlerd2->SetXTitle("h_ADCAmpl345Zoom_HE \b");
      kqlerd2->SetMarkerColor(2);
      kqlerd2->SetLineColor(2);
      kqlerd2->Draw("");
      
      c1->cd(4);
      TH1F *kqlerd3= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd3->SetMarkerStyle(20);
      kqlerd3->SetMarkerSize(0.8);
      kqlerd3->GetYaxis()->SetLabelSize(0.04);
      kqlerd3->SetXTitle("h_ADCAmpl_HB \b");
      kqlerd3->SetMarkerColor(2);
      kqlerd3->SetLineColor(2);
      kqlerd3->Draw("");
      
      c1->Update();
      
    //======================================================================
    //==================================================================================================== end
    //======================================================================
    //======================================================================
    // close and delete all possible things:

        //   psfile->Close();
        psfile.Close();

    hfile1->Close();
//    hfile1->Delete();
    hfile1->Close();
//    hfile1->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}




      