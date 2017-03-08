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
	//		gStyle->SetOptStat(0);   //  no statistics _or_
	//		   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//      	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//				gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

//	TFile *hfile2= new TFile("LASER_284348.root", "READ");        
//	TFile *hfile2= new TFile("LASER_284352.root", "READ");        
//	TFile *hfile2= new TFile("LASER_284499.root", "READ");        
//	TFile *hfile2= new TFile("LASER_284901.root", "READ");        
//	TFile *hfile2= new TFile("LASER_284902.root", "READ");        
//	TFile *hfile1= new TFile("LASER_285227.root", "READ");        


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
          TPostScript psfile ("zraddam0.ps", 111);
//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //============================================================================================= 1
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,3);

      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal00_HE");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal00_HE \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");

      c1->cd(2);
      //    TH1F *aaaaac1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
      TH1F *aaaaac1= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      gPad->SetLogy();
      gPad->SetLogx();
      aaaaac1->SetMarkerStyle(20);
      aaaaac1->SetMarkerSize(0.8);
      aaaaac1->GetYaxis()->SetLabelSize(0.04);
      aaaaac1->SetXTitle("ADCAmpl RUN1 in each event & cell HE \b");
      aaaaac1->SetMarkerColor(2);
      aaaaac1->SetLineColor(2);
      aaaaac1->Draw("");

      c1->cd(3);
      TH2F *jqaz1= (TH2F*)hfile1->Get("h_mapDepth1Ped0_HE");
      TH2F *jqaz0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      jqaz1->Sumw2();
      jqaz0->Sumw2();
        TH2F* Cmegcqa = (TH2F*)jqaz1->Clone("Cmegcqa");
        Cmegcqa->Divide(jqaz1,jqaz0, 1, 1, "B");
        Cmegcqa->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cmegcqa->SetMarkerStyle(20);
      Cmegcqa->SetMarkerSize(0.4);
      Cmegcqa->GetZaxis()->SetLabelSize(0.08);
      Cmegcqa->SetXTitle("#eta \b");
      Cmegcqa->SetYTitle("#phi \b");
      Cmegcqa->SetZTitle("mapDepth1Ped0_HE \b");
      Cmegcqa->SetMarkerColor(2);
      Cmegcqa->SetLineColor(2);
//      Cmegcqa->SetMaximum(1.000);
      // Cmegcqa->SetMinimum(0.1);
      Cmegcqa->Draw("COLZ");

      c1->cd(1);
      TH1F *aaaaad1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaad1->SetMarkerStyle(20);
      aaaaad1->SetMarkerSize(0.8);
      aaaaad1->GetYaxis()->SetLabelSize(0.04);
      aaaaad1->SetXTitle("ADCAmpl  RUN1 in each event & cell HE \b");
      aaaaad1->SetMarkerColor(2);
      aaaaad1->SetLineColor(2);
      aaaaad1->Draw("");

      c1->cd(5);
      TH1F *aaraad1= (TH1F*)hfile2->Get("h_ADCAmplZoom1_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaraad1->SetMarkerStyle(20);
      aaraad1->SetMarkerSize(0.8);
      aaraad1->GetYaxis()->SetLabelSize(0.04);
      aaraad1->SetXTitle("ADCAmpl RUN2 in each event & cell HE \b");
      aaraad1->SetMarkerColor(2);
      aaraad1->SetLineColor(2);
      aaraad1->Draw("");
      c1->cd(6);
      TH1F *abaaac1= (TH1F*)hfile2->Get("h_ADCAmpl_HE");
      gPad->SetLogy();
      gPad->SetLogx();
      abaaac1->SetMarkerStyle(20);
      abaaac1->SetMarkerSize(0.8);
      abaaac1->GetYaxis()->SetLabelSize(0.04);
      abaaac1->SetXTitle("ADCAmpl RUN2 in each event & cell HE \b");
      abaaac1->SetMarkerColor(2);
      abaaac1->SetLineColor(2);
      abaaac1->Draw("");

      c1->Update();
    //============================================================================================= 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1RADDAM_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1RADDAM0_HE");
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
      //    Ceff->SetTitle("any Error, HE Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Signal for 1st Run - HE Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *tqod1= (TH2F*)hfile2->Get("h_mapDepth1RADDAM_HE");
      TH2F *tqod0= (TH2F*)hfile2->Get("h_mapDepth1RADDAM0_HE");
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
      //    Czeff->SetTitle("any Error, HE Depth1 \n");
      Czeff->SetXTitle("#eta");
      Czeff->SetYTitle("#phi");
      Czeff->SetZTitle("Signal for 2nd Run - HE Depth1");
      Czeff->SetMarkerColor(2);
      Czeff->SetLineColor(2);
      Czeff->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      //    TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
      TH2F* Diffe_Depth1_HE = (TH2F*)Ceff->Clone("Diffe_Depth1_HE");
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  Diffe_Depth1_HE->SetBinContent(i,j,0.);
	  if(Ceff->GetBinContent(i,j) !=0 && Czeff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Czeff->GetBinContent(i,j)/Ceff->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Ceff->GetBinContent(i,j)   -   Czeff->GetBinContent(i,j)  ;
	    //	    ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Depth1_HE->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth1_HE->SetBinContent(i,j,fabs(ccc1));
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
    Diffe_Depth1_HE->SetZTitle("|A2/A1| - Depth1_HE");
    Diffe_Depth1_HE->SetMarkerColor(2);
    Diffe_Depth1_HE->SetLineColor(2);
    Diffe_Depth1_HE->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth1_HE = new TH1F("diffAmpl_Depth1_HE","", 100, 0., 2.);
 
      for (int i=1;i<=Ceff->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Ceff->GetYaxis()->GetNbins();j++) {
	  if(Ceff->GetBinContent(i,j) !=0 && Czeff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Czeff->GetBinContent(i,j)/Ceff->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Ceff->GetBinContent(i,j)   -   Czeff->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Ceff->GetBinContent(i,j);
	    diffAmpl_Depth1_HE->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth1_HE->SetMarkerStyle(20);
      diffAmpl_Depth1_HE->SetMarkerSize(0.4);
      diffAmpl_Depth1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth1_HE->SetTitle("AmplRunsDifference Depth1_HE \n");
      diffAmpl_Depth1_HE->SetXTitle("|A2/A1| - Depth1_HE");
      diffAmpl_Depth1_HE->SetMarkerColor(2);
      diffAmpl_Depth1_HE->SetLineColor(2);
      diffAmpl_Depth1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *poqa1= (TH2F*)hfile1->Get("h_mapDepth2RADDAM_HE");
      TH2F *poqa0= (TH2F*)hfile1->Get("h_mapDepth2RADDAM0_HE");
      poqa1->Sumw2();
      poqa0->Sumw2();
      //    if(poqa0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cfrr = (TH2F*)poqa1->Clone("Cfrr");
	Cfrr->Divide(poqa1,poqa0, 1, 1, "B");
	Cfrr->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cfrr->SetMarkerStyle(20);
      Cfrr->SetMarkerSize(0.4);
      Cfrr->GetYaxis()->SetLabelSize(0.04);
      //    Cfrr->SetTitle("any Error, HE Depth2 \n");
      Cfrr->SetXTitle("#eta");
      Cfrr->SetYTitle("#phi");
      Cfrr->SetZTitle("Signal for 1st Run - HE Depth2");
      Cfrr->SetMarkerColor(2);
      Cfrr->SetLineColor(2);
      Cfrr->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *trwp1= (TH2F*)hfile2->Get("h_mapDepth2RADDAM_HE");
      TH2F *trwp0= (TH2F*)hfile2->Get("h_mapDepth2RADDAM0_HE");
      trwp1->Sumw2();
      trwp0->Sumw2();
      //    if(trwp0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cpoir = (TH2F*)trwp1->Clone("Cpoir");
	Cpoir->Divide(trwp1,trwp0, 1, 1, "B");
	Cpoir->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cpoir->SetMarkerStyle(20);
      Cpoir->SetMarkerSize(0.4);
      Cpoir->GetYaxis()->SetLabelSize(0.04);
      //    Cpoir->SetTitle("any Error, HE Depth2 \n");
      Cpoir->SetXTitle("#eta");
      Cpoir->SetYTitle("#phi");
      Cpoir->SetZTitle("Signal for 2nd Run - HE Depth2");
      Cpoir->SetMarkerColor(2);
      Cpoir->SetLineColor(2);
      Cpoir->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      //    TH2F* Cfrr = (TH2F*)poqa1->Clone("Cfrr");
      TH2F* Diffe_Depth2_HE = (TH2F*)Cfrr->Clone("Diffe_Depth2_HE");
      for (int i=1;i<=Cfrr->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cfrr->GetYaxis()->GetNbins();j++) {
	  Diffe_Depth2_HE->SetBinContent(i,j,0.);
	  if(Cfrr->GetBinContent(i,j) !=0 && Cpoir->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpoir->GetBinContent(i,j)/Cfrr->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Cfrr->GetBinContent(i,j)   -   Cpoir->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cfrr->GetBinContent(i,j);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Depth2_HE->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth2_HE->SetBinContent(i,j,fabs(ccc1));
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
    Diffe_Depth2_HE->SetZTitle("|A2/A1| - Depth2_HE");
    Diffe_Depth2_HE->SetMarkerColor(2);
    Diffe_Depth2_HE->SetLineColor(2);
    Diffe_Depth2_HE->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth2_HE = new TH1F("diffAmpl_Depth2_HE","", 100, 0., 2.);
 
      for (int i=1;i<=Cfrr->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cfrr->GetYaxis()->GetNbins();j++) {
	  if(Cfrr->GetBinContent(i,j) !=0 && Cpoir->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cpoir->GetBinContent(i,j)/Cfrr->GetBinContent(i,j)  ;
	    //	    double ccc1 =  Cfrr->GetBinContent(i,j)   -   Cpoir->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cfrr->GetBinContent(i,j);
	    diffAmpl_Depth2_HE->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth2_HE->SetMarkerStyle(20);
      diffAmpl_Depth2_HE->SetMarkerSize(0.4);
      diffAmpl_Depth2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth2_HE->SetTitle("AmplRunsDifference Depth2_HE \n");
      diffAmpl_Depth2_HE->SetXTitle("|A2/A1| - Depth2_HE");
      diffAmpl_Depth2_HE->SetMarkerColor(2);
      diffAmpl_Depth2_HE->SetLineColor(2);
      diffAmpl_Depth2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *llkj1= (TH2F*)hfile1->Get("h_mapDepth3RADDAM_HE");
      TH2F *llkj0= (TH2F*)hfile1->Get("h_mapDepth3RADDAM0_HE");
      llkj1->Sumw2();
      llkj0->Sumw2();
      //    if(llkj0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cdde = (TH2F*)llkj1->Clone("Cdde");
	Cdde->Divide(llkj1,llkj0, 1, 1, "B");
	Cdde->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdde->SetMarkerStyle(20);
      Cdde->SetMarkerSize(0.4);
      Cdde->GetYaxis()->SetLabelSize(0.04);
      //    Cdde->SetTitle("any Error, HE Depth3 \n");
      Cdde->SetXTitle("#eta");
      Cdde->SetYTitle("#phi");
      Cdde->SetZTitle("Signal for 1st Run - HE Depth3");
      Cdde->SetMarkerColor(2);
      Cdde->SetLineColor(2);
      Cdde->Draw("COLZ");
      //    }
      
      c1->cd(2);
      TH2F *tpoo1= (TH2F*)hfile2->Get("h_mapDepth3RADDAM_HE");
      TH2F *tpoo0= (TH2F*)hfile2->Get("h_mapDepth3RADDAM0_HE");
      tpoo1->Sumw2();
      tpoo0->Sumw2();
      //    if(tpoo0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cfree = (TH2F*)tpoo1->Clone("Cfree");
	Cfree->Divide(tpoo1,tpoo0, 1, 1, "B");
	Cfree->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cfree->SetMarkerStyle(20);
      Cfree->SetMarkerSize(0.4);
      Cfree->GetYaxis()->SetLabelSize(0.04);
      //    Cfree->SetTitle("any Error, HE Depth3 \n");
      Cfree->SetXTitle("#eta");
      Cfree->SetYTitle("#phi");
      Cfree->SetZTitle("Signal for 2nd Run - HE Depth3");
      Cfree->SetMarkerColor(2);
      Cfree->SetLineColor(2);
      Cfree->Draw("COLZ");
      //    }
      
      c1->cd(3);
    ///////////////////////////////////////
      TH2F* Diffe_Depth3_HE = (TH2F*)Cdde->Clone("Diffe_Depth3_HE");
      for (int i=1;i<=Cdde->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdde->GetYaxis()->GetNbins();j++) {
	  Diffe_Depth3_HE->SetBinContent(i,j,0.);
	  if(Cdde->GetBinContent(i,j) !=0 && Cfree->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cfree->GetBinContent(i,j)/Cdde->GetBinContent(i,j)  ;
	    //	    std::cout <<"111111 i=  " <<i  <<"  j=  " <<j << "  ccc1=  " <<ccc1 <<"  A2 =  " <<Cfree->GetBinContent(i,j) <<"  A1 =  " <<Cdde->GetBinContent(i,j) << std::endl; 
	    //	    double ccc1 =  Cdde->GetBinContent(i,j)   -   Cfree->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cdde->GetBinContent(i,j);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Depth3_HE->SetBinContent(i,j,fabs(ccc1));
	    Diffe_Depth3_HE->SetBinContent(i,j,fabs(ccc1));
	  }
	}
      }
      //	    std::cout <<"111111 NX=  " <<Cdde->GetXaxis()->GetNbins() <<" NY=  " <<Cdde->GetYaxis()->GetNbins() << std::endl; 
      //	    std::cout <<"222222 NX=  " <<Cfree->GetXaxis()->GetNbins() <<" NY=  " <<Cfree->GetYaxis()->GetNbins() << std::endl; 


    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth3_HE->SetMarkerStyle(20);
    Diffe_Depth3_HE->SetMarkerSize(0.4);
    Diffe_Depth3_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Depth3_HE->SetXTitle("#eta");
    Diffe_Depth3_HE->SetYTitle("#phi");
    Diffe_Depth3_HE->SetZTitle("|A2/A1| -  Depth3_HE");
    Diffe_Depth3_HE->SetMarkerColor(2);
    Diffe_Depth3_HE->SetLineColor(2);
    Diffe_Depth3_HE->Draw("COLZ");
    
    
      c1->cd(4);
      TH1F* diffAmpl_Depth3_HE = new TH1F("diffAmpl_Depth3_HE","", 100, 0., 2.);
 
      for (int i=1;i<=Cdde->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=Cdde->GetYaxis()->GetNbins();j++) {
	  if(Cdde->GetBinContent(i,j) !=0 && Cfree->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Cfree->GetBinContent(i,j)/Cdde->GetBinContent(i,j);
	    //	    std::cout <<"222222 i=  " <<i  <<"  j=  " <<j << "  ccc1=  " <<ccc1 <<"  A2 =  " <<Cfree->GetBinContent(i,j) <<"  A1 =  " <<Cdde->GetBinContent(i,j) << std::endl; 
	    //	    double ccc1 =  Cdde->GetBinContent(i,j) - Cfree->GetBinContent(i,j)  ;
	    //ccc1 = 100.*ccc1/Cdde->GetBinContent(i,j);
	    diffAmpl_Depth3_HE->Fill(fabs(ccc1));
	  }
	}
      }
      gPad->SetLogy();
      diffAmpl_Depth3_HE->SetMarkerStyle(20);
      diffAmpl_Depth3_HE->SetMarkerSize(0.4);
      diffAmpl_Depth3_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Depth3_HE->SetTitle("AmplRunsDifference Depth3_HE \n");
      diffAmpl_Depth3_HE->SetXTitle("|A2/A1| - Depth3_HE");
      diffAmpl_Depth3_HE->SetMarkerColor(2);
      diffAmpl_Depth3_HE->SetLineColor(2);
      diffAmpl_Depth3_HE->Draw("");
      
      c1->Update();
      
      
      //============================================================================================= 5
      //======================================================================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      //	    std::cout <<"333333  " << std::endl; 
      TH1F *aaaaab1= (TH1F*)hfile1->Get("h_A_Depth1RADDAM_HE");
      gPad->SetLogy();
      //     gPad->SetLogx();
      aaaaab1->SetMarkerStyle(20);
      aaaaab1->SetMarkerSize(0.8);
      aaaaab1->GetYaxis()->SetLabelSize(0.04);
      aaaaab1->SetXTitle("h_A_Depth1RADDAM_HE \b");
      aaaaab1->SetMarkerColor(2);
      aaaaab1->SetLineColor(2);
      aaaaab1->Draw("");
      c1->cd(2);
      TH1F *aaaaab2= (TH1F*)hfile1->Get("h_A_Depth2RADDAM_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      aaaaab2->SetMarkerStyle(20);
      aaaaab2->SetMarkerSize(0.8);
      aaaaab2->GetYaxis()->SetLabelSize(0.04);
      aaaaab2->SetXTitle("h_A_Depth2RADDAM_HE \b");
      aaaaab2->SetMarkerColor(2);
      aaaaab2->SetLineColor(2);
      aaaaab2->Draw("");
      c1->cd(3);
      TH1F *aaaaab3= (TH1F*)hfile1->Get("h_A_Depth3RADDAM_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      aaaaab3->SetMarkerStyle(20);
      aaaaab3->SetMarkerSize(0.8);
      aaaaab3->GetYaxis()->SetLabelSize(0.04);
      aaaaab3->SetXTitle("h_A_Depth3RADDAM_HE \b");
      aaaaab3->SetMarkerColor(2);
      aaaaab3->SetLineColor(2);
      aaaaab3->Draw("");
      c1->cd(4);
      TH1F *aaaaab6= (TH1F*)hfile1->Get("h_mapDepth3RADDAM16_HE");
      //    h_mapDepth3RADDAM160_HE
      gPad->SetLogy();
      //      gPad->SetLogx();
      aaaaab6->SetMarkerStyle(20);
      aaaaab6->SetMarkerSize(0.8);
      aaaaab6->GetYaxis()->SetLabelSize(0.04);
      aaaaab6->SetXTitle("h_mapDepth3RADDAM16_HE \b");
      aaaaab6->SetMarkerColor(2);
      aaaaab6->SetLineColor(2);
      aaaaab6->Draw("");

      c1->Update();


      //============================================================================================= 6
      //======================================================================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *cwod1= (TH2F*)hfile1->Get("h_mapDepth1TSmeanA_HE");
      TH2F *cwod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      cwod1->Sumw2();
      cwod0->Sumw2();
    //  if(cwod0->IsA()->InheritsFrom("TH2F")){
	TH2F* C3ff = (TH2F*)cwod1->Clone("C3ff");
	C3ff->Divide(cwod1,cwod0, 1, 1, "B");
	C3ff->Sumw2();
   //   }
      TH1F* diffTSmeanA_Depth1_HE = new TH1F("diffTSmeanA_Depth1_HE","", 100, 3.0,7.0);
      for (int i=1;i<=C3ff->GetXaxis()->GetNbins();i++) {
	for (int j=1;j<=C3ff->GetYaxis()->GetNbins();j++) {
	  if(C3ff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  C3ff->GetBinContent(i,j) ;
	    diffTSmeanA_Depth1_HE->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffTSmeanA_Depth1_HE->SetMarkerStyle(20);
      diffTSmeanA_Depth1_HE->SetMarkerSize(0.4);
      diffTSmeanA_Depth1_HE->GetYaxis()->SetLabelSize(0.04);
      diffTSmeanA_Depth1_HE->SetXTitle("<TSmeanA> in each cell \b");
      diffTSmeanA_Depth1_HE->SetMarkerColor(2);
      diffTSmeanA_Depth1_HE->SetLineColor(2);
      diffTSmeanA_Depth1_HE->Draw("");
 
      c1->cd(2);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_TSmeanA_HE");
          gPad->SetLogy();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("TSmeanA in each event & cell HE \b");
      aaaaaa3->SetMarkerColor(2);
      aaaaaa3->SetLineColor(2);
      aaaaaa3->Draw("");



      c1->Update();
    //======================================================================
      //============================================================================================= 7
      //======================================================================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(2,3);

      c1->cd(1);
      //	    std::cout <<"333333  " << std::endl; 
      TH1F *ssssab1= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      ssssab1->SetMarkerStyle(20);
      ssssab1->SetMarkerSize(0.8);
      ssssab1->GetYaxis()->SetLabelSize(0.04);
      ssssab1->SetXTitle("ADCAmpl345_HE \b");
      ssssab1->SetMarkerColor(2);
      ssssab1->SetLineColor(2);
      ssssab1->Draw("");
      c1->cd(2);
      TH1F *ssssab2= (TH1F*)hfile1->Get("h_ADCAmpl345Zoom1_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      ssssab2->SetMarkerStyle(20);
      ssssab2->SetMarkerSize(0.8);
      ssssab2->GetYaxis()->SetLabelSize(0.04);
      ssssab2->SetXTitle("ADCAmpl345_HE \b");
      ssssab2->SetMarkerColor(2);
      ssssab2->SetLineColor(2);
      ssssab2->Draw("");
      c1->cd(3);
      TH1F *ssssab3= (TH1F*)hfile1->Get("h_ADCAmpl345_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      ssssab3->SetMarkerStyle(20);
      ssssab3->SetMarkerSize(0.8);
      ssssab3->GetYaxis()->SetLabelSize(0.04);
      ssssab3->SetXTitle("ADCAmpl345_HE \b");
      ssssab3->SetMarkerColor(2);
      ssssab3->SetLineColor(2);
      ssssab3->Draw("");


      c1->cd(5);
      TH1F *bdepth1he= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      bdepth1he->SetMarkerStyle(20);
      bdepth1he->SetMarkerSize(0.8);
      bdepth1he->GetYaxis()->SetLabelSize(0.04);
      bdepth1he->SetXTitle("ADCAmpl in each event & cell HE \b");
      bdepth1he->SetMarkerColor(2);
      bdepth1he->SetLineColor(2);
      bdepth1he->Draw("");
      //    delete bdepth1he;    


      c1->cd(4);
      TH1F *bdepth2he= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      bdepth2he->SetMarkerStyle(20);
      bdepth2he->SetMarkerSize(0.8);
      bdepth2he->GetYaxis()->SetLabelSize(0.04);
      bdepth2he->SetXTitle("ADCAmpl in each event & cell HE \b");
      bdepth2he->SetMarkerColor(2);
      bdepth2he->SetLineColor(2);
      bdepth2he->Draw("");
      //    delete bdepth2he;    
            
      c1->cd(6);
      TH1F *bdepthahe= (TH1F*)hfile1->Get("h_AamplitudewithPedSubtr_RADDAM_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      bdepthahe->SetMarkerStyle(20);
      bdepthahe->SetMarkerSize(0.8);
      bdepthahe->GetYaxis()->SetLabelSize(0.04);
      bdepthahe->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      bdepthahe->SetMarkerColor(2);
      bdepthahe->SetLineColor(2);
      bdepthahe->Draw("");

      c1->Update();


    //======================================================================
      //============================================================================================= 8
      //======================================================================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(2,3);

      c1->cd(1);
      TH1F *runfile1zoom0= (TH1F*)hfile1->Get("h_AamplitudewithPedSubtr_RADDAM_HEzoom0");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile1zoom0->SetMarkerStyle(20);
      runfile1zoom0->SetMarkerSize(0.8);
      runfile1zoom0->GetYaxis()->SetLabelSize(0.04);
      runfile1zoom0->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile1zoom0->SetMarkerColor(1);
      runfile1zoom0->SetLineColor(1);
      runfile1zoom0->Draw("");

      c1->cd(2);
      TH1F *runfile2zoom0= (TH1F*)hfile2->Get("h_AamplitudewithPedSubtr_RADDAM_HEzoom0");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile2zoom0->SetMarkerStyle(20);
      runfile2zoom0->SetMarkerSize(0.8);
      runfile2zoom0->GetYaxis()->SetLabelSize(0.04);
      runfile2zoom0->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile2zoom0->SetMarkerColor(2);
      runfile2zoom0->SetLineColor(2);
      runfile2zoom0->Draw("");

      c1->cd(3);
      TH1F *runfile1zoom1= (TH1F*)hfile1->Get("h_AamplitudewithPedSubtr_RADDAM_HEzoom1");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile1zoom1->SetMarkerStyle(20);
      runfile1zoom1->SetMarkerSize(0.8);
      runfile1zoom1->GetYaxis()->SetLabelSize(0.04);
      runfile1zoom1->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile1zoom1->SetMarkerColor(1);
      runfile1zoom1->SetLineColor(1);
      runfile1zoom1->Draw("");

      c1->cd(4);
      TH1F *runfile2zoom1= (TH1F*)hfile2->Get("h_AamplitudewithPedSubtr_RADDAM_HEzoom1");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile2zoom1->SetMarkerStyle(20);
      runfile2zoom1->SetMarkerSize(0.8);
      runfile2zoom1->GetYaxis()->SetLabelSize(0.04);
      runfile2zoom1->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile2zoom1->SetMarkerColor(2);
      runfile2zoom1->SetLineColor(2);
      runfile2zoom1->Draw("");

      c1->cd(5);
      TH1F *runfile1zoom9= (TH1F*)hfile1->Get("h_AamplitudewithPedSubtr_RADDAM_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile1zoom9->SetMarkerStyle(20);
      runfile1zoom9->SetMarkerSize(0.8);
      runfile1zoom9->GetYaxis()->SetLabelSize(0.04);
      runfile1zoom9->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile1zoom9->SetMarkerColor(1);
      runfile1zoom9->SetLineColor(1);
      runfile1zoom9->Draw("");

      c1->cd(6);
      TH1F *runfile2zoom9= (TH1F*)hfile2->Get("h_AamplitudewithPedSubtr_RADDAM_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      runfile2zoom9->SetMarkerStyle(20);
      runfile2zoom9->SetMarkerSize(0.8);
      runfile2zoom9->GetYaxis()->SetLabelSize(0.04);
      runfile2zoom9->SetXTitle("ADCAmpl m1MAXp2 in each event & cell HE \b");
      runfile2zoom9->SetMarkerColor(2);
      runfile2zoom9->SetLineColor(2);
      runfile2zoom9->Draw("");

      c1->Update();


      //============================================================================================= 9
      //======================================================================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *rrrrrr1= (TH1F*)hfile1->Get("h_mapDepth3RADDAM16_HE");
      //    h_mapDepth3RADDAM160_HE
      gPad->SetLogy();
      //      gPad->SetLogx();
      rrrrrr1->SetMarkerStyle(20);
      rrrrrr1->SetMarkerSize(0.8);
      rrrrrr1->GetYaxis()->SetLabelSize(0.04);
      rrrrrr1->SetXTitle("channel A for eta16_HE \b");
      rrrrrr1->SetMarkerColor(3);
      rrrrrr1->SetLineColor(3);
      rrrrrr1->Draw("");

      c1->cd(2);
      TH1F *rrrrrr2= (TH1F*)hfile1->Get("h_sumphiEta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      rrrrrr2->SetMarkerStyle(20);
      rrrrrr2->SetMarkerSize(0.8);
      rrrrrr2->GetYaxis()->SetLabelSize(0.04);
      rrrrrr2->SetXTitle("sector A for eta16_HE \b");
      rrrrrr2->SetMarkerColor(1);
      rrrrrr2->SetLineColor(1);
      rrrrrr2->Draw("");
      TH1F *prrrrr2= (TH1F*)hfile1->Get("h_sumphiEta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      prrrrr2->SetMarkerStyle(20);
      prrrrr2->SetMarkerSize(0.8);
      prrrrr2->GetYaxis()->SetLabelSize(0.04);
      prrrrr2->SetXTitle("sector A for eta16_HE \b");
      prrrrr2->SetMarkerColor(2);
      prrrrr2->SetLineColor(2);
      prrrrr2->Draw("Same");
      TH1F *arrrrr2= (TH1F*)hfile1->Get("h_sumphiEta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      arrrrr2->SetMarkerStyle(20);
      arrrrr2->SetMarkerSize(0.8);
      arrrrr2->GetYaxis()->SetLabelSize(0.04);
      arrrrr2->SetXTitle("sector A for eta16_HE \b");
      arrrrr2->SetMarkerColor(4);
      arrrrr2->SetLineColor(4);
      arrrrr2->Draw("Same");

      c1->cd(3);
      TH1F *rrrrrr3= (TH1F*)hfile1->Get("h_Eta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      rrrrrr3->SetMarkerStyle(20);
      rrrrrr3->SetMarkerSize(0.8);
      rrrrrr3->GetYaxis()->SetLabelSize(0.04);
      rrrrrr3->SetXTitle("<channel A> for eta16_HE \b");
      rrrrrr3->SetMarkerColor(1);
      rrrrrr3->SetLineColor(1);
      rrrrrr3->Draw("");
      TH1F *prrrrr3= (TH1F*)hfile1->Get("h_Eta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      prrrrr3->SetMarkerStyle(20);
      prrrrr3->SetMarkerSize(0.8);
      prrrrr3->GetYaxis()->SetLabelSize(0.04);
      prrrrr3->SetXTitle("<channel A> for eta16_HE \b");
      prrrrr3->SetMarkerColor(2);
      prrrrr3->SetLineColor(2);
      prrrrr3->Draw("Same");
      TH1F *arrrrr3= (TH1F*)hfile1->Get("h_Eta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      arrrrr3->SetMarkerStyle(20);
      arrrrr3->SetMarkerSize(0.8);
      arrrrr3->GetYaxis()->SetLabelSize(0.04);
      arrrrr3->SetXTitle("<channel A> for eta16_HE \b");
      arrrrr3->SetMarkerColor(4);
      arrrrr3->SetLineColor(4);
      arrrrr3->Draw("Same");

      c1->cd(4);
      TH1F *rrrrrr4= (TH1F*)hfile1->Get("h_NphiForEta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      rrrrrr4->SetMarkerStyle(20);
      rrrrrr4->SetMarkerSize(0.8);
      rrrrrr4->GetYaxis()->SetLabelSize(0.04);
      rrrrrr4->SetXTitle("NphiSectors for eta16_HE");
      rrrrrr4->SetMarkerColor(1);
      rrrrrr4->SetLineColor(1);
      rrrrrr4->Draw("");
      TH1F *prrrrr4= (TH1F*)hfile1->Get("h_NphiForEta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      prrrrr4->SetMarkerStyle(20);
      prrrrr4->SetMarkerSize(0.8);
      prrrrr4->GetYaxis()->SetLabelSize(0.04);
      prrrrr4->SetXTitle("NphiSectors for eta16_HE");
      prrrrr4->SetMarkerColor(2);
      prrrrr4->SetLineColor(2);
      prrrrr4->Draw("Same");
      TH1F *arrrrr4= (TH1F*)hfile1->Get("h_NphiForEta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      arrrrr4->SetMarkerStyle(20);
      arrrrr4->SetMarkerSize(0.8);
      arrrrr4->GetYaxis()->SetLabelSize(0.04);
      arrrrr4->SetXTitle("NphiSectors for eta16_HE");
      arrrrr4->SetMarkerColor(4);
      arrrrr4->SetLineColor(4);
      arrrrr4->Draw("Same");

      c1->Update();


      //============================================================================================= 10
      //======================================================================
      //======================================================================
      //================
      //======================================================================
      //================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *file2r1= (TH1F*)hfile2->Get("h_mapDepth3RADDAM16_HE");
      //    h_mapDepth3RADDAM160_HE
      gPad->SetLogy();
      //      gPad->SetLogx();
      file2r1->SetMarkerStyle(20);
      file2r1->SetMarkerSize(0.8);
      file2r1->GetYaxis()->SetLabelSize(0.04);
      file2r1->SetXTitle("Run2 channel A for eta16_HE \b");
      file2r1->SetMarkerColor(3);
      file2r1->SetLineColor(3);
      file2r1->Draw("");

      c1->cd(2);
      TH1F *file2r2= (TH1F*)hfile2->Get("h_sumphiEta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      file2r2->SetMarkerStyle(20);
      file2r2->SetMarkerSize(0.8);
      file2r2->GetYaxis()->SetLabelSize(0.04);
      file2r2->SetXTitle("Run2 sector A  for eta16_HE \b");
      file2r2->SetMarkerColor(1);
      file2r2->SetLineColor(1);
      file2r2->Draw("");
      TH1F *pfile22= (TH1F*)hfile2->Get("h_sumphiEta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      pfile22->SetMarkerStyle(20);
      pfile22->SetMarkerSize(0.8);
      pfile22->GetYaxis()->SetLabelSize(0.04);
      pfile22->SetXTitle("Run2 sector A  for eta16_HE \b");
      pfile22->SetMarkerColor(2);
      pfile22->SetLineColor(2);
      pfile22->Draw("Same");
      TH1F *afile22= (TH1F*)hfile2->Get("h_sumphiEta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      afile22->SetMarkerStyle(20);
      afile22->SetMarkerSize(0.8);
      afile22->GetYaxis()->SetLabelSize(0.04);
      afile22->SetXTitle("Run2 sector A  for eta16_HE \b");
      afile22->SetMarkerColor(4);
      afile22->SetLineColor(4);
      afile22->Draw("Same");

      c1->cd(3);
      TH1F *file2r3= (TH1F*)hfile2->Get("h_Eta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      file2r3->SetMarkerStyle(20);
      file2r3->SetMarkerSize(0.8);
      file2r3->GetYaxis()->SetLabelSize(0.04);
      file2r3->SetXTitle("Run2 <channel A> for eta16_HE \b");
      file2r3->SetMarkerColor(1);
      file2r3->SetLineColor(1);
      file2r3->Draw("");
      TH1F *pfile23= (TH1F*)hfile2->Get("h_Eta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      pfile23->SetMarkerStyle(20);
      pfile23->SetMarkerSize(0.8);
      pfile23->GetYaxis()->SetLabelSize(0.04);
      pfile23->SetXTitle("Run2 <channel A> for eta16_HE \b");
      pfile23->SetMarkerColor(2);
      pfile23->SetLineColor(2);
      pfile23->Draw("Same");
      TH1F *afile23= (TH1F*)hfile2->Get("h_Eta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      afile23->SetMarkerStyle(20);
      afile23->SetMarkerSize(0.8);
      afile23->GetYaxis()->SetLabelSize(0.04);
      afile23->SetXTitle("Run2 <channel A> for eta16_HE \b");
      afile23->SetMarkerColor(4);
      afile23->SetLineColor(4);
      afile23->Draw("Same");

      c1->cd(4);
      TH1F *file2r4= (TH1F*)hfile2->Get("h_NphiForEta16Depth3RADDAM_HED2");
      gPad->SetLogy();
      //      gPad->SetLogx();
      file2r4->SetMarkerStyle(20);
      file2r4->SetMarkerSize(0.8);
      file2r4->GetYaxis()->SetLabelSize(0.04);
      file2r4->SetXTitle("NphiSectors for eta16_HE");
      file2r4->SetMarkerColor(1);
      file2r4->SetLineColor(1);
      file2r4->Draw("");
      TH1F *pfile24= (TH1F*)hfile2->Get("h_NphiForEta16Depth3RADDAM_HED2P");
      gPad->SetLogy();
      //      gPad->SetLogx();
      pfile24->SetMarkerStyle(20);
      pfile24->SetMarkerSize(0.8);
      pfile24->GetYaxis()->SetLabelSize(0.04);
      pfile24->SetXTitle("Run2 NphiSectors for eta16_HE");
      pfile24->SetMarkerColor(2);
      pfile24->SetLineColor(2);
      pfile24->Draw("Same");
      TH1F *afile24= (TH1F*)hfile2->Get("h_NphiForEta16Depth3RADDAM_HED2ALL");
      gPad->SetLogy();
      //      gPad->SetLogx();
      afile24->SetMarkerStyle(20);
      afile24->SetMarkerSize(0.8);
      afile24->GetYaxis()->SetLabelSize(0.04);
      afile24->SetXTitle("Run2 NphiSectors for eta16_HE");
      afile24->SetMarkerColor(4);
      afile24->SetLineColor(4);
      afile24->Draw("Same");

      c1->Update();


    //======================================================================
    //============================================================================================= sigLayers:
    //======================================================================
    //============================================================================================= 11
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
      
      
            
    //============================================================================================= 12
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
      
      
            
    //============================================================================================= 13
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
      
      
            
    //============================================================================================= 14
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
      
      
            
    //============================================================================================= 15
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


    //============================================================================================= 16
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
    //============================================================================================= sigLayers:
    //======================================================================
    //============================================================================================= 17
    //======================================================================
    //======================================================================
    //======================================================================
    //====================================================================== Ratio
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *pmmmlauer11= (TH1F*)hfile1->Get("h_sigLayer1RADDAM5_HED2");
      TH1F *pmmmlauer10= (TH1F*)hfile1->Get("h_sigLayer1RADDAM6_HED2");
      pmmmlauer11->Sumw2();
      pmmmlauer10->Sumw2();
      //    if(pmmmlauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Cmmmlauer1 = (TH1F*)pmmmlauer11->Clone("Cmmmlauer1");
	Cmmmlauer1->Divide(pmmmlauer11,pmmmlauer10, 1, 1, "B");
	Cmmmlauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      // gPad->SetLogz();
      Cmmmlauer1->SetMarkerStyle(20);
      Cmmmlauer1->SetMarkerSize(0.8);
      Cmmmlauer1->GetYaxis()->SetLabelSize(0.04);
      //    Cmmmlauer1->SetTitle("any Error, HE Mmmlayer1 \n");
      Cmmmlauer1->SetXTitle("L1 Ratio for 1st Run - HE #eta");
      Cmmmlauer1->SetYTitle("Ratio");
      Cmmmlauer1->SetMarkerColor(1);
      Cmmmlauer1->SetLineColor(1);
      Cmmmlauer1->SetMaximum(1.1);
      Cmmmlauer1->SetMinimum(0.0);
      Cmmmlauer1->Draw("");
      //    }
      
      c1->cd(2);
      TH1F *tmmmlauer11= (TH1F*)hfile2->Get("h_sigLayer1RADDAM5_HED2");
      TH1F *tmmmlauer10= (TH1F*)hfile2->Get("h_sigLayer1RADDAM6_HED2");
      tmmmlauer11->Sumw2();
      tmmmlauer10->Sumw2();
      //    if(tmmmlauer10->IsA()->InheritsFrom("TH1F")){
	TH1F* Smmmlauer1 = (TH1F*)tmmmlauer11->Clone("Smmmlauer1");
	Smmmlauer1->Divide(tmmmlauer11,tmmmlauer10, 1, 1, "B");
	Smmmlauer1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      //  gPad->SetLogz();
      Smmmlauer1->SetMarkerStyle(20);
      Smmmlauer1->SetMarkerSize(0.8);
      Smmmlauer1->GetYaxis()->SetLabelSize(0.04);
      //    Smmmlauer1->SetTitle("any Error, HE Mmmlayer1 \n");
      Smmmlauer1->SetXTitle("L1 Ratio for 2nd Run - HE #eta");
      Smmmlauer1->SetYTitle("Ratio");
      Smmmlauer1->SetMarkerColor(1);
      Smmmlauer1->SetLineColor(1);
      Smmmlauer1->SetMaximum(1.1);
      Smmmlauer1->SetMinimum(0.0);
      Smmmlauer1->Draw("");
      //    }
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Mmmlauer1_HE = (TH1F*)Cmmmlauer1->Clone("Diffe_Mmmlauer1_HE");
      Diffe_Mmmlauer1_HE->Sumw2();
      for (int i=1;i<=Cmmmlauer1->GetXaxis()->GetNbins();i++) {
	  Diffe_Mmmlauer1_HE->SetBinContent(i,0.);
	  if(Cmmmlauer1->GetBinContent(i) !=0 && Smmmlauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Smmmlauer1->GetBinContent(i)/Cmmmlauer1->GetBinContent(i)  ;
	    //	    double ccc1 =  Cmmmlauer1->GetBinContent(i)-Smmmlauer1->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Cmmmlauer1->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Mmmlauer1_HE->SetBinContent(i,fabs(ccc1));
	    Diffe_Mmmlauer1_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Mmmlauer1_HE->SetMarkerStyle(20);
    Diffe_Mmmlauer1_HE->SetMarkerSize(0.4);
    Diffe_Mmmlauer1_HE->GetYaxis()->SetLabelSize(0.06);
    Diffe_Mmmlauer1_HE->SetXTitle("|A2/A1| - L1_HE#eta");
    Diffe_Mmmlauer1_HE->SetYTitle("|A2/A1|");
    Diffe_Mmmlauer1_HE->SetMarkerColor(1);
    Diffe_Mmmlauer1_HE->SetLineColor(1);
    Diffe_Mmmlauer1_HE->Draw("");
    
    
    c1->cd(4);
    TH1F* diffAmpl_Mmmlauer1_HE = new TH1F("diffAmpl_Mmmlauer1_HE","", 100, 0., 2.);
    for (int i=1;i<=Cmmmlauer1->GetXaxis()->GetNbins();i++) {
      if(Cmmmlauer1->GetBinContent(i) !=0 && Smmmlauer1->GetBinContent(i) !=0 ) {
	    double ccc1 =  Smmmlauer1->GetBinContent(i)/Cmmmlauer1->GetBinContent(i)  ;
	    //double ccc1 =  Cmmmlauer1->GetBinContent(i)-Smmmlauer1->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Cmmmlauer1->GetBinContent(i);
	diffAmpl_Mmmlauer1_HE->Fill(fabs(ccc1));
      }
    }
    gPad->SetLogy();
      diffAmpl_Mmmlauer1_HE->SetMarkerStyle(20);
      diffAmpl_Mmmlauer1_HE->SetMarkerSize(0.4);
      diffAmpl_Mmmlauer1_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Mmmlauer1_HE->SetTitle("AmplRunsDifference L1_HE \n");
      diffAmpl_Mmmlauer1_HE->SetXTitle("|A2/A1| - L1_HE");
      diffAmpl_Mmmlauer1_HE->SetMarkerColor(2);
      diffAmpl_Mmmlauer1_HE->SetLineColor(2);
      diffAmpl_Mmmlauer1_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 18
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *pmmmlauer21= (TH1F*)hfile1->Get("h_sigLayer2RADDAM5_HED2");
      TH1F *pmmmlauer20= (TH1F*)hfile1->Get("h_sigLayer2RADDAM6_HED2");
      pmmmlauer21->Sumw2();
      pmmmlauer20->Sumw2();
	TH1F* Cmmmlauer2 = (TH1F*)pmmmlauer21->Clone("Cmmmlauer2");
	Cmmmlauer2->Divide(pmmmlauer21,pmmmlauer20, 1, 1, "B");
	Cmmmlauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Cmmmlauer2->SetMarkerStyle(20);
      Cmmmlauer2->SetMarkerSize(0.8);
      Cmmmlauer2->GetYaxis()->SetLabelSize(0.04);
      Cmmmlauer2->SetXTitle("L7 Ratio for 1st Run - HE  #eta");
      Cmmmlauer2->SetYTitle("Ratio");
      Cmmmlauer2->SetMarkerColor(2);
      Cmmmlauer2->SetLineColor(2);
      Cmmmlauer2->SetMaximum(1.1);
      Cmmmlauer2->SetMinimum(0.0);
      Cmmmlauer2->Draw("");
      
      c1->cd(2);
      TH1F *tmmmlauer21= (TH1F*)hfile2->Get("h_sigLayer2RADDAM5_HED2");
      TH1F *tmmmlauer20= (TH1F*)hfile2->Get("h_sigLayer2RADDAM6_HED2");
      tmmmlauer21->Sumw2();
      tmmmlauer20->Sumw2();
	TH1F* Smmmlauer2 = (TH1F*)tmmmlauer21->Clone("Smmmlauer2");
	Smmmlauer2->Divide(tmmmlauer21,tmmmlauer20, 1, 1, "B");
	Smmmlauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Smmmlauer2->SetMarkerStyle(20);
      Smmmlauer2->SetMarkerSize(0.8);
      Smmmlauer2->GetYaxis()->SetLabelSize(0.04);
      Smmmlauer2->SetXTitle("L7 Ratio for 2nd Run - HE #eta");
      Smmmlauer2->SetYTitle("Ratio");
      Smmmlauer2->SetMarkerColor(2);
      Smmmlauer2->SetLineColor(2);
      Smmmlauer2->SetMaximum(1.1);
      Smmmlauer2->SetMinimum(0.0);
      Smmmlauer2->Draw("");
      
      c1->cd(3);


    ///////////////////////////////////////
      TH1F* Diffe_Mmmlauer2_HE = (TH1F*)Cmmmlauer2->Clone("Diffe_Mmmlauer2_HE");
      Diffe_Mmmlauer2_HE->Sumw2();
      for (int i=1;i<=Cmmmlauer2->GetXaxis()->GetNbins();i++) {
	  Diffe_Mmmlauer2_HE->SetBinContent(i,0.);
	  if(Cmmmlauer2->GetBinContent(i) !=0 && Smmmlauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Smmmlauer2->GetBinContent(i)/Cmmmlauer2->GetBinContent(i)  ;
	    //	    double ccc1 =  Cmmmlauer2->GetBinContent(i)-Smmmlauer2->GetBinContent(i)  ;
	    //ccc1 = 100.*ccc1/Cmmmlauer2->GetBinContent(i);
	    //	    if(fabs(ccc1) > 2.)  Diffe_Mmmlauer2_HE->SetBinContent(i,fabs(ccc1));
	    //	    std::cout <<"333333 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	    Diffe_Mmmlauer2_HE->SetBinContent(i,fabs(ccc1));
	  }
      }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Mmmlauer2_HE->SetMarkerStyle(20);
    Diffe_Mmmlauer2_HE->SetMarkerSize(0.4);
    Diffe_Mmmlauer2_HE->GetYaxis()->SetLabelSize(0.04);
    Diffe_Mmmlauer2_HE->SetXTitle("|A2/A1| - L7_HE#eta");
    Diffe_Mmmlauer2_HE->SetYTitle("|A2/A1|");
    Diffe_Mmmlauer2_HE->SetMarkerColor(2);
    Diffe_Mmmlauer2_HE->SetLineColor(2);
    Diffe_Mmmlauer2_HE->Draw("");
    
    
    //    std::cout <<"============================================================ " << std::endl; 
      c1->cd(4);
      TH1F* diffAmpl_Mmmlauer2_HE = new TH1F("diffAmpl_Mmmlauer2_HE","", 100, 0., 2.);
      for (int i=1;i<=Cmmmlauer2->GetXaxis()->GetNbins();i++) {
	if(Cmmmlauer2->GetBinContent(i) !=0 && Smmmlauer2->GetBinContent(i) !=0 ) {
	    double ccc1 =  Smmmlauer2->GetBinContent(i)/Cmmmlauer2->GetBinContent(i)  ;
	    //	  double ccc1 =  Cmmmlauer2->GetBinContent(i)-Smmmlauer2->GetBinContent(i);
	    //ccc1 = 100.*ccc1/Cmmmlauer2->GetBinContent(i);
	    //	    std::cout <<"444444 i = " << i <<" ccc1 = " << ccc1 << std::endl; 
	  diffAmpl_Mmmlauer2_HE->Fill(fabs(ccc1));
	}
      }
      gPad->SetLogy();
      diffAmpl_Mmmlauer2_HE->SetMarkerStyle(20);
      diffAmpl_Mmmlauer2_HE->SetMarkerSize(0.4);
      diffAmpl_Mmmlauer2_HE->GetYaxis()->SetLabelSize(0.04);
      diffAmpl_Mmmlauer2_HE->SetTitle("AmplRunsDifference L7_HE \n");
      diffAmpl_Mmmlauer2_HE->SetXTitle("|A2/A1| - L7_HE");
      diffAmpl_Mmmlauer2_HE->SetMarkerColor(2);
      diffAmpl_Mmmlauer2_HE->SetLineColor(2);
      diffAmpl_Mmmlauer2_HE->Draw("");
      
      c1->Update();
      
      
            
    //============================================================================================= 19
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      Cmmmlauer1->Draw("");
      Cmmmlauer2->Draw("Same");

      c1->cd(2);
      Smmmlauer1->Draw("");
      Smmmlauer2->Draw("Same");

      c1->Update();


    //============================================================================================= 20
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      Diffe_Mmmlauer1_HE->Draw("");
      Diffe_Mmmlauer2_HE->Draw("Same");


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

