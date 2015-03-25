{
   //====================================================================== zamt.C
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
				gStyle->SetOptStat(0);   //  no statistics _or_
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
	std::string  rundir;
	rundir = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos" ;
	Int_t runnumber = 211006;
	cout << "Input file = " << rundir <<"/LED_" << runnumber <<".root" <<endl;
////	TFile *hfile1= new TFile("rundir/LED_211006.root", "READ");
TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_211006.root", "READ");
TFile *hfile2= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_211659.root", "READ");

//  /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_216568.root

//	TFile *hfile1= new TFile("testNZS.root", "READ"); 
//	TFile *hfile1= new TFile("test22LED.root", "READ");
//	TFile *hfile1= new TFile("test.root", "READ"); 
//
//	TFile *hfile1= new TFile("testRunDepCap32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepWidth32.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zamt1.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
    ///////////////////////////////////////
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
    //////////////
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_Amplitude_HB");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("TS RMS in each event & cell HB \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH2F* Diffe_Depth1_HB = (TH2F*)Ceff->Clone("Diffe_Depth1_HB");
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      cout << "222222: nx = " << nx <<" ny = " << ny <<endl;
      int nch = 0.;
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB->SetBinContent(i,j,0.);
	  if(ccc1 != 0. ) {
	    ++nch;
	    //	    cout<<"only non-zero channels: i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	  }
	  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
	}
      }
      cout<<"***** total number of non-zero channels,  nch = "<<nch <<endl;
      gPad->SetGridy();
      gPad->SetGridx();
//      gPad->SetLogz();
      Diffe_Depth1_HB->SetMarkerStyle(20);
      Diffe_Depth1_HB->SetMarkerSize(0.4);
      Diffe_Depth1_HB->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HB->SetXTitle("#eta \b");
      Diffe_Depth1_HB->SetYTitle("#phi \b");
      //    Diffe_Depth1_HB->SetZTitle("<TS RMS> out 1.0-2.3 - HB Depth1 \b");
      Diffe_Depth1_HB->SetMarkerColor(2);
      Diffe_Depth1_HB->SetLineColor(2);
      Diffe_Depth1_HB->SetMinimum(1.4);
      Diffe_Depth1_HB->SetMaximum(1.8);
      Diffe_Depth1_HB->Draw("COLZ");
      

      c1->cd(3);
      TH1F* diffAmplitude_Depth1_HB = new TH1F("diffAmplitude_Depth1_HB","", 100, 1., 2.);
      TH1F* MYdiffAmplitude_Depth1_HB = new TH1F("MYdiffAmplitude_Depth1_HB","", 100, 1., 2.);
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffAmplitude_Depth1_HB->Fill(ccc1);
	    if(i == 52  && j == 4 ) {
	      cout<<"333333: i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	      MYdiffAmplitude_Depth1_HB->Fill(ccc1);
	    }
	  }
	}
      }
      gPad->SetLogy();
      diffAmplitude_Depth1_HB->SetMarkerStyle(20);
      diffAmplitude_Depth1_HB->SetMarkerSize(0.4);
      diffAmplitude_Depth1_HB->GetYaxis()->SetLabelSize(0.04);
      diffAmplitude_Depth1_HB->SetXTitle("<TS RMS> in each cell \b");
      diffAmplitude_Depth1_HB->SetMarkerColor(2);
      diffAmplitude_Depth1_HB->SetLineColor(2);
      diffAmplitude_Depth1_HB->Draw("Error");
      MYdiffAmplitude_Depth1_HB->SetMarkerStyle(20);
      MYdiffAmplitude_Depth1_HB->SetMarkerSize(0.4);
      MYdiffAmplitude_Depth1_HB->SetMarkerColor(1);
      MYdiffAmplitude_Depth1_HB->SetLineColor(1);
      MYdiffAmplitude_Depth1_HB->Draw("ErrorSame");

      

      c1->cd(4);
      TH2F* DiffeCut_Depth1_HB = (TH2F*)Ceff->Clone("DiffeCut_Depth1_HB");
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j);
	  DiffeCut_Depth1_HB->SetBinContent(i,j,0.);
	}
      }
      //
  Int_t NR = 9;  // number of imposed dependencies for different channels 
  Int_t r1=0;
  while (r1<NR) {
      Int_t rr=0;
      while (rr==0) {
	//      Int_t ra = (rand() % 100) ; // 0-99
	Int_t i = nx*((rand()%100+2)/100.);
	Int_t j = ny*((rand()%100+2)/100.);
	ccc1  =  Ceff->GetBinContent(i,j);
	if(ccc1 >0.001) rr=1; 
      }//rr
      DiffeCut_Depth1_HB->SetBinContent(i,j,ccc1);
      /*
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  DiffeCut_Depth1_HB->SetBinContent(i,j,0.);
	  if(i == 52  && j == 4 ) {
	    cout<<"444444: i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	    DiffeCut_Depth1_HB->SetBinContent(i,j,ccc1);
	  }
	}
      }
*/
      gPad->SetGridy();
      gPad->SetGridx();
      //    gPad->SetLogz();
      DiffeCut_Depth1_HB->SetMarkerStyle(20);
      DiffeCut_Depth1_HB->SetMarkerSize(0.4);
      DiffeCut_Depth1_HB->GetZaxis()->SetLabelSize(0.08);
      DiffeCut_Depth1_HB->SetXTitle("#eta \b");
      DiffeCut_Depth1_HB->SetYTitle("#phi \b");
      //    DiffeCut_Depth1_HB->SetZTitle("<TS RMS> out 1.0-2.3 - HB Depth1 \b");
      DiffeCut_Depth1_HB->SetMarkerColor(2);
      DiffeCut_Depth1_HB->SetLineColor(2);
      DiffeCut_Depth1_HB->SetMinimum(1.4);
      DiffeCut_Depth1_HB->SetMaximum(1.8);
      DiffeCut_Depth1_HB->Draw("COLZ");
    ++r1;
  }//r1
 

      c1->Update();
      
      
            
    //======================================================================
    //============================================================================================ end
    //======================================================================
    //======================================================================
    // close and delete all possible things:

    psfile->Close();

//    hfile0->Close();
//    hfile0->Delete();
    hfile1->Close();
    hfile1->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}
