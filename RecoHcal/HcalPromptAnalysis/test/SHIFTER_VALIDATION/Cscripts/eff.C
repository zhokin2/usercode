void eff()
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
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // 
  // standard:
//  TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF.root");
  //   TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY.root");
//        TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA.root");

	// _new: 0, 250, 350, 450
//  TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new.root");
  //   TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY_new.root");
//        TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new.root");

//	// _new1: 500, 550, 600, 650
//  TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new1.root");
//   TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY_new1.root");
   //     TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new1.root");

	// _new2: 700, 750, 800, 850
//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new2.root");
//     TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY_new2.root");
	//TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new2.root");

	// _new4:  1000  1150  1300 1450
//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new4.root");
  //   TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY_new4.root");
//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new4.root");

	// _new5:   900  950  1050 1100 (schitalos' pozdnee)
	//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new5.root");
 //    TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_MCDY_new5.root");
	//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new5.root");

	// _new8: 
	//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new8.root");
	//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new8.root");

	// _new9: 
	//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new9.root");
	//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new9.root");

	// _new10: 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new10.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new10.root");
	// _new11: 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new11.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new11.root");
	// _new12: 
	//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_noZsel_MCVBF_new12.root");
	//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_1_2/src/SCRIPTS/HttTJS_Zsel_DATA_new12.root");
  /////////////////////////////
	// _1    : 
//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_tcm1.root");
//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol1.root");
	// _2    : 
//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_isol2.root");
//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol2.root");
	// _3    : 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_isol3.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol3.root");
	// _4    : 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_isol4.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol4.root");
	// _5    : 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_isol5.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol5.root");
	// _6    : 
	//		TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_VBF_isol6.root");
	//		TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJS_DATA_isol6.root");
  /////////////////////////////
	// _2    : 
//			TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJSopt_Signal_2.root");
//			TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_2_8/src/SCRIPTS/HttTJSopt_Data_2.root");
//  /////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c1
  //////////////////////////////////////////////////////////////////////////////////////////////////////////


//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_SnoCJV.root");
//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_DYnoCJV.root");

  //////////////////////////////////////////////////////////////////////////////////////////////////////////


//	TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_SwithCJV.root");
//	TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_4_4_3/src/SCRIPTS/zTJSopt_DYwithCJV.root");



  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


TFile *f_data_1 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_30.root");

//TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_Data.root");
TFile *f_data_2 = new TFile("/afs/cern.ch/user/z/zhokin/w0/higgs/CMSSW_5_3_4/src/SCRIPTS/HiggsTauTau_TJSopt_33.root");


  //////////////////////////////////////////////////////////////////////////////////////////////////////////c1
  /////////////////////////////
    TFile efile("eff.root","recreate");
  
  //-----------------
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c1
  TCanvas *c1 = new TCanvas("c1","c1",500,400);
  ///////////////////////////////////////
     c1->Divide(2,2);

  ///////////////////////////////////////
     c1->cd(1);
  
  TH2F *ah = (TH2F*)f_data_1->Get("EventFractionVsT3JSPtDa");
  TH2F *ah0 = (TH2F*)f_data_1->Get("EventFractionVsT3JSPtDa0");
    ah->Sumw2();
    ah->Sumw2();
    if(ah0->IsA()->InheritsFrom("TH2F")){
      TH2F* Ceff = (TH2F*)ah->Clone("Ceff");
      Ceff->Divide(ah,ah0, 1, 1, "B");
      Ceff->Sumw2();
    }
    /*
  //  TH2F* Ceff = new TH2F("Ceff","", 10, 10., 45., 10, 2.5, 4.5);
  TH2F* Ceff = new TH2F("Ceff","", 20, 20., 70., 20, 0.5, 4.5);

  for (Int_t binx = 1; binx < 21; binx++)  { 
    for (Int_t biny = 1; biny < 21; biny++)  { 
      Double_t ratio=0.;
      if(ah0->GetBinContent(binx,biny) > 0) ratio=ah->GetBinContent(binx,biny)/ah0->GetBinContent(binx,biny);
      //     cout << " binx= "  << binx << " biny= "  << biny <<   " ratio = " << ratio <<endl;

      Ceff->SetBinContent(binx, biny, ratio);
      Ceff->SetBinError(binx, biny,  ratio);
    }
  }
  Ceff->Sumw2();
*/
  Ceff->SetMarkerStyle(20);
  Ceff->SetXTitle("p_{T}, GeV");
  Ceff->SetYTitle("|#Delta #eta|");
  Ceff->SetMarkerColor(1);
  Ceff->SetLineColor(1);
  //  Ceff->SetMaximum(18);
  //  gPad->SetLogy();
  Ceff->Draw("Box");
  ///////////////////////////////////////
     c1->cd(2);
  
  TH2F *azh = (TH2F*)f_data_2->Get("EventFractionVsT3JSPtDa");
  TH2F *azh0 = (TH2F*)f_data_2->Get("EventFractionVsT3JSPtDa0");
    azh->Sumw2();
    azh->Sumw2();
    if(azh0->IsA()->InheritsFrom("TH2F")){
      TH2F* Czeff = (TH2F*)azh->Clone("Czeff");
      Czeff->Divide(azh,azh0, 1, 1, "B");
      Czeff->Sumw2();
    }
    /*
  TH2F* Czeff = new TH2F("Czeff","", 20, 20., 70., 20, 0.5, 4.5);
  
  for (Int_t binx = 1; binx < 21; binx++)  { 
    for (Int_t biny = 1; biny < 21; biny++)  { 
      Double_t ratio=0.;
      if(azh0->GetBinContent(binx,biny) > 0) ratio=azh->GetBinContent(binx,biny)/azh0->GetBinContent(binx,biny);
      Czeff->SetBinContent(binx, biny, ratio);
      Czeff->SetBinError(binx, biny,  ratio);
    }
  }
  Czeff->Sumw2();
*/  
  Czeff->SetMarkerStyle(20);
  Czeff->SetXTitle("p_{T}, GeV");
  Czeff->SetYTitle("|#Delta #eta|");
  Czeff->SetMarkerColor(1);
  Czeff->SetLineColor(1);
  //  Czeff->SetMaximum(18);
  //  gPad->SetLogy();
  Czeff->Draw("Box");
  
  
     c1->cd(3);
  Ceff->Draw("COLZ");
     c1->cd(4);
  Czeff->Draw("COLZ");
  //leg2 = new TLegend(0.45, 0.21, 0.70, 0.47);
  //leg2->AddEntry(dijet_Pt, "INCLUSIVE", "p");
  //leg2->AddEntry(dijet_Pt, "7 TeV DATA", "p");
  //leg2->Draw();
  ///////////////////////////////////////
  
  c1->SaveAs("HIGGS-GIF/SIG-BKG/eff-VBF-Bkg.png");
  
  c1->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c2
  TCanvas *c2 = new TCanvas("c2","c2",500,400);
  ///////////////////////////////////////
  Ceff->Draw("Box");
  
  c2->SaveAs("HIGGS-GIF/SIG-BKG/eff-VBF.png");
  c2->Write();

  ///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c3
  TCanvas *c3 = new TCanvas("c3","c3",500,400);
  ///////////////////////////////////////
  Czeff->Draw("Box");
  
  c3->SaveAs("HIGGS-GIF/SIG-BKG/eff-Bkg.png");
  c3->Write();
  ///////////////////////////////////////
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c4
  TCanvas *c4 = new TCanvas("c4","c4",500,400);
  ///////////////////////////////////////
     c4->Divide(2,2);

  ///////////////////////////////////////
     c4->cd(1);
     Ceff->Draw("LEGO2");
     c4->cd(2);
     Czeff->Draw("LEGO2");
     c4->cd(3);
     Ceff->Draw("SURF2");
     c4->cd(4);
     Czeff->Draw("SURF2");
     //////////////////////////////
  c4->SaveAs("HIGGS-GIF/SIG-BKG/eff-VBF-Bkg-tests.png");
  
  c4->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  

  //////////////////////////////////////////////////////////////////////////////////////////////////////////


	/*
   int Arrow;       // "ARR"   Draw 2D plot with Arrows.
   int Box;         // "BOX"   Draw 2D plot with proportional Boxes.
   int Char;        // "CHAR"  Draw 2D plot with a character set.
   int Color;       // "COL"   Draw 2D plot with Colored boxes.
   int Contour;     // "CONT"  Draw 2D plot as a Contour plot.
   int Func;        // "FUNC"  Draw only the function (for example in case of fit).
   int Hist;        // "HIST"  Draw only the histogram.
   int Lego;        // "LEGO"  Draw as a Lego plot(LEGO,Lego=1, LEGO1,Lego1=11, LEGO2,Lego=12).
   int Scat;        // "SCAT"  Draw 2D plot a Scatter plot.
   int Surf;        // "SURF"  Draw as a Surface (SURF,Surf=1, SURF1,Surf=11, SURF2,Surf=12)
   int Text;        // "TEXT"  Draw 2D plot with the content of each cell.
   int Tri;         // "TRI"   Draw 2D plot with Delaunay triangles.
*/

  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c5
  TCanvas *c5 = new TCanvas("c5","c5",500,400);
  ///////////////////////////////////////
  if(Czeff->IsA()->InheritsFrom("TH2F")){
    TH2F* Purity = (TH2F*)Czeff->Clone("Purity");
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
      cout << "*********    i = "  << i  << "  j = "  << j  << "  ccc3 = "  << ccc3  <<   endl;
      cout << "  ccc1 = "  << ccc1  << "  ccc2 = "  << ccc2  <<   endl;
      Purity->SetBinContent(i,j,ccc3);
      //      Purity->Fill(ccc3,1.);
      //
    }//for j
    //    }// cut on i
  }// for i
  Purity->Sumw2();
  /*
    TH2F* Purity = new TH2F("Purity","", 20, 20., 70., 20, 0.5, 4.5);
    
    for (Int_t binx = 1; binx < 21; binx++)  { 
    for (Int_t biny = 1; biny < 21; biny++)  { 
    Double_t ratio=0.;
    //      if(Purity->GetBinContent(binx,biny) > 0.) ratio=Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny);
    if(Czeff->GetBinContent(binx,biny) > 0.) ratio=Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny);
    //     cout << " binx= "  << binx << " biny= "  << biny <<   " ratio = " << ratio <<endl;
    
    Purity->SetBinContent(binx, biny, ratio);
    Purity->SetBinError(binx, biny,  ratio);
    }
    }
    Purity->Sumw2();
  */  
  Purity->SetMarkerStyle(20);
  Purity->SetXTitle("p_{T}, GeV");
  Purity->SetYTitle("|#Delta #eta|");
  Purity->SetMarkerColor(1);
  Purity->SetLineColor(1);
  Purity->Draw("Box");
  //////////////////////////////
  c5->SaveAs("HIGGS-GIF/SIG-BKG/purity-VBF-Bkg.png");
  
  c5->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c6
  TCanvas *c5 = new TCanvas("c6","c6",500,400);
  Purity->Draw("COLZ");
  c6->SaveAs("HIGGS-GIF/SIG-BKG/purityCOL-VBF-Bkg.png");
  c6->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c7
  TCanvas *c7 = new TCanvas("c7","c7",500,400);
  ///////////////////////////////////////
     Ceff->Draw("COLZ");
  c7->SaveAs("HIGGS-GIF/SIG-BKG/eff-VBF_COL.png");
  c7->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////c8
  TCanvas *c8 = new TCanvas("c8","c8",500,400);
  ///////////////////////////////////////
     Czeff->Draw("COLZ");
  c8->SaveAs("HIGGS-GIF/SIG-BKG/eff-Bkg_COL.png");
  c8->Write();
  //Ceff->Write();
  ///////////////////////////////////////
  ///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // pt>25-37.5, delEta>3.1-4.7  -> 27.5-3.9 S=17.7
//  for (Int_t binx = 7; binx < 12; binx++)  { 
//    for (Int_t biny =4; biny < 12; biny++)  { 
//      cout << " binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
//    }
//  }



  /*
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // pt>30, delEta>3.5  
  for (Int_t binx = 9; binx <10; binx++)  { 
    for (Int_t biny = 6; biny < 7; biny++)  { 
      cout << "pt>30, delEta>3.5 :  "  <<endl;
      cout << " binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // pt>37.5, delEta>4.5  
  for (Int_t binx = 12; binx < 13; binx++)  { 
    for (Int_t biny = 11; biny < 12; biny++)  { 
      cout << "pt>37.5, delEta>4.5 :  "  <<endl;
      cout << " binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  ///////////////////////////////////////
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // pt>37.5, delEta>4.9  
  for (Int_t binx = 12; binx < 13; binx++)  { 
    for (Int_t biny = 13; biny < 14; biny++)  { 
      cout << "pt>37.5, delEta>4.9 :  "  <<endl;
      cout << " binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  ///////////////////////////////////////
  ///////////////////////////////////////
      cout << "======================================================================================= "  <<endl;
  ///////////////////////////////////////
  // pt>25, delEta>2.5  
  for (Int_t binx = 7; binx <8; binx++)  { 
    for (Int_t biny = 1; biny < 2; biny++)  { 
      cout << "0 pt>25, delEta>2.5 :  "  <<endl;
      cout << " 0 binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  ///////////////////////////////////////
  // pt>27.5, delEta>2.5,  
  for (Int_t binx = 8; binx <10; binx++)  { 
    for (Int_t biny = 1; biny < 2; biny++)  { 
      cout << "0 pt>27.5, delEta>2.5 :  "  <<endl;
      cout << " 0 binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  
  ///////////////////////////////////////
  // pt>32.5, delEta>3.7  
  for (Int_t binx =10; binx <11; binx++)  { 
    for (Int_t biny = 7; biny < 8; biny++)  { 
      cout << "0 pt>32.5, delEta>3.7 :  "  <<endl;
      cout << " 0 binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  
  ///////////////////////////////////////
  // pt>35.0, delEta>3.7  
  for (Int_t binx =11; binx <12; binx++)  { 
    for (Int_t biny = 7; biny < 8; biny++)  { 
      cout << "0 pt>35., delEta>3.7 :  "  <<endl;
      cout << " 0 binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }
  
  
  for (Int_t binx =7; binx <13; binx++)  { 
    for (Int_t biny = 1; biny <14; biny++)  { 
      cout << " binx= "  << binx << " biny= "  << biny <<   " Ceff = " << Ceff->GetBinContent(binx,biny) <<   " Czeff = " << Czeff->GetBinContent(binx,biny) <<   " P = " << Ceff->GetBinContent(binx,biny)*Ceff->GetBinContent(binx,biny)/Czeff->GetBinContent(binx,biny) <<endl;
    }
  }

*/  
  

  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  return;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  
}

