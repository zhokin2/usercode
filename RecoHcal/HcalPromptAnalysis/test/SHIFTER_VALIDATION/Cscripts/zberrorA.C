{
   //====================================================================== h_RatioOccupancy_HFM
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
          TPostScript psfile ("zberrorA.ps", 111);
//

   c1 = new TCanvas("c1","Hcal4test",200,10,700,900);


    //=============================================================================================== 1 HB
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmpl_HB");
      gPad->SetLogy();
//       gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HB \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
       
 

      c1->cd(1);
      //      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HB");
    //   TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HB");
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
      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HB \b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
//      Ceff225->SetMaximum(1.000);
      // Ceff225->SetMinimum(0.1);
      Ceff225->Draw("COLZ");
            
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HB = (TH2F*)Ceff->Clone("Diffe_Depth1_HB");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB->SetBinContent(i,j,0.);
	  //	  if(ccc1 <0 || ccc1>60.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
	  //	  if(ccc1 > 0.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
	//  if(ccc1 < 4.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
	  if(ccc1 > 0.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB->SetMarkerStyle(20);
      Diffe_Depth1_HB->SetMarkerSize(0.4);
      Diffe_Depth1_HB->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1_HB->SetTitle("any Error, HB Depth1 \n");
      Diffe_Depth1_HB->SetXTitle("#eta \b");
      Diffe_Depth1_HB->SetYTitle("#phi \b");
      Diffe_Depth1_HB->SetZTitle("<ADCAmpl> bigger 0.- HB Depth1 \b");
      Diffe_Depth1_HB->SetMarkerColor(2);
      Diffe_Depth1_HB->SetLineColor(2);
      Diffe_Depth1_HB->Draw("COLZ");


      c1->cd(4);
      /*
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
*/
      TH1F* diffADCAmpl_Depth1_HB = new TH1F("diffADCAmpl_Depth1_HB","",  50, 0.,50.);
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1_HB->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1_HB->SetMarkerStyle(20);
      diffADCAmpl_Depth1_HB->SetMarkerSize(0.4);
      diffADCAmpl_Depth1_HB->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1_HB->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1_HB->SetMarkerColor(2);
      diffADCAmpl_Depth1_HB->SetLineColor(2);
      diffADCAmpl_Depth1_HB->Draw("");




      c1->Update();

    //============================================================================================ 2 HB
    //======================================================================
    //======================================================================
    //================ 
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
    ///////////////////////////////////////
      c1->cd(1);
    TH2F* Diffe_Depth1_HB0 = (TH2F*)Ceff->Clone("Diffe_Depth1_HB0");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB0->SetBinContent(i,j,0.);
	  if(ccc1 > 25.)  Diffe_Depth1_HB0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB0->SetMarkerStyle(20);
      Diffe_Depth1_HB0->SetMarkerSize(0.4);
      Diffe_Depth1_HB0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HB0->SetXTitle("#eta \b");
      Diffe_Depth1_HB0->SetYTitle("#phi \b");
      Diffe_Depth1_HB0->SetZTitle("<ADCAmpl> bigger 25.- HB Depth1 \b");
      Diffe_Depth1_HB0->SetMarkerColor(2);
      Diffe_Depth1_HB0->SetLineColor(2);
      Diffe_Depth1_HB0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth1_HB9 = (TH2F*)Ceff->Clone("Diffe_Depth1_HB9");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB9->SetBinContent(i,j,0.);
	  if(ccc1 > 27.)  Diffe_Depth1_HB9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB9->SetMarkerStyle(20);
      Diffe_Depth1_HB9->SetMarkerSize(0.4);
      Diffe_Depth1_HB9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HB9->SetXTitle("#eta \b");
      Diffe_Depth1_HB9->SetYTitle("#phi \b");
      Diffe_Depth1_HB9->SetZTitle("<ADCAmpl> bigger 27.- HB Depth1 \b");
      Diffe_Depth1_HB9->SetMarkerColor(2);
      Diffe_Depth1_HB9->SetLineColor(2);
      Diffe_Depth1_HB9->Draw("COLZ");
      
    ///////////////////////////////////////
    ///////////////////////////////////////
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HB");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff2= (TH2F*)twod1->Clone("Ceff2");
	Ceff2->Divide(twod1,twod0, 1, 1, "B");
	Ceff2->Sumw2();
      }
    ///////////////////////////////////////
      c1->cd(3);
    TH2F* Diffe_Depth1_HB0 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HB0");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB0->SetBinContent(i,j,0.);
	  if(ccc1 > 25.)  Diffe_Depth1_HB0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB0->SetMarkerStyle(20);
      Diffe_Depth1_HB0->SetMarkerSize(0.4);
      Diffe_Depth1_HB0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HB0->SetXTitle("#eta \b");
      Diffe_Depth1_HB0->SetYTitle("#phi \b");
      Diffe_Depth1_HB0->SetZTitle("<ADCAmpl> bigger 25.- HB Depth2 \b");
      Diffe_Depth1_HB0->SetMarkerColor(2);
      Diffe_Depth1_HB0->SetLineColor(2);
      Diffe_Depth1_HB0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(4);
    TH2F* Diffe_Depth1_HB9 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HB9");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HB9->SetBinContent(i,j,0.);
	  if(ccc1 > 27.)  Diffe_Depth1_HB9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HB9->SetMarkerStyle(20);
      Diffe_Depth1_HB9->SetMarkerSize(0.4);
      Diffe_Depth1_HB9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HB9->SetXTitle("#eta \b");
      Diffe_Depth1_HB9->SetYTitle("#phi \b");
      Diffe_Depth1_HB9->SetZTitle("<ADCAmpl> bigger 27.- HB Depth2 \b");
      Diffe_Depth1_HB9->SetMarkerColor(2);
      Diffe_Depth1_HB9->SetLineColor(2);
      Diffe_Depth1_HB9->Draw("COLZ");
      



      c1->Update();
      
 

    //=============================================================================================== 3 HB
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);

      // Amplitude:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");

      // RMS:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");



      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");

      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz= (TH2F*)twod1->Clone("Cefz");
	Cefz->Divide(twod1,twod0, 1, 1, "B");
	Cefz->Sumw2();
      }

      //////////////////////////////////////////////////////////////////////////    Cefz225:  
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HB");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HB");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HB");
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1_HB");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("RMS - HB Depth1 \b");
      Cefz225->Draw("COLZ");



      c1->cd(2);
    TH2F* Diffe_Depth1_HB = (TH2F*)Cefz225->Clone("Diffe_Depth1_HB");
    int nx = Cefz225->GetXaxis()->GetNbins();
    int ny = Cefz225->GetYaxis()->GetNbins();
    for (int j=1;j<=ny;j++) {
      for (int i=1;i<=nx;i++) {
	//		  double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	//	if(ccc1 > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	//	  Diffe_Depth1_HB->SetBinContent(i,j,0.);
	//	  if(ccc1 <18|| ccc1>30.)  Diffe_Depth1_HB->SetBinContent(i,j,ccc1);
	
	if(i> 41)  {Diffe_Depth1_HB->SetBinContent(i,j,ccc1);}
	else {Diffe_Depth1_HB->SetBinContent(i,j,0.);}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HB->SetMarkerStyle(20);
    Diffe_Depth1_HB->SetMarkerSize(0.4);
    Diffe_Depth1_HB->GetZaxis()->SetLabelSize(0.08);
    //    Diffe_Depth1_HB->SetTitle("any Error, HB Depth1 \n");
    Diffe_Depth1_HB->SetXTitle("#eta \b");
    Diffe_Depth1_HB->SetYTitle("#phi \b");
    //    Diffe_Depth1_HB->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HB Depth1 \b");
        Diffe_Depth1_HB->SetZTitle("cross check - HB Depth1 \b");
    Diffe_Depth1_HB->SetMarkerColor(2);
    Diffe_Depth1_HB->SetLineColor(2);
    //      Diffe_Depth1_HB->SetMaximum(1.000);
    //      Diffe_Depth1_HB->SetMinimum(0.0000001);
    Diffe_Depth1_HB->Draw("COLZ");
    cout<<" nx = "<< nx <<" ny = "<< ny <<endl;
    


      c1->cd(3);
      TH1F* ADCAmplperLS  = new TH1F("ADCAmplperLS ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HB = (TH2F*)Cefz225->Clone("h_mapDepth1_HB ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j++) {
//	cout<<" HB-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i< 42) {
	    //	    if(Cefz->GetBinContent(i,j) > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<    Cefz->GetBinContent(i,j)    <<endl;
	    
	    // no cuts - take all
	    //	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
	    //	    if(Cefz->GetBinContent(i,j)> 1.) {
	    // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 25.) {
	      
	      
	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLS ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HB-    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
//      cout<<" HB-    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HB-    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HB-   - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      

      //      gPad->SetLogy();
      ADCAmplperLS ->SetMarkerStyle(20);
      ADCAmplperLS ->SetMarkerSize(0.4);
      ADCAmplperLS ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLS ->SetXTitle("<ADCAmpl> per LS HB1 \b");
      ADCAmplperLS ->SetMarkerColor(2);
      ADCAmplperLS ->SetLineColor(4);
//      ADCAmplperLS ->SetMaximum(30.0);
//      ADCAmplperLS ->SetMinimum(25.0);
      ADCAmplperLS->SetXTitle(" #hits vs Phi for  HB-  cut:A>25\\b");
      ADCAmplperLS ->Draw();
      
      /////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(4);
      TH1F* ADCAmplperLS2  = new TH1F("ADCAmplperLS2 ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HB = (TH2F*)Cefz225->Clone("h_mapDepth1_HB ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j++) {
//	cout<<" HB-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i> 41) {
	    
	    
	    
	    // no cuts - take all
//	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
//	    if(Cefz->GetBinContent(i,j)> 1.) {
	      // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 25.) {


	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLS2 ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HB+    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
//      cout<<" HB+    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HB+    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HB+    - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      



      //      gPad->SetLogy();
      ADCAmplperLS2 ->SetMarkerStyle(20);
      ADCAmplperLS2 ->SetMarkerSize(0.4);
      ADCAmplperLS2 ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLS2 ->SetXTitle("<ADCAmpl> per LS HB1 \b");
      ADCAmplperLS2 ->SetMarkerColor(2);
      ADCAmplperLS2 ->SetLineColor(4);
//      ADCAmplperLS2 ->SetMaximum(30.0);
//      ADCAmplperLS2 ->SetMinimum(25.0);
      ADCAmplperLS2->SetXTitle(" #hits vs Phi for  HB+ cut:A>25\b");
      ADCAmplperLS2 ->Draw("");
      
      
      c1->Update();
            
    //===============================================================================================  4 HB
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_RatioOccupancy_HBM");
      int maxbins = 0;
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) maxbins++;
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
      }
      cout<<"HB maxbins=     "<< maxbins <<endl;

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("LS \b");
      //      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("min/av occupancy - HB M \b");
      Cefz225->Draw("COLZ");

      c1->cd(2);
      TH1F* qqq6 = new TH1F("qqq6","", maxbins, 1., maxbins+1.);
      //      TH1F* qqq6 = new TH1F("qqq6","", 125, 1., 126.);
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq6->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq6->SetMarkerStyle(20);
      qqq6->SetMarkerSize(0.4);
      qqq6->GetYaxis()->SetLabelSize(0.04);
      qqq6->SetXTitle("min/av occupancy - HB M \b");
      qqq6->SetMarkerColor(2);
      qqq6->SetLineColor(0);
      qqq6->SetMaximum(1.0);
      qqq6->SetMinimum(0.2);
      qqq6->Draw("Error");

      c1->cd(3);
      TH2F *Cefz226= (TH2F*)hfile1->Get("h_RatioOccupancy_HBP");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
      //    Cefz226->GetYaxis()->SetLabelSize(0.04);
      Cefz226->GetZaxis()->SetLabelSize(0.08);
      Cefz226->SetXTitle("LS \b");
      //      Cefz226->SetYTitle("#phi \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //      Cefz226->SetMaximum(1.000);
      //      Cefz226->SetMinimum(0.0001);
        Cefz226->SetZTitle("min/av occupancy - HB P \b");
      Cefz226->Draw("COLZ");

      c1->cd(4);
      TH1F* qqq7 = new TH1F("qqq7","", maxbins, 1., maxbins+1.);
      //      TH1F* qqq7 = new TH1F("qqq7","", 125, 1., 126.);
      int nx = Cefz226->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz226->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HB iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) qqq7->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      qqq7->SetMarkerStyle(20);
      qqq7->SetMarkerSize(0.4);
      qqq7->GetYaxis()->SetLabelSize(0.04);
      qqq7->SetXTitle("min/av occupancy - HB P \b");
      qqq7->SetMarkerColor(2);
      qqq7->SetLineColor(0);
      qqq7->SetMaximum(1.0);
      qqq7->SetMinimum(0.2);
      qqq7->Draw("Error");

            
      c1->Update();
    //===============================================================================================  5 HB
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      

      c1->cd(1);
      qqq6->SetMaximum(0.9);
      qqq6->SetMinimum(0.2);
      qqq6->Draw("Error");


      c1->cd(2);
      qqq7->SetMaximum(0.9);
      qqq7->SetMinimum(0.2);
      qqq7->Draw("Error");



      c1->Update();

    //======================================================================



    //=============================================================================================== 6 HE
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmpl_HE");
      gPad->SetLogy();
//       gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HE \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
       
 

      c1->cd(1);
      //      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HE");
    //   TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HE");
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
      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HE \b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
//      Ceff225->SetMaximum(1.000);
      // Ceff225->SetMinimum(0.1);
      Ceff225->Draw("COLZ");
            
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HE = (TH2F*)Ceff->Clone("Diffe_Depth1_HE");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HE->SetBinContent(i,j,0.);
	  //	  if(ccc1 <0 || ccc1>60.)  Diffe_Depth1_HE->SetBinContent(i,j,ccc1);
	  //	  if(ccc1 > 0.)  Diffe_Depth1_HE->SetBinContent(i,j,ccc1);
	//  if(ccc1 < 4.)  Diffe_Depth1_HE->SetBinContent(i,j,ccc1);
	  if(ccc1 > 0.)  Diffe_Depth1_HE->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HE->SetMarkerStyle(20);
      Diffe_Depth1_HE->SetMarkerSize(0.4);
      Diffe_Depth1_HE->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1_HE->SetTitle("any Error, HE Depth1 \n");
      Diffe_Depth1_HE->SetXTitle("#eta \b");
      Diffe_Depth1_HE->SetYTitle("#phi \b");
      Diffe_Depth1_HE->SetZTitle("<ADCAmpl> bigger 0.- HE Depth1 \b");
      Diffe_Depth1_HE->SetMarkerColor(2);
      Diffe_Depth1_HE->SetLineColor(2);
      Diffe_Depth1_HE->Draw("COLZ");


      c1->cd(4);
      /*
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
*/
      TH1F* diffADCAmpl_Depth1_HE = new TH1F("diffADCAmpl_Depth1_HE","", 70, 0., 70.);
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1_HE->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1_HE->SetMarkerStyle(20);
      diffADCAmpl_Depth1_HE->SetMarkerSize(0.4);
      diffADCAmpl_Depth1_HE->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1_HE->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1_HE->SetMarkerColor(2);
      diffADCAmpl_Depth1_HE->SetLineColor(2);
      diffADCAmpl_Depth1_HE->Draw("");




      c1->Update();

    //============================================================================================ 7 HE
    //======================================================================
    //======================================================================
    //================ 
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
    ///////////////////////////////////////
      c1->cd(1);
    TH2F* Diffe_Depth1_HE0 = (TH2F*)Ceff->Clone("Diffe_Depth1_HE0");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HE0->SetBinContent(i,j,0.);
	  if(ccc1 > 30.)  Diffe_Depth1_HE0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HE0->SetMarkerStyle(20);
      Diffe_Depth1_HE0->SetMarkerSize(0.4);
      Diffe_Depth1_HE0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HE0->SetXTitle("#eta \b");
      Diffe_Depth1_HE0->SetYTitle("#phi \b");
      Diffe_Depth1_HE0->SetZTitle("<ADCAmpl> bigger 30.- HE Depth1 \b");
      Diffe_Depth1_HE0->SetMarkerColor(2);
      Diffe_Depth1_HE0->SetLineColor(2);
      Diffe_Depth1_HE0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth1_HE9 = (TH2F*)Ceff->Clone("Diffe_Depth1_HE9");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HE9->SetBinContent(i,j,0.);
	  if(ccc1 > 33.)  Diffe_Depth1_HE9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HE9->SetMarkerStyle(20);
      Diffe_Depth1_HE9->SetMarkerSize(0.4);
      Diffe_Depth1_HE9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HE9->SetXTitle("#eta \b");
      Diffe_Depth1_HE9->SetYTitle("#phi \b");
      Diffe_Depth1_HE9->SetZTitle("<ADCAmpl> bigger 33.- HE Depth1 \b");
      Diffe_Depth1_HE9->SetMarkerColor(2);
      Diffe_Depth1_HE9->SetLineColor(2);
      Diffe_Depth1_HE9->Draw("COLZ");
      
    ///////////////////////////////////////
    ///////////////////////////////////////
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HE");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff2= (TH2F*)twod1->Clone("Ceff2");
	Ceff2->Divide(twod1,twod0, 1, 1, "B");
	Ceff2->Sumw2();
      }
    ///////////////////////////////////////
      c1->cd(3);
    TH2F* Diffe_Depth1_HE0 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HE0");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HE0->SetBinContent(i,j,0.);
	  if(ccc1 > 26.)  Diffe_Depth1_HE0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HE0->SetMarkerStyle(20);
      Diffe_Depth1_HE0->SetMarkerSize(0.4);
      Diffe_Depth1_HE0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HE0->SetXTitle("#eta \b");
      Diffe_Depth1_HE0->SetYTitle("#phi \b");
      Diffe_Depth1_HE0->SetZTitle("<ADCAmpl> bigger 26.- HE Depth2 \b");
      Diffe_Depth1_HE0->SetMarkerColor(2);
      Diffe_Depth1_HE0->SetLineColor(2);
      Diffe_Depth1_HE0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(4);
    TH2F* Diffe_Depth1_HE9 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HE9");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HE9->SetBinContent(i,j,0.);
	  if(ccc1 > 31.)  Diffe_Depth1_HE9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HE9->SetMarkerStyle(20);
      Diffe_Depth1_HE9->SetMarkerSize(0.4);
      Diffe_Depth1_HE9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HE9->SetXTitle("#eta \b");
      Diffe_Depth1_HE9->SetYTitle("#phi \b");
      Diffe_Depth1_HE9->SetZTitle("<ADCAmpl> bigger 31.- HE Depth2 \b");
      Diffe_Depth1_HE9->SetMarkerColor(2);
      Diffe_Depth1_HE9->SetLineColor(2);
      Diffe_Depth1_HE9->Draw("COLZ");
      



      c1->Update();
      
 

    //=============================================================================================== 8 HE
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);

      // Amplitude:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");

      // RMS:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HE");



      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HE");

      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz= (TH2F*)twod1->Clone("Cefz");
	Cefz->Divide(twod1,twod0, 1, 1, "B");
	Cefz->Sumw2();
      }

      //////////////////////////////////////////////////////////////////////////    Cefz225:  
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HE");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HE");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HE");
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1_HE");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("RMS - HE Depth1 \b");
      Cefz225->Draw("COLZ");



      c1->cd(2);
    TH2F* Diffe_Depth1_HE = (TH2F*)Cefz225->Clone("Diffe_Depth1_HE");
    int nx = Cefz225->GetXaxis()->GetNbins();
    int ny = Cefz225->GetYaxis()->GetNbins();
    for (int j=1;j<=ny;j++) {
      for (int i=1;i<=nx;i++) {
	//		  double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	//	if(ccc1 > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	//	  Diffe_Depth1_HE->SetBinContent(i,j,0.);
	//	  if(ccc1 <18|| ccc1>30.)  Diffe_Depth1_HE->SetBinContent(i,j,ccc1);
	
	if(i> 41)  {Diffe_Depth1_HE->SetBinContent(i,j,ccc1);}
	else {Diffe_Depth1_HE->SetBinContent(i,j,0.);}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HE->SetMarkerStyle(20);
    Diffe_Depth1_HE->SetMarkerSize(0.4);
    Diffe_Depth1_HE->GetZaxis()->SetLabelSize(0.08);
    //    Diffe_Depth1_HE->SetTitle("any Error, HE Depth1 \n");
    Diffe_Depth1_HE->SetXTitle("#eta \b");
    Diffe_Depth1_HE->SetYTitle("#phi \b");
    //    Diffe_Depth1_HE->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HE Depth1 \b");
        Diffe_Depth1_HE->SetZTitle("cross check - HE Depth1 \b");
    Diffe_Depth1_HE->SetMarkerColor(2);
    Diffe_Depth1_HE->SetLineColor(2);
    //      Diffe_Depth1_HE->SetMaximum(1.000);
    //      Diffe_Depth1_HE->SetMinimum(0.0000001);
    Diffe_Depth1_HE->Draw("COLZ");
    cout<<" nx = "<< nx <<" ny = "<< ny <<endl;
    


      c1->cd(3);
      TH1F* ADCAmplperLSHE  = new TH1F("ADCAmplperLSHE ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HE = (TH2F*)Cefz225->Clone("h_mapDepth1_HE ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      //      for (int j=1;j<=ny;j++) {
      for (int j=1;j<=ny;j +=2) {
	//	cout<<" HE-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i< 42) {
	    //	    if(Cefz->GetBinContent(i,j) > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<    Cefz->GetBinContent(i,j)    <<endl;
	    
	    // no cuts - take all
	    //	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
	    //	    if(Cefz->GetBinContent(i,j)> 1.) {
	    // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 30.) {
	      
	      
	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHE ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
		cout<<"*****HE: i = "<<i<<" j = "<<j<<"  BinContent= "<<    ccc1  <<" ncountall = "<<ncountall    <<" ncountmin = "<<ncountmin           <<endl;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HE-    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
		cout<<"*********************HE:  ncountmin = "<<ncountmin  <<"nnnmin = "<<nnnmin  <<"nnnbins = "<<nnnbins        <<endl;
	  ncountmin=0;
	  nnnbins++;
	}
      }
      cout<<" HE-    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HE-    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HE-   - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      

      //      gPad->SetLogy();
      ADCAmplperLSHE ->SetMarkerStyle(20);
      ADCAmplperLSHE ->SetMarkerSize(0.4);
      ADCAmplperLSHE ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHE ->SetXTitle("<ADCAmpl> per LS HE1 \b");
      ADCAmplperLSHE ->SetMarkerColor(2);
      ADCAmplperLSHE ->SetLineColor(4);
//      ADCAmplperLSHE ->SetMaximum(30.0);
//      ADCAmplperLSHE ->SetMinimum(25.0);
      ADCAmplperLSHE->SetXTitle(" #hits vs Phi for  HE-  cut:A>30\\b");
      //      gPad->SetLogy();
      ADCAmplperLSHE ->Draw();
      
      /////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(4);
      TH1F* ADCAmplperLSHE2  = new TH1F("ADCAmplperLSHE2 ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HE = (TH2F*)Cefz225->Clone("h_mapDepth1_HE ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      //      for (int j=1;j<=ny;j++) {
      for (int j=1;j<=ny;j +=2) {
//	cout<<" HE-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i> 41) {
	    
	    
	    
	    // no cuts - take all
//	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
//	    if(Cefz->GetBinContent(i,j)> 1.) {
	      // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 30.) {


	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHE2 ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HE+    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
      cout<<" HE+    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HE+    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HE+    - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      



      //      gPad->SetLogy();
      ADCAmplperLSHE2 ->SetMarkerStyle(20);
      ADCAmplperLSHE2 ->SetMarkerSize(0.4);
      ADCAmplperLSHE2 ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHE2 ->SetXTitle("<ADCAmpl> per LS HE1 \b");
      ADCAmplperLSHE2 ->SetMarkerColor(2);
      ADCAmplperLSHE2 ->SetLineColor(4);
//      ADCAmplperLSHE2 ->SetMaximum(30.0);
//      ADCAmplperLSHE2 ->SetMinimum(25.0);
      ADCAmplperLSHE2->SetXTitle(" #hits vs Phi for  HE+ cut:A>30\b");
      //      gPad->SetLogy();
      ADCAmplperLSHE2 ->Draw("");
      
      
      c1->Update();
            
    //===============================================================================================  9 HE
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_RatioOccupancy_HEM");
      int maxbins = 0;
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) maxbins++;
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
      }
      cout<<"HE maxbins=     "<< maxbins <<endl;

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("LS \b");
      //      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("min/av occupancy - HE M \b");
      Cefz225->Draw("COLZ");

      c1->cd(2);
      TH1F* wtre = new TH1F("wtre","", maxbins, 1., maxbins+1.);
      //      TH1F* wtre = new TH1F("wtre","", 125, 1., 126.);
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) wtre->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      wtre->SetMarkerStyle(20);
      wtre->SetMarkerSize(0.4);
      wtre->GetYaxis()->SetLabelSize(0.04);
      wtre->SetXTitle("min/av occupancy - HE M \b");
      wtre->SetMarkerColor(2);
      wtre->SetLineColor(0);
      wtre->SetMaximum(0.3);
      wtre->SetMinimum(0.);
      wtre->Draw("Error");

      c1->cd(3);
      TH2F *Cefz226= (TH2F*)hfile1->Get("h_RatioOccupancy_HEP");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
      //    Cefz226->GetYaxis()->SetLabelSize(0.04);
      Cefz226->GetZaxis()->SetLabelSize(0.08);
      Cefz226->SetXTitle("LS \b");
      //      Cefz226->SetYTitle("#phi \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //      Cefz226->SetMaximum(1.000);
      //      Cefz226->SetMinimum(0.0001);
        Cefz226->SetZTitle("min/av occupancy - HE P \b");
      Cefz226->Draw("COLZ");

      c1->cd(4);
      TH1F* juyt = new TH1F("juyt","", maxbins, 1., maxbins+1.);
      //      TH1F* juyt = new TH1F("juyt","", 125, 1., 126.);
      int nx = Cefz226->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz226->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HE iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) juyt->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      juyt->SetMarkerStyle(20);
      juyt->SetMarkerSize(0.4);
      juyt->GetYaxis()->SetLabelSize(0.04);
      juyt->SetXTitle("min/av occupancy - HE P \b");
      juyt->SetMarkerColor(2);
      juyt->SetLineColor(0);
      juyt->SetMaximum(0.3);
      juyt->SetMinimum(0.0);
      juyt->Draw("Error");

            
      c1->Update();
    //=============================================================================================== 10 HE
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      

      c1->cd(1);
      wtre->SetMaximum(0.2);
      wtre->SetMinimum(0.0);
      wtre->Draw("Error");


      c1->cd(2);
      juyt->SetMaximum(0.2);
      juyt->SetMinimum(0.0);
      juyt->Draw("Error");



      c1->Update();

    //======================================================================



    //=============================================================================================== 11 HF
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmpl_HF");
      gPad->SetLogy();
//       gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HF \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
       
 

      c1->cd(1);
      //      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HF");
    //   TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl225_HF");
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
      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth1ADCAmpl_HF \b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
//      Ceff225->SetMaximum(1.000);
      // Ceff225->SetMinimum(0.1);
      Ceff225->Draw("COLZ");
            
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth1_HF = (TH2F*)Ceff->Clone("Diffe_Depth1_HF");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF->SetBinContent(i,j,0.);
	  //	  if(ccc1 <0 || ccc1>60.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
	  //	  if(ccc1 > 0.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
	//  if(ccc1 < 4.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
	  if(ccc1 > 0.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF->SetMarkerStyle(20);
      Diffe_Depth1_HF->SetMarkerSize(0.4);
      Diffe_Depth1_HF->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth1_HF->SetTitle("any Error, HF Depth1 \n");
      Diffe_Depth1_HF->SetXTitle("#eta \b");
      Diffe_Depth1_HF->SetYTitle("#phi \b");
      Diffe_Depth1_HF->SetZTitle("<ADCAmpl> bigger 0.- HF Depth1 \b");
      Diffe_Depth1_HF->SetMarkerColor(2);
      Diffe_Depth1_HF->SetLineColor(2);
      Diffe_Depth1_HF->Draw("COLZ");


      c1->cd(4);
      /*
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
*/
      TH1F* diffADCAmpl_Depth1_HF = new TH1F("diffADCAmpl_Depth1_HF","", 100, -20.,200.);
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth1_HF->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth1_HF->SetMarkerStyle(20);
      diffADCAmpl_Depth1_HF->SetMarkerSize(0.4);
      diffADCAmpl_Depth1_HF->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth1_HF->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth1_HF->SetMarkerColor(2);
      diffADCAmpl_Depth1_HF->SetLineColor(2);
      diffADCAmpl_Depth1_HF->Draw("");




      c1->Update();

    //============================================================================================ 12 HF
    //======================================================================
    //======================================================================
    //================ 
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
    ///////////////////////////////////////
      c1->cd(1);
    TH2F* Diffe_Depth1_HF0 = (TH2F*)Ceff->Clone("Diffe_Depth1_HF0");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF0->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  Diffe_Depth1_HF0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF0->SetMarkerStyle(20);
      Diffe_Depth1_HF0->SetMarkerSize(0.4);
      Diffe_Depth1_HF0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF0->SetXTitle("#eta \b");
      Diffe_Depth1_HF0->SetYTitle("#phi \b");
      Diffe_Depth1_HF0->SetZTitle("<ADCAmpl> bigger 20.- HF Depth1 \b");
      Diffe_Depth1_HF0->SetMarkerColor(2);
      Diffe_Depth1_HF0->SetLineColor(2);
      Diffe_Depth1_HF0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth1_HF9 = (TH2F*)Ceff->Clone("Diffe_Depth1_HF9");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF9->SetBinContent(i,j,0.);
	  if(ccc1 > 30.)  Diffe_Depth1_HF9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF9->SetMarkerStyle(20);
      Diffe_Depth1_HF9->SetMarkerSize(0.4);
      Diffe_Depth1_HF9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF9->SetXTitle("#eta \b");
      Diffe_Depth1_HF9->SetYTitle("#phi \b");
      Diffe_Depth1_HF9->SetZTitle("<ADCAmpl> bigger 30.- HF Depth1 \b");
      Diffe_Depth1_HF9->SetMarkerColor(2);
      Diffe_Depth1_HF9->SetLineColor(2);
      Diffe_Depth1_HF9->Draw("COLZ");
      
    ///////////////////////////////////////
    ///////////////////////////////////////
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth2ADCAmpl_HF");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth2_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff2= (TH2F*)twod1->Clone("Ceff2");
	Ceff2->Divide(twod1,twod0, 1, 1, "B");
	Ceff2->Sumw2();
      }
    ///////////////////////////////////////
      c1->cd(3);
    TH2F* Diffe_Depth1_HF0 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HF0");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF0->SetBinContent(i,j,0.);
	  if(ccc1 > 20.)  Diffe_Depth1_HF0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF0->SetMarkerStyle(20);
      Diffe_Depth1_HF0->SetMarkerSize(0.4);
      Diffe_Depth1_HF0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF0->SetXTitle("#eta \b");
      Diffe_Depth1_HF0->SetYTitle("#phi \b");
      Diffe_Depth1_HF0->SetZTitle("<ADCAmpl> bigger 20.- HF Depth2 \b");
      Diffe_Depth1_HF0->SetMarkerColor(2);
      Diffe_Depth1_HF0->SetLineColor(2);
      Diffe_Depth1_HF0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(4);
    TH2F* Diffe_Depth1_HF9 = (TH2F*)Ceff2->Clone("Diffe_Depth2_HF9");
    int nx = Ceff2->GetXaxis()->GetNbins();
    int ny = Ceff2->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff2->GetBinContent(i,j)   ;
	  Diffe_Depth1_HF9->SetBinContent(i,j,0.);
	  if(ccc1 > 30.)  Diffe_Depth1_HF9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth1_HF9->SetMarkerStyle(20);
      Diffe_Depth1_HF9->SetMarkerSize(0.4);
      Diffe_Depth1_HF9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth1_HF9->SetXTitle("#eta \b");
      Diffe_Depth1_HF9->SetYTitle("#phi \b");
      Diffe_Depth1_HF9->SetZTitle("<ADCAmpl> bigger 30.- HF Depth2 \b");
      Diffe_Depth1_HF9->SetMarkerColor(2);
      Diffe_Depth1_HF9->SetLineColor(2);
      Diffe_Depth1_HF9->Draw("COLZ");
      



      c1->Update();
      
 

    //=============================================================================================== 13 HF
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);

      // Amplitude:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");

      // RMS:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HF");



      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HF");

      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz= (TH2F*)twod1->Clone("Cefz");
	Cefz->Divide(twod1,twod0, 1, 1, "B");
	Cefz->Sumw2();
      }

      //////////////////////////////////////////////////////////////////////////    Cefz225:  
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1Amplitude_HF");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl_HF");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1ADCAmpl12_HF");
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth1_HF");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("RMS - HF Depth1 \b");
      Cefz225->Draw("COLZ");



      c1->cd(2);
    TH2F* Diffe_Depth1_HF = (TH2F*)Cefz225->Clone("Diffe_Depth1_HF");
    int nx = Cefz225->GetXaxis()->GetNbins();
    int ny = Cefz225->GetYaxis()->GetNbins();
    for (int j=1;j<=ny;j++) {
      for (int i=1;i<=nx;i++) {
	//		  double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	//	if(ccc1 > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	//	  Diffe_Depth1_HF->SetBinContent(i,j,0.);
	//	  if(ccc1 <18|| ccc1>30.)  Diffe_Depth1_HF->SetBinContent(i,j,ccc1);
	
	if(i> 41)  {Diffe_Depth1_HF->SetBinContent(i,j,ccc1);}
	else {Diffe_Depth1_HF->SetBinContent(i,j,0.);}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth1_HF->SetMarkerStyle(20);
    Diffe_Depth1_HF->SetMarkerSize(0.4);
    Diffe_Depth1_HF->GetZaxis()->SetLabelSize(0.08);
    //    Diffe_Depth1_HF->SetTitle("any Error, HF Depth1 \n");
    Diffe_Depth1_HF->SetXTitle("#eta \b");
    Diffe_Depth1_HF->SetYTitle("#phi \b");
    //    Diffe_Depth1_HF->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HF Depth1 \b");
        Diffe_Depth1_HF->SetZTitle("cross check - HF Depth1 \b");
    Diffe_Depth1_HF->SetMarkerColor(2);
    Diffe_Depth1_HF->SetLineColor(2);
    //      Diffe_Depth1_HF->SetMaximum(1.000);
    //      Diffe_Depth1_HF->SetMinimum(0.0000001);
    Diffe_Depth1_HF->Draw("COLZ");
    cout<<" nx = "<< nx <<" ny = "<< ny <<endl;
    


      c1->cd(3);
      TH1F* ADCAmplperLSHF  = new TH1F("ADCAmplperLSHF ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HF = (TH2F*)Cefz225->Clone("h_mapDepth1_HF ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j +=2) {
//      for (int j=1;j<=ny;j++) {
//	cout<<" HF-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i< 42) {
	    //	    	    if(Cefz->GetBinContent(i,j) > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<    Cefz->GetBinContent(i,j)    <<endl;
	    
	    // no cuts - take all
	    //	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
	    //	    if(Cefz->GetBinContent(i,j)> 1.) {
	    // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 20.) {
	      
	      
	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHF ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
		cout<<"*****HF: i = "<<i<<" j = "<<j<<"  BinContent= "<<    ccc1  <<" ncountall = "<<ncountall    <<" ncountmin = "<<ncountmin           <<endl;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HF-    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
      cout<<" HF-    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HF-    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HF-   - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      

      //      gPad->SetLogy();
      ADCAmplperLSHF ->SetMarkerStyle(20);
      ADCAmplperLSHF ->SetMarkerSize(0.4);
      ADCAmplperLSHF ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHF ->SetXTitle("<ADCAmpl> per LS HF1 \b");
      ADCAmplperLSHF ->SetMarkerColor(2);
      ADCAmplperLSHF ->SetLineColor(4);
//      ADCAmplperLSHF ->SetMaximum(30.0);
//      ADCAmplperLSHF ->SetMinimum(25.0);
      ADCAmplperLSHF->SetXTitle(" #hits vs Phi for  HF-  cut:A>20\\b");
      ADCAmplperLSHF ->Draw();
      
      /////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(4);
      TH1F* ADCAmplperLSHF2  = new TH1F("ADCAmplperLSHF2 ","", 72, 1.,73.);
      TH2F* Diffe_Depth1_HF = (TH2F*)Cefz225->Clone("h_mapDepth1_HF ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j++) {
//	cout<<" HF-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i> 41) {
	    
	    
	    
	    // no cuts - take all
//	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
//	    if(Cefz->GetBinContent(i,j)> 1.) {
	      // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 20.) {


	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHF2 ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HF+    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
      cout<<" HF+    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HF+    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HF+    - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      



      //      gPad->SetLogy();
      ADCAmplperLSHF2 ->SetMarkerStyle(20);
      ADCAmplperLSHF2 ->SetMarkerSize(0.4);
      ADCAmplperLSHF2 ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHF2 ->SetXTitle("<ADCAmpl> per LS HF1 \b");
      ADCAmplperLSHF2 ->SetMarkerColor(2);
      ADCAmplperLSHF2 ->SetLineColor(4);
//      ADCAmplperLSHF2 ->SetMaximum(30.0);
//      ADCAmplperLSHF2 ->SetMinimum(25.0);
      ADCAmplperLSHF2->SetXTitle(" #hits vs Phi for  HF+ cut:A>20\b");
      ADCAmplperLSHF2 ->Draw("");
      
      
      c1->Update();
            
    //===============================================================================================  14 HF
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_RatioOccupancy_HFM");
      int maxbins = 0;
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) maxbins++;
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
      }
      cout<<"HF maxbins=     "<< maxbins <<endl;

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("LS \b");
      //      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("min/av occupancy - HF M \b");
      Cefz225->Draw("COLZ");

      c1->cd(2);
      TH1F* uytr = new TH1F("uytr","", maxbins, 1., maxbins+1.);
      //      TH1F* uytr = new TH1F("uytr","", 125, 1., 126.);
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) uytr->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      uytr->SetMarkerStyle(20);
      uytr->SetMarkerSize(0.4);
      uytr->GetYaxis()->SetLabelSize(0.04);
      uytr->SetXTitle("min/av occupancy - HF M \b");
      uytr->SetMarkerColor(2);
      uytr->SetLineColor(0);
      uytr->SetMaximum(1.0);
      uytr->SetMinimum(0.2);
      uytr->Draw("Error");

      c1->cd(3);
      TH2F *Cefz226= (TH2F*)hfile1->Get("h_RatioOccupancy_HFP");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
      //    Cefz226->GetYaxis()->SetLabelSize(0.04);
      Cefz226->GetZaxis()->SetLabelSize(0.08);
      Cefz226->SetXTitle("LS \b");
      //      Cefz226->SetYTitle("#phi \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //      Cefz226->SetMaximum(1.000);
      //      Cefz226->SetMinimum(0.0001);
        Cefz226->SetZTitle("min/av occupancy - HF P \b");
      Cefz226->Draw("COLZ");

      c1->cd(4);
      TH1F* paer = new TH1F("paer","", maxbins, 1., maxbins+1.);
      //      TH1F* paer = new TH1F("paer","", 125, 1., 126.);
      int nx = Cefz226->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz226->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth1_HF iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) paer->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      paer->SetMarkerStyle(20);
      paer->SetMarkerSize(0.4);
      paer->GetYaxis()->SetLabelSize(0.04);
      paer->SetXTitle("min/av occupancy - HF P \b");
      paer->SetMarkerColor(2);
      paer->SetLineColor(0);
      paer->SetMaximum(1.0);
      paer->SetMinimum(0.2);
      paer->Draw("Error");

            
      c1->Update();
    //===============================================================================================  15 HF
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      

      c1->cd(1);
      uytr->SetMaximum(0.9);
      uytr->SetMinimum(0.2);
      uytr->Draw("Error");


      c1->cd(2);
      paer->SetMaximum(0.9);
      paer->SetMinimum(0.2);
      paer->Draw("Error");



      c1->Update();

    //======================================================================



    //=============================================================================================== 16 HO
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_ADCAmpl_HO");
      gPad->SetLogy();
//       gPad->SetLogx();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("ADCAmpl in each event & cell HO \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->Draw("");
       
 

      c1->cd(1);
      //      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl12_HO");
    //   TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl225_HO");
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
      Ceff225->GetZaxis()->SetLabelSize(0.08);
      Ceff225->SetXTitle("#eta \b");
      Ceff225->SetYTitle("#phi \b");
      Ceff225->SetZTitle("h_mapDepth4ADCAmpl_HO \b");
      Ceff225->SetMarkerColor(2);
      Ceff225->SetLineColor(2);
//      Ceff225->SetMaximum(1.000);
      // Ceff225->SetMinimum(0.1);
      Ceff225->Draw("COLZ");
            
      c1->cd(3);
    ///////////////////////////////////////
    TH2F* Diffe_Depth4_HO = (TH2F*)Ceff->Clone("Diffe_Depth4_HO");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth4_HO->SetBinContent(i,j,0.);
	  //	  if(ccc1 <0 || ccc1>60.)  Diffe_Depth4_HO->SetBinContent(i,j,ccc1);
	  //	  if(ccc1 > 0.)  Diffe_Depth4_HO->SetBinContent(i,j,ccc1);
	//  if(ccc1 < 4.)  Diffe_Depth4_HO->SetBinContent(i,j,ccc1);
	  if(ccc1 > 0.)  Diffe_Depth4_HO->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth4_HO->SetMarkerStyle(20);
      Diffe_Depth4_HO->SetMarkerSize(0.4);
      Diffe_Depth4_HO->GetZaxis()->SetLabelSize(0.08);
      //    Diffe_Depth4_HO->SetTitle("any Error, HO Depth4 \n");
      Diffe_Depth4_HO->SetXTitle("#eta \b");
      Diffe_Depth4_HO->SetYTitle("#phi \b");
      Diffe_Depth4_HO->SetZTitle("<ADCAmpl> bigger 0.- HO Depth4 \b");
      Diffe_Depth4_HO->SetMarkerColor(2);
      Diffe_Depth4_HO->SetLineColor(2);
      Diffe_Depth4_HO->Draw("COLZ");


      c1->cd(4);
      /*
      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Ceff = (TH2F*)twod1->Clone("Ceff");
	Ceff->Divide(twod1,twod0, 1, 1, "B");
	Ceff->Sumw2();
      }
*/
      TH1F* diffADCAmpl_Depth4_HO = new TH1F("diffADCAmpl_Depth4_HO","", 100, 50.,150.);
      int nx = Ceff->GetXaxis()->GetNbins();
      int ny = Ceff->GetYaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	for (int j=1;j<=ny;j++) {
	  if(Ceff->GetBinContent(i,j) !=0 ) {
	    double ccc1 =  Ceff->GetBinContent(i,j) ;
	    diffADCAmpl_Depth4_HO->Fill(ccc1);
	  }
	}
      }
      gPad->SetLogy();
      diffADCAmpl_Depth4_HO->SetMarkerStyle(20);
      diffADCAmpl_Depth4_HO->SetMarkerSize(0.4);
      diffADCAmpl_Depth4_HO->GetYaxis()->SetLabelSize(0.04);
      diffADCAmpl_Depth4_HO->SetXTitle("<ADCAmpl> in each cell \b");
      diffADCAmpl_Depth4_HO->SetMarkerColor(2);
      diffADCAmpl_Depth4_HO->SetLineColor(2);
      diffADCAmpl_Depth4_HO->Draw("");




      c1->Update();

    //============================================================================================ 17 HO
    //======================================================================
    //======================================================================
    //================ 
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      
    ///////////////////////////////////////
      c1->cd(1);
    TH2F* Diffe_Depth4_HO0 = (TH2F*)Ceff->Clone("Diffe_Depth4_HO0");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth4_HO0->SetBinContent(i,j,0.);
	  if(ccc1 > 90.)  Diffe_Depth4_HO0->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth4_HO0->SetMarkerStyle(20);
      Diffe_Depth4_HO0->SetMarkerSize(0.4);
      Diffe_Depth4_HO0->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth4_HO0->SetXTitle("#eta \b");
      Diffe_Depth4_HO0->SetYTitle("#phi \b");
      Diffe_Depth4_HO0->SetZTitle("<ADCAmpl> bigger 90.- HO Depth4 \b");
      Diffe_Depth4_HO0->SetMarkerColor(2);
      Diffe_Depth4_HO0->SetLineColor(2);
      Diffe_Depth4_HO0->Draw("COLZ");
      

    ///////////////////////////////////////
      c1->cd(2);
    TH2F* Diffe_Depth4_HO9 = (TH2F*)Ceff->Clone("Diffe_Depth4_HO9");
    int nx = Ceff->GetXaxis()->GetNbins();
    int ny = Ceff->GetYaxis()->GetNbins();
    for (int i=1;i<=nx;i++) {
      for (int j=1;j<=ny;j++) {
	  double ccc1 =  Ceff->GetBinContent(i,j)   ;
	  Diffe_Depth4_HO9->SetBinContent(i,j,0.);
	  if(ccc1 > 91.)  Diffe_Depth4_HO9->SetBinContent(i,j,ccc1);
      }
    }
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Diffe_Depth4_HO9->SetMarkerStyle(20);
      Diffe_Depth4_HO9->SetMarkerSize(0.4);
      Diffe_Depth4_HO9->GetZaxis()->SetLabelSize(0.08);
      Diffe_Depth4_HO9->SetXTitle("#eta \b");
      Diffe_Depth4_HO9->SetYTitle("#phi \b");
      Diffe_Depth4_HO9->SetZTitle("<ADCAmpl> bigger  91. - HO Depth4 \b");
      Diffe_Depth4_HO9->SetMarkerColor(2);
      Diffe_Depth4_HO9->SetLineColor(2);
      Diffe_Depth4_HO9->Draw("COLZ");
      
    ///////////////////////////////////////


      c1->Update();
      
 

    //=============================================================================================== 18 HO
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);

      // Amplitude:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");

      // RMS:      
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Amplitude_HO");



      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
//      TH2F *twod1= (TH2F*)hfile1->Get("h_mapDepth4Amplitude_HO");

      TH2F *twod0= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      twod1->Sumw2();
      twod0->Sumw2();
      if(twod0->IsA()->InheritsFrom("TH2F")){
	TH2F* Cefz= (TH2F*)twod1->Clone("Cefz");
	Cefz->Divide(twod1,twod0, 1, 1, "B");
	Cefz->Sumw2();
      }

      //////////////////////////////////////////////////////////////////////////    Cefz225:  
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth4Amplitude_HO");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl_HO");
//      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth4ADCAmpl12_HO");
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_mapDepth4_HO");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("#eta \b");
      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("RMS - HO Depth4 \b");
      Cefz225->Draw("COLZ");



      c1->cd(2);
    TH2F* Diffe_Depth4_HO = (TH2F*)Cefz225->Clone("Diffe_Depth4_HO");
    int nx = Cefz225->GetXaxis()->GetNbins();
    int ny = Cefz225->GetYaxis()->GetNbins();
    for (int j=1;j<=ny;j++) {
      for (int i=1;i<=nx;i++) {
	//		  double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	double ccc1 =  Cefz225->GetBinContent(i,j)   ;
	//	if(ccc1 > 0.) cout<<" i = "<<i<<" j = "<<j<<"  BinContent= "<<ccc1<<endl;
	//	  Diffe_Depth4_HO->SetBinContent(i,j,0.);
	//	  if(ccc1 <18|| ccc1>30.)  Diffe_Depth4_HO->SetBinContent(i,j,ccc1);
	
	if(i> 41)  {Diffe_Depth4_HO->SetBinContent(i,j,ccc1);}
	else {Diffe_Depth4_HO->SetBinContent(i,j,0.);}
      }
    }
    gPad->SetGridy();
    gPad->SetGridx();
    gPad->SetLogz();
    Diffe_Depth4_HO->SetMarkerStyle(20);
    Diffe_Depth4_HO->SetMarkerSize(0.4);
    Diffe_Depth4_HO->GetZaxis()->SetLabelSize(0.08);
    //    Diffe_Depth4_HO->SetTitle("any Error, HO Depth4 \n");
    Diffe_Depth4_HO->SetXTitle("#eta \b");
    Diffe_Depth4_HO->SetYTitle("#phi \b");
    //    Diffe_Depth4_HO->SetZTitle("<ADCAmpl> bigger 30.& smalle 18 - HO Depth4 \b");
        Diffe_Depth4_HO->SetZTitle("cross check - HO Depth4 \b");
    Diffe_Depth4_HO->SetMarkerColor(2);
    Diffe_Depth4_HO->SetLineColor(2);
    //      Diffe_Depth4_HO->SetMaximum(1.000);
    //      Diffe_Depth4_HO->SetMinimum(0.0000001);
    Diffe_Depth4_HO->Draw("COLZ");
    cout<<" nx = "<< nx <<" ny = "<< ny <<endl;
    


      c1->cd(3);
      TH1F* ADCAmplperLSHO  = new TH1F("ADCAmplperLSHO ","", 72, 1.,73.);
      TH2F* Diffe_Depth4_HO = (TH2F*)Cefz225->Clone("h_mapDepth4_HO ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j++) {
//	cout<<" HO-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i< 42) {
	    //	    	    if(Cefz->GetBinContent(i,j) > 0.) cout<<"HO: i = "<<i<<" j = "<<j<<"  BinContent= "<<    Cefz->GetBinContent(i,j)    <<endl;
	    
	    // no cuts - take all
	    //	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
	    //	    if(Cefz->GetBinContent(i,j)> 1.) {
	    // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 90.) {
	      
	      
	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHO ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HO-    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
//      cout<<" HO-    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HO-    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HO-   - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      

      //      gPad->SetLogy();
      ADCAmplperLSHO ->SetMarkerStyle(20);
      ADCAmplperLSHO ->SetMarkerSize(0.4);
      ADCAmplperLSHO ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHO ->SetXTitle("<ADCAmpl> per LS HO1 \b");
      ADCAmplperLSHO ->SetMarkerColor(2);
      ADCAmplperLSHO ->SetLineColor(4);
//      ADCAmplperLSHO ->SetMaximum(30.0);
//      ADCAmplperLSHO ->SetMinimum(25.0);
      ADCAmplperLSHO->SetXTitle(" #hits vs Phi for  HO-  cut:A>90\\b");
      ADCAmplperLSHO ->Draw();
      
      /////////////////////////////////////////////////////////////////////////////////////////////////
      c1->cd(4);
      TH1F* ADCAmplperLSHO2  = new TH1F("ADCAmplperLSHO2 ","", 72, 1.,73.);
      TH2F* Diffe_Depth4_HO = (TH2F*)Cefz225->Clone("h_mapDepth4_HO ");
      int nx = Cefz225->GetXaxis()->GetNbins();
      int ny = Cefz225->GetYaxis()->GetNbins();
      unsigned long int ncountall=0;
      int ncountmin=0;
      int nnnmin=10000000000000000;
      int nnnbins=0;
      for (int j=1;j<=ny;j++) {
//	cout<<" HO-    ****************   j = "<<   j    <<endl;
	
	for (int i=1;i<=nx;i++) {
	  if(i> 41) {
	    
	    
	    
	    // no cuts - take all
//	    	    if(Cefz->GetBinContent(i,j)> -10.) {
	    // cut on RMS:
//	    if(Cefz->GetBinContent(i,j)> 1.) {
	      // cut on Amplitude
	    if(Cefz->GetBinContent(i,j)> 90.) {


	      double ccc1 =  Cefz225->GetBinContent(i,j);
	      if(ccc1>0.) {
		ADCAmplperLSHO2 ->Fill(float(j), ccc1);
		ncountall += ccc1 ;
		ncountmin += ccc1;
	      }
	    }
	  }
	}
	if(ncountmin> 0) {
//	  cout<<" HO+    - ncountmin = "<<   ncountmin    <<" ncountall  = "<<   ncountall    <<endl;
	  if(ncountmin < nnnmin ) nnnmin = ncountmin;
	  ncountmin=0;
	  nnnbins++;
	}
      }
//      cout<<" HO+    - ncountall = "<<   ncountall    <<" nnnmin= "<<   nnnmin    <<" nnnbins= "<<   nnnbins    <<" Ave= "<<   ncountall/nnnbins    <<endl;
//      if(nnnmin > 0.) cout<<" HO+    - ncountall/nnnbins/nnnmin = "<<   (float)ncountall/nnnbins/nnnmin    <<endl;
      if(nnnmin > 0.) cout<<" HO+    - nnnmin*nnnbins/ncountall = "<<   (float)nnnmin*nnnbins/ncountall    <<endl;
      



      //      gPad->SetLogy();
      ADCAmplperLSHO2 ->SetMarkerStyle(20);
      ADCAmplperLSHO2 ->SetMarkerSize(0.4);
      ADCAmplperLSHO2 ->GetYaxis()->SetLabelSize(0.04);
//      ADCAmplperLSHO2 ->SetXTitle("<ADCAmpl> per LS HO1 \b");
      ADCAmplperLSHO2 ->SetMarkerColor(2);
      ADCAmplperLSHO2 ->SetLineColor(4);
//      ADCAmplperLSHO2 ->SetMaximum(30.0);
//      ADCAmplperLSHO2 ->SetMinimum(25.0);
      ADCAmplperLSHO2->SetXTitle(" #hits vs Phi for  HO+ cut:A>90\b");
      ADCAmplperLSHO2 ->Draw("");
      
      
      c1->Update();
            
    //===============================================================================================  19 HO
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(2,2);
      

      c1->cd(1);
      TH2F *Cefz225= (TH2F*)hfile1->Get("h_RatioOccupancy_HOM");
      int maxbins = 0;
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
//	if(ccc1>0.) cout<<"  iLS = "<<i<<" ccc1= "<<ccc1<<endl;
//	if(ccc1>0.) maxbins++;
	if(ccc1>0.) {maxbins = i; if(i>maxbins) maxbins = i;}
      }
      cout<<"HO maxbins=     "<< maxbins <<endl;

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz225->SetMarkerStyle(20);
      Cefz225->SetMarkerSize(0.4);
      //    Cefz225->GetYaxis()->SetLabelSize(0.04);
      Cefz225->GetZaxis()->SetLabelSize(0.08);
      Cefz225->SetXTitle("LS \b");
      //      Cefz225->SetYTitle("#phi \b");
      Cefz225->SetMarkerColor(2);
      Cefz225->SetLineColor(2);
      //      Cefz225->SetMaximum(1.000);
      //      Cefz225->SetMinimum(0.0001);
        Cefz225->SetZTitle("min/av occupancy - HO M \b");
      Cefz225->Draw("COLZ");

      c1->cd(2);
      TH1F* pour = new TH1F("pour","", maxbins, 1., maxbins+1.);
      //      TH1F* pour = new TH1F("pour","", 125, 1., 126.);
      int nx = Cefz225->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz225->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) pour->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      pour->SetMarkerStyle(20);
      pour->SetMarkerSize(0.4);
      pour->GetYaxis()->SetLabelSize(0.04);
      pour->SetXTitle("min/av occupancy - HO M \b");
      pour->SetMarkerColor(2);
      pour->SetLineColor(0);
      pour->SetMaximum(1.0);
      pour->SetMinimum(0.2);
      pour->Draw("Error");

      c1->cd(3);
      TH2F *Cefz226= (TH2F*)hfile1->Get("h_RatioOccupancy_HOP");
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogz();
      Cefz226->SetMarkerStyle(20);
      Cefz226->SetMarkerSize(0.4);
      //    Cefz226->GetYaxis()->SetLabelSize(0.04);
      Cefz226->GetZaxis()->SetLabelSize(0.08);
      Cefz226->SetXTitle("LS \b");
      //      Cefz226->SetYTitle("#phi \b");
      Cefz226->SetMarkerColor(2);
      Cefz226->SetLineColor(2);
      //      Cefz226->SetMaximum(1.000);
      //      Cefz226->SetMinimum(0.0001);
        Cefz226->SetZTitle("min/av occupancy - HO P \b");
      Cefz226->Draw("COLZ");

      c1->cd(4);
      TH1F* nhgy = new TH1F("nhgy","", maxbins, 1., maxbins+1.);
      //      TH1F* nhgy = new TH1F("nhgy","", 125, 1., 126.);
      int nx = Cefz226->GetXaxis()->GetNbins();
      for (int i=1;i<=nx;i++) {
	double ccc1 =  Cefz226->GetBinContent(i);
	//	  if(ccc1>0.)	  cout<<" depth4_HO iLS = "<<i<<" <As> per LS= "<<ccc1<<endl;
	  if(ccc1>0.) nhgy->Fill(float(i), ccc1);
      }
      //      gPad->SetLogy();
      nhgy->SetMarkerStyle(20);
      nhgy->SetMarkerSize(0.4);
      nhgy->GetYaxis()->SetLabelSize(0.04);
      nhgy->SetXTitle("min/av occupancy - HO P \b");
      nhgy->SetMarkerColor(2);
      nhgy->SetLineColor(0);
      nhgy->SetMaximum(1.0);
      nhgy->SetMinimum(0.2);
      nhgy->Draw("Error");

            
      c1->Update();
    //===============================================================================================  20 HO
    //======================================================================
    //======================================================================
    //================
    //======================================================================
      c1->Clear();
      c1->Divide(1,2);
      

      c1->cd(1);
      pour->SetMaximum(0.9);
      pour->SetMinimum(0.2);
      pour->Draw("Error");


      c1->cd(2);
      nhgy->SetMaximum(0.9);
      nhgy->SetMinimum(0.2);
      nhgy->Draw("Error");



      c1->Update();

    //======================================================================





















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
