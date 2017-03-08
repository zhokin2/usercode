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

	TFile *hfile1= new TFile("LED_280702.root", "READ");        
	TFile *hfile2= new TFile("LED_287824.root", "READ");



	//    getchar();
	//
          TPostScript psfile ("zdifampl.ps", 111);
//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //============================================================================================= 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1AmplE34_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      //    if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
      //    Ceff->SetTitle("any Error, HB Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Signal for 1st Run - HB Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *tqod1= (TH2F*)hfile2->Get("h_mapDepth1AmplE34_HB");
      TH2F *tqod0= (TH2F*)hfile2->Get("h_mapDepth1_HB");
      tqod1->Sumw2();
      tqod0->Sumw2();
      //    if(tqod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Czeff = (TH2F*)tqod1->Clone("Czeff");
	Czeff->Divide(tqod1,tqod0, 1, 1, "B");
	Czeff->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Czeff->SetMarkerStyle(20);
      Czeff->SetMarkerSize(0.4);
      Czeff->GetYaxis()->SetLabelSize(0.04);
      //    Czeff->SetTitle("any Error, HB Depth1 \n");
      Czeff->SetXTitle("#eta");
      Czeff->SetYTitle("#phi");
      Czeff->SetZTitle("Signal for 2nd Run - HB Depth1");
      Czeff->SetMarkerColor(2);
      Czeff->SetLineColor(2);
      Czeff->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      //    TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
      TH2F* Diffe_Depth1_HB = (TH2F*)Ceff->Clone("Diffe_Depth1_HB");
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  Diffe_Depth1_HB->SetBinContent(i,j,0.);
	  if(Ceff->GetBinContent(i,j) !=0 && Czeff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j)   -   Czeff->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	    if(fabs(ccc1) > 2.)  Diffe_Depth1_HB->SetBinContent(i,j,fabs(ccc1));
	  }
	}
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HB->SetMarkerStyle(20);
    Diffe_Depth1_HB->SetMarkerSize(0.4);
    Diffe_Depth1_HB->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth1_HB->SetTitle("any Error, HB Depth1 \n");
    Diffe_Depth1_HB->SetXTitle("#eta");
    Diffe_Depth1_HB->SetYTitle("#phi");
    Diffe_Depth1_HB->SetZTitle("Relative Difference in % - Depth1_HB");
    Diffe_Depth1_HB->SetMarkerColor(2);
    Diffe_Depth1_HB->SetLineColor(2);
    Diffe_Depth1_HB->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth1_HB = new TH1F("diffAmpl_Depth1_HB","", 100, -10., 10.);
 
      for (int i=1;i<=Ceff->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Ceff->GetYaxis()->GetNbins();j++) {
	  if(Ceff->GetBinContent(i,j) !=0 && Czeff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j)   -   Czeff->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	    diffAmpl_Depth1_HB->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth1_HB->SetMarkerStyle(20);
      diffAmpl_Depth1_HB->SetMarkerSize(0.4);
      diffAmpl_Depth1_HB->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth1_HB->SetTitle("AmplRunsDifference Depth1_HB \n");
      diffAmpl_Depth1_HB->SetXTitle("Relative Difference, % - Depth1_HB");
      diffAmpl_Depth1_HB->SetMarkerColor(2);
      diffAmpl_Depth1_HB->SetLineColor(2);
      diffAmpl_Depth1_HB->Draw("");
      
      c1->Update();
      
      
            
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *oyxz1= (TH2F*)hfile1->Get("h_mapDepth2AmplE34_HB");
      TH2F *oyxz0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      oyxz1->Sumw2();
      oyxz0->Sumw2();
      //    if(oyxz0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceffew = (TH2F*)oyxz1->Clone("Ceffew");
	Ceffew->Divide(oyxz1,oyxz0, 1, 1, "B");
	Ceffew->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceffew->SetMarkerStyle(20);
      Ceffew->SetMarkerSize(0.4);
      Ceffew->GetYaxis()->SetLabelSize(0.04);
      //    Ceffew->SetTitle("any Error, HB Depth2 \n");
      Ceffew->SetXTitle("#eta");
      Ceffew->SetYTitle("#phi");
      Ceffew->SetZTitle("Signal for 1st Run - HB Depth2");
      Ceffew->SetMarkerColor(2);
      Ceffew->SetLineColor(2);
      Ceffew->Draw("COLZ");
      
      c1->cd(2);
      TH2F *ytrz1= (TH2F*)hfile2->Get("h_mapDepth2AmplE34_HB");
      TH2F *ytrz0= (TH2F*)hfile2->Get("h_mapDepth2_HB");
      ytrz1->Sumw2();
      ytrz0->Sumw2();
      //    if(ytrz0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cerrd = (TH2F*)ytrz1->Clone("Cerrd");
	Cerrd->Divide(ytrz1,ytrz0, 1, 1, "B");
	Cerrd->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cerrd->SetMarkerStyle(20);
      Cerrd->SetMarkerSize(0.4);
      Cerrd->GetYaxis()->SetLabelSize(0.04);
      //    Cerrd->SetTitle("any Error, HB Depth2 \n");
      Cerrd->SetXTitle("#eta");
      Cerrd->SetYTitle("#phi");
      Cerrd->SetZTitle("Signal for 2nd Run - HB Depth2");
      Cerrd->SetMarkerColor(2);
      Cerrd->SetLineColor(2);
      Cerrd->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth2_HB = (TH2F*)Ceff->Clone("Diffe_Depth2_HB");
 
    for (int i=1;i<=Ceff->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Ceff->GetYaxis()->GetNbins();j++) {
	Diffe_Depth2_HB->SetBinContent(i,j,0.);
	if(Ceff->GetBinContent(i,j) !=0 && Cerrd->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   -   Cerrd->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth2_HB->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth2_HB->SetMarkerStyle(20);
    Diffe_Depth2_HB->SetMarkerSize(0.4);
    Diffe_Depth2_HB->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth2_HB->SetTitle("any Error, HB Depth2 \n");
    Diffe_Depth2_HB->SetXTitle("#eta");
    Diffe_Depth2_HB->SetYTitle("#phi");
    Diffe_Depth2_HB->SetZTitle("Relative Difference in % - Depth2_HB");
    Diffe_Depth2_HB->SetMarkerColor(2);
    Diffe_Depth2_HB->SetLineColor(2);
    Diffe_Depth2_HB->Draw("COLZ");
    

      c1->cd(4);
      TH1F* diffAmpl_Depth2_HB = new TH1F("diffAmpl_Depth2_HB","", 100, -10., 10.);
 
      for (int i=1;i<=Ceff->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Ceff->GetYaxis()->GetNbins();j++) {
	  if(Ceff->GetBinContent(i,j) !=0 && Cerrd->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j)   -   Cerrd->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	    diffAmpl_Depth2_HB->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth2_HB->SetMarkerStyle(20);
      diffAmpl_Depth2_HB->SetMarkerSize(0.4);
      diffAmpl_Depth2_HB->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth2_HB->SetTitle("AmplRunsDifference Depth2_HB \n");
      diffAmpl_Depth2_HB->SetXTitle("Relative Difference, % - Depth2_HB");
      diffAmpl_Depth2_HB->SetMarkerColor(2);
      diffAmpl_Depth2_HB->SetLineColor(2);
      diffAmpl_Depth2_HB->Draw("");
      
      c1->Update();
      
      
            
    //==================================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *frde1= (TH2F*)hfile1->Get("h_mapDepth1AmplE34_HE");
      TH2F *frde0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      frde1->Sumw2();
      frde0->Sumw2();
      //    if(frde0->IsA()->InheritsFrom("TH2F")){
	TH2F* Coer = (TH2F*)frde1->Clone("Coer");
	Coer->Divide(frde1,frde0, 1, 1, "B");
	Coer->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Coer->SetMarkerStyle(20);
      Coer->SetMarkerSize(0.4);
      Coer->GetYaxis()->SetLabelSize(0.04);
      //    Coer->SetTitle("any Error, HE Depth1 \n");
      Coer->SetXTitle("#eta");
      Coer->SetYTitle("#phi");
      Coer->SetZTitle("Signal for 1st Run - HE Depth1");
      Coer->SetMarkerColor(2);
      Coer->SetLineColor(2);
      Coer->Draw("COLZ");
      
      c1->cd(2);
      TH2F *lkjh1= (TH2F*)hfile2->Get("h_mapDepth1AmplE34_HE");
      TH2F *lkjh= (TH2F*)hfile2->Get("h_mapDepth1_HE");
      lkjh1->Sumw2();
      lkjh->Sumw2();
      //    if(tqod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Coikj = (TH2F*)lkjh1->Clone("Coikj");
	Coikj->Divide(lkjh1,lkjh, 1, 1, "B");
	Coikj->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Coikj->SetMarkerStyle(20);
      Coikj->SetMarkerSize(0.4);
      Coikj->GetYaxis()->SetLabelSize(0.04);
      //    Coikj->SetTitle("any Error, HE Depth1 \n");
      Coikj->SetXTitle("#eta");
      Coikj->SetYTitle("#phi");
      Coikj->SetZTitle("Signal for 2nd Run - HE Depth1");
      Coikj->SetMarkerColor(2);
      Coikj->SetLineColor(2);
      Coikj->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HE = (TH2F*)Coer->Clone("Diffe_Depth1_HE");
 
    for (int i=1;i<=Coer->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Coer->GetYaxis()->GetNbins();j++) {
	Diffe_Depth1_HE->SetBinContent(i,j,0.);
	if(Coer->GetBinContent(i,j) !=0 && Coikj->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Coer->GetBinContent(i,j)   -   Coikj->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Coer->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth1_HE->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HE->SetMarkerStyle(20);
    Diffe_Depth1_HE->SetMarkerSize(0.4);
    Diffe_Depth1_HE->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth1_HE->SetTitle("any Error, HE Depth1 \n");
    Diffe_Depth1_HE->SetXTitle("#eta");
    Diffe_Depth1_HE->SetYTitle("#phi");
    Diffe_Depth1_HE->SetZTitle("Relative Difference in % - Depth1_HE");
    Diffe_Depth1_HE->SetMarkerColor(2);
    Diffe_Depth1_HE->SetLineColor(2);
    Diffe_Depth1_HE->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth1_HE = new TH1F("diffAmpl_Depth1_HE","", 100, -10., 10.);
 
      for (int i=1;i<=Coer->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Coer->GetYaxis()->GetNbins();j++) {
	  if(Coer->GetBinContent(i,j) !=0 && Coikj->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Coer->GetBinContent(i,j)   -   Coikj->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Coer->GetBinContent(i,j);
	    diffAmpl_Depth1_HE->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth1_HE->SetMarkerStyle(20);
      diffAmpl_Depth1_HE->SetMarkerSize(0.4);
      diffAmpl_Depth1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth1_HE->SetTitle("AmplRunsDifference Depth1_HE \n");
      diffAmpl_Depth1_HE->SetXTitle("Relative Difference, % - Depth1_HE");
      diffAmpl_Depth1_HE->SetMarkerColor(2);
      diffAmpl_Depth1_HE->SetLineColor(2);
      diffAmpl_Depth1_HE->Draw("");
      
      c1->Update();
      
      
            
    //==================================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *pkht1= (TH2F*)hfile1->Get("h_mapDepth2AmplE34_HE");
      TH2F *pkht0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      pkht1->Sumw2();
      pkht0->Sumw2();
      //    if(pkht0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cqpa = (TH2F*)pkht1->Clone("Cqpa");
	Cqpa->Divide(pkht1,pkht0, 1, 1, "B");
	Cqpa->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cqpa->SetMarkerStyle(20);
      Cqpa->SetMarkerSize(0.4);
      Cqpa->GetYaxis()->SetLabelSize(0.04);
      //    Cqpa->SetTitle("any Error, HE Depth2 \n");
      Cqpa->SetXTitle("#eta");
      Cqpa->SetYTitle("#phi");
      Cqpa->SetZTitle("Signal for 1st Run - HE Depth2");
      Cqpa->SetMarkerColor(2);
      Cqpa->SetLineColor(2);
      Cqpa->Draw("COLZ");
      
      c1->cd(2);
      TH2F *erto1= (TH2F*)hfile2->Get("h_mapDepth2AmplE34_HE");
      TH2F *erto0= (TH2F*)hfile2->Get("h_mapDepth2_HE");
      erto1->Sumw2();
      erto0->Sumw2();
      //    if(erto0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cqpwy = (TH2F*)erto1->Clone("Cqpwy");
	Cqpwy->Divide(erto1,erto0, 1, 1, "B");
	Cqpwy->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cqpwy->SetMarkerStyle(20);
      Cqpwy->SetMarkerSize(0.4);
      Cqpwy->GetYaxis()->SetLabelSize(0.04);
      //    Cqpwy->SetTitle("any Error, HE Depth2 \n");
      Cqpwy->SetXTitle("#eta");
      Cqpwy->SetYTitle("#phi");
      Cqpwy->SetZTitle("Signal for 2nd Run - HE Depth2");
      Cqpwy->SetMarkerColor(2);
      Cqpwy->SetLineColor(2);
      Cqpwy->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth2_HE = (TH2F*)Cqpa->Clone("Diffe_Depth2_HE");
 
    for (int i=1;i<=Cqpa->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cqpa->GetYaxis()->GetNbins();j++) {
	Diffe_Depth2_HE->SetBinContent(i,j,0.);
	if(Cqpa->GetBinContent(i,j) !=0 && Cqpwy->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Cqpa->GetBinContent(i,j)   -   Cqpwy->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Cqpa->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth2_HE->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth2_HE->SetMarkerStyle(20);
    Diffe_Depth2_HE->SetMarkerSize(0.4);
    Diffe_Depth2_HE->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth2_HE->SetTitle("any Error, HE Depth2 \n");
    Diffe_Depth2_HE->SetXTitle("#eta");
    Diffe_Depth2_HE->SetYTitle("#phi");
    Diffe_Depth2_HE->SetZTitle("Relative Difference in % - Depth2_HE");
    Diffe_Depth2_HE->SetMarkerColor(2);
    Diffe_Depth2_HE->SetLineColor(2);
    Diffe_Depth2_HE->Draw("COLZ");
    

      c1->cd(4);
      TH1F* diffAmpl_Depth2_HE = new TH1F("diffAmpl_Depth2_HE","", 100, -10., 10.);
 
      for (int i=1;i<=Cqpa->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cqpa->GetYaxis()->GetNbins();j++) {
	  if(Cqpa->GetBinContent(i,j) !=0 && Cqpwy->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cqpa->GetBinContent(i,j)   -   Cqpwy->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Cqpa->GetBinContent(i,j);
	    diffAmpl_Depth2_HE->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth2_HE->SetMarkerStyle(20);
      diffAmpl_Depth2_HE->SetMarkerSize(0.4);
      diffAmpl_Depth2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth2_HE->SetTitle("AmplRunsDifference Depth2_HE \n");
      diffAmpl_Depth2_HE->SetXTitle("Relative Difference, % - Depth2_HE");
      diffAmpl_Depth2_HE->SetMarkerColor(2);
      diffAmpl_Depth2_HE->SetLineColor(2);
      diffAmpl_Depth2_HE->Draw("");
      
      c1->Update();
      
      
            
    //==================================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *saqw1= (TH2F*)hfile1->Get("h_mapDepth3AmplE34_HE");
      TH2F *saqw0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      saqw1->Sumw2();
      saqw0->Sumw2();
      //    if(saqw0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cmju = (TH2F*)saqw1->Clone("Cmju");
	Cmju->Divide(saqw1,saqw0, 1, 1, "B");
	Cmju->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cmju->SetMarkerStyle(20);
      Cmju->SetMarkerSize(0.4);
      Cmju->GetYaxis()->SetLabelSize(0.04);
      //    Cmju->SetTitle("any Error, HE Depth3 \n");
      Cmju->SetXTitle("#eta");
      Cmju->SetYTitle("#phi");
      Cmju->SetZTitle("Signal for 1st Run - HE Depth3");
      Cmju->SetMarkerColor(2);
      Cmju->SetLineColor(2);
      Cmju->Draw("COLZ");
      
      c1->cd(2);
      TH2F *lpqx1= (TH2F*)hfile2->Get("h_mapDepth3AmplE34_HE");
      TH2F *lpqx0= (TH2F*)hfile2->Get("h_mapDepth3_HE");
      lpqx1->Sumw2();
      lpqx0->Sumw2();
      //    if(lpqx0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cmnbv = (TH2F*)lpqx1->Clone("Cmnbv");
	Cmnbv->Divide(lpqx1,lpqx0, 1, 1, "B");
	Cmnbv->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cmnbv->SetMarkerStyle(20);
      Cmnbv->SetMarkerSize(0.4);
      Cmnbv->GetYaxis()->SetLabelSize(0.04);
      //    Cmnbv->SetTitle("any Error, HE Depth3 \n");
      Cmnbv->SetXTitle("#eta");
      Cmnbv->SetYTitle("#phi");
      Cmnbv->SetZTitle("Signal for 2nd Run - HE Depth3");
      Cmnbv->SetMarkerColor(2);
      Cmnbv->SetLineColor(2);
      Cmnbv->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth3_HE = (TH2F*)Cmju->Clone("Diffe_Depth3_HE");
 
    for (int i=1;i<=Cmju->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cmju->GetYaxis()->GetNbins();j++) {
	Diffe_Depth3_HE->SetBinContent(i,j,0.);
	if(Cmju->GetBinContent(i,j) !=0 && Cmnbv->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Cmju->GetBinContent(i,j)   -   Cmnbv->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Cmju->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth3_HE->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth3_HE->SetMarkerStyle(20);
    Diffe_Depth3_HE->SetMarkerSize(0.4);
    Diffe_Depth3_HE->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth3_HE->SetTitle("any Error, HE Depth3 \n");
    Diffe_Depth3_HE->SetXTitle("#eta");
    Diffe_Depth3_HE->SetYTitle("#phi");
    Diffe_Depth3_HE->SetZTitle("Relative Difference in % - Depth3_HE");
    Diffe_Depth3_HE->SetMarkerColor(2);
    Diffe_Depth3_HE->SetLineColor(2);
    Diffe_Depth3_HE->Draw("COLZ");
    

      c1->cd(4);
      TH1F* diffAmpl_Depth3_HE = new TH1F("diffAmpl_Depth3_HE","", 100, -10., 10.);
 
      for (int i=1;i<=Cmju->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cmju->GetYaxis()->GetNbins();j++) {
	  if(Cmju->GetBinContent(i,j) !=0 && Cmnbv->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cmju->GetBinContent(i,j)   -   Cmnbv->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Cmju->GetBinContent(i,j);
	    diffAmpl_Depth3_HE->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth3_HE->SetMarkerStyle(20);
      diffAmpl_Depth3_HE->SetMarkerSize(0.4);
      diffAmpl_Depth3_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth3_HE->SetTitle("AmplRunsDifference Depth3_HE \n");
      diffAmpl_Depth3_HE->SetXTitle("Relative Difference, % - Depth3_HE");
      diffAmpl_Depth3_HE->SetMarkerColor(2);
      diffAmpl_Depth3_HE->SetLineColor(2);
      diffAmpl_Depth3_HE->Draw("");
      
      c1->Update();
      
      
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *mnsy1= (TH2F*)hfile1->Get("h_mapDepth1AmplE34_HF");
      TH2F *mnsy0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      mnsy1->Sumw2();
      mnsy0->Sumw2();
      //    if(mnsy0->IsA()->InheritsFrom("TH2F")){
	TH2F* Clpq = (TH2F*)mnsy1->Clone("Clpq");
	Clpq->Divide(mnsy1,mnsy0, 1, 1, "B");
	Clpq->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Clpq->SetMarkerStyle(20);
      Clpq->SetMarkerSize(0.4);
      Clpq->GetYaxis()->SetLabelSize(0.04);
      //    Clpq->SetTitle("any Error, HF Depth1 \n");
      Clpq->SetXTitle("#eta");
      Clpq->SetYTitle("#phi");
      Clpq->SetZTitle("Signal for 1st Run - HF Depth1");
      Clpq->SetMarkerColor(2);
      Clpq->SetLineColor(2);
      Clpq->Draw("COLZ");
      
      c1->cd(2);
      TH2F *kabx1= (TH2F*)hfile2->Get("h_mapDepth1AmplE34_HF");
      TH2F *kabx0= (TH2F*)hfile2->Get("h_mapDepth1_HF");
      kabx1->Sumw2();
      kabx0->Sumw2();
      //    if(kabx0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cigre = (TH2F*)kabx1->Clone("Cigre");
	Cigre->Divide(kabx1,kabx0, 1, 1, "B");
	Cigre->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cigre->SetMarkerStyle(20);
      Cigre->SetMarkerSize(0.4);
      Cigre->GetYaxis()->SetLabelSize(0.04);
      //    Cigre->SetTitle("any Error, HF Depth1 \n");
      Cigre->SetXTitle("#eta");
      Cigre->SetYTitle("#phi");
      Cigre->SetZTitle("Signal for 2nd Run - HF Depth1");
      Cigre->SetMarkerColor(2);
      Cigre->SetLineColor(2);
      Cigre->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HF = (TH2F*)Clpq->Clone("Diffe_Depth1_HF");
 
    for (int i=1;i<=Clpq->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Clpq->GetYaxis()->GetNbins();j++) {
	Diffe_Depth1_HF->SetBinContent(i,j,0.);
	if(Clpq->GetBinContent(i,j) !=0 && Cigre->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Clpq->GetBinContent(i,j)   -   Cigre->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Clpq->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth1_HF->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HF->SetMarkerStyle(20);
    Diffe_Depth1_HF->SetMarkerSize(0.4);
    Diffe_Depth1_HF->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth1_HF->SetTitle("any Error, HF Depth1 \n");
    Diffe_Depth1_HF->SetXTitle("#eta");
    Diffe_Depth1_HF->SetYTitle("#phi");
    Diffe_Depth1_HF->SetZTitle("Relative Difference in % - Depth1_HF");
    Diffe_Depth1_HF->SetMarkerColor(2);
    Diffe_Depth1_HF->SetLineColor(2);
    Diffe_Depth1_HF->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth1_HF = new TH1F("diffAmpl_Depth1_HF","", 100, -10., 10.);
 
      for (int i=1;i<=Clpq->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Clpq->GetYaxis()->GetNbins();j++) {
	  if(Clpq->GetBinContent(i,j) !=0 && Cigre->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Clpq->GetBinContent(i,j)   -   Cigre->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Clpq->GetBinContent(i,j);
	    diffAmpl_Depth1_HF->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth1_HF->SetMarkerStyle(20);
      diffAmpl_Depth1_HF->SetMarkerSize(0.4);
      diffAmpl_Depth1_HF->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth1_HF->SetTitle("AmplRunsDifference Depth1_HF \n");
      diffAmpl_Depth1_HF->SetXTitle("Relative Difference, % - Depth1_HF");
      diffAmpl_Depth1_HF->SetMarkerColor(2);
      diffAmpl_Depth1_HF->SetLineColor(2);
      diffAmpl_Depth1_HF->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *lqps1= (TH2F*)hfile1->Get("h_mapDepth2AmplE34_HF");
      TH2F *lqps0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      lqps1->Sumw2();
      lqps0->Sumw2();
      //    if(lqps0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cqwl = (TH2F*)lqps1->Clone("Cqwl");
	Cqwl->Divide(lqps1,lqps0, 1, 1, "B");
	Cqwl->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cqwl->SetMarkerStyle(20);
      Cqwl->SetMarkerSize(0.4);
      Cqwl->GetYaxis()->SetLabelSize(0.04);
      //    Cqwl->SetTitle("any Error, HF Depth2 \n");
      Cqwl->SetXTitle("#eta");
      Cqwl->SetYTitle("#phi");
      Cqwl->SetZTitle("Signal for 1st Run - HF Depth2");
      Cqwl->SetMarkerColor(2);
      Cqwl->SetLineColor(2);
      Cqwl->Draw("COLZ");
      
      c1->cd(2);
      TH2F *mqps1= (TH2F*)hfile2->Get("h_mapDepth2AmplE34_HF");
      TH2F *mqps0= (TH2F*)hfile2->Get("h_mapDepth2_HF");
      mqps1->Sumw2();
      mqps0->Sumw2();
      //    if(mqps0->IsA()->InheritsFrom("TH2F")){
	TH2F* Clzsr = (TH2F*)mqps1->Clone("Clzsr");
	Clzsr->Divide(mqps1,mqps0, 1, 1, "B");
	Clzsr->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Clzsr->SetMarkerStyle(20);
      Clzsr->SetMarkerSize(0.4);
      Clzsr->GetYaxis()->SetLabelSize(0.04);
      //    Clzsr->SetTitle("any Error, HF Depth2 \n");
      Clzsr->SetXTitle("#eta");
      Clzsr->SetYTitle("#phi");
      Clzsr->SetZTitle("Signal for 2nd Run - HF Depth2");
      Clzsr->SetMarkerColor(2);
      Clzsr->SetLineColor(2);
      Clzsr->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth2_HF = (TH2F*)Cqwl->Clone("Diffe_Depth2_HF");
 
    for (int i=1;i<=Cqwl->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cqwl->GetYaxis()->GetNbins();j++) {
	Diffe_Depth2_HF->SetBinContent(i,j,0.);
	if(Cqwl->GetBinContent(i,j) !=0 && Clzsr->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Cqwl->GetBinContent(i,j)   -   Clzsr->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Cqwl->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth2_HF->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth2_HF->SetMarkerStyle(20);
    Diffe_Depth2_HF->SetMarkerSize(0.4);
    Diffe_Depth2_HF->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth2_HF->SetTitle("any Error, HF Depth2 \n");
    Diffe_Depth2_HF->SetXTitle("#eta");
    Diffe_Depth2_HF->SetYTitle("#phi");
    Diffe_Depth2_HF->SetZTitle("Relative Difference in % - Depth2_HF");
    Diffe_Depth2_HF->SetMarkerColor(2);
    Diffe_Depth2_HF->SetLineColor(2);
    Diffe_Depth2_HF->Draw("COLZ");
    

      c1->cd(4);
      TH1F* diffAmpl_Depth2_HF = new TH1F("diffAmpl_Depth2_HF","", 100, -10., 10.);
 
      for (int i=1;i<=Cqwl->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cqwl->GetYaxis()->GetNbins();j++) {
	  if(Cqwl->GetBinContent(i,j) !=0 && Clzsr->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cqwl->GetBinContent(i,j)   -   Clzsr->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Cqwl->GetBinContent(i,j);
	    diffAmpl_Depth2_HF->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth2_HF->SetMarkerStyle(20);
      diffAmpl_Depth2_HF->SetMarkerSize(0.4);
      diffAmpl_Depth2_HF->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth2_HF->SetTitle("AmplRunsDifference Depth2_HF \n");
      diffAmpl_Depth2_HF->SetXTitle("Relative Difference, % - Depth2_HF");
      diffAmpl_Depth2_HF->SetMarkerColor(2);
      diffAmpl_Depth2_HF->SetLineColor(2);
      diffAmpl_Depth2_HF->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *owje1= (TH2F*)hfile1->Get("h_mapDepth4AmplE34_HO");
      TH2F *owje0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      owje1->Sumw2();
      owje0->Sumw2();
      //    if(owje0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdkg = (TH2F*)owje1->Clone("Cdkg");
	Cdkg->Divide(owje1,owje0, 1, 1, "B");
	Cdkg->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdkg->SetMarkerStyle(20);
      Cdkg->SetMarkerSize(0.4);
      Cdkg->GetYaxis()->SetLabelSize(0.04);
      //    Cdkg->SetTitle("any Error, HO Depth4 \n");
      Cdkg->SetXTitle("#eta");
      Cdkg->SetYTitle("#phi");
      Cdkg->SetZTitle("Signal for 1st Run - HO Depth4");
      Cdkg->SetMarkerColor(2);
      Cdkg->SetLineColor(2);
      Cdkg->Draw("COLZ");
      
      c1->cd(2);
      TH2F *mbxd1= (TH2F*)hfile2->Get("h_mapDepth4AmplE34_HO");
      TH2F *mbxd0= (TH2F*)hfile2->Get("h_mapDepth4_HO");
      mbxd1->Sumw2();
      mbxd0->Sumw2();
      //    if(mbxd0->IsA()->InheritsFrom("TH2F")){
	TH2F* Capqw = (TH2F*)mbxd1->Clone("Capqw");
	Capqw->Divide(mbxd1,mbxd0, 1, 1, "B");
	Capqw->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Capqw->SetMarkerStyle(20);
      Capqw->SetMarkerSize(0.4);
      Capqw->GetYaxis()->SetLabelSize(0.04);
      //    Capqw->SetTitle("any Error, HO Depth4 \n");
      Capqw->SetXTitle("#eta");
      Capqw->SetYTitle("#phi");
      Capqw->SetZTitle("Signal for 2nd Run - HO Depth4");
      Capqw->SetMarkerColor(2);
      Capqw->SetLineColor(2);
      Capqw->Draw("COLZ");
      
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth4_HO = (TH2F*)Cdkg->Clone("Diffe_Depth4_HO");
 
    for (int i=1;i<=Cdkg->GetXaxis()->GetNbins();i++) {
      for (int j=1;j<=Cdkg->GetYaxis()->GetNbins();j++) {
	Diffe_Depth4_HO->SetBinContent(i,j,0.);
	if(Cdkg->GetBinContent(i,j) !=0 && Capqw->GetBinContent(i,j) !=0 ) {
	  double ccc1 =  Cdkg->GetBinContent(i,j)   -   Capqw->GetBinContent(i,j)  ;
	  ccc1 = 100.*ccc1/Cdkg->GetBinContent(i,j);
	  if(fabs(ccc1) > 2. )  Diffe_Depth4_HO->SetBinContent(i,j,fabs(ccc1));
	}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth4_HO->SetMarkerStyle(20);
    Diffe_Depth4_HO->SetMarkerSize(0.4);
    Diffe_Depth4_HO->GetYaxis()->SetLabelSize(0.04);
    //    Diffe_Depth4_HO->SetTitle("any Error, HO Depth4 \n");
    Diffe_Depth4_HO->SetXTitle("#eta");
    Diffe_Depth4_HO->SetYTitle("#phi");
    Diffe_Depth4_HO->SetZTitle("Relative Difference in % - Depth4_HO");
    Diffe_Depth4_HO->SetMarkerColor(2);
    Diffe_Depth4_HO->SetLineColor(2);
    Diffe_Depth4_HO->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth4_HO = new TH1F("diffAmpl_Depth4_HO","", 100, -10., 10.);
 
      for (int i=1;i<=Cdkg->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdkg->GetYaxis()->GetNbins();j++) {
	  if(Cdkg->GetBinContent(i,j) !=0 && Capqw->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cdkg->GetBinContent(i,j)   -   Capqw->GetBinContent(i,j)  ;
	    ccc1 = 100.*ccc1/Cdkg->GetBinContent(i,j);
	    diffAmpl_Depth4_HO->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth4_HO->SetMarkerStyle(20);
      diffAmpl_Depth4_HO->SetMarkerSize(0.4);
      diffAmpl_Depth4_HO->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth4_HO->SetTitle("AmplRunsDifference Depth4_HO \n");
      diffAmpl_Depth4_HO->SetXTitle("Relative Difference, % - Depth4_HO");
      diffAmpl_Depth4_HO->SetMarkerColor(2);
      diffAmpl_Depth4_HO->SetLineColor(2);
      diffAmpl_Depth4_HO->Draw("");
      
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
