#include <iostream>
#include <fstream>
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
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"

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
		   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

//	TFile *hfile1= new TFile("../PYTHON_runlist_test/Global_283884_1.root", "READ");
//        TFile *hfile1= new TFile("Global_test.root", "READ");

//	TFile *hfile1= new TFile("LED_280702.root", "READ");        
	//	TFile *hfile2= new TFile("LED_287824.root", "READ");

	//	TFile *hfile1= new TFile("LED_284352.root", "READ");        
//	TFile *hfile1= new TFile("LEDtest.root", "READ");
//	TFile *hfile1= new TFile("Global_311668.root", "READ");


//	TFile *hfile1= new TFile("Global_321177_olddefault.root", "READ");
//	TFile *hfile1= new TFile("Global_321177.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_9_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap.root", "READ");
	TFile *hfile1= new TFile("Global_325001_ls1to600_abortgap.root", "READ");


	//	TFile *hfile2= new TFile("LED_284902.root", "READ");
	//	TFile *hfile2= new TFile("LED_284499.root", "READ");
	//	TFile *hfile2= new TFile("LED_284352.root", "READ");

	//	TFile *hfile2= new TFile("LED_286590.root", "READ");



	//    getchar();
	//
          TPostScript psfile ("zadcamplCMT.ps", 111);


//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *lftr1= (TH1F*)hfile1->Get("h_AiForLS_11_HB");
      gPad->SetLogy();//gPad->SetGridy();      gPad->SetGridx();     
      lftr1->SetXTitle("Ai for LS=11_HB \b");
      lftr1->Draw("");

      c1->cd(2);
      TH1F *lftr2= (TH1F*)hfile1->Get("h_AiForLS_12_HB");
      gPad->SetLogy();//     
      lftr2->SetXTitle("Ai for LS=12_HB \b");
      lftr2->Draw("");

      c1->cd(3);
      TH1F *lftr3= (TH1F*)hfile1->Get("h_AiForLS_13_HB");
      gPad->SetLogy();//     
      lftr3->SetXTitle("Ai for LS=13_HB \b");
      lftr3->Draw("");

      c1->cd(4);
      TH1F *lftr4= (TH1F*)hfile1->Get("h_AiForLS_75_HB");
      gPad->SetLogy();//     
      lftr4->SetXTitle("Ai for LS=75_HB \b");
      lftr4->Draw("");
 
       c1->Update();
    //========================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *lftr44 = (TH1F*)hfile1->Get("h_AiForLS_66_HB");
      gPad->SetLogy();//     
      lftr44->SetXTitle("Ai for LS=66_HB \b");
      lftr44->Draw("");
 
      c1->cd(2);
      TH1F *lftr5= (TH1F*)hfile1->Get("h_AiForLS_215_HB");
      gPad->SetLogy();//     
      lftr5->SetXTitle("Ai for LS=215_HB \b");
      lftr5->Draw("");
 
      c1->cd(3);
      TH1F *lftr6= (TH1F*)hfile1->Get("h_AiForLS_233_HB");
      gPad->SetLogy();//     
      lftr6->SetXTitle("Ai for LS=233_HB \b");
      lftr6->Draw("");
 
      c1->cd(4);
      TH1F *lftr7= (TH1F*)hfile1->Get("h_AiForLS_456_HB");
      gPad->SetLogy();//     
      lftr7->SetXTitle("Ai for LS=456_HB \b");
      lftr7->Draw("");
 
       c1->Update();
    //========================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *lftr12= (TH1F*)hfile1->Get("h_AiForLS_100_HB");
      gPad->SetLogy();//     
      lftr12->SetXTitle("Ai for LS=100_HB \b");
      lftr12->Draw("");

      c1->cd(2);
      TH1F *lftr9= (TH1F*)hfile1->Get("h_AiForLS_444_HB");
      gPad->SetLogy();//     
      lftr9->SetXTitle("Ai for LS=444_HB \b");
      lftr9->Draw("");

      c1->cd(3);
      TH1F *lftr8= (TH1F*)hfile1->Get("h_AiForLS_bad_HB");
      gPad->SetLogy();//     
      lftr8->SetXTitle("Ai for LS=bad_HB \b");
      lftr8->Draw("");
 
      c1->cd(4);
      TH1F *lftr10= (TH1F*)hfile1->Get("h_AiForLS_good_HB");
      gPad->SetLogy();//     
      lftr10->SetXTitle("Ai for LS=good_HB \b");
      lftr10->Draw("");
 
       c1->Update();
 
    //========================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *lftr21= (TH2F*)hfile1->Get("h_mapAiForLS_bad_HB");
      TH2F *lftr22= (TH2F*)hfile1->Get("h_map0AiForLS_bad_HB");
      lftr21->Sumw2();
      lftr22->Sumw2();
	TH2F* lftr23= (TH2F*)lftr21->Clone("lftr23");
	lftr23->Divide(lftr21,lftr22, 1, 1, "B");
	lftr23->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      lftr23->SetMarkerStyle(20);
      lftr23->SetMarkerSize(0.4);
      lftr23->GetZaxis()->SetLabelSize(0.08);
      lftr23->SetXTitle("#eta \b");
      lftr23->SetYTitle("#phi \b");
      lftr23->SetZTitle("<A> for bad LSs - HB \b");
      lftr23->SetMarkerColor(2);
      lftr23->SetLineColor(2);
      //      lftr23->SetMaximum(1.000);
      //      lftr23->SetMinimum(0.0001);
      lftr23->Draw("COLZ");
       
      c1->cd(2);
      TH2F *lftr24= (TH2F*)hfile1->Get("h_mapAiForLS_good_HB");
      TH2F *lftr25= (TH2F*)hfile1->Get("h_map0AiForLS_good_HB");
      lftr24->Sumw2();
      lftr25->Sumw2();
	TH2F* lftr26= (TH2F*)lftr24->Clone("lftr26");
	lftr26->Divide(lftr24,lftr25, 1, 1, "B");
	lftr26->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      lftr26->SetMarkerStyle(20);
      lftr26->SetMarkerSize(0.4);
      lftr26->GetZaxis()->SetLabelSize(0.08);
      lftr26->SetXTitle("#eta \b");
      lftr26->SetYTitle("#phi \b");
      lftr26->SetZTitle("<A> for good LSs - HB \b");
      lftr26->SetMarkerColor(2);
      lftr26->SetLineColor(2);
      //      lftr26->SetMaximum(1.000);
      //      lftr26->SetMinimum(0.0001);
      lftr26->Draw("COLZ");
       
       
       c1->Update();
     
    //========================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *besz1= (TH1F*)hfile1->Get("h_AiForLS_11_HE");
      gPad->SetLogy();//gPad->SetGridy();      gPad->SetGridx();     
      besz1->SetXTitle("Ai for LS=11_HE \b");
      besz1->Draw("");

      c1->cd(2);
      TH1F *besz2= (TH1F*)hfile1->Get("h_AiForLS_12_HE");
      gPad->SetLogy();//     
      besz2->SetXTitle("Ai for LS=12_HE \b");
      besz2->Draw("");

      c1->cd(3);
      TH1F *besz3= (TH1F*)hfile1->Get("h_AiForLS_13_HE");
      gPad->SetLogy();//     
      besz3->SetXTitle("Ai for LS=13_HE \b");
      besz3->Draw("");

      c1->cd(4);
      TH1F *besz4= (TH1F*)hfile1->Get("h_AiForLS_75_HE");
      gPad->SetLogy();//     
      besz4->SetXTitle("Ai for LS=75_HE \b");
      besz4->Draw("");
 
       c1->Update();
    //========================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *besz44 = (TH1F*)hfile1->Get("h_AiForLS_66_HE");
      gPad->SetLogy();//     
      besz44->SetXTitle("Ai for LS=66_HE \b");
      besz44->Draw("");
 
      c1->cd(2);
      TH1F *besz5= (TH1F*)hfile1->Get("h_AiForLS_215_HE");
      gPad->SetLogy();//     
      besz5->SetXTitle("Ai for LS=215_HE \b");
      besz5->Draw("");
 
      c1->cd(3);
      TH1F *besz6= (TH1F*)hfile1->Get("h_AiForLS_233_HE");
      gPad->SetLogy();//     
      besz6->SetXTitle("Ai for LS=233_HE \b");
      besz6->Draw("");
 
      c1->cd(4);
      TH1F *besz7= (TH1F*)hfile1->Get("h_AiForLS_456_HE");
      gPad->SetLogy();//     
      besz7->SetXTitle("Ai for LS=456_HE \b");
      besz7->Draw("");
 
       c1->Update();
    //========================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *besz12= (TH1F*)hfile1->Get("h_AiForLS_100_HE");
      gPad->SetLogy();//     
      besz12->SetXTitle("Ai for LS=100_HE \b");
      besz12->Draw("");

      c1->cd(2);
      TH1F *besz9= (TH1F*)hfile1->Get("h_AiForLS_444_HE");
      gPad->SetLogy();//     
      besz9->SetXTitle("Ai for LS=444_HE \b");
      besz9->Draw("");

      c1->cd(3);
      TH1F *besz8= (TH1F*)hfile1->Get("h_AiForLS_bad_HE");
      gPad->SetLogy();//     
      besz8->SetXTitle("Ai for LS=bad_HE \b");
      besz8->Draw("");
 
      c1->cd(4);
      TH1F *besz10= (TH1F*)hfile1->Get("h_AiForLS_good_HE");
      gPad->SetLogy();//     
      besz10->SetXTitle("Ai for LS=good_HE \b");
      besz10->Draw("");
 
       c1->Update();
 
    //========================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *besz21= (TH2F*)hfile1->Get("h_mapAiForLS_bad_HE");
      TH2F *besz22= (TH2F*)hfile1->Get("h_map0AiForLS_bad_HE");
      besz21->Sumw2();
      besz22->Sumw2();
	TH2F* besz23= (TH2F*)besz21->Clone("besz23");
	besz23->Divide(besz21,besz22, 1, 1, "B");
	besz23->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      besz23->SetMarkerStyle(20);
      besz23->SetMarkerSize(0.4);
      besz23->GetZaxis()->SetLabelSize(0.08);
      besz23->SetXTitle("#eta \b");
      besz23->SetYTitle("#phi \b");
      besz23->SetZTitle("<A> for bad LSs - HE \b");
      besz23->SetMarkerColor(2);
      besz23->SetLineColor(2);
      //      besz23->SetMaximum(1.000);
      //      besz23->SetMinimum(0.0001);
      besz23->Draw("COLZ");
       
      c1->cd(2);
      TH2F *besz24= (TH2F*)hfile1->Get("h_mapAiForLS_good_HE");
      TH2F *besz25= (TH2F*)hfile1->Get("h_map0AiForLS_good_HE");
      besz24->Sumw2();
      besz25->Sumw2();
	TH2F* besz26= (TH2F*)besz24->Clone("besz26");
	besz26->Divide(besz24,besz25, 1, 1, "B");
	besz26->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      besz26->SetMarkerStyle(20);
      besz26->SetMarkerSize(0.4);
      besz26->GetZaxis()->SetLabelSize(0.08);
      besz26->SetXTitle("#eta \b");
      besz26->SetYTitle("#phi \b");
      besz26->SetZTitle("<A> for good LSs - HE \b");
      besz26->SetMarkerColor(2);
      besz26->SetLineColor(2);
      //      besz26->SetMaximum(1.000);
      //      besz26->SetMinimum(0.0001);
      besz26->Draw("COLZ");
       
       
       c1->Update();
     
    //========================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *kgtr1= (TH1F*)hfile1->Get("h_AiForLS_11_HO");
      gPad->SetLogy();//gPad->SetGridy();      gPad->SetGridx();     
      kgtr1->SetXTitle("Ai for LS=11_HO \b");
      kgtr1->Draw("");

      c1->cd(2);
      TH1F *kgtr2= (TH1F*)hfile1->Get("h_AiForLS_12_HO");
      gPad->SetLogy();//     
      kgtr2->SetXTitle("Ai for LS=12_HO \b");
      kgtr2->Draw("");

      c1->cd(3);
      TH1F *kgtr3= (TH1F*)hfile1->Get("h_AiForLS_13_HO");
      gPad->SetLogy();//     
      kgtr3->SetXTitle("Ai for LS=13_HO \b");
      kgtr3->Draw("");

      c1->cd(4);
      TH1F *kgtr4= (TH1F*)hfile1->Get("h_AiForLS_75_HO");
      gPad->SetLogy();//     
      kgtr4->SetXTitle("Ai for LS=75_HO \b");
      kgtr4->Draw("");
 
       c1->Update();
    //========================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *kgtr44 = (TH1F*)hfile1->Get("h_AiForLS_66_HO");
      gPad->SetLogy();//     
      kgtr44->SetXTitle("Ai for LS=66_HO \b");
      kgtr44->Draw("");
 
      c1->cd(2);
      TH1F *kgtr5= (TH1F*)hfile1->Get("h_AiForLS_215_HO");
      gPad->SetLogy();//     
      kgtr5->SetXTitle("Ai for LS=215_HO \b");
      kgtr5->Draw("");
 
      c1->cd(3);
      TH1F *kgtr6= (TH1F*)hfile1->Get("h_AiForLS_233_HO");
      gPad->SetLogy();//     
      kgtr6->SetXTitle("Ai for LS=233_HO \b");
      kgtr6->Draw("");
 
      c1->cd(4);
      TH1F *kgtr7= (TH1F*)hfile1->Get("h_AiForLS_456_HO");
      gPad->SetLogy();//     
      kgtr7->SetXTitle("Ai for LS=456_HO \b");
      kgtr7->Draw("");
 
       c1->Update();
    //========================================================================================== 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *kgtr12= (TH1F*)hfile1->Get("h_AiForLS_100_HO");
      gPad->SetLogy();//     
      kgtr12->SetXTitle("Ai for LS=100_HO \b");
      kgtr12->Draw("");

      c1->cd(2);
      TH1F *kgtr9= (TH1F*)hfile1->Get("h_AiForLS_444_HO");
      gPad->SetLogy();//     
      kgtr9->SetXTitle("Ai for LS=444_HO \b");
      kgtr9->Draw("");

      c1->cd(3);
      TH1F *kgtr8= (TH1F*)hfile1->Get("h_AiForLS_bad_HO");
      gPad->SetLogy();//     
      kgtr8->SetXTitle("Ai for LS=bad_HO \b");
      kgtr8->Draw("");
 
      c1->cd(4);
      TH1F *kgtr10= (TH1F*)hfile1->Get("h_AiForLS_good_HO");
      gPad->SetLogy();//     
      kgtr10->SetXTitle("Ai for LS=good_HO \b");
      kgtr10->Draw("");
 
       c1->Update();
 
    //========================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *kgtr21= (TH2F*)hfile1->Get("h_mapAiForLS_bad_HO");
      TH2F *kgtr22= (TH2F*)hfile1->Get("h_map0AiForLS_bad_HO");
      kgtr21->Sumw2();
      kgtr22->Sumw2();
	TH2F* kgtr23= (TH2F*)kgtr21->Clone("kgtr23");
	kgtr23->Divide(kgtr21,kgtr22, 1, 1, "B");
	kgtr23->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      kgtr23->SetMarkerStyle(20);
      kgtr23->SetMarkerSize(0.4);
      kgtr23->GetZaxis()->SetLabelSize(0.08);
      kgtr23->SetXTitle("#eta \b");
      kgtr23->SetYTitle("#phi \b");
      kgtr23->SetZTitle("<A> for bad LSs - HO \b");
      kgtr23->SetMarkerColor(2);
      kgtr23->SetLineColor(2);
      //      kgtr23->SetMaximum(1.000);
      //      kgtr23->SetMinimum(0.0001);
      kgtr23->Draw("COLZ");
       
      c1->cd(2);
      TH2F *kgtr24= (TH2F*)hfile1->Get("h_mapAiForLS_good_HO");
      TH2F *kgtr25= (TH2F*)hfile1->Get("h_map0AiForLS_good_HO");
      kgtr24->Sumw2();
      kgtr25->Sumw2();
	TH2F* kgtr26= (TH2F*)kgtr24->Clone("kgtr26");
	kgtr26->Divide(kgtr24,kgtr25, 1, 1, "B");
	kgtr26->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      kgtr26->SetMarkerStyle(20);
      kgtr26->SetMarkerSize(0.4);
      kgtr26->GetZaxis()->SetLabelSize(0.08);
      kgtr26->SetXTitle("#eta \b");
      kgtr26->SetYTitle("#phi \b");
      kgtr26->SetZTitle("<A> for good LSs - HO \b");
      kgtr26->SetMarkerColor(2);
      kgtr26->SetLineColor(2);
      //      kgtr26->SetMaximum(1.000);
      //      kgtr26->SetMinimum(0.0001);
      kgtr26->Draw("COLZ");
       
       
       c1->Update();
     
    //========================================================================================== 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *htqn1= (TH1F*)hfile1->Get("h_AiForLS_11_HF");
      gPad->SetLogy();//gPad->SetGridy();      gPad->SetGridx();     
      htqn1->SetXTitle("Ai for LS=11_HF \b");
      htqn1->Draw("");

      c1->cd(2);
      TH1F *htqn2= (TH1F*)hfile1->Get("h_AiForLS_12_HF");
      gPad->SetLogy();//     
      htqn2->SetXTitle("Ai for LS=12_HF \b");
      htqn2->Draw("");

      c1->cd(3);
      TH1F *htqn3= (TH1F*)hfile1->Get("h_AiForLS_13_HF");
      gPad->SetLogy();//     
      htqn3->SetXTitle("Ai for LS=13_HF \b");
      htqn3->Draw("");

      c1->cd(4);
      TH1F *htqn4= (TH1F*)hfile1->Get("h_AiForLS_75_HF");
      gPad->SetLogy();//     
      htqn4->SetXTitle("Ai for LS=75_HF \b");
      htqn4->Draw("");
 
       c1->Update();
    //========================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *htqn44 = (TH1F*)hfile1->Get("h_AiForLS_66_HF");
      gPad->SetLogy();//     
      htqn44->SetXTitle("Ai for LS=66_HF \b");
      htqn44->Draw("");
 
      c1->cd(2);
      TH1F *htqn5= (TH1F*)hfile1->Get("h_AiForLS_215_HF");
      gPad->SetLogy();//     
      htqn5->SetXTitle("Ai for LS=215_HF \b");
      htqn5->Draw("");
 
      c1->cd(3);
      TH1F *htqn6= (TH1F*)hfile1->Get("h_AiForLS_233_HF");
      gPad->SetLogy();//     
      htqn6->SetXTitle("Ai for LS=233_HF \b");
      htqn6->Draw("");
 
      c1->cd(4);
      TH1F *htqn7= (TH1F*)hfile1->Get("h_AiForLS_456_HF");
      gPad->SetLogy();//     
      htqn7->SetXTitle("Ai for LS=456_HF \b");
      htqn7->Draw("");
 
       c1->Update();
    //========================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *htqn12= (TH1F*)hfile1->Get("h_AiForLS_100_HF");
      gPad->SetLogy();//     
      htqn12->SetXTitle("Ai for LS=100_HF \b");
      htqn12->Draw("");

      c1->cd(2);
      TH1F *htqn9= (TH1F*)hfile1->Get("h_AiForLS_444_HF");
      gPad->SetLogy();//     
      htqn9->SetXTitle("Ai for LS=444_HF \b");
      htqn9->Draw("");

      c1->cd(3);
      TH1F *htqn8= (TH1F*)hfile1->Get("h_AiForLS_bad_HF");
      gPad->SetLogy();//     
      htqn8->SetXTitle("Ai for LS=bad_HF \b");
      htqn8->Draw("");
 
      c1->cd(4);
      TH1F *htqn10= (TH1F*)hfile1->Get("h_AiForLS_good_HF");
      gPad->SetLogy();//     
      htqn10->SetXTitle("Ai for LS=good_HF \b");
      htqn10->Draw("");
 
       c1->Update();
 
    //========================================================================================== 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *htqn21= (TH2F*)hfile1->Get("h_mapAiForLS_bad_HF");
      TH2F *htqn22= (TH2F*)hfile1->Get("h_map0AiForLS_bad_HF");
      htqn21->Sumw2();
      htqn22->Sumw2();
	TH2F* htqn23= (TH2F*)htqn21->Clone("htqn23");
	htqn23->Divide(htqn21,htqn22, 1, 1, "B");
	htqn23->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      htqn23->SetMarkerStyle(20);
      htqn23->SetMarkerSize(0.4);
      htqn23->GetZaxis()->SetLabelSize(0.08);
      htqn23->SetXTitle("#eta \b");
      htqn23->SetYTitle("#phi \b");
      htqn23->SetZTitle("<A> for bad LSs - HF \b");
      htqn23->SetMarkerColor(2);
      htqn23->SetLineColor(2);
      //      htqn23->SetMaximum(1.000);
      //      htqn23->SetMinimum(0.0001);
      htqn23->Draw("COLZ");
       
      c1->cd(2);
      TH2F *htqn24= (TH2F*)hfile1->Get("h_mapAiForLS_good_HF");
      TH2F *htqn25= (TH2F*)hfile1->Get("h_map0AiForLS_good_HF");
      htqn24->Sumw2();
      htqn25->Sumw2();
	TH2F* htqn26= (TH2F*)htqn24->Clone("htqn26");
	htqn26->Divide(htqn24,htqn25, 1, 1, "B");
	htqn26->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      htqn26->SetMarkerStyle(20);
      htqn26->SetMarkerSize(0.4);
      htqn26->GetZaxis()->SetLabelSize(0.08);
      htqn26->SetXTitle("#eta \b");
      htqn26->SetYTitle("#phi \b");
      htqn26->SetZTitle("<A> for good LSs - HF \b");
      htqn26->SetMarkerColor(2);
      htqn26->SetLineColor(2);
      //      htqn26->SetMaximum(1.000);
      //      htqn26->SetMinimum(0.0001);
      htqn26->Draw("COLZ");
       
       
       c1->Update();
     
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




      
