{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
		//
		//
		//
		//
				gStyle->SetOptStat(0);   //  no statistics _or_
				// gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


		//
		//
		//
		//
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
//	gStyle->SetOptStat(101110);// entries, meam, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!
	//  gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(101110); // entries, mean, rms, overflow !!!!!!!!!!!!!!!!!!!!!!!!!!
		//
		//
		//
		//
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

//	TFile *hfile1= new TFile("testNZS.root", "READ"); 
	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229713.root", "READ");
	//	TFile *hfile1= new TFile("test.root", "READ"); 
//
	//    getchar();
	//
          TPostScript psfile ("zpedestals.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal0_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal0 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal1_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal1 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal2_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal2 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal3_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal3 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver4_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal4 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //    aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver9_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal9 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw0_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma0 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw1_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma1 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw2_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma2 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw3_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma3 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver4_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma4 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver9_HB");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma9 HB \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal0_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal0 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal1_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal1 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal2_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal2 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal3_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal3 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver4_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal4 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver9_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal9 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw0_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma0 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw1_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma1 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw2_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma2 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw3_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma3 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver4_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma4 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver9_HE");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma9 HE \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal0_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal0 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal1_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal1 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal2_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal2 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal3_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal3 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver4_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal4 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver9_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal9 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw0_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma0 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw1_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma1 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw2_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma2 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw3_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma3 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver4_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma4 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver9_HF");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma9 HF \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal0_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal0 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal1_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal1 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal2_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal2 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestal3_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal3 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver4_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal4 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalaver9_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestal9 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,3);
      
      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw0_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma0 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw1_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma1 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw2_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma2 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalw3_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma3 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(5);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver4_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma4 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      c1->cd(6);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_pedestalwaver9_HO");
         gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("pedestalSigma9 HO \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(4);
      //aaaaaa1->SetMinimum(0.9);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      
    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestalw_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HB Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestalw_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HB Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestalw_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HE Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestalw_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HE Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3pedestalw_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HE Depth3 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestalw_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HF Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestalw_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HF Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4pedestalw_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: pedestalSigma > 5_Sig - HO Depth4 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.00001);
      Cefz225->Draw("COLZ");
      
      c1->Update();
    //======================================================================
    //============================================================================================== 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestal_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HB Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestal_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HB Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestal_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HE Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestal_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HE Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      c1->cd(3);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth3pedestal_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth3_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HE Depth3 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1pedestal_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HF Depth1 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2pedestal_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HF Depth2 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
      
      c1->Update();
    //============================================================================================== 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4pedestal_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz225= (TH2F*)twod1->Clone("Cefz225");
	Cefz225->Divide(twod1,twod0, 1, 1, "B");
	Cefz225->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetZTitle("Rate: tails of pedestals - HO Depth4 \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      Cefz225->SetMaximum(1.000);
      Cefz225->SetMinimum(0.001);
      Cefz225->Draw("COLZ");
      
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
