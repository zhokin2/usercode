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
	//		   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//	TFile *hfile1= new TFile("Global_321177_41.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600.root_no41", "READ");

//	TFile *hfile1= new TFile("Global_325001_ls1to600.root", "READ");

//	TFile *hfile1= new TFile("Global_RBX_325001_40.root", "READ");
//	TFile *hfile1= new TFile("Global_RBX_325001_ls1to600.root", "READ");


////////////////////////////////////////////////////////////

//	TFile *hfile1= new TFile("Global_321177_41_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap_no41.root", "READ");

//	TFile *hfile1= new TFile("Global_325001_ls1to600_abortgap.root", "READ");


//	TFile *hfile1= new TFile("Global_321624_1.root", "READ");
//	TFile *hfile1= new TFile("Global_321625.root", "READ");
	TFile *hfile1= new TFile("Global_321313.root", "READ");





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//    getchar();
	//
          TPostScript psfile ("zRunEstimator1.ps", 111);


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
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS1 divided by 
      //              h_2D0sumADCAmplLS1       ................. definition 2.
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS1");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS1");
      twod1->Sumw2();
      twod0->Sumw2();
      //    if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz1= (TH2F*)twod1->Clone("Cefz1");
	Cefz1->Divide(twod1,twod0, 1, 1, "B");
	Cefz1->Sumw2();
	//    }
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

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      //    if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
	//    }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
//            Rate1->SetMinimum(24.);
      Rate1->Draw("Error");


      int maxbins = 0;
      int nx = Rate1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
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
      ADCAmplperLS ->SetXTitle("<ADCAmpl> per LS HB1 \b");
      ADCAmplperLS ->SetMarkerColor(2);
      ADCAmplperLS ->SetLineColor(0);
          ADCAmplperLS ->SetMaximum(30.0);
          ADCAmplperLS ->SetMinimum(20.0);
      ADCAmplperLS ->Draw("Error");
       c1->Update();


    //========================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_sumADCAmplLS2");
      gPad->SetLogy();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth2\b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
      aaaaaa2->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS2 divided by 
      //              h_2D0sumADCAmplLS2       ................. definition 2.
      c1->cd(2);
      TH2F *pedk1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS2");
      TH2F *pedk0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS2");
     pedk1->Sumw2();
     pedk0->Sumw2();
      //    if(pedk0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz2= (TH2F*)pedk1->Clone("Cefz2");
	Cefz2->Divide(pedk1,pedk0, 1, 1, "B");
	Cefz2->Sumw2();
	//    }
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

      c1->cd(3);
      TH1F *pedk3= (TH1F*)hfile1->Get("h_sumADCAmplperLS2");
      TH1F *pedk2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS2");
     pedk3->Sumw2();
     pedk2->Sumw2();
      gPad->SetGridy();
      //    if(pedk2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)pedk3->Clone("Rate2");
	Rate2->Divide(pedk3,pedk2, 1, 1, "B");
	Rate2->Sumw2();
	//    }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
//            Rate2->SetMinimum(24.);
      Rate2->Draw("Error");


      maxbins = 0;
      nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS2 = new TH1F("ADCAmplperLS2","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS2  = new TH1F("ADCAmplperLS2 ","", 600, 1.,601.);
      nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS2 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS2 ->SetMarkerStyle(20);
      ADCAmplperLS2 ->SetMarkerSize(0.4);
      ADCAmplperLS2 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS2 ->SetXTitle("<ADCAmpl> per LS HB2 \b");
      ADCAmplperLS2 ->SetMarkerColor(2);
      ADCAmplperLS2 ->SetLineColor(0);
          ADCAmplperLS2 ->SetMaximum(30.0);
          ADCAmplperLS2 ->SetMinimum(20.0);
      ADCAmplperLS2 ->Draw("Error");
       c1->Update();



    //========================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_sumADCAmplLS3");
      gPad->SetLogy();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth1\b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
      aaaaaa3->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS3 divided by 
      //              h_2D0sumADCAmplLS3       ................. definition 2.
      c1->cd(2);
      TH2F *pqmx1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS3");
      TH2F *pqmx0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS3");
     pqmx1->Sumw2();
     pqmx0->Sumw2();
      //    if(pqmx0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz3= (TH2F*)pqmx1->Clone("Cefz2");
	Cefz3->Divide(pqmx1,pqmx0, 1, 1, "B");
	Cefz3->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz3->SetMarkerStyle(20);
      Cefz3->SetMarkerSize(0.4);
      //    Cefz2->GetYaxis()->SetLabelSize(0.04);
      Cefz3->GetZaxis()->SetLabelSize(0.08);
      Cefz3->SetXTitle("<A>  - HE Depth1                   #eta \b");
      Cefz3->SetYTitle("#phi \b");
      //    Cefz2->SetZTitle("<A>  - HE Depth1 \b");
      Cefz3->SetMarkerColor(2);
      Cefz3->SetLineColor(2);
      //      Cefz2->SetMaximum(1.000);
//            Cefz2->SetMinimum(1.0);
      Cefz3->Draw("COLZ");

      c1->cd(3);
      TH1F *pqmx3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3");
      TH1F *pqmx2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3");
     pqmx3->Sumw2();
     pqmx2->Sumw2();
      gPad->SetGridy();
      //    if(pqmx2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)pqmx3->Clone("Rate3");
	Rate3->Divide(pqmx3,pqmx2, 1, 1, "B");
	Rate3->Sumw2();
	//    }
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(0);
//            Rate2->SetMinimum(24.);
      Rate3->Draw("Error");


      maxbins = 0;
      nx = Rate3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate3->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS3 = new TH1F("ADCAmplperLS3","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS3  = new TH1F("ADCAmplperLS3 ","", 600, 1.,601.);
      nx = Rate3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS3 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS3 ->SetMarkerStyle(20);
      ADCAmplperLS3 ->SetMarkerSize(0.4);
      ADCAmplperLS3 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS3 ->SetXTitle("<ADCAmpl> per LS HE1 \b");
      ADCAmplperLS3 ->SetMarkerColor(2);
      ADCAmplperLS3 ->SetLineColor(0);
      //        ADCAmplperLS3 ->SetMaximum(30.0);
      //        ADCAmplperLS3 ->SetMinimum(0.0);
      ADCAmplperLS3 ->Draw("Error");
       c1->Update();



    //========================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_sumADCAmplLS4");
      gPad->SetLogy();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth2\b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
      aaaaaa4->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS4 divided by 
      //              h_2D0sumADCAmplLS4       ................. definition 2.
      c1->cd(2);
      TH2F *pyen1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS4");
      TH2F *pyen0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS4");
     pyen1->Sumw2();
     pyen0->Sumw2();
      //    if(pyen0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz4= (TH2F*)pyen1->Clone("Cefz4");
	Cefz4->Divide(pyen1,pyen0, 1, 1, "B");
	Cefz4->Sumw2();
	//    }
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

      c1->cd(3);
      TH1F *pyen3= (TH1F*)hfile1->Get("h_sumADCAmplperLS4");
      TH1F *pyen2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS4");
     pyen3->Sumw2();
     pyen2->Sumw2();
      gPad->SetGridy();
      //    if(pyen2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate4 = (TH1F*)pyen3->Clone("Rate2");
	Rate2->Divide(pyen3,pyen2, 1, 1, "B");
	Rate2->Sumw2();
	//    }
      Rate4->SetMarkerStyle(20);
      Rate4->SetMarkerSize(0.8);
      Rate4->SetXTitle("<A>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      Rate4->SetMarkerColor(2);
      Rate4->SetLineColor(0);
//            Rate4->SetMinimum(24.);
      Rate4->Draw("Error");


      maxbins = 0;
      nx = Rate4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate4->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS4 = new TH1F("ADCAmplperLS4","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS4  = new TH1F("ADCAmplperLS4 ","", 600, 1.,601.);
      nx = Rate4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS4 ->SetMarkerStyle(20);
      ADCAmplperLS4 ->SetMarkerSize(0.4);
      ADCAmplperLS4 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS4 ->SetXTitle("<ADCAmpl> per LS HE2 \b");
      ADCAmplperLS4 ->SetMarkerColor(2);
      ADCAmplperLS4 ->SetLineColor(0);
      //        ADCAmplperLS4 ->SetMaximum(30.0);
      //        ADCAmplperLS4 ->SetMinimum(20.0);
      ADCAmplperLS4 ->Draw("Error");
       c1->Update();



    //========================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa5= (TH1F*)hfile1->Get("h_sumADCAmplLS5");
      gPad->SetLogy();
      aaaaaa5->SetMarkerStyle(20);
      aaaaaa5->SetMarkerSize(0.8);
      aaaaaa5->GetYaxis()->SetLabelSize(0.04);
      aaaaaa5->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth3\b");
      aaaaaa5->SetMarkerColor(4);
      aaaaaa5->SetLineColor(0);
      aaaaaa5->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS5 divided by 
      //              h_2D0sumADCAmplLS5       ................. definition 2.
      c1->cd(2);
      TH2F *mkrz1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS5");
      TH2F *mkrz0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS5");
     mkrz1->Sumw2();
     mkrz0->Sumw2();
      //    if(mkrz0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz5= (TH2F*)mkrz1->Clone("Cefz5");
	Cefz5->Divide(mkrz1,mkrz0, 1, 1, "B");
	Cefz5->Sumw2();
	//    }
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

      c1->cd(3);
      TH1F *mkrz3= (TH1F*)hfile1->Get("h_sumADCAmplperLS5");
      TH1F *mkrz2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS5");
     mkrz3->Sumw2();
     mkrz2->Sumw2();
      gPad->SetGridy();
      //    if(mkrz2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate5 = (TH1F*)mkrz3->Clone("Rate5");
	Rate5->Divide(mkrz3,mkrz2, 1, 1, "B");
	Rate5->Sumw2();
	//    }
      Rate5->SetMarkerStyle(20);
      Rate5->SetMarkerSize(0.8);
      Rate5->SetXTitle("<A>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      Rate5->SetMarkerColor(2);
      Rate5->SetLineColor(0);
//            Rate5->SetMinimum(24.);
      Rate5->Draw("Error");


      maxbins = 0;
      nx = Rate5->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate5->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS5 = new TH1F("ADCAmplperLS5","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS5  = new TH1F("ADCAmplperLS5 ","", 600, 1.,601.);
      nx = Rate5->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate5->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS5 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS5 ->SetMarkerStyle(20);
      ADCAmplperLS5 ->SetMarkerSize(0.4);
      ADCAmplperLS5 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS5 ->SetXTitle("<ADCAmpl> per LS HE3 \b");
      ADCAmplperLS5 ->SetMarkerColor(2);
      ADCAmplperLS5 ->SetLineColor(0);
      //        ADCAmplperLS5 ->SetMaximum(30.0);
      //        ADCAmplperLS5 ->SetMinimum(20.0);
      ADCAmplperLS5 ->Draw("Error");
       c1->Update();



    //========================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumADCAmplLS6");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("<A>(ev.in LS) in LSs & channels - HF depth1\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      aaaaaa6->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS6 divided by 
      //              h_2D0sumADCAmplLS6       ................. definition 2.
      c1->cd(2);
      TH2F *juqm1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS6");
      TH2F *juqm0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS6");
     juqm1->Sumw2();
     juqm0->Sumw2();
      //    if(juqm0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6= (TH2F*)juqm1->Clone("Cefz6");
	Cefz6->Divide(juqm1,juqm0, 1, 1, "B");
	Cefz6->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("<A>  - HF Depth1                   #eta \b");
      Cefz6->SetYTitle("#phi \b");
      //    Cefz6->SetZTitle("<A>  - HF Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
//            Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *juqm3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6");
      TH1F *juqm2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6");
     juqm3->Sumw2();
     juqm2->Sumw2();
      gPad->SetGridy();
      //    if(juqm2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate6 = (TH1F*)juqm3->Clone("Rate6");
	Rate6->Divide(juqm3,juqm2, 1, 1, "B");
	Rate6->Sumw2();
	//    }
      Rate6->SetMarkerStyle(20);
      Rate6->SetMarkerSize(0.8);
      Rate6->SetXTitle("<A>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      Rate6->SetMarkerColor(2);
      Rate6->SetLineColor(0);
//            Rate6->SetMinimum(24.);
      Rate6->Draw("Error");


      maxbins = 0;
      nx = Rate6->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate6->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS6 = new TH1F("ADCAmplperLS6","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS6  = new TH1F("ADCAmplperLS6 ","", 600, 1.,601.);
      nx = Rate6->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate6->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS6 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS6 ->SetMarkerStyle(20);
      ADCAmplperLS6 ->SetMarkerSize(0.4);
      ADCAmplperLS6 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS6 ->SetXTitle("<ADCAmpl> per LS HF1 \b");
      ADCAmplperLS6 ->SetMarkerColor(2);
      ADCAmplperLS6 ->SetLineColor(0);
      //        ADCAmplperLS6 ->SetMaximum(30.0);
      //        ADCAmplperLS6 ->SetMinimum(20.0);
      ADCAmplperLS6 ->Draw("Error");
       c1->Update();



    //========================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumADCAmplLS7");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("<A>(ev.in LS) in LSs & channels - HF depth2\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      aaaaaa7->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmplLS7 divided by 
      //              h_2D0sumADCAmplLS7       ................. definition 2.
      c1->cd(2);
      TH2F *nyai1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS7");
      TH2F *nyai0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS7");
     nyai1->Sumw2();
     nyai0->Sumw2();
      //    if(nyai0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7= (TH2F*)nyai1->Clone("Cefz7");
	Cefz7->Divide(nyai1,nyai0, 1, 1, "B");
	Cefz7->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("<A>  - HF Depth2                   #eta \b");
      Cefz7->SetYTitle("#phi \b");
      //    Cefz7->SetZTitle("<A>  - HF Depth1 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
//            Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *nyai3= (TH1F*)hfile1->Get("h_sumADCAmplperLS7");
      TH1F *nyai2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS7");
     nyai3->Sumw2();
     nyai2->Sumw2();
      gPad->SetGridy();
      //    if(nyai2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate7 = (TH1F*)nyai3->Clone("Rate7");
	Rate7->Divide(nyai3,nyai2, 1, 1, "B");
	Rate7->Sumw2();
	//    }
      Rate7->SetMarkerStyle(20);
      Rate7->SetMarkerSize(0.8);
      Rate7->SetXTitle("<A>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      Rate7->SetMarkerColor(2);
      Rate7->SetLineColor(0);
//            Rate7->SetMinimum(24.);
      Rate7->Draw("Error");


      maxbins = 0;
      nx = Rate7->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate7->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS7 = new TH1F("ADCAmplperLS7","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS7  = new TH1F("ADCAmplperLS7 ","", 600, 1.,601.);
      nx = Rate7->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate7->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS7 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS7 ->SetMarkerStyle(20);
      ADCAmplperLS7 ->SetMarkerSize(0.4);
      ADCAmplperLS7 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS7 ->SetXTitle("<ADCAmpl> per LS HF2 \b");
      ADCAmplperLS7 ->SetMarkerColor(2);
      ADCAmplperLS7 ->SetLineColor(0);
      //        ADCAmplperLS7 ->SetMaximum(30.0);
      //        ADCAmplperLS7 ->SetMinimum(20.0);
      ADCAmplperLS7 ->Draw("Error");



       c1->Update();



    //========================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa8= (TH1F*)hfile1->Get("h_sumADCAmplLS8");
      gPad->SetLogy();
      aaaaaa8->SetMarkerStyle(20);
      aaaaaa8->SetMarkerSize(0.8);
      aaaaaa8->GetYaxis()->SetLabelSize(0.04);
      aaaaaa8->SetXTitle("<A>(ev.in LS) in LSs & channels - HO depth4\b");
      aaaaaa8->SetMarkerColor(4);
      aaaaaa8->SetLineColor(0);
      aaaaaa8->Draw("Error");

      //plot 2: TH2F  h_2DsumADCAmpLS8 divided by 
      //              h_2D0sumADCAmpLS8       ................. definition 2.
      c1->cd(2);
      //    TH2F *twoddepth4ho1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
      //    TH2F *twoddepth4ho0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      TH2F *mkea1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS8");
      TH2F *mkea0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS8");
     mkea1->Sumw2();
     mkea0->Sumw2();
      //    if(mkea0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz8= (TH2F*)mkea1->Clone("Cefz8");
	Cefz8->Divide(mkea1,mkea0, 1, 1, "B");
	Cefz8->Sumw2();
	//    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz8->SetMarkerStyle(20);
      Cefz8->SetMarkerSize(0.4);
      //    Cefz8->GetYaxis()->SetLabelSize(0.04);
      Cefz8->GetZaxis()->SetLabelSize(0.08);
      Cefz8->SetXTitle("<A>  - HO Depth4                   #eta \b");
      Cefz8->SetYTitle("#phi \b");
      //    Cefz8->SetZTitle("<A>  - HO Depth1 \b");
      Cefz8->SetMarkerColor(2);
      Cefz8->SetLineColor(2);
      //      Cefz8->SetMaximum(1.000);
//            Cefz8->SetMinimum(1.0);
      Cefz8->Draw("COLZ");

      c1->cd(3);
      TH1F *mkea3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8");
      TH1F *mkea2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8");
     mkea3->Sumw2();
     mkea2->Sumw2();
      gPad->SetGridy();
      //    if(mkea2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate8 = (TH1F*)mkea3->Clone("Rate8");
	Rate8->Divide(mkea3,mkea2, 1, 1, "B");
	Rate8->Sumw2();
	//    }
      for (int i=1;i<=nx;i++) {
	double ccc1 =  mkea3->GetBinContent(i);
	double ccc2 =  mkea2->GetBinContent(i);

	if(ccc2>0.)  {double ccc3=ccc1/ccc2; cout<<" depth1_HO iLS = "<<i<<" A3=  "<<ccc1<<" A2=  "<<ccc2<<" Adiv=  "<<ccc3<<endl;}
      }
      Rate8->SetMarkerStyle(20);
      Rate8->SetMarkerSize(0.8);
      Rate8->SetXTitle("<A>(ev.in LS & ch.) - HO depth4 -    iLS \b");
      Rate8->SetMarkerColor(2);
      Rate8->SetLineColor(0);
//            Rate8->SetMinimum(24.);
      Rate8->Draw("Error");


      maxbins = 0;
      nx = Rate8->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate8->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS8 = new TH1F("ADCAmplperLS8","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS8  = new TH1F("ADCAmplperLS8 ","", 600, 1.,601.);
      nx = Rate8->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate8->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS8 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS8 ->SetMarkerStyle(20);
      ADCAmplperLS8 ->SetMarkerSize(0.4);
      ADCAmplperLS8 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS8 ->SetXTitle("<ADCAmpl> per LS HO4 \b");
      ADCAmplperLS8 ->SetMarkerColor(2);
      ADCAmplperLS8 ->SetLineColor(0);
      //        ADCAmplperLS8 ->SetMaximum(30.0);
      //        ADCAmplperLS8 ->SetMinimum(20.0);
      ADCAmplperLS8 ->Draw("Error");
       c1->Update();




    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);

      c1->cd(1);
      TH1F *bbbbbb1= (TH1F*)hfile1->Get("h_sumADCAmplLS1");
      gPad->SetLogy();
      bbbbbb1->SetMarkerStyle(20);
      bbbbbb1->SetMarkerSize(0.8);
      bbbbbb1->GetYaxis()->SetLabelSize(0.04);
      bbbbbb1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb1->SetMarkerColor(4);
      bbbbbb1->SetLineColor(0);
      bbbbbb1->Draw("Error");

      c1->cd(2);
      TH1F *bbbbbb2= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy1");
      gPad->SetLogy();
      bbbbbb2->SetMarkerStyle(20);
      bbbbbb2->SetMarkerSize(0.8);
      bbbbbb2->GetYaxis()->SetLabelSize(0.04);
      bbbbbb2->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb2->SetMarkerColor(4);
      bbbbbb2->SetLineColor(0);
      bbbbbb2->Draw("Error");

      c1->cd(3);
      TH1F *bbbbbb3= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy2");
      gPad->SetLogy();
      bbbbbb3->SetMarkerStyle(20);
      bbbbbb3->SetMarkerSize(0.8);
      bbbbbb3->GetYaxis()->SetLabelSize(0.04);
      bbbbbb3->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb3->SetMarkerColor(4);
      bbbbbb3->SetLineColor(0);
      bbbbbb3->Draw("Error");

      c1->cd(4);
      TH1F *bbbbbb4= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy3");
      gPad->SetLogy();
      bbbbbb4->SetMarkerStyle(20);
      bbbbbb4->SetMarkerSize(0.8);
      bbbbbb4->GetYaxis()->SetLabelSize(0.04);
      bbbbbb4->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb4->SetMarkerColor(4);
      bbbbbb4->SetLineColor(0);
      bbbbbb4->Draw("Error");

      c1->cd(5);
      TH1F *bbbbbb5= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy4");
      gPad->SetLogy();
      bbbbbb5->SetMarkerStyle(20);
      bbbbbb5->SetMarkerSize(0.8);
      bbbbbb5->GetYaxis()->SetLabelSize(0.04);
      bbbbbb5->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb5->SetMarkerColor(4);
      bbbbbb5->SetLineColor(0);
      bbbbbb5->Draw("Error");

      c1->cd(6);
      TH1F *bbbbbb6= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy5");
      gPad->SetLogy();
      bbbbbb6->SetMarkerStyle(20);
      bbbbbb6->SetMarkerSize(0.8);
      bbbbbb6->GetYaxis()->SetLabelSize(0.04);
      bbbbbb6->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      bbbbbb6->SetMarkerColor(4);
      bbbbbb6->SetLineColor(0);
      bbbbbb6->Draw("Error");


      c1->Update();



    //=============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      /*
      c1->Clear();
      c1->Divide(2,3);
      // HB
  TH2F*    h_2DsumADCAmplLS1         ;
  TH2F*    h_2D0sumADCAmplLS1         ;
  TH2F*    h_2DsumADCAmplLS2         ;
  TH2F*    h_2D0sumADCAmplLS2         ;

  // HE
  TH2F*    h_2DsumADCAmplLS3         ;
  TH2F*    h_2D0sumADCAmplLS3         ;
  TH2F*    h_2DsumADCAmplLS4         ;
  TH2F*    h_2D0sumADCAmplLS4         ;
  TH2F*    h_2DsumADCAmplLS5         ;
  TH2F*    h_2D0sumADCAmplLS5         ;
  TH2F*    h_2DsumADCAmplLSdepth4HEu    ;
  TH2F*    h_2D0sumADCAmplLSdepth4HEu    ;
  TH2F*    h_2DsumADCAmplLSdepth5HEu    ;
  TH2F*    h_2D0sumADCAmplLSdepth5HEu    ;
  TH2F*    h_2DsumADCAmplLSdepth6HEu    ;
  TH2F*    h_2D0sumADCAmplLSdepth6HEu    ;
  TH2F*    h_2DsumADCAmplLSdepth7HEu    ;
  TH2F*    h_2D0sumADCAmplLSdepth7HEu    ;

  // HF
  TH2F*    h_2DsumADCAmplLS6         ;
  TH2F*    h_2D0sumADCAmplLS6         ;
  TH2F*    h_2DsumADCAmplLS7         ;
  TH2F*    h_2D0sumADCAmplLS7         ;
  TH2F*    h_2DsumADCAmplLSdepth3HFu    ;
  TH2F*    h_2D0sumADCAmplLSdepth3HFu    ;
  TH2F*    h_2DsumADCAmplLSdepth4HFu    ;
  TH2F*    h_2D0sumADCAmplLSdepth4HFu    ;

  //HO
  TH2F*    h_2DsumADCAmplLS8         ;
  TH2F*    h_2D0sumADCAmplLS8         ;

      c1->Update();

*/
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




      
