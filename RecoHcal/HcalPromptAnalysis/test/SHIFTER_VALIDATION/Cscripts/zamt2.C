//______________________________________________________________________________
TCanvas *c1;
TGraph *gr1;
//______________________________________________________________________________
void zamt2()
{
  //
  Int_t NP = 3;
  // days of year:
  Float_t XX[] = { 161., 264., 353.};// time points
  // width averaged:
  Float_t YY[] = { 1.5, 1.5, 1.5};// to be specified, here just initialisation
  //
  TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_199392.root", "READ");

  TFile *hfile2= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_206456.root", "READ");

  TFile *hfile3= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_211659.root", "READ");

  for(int k1 = 1; k1<4; k1++) {
    if(k1==1) {
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
    }
    else if(k1==2) {
      TH2F *twod1= (TH2F*)hfile2->Get("h_mapDepth1Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile2->Get("h_mapDepth1_HB");
    }
    else if(k1==3) {
      TH2F *twod1= (TH2F*)hfile3->Get("h_mapDepth1Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile3->Get("h_mapDepth1_HB");
    }
    if(twod0->IsA()->InheritsFrom("TH2F")) {
      TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
      Ceff->Divide(twod1,twod0, 1, 1, "B");
    }
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	if(i == 52  && j == 4 ) {
	  cout<<" Point: " << k1 << " i = " << i << " j = " << j <<" BinContent= "<< YY[k1] <<endl;
	  YY[k1]  =  Ceff->GetBinContent(i,j)   ;
	}//if
      }//for     j
    }//for    i
    //
  }//for  k1 
  
  //

  // Create a new canvas.
   c1 = new TCanvas("zamt2","Monte Carlo Study of Z scaling",10,40,800,600);
   c1->Range(0,0,25,18);
   c1->SetFillColor(40);


   pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.48,0.83,33);
   pad2 = new TPad("pad2","This is pad2",0.52,0.02,0.98,0.83,33);

   pad1->Draw();
   pad2->Draw();

//
//
   pad1->cd();
   pad1->Range(-0.255174,-19.25,2.29657,-6.75);
   //   pad1->SetLogx();
   //   pad1->SetLogy();

   // create a 2-d histogram to define the range
   //              x1   y1     x2     y2
   pad1->DrawFrame(1,   0.,   365,   2.5);
   pad1->GetFrame()->SetFillColor(19);

   cout<<" gr1: NP=" << NP << 
     " XX[1] = " << XX[1] << " YY[1] = " << YY[1]  <<
     " XX[2] = " << XX[2] << " YY[2] = " << YY[2]  <<
     " XX[3] = " << XX[3] << " YY[3] = " << YY[3]  <<endl;
   gr1 = new TGraph(NP,XX,YY);
   
   gr1->SetLineColor(38);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(20);
   gr1->SetMarkerSize(1.1);
   gr1->Draw("P");

//

   c1->Modified();
   c1->Update();
   //
   c1->Print("zamt2.ps");
        gSystem->Exit(0);
}
