{
   //======================================================================
      printf("reco: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	//		gStyle->SetOptStat(0);   //  no statistics _or_
	//	        	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//	gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
//	TFile *hfile1= new TFile("Global_234034.root", "READ");
//	TFile *hfile1= new TFile("Global_255031.root", "READ");
//	TFile *hfile1= new TFile("Global_234193.root", "READ");
//	TFile *hfile1= new TFile("newruns/Global_234034.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/CMTweb/histos/Global_234556.root", "READ");

//	TFile *hfile1= new TFile("test.root", "READ"); 
//	TFile *hfile1= new TFile("testNZS.root", "READ"); 

//	TFile *hfile1= new TFile("Global_255031.root", "READ");

//	TFile *hfile1= new TFile("Global_256001.root", "READ");
//	TFile *hfile1= new TFile("Global_256167.root", "READ");
// 	TFile *hfile1= new TFile("Global_256348.root", "READ");
//	TFile *hfile1= new TFile("Global_256630.root", "READ");
	TFile *hfile1= new TFile("Global_test.root", "READ");


	//    getchar();
	//
          TPostScript psfile ("zRunLS.ps", 111);
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
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nevents_per_eachRealLS");
      int MaxLumReal= aaaaaa1->GetBinContent(aaaaaa1->GetMaximumBin());
      cout<<" MaxLumReal=     "<< MaxLumReal <<endl;
//            gPad->SetLogy();
      //            gPad->SetLogx();
      gPad->SetGridy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#ev per LS \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");

      int maxbins = 0;
      for (int i=1;i<=aaaaaa1->GetXaxis()->GetNbins();i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
	if(ccc1>0.) {maxbins = i; }
//	if(ccc1>0.) maxbins++;
      }
      cout<<" maxbins=     "<< maxbins <<endl;


//      cout<<"*************************    eachRealLS   nx =     " << nx <<endl;
      //    for (int i=1;i<=nx;i++) {
//      for (int i=1;i<=100;i++) {
//	double ccc1 =  aaaaaa1->GetBinContent(i)   ;
	//	if(ccc1>0) cout<<"iLS =     " << i <<" Nev = "<<ccc1<<endl;
	//	if(ccc1<1) cout<<"iLS =     " << i <<" Nev = "<<ccc1<<endl;
	//	if(ccc1>0) cout<<" i = "<<i<<" #ev per iLS= "<<ccc1<<endl;
//	if(i == 227) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 241) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 242) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 243) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 322) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//      }

      c1->cd(2);

      TH1F* ADCAmplperLS  = new TH1F("ADCAmplperLS ","", maxbins, 1.,maxbins+1.    );
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
//		  if(i<maxbins)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;

	  ADCAmplperLS ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS ->SetMarkerStyle(20);
      ADCAmplperLS ->SetMarkerSize(0.8);
      ADCAmplperLS ->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS ->SetXTitle("#ev per LS \b");
      ADCAmplperLS ->SetMarkerColor(4);
      ADCAmplperLS ->SetLineColor(0);
      ADCAmplperLS ->SetMinimum(0.8);
      ADCAmplperLS ->Draw("Error");

      int icount0=0;
      int icount=0;
      int nx = ADCAmplperLS->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ADCAmplperLS->GetBinContent(i)   ;
	if(ccc1>0.) icount0++;
	//	if(ccc1<4400.&& ccc1>0.)) {
	if( ccc1>0.)) {
	  icount++;
//	  cout<<"Dots,limited, depth1_HB LS = "<<i<<" #ev per LS= "<<ccc1<<endl;
	}
      }
//	  cout<<"*************************************** "<<endl;
//	  cout<<"Dots,Bigger 0.0, depth1_HB icount = "<<icount0<<endl;
//	  cout<<"Dots,Bigger limited, depth1_HB icount = "<<icount<<endl;


      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nevents_per_eachLS");

      int maxbins3= 0;
      for (int i=1;i<=aaaaaa1->GetXaxis()->GetNbins();i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) {maxbins3= i; if(i>maxbins3) maxbins3 = i;}
	if(ccc1>0.) {maxbins3= i; }
//	if(ccc1>0.) maxbins3++;
      }
      cout<<" maxbins3=     "<< maxbins3 <<endl;
      aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins3+1.);

            gPad->SetLogy();
      //            gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#ev per iLS \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(1);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      //      cout<<"eachLS   nx =     " << nx <<endl;
      //    for (int i=1;i<=nx;i++) {
      for (int i=1;i<=100;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i)   ;
	//	if(ccc1<1) cout<<"iLS =     " << i <<" Nev = "<<ccc1<<endl;
	//	if(ccc1>0) cout<<"iLS =     " << i <<" Nev = "<<ccc1<<endl;
	//	if(ccc1>0) cout<<" i = "<<i<<" #ev per iLS= "<<ccc1<<endl;
//	if(i == 227) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 241) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 242) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 243) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
//	if(i == 322) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
      }
 
      c1->cd(4);
      TH1F *aaaaaa9= (TH1F*)hfile1->Get("h_lsnumber_per_eachLS");
      int MaxLum= aaaaaa9->GetBinContent(aaaaaa9->GetMaximumBin());
      cout<<" MaxLum=     "<< MaxLum <<endl;

      int maxbins4= 0;
      for (int i=1;i<=aaaaaa9->GetXaxis()->GetNbins();i++) {
	double ccc1 =  aaaaaa9->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) {maxbins4= i; if(i>maxbins4) maxbins4 = i;}
	if(ccc1>0.) {maxbins4= i; }
//	if(ccc1>0.) maxbins4++;
      }
      cout<<" maxbins4=     "<< maxbins4 <<endl;
      aaaaaa9->GetXaxis()->SetRangeUser(0, maxbins4+1.);

      aaaaaa9->SetMarkerStyle(20);
      aaaaaa9->SetMarkerSize(0.8);
      aaaaaa9->GetYaxis()->SetLabelSize(0.04);
      aaaaaa9->SetXTitle("LSnumber per iLS \b");
      //    aaaaaa9->SetYTitle("Rate of events \b");
      aaaaaa9->SetMarkerColor(1);
      aaaaaa9->SetLineColor(0);
      aaaaaa9->SetMinimum(0.8);
      aaaaaa9->Draw("Error");
//      for (int i=1;i<=nx;i++) {
//	double ccc1 =  aaaaaa9->GetBinContent(i)   ;
      //	if(ccc1>0) cout<<" i = "<<i<<" LSnumber per iLS= "<<ccc1<<endl;
//	if(i == 227) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
//	if(i == 241) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
//	if(i == 242) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
//	if(i == 243) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
//	if(i == 322) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
//      }
      for (int i=1;i<=100;i++) {
	double ccc1 =  aaaaaa9->GetBinContent(i)   ;
	//	if(ccc1<1) cout<<"iLS =     " << i <<" Nev = "<<ccc1<<endl;
	//	if(ccc1>0) cout<<"iLS =  " << i <<" LS = "<<ccc1<<endl;
      }


      c1->Update();


    //=============================================================================================== 2
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      ADCAmplperLS ->Draw("Error");

      c1->cd(2);
//      TH1F* ADCAmplperLS1= new TH1F("ADCAmplperLS","", maxbins, 1., maxbins+1.);
          TH1F* ADCAmplperLS1 = new TH1F("Nev ","", 100, 300.,400.);
      int nx = ADCAmplperLS->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  ADCAmplperLS->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) ADCAmplperLS1->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      ADCAmplperLS1->SetMarkerStyle(20);
      ADCAmplperLS1->SetMarkerSize(0.4);
      ADCAmplperLS1->GetYaxis()->SetLabelSize(0.04);
      ADCAmplperLS1->SetXTitle("#ev per LS \b");
      ADCAmplperLS1->SetMarkerColor(2);
      ADCAmplperLS1->SetLineColor(0);
      ADCAmplperLS1->SetMaximum(5000.0);
      ADCAmplperLS1->SetMinimum(0.0);
      ADCAmplperLS1->Draw("Error");

      c1->Update();
    //=============================================================================================== 3
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_averSIGNALoccupancy_HB");
if(aaaaaa1) aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("averSIGNALoccupancy per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
//      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_averSIGNALoccupancy_HE");
		if(aaaaaa2) aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("averSIGNALoccupancy per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
//      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_averSIGNALoccupancy_HF");
		if(aaaaaa3) aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("averSIGNALoccupancy per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
//      aaaaaa3->SetMinimum(0.8);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_averSIGNALoccupancy_HO");
		if(aaaaaa4) aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("averSIGNALoccupancy per LS  HO    \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
//      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();




    //=============================================================================================== 4
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F* awer4 = new TH1F("awer4","", maxbins, 1., maxbins+1.);
//          TH1F* awer4  = new TH1F("h_averSIGNALoccupancy_HB ","", 200, 200.,400.);
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) awer4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      awer4 ->SetMarkerStyle(20);
      awer4 ->SetMarkerSize(0.6);
      awer4 ->GetYaxis()->SetLabelSize(0.04);
      awer4 ->SetXTitle("averSIGNALoccupancy per LS HB \b");
      awer4 ->SetMarkerColor(2);
      awer4 ->SetLineColor(0);
//       awer4 ->SetMaximum(0.4);
//       awer4 ->SetMinimum(0.0);
      gPad->SetGridx();
      awer4 ->Draw("Error");


      c1->cd(2);
      TH1F* sdrf4 = new TH1F("sdrf4","", maxbins, 1., maxbins+1.);
//          TH1F* sdrf4  = new TH1F("h_averSIGNALoccupancy_HE ","", 200, 200.,400.);
      int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) sdrf4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      sdrf4 ->SetMarkerStyle(20);
      sdrf4 ->SetMarkerSize(0.6);
      sdrf4 ->GetYaxis()->SetLabelSize(0.04);
      sdrf4 ->SetXTitle("averSIGNALoccupancy per LS HE \b");
      sdrf4 ->SetMarkerColor(2);
      sdrf4 ->SetLineColor(0);
//       sdrf4 ->SetMaximum(2.);
//       sdrf4 ->SetMinimum(0.0);
      gPad->SetGridx();
      sdrf4 ->Draw("Error");

      c1->cd(3);
      TH1F* dfty4 = new TH1F("dfty4","", maxbins, 1., maxbins+1.);
//          TH1F* dfty4  = new TH1F("h_averSIGNALoccupancy_HF ","", 200, 200.,400.);
      int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) dfty4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      dfty4 ->SetMarkerStyle(20);
      dfty4 ->SetMarkerSize(0.6);
      dfty4 ->GetYaxis()->SetLabelSize(0.04);
      dfty4 ->SetXTitle("averSIGNALoccupancy per LS HF \b");
      dfty4 ->SetMarkerColor(2);
      dfty4 ->SetLineColor(0);
//       dfty4 ->SetMaximum(1.0);
//       dfty4 ->SetMinimum(0.0);
      gPad->SetGridx();
      dfty4 ->Draw("Error");

      c1->cd(4);
      TH1F* mkiu4 = new TH1F("mkiu4","", maxbins, 1., maxbins+1.);
//          TH1F* mkiu4  = new TH1F("h_averSIGNALoccupancy_HO ","", 200, 200.,400.);
      int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) mkiu4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      mkiu4 ->SetMarkerStyle(20);
      mkiu4 ->SetMarkerSize(0.6);
      mkiu4 ->GetYaxis()->SetLabelSize(0.04);
      mkiu4 ->SetXTitle("averSIGNALoccupancy per LS H0 \b");
      mkiu4 ->SetMarkerColor(2);
      mkiu4 ->SetLineColor(0);
//       mkiu4 ->SetMaximum(1.06);
//       mkiu4 ->SetMinimum(0.96);
      gPad->SetGridx();
      mkiu4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 5
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_averSIGNALsumamplitude_HB");
		aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("averSIGNALsumamplitude per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_averSIGNALsumamplitude_HE");
		aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("averSIGNALsumamplitude  per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_averSIGNALsumamplitude_HF");
		aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("averSIGNALsumamplitude  per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
      aaaaaa3->SetMinimum(0.8);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_averSIGNALsumamplitude_HO");
		aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("averSIGNALsumamplitude  per LS  HO )   \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();




    //=============================================================================================== 6
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F* zasr4 = new TH1F("zasr4","", maxbins, 1., maxbins+1.);
//          TH1F* zasr4  = new TH1F("h_averSIGNALsumamplitude_HB ","", 200, 200.,400.);
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) zasr4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      zasr4 ->SetMarkerStyle(20);
      zasr4 ->SetMarkerSize(0.4);
      zasr4 ->GetYaxis()->SetLabelSize(0.04);
      zasr4 ->SetXTitle("averSIGNALsumamplitude  per LS HB \b");
      zasr4 ->SetMarkerColor(2);
      zasr4 ->SetLineColor(0);
//      zasr4 ->SetMaximum(500.);
//      zasr4 ->SetMinimum(0.0);
      gPad->SetGridx();
      zasr4 ->Draw("Error");


      c1->cd(2);
      TH1F* vfdr4 = new TH1F("vfdr4","", maxbins, 1., maxbins+1.);
//          TH1F* vfdr4  = new TH1F("h_averSIGNALsumamplitude_HE ","", 200, 200.,400.);
      int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) vfdr4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      vfdr4 ->SetMarkerStyle(20);
      vfdr4 ->SetMarkerSize(0.4);
      vfdr4 ->GetYaxis()->SetLabelSize(0.04);
      vfdr4 ->SetXTitle("averSIGNALsumamplitude  per LS HE \b");
      vfdr4 ->SetMarkerColor(2);
      vfdr4 ->SetLineColor(0);
//      vfdr4 ->SetMaximum(1000.);
//      vfdr4 ->SetMinimum(0.0);
      gPad->SetGridx();
      vfdr4 ->Draw("Error");

      c1->cd(3);
      TH1F* uiop4 = new TH1F("uiop4","", maxbins, 1., maxbins+1.);
//          TH1F* uiop4  = new TH1F("h_averSIGNALsumamplitude_HF ","", 200, 200.,400.);
      int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) uiop4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uiop4 ->SetMarkerStyle(20);
      uiop4 ->SetMarkerSize(0.4);
      uiop4 ->GetYaxis()->SetLabelSize(0.04);
      uiop4 ->SetXTitle("averSIGNALsumamplitude  per LS HF \b");
      uiop4 ->SetMarkerColor(2);
      uiop4 ->SetLineColor(0);
//      uiop4 ->SetMaximum(1400.);
//      uiop4 ->SetMinimum(0.0);
      gPad->SetGridx();
      uiop4 ->Draw("Error");

      c1->cd(4);
      TH1F* dfgh4 = new TH1F("dfgh4","", maxbins, 1., maxbins+1.);
//          TH1F* dfgh4  = new TH1F("h_averSIGNALsumamplitude_HO ","", 200, 200.,400.);
      int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) dfgh4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      dfgh4 ->SetMarkerStyle(20);
      dfgh4 ->SetMarkerSize(0.4);
      dfgh4 ->GetYaxis()->SetLabelSize(0.04);
      dfgh4 ->SetXTitle("averSIGNALsumamplitude  per LS H0 \b");
      dfgh4 ->SetLineColor(0);
      dfgh4 ->SetMarkerColor(2);
//dfgh4 ->SetMaximum(18700.);
//dfgh4 ->SetMinimum(0.);
      gPad->SetGridx();
      dfgh4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 7
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_averNOSIGNALoccupancy_HB");
		aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("averNOSIGNALoccupancy per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
//      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_averNOSIGNALoccupancy_HE");
		aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("averNOSIGNALoccupancy per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
//      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_averNOSIGNALoccupancy_HF");
		aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("averNOSIGNALoccupancy per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
//      aaaaaa3->SetMinimum(0.8);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_averNOSIGNALoccupancy_HO");
		aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("averNOSIGNALoccupancy per LS  HO    \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
//      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();





    //=============================================================================================== 8
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
if (awer4) delete awer4;
if (sdrf4) delete sdrf4;
if (dfty4) delete dfty4;
if (mkiu4) delete mkiu4;
      TH1F* awer4 = new TH1F("awer4","", maxbins, 1., maxbins+1.);
//          TH1F* awer4  = new TH1F("h_averNOSIGNALoccupancy_HB ","", 200, 200.,400.);
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) awer4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      awer4 ->SetMarkerStyle(20);
      awer4 ->SetMarkerSize(0.6);
      awer4 ->GetYaxis()->SetLabelSize(0.04);
      awer4 ->SetXTitle("averNOSIGNALoccupancy per LS HB \b");
      awer4 ->SetMarkerColor(2);
      awer4 ->SetLineColor(0);
//       awer4 ->SetMaximum(0.4);
//       awer4 ->SetMinimum(0.0);
      gPad->SetGridx();
      awer4 ->Draw("Error");


      c1->cd(2);
      TH1F* sdrf4 = new TH1F("sdrf4","", maxbins, 1., maxbins+1.);
//          TH1F* sdrf4  = new TH1F("h_averNOSIGNALoccupancy_HE ","", 200, 200.,400.);
      int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) sdrf4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      sdrf4 ->SetMarkerStyle(20);
      sdrf4 ->SetMarkerSize(0.6);
      sdrf4 ->GetYaxis()->SetLabelSize(0.04);
      sdrf4 ->SetXTitle("averNOSIGNALoccupancy per LS HE \b");
      sdrf4 ->SetMarkerColor(2);
      sdrf4 ->SetLineColor(0);
//       sdrf4 ->SetMaximum(2.);
//       sdrf4 ->SetMinimum(0.0);
      gPad->SetGridx();
      sdrf4 ->Draw("Error");

      c1->cd(3);
      TH1F* dfty4 = new TH1F("dfty4","", maxbins, 1., maxbins+1.);
//          TH1F* dfty4  = new TH1F("h_averNOSIGNALoccupancy_HF ","", 200, 200.,400.);
      int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) dfty4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      dfty4 ->SetMarkerStyle(20);
      dfty4 ->SetMarkerSize(0.6);
      dfty4 ->GetYaxis()->SetLabelSize(0.04);
      dfty4 ->SetXTitle("averNOSIGNALoccupancy per LS HF \b");
      dfty4 ->SetMarkerColor(2);
      dfty4 ->SetLineColor(0);
       dfty4 ->SetMaximum(866);
       dfty4 ->SetMinimum(856);
      gPad->SetGridx();
      dfty4 ->Draw("Error");

      c1->cd(4);
      TH1F* mkiu4 = new TH1F("mkiu4","", maxbins, 1., maxbins+1.);
//          TH1F* mkiu4  = new TH1F("h_averNOSIGNALoccupancy_HO ","", 200, 200.,400.);
      int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) mkiu4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      mkiu4 ->SetMarkerStyle(20);
      mkiu4 ->SetMarkerSize(0.6);
      mkiu4 ->GetYaxis()->SetLabelSize(0.04);
      mkiu4 ->SetXTitle("averNOSIGNALoccupancy per LS H0 \b");
      mkiu4 ->SetMarkerColor(2);
      mkiu4 ->SetLineColor(0);
//       mkiu4 ->SetMaximum(1.06);
//       mkiu4 ->SetMinimum(0.96);
      gPad->SetGridx();
      mkiu4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 9
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_averNOSIGNALsumamplitude_HB");
		aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("averNOSIGNALsumamplitude per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_averNOSIGNALsumamplitude_HE");
		aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("averNOSIGNALsumamplitude  per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_averNOSIGNALsumamplitude_HF");
		aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("averNOSIGNALsumamplitude  per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
      aaaaaa3->SetMinimum(0.8);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_averNOSIGNALsumamplitude_HO");
		aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("averNOSIGNALsumamplitude  per LS  HO )   \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();




    //=============================================================================================== 10
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

if (zasr4) delete zasr4;
if (vfdr4) delete vfdr4;
if (uiop4) delete uiop4;
if (dfgh4) delete dfgh4;
      c1->cd(1);
      TH1F* zasr4 = new TH1F("zasr4","", maxbins, 1., maxbins+1.);
//          TH1F* zasr4  = new TH1F("h_averNOSIGNALsumamplitude_HB ","", 200, 200.,400.);
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) zasr4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      zasr4 ->SetMarkerStyle(20);
      zasr4 ->SetMarkerSize(0.4);
      zasr4 ->GetYaxis()->SetLabelSize(0.04);
      zasr4 ->SetXTitle("averNOSIGNALsumamplitude  per LS HB \b");
      zasr4 ->SetMarkerColor(2);
      zasr4 ->SetLineColor(0);
//      zasr4 ->SetMaximum(500.);
//      zasr4 ->SetMinimum(0.0);
       gPad->SetGridx();
     zasr4 ->Draw("Error");


      c1->cd(2);
      TH1F* vfdr4 = new TH1F("vfdr4","", maxbins, 1., maxbins+1.);
//          TH1F* vfdr4  = new TH1F("h_averNOSIGNALsumamplitude_HE ","", 200, 200.,400.);
      int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) vfdr4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      vfdr4 ->SetMarkerStyle(20);
      vfdr4 ->SetMarkerSize(0.4);
      vfdr4 ->GetYaxis()->SetLabelSize(0.04);
      vfdr4 ->SetXTitle("averNOSIGNALsumamplitude  per LS HE \b");
      vfdr4 ->SetMarkerColor(2);
      vfdr4 ->SetLineColor(0);
//      vfdr4 ->SetMaximum(1000.);
//      vfdr4 ->SetMinimum(0.0);
      gPad->SetGridx();
      vfdr4 ->Draw("Error");

      c1->cd(3);
      TH1F* uiop4 = new TH1F("uiop4","", maxbins, 1., maxbins+1.);
//          TH1F* uiop4  = new TH1F("h_averNOSIGNALsumamplitude_HF ","", 200, 200.,400.);
      int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) uiop4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uiop4 ->SetMarkerStyle(20);
      uiop4 ->SetMarkerSize(0.4);
      uiop4 ->GetYaxis()->SetLabelSize(0.04);
      uiop4 ->SetXTitle("averNOSIGNALsumamplitude  per LS HF \b");
      uiop4 ->SetMarkerColor(2);
      uiop4 ->SetLineColor(0);
//      uiop4 ->SetMaximum(1400.);
//      uiop4 ->SetMinimum(0.0);
       gPad->SetGridx();
     uiop4 ->Draw("Error");

      c1->cd(4);
      TH1F* dfgh4 = new TH1F("dfgh4","", maxbins, 1., maxbins+1.);
//          TH1F* dfgh4  = new TH1F("h_averNOSIGNALsumamplitude_HO ","", 200, 200.,400.);
      int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) dfgh4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      dfgh4 ->SetMarkerStyle(20);
      dfgh4 ->SetMarkerSize(0.4);
      dfgh4 ->GetYaxis()->SetLabelSize(0.04);
      dfgh4 ->SetXTitle("averNOSIGNALsumamplitude  per LS H0 \b");
      dfgh4 ->SetLineColor(0);
      dfgh4 ->SetMarkerColor(2);
//dfgh4 ->SetMaximum(18700.);
//dfgh4 ->SetMinimum(0.);
      gPad->SetGridx();
      dfgh4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 11
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nls_per_run");
      //      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#LS in run \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      //aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nls_per_run");
            gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#LS in run at #ev/LS > 10 \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      //aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nevents_per_LS");
            gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#ev in iLS \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      //aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      c1->cd(4);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nevents_per_LSzoom");
            gPad->SetLogy();
	    //            gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#ev in iLS \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      //aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      

    //=============================================================================================== 12
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_maxxSUMAmpl_HB");
		aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("SumA maxx per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
//      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_maxxSUMAmpl_HE");
		aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("SumA maxx per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
//      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_maxxSUMAmpl_HF");
		aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("SumA maxx per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
 //     aaaaaa3->SetMinimum(0.8);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_maxxSUMAmpl_HO");
		aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("SumA maxx per LS  HO   \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
//      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();




    //=============================================================================================== 13
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F* sder4 = new TH1F("sder4","", maxbins, 1., maxbins+1.);
//          TH1F* sder4  = new TH1F("h_maxxSUMAmpl_HB ","", 200, 200.,400.);
//    int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=maxbins;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
//			  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) sder4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      sder4 ->SetMarkerStyle(20);
      sder4 ->SetMarkerSize(0.4);
      sder4 ->GetYaxis()->SetLabelSize(0.04);
      sder4 ->SetXTitle("SumA maxx per LS HB \b");
      sder4 ->SetMarkerColor(2);
      sder4 ->SetLineColor(0);
//      sder4 ->SetMaximum(17000.);
//      sder4 ->SetMinimum(8000.0);
      gPad->SetGridx();
      sder4 ->Draw("Error");


      c1->cd(2);
      TH1F* lopi4 = new TH1F("lopi4","", maxbins, 1., maxbins+1.);
//         TH1F* lopi4  = new TH1F("h_maxxSUMAmpl_HE ","", 200, 200.,400.);
//    int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=maxbins;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
//		  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) lopi4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      lopi4 ->SetMarkerStyle(20);
      lopi4 ->SetMarkerSize(0.4);
      lopi4 ->GetYaxis()->SetLabelSize(0.04);
      lopi4 ->SetXTitle("SumA maxx per LS HE \b");
      lopi4 ->SetMarkerColor(2);
      lopi4 ->SetLineColor(0);
//      lopi4 ->SetMaximum(30000.);
//      lopi4 ->SetMinimum(0.0);
      gPad->SetGridx();
      lopi4 ->Draw("Error");

      c1->cd(3);
      TH1F* qasd4 = new TH1F("qasd4","", maxbins, 1., maxbins+1.);
//          TH1F* qasd4  = new TH1F("h_maxxOCCUP_HF ","", 200, 200.,400.);
//    int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=maxbins;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
//		  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qasd4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qasd4 ->SetMarkerStyle(20);
      qasd4 ->SetMarkerSize(0.4);
      qasd4 ->GetYaxis()->SetLabelSize(0.04);
      qasd4 ->SetXTitle("SumA maxx per LS HF \b");
      qasd4 ->SetMarkerColor(2);
      qasd4 ->SetLineColor(0);
//      qasd4 ->SetMaximum(75000.);
//      qasd4 ->SetMinimum(15000.0);
      gPad->SetGridx();
      qasd4 ->Draw("Error");

      c1->cd(4);
      TH1F* mnbv4 = new TH1F("mnbv4","", maxbins, 1., maxbins+1.);
//          TH1F* mnbv4  = new TH1F("h_SumA of low A channels_HO ","", 200, 200.,400.);
//    int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=maxbins;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
//		  cout<<" depth1_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) mnbv4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      mnbv4 ->SetMarkerStyle(20);
      mnbv4 ->SetMarkerSize(0.4);
      mnbv4 ->GetYaxis()->SetLabelSize(0.04);
      mnbv4 ->SetXTitle("SumA maxx per LS H0 \b");
      mnbv4 ->SetMarkerColor(2);
      mnbv4 ->SetLineColor(0);
//    mnbv4 ->SetMaximum(15000.);
//    mnbv4 ->SetMinimum(12000.);
//      mnbv4 ->SetMaximum(13000.);
//      mnbv4 ->SetMinimum(10000.);
      gPad->SetGridx();
      mnbv4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 14
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *bbbbbb1= (TH1F*)hfile1->Get("h_sumamplitudechannel_HB");
            gPad->SetLogy();
      bbbbbb1->SetMarkerStyle(20);
      bbbbbb1->SetMarkerSize(0.8);
      bbbbbb1->GetYaxis()->SetLabelSize(0.04);
      bbbbbb1->SetXTitle("sumamplitudechannel HB \b");
      //    bbbbbb1->SetYTitle("Rate of events \b");
      bbbbbb1->SetMarkerColor(2);
      bbbbbb1->SetLineColor(2);
      bbbbbb1->SetMinimum(0.8);
//      TLine (200., 0.8, 200., 10000.);
      bbbbbb1->Draw("");
      //TLine *l=new TLine(bbbbbb1->GetUxmin(),3.0,bbbbbb1->GetUxmax(),3.0);
//      TLine *l=new TLine(80., 0.8, 80., 1000.);
TLine *l=new TLine(80., 0.8, 80., bbbbbb1->GetBinContent(4)+100.);
//      int MaxLumDanila= LumLum->GetBinContent(LumLum->GetMaximumBin());// old variant of Danila
      l->SetLineColor(kBlue);
      l->Draw("s");

      c1->cd(2);
      TH1F *bbbbbb2= (TH1F*)hfile1->Get("h_sumamplitudechannel_HE");
            gPad->SetLogy();
      bbbbbb2->SetMarkerStyle(20);
      bbbbbb2->SetMarkerSize(0.8);
      bbbbbb2->GetYaxis()->SetLabelSize(0.04);
      bbbbbb2->SetXTitle("sumamplitudechannel HE \b");
      //    bbbbbb2->SetYTitle("Rate of events \b");
      bbbbbb2->SetMarkerColor(2);
      bbbbbb2->SetLineColor(2);
      bbbbbb2->SetMinimum(0.8);
      bbbbbb2->Draw("");
//      TLine *l=new TLine(200., 0.8, 200., 1000.);
      TLine *l=new TLine(200., 0.8, 200., bbbbbb2->GetBinContent(7)+100.);
      l->SetLineColor(kBlue);
      l->Draw("s");

      c1->cd(3);
      TH1F *bbbbbb3= (TH1F*)hfile1->Get("h_sumamplitudechannel_HF");
            gPad->SetLogy();
      bbbbbb3->SetMarkerStyle(20);
      bbbbbb3->SetMarkerSize(0.8);
      bbbbbb3->GetYaxis()->SetLabelSize(0.04);
      bbbbbb3->SetXTitle("sumamplitudechannel HF \b");
      //    bbbbbb3->SetYTitle("Rate of events \b");
      bbbbbb3->SetMarkerColor(2);
      bbbbbb3->SetLineColor(2);
      bbbbbb3->SetMinimum(0.8);
      bbbbbb3->Draw("");
      TLine *l=new TLine(1200., 0.8, 1200., bbbbbb3->GetBinContent(17)+100.);
      l->SetLineColor(kBlue);
      l->Draw("s");

      c1->cd(4);
      TH1F *bbbbbb4= (TH1F*)hfile1->Get("h_sumamplitudechannel_HO");
            gPad->SetLogy();
      bbbbbb4->SetMarkerStyle(20);
      bbbbbb4->SetMarkerSize(0.8);
      bbbbbb4->GetYaxis()->SetLabelSize(0.04);
      bbbbbb4->SetXTitle("sumamplitudechannel HO \b");
      //    bbbbbb4->SetYTitle("Rate of events \b");
      bbbbbb4->SetMarkerColor(2);
      bbbbbb4->SetLineColor(2);
      bbbbbb4->SetMinimum(0.8);
      bbbbbb4->Draw("");
      TLine *l=new TLine(600., 0.8, 600., bbbbbb4->GetBinContent(6)+100.);
      l->SetLineColor(kBlue);
      l->Draw("s");



      c1->Update();
    //=============================================================================================== 15
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_maxxOCCUP_HB");
		aaaaaa1->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("Occup. maxx per LS  HB    \b");
//    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(4);
      aaaaaa1->SetLineColor(0);
//      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");



      c1->cd(2);
      TH1F *aaaaaa2= (TH1F*)hfile1->Get("h_maxxOCCUP_HE");
		aaaaaa2->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa2->SetMarkerStyle(20);
      aaaaaa2->SetMarkerSize(0.8);
      aaaaaa2->GetYaxis()->SetLabelSize(0.04);
      aaaaaa2->SetXTitle("Occup. maxx per LS  HE    \b");
//    aaaaaa2->SetYTitle("Rate of events \b");
      aaaaaa2->SetMarkerColor(4);
      aaaaaa2->SetLineColor(0);
//      aaaaaa2->SetMinimum(0.8);
      aaaaaa2->Draw("Error");

      c1->cd(3);
      TH1F *aaaaaa3= (TH1F*)hfile1->Get("h_maxxOCCUP_HF");
		aaaaaa3->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa3->SetMarkerStyle(20);
      aaaaaa3->SetMarkerSize(0.8);
      aaaaaa3->GetYaxis()->SetLabelSize(0.04);
      aaaaaa3->SetXTitle("Occup. maxx per LS  HF    \b");
//    aaaaaa3->SetYTitle("Rate of events \b");
      aaaaaa3->SetMarkerColor(4);
      aaaaaa3->SetLineColor(0);
//      aaaaaa3->SetMaximum(866.);
//      aaaaaa3->SetMinimum(861.);
      aaaaaa3->Draw("Error");

      c1->cd(4);
      TH1F *aaaaaa4= (TH1F*)hfile1->Get("h_maxxOCCUP_HO");
		aaaaaa4->GetXaxis()->SetRangeUser(0, maxbins+1.);
//            gPad->SetLogy();
//            gPad->SetLogx();
      gPad->SetGridx();
      aaaaaa4->SetMarkerStyle(20);
      aaaaaa4->SetMarkerSize(0.8);
      aaaaaa4->GetYaxis()->SetLabelSize(0.04);
      aaaaaa4->SetXTitle("Occup. maxx per LS  HO )   \b");
//    aaaaaa4->SetYTitle("Rate of events \b");
      aaaaaa4->SetMarkerColor(4);
      aaaaaa4->SetLineColor(0);
//      aaaaaa4->SetMinimum(0.8);
      aaaaaa4->Draw("Error");



      c1->Update();




    //=============================================================================================== 16
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,4);

      c1->cd(1);
      TH1F* lkfd4 = new TH1F("lkfd4","", maxbins, 1., maxbins+1.);
//          TH1F* lkfd4  = new TH1F("h_maxxOCCUP_HB ","", 200, 200.,400.);
      int nx = aaaaaa1->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) lkfd4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      lkfd4 ->SetMarkerStyle(20);
      lkfd4 ->SetMarkerSize(0.4);
      lkfd4 ->GetYaxis()->SetLabelSize(0.04);
      lkfd4 ->SetXTitle("Occup. maxx per LS HB \b");
      lkfd4 ->SetMarkerColor(2);
      lkfd4 ->SetLineColor(0);
//      lkfd4 ->SetMaximum(600.);
//      lkfd4 ->SetMinimum(300.0);
      gPad->SetGridx();
      lkfd4 ->Draw("Error");


      c1->cd(2);
      TH1F* bqpo4 = new TH1F("bqpo4","", maxbins, 1., maxbins+1.);
//          TH1F* bqpo4  = new TH1F("h_maxxOCCUP_HE ","", 200, 200.,400.);
      int nx = aaaaaa2->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa2->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) bqpo4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      bqpo4 ->SetMarkerStyle(20);
      bqpo4 ->SetMarkerSize(0.4);
      bqpo4 ->GetYaxis()->SetLabelSize(0.04);
      bqpo4 ->SetXTitle("Occup. maxx per LS HE \b");
      bqpo4 ->SetMarkerColor(2);
      bqpo4 ->SetLineColor(0);
//      bqpo4 ->SetMaximum(550.);
//      bqpo4 ->SetMinimum(0.0);
      gPad->SetGridx();
      bqpo4 ->Draw("Error");

      c1->cd(3);
      TH1F* vsrt4 = new TH1F("vsrt4","", maxbins, 1., maxbins+1.);
//          TH1F* vsrt4  = new TH1F("h_maxxOCCUP_HF ","", 200, 200.,400.);
      int nx = aaaaaa3->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa3->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) vsrt4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      vsrt4 ->SetMarkerStyle(20);
      vsrt4 ->SetMarkerSize(0.4);
      vsrt4 ->GetYaxis()->SetLabelSize(0.04);
      vsrt4 ->SetXTitle("Occup. maxx per LS HF \b");
      vsrt4 ->SetMarkerColor(2);
      vsrt4 ->SetLineColor(0);
//      vsrt4 ->SetMaximum(865.);
//      vsrt4 ->SetMinimum(862.0);
//      vsrt4 ->SetMaximum(865.);
//      vsrt4 ->SetMinimum(862.0);
      gPad->SetGridx();
      vsrt4 ->Draw("Error");

      c1->cd(4);
      TH1F* lqpa4 = new TH1F("lqpa4","", maxbins, 1., maxbins+1.);
//          TH1F* lqpa4  = new TH1F("h_maxxOCCUP_HO ","", 200, 200.,400.);
      int nx = aaaaaa4->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa4->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) lqpa4 ->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      lqpa4 ->SetMarkerStyle(20);
      lqpa4 ->SetMarkerSize(0.4);
      lqpa4 ->GetYaxis()->SetLabelSize(0.04);
      lqpa4 ->SetXTitle("Occup. maxx per LS H0 \b");
      lqpa4 ->SetMarkerColor(2);
      lqpa4 ->SetLineColor(0);
//      lqpa4 ->SetMaximum(160.);
//    lqpa4 ->SetMinimum(130.);
//      lqpa4 ->SetMaximum(110.);
//      lqpa4 ->SetMinimum(80.);
      gPad->SetGridx();
      lqpa4 ->Draw("Error");

      c1->Update();



    //=============================================================================================== 17
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *cccccc1= (TH1F*)hfile1->Get("h_eventamplitude_HB");
            gPad->SetLogy();
      cccccc1->SetMarkerStyle(20);
      cccccc1->SetMarkerSize(0.8);
      cccccc1->GetYaxis()->SetLabelSize(0.04);
      cccccc1->SetXTitle("eventamplitude HB \b");
      //    cccccc1->SetYTitle("Rate of events \b");
      cccccc1->SetMarkerColor(2);
      cccccc1->SetLineColor(2);
//      cccccc1->SetMinimum(0.8);
      cccccc1->Draw("");

      c1->cd(2);
      TH1F *cccccc2= (TH1F*)hfile1->Get("h_eventamplitude_HE");
            gPad->SetLogy();
      cccccc2->SetMarkerStyle(20);
      cccccc2->SetMarkerSize(0.8);
      cccccc2->GetYaxis()->SetLabelSize(0.04);
      cccccc2->SetXTitle("eventamplitude HE \b");
      //    cccccc2->SetYTitle("Rate of events \b");
      cccccc2->SetMarkerColor(2);
      cccccc2->SetLineColor(2);
//      cccccc2->SetMinimum(0.8);
      cccccc2->Draw("");

      c1->cd(3);
      TH1F *cccccc3= (TH1F*)hfile1->Get("h_eventamplitude_HF");
            gPad->SetLogy();
      cccccc3->SetMarkerStyle(20);
      cccccc3->SetMarkerSize(0.8);
      cccccc3->GetYaxis()->SetLabelSize(0.04);
      cccccc3->SetXTitle("eventamplitude HF \b");
      //    cccccc3->SetYTitle("Rate of events \b");
      cccccc3->SetMarkerColor(2);
      cccccc3->SetLineColor(2);
//      cccccc3->SetMinimum(0.8);
      cccccc3->Draw("");

      c1->cd(4);
      TH1F *cccccc4= (TH1F*)hfile1->Get("h_eventamplitude_HO");
            gPad->SetLogy();
      cccccc4->SetMarkerStyle(20);
      cccccc4->SetMarkerSize(0.8);
      cccccc4->GetYaxis()->SetLabelSize(0.04);
      cccccc4->SetXTitle("eventamplitude HO \b");
      //    cccccc4->SetYTitle("Rate of events \b");
      cccccc4->SetMarkerColor(2);
      cccccc4->SetLineColor(2);
//      cccccc4->SetMinimum(0.8);
      cccccc4->Draw("");



      c1->Update();
    //=============================================================================================== 18
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);

      c1->cd(1);
      TH1F *cccccc1= (TH1F*)hfile1->Get("h_eventoccupancy_HB");
            gPad->SetLogy();
      cccccc1->SetMarkerStyle(20);
      cccccc1->SetMarkerSize(0.8);
      cccccc1->GetYaxis()->SetLabelSize(0.04);
      cccccc1->SetXTitle("eventoccupancy HB \b");
      //    cccccc1->SetYTitle("Rate of events \b");
      cccccc1->SetMarkerColor(4);
      cccccc1->SetLineColor(4);
//      cccccc1->SetMinimum(0.8);
      cccccc1->Draw("");

      c1->cd(2);
      TH1F *cccccc2= (TH1F*)hfile1->Get("h_eventoccupancy_HE");
            gPad->SetLogy();
      cccccc2->SetMarkerStyle(20);
      cccccc2->SetMarkerSize(0.8);
      cccccc2->GetYaxis()->SetLabelSize(0.04);
      cccccc2->SetXTitle("eventoccupancy HE \b");
      //    cccccc2->SetYTitle("Rate of events \b");
      cccccc2->SetMarkerColor(4);
      cccccc2->SetLineColor(4);
//      cccccc2->SetMinimum(0.8);
      cccccc2->Draw("");

      c1->cd(3);
      TH1F *cccccc3= (TH1F*)hfile1->Get("h_eventoccupancy_HF");
            gPad->SetLogy();
      cccccc3->SetMarkerStyle(20);
      cccccc3->SetMarkerSize(0.8);
      cccccc3->GetYaxis()->SetLabelSize(0.04);
      cccccc3->SetXTitle("eventoccupancy HF \b");
      //    cccccc3->SetYTitle("Rate of events \b");
      cccccc3->SetMarkerColor(4);
      cccccc3->SetLineColor(4);
//      cccccc3->SetMinimum(0.8);
      cccccc3->Draw("");

      c1->cd(4);
      TH1F *cccccc4= (TH1F*)hfile1->Get("h_eventoccupancy_HO");
            gPad->SetLogy();
      cccccc4->SetMarkerStyle(20);
      cccccc4->SetMarkerSize(0.8);
      cccccc4->GetYaxis()->SetLabelSize(0.04);
      cccccc4->SetXTitle("eventoccupancy HO \b");
      //    cccccc4->SetYTitle("Rate of events \b");
      cccccc4->SetMarkerColor(4);
      cccccc4->SetLineColor(4);
//      cccccc4->SetMinimum(0.8);
      cccccc4->Draw("");



      c1->Update();

    //=============================================================================================== 19
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DAtaildepth1_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0Ataildepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* tail1= (TH2F*)twod1->Clone("tail1");
	tail1->Divide(twod1,twod0, 1, 1, "B");
	tail1->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      tail1->SetMarkerStyle(20);
      tail1->SetMarkerSize(0.4);
      tail1->SetXTitle("#eta \b");
      tail1->SetYTitle("#phi \b");
      tail1->SetZTitle("2D <A> in the tail - HB Depth1 \b");
      tail1->SetMarkerColor(2);
      tail1->SetLineColor(2);
      tail1->Draw("COLZ");
      c1->cd(2);
      TH2F *twod1= (TH2F*)hfile1->Get("h_2DAtaildepth2_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_2D0Ataildepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* tail2= (TH2F*)twod1->Clone("tail2");
	tail2->Divide(twod1,twod0, 1, 1, "B");
	tail2->Sumw2();
      }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      tail2->SetMarkerStyle(20);
      tail2->SetMarkerSize(0.4);
      tail2->SetXTitle("#eta \b");
      tail2->SetYTitle("#phi \b");
      tail2->SetZTitle("2D <A> in the tail - HB Depth2 \b");
      tail2->SetMarkerColor(2);
      tail2->SetLineColor(2);
      tail2->Draw("COLZ");

      c1->Update();

    //======================================================================
    //======================================================================
    //=============================================================================================== 20
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);

      c1->cd(1);
TH1F *ufrew3= (TH1F*)hfile1->Get("h_averSIGNALoccupancy_HF");
TH1F *ufrew4= (TH1F*)hfile1->Get("h_averNOSIGNALoccupancy_HF");
TH1F* ufrew1= (TH1F*)ufrew3->Clone("ufrew1");
ufrew1->Add(ufrew3,ufrew4, 1, 1);
      ufrew1->GetXaxis()->SetRangeUser(0, maxbins+1.);
      gPad->SetGridx();
      ufrew1->SetMarkerStyle(20);
      ufrew1->SetMarkerSize(0.8);
      ufrew1->GetYaxis()->SetLabelSize(0.04);
      ufrew1->SetXTitle("average occupancy per LS  HF    \b");
      ufrew1->SetMarkerColor(4);
      ufrew1->SetLineColor(0);
      ufrew1->Draw("Error");


      c1->Update();

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
