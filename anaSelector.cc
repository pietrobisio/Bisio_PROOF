#define anaSelector_cxx
// The class definition in anaSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("anaSelector.C")
// root> T->Process("anaSelector.C","some options")
// root> T->Process("anaSelector.C+")
//


#include "anaSelector.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>


double m(double pid){
  
  double mass = 0;
  
  if(pid == 22 || abs(pid) == 12 || abs(pid) == 14) mass = 0; //gamma, nu e, nu mu
  if(abs(pid) == 13) mass = 105.6583745; //muon
  if(abs(pid) == 11) mass = 0.510999 ; //electron
  if(abs(pid) == 211) mass = 139.570; // pion ±
  if(pid == 2112) mass = 939.565; //neutron
  if(pid == 2212) mass = 938.272; //proton
  return mass;
}








void anaSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void anaSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   //Create here histos

   hGen_E=new TH1D("hGen_E","hGen_E",100,0,20);
   
   int bmin = 0;
   int bmax = 11000;
   
   h_miss_A = new TH1D("h_miss_A","h_miss_A",300,bmin,bmax);
   h_miss_C = new TH1D("h_miss_C","h_miss_C",300,bmin,bmax);
   
   /*
   h_piEmax = new TH1D("h_piEmax","h_piEmax",300,bmin,bmax);
   h_muEmax = new TH1D("h_muEmax","h_muEmax",300,bmin,bmax);
   h_eEmax = new TH1D("h_eEmax","h_eEmax",300,bmin,bmax);
   h_gammaEmax = new TH1D("h_gammaEmax","h_gammaEmax",300,bmin,bmax);
   h_nuEmax = new TH1D("h_nuEmax","h_nuEmax",300,bmin,bmax);
   h_NEmax = new TH1D("h_NEmax","h_NEmax",300,bmin,bmax);
   h_PEmax = new TH1D("h_PEmax","h_PEmax",300,bmin,bmax);
  
   h_piN = new TH1D("h_piN","h_piN",300,-0.5,300);
   h_muN = new TH1D("h_muN","h_muN",300,-0.5,300);
   h_eN = new TH1D("h_eN","h_eN",300,-0.5,300);
   h_gammaN = new TH1D("h_gammaN","h_gammaN",300,-0.5,300);
   h_nuN = new TH1D("h_nuN","h_nuN",300,-0.5,300);
   h_NN = new TH1D("h_NN","h_NN",300,-0.5,300);
   h_PN = new TH1D("h_PN","h_PN",300,-0.5,300);*/

   h2_Emiss_Eex = new TH2D("h2_Emiss_Eex","h2_Emiss_Eex",300,bmin,bmax,300,bmin,bmax);
   h2_E_Theta_muon = new TH2D("h2_E_Theta_muon","h2_E_Theta_muon",300,bmin,bmax,200,0,180);
   h2_z_Theta_muon = new TH2D("h2_z_Theta_muon","h2_z_Theta_muon",400,-200,200,200,0,180);
   h2_E_Theta_muon_Max = new TH2D("h2_E_Theta_muon_Max","h2_E_Theta_muon_Max",300,bmin,bmax,200,0,180);


   //With this code, you have all histos to the output automatically.
   Info("SlaveBegin", "AllHistos to fOutput");
   TIter next(gDirectory->GetList());
   TObject *obj;
   while (obj = (TObject*) next()) {
     if (obj->InheritsFrom(TH1::Class())) {
       Info("SlaveBegin", "Obj: %s", obj->GetName());
       fOutput->Add(obj);
     }
   }
   Info("SlaveBegin", "end");
   
}

Bool_t anaSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
  
  this->GetEntry(entry);
  //check if there is a generated (note gen_PID is a pointer to a vector)
  if (gen_pid->size()<1) return kTRUE;
  
  //just fill a histogram (again, gen_pz is a pointer, so to get the vector content, I use (*gen_pz)
  hGen_E->Fill((*gen_pz)[0]/1000.);
  



  double EDEP = 0;
  double Emiss = 0;
  double Emiss_part = 0;
  
  for(int j=0;j<(totEdep->size()); j++){
    EDEP =  EDEP +  (*totEdep)[j];
  }
  Emiss = sqrt(((*gen_pz)[0])*(*gen_pz)[0] + 0.510999*0.510999) - EDEP;
  h_miss_A->Fill(Emiss);
  

  // High Energy loss Analysis //
  int e_count = 0;
  int mu_count = 0;
  int nu_count = 0;
  int gamma_count =0;
  int pi_count = 0;
  int N_count = 0;
  int P_count = 0;
  int others_count =0;
    
  double Et = 0;
  double Ek =0;
  double Theta  = 0;
  //double pid_Max = 0;
  double E_Max = 0;
  double Theta_Max = 0;

 
  if(Emiss>2000){
    Emiss_part = 0;
    h_miss_C->Fill(Emiss);
    
    for(int i=0; i<(pid->size()); i++){
      //flux particle parameters:
      int ID = (*id)[i];
      double fpx = (*px)[i];
      double fpy = (*py)[i];
      double fpz = (*pz)[i];
      // double fx = (*avg_x)[i];
      //double fy = (*avg_y)[i];
      double fz = (*avg_z)[i];
      int pID = (*pid)[i];

  	  
      //check if particle is exiting the detector //	  
      int check_ext =0 ;
      if(ID==101 && fpz<0) check_ext =1; // front
      if(ID==102 && fpy>0) check_ext =1; // top
      if(ID==103 && fpx>0) check_ext =1; // left
      if(ID==104 && fpx<0) check_ext =1; // right
      if(ID==105 && fpy<0) check_ext =1; // bottom
      if(ID==106 && fpz>0) check_ext =1; // back	  
      
      if(check_ext==1){
	Et = sqrt( fpx*fpx + fpy*fpy + fpz*fpz + m(pID)*m(pID));
	Ek = Et - m(pID); 
	Theta  = 180./3.1416*acos(fpz/sqrt(fpx*fpx + fpy*fpy + fpz*fpz));
	
	if(abs(pID) == 11) { e_count++; }
	if(abs(pID) == 22) { gamma_count++; }
	if(abs(pID) == 211){ pi_count++; }
	if(pID == 2112) { N_count++; }
	if(pID == 2212) { P_count++; }
	if(abs(pID) == 13) { 
	  mu_count++;
	  h2_E_Theta_muon -> Fill(Et,Theta);
	  h2_z_Theta_muon -> Fill(fz,Theta);
	  
	  if(Et > E_Max){ //searching max energy exiting muon
	    E_Max = Et;
	    Theta_Max = Theta; 
	  }
	}
	if(abs(pID) == 14 || abs(pID) == 12)  { nu_count++; }
	if(abs(pID)!=11 && abs(pID)!=12  && abs(pID)!=13  && abs(pID)!=14  && abs(pID)!=22 && abs(pID)!=211 && pID!=2112 && pID!=2212){
	  others_count++;
	  cout << "New exiting particle: " << pID << endl;
	}

	Emiss_part = Emiss_part + Ek;
      }//chiusura if particella uscente
    }//chiusura loop su hit nel flux
    
    h2_E_Theta_muon_Max -> Fill(E_Max,Theta_Max);
    h2_Emiss_Eex->Fill(Emiss,Emiss_part);
   
    //cout<<mu_count<<endl;
    // h_eN -> Fill(e_count);
    //h_eN -> Fill(10);
    //h_muN -> Fill(13);
    //h_nuN -> Fill(nu_count);
    //h_gammaN -> Fill(gamma_count);
    //h_piN -> Fill(12);
    //h_NN -> Fill(N_count);
    //h_PN -> Fill(P_count);
    
  }//chiusura loop su eventi selezionati

  
  

  return kTRUE;
}

void anaSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
  hGen_E->Scale(1./m_EOT);
}

void anaSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  Info("Terminate", "Terminate starts. EOT are: %f", m_EOT);

  //A.C. you can also normalize here if you want
  
 

}


void anaSelector::setEOT(double n) {
	m_EOT = n;
}





