{
   //====================================================================== Amplitude
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
					gStyle->SetOptStat(0);   //  no statistics _or_
			//		        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1100000);//  over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1000000);//  integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1010000);//  und integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229514.root", "READ");
	//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229528.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229621.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229653.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229669.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229672.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229685.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229695.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229699.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229713.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229714.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229715.root", "READ");
//
//
//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234193.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234556.root", "READ");
//
//
//	TFile *hfile1= new TFile("Global_234034.root", "READ");
//
//	TFile *hfile1= new TFile("test.root", "READ"); 
//	TFile *hfile1= new TFile("testNZS.root", "READ"); 


//	TFile *hfile1= new TFile("Global_51.root", "READ");
//	TFile *hfile1= new TFile("Global_235698.root", "READ");

//	TFile *hfile1= new TFile("Global_255031.root", "READ");

//	TFile *hfile1= new TFile("Global_256001.root", "READ");
//	TFile *hfile1= new TFile("Global_256167.root", "READ");
//	TFile *hfile1= new TFile("Global_256348.root", "READ");
//	TFile *hfile1= new TFile("Global_256630.root", "READ");
	TFile *hfile1= new TFile("Global_test.root", "READ");

	//    getchar();
	//
          TPostScript psfile ("zberrorB.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


      TH1F *binni= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      int maxbins = 0;
      int nx = binni->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  binni->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;

    //======================================================================================= 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumErrorBLS1");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("ErrorB in LSs & channels - HB depth1\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      //      aaaaaa6->SetMaximum(1000.);
      aaaaaa6->SetMinimum(0.8);
      aaaaaa6->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS1");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS1");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6= (TH2F*)twod1->Clone("Cefz6");
	Cefz6->Divide(twod1,twod0, 1, 1, "B");
	Cefz6->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("#eta \b");
      Cefz6->SetYTitle("#phi \b");
      Cefz6->SetZTitle("<ErrorB>  - HB Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
      //      Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* qsdr = new TH1F("qsdr","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qsdr->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qsdr->SetMarkerStyle(20);
      qsdr->SetMarkerSize(0.8);
      qsdr->GetYaxis()->SetLabelSize(0.04);
      qsdr->SetXTitle("<ErrorB>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      qsdr->SetMarkerColor(2);
      qsdr->SetLineColor(0);
      qsdr->SetMaximum(0.01);
      qsdr->SetMinimum(0.0001);
      gPad->SetGridy();
      qsdr->Draw("Error");

      c1->Update();




    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumErrorBLS2");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("ErrorB in LSs & channels - HB depth2\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      //      aaaaaa7->SetMaximum(1000.);
      aaaaaa7->SetMinimum(0.8);
      aaaaaa7->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS2");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS2");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7= (TH2F*)twod1->Clone("Cefz7");
	Cefz7->Divide(twod1,twod0, 1, 1, "B");
	Cefz7->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("#eta \b");
      Cefz7->SetYTitle("#phi \b");
      Cefz7->SetZTitle("<ErrorB>  - HB Depth2 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
      //      Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* dfrt = new TH1F("dfrt","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth2_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) dfrt->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      dfrt->SetMarkerStyle(20);
      dfrt->SetMarkerSize(0.8);
      dfrt->GetYaxis()->SetLabelSize(0.04);
      dfrt->SetXTitle("<ErrorB>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      dfrt->SetMarkerColor(2);
      dfrt->SetLineColor(0);
      dfrt->SetMaximum(0.01);
      dfrt->SetMinimum(0.0001);
      gPad->SetGridy();
      dfrt->Draw("Error");

      c1->Update();




    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      qsdr->SetMaximum(0.01);
      qsdr->SetMinimum(0.0001);
      gPad->SetGridy();
      qsdr->Draw("Error");

      c1->cd(2);
      dfrt->SetMaximum(0.01);
      dfrt->SetMinimum(0.0001);
      gPad->SetGridy();
      dfrt->Draw("Error");

      c1->Update();



    //======================================================================================= 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumErrorBLS3");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("ErrorB in LSs & channels - HE depth1\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      //      aaaaaa6->SetMaximum(1000.);
      aaaaaa6->SetMinimum(0.8);
      aaaaaa6->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS3");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS3");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6= (TH2F*)twod1->Clone("Cefz6");
	Cefz6->Divide(twod1,twod0, 1, 1, "B");
	Cefz6->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("#eta \b");
      Cefz6->SetYTitle("#phi \b");
      Cefz6->SetZTitle("<ErrorB>  - HE Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
      //      Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* zder = new TH1F("zder","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) zder->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      zder->SetMarkerStyle(20);
      zder->SetMarkerSize(0.8);
      zder->GetYaxis()->SetLabelSize(0.04);
      zder->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      zder->SetMarkerColor(2);
      zder->SetLineColor(0);
      zder->SetMaximum(0.01);
      zder->SetMinimum(0.0001);
      gPad->SetGridy();
      zder->Draw("Error");

      c1->Update();




    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumErrorBLS4");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("ErrorB in LSs & channels - HE depth2\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      //      aaaaaa7->SetMaximum(1000.);
      aaaaaa7->SetMinimum(0.8);
      aaaaaa7->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS4");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS4");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7= (TH2F*)twod1->Clone("Cefz7");
	Cefz7->Divide(twod1,twod0, 1, 1, "B");
	Cefz7->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("#eta \b");
      Cefz7->SetYTitle("#phi \b");
      Cefz7->SetZTitle("<ErrorB>  - HE Depth2 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
      //      Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS4");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* ouyt = new TH1F("ouyt","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth2_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ouyt->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ouyt->SetMarkerStyle(20);
      ouyt->SetMarkerSize(0.8);
      ouyt->GetYaxis()->SetLabelSize(0.04);
      ouyt->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      ouyt->SetMarkerColor(2);
      ouyt->SetLineColor(0);
      ouyt->SetMaximum(0.01);
      ouyt->SetMinimum(0.0001);
      gPad->SetGridy();
      ouyt->Draw("Error");

      c1->Update();




    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumErrorBLS5");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("ErrorB in LSs & channels - HE depth3\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      //      aaaaaa7->SetMaximum(1000.);
      aaaaaa7->SetMinimum(0.8);
      aaaaaa7->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS5");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS5");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7= (TH2F*)twod1->Clone("Cefz7");
	Cefz7->Divide(twod1,twod0, 1, 1, "B");
	Cefz7->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("#eta \b");
      Cefz7->SetYTitle("#phi \b");
      Cefz7->SetZTitle("<ErrorB>  - HE Depth3 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
      //      Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS5");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* cfre = new TH1F("cfre","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth3_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) cfre->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      cfre->SetMarkerStyle(20);
      cfre->SetMarkerSize(0.8);
      cfre->GetYaxis()->SetLabelSize(0.04);
      cfre->SetXTitle("<ErrorB>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      cfre->SetMarkerColor(2);
      cfre->SetLineColor(0);
      cfre->SetMaximum(0.01);
      cfre->SetMinimum(0.0001);
      gPad->SetGridy();
      cfre->Draw("Error");

      c1->Update();




    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);

      c1->cd(1);
      zder->SetMaximum(0.01);
      zder->SetMinimum(0.0001);
      gPad->SetGridy();
      zder->Draw("Error");

      c1->cd(2);
      ouyt->SetMaximum(0.01);
      ouyt->SetMinimum(0.0001);
      gPad->SetGridy();
      ouyt->Draw("Error");

      c1->cd(3);
      cfre->SetMaximum(0.01);
      cfre->SetMinimum(0.0001);
      gPad->SetGridy();
      cfre->Draw("Error");

      c1->Update();



    //======================================================================================= 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumErrorBLS6");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("ErrorB in LSs & channels - HF depth1\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      //      aaaaaa6->SetMaximum(1000.);
      aaaaaa6->SetMinimum(0.8);
      aaaaaa6->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS6");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS6");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6= (TH2F*)twod1->Clone("Cefz6");
	Cefz6->Divide(twod1,twod0, 1, 1, "B");
	Cefz6->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("#eta \b");
      Cefz6->SetYTitle("#phi \b");
      Cefz6->SetZTitle("<ErrorB>  - HF Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
      //      Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS6");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* lmku = new TH1F("lmku","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) lmku->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      lmku->SetMarkerStyle(20);
      lmku->SetMarkerSize(0.8);
      lmku->GetYaxis()->SetLabelSize(0.04);
      lmku->SetXTitle("<ErrorB>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      lmku->SetMarkerColor(2);
      lmku->SetLineColor(0);
      lmku->SetMaximum(0.01);
      lmku->SetMinimum(0.0001);
      gPad->SetGridy();
      lmku->Draw("Error");

      c1->Update();




    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumErrorBLS7");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("ErrorB in LSs & channels - HF depth2\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      //      aaaaaa7->SetMaximum(1000.);
      aaaaaa7->SetMinimum(0.8);
      aaaaaa7->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS7");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS7");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7= (TH2F*)twod1->Clone("Cefz7");
	Cefz7->Divide(twod1,twod0, 1, 1, "B");
	Cefz7->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7->SetMarkerStyle(20);
      Cefz7->SetMarkerSize(0.4);
      //    Cefz7->GetYaxis()->SetLabelSize(0.04);
      Cefz7->GetZaxis()->SetLabelSize(0.08);
      Cefz7->SetXTitle("#eta \b");
      Cefz7->SetYTitle("#phi \b");
      Cefz7->SetZTitle("<ErrorB>  - HF Depth2 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
      //      Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS7");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* jert = new TH1F("jert","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth2_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) jert->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      jert->SetMarkerStyle(20);
      jert->SetMarkerSize(0.8);
      jert->GetYaxis()->SetLabelSize(0.04);
      jert->SetXTitle("<ErrorB>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      jert->SetMarkerColor(2);
      jert->SetLineColor(0);
      jert->SetMaximum(0.01);
      jert->SetMinimum(0.0001);
      gPad->SetGridy();
      jert->Draw("Error");

      c1->Update();




    //=============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      lmku->SetMaximum(0.01);
      lmku->SetMinimum(0.0001);
      gPad->SetGridy();
      lmku->Draw("Error");

      c1->cd(2);
      jert->SetMaximum(0.01);
      jert->SetMinimum(0.0001);
      gPad->SetGridy();
      jert->Draw("Error");

      c1->Update();



    //======================================================================================= 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumErrorBLS8");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("ErrorB in LSs & channels - HO depth4\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      //      aaaaaa6->SetMaximum(1000.);
      aaaaaa6->SetMinimum(0.8);
      aaaaaa6->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumErrorBLS8");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumErrorBLS8");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6= (TH2F*)twod1->Clone("Cefz6");
	Cefz6->Divide(twod1,twod0, 1, 1, "B");
	Cefz6->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6->SetMarkerStyle(20);
      Cefz6->SetMarkerSize(0.4);
      //    Cefz6->GetYaxis()->SetLabelSize(0.04);
      Cefz6->GetZaxis()->SetLabelSize(0.08);
      Cefz6->SetXTitle("#eta \b");
      Cefz6->SetYTitle("#phi \b");
      Cefz6->SetZTitle("<ErrorB>  - HO Depth4 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
      //      Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumErrorBperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ErrorBperLS8");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      gPad->SetLogy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<ErrorB>(ev.in LS & ch.) - HO depth4 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");

      c1->cd(4);
      TH1F* kuiy = new TH1F("kuiy","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) kuiy->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      kuiy->SetMarkerStyle(20);
      kuiy->SetMarkerSize(0.8);
      kuiy->GetYaxis()->SetLabelSize(0.04);
      kuiy->SetXTitle("<ErrorB>(ev.in LS & ch.) - HO depth4 -    iLS \b");
      kuiy->SetMarkerColor(2);
      kuiy->SetLineColor(0);
      kuiy->SetMaximum(0.01);
      kuiy->SetMinimum(0.0001);
      gPad->SetGridy();
      kuiy->Draw("Error");

      c1->Update();





    //=============================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      kuiy->SetMaximum(0.01);
      kuiy->SetMinimum(0.0001);
      gPad->SetGridy();
      kuiy->Draw("Error");


      c1->Update();





    //======================================================================
    //============================================================================================= end
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
