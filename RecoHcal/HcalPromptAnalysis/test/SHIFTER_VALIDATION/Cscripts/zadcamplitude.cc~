//#include "LogEleMapdb.h"

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
				gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// name mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(101110);                                          // entries, mean, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

	TFile *hfile1= new TFile("../PYTHON_runlist_test/Global_283884_1.root", "READ");
//        TFile *hfile1= new TFile("Global_test.root", "READ");

	//    getchar();
	//
          TPostScript psfile ("zadcamplitude.ps", 111);


//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
             
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      c1->cd(1);
      TH2F *twoe1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HB");
      TH2F *twoe0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twoe1->Sumw2();
      twoe0->Sumw2();
      //    if(twoe0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twoe1->Clone("Cefz225");
	Cefz225->Divide(twoe1,twoe0, 1, 1, "B");
	Cefz225->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate for ADCAmpl in each event & cell - HB Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
//      Cefz225->SetMinimum(0.0001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      
 //         TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HB");
//      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom_HB");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
            
      c1->cd(3);
      
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HB = (TH2F*)Ceff->Clone("Diffe_Depth1_HB");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	double ccc1 =  Ceff->GetBinContent(i,j)   ;
	Diffe_Depth1_HB->SetBinContent(i,j,0.);
	if(ccc1 <18|| ccc1>30.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB->SetMarkerStyle(20);
      Diffe_Depth1_HB->SetMarkerSize(0.4);
      Diffe_Depth1_HB->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1_HB->SetTitle("any Error, HB Depth1 \n");
      Diffe_Depth1_HB->SetXTitle("#eta \b");
      Diffe_Depth1_HB->SetYTitle("#phi \b");
      Diffe_Depth1_HB->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HB Depth1 \b");
      Diffe_Depth1_HB->SetMarkerColor(2);
      Diffe_Depth1_HB->SetLineColor(2);
      //      Diffe_Depth1_HB->SetMaximum(1.000);
      //      Diffe_Depth1_HB->SetMinimum(0.0000001);
      Diffe_Depth1_HB->Draw("COLZ");
            

      c1->cd(4);
      //    TH1F* diffADCAmpl_Depth1_HB = new TH1F("diffADCAmpl_Depth1_HB","", 100, 0.,3000.);
      TH1F* diffADCAmpl_Depth1_HB = new TH1F("diffADCAmpl_Depth1_HB","", 100, 0.,100.);
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
       nx = Ceff->GetXaxis()->GetNbins();
       ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1_HB->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1_HB->SetMarkerStyle(20);
      diffADCAmpl_Depth1_HB->SetMarkerSize(0.4);
      diffADCAmpl_Depth1_HB->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1_HB->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1_HB->SetMarkerColor(2);
      diffADCAmpl_Depth1_HB->SetLineColor(2);
      diffADCAmpl_Depth1_HB->Draw("");
             
      c1->Update();
      
      
            
    //========================================================================================== 10   
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
      //      aaaaaa1->Draw("Same");
      
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
      
      
    //============================================================================================ 17
    //======================================================================
    //======================================================================
    //================ diffADCAmpl_Depth1_HF
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *ters1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
      TH2F *ters0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      ters1->Sumw2();
      ters0->Sumw2();
      if(ters0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)ters1->Clone("Ceff");
	Ceff->Divide(ters1,ters0, 1, 1, "B");
	Ceff->Sumw2();
      }

    ///////////////////////////////////////
      c1->cd(1);
      TH1F* diffADCAmpl_Depth1_HF0 = new TH1F("diffADCAmpl_Depth1_HF0","", 100, -20.,200.);
      nx = Ceff->GetXaxis()->GetNbins();
      ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1_HF0->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1_HF0->SetMarkerStyle(20);
      diffADCAmpl_Depth1_HF0->SetMarkerSize(0.4);
      diffADCAmpl_Depth1_HF0->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1_HF0->SetXTitle("<ADCAmpl> in each channel - HF Depth1 \b");
      diffADCAmpl_Depth1_HF0->SetMarkerColor(2);
      diffADCAmpl_Depth1_HF0->SetLineColor(2);
      diffADCAmpl_Depth1_HF0->Draw("");

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth1_HF = (TH2F*)Ceff->Clone("Diffe_Depth1_HF");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF->SetBinContent(i,j,0.);
	  if(ccc1 > 0.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF->SetMarkerStyle(20);
      Diffe_Depth1_HF->SetMarkerSize(0.4);
      Diffe_Depth1_HF->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF->SetXTitle("#eta \b");
      Diffe_Depth1_HF->SetYTitle("#phi \b");
      Diffe_Depth1_HF->SetZTitle("<ADCAmpl> bigger 0.- HF Depth1 \b");
      Diffe_Depth1_HF->SetMarkerColor(2);
      Diffe_Depth1_HF->SetLineColor(2);
      Diffe_Depth1_HF->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(3);
    TH2F* Diffe_Depth1_HF0 = (TH2F*)Ceff->Clone("Diffe_Depth1_HF0");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF0->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  Diffe_Depth1_HF0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF0->SetMarkerStyle(20);
      Diffe_Depth1_HF0->SetMarkerSize(0.4);
      Diffe_Depth1_HF0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF0->SetXTitle("#eta \b");
      Diffe_Depth1_HF0->SetYTitle("#phi \b");
      Diffe_Depth1_HF0->SetZTitle("<ADCAmpl> bigger 20.- HF Depth1 \b");
      Diffe_Depth1_HF0->SetMarkerColor(2);
      Diffe_Depth1_HF0->SetLineColor(2);
      Diffe_Depth1_HF0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(4);
    TH2F* Diffe_Depth1_HF9 = (TH2F*)Ceff->Clone("Diffe_Depth1_HF9");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF9->SetBinContent(i,j,0.);
	  if(ccc1 > 30.)  Diffe_Depth1_HF9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF9->SetMarkerStyle(20);
      Diffe_Depth1_HF9->SetMarkerSize(0.4);
      Diffe_Depth1_HF9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF9->SetXTitle("#eta \b");
      Diffe_Depth1_HF9->SetYTitle("#phi \b");
      Diffe_Depth1_HF9->SetZTitle("<ADCAmpl> bigger 30.- HF Depth1 \b");
      Diffe_Depth1_HF9->SetMarkerColor(2);
      Diffe_Depth1_HF9->SetLineColor(2);
      Diffe_Depth1_HF9->Draw("COLZ");
      
      c1->Update();
      
 

    //============================================================================================ 18
    //======================================================================
    //======================================================================
    //================ diffADCAmpl_Depth1_HF
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *iwjr1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HF");
      TH2F *iwjr0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      iwjr1->Sumw2();
      iwjr0->Sumw2();
      if(iwjr0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)iwjr1->Clone("Ceff");
	Ceff->Divide(iwjr1,iwjr0, 1, 1, "B");
	Ceff->Sumw2();
      }

    ///////////////////////////////////////
      c1->cd(1);
      TH1F* diffADCAmpl_Depth2_HF0 = new TH1F("diffADCAmpl_Depth2_HF0","", 100, -20.,200.);
      nx = Ceff->GetXaxis()->GetNbins();
      ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth2_HF0->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth2_HF0->SetMarkerStyle(20);
      diffADCAmpl_Depth2_HF0->SetMarkerSize(0.4);
      diffADCAmpl_Depth2_HF0->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth2_HF0->SetXTitle("<ADCAmpl> in each channel - HF Depth2 \b");
      diffADCAmpl_Depth2_HF0->SetMarkerColor(2);
      diffADCAmpl_Depth2_HF0->SetLineColor(2);
      diffADCAmpl_Depth2_HF0->Draw("");

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth2_HF = (TH2F*)Ceff->Clone("Diffe_Depth2_HF");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth2_HF->SetBinContent(i,j,0.);
	  if(ccc1 > 0.)  Diffe_Depth2_HF->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2_HF->SetMarkerStyle(20);
      Diffe_Depth2_HF->SetMarkerSize(0.4);
      Diffe_Depth2_HF->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth2_HF->SetXTitle("#eta \b");
      Diffe_Depth2_HF->SetYTitle("#phi \b");
      Diffe_Depth2_HF->SetZTitle("<ADCAmpl> bigger 0.- HF Depth2 \b");
      Diffe_Depth2_HF->SetMarkerColor(2);
      Diffe_Depth2_HF->SetLineColor(2);
      Diffe_Depth2_HF->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(3);
    TH2F* Diffe_Depth2_HF0 = (TH2F*)Ceff->Clone("Diffe_Depth2_HF0");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth2_HF0->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  Diffe_Depth2_HF0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2_HF0->SetMarkerStyle(20);
      Diffe_Depth2_HF0->SetMarkerSize(0.4);
      Diffe_Depth2_HF0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth2_HF0->SetXTitle("#eta \b");
      Diffe_Depth2_HF0->SetYTitle("#phi \b");
      Diffe_Depth2_HF0->SetZTitle("<ADCAmpl> bigger 20.- HF Depth2 \b");
      Diffe_Depth2_HF0->SetMarkerColor(2);
      Diffe_Depth2_HF0->SetLineColor(2);
      Diffe_Depth2_HF0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(4);
    TH2F* Diffe_Depth2_HF9 = (TH2F*)Ceff->Clone("Diffe_Depth2_HF9");
    nx = Ceff->GetXaxis()->GetNbins();
    ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth2_HF9->SetBinContent(i,j,0.);
	  if(ccc1 > 25.)  Diffe_Depth2_HF9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth2_HF9->SetMarkerStyle(20);
      Diffe_Depth2_HF9->SetMarkerSize(0.4);
      Diffe_Depth2_HF9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth2_HF9->SetXTitle("#eta \b");
      Diffe_Depth2_HF9->SetYTitle("#phi \b");
      Diffe_Depth2_HF9->SetZTitle("<ADCAmpl> bigger 25.- HF Depth2 \b");
      Diffe_Depth2_HF9->SetMarkerColor(2);
      Diffe_Depth2_HF9->SetLineColor(2);
      Diffe_Depth2_HF9->Draw("COLZ");
      


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




      
