#include <iostream>
#include <fstream>
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TROOT.h"
#include <TMath.h>
#include "TStyle.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TText.h"
#include "TAxis.h"
#include "TFile.h"
#include "TLine.h"
#include "TGraph.h"
#include <TPaveText.h>
#include <TPostScript.h>
#include <TClass.h>
#include <TLatex.h>
#include <TFrame.h>
#include <TPad.h>
#include <TGaxis.h>

#include "TGraphErrors.h"
#include "TF1.h"
#include "TArrow.h"

//
using namespace std;
//
//  
int main(int argc, char *argv[])
{
  //______________________________________________________________________________________________________________________________    
  //TCanvas *c1;
  TGraph *gr1;  TGraph *gr2;TGraph *gr3;  TGraph *gr4;TGraph *gr5;  TGraph *gr6;TGraph *gr7;TGraph *gr8;TGraph *gr9;
  TGraphErrors* ge1;TGraphErrors* ge2;TGraphErrors* ge3;TGraphErrors* ge4;TGraphErrors* ge5;TGraphErrors* ge6;TGraphErrors* ge7;TGraphErrors* ge8;TGraphErrors* ge9;

  //
  const Int_t NMethods =16;// total number of Methods (all-together 37 methods)
  const Int_t NMethodsStart =0;     // since which method to start ( min=  0)
  const Int_t NMethodsToUse =15;// choose Number of methods to use ( max= 36)
  //
 TString MethodName[NMethods] = { "PLOT0", "PLOT1", "PLOT2", "PLOT3", "PLOT4", "PLOT5" , "PLOT6" , "PLOT7" , "PLOT8" , "PLOT9" , "PLOT10"  , "PLOT11" , "PLOT12" , "PLOT13", "PLOT14" , "PLOT15" };
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
//______________________________________________________________________________________________________________________________    
  //______________________________________________________________________________________________________________________________   WORKABLE:
 
  //______________________________________________________________________________________________________________________________ 22+161=183   

 const Int_t NMAX =392;// 
 TString LEDruns[NMAX] = {
"303442", "303443", "303444", "303445", "303446", "303454", "303458", "303464", "303466", "303475", 
"303477", "303484", "303493", "303494", "303498", "303499", "303507", "303514", "303557", "303565", 
"303568", "303569", "303572", "303573", "303574", "303575", "303576", "303582", "303586", "303589", 
"303590", "303592", "303593", "303595", "303601", "303602", "303603", "303604", "303605", "303606", 
"303607", "303608", "303610", "303613", "303615", "303616", "303617", "303621", "303623", "303638", 
"303647", "303649", "303652", "303657", "303658", "303665", "303676", "303677", "303678", "303684", 
"303694", "303698", "303699", "303700", "303701", "303702", "303704", "303705", "303706", "303707", 
"303708", "303709", "303711", "303712", "303714", "303718", "303719", "303728", "303729", "303731", 
"303732", "303734", "303739", "303740", "303741", "303742", "303743", "303744", "303745", "303746", 
"303750", "303765", "303766", "303772", "303775", "303776", "303779", "303780", "303783", "303790", 
"303793", "303794", "303795", "303806", "303807", "303808", "303813", "303814", "303815", "303816", 
"303817", "303818", "303819", "303820", "303823", "303824", "303825", "303826", "303830", "303831", 
"303832", "303835", "303837", "303838", "303846", "303855", "303859", "303864", "303868", "303870", 
"303878", "303884", "303885", "303888", "303889", "303891", "303896", "303920", "303937", "303946", 
"303947", "303948", "303989", "303990", "303991", "303994", "303995", "303997", "303998", "303999", 
"304000", "304002", "304003", "304009", "304012", "304013", "304015", "304018", "304020", "304023", 
"304028", "304032", "304045", "304054", "304055", "304057", "304058", "304059", "304060", "304061", 
"304062", "304074", "304086", "304093", "304104", "304115", "304117", "304119", "304120", "304125", 
"304129", "304131", "304134", "304143", "304144", "304149", "304150", "304151", "304152", "304153", 
"304154", "304155", "304158", "304160", "304165", "304168", "304169", "304170", "304182", "304185", 
"304186", "304188", "304189", "304190", "304191", "304192", "304194", "304196", "304197", "304198", 
"304199", "304200", "304201", "304203", "304204", "304205", "304206", "304209", "304212", "304213", 
"304226", "304237", "304244", "304245", "304248", "304249", "304254", "304259", "304269", "304282", 
"304286", "304290", "304291", "304292", "304299", "304300", "304301", "304303", "304311", "304312", 
"304313", "304314", "304315", "304316", "304317", "304323", "304326", "304328", "304329", "304330", 
"304331", "304332", "304333", "304346", "304348", "304349", "304350", "304351", "304353", "304354", 
"304355", "304356", "304364", "304365", "304366", "304422", "304428", "304431", "304435", "304441", 
"304444", "304446", "304447", "304448", "304449", "304451", "304452", "304453", "304455", "304456", 
"304457", "304482", "304485", "304486", "304500", "304503", "304504", "304505", "304506", "304507", 
"304508", "304511", "304514", "304517", "304533", "304535", "304542", "304555", "304556", "304557", 
"304560", "304562", "304597", "304600", "304602", "304610", "304611", "304612", "304615", "304616", 
"304618", "304622", "304623", "304625", "304626", "304627", "304628", "304629", "304632", "304639", 
"304641", "304643", "304644", "304645", "304649", "304650", "304651", "304652", "304653", "304654", 
"304655", "304657", "304659", "304661", "304662", "304663", "304665", "304668", "304669", "304671", 
"304672", "304673", "304675", "304679", "304686", "304688", "304697", "304700", "304701", "304705", 
"304709", "304710", "304711", "304713", "304720", "304722", "304724", "304725", "304727", "304728", 
"304729", "304734", "304737", "304738", "304739", "304740", "304742", "304751", "304758", "304775", 
"304776", "304777", "304778", "304779", "304781", "304782", "304784", "304785", "304787", "304789", 
"304790", "304791", "304792", "304793", "304794", "304795", "304796", "304797", "304817", "304819", 
"304821", "304822"

 };
 ///////////////////////////////
 Float_t X0[NMAX] = {
   1.,       2.,       3.,       4.,       5.,       6.,       7.,       8.,       9.,       10.,   
  11.,      12.,      13.,      14.,      15.,      16.,      17.,      18.,      19.,       20.,   
  21.,      22.,      23.,      24.,      25.,      26.,      27.,      28.,      29.,       30.,   
  31.,      32.,      33.,      34.,      35.,      36.,      37.,      38.,      39.,       40.,   
  41.,      42.,      43.,      44.,      45.,      46.,      47.,      48.,      49.,       50.,   
  51.,      52.,      53.,      54.,      55.,      56.,      57.,      58.,      59.,       60.,   
  61.,      62.,      63.,      64.,      65.,      66.,      67.,      68.,      69.,       70.,   
  71.,      72.,      73.,      74.,      75.,      76.,      77.,      78.,      79.,       80.,   
  81.,      82.,      83.,      84.,      85.,      86.,      87.,      88.,      89.,       90.,   
  91.,      92.,      93.,      94.,      95.,      96.,      97.,      98.,      99.,      100.,   
 101.,     102.,     103.,     104.,     105.,     106.,     107.,     108.,     109.,      110.,   
 111.,     112.,     113.,     114.,     115.,     116.,     117.,     118.,     119.,      120.,   
 121.,     122.,     123.,     124.,     125.,     126.,     127.,     128.,     129.,      130.,   
 131.,     132.,     133.,     134.,     135.,     136.,     137.,     138.,     139.,      140.,   
 141.,     142.,     143.,     144.,     145.,     146.,     147.,     148.,     149.,      150.,   
 151.,     152.,     153.,     154.,     155.,     156.,     157.,     158.,     159.,      160.,   
 161.,     162.,     163.,     164.,     165.,     166.,     167.,     168.,     169.,      170.,   
 171.,     172.,     173.,     174.,     175.,     176.,     177.,     178.,     179.,      180.,   
 181.,     182.,     183.,     184.,     185.,     186.,     187.,     188.,     189.,      190.,   
 191.,     192.,     193.,     194.,     195.,     196.,     197.,     198.,     199.,      200.,   
 201.,     202.,     203.,     204.,     205.,     206.,     207.,     208.,     209.,      210.,   
 211.,     212.,     213.,     214.,     215.,     216.,     217.,     218.,     219.,      220.,   
 221.,     222.,     223.,     224.,     225.,     226.,     227.,     228.,     229.,      230.,   
 231.,     232.,     233.,     234.,     235.,     236.,     237.,     238.,     239.,      240.,   
 241.,     242.,     243.,     244.,     245.,     246.,     247.,     248.,     249.,      250.,   
 251.,     252.,     253.,     254.,     255.,     256.,     257.,     258.,     259.,      260.,   
 261.,     262.,     263.,     264.,     265.,     266.,     267.,     268.,     269.,      270.,   
 271.,     272.,     273.,     274.,     275.,     276.,     277.,     278.,     279.,      280.,   
 281.,     282.,     283.,     284.,     285.,     286.,     287.,     288.,     289.,      290.,   
 291.,     292.,     293.,     294.,     295.,     296.,     297.,     298.,     299.,      300.,   
 301.,     302.,     303.,     304.,     305.,     306.,     307.,     308.,     309.,      310.,   
 311.,     312.,     313.,     314.,     315.,     316.,     317.,     318.,     319.,      320.,   
 321.,     322.,     323.,     324.,     325.,     326.,     327.,     328.,     329.,      330.,   
 331.,     332.,     333.,     334.,     335.,     336.,     337.,     338.,     339.,      340.,   
 341.,     342.,     343.,     344.,     345.,     346.,     347.,     348.,     349.,      350.,   
 351.,     352.,     353.,     354.,     355.,     356.,     357.,     358.,     359.,      360.,   
 361.,     362.,     363.,     364.,     365.,     366.,     367.,     368.,     369.,      370.,   
 371.,     372.,     373.,     374.,     375.,     376.,     377.,     378.,     379.,      380.,   
 381.,     382.,     383.,     384.,     385.,     386.,     387.,     388.,     389.,      390.,   
 391.,     392.
 };// 


  //______________________________________________________________________________
  //
  //---=[ SetCanvasDef           ]=----------------
  // Create a new canvas.
 //TCanvas  *c1 = new TCanvas("c1","GSM",10,10,900,700);

 //TCanvas  *c1 = new TCanvas("c1","GSM",20,50,920,850);
 TCanvas  *c1 = new TCanvas("c1","GSM",10,10,1010,1010);
 
 
 //TCanvas  *c1 = new TCanvas("c1","GSM",200,10,700,900);
 //TCanvas  *c1 = new TCanvas("c1","Hcal4test",200,10,700,900);
 
 c1->Range(0,0,25,18);
 //c1->SetFillColor(40);
 c1->SetFillColor(0);
 c1->Clear();
 
 TLatex *t = new TLatex();
 t->SetTextFont(32);
 //t->SetTextColor(4);
 t->SetTextSize(0.03);
 t->SetTextAlign(12);
 //______________________________________________________________________________
 t->DrawLatex(0.9,15.5,"Time dependence of full Amplitude averaged over events of each LED run for some random HB channels");
 
 //-----------------------------------------------------------------------------------------------------
 //
 //              x1   y1     x2     y2
 //    pad1->DrawFrame(1,   0.8,  370,   1.2);// all 
 
 //
 Float_t x1=0.00; Float_t x2=400.0;
 
 Float_t y1=0.; Float_t y2=  1.2; //
 //
 // 
 Float_t xx1=0.35; Float_t xx2=0.55;
 Float_t yy1=0.76; Float_t yy2=0.88;
 // 
 //-----------------------------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------------------------
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // define max size of massives (to be just NMAXSIZE ):
 Int_t NMAXSIZE = NMAX;
 //----------------------------------------------------------------------
 Double_t XX[NMAXSIZE]; Double_t XXE[NMAXSIZE]; Double_t XXX[NMAXSIZE]; Double_t XXXE[NMAXSIZE]; 
 Double_t YY[NMAXSIZE]; Double_t YYE[NMAXSIZE]; 
 //
 Double_t GSMRATIOD2[NMAXSIZE]; 
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 //---------------------------------------------------------------------------------------------------------------------
 Int_t NP = NMAX;  // for loop over time points(LED runs) NMAX is number of LED runs(time abscissa)
 cout << " NP = " << NP <<endl;
 //
 //---------------------------------------------------------------------------------------------------------------------  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 
 Double_t cutMinA =0.; Double_t cutMaxA = 999999999999.;
 // 	    	        Double_t cutMinA =50000.; Double_t cutMaxA = 350000.;
 
 //    Double_t cutMinA =9000.; Double_t cutMaxA = 40000.;  
 //
 // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //---------------------------------------------------------------------------------------------------------------------
 //------------------------------------ define DELTA (days) of current point wrt first point
 for(int kk1 = 0; kk1<NP; kk1++){ 
   XX[kk1] = X0[kk1];   
   int k10 = 0; 
      int z1=X0[k10];  
      XX[kk1] -= z1;  
      //      if(verbosity == 2 ){cout << "ORDINATE points:    kk1 =  " <<kk1   <<"  XX[kk1]= " << XX[kk1] <<endl;}
      
      XXE[kk1] = 0.001*XX[kk1];
 }//XXE - errors at fit
 //-----------------------------------------------------------------------------------------------------
 
 
  //----------------------------------------------------------------------------------------------------
  //----------------------------------------------------------------------------------------------------
  ///////////////////////////////////////////////////////////////////////// initial nulling:
      for(int k1 = 0; k1<NP; k1++) {
	GSMRATIOD2[k1]= -1.;
      }

  /////////////////////////////////////////////////////////////////////////

  //______________________________________________________________________________
  //     ls -latr /afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_* | less  

  //  TString fname = "/afs/cern.ch/work/z/zhokin/hcal/roc4/CMSSW_9_2_14/src/RecoHcal/HcalPromptAnalysis/test/SHIFTER_VALIDATION/finalruns";


//    TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LED_";
//  TString fname = "/afs/cern.ch/cms/CAF/CMSALCA/ALCA_HCALCALIB/HCALMONITORING/RDMweb/histos/LASER_";

  // booking:
  cout << "!!!!!!!!!!!!!!!!!!!!!! use root files from my dir. " <<endl;
  /////////////////////////////////////////////////////////////////////////////////////////      
  /*
    h_ADCAmplZoom1_HB = new TH1F("h_ADCAmplZoom1_HB"," ", 100, -20.,480.);
    h_ADCAmplZoom1_HE = new TH1F("h_ADCAmplZoom1_HE"," ", 100, -200.,9800.);
    h_ADCAmplZoom1_HF = new TH1F("h_ADCAmplZoom1_HF"," ", 100, -200.,9800.);
    h_ADCAmplZoom1_HO = new TH1F("h_ADCAmplZoom1_HO"," ", 100, -20.,480.);
*/
  TH1F* Aeff0D = new TH1F("Aeff0D","", 100, 0.,100.);
  TH1F* h_entrtotalzero0 = new TH1F("h_entrtotalzero0","", 110, 0.,110.);
  TH1F* h_maxbinnonzero0 = new TH1F("h_maxbinnonzero0","", 110, 0.,110.);
  TH1F* h_contentofmaxbinnonzero0 = new TH1F("h_contentofmaxbinnonzero0","", 100, 0.,10.);

  /*
    h_sumamplitudechannel_HB  = new TH1F("h_sumamplitudechannel_HB"," ",      100,  0., 2000.);
    h_sumamplitudechannel_HE  = new TH1F("h_sumamplitudechannel_HE"," ",      100,  0., 2000.);
    h_sumamplitudechannel_HF  = new TH1F("h_sumamplitudechannel_HF"," ",      100,  0.,20000.);
    h_sumamplitudechannel_HO  = new TH1F("h_sumamplitudechannel_HO"," ",      100,  0., 2000.);
*/
  TH1F* Aeff1D = new TH1F("Aeff1D","", 100, 0.,100.);
  TH1F* h_entrtotalzero1 = new TH1F("h_entrtotalzero1","", 110, 0.,110.);
  TH1F* h_maxbinnonzero1 = new TH1F("h_maxbinnonzero1","", 110, 0.,110.);
  TH1F* h_contentofmaxbinnonzero1 = new TH1F("h_contentofmaxbinnonzero1","", 100, 0.,10.);


  /*
    h_eventamplitude_HB  = new TH1F("h_eventamplitude_HB"," ",      100,  0.,  80000.);
    h_eventamplitude_HE  = new TH1F("h_eventamplitude_HE"," ",      100,  0., 100000.);
    h_eventamplitude_HF  = new TH1F("h_eventamplitude_HF"," ",      100,  0., 150000.);
    h_eventamplitude_HO  = new TH1F("h_eventamplitude_HO"," ",      100,  0., 250000.);
*/
  TH1F* Aeff2D = new TH1F("Aeff2D","", 100, 0.,100.);
  TH1F* h_entrtotalzero2= new TH1F("h_entrtotalzero2","", 110, 0.,110.);
  TH1F* h_maxbinnonzero2= new TH1F("h_maxbinnonzero2","", 110, 0.,110.);
  TH1F* h_contentofmaxbinnonzero2= new TH1F("h_contentofmaxbinnonzero2","", 100,  0., 10.);



    /////////////////////////////////////////////////////////////////////////////////////////      LOOP     LOOP   LOOP   LOOP   LOOP LOOP
  int ck1count = 0; int ck2count = 0;
  float npedestal = 0;
  float nsignal = 0;
  for(int k1 = 0; k1<NP; k1++) {
    ck1count++;
    //    if(ck1count> 5 && ck1count < 19 ) {
    if(ck1count> 0 ) {
    /////////////////////////////////////////////////////////////////////////////////////////      
    // my dir.
    //	  TString epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";
		     TString epsName = "finalruns/Global_" + LEDruns[k1] + ".root";
    
    //      if(k1 > 21) {epsName = fname + LEDruns[k1] + ".root";}// 2018 shunt1
    //    	  TString epsName = "rootshunt1/LEDtest" + LEDruns[k1] + ".root";
    
    /*
      TString epsName;
      if(k1 < 0) {epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";}// was used: shunt6 for HEP17 2017 channels !!!
      if(k1 == 0) {epsName = "rootshunt1/LEDtest" + LEDruns[k1] + ".root";}
      if(k1 == 1) {epsName = "rootshunt6/LEDtest" + LEDruns[k1] + ".root";}
*/
      //		  TString epsName = "LEDtest" + LEDruns[k1] + ".root";

      //	  TString epsName = "LEDtest309714.root";
		  //	  TString epsName = "LEDtest307971NEW.root";

      // RMT:
      //      	  	    TString epsName = fname + LEDruns[k1] +".root";

      /////////////////////////////////////////////////////////////////////////////////////////      
      
      TFile *hfile= new TFile(epsName, "READ");



      /////////////////////////////////////////////////////////////////////////////////////////      

      /*
h_ADCAmplZoom1_HB
CHANNELADCAMPLITUDE.png
*/    

// mixture0:
      int metkanodigicollection = 0;
      TH1F * Aeff0= (TH1F*)hfile->Get("h_ADCAmplZoom1_HB");
      int entrtotal0 = Aeff0->GetEntries();
      //      int entrtotal0 = Aeff0->GetMean(); 
      if(entrtotal0 == 0 ) {
	h_entrtotalzero0->Fill(float(entrtotal0) );
	metkanodigicollection = 1;
	//	break;
      }
      /////////////////////////////////////////////////////////////////////////////////////////      
      if(metkanodigicollection == 0 ) {
	int kz = Aeff0->GetXaxis()->GetNbins();
	//      cout  <<"BEGINNING k1= " << k1 <<" kz= " << kz <<endl;
	int maxvalueA0 = -1;
	for (int jjj=0;jjj<kz;jjj++) {
	  if(double(Aeff0->GetBinContent(jjj))>0. && maxvalueA0 < jjj ) maxvalueA0 = jjj;
	  //	cout  <<" k1= " << k1 <<" jjj= " << jjj <<" content= " << Aeff0->GetBinContent(jjj) <<endl;
	  Aeff0D->Fill(float(jjj), double(Aeff0->GetBinContent(jjj)) );
	}// for
	//      cout  <<" run = " << LEDruns[k1]  <<" k1= " << k1 <<" max bin value= " << maxvalueA0 <<" ck1count= " << ck1count <<endl;
	h_maxbinnonzero0->Fill(float(maxvalueA0) );
	h_contentofmaxbinnonzero0->Fill(double(Aeff0->GetBinContent(maxvalueA0)));
      }     
      
      // 
      // 
      // display last-run existing histoes:
	//	if(k1== NP-1 ) {
	  //       if(ck2count== 1 ) {
             if(ck2count== 14 ) {
	  c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy(); 

	gPad->SetGridx();
		gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff0->SetMarkerStyle(20);
	Aeff0->SetMarkerSize(0.6);
	Aeff0->GetYaxis()->SetLabelSize(0.04);
	//	Aeff0->SetTitle("Last run & events & channels");
	Aeff0->SetXTitle("Aijk");
	Aeff0->SetYTitle("N");
	Aeff0->SetMarkerColor(4);
	Aeff0->SetLineColor(4);
	Aeff0->SetMinimum(0.8);
	Aeff0->Draw("E");
	//	Aeff0->Draw("PL");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "Aijk.png";
	TString plotName = fdir + "Aijk-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijkLastRun.png is drawn **** " <<endl;
       }
      // display first runt existing histoes:
	//     if(k1== NP-2 ) {
	 //       if(ck2count== 2 ) {
             if(ck2count== 15 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy();
	gPad->SetGridx();
	//	gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff0->SetMarkerStyle(20);
	Aeff0->SetMarkerSize(0.6);
	Aeff0->GetYaxis()->SetLabelSize(0.04);
	//	Aeff0->SetTitle("First run & events & channels");
	Aeff0->SetXTitle("Aijk");
	Aeff0->SetYTitle("N");
	Aeff0->SetMarkerColor(4);
	Aeff0->SetLineColor(4);
	Aeff0->SetMinimum(0.8);
	//	Aeff0->Draw("PL");
	Aeff0->Draw("E");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "AijkFirstRun.png";
	TString plotName = fdir + "Aijk-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijkLAST.png is drawn **** " <<endl;
      }



      /*
h_sumamplitudechannel_HB
SUMMEDAMPLITUDES.png

h_sumamplitudechannel_HB
ChannelDepthsummedAmplitudes.png
*/    

// mixture1:
	       TH1F * Aeff1= (TH1F*)hfile->Get("h_sumamplitudechannel_HB");
	     if(metkanodigicollection == 0 ) {
	       int entrtotal1 = Aeff1->GetEntries();
	       //      int entrtotal1 = Aeff1->GetMean(); 
	       if(entrtotal1 == 0 ) h_entrtotalzero1->Fill(float(entrtotal1) );
	       
	       /////////////////////////////////////////////////////////////////////////////////////////      
	       int kx = Aeff1->GetXaxis()->GetNbins();
	       //      cout  <<"BEGINNING k1= " << k1 <<" kx= " << kx <<endl;
	       int maxvalueA1 = -1;
	       for (int jjj=0;jjj<kx;jjj++) {
		 if(double(Aeff1->GetBinContent(jjj))>0. && maxvalueA1 < jjj ) maxvalueA1 = jjj;
		 //	cout  <<" k1= " << k1 <<" jjj= " << jjj <<" content= " << Aeff1->GetBinContent(jjj) <<endl;
		 Aeff1D->Fill(float(jjj), double(Aeff1->GetBinContent(jjj)) );
	       }// for
	       //      cout  <<" run = " << LEDruns[k1]  <<" k1= " << k1 <<" max bin value= " << maxvalueA <<" ck1count= " << ck1count <<endl;
	       h_maxbinnonzero1->Fill(float(maxvalueA1) );
	       h_contentofmaxbinnonzero1->Fill(double(Aeff1->GetBinContent(maxvalueA1)));
	     }     
	     
      // 
      // 
      // display last-run existing histoes:
	//	if(k1== NP-1 ) {
	  //      if(ck2count== 1 ) {
             if(ck2count== 14 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy(); 

	gPad->SetGridx();
		gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff1->SetMarkerStyle(20);
	Aeff1->SetMarkerSize(0.6);
	Aeff1->GetYaxis()->SetLabelSize(0.04);
	//	Aeff1->SetTitle("Last run & events & channels");
	Aeff1->SetXTitle("Aij");
	Aeff1->SetYTitle("N");
	Aeff1->SetMarkerColor(4);
	Aeff1->SetLineColor(4);
	Aeff1->SetMinimum(0.8);
	Aeff1->Draw("E");
	//	Aeff1->Draw("PL");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "Aijk.png";
	TString plotName = fdir + "Aij-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijLastRun.png is drawn **** " <<endl;
       }
      // display first runt existing histoes:
	     //           if(k1== NP-2 ) {
	       //       if(ck2count== 2 ) {
             if(ck2count== 15 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy();
	gPad->SetGridx();
	//	gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff1->SetMarkerStyle(20);
	Aeff1->SetMarkerSize(0.6);
	Aeff1->GetYaxis()->SetLabelSize(0.04);
	//	Aeff1->SetTitle("First run & events & channels");
	Aeff1->SetXTitle("Aij");
	Aeff1->SetYTitle("N");
	Aeff1->SetMarkerColor(4);
	Aeff1->SetLineColor(4);
	Aeff1->SetMinimum(0.8);
	//	Aeff1->Draw("PL");
	Aeff1->Draw("E");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "AijkFirstRun.png";
	TString plotName = fdir + "Aij-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AijLAST.png is drawn **** " <<endl;
      }


      /*
    // for averSIGNALOCCUPANCY :
    h_averSIGNALoccupancy_HB  = new TH1F("h_averSIGNALoccupancy_HB"," ",     bac, 1.,bac2);
    h_averSIGNALoccupancy_HE  = new TH1F("h_averSIGNALoccupancy_HE"," ",     bac, 1.,bac2);
    h_averSIGNALoccupancy_HF  = new TH1F("h_averSIGNALoccupancy_HF"," ",     bac, 1.,bac2);
    h_averSIGNALoccupancy_HO  = new TH1F("h_averSIGNALoccupancy_HO"," ",     bac, 1.,bac2);
    
    // for averSIGNALsumamplitude :
    h_averSIGNALsumamplitude_HB  = new TH1F("h_averSIGNALsumamplitude_HB"," ",     bac, 1.,bac2);
    h_averSIGNALsumamplitude_HE  = new TH1F("h_averSIGNALsumamplitude_HE"," ",     bac, 1.,bac2);
    h_averSIGNALsumamplitude_HF  = new TH1F("h_averSIGNALsumamplitude_HF"," ",     bac, 1.,bac2);
    h_averSIGNALsumamplitude_HO  = new TH1F("h_averSIGNALsumamplitude_HO"," ",     bac, 1.,bac2);
    
    // for averNOSIGNALOCCUPANCY :
    h_averNOSIGNALoccupancy_HB  = new TH1F("h_averNOSIGNALoccupancy_HB"," ",     bac, 1.,bac2);
    h_averNOSIGNALoccupancy_HE  = new TH1F("h_averNOSIGNALoccupancy_HE"," ",     bac, 1.,bac2);
    h_averNOSIGNALoccupancy_HF  = new TH1F("h_averNOSIGNALoccupancy_HF"," ",     bac, 1.,bac2);
    h_averNOSIGNALoccupancy_HO  = new TH1F("h_averNOSIGNALoccupancy_HO"," ",     bac, 1.,bac2);
    
    // for averNOSIGNALsumamplitude :
    h_averNOSIGNALsumamplitude_HB  = new TH1F("h_averNOSIGNALsumamplitude_HB"," ",     bac, 1.,bac2);
    h_averNOSIGNALsumamplitude_HE  = new TH1F("h_averNOSIGNALsumamplitude_HE"," ",     bac, 1.,bac2);
    h_averNOSIGNALsumamplitude_HF  = new TH1F("h_averNOSIGNALsumamplitude_HF"," ",     bac, 1.,bac2);
    h_averNOSIGNALsumamplitude_HO  = new TH1F("h_averNOSIGNALsumamplitude_HO"," ",     bac, 1.,bac2);
      */



      /*
      h_eventamplitude_HB->Fill((sumamplitudesubdet+sumamplitudesubdet0));
      h_eventoccupancy_HB->Fill((sumofchannels+sumofchannels0));

    // for event Amplitudes for each sub-detector
    h_eventamplitude_HB  = new TH1F("h_eventamplitude_HB"," ",      100,  0.,  80000.);
    h_eventamplitude_HE  = new TH1F("h_eventamplitude_HE"," ",      100,  0., 100000.);
    h_eventamplitude_HF  = new TH1F("h_eventamplitude_HF"," ",      100,  0., 150000.);
    h_eventamplitude_HO  = new TH1F("h_eventamplitude_HO"," ",      100,  0., 250000.);

    // for event Occupancy for each sub-detector
    h_eventoccupancy_HB  = new TH1F("h_eventoccupancy_HB"," ",      100,  0.,  3000.);
    h_eventoccupancy_HE  = new TH1F("h_eventoccupancy_HE"," ",      100,  0.,  2000.);
    h_eventoccupancy_HF  = new TH1F("h_eventoccupancy_HF"," ",      100,  0.,  1000.);
    h_eventoccupancy_HO  = new TH1F("h_eventoccupancy_HO"," ",      100,  0.,  2500.);

*/    
      // mixture2:
	       TH1F * Aeff2= (TH1F*)hfile->Get("h_eventamplitude_HB");
	       int entrtotal2 = Aeff2->GetEntries();
	     if(metkanodigicollection == 0 ) {
	       //    int entrtotal2 = Aeff2->GetMean(1); 
	       if(entrtotal2 == 0 ) {
		 h_entrtotalzero2->Fill(float(entrtotal2) );
		 //	break;
	       }
	       else {
		 /////////////////////////////////////////////////////////////////////////////////////////      
		 float nsignalrun=0.;float npedestalrun=0.;
		 int kx2 = Aeff2->GetXaxis()->GetNbins();
		 int maxvalueA2= -1;
		 for (int jjj=0;jjj<kx2;jjj++) {
		   if(double(Aeff2->GetBinContent(jjj))>0. && maxvalueA2 < jjj ) maxvalueA2 = jjj;
		   Aeff2D->Fill(float(jjj), double(Aeff2->GetBinContent(jjj)) );
		   if(jjj< 30 ) {npedestal += Aeff2->GetBinContent(jjj);npedestalrun += Aeff2->GetBinContent(jjj);}
		   else  {nsignal += Aeff2->GetBinContent(jjj);	nsignalrun += Aeff2->GetBinContent(jjj);}
		 }// for
		 h_maxbinnonzero2->Fill(float(maxvalueA2) );
		 h_contentofmaxbinnonzero2->Fill(double(Aeff2->GetBinContent(maxvalueA2)));
		 if((nsignalrun+npedestalrun) != 0. ) GSMRATIOD2[k1]= nsignalrun/(nsignalrun+npedestalrun);	
	       }//else
	     }
	     ck2count++;
	     cout << "!!!! read LED run with k1= " << k1   << "  entrtotal2= " << entrtotal2   << "  Rsignal= " << GSMRATIOD2[k1]   <<"  run:  " << LEDruns[k1] <<endl;

     // 
      // 
      // display last-run existing histoes:
      //       if(k1== NP-1 ) {
      //         if(ck2count== 1 ) {
             if(ck2count== 14 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy(); 

	gPad->SetGridx();
		gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff2->SetMarkerStyle(20);
	Aeff2->SetMarkerSize(0.8);
	Aeff2->GetYaxis()->SetLabelSize(0.04);
	//	Aeff2->SetTitle("Last run & events & channels");
	Aeff2->SetXTitle("Aevent");
	Aeff2->SetYTitle("N");
	Aeff2->SetMarkerColor(2);
	Aeff2->SetLineColor(2);
	Aeff2->SetMinimum(0.8);
	Aeff2->Draw("Error");
	//	Aeff2->Draw("PL");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "Aevent.png";
	TString plotName = fdir + "Aevent-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AeventLastRun.png is drawn **** " <<endl;
       }
      // display first runt existing histoes:
	     //            if(k1== NP-2 ) {
	     //        if(ck2count== 2 ) {
             if(ck2count== 15 ) {
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	gPad->SetGridy();
	gPad->SetGridx();
	//	gPad->SetLogy();
	gStyle->SetOptStat(101110); 
	Aeff2->SetMarkerStyle(20);
	Aeff2->SetMarkerSize(0.8);
	Aeff2->GetYaxis()->SetLabelSize(0.04);
	Aeff2->SetTitle("First run & events & channels");
	Aeff2->SetXTitle("Aevent");
	Aeff2->SetYTitle("N");
	Aeff2->SetMarkerColor(2);
	Aeff2->SetLineColor(2);
	Aeff2->SetMinimum(0.8);
	//	Aeff2->Draw("PL");
	Aeff2->Draw("Error");
	c1->Update();
	TString fdir = "zamt2mixing2018/";
	//	TString plotName = fdir + "AeventFirstRun.png";
	TString plotName = fdir + "Aevent-Run"+  LEDruns[k1] + ".png";
	c1->SaveAs(plotName);
	cout<<"****PLOT  AeventLAST.png is drawn **** " <<endl;
      }


      // 000000000000000000000000000000000000000000000000000000000000000000000000
      
      ///////////////////// hfile->Close();
      hfile->Close();
      ///////////////////// 
    }// if
  }//for k1 loop over time points(LED runs)
  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                   DONE: last LED run READ " <<endl;
  
  //	c1->Clear();
  
  
  cout  <<"=============================================== ck1count= " << ck1count <<" ck2count= " << ck2count <<endl;
  cout << "!!!! npedestal= " << npedestal   << "  nsignal= " << nsignal   <<"  total=  " << nsignal+npedestal <<endl;
  cout << "!!!! Rnpedestal= " << npedestal/(nsignal+npedestal)  << "  Rnsignal= " << nsignal/(nsignal+npedestal)   <<endl;
 
  // ////////////////////////////////////////////////////////////////////////////////////////////////// END OF LOOP OVER LED RUNS
  ////////////////////////////////////////////////////////////////////////////////////////////////////  END OF LOOP OVER LED RUNS
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   DRAWING   DRAWING   DRAWING   DRAWING   DRAWING
      cout<<"****  ****  ****  ****  ****     Draw Dependencies: *** " <<endl;

      
      
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      Int_t Method = NMethodsStart ;
  while (Method<NMethodsToUse+1) {
    if( Method != 9999992 )
      {
	cout<<" ****  START   Method " << Method <<endl;
    //  //////////////////////////////////////////////////////////////////////////
    //======================================================================================================= PLOT2  GSM ratio vs days
    if(Method == 2 ) {
      cout<<"****Draw 2 Dependencies: GSM ratio vs days  *** " <<endl;
      for(int k1 = 0; k1<NP; k1++) {YY[k1]=0.;}
      //      c1->Range(0,0,25,18);
      //      c1->SetFillColor(0);
      //      c1->Clear();
      TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.99,0.99,0);
      pad1->Draw();
      pad1->cd();
      pad1->Range(-0.255174,-19.25,2.29657,-6.75);
      //              x1   y1     x2     y2
      pad1->DrawFrame(x1,y1,x2,y2);  // 1-A, 
      //  pad1->DrawFrame(1,   0.,  370,   2.0);  // 1-A, 
      pad1->GetFrame()->SetFillColor(0);
      pad1->Draw();
      gPad->SetGridy();gPad->SetGridx(); 
      //                -   -       -        -   -  -                                                            -   -   -       -           -    -
      Int_t colorlines = 0;      
      Int_t generalcount = 0;      
      
      Int_t sscount = -1;
      ////////////////////////////////////////////////////////////////////////////////////////////////////
      for(int k1 = 0; k1<NP; k1++) {
	sscount++;
	YY[sscount] = GSMRATIOD2[k1];// 
	XXX[sscount] = XX[k1];
      }//for k1
      ////////////////////////////////////////////////////////////////////////////////////////////////////
      
      Int_t MMcount = sscount+1;
      if(MMcount>0) {
	generalcount++;
	gr1 = new TGraph(MMcount,XXX,YY); 
	colorlines = generalcount/5.+2;
	gr1->SetLineColor(colorlines);  gr1->SetMarkerColor(colorlines); 
	gr1->SetMarkerStyle(20); gr1->SetMarkerSize(1.2); gr1->SetFillStyle(0); 
	gr1->GetXaxis()->SetTitle("irun"); gr1->GetYaxis()->SetTitle("Rsignal");
	//	gr1->GetXaxis()->SetXTitle("irun");gr1->GetXaxis()->SetYTitle("Rsignal");
	//	gr1->Draw("PL");
	gr1->Draw("P");
      }// if
      
      //      TLegend leg(.6,.67,.78,.88, " HBP Depth1");
      //   TLegend leg(xx1,yy1,xx2,yy2, "HBP17: R vs t");
      TLegend leg(xx1,yy1,xx2,yy2, "HB: Rsignal vs irun");
      //      leg.AddEntry(gr1);
      leg.SetMargin( 0.3 );
      leg.SetBorderSize(1);
      leg.DrawClone("Same");
      /*      
      // Draw labels on the y axis
      TText *t7 = new TText();
      t7->SetTextAlign(32);
      t7->SetTextSize(0.035);
      t7->SetTextFont(72);
      char *labels[NP+1] = {"31","1","7","7","8","9","12","13","19","22","22","24","24","24","24","24","24","Feb."};
      float X7[NP];
      for(int k1 = 0; k1<NP; k1++) {
      //	cout<<"**** XXX[k1] =  " << XXX[k1] <<"     YY[k1] =  " << YY[k1] <<   endl;
      t7->DrawText(0.2+XXX[k1],0.890,labels[k1]);
      }
      t7->DrawText(0.2+XXX[NP-1]+75.,0.890,labels[NP]);
      */
      
    }////Method = 2
    //
    //======================================================================================================= PLOT3:  entrtotalzero2  for each event and all runs 
    if(Method == 3) {
      cout<<"****Draw 3 Dependencies: entrtotalzero2 for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_entrtotalzero2->SetStats(0);
      h_entrtotalzero2->SetMarkerStyle(20);
      h_entrtotalzero2->SetMarkerSize(0.4);
      h_entrtotalzero2->GetYaxis()->SetLabelSize(0.04);
      h_entrtotalzero2->SetTitle("all runs & events");
      h_entrtotalzero2->SetXTitle("N entries = 0 no HBHEHO digiCollection ");
      h_entrtotalzero2->SetYTitle("N");
      h_entrtotalzero2->SetMarkerColor(4);
      h_entrtotalzero2->SetLineColor(4);
      //    h_entrtotalzero2->Draw("Error");
      //    h_entrtotalzero2->Draw("PL");
       h_entrtotalzero2->SetMinimum(0.8);
       h_entrtotalzero2->Draw("");

      c1->Update();

    }//Method = 3

    //======================================================================================================= PLOT4:  contentofmaxbinnonzero2  for each event and all runs 
    if(Method == 4) {
      cout<<"****Draw 4 Dependencies: contentofmaxbinnonzero2  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_contentofmaxbinnonzero2->SetStats(0);
      h_contentofmaxbinnonzero2->SetMarkerStyle(20);
      h_contentofmaxbinnonzero2->SetMarkerSize(0.4);
      h_contentofmaxbinnonzero2->GetYaxis()->SetLabelSize(0.04);
      h_contentofmaxbinnonzero2->SetTitle("all runs & events");
      h_contentofmaxbinnonzero2->SetXTitle("content of max non-zero bin ");
      h_contentofmaxbinnonzero2->SetYTitle("N");
      h_contentofmaxbinnonzero2->SetMarkerColor(4);
      h_contentofmaxbinnonzero2->SetLineColor(4);
      //    h_contentofmaxbinnonzero2->Draw("Error");
      //    h_contentofmaxbinnonzero2->Draw("PL");
       h_contentofmaxbinnonzero2->SetMinimum(0.8);
       h_contentofmaxbinnonzero2->Draw("");

      c1->Update();

    }//Method = 4

    //======================================================================================================= PLOT5:  maxbinnonzero2  for each event and all runs 
    if(Method == 5) {
      cout<<"****Draw 5 Dependencies: maxbinnonzero2  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_maxbinnonzero2->SetStats(0);
      h_maxbinnonzero2->SetMarkerStyle(20);
      h_maxbinnonzero2->SetMarkerSize(0.4);
      h_maxbinnonzero2->GetYaxis()->SetLabelSize(0.04);
      h_maxbinnonzero2->SetTitle("all runs & events");
      h_maxbinnonzero2->SetXTitle("max non-zero bin ");
      h_maxbinnonzero2->SetYTitle("N");
      h_maxbinnonzero2->SetMarkerColor(4);
      h_maxbinnonzero2->SetLineColor(4);
      //    h_maxbinnonzero2->Draw("Error");
      //    h_maxbinnonzero2->Draw("PL");
       h_maxbinnonzero2->SetMinimum(0.8);
       h_maxbinnonzero2->Draw("");

      c1->Update();

    }//Method = 5

    //======================================================================================================= PLOT6:  Aevent  for each event and all runs 
    if(Method == 6) {
      cout<<"****Draw 6 Dependencies: Aevent  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      Aeff2D->SetStats(0);
      Aeff2D->SetMarkerStyle(20);
      Aeff2D->SetMarkerSize(0.4);
      Aeff2D->GetYaxis()->SetLabelSize(0.04);
      Aeff2D->SetTitle("all runs & events");
      Aeff2D->SetXTitle("A-sub-detector x800, adcCounts");
      Aeff2D->SetYTitle("N");
      Aeff2D->SetMarkerColor(4);
      Aeff2D->SetLineColor(4);
      //    Aeff2D->Draw("Error");
      //    Aeff2D->Draw("PL");
       Aeff2D->SetMinimum(0.8);
       Aeff2D->Draw("");

      c1->Update();

    }//Method = 6

    //======================================================================================================= PLOT7:  entrtotalzero1  for each event and all runs 
    if(Method == 7) {
      cout<<"****Draw 7 Dependencies: entrtotalzero1  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_entrtotalzero1->SetStats(0);
      h_entrtotalzero1->SetMarkerStyle(20);
      h_entrtotalzero1->SetMarkerSize(0.4);
      h_entrtotalzero1->GetYaxis()->SetLabelSize(0.04);
      h_entrtotalzero1->SetTitle("all runs & events");
      h_entrtotalzero1->SetXTitle("N entries = 0 no HBHEHO digiCollection ");
      h_entrtotalzero1->SetYTitle("N");
      h_entrtotalzero1->SetMarkerColor(4);
      h_entrtotalzero1->SetLineColor(4);
      //    h_entrtotalzero1->Draw("Error");
      //    h_entrtotalzero1->Draw("PL");
       h_entrtotalzero1->SetMinimum(0.8);
       h_entrtotalzero1->Draw("");

      c1->Update();

    }//Method = 7

    //======================================================================================================= PLOT8:  contentofmaxbinnonzero1  for each event and all runs 
    if(Method == 8) {
      cout<<"****Draw 8 Dependencies: contentofmaxbinnonzero1  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_contentofmaxbinnonzero1->SetStats(0);
      h_contentofmaxbinnonzero1->SetMarkerStyle(20);
      h_contentofmaxbinnonzero1->SetMarkerSize(0.4);
      h_contentofmaxbinnonzero1->GetYaxis()->SetLabelSize(0.04);
      h_contentofmaxbinnonzero1->SetTitle("all runs & events");
      h_contentofmaxbinnonzero1->SetXTitle("content of max non-zero bin ");
      h_contentofmaxbinnonzero1->SetYTitle("N");
      h_contentofmaxbinnonzero1->SetMarkerColor(4);
      h_contentofmaxbinnonzero1->SetLineColor(4);
      //    h_contentofmaxbinnonzero1->Draw("Error");
      //    h_contentofmaxbinnonzero1->Draw("PL");
       h_contentofmaxbinnonzero1->SetMinimum(0.8);
       h_contentofmaxbinnonzero1->Draw("");

      c1->Update();

    }//Method = 8

    //======================================================================================================= PLOT9:  maxbinnonzero1  for each event and all runs 
    if(Method == 9) {
      cout<<"****Draw 9 Dependencies: maxbinnonzero1  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_maxbinnonzero1->SetStats(0);
      h_maxbinnonzero1->SetMarkerStyle(20);
      h_maxbinnonzero1->SetMarkerSize(0.4);
      h_maxbinnonzero1->GetYaxis()->SetLabelSize(0.04);
      h_maxbinnonzero1->SetTitle("all runs & events");
      h_maxbinnonzero1->SetXTitle("max non-zero bin ");
      h_maxbinnonzero1->SetYTitle("N");
      h_maxbinnonzero1->SetMarkerColor(4);
      h_maxbinnonzero1->SetLineColor(4);
      //    h_maxbinnonzero1->Draw("Error");
      //    h_maxbinnonzero1->Draw("PL");
       h_maxbinnonzero1->SetMinimum(0.8);
       h_maxbinnonzero1->Draw("");

      c1->Update();

    }//Method = 9

    //======================================================================================================= PLOT10:  Aij  for each event and all runs 
    if(Method == 10) {
      cout<<"****Draw 10 Dependencies: Aij  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      //    	  TString epsName = fname + LEDruns[0] +".root";
      //    	  TFile *hfile= new TFile(epsName, "READ");
      //    	  TH1F * Aeff1D= (TH1F*)hfile->Get("h_ADCAmpl_HB");

      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      Aeff1D->SetStats(0);
      Aeff1D->SetMarkerStyle(20);
      Aeff1D->SetMarkerSize(0.4);
      Aeff1D->GetYaxis()->SetLabelSize(0.04);
      Aeff1D->SetTitle("all runs & events");
      Aeff1D->SetXTitle("Aij x20, adcCounts ");
      Aeff1D->SetYTitle("N");
      Aeff1D->SetMarkerColor(4);
      Aeff1D->SetLineColor(4);
      //    Aeff1D->Draw("Error");
      //    Aeff1D->Draw("PL");
       Aeff1D->SetMinimum(0.8);
       Aeff1D->Draw("");

      c1->Update();

    }//Method = 10
    //======================================================================================================= PLOT11:  entrtotalzero0  for each event and all runs 
    if(Method == 11) {
      cout<<"****Draw 11 Dependencies: entrtotalzero0  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_entrtotalzero0->SetStats(0);
      h_entrtotalzero0->SetMarkerStyle(20);
      h_entrtotalzero0->SetMarkerSize(0.4);
      h_entrtotalzero0->GetYaxis()->SetLabelSize(0.04);
      h_entrtotalzero0->SetTitle("all runs & events");
      h_entrtotalzero0->SetXTitle("N entries = 0 no HBHEHO digiCollection ");
      h_entrtotalzero0->SetYTitle("N");
      h_entrtotalzero0->SetMarkerColor(4);
      h_entrtotalzero0->SetLineColor(4);
      //    h_entrtotalzero0->Draw("Error");
      //    h_entrtotalzero0->Draw("PL");
       h_entrtotalzero0->SetMinimum(0.8);
       h_entrtotalzero0->Draw("");

      c1->Update();

    }//Method = 11

    //======================================================================================================= PLOT12:  contentofmaxbinnonzero0  for each event and all runs 
    if(Method == 12) {
      cout<<"****Draw 12 Dependencies: contentofmaxbinnonzero0  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_contentofmaxbinnonzero0->SetStats(0);
      h_contentofmaxbinnonzero0->SetMarkerStyle(20);
      h_contentofmaxbinnonzero0->SetMarkerSize(0.4);
      h_contentofmaxbinnonzero0->GetYaxis()->SetLabelSize(0.04);
      h_contentofmaxbinnonzero0->SetTitle("all runs & events");
      h_contentofmaxbinnonzero0->SetXTitle("content of max non-zero bin ");
      h_contentofmaxbinnonzero0->SetYTitle("N");
      h_contentofmaxbinnonzero0->SetMarkerColor(4);
      h_contentofmaxbinnonzero0->SetLineColor(4);
      //    h_contentofmaxbinnonzero0->Draw("Error");
      //    h_contentofmaxbinnonzero0->Draw("PL");
       h_contentofmaxbinnonzero0->SetMinimum(0.8);
       h_contentofmaxbinnonzero0->Draw("");

      c1->Update();

    }//Method = 12

    //======================================================================================================= PLOT13:  maxbinnonzero0  for each event and all runs 
    if(Method == 13) {
      cout<<"****Draw 13 Dependencies: maxbinnonzero0  for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      h_maxbinnonzero0->SetStats(0);
      h_maxbinnonzero0->SetMarkerStyle(20);
      h_maxbinnonzero0->SetMarkerSize(0.4);
      h_maxbinnonzero0->GetYaxis()->SetLabelSize(0.04);
      h_maxbinnonzero0->SetTitle("all runs & events");
      h_maxbinnonzero0->SetXTitle("max non-zero bin ");
      h_maxbinnonzero0->SetYTitle("N");
      h_maxbinnonzero0->SetMarkerColor(4);
      h_maxbinnonzero0->SetLineColor(4);
      //    h_maxbinnonzero0->Draw("Error");
      //    h_maxbinnonzero0->Draw("PL");
       h_maxbinnonzero0->SetMinimum(0.8);
       h_maxbinnonzero0->Draw("");

      c1->Update();

    }//Method = 13

    //======================================================================================================= PLOT14:  Aijk for each event and all runs 
    if(Method == 14) {
      cout<<"****Draw 14 Dependencies: Aijk for each event and all runs  *** " <<endl;
      c1->Clear();
      c1->Divide(1,1);
      
      c1->cd(1);
      gPad->SetGridy();
      gPad->SetGridx();
      gPad->SetLogy();
      gStyle->SetOptStat(101110); 
      //      Aeff0D->SetStats(0);
      Aeff0D->SetMarkerStyle(20);
      Aeff0D->SetMarkerSize(0.4);
      Aeff0D->GetYaxis()->SetLabelSize(0.04);
      Aeff0D->SetTitle("all runs & events");
      Aeff0D->SetXTitle("Aijk x50, adcCounts");
      Aeff0D->SetYTitle("N");
      Aeff0D->SetMarkerColor(4);
      Aeff0D->SetLineColor(4);
      //    Aeff0D->Draw("Error");
      //    Aeff0D->Draw("PL");
       Aeff0D->SetMinimum(0.8);
       Aeff0D->Draw("");

      c1->Update();

    }//Method = 14


    //  //////////////////////////////////////////////////////////////////////////



  //======================================================================================================= 
  //======================================================================================================= finish loop over Methods
  //======================================================================================================= 
    TString fdir = "zamt2mixing2018/";
    //
    TString plotName = fdir + MethodName[Method] +".png";
    c1->SaveAs(plotName);
    cout<<"****PLOT "   << Method  <<" drawn **** " <<endl;
    
    }//if( Method != 9 
    ++Method;
  }//while loop over Methods
      cout << "!!!! npedestal= " << npedestal   << "  nsignal= " << nsignal   <<"  total=  " << nsignal+npedestal <<endl;
  cout << "!!!! Rnpedestal= " << npedestal/(nsignal+npedestal)  << "  Rnsignal= " << nsignal/(nsignal+npedestal)   <<endl;

  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //======================================================================================================= 
  //______________________________________________________________________________
  //______________________________________________________________________________
  //  
  //______________________________________________________________________________
  //______________________________________________________________________________
  //  
  gSystem->Exit(0);
  //______________________________________________________________________________
}
//______________________________________________________________________________
