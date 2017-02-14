{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
				gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

//	TFile *hfile1= new TFile("test234457.root", "READ");
	//	TFile *hfile1= new TFile("test211006.root", "READ"); 
//	TFile *hfile1= new TFile("testNZS.root", "READ"); 
//	TFile *hfile1= new TFile("test22LED.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229713.root", "READ");
	//	TFile *hfile1= new TFile("test.root", "READ");

//
//	TFile *hfile1= new TFile("testRunDepCap32.root", "READ"); 
//	TFile *hfile1= new TFile("testRunDepWidth32.root", "READ"); 
//
//	TFile *hfile1= new TFile("Pedestal_238255.root", "READ");
//	TFile *hfile1= new TFile("Laser_238183.root", "READ");

	TFile *hfile1= new TFile("Global_test.root", "READ");
	//    getchar();
	//
          TPostScript psfile ("zcerrorA.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1 
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HB");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
//      aaaaaa1->SetMaximum(10000000000);
//      aaaaaa1->SetMinimum(0.8);
      gPad->SetGridx();
      aaaaaa1->Draw("");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225Copy_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HB amplitude < 40.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");
            


      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225Copy_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth2ADCAmpl_HB amplitude < 40.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");

      c1->Update();
    //=============================================================================================== 2 
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HE");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HE \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
//      aaaaaa1->SetMaximum(10000000000);
//      aaaaaa1->SetMinimum(0.8);
      gPad->SetGridx();
      aaaaaa1->Draw("");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225Copy_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HE amplitude < 40.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");
            


      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225Copy_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth2ADCAmpl_HE amplitude < 40.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");


      c1->cd(4);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3ADCAmpl225Copy_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth3ADCAmpl_HE amplitude < 40.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");



      c1->Update();
    //=============================================================================================== 3 
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HF");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HF \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
//      aaaaaa1->SetMaximum(10000000000);
//      aaaaaa1->SetMinimum(0.8);
      gPad->SetGridx();
      aaaaaa1->Draw("");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225Copy_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HF amplitude < 20.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");
            


      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl225Copy_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth2ADCAmpl_HF amplitude < 20.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");

      c1->Update();
    //=============================================================================================== 4 
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmplZoom1_HO");
      gPad->SetLogy();
//      gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HO \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
//      aaaaaa1->SetMaximum(10000000000);
//      aaaaaa1->SetMinimum(0.8);
      gPad->SetGridx();
      aaaaaa1->Draw("");

      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl225Copy_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff225 = (TH2F*)twod1->Clone("Ceff225");
	Ceff225->Divide(twod1,twod0, 1, 1, "B");
	Ceff225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Ceff225->SetMarkerStyle(20);
      Ceff225->SetMarkerSize(0.4);
      //      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth4ADCAmpl_HO amplitude < 100.\b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
      Ceff225->Draw("COLZ");
            



      c1->Update();
    //======================================================================
    //============================================================================================ end
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
