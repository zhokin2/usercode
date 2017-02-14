{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
				gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
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

	TFile *hfile1= new TFile("testNZS.root", "READ"); 
	//    getchar();
	//
          TPostScript psfile ("zRunRatioHOHF.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth4_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate60 = (TH1F*)twod1->Clone("Rate60");
	Rate60->Divide(twod1,twod0, 1, 1, "B");
	Rate60->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth1_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate70 = (TH1F*)twod1->Clone("Rate70");
	Rate70->Divide(twod1,twod0, 1, 1, "B");
	Rate70->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth2_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate80 = (TH1F*)twod1->Clone("Rate80");
	Rate80->Divide(twod1,twod0, 1, 1, "B");
	Rate80->Sumw2();
      }
      

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate1_depth4_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate61 = (TH1F*)twod1->Clone("Rate60");
	Rate61->Divide(twod1,twod0, 1, 1, "B");
	Rate61->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate1_depth1_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate71 = (TH1F*)twod1->Clone("Rate70");
	Rate71->Divide(twod1,twod0, 1, 1, "B");
	Rate71->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate1_depth2_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate81 = (TH1F*)twod1->Clone("Rate80");
	Rate81->Divide(twod1,twod0, 1, 1, "B");
	Rate81->Sumw2();
      }
      
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate2_depth4_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate62 = (TH1F*)twod1->Clone("Rate60");
	Rate62->Divide(twod1,twod0, 1, 1, "B");
	Rate62->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate2_depth1_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate72 = (TH1F*)twod1->Clone("Rate70");
	Rate72->Divide(twod1,twod0, 1, 1, "B");
	Rate72->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate2_depth2_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate82 = (TH1F*)twod1->Clone("Rate80");
	Rate82->Divide(twod1,twod0, 1, 1, "B");
	Rate82->Sumw2();
      }

      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate3_depth4_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate63 = (TH1F*)twod1->Clone("Rate60");
	Rate63->Divide(twod1,twod0, 1, 1, "B");
	Rate63->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate3_depth1_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate73 = (TH1F*)twod1->Clone("Rate70");
	Rate73->Divide(twod1,twod0, 1, 1, "B");
	Rate73->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate3_depth2_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate83 = (TH1F*)twod1->Clone("Rate80");
	Rate83->Divide(twod1,twod0, 1, 1, "B");
	Rate83->Sumw2();
      }

    //================
      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate60->Draw("Error");
      Rate61->Draw("ErrorSame");
      Rate62->Draw("ErrorSame");
      Rate63->Draw("ErrorSame");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate70->Draw("Error");
      Rate71->Draw("ErrorSame");
      Rate72->Draw("ErrorSame");
      Rate73->Draw("ErrorSame");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate80->Draw("Error");
      Rate81->Draw("ErrorSame");
      Rate82->Draw("ErrorSame");
      Rate83->Draw("ErrorSame");
       
      
      c1->Update();

    //======================================================================
    //======================================================================
    //========================================================================================== end
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
