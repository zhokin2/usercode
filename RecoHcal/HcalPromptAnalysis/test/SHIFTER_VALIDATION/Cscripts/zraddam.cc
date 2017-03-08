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
          TPostScript psfile ("zraddam.ps", 111);
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
      /*
      TH2F *kmzz1= (TH2F*)hfile1->Get("h_mapDepth2Ped0_HE");
      TH2F *kmzz0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      kmzz1->Sumw2();
      kmzz0->Sumw2();
        TH2F* Cmegcqx = (TH2F*)kmzz1->Clone("Cmegcqx");
        Cmegcqx->Divide(kmzz1,kmzz0, 1, 1, "B");
        Cmegcqx->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cmegcqx->SetMarkerStyle(20);
      Cmegcqx->SetMarkerSize(0.4);
      Cmegcqx->GetZaxis()->SetLabelSize(0.08);
      Cmegcqx->SetXTitle("#eta \b");
      Cmegcqx->SetYTitle("#phi \b");
      Cmegcqx->SetZTitle("mapDepth2Ped0_HE \b");
      Cmegcqx->SetMarkerColor(2);
      Cmegcqx->SetLineColor(2);
//      Cmegcqx->SetMaximum(1.000);
      // Cmegcqx->SetMinimum(0.1);
      Cmegcqx->Draw("COLZ");

      c1->cd(6);
      TH2F *keut1= (TH2F*)hfile1->Get("h_mapDepth3Ped0_HE");
      TH2F *keut0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      keut1->Sumw2();
      keut0->Sumw2();
        TH2F* Cmegcqz = (TH2F*)keut1->Clone("Cmegcqz");
        Cmegcqz->Divide(keut1,keut0, 1, 1, "B");
        Cmegcqz->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cmegcqz->SetMarkerStyle(20);
      Cmegcqz->SetMarkerSize(0.4);
      Cmegcqz->GetZaxis()->SetLabelSize(0.08);
      Cmegcqz->SetXTitle("#eta \b");
      Cmegcqz->SetYTitle("#phi \b");
      Cmegcqz->SetZTitle("mapDepth3Ped0_HE \b");
      Cmegcqz->SetMarkerColor(2);
      Cmegcqz->SetLineColor(2);
//      Cmegcqz->SetMaximum(1.000);
      // Cmegcqz->SetMinimum(0.1);
      Cmegcqz->Draw("COLZ");
*/
      //    TH1F *abaaac1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
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
      c1->Divide(2,3);

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
      //	    std::cout <<"444444  " << std::endl; 
      TH1F *aaaaab4= (TH1F*)hfile1->Get("h_A_Layer1RADDAM_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      aaaaab4->SetMarkerStyle(20);
      aaaaab4->SetMarkerSize(0.8);
      aaaaab4->GetYaxis()->SetLabelSize(0.04);
      aaaaab4->SetXTitle("h_A_Layer1RADDAM_HE \b");
      aaaaab4->SetMarkerColor(2);
      aaaaab4->SetLineColor(2);
      aaaaab4->Draw("");
      c1->cd(5);
      TH1F *aaaaab5= (TH1F*)hfile1->Get("h_A_Layer2RADDAM_HE");
      gPad->SetLogy();
      //      gPad->SetLogx();
      aaaaab5->SetMarkerStyle(20);
      aaaaab5->SetMarkerSize(0.8);
      aaaaab5->GetYaxis()->SetLabelSize(0.04);
      aaaaab5->SetXTitle("h_A_Layer2RADDAM_HE \b");
      aaaaab5->SetMarkerColor(2);
      aaaaab5->SetLineColor(2);
      aaaaab5->Draw("");
      c1->cd(6);
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
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *kkkkkb1= (TH1F*)hfile1->Get("h_A_Varia1RADDAM_HE");
      gPad->SetLogy();
              gPad->SetLogx();
      kkkkkb1->SetMarkerStyle(20);
      kkkkkb1->SetMarkerSize(0.8);
      kkkkkb1->GetYaxis()->SetLabelSize(0.04);
      kkkkkb1->SetXTitle("h_A_Varia1RADDAM_HE \b");
      kkkkkb1->SetMarkerColor(2);
      kkkkkb1->SetLineColor(2);
      kkkkkb1->Draw("");
      c1->cd(2);
      TH1F *kkkkkb2= (TH1F*)hfile1->Get("h_A_Varia2RADDAM_HE");
      gPad->SetLogy();
            gPad->SetLogx();
      kkkkkb2->SetMarkerStyle(20);
      kkkkkb2->SetMarkerSize(0.8);
      kkkkkb2->GetYaxis()->SetLabelSize(0.04);
      kkkkkb2->SetXTitle("h_A_Varia2RADDAM_HE \b");
      kkkkkb2->SetMarkerColor(2);
      kkkkkb2->SetLineColor(2);
      kkkkkb2->Draw("");
      c1->cd(3);
      TH1F *kkkkkb3= (TH1F*)hfile1->Get("h_A_Varia3RADDAM_HE");
      gPad->SetLogy();
         gPad->SetLogx();
      kkkkkb3->SetMarkerStyle(20);
      kkkkkb3->SetMarkerSize(0.8);
      kkkkkb3->GetYaxis()->SetLabelSize(0.04);
      kkkkkb3->SetXTitle("h_A_Varia3RADDAM_HE \b");
      kkkkkb3->SetMarkerColor(2);
      kkkkkb3->SetLineColor(2);
      kkkkkb3->Draw("");
      c1->cd(4);
      TH1F *kkkkkb4= (TH1F*)hfile1->Get("h_A_Varia4RADDAM_HE");
      gPad->SetLogy();
            gPad->SetLogx();
      kkkkkb4->SetMarkerStyle(20);
      kkkkkb4->SetMarkerSize(0.8);
      kkkkkb4->GetYaxis()->SetLabelSize(0.04);
      kkkkkb4->SetXTitle("h_A_Varia4RADDAM_HE \b");
      kkkkkb4->SetMarkerColor(2);
      kkkkkb4->SetLineColor(2);
      kkkkkb4->Draw("");


      c1->Update();
      //============================================================================================= 7
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
      //============================================================================================= 8
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
      //============================================================================================= 9
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


      //============================================================================================= 10
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


      //============================================================================================= 11
      //======================================================================
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



      /*
    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
             
      c1->cd(1);
      TH2F *twoedepth1he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      ////  TH2F *twoedepth1he1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HE");
      //    TH2F *twoedepth1he0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      //    twoedepth1he1->Sumw2();
      //    twoedepth1he0->Sumw2();
	TH2F* Cdepth1hefz225= (TH2F*)twoedepth1he1->Clone("Cdepth1hefz225");
	//	Cdepth1hefz225->Divide(twoedepth1he1,twoedepth1he0, 1, 1, "B");
	//	Cdepth1hefz225->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth1hefz225->SetMarkerStyle(20);
      Cdepth1hefz225->SetMarkerSize(0.4);
      Cdepth1hefz225->GetYaxis()->SetLabelSize(0.04);
      Cdepth1hefz225->GetZaxis()->SetLabelSize(0.08);
      Cdepth1hefz225->SetXTitle("#eta \b");
      Cdepth1hefz225->SetYTitle("#phi \b");
      //    Cdepth1hefz225->SetZTitle("Rate for ADCAmpl in each event & cell - HE Depth1 \b");
      Cdepth1hefz225->SetZTitle("ADCAmpl in each event & cell - HE Depth1 \b");
      Cdepth1hefz225->SetMarkerColor(2);
      Cdepth1hefz225->SetLineColor(2);
      //    Cdepth1hefz225->SetMaximum(1.000);
      //    Cdepth1hefz225->SetMinimum(0.00001);
      Cdepth1hefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twoedepth1he8= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HE");
	TH2F* Cdepth1hefz228= (TH2F*)twoedepth1he8->Clone("Cdepth1hefz225");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cdepth1hefz228->SetMarkerStyle(20);
      Cdepth1hefz228->SetMarkerSize(0.4);
      Cdepth1hefz228->GetYaxis()->SetLabelSize(0.04);
      Cdepth1hefz228->GetZaxis()->SetLabelSize(0.08);
      Cdepth1hefz228->SetXTitle("#eta \b");
      Cdepth1hefz228->SetYTitle("#phi \b");
      Cdepth1hefz228->SetZTitle("ADCAmpl <min||>max in each event & cell - HE Depth1 \b");
      Cdepth1hefz228->SetMarkerColor(2);
      Cdepth1hefz228->SetLineColor(2);
      //    Cdepth1hefz228->SetMaximum(1.000);
      //    Cdepth1hefz228->SetMinimum(0.00001);
      Cdepth1hefz228->Draw("COLZ");
      
             
      c1->Update();
*/      
