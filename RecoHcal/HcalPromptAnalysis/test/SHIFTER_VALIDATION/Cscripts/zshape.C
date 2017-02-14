{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
			gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//				gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//		gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//					gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
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
	//      gStyle->SetTitleY(0.01);            // title x-position
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

	//
	//
	//
//	TFile *hfile1= new TFile("Global_234034.root", "READ");
//	TFile *hfile1= new TFile("test211006.root", "READ");
//	TFile *hfile1= new TFile("test234457.root", "READ");
//
	TFile *hfile1= new TFile("Global_test.root", "READ");
	//	TFile *hfile1= new TFile("Pedestal_238255.root", "READ");
//	TFile *hfile1= new TFile("Laser_238183.root", "READ");

	//
	//
	//
	//	TFile *hfile1= new TFile("testNZS.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zshape.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //======================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Ahigh_HB0");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Ahigh_HB0");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap0 high-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
 //     Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");


      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Alow_HB0");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Alow_HB0");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap0 low-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
      //      Rate1->SetMaximum(580.);
      Rate1->Draw("Error");
       
      c1->cd(3);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Ahigh_HB1");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Ahigh_HB1");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap1 high-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
 //     Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");


      c1->cd(4);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Alow_HB1");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Alow_HB1");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap1 low-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
//      Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");
       
      c1->cd(5);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Ahigh_HB2");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Ahigh_HB2");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap2 high-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
 //     Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");


      c1->cd(6);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Alow_HB2");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Alow_HB2");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap2 low-A\b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
//      Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");
       
      c1->cd(7);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Ahigh_HB3");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Ahigh_HB3");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap3 high-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
 //     Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");


      c1->cd(8);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_Alow_HB3");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_Alow_HB3");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate1 = (TH1F*)twod1->Clone("Rate1");
	Rate1->Divide(twod1,twod0, 1, 1, "B");
	Rate1->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate1->SetMarkerStyle(20);
      Rate1->SetMarkerSize(0.8);
      Rate1->SetXTitle("< A > vs iTS HB cap3 low-A \b");
      Rate1->SetMarkerColor(2);
      Rate1->SetLineColor(0);
//      Rate1->SetMinimum(-10.);
      Rate1->Draw("Error");
       
       




      c1->Update();


    //======================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_good_channels_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_good_channels_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod1->Clone("Rate2");
	Rate2->Divide(twod1,twod0, 1, 1, "B");
	Rate2->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("< A > vs iTS HB good channels \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(2);
 //     Rate2->SetMinimum(-10.);
      Rate2->Draw("");

      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_bad_channels_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_bad_channels_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod1->Clone("Rate2");
	Rate2->Divide(twod1,twod0, 1, 1, "B");
	Rate2->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("< A > vs iTS HB bad channels \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(2);
 //     Rate2->SetMinimum(-10.);
      Rate2->Draw("");

      c1->cd(3);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_good_channels_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_good_channels_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod1->Clone("Rate2");
	Rate2->Divide(twod1,twod0, 1, 1, "B");
	Rate2->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("< A > vs iTS HE good channels \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(2);
 //     Rate2->SetMinimum(-10.);
      Rate2->Draw("");

      c1->cd(4);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_bad_channels_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_bad_channels_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate2 = (TH1F*)twod1->Clone("Rate2");
	Rate2->Divide(twod1,twod0, 1, 1, "B");
	Rate2->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate2->SetMarkerStyle(20);
      Rate2->SetMarkerSize(0.8);
      Rate2->SetXTitle("< A > vs iTS HE bad channels \b");
      Rate2->SetMarkerColor(2);
      Rate2->SetLineColor(2);
 //     Rate2->SetMinimum(-10.);
      Rate2->Draw("");

      c1->Update();

    //======================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_good_channels_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_good_channels_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)twod1->Clone("Rate3");
	Rate3->Divide(twod1,twod0, 1, 1, "B");
	Rate3->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->SetXTitle("< A > vs iTS HF good channels \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(2);
 //     Rate3->SetMinimum(-10.);
      Rate3->Draw("");

      c1->cd(2);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_bad_channels_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_bad_channels_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)twod1->Clone("Rate3");
	Rate3->Divide(twod1,twod0, 1, 1, "B");
	Rate3->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->SetXTitle("< A > vs iTS HF bad channels \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(2);
 //     Rate3->SetMinimum(-10.);
      Rate3->Draw("");

      c1->cd(3);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_good_channels_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_good_channels_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)twod1->Clone("Rate3");
	Rate3->Divide(twod1,twod0, 1, 1, "B");
	Rate3->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->SetXTitle("< A > vs iTS HO good channels \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(2);
 //     Rate3->SetMinimum(-10.);
      Rate3->Draw("");

      c1->cd(4);
      TH1F *twod1= (TH1F*)hfile1->Get("h_shape_bad_channels_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_shape0_bad_channels_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate3 = (TH1F*)twod1->Clone("Rate3");
	Rate3->Divide(twod1,twod0, 1, 1, "B");
	Rate3->Sumw2();
      }
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate3->SetMarkerStyle(20);
      Rate3->SetMarkerSize(0.8);
      Rate3->SetXTitle("< A > vs iTS HO bad channels \b");
      Rate3->SetMarkerColor(2);
      Rate3->SetLineColor(2);
 //     Rate3->SetMinimum(-10.);
      Rate3->Draw("");

      c1->Update();

    //=========================================================================================
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
