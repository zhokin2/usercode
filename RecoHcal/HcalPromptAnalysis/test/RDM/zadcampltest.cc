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
          TPostScript psfile ("zadcampltest.ps", 111);


//

 TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //========================================================================================== 1
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH2F *Zzzdepth1hef1= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef1->SetXTitle("#eta \b");
      Zzzdepth1hef1->SetYTitle("#phi \b");
      Zzzdepth1hef1->SetZTitle("h_mapDepth1_HE \b");
      Zzzdepth1hef1->Draw("COLZ");

      c1->cd(2);
      TH2F *Zzzdepth1hef2= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef2->SetXTitle("#eta \b");
      Zzzdepth1hef2->SetYTitle("#phi \b");
      Zzzdepth1hef2->SetZTitle("h_mapDepth2_HE \b");
      Zzzdepth1hef2->Draw("COLZ");

      c1->cd(3);
      TH2F *Zzzdepth1hef3= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef3->SetXTitle("#eta \b");
      Zzzdepth1hef3->SetYTitle("#phi \b");
      Zzzdepth1hef3->SetZTitle("h_mapDepth3_HE \b");
      Zzzdepth1hef3->Draw("COLZ");

      c1->cd(4);
      TH2F *Zzzdepth1hef4= (TH2F*)hfile1->Get("h_mapDepth4_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef4->SetXTitle("#eta \b");
      Zzzdepth1hef4->SetYTitle("#phi \b");
      Zzzdepth1hef4->SetZTitle("h_mapDepth4_HE \b");
      Zzzdepth1hef4->Draw("COLZ");

      c1->cd(5);
      TH2F *Zzzdepth1hef5= (TH2F*)hfile1->Get("h_mapDepth5_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef5->SetXTitle("#eta \b");
      Zzzdepth1hef5->SetYTitle("#phi \b");
      Zzzdepth1hef5->SetZTitle("h_mapDepth5_HE \b");
      Zzzdepth1hef5->Draw("COLZ");

      c1->cd(6);
      TH2F *Zzzdepth1hef6= (TH2F*)hfile1->Get("h_mapDepth6_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef6->SetXTitle("#eta \b");
      Zzzdepth1hef6->SetYTitle("#phi \b");
      Zzzdepth1hef6->SetZTitle("h_mapDepth6_HE \b");
      Zzzdepth1hef6->Draw("COLZ");

      c1->cd(7);
      TH2F *Zzzdepth1hef7= (TH2F*)hfile1->Get("h_mapDepth7_HE");
      gPad->SetGridy();      gPad->SetGridx();      gPad->SetLogz();
      Zzzdepth1hef7->SetXTitle("#eta \b");
      Zzzdepth1hef7->SetYTitle("#phi \b");
      Zzzdepth1hef7->SetZTitle("h_mapDepth7_HE \b");
      Zzzdepth1hef7->Draw("COLZ");


      
       c1->Update();
     
    //========================================================================================== 2    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
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
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *kqlerd1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HF");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd1->SetMarkerStyle(20);
      kqlerd1->SetMarkerSize(0.8);
      kqlerd1->GetYaxis()->SetLabelSize(0.04);
      kqlerd1->SetXTitle("h_ADCAmplZoom1_HF \b");
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
      
      c1->cd(5);
      TH1F *kqlerd5= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd5->SetMarkerStyle(20);
      kqlerd5->SetMarkerSize(0.8);
      kqlerd5->GetYaxis()->SetLabelSize(0.04);
      kqlerd5->SetXTitle("h_ADCAmpl_HE \b");
      kqlerd5->SetMarkerColor(2);
      kqlerd5->SetLineColor(2);
      kqlerd5->Draw("");
      
      c1->cd(6);
      TH1F *kqlerd6= (TH1F*)hfile1->Get("h_ADCAmpl345_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd6->SetMarkerStyle(20);
      kqlerd6->SetMarkerSize(0.8);
      kqlerd6->GetYaxis()->SetLabelSize(0.04);
      kqlerd6->SetXTitle("h_ADCAmpl345_HE \b");
      kqlerd6->SetMarkerColor(2);
      kqlerd6->SetLineColor(2);
      kqlerd6->Draw("");
      
      c1->Update();
      
    //========================================================================================== 3    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
      
      c1->cd(1);
      TH1F *JDBEYESJ0= (TH1F*)hfile1->Get("h_totalAmplitudeHBperEvent");
      //      gPad->SetLogy();
      // gPad->SetLogx();
      JDBEYESJ0->SetStats(0);
      JDBEYESJ0->SetMarkerStyle(20);
      JDBEYESJ0->SetMarkerSize(0.8);
      JDBEYESJ0->GetYaxis()->SetLabelSize(0.04);
      JDBEYESJ0->SetXTitle("h_totalAmplitudeHBperEvent \b");
      JDBEYESJ0->SetMarkerColor(2);
      JDBEYESJ0->SetLineColor(1);
      JDBEYESJ0->Draw("HIST same P0");
      JDBEYESJ0->SetMinimum(0.8);
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *JDBEYESJ1= (TH1F*)hfile1->Get("h_totalAmplitudeHEperEvent");
      //      gPad->SetLogy();
      // gPad->SetLogx();
      JDBEYESJ1->SetStats(0);
      JDBEYESJ1->SetMarkerStyle(20);
      JDBEYESJ1->SetMarkerSize(0.8);
      JDBEYESJ1->GetYaxis()->SetLabelSize(0.04);
      JDBEYESJ1->SetXTitle("h_totalAmplitudeHEperEvent \b");
      JDBEYESJ1->SetMarkerColor(2);
      JDBEYESJ1->SetLineColor(1);
      JDBEYESJ1->Draw("HIST same P0");
      JDBEYESJ1->SetMinimum(0.8);
      c1->cd(3);
      TH1F *JDBEYESJ2= (TH1F*)hfile1->Get("h_totalAmplitudeHFperEvent");
      // gPad->SetLogy();
      // gPad->SetLogx();
      JDBEYESJ2->SetStats(0);
      JDBEYESJ2->SetMarkerStyle(20);
      JDBEYESJ2->SetMarkerSize(0.8);
      JDBEYESJ2->GetYaxis()->SetLabelSize(0.04);
      JDBEYESJ2->SetXTitle("h_totalAmplitudeHFperEvent \b");
      JDBEYESJ2->SetMarkerColor(2);
      JDBEYESJ2->SetLineColor(2);
      JDBEYESJ2->Draw("HIST same P0");
      JDBEYESJ2->SetMinimum(0.8);
      c1->cd(4);
      TH1F *JDBEYESJ3= (TH1F*)hfile1->Get("h_totalAmplitudeHOperEvent");
      // gPad->SetLogy();
      // gPad->SetLogx();
      JDBEYESJ3->SetStats(0);
      JDBEYESJ3->SetMarkerStyle(20);
      JDBEYESJ3->SetMarkerSize(0.8);
      JDBEYESJ3->GetYaxis()->SetLabelSize(0.04);
      JDBEYESJ3->SetXTitle("h_totalAmplitudeHOperEvent \b");
      JDBEYESJ3->SetMarkerColor(2);
      JDBEYESJ3->SetLineColor(2);
      JDBEYESJ3->Draw("HIST same P0");
      JDBEYESJ3->SetMinimum(0.8);

      c1->Update();
      
    //========================================================================================== 4    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *kjftrh0= (TH1F*)hfile1->Get("h_totalAmplitudeHB");
      gPad->SetLogy();
      // gPad->SetLogx();
      kjftrh0->SetMarkerStyle(20);
      kjftrh0->SetMarkerSize(0.8);
      kjftrh0->GetYaxis()->SetLabelSize(0.04);
      kjftrh0->SetXTitle("h_totalAmplitudeHB \b");
      kjftrh0->SetMarkerColor(2);
      kjftrh0->SetLineColor(2);
      kjftrh0->Draw("");
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *kjftrh1= (TH1F*)hfile1->Get("h_totalAmplitudeHE");
      gPad->SetLogy();
      // gPad->SetLogx();
      kjftrh1->SetMarkerStyle(20);
      kjftrh1->SetMarkerSize(0.8);
      kjftrh1->GetYaxis()->SetLabelSize(0.04);
      kjftrh1->SetXTitle("h_totalAmplitudeHE \b");
      kjftrh1->SetMarkerColor(2);
      kjftrh1->SetLineColor(2);
      kjftrh1->Draw("");
      
      c1->cd(3);
      TH1F *kjftrh2= (TH1F*)hfile1->Get("h_totalAmplitudeHF");
      gPad->SetLogy();
      // gPad->SetLogx();
      kjftrh2->SetMarkerStyle(20);
      kjftrh2->SetMarkerSize(0.8);
      kjftrh2->GetYaxis()->SetLabelSize(0.04);
      kjftrh2->SetXTitle("h_totalAmplitudeHF \b");
      kjftrh2->SetMarkerColor(2);
      kjftrh2->SetLineColor(2);
      kjftrh2->Draw("");
      
      c1->cd(4);
      TH1F *kjftrh3= (TH1F*)hfile1->Get("h_totalAmplitudeHO");
      gPad->SetLogy();
      // gPad->SetLogx();
      kjftrh3->SetMarkerStyle(20);
      kjftrh3->SetMarkerSize(0.8);
      kjftrh3->GetYaxis()->SetLabelSize(0.04);
      kjftrh3->SetXTitle("h_totalAmplitudeHO \b");
      kjftrh3->SetMarkerColor(2);
      kjftrh3->SetLineColor(2);
      kjftrh3->Draw("");
      
      
      c1->Update();
      
    //========================================================================================== 5    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *oqppq0= (TH1F*)hfile1->Get("h_AmplitudeHBtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      oqppq0->SetMarkerStyle(20);
      oqppq0->SetMarkerSize(0.8);
      oqppq0->GetYaxis()->SetLabelSize(0.04);
      oqppq0->SetXTitle("h_AmplitudeHBtest \b");
      oqppq0->SetMarkerColor(2);
      oqppq0->SetLineColor(2);
      oqppq0->Draw("");
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *oqppq1= (TH1F*)hfile1->Get("h_AmplitudeHEtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      oqppq1->SetMarkerStyle(20);
      oqppq1->SetMarkerSize(0.8);
      oqppq1->GetYaxis()->SetLabelSize(0.04);
      oqppq1->SetXTitle("h_AmplitudeHEtest \b");
      oqppq1->SetMarkerColor(2);
      oqppq1->SetLineColor(2);
      oqppq1->Draw("");
      
      c1->cd(3);
      TH1F *oqppq2= (TH1F*)hfile1->Get("h_AmplitudeHFtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      oqppq2->SetMarkerStyle(20);
      oqppq2->SetMarkerSize(0.8);
      oqppq2->GetYaxis()->SetLabelSize(0.04);
      oqppq2->SetXTitle("h_AmplitudeHFtest \b");
      oqppq2->SetMarkerColor(2);
      oqppq2->SetLineColor(2);
      oqppq2->Draw("");
      
      c1->cd(4);
      TH1F *oqppq3= (TH1F*)hfile1->Get("h_AmplitudeHOtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      oqppq3->SetMarkerStyle(20);
      oqppq3->SetMarkerSize(0.8);
      oqppq3->GetYaxis()->SetLabelSize(0.04);
      oqppq3->SetXTitle("h_AmplitudeHOtest \b");
      oqppq3->SetMarkerColor(2);
      oqppq3->SetLineColor(2);
      oqppq3->Draw("");
      
      
      c1->Update();
      
    //========================================================================================== 6    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *KJGHG0= (TH1F*)hfile1->Get("h_numberofhitsHBtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      KJGHG0->SetMarkerStyle(20);
      KJGHG0->SetMarkerSize(0.8);
      KJGHG0->GetYaxis()->SetLabelSize(0.04);
      KJGHG0->SetXTitle("h_numberofhitsHB \b");
      KJGHG0->SetMarkerColor(2);
      KJGHG0->SetLineColor(2);
      KJGHG0->Draw("");
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *KJGHG1= (TH1F*)hfile1->Get("h_numberofhitsHEtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      KJGHG1->SetMarkerStyle(20);
      KJGHG1->SetMarkerSize(0.8);
      KJGHG1->GetYaxis()->SetLabelSize(0.04);
      KJGHG1->SetXTitle("h_numberofhitsHE \b");
      KJGHG1->SetMarkerColor(2);
      KJGHG1->SetLineColor(2);
      KJGHG1->Draw("");
      
      c1->cd(3);
      TH1F *KJGHG2= (TH1F*)hfile1->Get("h_numberofhitsHFtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      KJGHG2->SetMarkerStyle(20);
      KJGHG2->SetMarkerSize(0.8);
      KJGHG2->GetYaxis()->SetLabelSize(0.04);
      KJGHG2->SetXTitle("h_numberofhitsHF \b");
      KJGHG2->SetMarkerColor(2);
      KJGHG2->SetLineColor(2);
      KJGHG2->Draw("");
      
      c1->cd(4);
      TH1F *KJGHG3= (TH1F*)hfile1->Get("h_numberofhitsHOtest");
      gPad->SetLogy();
      // gPad->SetLogx();
      KJGHG3->SetMarkerStyle(20);
      KJGHG3->SetMarkerSize(0.8);
      KJGHG3->GetYaxis()->SetLabelSize(0.04);
      KJGHG3->SetXTitle("h_numberofhitsHO \b");
      KJGHG3->SetMarkerColor(2);
      KJGHG3->SetLineColor(2);
      KJGHG3->Draw("");
      
      
      c1->Update();
      
    //========================================================================================== 7    
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *kjkjkhj0= (TH1F*)hfile1->Get("h_AmplitudeHBtest1");
      //      gPad->SetLogy();
      // gPad->SetLogx();
     kjkjkhj0->SetMarkerStyle(20);
     kjkjkhj0->SetMarkerSize(0.8);
     kjkjkhj0->GetYaxis()->SetLabelSize(0.04);
     kjkjkhj0->SetXTitle("h_AmplitudeHBtest1 \b");
     kjkjkhj0->SetMarkerColor(2);
     kjkjkhj0->SetLineColor(2);
     kjkjkhj0->Draw("");
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *kjkjkhj1= (TH1F*)hfile1->Get("h_AmplitudeHBtest6");
//       gPad->SetLogy();
      // gPad->SetLogx();
     kjkjkhj1->SetMarkerStyle(20);
     kjkjkhj1->SetMarkerSize(0.8);
     kjkjkhj1->GetYaxis()->SetLabelSize(0.04);
     kjkjkhj1->SetXTitle("h_AmplitudeHBtest6 \b");
     kjkjkhj1->SetMarkerColor(2);
     kjkjkhj1->SetLineColor(2);
     kjkjkhj1->Draw("");
      
      c1->cd(3);
      TH1F *kjkjkhj2= (TH1F*)hfile1->Get("h_AmplitudeHEtest1");
//       gPad->SetLogy();
      // gPad->SetLogx();
     kjkjkhj2->SetMarkerStyle(20);
     kjkjkhj2->SetMarkerSize(0.8);
     kjkjkhj2->GetYaxis()->SetLabelSize(0.04);
     kjkjkhj2->SetXTitle("h_AmplitudeHEtest1 \b");
     kjkjkhj2->SetMarkerColor(2);
     kjkjkhj2->SetLineColor(2);
     kjkjkhj2->Draw("");
      
      c1->cd(4);
      TH1F *kjkjkhj3= (TH1F*)hfile1->Get("h_AmplitudeHEtest6");
//       gPad->SetLogy();
      // gPad->SetLogx();
     kjkjkhj3->SetMarkerStyle(20);
     kjkjkhj3->SetMarkerSize(0.8);
     kjkjkhj3->GetYaxis()->SetLabelSize(0.04);
     kjkjkhj3->SetXTitle("h_AmplitudeHEtest6 \b");
     kjkjkhj3->SetMarkerColor(2);
     kjkjkhj3->SetLineColor(2);
     kjkjkhj3->Draw("");
      
      
      c1->Update();
    //========================================================================================== 8  
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *dkfuirhj0= (TH1F*)hfile1->Get("h_AmplitudeHBtest1");
      gPad->SetLogy();
      // gPad->SetLogx();
     dkfuirhj0->SetMarkerStyle(20);
     dkfuirhj0->SetMarkerSize(0.8);
     dkfuirhj0->GetYaxis()->SetLabelSize(0.04);
     dkfuirhj0->SetXTitle("h_AmplitudeHBtest1 \b");
     dkfuirhj0->SetMarkerColor(2);
     dkfuirhj0->SetLineColor(2);
     dkfuirhj0->Draw("");
      //    h_ADCAmpl_HF"
      c1->cd(2);
      TH1F *dkfuirhj1= (TH1F*)hfile1->Get("h_AmplitudeHBtest6");
      gPad->SetLogy();
      // gPad->SetLogx();
     dkfuirhj1->SetMarkerStyle(20);
     dkfuirhj1->SetMarkerSize(0.8);
     dkfuirhj1->GetYaxis()->SetLabelSize(0.04);
     dkfuirhj1->SetXTitle("h_AmplitudeHBtest6 \b");
     dkfuirhj1->SetMarkerColor(2);
     dkfuirhj1->SetLineColor(2);
     dkfuirhj1->Draw("");
      
      c1->cd(3);
      TH1F *dkfuirhj2= (TH1F*)hfile1->Get("h_AmplitudeHEtest1");
      gPad->SetLogy();
      // gPad->SetLogx();
     dkfuirhj2->SetMarkerStyle(20);
     dkfuirhj2->SetMarkerSize(0.8);
     dkfuirhj2->GetYaxis()->SetLabelSize(0.04);
     dkfuirhj2->SetXTitle("h_AmplitudeHEtest1 \b");
     dkfuirhj2->SetMarkerColor(2);
     dkfuirhj2->SetLineColor(2);
     dkfuirhj2->Draw("");
      
      c1->cd(4);
      TH1F *dkfuirhj3= (TH1F*)hfile1->Get("h_AmplitudeHEtest6");
      gPad->SetLogy();
      // gPad->SetLogx();
     dkfuirhj3->SetMarkerStyle(20);
     dkfuirhj3->SetMarkerSize(0.8);
     dkfuirhj3->GetYaxis()->SetLabelSize(0.04);
     dkfuirhj3->SetXTitle("h_AmplitudeHEtest6 \b");
     dkfuirhj3->SetMarkerColor(2);
     dkfuirhj3->SetLineColor(2);
     dkfuirhj3->Draw("");
      
      
      c1->Update();
    //========================================================================================== 9
      //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      TH1F *kbdfv= (TH1F*)hfile1->Get("h_ADCAmpl345_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
     kbdfv->SetMarkerStyle(20);
     kbdfv->SetMarkerSize(0.8);
     kbdfv->GetYaxis()->SetLabelSize(0.04);
     kbdfv->SetXTitle("h_ADCAmpl345_HE \b");
     kbdfv->SetMarkerColor(2);
     kbdfv->SetLineColor(2);
     kbdfv->Draw("");


      c1->cd(2);
      TH2F *twoedepth1hb1= (TH2F*)hfile1->Get("h_corrforxaMAIN_HE");
      TH2F *twoedepth1hb0= (TH2F*)hfile1->Get("h_corrforxaMAIN0_HE");
      twoedepth1hb1->Sumw2();
      twoedepth1hb0->Sumw2();
	TH2F* Cdepth1hbfz225= (TH2F*)twoedepth1hb1->Clone("Cdepth1hbfz225");
	Cdepth1hbfz225->Divide(twoedepth1hb1,twoedepth1hb0, 1, 1, "B");
	Cdepth1hbfz225->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gStyle->SetOptStat(00000000);
      Cdepth1hbfz225->SetMarkerStyle(20);
      Cdepth1hbfz225->SetMarkerSize(0.4);
      Cdepth1hbfz225->SetXTitle("charge, fC \b");
      Cdepth1hbfz225->SetYTitle("Fcor \b");
      Cdepth1hbfz225->SetMarkerColor(2);
      Cdepth1hbfz225->SetLineColor(2);
      Cdepth1hbfz225->SetMaximum(1.500);
      Cdepth1hbfz225->SetMinimum(0.9);
      Cdepth1hbfz225->Draw("HIST same P0");

      TH2F *gffgghb1= (TH2F*)hfile1->Get("h_corrforxaADDI_HE");
      TH2F *gffgghb0= (TH2F*)hfile1->Get("h_corrforxaADDI0_HE");
      gffgghb1->Sumw2();
      gffgghb0->Sumw2();
	TH2F* Cdepth1hbfz399= (TH2F*)gffgghb1->Clone("Cdepth1hbfz399");
	Cdepth1hbfz399->Divide(gffgghb1,gffgghb0, 1, 1, "B");
	Cdepth1hbfz399->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gStyle->SetOptStat(00000000);
      Cdepth1hbfz399->SetMarkerStyle(24);
      Cdepth1hbfz399->SetMarkerSize(0.4);
      Cdepth1hbfz399->SetXTitle("charge, fC \b");
      Cdepth1hbfz399->SetYTitle("Fcor \b");
      Cdepth1hbfz399->SetMarkerColor(4);
      Cdepth1hbfz399->SetLineColor(4);
      Cdepth1hbfz399->SetMaximum(1.500);
      Cdepth1hbfz399->SetMinimum(0.9);
      Cdepth1hbfz399->Draw("HIST same P0");
      
      
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




      
