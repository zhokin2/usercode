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
	//	        	  gStyle->SetOptStat(11111111);
	//				gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//					gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
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
	//      gStyle->SetTitleY(0.01);            // title x-position
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

//	TFile *hfile1= new TFile("./histos/Global_190707.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_197724.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_197874.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_197875.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_197903.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_197929.root", "READ"); 
//
//	TFile *hfile1= new TFile("./histos/Global_198487.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_198488.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_198489.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_198490.root", "READ"); 
//
//	TFile *hfile1= new TFile("./histos/Global_209089.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_209106.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_209109.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_209146.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_209148.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_209151.root", "READ"); 
//
//	TFile *hfile1= new TFile("./histos/Global_227391.root", "READ"); 
//	TFile *hfile1= new TFile("./histos/Global_229441.root", "READ"); 
	//
	//

	//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229514.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229528.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229621.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229653.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229669.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229672.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229685.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229695.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229699.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229702.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229713.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229714.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229715.root", "READ");
	//
	//
	//
//	TFile *hfile1= new TFile("newruns/Global_234034.root", "READ");
//	TFile *hfile1= new TFile("Global_234034.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234193.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234556.root", "READ");



//	TFile *hfile1= new TFile("Global_test.root", "READ");
//	TFile *hfile1= new TFile("Global_255031.root", "READ");

//	TFile *hfile1= new TFile("Global_256001.root", "READ");
//	TFile *hfile1= new TFile("Global_256167.root", "READ");
// 	TFile *hfile1= new TFile("Global_256348.root", "READ");
//	TFile *hfile1= new TFile("Global_256630.root", "READ");
//	TFile *hfile1= new TFile("Global_test.root", "READ");


//	TFile *hfile1= new TFile("Global_321177_olddefault.root", "READ");
//	TFile *hfile1= new TFile("Global_321177.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600.root", "READ");

//	TFile *hfile1= new TFile("Global_321177_9_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap.root", "READ");

//	TFile *hfile1= new TFile("Global_RBX_325001_40.root", "READ");
	TFile *hfile1= new TFile("Global_RBX_325001_ls1to600.root", "READ");

	//	TFile *hfile1= new TFile("Global_238283.root", "READ");
	//	TFile *hfile1= new TFile("Global_236770.root", "READ");
//	TFile *hfile1= new TFile("Global_ttt236770.root", "READ");

	//
	//
	//
	//	TFile *hfile1= new TFile("testNZS.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zRunNbadchan.ps", 111);
//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);

	  int nx = 0;int icount=0;int icount0=0;
    //======================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HB");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("N bad channels - HB depth1 \b");
      aaaaaa1->SetYTitle("Nevents \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->SetMinimum(0.8);
      //      aaaaaa1->SetMinimum(0.0001);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth1_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      //    if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      //    Rate1->SetXTitle("iLS \b");
      //    Rate1->SetYTitle("< N bad channels > HB depth1 \b");
      Rate1->SetXTitle("< Nbcs > HB depth1                            iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      Rate1->Draw("Error");
      nx= Rate1->GetXaxis()->GetNbins();
      cout<<"1 Max # iLS = "<< nx <<endl;
      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>0.0006) {
	  icount++;
	  cout<<"Bigger 0.0006, depth1_HB iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
	  cout<<"Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
	  cout<<"Bigger 0.0006, depth1_HB icount = "<<icount<<endl;

      TH1F *kwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth1_HB");
      TH1F *kwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HB");
      kwod1->Sumw2();
      kwod0->Sumw2();
      //    if(kwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1C = (TH1F*)kwod1->Clone("Rate1C");
	Rate1C->Divide(kwod1,kwod0, 1, 1, "B");
	Rate1C->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1C->SetMarkerStyle(20);
      Rate1C->SetMarkerSize(0.8);
      Rate1C->SetXTitle("iLS \b");
      //    Rate1C->SetYTitle("< N bad channels > HB depth1 \b");
      Rate1C->SetMarkerColor(1);
      Rate1C->SetLineColor(0);
      //      Rate1C->Draw("ErrorSame");
//      nx= Rate1C->GetXaxis()->GetNbins();
//      for (int i=1;i<=nx;i++) {
//	double ccc1 =  Rate1C->GetBinContent(i)   ;
//	if(ccc1>0.05) {
	  //	  cout<<"========================================== "<<endl;
	  //	  cout<<"depth1_HB iLS = "<<i<<" abnormal bcs events, for which its <Nbcs> portion per iLS= "<<ccc1<<endl;
//	}
//      }

      c1->cd(3);
      TH1F* Rate1profile = new TH1F("Rate1profile","", 100, 0.,20.);
      nx= Rate1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate1->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate1->GetBinContent(i) ;
	  Rate1profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate1profile->SetMarkerStyle(20);
      Rate1profile->SetMarkerSize(0.4);
      Rate1profile->GetYaxis()->SetLabelSize(0.04);
      Rate1profile->SetXTitle("<Nbcs> in each LS \b");
      Rate1profile->SetMarkerColor(2);
      Rate1profile->SetLineColor(2);
      Rate1profile->Draw("");


      c1->cd(4);
      TH1F* Rate1Cprofile = new TH1F("Rate1Cprofile","", 100, 0.,20.);
      nx= Rate1C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate1C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate1C->GetBinContent(i) ;
	  Rate1Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate1Cprofile->SetMarkerStyle(20);
      Rate1Cprofile->SetMarkerSize(0.4);
      Rate1Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate1Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate1Cprofile->SetMarkerColor(1);
      Rate1Cprofile->SetLineColor(1);
      Rate1Cprofile->Draw("");
      
      c1->Update();
      
      
            
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HB");
      gPad->SetLogy();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("N bad channels - HB depth2 \b");
      aaaaaa2->SetYTitle("Nevents \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(4);
      aaaaaa2->SetMinimum(0.8);
//      aaaaaa2->SetMinimum(0.0001);
      aaaaaa2->Draw("");
       
      c1->cd(2);
      TH1F *qwod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth2_HB");
      TH1F *qwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HB");
      qwod1->Sumw2();
      qwod0->Sumw2();
//      if(qwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)qwod1->Clone("Rate2");
	Rate2->Divide(qwod1,qwod0, 1, 1, "B");
	Rate2->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      nx= Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.15) {
	  //	  cout<<"depth2_HB iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      //    Rate2->SetXTitle("iLS \b");
      //      Rate2->SetYTitle("< N bad channels > HB depth2 \b");
      Rate2->SetXTitle("< Nbcs > HB depth2                            iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
      TH1F *wwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth2_HB");
      TH1F *wwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HB");
      wwod1->Sumw2();
      wwod0->Sumw2();
//      if(wwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2C = (TH1F*)wwod1->Clone("Rate2C");
	Rate2C->Divide(wwod1,wwod0, 1, 1, "B");
	Rate2C->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate2C->SetMarkerStyle(20);
      Rate2C->SetMarkerSize(0.8);
      Rate2C->SetXTitle("iLS \b");
      //    Rate2C->SetYTitle("< N bad channels > HB depth2 \b");
      Rate2C->SetMarkerColor(1);
      Rate2C->SetLineColor(0);
//      Rate2C->Draw("SameError");
      
      c1->cd(3);
      TH1F* Rate2profile = new TH1F("Rate2profile","", 100, 0.,5.);
      nx= Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate2->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate2->GetBinContent(i) ;
	  Rate2profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate2profile->SetMarkerStyle(20);
      Rate2profile->SetMarkerSize(0.4);
      Rate2profile->GetYaxis()->SetLabelSize(0.04);
      Rate2profile->SetXTitle("<Nbcs> in each LS \b");
      Rate2profile->SetMarkerColor(2);
      Rate2profile->SetLineColor(2);
      Rate2profile->Draw("");


      c1->cd(4);
      TH1F* Rate2Cprofile = new TH1F("Rate2Cprofile","", 100, 0.,5.);
      nx= Rate2C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate2C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate2C->GetBinContent(i) ;
	  Rate2Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate2Cprofile->SetMarkerStyle(20);
      Rate2Cprofile->SetMarkerSize(0.4);
      Rate2Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate2Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate2Cprofile->SetMarkerColor(1);
      Rate2Cprofile->SetLineColor(1);
      Rate2Cprofile->Draw("");
      
      c1->Update();
      
      
      
            
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HE");
      gPad->SetLogy();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("N bad channels - HE depth1 \b");
      aaaaaa3->SetYTitle("Nevents \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(4);
      aaaaaa3->SetMinimum(0.8);
//      aaaaaa3->SetMinimum(0.0001);
      aaaaaa3->Draw("");
       
      c1->cd(2);
      TH1F *ewod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth1_HE");
      TH1F *ewod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HE");
      ewod1->Sumw2();
      ewod0->Sumw2();
//      if(ewod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)ewod1->Clone("Rate3");
	Rate3->Divide(ewod1,ewod0, 1, 1, "B");
	Rate3->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      //    Rate3->SetXTitle("iLS \b");
      //    Rate3->SetYTitle("< N bad channels > HE depth1 \b");
      Rate3->SetXTitle("< Nbcs > HE depth1                            iLS \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(0);
      Rate3->Draw("Error");
      nx= Rate3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate3->GetBinContent(i)   ;
	if(ccc1>0.00004) {
	  	  cout<<"depth1_HE iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }

      TH1F *rwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth1_HE");
      TH1F *rwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HE");
      rwod1->Sumw2();
      rwod0->Sumw2();
      //    if(rwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3C = (TH1F*)rwod1->Clone("Rate3C");
	Rate3C->Divide(rwod1,rwod0, 1, 1, "B");
	Rate3C->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3C->SetMarkerStyle(20);
      Rate3C->SetMarkerSize(0.8);
      Rate3C->SetXTitle("iLS \b");
      //    Rate3C->SetYTitle("< N bad channels > HE depth1 \b");
      Rate3C->SetMarkerColor(1);
      Rate3C->SetLineColor(0);
      //      Rate3C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate3profile = new TH1F("Rate3profile","", 100, 0.,20.);
      nx= Rate3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate3->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate3->GetBinContent(i) ;
	  Rate3profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate3profile->SetMarkerStyle(20);
      Rate3profile->SetMarkerSize(0.4);
      Rate3profile->GetYaxis()->SetLabelSize(0.04);
      Rate3profile->SetXTitle("<Nbcs> in each LS \b");
      Rate3profile->SetMarkerColor(2);
      Rate3profile->SetLineColor(2);
      Rate3profile->Draw("");


      c1->cd(4);
      TH1F* Rate3Cprofile = new TH1F("Rate3Cprofile","", 100, 0.,20.);
      nx= Rate3C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate3C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate3C->GetBinContent(i) ;
	  Rate3Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate3Cprofile->SetMarkerStyle(20);
      Rate3Cprofile->SetMarkerSize(0.4);
      Rate3Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate3Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate3Cprofile->SetMarkerColor(1);
      Rate3Cprofile->SetLineColor(1);
      Rate3Cprofile->Draw("");
      
      c1->Update();
      
      
            
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HE");
      gPad->SetLogy();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("N bad channels - HE depth2 \b");
      aaaaaa4->SetYTitle("Nevents \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(4);
      aaaaaa4->SetMinimum(0.8);
//      aaaaaa4->SetMinimum(0.0001);
      aaaaaa4->Draw("");
       
      c1->cd(2);
      TH1F *ywod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth2_HE");
      TH1F *ywod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HE");
      ywod1->Sumw2();
      ywod0->Sumw2();
//      if(ywod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate4 = (TH1F*)ywod1->Clone("Rate4");
	Rate4->Divide(ywod1,ywod0, 1, 1, "B");
	Rate4->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate4->SetMarkerStyle(20);
      Rate4->SetMarkerSize(0.8);
      Rate4->SetXTitle("iLS \b");
      //    Rate4->SetYTitle("< N bad channels > HE depth2 \b");
      Rate4->SetXTitle("< Nbcs > HE depth2                            iLS \b");
      Rate4->SetMarkerColor(2);
      Rate4->SetLineColor(0);
      Rate4->Draw("Error");
      TH1F *uwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth2_HE");
      TH1F *uwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HE");
      uwod1->Sumw2();
      uwod0->Sumw2();
      //    if(uwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate4C = (TH1F*)uwod1->Clone("Rate4C");
	Rate4C->Divide(uwod1,uwod0, 1, 1, "B");
	Rate4C->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate4C->SetMarkerStyle(20);
      Rate4C->SetMarkerSize(0.8);
      Rate4C->SetXTitle("iLS \b");
      //    Rate4C->SetYTitle("< N bad channels > HE depth2 \b");
      Rate4C->SetMarkerColor(1);
      Rate4C->SetLineColor(0);
      Rate4C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate4profile = new TH1F("Rate4profile","", 100, 0.,20.);
      nx= Rate4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate4->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate4->GetBinContent(i) ;
	  Rate4profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate4profile->SetMarkerStyle(20);
      Rate4profile->SetMarkerSize(0.4);
      Rate4profile->GetYaxis()->SetLabelSize(0.04);
      Rate4profile->SetXTitle("<Nbcs> in each LS \b");
      Rate4profile->SetMarkerColor(2);
      Rate4profile->SetLineColor(2);
      Rate4profile->Draw("");


      c1->cd(4);
      TH1F* Rate4Cprofile = new TH1F("Rate4Cprofile","", 100, 0.,20.);
      nx= Rate4C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate4C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate4C->GetBinContent(i) ;
	  Rate4Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate4Cprofile->SetMarkerStyle(20);
      Rate4Cprofile->SetMarkerSize(0.4);
      Rate4Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate4Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate4Cprofile->SetMarkerColor(1);
      Rate4Cprofile->SetLineColor(1);
      Rate4Cprofile->Draw("");
      
      c1->Update();
      
      
            
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa5= (TH1F*)hfile1->Get("h_nbadchannels_depth3_HE");
      gPad->SetLogy();
      aaaaaa5->SetMarkerStyle(20);
      aaaaaa5->SetMarkerSize(0.8);
      aaaaaa5->GetYaxis()->SetLabelSize(0.04);
      aaaaaa5->SetXTitle("N bad channels - HE depth3 \b");
      aaaaaa5->SetYTitle("Nevents \b");
      aaaaaa5->SetMarkerColor(4);
      aaaaaa5->SetLineColor(4);
      aaaaaa5->SetMinimum(0.8);
//      aaaaaa5->SetMinimum(0.0001);
      aaaaaa5->Draw("");
       
      c1->cd(2);
      TH1F *iwod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth3_HE");
      TH1F *iwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth3_HE");
      iwod1->Sumw2();
      iwod0->Sumw2();
//      if(iwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate5 = (TH1F*)iwod1->Clone("Rate5");
	Rate5->Divide(iwod1,iwod0, 1, 1, "B");
	Rate5->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate5->SetMarkerStyle(20);
      Rate5->SetMarkerSize(0.8);
      //    Rate5->SetXTitle("iLS \b");
      //    Rate5->SetYTitle("< N bad channels > HE depth3 \b");
      Rate5->SetXTitle("< Nbcs > HE depth3                            iLS \b");
      Rate5->SetMarkerColor(2);
      Rate5->SetLineColor(0);
      Rate5->Draw("Error");
      TH1F *owod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth3_HE");
      TH1F *owod0= (TH1F*)hfile1->Get("h_runbadrate0_depth3_HE");
      owod1->Sumw2();
      owod0->Sumw2();
      //    if(owod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate5C = (TH1F*)owod1->Clone("Rate5C");
	Rate5C->Divide(owod1,owod0, 1, 1, "B");
	Rate5C->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate5C->SetMarkerStyle(20);
      Rate5C->SetMarkerSize(0.8);
      Rate5C->SetXTitle("iLS \b");
      //    Rate5C->SetYTitle("< N bad channels > HE depth3 \b");
      Rate5C->SetMarkerColor(1);
      Rate5C->SetLineColor(0);
      Rate5C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate5profile = new TH1F("Rate5profile","", 100, 0.,5.);
      nx= Rate5->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate5->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate5->GetBinContent(i) ;
	  Rate5profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate5profile->SetMarkerStyle(20);
      Rate5profile->SetMarkerSize(0.4);
      Rate5profile->GetYaxis()->SetLabelSize(0.04);
      Rate5profile->SetXTitle("<Nbcs> in each LS \b");
      Rate5profile->SetMarkerColor(2);
      Rate5profile->SetLineColor(2);
      Rate5profile->Draw("");


      c1->cd(4);
      TH1F* Rate5Cprofile = new TH1F("Rate5Cprofile","", 100, 0.,5.);
      nx= Rate5C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate5C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate5C->GetBinContent(i) ;
	  Rate5Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate5Cprofile->SetMarkerStyle(20);
      Rate5Cprofile->SetMarkerSize(0.4);
      Rate5Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate5Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate5Cprofile->SetMarkerColor(1);
      Rate5Cprofile->SetLineColor(1);
      Rate5Cprofile->Draw("");
      
      c1->Update();
      
      
            
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,5);
      
      c1->cd(1);
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->GetXaxis()->SetLabelSize(0.06);
      Rate1->GetYaxis()->SetLabelSize(0.06);
      Rate1->SetTitleSize(0.06,"XY" );
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      Rate1->Draw("Error");
       
      c1->cd(2);
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->GetXaxis()->SetLabelSize(0.06);
      Rate2->GetYaxis()->SetLabelSize(0.06);
      Rate2->SetTitleSize(0.06,"XY" );
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
       
      c1->cd(3);
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->GetXaxis()->SetLabelSize(0.06);
      Rate3->GetYaxis()->SetLabelSize(0.06);
      Rate3->SetTitleSize(0.06,"XY" );
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(0);
      Rate3->Draw("Error");
       
      c1->cd(4);
      Rate4->SetMarkerStyle(20);
      Rate4->SetMarkerSize(0.8);
      Rate4->GetXaxis()->SetLabelSize(0.06);
      Rate4->GetYaxis()->SetLabelSize(0.06);
      Rate4->SetTitleSize(0.06,"XY" );
      Rate4->SetMarkerColor(2);
      Rate4->SetLineColor(0);
      Rate4->Draw("Error");
       
      c1->cd(5);
      Rate5->SetMarkerStyle(20);
      Rate5->SetMarkerSize(0.8);
      Rate5->GetXaxis()->SetLabelSize(0.06);
      Rate5->GetYaxis()->SetLabelSize(0.06);
      Rate5->SetTitleSize(0.06,"XY" );
      Rate5->SetMarkerColor(2);
      Rate5->SetLineColor(0);
      Rate5->Draw("Error");
       
      c1->Update();
    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->GetXaxis()->SetLabelSize(0.06);
      Rate1->GetYaxis()->SetLabelSize(0.06);
      Rate1->SetTitleSize(0.06,"XY" );
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      Rate1->Draw("Error");
      Rate1C->Draw("ErrorSame");
       
      c1->cd(2);
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->GetXaxis()->SetLabelSize(0.06);
      Rate2->GetYaxis()->SetLabelSize(0.06);
      Rate2->SetTitleSize(0.06,"XY" );
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
      Rate2C->Draw("ErrorSame");
       
      c1->Update();
    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->GetXaxis()->SetLabelSize(0.06);
      Rate3->GetYaxis()->SetLabelSize(0.06);
      Rate3->SetTitleSize(0.06,"XY" );
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(0);
      Rate3->Draw("Error");
      Rate3C->Draw("ErrorSame");
       
      c1->cd(2);
      Rate4->SetMarkerStyle(20);
      Rate4->SetMarkerSize(0.8);
      Rate4->GetXaxis()->SetLabelSize(0.06);
      Rate4->GetYaxis()->SetLabelSize(0.06);
      Rate4->SetTitleSize(0.06,"XY" );
      Rate4->SetMarkerColor(2);
      Rate4->SetLineColor(0);
      Rate4->Draw("Error");
      Rate4C->Draw("ErrorSame");
       
      c1->cd(3);
      Rate5->SetMarkerStyle(20);
      Rate5->SetMarkerSize(0.8);
      Rate5->GetXaxis()->SetLabelSize(0.06);
      Rate5->GetYaxis()->SetLabelSize(0.06);
      Rate5->SetTitleSize(0.06,"XY" );
      Rate5->SetMarkerColor(2);
      Rate5->SetLineColor(0);
      Rate5->Draw("Error");
      Rate5C->Draw("ErrorSame");
       
      c1->Update();


    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa9= (TH1F*)hfile1->Get("h_nbadchannels_depth4_HO");
      gPad->SetLogy();
      aaaaaa9->SetMarkerStyle(20);
      aaaaaa9->SetMarkerSize(0.8);
      aaaaaa9->GetYaxis()->SetLabelSize(0.04);
      aaaaaa9->SetXTitle("N bad channels - HO depth4 \b");
      aaaaaa9->SetYTitle("Nevents \b");
      aaaaaa9->SetMarkerColor(4);
      aaaaaa9->SetLineColor(4);
      aaaaaa9->SetMinimum(0.1);
      aaaaaa9->Draw("");

 //     c1->cd(2);
 //     TH1F* Cdef143 = new TH1F("Cdef143","", 10, 1., 11.);
//      TH1F *aaaaaa9= (TH1F*)hfile1->Get("h_nbadchannels_depth4_HO");
//      for (Int_t binx = 1; binx < 51; binx++)  { 
//	Double_t ratio=0.;
//	if(aaaaaa9->GetBinContent(binx) > 0) ratio=aaaaaa9->GetBinContent(binx);
//	//     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;
	
//	Cdef143->SetBinContent(binx, ratio);
////	Cdef143->SetBinError(binx,  aaaa*ratio);
//      }
//      gPad->SetLogy();
//      Cdef143->Draw("");
       
            c1->cd(2);
      TH1F *pwod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth4_HO");
      TH1F *pwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      pwod1->Sumw2();
      pwod0->Sumw2();
//      if(pwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate6 = (TH1F*)pwod1->Clone("Rate6");
	Rate6->Divide(pwod1,pwod0, 1, 1, "B");
	Rate6->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate6->SetMarkerStyle(20);
      Rate6->SetMarkerSize(0.8);
      //    Rate6->SetXTitle("iLS \b");
      //    Rate6->SetYTitle("< N bad channels > HO depth4 \b");
      Rate6->SetXTitle("< Nbcs > HO depth4                            iLS \b");
      Rate6->SetMarkerColor(2);
      Rate6->SetLineColor(0);
      //      Rate6->SetMinimum(80.);
      //      Rate6->SetMaximum(100.);
            Rate6->Draw("Error");
      nx= Rate6->GetXaxis()->GetNbins();
      cout<<"6 Max # iLS = "<< nx <<endl;
      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate6->GetBinContent(i)   ;
	if(ccc1>0.5) icount0++;
	if(ccc1>0.0) {
	  icount++;
	  cout<<"Bigger 0.0, depth4_HO iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 0.0, depth4_HO icount = "<<icount<<endl;
      cout<<"Bigger 0.5, depth4_HO icount = "<<icount0<<endl;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate6->GetBinContent(i)   ;
	if(ccc1>3.0) {
	  icount++;
	  	  cout<<"11111  Bigger 3.0, depth4_HO iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 3.0, depth4_HO icount = "<<icount<<endl;
      
      

      TH1F *awod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth4_HO");
      TH1F *awod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      awod1->Sumw2();
      awod0->Sumw2();
//      if(awod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate6C = (TH1F*)awod1->Clone("Rate6C");
	Rate6C->Divide(awod1,awod0, 1, 1, "B");
	Rate6C->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate6C->SetMarkerStyle(20);
      Rate6C->SetMarkerSize(0.8);
      Rate6C->SetXTitle("iLS \b");
      //    Rate6C->SetYTitle("< N bad channels > HO depth4 \b");
      Rate6C->SetMarkerColor(1);
      Rate6C->SetLineColor(0);
      //    Rate6C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate6profile = new TH1F("Rate6profile","", 100, 0.,50.);
      nx= Rate6->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate6->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate6->GetBinContent(i) ;
	  Rate6profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate6profile->SetMarkerStyle(20);
      Rate6profile->SetMarkerSize(0.4);
      Rate6profile->GetYaxis()->SetLabelSize(0.04);
      Rate6profile->SetXTitle("<Nbcs> in each LS \b");
      Rate6profile->SetMarkerColor(2);
      Rate6profile->SetLineColor(2);
      Rate6profile->Draw("");


      c1->cd(4);
      TH1F* Rate6Cprofile = new TH1F("Rate6Cprofile","", 100, 0.,50.);
      nx= Rate6C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate6C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate6C->GetBinContent(i) ;
	  Rate6Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate6Cprofile->SetMarkerStyle(20);
      Rate6Cprofile->SetMarkerSize(0.4);
      Rate6Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate6Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate6Cprofile->SetMarkerColor(1);
      Rate6Cprofile->SetLineColor(1);
      Rate6Cprofile->Draw("");
      
      c1->Update();
      
      
            

    //=============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaa01= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HF");
      gPad->SetLogy();
      aaaaa01->SetMarkerStyle(20);
      aaaaa01->SetMarkerSize(0.8);
      aaaaa01->GetYaxis()->SetLabelSize(0.04);
      aaaaa01->SetXTitle("N bad channels - HF depth1 \b");
      aaaaa01->SetYTitle("Nevents \b");
      aaaaa01->SetMarkerColor(4);
      aaaaa01->SetLineColor(4);
      aaaaa01->SetMinimum(0.8);
      aaaaa01->Draw("");
       
      c1->cd(2);
      TH1F *swod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth1_HF");
      TH1F *swod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      swod1->Sumw2();
      swod0->Sumw2();
//      if(swod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate7 = (TH1F*)swod1->Clone("Rate7");
	Rate7->Divide(swod1,swod0, 1, 1, "B");
	Rate7->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate7->SetMarkerStyle(20);
      Rate7->SetMarkerSize(0.8);
      //    Rate7->SetXTitle("iLS \b");
      //    Rate7->SetYTitle("< N bad channels > HF depth1 \b");
      Rate7->SetXTitle("< Nbcs > HF depth1                            iLS \b");
      Rate7->SetMarkerColor(2);
      Rate7->SetLineColor(0);
      Rate7->Draw("Error");
      nx= Rate7->GetXaxis()->GetNbins();
      cout<<"7 Max # iLS = "<< nx <<endl;
      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate7->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>0.002) {
	  icount++;
	  cout<<"Bigger 0.002, depth1_HF iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 0.0, depth1_HF icount = "<<icount0<<endl;
      cout<<"Bigger 0.002, depth1_HF icount = "<<icount<<endl;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate7->GetBinContent(i)   ;
	if(ccc1>0.0) {
	  icount++;
	  //	  cout<<"Bigger 0.0, depth1_HF iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 0.0, depth1_HF icount = "<<icount<<endl;


      TH1F *dwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth1_HF");
      TH1F *dwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      dwod1->Sumw2();
      dwod0->Sumw2();
//      if(dwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate7C = (TH1F*)dwod1->Clone("Rate7C");
	Rate7C->Divide(dwod1,dwod0, 1, 1, "B");
	Rate7C->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate7C->SetMarkerStyle(20);
      Rate7C->SetMarkerSize(0.8);
      Rate7C->SetXTitle("iLS \b");
      //    Rate7C->SetYTitle("< N bad channels > HF depth1 \b");
      Rate7C->SetMarkerColor(1);
      Rate7C->SetLineColor(0);
      //    Rate7C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate7profile = new TH1F("Rate7profile","", 100, 0.,20.);
      nx= Rate7->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate7->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate7->GetBinContent(i) ;
	  Rate7profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate7profile->SetMarkerStyle(20);
      Rate7profile->SetMarkerSize(0.4);
      Rate7profile->GetYaxis()->SetLabelSize(0.04);
      Rate7profile->SetXTitle("<Nbcs> in each LS \b");
      Rate7profile->SetMarkerColor(2);
      Rate7profile->SetLineColor(2);
      Rate7profile->Draw("");


      c1->cd(4);
      TH1F* Rate7Cprofile = new TH1F("Rate7Cprofile","", 100, 0.,20.);
      nx= Rate7C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate7C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate7C->GetBinContent(i) ;
	  Rate7Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate7Cprofile->SetMarkerStyle(20);
      Rate7Cprofile->SetMarkerSize(0.4);
      Rate7Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate7Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate7Cprofile->SetMarkerColor(1);
      Rate7Cprofile->SetLineColor(1);
      Rate7Cprofile->Draw("");
      
      c1->Update();
      
      
            

    //=============================================================================================== 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaa11= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HF");
      gPad->SetLogy();
      aaaaa11->SetMarkerStyle(20);
      aaaaa11->SetMarkerSize(0.8);
      aaaaa11->GetYaxis()->SetLabelSize(0.04);
      aaaaa11->SetXTitle("N bad channels - HF depth2 \b");
      aaaaa11->SetYTitle("Nevents \b");
      aaaaa11->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaa11->SetMinimum(0.8);
      aaaaa11->Draw("");
       
      c1->cd(2);
      TH1F *fwod1= (TH1F*)hfile1->Get("h_runnbadchannels_depth2_HF");
      TH1F *fwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      fwod1->Sumw2();
      fwod0->Sumw2();
      //    if(fwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate8 = (TH1F*)fwod1->Clone("Rate8");
	Rate8->Divide(fwod1,fwod0, 1, 1, "B");
	Rate8->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate8->SetMarkerStyle(20);
      Rate8->SetMarkerSize(0.8);
      //    Rate8->SetXTitle("iLS \b");
      //    Rate8->SetYTitle("< N bad channels > HF depth2 \b");
      Rate8->SetXTitle("< Nbcs > HF depth2                            iLS \b");
      Rate8->SetMarkerColor(2);
      Rate8->SetLineColor(0);
      Rate8->Draw("Error");

      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate8->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>0.002) {
	  icount++;
	  cout<<" Dots,limited, depth2_HF iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
	  cout<<"*************************************** "<<endl;
	  cout<<"Dots,Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
	  cout<<"Dots,Bigger limited, depth1_HB icount = "<<icount<<endl;

      TH1F *gwod1= (TH1F*)hfile1->Get("h_runnbadchannelsC_depth2_HF");
      TH1F *gwod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      gwod1->Sumw2();
      gwod0->Sumw2();
//      if(gwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate8C = (TH1F*)gwod1->Clone("Rate8C");
	Rate8C->Divide(gwod1,gwod0, 1, 1, "B");
	Rate8C->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate8C->SetMarkerStyle(20);
      Rate8C->SetMarkerSize(0.8);
      Rate8C->SetXTitle("iLS \b");
      //    Rate8C->SetYTitle("< N bad channels > HF depth2 \b");
      Rate8C->SetMarkerColor(1);
      Rate8C->SetLineColor(0);
      Rate8C->Draw("ErrorSame");
      
      c1->cd(3);
      TH1F* Rate8profile = new TH1F("Rate8profile","", 100, 0.,20.);
      nx= Rate8->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate8->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate8->GetBinContent(i) ;
	  Rate8profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate8profile->SetMarkerStyle(20);
      Rate8profile->SetMarkerSize(0.4);
      Rate8profile->GetYaxis()->SetLabelSize(0.04);
      Rate8profile->SetXTitle("<Nbcs> in each LS \b");
      Rate8profile->SetMarkerColor(2);
      Rate8profile->SetLineColor(2);
      Rate8profile->Draw("");


      c1->cd(4);
      TH1F* Rate8Cprofile = new TH1F("Rate8Cprofile","", 100, 0.,20.);
      nx= Rate8C->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate8C->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate8C->GetBinContent(i) ;
	  Rate8Cprofile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate8Cprofile->SetMarkerStyle(20);
      Rate8Cprofile->SetMarkerSize(0.4);
      Rate8Cprofile->GetYaxis()->SetLabelSize(0.04);
      Rate8Cprofile->SetXTitle("abnormal <Nbcs> in each LS \b");
      Rate8Cprofile->SetMarkerColor(1);
      Rate8Cprofile->SetLineColor(1);
      Rate8Cprofile->Draw("");
      
      c1->Update();
      
      
            

    //=============================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      Rate6->SetMarkerStyle(20);
      Rate6->SetMarkerSize(0.8);
      Rate6->GetXaxis()->SetLabelSize(0.06);
      Rate6->GetYaxis()->SetLabelSize(0.06);
      Rate6->SetTitleSize(0.06,"XY" );
      Rate6->SetMarkerColor(2);
      Rate6->SetLineColor(0);
      Rate6->Draw("Error");
      Rate6C->Draw("ErrorSame");
       
      c1->cd(2);
      Rate7->SetMarkerStyle(20);
      Rate7->SetMarkerSize(0.8);
      Rate7->GetXaxis()->SetLabelSize(0.06);
      Rate7->GetYaxis()->SetLabelSize(0.06);
      Rate7->SetTitleSize(0.06,"XY" );
      Rate7->SetMarkerColor(2);
      Rate7->SetLineColor(0);
      Rate7->Draw("Error");
      Rate7C->Draw("ErrorSame");
       
      c1->cd(3);
      Rate8->SetMarkerStyle(20);
      Rate8->SetMarkerSize(0.8);
      Rate8->GetXaxis()->SetLabelSize(0.06);
      Rate8->GetYaxis()->SetLabelSize(0.06);
      Rate8->SetTitleSize(0.06,"XY" );
      Rate8->SetMarkerColor(2);
      Rate8->SetLineColor(0);
      Rate8->Draw("Error");
      Rate8C->Draw("ErrorSame");
       
      c1->Update();


    //=========================================================================================== 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *aaaaa21= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HB");
      gPad->SetLogy();
      aaaaa21->GetYaxis()->SetLabelSize(0.04);
      aaaaa21->SetXTitle("N bad channels - HB depth1 \b");
      aaaaa21->SetYTitle("Nevents \b");
      aaaaa21->SetLineColor(2);
      aaaaa21->SetMinimum(0.8);
      aaaaa21->Draw("");
       
      c1->cd(2);
      TH1F *aaaaa31= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HB");
      gPad->SetLogy();
      aaaaa31->GetYaxis()->SetLabelSize(0.04);
      aaaaa31->SetXTitle("N bad channels - HB depth2 \b");
      aaaaa31->SetYTitle("Nevents \b");
      aaaaa31->SetLineColor(2);
      aaaaa31->SetMinimum(0.8);
      aaaaa31->Draw("");
       
      c1->cd(3);
      TH1F *aaaaa41= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HE");
      gPad->SetLogy();
      aaaaa41->GetYaxis()->SetLabelSize(0.04);
      aaaaa41->SetXTitle("N bad channels - HE depth1 \b");
      aaaaa41->SetYTitle("Nevents \b");
      aaaaa41->SetLineColor(2);
      aaaaa41->SetMinimum(0.8);
      aaaaa41->Draw("");
       
      c1->cd(4);
      TH1F *aaaaa51= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HE");
      gPad->SetLogy();
      aaaaa51->GetYaxis()->SetLabelSize(0.04);
      aaaaa51->SetXTitle("N bad channels - HE depth2 \b");
      aaaaa51->SetYTitle("Nevents \b");
      aaaaa51->SetLineColor(2);
      aaaaa51->SetMinimum(0.8);
      aaaaa51->Draw("");
       
      c1->cd(5);
      TH1F *aaaaa61= (TH1F*)hfile1->Get("h_nbadchannels_depth3_HE");
      gPad->SetLogy();
      aaaaa61->GetYaxis()->SetLabelSize(0.04);
      aaaaa61->SetXTitle("N bad channels - HE depth3 \b");
      aaaaa61->SetYTitle("Nevents \b");
      aaaaa61->SetLineColor(2);
      aaaaa61->SetMinimum(0.8);
      aaaaa61->Draw("");
       
      c1->cd(6);
      TH1F *aaaaa71= (TH1F*)hfile1->Get("h_nbadchannels_depth4_HO");
      gPad->SetLogy();
      aaaaa71->GetYaxis()->SetLabelSize(0.04);
      aaaaa71->SetXTitle("N bad channels - HO depth4 \b");
      aaaaa71->SetYTitle("Nevents \b");
      aaaaa71->SetLineColor(2);
      aaaaa71->SetMinimum(0.8);
      aaaaa71->Draw("");
       
      c1->cd(7);
      TH1F *aaaaa81= (TH1F*)hfile1->Get("h_nbadchannels_depth1_HF");
      gPad->SetLogy();
      aaaaa81->GetYaxis()->SetLabelSize(0.04);
      aaaaa81->SetXTitle("N bad channels - HF depth1 \b");
      aaaaa81->SetYTitle("Nevents \b");
      aaaaa81->SetLineColor(2);
      aaaaa81->SetMinimum(0.8);
      aaaaa81->Draw("");
       
      c1->cd(8);
      TH1F *aaaaa91= (TH1F*)hfile1->Get("h_nbadchannels_depth2_HF");
      gPad->SetLogy();
      aaaaa91->GetYaxis()->SetLabelSize(0.04);
      aaaaa91->SetXTitle("N bad channels - HF depth2 \b");
      aaaaa91->SetYTitle("Nevents \b");
      aaaaa91->SetLineColor(2);
      aaaaa91->SetMinimum(0.8);
      aaaaa91->Draw("");
       
      c1->Update();


    //=========================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *hwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth1_HB");
      TH1F *hwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth1_HB");
      hwod1->Sumw2();
      hwod0->Sumw2();
//      if(hwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratq1 = (TH1F*)hwod1->Clone("Ratq1");
	Ratq1->Divide(hwod1,hwod0, 1, 1, "B");
	Ratq1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratq1->SetMarkerStyle(20);
      Ratq1->SetMarkerSize(0.8);
      Ratq1->SetXTitle("< Nbcs > HB depth1                       iBCN \b");
      Ratq1->SetMarkerColor(2);
      Ratq1->SetLineColor(0);
      Ratq1->Draw("Error");

      c1->cd(2);
      TH1F *jwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth2_HB");
      TH1F *jwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth2_HB");
      jwod1->Sumw2();
      jwod0->Sumw2();
      //    if(jwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratw1 = (TH1F*)jwod1->Clone("Ratw1");
	Ratw1->Divide(jwod1,jwod0, 1, 1, "B");
	Ratw1->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratw1->SetMarkerStyle(20);
      Ratw1->SetMarkerSize(0.8);
      Ratw1->SetXTitle("< Nbcs > HB depth2                       iBCN \b");
      Ratw1->SetMarkerColor(2);
      Ratw1->SetLineColor(0);
      Ratw1->Draw("Error");

      c1->cd(3);
      TH1F *mwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth1_HE");
      TH1F *mwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth1_HE");
      mwod1->Sumw2();
      mwod0->Sumw2();
//      if(mwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratr1 = (TH1F*)mwod1->Clone("Ratr1");
	Ratr1->Divide(mwod1,mwod0, 1, 1, "B");
	Ratr1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratr1->SetMarkerStyle(20);
      Ratr1->SetMarkerSize(0.8);
      Ratr1->SetXTitle("< Nbcs > HE depth1                       iBCN \b");
      Ratr1->SetMarkerColor(2);
      Ratr1->SetLineColor(0);
      Ratr1->Draw("Error");

      c1->cd(4);
      TH1F *lwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth2_HE");
      TH1F *lwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth2_HE");
      lwod1->Sumw2();
      lwod0->Sumw2();
//      if(lwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratt1 = (TH1F*)lwod1->Clone("Ratt1");
	Ratt1->Divide(lwod1,lwod0, 1, 1, "B");
	Ratt1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratt1->SetMarkerStyle(20);
      Ratt1->SetMarkerSize(0.8);
      Ratt1->SetXTitle("< Nbcs > HE depth2                       iBCN \b");
      Ratt1->SetMarkerColor(2);
      Ratt1->SetLineColor(0);
      Ratt1->Draw("Error");

      c1->cd(5);
      TH1F *zwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth3_HE");
      TH1F *zwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth3_HE");
      zwod1->Sumw2();
      zwod0->Sumw2();
      //    if(zwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Raty1 = (TH1F*)zwod1->Clone("Raty1");
	Raty1->Divide(zwod1,zwod0, 1, 1, "B");
	Raty1->Sumw2();
	//    }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Raty1->SetMarkerStyle(20);
      Raty1->SetMarkerSize(0.8);
      Raty1->SetXTitle("< Nbcs > HE depth3                       iBCN \b");
      Raty1->SetMarkerColor(2);
      Raty1->SetLineColor(0);
      Raty1->Draw("Error");

      c1->cd(6);
      TH1F *xwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth1_HF");
      TH1F *xwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth1_HF");
      xwod1->Sumw2();
      xwod0->Sumw2();
//      if(xwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratu1 = (TH1F*)xwod1->Clone("Ratu1");
	Ratu1->Divide(xwod1,xwod0, 1, 1, "B");
	Ratu1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratu1->SetMarkerStyle(20);
      Ratu1->SetMarkerSize(0.8);
      Ratu1->SetXTitle("< Nbcs > HF depth1                       iBCN \b");
      Ratu1->SetMarkerColor(2);
      Ratu1->SetLineColor(0);
      Ratu1->Draw("Error");

      nx= Ratu1->GetXaxis()->GetNbins();
      cout<<"Max BCN = "<< nx <<endl;
      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Ratu1->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>0.) {
	  icount++;
	  cout<<"Bigger 0.0, depth1_HF iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
      cout<<"Bigger 0.0, depth1_HB icount = "<<icount<<endl;
      
      c1->cd(7);
      TH1F *cwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth2_HF");
      TH1F *cwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth2_HF");
      cwod1->Sumw2();
      cwod0->Sumw2();
//      if(cwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rati1 = (TH1F*)cwod1->Clone("Rati1");
	Rati1->Divide(cwod1,cwod0, 1, 1, "B");
	Rati1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rati1->SetMarkerStyle(20);
      Rati1->SetMarkerSize(0.8);
      Rati1->SetXTitle("< Nbcs > HF depth2                       iBCN \b");
      Rati1->SetMarkerColor(2);
      Rati1->SetLineColor(0);
      Rati1->Draw("Error");

      c1->cd(8);
      TH1F *vwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth4_HO");
      TH1F *vwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth4_HO");
      vwod1->Sumw2();
      vwod0->Sumw2();
//      if(vwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rato1 = (TH1F*)vwod1->Clone("Rato1");
	Rato1->Divide(vwod1,vwod0, 1, 1, "B");
	Rato1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rato1->SetMarkerStyle(20);
      Rato1->SetMarkerSize(0.8);
      Rato1->SetXTitle("< Nbcs > HO depth4                       iBCN \b");
      Rato1->SetMarkerColor(2);
      Rato1->SetLineColor(0);
      Rato1->Draw("Error");




      c1->Update();
    //=========================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH1F *bwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth1_HF");
      TH1F *bwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth1_HF");
      bwod1->Sumw2();
      bwod0->Sumw2();
//      if(bwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Ratp1 = (TH1F*)bwod1->Clone("Ratp1");
	Ratp1->Divide(bwod1,bwod0, 1, 1, "B");
	Ratp1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Ratp1->SetMarkerStyle(20);
      Ratp1->SetMarkerSize(0.8);
      Ratp1->SetXTitle("< Nbcs > HF depth1                       iBCN \b");
      Ratp1->SetMarkerColor(2);
      Ratp1->SetLineColor(0);
      Ratp1->Draw("Error");

      nx= Ratp1->GetXaxis()->GetNbins();
      cout<<"Max BCN = "<< nx <<endl;
      icount0=0;
      icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Ratp1->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>0.) {
	  icount++;
	  cout<<"Bigger 0.0, depth1_HF iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      cout<<"Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
      cout<<"Bigger 0.0, depth1_HB icount = "<<icount<<endl;
      
      c1->cd(2);
      TH1F *nwod1= (TH1F*)hfile1->Get("h_bcnnbadchannels_depth2_HF");
      TH1F *nwod0= (TH1F*)hfile1->Get("h_bcnbadrate0_depth2_HF");
      nwod1->Sumw2();
      nwod0->Sumw2();
//      if(nwod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rata1 = (TH1F*)nwod1->Clone("Rata1");
	Rata1->Divide(nwod1,nwod0, 1, 1, "B");
	Rata1->Sumw2();
//      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rata1->SetMarkerStyle(20);
      Rata1->SetMarkerSize(0.8);
      Rata1->SetXTitle("< Nbcs > HF depth2                       iBCN \b");
      Rata1->SetMarkerColor(2);
      Rata1->SetLineColor(0);
      Rata1->Draw("Error");



      c1->Update();
    //=========================================================================================
     //======================================================================
    //============================================================================================= end
    //======================================================================
    //======================================================================
    // close and delete all possible things:

      psfile.Close();

//    hfile0->Close();
//    hfile0->Delete();
    hfile1->Close();
    //  hfile1->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}

