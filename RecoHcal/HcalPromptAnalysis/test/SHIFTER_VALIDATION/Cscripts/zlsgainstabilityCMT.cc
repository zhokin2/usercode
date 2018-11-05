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
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(101110);                                          // entries, mean, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		  			//	gStyle->SetOptStat(100000);//  over !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//
	//gStyle->SetOptFit(00010);// constant, mean and sigma only !!
		//	gStyle->SetOptFit(00001);// hi2/nu, constant, mean and sigma only !!
				//	gStyle->SetOptFit(0010);// constant, mean and sigma only !!
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

//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234556.root", "READ");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//	TFile *hfile1= new TFile("Global_321177_41.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600.root_no41", "READ");

//	TFile *hfile1= new TFile("Global_325001_ls1to600.root", "READ");
//	TFile *hfile1= new TFile("Global_RBX_325001_40.root", "READ");
//	TFile *hfile1= new TFile("Global_RBX_325001_ls1to600.root", "READ");
	TFile *hfile1= new TFile("Global_RBX_321177_ls1to600.root", "READ");


////////////////////////////////////////////////////////////

//	TFile *hfile1= new TFile("Global_321177_41_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap_no41.root", "READ");

//	TFile *hfile1= new TFile("Global_325001_ls1to600_abortgap.root", "READ");





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//    getchar();
	//
          TPostScript psfile ("zlsgainstabilityCMT.ps", 111);


//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH1F *Rate1= (TH1F*)hfile1->Get("h_nevents_per_eachRealLS");
      //      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Rate1->SetXTitle("nevents_per_eachRealLS \b");
      //      Rate1->Draw("");

      int maxbins = 0;
      int nx = Rate1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
	//	if(ccc1>0.) cout<<" ibin=     "<< i <<" nevents=     "<< ccc1 <<endl;
      }
      cout<<" maxbins=     "<< maxbins <<endl;

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
      //          ADCAmplperLS ->SetMaximum(30.0);
      //          ADCAmplperLS ->SetMinimum(20.0);
      ADCAmplperLS ->Draw("Error");

      c1->cd(2);
      TH1F *Rate2= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_lscounterM1");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate2->SetXTitle("lscounterM1 sumADCAmplEtaPhiLs \b");
      Rate2->Draw("");

       c1->Update();

    //========================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);

      c1->cd(1);
      TH1F *Rate3= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_bbbc");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate3->SetXTitle("bbbc sumADCAmplEtaPhiLs \b");
      Rate3->Draw("");

     c1->cd(2);
      TH1F *Rate4= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_bbb1");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate4->SetXTitle("bbb1 sumADCAmplEtaPhiLs \b");
      Rate4->Draw("");

     c1->cd(3);
      TH1F *Rate5= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate5->SetXTitle("bbb3 sumADCAmplEtaPhiLs \b");
      Rate5->Draw("");

     c1->cd(4);
      TH1F *Rate6= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_ietaphi");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate6->SetXTitle("ietaphi sumADCAmplEtaPhiLs \b");
      Rate6->Draw("");


      c1->Update();
    //========================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);
//     h_2D0sumADCAmplLS1->Fill(double(ieta), double(k3), bbb1);
      c1->cd(1);
      TH2F *Cefz2= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS1");
      gPad->SetGridy();
      gPad->SetGridx();
      //      gPad->SetLogz();
      Cefz2->SetMarkerStyle(20);
      Cefz2->SetMarkerSize(0.4);
      //    Cefz2->GetYaxis()->SetLabelSize(0.04);
      Cefz2->GetZaxis()->SetLabelSize(0.08);
      Cefz2->SetXTitle("nv0-overAllLSs test with  HB1  #eta \b");
      Cefz2->SetYTitle("#phi  \b");
      //    Cefz2->SetZTitle("<A>  - HB Depth1 \b");
      Cefz2->SetMarkerColor(2);
      Cefz2->SetLineColor(2);
      //      Cefz2->SetMaximum(1.000);
      //      Cefz2->SetMinimum(1.0);
      Cefz2->Draw("COLZ");

      c1->Update();
    //======================================================================
    //======================================================================
    //========================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,1);

      c1->cd(1);
      int maxbinx = 0;
      int maxbiny = 0;
      nx = Cefz2->GetXaxis()->GetNbins();
      int ny = Cefz2->GetYaxis()->GetNbins();
      cout<<"HB1        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* ADCAmplLSHB1 = new TH1F("ADCAmplLSHB1","", 1000, 0., 1000000.);
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Cefz2->GetBinContent(i,j);
	  if(ccc1>0.) {
	    maxbinx = i; if(i>maxbinx) maxbinx = i;
	    maxbiny = j; if(j>maxbiny) maxbiny = j;
	    //	    	    cout<<"HB1:  ibin=  "<< i <<"      jbin= "<< j <<"      A= "<< ccc1 <<endl;
	    ADCAmplLSHB1 ->Fill(ccc1);
	  }
	}}
      ADCAmplLSHB1 ->SetMarkerStyle(20);
      ADCAmplLSHB1 ->SetMarkerSize(0.4);
      ADCAmplLSHB1 ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplLSHB1 ->SetXTitle("nev0-overAllLSs test with ADCAmplLSHB1 \b");
      ADCAmplLSHB1 ->SetMarkerColor(2);
      ADCAmplLSHB1 ->SetLineColor(0);
      //          ADCAmplLSHB1 ->SetMaximum(30.0);
      //          ADCAmplLSHB1 ->SetMinimum(20.0);
      //    gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
          ADCAmplLSHB1 ->Draw("Error");
	  //   ADCAmplLSHB1 ->Draw("");
      cout<<"HB1 maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<endl;
      // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=72; nphi=82;


       c1->Update();


    //========================================================================================== 5
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      TH1F *ATIT1= (TH1F*)hfile1->Get("h_bcnvsamplitude_HB");
      TH1F *ATIT2= (TH1F*)hfile1->Get("h_bcnvsamplitude0_HB");
      int minbx = 999999;
      int maxbx = -1;
      nx = ATIT2->GetXaxis()->GetNbins();
      for (int i=0;i<=nx;i++) {
	//	i-=1;
	double ccc1 =  ATIT2->GetBinContent(i);
	if(ccc1>0.) {
	  if(i>maxbx) maxbx = i;if(i<minbx) minbx = i;
	  if(i>=3440 && i<=3570 ) cout<<"Page5: i = =     "<< i-1 <<" Ni=     "<< ccc1 <<endl;
	}}
      cout<<"Page5: minbx=     "<< minbx-1 <<" maxbx=     "<< maxbx-1 <<endl;

      c1->cd(1);
      TH1F* ITIT1 = new TH1F("ITIT1","", maxbx-minbx+1, float(minbx), maxbx+1.);
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ATIT1->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" bcnvsamplitude_HB ;  i = "<<i<<" ccc1= "<<ccc1<<endl;
	if(ccc1>0.) ITIT1 ->Fill(float(i), ccc1);
      }
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      ITIT1->SetXTitle("bcnvsamplitude_HB \b");
      ITIT1->SetMarkerStyle(20);ITIT1->SetMarkerSize(0.4);ITIT1->GetYaxis()->SetLabelSize(0.04);ITIT1->SetMarkerColor(2);ITIT1->SetLineColor(0);// ITIT1->SetMaximum(30.0);// ITIT1->SetMinimum(20.0); 
      ITIT1->Draw("Error");

      c1->cd(2);
      TH1F* ITIT2 = new TH1F("ITIT2","", maxbx-minbx+1, float(minbx), maxbx+1.);
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ATIT2->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" bcnvsamplitude_HB ;  i = "<<i<<" ccc1= "<<ccc1<<endl;
	if(ccc1>0.) ITIT2->Fill(float(i), ccc1);
      }
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      ITIT2->SetXTitle("bcnvsamplitude0 HBs \b");
      ITIT2->SetMarkerStyle(20);ITIT2->SetMarkerSize(0.4);ITIT2->GetYaxis()->SetLabelSize(0.04);ITIT2->SetMarkerColor(2);ITIT2->SetLineColor(0);// ITIT2->SetMaximum(30.0);// ITIT2->SetMinimum(20.0); 
      ITIT2->Draw("Error");
     
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
      
    //======================================================================
    //========================================================================================== 6
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
      
      c1->cd(1);
      TH1F *twrd3= (TH1F*)hfile1->Get("h_bcnvsamplitude_HB");
      TH1F *twrd2= (TH1F*)hfile1->Get("h_bcnvsamplitude0_HB");
      twrd3->Sumw2(); twrd2->Sumw2(); gPad->SetGridy();
      TH1F* Rase1 = (TH1F*)twrd3->Clone("Rase1");
      Rase1->Divide(twrd3,twrd2, 1, 1, "B");
      Rase1->Sumw2();
      TH1F* Rase1NNN = new TH1F("Rase1NNN","", maxbx-minbx+1, float(minbx), maxbx+1.);
      nx = Rase1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rase1->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HB i = "<<i<<" <A> per bx= "<<ccc1<<endl;
	  if(ccc1>0.) Rase1NNN->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Rase1NNN->SetMarkerStyle(20);Rase1NNN->SetMarkerSize(0.4);Rase1NNN->GetYaxis()->SetLabelSize(0.04);Rase1NNN->SetXTitle("<ADCAmpl> per bx HB \b");Rase1NNN->SetMarkerColor(2);Rase1NNN->SetLineColor(0);//Rase1NNN->SetMaximum(30.0);//Rase1NNN->SetMinimum(20.0);
      Rase1NNN->Draw("Error");


      c1->cd(2);
      TH1F *twed3= (TH1F*)hfile1->Get("h_bcnvsamplitude_HE");
      TH1F *twed2= (TH1F*)hfile1->Get("h_bcnvsamplitude0_HE");
      twed3->Sumw2(); twed2->Sumw2(); gPad->SetGridy();
      TH1F* Rase2 = (TH1F*)twed3->Clone("Rase2");
      Rase2->Divide(twed3,twed2, 1, 1, "B");
      Rase2->Sumw2();
      TH1F* Rase2NNN = new TH1F("Rase2NNN","", maxbx-minbx+1, float(minbx), maxbx+1.);
      nx = Rase2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rase2->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HE i = "<<i<<" <A> per bx= "<<ccc1<<endl;
	  if(ccc1>0.) Rase2NNN->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Rase2NNN->SetMarkerStyle(20);Rase2NNN->SetMarkerSize(0.4);Rase2NNN->GetYaxis()->SetLabelSize(0.04);Rase2NNN->SetXTitle("<ADCAmpl> per bx HE \b");Rase2NNN->SetMarkerColor(2);Rase2NNN->SetLineColor(0);//Rase2NNN->SetMaximum(30.0);//Rase2NNN->SetMinimum(20.0);
      Rase2NNN->Draw("Error");


      c1->cd(3);
      TH1F *twwd3= (TH1F*)hfile1->Get("h_bcnvsamplitude_HF");
      TH1F *twwd2= (TH1F*)hfile1->Get("h_bcnvsamplitude0_HF");
      twwd3->Sumw2(); twwd2->Sumw2(); gPad->SetGridy();
      TH1F* Rase3 = (TH1F*)twwd3->Clone("Rase3");
      Rase3->Divide(twwd3,twwd2, 1, 1, "B");
      Rase3->Sumw2();
      TH1F* Rase3NNN = new TH1F("Rase3NNN","", maxbx-minbx+1, float(minbx), maxbx+1.);
      nx = Rase3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rase3->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HF i = "<<i<<" <A> per bx= "<<ccc1<<endl;
	  if(ccc1>0.) Rase3NNN->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Rase3NNN->SetMarkerStyle(20);Rase3NNN->SetMarkerSize(0.4);Rase3NNN->GetYaxis()->SetLabelSize(0.04);Rase3NNN->SetXTitle("<ADCAmpl> per bx HF \b");Rase3NNN->SetMarkerColor(2);Rase3NNN->SetLineColor(0);//Rase3NNN->SetMaximum(30.0);//Rase3NNN->SetMinimum(20.0);
      Rase3NNN->Draw("Error");


      c1->cd(4);
      TH1F *twqd3= (TH1F*)hfile1->Get("h_bcnvsamplitude_HO");
      TH1F *twqd2= (TH1F*)hfile1->Get("h_bcnvsamplitude0_HO");
      twqd3->Sumw2(); twqd2->Sumw2(); gPad->SetGridy();
      TH1F* Rase4 = (TH1F*)twqd3->Clone("Rase4");
      Rase4->Divide(twqd3,twqd2, 1, 1, "B");
      Rase4->Sumw2();
      TH1F* Rase4NNN = new TH1F("Rase4NNN","", maxbx-minbx+1, float(minbx), maxbx+1.);
      nx = Rase4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rase4->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HO i = "<<i<<" <A> per bx= "<<ccc1<<endl;
	  if(ccc1>0.) Rase4NNN->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Rase4NNN->SetMarkerStyle(20);Rase4NNN->SetMarkerSize(0.4);Rase4NNN->GetYaxis()->SetLabelSize(0.04);Rase4NNN->SetXTitle("<ADCAmpl> per bx HO \b");Rase4NNN->SetMarkerColor(2);Rase4NNN->SetLineColor(0);//Rase4NNN->SetMaximum(30.0);//Rase4NNN->SetMinimum(20.0);
      Rase4NNN->Draw("Error");

       c1->Update();
    //========================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);

      c1->cd(1);
      TH1F *Rate7= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_orbitNum");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate7->SetXTitle("h_sumADCAmplEtaPhiLs_orbitNum \b");
      Rate7->Draw("");

     c1->cd(2);
      TH1F *Rate8= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_lscounterM1");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate8->SetXTitle("h_sumADCAmplEtaPhiLs_lscounterM1 \b");
      Rate8->Draw("");

     c1->cd(3);
      TH1F *Rate9= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_lscounterM1orbitNum");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Rate9->SetXTitle("h_sumADCAmplEtaPhiLs_lscounterM1orbitNum \b");
      Rate9->Draw("");


      c1->Update();
    //======================================================================
    //========================================================================================== 8
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      TH1F *ASSS1= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_lscounterM1orbitNum");
      TH1F *ASSS2= (TH1F*)hfile1->Get("h_sumADCAmplEtaPhiLs_lscounterM1");
      int minls = 999999;
      int maxls = -1;
      nx = ASSS2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ASSS2->GetBinContent(i);
	if(ccc1>0.) {if(i>maxls) maxls = i;if(i<minls) minls = i;}
	//	  if(ccc1>0.)	  cout<<" ASSS2 ;  i = "<<i<<" ccc1= "<<ccc1<<endl;
	//	if(ccc1>0.) {maxls = i; if(i>maxls) maxls = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" minls=     "<< minls <<" maxls=     "<< maxls <<endl;
      //////////////////////////////////////////////////////////////////////////////////////
      c1->cd(1);
      TH1F* ISSS1 = new TH1F("ISSS1","", maxls-minls+1, float(minls), maxls+1.);
      for (int i=0;i<=nx;i++) {
	double ccc1 =  ASSS1->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" bcnvsamplitude_HB ;  i = "<<i<<" ccc1= "<<ccc1<<endl;
	if(ccc1>0.) ISSS1 ->Fill(float(i), ccc1);
      }
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      ISSS1->SetXTitle("lscounterM1 w = orbitNum*Nentries \b");
      ISSS1->SetMarkerStyle(20);ISSS1->SetMarkerSize(0.4);ISSS1->GetYaxis()->SetLabelSize(0.04);ISSS1->SetMarkerColor(2);ISSS1->SetLineColor(0);// ISSS1->SetMaximum(30.0);// ISSS1->SetMinimum(20.0); 
      ISSS1->Draw("Error");
      //////////////////////////////////////////////////////////////////////////////////////
      c1->cd(2);
      TH1F* ISSS2 = new TH1F("ISSS2","", maxls-minls+1, float(minls), maxls+1.);
      for (int i=0;i<=nx;i++) {
	double ccc1 =  ASSS2->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" bcnvsamplitude_HB ;  i = "<<i<<" ccc1= "<<ccc1<<endl;
	if(ccc1>0.) ISSS2->Fill(float(i), ccc1);
      }
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      ISSS2->SetXTitle("lscounterM1 w = Nentries \b");
      ISSS2->SetMarkerStyle(20);ISSS2->SetMarkerSize(0.4);ISSS2->GetYaxis()->SetLabelSize(0.04);ISSS2->SetMarkerColor(2);ISSS2->SetLineColor(0);// ISSS2->SetMaximum(30.0);// ISSS2->SetMinimum(20.0); 
      ISSS2->Draw("Error");
      //////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      TH1F* Roze1 = (TH1F*)ASSS2->Clone("Roze1");
      Roze1->Divide(ASSS1,ASSS2, 1, 1, "B");
      Roze1->Sumw2();
      TH1F* Roze1NNN = new TH1F("Roze1NNN","", maxls-minls+1, float(minls), maxls+1.);
      nx = Roze1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Roze1->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HB i = "<<i<<" <A> per ls= "<<ccc1<<endl;
	  if(ccc1>0.) Roze1NNN->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Roze1NNN->SetMarkerStyle(20);Roze1NNN->SetMarkerSize(0.4);Roze1NNN->GetYaxis()->SetLabelSize(0.04);Roze1NNN->SetXTitle("lscounterM1 w = <orbitNum> \b");Roze1NNN->SetMarkerColor(2);Roze1NNN->SetLineColor(0);//Roze1NNN->SetMaximum(30.0);//Roze1NNN->SetMinimum(20.0);
      Roze1NNN->Draw("Error");

       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
      
    //========================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);

      c1->cd(1);
      TH1F *TEST7= (TH1F*)hfile1->Get("h_orbitNumvsamplitude_HB");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      TEST7->SetXTitle("h_orbitNumvsamplitude_HB \b");
      TEST7->Draw("");

     c1->cd(2);
      TH1F *TEST8= (TH1F*)hfile1->Get("h_orbitNumvsamplitude0_HB");
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      TEST8->SetXTitle("h_orbitNumvsamplitude0_HB \b");
      TEST8->Draw("");

      c1->cd(3);
      TH1F* TEST9 = (TH1F*)TEST8->Clone("TEST9");
      TEST9->Divide(TEST7,TEST8, 1, 1, "B");  
      //    TH1F* TEST9 = new TH1F("TEST9","", zaP, zaR, zaR2);
      //      TH1F* TEST9 = new TH1F("TEST9","", maxorbitNum-minorbitNum+1, float(minorbitNum), maxorbitNum+1.);
      /*
      nx =TEST9->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  TEST9->GetBinContent(i);
		if(ccc1>0.)	  cout<<" HB i = "<<i<<" <A> per orbitNum= "<<ccc1<<endl;
		//	  if(ccc1>0.) TEST9->Fill(float(i), ccc1);
      }
*/
      //      gPad->SetLogy();
      TEST9->SetMarkerStyle(20);TEST9->SetMarkerSize(0.4);TEST9->GetYaxis()->SetLabelSize(0.04);TEST9->SetXTitle("<ADCAmpl> per orbitNum HB \b");TEST9->SetMarkerColor(2);TEST9->SetLineColor(0);//TEST9->SetMaximum(30.0);//TEST9->SetMinimum(20.0);
      TEST9->Draw("Error");


      c1->Update();
    //======================================================================
    //========================================================================================== 10
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);
      
      c1->cd(1);
      TH1F *kqrd3= (TH1F*)hfile1->Get("h_orbitNumvsamplitude_HB");
      TH1F *kqrd2= (TH1F*)hfile1->Get("h_orbitNumvsamplitude0_HB");
      kqrd3->Sumw2(); kqrd2->Sumw2(); gPad->SetGridy();
      TH1F* Posw1 = (TH1F*)kqrd3->Clone("Posw1");
      Posw1->Divide(kqrd3,kqrd2, 1, 1, "B");      Posw1->Sumw2();
      //    TH1F* Posw1 = new TH1F("Posw1","", zaP, zaR, zaR2);
      //      TH1F* Posw1 = new TH1F("Posw1","", maxorbitNum-minorbitNum+1, float(minorbitNum), maxorbitNum+1.);
      nx = Posw1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Posw1->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HB i = "<<i<<" <A> per orbitNum= "<<ccc1<<endl;
	  if(ccc1>0.) Posw1->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Posw1->SetMarkerStyle(20);Posw1->SetMarkerSize(0.4);Posw1->GetYaxis()->SetLabelSize(0.04);Posw1->SetXTitle("<ADCAmpl> per orbitNum HB \b");Posw1->SetMarkerColor(2);Posw1->SetLineColor(0);//Posw1->SetMaximum(30.0);//Posw1->SetMinimum(20.0);
      Posw1->Draw("Error");


      c1->cd(2);
      TH1F *kqed3= (TH1F*)hfile1->Get("h_orbitNumvsamplitude_HE");
      TH1F *kqed2= (TH1F*)hfile1->Get("h_orbitNumvsamplitude0_HE");
      kqed3->Sumw2(); kqed2->Sumw2(); gPad->SetGridy();
      TH1F* Posw2 = (TH1F*)kqed3->Clone("Posw2");
      Posw2->Divide(kqed3,kqed2, 1, 1, "B");
      Posw2->Sumw2();
      //    TH1F* Posw2 = new TH1F("Posw2","", zaP, zaR, zaR2);
      //      TH1F* Posw2 = new TH1F("Posw2","", maxorbitNum-minorbitNum+1, float(minorbitNum), maxorbitNum+1.);
      nx = Posw2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Posw2->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HE i = "<<i<<" <A> per orbitNum= "<<ccc1<<endl;
	  if(ccc1>0.) Posw2->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Posw2->SetMarkerStyle(20);Posw2->SetMarkerSize(0.4);Posw2->GetYaxis()->SetLabelSize(0.04);Posw2->SetXTitle("<ADCAmpl> per orbitNum HE \b");Posw2->SetMarkerColor(2);Posw2->SetLineColor(0);//Posw2->SetMaximum(30.0);//Posw2->SetMinimum(20.0);
      Posw2->Draw("Error");


      c1->cd(3);
      TH1F *kqwd3= (TH1F*)hfile1->Get("h_orbitNumvsamplitude_HF");
      TH1F *kqwd2= (TH1F*)hfile1->Get("h_orbitNumvsamplitude0_HF");
      kqwd3->Sumw2(); kqwd2->Sumw2(); gPad->SetGridy();
      TH1F* Posw3 = (TH1F*)kqwd3->Clone("Posw3");
      Posw3->Divide(kqwd3,kqwd2, 1, 1, "B");
      Posw3->Sumw2();
      //    TH1F* Posw3 = new TH1F("Posw3","", zaP, zaR, zaR2);
      //      TH1F* Posw3 = new TH1F("Posw3","", maxorbitNum-minorbitNum+1, float(minorbitNum), maxorbitNum+1.);
      nx = Posw3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Posw3->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HF i = "<<i<<" <A> per orbitNum= "<<ccc1<<endl;
	  if(ccc1>0.) Posw3->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Posw3->SetMarkerStyle(20);Posw3->SetMarkerSize(0.4);Posw3->GetYaxis()->SetLabelSize(0.04);Posw3->SetXTitle("<ADCAmpl> per orbitNum HF \b");Posw3->SetMarkerColor(2);Posw3->SetLineColor(0);//Posw3->SetMaximum(30.0);//Posw3->SetMinimum(20.0);
      Posw3->Draw("Error");


      c1->cd(4);
      TH1F *kqqd3= (TH1F*)hfile1->Get("h_orbitNumvsamplitude_HO");
      TH1F *kqqd2= (TH1F*)hfile1->Get("h_orbitNumvsamplitude0_HO");
      kqqd3->Sumw2(); kqqd2->Sumw2(); gPad->SetGridy();
      TH1F* Posw4 = (TH1F*)kqqd3->Clone("Posw4");
      Posw4->Divide(kqqd3,kqqd2, 1, 1, "B");
      Posw4->Sumw2();
      //    TH1F* Posw4 = new TH1F("Posw4","", zaP, zaR, zaR2);
      //    TH1F* Posw4 = new TH1F("Posw4","", maxorbitNum-minorbitNum+1, float(minorbitNum), maxorbitNum+1.);
      nx = Posw4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Posw4->GetBinContent(i);
	//	if(ccc1>0.)	  cout<<" HO i = "<<i<<" <A> per orbitNum= "<<ccc1<<endl;
	  if(ccc1>0.) Posw4->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      Posw4->SetMarkerStyle(20);Posw4->SetMarkerSize(0.4);Posw4->GetYaxis()->SetLabelSize(0.04);Posw4->SetXTitle("<ADCAmpl> per orbitNum HO \b");Posw4->SetMarkerColor(2);Posw4->SetLineColor(0);//Posw4->SetMaximum(30.0);//Posw4->SetMinimum(20.0);
      Posw4->Draw("Error");

       c1->Update();

    //========================================================================================== 11    HB - "h_2DsumADCAmplEtaPhiLs0
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TH2F *Cefz1KKK= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs0");
      TH2F *Cefz1LLL= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs00");
      TH2F* Cefz1 = (TH2F*)Cefz1LLL->Clone("Cefz1");
      Cefz1->Divide(Cefz1KKK,Cefz1LLL, 1, 1, "B");// average A
      Cefz1->Sumw2();

      int sumijhb = 0;
      c1->cd(1);
      maxbinx = 0;
      maxbiny = 0;
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();
      cout<<"HB h_2DsumADCAmplEtaPhiLs0         nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* ADCAmplLS0 = new TH1F("ADCAmplLS0","", 100, 0., 50.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  sumijhb++;
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HB h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  ADCAmplLS0 ->Fill(ccc1);
	}
      }}
      cout<<"HB maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<"     sumijhb=  "<< sumijhb <<endl;
      ADCAmplLS0 ->SetMarkerStyle(20);ADCAmplLS0 ->SetMarkerSize(0.4);ADCAmplLS0 ->GetYaxis()->SetLabelSize(0.04);ADCAmplLS0 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");ADCAmplLS0->SetYTitle("     HB \b");ADCAmplLS0 ->SetMarkerColor(2);ADCAmplLS0 ->SetLineColor(0);//ADCAmplLS0->SetMinimum(10.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      ADCAmplLS0 ->Draw("L");
            ADCAmplLS0 ->Draw("Error");
	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(2);
      TH1F* ADCAmplLS = new TH1F("ADCAmplLS","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  //	  cout<<"HB h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  //	  ADCAmplLS ->Fill(ccc1/maxbinx);
	  ADCAmplLS ->Fill( float(i), ccc1*maxbinx/sumijhb);
	}
      }}
      ADCAmplLS ->SetMarkerStyle(20);ADCAmplLS ->SetMarkerSize(0.4);ADCAmplLS ->GetYaxis()->SetLabelSize(0.04);ADCAmplLS ->SetMarkerColor(2);ADCAmplLS ->SetLineColor(0);
      ADCAmplLS->SetXTitle("        iLS  \b");  ADCAmplLS->SetYTitle("     <A>k \b");
      //ADCAmplLS->SetMinimum(0.8);ADCAmplLS->SetMaximum(500.);
      //      gPad->SetLogy();
      gPad->SetGridy();gPad->SetGridx();     
      ADCAmplLS ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      TH1F* ADCAmplLS1 = new TH1F("ADCAmplLS1","", 200, 0., 100.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Cefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HB h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  ADCAmplLS1 ->Fill(ccc1);
	}
      }}
      cout<<"HB maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<endl;
      ADCAmplLS1 ->SetMarkerStyle(20);ADCAmplLS1 ->SetMarkerSize(0.4);ADCAmplLS1 ->GetYaxis()->SetLabelSize(0.04);ADCAmplLS1 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");ADCAmplLS1 ->SetMarkerColor(2);ADCAmplLS1 ->SetLineColor(0);  ADCAmplLS1->SetMinimum(0.8);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      ADCAmplLS1 ->Draw("L");
            ADCAmplLS1 ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    c1->cd(4);
	    // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; 
	    //          neta=72;    nphi=82;
	    //         zneta=18;   znphi=22;
	    TH2F* Cefz4     = new TH2F("Cefz4","",  22, -11., 11., 18, 0., 18. );
	    // i - # LSs:
	    for (int i=1;i<=nx;i++) {
	      // j - etaphi index:
	      for (int j=1;j<=ny;j++) {
		double ccc1 =  Cefz1->GetBinContent(i,j);
		//if(ccc1>0.) cout<<"HB h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1/maxbinx <<endl;
		//	if(ccc1>0. && ccc1/maxbinx < 2000) {
		if(ccc1>0.) {
		  int jeta = (j-1)/18;// jeta = 0-21
		  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
		  //	  jeta += 1;// jeta = 1-22
		  //		  if(i==1) cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta-11 <<" jphi= "<< jphi-1 <<"  A= "<< ccc1/maxbinx <<endl;
		  //	  Cefz4 ->Fill(jeta-11,jphi-1,ccc1/maxbinx);
		  
		  
		  Cefz4 ->Fill(jeta-11,jphi-1,ccc1*maxbiny/sumijhb);
		}
	      }}
	    gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
	    Cefz4->SetMarkerStyle(20); Cefz4->SetMarkerSize(0.4); Cefz4->GetZaxis()->SetLabelSize(0.08); Cefz4->SetXTitle("<A>ij         #eta  \b"); Cefz4->SetYTitle("      #phi \b"); Cefz4->SetZTitle("<A>ij  - All \b"); Cefz4->SetMarkerColor(2); Cefz4->SetLineColor(2);      //      Cefz4->SetMaximum(1.000);  //      Cefz4->SetMinimum(1.0);
	    Cefz4->Draw("COLZ");
	    
	    c1->Update();

    //======================================================================

    //========================================================================================== 12   HB
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();
      cout<<"HB GainStability        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* GainStability0 = new TH1F("GainStability0","", 620, 0., 620.);
      TH1F* GainStability1 = new TH1F("GainStability1","", 620, 0., 620.);
      TH1F* GainStability2 = new TH1F("GainStability2","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Cefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    int jeta = (j-1)/18;// jeta = 0-21
	    int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	    //	  jeta += 1;// jeta = 1-22
	    //	    cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	    if(jeta== 8 && jphi==11) GainStability0 ->Fill(i,ccc1);
	    if(jeta==10 && jphi==11) GainStability1 ->Fill(i,ccc1);
	    if(jeta==12 && jphi==11) GainStability2 ->Fill(i,ccc1);
	  }
	}}
      GainStability0 ->SetMarkerStyle(20);GainStability0 ->SetMarkerSize(0.4);GainStability0 ->GetYaxis()->SetLabelSize(0.04);GainStability0 ->SetXTitle("GainStability0 \b");GainStability0 ->SetMarkerColor(2);GainStability0 ->SetLineColor(0);// GainStability0 ->SetMaximum(30.0);// GainStability0 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      GainStability0 ->Draw("Error");
      
    //================
      c1->cd(2);
      GainStability1 ->SetMarkerStyle(20);GainStability1 ->SetMarkerSize(0.4);GainStability1 ->GetYaxis()->SetLabelSize(0.04);GainStability1 ->SetXTitle("GainStability1 \b");GainStability1 ->SetMarkerColor(2);GainStability1 ->SetLineColor(0);// GainStability1 ->SetMaximum(30.0);// GainStability1 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      GainStability1 ->Draw("Error");
      
    //================
      c1->cd(3);
      GainStability2 ->SetMarkerStyle(20);GainStability2 ->SetMarkerSize(0.4);GainStability2 ->GetYaxis()->SetLabelSize(0.04);GainStability2 ->SetXTitle("GainStability2 \b");GainStability2 ->SetMarkerColor(2);GainStability2 ->SetLineColor(0);// GainStability2 ->SetMaximum(30.0);// GainStability2 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      GainStability2 ->Draw("Error");
      
      ////////////////////////////////////////////////////////////////////////////////////
      
      
       c1->Update();



    //========================================================================================== 13  HB: j = 7,8,9,10            11,12,13,14      7
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta0k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      int kcount=1;
      cout<<"HB Gforhbjeta0k *********************************************************************       jeta == 7    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 7) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta0k0 = new TH1F("Gforhbjeta0k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta0k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta0k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta0k0 ->SetMarkerStyle(20);Gforhbjeta0k0 ->SetMarkerSize(0.4);Gforhbjeta0k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta0k0 ->SetXTitle("Gforhbjeta0k0 \b");Gforhbjeta0k0 ->SetMarkerColor(2);Gforhbjeta0k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta0k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta0k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 14 HB: j = 7,8,9,10            11,12,13,14     8
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta1k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta1k *********************************************************************       jeta == 8    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 8) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta1k0 = new TH1F("Gforhbjeta1k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta1k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta1k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta1k0 ->SetMarkerStyle(20);Gforhbjeta1k0 ->SetMarkerSize(0.4);Gforhbjeta1k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta1k0 ->SetXTitle("Gforhbjeta1k0 \b");Gforhbjeta1k0 ->SetMarkerColor(2);Gforhbjeta1k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta1k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta1k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 15 HB: j = 7,8,9,10            11,12,13,14      9
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta2k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta2k *********************************************************************       jeta == 9    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 9) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta2k0 = new TH1F("Gforhbjeta2k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta2k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta2k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta2k0 ->SetMarkerStyle(20);Gforhbjeta2k0 ->SetMarkerSize(0.4);Gforhbjeta2k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta2k0 ->SetXTitle("Gforhbjeta2k0 \b");Gforhbjeta2k0 ->SetMarkerColor(2);Gforhbjeta2k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta2k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta2k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 16 HB: j = 7,8,9,10            11,12,13,14       10
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta3k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta3k *********************************************************************       jeta == 10   "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 10) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta3k0 = new TH1F("Gforhbjeta3k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta3k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta3k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta3k0 ->SetMarkerStyle(20);Gforhbjeta3k0 ->SetMarkerSize(0.4);Gforhbjeta3k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta3k0 ->SetXTitle("Gforhbjeta3k0 \b");Gforhbjeta3k0 ->SetMarkerColor(2);Gforhbjeta3k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta3k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta3k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 17 HB: j = 7,8,9,10            11,12,13,14        11
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta18k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta18k *********************************************************************       jeta == 11    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 11) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta18k0 = new TH1F("Gforhbjeta18k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta18k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta18k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta18k0 ->SetMarkerStyle(20);Gforhbjeta18k0 ->SetMarkerSize(0.4);Gforhbjeta18k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta18k0 ->SetXTitle("Gforhbjeta18k0 \b");Gforhbjeta18k0 ->SetMarkerColor(2);Gforhbjeta18k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta18k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta18k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 18 HB: j = 7,8,9,10            11,12,13,14       12
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta19k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta19k *********************************************************************       jeta == 12    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 12) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta19k0 = new TH1F("Gforhbjeta19k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta19k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta19k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta19k0 ->SetMarkerStyle(20);Gforhbjeta19k0 ->SetMarkerSize(0.4);Gforhbjeta19k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta19k0 ->SetXTitle("Gforhbjeta19k0 \b");Gforhbjeta19k0 ->SetMarkerColor(2);Gforhbjeta19k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta19k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta19k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 19 HB: j = 7,8,9,10            11,12,13,14       13
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta20k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta20k *********************************************************************       jeta == 13    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 13) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta20k0 = new TH1F("Gforhbjeta20k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta20k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta20k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta20k0 ->SetMarkerStyle(20);Gforhbjeta20k0 ->SetMarkerSize(0.4);Gforhbjeta20k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta20k0 ->SetXTitle("Gforhbjeta20k0 \b");Gforhbjeta20k0 ->SetMarkerColor(2);Gforhbjeta20k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta20k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta20k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 20 HB: j = 7,8,9,10            11,12,13,14        14
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Cefz1->GetXaxis()->GetNbins();
      ny = Cefz1->GetYaxis()->GetNbins();

      //    if( nlsohb > 0.)      nhistohb /= nlsohb;
      //    cout<<"HB Gforhbjeta21k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohb=     "<< nhistohb <<endl;
      kcount=1;
      cout<<"HB Gforhbjeta21k *********************************************************************       jeta == 14    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 14) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhbjeta21k0 = new TH1F("Gforhbjeta21k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Cefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HB  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhbjeta21k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HB Gforhbjeta21k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhbjeta21k0 ->SetMarkerStyle(20);Gforhbjeta21k0 ->SetMarkerSize(0.4);Gforhbjeta21k0 ->GetYaxis()->SetLabelSize(0.04);Gforhbjeta21k0 ->SetXTitle("Gforhbjeta21k0 \b");Gforhbjeta21k0 ->SetMarkerColor(2);Gforhbjeta21k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhbjeta21k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhbjeta21k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 21    HE - "h_2DsumADCAmplEtaPhiLs1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TH2F *Sefz1KKK= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs1");
      TH2F *Sefz1LLL= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs10");
      TH2F* Sefz1 = (TH2F*)Sefz1LLL->Clone("Sefz1");
      Sefz1->Divide(Sefz1KKK,Sefz1LLL, 1, 1, "B");// average A
      Sefz1->Sumw2();

      c1->cd(1);
      maxbinx = 0;
      maxbiny = 0;
      int sumijhe = 0;
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();
      cout<<"HE h_2DsumADCAmplEtaPhiLs0         nx=     "<< nx <<" ny=     "<< ny <<endl;
      // i - # LSs:
      TH1F* Sefw0 = new TH1F("Sefw0","", 200, 0., 9000.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Sefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  sumijhe++;
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HE h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Sefw0 ->Fill(ccc1);
	}
      }}
      cout<<"HE maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<"     sumijhe=  "<< sumijhe <<endl;
      Sefw0 ->SetMarkerStyle(20);Sefw0 ->SetMarkerSize(0.4);Sefw0 ->GetYaxis()->SetLabelSize(0.04);Sefw0 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Sefw0->SetYTitle("     HE \b");Sefw0->SetMarkerColor(2);Sefw0 ->SetLineColor(0);  Sefw0->SetMinimum(10.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Sefw0 ->Draw("L");
            Sefw0 ->Draw("Error");
	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(2);
      TH1F* Sefw = new TH1F("Sefw","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Sefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  //	  cout<<"HE h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  //	  Sefw ->Fill(ccc1/maxbinx);
	  Sefw ->Fill( float(i), ccc1*maxbinx/sumijhe);
	}
      }}
      Sefw ->SetMarkerStyle(20);Sefw ->SetMarkerSize(0.4);Sefw ->GetYaxis()->SetLabelSize(0.04);Sefw ->SetMarkerColor(2);Sefw ->SetLineColor(0);
      Sefw->SetXTitle("        iLS  \b");  Sefw->SetYTitle("     <A>k \b");
      //Sefw->SetMinimum(0.8);Sefw->SetMaximum(500.);
      gPad->SetLogy();
      gPad->SetGridy();gPad->SetGridx();     
      Sefw ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      TH1F* Sefw1 = new TH1F("Sefw1","", 100, 0., 5000.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Sefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HE h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Sefw1 ->Fill(ccc1);
	}
      }}
      cout<<"HE maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<endl;
      Sefw1 ->SetMarkerStyle(20);Sefw1 ->SetMarkerSize(0.4);Sefw1 ->GetYaxis()->SetLabelSize(0.04);Sefw1 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Sefw1 ->SetMarkerColor(2);Sefw1 ->SetLineColor(0);
      //Sefw1->SetMinimum(0.8);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Sefw1 ->Draw("L");
            Sefw1 ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    c1->cd(4);
	    // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
	    TH2F* Sefz4     = new TH2F("Sefz4","",  22, -11., 11., 18, 0., 18. );
	    // i - # LSs:
	    for (int i=1;i<=nx;i++) {
	      // j - etaphi index:
	      for (int j=1;j<=ny;j++) {
		double ccc1 =  Sefz1->GetBinContent(i,j);
		//if(ccc1>0.) cout<<"HE h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1/maxbinx <<endl;
		//	if(ccc1>0. && ccc1/maxbinx < 2000) {
		if(ccc1>0.) {
		  int jeta = (j-1)/18;// jeta = 0-21
		  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
		  //	  jeta += 1;// jeta = 1-22
		  //		  if(i==1) cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta-11 <<" jphi= "<< jphi-1 <<"  A= "<< ccc1/maxbinx <<endl;
		  //	  Sefz4 ->Fill(jeta-11,jphi-1,ccc1/maxbinx);
		  Sefz4 ->Fill(jeta-11,jphi-1,ccc1*maxbiny/sumijhe);
		}
	      }}
	    gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
	    Sefz4->SetMarkerStyle(20); Sefz4->SetMarkerSize(0.4); Sefz4->GetZaxis()->SetLabelSize(0.08); Sefz4->SetXTitle("<A>ij         #eta  \b"); Sefz4->SetYTitle("      #phi \b"); Sefz4->SetZTitle("<A>ij  - All \b"); Sefz4->SetMarkerColor(2); Sefz4->SetLineColor(2);      //      Sefz4->SetMaximum(1.000);  //      Sefz4->SetMinimum(1.0);
	    Sefz4->Draw("COLZ");
	    
	    c1->Update();
	    
    //======================================================================

    //========================================================================================== 22 HE
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();
      cout<<"HE Sefk        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* Sefk0 = new TH1F("Sefk0","", 620, 0., 620.);
      TH1F* Sefk1 = new TH1F("Sefk1","", 620, 0., 620.);
      TH1F* Sefk2 = new TH1F("Sefk2","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Sefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    int jeta = (j-1)/18;// jeta = 0-21
	    int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	    //	  jeta += 1;// jeta = 1-22
	    //	    cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	    if(jeta== 4 && jphi==11) Sefk0 ->Fill(i,ccc1);
	    if(jeta== 5 && jphi==11) Sefk1 ->Fill(i,ccc1);
	    if(jeta==16 && jphi==11) Sefk2 ->Fill(i,ccc1);
	  }
	}}
      Sefk0 ->SetMarkerStyle(20);Sefk0 ->SetMarkerSize(0.4);Sefk0 ->GetYaxis()->SetLabelSize(0.04);Sefk0 ->SetXTitle("Sefk0 \b");Sefk0 ->SetMarkerColor(2);Sefk0 ->SetLineColor(0);// Sefk0 ->SetMaximum(30.0);// Sefk0 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Sefk0 ->Draw("Error");
      
    //================
      c1->cd(2);
      Sefk1 ->SetMarkerStyle(20);Sefk1 ->SetMarkerSize(0.4);Sefk1 ->GetYaxis()->SetLabelSize(0.04);Sefk1 ->SetXTitle("Sefk1 \b");Sefk1 ->SetMarkerColor(2);Sefk1 ->SetLineColor(0);// Sefk1 ->SetMaximum(30.0);// Sefk1 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Sefk1 ->Draw("Error");
      
    //================
      c1->cd(3);
      Sefk2 ->SetMarkerStyle(20);Sefk2 ->SetMarkerSize(0.4);Sefk2 ->GetYaxis()->SetLabelSize(0.04);Sefk2 ->SetXTitle("Sefk2 \b");Sefk2 ->SetMarkerColor(2);Sefk2 ->SetLineColor(0);// Sefk2 ->SetMaximum(30.0);// Sefk2 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Sefk2 ->Draw("Error");
      
      ////////////////////////////////////////////////////////////////////////////////////
      
      
       c1->Update();



    //========================================================================================== 23  HE: j = 3,4,5, 6, 7      14,15,16,17,18                 3
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta0k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta0k *********************************************************************       jeta == 3    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 3) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta0k0 = new TH1F("Gforhejeta0k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta0k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta0k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta0k0 ->SetMarkerStyle(20);Gforhejeta0k0 ->SetMarkerSize(0.4);Gforhejeta0k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta0k0 ->SetXTitle("Gforhejeta0k0 \b");Gforhejeta0k0 ->SetMarkerColor(2);Gforhejeta0k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta0k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta0k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 24 HE: j = 3,4,5, 6, 7      14,15,16,17,18                     4
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta1k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta1k *********************************************************************       jeta == 4    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 4) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta1k0 = new TH1F("Gforhejeta1k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta1k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta1k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta1k0 ->SetMarkerStyle(20);Gforhejeta1k0 ->SetMarkerSize(0.4);Gforhejeta1k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta1k0 ->SetXTitle("Gforhejeta1k0 \b");Gforhejeta1k0 ->SetMarkerColor(2);Gforhejeta1k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta1k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta1k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 25 HE: j = 3,4,5, 6, 7      14,15,16,17,18          5
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta2k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta2k *********************************************************************       jeta == 5    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 5) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta2k0 = new TH1F("Gforhejeta2k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta2k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta2k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta2k0 ->SetMarkerStyle(20);Gforhejeta2k0 ->SetMarkerSize(0.4);Gforhejeta2k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta2k0 ->SetXTitle("Gforhejeta2k0 \b");Gforhejeta2k0 ->SetMarkerColor(2);Gforhejeta2k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta2k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta2k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 26 HE: j = 3,4,5, 6, 7      14,15,16,17,18            6
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta3k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta3k *********************************************************************       jeta ==   6  "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta ==  6) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta3k0 = new TH1F("Gforhejeta3k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta3k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta3k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta3k0 ->SetMarkerStyle(20);Gforhejeta3k0 ->SetMarkerSize(0.4);Gforhejeta3k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta3k0 ->SetXTitle("Gforhejeta3k0 \b");Gforhejeta3k0 ->SetMarkerColor(2);Gforhejeta3k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta3k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta3k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 27 HE: j = 3,4,5, 6, 7      14,15,16,17,18    7
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta18k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta18k *********************************************************************       jeta ==  7    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta ==  7) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta18k0 = new TH1F("Gforhejeta18k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta18k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta18k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta18k0 ->SetMarkerStyle(20);Gforhejeta18k0 ->SetMarkerSize(0.4);Gforhejeta18k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta18k0 ->SetXTitle("Gforhejeta18k0 \b");Gforhejeta18k0 ->SetMarkerColor(2);Gforhejeta18k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta18k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta18k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 28 HE: j = 3,4,5, 6, 7      14,15,16,17,18           14
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta19k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta19k *********************************************************************       jeta == 14    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 14) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta19k0 = new TH1F("Gforhejeta19k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta19k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta19k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta19k0 ->SetMarkerStyle(20);Gforhejeta19k0 ->SetMarkerSize(0.4);Gforhejeta19k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta19k0 ->SetXTitle("Gforhejeta19k0 \b");Gforhejeta19k0 ->SetMarkerColor(2);Gforhejeta19k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta19k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta19k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 29 HE: j = 3,4,5, 6, 7      14,15,16,17,18     15
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta20k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta20k *********************************************************************       jeta == 15    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 15) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta20k0 = new TH1F("Gforhejeta20k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta20k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta20k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta20k0 ->SetMarkerStyle(20);Gforhejeta20k0 ->SetMarkerSize(0.4);Gforhejeta20k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta20k0 ->SetXTitle("Gforhejeta20k0 \b");Gforhejeta20k0 ->SetMarkerColor(2);Gforhejeta20k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta20k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta20k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 30 HE: j = 3,4,5, 6, 7      14,15,16,17,18    16
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta21k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta21k *********************************************************************       jeta ==  16   "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 16) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta21k0 = new TH1F("Gforhejeta21k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta21k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta21k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta21k0 ->SetMarkerStyle(20);Gforhejeta21k0 ->SetMarkerSize(0.4);Gforhejeta21k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta21k0 ->SetXTitle("Gforhejeta21k0 \b");Gforhejeta21k0 ->SetMarkerColor(2);Gforhejeta21k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta21k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta21k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 31 HE: j = 3,4,5, 6, 7      14,15,16,17,18         17
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta22k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta22k *********************************************************************       jeta == 17    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 17) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta22k0 = new TH1F("Gforhejeta22k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta22k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta22k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta22k0 ->SetMarkerStyle(20);Gforhejeta22k0 ->SetMarkerSize(0.4);Gforhejeta22k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta22k0 ->SetXTitle("Gforhejeta22k0 \b");Gforhejeta22k0 ->SetMarkerColor(2);Gforhejeta22k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta22k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta22k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 32 HE: j = 3,4,5, 6, 7      14,15,16,17,18          18
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Sefz1->GetXaxis()->GetNbins();
      ny = Sefz1->GetYaxis()->GetNbins();

      //    if( nlsohe > 0.)      nhistohe /= nlsohe;
      //    cout<<"HE Gforhejeta23k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohe=     "<< nhistohe <<endl;
      kcount=1;
      cout<<"HE Gforhejeta23k *********************************************************************       jeta == 18    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 18) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhejeta23k0 = new TH1F("Gforhejeta23k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Sefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HE  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhejeta23k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HE Gforhejeta23k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhejeta23k0 ->SetMarkerStyle(20);Gforhejeta23k0 ->SetMarkerSize(0.4);Gforhejeta23k0 ->GetYaxis()->SetLabelSize(0.04);Gforhejeta23k0 ->SetXTitle("Gforhejeta23k0 \b");Gforhejeta23k0 ->SetMarkerColor(2);Gforhejeta23k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhejeta23k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhejeta23k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 33    HO - "h_2DsumADCAmplEtaPhiLs2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TH2F *Yefz1KKK= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs2");
      TH2F *Yefz1LLL= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs20");
      TH2F* Yefz1 = (TH2F*)Yefz1LLL->Clone("Yefz1");
      Yefz1->Divide(Yefz1KKK,Yefz1LLL, 1, 1, "B");// average A
      Yefz1->Sumw2();

      c1->cd(1);
      maxbinx = 0;
      maxbiny = 0;
      int sumijho = 0;
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();
      cout<<"HO h_2DsumADCAmplEtaPhiLs0         nx=     "<< nx <<" ny=     "<< ny <<endl;
      // i - # LSs:
      TH1F* Yefw0 = new TH1F("Yefw0","", 200, 0., 200.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Yefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  sumijho++;
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HO h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Yefw0 ->Fill(ccc1);
	}
      }}
      cout<<"HO maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny<<"     sumijho=  "<< sumijho <<endl;
      Yefw0 ->SetMarkerStyle(20);Yefw0 ->SetMarkerSize(0.4);Yefw0 ->GetYaxis()->SetLabelSize(0.04);Yefw0 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Yefw0->SetYTitle("     HO \b");Yefw0 ->SetMarkerColor(2);Yefw0 ->SetLineColor(0);
//  Yefw0->SetMinimum(10.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Yefw0 ->Draw("L");
            Yefw0 ->Draw("Error");
	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(2);
      TH1F* Yefw = new TH1F("Yefw","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	double sumsum = 0.;
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Yefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    //	    if(ccc1> 2500.) cout<<"HO :  i=  "<< i <<"      j= "<< j <<"  ccc1 = "<< ccc1 <<"  ccc1*maxbinx/sumijho = "<< ccc1*maxbinx/sumijho <<endl;
	    //	 	  Yefw ->Fill(ccc1/maxbinx);
	    sumsum += ccc1*maxbinx/sumijho;
	    //	    Yefw ->Fill( float(i), ccc1*maxbinx/sumijho);
	  }
	}
	//	cout<<"HO :  i=  "<< i <<"  sumsum = "<< sumsum <<endl;
	Yefw ->Fill( float(i), sumsum);
      }
      Yefw ->SetMarkerStyle(20);Yefw ->SetMarkerSize(0.4);Yefw ->GetYaxis()->SetLabelSize(0.04);Yefw ->SetMarkerColor(2);Yefw ->SetLineColor(0);
      Yefw->SetXTitle("        iLS  \b");  Yefw->SetYTitle("     <A>k \b");
      //Yefw->SetMinimum(0.8);Yefw->SetMaximum(500.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Yefw ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      TH1F* Yefw1 = new TH1F("Yefw1","", 100, 0., 200.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Yefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HO h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Yefw1 ->Fill(ccc1);
	}
      }}
      cout<<"HO maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<endl;
      Yefw1 ->SetMarkerStyle(20);Yefw1 ->SetMarkerSize(0.4);Yefw1 ->GetYaxis()->SetLabelSize(0.04);Yefw1 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Yefw1 ->SetMarkerColor(2);Yefw1 ->SetLineColor(0);
      //  Yefw1->SetMinimum(0.8);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Yefw1 ->Draw("L");
            Yefw1 ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(4);
      // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
      TH2F* Yefz4     = new TH2F("Yefz4","",  22, -11., 11., 18, 0., 18. );
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Yefz1->GetBinContent(i,j);
	  //if(ccc1>0.) cout<<"HO h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1/maxbinx <<endl;
	  //	if(ccc1>0. && ccc1/maxbinx < 2000) {
	  if(ccc1>0.) {
	    int jeta = (j-1)/18;// jeta = 0-21
	    int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	    //	  jeta += 1;// jeta = 1-22
	    //	    if(i==1) cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta-11 <<" jphi= "<< jphi-1 <<"  A= "<< ccc1/maxbinx <<endl;
	    //	  Yefz4 ->Fill(jeta-11,jphi-1,ccc1/maxbinx);
	    Yefz4 ->Fill(jeta-11,jphi-1,ccc1*maxbiny/sumijho);
	  }
	}}
      gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
      Yefz4->SetMarkerStyle(20); Yefz4->SetMarkerSize(0.4); Yefz4->GetZaxis()->SetLabelSize(0.08); Yefz4->SetXTitle("<A>ij         #eta  \b"); Yefz4->SetYTitle("      #phi \b"); Yefz4->SetZTitle("<A>ij  - All \b"); Yefz4->SetMarkerColor(2); Yefz4->SetLineColor(2);  //    Yefz4->SetMaximum(180.0);        Yefz4->SetMinimum(80.0);
      Yefz4->Draw("COLZ");
      
      c1->Update();
      
    //======================================================================

    //========================================================================================== 34 HO
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();
      cout<<"HO Yefk        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* Yefk0 = new TH1F("Yefk0","", 620, 0., 620.);
      TH1F* Yefk1 = new TH1F("Yefk1","", 620, 0., 620.);
      TH1F* Yefk2 = new TH1F("Yefk2","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Yefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    int jeta = (j-1)/18;// jeta = 0-21
	    int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	    //	  jeta += 1;// jeta = 1-22
	    //	    cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	    if(jeta== 7 && jphi==11) Yefk0 ->Fill(i,ccc1);
	    if(jeta==10 && jphi==11) Yefk1 ->Fill(i,ccc1);
	    if(jeta==12 && jphi==11) Yefk2 ->Fill(i,ccc1);
	  }
	}}
      Yefk0 ->SetMarkerStyle(20);Yefk0 ->SetMarkerSize(0.4);Yefk0 ->GetYaxis()->SetLabelSize(0.04);Yefk0 ->SetXTitle("Yefk0 \b");Yefk0 ->SetMarkerColor(2);Yefk0 ->SetLineColor(0);// Yefk0 ->SetMaximum(30.0);// Yefk0 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Yefk0 ->Draw("Error");
      
    //================
      c1->cd(2);
      Yefk1 ->SetMarkerStyle(20);Yefk1 ->SetMarkerSize(0.4);Yefk1 ->GetYaxis()->SetLabelSize(0.04);Yefk1 ->SetXTitle("Yefk1 \b");Yefk1 ->SetMarkerColor(2);Yefk1 ->SetLineColor(0);// Yefk1 ->SetMaximum(30.0);// Yefk1 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Yefk1 ->Draw("Error");
      
    //================
      c1->cd(3);
      Yefk2 ->SetMarkerStyle(20);Yefk2 ->SetMarkerSize(0.4);Yefk2 ->GetYaxis()->SetLabelSize(0.04);Yefk2 ->SetXTitle("Yefk2 \b");Yefk2 ->SetMarkerColor(2);Yefk2 ->SetLineColor(0);// Yefk2 ->SetMaximum(30.0);// Yefk2 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Yefk2 ->Draw("Error");
      
      ////////////////////////////////////////////////////////////////////////////////////
      
      
       c1->Update();



    //========================================================================================== 35 HO: j = 7,8,9,10            11,12,13,14      7
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta0k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta0k *********************************************************************       jeta == 7    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 7) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta0k0 = new TH1F("Gforhojeta0k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta0k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta0k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta0k0 ->SetMarkerStyle(20);Gforhojeta0k0 ->SetMarkerSize(0.4);Gforhojeta0k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta0k0 ->SetXTitle("Gforhojeta0k0 \b");Gforhojeta0k0 ->SetMarkerColor(2);Gforhojeta0k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta0k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta0k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 36 HO: j = 7,8,9,10            11,12,13,14      8
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta1k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta1k *********************************************************************       jeta == 8    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 8) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta1k0 = new TH1F("Gforhojeta1k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta1k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta1k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta1k0 ->SetMarkerStyle(20);Gforhojeta1k0 ->SetMarkerSize(0.4);Gforhojeta1k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta1k0 ->SetXTitle("Gforhojeta1k0 \b");Gforhojeta1k0 ->SetMarkerColor(2);Gforhojeta1k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta1k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta1k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 37  HO: j = 7,8,9,10            11,12,13,14      9
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta2k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta2k *********************************************************************       jeta == 9    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 9) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta2k0 = new TH1F("Gforhojeta2k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta2k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta2k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta2k0 ->SetMarkerStyle(20);Gforhojeta2k0 ->SetMarkerSize(0.4);Gforhojeta2k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta2k0 ->SetXTitle("Gforhojeta2k0 \b");Gforhojeta2k0 ->SetMarkerColor(2);Gforhojeta2k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta2k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta2k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 38  HO: j = 7,8,9,10            11,12,13,14    10
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta3k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta3k *********************************************************************       jeta == 10   "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 10) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta3k0 = new TH1F("Gforhojeta3k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta3k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta3k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta3k0 ->SetMarkerStyle(20);Gforhojeta3k0 ->SetMarkerSize(0.4);Gforhojeta3k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta3k0 ->SetXTitle("Gforhojeta3k0 \b");Gforhojeta3k0 ->SetMarkerColor(2);Gforhojeta3k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta3k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta3k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 39  HO: j = 7,8,9,10            11,12,13,14    11
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta18k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta18k *********************************************************************       jeta == 11    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 11) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta18k0 = new TH1F("Gforhojeta18k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta18k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta18k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta18k0 ->SetMarkerStyle(20);Gforhojeta18k0 ->SetMarkerSize(0.4);Gforhojeta18k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta18k0 ->SetXTitle("Gforhojeta18k0 \b");Gforhojeta18k0 ->SetMarkerColor(2);Gforhojeta18k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta18k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta18k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 40  HO: j = 7,8,9,10            11,12,13,14   12
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta19k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta19k *********************************************************************       jeta == 12    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 12) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta19k0 = new TH1F("Gforhojeta19k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta19k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta19k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta19k0 ->SetMarkerStyle(20);Gforhojeta19k0 ->SetMarkerSize(0.4);Gforhojeta19k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta19k0 ->SetXTitle("Gforhojeta19k0 \b");Gforhojeta19k0 ->SetMarkerColor(2);Gforhojeta19k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta19k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta19k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 41  HO: j = 7,8,9,10            11,12,13,14    13
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta20k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta20k *********************************************************************       jeta == 13    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 13) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta20k0 = new TH1F("Gforhojeta20k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta20k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta20k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta20k0 ->SetMarkerStyle(20);Gforhojeta20k0 ->SetMarkerSize(0.4);Gforhojeta20k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta20k0 ->SetXTitle("Gforhojeta20k0 \b");Gforhojeta20k0 ->SetMarkerColor(2);Gforhojeta20k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta20k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta20k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 42  HO: j = 7,8,9,10            11,12,13,14    14
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Yefz1->GetXaxis()->GetNbins();
      ny = Yefz1->GetYaxis()->GetNbins();

      //    if( nlsoho > 0.)      nhistoho /= nlsoho;
      //    cout<<"HO Gforhojeta21k        nx=     "<< nx <<" ny=     "<< ny <<" nhistoho=     "<< nhistoho <<endl;
      kcount=1;
      cout<<"HO Gforhojeta21k *********************************************************************       jeta == 14    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 14) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforhojeta21k0 = new TH1F("Gforhojeta21k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Yefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HO  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforhojeta21k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HO Gforhojeta21k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforhojeta21k0 ->SetMarkerStyle(20);Gforhojeta21k0 ->SetMarkerSize(0.4);Gforhojeta21k0 ->GetYaxis()->SetLabelSize(0.04);Gforhojeta21k0 ->SetXTitle("Gforhojeta21k0 \b");Gforhojeta21k0 ->SetMarkerColor(2);Gforhojeta21k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforhojeta21k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforhojeta21k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 43    HF - "h_2DsumADCAmplEtaPhiLs3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TH2F *Gefz1KKK= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs3");
      TH2F *Gefz1LLL= (TH2F*)hfile1->Get("h_2DsumADCAmplEtaPhiLs30");
      TH2F* Gefz1 = (TH2F*)Gefz1LLL->Clone("Gefz1");
      Gefz1->Divide(Gefz1KKK,Gefz1LLL, 1, 1, "B");// average A
      Gefz1->Sumw2();


      c1->cd(1);
      maxbinx = 0;
      maxbiny = 0;
      int sumijhf = 0;
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();
      cout<<"HF h_2DsumADCAmplEtaPhiLs0         nx=     "<< nx <<" ny=     "<< ny <<endl;
      // i - # LSs:
      TH1F* Gefw0 = new TH1F("Gefw0","", 250, 0., 500.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Gefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  sumijhf++;
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HF h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Gefw0 ->Fill(ccc1);
	}
      }}
      cout<<"HF maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<"     sumijhf=  "<< sumijhf <<endl;
      Gefw0 ->SetMarkerStyle(20);Gefw0 ->SetMarkerSize(0.4);Gefw0 ->GetYaxis()->SetLabelSize(0.04);Gefw0 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Gefw0->SetYTitle("     HF \b");Gefw0 ->SetMarkerColor(2);Gefw0 ->SetLineColor(0);
      //  Gefw0->SetMinimum(10.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Gefw0 ->Draw("L");
            Gefw0 ->Draw("Error");
	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(2);
      TH1F* Gefw = new TH1F("Gefw","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Gefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  //	  cout<<"HF h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  //	  Gefw ->Fill(ccc1/maxbinx);
	  Gefw ->Fill( float(i), ccc1*maxbinx/sumijhf);
	}
      }}
      Gefw ->SetMarkerStyle(20);Gefw ->SetMarkerSize(0.4);Gefw ->GetYaxis()->SetLabelSize(0.04);Gefw ->SetMarkerColor(2);Gefw ->SetLineColor(0);
      Gefw->SetXTitle("        iLS  \b");  Gefw->SetYTitle("     <A>k \b");
      //Gefw->SetMinimum(0.8);Gefw->SetMaximum(500.);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefw ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(3);
      TH1F* Gefw1 = new TH1F("Gefw1","", 50, 0., 150.);
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
      for (int j=1;j<=ny;j++) {
	double ccc1 =  Gefz1->GetBinContent(i,j);
	if(ccc1>0.) {
	  maxbinx = i; if(i>maxbinx) maxbinx = i;
	  maxbiny = j; if(j>maxbiny) maxbiny = j;
	  //	  cout<<"HF h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1 <<endl;
	  Gefw1 ->Fill(ccc1);
	}
      }}
      cout<<"HF maxbinx=  "<< maxbinx<<"     maxbiny=  "<< maxbiny <<endl;
      Gefw1 ->SetMarkerStyle(20);Gefw1 ->SetMarkerSize(0.4);Gefw1 ->GetYaxis()->SetLabelSize(0.04);Gefw1 ->SetXTitle("<A>ijk = <A> averaged per events in k-th LS \b");Gefw1 ->SetMarkerColor(2);Gefw1 ->SetLineColor(0); 
      // Gefw1->SetMinimum(0.8);
      gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      //      Gefw1 ->Draw("L");
            Gefw1 ->Draw("Error");

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    c1->cd(4);
	    // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
	    TH2F* Gefz4     = new TH2F("Gefz4","",  22, -11., 11., 18, 0., 18. );
	    // i - # LSs:
	    for (int i=1;i<=nx;i++) {
	      // j - etaphi index:
	      for (int j=1;j<=ny;j++) {
		double ccc1 =  Gefz1->GetBinContent(i,j);
		//if(ccc1>0.) cout<<"HF h_2DsumADCAmplEtaPhiLs:  ibin=  "<< i <<"      jbin= "<< j <<"  A= "<< ccc1/maxbinx <<endl;
		//	if(ccc1>0. && ccc1/maxbinx < 2000) {
		if(ccc1>0.) {
		  int jeta = (j-1)/18;// jeta = 0-21
		  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
		  //	  jeta += 1;// jeta = 1-22
		  //	  	  if(i==1) cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta-11 <<" jphi= "<< jphi-1 <<"  A= "<< ccc1/maxbinx <<endl;
		  Gefz4 ->Fill(jeta-11,jphi-1,ccc1*maxbiny/sumijhf);
		  //	  Gefz4 ->Fill(jeta-11,jphi-1,ccc1/maxbinx);
		}
	      }}
	    gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
	    Gefz4->SetMarkerStyle(20); Gefz4->SetMarkerSize(0.4); Gefz4->GetZaxis()->SetLabelSize(0.08); Gefz4->SetXTitle("<A>ij         #eta  \b"); Gefz4->SetYTitle("      #phi \b"); Gefz4->SetZTitle("<A>ij  - All \b"); Gefz4->SetMarkerColor(2); Gefz4->SetLineColor(2);      //      Gefz4->SetMaximum(1.000);  //      Gefz4->SetMinimum(1.0);
	    Gefz4->Draw("COLZ");
	    
	    c1->Update();
	    
    //======================================================================

    //========================================================================================== 44
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();
      cout<<"HF Gefk        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* Gefk0 = new TH1F("Gefk0","", 620, 0., 620.);
      TH1F* Gefk1 = new TH1F("Gefk1","", 620, 0., 620.);
      TH1F* Gefk2 = new TH1F("Gefk2","", 620, 0., 620.);
      // i - # LSs:
      for (int i=1;i<=nx;i++) {
	// j - etaphi index:
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Gefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    int jeta = (j-1)/18;// jeta = 0-21
	    int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	    //	  jeta += 1;// jeta = 1-22
	    //	    cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	    if(jeta== 1 && jphi==11) Gefk0 ->Fill(i,ccc1);
	    if(jeta== 2 && jphi==11) Gefk1 ->Fill(i,ccc1);
	    if(jeta== 3 && jphi==11) Gefk2 ->Fill(i,ccc1);
	  }
	}}
      Gefk0 ->SetMarkerStyle(20);Gefk0 ->SetMarkerSize(0.4);Gefk0 ->GetYaxis()->SetLabelSize(0.04);Gefk0 ->SetXTitle("Gefk0 \b");Gefk0 ->SetMarkerColor(2);Gefk0 ->SetLineColor(0);// Gefk0 ->SetMaximum(30.0);// Gefk0 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefk0 ->Draw("Error");
      
    //================
      c1->cd(2);
      Gefk1 ->SetMarkerStyle(20);Gefk1 ->SetMarkerSize(0.4);Gefk1 ->GetYaxis()->SetLabelSize(0.04);Gefk1 ->SetXTitle("Gefk1 \b");Gefk1 ->SetMarkerColor(2);Gefk1 ->SetLineColor(0);// Gefk1 ->SetMaximum(30.0);// Gefk1 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefk1 ->Draw("Error");
      
    //================
      c1->cd(3);
      Gefk2 ->SetMarkerStyle(20);Gefk2 ->SetMarkerSize(0.4);Gefk2 ->GetYaxis()->SetLabelSize(0.04);Gefk2 ->SetXTitle("Gefk2 \b");Gefk2 ->SetMarkerColor(2);Gefk2 ->SetLineColor(0);// Gefk2 ->SetMaximum(30.0);// Gefk2 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefk2 ->Draw("Error");
      
      ////////////////////////////////////////////////////////////////////////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 45
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
	    //	    cout<<"  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
      c1->cd(1);
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();
      cout<<"HF Gefh        nx=     "<< nx <<" ny=     "<< ny <<endl;
      TH1F* Gefh0 = new TH1F("Gefh0","", 620, 0., 620.);
      TH1F* Gefh1 = new TH1F("Gefh1","", 620, 0., 620.);
      TH1F* Gefh2 = new TH1F("Gefh2","", 620, 0., 620.);
      // j - etaphi index:
      int nhistohf = 0.;int nlsohf = -1.;
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	//	  jeta += 1;// jeta = 1-22
	double sumj=0.; double ssumj=0.; int nj=0;double meanj=0.;double sigmaj=0.;
	// i - # LSs:
	for (int i=1;i<=nx;i++) {double ccc1 =  Gefz1->GetBinContent(i,j);if(ccc1>0.){sumj += ccc1;nj++;nhistohf++;} } meanj=sumj/nj;if(nj>nlsohf) nlsohf=nj;
	// i - # LSs:
	for (int i=1;i<=nx;i++) {double ccc1 =  Gefz1->GetBinContent(i,j);if(ccc1>0.) {ssumj += (ccc1-meanj)*(ccc1-meanj);}} sigmaj = sqrt(ssumj/nj);
	// i - # LSs:
	for (int i=1;i<=nx;i++) {
	  double ccc1 =  Gefz1->GetBinContent(i,j);
	  if(ccc1>0.) {
	    double dif3rmsMIN = meanj-3*sigmaj;if(dif3rmsMIN<0.) dif3rmsMIN = 0.;  double dif3rmsMAX = meanj+3*sigmaj;
	    if(jeta== 1 && jphi==11 && (ccc1<dif3rmsMIN || ccc1>dif3rmsMAX) ) Gefh0 ->Fill(i,ccc1);
	    if(jeta== 2 && jphi==11 && (ccc1<dif3rmsMIN || ccc1>dif3rmsMAX) ) Gefh1 ->Fill(i,ccc1);
	    if(jeta== 3 && jphi==11 && (ccc1<dif3rmsMIN || ccc1>dif3rmsMAX) ) Gefh2 ->Fill(i,ccc1);
	  }}}
      cout<<"HF 45        nhistohf =     "<< nhistohf <<"           nlsohf =     "<< nlsohf <<endl;

      Gefh0 ->SetMarkerStyle(20);Gefh0 ->SetMarkerSize(0.4);Gefh0 ->GetYaxis()->SetLabelSize(0.04);Gefh0 ->SetXTitle("Gefh0 \b");Gefh0 ->SetMarkerColor(2);Gefh0 ->SetLineColor(0);// Gefh0 ->SetMaximum(30.0);// Gefh0 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefh0 ->Draw("Error");
      //================
      c1->cd(2);
      Gefh1 ->SetMarkerStyle(20);Gefh1 ->SetMarkerSize(0.4);Gefh1 ->GetYaxis()->SetLabelSize(0.04);Gefh1 ->SetXTitle("Gefh1 \b");Gefh1 ->SetMarkerColor(2);Gefh1 ->SetLineColor(0);// Gefh1 ->SetMaximum(30.0);// Gefh1 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefh1 ->Draw("Error");
    //================
      c1->cd(3);
      Gefh2 ->SetMarkerStyle(20);Gefh2 ->SetMarkerSize(0.4);Gefh2 ->GetYaxis()->SetLabelSize(0.04);Gefh2 ->SetXTitle("Gefh2 \b");Gefh2 ->SetMarkerColor(2);Gefh2 ->SetLineColor(0);// Gefh2 ->SetMaximum(30.0);// Gefh2 ->SetMinimum(20.0); // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
      Gefh2 ->Draw("Error");

      ////////////////////////////////////////////////////////////////////////////////////
       c1->Update();

    //========================================================================================== 46 HF: j = 0,1,2, 3            18,19,20,21          0
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta0k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta0k *********************************************************************       jeta == 0    "<<endl; 
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 0) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta0k0 = new TH1F("Gforjeta0k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta0k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta0k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta0k0 ->SetMarkerStyle(20);Gforjeta0k0 ->SetMarkerSize(0.4);Gforjeta0k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta0k0 ->SetXTitle("Gforjeta0k0 \b");Gforjeta0k0 ->SetMarkerColor(2);Gforjeta0k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta0k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta0k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 47 HF: j = 0,1,2, 3            18,19,20,21      1
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta1k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta1k *********************************************************************       jeta == 1    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 1) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta1k0 = new TH1F("Gforjeta1k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta1k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta1k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta1k0 ->SetMarkerStyle(20);Gforjeta1k0 ->SetMarkerSize(0.4);Gforjeta1k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta1k0 ->SetXTitle("Gforjeta1k0 \b");Gforjeta1k0 ->SetMarkerColor(2);Gforjeta1k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta1k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta1k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 48   HF: j = 0,1,2, 3            18,19,20,21    2
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta2k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta2k *********************************************************************       jeta == 2    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 2) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta2k0 = new TH1F("Gforjeta2k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta2k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta2k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta2k0 ->SetMarkerStyle(20);Gforjeta2k0 ->SetMarkerSize(0.4);Gforjeta2k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta2k0 ->SetXTitle("Gforjeta2k0 \b");Gforjeta2k0 ->SetMarkerColor(2);Gforjeta2k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta2k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta2k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 49 HF: j = 0,1,2, 3            18,19,20,21   3
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta3k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta3k *********************************************************************       jeta == 3    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 3) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta3k0 = new TH1F("Gforjeta3k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta3k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta3k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta3k0 ->SetMarkerStyle(20);Gforjeta3k0 ->SetMarkerSize(0.4);Gforjeta3k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta3k0 ->SetXTitle("Gforjeta3k0 \b");Gforjeta3k0 ->SetMarkerColor(2);Gforjeta3k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta3k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta3k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 50   HF: j = 0,1,2, 3            18,19,20,21      18
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta18k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta18k *********************************************************************       jeta == 18    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 18) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta18k0 = new TH1F("Gforjeta18k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta18k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta18k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta18k0 ->SetMarkerStyle(20);Gforjeta18k0 ->SetMarkerSize(0.4);Gforjeta18k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta18k0 ->SetXTitle("Gforjeta18k0 \b");Gforjeta18k0 ->SetMarkerColor(2);Gforjeta18k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta18k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta18k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 51   HF: j = 0,1,2, 3            18,19,20,21     19
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta19k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta19k *********************************************************************       jeta == 19    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 19) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta19k0 = new TH1F("Gforjeta19k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta19k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta19k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta19k0 ->SetMarkerStyle(20);Gforjeta19k0 ->SetMarkerSize(0.4);Gforjeta19k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta19k0 ->SetXTitle("Gforjeta19k0 \b");Gforjeta19k0 ->SetMarkerColor(2);Gforjeta19k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta19k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta19k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 52  HF: j = 0,1,2, 3            18,19,20,21   20
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta20k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta20k *********************************************************************       jeta == 20    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 20) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta20k0 = new TH1F("Gforjeta20k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta20k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta20k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta20k0 ->SetMarkerStyle(20);Gforjeta20k0 ->SetMarkerSize(0.4);Gforjeta20k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta20k0 ->SetXTitle("Gforjeta20k0 \b");Gforjeta20k0 ->SetMarkerColor(2);Gforjeta20k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta20k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta20k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
    //========================================================================================== 53   HF: j = 0,1,2, 3            18,19,20,21    21
    //======================================================================
    //======================================================================
    //======================================================================
      c1->Clear();
      c1->Divide(3,6);
      
      nx = Gefz1->GetXaxis()->GetNbins();
      ny = Gefz1->GetYaxis()->GetNbins();

      if( nlsohf > 0.)      nhistohf /= nlsohf;
      cout<<"HF Gforjeta21k        nx=     "<< nx <<" ny=     "<< ny <<" nhistohf=     "<< nhistohf <<endl;
      kcount=1;
      cout<<"HF Gforjeta21k *********************************************************************       jeta == 21    "<<endl;
      // j - etaphi index:
      for (int j=1;j<=ny;j++) {
	int jeta = (j-1)/18;// jeta = 0-21
	if(jeta == 21) {
	  int jphi = (j-1)-18*jeta+1;// jphi=1-18 
	  //	  jeta += 1;// jeta = 1-22
	  TH1F* Gforjeta21k0 = new TH1F("Gforjeta21k0","", 620, 0., 620.);
	  // i - # LSs:
	  for (int i=1;i<=nx;i++) {
	    double ccc1 =  Gefz1->GetBinContent(i,j);
	    if(ccc1>0.) {
	      //	      if(i==1)cout<<"HF  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
	      Gforjeta21k0 ->Fill(i,ccc1);
	    }}
	  c1->cd(kcount);
	  //	  cout<<"HF Gforjeta21k        kcount=     "<< kcount <<"   jphi   =     "<<jphi  <<endl;
	  Gforjeta21k0 ->SetMarkerStyle(20);Gforjeta21k0 ->SetMarkerSize(0.4);Gforjeta21k0 ->GetYaxis()->SetLabelSize(0.04);Gforjeta21k0 ->SetXTitle("Gforjeta21k0 \b");Gforjeta21k0 ->SetMarkerColor(2);Gforjeta21k0 ->SetLineColor(0);
	  // gPad->SetLogy();gPad->SetGridy();gPad->SetGridx();     
	  Gforjeta21k0->Draw("Error");
	  kcount++;
	  //	c1->Update();
	  //		delete Gforjeta21k0;
	  if(kcount>18) break;
	}
      }
      
      /////////////////
       c1->Update();
      ////////////////////////////////////////////////////////////////////////////////////
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




      
