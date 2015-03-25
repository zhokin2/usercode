void htttjsopt()
{
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////// style
  //gStyle->SetOptStat(111111);
        gROOT->SetStyle("Plain");
		gStyle->SetOptStat(0);   //  no statistics _or_
		//         	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//gStyle->SetOptStat(0101);// name and entries
	//	   gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

	gStyle->SetPalette(1);
//---=[ Pad style ]=----------------
        gStyle->SetPadTopMargin(TopOffset);
        gStyle->SetPadBottomMargin(LeftOffset);
        gStyle->SetPadRightMargin(TopOffset);
        gStyle->SetPadLeftMargin(LeftOffset);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // 
  //////////////////////////////////////////////////////////////////////////////////////////////////////////


//TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_SnoCJV.root");
//TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_DYnoCJV.root");

 
////////////////////////////////////////////////////////////////////////////////////////////////////////


//TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_SwithCJV.root");
//TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_DYwithCJV.root");

////////////////////////////////////////////////////////////////////////////////////////////////////////


TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_30.root");

//TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_Data.root");
TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_33.root");



  /////////////////////////////
  Double_t nvtx_data[60];
  Double_t Sum_nvtx_data = 0.;

    Double_t nvtx_mc[60];
    Double_t Sum_nvtx_mc = 0.;
    //-----------------------     Data PU:for    ------------------------------------------------
          
    TFile* file1 = new TFile("MyDataPileupHistogram_12.root");// AB runs:160871 - 163869
    for (Int_t id = 0; id < 60; id++) {
      if(id<50) {nvtx_data[id] = pileup->GetBinContent(id+1);}
      else{nvtx_data[id] = 0.;}
      Sum_nvtx_data +=nvtx_data[id];
//      cout <<"Data: bin id = " << id <<"  bin content 1 = " << nvtx_data1[id] << endl; 
    }
    TFile* file = new TFile("PUa_gen0.root");
    //-----------------------      
    for (Int_t im = 0; im < 60; im++) {
      nvtx_mc[im] = histo_genPUs->GetBinContent(im+1);
//      cout <<"MC: bin im = " << im <<"  bin content = " << nvtx_mc[im] << endl; 
      Sum_nvtx_mc +=nvtx_mc[im];
    }
      cout <<"                          MC: Sum_nvtx_mc = " << Sum_nvtx_mc << endl; 

    //-----------------------                        MC PU:for MC weight applied   ------------------------------------------------
//  TH2F *ah = (TH2F*)f_data_1->Get("EventFractionVsT3JSPtDaMM250");
//  TH1F *ah = (TH1F*)file->Get("EventFractionVsT3JSPtDaMM250");


    
      cout <<"      PU normilizing factor to have w=1 after PU-reweighting = " << Sum_nvtx_mc/Sum_nvtx_data << endl; 
    //////////////////////////////////////////////////////////////////////////////////////////////////////////c1
      Sum_nvtx_mc =1.;
      Sum_nvtx_data =1.;
  /////////////////////////////
    TFile efile("htttjsopt.root","recreate");
  
  //-----------------
      Double_t aaaa = 0.03;
    //  Double_t aaaa = 1.;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 243 vs Pt
  TCanvas *c1 = new TCanvas("c1","c1",500,400);
  ///////////////////////////////////////
  TH1F *ah = (TH1F*)f_data_1->Get("EventFractionVsTJSPt243");
  TH1F *ah0 = (TH1F*)f_data_1->Get("EventFractionVsTJSPt0");
    ah->Sumw2();
    ah0->Sumw2();
    if(ah0->IsA()->InheritsFrom("TH1F")){
      TH1F* Ceff = (TH1F*)ah->Clone("Ceff");
      Ceff->Divide(ah,ah0, 1, 1, "B");
      Ceff->Sumw2();
    }
    /*
  TH1F* Ceff = new TH1F("Ceff","", 20, 20., 70.);

  //  Ceff->Divide(ah, ah0,1.,1.,"B");

 for (Int_t binx = 1; binx < 21; binx++)  { 
   Double_t ratio=0.;
   if(ah0->GetBinContent(binx) > 0) ratio=ah->GetBinContent(binx)/ah0->GetBinContent(binx);
   Ceff->SetBinContent(binx, ratio);
   Ceff->SetBinError(binx,  aaaa*ratio);
 }


 Ceff->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  Ceff->SetMarkerStyle(20);
  Ceff->SetXTitle("Pt, GeV");
  Ceff->SetYTitle("eff.");
  Ceff->SetMarkerColor(4);
  Ceff->SetLineColor(4);
  //  Ceff->SetMaximum(18);
  //  gPad->SetLogy();
  Ceff->Draw("Error");
  //////////////////////////////////
  TH1F *ahz = (TH1F*)f_data_2->Get("EventFractionVsTJSPt243");
  TH1F *ahz0 = (TH1F*)f_data_2->Get("EventFractionVsTJSPt0");
    ahz->Sumw2();
    ahz0->Sumw2();
    if(ahz0->IsA()->InheritsFrom("TH1F")){
      TH1F* Czeff = (TH1F*)ahz->Clone("Czeff");
      Czeff->Divide(ahz,ahz0, 1, 1, "B");
      Czeff->Sumw2();
    }
    /*
  TH1F* Czeff = new TH1F("Czeff","", 20, 20., 70.);

  //  Czeff->Divide(ah, ah0,1.,1.,"B");

  
  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(ahz0->GetBinContent(binx) > 0) ratio=ahz->GetBinContent(binx)/ahz0->GetBinContent(binx);
      //     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;

      Czeff->SetBinContent(binx, ratio);
      Czeff->SetBinError(binx,  aaaa*ratio);
  }

  Czeff->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  
  Czeff->SetMarkerStyle(20);
  Czeff->SetXTitle("Pt, GeV");
  Czeff->SetYTitle("eff.");
  Czeff->SetMarkerColor(4);
  Czeff->SetLineColor(4);
  //  Czeff->SetMaximum(18);
  //  gPad->SetLogy();
  Czeff->Draw("Error");
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c2
  TCanvas *c2 = new TCanvas("c2","c2",500,400);
  Ceff->Draw("Error");
//  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff243-VBF.gif");
  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff243-VBF.png");
  c2->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c3
  TCanvas *c3 = new TCanvas("c3","c3",500,400);
  Czeff->Draw("Error");
//  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff243-Bkg.gif");
  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff243-Bkg.png");
  c3->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c5
  TCanvas *c5 = new TCanvas("c5","c5",500,400);
  if(Czeff->IsA()->InheritsFrom("TH1F")){
    TH1F* Purity = (TH1F*)Czeff->Clone("Purity");
    //      Purity->Multiply(Ceff,Ceff, 1, 1, "B");
    //      Purity->Divide(Purity,Czeff, 1, 1, "B");
    //      Purity->Divide(Ceff,Czeff, 1, 1, "B");
  }
  
  int nx = Purity->GetXaxis()->GetNbins();
  int ny = Purity->GetYaxis()->GetNbins();
  for (int i=1;i<=nx;i++) {
    for (int j=1;j<=ny;j++) {
      //                                                            
      double ccc1 = 0.;
      double ccc2 = 0.;
      double ccc3 = 0.1;
      //                                                            
      ccc1 =Ceff->GetBinContent(i,j);
      ccc2 =Czeff->GetBinContent(i,j);
      if(ccc2 > 0.00001) {
	ccc3 = ccc1*ccc1/ccc2;
      }
      //    cout << "*********    i = "  << i  << "  j = "  << j  << "  ccc3 = "  << ccc3  <<   endl;
      //    cout << "  ccc1 = "  << ccc1  << "  ccc2 = "  << ccc2  <<   endl;
      Purity->SetBinContent(i,j,ccc3);
      //      Purity->Fill(ccc3,1.);
      //
    }//for j
    //    }// cut on i
  }// for i
  Purity->Sumw2();





  /*
  TH1F* Purity = new TH1F("Purity","", 20, 20., 70.);
//    Purity->Divide(Ceff, Czeff,1.,1.,"B");
//    Purity->Multiply(Purity, Ceff,1.,1.,"B");

//  Purity->Multiply(Ceff, Ceff,1.,1.,"B");
//  Purity->Divide(Purity, Czeff,1.,1.,"B");



  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(Czeff->GetBinContent(binx) > 0.) ratio=Ceff->GetBinContent(binx)*Ceff->GetBinContent(binx)/Czeff->GetBinContent(binx);
      Purity->SetBinContent(binx, ratio);
      Purity->SetBinError(binx, aaaa*ratio);  }

  Purity->Sumw2();
*/
  Purity->SetMarkerStyle(20);
  Purity->SetYTitle("Signif.");
  Purity->SetXTitle("Pt, GeV");
  Purity->SetMarkerColor(4);
  Purity->SetLineColor(4);
  Purity->Draw("Error");
//  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity243-VBF-Bkg.gif");
  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity243-VBF-Bkg.png");

  c5->Write();

  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c9
  TCanvas *c9 = new TCanvas("c9","c9",500,400);
  // Signal: Nev =   1732824 Xsec = 745 fb.   L_mc      = 1732824/745. = 2325.938 fp-1;      mscale = 1/L =  0.000429934 fb/ev.
  Double_t mscaleS=0.000429934;// Signal  Xsec normalization, fb
  Double_t mscaleSPU  = 0.000429934*Sum_nvtx_mc/Sum_nvtx_data;// Signal  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Signal mscaleS    = " << mscaleS << endl;
  cout <<"===--> Xsec normalization, fb:Signal mscaleSPU    = " << mscaleSPU << endl;
  TH1F *SignalXsec = (TH1F*)f_data_1->Get("EventFractionVsTJSPt243");
       gPad->SetGridy();
       gPad->SetGridx();
  SignalXsec->Sumw2();
  SignalXsec->SetMarkerStyle(20);
  SignalXsec->SetMarkerColor(4);
  SignalXsec->SetLineColor(4);
  SignalXsec->Scale(mscaleSPU);
  SignalXsec->SetXTitle("Pt, GeV");
  SignalXsec->SetYTitle("S #sigma, fb");
  SignalXsec->Draw("Error");
//  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec243-VBF.gif");
  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec243-VBF.png");
  c9->Write();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c10
  TCanvas *c10 = new TCanvas("c10","c10",500,400);
  // DY-Bkg: Nev =   36264432 Xsec = 3048000. fb.  L_mc = 36264432/3048000. = 11.89778 fp-1; mscale = 1/L =  0.084049    fb/ev.
  Double_t mscaleB=0.084049;// DY-Bkg  Xsec normalization, fb
  Double_t mscaleBPU=0.084049*Sum_nvtx_mc/Sum_nvtx_data;// DY-Bkg  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Bkg mscaleB    = " << mscaleB << endl;
  cout <<"===--> Xsec normalization, fb:Bkg mscaleBPU    = " << mscaleBPU << endl;
  TH1F *BkgXsec = (TH1F*)f_data_2->Get("EventFractionVsTJSPt243");
       gPad->SetGridy();
       gPad->SetGridx();
  BkgXsec->Sumw2();
  BkgXsec->SetMarkerStyle(20);
  BkgXsec->SetMarkerColor(4);
  BkgXsec->SetLineColor(4);
  BkgXsec->Scale(mscaleBPU);
  BkgXsec->SetXTitle("Pt, GeV");
  BkgXsec->SetYTitle("B #sigma, fb");
  BkgXsec->Draw("Error");
//  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec243-Bkg.gif");
  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec243-Bkg.png");
  c10->Write();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 143 vs Da
  TCanvas *c1 = new TCanvas("c1","c1",500,400);
  ///////////////////////////////////////
  TH1F *ah = (TH1F*)f_data_1->Get("EventFractionVsTJSDa143");
  TH1F *ah0 = (TH1F*)f_data_1->Get("EventFractionVsTJSDa0");
    ah->Sumw2();
    ah0->Sumw2();
    if(ah0->IsA()->InheritsFrom("TH1F")){
      TH1F* Cdef143 = (TH1F*)ah->Clone("Cdef143");
      Cdef143->Divide(ah,ah0, 1, 1, "B");
      Cdef143->Sumw2();
    }
    /*
  TH1F* Cdef143 = new TH1F("Cdef143","", 20, 0.5, 4.5);

  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(ah0->GetBinContent(binx) > 0) ratio=ah->GetBinContent(binx)/ah0->GetBinContent(binx);
      //     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;

      Cdef143->SetBinContent(binx, ratio);
      Cdef143->SetBinError(binx,  aaaa*ratio);
  }
  Cdef143->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  Cdef143->SetMarkerStyle(20);
  Cdef143->SetXTitle("|#Delta #eta|");
  Cdef143->SetYTitle("eff.");
  Cdef143->SetMarkerColor(4);
  Cdef143->SetLineColor(4);
  //  Cdef143->SetMaximum(18);
  //  gPad->SetLogy();
  Cdef143->Draw("Error");
  //////////////////////////////////
  TH1F *ahz = (TH1F*)f_data_2->Get("EventFractionVsTJSDa143");
  TH1F *ahz0 = (TH1F*)f_data_2->Get("EventFractionVsTJSDa0");
    ahz->Sumw2();
    ahz0->Sumw2();
    if(ahz0->IsA()->InheritsFrom("TH1F")){
      TH1F* Czdef143 = (TH1F*)ahz->Clone("Czdef143");
      Czdef143->Divide(ahz,ahz0, 1, 1, "B");
      Czdef143->Sumw2();
    }
    /*
  TH1F* Czdef143 = new TH1F("Czdef143","", 20, 0.5, 4.5);

  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(ahz0->GetBinContent(binx) > 0) ratio=ahz->GetBinContent(binx)/ahz0->GetBinContent(binx);
      //     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;

      Czdef143->SetBinContent(binx, ratio);
      Czdef143->SetBinError(binx,  aaaa*ratio);
  }
  Czdef143->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  
  Czdef143->SetMarkerStyle(20);
  Czdef143->SetXTitle("|#Delta #eta|");
  Czdef143->SetYTitle("eff.");
  Czdef143->SetMarkerColor(4);
  Czdef143->SetLineColor(4);
  //  Czdef143->SetMaximum(18);
  //  gPad->SetLogy();
  Czdef143->Draw("Error");
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c2
  TCanvas *c2 = new TCanvas("c2","c2",500,400);
  Cdef143->Draw("Error");
//  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff143-VBF.gif");
  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff143-VBF.png");
  c2->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c3
  TCanvas *c3 = new TCanvas("c3","c3",500,400);
  Czdef143->Draw("Error");
//  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff143-Bkg.gif");
  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff143-Bkg.png");
  c3->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c5
  TCanvas *c5 = new TCanvas("c5","c5",500,400);
  if(Czdef143->IsA()->InheritsFrom("TH1F")){
    TH1F* Signif143 = (TH1F*)Czdef143->Clone("Signif143");
  }
  int nx = Signif143->GetXaxis()->GetNbins();
  int ny = Signif143->GetYaxis()->GetNbins();
  for (int i=1;i<=nx;i++) {
    for (int j=1;j<=ny;j++) {
      double ccc1 = 0.;
      double ccc2 = 0.;
      double ccc3 = 0.1;
      ccc1 =Cdef143->GetBinContent(i,j);
      ccc2 =Czdef143->GetBinContent(i,j);
      if(ccc2 > 0.00001) {
	ccc3 = ccc1*ccc1/ccc2;
      }
      Signif143->SetBinContent(i,j,ccc3);
    }//for j
  }// for i
  Signif143->Sumw2();

  /*
  TH1F* Signif143 = new TH1F("Signif143","", 20, 0.5, 4.5);
  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(Czdef143->GetBinContent(binx) > 0.) ratio=Cdef143->GetBinContent(binx)*Cdef143->GetBinContent(binx)/Czdef143->GetBinContent(binx);
      Signif143->SetBinContent(binx, ratio);
      Signif143->SetBinError(binx, aaaa*ratio);  }
  Signif143->Sumw2();
*/
  Signif143->SetMarkerStyle(20);
  Signif143->SetYTitle("Signif.");
  Signif143->SetXTitle("|#Delta #eta|");
  Signif143->SetMarkerColor(4);
  Signif143->SetLineColor(4);
  Signif143->Draw("Error");
//  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity143-VBF-Bkg.gif");
  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity143-VBF-Bkg.png");

  c5->Write();

  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c9
  TCanvas *c9 = new TCanvas("c9","c9",500,400);
  // Signal: Nev =   1732824 Xsec = 745 fb.   L_mc      = 1732824/745. = 2325.938 fp-1;      mscale = 1/L =  0.000429934 fb/ev.
  Double_t mscaleS=0.000429934;// Signal  Xsec normalization, fb
  Double_t mscaleSPU  = 0.000429934*Sum_nvtx_mc/Sum_nvtx_data;// Signal  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Signal mscaleS    = " << mscaleS << endl;
  cout <<"===--> Xsec normalization, fb:Signal mscaleSPU    = " << mscaleSPU << endl;
  TH1F *SignalXsec = (TH1F*)f_data_1->Get("EventFractionVsTJSDa143");
       gPad->SetGridy();
       gPad->SetGridx();
  SignalXsec->Sumw2();
  SignalXsec->SetMarkerStyle(20);
  SignalXsec->SetMarkerColor(4);
  SignalXsec->SetLineColor(4);
  SignalXsec->Scale(mscaleSPU);
  SignalXsec->SetXTitle("|#Delta #eta|");
  SignalXsec->SetYTitle("S #sigma, fb");
  SignalXsec->Draw("Error");
//  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec143-VBF.gif");
  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec143-VBF.png");
  c9->Write();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c10
  TCanvas *c10 = new TCanvas("c10","c10",500,400);
  // DY-Bkg: Nev =   36264432 Xsec = 3048000. fb.  L_mc = 36264432/3048000. = 11.89778 fp-1; mscale = 1/L =  0.084049    fb/ev.
  Double_t mscaleB=0.084049;// DY-Bkg  Xsec normalization, fb
  Double_t mscaleBPU=0.084049*Sum_nvtx_mc/Sum_nvtx_data;// DY-Bkg  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Bkg mscaleB    = " << mscaleB << endl;
  cout <<"===--> Xsec normalization, fb:Bkg mscaleBPU    = " << mscaleBPU << endl;
  TH1F *BkgXsec = (TH1F*)f_data_2->Get("EventFractionVsTJSDa143");
       gPad->SetGridy();
       gPad->SetGridx();
  BkgXsec->Sumw2();
  BkgXsec->SetMarkerStyle(20);
  BkgXsec->SetMarkerColor(4);
  BkgXsec->SetLineColor(4);
  BkgXsec->Scale(mscaleBPU);
  BkgXsec->SetXTitle("|#Delta #eta|");
  BkgXsec->SetYTitle("B #sigma, fb");
  BkgXsec->Draw("Error");
//  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec143-Bkg.gif");
  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec143-Bkg.png");
  c10->Write();
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 123 vs Mjj
  TCanvas *c1 = new TCanvas("c1","c1",500,400);
  ///////////////////////////////////////
  TH1F *ah = (TH1F*)f_data_1->Get("EventFractionVsTJSMjj123");
  TH1F *ah0 = (TH1F*)f_data_1->Get("EventFractionVsTJSMjj0");
    ah->Sumw2();
    ah0->Sumw2();
    if(ah0->IsA()->InheritsFrom("TH1F")){
      TH1F* C123abc = (TH1F*)ah->Clone("C123abc");
      C123abc->Divide(ah,ah0, 1, 1, "B");
      C123abc->Sumw2();
    }
    /*
  TH1F* C123abc = new TH1F("C123abc","", 20, 0., 1000.);

  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(ah0->GetBinContent(binx) > 0) ratio=ah->GetBinContent(binx)/ah0->GetBinContent(binx);
      //     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;

      C123abc->SetBinContent(binx, ratio);
      C123abc->SetBinError(binx,  aaaa*ratio);
  }
  C123abc->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  C123abc->SetMarkerStyle(20);
  C123abc->SetXTitle("Mjj, GeV");
  C123abc->SetYTitle("eff.");
  C123abc->SetMarkerColor(4);
  C123abc->SetLineColor(4);
  //  C123abc->SetMaximum(18);
  //  gPad->SetLogy();
  C123abc->Draw("Error");
  //////////////////////////////////
  TH1F *ahz = (TH1F*)f_data_2->Get("EventFractionVsTJSMjj123");
  TH1F *ahz0 = (TH1F*)f_data_2->Get("EventFractionVsTJSMjj0");
    ahz->Sumw2();
    ahz0->Sumw2();
    if(ahz0->IsA()->InheritsFrom("TH1F")){
      TH1F* Cz123abc = (TH1F*)ahz->Clone("Cz123abc");
      Cz123abc->Divide(ahz,ahz0, 1, 1, "B");
      Cz123abc->Sumw2();
    }
    /*
  TH1F* Cz123abc = new TH1F("Cz123abc","", 20, 0., 1000.);

  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(ahz0->GetBinContent(binx) > 0) ratio=ahz->GetBinContent(binx)/ahz0->GetBinContent(binx);
      //     cout << " binx= "  << binx <<   " ratio = " << ratio <<endl;

      Cz123abc->SetBinContent(binx, ratio);
      Cz123abc->SetBinError(binx,  aaaa*ratio);
  }
  Cz123abc->Sumw2();
*/
       gPad->SetGridy();
       gPad->SetGridx();
  Cz123abc->SetMarkerStyle(20);
  Cz123abc->SetXTitle("Mjj, GeV");
  Cz123abc->SetYTitle("eff.");
  Cz123abc->SetMarkerColor(4);
  Cz123abc->SetLineColor(4);
  //  Cz123abc->SetMaximum(18);
  //  gPad->SetLogy();
  Cz123abc->Draw("Error");
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c2
  TCanvas *c2 = new TCanvas("c2","c2",500,400);
  C123abc->Draw("Error");
//  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff123-VBF.gif");
  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff123-VBF.png");
  c2->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c3
  TCanvas *c3 = new TCanvas("c3","c3",500,400);
  Cz123abc->Draw("Error");
//  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff123-Bkg.gif");
  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff123-Bkg.png");
  c3->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c5
  TCanvas *c5 = new TCanvas("c5","c5",500,400);
  if(Cz123abc->IsA()->InheritsFrom("TH1F")){
    TH1F* Sign123 = (TH1F*)Cz123abc->Clone("Sign123");
  }
  int nx = Sign123->GetXaxis()->GetNbins();
  int ny = Sign123->GetYaxis()->GetNbins();
  for (int i=1;i<=nx;i++) {
    for (int j=1;j<=ny;j++) {
      double ccc1 = 0.;
      double ccc2 = 0.;
      double ccc3 = 0.1;
      ccc1 =C123abc->GetBinContent(i,j);
      ccc2 =Cz123abc->GetBinContent(i,j);
      if(ccc2 > 0.00001) {
	ccc3 = ccc1*ccc1/ccc2;
      }
      Sign123->SetBinContent(i,j,ccc3);
    }//for j
  }// for i
  Sign123->Sumw2();



  /*
  TH1F* Sign123 = new TH1F("Sign123","", 20, 0., 1000.);
  for (Int_t binx = 1; binx < 21; binx++)  { 
      Double_t ratio=0.;
      if(Cz123abc->GetBinContent(binx) > 0.) ratio=C123abc->GetBinContent(binx)*C123abc->GetBinContent(binx)/Cz123abc->GetBinContent(binx);
      Sign123->SetBinContent(binx, ratio);
      Sign123->SetBinError(binx, aaaa*ratio);  }
  Sign123->Sumw2();
*/
  Sign123->SetMarkerStyle(20);
  Sign123->SetYTitle("Signif.");
  Sign123->SetXTitle("Mjj, GeV");
  Sign123->SetMarkerColor(4);
  Sign123->SetLineColor(4);
  Sign123->Draw("Error");
//  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity123-VBF-Bkg.gif");
  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity123-VBF-Bkg.png");

  c5->Write();

  //////////////////////////////////////////////////////////////////////////////////////////////////////////c9
  TCanvas *c9 = new TCanvas("c9","c9",500,400);
  // Signal: Nev =   1732824 Xsec = 745 fb.   L_mc      = 1732824/745. = 2325.938 fp-1;      mscale = 1/L =  0.000429934 fb/ev.
  Double_t mscaleS=0.000429934;// Signal  Xsec normalization, fb
  Double_t mscaleSPU  = 0.000429934*Sum_nvtx_mc/Sum_nvtx_data;// Signal  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Signal mscaleS    = " << mscaleS << endl;
  cout <<"===--> Xsec normalization, fb:Signal mscaleSPU    = " << mscaleSPU << endl;
  TH1F *SignalXsec = (TH1F*)f_data_1->Get("EventFractionVsTJSMjj123");
       gPad->SetGridy();
       gPad->SetGridx();
  SignalXsec->Sumw2();
  SignalXsec->SetMarkerStyle(20);
  SignalXsec->SetMarkerColor(4);
  SignalXsec->SetLineColor(4);
  SignalXsec->Scale(mscaleSPU);
  SignalXsec->SetXTitle("Mjj, GeV");
  SignalXsec->SetYTitle("S #sigma, fb");
  SignalXsec->Draw("Error");
//  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec123-VBF.gif");
  c9->SaveAs("HIGGS-GIF/SIG-BKG/Xsec123-VBF.png");
  c9->Write();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c10
  TCanvas *c10 = new TCanvas("c10","c10",500,400);
  // DY-Bkg: Nev =   36264432 Xsec = 3048000. fb.  L_mc = 36264432/3048000. = 11.89778 fp-1; mscale = 1/L =  0.084049    fb/ev.
  Double_t mscaleB=0.084049;// DY-Bkg  Xsec normalization, fb
  Double_t mscaleBPU=0.084049*Sum_nvtx_mc/Sum_nvtx_data;// DY-Bkg  Xsec normalization, fb
  cout <<"===--> Xsec normalization, fb:Bkg mscaleB    = " << mscaleB << endl;
  cout <<"===--> Xsec normalization, fb:Bkg mscaleBPU    = " << mscaleBPU << endl;
  TH1F *BkgXsec = (TH1F*)f_data_2->Get("EventFractionVsTJSMjj123");
       gPad->SetGridy();
       gPad->SetGridx();
  BkgXsec->Sumw2();
  BkgXsec->SetMarkerStyle(20);
  BkgXsec->SetMarkerColor(4);
  BkgXsec->SetLineColor(4);
  BkgXsec->Scale(mscaleBPU);
  BkgXsec->SetXTitle("Mjj, GeV");
  BkgXsec->SetYTitle("B #sigma, fb");
  BkgXsec->Draw("Error");
//  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec123-Bkg.gif");
  c10->SaveAs("HIGGS-GIF/SIG-BKG/Xsec123-Bkg.png");
  c10->Write();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  return;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  
}

