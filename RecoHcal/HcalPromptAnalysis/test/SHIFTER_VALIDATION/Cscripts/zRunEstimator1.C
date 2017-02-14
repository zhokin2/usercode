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
				//			gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
          TPostScript psfile ("zRunEstimator1.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //======================================================================================= 1
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
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz1= (TH2F*)twod1->Clone("Cefz1");
	Cefz1->Divide(twod1,twod0, 1, 1, "B");
	Cefz1->Sumw2();
      }
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
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //      Rate2->SetMaximum(1000.);
      //      Rate2->SetMinimum(960.);
//            Rate2->SetMaximum(28.);
//            Rate2->SetMinimum(24.);
      Rate2->Draw("Error");
//      int nx = Rate2->GetXaxis()->GetNbins();
//      cout<<" Max # iLS = "<< nx <<endl;
//      int icount0=0;
//      int icount=0;
//      for (int i=1;i<=nx;i++) {
//	double ccc1 =  Rate2->GetBinContent(i)   ;
//	if(ccc1>0.) icount0++;
//	if(ccc1>0.) {
//	if(ccc1>29.|| (ccc1<28.2 && ccc1>0.)) {
//	  icount++;
	  //	  cout<<"Red Dots,limited, depth1_HB iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
//	}
//      }
      //	  cout<<"*************************************** "<<endl;
      //	  cout<<"Red Dots,Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
      //	  cout<<"Red Dots,Bigger limited, depth1_HB icount = "<<icount<<endl;



      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.4);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //          Rate2->SetMaximum(91.3);
      //          Rate2->SetMinimum(90.4);
//      Rate2->Draw("ErrorSame");
*/

      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* ADCAmplperLS = new TH1F("ADCAmplperLS","", maxbins, 1., maxbins+1.);
//          TH1F* ADCAmplperLS  = new TH1F("ADCAmplperLS ","", 600, 1.,601.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
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
          ADCAmplperLS ->SetMinimum(25.0);
      ADCAmplperLS ->Draw("Error");
      
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS1_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS1");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz1S= (TH2F*)twod1S->Clone("Cefz1S");
	Cefz1S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz1S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz1S->SetMarkerStyle(20);
      Cefz1S->SetMarkerSize(0.4);
      //    Cefz1S->GetYaxis()->SetLabelSize(0.04);
      Cefz1S->GetZaxis()->SetLabelSize(0.08);
      Cefz1S->SetXTitle("<A> for few LSs - HB Depth1                   #eta \b");
      Cefz1S->SetYTitle("#phi \b");
      //    Cefz1S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz1S->SetMarkerColor(2);
      Cefz1S->SetLineColor(2);
      //      Cefz1S->SetMaximum(1.000);
//            Cefz1S->SetMinimum(1.0);
      Cefz1S->Draw("COLZ");
*/
      c1->Update();



    //=============================================================================================== 2
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

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS2");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS2");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz2= (TH2F*)twod1->Clone("Cefz2");
	Cefz2->Divide(twod1,twod0, 1, 1, "B");
	Cefz2->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz2->SetMarkerStyle(20);
      Cefz2->SetMarkerSize(0.4);
      //    Cefz2->GetYaxis()->SetLabelSize(0.04);
      Cefz2->GetZaxis()->SetLabelSize(0.08);
      Cefz2->SetXTitle("#eta \b");
      Cefz2->SetYTitle("#phi \b");
      Cefz2->SetZTitle("<A>  - HB Depth2 \b");
      Cefz2->SetMarkerColor(2);
      Cefz2->SetLineColor(2);
      //      Cefz2->SetMaximum(3000.);
      //      Cefz2->SetMinimum(1.0);
      Cefz2->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //        Rate2->SetMaximum(200.);
      //        Rate2->SetMinimum(-10.);
      //    Rate2->SetMaximum(26.2);
      //    Rate2->SetMinimum(25.4);
//       Rate2->SetMaximum(980.);
//      Rate2->SetMinimum(940.);
     Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"2 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
//	if(ccc1 >= 35) cout<<" iLS =     "<< i <<"    2<A> per channel= "<<ccc1<<endl;
	//	if(i == 735) cout<<"  iLS =     "<< i <<"    2<A> per channel= "<<ccc1<<endl;
      }

      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.4);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //        Rate2->SetMinimum(-10.);
      //        Rate2->SetMaximum(200.);
      //    Rate2->SetMaximum(26.2);
      //    Rate2->SetMinimum(25.4);
      //    Rate2->Draw("ErrorSame");
*/
      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
          TH1F* qqq2  = new TH1F("qqq2","", maxbins, 1., maxbins+1.);
//          TH1F* qqq2 = new TH1F("qqq2","", 600, 1., 601.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);

	//		  if(ccc1>27.)	  cout<<" depth2_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	//		  if(ccc1<26.&& i< 300)	  cout<<" depth2_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;


	  if(ccc1>0.) qqq2->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq2->SetMarkerStyle(20);
      qqq2->SetMarkerSize(0.4);
      qqq2->GetYaxis()->SetLabelSize(0.04);
      qqq2->SetXTitle("<ADCAmpl> per LS HB2 \b");
      qqq2->SetMarkerColor(2);
      qqq2->SetLineColor(0);
      qqq2->SetMaximum(30.0);
      qqq2->SetMinimum(25.0);
      qqq2->Draw("Error");


      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS2_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS2");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz2S= (TH2F*)twod1S->Clone("Cefz2S");
	Cefz2S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz2S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz2S->SetMarkerStyle(20);
      Cefz2S->SetMarkerSize(0.4);
      //    Cefz2S->GetYaxis()->SetLabelSize(0.04);
      Cefz2S->GetZaxis()->SetLabelSize(0.08);
      Cefz2S->SetXTitle("<A> for few LSs - HB Depth2                   #eta \b");
      Cefz2S->SetYTitle("#phi \b");
      //    Cefz2S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz2S->SetMarkerColor(2);
      Cefz2S->SetLineColor(2);
      //      Cefz2S->SetMaximum(1.000);
//            Cefz2S->SetMinimum(1.0);
      Cefz2S->Draw("COLZ");

*/




      c1->Update();



    //=============================================================================================== 3
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

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS3");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS3");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz3= (TH2F*)twod1->Clone("Cefz3");
	Cefz3->Divide(twod1,twod0, 1, 1, "B");
	Cefz3->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz3->SetMarkerStyle(20);
      Cefz3->SetMarkerSize(0.4);
      //    Cefz3->GetYaxis()->SetLabelSize(0.04);
      Cefz3->GetZaxis()->SetLabelSize(0.08);
      Cefz3->SetXTitle("#eta \b");
      Cefz3->SetYTitle("#phi \b");
      Cefz3->SetZTitle("<A>  - HE Depth1 \b");
      Cefz3->SetMarkerColor(2);
      Cefz3->SetLineColor(2);
      //      Cefz3->SetMaximum(1.000);
      //            Cefz3->SetMinimum(1.0);
      Cefz3->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(34.);
      //    Rate2->SetMinimum(27.0);
//      Rate2->SetMaximum(1050.);
//      Rate2->SetMinimum(900.);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"3 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
//	if(ccc1>40) cout<<" iLS =     "<< i <<"    3<A> per channel= "<<ccc1<<endl;
	//	if(i == 516) cout<<"  iLS =     "<< i <<"    3<A> per channel= "<<ccc1<<endl;
      }
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.4);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(34.);
      //    Rate2->SetMinimum(27.0);
      //    Rate2->Draw("ErrorSame");
*/
      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* qqq3  = new TH1F("qqq3","", maxbins, 1., maxbins+1.);
      //    TH1F* qqq3 = new TH1F("qqq3","", 800, 1., 801.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq3->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq3->SetMarkerStyle(20);
      qqq3->SetMarkerSize(0.4);
      qqq3->GetYaxis()->SetLabelSize(0.04);
      qqq3->SetXTitle("<ADCAmpl> per LS HE1 \b");
      qqq3->SetMarkerColor(2);
      qqq3->SetLineColor(0);
      qqq3->SetMaximum(50.0);
      qqq3->SetMinimum(20.0);
      qqq3->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS3_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS3");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz3S= (TH2F*)twod1S->Clone("Cefz3S");
	Cefz3S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz3S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz3S->SetMarkerStyle(20);
      Cefz3S->SetMarkerSize(0.4);
      //    Cefz3S->GetYaxis()->SetLabelSize(0.04);
      Cefz3S->GetZaxis()->SetLabelSize(0.08);
      Cefz3S->SetXTitle("<A> for few LSs - HE Depth1                   #eta \b");
      Cefz3S->SetYTitle("#phi \b");
      //    Cefz3S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz3S->SetMarkerColor(2);
      Cefz3S->SetLineColor(2);
      //      Cefz3S->SetMaximum(1.000);
//            Cefz3S->SetMinimum(1.0);
      Cefz3S->Draw("COLZ");
*/

      c1->Update();


    //=============================================================================================== 4
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


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS4");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS4");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz4= (TH2F*)twod1->Clone("Cefz4");
	Cefz4->Divide(twod1,twod0, 1, 1, "B");
	Cefz4->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz4->SetMarkerStyle(20);
      Cefz4->SetMarkerSize(0.4);
      //    Cefz4->GetYaxis()->SetLabelSize(0.04);
      Cefz4->GetZaxis()->SetLabelSize(0.08);
      Cefz4->SetXTitle("#eta \b");
      Cefz4->SetYTitle("#phi \b");
      Cefz4->SetZTitle("<A>  - HE Depth2 \b");
      Cefz4->SetMarkerColor(2);
      Cefz4->SetLineColor(2);
      //      Cefz4->SetMaximum(1.000);
      //      Cefz4->SetMinimum(1.0);
      Cefz4->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS4");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(29.);
      //    Rate2->SetMinimum(25.0);
//      Rate2->SetMaximum(1050.);
//      Rate2->SetMinimum(900.);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"4 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
//	if(ccc1>30) cout<<" iLS =     "<< i <<"    4<A> per channel= "<<ccc1<<endl;
	//	if(i == 516) cout<<"  iLS =     "<< i <<"    4<A> per channel= "<<ccc1<<endl;
      }
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS4");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(29.);
      //    Rate2->SetMinimum(25.0);
      //    Rate2->Draw("ErrorSame");
*/

      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* qqq4  = new TH1F("qqq4","", maxbins, 1., maxbins+1.);
      //    TH1F* qqq4 = new TH1F("qqq4","", 800, 1., 801.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq4->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq4->SetMarkerStyle(20);
      qqq4->SetMarkerSize(0.4);
      qqq4->GetYaxis()->SetLabelSize(0.04);
      qqq4->SetXTitle("<ADCAmpl> per LS HE2 \b");
      qqq4->SetMarkerColor(2);
      qqq4->SetLineColor(0);
      qqq4->SetMaximum(45.0);
      qqq4->SetMinimum(20.0);
      qqq4->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS4_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS4");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz4S= (TH2F*)twod1S->Clone("Cefz4S");
	Cefz4S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz4S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz4S->SetMarkerStyle(20);
      Cefz4S->SetMarkerSize(0.4);
      //    Cefz4S->GetYaxis()->SetLabelSize(0.04);
      Cefz4S->GetZaxis()->SetLabelSize(0.08);
      Cefz4S->SetXTitle("<A> for few LSs - HE Depth2                   #eta \b");
      Cefz4S->SetYTitle("#phi \b");
      //    Cefz4S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz4S->SetMarkerColor(2);
      Cefz4S->SetLineColor(2);
      //      Cefz4S->SetMaximum(1.000);
//            Cefz4S->SetMinimum(1.0);
      Cefz4S->Draw("COLZ");
*/



        c1->Update();



    //=============================================================================================== 5
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


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS5");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS5");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz5= (TH2F*)twod1->Clone("Cefz5");
	Cefz5->Divide(twod1,twod0, 1, 1, "B");
	Cefz5->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz5->SetMarkerStyle(20);
      Cefz5->SetMarkerSize(0.4);
      //    Cefz5->GetYaxis()->SetLabelSize(0.04);
      Cefz5->GetZaxis()->SetLabelSize(0.08);
      Cefz5->SetXTitle("#eta \b");
      Cefz5->SetYTitle("#phi \b");
      Cefz5->SetZTitle("<A>  - HE Depth3 \b");
      Cefz5->SetMarkerColor(2);
      Cefz5->SetLineColor(2);
      //      Cefz5->SetMaximum(1.000);
      //      Cefz5->SetMinimum(1.0);
      Cefz5->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS5");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(38.);
      //    Rate2->SetMinimum(28.0);
//      Rate2->SetMaximum(1050.);
//      Rate2->SetMinimum(900.);
      Rate2->Draw("Error");

      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"5 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
//	if(ccc1>40) cout<<" iLS =     "<< i <<"    5<A> per channel= "<<ccc1<<endl;
	//	if(i == 516) cout<<"  iLS =     "<< i <<"    5<A> per channel= "<<ccc1<<endl;
      }
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS5");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(38.);
      //    Rate2->SetMinimum(28.0);
      //    Rate2->Draw("ErrorSame");
*/

      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* qqq5  = new TH1F("qqq5","", maxbins, 1., maxbins+1.);
      //    TH1F* qqq5 = new TH1F("qqq5","", 800, 1., 801.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq5->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq5->SetMarkerStyle(20);
      qqq5->SetMarkerSize(0.4);
      qqq5->GetYaxis()->SetLabelSize(0.04);
      qqq5->SetXTitle("<ADCAmpl> per LS HE3 \b");
      qqq5->SetMarkerColor(2);
      qqq5->SetLineColor(0);
      qqq5->SetMaximum(80.0);
      qqq5->SetMinimum(20.0);
      qqq5->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS5_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS5");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz5S= (TH2F*)twod1S->Clone("Cefz5S");
	Cefz5S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz5S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz5S->SetMarkerStyle(20);
      Cefz5S->SetMarkerSize(0.4);
      //    Cefz5S->GetYaxis()->SetLabelSize(0.04);
      Cefz5S->GetZaxis()->SetLabelSize(0.08);
      Cefz5S->SetXTitle("<A> for few LSs - HE Depth3                   #eta \b");
      Cefz5S->SetYTitle("#phi \b");
      //    Cefz5S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz5S->SetMarkerColor(2);
      Cefz5S->SetLineColor(2);
      //      Cefz5S->SetMaximum(1.000);
//            Cefz5S->SetMinimum(1.0);
      Cefz5S->Draw("COLZ");

*/


      c1->Update();



    //=============================================================================================== 6
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


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS6");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS6");
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
      Cefz6->SetZTitle("<A>  - HF Depth1 \b");
      Cefz6->SetMarkerColor(2);
      Cefz6->SetLineColor(2);
      //      Cefz6->SetMaximum(1.000);
      //      Cefz6->SetMinimum(1.0);
      Cefz6->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"6 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	//	if(ccc1>10) cout<<"HF1 iLS =     "<< i <<"    6<A> per channel= "<<ccc1<<endl;
      }
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS6");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(110.);
      //    Rate2->SetMinimum(30.0);
      //    Rate2->Draw("ErrorSame");
*/

      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<"HF maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* qqq6 = new TH1F("qqq6","", maxbins, 1., maxbins+1.);
//      TH1F* qqq6 = new TH1F("qqq6","", 800, 1., 801.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);


		  if(ccc1>0 && ccc1<36.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
//		  if(ccc1>0 && ccc1<30.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
//		  if(i< 20)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;



	  if(ccc1>0.) qqq6->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq6->SetMarkerStyle(20);
      qqq6->SetMarkerSize(0.4);
      qqq6->GetYaxis()->SetLabelSize(0.04);
      qqq6->SetXTitle("<ADCAmpl> per LS HF1 \b");
      qqq6->SetMarkerColor(2);
      qqq6->SetLineColor(0);
      qqq6->SetMaximum(70.0);
      qqq6->SetMinimum(0.0);
      qqq6->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS6_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS6");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz6S= (TH2F*)twod1S->Clone("Cefz6S");
	Cefz6S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz6S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz6S->SetMarkerStyle(20);
      Cefz6S->SetMarkerSize(0.4);
      //    Cefz6S->GetYaxis()->SetLabelSize(0.04);
      Cefz6S->GetZaxis()->SetLabelSize(0.08);
      Cefz6S->SetXTitle("<A> for few LSs - HF Depth1                   #eta \b");
      Cefz6S->SetYTitle("#phi \b");
      //    Cefz6S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz6S->SetMarkerColor(2);
      Cefz6S->SetLineColor(2);
      //      Cefz6S->SetMaximum(1.000);
//            Cefz6S->SetMinimum(1.0);
      Cefz6S->Draw("COLZ");
*/


      c1->Update();



    //=============================================================================================== 7
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


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS7");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS7");
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
      Cefz7->SetZTitle("<A>  - HF Depth2 \b");
      Cefz7->SetMarkerColor(2);
      Cefz7->SetLineColor(2);
      //      Cefz7->SetMaximum(1.000);
      //      Cefz7->SetMinimum(1.0);
      Cefz7->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS7");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(60.);
      //    Rate2->SetMinimum(10.0);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"7 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	//	if(ccc1>6) cout<<"HF2 iLS =     "<< i <<"    7<A> per channel= "<<ccc1<<endl;
      }
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS7");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(60.);
      //    Rate2->SetMinimum(10.0);
      //    Rate2->Draw("ErrorSame");
*/

      c1->cd(4);
      TH1F* qqq7 = new TH1F("qqq7","", maxbins, 1., maxbins+1.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq7->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq7->SetMarkerStyle(20);
      qqq7->SetMarkerSize(0.4);
      qqq7->GetYaxis()->SetLabelSize(0.04);
      qqq7->SetXTitle("<ADCAmpl> per LS HF2 \b");
      qqq7->SetMarkerColor(2);
      qqq7->SetLineColor(0);
      qqq7->SetMaximum(70.0);
      qqq7->SetMinimum(0.0);
      qqq7->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS7_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS7");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz7S= (TH2F*)twod1S->Clone("Cefz7S");
	Cefz7S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz7S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz7S->SetMarkerStyle(20);
      Cefz7S->SetMarkerSize(0.4);
      //    Cefz7S->GetYaxis()->SetLabelSize(0.04);
      Cefz7S->GetZaxis()->SetLabelSize(0.08);
      Cefz7S->SetXTitle("<A> for few LSs - HF Depth2                   #eta \b");
      Cefz7S->SetYTitle("#phi \b");
      //    Cefz7S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz7S->SetMarkerColor(2);
      Cefz7S->SetLineColor(2);
      //      Cefz7S->SetMaximum(1.000);
//            Cefz7S->SetMinimum(1.0);
      Cefz7S->Draw("COLZ");
*/


      c1->Update();



    //=============================================================================================== 8
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


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumADCAmplLS8");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS8");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz8= (TH2F*)twod1->Clone("Cefz8");
	Cefz8->Divide(twod1,twod0, 1, 1, "B");
	Cefz8->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz8->SetMarkerStyle(20);
      Cefz8->SetMarkerSize(0.4);
      //    Cefz8->GetYaxis()->SetLabelSize(0.04);
      Cefz8->GetZaxis()->SetLabelSize(0.08);
      Cefz8->SetXTitle("#eta \b");
      Cefz8->SetYTitle("#phi \b");
      Cefz8->SetZTitle("<A>  - HO Depth4 \b");
      Cefz8->SetMarkerColor(2);
      Cefz8->SetLineColor(2);
      //      Cefz8->SetMaximum(1.000);
      //      Cefz8->SetMinimum(1.0);
      Cefz8->Draw("COLZ");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HO depth4 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
              Rate2->SetMaximum(500.);
	      Rate2->SetMinimum(0.);
      Rate2->Draw("Error");

      int nx = Rate2->GetXaxis()->GetNbins();
      // cout<<"8 Max # iLS = "<< nx <<endl;
      int icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
 	if(ccc1>300) icount++;
	//	if(ccc1>300) cout<<"HO iLS =     "<< i <<"    8<A> per channel= "<<ccc1<<endl;
	//	if(ccc1<1.) cout<<"HO ZERO  iLS =     "<< i <<"    8<A> per channel= "<<ccc1<<endl;
      }
      //    cout<<"HO icount300 =     "<< icount<< endl;
      /*
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS8");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HO depth3 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //    Rate2->SetMaximum(420.);
      //    Rate2->SetMinimum(405.0);
      //      Rate2->Draw("ErrorSame");
*/

      int maxbins = 0;
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;
      c1->cd(4);
      TH1F* qqq8  = new TH1F("qqq8","", maxbins, 1., maxbins+1.);
      //    TH1F* qqq8 = new TH1F("qqq8","", 800, 1., 801.);
      int nx = Rate2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i);


	//		if(ccc1>0 && (ccc1>91.6 || ccc1<91.4))	  cout<<" _HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
		if(ccc1>0 && (ccc1<91.0))	  cout<<" _HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;



	  if(ccc1>0.) qqq8->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq8->SetMarkerStyle(20);
      qqq8->SetMarkerSize(0.4);
      qqq8->GetYaxis()->SetLabelSize(0.04);
      qqq8->SetXTitle("<ADCAmpl> per LS HO4 \b");
      qqq8->SetMarkerColor(2);
      qqq8->SetLineColor(0);
      qqq8->SetMaximum(110.0);
      qqq8->SetMinimum(80.0);
//      qqq8->SetMaximum(95.0);
//      qqq8->SetMinimum(90.0);
      qqq8->Draw("Error");
      /*
      TH2F *twod1S= (TH2F*)hfile1->Get("h_2DsumADCAmplLS8_LSselected");
      TH2F *twod0S= (TH2F*)hfile1->Get("h_2D0sumADCAmplLS8");
      twod1S->Sumw2();
      twod0S->Sumw2();
      if(twod0S->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz8S= (TH2F*)twod1S->Clone("Cefz8S");
	Cefz8S->Divide(twod1S,twod0S, 1, 1, "B");
	Cefz8S->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz8S->SetMarkerStyle(20);
      Cefz8S->SetMarkerSize(0.4);
      //    Cefz8S->GetYaxis()->SetLabelSize(0.04);
      Cefz8S->GetZaxis()->SetLabelSize(0.08);
      Cefz8S->SetXTitle("<A> for few LSs - HO Depth4                   #eta \b");
      Cefz8S->SetYTitle("#phi \b");
      //    Cefz8S->SetZTitle("<A>  - HB Depth1 \b");
      Cefz8S->SetMarkerColor(2);
      Cefz8S->SetLineColor(2);
      //      Cefz8S->SetMaximum(1.000);
//            Cefz8S->SetMinimum(1.0);
      Cefz8S->Draw("COLZ");
*/


      c1->Update();



    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);

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

      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy1");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy2");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy3");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy4");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy5");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");


      c1->Update();



    //======================================================================================= 10
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
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplperLS1");
      //    gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("h_sumADCAmplperLS1");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(3);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumADCAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      gPad->SetGridy();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      //      Rate2->SetMaximum(1000.);
      //      Rate2->SetMinimum(960.);
//            Rate2->SetMaximum(28.);
//            Rate2->SetMinimum(24.);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      //    cout<<" Max # iLS = "<< nx <<endl;
      int icount0=0;
      int icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	if(ccc1>3.4) {
	  icount++;
	  //	  cout<<"Red Dots,Bigger 3.4, depth1_HB iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      //	  cout<<"*************************************** "<<endl;
      //	  cout<<"Red Dots,Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
      //	  cout<<"Red Dots,Bigger 3.4, depth1_HB icount = "<<icount<<endl;
      int icount=0;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>4.6) {
	  icount++;
	  //	  cout<<"Red Dots,Bigger 4.6, depth1_HB iLS = "<<i<<" <Nbcs> per iLS= "<<ccc1<<endl;
	}
      }
      //    	  cout<<"Red Dots,Bigger 4.6, depth1_HB icount = "<<icount<<endl;

      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutADCAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.4);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      //          Rate2->SetMaximum(91.3);
      //          Rate2->SetMinimum(90.4);
//      Rate2->Draw("ErrorSame");




      c1->cd(4);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_sum0ADCAmplperLS1");
      //    gPad->SetLogy();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("h_sum0ADCAmplperLS1");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
      aaaaaa2->Draw("Error");

      c1->Update();







    //======================================================================================= 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      qqq6->SetMarkerStyle(20);
      qqq6->SetMarkerSize(0.4);
      qqq6->GetYaxis()->SetLabelSize(0.04);
      qqq6->SetXTitle("<ADCAmpl> per LS HF1 \b");
      qqq6->SetMarkerColor(2);
      qqq6->SetLineColor(0);
      qqq6->SetMaximum(70.0);
      qqq6->SetMinimum(10.0);
      gPad->SetGridy();
      qqq6->Draw("Error");



      c1->cd(2);
      qqq7->SetMarkerStyle(20);
      qqq7->SetMarkerSize(0.4);
      qqq7->GetYaxis()->SetLabelSize(0.04);
      qqq7->SetXTitle("<ADCAmpl> per LS HF2 \b");
      qqq7->SetMarkerColor(2);
      qqq7->SetLineColor(0);
      qqq7->SetMaximum(70.0);
      qqq7->SetMinimum(0.0);
      gPad->SetGridy();
      qqq7->Draw("Error");


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
