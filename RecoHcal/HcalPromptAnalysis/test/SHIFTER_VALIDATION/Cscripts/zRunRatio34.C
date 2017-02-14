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

//	TFile *hfile1= new TFile("test.root", "READ"); 
//



	TFile *hfile1= new TFile("Global_test.root", "READ"); 
//	TFile *hfile1= new TFile("test5123.root", "READ"); 
//	TFile *hfile1= new TFile("test17Jule.root", "READ"); 



//	TFile *hfile1= new TFile("testRunDepCap32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepRatio32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepWidth32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepADCampl32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepTSmax32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepTSmean32.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zRunRatio34.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=========================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth1_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate10 = (TH1F*)twod1->Clone("Rate10");
	Rate10->Divide(twod1,twod0, 1, 1, "B");
	Rate10->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth2_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate20 = (TH1F*)twod1->Clone("Rate20");
	Rate20->Divide(twod1,twod0, 1, 1, "B");
	Rate20->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth1_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate30 = (TH1F*)twod1->Clone("Rate30");
	Rate30->Divide(twod1,twod0, 1, 1, "B");
	Rate30->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth2_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate40 = (TH1F*)twod1->Clone("Rate40");
	Rate40->Divide(twod1,twod0, 1, 1, "B");
	Rate40->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrate_depth3_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate50 = (TH1F*)twod1->Clone("Rate50");
	Rate50->Divide(twod1,twod0, 1, 1, "B");
	Rate50->Sumw2();
      }

      
      
      c1->Clear();
      c1->Divide(1,5);
      
      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate10->SetMarkerStyle(20);
      Rate10->SetMarkerSize(0.8);
      Rate10->GetXaxis()->SetLabelSize(0.06);
      Rate10->GetYaxis()->SetLabelSize(0.06);
      Rate10->SetTitleSize(0.06,"XY" );
      //    Rate10->SetXTitle("iRun \b");
      //    Rate10->SetYTitle("Rate if some bcs-HBdepth1\b");
      Rate10->SetXTitle("Portion of bcs events    HBdepth1             iRun \b");
      Rate10->SetMarkerColor(1);
      Rate10->SetLineColor(1);
      Rate10->SetMaximum(1.100);
      Rate10->Draw("Error");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate20->SetMarkerStyle(20);
      Rate20->SetMarkerSize(0.8);
      Rate20->GetXaxis()->SetLabelSize(0.06);
      Rate20->GetYaxis()->SetLabelSize(0.06);
      Rate20->SetTitleSize(0.06,"XY" );
      //      Rate20->SetXTitle("iRun \b");
      //      Rate20->SetYTitle("Rate if some bcs-HBdepth2\b");
      Rate20->SetXTitle("Portion of bcs events    HBdepth2             iRun \b");
      Rate20->SetMarkerColor(1);
      Rate20->SetLineColor(0);
      Rate20->Draw("Error");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate30->SetMarkerStyle(20);
      Rate30->SetMarkerSize(0.8);
      Rate30->GetXaxis()->SetLabelSize(0.06);
      Rate30->GetYaxis()->SetLabelSize(0.06);
      Rate30->SetTitleSize(0.06,"XY" );
      //    Rate30->SetXTitle("iRun \b");
      //    Rate30->SetYTitle("Rate if some bcs-HEdepth1\b");
      Rate30->SetXTitle("Portion of bcs events    HEdepth1             iRun \b");
      Rate30->SetMarkerColor(1);
      Rate30->SetLineColor(0);
      Rate30->Draw("Error");
       
      c1->cd(4);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate40->SetMarkerStyle(20);
      Rate40->SetMarkerSize(0.8);
      Rate40->GetXaxis()->SetLabelSize(0.06);
      Rate40->GetYaxis()->SetLabelSize(0.06);
      Rate40->SetTitleSize(0.06,"XY" );
      //    Rate40->SetXTitle("iRun \b");
      //    Rate40->SetYTitle("Rate if some bcs-HEdepth2\b");
      Rate40->SetXTitle("Portion of bcs events    HEdepth2             iRun \b");
      Rate40->SetMarkerColor(1);
      Rate40->SetLineColor(0);
      Rate40->Draw("Error");
       
      c1->cd(5);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate50->SetMarkerStyle(20);
      Rate50->SetMarkerSize(0.8);
      Rate50->GetXaxis()->SetLabelSize(0.06);
      Rate50->GetYaxis()->SetLabelSize(0.06);
      Rate50->SetTitleSize(0.06,"XY" );
      //    Rate50->SetXTitle("iRun \b");
      //    Rate50->SetYTitle("Rate if some bcs-HEdepth3\b");
      Rate50->SetXTitle("Portion of bcs events    HEdepth3             iRun \b");
      Rate50->SetMarkerColor(1);
      Rate50->SetLineColor(0);
      Rate50->Draw("Error");
       
      c1->Update();
    //=========================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth1_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate11 = (TH1F*)twod1->Clone("Rate10");
	Rate11->Divide(twod1,twod0, 1, 1, "B");
	Rate11->Sumw2();
      }
      int nx = Rate11->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Rate11->GetBinContent(i)   ;
	if(ccc1 >= 0.10) {
	  cout<<"Red Color:  depth1_HB iLS = "<<i<<"  Portion of bcs events per iLS= "<<ccc1<<endl;
	}
	if(i == 735) cout<<"  iLS =     "<< i <<" Portion of bcs events per iLS= "<<ccc1<<endl;
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth2_HB");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate21 = (TH1F*)twod1->Clone("Rate20");
	Rate21->Divide(twod1,twod0, 1, 1, "B");
	Rate21->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth1_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate31 = (TH1F*)twod1->Clone("Rate30");
	Rate31->Divide(twod1,twod0, 1, 1, "B");
	Rate31->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth2_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate41 = (TH1F*)twod1->Clone("Rate40");
	Rate41->Divide(twod1,twod0, 1, 1, "B");
	Rate41->Sumw2();
      }
      
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth3_HE");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate51 = (TH1F*)twod1->Clone("Rate50");
	Rate51->Divide(twod1,twod0, 1, 1, "B");
	Rate51->Sumw2();
      }

      
      c1->Clear();
      c1->Divide(1,5);
      
      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate11->SetMarkerStyle(20);
      Rate11->SetMarkerSize(0.8);
      Rate11->GetXaxis()->SetLabelSize(0.06);
      Rate11->GetYaxis()->SetLabelSize(0.06);
      Rate11->SetTitleSize(0.06,"XY" );
      //    Rate11->SetXTitle("iRun \b");
      //    Rate11->SetYTitle("Rate if Nbcs>cut1-HBdep1\b");
      Rate11->SetXTitle("Portion of bcs events    HBdepth1             iRun \b");
      Rate11->SetMarkerColor(2);
      Rate11->SetLineColor(0);
      Rate11->Draw("Error");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate21->SetMarkerStyle(20);
      Rate21->SetMarkerSize(0.8);
      Rate21->GetXaxis()->SetLabelSize(0.06);
      Rate21->GetYaxis()->SetLabelSize(0.06);
      Rate21->SetTitleSize(0.06,"XY" );
      //    Rate21->SetXTitle("iRun \b");
      //    Rate21->SetYTitle("Rate if Nbcs>cut1-HBdep2\b");
      Rate21->SetXTitle("Portion of bcs events    HBdepth2             iRun \b");
      Rate21->SetMarkerColor(2);
      Rate21->SetLineColor(0);
      Rate21->Draw("Error");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate31->SetMarkerStyle(20);
      Rate31->SetMarkerSize(0.8);
      Rate31->GetXaxis()->SetLabelSize(0.06);
      Rate31->GetYaxis()->SetLabelSize(0.06);
      Rate31->SetTitleSize(0.06,"XY" );
      //    Rate31->SetXTitle("iRun \b");
      //    Rate31->SetYTitle("Rate if Nbcs>cut1-HEdep1\b");
      Rate31->SetXTitle("Portion of bcs events    HEdepth1             iRun \b");
      Rate31->SetMarkerColor(2);
      Rate31->SetLineColor(0);
      Rate31->Draw("Error");
       
      c1->cd(4);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate41->SetMarkerStyle(20);
      Rate41->SetMarkerSize(0.8);
      Rate41->GetXaxis()->SetLabelSize(0.06);
      Rate41->GetYaxis()->SetLabelSize(0.06);
      Rate41->SetTitleSize(0.06,"XY" );
      //    Rate41->SetXTitle("iRun \b");
      //    Rate41->SetYTitle("Rate if Nbcs>cut1-HEdep2\b");
      Rate41->SetXTitle("Portion of bcs events    HEdepth2             iRun \b");
      Rate41->SetMarkerColor(2);
      Rate41->SetLineColor(0);
      Rate41->Draw("Error");
       
      c1->cd(5);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate51->SetMarkerStyle(20);
      Rate51->SetMarkerSize(0.8);
      Rate51->GetXaxis()->SetLabelSize(0.06);
      Rate51->GetYaxis()->SetLabelSize(0.06);
      Rate51->SetTitleSize(0.06,"XY" );
      //    Rate51->SetXTitle("iRun \b");
      //    Rate51->SetYTitle("Rate if Nbcs>cut1-HEdep3\b");
      Rate51->SetXTitle("Portion of bcs events    HEdepth3             iRun \b");
      Rate51->SetMarkerColor(2);
      Rate51->SetLineColor(0);
      Rate51->Draw("Error");
       
      c1->Update();
    //=========================================================================================== 3
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate10->Draw("Error");
      Rate11->Draw("ErrorSame");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate20->Draw("Error");
      Rate21->Draw("ErrorSame");
       
      
      c1->Update();

    //=========================================================================================== 4
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate30->Draw("Error");
      Rate31->Draw("ErrorSame");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate40->Draw("Error");
      Rate41->Draw("ErrorSame");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate50->Draw("Error");
      Rate51->Draw("ErrorSame");
       
      
      c1->Update();

    //=========================================================================================== 5
    //======================================================================
    //======================================================================
    //================
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

      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate60->SetMarkerStyle(20);
      Rate60->SetMarkerSize(0.9);
      Rate60->GetXaxis()->SetLabelSize(0.06);
      Rate60->GetYaxis()->SetLabelSize(0.06);
      Rate60->SetTitleSize(0.06,"XY" );
      //    Rate60->SetXTitle("iRun \b");
      //    Rate60->SetYTitle("Rate if some bcs-HOdepth4\b");
      Rate60->SetXTitle("Portion of bcs events    HOdepth4             iRun \b");
      Rate60->SetMarkerColor(1);
//      Rate60->SetLineColor(0);
      Rate60->Draw("Error");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate70->SetMarkerStyle(20);
      Rate70->SetMarkerSize(0.9);
      Rate70->GetXaxis()->SetLabelSize(0.06);
      Rate70->GetYaxis()->SetLabelSize(0.06);
      Rate70->SetTitleSize(0.06,"XY" );
      //    Rate70->SetXTitle("iRun \b");
      //    Rate70->SetYTitle("Rate if some bcs-HFdepth1\b");
      Rate70->SetXTitle("Portion of bcs events    HFdepth1             iRun \b");
      Rate70->SetMarkerColor(1);
      Rate70->SetLineColor(0);
      Rate70->Draw("Error");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate80->SetMarkerStyle(20);
      Rate80->SetMarkerSize(0.9);
      Rate80->GetXaxis()->SetLabelSize(0.06);
      Rate80->GetYaxis()->SetLabelSize(0.06);
      Rate80->SetTitleSize(0.06,"XY" );
      //    Rate80->SetXTitle("iRun \b");
      //    Rate80->SetYTitle("Rate if some bcs-HFdepth2\b");
      Rate80->SetXTitle("Portion of bcs events    HFdepth2             iRun \b");
      Rate80->SetMarkerColor(1);
      Rate80->SetLineColor(0);
      Rate80->Draw("Error");
       
      
      c1->Update();

    //=========================================================================================== 6
    //======================================================================
    //======================================================================
    //================
      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth4_HO");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate61 = (TH1F*)twod1->Clone("Rate61");
	Rate61->Divide(twod1,twod0, 1, 1, "B");
	Rate61->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth1_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate71 = (TH1F*)twod1->Clone("Rate71");
	Rate71->Divide(twod1,twod0, 1, 1, "B");
	Rate71->Sumw2();
      }

      TH1F *twod1= (TH1F*)hfile1->Get("h_runbadrateC_depth2_HF");
      TH1F *twod0= (TH1F*)hfile1->Get("h_runbadrate0_depth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH1F")){
	TH1F* Rate81 = (TH1F*)twod1->Clone("Rate81");
	Rate81->Divide(twod1,twod0, 1, 1, "B");
	Rate81->Sumw2();
      }
      



      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate61->SetMarkerStyle(20);
      Rate61->SetMarkerSize(0.5);
      Rate61->GetXaxis()->SetLabelSize(0.06);
      Rate61->GetYaxis()->SetLabelSize(0.06);
      Rate61->SetTitleSize(0.06,"XY" );
      //          Rate61->SetXTitle("iRun \b");
      //          Rate61->SetYTitle("Rate if Nbcs>cut1-HOdeph4\b");
      Rate61->SetXTitle("Portion of bcs events    HOdepth4             iRun \b");
      Rate61->SetMarkerColor(2);
      Rate61->SetLineColor(0);
      Rate61->Draw("Error");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate71->SetMarkerStyle(20);
      Rate71->SetMarkerSize(0.5);
      Rate71->GetXaxis()->SetLabelSize(0.06);
      Rate71->GetYaxis()->SetLabelSize(0.06);
      Rate71->SetTitleSize(0.06,"XY" );
      //          Rate71->SetXTitle("iRun \b");
      //          Rate71->SetYTitle("Rate if Nbcs>cut1-HFdeph1\b");
      Rate71->SetXTitle("Portion of bcs events    HFdepth1             iRun \b");
      Rate71->SetMarkerColor(2);
      Rate71->SetLineColor(0);
      Rate71->Draw("Error");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate81->SetMarkerStyle(20);
      Rate81->SetMarkerSize(0.5);
      Rate81->GetXaxis()->SetLabelSize(0.06);
      Rate81->GetYaxis()->SetLabelSize(0.06);
      Rate81->SetTitleSize(0.06,"XY" );
      //          Rate81->SetXTitle("iRun \b");
      //          Rate81->SetYTitle("Rate if Nbcs>cut1-HFdeph2\b");
      Rate81->SetXTitle("Portion of bcs events    HFdepth2             iRun \b");
      Rate81->SetMarkerColor(2);
      Rate81->SetLineColor(0);
      Rate81->Draw("Error");
       
      
      c1->Update();

    //=========================================================================================== 7
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(1,3);
      

      c1->cd(1);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate60->Draw("Error");
      Rate61->Draw("ErrorSame");
       
      c1->cd(2);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate70->Draw("Error");
      Rate71->Draw("ErrorSame");
       
      c1->cd(3);
      //    gPad->SetGridy();
      //    gPad->SetGridx();
      Rate80->Draw("Error");
      Rate81->Draw("ErrorSame");
       
      
      c1->Update();

    //=========================================================================================== 8
    //======================================================================
    //======================================================================
    //================
      c1->Clear();
      c1->Divide(2,4);

      c1->cd(1);
      TH1F* Rate11profile = new TH1F("Rate11profile","", 100, 0.,1.);
      int nx = Rate11->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate11->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate11->GetBinContent(i) ;
	  Rate11profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate11profile->SetMarkerStyle(20);
      Rate11profile->SetMarkerSize(0.4);
      Rate11profile->GetYaxis()->SetLabelSize(0.04);
      Rate11profile->SetXTitle("ev.fraction in each LS for HBdepth1 \b");
      Rate11profile->SetMarkerColor(2);
      Rate11profile->SetLineColor(2);
      Rate11profile->Draw("");
      
      c1->cd(2);
      TH1F* Rate21profile = new TH1F("Rate21profile","", 100, 0.,1.);
      int nx = Rate21->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate21->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate21->GetBinContent(i) ;
	  Rate21profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate21profile->SetMarkerStyle(20);
      Rate21profile->SetMarkerSize(0.4);
      Rate21profile->GetYaxis()->SetLabelSize(0.04);
      Rate21profile->SetXTitle("ev.fraction in each LS for HBdepth2 \b");
      Rate21profile->SetMarkerColor(2);
      Rate21profile->SetLineColor(2);
      Rate21profile->Draw("");
      
      c1->cd(3);
      TH1F* Rate31profile = new TH1F("Rate31profile","", 100, 0.,1.);
      int nx = Rate31->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate31->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate31->GetBinContent(i) ;
	  Rate31profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate31profile->SetMarkerStyle(20);
      Rate31profile->SetMarkerSize(0.4);
      Rate31profile->GetYaxis()->SetLabelSize(0.04);
      Rate31profile->SetXTitle("ev.fraction in each LS for HEdepth1 \b");
      Rate31profile->SetMarkerColor(2);
      Rate31profile->SetLineColor(2);
      Rate31profile->Draw("");
      
      c1->cd(4);
      TH1F* Rate41profile = new TH1F("Rate41profile","", 100, 0.,1.);
      int nx = Rate41->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate41->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate41->GetBinContent(i) ;
	  Rate41profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate41profile->SetMarkerStyle(20);
      Rate41profile->SetMarkerSize(0.4);
      Rate41profile->GetYaxis()->SetLabelSize(0.04);
      Rate41profile->SetXTitle("ev.fraction in each LS for HEdepth2 \b");
      Rate41profile->SetMarkerColor(2);
      Rate41profile->SetLineColor(2);
      Rate41profile->Draw("");
      
      c1->cd(5);
      TH1F* Rate51profile = new TH1F("Rate51profile","", 100, 0.,1.);
      int nx = Rate51->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate51->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate51->GetBinContent(i) ;
	  Rate51profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate51profile->SetMarkerStyle(20);
      Rate51profile->SetMarkerSize(0.4);
      Rate51profile->GetYaxis()->SetLabelSize(0.04);
      Rate51profile->SetXTitle("ev.fraction in each LS for HEdepth3 \b");
      Rate51profile->SetMarkerColor(2);
      Rate51profile->SetLineColor(2);
      Rate51profile->Draw("");
      
      c1->cd(6);
      TH1F* Rate61profile = new TH1F("Rate61profile","", 100, 0.,1.);
      int nx = Rate61->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate61->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate61->GetBinContent(i) ;
	  Rate61profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate61profile->SetMarkerStyle(20);
      Rate61profile->SetMarkerSize(0.4);
      Rate61profile->GetYaxis()->SetLabelSize(0.04);
      Rate61profile->SetXTitle("ev.fraction in each LS for HOdepth4 \b");
      Rate61profile->SetMarkerColor(2);
      Rate61profile->SetLineColor(2);
      Rate61profile->Draw("");
      
      c1->cd(7);
      TH1F* Rate71profile = new TH1F("Rate71profile","", 100, 0.,1.);
      int nx = Rate71->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate71->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate71->GetBinContent(i) ;
	  Rate71profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate71profile->SetMarkerStyle(20);
      Rate71profile->SetMarkerSize(0.4);
      Rate71profile->GetYaxis()->SetLabelSize(0.04);
      Rate71profile->SetXTitle("ev.fraction in each LS for HFdepth1 \b");
      Rate71profile->SetMarkerColor(2);
      Rate71profile->SetLineColor(2);
      Rate71profile->Draw("");
      
      c1->cd(8);
      TH1F* Rate81profile = new TH1F("Rate81profile","", 100, 0.,1.);
      int nx = Rate81->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	//	if(Rate81->GetBinContent(i) !=0 ) {
	  double ccc1 =  Rate81->GetBinContent(i) ;
	  Rate81profile->Fill(ccc1);
	  //	}
      }
      gPad->SetLogy();
      Rate81profile->SetMarkerStyle(20);
      Rate81profile->SetMarkerSize(0.4);
      Rate81profile->GetYaxis()->SetLabelSize(0.04);
      Rate81profile->SetXTitle("ev.fraction in each LS for HFdepth2 \b");
      Rate81profile->SetMarkerColor(2);
      Rate81profile->SetLineColor(2);
      Rate81profile->Draw("");
      
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
