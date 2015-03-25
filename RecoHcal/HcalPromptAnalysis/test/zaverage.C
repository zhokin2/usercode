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

	TFile *hfile1= new TFile("test.root", "READ"); 
//
//	TFile *hfile1= new TFile("testRunDepCap32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepWidth32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepADCampl32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepRatio32.root", "READ"); 

//	TFile *hfile1= new TFile("testNZS.root", "READ"); 
//	TFile *hfile1= new TFile("test5123.root", "READ"); 
//	TFile *hfile1= new TFile("test17Jule.root", "READ"); 
	//	TFile *hfile1= new TFile("test224.root", "READ"); 

	//    getchar();
	//
          TPostScript psfile ("zaverage.ps", 111);
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
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped0_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped0_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped1_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped1_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped2_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped2_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped3_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped3_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped0_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped0_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped1_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped1_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped2_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped2_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped3_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped3_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ped0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Ped0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ped1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Ped1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ped2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Ped2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Ped3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Ped3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped0_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped0_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped1_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped1_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped2_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped2_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Ped3_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Ped3_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped0_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped0_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped1_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped1_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped2_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped2_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Ped3_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Ped3_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Ped0_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Ped0_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Ped1_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Ped1_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Ped2_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Ped2_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Ped3_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Ped3_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw0_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw0_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw1_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw1_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw2_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw2_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw3_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw3_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw0_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw0_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw1_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw1_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw2_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw2_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw3_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw3_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Pedw0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Pedw0_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Pedw1_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Pedw1_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Pedw2_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Pedw2_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3Pedw3_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth3Pedw3_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw0_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw0_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw1_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw1_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw2_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw2_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Pedw3_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth1Pedw3_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw0_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw0_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw1_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw1_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw2_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw2_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2Pedw3_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth2Pedw3_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Pedw0_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Pedw0_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Pedw1_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Pedw1_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Pedw2_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Pedw2_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Pedw3_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("mapDepth4Pedw3_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================17
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal0_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapGetRMSOverNormalizedSignal_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal0_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapGetRMSOverNormalizedSignal_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal0_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapGetRMSOverNormalizedSignal_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapGetRMSOverNormalizedSignal0_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapGetRMSOverNormalizedSignal_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->Update();
      
      
    //===============================================================================================18
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth1ADCAmpl12_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl12_HB");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth2ADCAmpl12_HB \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth1ADCAmpl12_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl12_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth2ADCAmpl12_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
            
      c1->Update();
      
    //===============================================================================================19
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3ADCAmpl12_HE");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth3ADCAmpl12_HE \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth1ADCAmpl12_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl12_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth2ADCAmpl12_HF \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl12_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
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
      Ceff->GetZaxis()->SetLabelSize(0.08);
      Ceff->SetXTitle("#eta \b");
      Ceff->SetYTitle("#phi \b");
      Ceff->SetZTitle("h_mapDepth4ADCAmpl12_HO \b");
      Ceff->SetMarkerColor(2);
      Ceff->SetLineColor(2);
//      Ceff->SetMaximum(1.000);
      // Ceff->SetMinimum(0.1);
      Ceff->Draw("COLZ");
            
            
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
