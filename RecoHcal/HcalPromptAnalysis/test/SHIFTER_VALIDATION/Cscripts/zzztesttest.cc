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

	TFile *hfile1= new TFile("Global_325001_ls1to600.root", "READ");


////////////////////////////////////////////////////////////

//	TFile *hfile1= new TFile("Global_321177_41_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap.root", "READ");
//	TFile *hfile1= new TFile("Global_321177_ls1to600_abortgap_no41.root", "READ");

//	TFile *hfile1= new TFile("Global_325001_ls1to600_abortgap.root", "READ");





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//    getchar();
	//
          TPostScript psfile ("zzztesttest.ps", 111);


//

	  TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
	    //	    cout<<"  i= "<< i <<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<"      A= "<< ccc1 <<endl;
      c1->cd(1);



      ///////////////////        tests

      ///////////////////        tests
      int neta = 82;  int nphi = 72;
      cout<<"   neta=     "<< neta <<" nphi=     "<< nphi <<endl;
      
      //                                       INDEXIES:
      for(int k3 = 0; k3<nphi; k3++) {
	//kkkk3= 1-18
      	int kkkk3 = (k3)/4 + 1 ;
	//    	cout<<"   k3=     "<< k3 <<" kkkk3=     "<< kkkk3 <<endl;
      }
      for(int k2 = 0; k2<neta; k2++) {
	/*
	float kkkkkk2 = (k2-1)/4.;
	cout<<"INI   k2=     "<< k2 <<" kkkkkk2=     "<< kkkkkk2 <<endl;
	if(kkkkkk2<0) kkkkkk2=1.;else kkkkkk2+=2;
        int kkkk2=kkkkkk2;
*/
	//kkkk2= 1-22
	int kkkk2 = (k2-1)/4;
	if(k2==0) kkkk2=1.;else kkkk2+=2;
	//	cout<<"AFTER                      k2=     "<< k2 <<" kkkk2=     "<< kkkk2 <<endl;
      }





      //                                       PACKING
      int zneta = 22;  int znphi = 18;
      //kkkk2= 1-22
      for(int kkkk2 = 0; kkkk2<zneta; kkkk2++) {
	//kkkk3= 1-18
	for(int kkkk3 = 0; kkkk3<znphi; kkkk3++) {
	  int ietaphi = 0; ietaphi = ((kkkk2+1)-1)*znphi + (kkkk3+1) ; //  ietaphi = 1 - 5904 ( # =5904; in histo,booking is: 1 - 5905 )
	  cout<<"   kkkk2=     "<< kkkk2 <<"   kkkk3=     "<< kkkk3 <<"      ietaphi=     "<< ietaphi <<endl;
	}
      }
      // j = ietaphi = 1- 396





      //                                   UNPACKING:
       int ietaphimax = 396;

      int ny = ietaphimax + 1 ;
      for (int j=1;j<ny;j++) {
	  int jeta = (j-1)/znphi;
	  int jphi = (j-1)-znphi*jeta+1;// jphi=1-18 
	  jeta += 1;// jeta = 1-22
	  cout<<" j= "<< j <<"  jeta= "<< jeta <<" jphi= "<< jphi <<endl;
      }






      ////////////////////////////////////////////////////////////////////////////////////
       c1->Update();

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




      
