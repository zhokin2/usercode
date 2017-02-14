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

//	TFile *hfile1= new TFile("analysisUSC211154.root", "READ");        
	TFile *hfile1= new TFile("Global_test.root", "READ");        


	//    getchar();
	//
          TPostScript psfile ("zampl.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //==================================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1_HB");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("any Error, HB Depth1 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HB Depth1");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2_HB");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
//      twod1->SetTitle("any Error, HB Depth2 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HB Depth2");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3_HB");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
//      twod1->SetTitle("any Error, HB Depth3 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HB Depth3");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->Update();
	
	
            
    //==================================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
      //    Ceff->SetTitle("any Error, HB Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("<Adc,fC - HB Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HB Depth2 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Adc,fC - HB Depth2");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Amplitude_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HB Depth3 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Adc, fC - HB Depth3");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_Amplitude_HB");
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("Adc, fC  - HB\n");
      twod1->SetXTitle("fC");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("");
      
      c1->Update();
	
	
            
    //==================================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ampl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
      //    Ceff->SetTitle("any Error, HB Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("<AdcSumOverTS:1-9>, GeV - HB Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ampl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
          twod1->Sumw2();
          twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HB Depth2 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("AdcSumOverTS:1-9>, GeV - HB Depth2");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ampl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HB");
          twod1->Sumw2();
          twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HB Depth3 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("AdcSumOverTS:1-9>, GeV - HB Depth3");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_Ampl_HB");
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("AdcSumOverTS:1-9>, GeV - HB  \n");
      twod1->SetXTitle("GeV");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("");
      
      c1->Update();
	
	
            
    //==================================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1_HE");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("any Error, HE Depth1 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HE Depth1");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2_HE");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
//      twod1->SetTitle("any Error, HE Depth2 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HE Depth2");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3_HE");
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
//      twod1->SetTitle("any Error, HE Depth3 \n");
      twod1->SetXTitle("#eta");
      twod1->SetYTitle("#phi");
      twod1->SetZTitle("HE Depth3");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("COLZ");
      
      c1->Update();
	
	
            
    //==================================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
      //    Ceff->SetTitle("any Error, HE Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("<Adc,fC - HE Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Amplitude_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HE Depth2 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Adc,fC - HE Depth2");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Amplitude_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HE Depth3 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("Adc, fC - HE Depth3");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_Amplitude_HE");
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("Adc, fC  - HE\n");
      twod1->SetXTitle("fC");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("");
      
      c1->Update();
	
	
            
    //==================================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ampl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
      //    Ceff->SetTitle("any Error, HE Depth1 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("<AdcSumOverTS:1-9>, GeV - HE Depth1");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ampl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
          twod1->Sumw2();
          twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HE Depth2 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("AdcSumOverTS:1-9>, GeV - HE Depth2");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ampl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
          twod1->Sumw2();
          twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
       gPad->SetGridy();
       gPad->SetGridx();
      gPad->SetLogz();
      Ceff->SetMarkerStyle(20);
      Ceff->SetMarkerSize(0.4);
      Ceff->GetYaxis()->SetLabelSize(0.04);
//      Ceff->SetTitle("any Error, HE Depth3 \n");
      Ceff->SetXTitle("#eta");
      Ceff->SetYTitle("#phi");
      Ceff->SetZTitle("AdcSumOverTS:1-9>, GeV - HE Depth3");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
      Ceff->Draw("COLZ");
      
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_Ampl_HE");
      gPad->SetLogz();
      twod1->SetMarkerStyle(20);
      twod1->SetMarkerSize(0.4);
      twod1->GetYaxis()->SetLabelSize(0.04);
      twod1->SetTitle("AdcSumOverTS:1-9>, GeV - HE  \n");
      twod1->SetXTitle("GeV");
      twod1->SetMarkerColor(2);
      twod1->SetLineColor(2);
      twod1->Draw("");
      
      c1->Update();
	
	
            
    //======================================================================
    //==================================================================================================== end
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
