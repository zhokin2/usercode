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
          TPostScript psfile ("zraddam2.ps", 111);
//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //============================================================================================= 1
    //======================================================================
    //====================================================================== Ratio
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *plauer11= (TH1F*)hfile1->Get("h_mapLayer1RADDAM5_HED2");
      TH1F *plauer10= (TH1F*)hfile1->Get("h_mapLayer1RADDAM6_HED2");
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
      Clauer1->SetMinimum(0.0);
      Clauer1->Draw("");
      //    }
      
      c1->cd(2);
      TH1F *tlauer11= (TH1F*)hfile2->Get("h_mapLayer1RADDAM5_HED2");
      TH1F *tlauer10= (TH1F*)hfile2->Get("h_mapLayer1RADDAM6_HED2");
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
      Slauer1->SetMinimum(0.0);
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
    Diffe_Lauer1_HE->SetMarkerSize(0.4);
    Diffe_Lauer1_HE->GetYaxis()->SetLabelSize(0.06);
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
      
      
            
    //============================================================================================= 2
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *plauer21= (TH1F*)hfile1->Get("h_mapLayer2RADDAM5_HED2");
      TH1F *plauer20= (TH1F*)hfile1->Get("h_mapLayer2RADDAM6_HED2");
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
      Clauer2->SetMinimum(0.0);
      Clauer2->Draw("");
      
      c1->cd(2);
      TH1F *tlauer21= (TH1F*)hfile2->Get("h_mapLayer2RADDAM5_HED2");
      TH1F *tlauer20= (TH1F*)hfile2->Get("h_mapLayer2RADDAM6_HED2");
      tlauer21->Sumw2();
      tlauer20->Sumw2();
	TH1F* Slauer2 = (TH1F*)tlauer21->Clone("Slauer2");
	Slauer2->Divide(tlauer21,tlauer20, 1, 1, "B");
	Slauer2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      Slauer2->SetMarkerStyle(20);
      Slauer2->SetMarkerSize(0.8);
      Slauer2->GetYaxis()->SetLabelSize(0.04);
      Slauer2->SetXTitle("L7 Ratio for 2nd Run - HE #eta");
      Slauer2->SetYTitle("Ratio");
      Slauer2->SetMarkerColor(2);
      Slauer2->SetLineColor(2);
      Slauer2->SetMaximum(1.1);
      Slauer2->SetMinimum(0.0);
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
    Diffe_Lauer2_HE->SetMarkerSize(0.4);
    Diffe_Lauer2_HE->GetYaxis()->SetLabelSize(0.04);
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
      
      
            
    //============================================================================================= 3
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


    //============================================================================================= 4
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

    //============================================================================================= 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      TH1F *Adiv16layer1= (TH1F*)hfile1->Get("h_Adiv16_Layer1RADDAM_HED2");
      gPad->SetLogy();
      Adiv16layer1->SetMarkerStyle(20);
      Adiv16layer1->SetMarkerSize(0.8);
      Adiv16layer1->GetYaxis()->SetLabelSize(0.04);
      Adiv16layer1->SetXTitle("Adiv16_L1_HE \b");
      Adiv16layer1->SetMarkerColor(2);
      Adiv16layer1->SetLineColor(2);
      Adiv16layer1->Draw("");
      c1->cd(2);
      TH1F *Adiv16layer2= (TH1F*)hfile1->Get("h_Adiv16_Layer2RADDAM_HED2");
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
    //============================================================================================= 6
    //======================================================================
    //======================================================================
    //======================================================================
    //====================================================================== Ratio
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglauer11= (TH1F*)hfile1->Get("h_sigLayer1RADDAM5_HED2");
      TH1F *psiglauer10= (TH1F*)hfile1->Get("h_sigLayer1RADDAM6_HED2");
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
      Csiglauer1->SetMinimum(0.0);
      Csiglauer1->Draw("");
      //    }
      
      c1->cd(2);
      TH1F *tsiglauer11= (TH1F*)hfile2->Get("h_sigLayer1RADDAM5_HED2");
      TH1F *tsiglauer10= (TH1F*)hfile2->Get("h_sigLayer1RADDAM6_HED2");
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
      Ssiglauer1->SetMinimum(0.0);
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
    Diffe_Siglauer1_HE->SetMarkerSize(0.4);
    Diffe_Siglauer1_HE->GetYaxis()->SetLabelSize(0.06);
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
      
      
            
    //============================================================================================= 7
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *psiglauer21= (TH1F*)hfile1->Get("h_sigLayer2RADDAM5_HED2");
      TH1F *psiglauer20= (TH1F*)hfile1->Get("h_sigLayer2RADDAM6_HED2");
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
      Csiglauer2->SetMinimum(0.0);
      Csiglauer2->Draw("");
      
      c1->cd(2);
      TH1F *tsiglauer21= (TH1F*)hfile2->Get("h_sigLayer2RADDAM5_HED2");
      TH1F *tsiglauer20= (TH1F*)hfile2->Get("h_sigLayer2RADDAM6_HED2");
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
      Ssiglauer2->SetMinimum(0.0);
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
    Diffe_Siglauer2_HE->SetMarkerSize(0.4);
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
      
      
            
    //============================================================================================= 8
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


    //============================================================================================= 9
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
