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
	//	gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
//	gStyle->SetOptStat(1101);// mame mean and rms 
	//gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	//		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
							gStyle->SetOptStat(101110);                                          // entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



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
// macro to recreate a H1Tree
// using the H1EventList in skel_writelist.C
//

	//  old 2012
	//  new 2016
	//		TFile *hfile0= new TFile("my2016_HiggsTauTau_taggingJetSelectionMC.root", "READ");//MC3 weighted
		TFile *hfile1= new TFile("my2016_HiggsTauTau_taggingJetSelectionMC.root", "READ");//DadaC_2012

	//  new 2016

		//	TFile *hfile0= new TFile("MinimumBias_Run2016G-PromptReco-v1-track90b.root", "READ");//DadaC_2012
		//	TFile *hfile1= new TFile("MinimumBias_Run2016G-PromptReco-v1-track90b.root", "READ");//DadaC_2012


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
	// 	hfile.ls();
	// 	hfile->Print();
	//    getchar();
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
          TPostScript psfile ("dedx.ps", 111);
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
   TCanvas *c1 = new TCanvas("c1","HiggsTauTauAnalysisMC",200,10,700,900);

   //  TCanvas *cHB = new TCanvas("cHB","cHB",1000,500);
   //  TCanvas *cHE = new TCanvas("cHE","cHE",1500,500);
   //  TCanvas *cONE = new TCanvas("cONE","cONE",500,500);
   //  TCanvas *cFour = new TCanvas("cFour","cFour",1500,1000);
   //  TCanvas *cFour1= new TCanvas("cFour1","cFour1",1200,800);

//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);
//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);
//AZ58      printf("TCanvas Test for dedx is Open \n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
      std::cout <<"===--> Start dedx.cc.exe ============================ " << std::endl;

      Double_t mscale=1.;
                 
//      TH1F *aaa_c1_1 = (TH1F*)hfile0->Get("hnvtx00");// mc
//      TH1F *aaa_c1_2 = (TH1F*)hfile1->Get("hnvtx00");//data
      
//      TH1F *aaa_c1_1 = (TH1F*)hfile0->Get("hnvtx1");// mc
//      TH1F *aaa_c1_2 = (TH1F*)hfile1->Get("hnvtx1");//data
      
      TH1F *aaa_c1_1 = (TH1F*)hfile1->Get("hnvtx1");// mc
      TH1F *aaa_c1_2 = (TH1F*)hfile1->Get("hnvtxClosestDetaMaxP1");//data
      
      aaa_c1_1->Sumw2();
      aaa_c1_2->Sumw2();
      //    if(aaa_c1_1->IsA()->InheritsFrom("TH1F")  && aaa_c1_2->IsA()->InheritsFrom("TH1F")){
	Double_t dintegral = aaa_c1_2->Integral();
	Double_t mintegral = aaa_c1_1->Integral();
	if(mintegral > 0.){
	  mscale = dintegral/mintegral;// comment this line if want do not apply histo normalization (except PU-reweighting)
	  //	}
      }
        
      std::cout <<"===--> mscale    = " << mscale << std::endl;
    //==================================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      //TH1F*  hNvtxEv                     = new TH1F ("hNvtxEv"," ",100, 0.,100.);
      
      c1->Clear();
      c1->Divide(2,2);
      c1->cd(1);
	{            
	  TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx000");
	  gPad->SetLogy();
	  mp3d->SetMarkerStyle(21);
	  mp3d->SetMarkerSize(0.4);
	  mp3d->GetXaxis()->SetTitle("hnvtx000");
	  mp3d->GetYaxis()->SetLabelSize(0.04);
	  mp3d->SetMarkerColor(1);
	  mp3d->SetLineColor(1);
	  //       mp3d->SetFillColor(5);
	  mp3d->SetMinimum(0.8);
	  mp3d->Draw("Error");
	}
	{            
        TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx000");
        gPad->SetLogy();
	//      mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(kRed);
        mp3d->SetLineColor(2);
        //       mp3d->SetFillColor(5);
        mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");
	}
      c1->cd(2);
	{            
	TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx00");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Nvtx00(w)");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");
	}
	{            
	TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx00");
	gPad->SetLogy();
//	mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");
	}
	
	
      c1->cd(3);
	{            
	TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Nvtx1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");
	}
	{            
	TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");
	}

      c1->cd(4);
	{            
	TH1F *mp3d= (TH1F*)hfile1->Get("hnvtx2");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Nvtx2");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");
	}

	
	
	
	c1->Update();
    //==================================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{            
	  TH1F *mp3d= (TH1F*)hfile1->Get("hVertNDF0");
	  gPad->SetLogy();
	  mp3d->SetMarkerStyle(21);
	  mp3d->SetMarkerSize(0.4);
	  mp3d->GetXaxis()->SetTitle("hVertNDF0");
	  mp3d->GetYaxis()->SetLabelSize(0.04);
	  mp3d->SetMarkerColor(1);
	  mp3d->SetLineColor(1);
	  //       mp3d->SetFillColor(5);
	  mp3d->SetMinimum(0.8);
	  mp3d->Draw("Error");
	}
	{            
        TH1F *mp3d= (TH1F*)hfile1->Get("hVertNDF0");
        gPad->SetLogy();
	//      mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(kRed);
        mp3d->SetLineColor(2);
        //       mp3d->SetFillColor(5);
        mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");
	}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hVtxZ");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hVtxZ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hVtxZCut");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);
	{            
	  TH1F *mp3d= (TH1F*)hfile1->Get("hVertChi2");
	  gPad->SetLogy();
	  mp3d->SetMarkerStyle(21);
	  mp3d->SetMarkerSize(0.4);
	  mp3d->GetXaxis()->SetTitle("hVertChi2");
	  mp3d->GetYaxis()->SetLabelSize(0.04);
	  mp3d->SetMarkerColor(1);
	  mp3d->SetLineColor(1);
	  //       mp3d->SetFillColor(5);
	  mp3d->SetMinimum(0.8);
	  mp3d->Draw("Error");
	}
	{            
        TH1F *mp3d= (TH1F*)hfile1->Get("hVertChi2");
        gPad->SetLogy();
	//      mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(kRed);
        mp3d->SetLineColor(2);
        //       mp3d->SetFillColor(5);
        mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");
	}

      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hVtxRho");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hVtxRho");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hVtxRhoCut");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

	
	
	c1->Update();
    //====================================================================================================  3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumTracksCollected000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumTracksCollected");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumTracksCollected0");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumTracksCollected");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(3);
	mp3d->SetLineColor(3);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumTracksCollected1");
	gPad->SetLogy();
//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumTracksCollected");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumTracksCollected2");
	gPad->SetLogy();
//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumTracksCollected");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kBlue);
	mp3d->SetLineColor(4);
//	mp3d->SetFillColor(5);
	mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackCharge000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackCharge000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackCharge000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("halltracknumber000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("halltracknumber000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("halltracknumber000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNmeasurements000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackNmeasurements");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNmeasurements1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNmeasurements2");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //====================================================================================================  4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx00000");
	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVx");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx0000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx00002");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx00003");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy00000");
	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVy00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy0000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy00002");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy00003");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	
      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz00000");
	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVz00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz0000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz00002");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz00003");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}


	c1->Update();
	
	
    //====================================================================================================  5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx00000");
//	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVx00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVx0000");
//	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy00000");
//	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVy00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVy0000");
//	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz00000");
//	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackVz00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVz0000");
//	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //====================================================================================================  6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz00000");
	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackDz00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz0000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz00002");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy00000");
	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackDxy00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy0000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy00002");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy000");
	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	

      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz00000");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackDz00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz0000");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDz00002");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}

      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy00000");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackDxy00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy0000");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy00002");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDxy000");
	  //	gPad->SetLogy();
	gPad->SetGridx();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("ErrorSame");}
	

	c1->Update();
	
	
    //====================================================================================================  7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits000");
	//	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackNhits");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits1");
	//	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits2");
	//	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits000");
		gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackNhits");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits1");
		gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits2");
		gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits0");
	//	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackNhits0");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits0");
	//	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits00");
	//	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackNhits00");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackNhits00");
	//	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
    //====================================================================================================  8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackPt000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackPt");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackPt1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackPt2");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackP000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackP000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackP000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackEta000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackEta");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackEta1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackEta2");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	

	c1->Update();
	
	
     //====================================================================================================  9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP00000");
	//	gPad->SetLogy();
//	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(1);
	mp2d->SetLineColor(1);
	mp2d->GetXaxis()->SetTitle("P, GeV/c");
	mp2d->GetYaxis()->SetTitle("dE/dx, [MeV/cm]");
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("");}
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP000");
	//	gPad->SetLogy();
	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(4);
	mp2d->SetLineColor(4);
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("Same");}
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP2");
	//	gPad->SetLogy();
	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(2);
	mp2d->SetLineColor(2);
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("Same");}



	c1->Update();
	
	
    //====================================================================================================  10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      /*
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP000");
	//	gPad->SetLogy();
//	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(1);
	mp2d->SetLineColor(1);
	mp2d->GetXaxis()->SetTitle("P, GeV/c");
	mp2d->GetYaxis()->SetTitle("dE/dx, [MeV/cm]");
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("");}
*/
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP1");
	//	gPad->SetLogy();
	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(4);
	mp2d->SetLineColor(4);
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("");}
	//	mp2d->Draw("Same");}
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP2");
	//	gPad->SetLogy();
	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(kRed);
	mp2d->SetLineColor(kRed);
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("Same");}



	c1->Update();
	
	
    //====================================================================================================  11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP0000");
	//	gPad->SetLogy();
//	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(2);
	mp2d->SetLineColor(2);
	mp2d->GetXaxis()->SetTitle("P, GeV/c");
	mp2d->GetYaxis()->SetTitle("dE/dx, [MeV/cm]");
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("");}

	c1->Update();
     //====================================================================================================  12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP00000");
	//	gPad->SetLogy();
//	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(1);
	mp2d->SetLineColor(1);
	mp2d->GetXaxis()->SetTitle("P, GeV/c");
	mp2d->GetYaxis()->SetTitle("dE/dx, [MeV/cm]");
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("");}
	{TH2F *mp2d= (TH2F*)hfile1->Get("hTrackDeDxVsP0000");
	//	gPad->SetLogy();
//	mp2d->Scale(mscale);
	mp2d->SetMarkerStyle(20);
	mp2d->SetMarkerSize(0.1);
	mp2d->GetYaxis()->SetLabelSize(0.04);
	mp2d->SetMarkerColor(2);
	mp2d->SetLineColor(2);
	mp2d->GetXaxis()->SetTitle("P, GeV/c");
	mp2d->GetYaxis()->SetTitle("dE/dx, [MeV/cm]");
	//       mp2d->SetFillColor(5);
	//	   mp2d->SetMinimum(0.8);
	mp2d->Draw("Same");}


	c1->Update();


    //==================================================================================================== 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP00000");
	gPad->SetLogx();
//	mp3e->Scale(mscale);
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(1);
	mp3e->SetLineColor(1);
	mp3e->GetXaxis()->SetTitle("P, GeV/c");
	mp3e->GetYaxis()->SetTitle("log(dE/dx), [MeV/cm]");
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("");}

	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP000");
	gPad->SetLogx();
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(4);
	mp3e->SetLineColor(4);
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("Same");}

	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP2");
	gPad->SetLogx();
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(2);
	mp3e->SetLineColor(2);
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("Same");}



	c1->Update();
	
	
    //==================================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      /*
	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP000");
	gPad->SetLogx();
//	mp3e->Scale(mscale);
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(1);
	mp3e->SetLineColor(1);
	mp3e->GetXaxis()->SetTitle("P, GeV/c");
	mp3e->GetYaxis()->SetTitle("log(dE/dx), [MeV/cm]");
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("");}
*/
	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP1");
	gPad->SetLogx();
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(4);
	mp3e->SetLineColor(4);
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("Same");}

	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP2");
	gPad->SetLogx();
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(2);
	mp3e->SetLineColor(2);
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("Same");}



	c1->Update();
	
	
    //==================================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      
	{TH2F *mp3e= (TH2F*)hfile1->Get("hTracklogDeDxVslogP0000");
	gPad->SetLogx();
//	mp3e->Scale(mscale);
	mp3e->SetMarkerStyle(20);
	mp3e->SetMarkerSize(0.1);
	mp3e->GetYaxis()->SetLabelSize(0.04);
	mp3e->SetMarkerColor(2);
	mp3e->SetLineColor(2);
	mp3e->GetXaxis()->SetTitle("P, GeV/c");
	mp3e->GetYaxis()->SetTitle("log(dE/dx), [MeV/cm]");
	//       mp3e->SetFillColor(5);
	//	   mp3e->SetMinimum(0.8);
	mp3e->Draw("");}


	c1->Update();
    //==================================================================================================== 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDEDX000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hTrackDEDX000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackDEDX000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTracklogDeDx00000");
		gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("logDeDx");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
		   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTracklogDeDx000");
		gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
		   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTracklogDeDx1");
		gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(5);
	mp3d->SetLineColor(5);
	//       mp3d->SetFillColor(5);
		   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTracklogDeDx2");
		gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
		   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
    //==================================================================================================== 17
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass0000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Mass 0000 00003 ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass00003");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass00002");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Mass 00002 000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass000");
	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Mass 000 2");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMass2");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}



	c1->Update();
	
	
	
    //==================================================================================================== 18
    //======================================================================
    //======================================================================
    //================ MassPlusMinus
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus0000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MassPlusMinus 0000 00003 ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00003");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00002");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MassPlusMinus 00002 000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus000");
	gPad->SetLogy();
	//	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MassPlusMinus 000 2");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("");}

	{TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus2");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(4);
	mp3d->SetLineColor(4);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}



	c1->Update();
	
	
	
    //==================================================================================================== 19
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
        {TH1F *mp3d= (TH1F*)hfile1->Get("hMass00002");
        gPad->SetLogy();
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetXaxis()->SetTitle("hMass 00002 00004 00005 00006 00007");
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(1);
        mp3d->SetLineColor(1);
	mp3d->SetMinimum(0.8);
        mp3d->Draw("Error");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMass00004");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(2);
        mp3d->SetLineColor(2);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMass00005");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(3);
        mp3d->SetLineColor(3);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("ErrorSame");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMass00006");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(4);
        mp3d->SetLineColor(4);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMass00007");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(5);
        mp3d->SetLineColor(5);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("ErrorSame");}

      c1->cd(2);
        {TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00002");
        gPad->SetLogy();
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetXaxis()->SetTitle("hMassPlusMinus 00002 00004 00005 00006 00007");
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(1);
        mp3d->SetLineColor(1);
	mp3d->SetMinimum(0.8);
        mp3d->Draw("Error");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00004");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(2);
        mp3d->SetLineColor(2);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00005");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(3);
        mp3d->SetLineColor(3);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("ErrorSame");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00006");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(4);
        mp3d->SetLineColor(4);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("Same");}

        {TH1F *mp3d= (TH1F*)hfile1->Get("hMassPlusMinus00007");
        gPad->SetLogy();
        // mp3d->Scale(mscale);
        mp3d->SetMarkerStyle(21);
        mp3d->SetMarkerSize(0.4);
        mp3d->GetYaxis()->SetLabelSize(0.04);
        mp3d->SetMarkerColor(5);
        mp3d->SetLineColor(5);
        //       mp3d->SetFillColor(5);
           mp3d->SetMinimum(0.8);
        mp3d->Draw("ErrorSame");}


        c1->Update();


    //==================================================================================================== 20
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp1d= (TH1F*)hfile1->Get("htrig1");
	gPad->SetLogy();
	mp1d->Scale(mscale);
	mp1d->SetMarkerStyle(20);
	mp1d->SetMarkerSize(0.1);
	mp1d->GetYaxis()->SetLabelSize(0.04);
	mp1d->SetMarkerColor(kBlue);
	mp1d->GetXaxis()->SetTitle("htrig1");
	mp1d->SetLineColor(4);
	//       mp1d->SetFillColor(5);
	mp1d->SetMinimum(0.8);
	mp1d->Draw("");}

      c1->cd(2);
	{TH1F *mp1d= (TH1F*)hfile1->Get("htrig2");
	gPad->SetLogy();
	mp1d->Scale(mscale);
	mp1d->SetMarkerStyle(20);
	mp1d->SetMarkerSize(0.1);
	mp1d->GetYaxis()->SetLabelSize(0.04);
	mp1d->SetMarkerColor(kBlue);
	mp1d->GetXaxis()->SetTitle("htrig2");
	mp1d->SetLineColor(4);
	//       mp1d->SetFillColor(5);
	mp1d->SetMinimum(0.8);
	mp1d->Draw("");}

      c1->cd(3);
	{TH1F *mp1d= (TH1F*)hfile1->Get("htrig3");
	gPad->SetLogy();
	mp1d->Scale(mscale);
	mp1d->SetMarkerStyle(20);
	mp1d->SetMarkerSize(0.1);
	mp1d->GetYaxis()->SetLabelSize(0.04);
	mp1d->SetMarkerColor(kBlue);
	mp1d->GetXaxis()->SetTitle("htrig3");
	mp1d->SetLineColor(4);
	//       mp1d->SetFillColor(5);
	mp1d->SetMinimum(0.8);
	mp1d->Draw("");}

      c1->cd(4);
	{TH1F *mp1d= (TH1F*)hfile1->Get("htrig4");
	gPad->SetLogy();
	mp1d->Scale(mscale);
	mp1d->SetMarkerStyle(20);
	mp1d->SetMarkerSize(0.1);
	mp1d->GetYaxis()->SetLabelSize(0.04);
	mp1d->SetMarkerColor(kBlue);
	mp1d->GetXaxis()->SetTitle("htrig4");
	mp1d->SetLineColor(4);
	//       mp1d->SetFillColor(5);
	mp1d->SetMinimum(0.8);
	mp1d->Draw("");}



	c1->Update();
	
    //==================================================================================================== 21
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoMuons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumRecoMuons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->GetXaxis()->SetTitle("N #mu");
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoMuons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->GetXaxis()->SetTitle("N #mu");
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoMuons1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumRecoMuons1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoMuons1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoElectrons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("N e");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoElectrons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("N e");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
	
      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoElectrons1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hNumRecoElectrons1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hNumRecoElectrons1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->GetXaxis()->SetTitle("N e");
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
	c1->Update();
	
	
    //==================================================================================================== 22
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDrvtx000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MuonsDR");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDrvtx000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDzvtx000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MuonsDZ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDzvtx000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsDrspot000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("ElectronsDR");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsDrspot000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsPixels000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("ElectronsDZ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsPixels000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //==================================================================================================== 23
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDrvtx1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MuonsDR");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDrvtx1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDzvtx1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("MuonsDZ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMuonsDzvtx1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsDrspot1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("ElectronsDR");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsDrspot1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsPixels1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("ElectronsDZ");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsPixels1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //==================================================================================================== 24
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoMuons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("IsoMuons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoMuons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPtPV000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03EcalRecHitSumEt/Pt000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPtPV000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPt000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03TkSumPt/Pt000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPt000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoElectrons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03HcalTowerSumEt/Pt000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoElectrons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //==================================================================================================== 25
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoMuons1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("IsoMuons1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoMuons1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPtPV1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03EcalRecHitSumEt/Pt1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPtPV1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPt1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03TkSumPt/Pt1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hElectronsSumPt1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoElectrons1");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("Electrons-dr03HcalTowerSumEt/Pt1");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hIsoElectrons1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
    //==================================================================================================== 26
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hncharge");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hncharge");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hncharge");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoChargeMuons");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoChargeMuons");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoChargeMuons");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoChargeElectrons");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoChargeElectrons");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoChargeElectrons");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

	c1->Update();
	
	
    //==================================================================================================== 27
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hDiMuonRecoMass000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hDiMuonRecoMass");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hDiMuonRecoMass1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hDiElectronRecoMass000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hDiElectronRecoMass");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hDiElectronRecoMass1");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

	c1->Update();
	
	
    //==================================================================================================== 28
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoPtMuons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoPtMuons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoPtMuons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoEtaMuons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoEtaMuons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoEtaMuons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(3);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoPtElectrons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoPtElectrons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoPtElectrons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(4);

	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoEtaElectrons000");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hRecoEtaElectrons000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hRecoEtaElectrons000");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

	c1->Update();
	
	
    //==================================================================================================== 29
    //======================================================================
    //======================================================================
    //================
    //======================================================================
            
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpt");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hMETpt");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpt");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(3);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpx");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hMETpx");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpx");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}

      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpy");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hMETpy");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETpy");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}
	
      c1->cd(4);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETphi");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hMETphi");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETphi");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


      c1->cd(5);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETet");
	gPad->SetLogy();
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetXaxis()->SetTitle("hMETet");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Error");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hMETet");
	gPad->SetLogy();
	// mp3d->Scale(mscale);
	mp3d->SetMarkerStyle(21);
	mp3d->SetMarkerSize(0.4);
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(kRed);
	mp3d->SetLineColor(2);
	//       mp3d->SetFillColor(5);
	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Same");}


	c1->Update();
	
	
	
	
     //====================================================================================================  9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
	/*            
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVTXxy00000");
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.1);
	mp3d->GetXaxis()->SetTitle("hTrackVTXxy00000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(1);
	mp3d->SetLineColor(1);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Box");}
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVTXxy0000");
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.1);
	mp3d->GetXaxis()->SetTitle("hTrackVTXxy0000");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("BoxSame");}


      c1->cd(2);
	{TH1F *mp3d= (TH1F*)hfile1->Get("hTrackVTXxy00002");
	mp3d->SetMarkerStyle(20);
	mp3d->SetMarkerSize(0.1);
	mp3d->GetXaxis()->SetTitle("hTrackVTXxy00002");
	mp3d->GetYaxis()->SetLabelSize(0.04);
	mp3d->SetMarkerColor(2);
	mp3d->SetLineColor(2);
//	   mp3d->SetMinimum(0.8);
	mp3d->Draw("Box");}



	c1->Update();


*/
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


