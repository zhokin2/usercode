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
          TPostScript psfile ("zaerrorA.ps", 111);
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
    //================  h_sumADCAmplperLS1_P1
    //======================================================================

      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1_P1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1_P1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT1 = (TH1F*)twod3->Clone("ERT1");
	ERT1->Divide(twod3,twod2, 1, 1, "B");
	ERT1->Sumw2();
      }
      ERT1->SetMarkerStyle(20);
      ERT1->SetMarkerSize(0.4);
      ERT1->SetXTitle("<A>(ev.in LS & ch.) - HB P1     -    iLS \b");
      ERT1->SetMarkerColor(2);
      ERT1->SetLineColor(0);
      //    ERT1->SetMaximum(110.);
      //    ERT1->SetMinimum(30.0);
      ERT1->Draw("Error");

      c1->cd(2);
      TH1F* rty1 = new TH1F("rty1","", maxbins, 1., maxbins+1.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) rty1->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      rty1->SetMarkerStyle(20);
      rty1->SetMarkerSize(0.4);
      rty1->GetYaxis()->SetLabelSize(0.04);
      rty1->SetXTitle("<ADCAmpl> per LS HB P1 \b");
      rty1->SetMarkerColor(1);
      rty1->SetLineColor(0);
      rty1->SetMaximum(45.0);
      rty1->SetMinimum(25.);
      gPad->SetGridy();
      rty1->Draw("Error");



      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1_P2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1_P2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT2 = (TH1F*)twod3->Clone("ERT2");
	ERT2->Divide(twod3,twod2, 1, 1, "B");
	ERT2->Sumw2();
      }
      ERT2->SetMarkerStyle(20);
      ERT2->SetMarkerSize(0.4);
      ERT2->SetXTitle("<A>(ev.in LS & ch.) - HB P2     -    iLS \b");
      ERT2->SetMarkerColor(2);
      ERT2->SetLineColor(0);
      //    ERT2->SetMaximum(110.);
      //    ERT2->SetMinimum(30.0);
      ERT2->Draw("Error");

      c1->cd(4);
      TH1F* rty2 = new TH1F("rty2","", maxbins, 1., maxbins+1.);
      int nx = ERT2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) rty2->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      rty2->SetMarkerStyle(20);
      rty2->SetMarkerSize(0.4);
      rty2->GetYaxis()->SetLabelSize(0.04);
      rty2->SetXTitle("<ADCAmpl> per LS HB P2 \b");
      rty2->SetMarkerColor(2);
      rty2->SetLineColor(0);
      rty2->SetMaximum(45.0);
      rty2->SetMinimum(25.);
      gPad->SetGridy();
      rty2->Draw("Error");



      c1->cd(5);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1_M1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1_M1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT3 = (TH1F*)twod3->Clone("ERT3");
	ERT3->Divide(twod3,twod2, 1, 1, "B");
	ERT3->Sumw2();
      }
      ERT3->SetMarkerStyle(20);
      ERT3->SetMarkerSize(0.4);
      ERT3->SetXTitle("<A>(ev.in LS & ch.) - HB M1     -    iLS \b");
      ERT3->SetMarkerColor(2);
      ERT3->SetLineColor(0);
      //    ERT3->SetMaximum(110.);
      //    ERT3->SetMinimum(30.0);
      ERT3->Draw("Error");

      c1->cd(6);
      TH1F* rty3 = new TH1F("rty3","", maxbins, 1., maxbins+1.);
      int nx = ERT3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) rty3->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      rty3->SetMarkerStyle(20);
      rty3->SetMarkerSize(0.4);
      rty3->GetYaxis()->SetLabelSize(0.04);
      rty3->SetXTitle("<ADCAmpl> per LS HF M1 \b");
      rty3->SetMarkerColor(3);
      rty3->SetLineColor(0);
      rty3->SetMaximum(45.0);
      rty3->SetMinimum(25.);
      gPad->SetGridy();
      rty3->Draw("Error");



      c1->cd(7);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1_M2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1_M2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT4 = (TH1F*)twod3->Clone("ERT4");
	ERT4->Divide(twod3,twod2, 1, 1, "B");
	ERT4->Sumw2();
      }
      ERT4->SetMarkerStyle(20);
      ERT4->SetMarkerSize(0.4);
      ERT4->SetXTitle("<A>(ev.in LS & ch.) - HB M2     -    iLS \b");
      ERT4->SetMarkerColor(2);
      ERT4->SetLineColor(0);
      //    ERT4->SetMaximum(110.);
      //    ERT4->SetMinimum(30.0);
      ERT4->Draw("Error");

      c1->cd(8);
      TH1F* rty4 = new TH1F("rty4","", maxbins, 1., maxbins+1.);
      int nx = ERT4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) rty4->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      rty4->SetMarkerStyle(20);
      rty4->SetMarkerSize(0.4);
      rty4->GetYaxis()->SetLabelSize(0.04);
      rty4->SetXTitle("<ADCAmpl> per LS HB M2 \b");
      rty4->SetMarkerColor(4);
      rty4->SetLineColor(0);
      rty4->SetMaximum(45.0);
      rty4->SetMinimum(25.);
      gPad->SetGridy();
      rty4->Draw("Error");


      c1->Update();



    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      rty1->SetXTitle("<ADCAmpl> per LS HB:black- P1,red-P2,green-M1,blue-M2 \b");
      rty1->SetMaximum(34.0);
      rty1->SetMinimum(24.);
      rty2->SetMaximum(34.0);
      rty2->SetMinimum(24.);
      rty3->SetMaximum(34.0);
      rty3->SetMinimum(24.);
      rty4->SetMaximum(34.0);
      rty4->SetMinimum(24.);
rty1->SetMarkerSize(0.4);
rty2->SetMarkerSize(0.4);
rty3->SetMarkerSize(0.4);
rty4->SetMarkerSize(0.4);

      rty1->SetLineColor(1);
      rty2->SetLineColor(2);
      rty3->SetLineColor(3);
      rty4->SetLineColor(4);

//      rty1->Draw("Error");
//      rty2->Draw("ErrorSame");
//      rty3->Draw("ErrorSame");
//      rty4->Draw("ErrorSame");

      gPad->SetGridy();
      rty1->Draw("");
      rty2->Draw("Same");
      rty3->Draw("Same");
      rty4->Draw("Same");


      c1->cd(2);
      TH1F* diff = new TH1F("diff","", 100, 0., 1.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	double ccc2 =  ERT2->GetBinContent(i);
	double ccc3 =  ERT3->GetBinContent(i);
	double ccc4 =  ERT4->GetBinContent(i);
	if(ccc1 > 0. ) {
	  double delta = ccc1-ccc2;
	  delta = fabs(delta);
	  if(fabs(ccc1-ccc3) > delta ) delta=fabs(ccc1-ccc3);
	  if(fabs(ccc1-ccc4) > delta ) delta=fabs(ccc1-ccc4);
	  if(fabs(ccc2-ccc3) > delta ) delta=fabs(ccc2-ccc3);
	  if(fabs(ccc2-ccc4) > delta ) delta=fabs(ccc2-ccc4);
	  if(fabs(ccc3-ccc4) > delta ) delta=fabs(ccc3-ccc4);
	  
	  diff->Fill(delta);
	}
      }
      diff->SetMarkerStyle(20);
      diff->SetMarkerSize(0.8);
      diff->SetXTitle("max difference HB \b");
      diff->SetMarkerColor(2);
      diff->SetLineColor(0);
      //    diff->SetMaximum(110.);
          diff->SetMinimum(0.8);
      gPad->SetGridx();
      gPad->SetLogy();
      diff->Draw("Error");
      
      
      c1->Update();


    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      rty1->SetXTitle("<ADCAmpl> per LS HB:black- P1,red-P2,green-M1,blue-M2 \b");
      rty1->SetMaximum(60.0);
      rty1->SetMinimum(0.);
      rty2->SetMaximum(60.0);
      rty2->SetMinimum(0.);
      rty3->SetMaximum(60.0);
      rty3->SetMinimum(0.);
      rty4->SetMaximum(60.0);
      rty4->SetMinimum(0.);
rty1->SetMarkerSize(0.4);
rty2->SetMarkerSize(0.4);
rty3->SetMarkerSize(0.4);
rty4->SetMarkerSize(0.4);

//      rty1->SetLineColor(0);
//      rty2->SetLineColor(0);
//      rty3->SetLineColor(0);
//      rty4->SetLineColor(0);

//      rty1->Draw("Error");
//      rty2->Draw("ErrorSame");
//      rty3->Draw("ErrorSame");
//      rty4->Draw("ErrorSame");

      gPad->SetGridy();
      rty1->Draw("");
      rty2->Draw("Same");
      rty3->Draw("Same");
      rty4->Draw("Same");

      c1->Update();
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);


      rty1->SetXTitle("<ADCAmpl> per LS HB:black- P1,red-P2,green-M1,blue-M2 \b");
      rty1->SetMaximum(44.0);
      rty1->SetMinimum(20.);
      rty2->SetMaximum(44.0);
      rty2->SetMinimum(20.);
      rty3->SetMaximum(44.0);
      rty3->SetMinimum(20.);
      rty4->SetMaximum(44.0);
      rty4->SetMinimum(20.);
      rty1->SetLineColor(0);
      rty2->SetLineColor(0);
      rty3->SetLineColor(0);
      rty4->SetLineColor(0);

      c1->cd(1);
      gPad->SetGridy();
      rty1->Draw("Error");
      c1->cd(2);
      gPad->SetGridy();
      rty2->Draw("Error");
      c1->cd(3);
      gPad->SetGridy();
      rty3->Draw("Error");
      c1->cd(4);
      gPad->SetGridy();
      rty4->Draw("Error");


      c1->Update();


    //======================================================================================= 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3_P1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3_P1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT1 = (TH1F*)twod3->Clone("ERT1");
	ERT1->Divide(twod3,twod2, 1, 1, "B");
	ERT1->Sumw2();
      }
      ERT1->SetMarkerStyle(20);
      ERT1->SetMarkerSize(0.4);
      ERT1->SetXTitle("<A>(ev.in LS & ch.) - HE P1     -    iLS \b");
      ERT1->SetMarkerColor(2);
      ERT1->SetLineColor(0);
      //    ERT1->SetMaximum(110.);
      //    ERT1->SetMinimum(30.0);
      ERT1->Draw("Error");

      c1->cd(2);
      TH1F* hee1 = new TH1F("hee1","", maxbins, 1., maxbins+1.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hee1->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hee1->SetMarkerStyle(20);
      hee1->SetMarkerSize(0.4);
      hee1->GetYaxis()->SetLabelSize(0.04);
      hee1->SetXTitle("<ADCAmpl> per LS HF P1 \b");
      hee1->SetMarkerColor(1);
      hee1->SetLineColor(0);
      hee1->SetMaximum(45.0);
      hee1->SetMinimum(35.);
      gPad->SetGridy();
      hee1->Draw("Error");



      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3_P2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3_P2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT2 = (TH1F*)twod3->Clone("ERT2");
	ERT2->Divide(twod3,twod2, 1, 1, "B");
	ERT2->Sumw2();
      }
      ERT2->SetMarkerStyle(20);
      ERT2->SetMarkerSize(0.4);
      ERT2->SetXTitle("<A>(ev.in LS & ch.) - HE P2     -    iLS \b");
      ERT2->SetMarkerColor(2);
      ERT2->SetLineColor(0);
      //    ERT2->SetMaximum(110.);
      //    ERT2->SetMinimum(30.0);
      ERT2->Draw("Error");

      c1->cd(4);
      TH1F* hee2 = new TH1F("hee2","", maxbins, 1., maxbins+1.);
      int nx = ERT2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hee2->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hee2->SetMarkerStyle(20);
      hee2->SetMarkerSize(0.4);
      hee2->GetYaxis()->SetLabelSize(0.04);
      hee2->SetXTitle("<ADCAmpl> per LS HE P2 \b");
      hee2->SetMarkerColor(2);
      hee2->SetLineColor(0);
      hee2->SetMaximum(45.0);
      hee2->SetMinimum(35.);
      gPad->SetGridy();
      hee2->Draw("Error");



      c1->cd(5);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3_M1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3_M1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT3 = (TH1F*)twod3->Clone("ERT3");
	ERT3->Divide(twod3,twod2, 1, 1, "B");
	ERT3->Sumw2();
      }
      ERT3->SetMarkerStyle(20);
      ERT3->SetMarkerSize(0.4);
      ERT3->SetXTitle("<A>(ev.in LS & ch.) - HE M1     -    iLS \b");
      ERT3->SetMarkerColor(2);
      ERT3->SetLineColor(0);
      //    ERT3->SetMaximum(110.);
      //    ERT3->SetMinimum(30.0);
      ERT3->Draw("Error");

      c1->cd(6);
      TH1F* hee3 = new TH1F("hee3","", maxbins, 1., maxbins+1.);
      int nx = ERT3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hee3->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hee3->SetMarkerStyle(20);
      hee3->SetMarkerSize(0.4);
      hee3->GetYaxis()->SetLabelSize(0.04);
      hee3->SetXTitle("<ADCAmpl> per LS HE M1 \b");
      hee3->SetMarkerColor(3);
      hee3->SetLineColor(0);
      hee3->SetMaximum(45.0);
      hee3->SetMinimum(35.);
      gPad->SetGridy();
      hee3->Draw("Error");



      c1->cd(7);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3_M2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3_M2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT4 = (TH1F*)twod3->Clone("ERT4");
	ERT4->Divide(twod3,twod2, 1, 1, "B");
	ERT4->Sumw2();
      }
      ERT4->SetMarkerStyle(20);
      ERT4->SetMarkerSize(0.4);
      ERT4->SetXTitle("<A>(ev.in LS & ch.) - HE M2     -    iLS \b");
      ERT4->SetMarkerColor(2);
      ERT4->SetLineColor(0);
      //    ERT4->SetMaximum(110.);
      //    ERT4->SetMinimum(30.0);
      ERT4->Draw("Error");

      c1->cd(8);
      TH1F* hee4 = new TH1F("hee4","", maxbins, 1., maxbins+1.);
      int nx = ERT4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hee4->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hee4->SetMarkerStyle(20);
      hee4->SetMarkerSize(0.4);
      hee4->GetYaxis()->SetLabelSize(0.04);
      hee4->SetXTitle("<ADCAmpl> per LS HE M2 \b");
      hee4->SetMarkerColor(4);
      hee4->SetLineColor(0);
      hee4->SetMaximum(45.0);
      hee4->SetMinimum(35.);
      gPad->SetGridy();
      hee4->Draw("Error");


      c1->Update();



    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      hee1->SetXTitle("<ADCAmpl> per LS HE:black- P1,red-P2,green-M1,blue-M2 \b");
      hee1->SetMaximum(48.0);
      hee1->SetMinimum(32.);
      hee2->SetMaximum(48.0);
      hee2->SetMinimum(32.);
      hee3->SetMaximum(48.0);
      hee3->SetMinimum(32.);
      hee4->SetMaximum(48.0);
      hee4->SetMinimum(32.);
hee1->SetMarkerSize(0.4);
hee2->SetMarkerSize(0.4);
hee3->SetMarkerSize(0.4);
hee4->SetMarkerSize(0.4);

      hee1->SetLineColor(1);
      hee2->SetLineColor(2);
      hee3->SetLineColor(3);
      hee4->SetLineColor(4);

//      hee1->Draw("Error");
//      hee2->Draw("ErrorSame");
//      hee3->Draw("ErrorSame");
//      hee4->Draw("ErrorSame");

      gPad->SetGridy();
      hee1->Draw("");
      hee2->Draw("Same");
      hee3->Draw("Same");
      hee4->Draw("Same");


      c1->cd(2);
      TH1F* heef = new TH1F("heef","", 100, 0., 4.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	double ccc2 =  ERT2->GetBinContent(i);
	double ccc3 =  ERT3->GetBinContent(i);
	double ccc4 =  ERT4->GetBinContent(i);
	if(ccc1 > 0. ) {
	  double delta = ccc1-ccc2;
	  delta = fabs(delta);
	  if(fabs(ccc1-ccc3) > delta ) delta=fabs(ccc1-ccc3);
	  if(fabs(ccc1-ccc4) > delta ) delta=fabs(ccc1-ccc4);
	  if(fabs(ccc2-ccc3) > delta ) delta=fabs(ccc2-ccc3);
	  if(fabs(ccc2-ccc4) > delta ) delta=fabs(ccc2-ccc4);
	  if(fabs(ccc3-ccc4) > delta ) delta=fabs(ccc3-ccc4);
	  
	  heef->Fill(delta);
	}
      }
      heef->SetMarkerStyle(20);
      heef->SetMarkerSize(0.8);
      heef->SetXTitle("max difference HE\b");
      heef->SetMarkerColor(2);
      heef->SetLineColor(0);
      //    heef->SetMaximum(110.);
      //    heef->SetMinimum(30.0);
      gPad->SetGridx();
      gPad->SetLogy();
      heef->Draw("Error");
      
      
      c1->Update();


    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      hee1->SetXTitle("<ADCAmpl> per LS HE:black- P1,red-P2,green-M1,blue-M2 \b");
      hee1->SetMaximum(60.0);
      hee1->SetMinimum(0.);
      hee2->SetMaximum(60.0);
      hee2->SetMinimum(0.);
      hee3->SetMaximum(60.0);
      hee3->SetMinimum(0.);
      hee4->SetMaximum(60.0);
      hee4->SetMinimum(0.);
hee1->SetMarkerSize(0.4);
hee2->SetMarkerSize(0.4);
hee3->SetMarkerSize(0.4);
hee4->SetMarkerSize(0.4);

//      hee1->SetLineColor(0);
//      hee2->SetLineColor(0);
//      hee3->SetLineColor(0);
//      hee4->SetLineColor(0);

//      hee1->Draw("Error");
//      hee2->Draw("ErrorSame");
//      hee3->Draw("ErrorSame");
//      hee4->Draw("ErrorSame");

      gPad->SetGridy();
      hee1->Draw("");
      hee2->Draw("Same");
      hee3->Draw("Same");
      hee4->Draw("Same");

      c1->Update();
    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);


      hee1->SetXTitle("<ADCAmpl> per LS HE:black- P1,red-P2,green-M1,blue-M2 \b");
      hee1->SetMaximum(44.0);
      hee1->SetMinimum(29.);
      hee2->SetMaximum(44.0);
      hee2->SetMinimum(29.);
      hee3->SetMaximum(44.0);
      hee3->SetMinimum(29.);
      hee4->SetMaximum(44.0);
      hee4->SetMinimum(29.);
      hee1->SetLineColor(0);
      hee2->SetLineColor(0);
      hee3->SetLineColor(0);
      hee4->SetLineColor(0);

      c1->cd(1);
      gPad->SetGridy();
      hee1->Draw("Error");
      c1->cd(2);
      gPad->SetGridy();
      hee2->Draw("Error");
      c1->cd(3);
      gPad->SetGridy();
      hee3->Draw("Error");
      c1->cd(4);
      gPad->SetGridy();
      hee4->Draw("Error");


      c1->Update();


    //======================================================================================= 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6_P1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6_P1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT1 = (TH1F*)twod3->Clone("ERT1");
	ERT1->Divide(twod3,twod2, 1, 1, "B");
	ERT1->Sumw2();
      }
      ERT1->SetMarkerStyle(20);
      ERT1->SetMarkerSize(0.4);
      ERT1->SetXTitle("<A>(ev.in LS & ch.) - HF P1     -    iLS \b");
      ERT1->SetMarkerColor(2);
      ERT1->SetLineColor(0);
      //    ERT1->SetMaximum(110.);
      //    ERT1->SetMinimum(30.0);
      ERT1->Draw("Error");

      c1->cd(2);
      TH1F* hf11 = new TH1F("hf11","", maxbins, 1., maxbins+1.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hf11->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hf11->SetMarkerStyle(20);
      hf11->SetMarkerSize(0.4);
      hf11->GetYaxis()->SetLabelSize(0.04);
      hf11->SetXTitle("<ADCAmpl> per LS HF P1 \b");
      hf11->SetMarkerColor(1);
      hf11->SetLineColor(0);
      hf11->SetMaximum(45.0);
      hf11->SetMinimum(30.);
      gPad->SetGridy();
      hf11->Draw("Error");



      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6_P2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6_P2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT2 = (TH1F*)twod3->Clone("ERT2");
	ERT2->Divide(twod3,twod2, 1, 1, "B");
	ERT2->Sumw2();
      }
      ERT2->SetMarkerStyle(20);
      ERT2->SetMarkerSize(0.4);
      ERT2->SetXTitle("<A>(ev.in LS & ch.) - HF P2     -    iLS \b");
      ERT2->SetMarkerColor(2);
      ERT2->SetLineColor(0);
      //    ERT2->SetMaximum(110.);
      //    ERT2->SetMinimum(30.0);
      ERT2->Draw("Error");

      c1->cd(4);
      TH1F* hf12 = new TH1F("hf12","", maxbins, 1., maxbins+1.);
      int nx = ERT2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hf12->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hf12->SetMarkerStyle(20);
      hf12->SetMarkerSize(0.4);
      hf12->GetYaxis()->SetLabelSize(0.04);
      hf12->SetXTitle("<ADCAmpl> per LS HF P2 \b");
      hf12->SetMarkerColor(2);
      hf12->SetLineColor(0);
      hf12->SetMaximum(45.0);
      hf12->SetMinimum(30.);
      gPad->SetGridy();
      hf12->Draw("Error");



      c1->cd(5);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6_M1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6_M1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT3 = (TH1F*)twod3->Clone("ERT3");
	ERT3->Divide(twod3,twod2, 1, 1, "B");
	ERT3->Sumw2();
      }
      ERT3->SetMarkerStyle(20);
      ERT3->SetMarkerSize(0.4);
      ERT3->SetXTitle("<A>(ev.in LS & ch.) - HF M1     -    iLS \b");
      ERT3->SetMarkerColor(2);
      ERT3->SetLineColor(0);
      //    ERT3->SetMaximum(110.);
      //    ERT3->SetMinimum(30.0);
      ERT3->Draw("Error");

      c1->cd(6);
      TH1F* hf13 = new TH1F("hf13","", maxbins, 1., maxbins+1.);
      int nx = ERT3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hf13->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hf13->SetMarkerStyle(20);
      hf13->SetMarkerSize(0.4);
      hf13->GetYaxis()->SetLabelSize(0.04);
      hf13->SetXTitle("<ADCAmpl> per LS HF M1 \b");
      hf13->SetMarkerColor(3);
      hf13->SetLineColor(0);
      hf13->SetMaximum(45.0);
      hf13->SetMinimum(30.);
      gPad->SetGridy();
      hf13->Draw("Error");



      c1->cd(7);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6_M2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6_M2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* ERT4 = (TH1F*)twod3->Clone("ERT4");
	ERT4->Divide(twod3,twod2, 1, 1, "B");
	ERT4->Sumw2();
      }
      ERT4->SetMarkerStyle(20);
      ERT4->SetMarkerSize(0.4);
      ERT4->SetXTitle("<A>(ev.in LS & ch.) - HF M2     -    iLS \b");
      ERT4->SetMarkerColor(2);
      ERT4->SetLineColor(0);
      //    ERT4->SetMaximum(110.);
      //    ERT4->SetMinimum(30.0);
      ERT4->Draw("Error");

      c1->cd(8);
      TH1F* hf14 = new TH1F("hf14","", maxbins, 1., maxbins+1.);
      int nx = ERT4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) hf14->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      hf14->SetMarkerStyle(20);
      hf14->SetMarkerSize(0.4);
      hf14->GetYaxis()->SetLabelSize(0.04);
      hf14->SetXTitle("<ADCAmpl> per LS HF M2 \b");
      hf14->SetMarkerColor(4);
      hf14->SetLineColor(0);
      hf14->SetMaximum(45.0);
      hf14->SetMinimum(30.);
      gPad->SetGridy();
      hf14->Draw("Error");


      c1->Update();



    //=============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      hf11->SetXTitle("<ADCAmpl> per LS HF:black- P1,red-P2,green-M1,blue-M2 \b");
      hf11->SetMaximum(42.0);
      hf11->SetMinimum(30.);
      hf12->SetMaximum(42.0);
      hf12->SetMinimum(30.);
      hf13->SetMaximum(42.0);
      hf13->SetMinimum(30.);
      hf14->SetMaximum(42.0);
      hf14->SetMinimum(30.);
hf11->SetMarkerSize(0.4);
hf12->SetMarkerSize(0.4);
hf13->SetMarkerSize(0.4);
hf14->SetMarkerSize(0.4);

      hf11->SetLineColor(1);
      hf12->SetLineColor(2);
      hf13->SetLineColor(3);
      hf14->SetLineColor(4);

//      hf11->Draw("Error");
//      hf12->Draw("ErrorSame");
//      hf13->Draw("ErrorSame");
//      hf14->Draw("ErrorSame");

      gPad->SetGridy();
      hf11->Draw("");
      hf12->Draw("Same");
      hf13->Draw("Same");
      hf14->Draw("Same");


      c1->cd(2);
      TH1F* hf1f = new TH1F("hf1f","", 100, 0., 4.);
      int nx = ERT1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ERT1->GetBinContent(i);
	double ccc2 =  ERT2->GetBinContent(i);
	double ccc3 =  ERT3->GetBinContent(i);
	double ccc4 =  ERT4->GetBinContent(i);
	if(ccc1 > 0. ) {
	  double delta = ccc1-ccc2;
	  delta = fabs(delta);
	  if(fabs(ccc1-ccc3) > delta ) delta=fabs(ccc1-ccc3);
	  if(fabs(ccc1-ccc4) > delta ) delta=fabs(ccc1-ccc4);
	  if(fabs(ccc2-ccc3) > delta ) delta=fabs(ccc2-ccc3);
	  if(fabs(ccc2-ccc4) > delta ) delta=fabs(ccc2-ccc4);
	  if(fabs(ccc3-ccc4) > delta ) delta=fabs(ccc3-ccc4);
	  
	  hf1f->Fill(delta);
	}
      }
      hf1f->SetMarkerStyle(20);
      hf1f->SetMarkerSize(0.8);
      hf1f->SetXTitle("max difference HF\b");
      hf1f->SetMarkerColor(2);
      hf1f->SetLineColor(0);
      //    hf1f->SetMaximum(110.);
      //    hf1f->SetMinimum(30.0);
      gPad->SetGridx();
      gPad->SetLogy();
      hf1f->Draw("Error");
      
      
      c1->Update();


    //=============================================================================================== 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      hf11->SetXTitle("<ADCAmpl> per LS HF:black- P1,red-P2,green-M1,blue-M2 \b");
      hf11->SetMaximum(60.0);
      hf11->SetMinimum(0.);
      hf12->SetMaximum(60.0);
      hf12->SetMinimum(0.);
      hf13->SetMaximum(60.0);
      hf13->SetMinimum(0.);
      hf14->SetMaximum(60.0);
      hf14->SetMinimum(0.);
hf11->SetMarkerSize(0.4);
hf12->SetMarkerSize(0.4);
hf13->SetMarkerSize(0.4);
hf14->SetMarkerSize(0.4);

//      hf11->SetLineColor(0);
//      hf12->SetLineColor(0);
//      hf13->SetLineColor(0);
//      hf14->SetLineColor(0);

//      hf11->Draw("Error");
//      hf12->Draw("ErrorSame");
//      hf13->Draw("ErrorSame");
//      hf14->Draw("ErrorSame");

      gPad->SetGridy();
      hf11->Draw("");
      hf12->Draw("Same");
      hf13->Draw("Same");
      hf14->Draw("Same");

      c1->Update();
    //=============================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);


      hf11->SetXTitle("<ADCAmpl> per LS HF:black- P1,red-P2,green-M1,blue-M2 \b");
      hf11->SetMaximum(44.0);
      hf11->SetMinimum(29.);
      hf12->SetMaximum(44.0);
      hf12->SetMinimum(29.);
      hf13->SetMaximum(44.0);
      hf13->SetMinimum(29.);
      hf14->SetMaximum(44.0);
      hf14->SetMinimum(29.);
      hf11->SetLineColor(0);
      hf12->SetLineColor(0);
      hf13->SetLineColor(0);
      hf14->SetLineColor(0);

      c1->cd(1);
      gPad->SetGridy();
      hf11->Draw("Error");
      c1->cd(2);
      gPad->SetGridy();
      hf12->Draw("Error");
      c1->cd(3);
      gPad->SetGridy();
      hf13->Draw("Error");
      c1->cd(4);
      gPad->SetGridy();
      hf14->Draw("Error");


      c1->Update();


    //======================================================================================= 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8_P1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8_P1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* HOO1 = (TH1F*)twod3->Clone("HOO1");
	HOO1->Divide(twod3,twod2, 1, 1, "B");
	HOO1->Sumw2();
      }
      HOO1->SetMarkerStyle(20);
      HOO1->SetMarkerSize(0.4);
      HOO1->SetXTitle("<A>(ev.in LS & ch.) - HO P1     -    iLS \b");
      HOO1->SetMarkerColor(2);
      HOO1->SetLineColor(0);
      //    HOO1->SetMaximum(110.);
      //    HOO1->SetMinimum(30.0);
      HOO1->Draw("Error");

      c1->cd(2);
      TH1F* ho41 = new TH1F("ho41","", maxbins, 1., maxbins+1.);
      int nx = HOO1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  HOO1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ho41->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ho41->SetMarkerStyle(20);
      ho41->SetMarkerSize(0.4);
      ho41->GetYaxis()->SetLabelSize(0.04);
      ho41->SetXTitle("<ADCAmpl> per LS HF P1 \b");
      ho41->SetMarkerColor(1);
      ho41->SetLineColor(0);
      ho41->SetMaximum(200.);
      ho41->SetMinimum(0.);
      gPad->SetGridy();
      ho41->Draw("Error");



      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8_P2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8_P2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* HOO2 = (TH1F*)twod3->Clone("HOO2");
	HOO2->Divide(twod3,twod2, 1, 1, "B");
	HOO2->Sumw2();
      }
      HOO2->SetMarkerStyle(20);
      HOO2->SetMarkerSize(0.4);
      HOO2->SetXTitle("<A>(ev.in LS & ch.) - HO P2     -    iLS \b");
      HOO2->SetMarkerColor(2);
      HOO2->SetLineColor(0);
      //    HOO2->SetMaximum(110.);
      //    HOO2->SetMinimum(30.0);
      HOO2->Draw("Error");

      c1->cd(4);
      TH1F* ho42 = new TH1F("ho42","", maxbins, 1., maxbins+1.);
      int nx = HOO2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  HOO2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ho42->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ho42->SetMarkerStyle(20);
      ho42->SetMarkerSize(0.4);
      ho42->GetYaxis()->SetLabelSize(0.04);
      ho42->SetXTitle("<ADCAmpl> per LS HO P2 \b");
      ho42->SetMarkerColor(2);
      ho42->SetLineColor(0);
      ho42->SetMaximum(200.);
      ho42->SetMinimum(0.);
      gPad->SetGridy();
      ho42->Draw("Error");



      c1->cd(5);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8_M1" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8_M1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* HOO3 = (TH1F*)twod3->Clone("HOO3");
	HOO3->Divide(twod3,twod2, 1, 1, "B");
	HOO3->Sumw2();
      }
      HOO3->SetMarkerStyle(20);
      HOO3->SetMarkerSize(0.4);
      HOO3->SetXTitle("<A>(ev.in LS & ch.) - HO M1     -    iLS \b");
      HOO3->SetMarkerColor(2);
      HOO3->SetLineColor(0);
      //    HOO3->SetMaximum(110.);
      //    HOO3->SetMinimum(30.0);
      HOO3->Draw("Error");

      c1->cd(6);
      TH1F* ho43 = new TH1F("ho43","", maxbins, 1., maxbins+1.);
      int nx = HOO3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  HOO3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ho43->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ho43->SetMarkerStyle(20);
      ho43->SetMarkerSize(0.4);
      ho43->GetYaxis()->SetLabelSize(0.04);
      ho43->SetXTitle("<ADCAmpl> per LS HO M1 \b");
      ho43->SetMarkerColor(3);
      ho43->SetLineColor(0);
      ho43->SetMaximum(200.);
      ho43->SetMinimum(0.);
      gPad->SetGridy();
      ho43->Draw("Error");



      c1->cd(7);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8_M2" );
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8_M2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* HOO4 = (TH1F*)twod3->Clone("HOO4");
	HOO4->Divide(twod3,twod2, 1, 1, "B");
	HOO4->Sumw2();
      }
      HOO4->SetMarkerStyle(20);
      HOO4->SetMarkerSize(0.4);
      HOO4->SetXTitle("<A>(ev.in LS & ch.) - HO M2     -    iLS \b");
      HOO4->SetMarkerColor(2);
      HOO4->SetLineColor(0);
      //    HOO4->SetMaximum(110.);
      //    HOO4->SetMinimum(30.0);
      HOO4->Draw("Error");

      c1->cd(8);
      TH1F* ho44 = new TH1F("ho44","", maxbins, 1., maxbins+1.);
      int nx = HOO4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  HOO4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ho44->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ho44->SetMarkerStyle(20);
      ho44->SetMarkerSize(0.4);
      ho44->GetYaxis()->SetLabelSize(0.04);
      ho44->SetXTitle("<ADCAmpl> per LS HO M2 \b");
      ho44->SetMarkerColor(4);
      ho44->SetLineColor(0);
      ho44->SetMaximum(200.);
      ho44->SetMinimum(0.);
      gPad->SetGridy();
      ho44->Draw("Error");


      c1->Update();



    //=============================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      ho41->SetXTitle("<ADCAmpl> per LS HO:black- P1,red-P2,green-M1,blue-M2 \b");
      ho41->SetMaximum(100.0);
      ho41->SetMinimum(90.);
      ho42->SetMaximum(100.0);
      ho42->SetMinimum(90.);
      ho43->SetMaximum(100.0);
      ho43->SetMinimum(90.);
      ho44->SetMaximum(100.0);
      ho44->SetMinimum(90.);
ho41->SetMarkerSize(0.4);
ho42->SetMarkerSize(0.4);
ho43->SetMarkerSize(0.4);
ho44->SetMarkerSize(0.4);

      ho41->SetLineColor(1);
      ho42->SetLineColor(2);
      ho43->SetLineColor(3);
      ho44->SetLineColor(4);

//      ho41->Draw("Error");
//      ho42->Draw("ErrorSame");
//      ho43->Draw("ErrorSame");
//      ho44->Draw("ErrorSame");

      gPad->SetGridy();
      ho41->Draw("");
      ho42->Draw("Same");
      ho43->Draw("Same");
      ho44->Draw("Same");


      c1->cd(2);
      TH1F* ho4f = new TH1F("ho4f","", 100, 0., 4.);
      int nx = HOO1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  HOO1->GetBinContent(i);
	double ccc2 =  HOO2->GetBinContent(i);
	double ccc3 =  HOO3->GetBinContent(i);
	double ccc4 =  HOO4->GetBinContent(i);
	if(ccc1 > 0. ) {
	  double delta = ccc1-ccc2;
	  delta = fabs(delta);
	  if(fabs(ccc1-ccc3) > delta ) delta=fabs(ccc1-ccc3);
	  if(fabs(ccc1-ccc4) > delta ) delta=fabs(ccc1-ccc4);
	  if(fabs(ccc2-ccc3) > delta ) delta=fabs(ccc2-ccc3);
	  if(fabs(ccc2-ccc4) > delta ) delta=fabs(ccc2-ccc4);
	  if(fabs(ccc3-ccc4) > delta ) delta=fabs(ccc3-ccc4);
	  
	  ho4f->Fill(delta);
	}
      }
      ho4f->SetMarkerStyle(20);
      ho4f->SetMarkerSize(0.8);
      ho4f->SetXTitle("max difference HO\b");
      ho4f->SetMarkerColor(2);
      ho4f->SetLineColor(0);
      //    ho4f->SetMaximum(110.);
      //    ho4f->SetMinimum(30.0);
      gPad->SetGridx();
      gPad->SetLogy();
      ho4f->Draw("Error");
      
      
      c1->Update();


    //=============================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);

      ho41->SetXTitle("<ADCAmpl> per LS HO:black- P1,red-P2,green-M1,blue-M2 \b");
      ho41->SetMaximum(200.0);
      ho41->SetMinimum(0.);
      ho42->SetMaximum(200.0);
      ho42->SetMinimum(0.);
      ho43->SetMaximum(200.0);
      ho43->SetMinimum(0.);
      ho44->SetMaximum(200.0);
      ho44->SetMinimum(0.);
ho41->SetMarkerSize(0.4);
ho42->SetMarkerSize(0.4);
ho43->SetMarkerSize(0.4);
ho44->SetMarkerSize(0.4);

//      ho41->SetLineColor(0);
//      ho42->SetLineColor(0);
//      ho43->SetLineColor(0);
//      ho44->SetLineColor(0);

//      ho41->Draw("Error");
//      ho42->Draw("ErrorSame");
//      ho43->Draw("ErrorSame");
//      ho44->Draw("ErrorSame");

      gPad->SetGridy();
      ho41->Draw("");
      ho42->Draw("Same");
      ho43->Draw("Same");
      ho44->Draw("Same");

      c1->Update();
    //=============================================================================================== 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);


      ho41->SetXTitle("<ADCAmpl> per LS HO:black- P1,red-P2,green-M1,blue-M2 \b");
      ho41->SetMaximum(200.0);
      ho41->SetMinimum(0.);
      ho42->SetMaximum(200.0);
      ho42->SetMinimum(0.);
      ho43->SetMaximum(200.0);
      ho43->SetMinimum(0.);
      ho44->SetMaximum(200.0);
      ho44->SetMinimum(0.);
      ho41->SetLineColor(0);
      ho42->SetLineColor(0);
      ho43->SetLineColor(0);
      ho44->SetLineColor(0);

      c1->cd(1);
      gPad->SetGridy();
      ho41->Draw("Error");
      c1->cd(2);
      gPad->SetGridy();
      ho42->Draw("Error");
      c1->cd(3);
      gPad->SetGridy();
      ho43->Draw("Error");
      c1->cd(4);
      gPad->SetGridy();
      ho44->Draw("Error");


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
