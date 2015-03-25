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

//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229514.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229528.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229621.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229653.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229669.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229672.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229685.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229695.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229699.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229702.root", "READ");
	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229713.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229714.root", "READ");
//	TFile *hfile1= new TFile("/afs/cern.ch/user/z/zhokin/public/html/RMT/lastMarch2014/cmt/Global_229715.root", "READ");

//	TFile *hfile1= new TFile("test.root", "READ"); 
//	TFile *hfile1= new TFile("testNZS.root", "READ"); 

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
      c1->Divide(1,2);

      c1->cd(1);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nevents_per_eachLS");
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
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i)   ;
	//	if(ccc1>0) cout<<" i = "<<i<<" #ev per iLS= "<<ccc1<<endl;
	if(i == 227) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
	if(i == 241) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
	if(i == 242) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
	if(i == 243) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
	if(i == 322) cout<<"iLS =     "<< i <<" Nev = "<<ccc1<<endl;
      }
 
      c1->cd(2);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_lsnumber_per_eachLS");
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("LSnumber per iLS \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(1);
      aaaaaa1->SetLineColor(0);
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("Error");
      for (int i=1;i<=nx;i++) {
	double ccc1 =  aaaaaa1->GetBinContent(i)   ;
	//	if(ccc1>0) cout<<" i = "<<i<<" LSnumber per iLS= "<<ccc1<<endl;
	if(i == 227) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
	if(i == 241) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
	if(i == 242) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
	if(i == 243) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
	if(i == 322) cout<<"iLS =     "<< i <<" LSnumber = "<<ccc1<<endl;
      }


      c1->Update();


    //=============================================================================================== 2
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
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      c1->cd(3);
      TH1F *aaaaaa1= (TH1F*)hfile1->Get("h_nls_per_run10");
      //      gPad->SetLogy();
      aaaaaa1->SetMarkerStyle(20);
      aaaaaa1->SetMarkerSize(0.8);
      aaaaaa1->GetYaxis()->SetLabelSize(0.04);
      aaaaaa1->SetXTitle("#LS in run at #ev/LS > 10 \b");
      //    aaaaaa1->SetYTitle("Rate of events \b");
      aaaaaa1->SetMarkerColor(2);
      aaaaaa1->SetLineColor(2);
      aaaaaa1->SetMinimum(0.8);
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
      aaaaaa1->SetMinimum(0.8);
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
      aaaaaa1->SetMinimum(0.8);
      aaaaaa1->Draw("");
       
      
      c1->Update();
      
      

    //======================================================================
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
