{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
					gStyle->SetOptStat(0);   //  no statistics _or_
	// gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
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
	TFile *hfile1= new TFile("test.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zamplpedcorr.ps", 111);
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
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedvsampl_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedvsampl0_HB");
//      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz225= (TH1F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
//	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
          Cefz225->SetXTitle("Pedestals \b");
          Cefz225->SetYTitle("<A> \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //    Cefz225->SetMaximum(1.000);
      //    Cefz225->SetMinimum(0.0001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedwvsampl_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedwvsampl0_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz226= (TH1F*)twod1->Clone("Cefz226");
	Cefz226->Divide(twod1,twod0, 1, 1, "B");
	Cefz226->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
          Cefz226->SetXTitle("Width_Pedestals \b");
          Cefz226->SetYTitle("<A> \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //    Cefz226->SetMaximum(1.000);
      //    Cefz226->SetMinimum(0.0001);
      Cefz226->Draw("COLZ");
      
      c1->cd(3);
      TH1F *twod1= (TH1F*)hfile1->Get("h_amplvsped_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_amplvsped0_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz227= (TH1F*)twod1->Clone("Cefz227");
	Cefz227->Divide(twod1,twod0, 1, 1, "B");
	Cefz227->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz227->SetMarkerStyle(20);
      Cefz227->SetMarkerSize(0.4);
          Cefz227->SetXTitle("Amplitude \b");
          Cefz227->SetYTitle("<Pedestals> \b");
      Cefz227->SetMarkerColor(2);
      Cefz227->SetLineColor(2);
      //    Cefz227->SetMaximum(1.000);
      //    Cefz227->SetMinimum(0.0001);
      Cefz227->Draw("COLZ");
      
      c1->cd(4);
      TH1F *twod1= (TH1F*)hfile1->Get("h_amplvspedw_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_amplvsped0_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz228= (TH1F*)twod1->Clone("Cefz228");
	Cefz228->Divide(twod1,twod0, 1, 1, "B");
	Cefz228->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz228->SetMarkerStyle(20);
      Cefz228->SetMarkerSize(0.4);
          Cefz228->SetXTitle("Amplitude \b");
          Cefz228->SetYTitle("<Width_Pedestals> \b");
      Cefz228->SetMarkerColor(2);
      Cefz228->SetLineColor(2);
      //    Cefz228->SetMaximum(1.000);
      //    Cefz228->SetMinimum(0.0001);
      Cefz228->Draw("COLZ");
      
      
      c1->Update();
      
      
            
    //========================================================================================= 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *two11= (TH2F*)hfile1->Get("h2_pedvsampl_HB");
      gPad->SetGridy();
      gPad->SetGridx();
      two11->SetMarkerStyle(20);
      two11->SetMarkerSize(0.4);
      two11->SetXTitle("Pedestals HB \b");
      two11->SetYTitle("Amplitude HB\b");
      two11->SetMarkerColor(2);
      two11->SetLineColor(2);
      //         gPad->SetLogy();
      two11->Draw("COLZ");
      
      c1->cd(2);
      TH2F *two12= (TH2F*)hfile1->Get("h2_pedwvsampl_HB");
      gPad->SetGridy();
      gPad->SetGridx();
      two12->SetMarkerStyle(20);
      two12->SetMarkerSize(0.4);
      two12->SetXTitle("Width_Pedestals HB \b");
      two12->SetYTitle("Amplitude HB\b");
      two12->SetMarkerColor(2);
      two12->SetLineColor(2);
      //   gPad->SetLogy();
      two12->Draw("COLZ");
      
      c1->cd(3);
      TH2F *two22= (TH2F*)hfile1->Get("h2_amplvsped_HB");
      gPad->SetGridy();
      gPad->SetGridx();
      two22->SetMarkerStyle(20);
      two22->SetMarkerSize(0.4);
      two22->SetYTitle("Pedestals HB \b");
      two22->SetXTitle("Amplitude HB\b");
      two22->SetMarkerColor(2);
      two22->SetLineColor(2);
      two22->Draw("COLZ");
      
      c1->cd(4);
      TH2F *two22= (TH2F*)hfile1->Get("h2_amplvspedw_HB");
      gPad->SetGridy();
      gPad->SetGridx();
      two22->SetMarkerStyle(20);
      two22->SetMarkerSize(0.4);
      two22->SetYTitle("Width_Pedestals HB \b");
      two22->SetXTitle("Amplitude HB\b");
      two22->SetMarkerColor(2);
      two22->SetLineColor(2);
      two22->Draw("COLZ");
      
      c1->Update();
      
    //========================================================================================= 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy2");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");
      
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy3");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");
      
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_sumADCAmplLS1copy4");
      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("<A>(ev.in LS) in LSs & channels - HB depth1\b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->Draw("Error");
      
      c1->cd(4);
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
            
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedvsampl_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedvsampl0_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz225= (TH1F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
          Cefz225->SetXTitle("Pedestals \b");
          Cefz225->SetYTitle("<A> \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //    Cefz225->SetMaximum(1.000);
      //    Cefz225->SetMinimum(0.0001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedwvsampl_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedwvsampl0_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz226= (TH1F*)twod1->Clone("Cefz226");
	Cefz226->Divide(twod1,twod0, 1, 1, "B");
	Cefz226->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
          Cefz226->SetXTitle("Width_Pedestals \b");
          Cefz226->SetYTitle("<A> \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //    Cefz226->SetMaximum(1.000);
      //    Cefz226->SetMinimum(0.0001);
      Cefz226->Draw("COLZ");
      
      c1->cd(3);
      TH2F *two11= (TH2F*)hfile1->Get("h2_pedvsampl_HE");
      gPad->SetGridy();
      gPad->SetGridx();
      two11->SetMarkerStyle(20);
      two11->SetMarkerSize(0.4);
      two11->SetXTitle("Pedestals HE \b");
      two11->SetYTitle("Amplitude HE\b");
      two11->SetMarkerColor(2);
      two11->SetLineColor(2);
      //         gPad->SetLogy();
      two11->Draw("COLZ");
      
      c1->cd(4);
      TH2F *two12= (TH2F*)hfile1->Get("h2_pedwvsampl_HE");
      gPad->SetGridy();
      gPad->SetGridx();
      two12->SetMarkerStyle(20);
      two12->SetMarkerSize(0.4);
      two12->SetXTitle("Width_Pedestals HE \b");
      two12->SetYTitle("Amplitude HE\b");
      two12->SetMarkerColor(2);
      two12->SetLineColor(2);
      //   gPad->SetLogy();
      two12->Draw("COLZ");
      
      
      c1->Update();
            
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedvsampl_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedvsampl0_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz225= (TH1F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
          Cefz225->SetXTitle("Pedestals \b");
          Cefz225->SetYTitle("<A> \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //    Cefz225->SetMaximum(1.000);
      //    Cefz225->SetMinimum(0.0001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedwvsampl_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedwvsampl0_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz226= (TH1F*)twod1->Clone("Cefz226");
	Cefz226->Divide(twod1,twod0, 1, 1, "B");
	Cefz226->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
          Cefz226->SetXTitle("Width_Pedestals \b");
          Cefz226->SetYTitle("<A> \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //    Cefz226->SetMaximum(1.000);
      //    Cefz226->SetMinimum(0.0001);
      Cefz226->Draw("COLZ");
      
      c1->cd(3);
      TH2F *two11= (TH2F*)hfile1->Get("h2_pedvsampl_HF");
      gPad->SetGridy();
      gPad->SetGridx();
      two11->SetMarkerStyle(20);
      two11->SetMarkerSize(0.4);
      two11->SetXTitle("Pedestals HF \b");
      two11->SetYTitle("Amplitude HF\b");
      two11->SetMarkerColor(2);
      two11->SetLineColor(2);
      //         gPad->SetLogy();
      two11->Draw("COLZ");
      
      c1->cd(4);
      TH2F *two12= (TH2F*)hfile1->Get("h2_pedwvsampl_HF");
      gPad->SetGridy();
      gPad->SetGridx();
      two12->SetMarkerStyle(20);
      two12->SetMarkerSize(0.4);
      two12->SetXTitle("Width_Pedestals HF \b");
      two12->SetYTitle("Amplitude HF\b");
      two12->SetMarkerColor(2);
      two12->SetLineColor(2);
      //   gPad->SetLogy();
      two12->Draw("COLZ");
      
      
      c1->Update();
            
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedvsampl_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedvsampl0_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz225= (TH1F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
          Cefz225->SetXTitle("Pedestals \b");
          Cefz225->SetYTitle("<A> \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
          Cefz225->SetMaximum(2000.);
      //    Cefz225->SetMinimum(0.0001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_pedwvsampl_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_pedwvsampl0_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Cefz226= (TH1F*)twod1->Clone("Cefz226");
	Cefz226->Divide(twod1,twod0, 1, 1, "B");
	Cefz226->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
          Cefz226->SetXTitle("Width_Pedestals \b");
          Cefz226->SetYTitle("<A> \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
          Cefz226->SetMaximum(2000.);
      //    Cefz226->SetMinimum(0.0001);
      Cefz226->Draw("COLZ");
      
      c1->cd(3);
      TH2F *two11= (TH2F*)hfile1->Get("h2_pedvsampl_HO");
      gPad->SetGridy();
      gPad->SetGridx();
      two11->SetMarkerStyle(20);
      two11->SetMarkerSize(0.4);
      two11->SetXTitle("Pedestals HO \b");
      two11->SetYTitle("Amplitude HO\b");
      two11->SetMarkerColor(2);
      two11->SetLineColor(2);
      //         gPad->SetLogy();
      two11->Draw("COLZ");
      
      c1->cd(4);
      TH2F *two12= (TH2F*)hfile1->Get("h2_pedwvsampl_HO");
      gPad->SetGridy();
      gPad->SetGridx();
      two12->SetMarkerStyle(20);
      two12->SetMarkerSize(0.4);
      two12->SetXTitle("Width_Pedestals HO \b");
      two12->SetYTitle("Amplitude HO\b");
      two12->SetMarkerColor(2);
      two12->SetLineColor(2);
      //   gPad->SetLogy();
      two12->Draw("COLZ");
      
      
      c1->Update();
            
    //======================================================================
    //======================================================================================== end
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
