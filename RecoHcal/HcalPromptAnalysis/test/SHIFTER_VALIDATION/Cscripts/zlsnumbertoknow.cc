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

//	TFile *hfile1= new TFile("../PYTHON_runlist_test/Global_283884_1.root", "READ");
//        TFile *hfile1= new TFile("Global_test.root", "READ");

//	TFile *hfile1= new TFile("LED_280702.root", "READ");        
	//	TFile *hfile2= new TFile("LED_287824.root", "READ");

	//	TFile *hfile1= new TFile("LED_284352.root", "READ");        
//	TFile *hfile1= new TFile("LEDtest.root", "READ");
//	TFile *hfile1= new TFile("Global_311668.root", "READ");


//	TFile *hfile1= new TFile("Global_321177_olddefault.root", "READ");
//	TFile *hfile1= new TFile("Global_321177.root", "READ");
//	TFile *hfile1= new TFile("../PYTHON_runlist_1/Global_321177_4.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_4.root", "READ");
	TFile *hfile1= new TFile("Global_321177_4_ls180to220.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_4_ls1to600.root", "READ");


	//	TFile *hfile2= new TFile("LED_284902.root", "READ");
	//	TFile *hfile2= new TFile("LED_284499.root", "READ");
	//	TFile *hfile2= new TFile("LED_284352.root", "READ");

	//	TFile *hfile2= new TFile("LED_286590.root", "READ");



	//    getchar();
	//
          TPostScript psfile ("zlsnumbertoknow.ps", 111);


//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);

      c1->cd(1);
      TH1F *Rate1= (TH1F*)hfile1->Get("h_nevents_per_eachRealLS");
      //    gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //    Rate1->SetXTitle("nevents_per_eachRealLS \b");
      //    Rate1->Draw("");

      int maxbins = 0;
      int nx = Rate1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
	if(ccc1>0.) cout<<" ibin=     "<< i <<" nevents=     "<< ccc1 <<endl;
      }
      cout<<" maxbins=     "<< maxbins <<endl;

      c1->cd(4);
      TH1F* ADCAmplperLS = new TH1F("ADCAmplperLS","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS  = new TH1F("ADCAmplperLS ","", 600, 1.,601.);
      nx = Rate1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS ->SetMarkerStyle(20);
      ADCAmplperLS ->SetMarkerSize(0.4);
      ADCAmplperLS ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS ->SetXTitle("nevents_per_eachRealLS \b");
      ADCAmplperLS ->SetMarkerColor(2);
      ADCAmplperLS ->SetLineColor(0);
      //        ADCAmplperLS ->SetMaximum(30.0);
      //        ADCAmplperLS ->SetMinimum(20.0);
      ADCAmplperLS ->Draw("Error");

       c1->Update();


    //========================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      //      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS1");
      TH2F *twod1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS1");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS1");
      twod1->Sumw2();
      twod0->Sumw2();
	TH2F* Cefz1= (TH2F*)twod1->Clone("Cefz1");
	Cefz1->Divide(twod1,twod0, 1, 1, "B");
	Cefz1->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz1->SetMarkerStyle(20);
      Cefz1->SetMarkerSize(0.4);
      //    Cefz1->GetYaxis()->SetLabelSize(0.04);
      Cefz1->GetZaxis()->SetLabelSize(0.08);
      Cefz1->SetXTitle("<A>  - HB Depth1                   #eta \b");
      Cefz1->SetYTitle("#phi \b");
      //    Cefz1->SetZTitle("<A>  - HB Depth1 \b");
      Cefz1->SetMarkerColor(2);
      Cefz1->SetLineColor(2);
      //      Cefz1->SetMaximum(1.000);
//            Cefz1->SetMinimum(1.0);
      Cefz1->Draw("COLZ");

      nx = Cefz1->GetXaxis()->GetNbins();
      int ny = Cefz1->GetYaxis()->GetNbins();
      cout<<"HB depth1 nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz1->GetBinContent(i,j);
		if(ccc1>0.) cout<<"HB depth1 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HB depth1
      // eta plot: 26-57  ; phi plot: 1-72 
      // eta       25-56  ; phi       0-71


      c1->cd(2);
      //      TH2F *omwp1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS2");
      TH2F *omwp1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS2");
      TH2F *omwp0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS2");
      omwp1->Sumw2();
      omwp0->Sumw2();
	TH2F* Cefz2= (TH2F*)omwp1->Clone("Cefz2");
	Cefz2->Divide(omwp1,omwp0, 1, 1, "B");
	Cefz2->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz2->SetMarkerStyle(20);
      Cefz2->SetMarkerSize(0.4);
      //    Cefz2->GetYaxis()->SetLabelSize(0.04);
      Cefz2->GetZaxis()->SetLabelSize(0.08);
      Cefz2->SetXTitle("<A>  - HB Depth2                   #eta \b");
      Cefz2->SetYTitle("#phi \b");
      //    Cefz2->SetZTitle("<A>  - HB Depth1 \b");
      Cefz2->SetMarkerColor(2);
      Cefz2->SetLineColor(2);
      //      Cefz2->SetMaximum(1.000);
//            Cefz2->SetMinimum(1.0);
      Cefz2->Draw("COLZ");

      nx = Cefz2->GetXaxis()->GetNbins();
      ny = Cefz2->GetYaxis()->GetNbins();
      cout<<"HB depth2 nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz2->GetBinContent(i,j);
		if(ccc1>0.) cout<<" HB depth2 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HB depth2
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71
      ////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      //      TH2F *ldue1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS3");
      TH2F *ldue1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS3");
      TH2F *ldue0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS3");
      ldue1->Sumw2();
      ldue0->Sumw2();
	TH2F* Cefz3= (TH2F*)ldue1->Clone("Cefz3");
	Cefz3->Divide(ldue1,ldue0, 1, 1, "B");
	Cefz3->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz3->SetMarkerStyle(20);
      Cefz3->SetMarkerSize(0.4);
      //    Cefz3->GetYaxis()->SetLabelSize(0.04);
      Cefz3->GetZaxis()->SetLabelSize(0.08);
      Cefz3->SetXTitle("<A>  - HE Depth1                   #eta \b");
      Cefz3->SetYTitle("#phi \b");
      //    Cefz3->SetZTitle("<A>  - HB Depth1 \b");
      Cefz3->SetMarkerColor(2);
      Cefz3->SetLineColor(2);
      //      Cefz3->SetMaximum(1.000);
//            Cefz3->SetMinimum(1.0);
      Cefz3->Draw("COLZ");

      nx = Cefz3->GetXaxis()->GetNbins();
      ny = Cefz3->GetYaxis()->GetNbins();
      cout<<"HE depth1  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz3->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HE depth1 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HE depth1
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71

      c1->cd(4);
      //      TH2F *sdfg1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS4");
      TH2F *sdfg1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS4");
      TH2F *sdfg0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS4");
      sdfg1->Sumw2();
      sdfg0->Sumw2();
	TH2F* Cefz4= (TH2F*)sdfg1->Clone("Cefz4");
	Cefz4->Divide(sdfg1,sdfg0, 1, 1, "B");
	Cefz4->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz4->SetMarkerStyle(20);
      Cefz4->SetMarkerSize(0.4);
      //    Cefz4->GetYaxis()->SetLabelSize(0.04);
      Cefz4->GetZaxis()->SetLabelSize(0.08);
      Cefz4->SetXTitle("<A>  - HE Depth2                   #eta \b");
      Cefz4->SetYTitle("#phi \b");
      //    Cefz4->SetZTitle("<A>  - HB Depth1 \b");
      Cefz4->SetMarkerColor(2);
      Cefz4->SetLineColor(2);
      //      Cefz4->SetMaximum(1.000);
//            Cefz4->SetMinimum(1.0);
      Cefz4->Draw("COLZ");

      nx = Cefz4->GetXaxis()->GetNbins();
      ny = Cefz4->GetYaxis()->GetNbins();
      cout<<"HE depth2  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz4->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HE depth2 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HE depth2
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71


      c1->cd(5);
      //      TH2F *rbnm1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS5");
      TH2F *rbnm1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS5");
      TH2F *rbnm0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS5");
      rbnm1->Sumw2();
      rbnm0->Sumw2();
	TH2F* Cefz5= (TH2F*)rbnm1->Clone("Cefz5");
	Cefz5->Divide(rbnm1,rbnm0, 1, 1, "B");
	Cefz5->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz5->SetMarkerStyle(20);
      Cefz5->SetMarkerSize(0.4);
      //    Cefz5->GetYaxis()->SetLabelSize(0.04);
      Cefz5->GetZaxis()->SetLabelSize(0.08);
      Cefz5->SetXTitle("<A>  - HE Depth3                   #eta \b");
      Cefz5->SetYTitle("#phi \b");
      //    Cefz5->SetZTitle("<A>  - HB Depth1 \b");
      Cefz5->SetMarkerColor(2);
      Cefz5->SetLineColor(2);
      //      Cefz5->SetMaximum(1.000);
//            Cefz5->SetMinimum(1.0);
      Cefz5->Draw("COLZ");

      nx = Cefz5->GetXaxis()->GetNbins();
      ny = Cefz5->GetYaxis()->GetNbins();
      cout<<"HE depth3  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz5->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HE depth3 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HE depth3
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71

      ////////////////////////////////////////////////////////////////////////////////////
      c1->cd(6);
      //      TH2F *plkm1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS6");
      TH2F *plkm1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS6");
      TH2F *plkm0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS6");
      plkm1->Sumw2();
      plkm0->Sumw2();
	TH2F* Cefz6= (TH2F*)plkm1->Clone("Cefz6");
	Cefz6->Divide(plkm1,plkm0, 1, 1, "B");
	Cefz6->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("<A>  - HF Depth1                   #eta \b");
      Cefz6->SetYTitle("#phi \b");
      //    Cefz6->SetZTitle("<A>  - HB Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
//            Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      nx = Cefz6->GetXaxis()->GetNbins();
      ny = Cefz6->GetYaxis()->GetNbins();
      cout<<"HF depth1  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz6->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HF depth1 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HF depth1
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71

      c1->cd(7);
      //      TH2F *epsl1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS7");
      TH2F *epsl1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS7");
      TH2F *epsl0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS7");
      epsl1->Sumw2();
      epsl0->Sumw2();
	TH2F* Cefz7= (TH2F*)epsl1->Clone("Cefz7");
	Cefz7->Divide(epsl1,epsl0, 1, 1, "B");
	Cefz7->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("<A>  - HF Depth2                   #eta \b");
      Cefz7->SetYTitle("#phi \b");
      //    Cefz7->SetZTitle("<A>  - HB Depth1 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
//            Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      nx = Cefz7->GetXaxis()->GetNbins();
      ny = Cefz7->GetYaxis()->GetNbins();
      cout<<"HF depth2  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz7->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HF depth2 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HF depth2
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71


      ////////////////////////////////////////////////////////////////////////////////////
      c1->cd(8);
      //      TH2F *wvbs1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS8");
      TH2F *wvbs1= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS8");
      TH2F *wvbs0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS8");
      wvbs1->Sumw2();
      wvbs0->Sumw2();
	TH2F* Cefz8= (TH2F*)wvbs1->Clone("Cefz8");
	Cefz8->Divide(wvbs1,wvbs0, 1, 1, "B");
	Cefz8->Sumw2();
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz8->SetMarkerStyle(20);
      Cefz8->SetMarkerSize(0.4);
      //    Cefz8->GetYaxis()->SetLabelSize(0.04);
      Cefz8->GetZaxis()->SetLabelSize(0.08);
      Cefz8->SetXTitle("<A>  - HO Depth4                   #eta \b");
      Cefz8->SetYTitle("#phi \b");
      //    Cefz8->SetZTitle("<A>  - HB Depth1 \b");
      Cefz8->SetMarkerColor(2);
      Cefz8->SetLineColor(2);
      //      Cefz8->SetMaximum(1.000);
//            Cefz8->SetMinimum(1.0);
      Cefz8->Draw("COLZ");

      nx = Cefz8->GetXaxis()->GetNbins();
      ny = Cefz8->GetYaxis()->GetNbins();
      cout<<"HO depth4  nx=     "<< nx <<" ny=     "<< ny <<endl;
      for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz8->GetBinContent(i,j);
	if(ccc1>0.) cout<<" HO depth4 ibin=     "<< i <<" jbin=     "<< j <<" A=     "<< ccc1 <<endl;
      }      }
      // HO depth4
      // eta plot: 26,27,56,57 ; phi plot: 1-72 
      // eta       25,26,55,56  ; phi       0-71

      ////////////////////////////////////////////////////////////////////////////////////




       c1->Update();
    //======================================================================
    //======================================================================

    //======================================================================
    //======================================================================

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




      
