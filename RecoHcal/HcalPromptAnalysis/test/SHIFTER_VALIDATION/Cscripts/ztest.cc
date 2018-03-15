#include <iostream>
#include <iomanip>
#include <fstream>
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
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
#include <TLatex.h>
#include <TFrame.h>
#include <TPad.h>
#include <TGaxis.h>

#include "TGraphErrors.h"
#include "TF1.h"
#include "TArrow.h"

//
using namespace std;
//
//  
int main(int argc, char *argv[])
{


//Int_t cosmic_hours(
  Char_t *id = "AIMS_0deg" ;
  Int_t Rebin=2  ;
  Bool_t FIT= kTRUE; 

	TFile *hfile1= new TFile("LEDtest.root", "READ");

  Int_t i=0, Ntotal=0;
  Float_t time[100],N[100],N1[100],N2[100],N3[100];
  Float_t Nh,t;
  Int_t H0=4, Hn=12; //aims_0deg

  // define histograms
  const Float_t Nmin=0., Nmax=60.;  // (Nmax better multiple of Rebin :)
  const Int_t Nchannels= (Int_t) ((Float_t) (Nmax-Nmin))/((Float_t) Rebin);
  TH1F *h1 = new TH1F("h1","counts",Nchannels,Nmin-0.5,Nmax-0.5);

  const Char_t * file = Form("%s.txt",id); //full name
  //cout << file << endl;

  ifstream inFile(file, ios::in); // open datafile ...
//...and read from file, row by row
  while ( inFile >> Nh ){  
    Ntotal += Nh; //summ all counts
    h1->Fill(Nh);
    N[i]=Nh;
    time[i]=(Float_t) i;
    // cout << time[i] << " " << N[i] << endl; //type on screen
    i++;  //increment loop counter
  }
 
  const Int_t Nhours=i; //that is our total number of hours
  //cout << "<I> read "<< Nhours <<" points from file " << file << " ...total counts = " << Ntotal <<endl; //type on screen
  printf("<I> Read %d points from file %s ...total counts: %d, average: %4.2f \n",Nhours,file,Ntotal,((float)Ntotal/(float)Nhours)); // ...in anotehr way
  inFile.close(); // close file

// ... then do the plot...

// general graphics settings
  Double_t font = 42;  // choice of font type
  Double_t valSize=0.05; //size of axis values
  Double_t titSize=0.05; //size of axis titles
  gStyle->SetOptStat(1); //plot statistics box
  gStyle->SetOptFit(1111); // switch on statistics details for fit
  gStyle->SetOptTitle(0);
  gStyle->SetOptDate(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetCanvasColor(10);
  gStyle->SetTitleFont(font,"XY");
  gStyle->SetLabelFont(font,"XY");
  gStyle->SetStatFont(font);
  
  TVirtualPad *pad = 0x0; //plotting pad

  TCanvas *c1 = new TCanvas("c1", "Graphs",5,5,600,600); // plotting canvas
  
  c1->SetFillColor(0);
  c1->SetGridy(); //no grids
  c1->SetGridx();
  c1->SetBorderSize(1);
  c1->SetLogy(kFALSE);
  c1->SetLeftMargin(0.25);
  c1->SetRightMargin(0.085);
  c1->SetBottomMargin(0.15);
  c1->SetTopMargin(0.05);
  c1->Divide(2,2); // divide in 2 x 2 panels

  //gPad->SetTicks(); gPad->SetGrid();

  //c1->cd(1); //1st panel
  pad = c1->cd(1);	  
  pad->SetLeftMargin(0.18); pad->SetRightMargin(0.01);
  pad->SetTopMargin(0.005); pad->SetBottomMargin(0.16);
  //pad->SetFrameLineWidth(0.1); //histo frame      

  // Build graph of dependence on time (hour) dependence
  TGraph* g1   = new TGraph(Nhours,time, N); 
  g1->GetHistogram()->SetStats(0);
  g1->GetXaxis()->SetLabelFont(font);
  g1->GetXaxis()->SetTitleFont(font);
  g1->GetYaxis()->SetLabelFont(font);
  g1->GetYaxis()->SetTitleFont(font);
  
  //g1->SetMaximum(Ymax); g1->SetMinimum(Ymin);
  g1->GetYaxis()->SetTickLength(.02);  
  g1->GetXaxis()->SetTitle("Hour");
  g1->GetYaxis()->SetTitle("Counts");
  g1->GetXaxis()->SetTitleOffset(1.0);
  g1->GetYaxis()->SetTitleOffset(1.2);
  g1->GetXaxis()->SetLabelSize(valSize);
  g1->GetYaxis()->SetLabelSize(valSize);
  g1->GetYaxis()->SetTitleSize(titSize);
  g1->GetXaxis()->SetTitleSize(titSize);
  g1->SetTitle("");
  g1->SetLineWidth(1);
  g1->SetMarkerStyle(20); //20:dot, 21:square, 22,23:triangle
  g1->SetMarkerSize(1.);
  g1->SetMarkerColor(kRed); //kRed, kBlue, etc.
  g1->SetLineColor(kRed);
  g1->Draw("APL");  // draw symbols and lines
  //g1->Draw("AP");  // draw symbols

  //c1->cd(2); //2nd panel
  pad = c1->cd(2);	  
  pad->SetLeftMargin(0.18); pad->SetRightMargin(0.01);
  pad->SetTopMargin(0.005); pad->SetBottomMargin(0.16);

  // histogram of all counts
  h1->GetXaxis()->SetTitle("Counts");
  h1->GetYaxis()->SetTitle("Frequency");
  h1->GetXaxis()->SetTitleOffset(1.0);
  h1->GetYaxis()->SetTitleOffset(1.2);
  h1->SetLabelSize(valSize,"XY");
  h1->SetTitleSize(titSize,"XY");
  h1->SetTitle("");
  h1->SetName("All Counts");
  h1->SetLineWidth(2.);
  h1->SetMarkerStyle(20); //20:dot, 21:square, 22,23:triangle
  h1->SetMarkerSize(1.3);
  h1->SetMarkerColor(kRed); //kRed, kBlue, etc.
  h1->SetLineColor(kRed);
  h1->Draw();  // draw 

// fancy things on statistics box ... http://root.cern.ch/root/html/TPaveStats.html
  gPad->Update();
  TPaveStats *st = (TPaveStats*)h1->FindObject("stats");
  st->SetX1NDC(0.65); st->SetX2NDC(0.99); //x start, end
  st->SetY1NDC(0.99); st->SetY2NDC(0.59); //x start, end

  Float_t NsigInt=5.0; //N sigmas (rms) for integration

  Float_t hMean=h1->GetMean();
  Float_t hMeanErr=h1->GetMeanError(1);
  Float_t hWidth=h1->GetRMS();
  Float_t hWidthErr=h1->GetRMSError();
  Float_t hInt=h1->Integral(hMean-NsigInt*hWidth,hMean+NsigInt*hWidth); // /h1->GetBinWidth(1);
  printf("<I> Histogram: Center: %4.2f +- %4.2f, rms: %4.2f +- %4.2f, Integral(+-%4.1f rms): %6.1f\n",hMean,hMeanErr,hWidth,hWidthErr,NsigInt,hInt);

  TLegend *legend1=new TLegend(0.62,0.45,0.98,0.55);
  legend1->SetBorderSize(2);
  legend1->SetTextFont(42);
  legend1->SetTextSize(0.035);
  legend1->SetFillColor(0);
  legend1->AddEntry(h1,Form("Data, %s", id),"l");

  if (FIT) {  //decide to do fit or not
  // define function    
  //TF1* f1=new TF1("f1", "gaus",Nmin,Nmax);
  TF1* f1=new TF1("f1", "[0]*exp(-0.5*((x-[1])/[2])**2)",Nmin,Nmax); // [n] is parameter nr.
  f1->SetLineColor(kBlue+1); 
  f1->SetLineWidth(2);
  f1->SetLineStyle(1);

  // define fit range
  Float_t FitMin=Nmin, FitMax=Nmax; //
  //Float_t FitMin=0.3*hMean, FitMax= 3.*hMean; //
  // set start and range of parameters
  f1->SetParameter(0, 10.);       // constant
  //f1->SetParLimits(0, 0.5, 50);
  f1->SetParameter(1, hMean);      // centroid, mean of histogram
  f1->SetParLimits(1, 0.8*hMean, 1.2*hMean); //not needed in simple cases
  f1->SetParameter(2, hWidth);      // sigma
  f1->SetParLimits(2, 0.8*hWidth, 1.2*hWidth); //not needed

  // perform fit
  h1->Fit("f1", "M", "",FitMin,FitMax); //fit in specified range "M" is Minuit minimization procedure
  cout << "Gauss fit: chi2/NDF = " << f1->GetChisquare() << "/" << f1->GetNDF() << endl;

  // retrieve the parameters of the fit 
  Float_t fMean=f1->GetParameter(1);
  Float_t fMeanErr=f1->GetParError(1);
  Float_t fWidth=f1->GetParameter(2);
  Float_t fWidthErr=f1->GetParError(2);
  Float_t fInt=f1->Integral(fMean-NsigInt*fWidth,fMean+NsigInt*fWidth);
  printf("<I> Fit: Mean: %4.2f +- %4.2f, Width: %4.2f +- %4.2f, Integral(+-%4.1f sigma): %6.1f\n",fMean,fMeanErr,fWidth,fWidthErr,NsigInt,fInt);
  legend1->AddEntry(f1,"Fit, gaussian","l");

  }

  legend1->Draw();
  
  c1->SaveAs(Form("cosmics_%s.pdf",id)); //save plot, pdf format
  c1->SaveAs(Form("cosmics_%s.png",id)); //...and png format



  //______________________________________________________________________________
  //  
  gSystem->Exit(0);
  //______________________________________________________________________________


}


