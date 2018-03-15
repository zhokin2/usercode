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
#include "TF1.h"

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
	//		gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// name mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		gStyle->SetOptStat(101110);                                          // entries, mean, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		  			//	gStyle->SetOptStat(100000);//  over !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//
		//	gStyle->SetOptFit(00010);// constant, mean and sigma only !!
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
          TPostScript psfile ("zadcamplpedGsel.ps", 111);


//

 TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
             
      c1->cd(1);
      TH1F *kqlerd2= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      kqlerd2->SetStats(0);
      kqlerd2->SetMarkerStyle(20);
      kqlerd2->SetMarkerSize(0.8);
      kqlerd2->GetYaxis()->SetLabelSize(0.04);
      //    kqlerd2->SetXTitle("Aijk max 1TS HE \b");
      kqlerd2->SetXTitle("Aijk all TSs HE \b");
      kqlerd2->SetMarkerColor(2);
      kqlerd2->SetLineColor(2);
      kqlerd2->Draw("");
      //////////////////////////////////////
      TH2F *twod1he1= (TH2F*)hfile1->Get("h_mapADCAmplfirstpeak_HE");
      TH2F *twod1he0= (TH2F*)hfile1->Get("h_mapADCAmplfirstpeak0_HE");
      TH2F* C1heff = (TH2F*)twod1he1->Clone("C1heff");
      C1heff->Divide(twod1he1,twod1he0, 1, 1, "B");
      C1heff->Sumw2();
      TH2F *twod9he1= (TH2F*)hfile1->Get("h_mapADCAmplsecondpeak_HE");
      TH2F *twod9he0= (TH2F*)hfile1->Get("h_mapADCAmplsecondpeak0_HE");
      TH2F* C9heff = (TH2F*)twod9he1->Clone("C9heff");
      C9heff->Divide(twod9he1,twod9he0, 1, 1, "B");
      C9heff->Sumw2();
      ///////////////////////////////////
      c1->cd(2);
      TH1F* aiffsecondtofirst = new TH1F("aiffsecondtofirst","", 200, 0.,200.);
      TH1F* biffsecondtofirst = new TH1F("biffsecondtofirst","", 200, 0.,200.);
      TH1F* diffsecondtofirst = new TH1F("diffsecondtofirst","", 100, 35.,55.);
      TH2F* C9hefw = (TH2F*)C9heff->Clone("diffsecondtofirst");
      for (int i=1;i<=C9hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=C9hefw->GetYaxis()->GetNbins();j++) {
	  double aiffer = C9heff->GetBinContent(i,j);
	  double biffer = C1heff->GetBinContent(i,j) ;
	  double differ = C9heff->GetBinContent(i,j) - C1heff->GetBinContent(i,j) ;
	  if(aiffer != 0.) aiffsecondtofirst->Fill(aiffer);
	  if(biffer != 0.) biffsecondtofirst->Fill(biffer);
	  if(differ != 0.) diffsecondtofirst->Fill(differ);
	}
      }
      gPad->SetLogy(kFALSE);
      diffsecondtofirst->SetMarkerStyle(20);
      diffsecondtofirst->SetMarkerSize(0.4);
      diffsecondtofirst->GetYaxis()->SetLabelSize(0.04);
      diffsecondtofirst->SetXTitle("dirrerence of second and first peaks for each channel (depth-averaged) \b");
      diffsecondtofirst->SetMarkerColor(2);
      diffsecondtofirst->SetLineColor(2);
      diffsecondtofirst->Draw("");

      TF1* g0 = new TF1("m1","gaus",30,50);
      diffsecondtofirst->Fit(g0,"R");


      //      diffsecondtofirst.Fit("gaus");


      c1->cd(3);
      aiffsecondtofirst->Draw("");
      c1->cd(4);
      biffsecondtofirst->Draw("");
             
      c1->Update();
      
            
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
             
      c1->cd(1);
      TH1F *plot2= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom1_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      plot2->SetStats(0);
      plot2->SetMarkerStyle(20);
      plot2->SetMarkerSize(0.8);
      plot2->GetYaxis()->SetLabelSize(0.04);
      plot2->SetXTitle("Aijk 3TSs HE \b");
      plot2->SetMarkerColor(2);
      plot2->SetLineColor(2);
      plot2->Draw("");
      //////////////////////////////////////
      TH2F *hdjej1= (TH2F*)hfile1->Get("h_mapADCAmpl11firstpeak_HE");
      TH2F *hdjej0= (TH2F*)hfile1->Get("h_mapADCAmpl11firstpeak0_HE");
      TH2F* C1zeff = (TH2F*)hdjej1->Clone("C1zeff");
      C1zeff->Divide(hdjej1,hdjej0, 1, 1, "B");
      C1zeff->Sumw2();
      TH2F *twod8he1= (TH2F*)hfile1->Get("h_mapADCAmpl11secondpeak_HE");
      TH2F *twod8he0= (TH2F*)hfile1->Get("h_mapADCAmpl11secondpeak0_HE");
      TH2F* C8zeff = (TH2F*)twod8he1->Clone("C8zeff");
      C8zeff->Divide(twod8he1,twod8he0, 1, 1, "B");
      C8zeff->Sumw2();
      ///////////////////////////////////
      c1->cd(2);
      TH1F* aiffsecondtofirst1 = new TH1F("aiffsecondtofirst1","", 200, 0.,200.);
      TH1F* biffsecondtofirst1 = new TH1F("biffsecondtofirst1","", 200, 0.,200.);
      TH1F* diffsecondtofirst1 = new TH1F("diffsecondtofirst1","", 100, 35.,55.);
      TH2F* C8hefw = (TH2F*)C8zeff->Clone("diffsecondtofirst1");
      for (int i=1;i<=C8hefw->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=C8hefw->GetYaxis()->GetNbins();j++) {
	  double differ = C8zeff->GetBinContent(i,j) - C1zeff->GetBinContent(i,j) ;
	  double aiffer = C8zeff->GetBinContent(i,j);
	  double biffer = C1zeff->GetBinContent(i,j);
	  if(differ != 0.) diffsecondtofirst1->Fill(differ);
	  if(aiffer != 0.) aiffsecondtofirst1->Fill(aiffer);
	  if(biffer != 0.) biffsecondtofirst1->Fill(biffer);
	}
      }
      gPad->SetLogy(kFALSE);
      diffsecondtofirst1->SetMarkerStyle(20);
      diffsecondtofirst1->SetMarkerSize(0.4);
      diffsecondtofirst1->GetYaxis()->SetLabelSize(0.04);
      diffsecondtofirst1->SetXTitle("dirrerence of second and first peaks for each channel (depth-averaged) \b");
      diffsecondtofirst1->SetMarkerColor(2);
      diffsecondtofirst1->SetLineColor(2);
      diffsecondtofirst1->Draw("");
      TF1* gg = new TF1("mg","gaus",30,50);
      diffsecondtofirst1->Fit(gg,"R");



      c1->cd(3);
      aiffsecondtofirst1->Draw("");
      c1->cd(4);
      biffsecondtofirst1->Draw("");
             
      c1->Update();
      
            
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
             
      c1->cd(1);
      TH1F *plot3= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom_HE");
      gPad->SetLogy();
      // gPad->SetLogx();
      plot3->SetStats(0);
      plot3->SetMarkerStyle(20);
      plot3->SetMarkerSize(0.8);
      plot3->GetYaxis()->SetLabelSize(0.04);
      plot3->SetXTitle("Aijk 4TSs HE \b");
      plot3->SetMarkerColor(2);
      plot3->SetLineColor(2);
      plot3->Draw("");
      //////////////////////////////////////
      TH2F *hdjem1= (TH2F*)hfile1->Get("h_mapADCAmpl12firstpeak_HE");
      TH2F *hdjem0= (TH2F*)hfile1->Get("h_mapADCAmpl12firstpeak0_HE");
      TH2F* M1zeff = (TH2F*)hdjem1->Clone("M1zeff");
      M1zeff->Divide(hdjem1,hdjem0, 1, 1, "B");
      M1zeff->Sumw2();
      //////////////////////////////////////
      TH2F *twod7he1= (TH2F*)hfile1->Get("h_mapADCAmpl12secondpeak_HE");
      TH2F *twod7he0= (TH2F*)hfile1->Get("h_mapADCAmpl12secondpeak0_HE");
      TH2F* C9zeff = (TH2F*)twod7he1->Clone("C9zeff");
      C9zeff->Divide(twod7he1,twod7he0, 1, 1, "B");
      C9zeff->Sumw2();
      ///////////////////////////////////
      c1->cd(2);
      TH1F* aiffsecondtofirst7 = new TH1F("aiffsecondtofirst7","", 200, 0.,200.);
      TH1F* biffsecondtofirst7 = new TH1F("biffsecondtofirst7","", 200, 0.,200.);
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
      diffsecondtofirst7->GetYaxis()->SetLabelSize(0.04);
      diffsecondtofirst7->SetXTitle("dirrerence of second and first peaks for each channel (depth-averaged) \b");
      diffsecondtofirst7->SetMarkerColor(2);
      diffsecondtofirst7->SetLineColor(2);
      diffsecondtofirst7->Draw("");
      TF1* g7 = new TF1("m1","gaus",30,50);
      diffsecondtofirst7->Fit(g7,"R");

      c1->cd(3);
      aiffsecondtofirst7->Draw("");
      c1->cd(4);
      biffsecondtofirst7->Draw("");
             
      c1->Update();
      
            
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
             
      c1->cd(1);
      TH1F *zolton1= (TH1F*)hfile1->Get("h_gsmdifferencefit1_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton1->SetStats(0);
      zolton1->SetMarkerStyle(20);
      zolton1->SetMarkerSize(0.8);
      zolton1->GetYaxis()->SetLabelSize(0.04);
      zolton1->SetXTitle("diff fit 1 HE \b");
      zolton1->SetMarkerColor(2);
      zolton1->SetLineColor(2);
      zolton1->Draw("");
      TF1* g1 = new TF1("m1","gaus",25,55);
      zolton1->Fit(g1,"R");

      c1->cd(2);
      TH1F *zolton2= (TH1F*)hfile1->Get("h_gsmdifferencefit4_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton2->SetStats(0);
      zolton2->SetMarkerStyle(20);
      zolton2->SetMarkerSize(0.8);
      zolton2->GetYaxis()->SetLabelSize(0.04);
      zolton2->SetXTitle("diff fit 4 HE \b");
      zolton2->SetMarkerColor(2);
      zolton2->SetLineColor(2);
      zolton2->Draw("");
      TF1* g2 = new TF1("m2","gaus",25,55);
      zolton2->Fit(g2,"R");

      c1->cd(3);
      TH1F *zolton3= (TH1F*)hfile1->Get("h_gsmdifferencefit2_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton3->SetStats(0);
      zolton3->SetMarkerStyle(20);
      zolton3->SetMarkerSize(0.8);
      zolton3->GetYaxis()->SetLabelSize(0.04);
      zolton3->SetXTitle("diff fit 2 HE \b");
      zolton3->SetMarkerColor(2);
      zolton3->SetLineColor(2);
      zolton3->Draw("");
      TF1* g3 = new TF1("m3","gaus",25,55);
      zolton3->Fit(g3,"R");

      c1->cd(4);
      TH1F *zolton4= (TH1F*)hfile1->Get("h_gsmdifferencefit5_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton4->SetStats(0);
      zolton4->SetMarkerStyle(20);
      zolton4->SetMarkerSize(0.8);
      zolton4->GetYaxis()->SetLabelSize(0.04);
      zolton4->SetXTitle("diff fit 5 HE \b");
      zolton4->SetMarkerColor(2);
      zolton4->SetLineColor(2);
      zolton4->Draw("");
      TF1* g4 = new TF1("m4","gaus",25,55);
      zolton4->Fit(g4,"R");

      c1->cd(5);
      TH1F *zolton5= (TH1F*)hfile1->Get("h_gsmdifferencefit3_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton5->SetStats(0);
      zolton5->SetMarkerStyle(20);
      zolton5->SetMarkerSize(0.8);
      zolton5->GetYaxis()->SetLabelSize(0.04);
      zolton5->SetXTitle("diff fit 3 HE \b");
      zolton5->SetMarkerColor(2);
      zolton5->SetLineColor(2);
      zolton5->Draw("");
      TF1* g5 = new TF1("m5","gaus",25,55);
      zolton5->Fit(g5,"R");

      c1->cd(6);
      TH1F *zolton6= (TH1F*)hfile1->Get("h_gsmdifferencefit6_HE");
      gPad->SetLogy(kFALSE);
      // gPad->SetLogx();
//      zolton6->SetStats(0);
      zolton6->SetMarkerStyle(20);
      zolton6->SetMarkerSize(0.8);
      zolton6->GetYaxis()->SetLabelSize(0.04);
      zolton6->SetXTitle("diff fit 6 HE \b");
      zolton6->SetMarkerColor(2);
      zolton6->SetLineColor(2);
      zolton6->Draw("");
      TF1* g6 = new TF1("m6","gaus",25,55);
      zolton6->Fit(g6,"R");


      c1->Update();
      //////////////////////////////////////
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
             
      c1->cd(1);
      TH1F *plot6= (TH1F*)hfile1->Get("h_ndepthesperamplitudebins_HE");
      gPad->SetLogy();
      plot6->SetStats(0);
      plot6->SetMarkerStyle(20);
      plot6->SetMarkerSize(0.8);
      plot6->GetYaxis()->SetLabelSize(0.04);
      plot6->SetXTitle("ndepthesperamplitudebins \b");
      plot6->SetMarkerColor(2);
      plot6->SetLineColor(2);
      plot6->SetMinimum(0.9);
      plot6->Draw("");

      c1->cd(2);
      TH1F *plot7= (TH1F*)hfile1->Get("h_amplitudeaveragedbydepthes_HE");
      gPad->SetLogy(kFALSE);
      plot7->SetStats(0);
      plot7->SetMarkerStyle(20);
      plot7->SetMarkerSize(0.8);
      plot7->GetYaxis()->SetLabelSize(0.04);
      plot7->SetXTitle("amplitudeaveragedbydepthes \b");
      plot7->SetMarkerColor(2);
      plot7->SetLineColor(2);
      plot7->SetMinimum(0.9);
      plot7->Draw("");

      c1->Update();
      //////////////////////////////////////
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
