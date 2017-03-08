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
	//		   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//				gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(101110);                                          // entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
//	TFile *hfile1= new TFile("LASER_284348.root", "READ");        
//	TFile *hfile2= new TFile("LASER_287398.root", "READ");

//	TFile *hfile1= new TFile("LASER_284352.root", "READ");        
//	TFile *hfile2= new TFile("LASER_287398.root", "READ");

//	TFile *hfile1= new TFile("LASER_284472.root", "READ");        
//	TFile *hfile2= new TFile("LASER_287398.root", "READ");

//	TFile *hfile1= new TFile("LASER_264649.root", "READ");        
//	TFile *hfile2= new TFile("LASER_287398.root", "READ");


  	TFile *hfile1= new TFile("LASER_226835.root", "READ");        
  	TFile *hfile2= new TFile("LASER_287398.root", "READ");

	//	TFile *hfile1= new TFile("LASER_272967.root", "READ");        
	//	TFile *hfile2= new TFile("LASER_287398.root", "READ");

	//	TFile *hfile1= new TFile("LASER_272957.root", "READ");        
	//	TFile *hfile2= new TFile("LASER_287398.root", "READ");

	//	TFile *hfile1= new TFile("LASER_272977.root", "READ");        
	//	TFile *hfile2= new TFile("LASER_287398.root", "READ");
	//    getchar();
	//
          TPostScript psfile ("zraddam1.ps", 111);
//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


      //======================================================================  Ratio:           
    //============================================================================================= 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod19= (TH2F*)hfile1->Get("h_mapDepth1RADDAM5_HE");
      TH2F *twod09= (TH2F*)hfile1->Get("h_mapDepth1RADDAM6_HE");
      twod19->Sumw2();
      twod09->Sumw2();
	TH2F* Ceff9 = (TH2F*)twod19->Clone("Ceff9");
	Ceff9->Divide(twod19,twod09, 1, 1, "B");
	Ceff9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff9->SetMarkerStyle(20);
      Ceff9->SetMarkerSize(0.4);
      Ceff9->GetYaxis()->SetLabelSize(0.04);
      Ceff9->SetXTitle("#eta");
      Ceff9->SetYTitle("#phi");
      Ceff9->SetZTitle("Ratio for 1st Run - HE Depth1");
      Ceff9->SetMarkerColor(2);
      Ceff9->SetLineColor(2);
      Ceff9->Draw("COLZ");
      
      c1->cd(2);
      TH2F *tqod19= (TH2F*)hfile2->Get("h_mapDepth1RADDAM5_HE");
      TH2F *tqod09= (TH2F*)hfile2->Get("h_mapDepth1RADDAM6_HE");
      tqod19->Sumw2();
      tqod09->Sumw2();
	TH2F* Czeff9 = (TH2F*)tqod19->Clone("Czeff9");
	Czeff9->Divide(tqod19,tqod09, 1, 1, "B");
	Czeff9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Czeff9->SetMarkerStyle(20);
      Czeff9->SetMarkerSize(0.4);
      Czeff9->GetYaxis()->SetLabelSize(0.04);
      Czeff9->SetXTitle("#eta");
      Czeff9->SetYTitle("#phi");
      Czeff9->SetZTitle("Ratio for 2nd Run - HE Depth1");
      Czeff9->SetMarkerColor(2);
      Czeff9->SetLineColor(2);
      Czeff9->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
      TH2F* Diffe_Depth1_HE9 = (TH2F*)Ceff9->Clone("Diffe_Depth1_HE9");
      for (int i=1;i<=Ceff9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Ceff9->GetYaxis()->GetNbins();j++) {
	  Diffe_Depth1_HE9->SetBinContent(i,j,0.);
	  if(Ceff9->GetBinContent(i,j) !=0 && Czeff9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Czeff9->GetBinContent(i,j)/Ceff9->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Ceff9->GetBinContent(i,j)   -   Czeff9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Ceff9->GetBinContent(i,j);
	    //if(fabs(ccc1) > 2.)  Diffe_Depth1_HE9->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth1_HE9->SetBinContent(i,j,fabs(ccc1));
	  }
	}
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HE9->SetMarkerStyle(20);
    Diffe_Depth1_HE9->SetMarkerSize(0.4);
    Diffe_Depth1_HE9->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth1_HE9->SetTitle("any Error, HE Depth1 \n");
    Diffe_Depth1_HE9->SetXTitle("#eta");
    Diffe_Depth1_HE9->SetYTitle("#phi");
    Diffe_Depth1_HE9->SetZTitle("|A2/A1| -  Depth1_HE");
    Diffe_Depth1_HE9->SetMarkerColor(2);
    Diffe_Depth1_HE9->SetLineColor(2);
    Diffe_Depth1_HE9->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth1_HE9 = new TH1F("diffAmpl_Depth1_HE9","", 100, 0., 2.);
 
      for (int i=1;i<=Ceff9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Ceff9->GetYaxis()->GetNbins();j++) {
	  if(Ceff9->GetBinContent(i,j) !=0 && Czeff9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Czeff9->GetBinContent(i,j)/Ceff9->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Ceff9->GetBinContent(i,j)   -   Czeff9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Ceff9->GetBinContent(i,j);
	    diffAmpl_Depth1_HE9->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth1_HE9->SetMarkerStyle(20);
      diffAmpl_Depth1_HE9->SetMarkerSize(0.4);
      diffAmpl_Depth1_HE9->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth1_HE9->SetTitle("AmplRunsDifference Depth1_HE \n");
      diffAmpl_Depth1_HE9->SetXTitle("|A2/A1| - Depth1_HE");
      diffAmpl_Depth1_HE9->SetMarkerColor(2);
      diffAmpl_Depth1_HE9->SetLineColor(2);
      diffAmpl_Depth1_HE9->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *poqa19= (TH2F*)hfile1->Get("h_mapDepth2RADDAM5_HE");
      TH2F *poqa09= (TH2F*)hfile1->Get("h_mapDepth2RADDAM6_HE");
      poqa19->Sumw2();
      poqa09->Sumw2();
      //    if(poqa0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cfrr9 = (TH2F*)poqa19->Clone("Cfrr9");
	Cfrr9->Divide(poqa19,poqa09, 1, 1, "B");
	Cfrr9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cfrr9->SetMarkerStyle(20);
      Cfrr9->SetMarkerSize(0.4);
      Cfrr9->GetYaxis()->SetLabelSize(0.04);
      //    Cfrr9->SetTitle("any Error, HE Depth2 \n");
      Cfrr9->SetXTitle("#eta");
      Cfrr9->SetYTitle("#phi");
      Cfrr9->SetZTitle("Ratio for 1st Run - HE Depth2");
      Cfrr9->SetMarkerColor(2);
      Cfrr9->SetLineColor(2);
      Cfrr9->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *trwp19 = (TH2F*)hfile2->Get("h_mapDepth2RADDAM5_HE");
      TH2F *trwp09 = (TH2F*)hfile2->Get("h_mapDepth2RADDAM6_HE");
      trwp19->Sumw2();
      trwp09->Sumw2();
      //    if(trwp0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cpoir9 = (TH2F*)trwp19->Clone("Cpoir9");
	Cpoir9->Divide(trwp19,trwp09, 1, 1, "B");
	Cpoir9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cpoir9->SetMarkerStyle(20);
      Cpoir9->SetMarkerSize(0.4);
      Cpoir9->GetYaxis()->SetLabelSize(0.04);
      //    Cpoir9->SetTitle("any Error, HE Depth2 \n");
      Cpoir9->SetXTitle("#eta");
      Cpoir9->SetYTitle("#phi");
      Cpoir9->SetZTitle("Ratio for 2nd Run - HE Depth2");
      Cpoir9->SetMarkerColor(2);
      Cpoir9->SetLineColor(2);
      Cpoir9->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      TH2F* Diffe_Depth2_HE9 = (TH2F*)Cfrr9->Clone("Diffe_Depth2_HE9");
      for (int i=1;i<=Cfrr9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cfrr9->GetYaxis()->GetNbins();j++) {
	  Diffe_Depth2_HE9->SetBinContent(i,j,0.);
	  if(Cfrr9->GetBinContent(i,j) !=0 && Cpoir9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpoir9->GetBinContent(i,j)/Cfrr9->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Cfrr9->GetBinContent(i,j)   -   Cpoir9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cfrr9->GetBinContent(i,j);
	    //if(fabs(ccc1) > 2.)  Diffe_Depth2_HE9->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth2_HE9->SetBinContent(i,j,fabs(ccc1));
	  }
	}
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth2_HE9->SetMarkerStyle(20);
    Diffe_Depth2_HE9->SetMarkerSize(0.4);
    Diffe_Depth2_HE9->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth2_HE9->SetTitle("any Error, HE Depth2 \n");
    Diffe_Depth2_HE9->SetXTitle("#eta");
    Diffe_Depth2_HE9->SetYTitle("#phi");
    Diffe_Depth2_HE9->SetZTitle("|A2/A1| -  Depth2_HE");
    Diffe_Depth2_HE9->SetMarkerColor(2);
    Diffe_Depth2_HE9->SetLineColor(2);
    Diffe_Depth2_HE9->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth2_HE9 = new TH1F("diffAmpl_Depth2_HE9","", 100, 0., 2.);
 
      for (int i=1;i<=Cfrr9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cfrr9->GetYaxis()->GetNbins();j++) {
	  if(Cfrr9->GetBinContent(i,j) !=0 && Cpoir9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpoir9->GetBinContent(i,j)/Cfrr9->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Cfrr9->GetBinContent(i,j)   -   Cpoir9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cfrr9->GetBinContent(i,j);
	    diffAmpl_Depth2_HE9->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth2_HE9->SetMarkerStyle(20);
      diffAmpl_Depth2_HE9->SetMarkerSize(0.4);
      diffAmpl_Depth2_HE9->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth2_HE9->SetTitle("AmplRunsDifference Depth2_HE \n");
      diffAmpl_Depth2_HE9->SetXTitle("|A2/A1| - Depth2_HE");
      diffAmpl_Depth2_HE9->SetMarkerColor(2);
      diffAmpl_Depth2_HE9->SetLineColor(2);
      diffAmpl_Depth2_HE9->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *lder19= (TH2F*)hfile1->Get("h_mapDepth3RADDAM5_HE");
      TH2F *lder09= (TH2F*)hfile1->Get("h_mapDepth3RADDAM6_HE");
      lder19->Sumw2();
      lder09->Sumw2();
      //    if(lder0->IsA()->InheritsFrom("TH2F")){
	TH2F* Crdsa9 = (TH2F*)lder19->Clone("Crdsa9");
	Crdsa9->Divide(lder19,lder09, 1, 1, "B");
	Crdsa9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Crdsa9->SetMarkerStyle(20);
      Crdsa9->SetMarkerSize(0.4);
      Crdsa9->GetYaxis()->SetLabelSize(0.04);
      //    Crdsa9->SetTitle("any Error, HE Depth3 \n");
      Crdsa9->SetXTitle("#eta");
      Crdsa9->SetYTitle("#phi");
      Crdsa9->SetZTitle("Ratio for 1st Run - HE Depth3");
      Crdsa9->SetMarkerColor(2);
      Crdsa9->SetLineColor(2);
      Crdsa9->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *jnmm19 = (TH2F*)hfile2->Get("h_mapDepth3RADDAM5_HE");
      TH2F *jnmm09 = (TH2F*)hfile2->Get("h_mapDepth3RADDAM6_HE");
      jnmm19->Sumw2();
      jnmm09->Sumw2();
      //    if(jnmm0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cpfff9 = (TH2F*)jnmm19->Clone("Cpfff9");
	Cpfff9->Divide(jnmm19,jnmm09, 1, 1, "B");
	Cpfff9->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cpfff9->SetMarkerStyle(20);
      Cpfff9->SetMarkerSize(0.4);
      Cpfff9->GetYaxis()->SetLabelSize(0.04);
      //    Cpfff9->SetTitle("any Error, HE Depth3 \n");
      Cpfff9->SetXTitle("#eta");
      Cpfff9->SetYTitle("#phi");
      Cpfff9->SetZTitle("Ratio for 2nd Run - HE Depth3");
      Cpfff9->SetMarkerColor(2);
      Cpfff9->SetLineColor(2);
      Cpfff9->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      TH2F* Diffe_Depth3_HE9 = (TH2F*)Crdsa9->Clone("Diffe_Depth3_HE9");
      for (int i=1;i<=Crdsa9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Crdsa9->GetYaxis()->GetNbins();j++) {
	  Diffe_Depth3_HE9->SetBinContent(i,j,0.);
	  if(Crdsa9->GetBinContent(i,j) !=0 && Cpfff9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpfff9->GetBinContent(i,j)/Crdsa9->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Crdsa9->GetBinContent(i,j)   -   Cpfff9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Crdsa9->GetBinContent(i,j);
	    //if(fabs(ccc1) > 2.)  Diffe_Depth3_HE9->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth3_HE9->SetBinContent(i,j,fabs(ccc1));
	  }
	}
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth3_HE9->SetMarkerStyle(20);
    Diffe_Depth3_HE9->SetMarkerSize(0.4);
    Diffe_Depth3_HE9->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth3_HE9->SetTitle("any Error, HE Depth3 \n");
    Diffe_Depth3_HE9->SetXTitle("#eta");
    Diffe_Depth3_HE9->SetYTitle("#phi");
    Diffe_Depth3_HE9->SetZTitle("|A2/A1| -  Depth3_HE");
    Diffe_Depth3_HE9->SetMarkerColor(2);
    Diffe_Depth3_HE9->SetLineColor(2);
    Diffe_Depth3_HE9->Draw("COLZ");
      c1->cd(4);
      TH1F* diffAmpl_Depth3_HE9 = new TH1F("diffAmpl_Depth3_HE9","", 100, 0., 2.);
      for (int i=1;i<=Crdsa9->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Crdsa9->GetYaxis()->GetNbins();j++) {
	  if(Crdsa9->GetBinContent(i,j) !=0 && Cpfff9->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpfff9->GetBinContent(i,j)/Crdsa9->GetBinContent(i,j)  ;
	    //double ccc1 =  Crdsa9->GetBinContent(i,j)   -   Cpfff9->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Crdsa9->GetBinContent(i,j);
	    diffAmpl_Depth3_HE9->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth3_HE9->SetMarkerStyle(20);
      diffAmpl_Depth3_HE9->SetMarkerSize(0.4);
      diffAmpl_Depth3_HE9->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth3_HE9->SetTitle("AmplRunsDifference Depth3_HE \n");
      diffAmpl_Depth3_HE9->SetXTitle("|A2/A1| - Depth3_HE");
      diffAmpl_Depth3_HE9->SetMarkerColor(2);
      diffAmpl_Depth3_HE9->SetLineColor(2);
      diffAmpl_Depth3_HE9->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      TH1F *Adiv16depth1= (TH1F*)hfile1->Get("h_Adiv16_Depth1RADDAM_HE");
      gPad->SetLogy();
      Adiv16depth1->SetMarkerStyle(20);
      Adiv16depth1->SetMarkerSize(0.8);
      Adiv16depth1->GetYaxis()->SetLabelSize(0.04);
      Adiv16depth1->SetXTitle("Adiv16_Depth1_HE \b");
      Adiv16depth1->SetMarkerColor(2);
      Adiv16depth1->SetLineColor(2);
      Adiv16depth1->Draw("");
      c1->cd(2);
      TH1F *Adiv16depth2= (TH1F*)hfile1->Get("h_Adiv16_Depth2RADDAM_HE");
      gPad->SetLogy();
      Adiv16depth2->SetMarkerStyle(20);
      Adiv16depth2->SetMarkerSize(0.8);
      Adiv16depth2->GetYaxis()->SetLabelSize(0.04);
      Adiv16depth2->SetXTitle("Adiv16_Depth2_HE \b");
      Adiv16depth2->SetMarkerColor(2);
      Adiv16depth2->SetLineColor(2);
      Adiv16depth2->Draw("");
      c1->cd(3);
      TH1F *Adiv16depth3= (TH1F*)hfile1->Get("h_Adiv16_Depth3RADDAM_HE");
      gPad->SetLogy();
      Adiv16depth3->SetMarkerStyle(20);
      Adiv16depth3->SetMarkerSize(0.8);
      Adiv16depth3->GetYaxis()->SetLabelSize(0.04);
      Adiv16depth3->SetXTitle("Adiv16_Depth3_HE \b");
      Adiv16depth3->SetMarkerColor(2);
      Adiv16depth3->SetLineColor(2);
      Adiv16depth3->Draw("");

      c1->Update();
    //============================================================================================= Layers:
    //======================================================================
    //============================================================================================= 5
    //======================   =============================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *player11= (TH1F*)hfile1->Get("h_mapLayer1RADDAM_HE");
      TH1F *player10= (TH1F*)hfile1->Get("h_mapLayer1RADDAM0_HE");
      player11->Sumw2();
      player10->Sumw2();
	TH1F* Clayer1 = (TH1F*)player11->Clone("Clayer1");
	Clayer1->Divide(player11,player10, 1, 1, "B");
	Clayer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //      gPad->SetLogz();
      Clayer1->SetMarkerStyle(20);
      Clayer1->SetMarkerSize(0.4);
      Clayer1->GetYaxis()->SetLabelSize(0.04);
      Clayer1->SetXTitle("L1Signal for 1st Run - HE     #eta");
      Clayer1->SetYTitle("Norm.Sig.");
      Clayer1->SetMarkerColor(2);
      Clayer1->SetLineColor(2);
      Clayer1->Draw("");
      
      c1->cd(2);
      TH1F *tlayer11= (TH1F*)hfile2->Get("h_mapLayer1RADDAM_HE");
      TH1F *tlayer10= (TH1F*)hfile2->Get("h_mapLayer1RADDAM0_HE");
      tlayer11->Sumw2();
      tlayer10->Sumw2();
	TH1F* Slayer1 = (TH1F*)tlayer11->Clone("Slayer1");
	Slayer1->Divide(tlayer11,tlayer10, 1, 1, "B");
	Slayer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      // gPad->SetLogz();
      Slayer1->SetMarkerStyle(20);
      Slayer1->SetMarkerSize(0.4);
      Slayer1->GetYaxis()->SetLabelSize(0.04);
      Slayer1->SetYTitle("Norm.Sig.");
      Slayer1->SetXTitle("L1Signal for 2ndt Run - HE     #eta");
      Slayer1->SetMarkerColor(2);
      Slayer1->SetLineColor(2);
      Slayer1->Draw("");
      
      c1->cd(3);
    ///////////////////////////////////////
      TH1F* Diffe_Layer1_HE = (TH1F*)Clayer1->Clone("Diffe_Layer1_HE");
      Diffe_Layer1_HE->Sumw2();
      for (int i=1;i<=Clayer1->GetXaxis()->GetNbins();i++) {
	Diffe_Layer1_HE->SetBinContent(i,0.);
	if(Clayer1->GetBinContent(i) !=0 && Slayer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slayer1->GetBinContent(i)/Clayer1->GetBinContent(i)  ;
	    //	  double ccc1 =  Clayer1->GetBinContent(i)-Slayer1->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Clayer1->GetBinContent(i);
	  //	    if(fabs(ccc1) > 2.)  Diffe_Layer1_HE->SetBinContent(i,fabs(ccc1));
	  Diffe_Layer1_HE->SetBinContent(i,fabs(ccc1));
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
    //gPad->SetLogz();
    Diffe_Layer1_HE->SetMarkerStyle(20);
    Diffe_Layer1_HE->SetMarkerSize(0.4);
    Diffe_Layer1_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Layer1_HE->SetXTitle("|A2/A1| -  L1_HE      #eta");
    Diffe_Layer1_HE->SetYTitle("|A2/A1|");
    Diffe_Layer1_HE->SetMarkerColor(2);
    Diffe_Layer1_HE->SetLineColor(2);
    Diffe_Layer1_HE->Draw("");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Layer1_HE = new TH1F("diffAmpl_Layer1_HE","", 100, 0., 2.);
      for (int i=1;i<=Clayer1->GetXaxis()->GetNbins();i++) {
	  if(Clayer1->GetBinContent(i) !=0 && Slayer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slayer1->GetBinContent(i)/Clayer1->GetBinContent(i)  ;
	    //	    double ccc1 =  Clayer1->GetBinContent(i)- Slayer1->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Clayer1->GetBinContent(i);
	    diffAmpl_Layer1_HE->Fill(fabs(ccc1));
	  }
      }
      gPad->SetLogy();
      diffAmpl_Layer1_HE->SetMarkerStyle(20);
      diffAmpl_Layer1_HE->SetMarkerSize(0.4);
      diffAmpl_Layer1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Layer1_HE->SetXTitle("|A2/A1| - L1_HE");
      diffAmpl_Layer1_HE->SetMarkerColor(2);
      diffAmpl_Layer1_HE->SetLineColor(2);
      diffAmpl_Layer1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 6
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *player21= (TH1F*)hfile1->Get("h_mapLayer2RADDAM_HE");
      TH1F *player20= (TH1F*)hfile1->Get("h_mapLayer2RADDAM0_HE");
      player21->Sumw2();
      player20->Sumw2();
	TH1F* Clayer2 = (TH1F*)player21->Clone("Clayer2");
	Clayer2->Divide(player21,player20, 1, 1, "B");
	Clayer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //gPad->SetLogz();
      Clayer2->SetMarkerStyle(20);
      Clayer2->SetMarkerSize(0.4);
      Clayer2->GetYaxis()->SetLabelSize(0.04);
      Clayer2->SetXTitle("L7Signal for 1st Run - HE    #eta");
      Clayer2->SetYTitle("Norm.Sig.");
      Clayer2->SetMarkerColor(2);
      Clayer2->SetLineColor(2);
      Clayer2->Draw("");
      
      c1->cd(2);
      TH1F *tlayer21= (TH1F*)hfile2->Get("h_mapLayer2RADDAM_HE");
      TH1F *tlayer20= (TH1F*)hfile2->Get("h_mapLayer2RADDAM0_HE");
      tlayer21->Sumw2();
      tlayer20->Sumw2();
	TH1F* Slayer2 = (TH1F*)tlayer21->Clone("Slayer2");
	Slayer2->Divide(tlayer21,tlayer20, 1, 1, "B");
	Slayer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //gPad->SetLogz();
      Slayer2->SetMarkerStyle(20);
      Slayer2->SetMarkerSize(0.4);
      Slayer2->GetYaxis()->SetLabelSize(0.04);
      Slayer2->SetXTitle("L7Signal for 2nd Run - HE      #eta");
      Slayer2->SetYTitle("Norm.Sig.");
      Slayer2->SetMarkerColor(2);
      Slayer2->SetLineColor(2);
      Slayer2->Draw("");
      
      c1->cd(3);
    ///////////////////////////////////////
      TH1F* Diffe_Layer2_HE = (TH1F*)Clayer2->Clone("Diffe_Layer2_HE");
      Diffe_Layer2_HE->Sumw2();
      for (int i=1;i<=Clayer2->GetXaxis()->GetNbins();i++) {
	Diffe_Layer2_HE->SetBinContent(i,0.);
	if(Clayer2->GetBinContent(i) !=0 && Slayer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slayer2->GetBinContent(i)/Clayer2->GetBinContent(i)  ;
	    //	  double ccc1 =  Clayer2->GetBinContent(i)-Slayer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Clayer2->GetBinContent(i);
	  //	  if(fabs(ccc1) > 2.)  Diffe_Layer2_HE->SetBinContent(i,fabs(ccc1));
	  Diffe_Layer2_HE->SetBinContent(i,fabs(ccc1));
	}
      }
      gPad->SetGridy();
    gPad->SetGridx();
    //gPad->SetLogz();
    Diffe_Layer2_HE->SetMarkerStyle(20);
    Diffe_Layer2_HE->SetMarkerSize(0.4);
    Diffe_Layer2_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Layer2_HE->SetXTitle("|A2/A1| -  L7_HE   #eta");
    Diffe_Layer2_HE->SetYTitle("|A2/A1|");
    Diffe_Layer2_HE->SetMarkerColor(2);
    Diffe_Layer2_HE->SetLineColor(2);
    Diffe_Layer2_HE->Draw("");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Layer2_HE = new TH1F("diffAmpl_Layer2_HE","", 100, 0., 2.);
      for (int i=1;i<=Clayer2->GetXaxis()->GetNbins();i++) {
	  if(Clayer2->GetBinContent(i) !=0 && Slayer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slayer2->GetBinContent(i)/Clayer2->GetBinContent(i)  ;
	    //double ccc1 =  Clayer2->GetBinContent(i)-Slayer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Clayer2->GetBinContent(i);
	    diffAmpl_Layer2_HE->Fill(fabs(ccc1));
	  }
      }
      gPad->SetLogy();
      diffAmpl_Layer2_HE->SetMarkerStyle(20);
      diffAmpl_Layer2_HE->SetMarkerSize(0.4);
      diffAmpl_Layer2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Layer2_HE->SetTitle("AmplRunsDifference Layer7_HE \n");
      diffAmpl_Layer2_HE->SetXTitle("|A2/A1| - Layer7_HE");
      diffAmpl_Layer2_HE->SetMarkerColor(2);
      diffAmpl_Layer2_HE->SetLineColor(2);
      diffAmpl_Layer2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 7
    //======================================================================
    //====================================================================== Ratio
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *plauer11= (TH1F*)hfile1->Get("h_mapLayer1RADDAM5_HE");
      TH1F *plauer10= (TH1F*)hfile1->Get("h_mapLayer1RADDAM6_HE");
      plauer11->Sumw2();
      plauer10->Sumw2();
      //    if(plauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Clauer1 = (TH1F*)plauer11->Clone("Clauer1");
	Clauer1->Divide(plauer11,plauer10, 1, 1, "B");
	Clauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      // gPad->SetLogz();
      Clauer1->SetMarkerStyle(20);
      Clauer1->SetMarkerSize(0.8);
      Clauer1->GetYaxis()->SetLabelSize(0.04);
      //    Clauer1->SetTitle("any Error, HE Layer1 \n");
      Clauer1->SetXTitle("L1 Ratio for 1st Run - HE #eta");
      Clauer1->SetYTitle("Ratio");
      Clauer1->SetMarkerColor(1);
      Clauer1->SetLineColor(1);
      Clauer1->SetMaximum(1.1);
      Clauer1->SetMinimum(0.8);
      Clauer1->Draw("");
      //    }
      
      c1->cd(2);
      TH1F *tlauer11= (TH1F*)hfile2->Get("h_mapLayer1RADDAM5_HE");
      TH1F *tlauer10= (TH1F*)hfile2->Get("h_mapLayer1RADDAM6_HE");
      tlauer11->Sumw2();
      tlauer10->Sumw2();
      //    if(tlauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Slauer1 = (TH1F*)tlauer11->Clone("Slauer1");
	Slauer1->Divide(tlauer11,tlauer10, 1, 1, "B");
	Slauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //  gPad->SetLogz();
      Slauer1->SetMarkerStyle(20);
      Slauer1->SetMarkerSize(0.8);
      Slauer1->GetYaxis()->SetLabelSize(0.04);
      //    Slauer1->SetTitle("any Error, HE Layer1 \n");
      Slauer1->SetXTitle("L1 Ratio for 2nd Run - HE #eta");
      Slauer1->SetYTitle("Ratio");
      Slauer1->SetMarkerColor(1);
      Slauer1->SetLineColor(1);
      Slauer1->SetMaximum(1.1);
      Slauer1->SetMinimum(0.8);
      Slauer1->Draw("");
      //    }
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Lauer1_HE = (TH1F*)Clauer1->Clone("Diffe_Lauer1_HE");
      Diffe_Lauer1_HE->Sumw2();
      for (int i=1;i<=Clauer1->GetXaxis()->GetNbins();i++) {
	  Diffe_Lauer1_HE->SetBinContent(i,0.);
	  if(Clauer1->GetBinContent(i) !=0 && Slauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slauer1->GetBinContent(i)/Clauer1->GetBinContent(i)  ;
	    //	    double ccc1 =  Clauer1->GetBinContent(i)-Slauer1->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Clauer1->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Lauer1_HE->SetBinContent(i,fabs(ccc1));
	    Diffe_Lauer1_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Lauer1_HE->SetMarkerStyle(20);
    Diffe_Lauer1_HE->SetMarkerSize(0.8);
    Diffe_Lauer1_HE->GetYaxis()->SetLabelSize(0.08);
    Diffe_Lauer1_HE->SetXTitle("|A2/A1| - L1_HE#eta");
    Diffe_Lauer1_HE->SetYTitle("|A2/A1|");
    Diffe_Lauer1_HE->SetMarkerColor(1);
    Diffe_Lauer1_HE->SetLineColor(1);
    Diffe_Lauer1_HE->Draw("");
    
    
    c1->cd(4);
    TH1F* diffAmpl_Lauer1_HE = new TH1F("diffAmpl_Lauer1_HE","", 100, 0., 2.);
    for (int i=1;i<=Clauer1->GetXaxis()->GetNbins();i++) {
      if(Clauer1->GetBinContent(i) !=0 && Slauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slauer1->GetBinContent(i)/Clauer1->GetBinContent(i)  ;
	    //double ccc1 =  Clauer1->GetBinContent(i)-Slauer1->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Clauer1->GetBinContent(i);
	diffAmpl_Lauer1_HE->Fill(fabs(ccc1));
      }
    }
    gPad->SetLogy();
      diffAmpl_Lauer1_HE->SetMarkerStyle(20);
      diffAmpl_Lauer1_HE->SetMarkerSize(0.4);
      diffAmpl_Lauer1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Lauer1_HE->SetTitle("AmplRunsDifference L1_HE \n");
      diffAmpl_Lauer1_HE->SetXTitle("|A2/A1| - L1_HE");
      diffAmpl_Lauer1_HE->SetMarkerColor(2);
      diffAmpl_Lauer1_HE->SetLineColor(2);
      diffAmpl_Lauer1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 8
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *plauer21= (TH1F*)hfile1->Get("h_mapLayer2RADDAM5_HE");
      TH1F *plauer20= (TH1F*)hfile1->Get("h_mapLayer2RADDAM6_HE");
      plauer21->Sumw2();
      plauer20->Sumw2();
	TH1F* Clauer2 = (TH1F*)plauer21->Clone("Clauer2");
	Clauer2->Divide(plauer21,plauer20, 1, 1, "B");
	Clauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Clauer2->SetMarkerStyle(20);
      Clauer2->SetMarkerSize(0.8);
      Clauer2->GetYaxis()->SetLabelSize(0.04);
      Clauer2->SetXTitle("L7 Ratio for 1st Run - HE  #eta");
      Clauer2->SetYTitle("Ratio");
      Clauer2->SetMarkerColor(2);
      Clauer2->SetLineColor(2);
      Clauer2->SetMaximum(1.1);
      Clauer2->SetMinimum(0.8);
      Clauer2->Draw("");
      
      c1->cd(2);
      TH1F *tlauer21= (TH1F*)hfile2->Get("h_mapLayer2RADDAM5_HE");
      TH1F *tlauer20= (TH1F*)hfile2->Get("h_mapLayer2RADDAM6_HE");
      tlauer21->Sumw2();
      tlauer20->Sumw2();
	TH1F* Slauer2 = (TH1F*)tlauer21->Clone("Slauer2");
	Slauer2->Divide(tlauer21,tlauer20, 1, 1, "B");
	Slauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Slauer2->SetMarkerStyle(20);
      Slauer2->SetMarkerSize(0.8);
      Slauer2->GetYaxis()->SetLabelSize(0.08);
      Slauer2->SetXTitle("L7 Ratio for 2nd Run - HE #eta");
      Slauer2->SetYTitle("Ratio");
      Slauer2->SetMarkerColor(2);
      Slauer2->SetLineColor(2);
      Slauer2->SetMaximum(1.1);
      Slauer2->SetMinimum(0.8);
      Slauer2->Draw("");
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Lauer2_HE = (TH1F*)Clauer2->Clone("Diffe_Lauer2_HE");
      Diffe_Lauer2_HE->Sumw2();
      for (int i=1;i<=Clauer2->GetXaxis()->GetNbins();i++) {
	  Diffe_Lauer2_HE->SetBinContent(i,0.);
	  if(Clauer2->GetBinContent(i) !=0 && Slauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slauer2->GetBinContent(i)/Clauer2->GetBinContent(i)  ;
	    //	    double ccc1 =  Clauer2->GetBinContent(i)-Slauer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Clauer2->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Lauer2_HE->SetBinContent(i,fabs(ccc1));
	    //	    std::cout <<"333333 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	    Diffe_Lauer2_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Lauer2_HE->SetMarkerStyle(20);
    Diffe_Lauer2_HE->SetMarkerSize(0.8);
    Diffe_Lauer2_HE->GetYaxis()->SetLabelSize(0.06);
    Diffe_Lauer2_HE->SetXTitle("|A2/A1| - L7_HE#eta");
    Diffe_Lauer2_HE->SetYTitle("|A2/A1|");
    Diffe_Lauer2_HE->SetMarkerColor(2);
    Diffe_Lauer2_HE->SetLineColor(2);
    Diffe_Lauer2_HE->Draw("");
    
    
    //    std::cout <<"============================================================ " << std::endl; 
      c1->cd(4);
      TH1F* diffAmpl_Lauer2_HE = new TH1F("diffAmpl_Lauer2_HE","", 100, 0., 2.);
      for (int i=1;i<=Clauer2->GetXaxis()->GetNbins();i++) {
	if(Clauer2->GetBinContent(i) !=0 && Slauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Slauer2->GetBinContent(i)/Clauer2->GetBinContent(i)  ;
	    //	  double ccc1 =  Clauer2->GetBinContent(i)-Slauer2->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Clauer2->GetBinContent(i);
	    //	    std::cout <<"444444 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	  diffAmpl_Lauer2_HE->Fill(fabs(ccc1));
	}
      }
      gPad->SetLogy();
      diffAmpl_Lauer2_HE->SetMarkerStyle(20);
      diffAmpl_Lauer2_HE->SetMarkerSize(0.4);
      diffAmpl_Lauer2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Lauer2_HE->SetTitle("AmplRunsDifference L7_HE \n");
      diffAmpl_Lauer2_HE->SetXTitle("|A2/A1| - L7_HE");
      diffAmpl_Lauer2_HE->SetMarkerColor(2);
      diffAmpl_Lauer2_HE->SetLineColor(2);
      diffAmpl_Lauer2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      Clauer1->Draw("");
      Clauer2->Draw("Same");

      c1->cd(2);
      Slauer1->Draw("");
      Slauer2->Draw("Same");

      c1->Update();

    //============================================================================================= 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      Diffe_Lauer1_HE->Draw("");
      Diffe_Lauer2_HE->Draw("Same");


      c1->Update();

    //============================================================================================= 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      TH1F *Adiv16layer1= (TH1F*)hfile1->Get("h_Adiv16_Layer1RADDAM_HE");
      gPad->SetLogy();
      Adiv16layer1->SetMarkerStyle(20);
      Adiv16layer1->SetMarkerSize(0.8);
      Adiv16layer1->GetYaxis()->SetLabelSize(0.04);
      Adiv16layer1->SetXTitle("Adiv16_L1_HE \b");
      Adiv16layer1->SetMarkerColor(2);
      Adiv16layer1->SetLineColor(2);
      Adiv16layer1->Draw("");
      c1->cd(2);
      TH1F *Adiv16layer2= (TH1F*)hfile1->Get("h_Adiv16_Layer2RADDAM_HE");
      gPad->SetLogy();
      Adiv16layer2->SetMarkerStyle(20);
      Adiv16layer2->SetMarkerSize(0.8);
      Adiv16layer2->GetYaxis()->SetLabelSize(0.04);
      Adiv16layer2->SetXTitle("Adiv16_L7_HE \b");
      Adiv16layer2->SetMarkerColor(2);
      Adiv16layer2->SetLineColor(2);
      Adiv16layer2->Draw("");

      c1->Update();


    //======================================================================
    //============================================================================================= sigLayers:
    //======================================================================
    //============================================================================================= 12
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglayer11= (TH1F*)hfile1->Get("h_sigLayer1RADDAM_HE");
      TH1F *psiglayer10= (TH1F*)hfile1->Get("h_sigLayer1RADDAM0_HE");
      psiglayer11->Sumw2();
      psiglayer10->Sumw2();
	TH1F* Csiglayer1 = (TH1F*)psiglayer11->Clone("Csiglayer1");
	Csiglayer1->Divide(psiglayer11,psiglayer10, 1, 1, "B");
	Csiglayer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //      gPad->SetLogz();
      Csiglayer1->SetMarkerStyle(20);
      Csiglayer1->SetMarkerSize(0.4);
      Csiglayer1->GetYaxis()->SetLabelSize(0.04);
      Csiglayer1->SetXTitle("L1Signal for 1st Run - HE     #eta");
      Csiglayer1->SetYTitle("Norm.Sig.");
      Csiglayer1->SetMarkerColor(2);
      Csiglayer1->SetLineColor(2);
      Csiglayer1->Draw("");
      
      c1->cd(2);
      TH1F *tsiglayer11= (TH1F*)hfile2->Get("h_sigLayer1RADDAM_HE");
      TH1F *tsiglayer10= (TH1F*)hfile2->Get("h_sigLayer1RADDAM0_HE");
      tsiglayer11->Sumw2();
      tsiglayer10->Sumw2();
	TH1F* Ssiglayer1 = (TH1F*)tsiglayer11->Clone("Ssiglayer1");
	Ssiglayer1->Divide(tsiglayer11,tsiglayer10, 1, 1, "B");
	Ssiglayer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      // gPad->SetLogz();
      Ssiglayer1->SetMarkerStyle(20);
      Ssiglayer1->SetMarkerSize(0.4);
      Ssiglayer1->GetYaxis()->SetLabelSize(0.04);
      Ssiglayer1->SetYTitle("Norm.Sig.");
      Ssiglayer1->SetXTitle("L1Signal for 2ndt Run - HE     #eta");
      Ssiglayer1->SetMarkerColor(2);
      Ssiglayer1->SetLineColor(2);
      Ssiglayer1->Draw("");
      
      c1->cd(3);
    ///////////////////////////////////////
      TH1F* Diffe_Siglayer1_HE = (TH1F*)Csiglayer1->Clone("Diffe_Siglayer1_HE");
      Diffe_Siglayer1_HE->Sumw2();
      for (int i=1;i<=Csiglayer1->GetXaxis()->GetNbins();i++) {
	Diffe_Siglayer1_HE->SetBinContent(i,0.);
	if(Csiglayer1->GetBinContent(i) !=0 && Ssiglayer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglayer1->GetBinContent(i)/Csiglayer1->GetBinContent(i)  ;
	    //	  double ccc1 =  Csiglayer1->GetBinContent(i)-Ssiglayer1->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Csiglayer1->GetBinContent(i);
	  //	    if(fabs(ccc1) > 2.)  Diffe_Siglayer1_HE->SetBinContent(i,fabs(ccc1));
	  Diffe_Siglayer1_HE->SetBinContent(i,fabs(ccc1));
	}
      }
      gPad->SetGridy();
      gPad->SetGridx();
    //gPad->SetLogz();
    Diffe_Siglayer1_HE->SetMarkerStyle(20);
    Diffe_Siglayer1_HE->SetMarkerSize(0.4);
    Diffe_Siglayer1_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Siglayer1_HE->SetXTitle("|A2/A1| -  L1_HE      #eta");
    Diffe_Siglayer1_HE->SetYTitle("|A2/A1|");
    Diffe_Siglayer1_HE->SetMarkerColor(2);
    Diffe_Siglayer1_HE->SetLineColor(2);
    Diffe_Siglayer1_HE->Draw("");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Siglayer1_HE = new TH1F("diffAmpl_Siglayer1_HE","", 100, 0., 2.);
      for (int i=1;i<=Csiglayer1->GetXaxis()->GetNbins();i++) {
	  if(Csiglayer1->GetBinContent(i) !=0 && Ssiglayer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglayer1->GetBinContent(i)/Csiglayer1->GetBinContent(i)  ;
	    //	    double ccc1 =  Csiglayer1->GetBinContent(i)- Ssiglayer1->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Csiglayer1->GetBinContent(i);
	    diffAmpl_Siglayer1_HE->Fill(fabs(ccc1));
	  }
      }
      gPad->SetLogy();
      diffAmpl_Siglayer1_HE->SetMarkerStyle(20);
      diffAmpl_Siglayer1_HE->SetMarkerSize(0.4);
      diffAmpl_Siglayer1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Siglayer1_HE->SetXTitle("|A2/A1| - L1_HE");
      diffAmpl_Siglayer1_HE->SetMarkerColor(2);
      diffAmpl_Siglayer1_HE->SetLineColor(2);
      diffAmpl_Siglayer1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 13
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglayer21= (TH1F*)hfile1->Get("h_sigLayer2RADDAM_HE");
      TH1F *psiglayer20= (TH1F*)hfile1->Get("h_sigLayer2RADDAM0_HE");
      psiglayer21->Sumw2();
      psiglayer20->Sumw2();
	TH1F* Csiglayer2 = (TH1F*)psiglayer21->Clone("Csiglayer2");
	Csiglayer2->Divide(psiglayer21,psiglayer20, 1, 1, "B");
	Csiglayer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //gPad->SetLogz();
      Csiglayer2->SetMarkerStyle(20);
      Csiglayer2->SetMarkerSize(0.4);
      Csiglayer2->GetYaxis()->SetLabelSize(0.04);
      Csiglayer2->SetXTitle("L7Signal for 1st Run - HE    #eta");
      Csiglayer2->SetYTitle("Norm.Sig.");
      Csiglayer2->SetMarkerColor(2);
      Csiglayer2->SetLineColor(2);
      Csiglayer2->Draw("");
      
      c1->cd(2);
      TH1F *tsiglayer21= (TH1F*)hfile2->Get("h_sigLayer2RADDAM_HE");
      TH1F *tsiglayer20= (TH1F*)hfile2->Get("h_sigLayer2RADDAM0_HE");
      tsiglayer21->Sumw2();
      tsiglayer20->Sumw2();
	TH1F* Ssiglayer2 = (TH1F*)tsiglayer21->Clone("Ssiglayer2");
	Ssiglayer2->Divide(tsiglayer21,tsiglayer20, 1, 1, "B");
	Ssiglayer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //gPad->SetLogz();
      Ssiglayer2->SetMarkerStyle(20);
      Ssiglayer2->SetMarkerSize(0.4);
      Ssiglayer2->GetYaxis()->SetLabelSize(0.04);
      Ssiglayer2->SetXTitle("L7Signal for 2nd Run - HE      #eta");
      Ssiglayer2->SetYTitle("Norm.Sig.");
      Ssiglayer2->SetMarkerColor(2);
      Ssiglayer2->SetLineColor(2);
      Ssiglayer2->Draw("");
      
      c1->cd(3);
    ///////////////////////////////////////
      TH1F* Diffe_Siglayer2_HE = (TH1F*)Csiglayer2->Clone("Diffe_Siglayer2_HE");
      Diffe_Siglayer2_HE->Sumw2();
      for (int i=1;i<=Csiglayer2->GetXaxis()->GetNbins();i++) {
	Diffe_Siglayer2_HE->SetBinContent(i,0.);
	if(Csiglayer2->GetBinContent(i) !=0 && Ssiglayer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglayer2->GetBinContent(i)/Csiglayer2->GetBinContent(i)  ;
	    //	  double ccc1 =  Csiglayer2->GetBinContent(i)-Ssiglayer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Csiglayer2->GetBinContent(i);
	  //	  if(fabs(ccc1) > 2.)  Diffe_Siglayer2_HE->SetBinContent(i,fabs(ccc1));
	  Diffe_Siglayer2_HE->SetBinContent(i,fabs(ccc1));
	}
      }
      gPad->SetGridy();
    gPad->SetGridx();
    //gPad->SetLogz();
    Diffe_Siglayer2_HE->SetMarkerStyle(20);
    Diffe_Siglayer2_HE->SetMarkerSize(0.4);
    Diffe_Siglayer2_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Siglayer2_HE->SetXTitle("|A2/A1| -  L7_HE   #eta");
    Diffe_Siglayer2_HE->SetYTitle("|A2/A1|");
    Diffe_Siglayer2_HE->SetMarkerColor(2);
    Diffe_Siglayer2_HE->SetLineColor(2);
    Diffe_Siglayer2_HE->Draw("");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Siglayer2_HE = new TH1F("diffAmpl_Siglayer2_HE","", 100, 0., 2.);
      for (int i=1;i<=Csiglayer2->GetXaxis()->GetNbins();i++) {
	  if(Csiglayer2->GetBinContent(i) !=0 && Ssiglayer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglayer2->GetBinContent(i)/Csiglayer2->GetBinContent(i)  ;
	    //double ccc1 =  Csiglayer2->GetBinContent(i)-Ssiglayer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Csiglayer2->GetBinContent(i);
	    diffAmpl_Siglayer2_HE->Fill(fabs(ccc1));
	  }
      }
      gPad->SetLogy();
      diffAmpl_Siglayer2_HE->SetMarkerStyle(20);
      diffAmpl_Siglayer2_HE->SetMarkerSize(0.4);
      diffAmpl_Siglayer2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Siglayer2_HE->SetTitle("AmplRunsDifference Siglayer7_HE \n");
      diffAmpl_Siglayer2_HE->SetXTitle("|A2/A1| - Siglayer7_HE");
      diffAmpl_Siglayer2_HE->SetMarkerColor(2);
      diffAmpl_Siglayer2_HE->SetLineColor(2);
      diffAmpl_Siglayer2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 14
    //======================================================================
    //====================================================================== Ratio
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglauer11= (TH1F*)hfile1->Get("h_sigLayer1RADDAM5_HE");
      TH1F *psiglauer10= (TH1F*)hfile1->Get("h_sigLayer1RADDAM6_HE");
      psiglauer11->Sumw2();
      psiglauer10->Sumw2();
      //    if(psiglauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Csiglauer1 = (TH1F*)psiglauer11->Clone("Csiglauer1");
	Csiglauer1->Divide(psiglauer11,psiglauer10, 1, 1, "B");
	Csiglauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      // gPad->SetLogz();
      Csiglauer1->SetMarkerStyle(20);
      Csiglauer1->SetMarkerSize(0.8);
      Csiglauer1->GetYaxis()->SetLabelSize(0.04);
      //    Csiglauer1->SetTitle("any Error, HE Siglayer1 \n");
      Csiglauer1->SetXTitle("L1 Ratio for 1st Run - HE #eta");
      Csiglauer1->SetYTitle("Ratio");
      Csiglauer1->SetMarkerColor(1);
      Csiglauer1->SetLineColor(1);
      Csiglauer1->SetMaximum(1.1);
      Csiglauer1->SetMinimum(0.5);
      Csiglauer1->Draw("");
      //    }
      
      c1->cd(2);
      TH1F *tsiglauer11= (TH1F*)hfile2->Get("h_sigLayer1RADDAM5_HE");
      TH1F *tsiglauer10= (TH1F*)hfile2->Get("h_sigLayer1RADDAM6_HE");
      tsiglauer11->Sumw2();
      tsiglauer10->Sumw2();
      //    if(tsiglauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Ssiglauer1 = (TH1F*)tsiglauer11->Clone("Ssiglauer1");
	Ssiglauer1->Divide(tsiglauer11,tsiglauer10, 1, 1, "B");
	Ssiglauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //  gPad->SetLogz();
      Ssiglauer1->SetMarkerStyle(20);
      Ssiglauer1->SetMarkerSize(0.8);
      Ssiglauer1->GetYaxis()->SetLabelSize(0.04);
      //    Ssiglauer1->SetTitle("any Error, HE Siglayer1 \n");
      Ssiglauer1->SetXTitle("L1 Ratio for 2nd Run - HE #eta");
      Ssiglauer1->SetYTitle("Ratio");
      Ssiglauer1->SetMarkerColor(1);
      Ssiglauer1->SetLineColor(1);
      Ssiglauer1->SetMaximum(1.1);
      Ssiglauer1->SetMinimum(0.5);
      Ssiglauer1->Draw("");
      //    }
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Siglauer1_HE = (TH1F*)Csiglauer1->Clone("Diffe_Siglauer1_HE");
      Diffe_Siglauer1_HE->Sumw2();
      for (int i=1;i<=Csiglauer1->GetXaxis()->GetNbins();i++) {
	  Diffe_Siglauer1_HE->SetBinContent(i,0.);
	  if(Csiglauer1->GetBinContent(i) !=0 && Ssiglauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglauer1->GetBinContent(i)/Csiglauer1->GetBinContent(i)  ;
	    //	    double ccc1 =  Csiglauer1->GetBinContent(i)-Ssiglauer1->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Csiglauer1->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Siglauer1_HE->SetBinContent(i,fabs(ccc1));
	    Diffe_Siglauer1_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Siglauer1_HE->SetMarkerStyle(20);
    Diffe_Siglauer1_HE->SetMarkerSize(0.8);
    Diffe_Siglauer1_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Siglauer1_HE->SetXTitle("|A2/A1| - L1_HE#eta");
    Diffe_Siglauer1_HE->SetYTitle("|A2/A1|");
    Diffe_Siglauer1_HE->SetMarkerColor(1);
    Diffe_Siglauer1_HE->SetLineColor(1);
    Diffe_Siglauer1_HE->Draw("");
    
    
    c1->cd(4);
    TH1F* diffAmpl_Siglauer1_HE = new TH1F("diffAmpl_Siglauer1_HE","", 100, 0., 2.);
    for (int i=1;i<=Csiglauer1->GetXaxis()->GetNbins();i++) {
      if(Csiglauer1->GetBinContent(i) !=0 && Ssiglauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglauer1->GetBinContent(i)/Csiglauer1->GetBinContent(i)  ;
	    //double ccc1 =  Csiglauer1->GetBinContent(i)-Ssiglauer1->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Csiglauer1->GetBinContent(i);
	diffAmpl_Siglauer1_HE->Fill(fabs(ccc1));
      }
    }
    gPad->SetLogy();
      diffAmpl_Siglauer1_HE->SetMarkerStyle(20);
      diffAmpl_Siglauer1_HE->SetMarkerSize(0.4);
      diffAmpl_Siglauer1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Siglauer1_HE->SetTitle("AmplRunsDifference L1_HE \n");
      diffAmpl_Siglauer1_HE->SetXTitle("|A2/A1| - L1_HE");
      diffAmpl_Siglauer1_HE->SetMarkerColor(2);
      diffAmpl_Siglauer1_HE->SetLineColor(2);
      diffAmpl_Siglauer1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 15
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglauer21= (TH1F*)hfile1->Get("h_sigLayer2RADDAM5_HE");
      TH1F *psiglauer20= (TH1F*)hfile1->Get("h_sigLayer2RADDAM6_HE");
      psiglauer21->Sumw2();
      psiglauer20->Sumw2();
	TH1F* Csiglauer2 = (TH1F*)psiglauer21->Clone("Csiglauer2");
	Csiglauer2->Divide(psiglauer21,psiglauer20, 1, 1, "B");
	Csiglauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Csiglauer2->SetMarkerStyle(20);
      Csiglauer2->SetMarkerSize(0.8);
      Csiglauer2->GetYaxis()->SetLabelSize(0.04);
      Csiglauer2->SetXTitle("L7 Ratio for 1st Run - HE  #eta");
      Csiglauer2->SetYTitle("Ratio");
      Csiglauer2->SetMarkerColor(2);
      Csiglauer2->SetLineColor(2);
      Csiglauer2->SetMaximum(1.1);
      Csiglauer2->SetMinimum(0.5);
      Csiglauer2->Draw("");
      
      c1->cd(2);
      TH1F *tsiglauer21= (TH1F*)hfile2->Get("h_sigLayer2RADDAM5_HE");
      TH1F *tsiglauer20= (TH1F*)hfile2->Get("h_sigLayer2RADDAM6_HE");
      tsiglauer21->Sumw2();
      tsiglauer20->Sumw2();
	TH1F* Ssiglauer2 = (TH1F*)tsiglauer21->Clone("Ssiglauer2");
	Ssiglauer2->Divide(tsiglauer21,tsiglauer20, 1, 1, "B");
	Ssiglauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Ssiglauer2->SetMarkerStyle(20);
      Ssiglauer2->SetMarkerSize(0.8);
      Ssiglauer2->GetYaxis()->SetLabelSize(0.04);
      Ssiglauer2->SetXTitle("L7 Ratio for 2nd Run - HE #eta");
      Ssiglauer2->SetYTitle("Ratio");
      Ssiglauer2->SetMarkerColor(2);
      Ssiglauer2->SetLineColor(2);
      Ssiglauer2->SetMaximum(1.1);
      Ssiglauer2->SetMinimum(0.5);
      Ssiglauer2->Draw("");
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Siglauer2_HE = (TH1F*)Csiglauer2->Clone("Diffe_Siglauer2_HE");
      Diffe_Siglauer2_HE->Sumw2();
      for (int i=1;i<=Csiglauer2->GetXaxis()->GetNbins();i++) {
	  Diffe_Siglauer2_HE->SetBinContent(i,0.);
	  if(Csiglauer2->GetBinContent(i) !=0 && Ssiglauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglauer2->GetBinContent(i)/Csiglauer2->GetBinContent(i)  ;
	    //	    double ccc1 =  Csiglauer2->GetBinContent(i)-Ssiglauer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Csiglauer2->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Siglauer2_HE->SetBinContent(i,fabs(ccc1));
	    //	    std::cout <<"333333 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	    Diffe_Siglauer2_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Siglauer2_HE->SetMarkerStyle(20);
    Diffe_Siglauer2_HE->SetMarkerSize(0.8);
    Diffe_Siglauer2_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Siglauer2_HE->SetXTitle("|A2/A1| - L7_HE#eta");
    Diffe_Siglauer2_HE->SetYTitle("|A2/A1|");
    Diffe_Siglauer2_HE->SetMarkerColor(2);
    Diffe_Siglauer2_HE->SetLineColor(2);
    Diffe_Siglauer2_HE->Draw("");
    
    
    //    std::cout <<"============================================================ " << std::endl; 
      c1->cd(4);
      TH1F* diffAmpl_Siglauer2_HE = new TH1F("diffAmpl_Siglauer2_HE","", 100, 0., 2.);
      for (int i=1;i<=Csiglauer2->GetXaxis()->GetNbins();i++) {
	if(Csiglauer2->GetBinContent(i) !=0 && Ssiglauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Ssiglauer2->GetBinContent(i)/Csiglauer2->GetBinContent(i)  ;
	    //	  double ccc1 =  Csiglauer2->GetBinContent(i)-Ssiglauer2->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Csiglauer2->GetBinContent(i);
	    //	    std::cout <<"444444 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	  diffAmpl_Siglauer2_HE->Fill(fabs(ccc1));
	}
      }
      gPad->SetLogy();
      diffAmpl_Siglauer2_HE->SetMarkerStyle(20);
      diffAmpl_Siglauer2_HE->SetMarkerSize(0.4);
      diffAmpl_Siglauer2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Siglauer2_HE->SetTitle("AmplRunsDifference L7_HE \n");
      diffAmpl_Siglauer2_HE->SetXTitle("|A2/A1| - L7_HE");
      diffAmpl_Siglauer2_HE->SetMarkerColor(2);
      diffAmpl_Siglauer2_HE->SetLineColor(2);
      diffAmpl_Siglauer2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      Csiglauer1->Draw("");
      Csiglauer2->Draw("Same");

      c1->cd(2);
      Ssiglauer1->Draw("");
      Ssiglauer2->Draw("Same");

      c1->Update();


    //============================================================================================= 17
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      Diffe_Siglauer1_HE->Draw("");
      Diffe_Siglauer2_HE->Draw("Same");


      c1->Update();

     //======================================================================
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
