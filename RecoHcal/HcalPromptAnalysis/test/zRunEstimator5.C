{
   //====================================================================== Ratio
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
				gStyle->SetOptStat(0);   //  no statistics _or_
	//	gStyle->SetOptStat(100000);//  over !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//		        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1100000);//  over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1000000);//  integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		gStyle->SetOptStat(1010000);//  und integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(100000);//  und integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

	TFile *hfile1= new TFile("test.root", "READ"); 
//	TFile *hfile1= new TFile("testNZS.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zRunEstimator5.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumAmplLS1");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS1");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS1");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(2);
//      Rate1->SetMaximum(0.8);
//      Rate1->SetMinimum(0.7);
      Rate1->Draw("Error");
      int nx = Rate1->GetXaxis()->GetNbins();
      cout<<"1 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i)   ;
	if(ccc1>0.6) cout<<" iLS =     "<< i <<"    1<A> per channel= "<<ccc1<<endl;
	if(ccc1<0.1 ) cout<<" iLS =     "<< i <<"HB depth1:    1<A> per channel= "<<ccc1<<endl;
	//	if(i == 735) cout<<"Red Dots,  iLS =     "<< i <<"    1<A> per channel= "<<ccc1<<endl;
      }
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS1");
//      twod3->Sumw2();
//      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
//	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate1->SetMarkerColor(1);
      Rate1->SetLineColor(1);
      //    Rate1->Draw("ErrorSame");

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS1");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.360);
      //    Rate1->SetMinimum(0.33);
      Rate1->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS1_LSselected");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS1");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth1 -    iLS \b");
      Rate1->SetMarkerColor(4);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.355);
      //    Rate1->SetMinimum(0.335);
      //    Rate1->SetMaximum(1.2);
      //    Rate1->SetMinimum(0.);
      Rate1->Draw("ErrorSame");

      c1->Update();
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_sumAmplLS2");
      gPad->SetLogy();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth2\b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
      aaaaaa2->Draw("Error");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS2");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS2");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
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
      //    Rate2->SetMaximum(0.2);
      //    Rate2->SetMinimum(-0.01);
      Rate2->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod3->Clone("Rate2");
	Rate2->Divide(twod3,twod2, 1, 1, "B");
	Rate2->Sumw2();
      }
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("<A>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate2->SetMarkerColor(1);
      Rate2->SetLineColor(0);
      Rate2->Draw("ErrorSame");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"2 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    2<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS2");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS2");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HB depth2 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.37);
      //    Rate1->SetMinimum(0.32);
      Rate1->Draw("Error");

      c1->Update();



    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_sumAmplLS3");
      gPad->SetLogy();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth1\b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
      aaaaaa3->Draw("Error");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS3");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS3");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
//      Rate1->SetMaximum(0.75);
//      Rate1->SetMinimum(0.65);
      Rate1->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate1->SetMarkerColor(1);
      Rate1->SetLineColor(0);
      //      Rate1->Draw("ErrorSame");
      int nx = Rate1->GetXaxis()->GetNbins();
      cout<<"3 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate1->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    3<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS3");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS3");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HE depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.41);
      //    Rate1->SetMinimum(0.35);
      Rate1->Draw("Error");

      c1->Update();


    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_sumAmplLS4");
      gPad->SetLogy();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth2\b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
      aaaaaa4->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS4");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS4");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS4");
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
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS4");
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
      Rate2->Draw("ErrorSame");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"4 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    4<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS4");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS4");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HE depth2 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.38);
      //    Rate1->SetMinimum(0.34);
      Rate1->Draw("Error");
      c1->Update();



    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa5= (TH1F*)hfile1->Get("h_sumAmplLS5");
      gPad->SetLogy();
      aaaaaa5->SetMarkerStyle(20);
      aaaaaa5->SetMarkerSize(0.8);
      aaaaaa5->GetYaxis()->SetLabelSize(0.04);
      aaaaaa5->SetXTitle("<A>(ev.in LS) in LSs & channels - HE depth3\b");
      aaaaaa5->SetMarkerColor(4);
      aaaaaa5->SetLineColor(0);
      aaaaaa5->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS5");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS5");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS5");
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
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS5");
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
      Rate2->Draw("ErrorSame");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"5 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    5<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS5");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS5");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HE depth3 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.41);
      //    Rate1->SetMinimum(0.34);
      Rate1->Draw("Error");
      c1->Update();



    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa6= (TH1F*)hfile1->Get("h_sumAmplLS6");
      gPad->SetLogy();
      aaaaaa6->SetMarkerStyle(20);
      aaaaaa6->SetMarkerSize(0.8);
      aaaaaa6->GetYaxis()->SetLabelSize(0.04);
      aaaaaa6->SetXTitle("<A>(ev.in LS) in LSs & channels - HF depth1\b");
      aaaaaa6->SetMarkerColor(4);
      aaaaaa6->SetLineColor(0);
      aaaaaa6->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS6");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS6");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS6");
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
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->SetMaximum(1.0);
      Rate2->SetMinimum(0.8);
      Rate2->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS6");
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
      //      Rate2->Draw("ErrorSame");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"6 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    6<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS6");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS6");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HF depth1 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.80);
      //    Rate1->SetMinimum(0.70);
      Rate1->Draw("Error");
      c1->Update();



    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa7= (TH1F*)hfile1->Get("h_sumAmplLS7");
      gPad->SetLogy();
      aaaaaa7->SetMarkerStyle(20);
      aaaaaa7->SetMarkerSize(0.8);
      aaaaaa7->GetYaxis()->SetLabelSize(0.04);
      aaaaaa7->SetXTitle("<A>(ev.in LS) in LSs & channels - HF depth2\b");
      aaaaaa7->SetMarkerColor(4);
      aaaaaa7->SetLineColor(0);
      aaaaaa7->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS7");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS7");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS7");
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
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(0);
      Rate2->Draw("Error");
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS7");
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
      //      Rate2->Draw("ErrorSame");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"7 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    7<A> per channel= "<<ccc1<<endl;
      }

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS7");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS7");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HF depth2 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.77);
      //    Rate1->SetMinimum(0.68);
      Rate1->Draw("Error");
      c1->Update();



    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa8= (TH1F*)hfile1->Get("h_sumAmplLS8");
      gPad->SetLogy();
      aaaaaa8->SetMarkerStyle(20);
      aaaaaa8->SetMarkerSize(0.8);
      aaaaaa8->GetYaxis()->SetLabelSize(0.04);
      aaaaaa8->SetXTitle("<A>(ev.in LS) in LSs & channels - HO depth4\b");
      aaaaaa8->SetMarkerColor(4);
      aaaaaa8->SetLineColor(0);
      aaaaaa8->Draw("Error");


      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DsumAmplLS8");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0sumAmplLS8");
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
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS8");
      twod3->Sumw2();
      twod2->Sumw2();
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
//      Rate2->SetMaximum(0.85);
//      Rate2->SetMinimum(0.75);
      Rate2->Draw("Error");
      int nx = Rate2->GetXaxis()->GetNbins();
      cout<<"8 Max # iLS = "<< nx <<endl;
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate2->GetBinContent(i)   ;
	if(ccc1>0.9) cout<<" iLS =     "<< i <<"    8<A> per channel= "<<ccc1<<endl;
	if(ccc1<0.1) cout<<" iLS =     "<< i <<"HO:    8<A> per channel= "<<ccc1<<endl;
      }
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumCutAmplperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS8");
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
      //      Rate2->Draw("ErrorSame");

      c1->cd(4);
      TH1F *twod3= (TH1F*)hfile1->Get("h_sumAmplperLS8");
      TH1F *twod2= (TH1F*)hfile1->Get("h_sum0AmplperLS8");
      twod3->Sumw2();
      twod2->Sumw2();
      if(twod2->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod3->Clone("Rate1");
	Rate1->Divide(twod3,twod2, 1, 1, "B");
	Rate1->Sumw2();
      }
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("<A>(ev.in LS & ch.) - HO depth4 -    iLS \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //    Rate1->SetMaximum(0.345);
      //    Rate1->SetMinimum(0.325);
      Rate1->Draw("Error");
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
