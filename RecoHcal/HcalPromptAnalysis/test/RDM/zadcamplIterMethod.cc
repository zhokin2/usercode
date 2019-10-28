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
	TFile *hfile1= new TFile("LED329317.root", "READ");




	//	TFile *hfile2= new TFile("LED_284902.root", "READ");
	//	TFile *hfile2= new TFile("LED_284499.root", "READ");
	//	TFile *hfile2= new TFile("LED_284352.root", "READ");

	//	TFile *hfile2= new TFile("LED_286590.root", "READ");



	//    getchar();
	//
          TPostScript psfile ("zadcamplIterMethod.ps", 111);


//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);
	  
	  
	  
	  const int nsub = 4;  const int ndepth = 7; const int neta = 82;  const int nphi = 72;
	  int njeta = neta; int njphi = nphi;int njdepth = ndepth;
	  double alexhe[ndepth][njeta][njphi];  
	  double variance[ndepth][njeta][njphi];  

	  const int jposbeg= 57;const int jposend= 71; 

	  const int jnegbeg= 12;const int jnegend= 26; 
	  /*
depth=5                    all
i=1-82 in initial histo
j=i-1 in massives

j= 13   23 (11)           12    25 (!!!)
j-41 in histo
  -28  -18 (11)          -29    -16

j= 59   69 (11)           57    70 (!!!)
j-41 in histo
   18   28 (11)           16    29
	   */

	  //========================================================================================== 1
	  //================
	  //======================================================================
	  c1->Clear();
          c1->Divide(2,4);
	  //  c1->Divide(1,1);
      
      c1->cd(1);
      TH2F *maprphinorm1HE1= (TH2F*)hfile1->Get("h_maprphinorm_HE1");maprphinorm1HE1->Sumw2();
      TH2F *maprphinorm0HE1= (TH2F*)hfile1->Get("h_maprphinorm0_HE1");maprphinorm0HE1->Sumw2();
      TH2F* maprphinormHE1 = (TH2F*)maprphinorm1HE1->Clone("maprphinormHE1");
      maprphinormHE1->Divide(maprphinorm1HE1,maprphinorm0HE1, 1, 1, "B");maprphinormHE1->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      //            gPad->SetLogz();
      maprphinormHE1->SetMarkerStyle(20);
      maprphinormHE1->SetMarkerSize(0.8);
      maprphinormHE1->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE1->SetXTitle("maprphinormHE1 \b");
      maprphinormHE1->SetMarkerColor(2);
      maprphinormHE1->SetLineColor(2);
      //    maprphinormHE1->Draw("");
          maprphinormHE1->Draw("COLZ");

      //    null;

      c1->cd(2);
      TH2F *maprphinorm1HE2= (TH2F*)hfile1->Get("h_maprphinorm_HE2");maprphinorm1HE2->Sumw2();
      TH2F *maprphinorm0HE2= (TH2F*)hfile1->Get("h_maprphinorm0_HE2");maprphinorm0HE2->Sumw2();
      TH2F* maprphinormHE2 = (TH2F*)maprphinorm1HE2->Clone("maprphinormHE2");
      maprphinormHE2->Divide(maprphinorm1HE2,maprphinorm0HE2, 1, 1, "B");maprphinormHE2->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE2->SetMarkerStyle(20);
      maprphinormHE2->SetMarkerSize(0.8);
      maprphinormHE2->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE2->SetXTitle("maprphinormHE2 \b");
      maprphinormHE2->SetMarkerColor(2);
      maprphinormHE2->SetLineColor(2);
          maprphinormHE2->Draw("COLZ");
      
      c1->cd(3);
      TH2F *maprphinorm1HE3= (TH2F*)hfile1->Get("h_maprphinorm_HE3");maprphinorm1HE3->Sumw2();
      TH2F *maprphinorm0HE3= (TH2F*)hfile1->Get("h_maprphinorm0_HE3");maprphinorm0HE3->Sumw2();
      TH2F* maprphinormHE3 = (TH2F*)maprphinorm1HE3->Clone("maprphinormHE3");
      maprphinormHE3->Divide(maprphinorm1HE3,maprphinorm0HE3, 1, 1, "B");maprphinormHE3->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE3->SetMarkerStyle(20);
      maprphinormHE3->SetMarkerSize(0.8);
      maprphinormHE3->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE3->SetXTitle("maprphinormHE3 \b");
      maprphinormHE3->SetMarkerColor(2);
      maprphinormHE3->SetLineColor(2);
          maprphinormHE3->Draw("COLZ");
      
      c1->cd(4);
      TH2F *maprphinorm1HE4= (TH2F*)hfile1->Get("h_maprphinorm_HE4");maprphinorm1HE4->Sumw2();
      TH2F *maprphinorm0HE4= (TH2F*)hfile1->Get("h_maprphinorm0_HE4");maprphinorm0HE4->Sumw2();
      TH2F* maprphinormHE4 = (TH2F*)maprphinorm1HE4->Clone("maprphinormHE4");
      maprphinormHE4->Divide(maprphinorm1HE4,maprphinorm0HE4, 1, 1, "B");maprphinormHE4->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE4->SetMarkerStyle(20);
      maprphinormHE4->SetMarkerSize(0.8);
      maprphinormHE4->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE4->SetXTitle("maprphinormHE4 \b");
      maprphinormHE4->SetMarkerColor(2);
      maprphinormHE4->SetLineColor(2);
          maprphinormHE4->Draw("COLZ");
      
      c1->cd(5);
      TH2F *maprphinorm1HE5= (TH2F*)hfile1->Get("h_maprphinorm_HE5");maprphinorm1HE5->Sumw2();
      TH2F *maprphinorm0HE5= (TH2F*)hfile1->Get("h_maprphinorm0_HE5");maprphinorm0HE5->Sumw2();
      TH2F* maprphinormHE5 = (TH2F*)maprphinorm1HE5->Clone("maprphinormHE5");
      maprphinormHE5->Divide(maprphinorm1HE5,maprphinorm0HE5, 1, 1, "B");maprphinormHE5->Sumw2();
//    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE5->SetMarkerStyle(20);
      maprphinormHE5->SetMarkerSize(0.8);
      maprphinormHE5->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE5->SetXTitle("maprphinormHE5 \b");
      maprphinormHE5->SetMarkerColor(2);
      maprphinormHE5->SetLineColor(2);
          maprphinormHE5->Draw("COLZ");
      
      c1->cd(6);
      TH2F *maprphinorm1HE6= (TH2F*)hfile1->Get("h_maprphinorm_HE6");maprphinorm1HE6->Sumw2();
      TH2F *maprphinorm0HE6= (TH2F*)hfile1->Get("h_maprphinorm0_HE6");maprphinorm0HE6->Sumw2();
      TH2F* maprphinormHE6 = (TH2F*)maprphinorm1HE6->Clone("maprphinormHE6");
      maprphinormHE6->Divide(maprphinorm1HE6,maprphinorm0HE6, 1, 1, "B");maprphinormHE6->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE6->SetMarkerStyle(20);
      maprphinormHE6->SetMarkerSize(0.8);
      maprphinormHE6->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE6->SetXTitle("maprphinormHE6 \b");
      maprphinormHE6->SetMarkerColor(2);
      maprphinormHE6->SetLineColor(2);
          maprphinormHE6->Draw("COLZ");
      
      c1->cd(7);
      TH2F *maprphinorm1HE7= (TH2F*)hfile1->Get("h_maprphinorm_HE7");maprphinorm1HE7->Sumw2();
      TH2F *maprphinorm0HE7= (TH2F*)hfile1->Get("h_maprphinorm0_HE7");maprphinorm0HE7->Sumw2();
      TH2F* maprphinormHE7 = (TH2F*)maprphinorm1HE7->Clone("maprphinormHE7");
      maprphinormHE7->Divide(maprphinorm1HE7,maprphinorm0HE7, 1, 1, "B");maprphinormHE7->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      maprphinormHE7->SetMarkerStyle(20);
      maprphinormHE7->SetMarkerSize(0.8);
      maprphinormHE7->GetYaxis()->SetLabelSize(0.04);
      maprphinormHE7->SetXTitle("maprphinormHE7 \b");
      maprphinormHE7->SetMarkerColor(2);
      maprphinormHE7->SetLineColor(2);
          maprphinormHE7->Draw("COLZ");
      
      c1->Update();
      
    //========================================================================================== 2
    //================
    //====================================================================== put R into massive alexhe
      c1->Clear();
      c1->Divide(1,3);
      
      cout<<"222       njeta=     "<< njeta <<"   njphi   =     "<<njphi  <<"   ndepth   =     "<<ndepth  <<endl;
      //       ny = maprphinormHE1->GetYaxis()->GetNbins();// # etaphi indexe
      //       nx = Gefz1->GetXaxis()->GetNbins();// # LS
      //       	   	   cout<<"222       ny=     "<< ny <<"   nx   =     "<<nx  <<endl;
      for(int jeta=0;jeta<njeta;jeta++){
	for(int jphi=0;jphi<njphi;jphi++){
	  //	   cout<<"222   jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	  alexhe[0][jeta][jphi] = maprphinormHE1->GetBinContent(jeta+1,jphi+1);
	  alexhe[1][jeta][jphi] = maprphinormHE2->GetBinContent(jeta+1,jphi+1);
	  alexhe[2][jeta][jphi] = maprphinormHE3->GetBinContent(jeta+1,jphi+1);
	  alexhe[3][jeta][jphi] = maprphinormHE4->GetBinContent(jeta+1,jphi+1);
	  alexhe[4][jeta][jphi] = maprphinormHE5->GetBinContent(jeta+1,jphi+1);
	  alexhe[5][jeta][jphi] = maprphinormHE6->GetBinContent(jeta+1,jphi+1);
	  alexhe[6][jeta][jphi] = maprphinormHE7->GetBinContent(jeta+1,jphi+1);
	  //	  	   if( alexhe[4][jeta][jphi] != 0. ) cout<<"222  depth=5 alexhe[4][jeta][jphi] != 0.     jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"  alexhe[4][jeta][jphi]   =     "<<alexhe[0][jeta][jphi]  <<endl;
	}	 
      }
      
      //------------------------  2D-eta/phi-plot: R, averaged over depthes


      // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
      //          TH2F* Gefz42D      = new TH2F("Gefz42D","",   23, -11.5, 11.5, 18, 0., 18. );
      //          TH2F* Gefz42D0     = new TH2F("Gefz42D0","",  23, -11.5, 11.5, 18, 0., 18. );
      TH2F* Gefz42D      = new TH2F("Gefz42D","",   neta, -41., 41., nphi, 0., 72. );
      TH2F* Gefz42D0     = new TH2F("Gefz42D0","",  neta, -41., 41., nphi, 0., 72. );
      //     TH2F* Gefz42D      = new TH2F("Gefz42D","",   22, -11., 11., 18, 0., 18. );
      //     TH2F* Gefz42D0     = new TH2F("Gefz42D0","",  22, -11., 11., 18, 0., 18. );
      //      TH2F* Gefz42D      = new TH2F("Gefz42D","",   24, -12., 12., 18, 0., 18. );
      //     TH2F* Gefz42D0     = new TH2F("Gefz42D0","",  24, -12., 12., 18, 0., 18. );
      TH2F* Gefz42DF = (TH2F*)Gefz42D0->Clone("Gefz42DF");
      for (int i=0;i<ndepth;i++) {
	for (int jeta=0;jeta<neta;jeta++) {
	  for (int jphi=0;jphi<nphi;jphi++) {
	    double ccc1 = alexhe[i][jeta][jphi];
	    //	     int neweta = jeta-11-0.5; if(jeta>=11) neweta = jeta-11+1.5; 
	    //	     if(ccc1!=0.) {Gefz42D ->Fill(neweta,jphi,ccc1); Gefz42D0 ->Fill(neweta,jphi,1.); }
	    
	    int k2plot = jeta-41;int kkk = k2plot; //if(k2plot >0 ) kkk=k2plot+1; //-41 +41 !=0
	    if(ccc1!=0.) {Gefz42D ->Fill(kkk,jphi,ccc1); Gefz42D0 ->Fill(kkk,jphi,1.); }
	  }}}
      c1->cd(1);
      Gefz42D->Draw("COLZ");
      c1->cd(2);
      Gefz42D0->Draw("COLZ");
      c1->cd(3);
      Gefz42DF->Divide(Gefz42D,Gefz42D0, 1, 1, "B");// average A
      //    Gefz1->Sumw2();
      gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
      Gefz42DF->SetMarkerStyle(20); Gefz42DF->SetMarkerSize(0.4); Gefz42DF->GetZaxis()->SetLabelSize(0.08); Gefz42DF->SetXTitle("<R>_depth       #eta  \b"); Gefz42DF->SetYTitle("      #phi \b"); Gefz42DF->SetZTitle("<R>_depth \b"); Gefz42DF->SetMarkerColor(2); Gefz42DF->SetLineColor(0);      //      Gefz42DF->SetMaximum(1.000);  //      Gefz42DF->SetMinimum(1.0);
      Gefz42DF->Draw("COLZ");
      
      
      
      c1->Update();
    //================
       //======================================================================
       //========================================================================================== 3   
       //======================================================================
       //======================================================================
       //======================================================================
       //====================================================================== 1D plot: R vs phi , averaged over depthes & eta
       c1->Clear();
       /////////////////
       c1->Divide(1,1);
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       c1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;

       TH1F* Gefz41D      = new TH1F("Gefz41D","", nphi, 0., 72. );
       TH1F* Gefz41D0     = new TH1F("Gefz41D0","",nphi, 0., 72. );
       TH1F* Gefz41DF = (TH1F*)Gefz41D0->Clone("Gefz41DF");

       for (int jphi=0;jphi<nphi;jphi++) {
	 for (int jeta=0;jeta<neta;jeta++) {
	   for (int i=0;i<ndepth;i++) {
	     double ccc1 = alexhe[i][jeta][jphi];
	     if(ccc1!=0.) {Gefz41D ->Fill(jphi,ccc1); Gefz41D0 ->Fill(jphi,1.); }
	   }}}
       //     Gefz41D->Sumw2();Gefz41D0->Sumw2();

       Gefz41DF->Divide(Gefz41D,Gefz41D0, 1, 1, "B");// R averaged over depthes & eta
            Gefz41DF->Sumw2();Gefz41D->Sumw2();Gefz41D0->Sumw2();
       //    for (int jphi=1;jphi<73;jphi++) {Gefz41DF->SetBinError(jphi,0.01);}
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Gefz41DF->SetMarkerStyle(20); Gefz41DF->SetMarkerSize(1.4); Gefz41DF->GetZaxis()->SetLabelSize(0.08); Gefz41DF->SetXTitle("#phi  \b"); Gefz41DF->SetYTitle("  <R> \b"); Gefz41DF->SetZTitle("<R>_PHI  - AllDepthes \b"); Gefz41DF->SetMarkerColor(4); Gefz41DF->SetLineColor(4);  Gefz41DF->SetMinimum(0.8);     //      Gefz41DF->SetMaximum(1.000);       
       Gefz41DF->Draw("Error");
       
       c1->Update();
       
    //================
       //========================================================================================== 4   
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=1
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection1=1;
       TH1F* h2CeffHEpositivedirection1 = new TH1F("h2CeffHEpositivedirection1","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=1
	   for (int i=0;i<1;i++) {
	     
	     TH1F *HEpositivedirection1 = (TH1F*)h2CeffHEpositivedirection1->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection1 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection1->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"444        kcountHEpositivedirection1   =     "<<kcountHEpositivedirection1  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection1);
	       HEpositivedirection1 ->SetMarkerStyle(20);HEpositivedirection1 ->SetMarkerSize(0.4);HEpositivedirection1 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection1 ->SetXTitle("HEpositivedirection1 \b");HEpositivedirection1 ->SetMarkerColor(2);HEpositivedirection1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection1 == 1) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 18; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 2) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 19; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 3) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 20; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 4) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 21; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 5) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 22; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 6) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 23; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 7) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 24; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 8) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 25; depth = 1 \b");
	       if(kcountHEpositivedirection1 == 9) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 26; depth = 1 \b");
	       if(kcountHEpositivedirection1 ==10) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 27; depth = 1 \b");
	       if(kcountHEpositivedirection1 ==11) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 28; depth = 1 \b");
	       if(kcountHEpositivedirection1 ==12) HEpositivedirection1 ->SetXTitle("R for HE+ jeta = 29; depth = 1 \b");
	       HEpositivedirection1->Draw("Error");
	       kcountHEpositivedirection1++;
	       if(kcountHEpositivedirection1>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 5  
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=2
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection2=1;
       TH1F* h2CeffHEpositivedirection2 = new TH1F("h2CeffHEpositivedirection2","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=2
	   for (int i=1;i<2;i++) {
	     
	     TH1F *HEpositivedirection2 = (TH1F*)h2CeffHEpositivedirection2->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection2 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection2->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"555        kcountHEpositivedirection2   =     "<<kcountHEpositivedirection2  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection2);
	       HEpositivedirection2 ->SetMarkerStyle(20);HEpositivedirection2 ->SetMarkerSize(0.4);HEpositivedirection2 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection2 ->SetXTitle("HEpositivedirection2 \b");HEpositivedirection2 ->SetMarkerColor(2);HEpositivedirection2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection2 == 1) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 17; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 2) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 18; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 3) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 19; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 4) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 20; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 5) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 21; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 6) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 22; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 7) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 23; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 8) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 24; depth = 2 \b");
	       if(kcountHEpositivedirection2 == 9) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 25; depth = 2 \b");
	       if(kcountHEpositivedirection2 ==10) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 26; depth = 2 \b");
	       if(kcountHEpositivedirection2 ==11) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 27; depth = 2 \b");
	       if(kcountHEpositivedirection2 ==12) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 28; depth = 2 \b");
	       if(kcountHEpositivedirection2 ==13) HEpositivedirection2 ->SetXTitle("R for HE+ jeta = 29; depth = 2 \b");
	       HEpositivedirection2->Draw("Error");
	       kcountHEpositivedirection2++;
	       if(kcountHEpositivedirection2>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 6   
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=3
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection3=1;
       TH1F* h2CeffHEpositivedirection3 = new TH1F("h2CeffHEpositivedirection3","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=3
	   for (int i=2;i<3;i++) {
	     
	     TH1F *HEpositivedirection3 = (TH1F*)h2CeffHEpositivedirection3->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection3 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection3->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"666        kcountHEpositivedirection3   =     "<<kcountHEpositivedirection3  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection3);
	       HEpositivedirection3 ->SetMarkerStyle(20);HEpositivedirection3 ->SetMarkerSize(0.4);HEpositivedirection3 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection3 ->SetXTitle("HEpositivedirection3 \b");HEpositivedirection3 ->SetMarkerColor(2);HEpositivedirection3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection3 == 1) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 17; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 2) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 18; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 3) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 19; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 4) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 20; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 5) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 21; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 6) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 22; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 7) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 23; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 8) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 24; depth = 3 \b");
	       if(kcountHEpositivedirection3 == 9) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 25; depth = 3 \b");
	       if(kcountHEpositivedirection3 ==10) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 26; depth = 3 \b");
	       if(kcountHEpositivedirection3 ==11) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 27; depth = 3 \b");
	       if(kcountHEpositivedirection3 ==12) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 28; depth = 3 \b");
	       if(kcountHEpositivedirection3 ==13) HEpositivedirection3 ->SetXTitle("R for HE+ jeta = 29; depth = 3 \b");
	       HEpositivedirection3->Draw("Error");
	       kcountHEpositivedirection3++;
	       if(kcountHEpositivedirection3>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 7   
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=4
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection4=1;
       TH1F* h2CeffHEpositivedirection4 = new TH1F("h2CeffHEpositivedirection4","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=4
	   for (int i=3;i<4;i++) {
	     
	     TH1F *HEpositivedirection4 = (TH1F*)h2CeffHEpositivedirection4->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection4 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection4->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"777        kcountHEpositivedirection4   =     "<<kcountHEpositivedirection4  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection4);
	       HEpositivedirection4 ->SetMarkerStyle(20);HEpositivedirection4 ->SetMarkerSize(0.4);HEpositivedirection4 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection4 ->SetXTitle("HEpositivedirection4 \b");HEpositivedirection4 ->SetMarkerColor(2);HEpositivedirection4 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection4 == 1) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 16; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 2) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 18; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 3) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 19; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 4) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 20; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 5) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 21; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 6) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 22; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 7) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 23; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 8) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 24; depth = 4 \b");
	       if(kcountHEpositivedirection4 == 9) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 25; depth = 4 \b");
	       if(kcountHEpositivedirection4 ==10) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 26; depth = 4 \b");
	       if(kcountHEpositivedirection4 ==11) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 27; depth = 4 \b");
	       if(kcountHEpositivedirection4 ==12) HEpositivedirection4 ->SetXTitle("R for HE+ jeta = 28; depth = 4 \b");
	       HEpositivedirection4->Draw("Error");
	       kcountHEpositivedirection4++;
	       if(kcountHEpositivedirection4>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 8   
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=5
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection5=1;
       TH1F* h2CeffHEpositivedirection5 = new TH1F("h2CeffHEpositivedirection5","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=5
	   for (int i=4;i<5;i++) {
	     
	     TH1F *HEpositivedirection5 = (TH1F*)h2CeffHEpositivedirection5->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       //	       cout<<"888  initial      kcountHEpositivedirection5   =     "<<kcountHEpositivedirection5  <<"   jeta-41=     "<< jeta-41 <<"   jphi=     "<< jphi <<"   alexhe[i][jeta][jphi]=     "<< alexhe[i][jeta][jphi] <<"  depth=     "<< i <<endl;
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection5 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection5->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"888        kcountHEpositivedirection5   =     "<<kcountHEpositivedirection5  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection5);
	       HEpositivedirection5 ->SetMarkerStyle(20);HEpositivedirection5 ->SetMarkerSize(0.4);HEpositivedirection5 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection5 ->SetXTitle("HEpositivedirection5 \b");HEpositivedirection5 ->SetMarkerColor(2);HEpositivedirection5 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection5 == 1) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 18; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 2) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 19; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 3) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 20; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 4) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 21; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 5) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 22; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 6) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 23; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 7) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 24; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 8) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 25; depth = 5 \b");
	       if(kcountHEpositivedirection5 == 9) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 26; depth = 5 \b");
	       if(kcountHEpositivedirection5 ==10) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 27; depth = 5 \b");
	       if(kcountHEpositivedirection5 ==11) HEpositivedirection5 ->SetXTitle("R for HE+ jeta = 28; depth = 5 \b");
	       HEpositivedirection5->Draw("Error");
	       kcountHEpositivedirection5++;
	       if(kcountHEpositivedirection5>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 9   
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=6
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection6=1;
       TH1F* h2CeffHEpositivedirection6 = new TH1F("h2CeffHEpositivedirection6","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=6
	   for (int i=5;i<6;i++) {
	     
	     TH1F *HEpositivedirection6 = (TH1F*)h2CeffHEpositivedirection6->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection6 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection6->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"999        kcountHEpositivedirection6   =     "<<kcountHEpositivedirection6  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection6);
	       HEpositivedirection6 ->SetMarkerStyle(20);HEpositivedirection6 ->SetMarkerSize(0.4);HEpositivedirection6 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection6 ->SetXTitle("HEpositivedirection6 \b");HEpositivedirection6 ->SetMarkerColor(2);HEpositivedirection6 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection6 == 1) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 19; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 2) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 20; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 3) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 21; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 4) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 22; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 5) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 23; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 6) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 24; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 7) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 25; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 8) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 26; depth = 6 \b");
	       if(kcountHEpositivedirection6 == 9) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 27; depth = 6 \b");
	       if(kcountHEpositivedirection6 ==10) HEpositivedirection6 ->SetXTitle("R for HE+ jeta = 28; depth = 6 \b");
	       HEpositivedirection6->Draw("Error");
	       kcountHEpositivedirection6++;
	       if(kcountHEpositivedirection6>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 10  
       //======================================================================
       //======================================================================1D plot: R vs phi , different eta,  depth=7
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirection7=1;
       TH1F* h2CeffHEpositivedirection7 = new TH1F("h2CeffHEpositivedirection7","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirection:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=7
	   for (int i=6;i<7;i++) {
	     
	     TH1F *HEpositivedirection7 = (TH1F*)h2CeffHEpositivedirection7->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = alexhe[i][jeta][jphi];
	       if(ccc1!=0.) {HEpositivedirection7 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirection7->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1010       kcountHEpositivedirection7   =     "<<kcountHEpositivedirection7  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirection7);
	       HEpositivedirection7 ->SetMarkerStyle(20);HEpositivedirection7 ->SetMarkerSize(0.4);HEpositivedirection7 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirection7 ->SetXTitle("HEpositivedirection7 \b");HEpositivedirection7 ->SetMarkerColor(2);HEpositivedirection7 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirection7 == 1) HEpositivedirection7 ->SetXTitle("R for HE+ jeta = 26; depth = 7 \b");
	       if(kcountHEpositivedirection7 == 2) HEpositivedirection7 ->SetXTitle("R for HE+ jeta = 27; depth = 7 \b");
	       if(kcountHEpositivedirection7 == 3) HEpositivedirection7 ->SetXTitle("R for HE+ jeta = 28; depth = 7 \b");
	       HEpositivedirection7->Draw("Error");
	       kcountHEpositivedirection7++;
	       if(kcountHEpositivedirection7>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //================
       //================
       //================
       //================
       //================
       //========================================================================================== 11
       //================
       //======================================================================
      c1->Clear();
          c1->Divide(2,4);
	  //  c1->Divide(1,1);
      
      c1->cd(1);
      TH2F *mapdphinorm1HE1= (TH2F*)hfile1->Get("h_maprphinorm2_HE1");mapdphinorm1HE1->Sumw2();
      TH2F *mapdphinorm0HE1= (TH2F*)hfile1->Get("h_maprphinorm0_HE1");mapdphinorm0HE1->Sumw2();
      TH2F* mapdphinormHE1 = (TH2F*)mapdphinorm1HE1->Clone("mapdphinormHE1");
      mapdphinormHE1->Divide(mapdphinorm1HE1,mapdphinorm0HE1, 1, 1, "B");mapdphinormHE1->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
            gPad->SetLogz();
      mapdphinormHE1->SetMarkerStyle(20);
      mapdphinormHE1->SetMarkerSize(0.8);
      mapdphinormHE1->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE1->SetXTitle("mapdphinormHE1 \b");
      mapdphinormHE1->SetMarkerColor(2);
      mapdphinormHE1->SetLineColor(2);
      //    mapdphinormHE1->Draw("");
          mapdphinormHE1->Draw("COLZ");

      //    null;

      c1->cd(2);
      TH2F *mapdphinorm1HE2= (TH2F*)hfile1->Get("h_maprphinorm2_HE2");mapdphinorm1HE2->Sumw2();
      TH2F *mapdphinorm0HE2= (TH2F*)hfile1->Get("h_maprphinorm0_HE2");mapdphinorm0HE2->Sumw2();
      TH2F* mapdphinormHE2 = (TH2F*)mapdphinorm1HE2->Clone("mapdphinormHE2");
      mapdphinormHE2->Divide(mapdphinorm1HE2,mapdphinorm0HE2, 1, 1, "B");mapdphinormHE2->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE2->SetMarkerStyle(20);
      mapdphinormHE2->SetMarkerSize(0.8);
      mapdphinormHE2->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE2->SetXTitle("mapdphinormHE2 \b");
      mapdphinormHE2->SetMarkerColor(2);
      mapdphinormHE2->SetLineColor(2);
          mapdphinormHE2->Draw("COLZ");
      
      c1->cd(3);
      TH2F *mapdphinorm1HE3= (TH2F*)hfile1->Get("h_maprphinorm2_HE3");mapdphinorm1HE3->Sumw2();
      TH2F *mapdphinorm0HE3= (TH2F*)hfile1->Get("h_maprphinorm0_HE3");mapdphinorm0HE3->Sumw2();
      TH2F* mapdphinormHE3 = (TH2F*)mapdphinorm1HE3->Clone("mapdphinormHE3");
      mapdphinormHE3->Divide(mapdphinorm1HE3,mapdphinorm0HE3, 1, 1, "B");mapdphinormHE3->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE3->SetMarkerStyle(20);
      mapdphinormHE3->SetMarkerSize(0.8);
      mapdphinormHE3->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE3->SetXTitle("mapdphinormHE3 \b");
      mapdphinormHE3->SetMarkerColor(2);
      mapdphinormHE3->SetLineColor(2);
          mapdphinormHE3->Draw("COLZ");
      
      c1->cd(4);
      TH2F *mapdphinorm1HE4= (TH2F*)hfile1->Get("h_maprphinorm2_HE4");mapdphinorm1HE4->Sumw2();
      TH2F *mapdphinorm0HE4= (TH2F*)hfile1->Get("h_maprphinorm0_HE4");mapdphinorm0HE4->Sumw2();
      TH2F* mapdphinormHE4 = (TH2F*)mapdphinorm1HE4->Clone("mapdphinormHE4");
      mapdphinormHE4->Divide(mapdphinorm1HE4,mapdphinorm0HE4, 1, 1, "B");mapdphinormHE4->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE4->SetMarkerStyle(20);
      mapdphinormHE4->SetMarkerSize(0.8);
      mapdphinormHE4->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE4->SetXTitle("mapdphinormHE4 \b");
      mapdphinormHE4->SetMarkerColor(2);
      mapdphinormHE4->SetLineColor(2);
          mapdphinormHE4->Draw("COLZ");
      
      c1->cd(5);
      TH2F *mapdphinorm1HE5= (TH2F*)hfile1->Get("h_maprphinorm2_HE5");mapdphinorm1HE5->Sumw2();
      TH2F *mapdphinorm0HE5= (TH2F*)hfile1->Get("h_maprphinorm0_HE5");mapdphinorm0HE5->Sumw2();
      TH2F* mapdphinormHE5 = (TH2F*)mapdphinorm1HE5->Clone("mapdphinormHE5");
      mapdphinormHE5->Divide(mapdphinorm1HE5,mapdphinorm0HE5, 1, 1, "B");mapdphinormHE5->Sumw2();
//    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE5->SetMarkerStyle(20);
      mapdphinormHE5->SetMarkerSize(0.8);
      mapdphinormHE5->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE5->SetXTitle("mapdphinormHE5 \b");
      mapdphinormHE5->SetMarkerColor(2);
      mapdphinormHE5->SetLineColor(2);
          mapdphinormHE5->Draw("COLZ");
      
      c1->cd(6);
      TH2F *mapdphinorm1HE6= (TH2F*)hfile1->Get("h_maprphinorm2_HE6");mapdphinorm1HE6->Sumw2();
      TH2F *mapdphinorm0HE6= (TH2F*)hfile1->Get("h_maprphinorm0_HE6");mapdphinorm0HE6->Sumw2();
      TH2F* mapdphinormHE6 = (TH2F*)mapdphinorm1HE6->Clone("mapdphinormHE6");
      mapdphinormHE6->Divide(mapdphinorm1HE6,mapdphinorm0HE6, 1, 1, "B");mapdphinormHE6->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE6->SetMarkerStyle(20);
      mapdphinormHE6->SetMarkerSize(0.8);
      mapdphinormHE6->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE6->SetXTitle("mapdphinormHE6 \b");
      mapdphinormHE6->SetMarkerColor(2);
      mapdphinormHE6->SetLineColor(2);
          mapdphinormHE6->Draw("COLZ");
      
      c1->cd(7);
      TH2F *mapdphinorm1HE7= (TH2F*)hfile1->Get("h_maprphinorm2_HE7");mapdphinorm1HE7->Sumw2();
      TH2F *mapdphinorm0HE7= (TH2F*)hfile1->Get("h_maprphinorm0_HE7");mapdphinorm0HE7->Sumw2();
      TH2F* mapdphinormHE7 = (TH2F*)mapdphinorm1HE7->Clone("mapdphinormHE7");
      mapdphinormHE7->Divide(mapdphinorm1HE7,mapdphinorm0HE7, 1, 1, "B");mapdphinormHE7->Sumw2();
      //    gPad->SetLogy();
      // gPad->SetLogx();
      mapdphinormHE7->SetMarkerStyle(20);
      mapdphinormHE7->SetMarkerSize(0.8);
      mapdphinormHE7->GetYaxis()->SetLabelSize(0.04);
      mapdphinormHE7->SetXTitle("mapdphinormHE7 \b");
      mapdphinormHE7->SetMarkerColor(2);
      mapdphinormHE7->SetLineColor(2);
          mapdphinormHE7->Draw("COLZ");
      
      c1->Update();
      
    //========================================================================================== 12
    //================
    //====================================================================== put Vaiance=Dispersia = Sig**2=<R**2> - (<R>)**2 
      //                                                                                           = sum(R*R)/N - (sum(R)/N)**2 
      //                                                                                           =  mapdphinormHE1,2,3..7   -  alexhe*alexhe
      ////                                                                                         into massive variance
      c1->Clear();
      c1->Divide(1,3);
      
      for(int jeta=0;jeta<njeta;jeta++){
	for(int jphi=0;jphi<njphi;jphi++){
	  //	   cout<<"12 12 12   jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<endl;
	  variance[0][jeta][jphi] = fabs(mapdphinormHE1->GetBinContent(jeta+1,jphi+1) - alexhe[0][jeta][jphi]*alexhe[0][jeta][jphi]) ;
	  if(variance[0][jeta][jphi] < 0.00003) variance[0][jeta][jphi] = 0.000067;
	  variance[1][jeta][jphi] = fabs(mapdphinormHE2->GetBinContent(jeta+1,jphi+1) - alexhe[1][jeta][jphi]*alexhe[1][jeta][jphi]) ;
	  if(variance[1][jeta][jphi] < 0.00003) variance[1][jeta][jphi] = 0.000067;
	  variance[2][jeta][jphi] = fabs(mapdphinormHE3->GetBinContent(jeta+1,jphi+1) - alexhe[2][jeta][jphi]*alexhe[2][jeta][jphi]) ;
	  if(variance[2][jeta][jphi] < 0.00003) variance[2][jeta][jphi] = 0.000067;
	  variance[3][jeta][jphi] = fabs(mapdphinormHE4->GetBinContent(jeta+1,jphi+1) - alexhe[3][jeta][jphi]*alexhe[3][jeta][jphi]) ;
	  if(variance[3][jeta][jphi] < 0.00003) variance[3][jeta][jphi] = 0.000067;
	  variance[4][jeta][jphi] = fabs(mapdphinormHE5->GetBinContent(jeta+1,jphi+1) - alexhe[4][jeta][jphi]*alexhe[4][jeta][jphi]) ;
	  if(variance[4][jeta][jphi] < 0.00003) variance[4][jeta][jphi] = 0.000067;
	  variance[5][jeta][jphi] = fabs(mapdphinormHE6->GetBinContent(jeta+1,jphi+1) - alexhe[5][jeta][jphi]*alexhe[5][jeta][jphi]) ;
	  if(variance[5][jeta][jphi] < 0.00003) variance[5][jeta][jphi] = 0.000067;
	  variance[6][jeta][jphi] = fabs(mapdphinormHE7->GetBinContent(jeta+1,jphi+1) - alexhe[6][jeta][jphi]*alexhe[6][jeta][jphi]) ;
	  if(variance[6][jeta][jphi] < 0.00003) variance[6][jeta][jphi] = 0.000067;


	  //	  	  if( alexhe[6][jeta][jphi] != 0. ) cout<<"12 12 12  alexhe[6][jeta][jphi] != 0.     jeta=     "<< jeta <<"   jphi   =     "<<jphi  <<"  variance[6][jeta][jphi]   =     "<<variance[0][jeta][jphi]  <<"   mapdphinormHE7->GetBinContent(jeta+1,jphi+1)   =     "<<mapdphinormHE7->GetBinContent(jeta+1,jphi+1)  <<"   alexhe[6][jeta][jphi]   =     "<<alexhe[6][jeta][jphi]  <<endl;
	}	 
      }
      
      //------------------------  2D-eta/phi-plot: R, averaged over depthes


      // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;
      //          TH2F* Defz42D      = new TH2F("Defz42D","",   23, -11.5, 11.5, 18, 0., 18. );
      //          TH2F* Defz42D0     = new TH2F("Defz42D0","",  23, -11.5, 11.5, 18, 0., 18. );
      TH2F* Defz42D      = new TH2F("Defz42D","",   neta, -41., 41., nphi, 0., 72. );
      TH2F* Defz42D0     = new TH2F("Defz42D0","",  neta, -41., 41., nphi, 0., 72. );
      //     TH2F* Defz42D      = new TH2F("Defz42D","",   22, -11., 11., 18, 0., 18. );
      //     TH2F* Defz42D0     = new TH2F("Defz42D0","",  22, -11., 11., 18, 0., 18. );
      //      TH2F* Defz42D      = new TH2F("Defz42D","",   24, -12., 12., 18, 0., 18. );
      //     TH2F* Defz42D0     = new TH2F("Defz42D0","",  24, -12., 12., 18, 0., 18. );
      TH2F* Defz42DF = (TH2F*)Defz42D0->Clone("Defz42DF");
      for (int i=0;i<ndepth;i++) {
	for (int jeta=0;jeta<neta;jeta++) {
	  for (int jphi=0;jphi<nphi;jphi++) {
	    double ccc1 = variance[i][jeta][jphi];
	    //	     int neweta = jeta-11-0.5; if(jeta>=11) neweta = jeta-11+1.5; 
	    //	     if(alexhe[i][jeta][jphi]>0.) {Defz42D ->Fill(neweta,jphi,ccc1); Defz42D0 ->Fill(neweta,jphi,1.); }
	    
	    int k2plot = jeta-41;int kkk = k2plot; //if(k2plot >0   kkk=k2plot+1; //-41 +41 !=0
	    if(alexhe[i][jeta][jphi]>0.) {Defz42D ->Fill(kkk,jphi,ccc1); Defz42D0 ->Fill(kkk,jphi,1.); }
	  }}}
      c1->cd(1);
      Defz42D->Draw("COLZ");
      c1->cd(2);
      Defz42D0->Draw("COLZ");
      c1->cd(3);
      Defz42DF->Divide(Defz42D,Defz42D0, 1, 1, "B");// average A
      //    Defz1->Sumw2();
      gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
      Defz42DF->SetMarkerStyle(20); Defz42DF->SetMarkerSize(0.4); Defz42DF->GetZaxis()->SetLabelSize(0.08); Defz42DF->SetXTitle("<D>_depth       #eta  \b"); Defz42DF->SetYTitle("      #phi \b"); Defz42DF->SetZTitle("<D>_depth \b"); Defz42DF->SetMarkerColor(2); Defz42DF->SetLineColor(0);      //      Defz42DF->SetMaximum(1.000);  //      Defz42DF->SetMinimum(1.0);
      Defz42DF->Draw("COLZ");
      
      
      
      c1->Update();
    //================
       //======================================================================
       //========================================================================================== 13  
       //======================================================================
       //======================================================================
       //======================================================================
       //====================================================================== 1D plot: D vs phi , averaged over depthes & eta
       c1->Clear();
       /////////////////
       c1->Divide(1,1);
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       c1->cd(1);
       // int ietaphi = 0; ietaphi = ((k2+1)-1)*nphi + (k3+1) ;  k2=0-neta-1; k3=0-nphi-1; neta=18; nphi=22;

       TH1F* Defz41D      = new TH1F("Defz41D","", nphi, 0., 72. );
       TH1F* Defz41D0     = new TH1F("Defz41D0","",nphi, 0., 72. );
       TH1F* Defz41DF = (TH1F*)Defz41D0->Clone("Defz41DF");

       for (int jphi=0;jphi<nphi;jphi++) {
	 for (int jeta=0;jeta<neta;jeta++) {
	   for (int i=0;i<ndepth;i++) {
	     double ccc1 = variance[i][jeta][jphi];
	     if(alexhe[i][jeta][jphi]>0.) {Defz41D ->Fill(jphi,ccc1); Defz41D0 ->Fill(jphi,1.); }
	   }}}
       //     Defz41D->Sumw2();Defz41D0->Sumw2();

       Defz41DF->Divide(Defz41D,Defz41D0, 1, 1, "B");// R averaged over depthes & eta
            Defz41DF->Sumw2();Defz41D->Sumw2();Defz41D0->Sumw2();
       //    for (int jphi=1;jphi<73;jphi++) {Defz41DF->SetBinError(jphi,0.01);}
       gPad->SetGridy();      gPad->SetGridx();      //      gPad->SetLogz();
       Defz41DF->SetMarkerStyle(20); Defz41DF->SetMarkerSize(1.4); Defz41DF->GetZaxis()->SetLabelSize(0.08); Defz41DF->SetXTitle("#phi  \b"); Defz41DF->SetYTitle("  <D> \b"); Defz41DF->SetZTitle("<D>_PHI  - AllDepthes \b"); Defz41DF->SetMarkerColor(4); Defz41DF->SetLineColor(4);  Defz41DF->SetMinimum(0.8);     Defz41DF->SetMinimum(-0.015);       
       Defz41DF->Draw("Error");
       
       c1->Update();
       
      //          ADCAmplperLS ->SetMaximum(30.0);
      //          ADCAmplperLS ->SetMinimum(20.0);
    //================
       //======================================================================
       //========================================================================================== 14   
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=1
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD1=1;
       TH1F* h2CeffHEpositivedirectionD1 = new TH1F("h2CeffHEpositivedirectionD1","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=1
	   for (int i=0;i<1;i++) {
	     
	     TH1F *HEpositivedirectionD1 = (TH1F*)h2CeffHEpositivedirectionD1->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD1 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD1->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1414       kcountHEpositivedirectionD1   =     "<<kcountHEpositivedirectionD1  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD1);
	       HEpositivedirectionD1 ->SetMarkerStyle(20);HEpositivedirectionD1 ->SetMarkerSize(0.4);HEpositivedirectionD1 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD1 ->SetXTitle("HEpositivedirectionD1 \b");HEpositivedirectionD1 ->SetMarkerColor(2);HEpositivedirectionD1 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD1 == 1) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 18; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 2) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 19; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 3) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 20; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 4) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 21; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 5) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 22; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 6) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 23; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 7) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 24; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 8) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 25; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 == 9) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 26; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 ==10) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 27; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 ==11) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 28; depth = 1 \b");
	       if(kcountHEpositivedirectionD1 ==12) HEpositivedirectionD1 ->SetXTitle("D for HE+ jeta = 29; depth = 1 \b");
	       HEpositivedirectionD1->Draw("Error");
	       kcountHEpositivedirectionD1++;
	       if(kcountHEpositivedirectionD1>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 15  
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=2
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD2=1;
       TH1F* h2CeffHEpositivedirectionD2 = new TH1F("h2CeffHEpositivedirectionD2","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=2
	   for (int i=1;i<2;i++) {
	     
	     TH1F *HEpositivedirectionD2 = (TH1F*)h2CeffHEpositivedirectionD2->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD2 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD2->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1515       kcountHEpositivedirectionD2   =     "<<kcountHEpositivedirectionD2  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD2);
	       HEpositivedirectionD2 ->SetMarkerStyle(20);HEpositivedirectionD2 ->SetMarkerSize(0.4);HEpositivedirectionD2 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD2 ->SetXTitle("HEpositivedirectionD2 \b");HEpositivedirectionD2 ->SetMarkerColor(2);HEpositivedirectionD2 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD2 == 1) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 17; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 2) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 18; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 3) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 19; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 4) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 20; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 5) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 21; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 6) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 22; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 7) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 23; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 8) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 24; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 == 9) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 25; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 ==10) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 26; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 ==11) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 27; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 ==12) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 28; depth = 2 \b");
	       if(kcountHEpositivedirectionD2 ==13) HEpositivedirectionD2 ->SetXTitle("D for HE+ jeta = 29; depth = 2 \b");
	       HEpositivedirectionD2->Draw("Error");
	       kcountHEpositivedirectionD2++;
	       if(kcountHEpositivedirectionD2>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 16   
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=3
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD3=1;
       TH1F* h2CeffHEpositivedirectionD3 = new TH1F("h2CeffHEpositivedirectionD3","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=3
	   for (int i=2;i<3;i++) {
	     
	     TH1F *HEpositivedirectionD3 = (TH1F*)h2CeffHEpositivedirectionD3->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD3 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD3->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1616       kcountHEpositivedirectionD3   =     "<<kcountHEpositivedirectionD3  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD3);
	       HEpositivedirectionD3 ->SetMarkerStyle(20);HEpositivedirectionD3 ->SetMarkerSize(0.4);HEpositivedirectionD3 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD3 ->SetXTitle("HEpositivedirectionD3 \b");HEpositivedirectionD3 ->SetMarkerColor(2);HEpositivedirectionD3 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD3 == 1) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 17; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 2) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 18; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 3) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 19; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 4) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 20; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 5) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 21; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 6) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 22; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 7) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 23; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 8) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 24; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 == 9) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 25; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 ==10) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 26; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 ==11) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 27; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 ==12) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 28; depth = 3 \b");
	       if(kcountHEpositivedirectionD3 ==13) HEpositivedirectionD3 ->SetXTitle("D for HE+ jeta = 29; depth = 3 \b");
	       HEpositivedirectionD3->Draw("Error");
	       kcountHEpositivedirectionD3++;
	       if(kcountHEpositivedirectionD3>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 17   
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=4
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD4=1;
       TH1F* h2CeffHEpositivedirectionD4 = new TH1F("h2CeffHEpositivedirectionD4","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=4
	   for (int i=3;i<4;i++) {
	     
	     TH1F *HEpositivedirectionD4 = (TH1F*)h2CeffHEpositivedirectionD4->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD4 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD4->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1717       kcountHEpositivedirectionD4   =     "<<kcountHEpositivedirectionD4  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD4);
	       HEpositivedirectionD4 ->SetMarkerStyle(20);HEpositivedirectionD4 ->SetMarkerSize(0.4);HEpositivedirectionD4 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD4 ->SetXTitle("HEpositivedirectionD4 \b");HEpositivedirectionD4 ->SetMarkerColor(2);HEpositivedirectionD4 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD4 == 1) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 16; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 2) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 18; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 3) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 19; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 4) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 20; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 5) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 21; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 6) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 22; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 7) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 23; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 8) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 24; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 == 9) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 25; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 ==10) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 26; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 ==11) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 27; depth = 4 \b");
	       if(kcountHEpositivedirectionD4 ==12) HEpositivedirectionD4 ->SetXTitle("D for HE+ jeta = 28; depth = 4 \b");
	       HEpositivedirectionD4->Draw("Error");
	       kcountHEpositivedirectionD4++;
	       if(kcountHEpositivedirectionD4>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 18   
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=5
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD5=1;
       TH1F* h2CeffHEpositivedirectionD5 = new TH1F("h2CeffHEpositivedirectionD5","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=5
	   for (int i=4;i<5;i++) {
	     
	     TH1F *HEpositivedirectionD5 = (TH1F*)h2CeffHEpositivedirectionD5->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD5 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD5->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1818       kcountHEpositivedirectionD5   =     "<<kcountHEpositivedirectionD5  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD5);
	       HEpositivedirectionD5 ->SetMarkerStyle(20);HEpositivedirectionD5 ->SetMarkerSize(0.4);HEpositivedirectionD5 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD5 ->SetXTitle("HEpositivedirectionD5 \b");HEpositivedirectionD5 ->SetMarkerColor(2);HEpositivedirectionD5 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD5 == 1) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 18; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 2) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 19; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 3) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 20; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 4) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 21; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 5) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 22; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 6) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 23; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 7) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 24; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 8) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 25; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 == 9) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 26; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 ==10) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 27; depth = 5 \b");
	       if(kcountHEpositivedirectionD5 ==11) HEpositivedirectionD5 ->SetXTitle("D for HE+ jeta = 28; depth = 5 \b");
	       HEpositivedirectionD5->Draw("Error");
	       kcountHEpositivedirectionD5++;
	       if(kcountHEpositivedirectionD5>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 19   
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=6
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD6=1;
       TH1F* h2CeffHEpositivedirectionD6 = new TH1F("h2CeffHEpositivedirectionD6","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=6
	   for (int i=5;i<6;i++) {
	     
	     TH1F *HEpositivedirectionD6 = (TH1F*)h2CeffHEpositivedirectionD6->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD6 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD6->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest>0.) {
	       cout<<"1919       kcountHEpositivedirectionD6   =     "<<kcountHEpositivedirectionD6  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD6);
	       HEpositivedirectionD6 ->SetMarkerStyle(20);HEpositivedirectionD6 ->SetMarkerSize(0.4);HEpositivedirectionD6 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD6 ->SetXTitle("HEpositivedirectionD6 \b");HEpositivedirectionD6 ->SetMarkerColor(2);HEpositivedirectionD6 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD6 == 1) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 19; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 2) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 20; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 3) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 21; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 4) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 22; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 5) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 23; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 6) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 24; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 7) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 25; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 8) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 26; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 == 9) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 27; depth = 6 \b");
	       if(kcountHEpositivedirectionD6 ==10) HEpositivedirectionD6 ->SetXTitle("D for HE+ jeta = 28; depth = 6 \b");
	       HEpositivedirectionD6->Draw("Error");
	       kcountHEpositivedirectionD6++;
	       if(kcountHEpositivedirectionD6>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //========================================================================================== 20  
       //======================================================================
       //======================================================================1D plot: D vs phi , different eta,  depth=7
       c1->Clear();
       /////////////////
       c1->Divide(3,5);
       int kcountHEpositivedirectionD7=1;
       TH1F* h2CeffHEpositivedirectionD7 = new TH1F("h2CeffHEpositivedirectionD7","", nphi, 0., 72. );

       for (int jeta=0;jeta<njeta;jeta++) {
	 // positivedirectionD:
	 if(jeta-41 > 0) {
	   
	   //	     for (int i=0;i<ndepth;i++) {
	   // depth=7
	   for (int i=6;i<7;i++) {
	     
	     TH1F *HEpositivedirectionD7 = (TH1F*)h2CeffHEpositivedirectionD7->Clone("twod1");
	     
	     float ccctest = 0; // to avoid empty massive elements
	     for (int jphi=0;jphi<nphi;jphi++) {
	       
	       double ccc1 = variance[i][jeta][jphi];
	       if(alexhe[i][jeta][jphi]>0.) {HEpositivedirectionD7 ->Fill(jphi,ccc1);ccctest = 1.;HEpositivedirectionD7->SetBinError(i,0.01);}
	     }// for jphi
	     if(ccctest !=0.) {
	       cout<<"2020       kcountHEpositivedirectionD7   =     "<<kcountHEpositivedirectionD7  <<"   jeta-41=     "<< jeta-41 <<endl;
	       c1->cd(kcountHEpositivedirectionD7);
	       HEpositivedirectionD7 ->SetMarkerStyle(20);HEpositivedirectionD7 ->SetMarkerSize(0.4);HEpositivedirectionD7 ->GetYaxis()->SetLabelSize(0.04);HEpositivedirectionD7 ->SetXTitle("HEpositivedirectionD7 \b");HEpositivedirectionD7 ->SetMarkerColor(2);HEpositivedirectionD7 ->SetLineColor(0);gPad->SetGridy();gPad->SetGridx(); 
	       //	   gPad->SetLogy();    
	       if(kcountHEpositivedirectionD7 == 1) HEpositivedirectionD7 ->SetXTitle("D for HE+ jeta = 26; depth = 7 \b");
	       if(kcountHEpositivedirectionD7 == 2) HEpositivedirectionD7 ->SetXTitle("D for HE+ jeta = 27; depth = 7 \b");
	       if(kcountHEpositivedirectionD7 == 3) HEpositivedirectionD7 ->SetXTitle("D for HE+ jeta = 28; depth = 7 \b");
	       HEpositivedirectionD7->Draw("Error");
	       kcountHEpositivedirectionD7++;
	       if(kcountHEpositivedirectionD7>15) break;// 4x6 = 24 
	     }//ccctest>0
	     
	   }// for i
	 }//if(jeta-41 > 0)
       }//for jeta
       /////////////////
       c1->Update();
       //================
       //================
       //================
       //================
       //================
       //================
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




      
