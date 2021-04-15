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
  if(pid == 22 || abs(pid) == 12 || abs(pid) == 14){mass = 0;} //gamma, nu e, nu mu
  else if(abs(pid) == 13){mass = 105.6583745;} //muon
  else if(abs(pid) == 11){mass = 0.510999;} //electron
  else if(abs(pid) == 211){mass = 139.570;} // pion ±
  else if(abs(pid) == 2112){mass = 939.565;} //neutron
  else if(abs(pid) == 2212){mass = 938.272;} //proton
  return mass;
}


void find_Max_mu(double &EM, double E, double &TM, double T, double &zM, double z,int &IDM, int ID){
  if (E>EM){
    EM=E;
    TM=T;
    zM=z;
    IDM=ID;
  }  
}

void find_Max_tot(double &EM, double E, double &TM, double T, int &pIDM, int pID){
  if (E>EM){
    EM=E;
    TM=T;
    pIDM=pID;
  }  
}

void find_Max(double &EM, double E, double &TM, double T){
  if (E>EM){
    EM=E;
    TM=T;
  }  
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
   
   h_miss_A = new TH1D("h_miss_A","h_miss_A",1100,0,11000);
   h_miss_C = new TH1D("h_miss_C","h_miss_C",1100,0,11000);
   h_miss_T = new TH1D("h_miss_T","h_miss_T",1000,0,1000);
   h_miss_NO_mu = new TH1D("h_miss_NO_mu","h_miss_NO_mu",1100,0,11000);
   h_miss_EM = new TH1D("h_miss_EM","h_miss_EM",1100,0,11000);
   
   h_mp = new TH1D("h_mp","h_mp",5000,-0.5,4999.5); 
  
   h_eN = new TH1D("h_eN","h_eN",100,-0.5,99.5);
   h_muN = new TH1D("h_muN","h_muN",50,-0.5,49.5);
   h_nuN = new TH1D("h_nuN","h_nuN",50,-0.5,49.5);
   h_gammaN = new TH1D("h_gammaN","h_gammaN",500,-0.5,499.5);
   h_piN = new TH1D("h_piN","h_piN",50,-0.5,49.5); 
   h_pi0N = new TH1D("h_pi0N","h_pi0N",50,-0.5,49.5); 
   h_NN = new TH1D("h_NN","h_NN",300,-0.5,299.5);
   h_aNN = new TH1D("h_aNN","h_aNN",50,-0.5,49.5);
   h_PN = new TH1D("h_PN","h_PN",50,-0.5,49.5);
   h_aPN = new TH1D("h_aPN","h_aPN",50,-0.5,49.5);
   h_OC = new TH1D("h_OC","h_OC",300,-0.5,299.5);
   h_kN = new TH1D("h_kN","h_kN",50,-0.5,49.5);
   h_k0lN = new TH1D("h_k0lN","h_k0lN",50,-0.5,49.5);
   h_k0sN = new TH1D("h_k0sN","h_k0sN",50,-0.5,49.5);
   h_lambdaN= new TH1D("h_lambdaN","h_lambdaN",50,-0.5,49.5);
   h_xiN = new TH1D("h_xiN","h_xiN",50,-0.5,49.5);
   h_xi0N = new TH1D("h_xi0N","h_xi0N",50,-0.5,49.5);
   h_sigma_mN = new TH1D("h_sigma_mN","h_sigma_mN",50,-0.5,49.5);
   h_sigma_pN = new TH1D("h_sigma_pN","h_sigma_pN",50,-0.5,49.5);
   h_nuclN = new TH1D("h_nuclN","h_nuclN",50,-0.5,49.5);

   h_eME = new TH1D("h_eME","h_eME",1100,0,11000);
   h_muME = new TH1D("h_muME","h_muME",1100,0,11000);
   h_nuME = new TH1D("h_nuME","h_nuME",1100,0,11000);
   h_gammaME = new TH1D("h_gammaME","h_gammaME",1100,0,11000);
   h_piME = new TH1D("h_piME","h_piME",1100,0,11000);
   h_pi0ME = new TH1D("h_pi0ME","h_pi0ME",1100,0,11000);
   h_NME = new TH1D("h_NME","h_NME",1100,0,11000);
   h_aNME = new TH1D("h_aNME","h_aNME",1100,0,11000);
   h_PME = new TH1D("h_PME","h_PME",1100,0,11000);
   h_aPME = new TH1D("h_aPME","h_aPME",1100,0,11000);  
   h_kME = new TH1D("h_kME","h_kME",1100,0,11000);
   h_k0lME = new TH1D("h_k0lME","h_k0lME",1100,0,11000);
   h_k0sME = new TH1D("h_k0sME","h_k0sME",1100,0,11000);
   h_lambdaME= new TH1D("h_lambdaME","h_lambdaME",1100,0,11000);
   h_xiME = new TH1D("h_xiME","h_xiME",1100,0,11000);
   h_xi0ME = new TH1D("h_xi0ME","h_xi0ME",1100,0,11000);
   h_sigma_mME = new TH1D("h_sigma_mME","h_sigma_mME",1100,0,11000);
   h_sigma_pME = new TH1D("h_sigma_pME","h_sigma_pME",1100,0,11000);
   h_nuclME = new TH1D("h_nuclME","h_nuclME",1100,0,11000);

   h_e_allE = new TH1D("h_e_allE","h_e_allE",1100,0,11000);
   h_mu_allE = new TH1D("h_mu_allE","h_mu_allE",1100,0,11000);
   h_nu_allE = new TH1D("h_nu_allE","h_nu_allE",1100,0,11000);
   h_gamma_allE = new TH1D("h_gamma_allE","h_gamma_allE",1100,0,11000);
   h_pi_allE = new TH1D("h_pi_allE","h_pi_allE",1100,0,11000);
   h_pi0_allE = new TH1D("h_pi0_allE","h_pi0_allE",1100,0,11000);
   h_N_allE = new TH1D("h_N_allE","h_N_allE",1100,0,11000);
   h_aN_allE = new TH1D("h_aN_allE","h_aN_allE",1100,0,11000);
   h_P_allE = new TH1D("h_P_allE","h_P_allE",1100,0,11000);
   h_aP_allE = new TH1D("h_aP_allE","h_aP_allE",1100,0,11000);  
   h_k_allE = new TH1D("h_k_allE","h_k_allE",1100,0,11000);
   h_k0l_allE = new TH1D("h_k0l_allE","h_k0l_allE",1100,0,11000);
   h_k0s_allE = new TH1D("h_k0s_allE","h_k0s_allE",1100,0,11000);
   h_lambda_allE= new TH1D("h_lambda_allE","h_lambda_allE",1100,0,11000);
   h_xi_allE = new TH1D("h_xi_allE","h_xi_allE",1100,0,11000);
   h_xi0_allE = new TH1D("h_xi0_allE","h_xi0_allE",1100,0,11000);
   h_sigma_m_allE = new TH1D("h_sigma_m_allE","h_sigma_m_allE",1100,0,11000);
   h_sigma_p_allE = new TH1D("h_sigma_p_allE","h_sigma_p_allE",1100,0,11000);
   h_nucl_allE = new TH1D("h_nucl_allE","h_nucl_allE",1100,0,11000);
   
   h2_E_Theta_e_Max = new TH2D("h2_E_Theta_e_Max","h2_E_Theta_e_Max",1100,0,11000,200,0,180);
   h2_E_Theta_mu_Max = new TH2D("h2_E_Theta_mu_Max","h2_E_Theta_mu_Max",1100,0,11000,200,0,180);
   h2_E_Theta_nu_Max = new TH2D("h2_E_Theta_nu_Max","h2_E_Theta_nu_Max",1100,0,11000,200,0,180);
   h2_E_Theta_gamma_Max = new TH2D("h2_E_Theta_gamma_Max","h2_E_Theta_gamma_Max",1100,0,11000,200,0,180);
   h2_E_Theta_pi_Max = new TH2D("h2_E_Theta_pi_Max","h2_E_Theta_pi_Max",1100,0,11000,200,0,180);
   h2_E_Theta_pi0_Max = new TH2D("h2_E_Theta_pi0_Max","h2_E_Theta_pi0_Max",1100,0,11000,200,0,180);
   h2_E_Theta_N_Max = new TH2D("h2_E_Theta_N_Max","h2_E_Theta_N_Max",1100,0,11000,200,0,180);
   h2_E_Theta_aN_Max = new TH2D("h2_E_Theta_aN_Max","h2_E_Theta_aN_Max",1100,0,11000,200,0,180);
   h2_E_Theta_P_Max = new TH2D("h2_E_Theta_P_Max","h2_E_Theta_P_Max",1100,0,11000,200,0,180);
   h2_E_Theta_aP_Max = new TH2D("h2_E_Theta_aP_Max","h2_E_Theta_aP_Max",1100,0,11000,200,0,180);
   h2_E_Theta_k_Max = new TH2D("h2_E_Theta_k_Max","h2_E_Theta_k_Max",1100,0,11000,200,0,180);
   h2_E_Theta_k0l_Max = new TH2D("h2_E_Theta_k0l_Max","h2_E_Theta_k0l_Max",1100,0,11000,200,0,180);
   h2_E_Theta_k0s_Max = new TH2D("h2_E_Theta_k0s_Max","h2_E_Theta_k0s_Max",1100,0,11000,200,0,180);
   h2_E_Theta_lambda_Max= new TH2D("h2_E_Theta_lambda_Max","h2_E_Theta_lambda_Max",1100,0,11000,200,0,180);
   h2_E_Theta_xi_Max = new TH2D("h2_E_Theta_xi_Max","h2_E_Theta_xi_Max",1100,0,11000,200,0,180);
   h2_E_Theta_xi0_Max = new TH2D("h2_E_Theta_xi0_Max","h2_E_Theta_xi0_Max",1100,0,11000,200,0,180);
   h2_E_Theta_sigma_m_Max = new TH2D("h2_E_Theta_sigma_m_Max","h2_E_Theta_sigma_m_Max",1100,0,11000,200,0,180);
   h2_E_Theta_sigma_p_Max = new TH2D("h2_E_Theta_sigma_p_Max","h2_E_Theta_sigma_p_Max",1100,0,11000,200,0,180);
   h2_E_Theta_nucl_Max = new TH2D("h2_E_Theta_nucl_Max","h2_E_Theta_nucl_Max",1100,0,11000,200,0,180);   
   
   //muon histograms
   h2_E_z_muon_Max = new TH2D("h2_E_z_muon_Max","h2_E_z_muon_Max",1100,0,11000,400,-200,200);
   h2_z_Theta_muon_Max = new TH2D("h2_z_Theta_muon_Max","h2_z_Theta_muon_Max",400,-200,200,200,0,180);
   h2_E_Theta_muon = new TH2D("h2_E_Theta_muon","h2_E_Theta_muon",1100,0,11000,200,0,180);
   h2_ExitingP = new TH2D("h2_ExitingP","h2_Soft_mu_ExitingP",100,-0.5,99.5,300,-0.5,299.5);

   h2_E_Theta_mu_Max_Exit12 = new TH2D("h2_E_Theta_mu_Max_Exit12","h2_E_Theta_mu_Max_Exit12",1100,0,11000,200,0,180);
   h2_E_Theta_mu_Max_Exit34 = new TH2D("h2_E_Theta_mu_Max_Exit34","h2_E_Theta_mu_Max_Exit34",1100,0,11000,200,0,180);
   h2_E_Theta_mu_Max_Exit56 = new TH2D("h2_E_Theta_mu_Max_Exit56","h2_E_Theta_mu_Max_Exit56",1100,0,11000,200,0,180);
   h2_E_Theta_mu_Max_ExitM = new TH2D("h2_E_Theta_mu_Max_ExitM","h2_E_Theta_mu_Max_ExitM",1100,0,11000,200,0,180);
      
  
   h2_Emiss_Eex = new TH2D("h2_Emiss_Eex","h2_Emiss_Eex",500,0,11000,500,0,11000);
   h2_Emiss_E_tot_Max = new TH2D("h2_Emiss_E_tot_Max","h2_Emiss_E_tot_Max",500,0,11000,500,0,11000);

   h2_Emiss_E_e_Max = new TH2D("h2_Emiss_E_e_Max","h2_Emiss_E_e_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_muon_Max = new TH2D("h2_Emiss_E_muon_Max","h2_Emiss_E_muon_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_nu_Max = new TH2D("h2_Emiss_E_nu_Max","h2_Emiss_E_nu_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_gamma_Max = new TH2D("h2_Emiss_E_gamma_Max","h2_Emiss_E_gamma_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_pi_Max = new TH2D("h2_Emiss_E_pi_Max","h2_Emiss_E_pi_Max",500,0,11000,500,0,11000);
   h2_Emiss_Ek_N_Max = new TH2D("h2_Emiss_Ek_N_Max","h2_Emiss_Ek_N_Max",500,0,11000,500,0,11000);
   h2_Emiss_Ek_P_Max = new TH2D("h2_Emiss_Ek_P_Max","h2_Emiss_Ek_P_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_k_Max = new TH2D("h2_Emiss_E_k_Max","h2_Emiss_E_k_Max",500,0,11000,500,0,11000);
   h2_Emiss_E_k0_Max = new TH2D("h2_Emiss_E_k0_Max","h2_Emiss_E_k0_Max",500,0,11000,500,0,11000);
   h2_Emiss_Ek_HB_Max = new TH2D("h2_Emiss_Ek_HB_Max","h2_Emiss_Ek_HB_Max",500,0,11000,500,0,11000);

   
   h_dist = new TH1D("h_dist","h_dist",5000,-0.5,4999.5);
   
   
   Tout = new TTree ("Tout","Tout");
   Tout->Branch("runNo",&t_runNo); 
   Tout->Branch("evn",&t_evn); 
   Tout->Branch("string",&t_string); 
   fOutput->Add(Tout);

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
  
  //if(entry%10000==0){
  //  Info("Process","entry number: %i",entry);
  //}
  
  this->GetEntry(entry);
  //check if there is a generated (note gen_PID is a pointer to a vector)
  if (gen_pid->size()<1){
    //this->clear_vector();
    return kTRUE;
  }

  //just fill a histogram (again, gen_pz is a pointer, so to get the vector content, I use (*gen_pz)
  hGen_E->Fill((*gen_pz)[0]/1000.);
   
  t_runNo=(int)((*runNo)[0]);
  t_evn=(int)((*evn)[0]);


  double EDEP = 0;
  double Emiss = 0;
  double Emiss_part = 0;
  
  for(int j=0;j<(totEdep->size()); j++){
    EDEP =  EDEP +  (*totEdep)[j];
  }
  Emiss = sqrt(((*gen_pz)[0])*(*gen_pz)[0] + 0.510999*0.510999) - EDEP;
  h_miss_A->Fill(Emiss);
  

  // High Energy loss Analysis //
  int e_count =0;
  int mu_count =0;
  int nu_count =0;
  int gamma_count =0;
  int pi_count =0;
  int pi0_count =0;
  int N_count =0;
  int aN_count =0;
  int P_count = 0;
  int aP_count = 0;
  int others_count =0;
  int k_count =0;
  int k0l_count =0;
  int k0s_count =0;
  int lambda_count =0;
  int xi_count=0;
  int xi0_count=0;
  int sigma_m_count=0;
  int sigma_p_count=0;
  int nucl_count =0;
  
  double e_meanE = 0;
  double mu_meanE = 0;
  double nu_meanE = 0;
  double gamma_meanE =0;
  double pi_meanE = 0;
  double pi0_meanE = 0;
  double N_meanE = 0;
  double aN_meanE = 0;
  double P_meanE = 0;
  double aP_meanE = 0;
  double k_meanE = 0;
  double k0l_meanE =0;
  double k0s_meanE =0;
  double lambda_meanE =0;
  double xi_meanE =0;
  double xi0_meanE =0;
  double sigma_m_meanE =0;
  double sigma_p_meanE =0;
  double nucl_meanE =0;

  double e_MaxE = 0;
  double mu_MaxE = 0;
  double nu_MaxE = 0;
  double gamma_MaxE =0;
  double pi_MaxE = 0;
  double pi0_MaxE = 0;
  double N_MaxE = 0;
  double aN_MaxE = 0;
  double P_MaxE = 0;
  double aP_MaxE = 0;
  double k_MaxE = 0;
  double k0l_MaxE = 0;
  double k0s_MaxE = 0;
  double lambda_MaxE =0;
  double xi_MaxE =0;
  double xi0_MaxE =0;
  double sigma_m_MaxE =0;
  double sigma_p_MaxE =0;
  double nucl_MaxE =0;

  double e_MaxT = 0;
  double mu_MaxT = 0;
  double nu_MaxT = 0;
  double gamma_MaxT =0;
  double pi_MaxT = 0;
  double pi0_MaxT = 0;
  double N_MaxT = 0;
  double aN_MaxT = 0;
  double P_MaxT = 0;
  double aP_MaxT = 0;
  double k_MaxT = 0;
  double k0l_MaxT = 0;
  double k0s_MaxT = 0;
  double lambda_MaxT =0;
  double xi_MaxT =0;
  double xi0_MaxT =0;
  double sigma_m_MaxT=0;
  double sigma_p_MaxT=0;
  double nucl_MaxT =0;
  
  double tot_MaxE =0;
  double tot_MaxT =0;
  int tot_MaxpID =0;
  //double tot_MaxZ =0;

  double mu_MaxZ =0;
  int mu_MaxID;

  
  if(Emiss>6000){
    h_miss_C->Fill(Emiss);
  
    for(int i=0; i<(pid->size()); i++){
      //flux particle parameters:
      int ID = (*id)[i];
      double Et = (*trackE)[i];
      double fpx = (*px)[i];
      double fpy = (*py)[i];
      double fpz = (*pz)[i];
      //double fx = (*avg_x)[i];
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
	
	double mp = sqrt(abs(Et*Et-(fpx*fpx+fpy*fpy+fpz*fpz)));
	
	if((Et*Et-(fpx*fpx+fpy*fpy+fpz*fpz)<-0.0001)||(isnan(mp)==1)){
	  t_string=string(Form("Mass ERROR!!!"));
	  Tout->Fill();
	}
	h_mp->Fill(mp);
	
	double Ek = Et - mp;
	double Theta  = 180./3.1416*acos(fpz/sqrt(fpx*fpx+fpy*fpy+fpz*fpz));

	if(abs(pID) == 11){ 
	  e_count++; 
	  e_meanE += Et;
	  find_Max(e_MaxE,Et,e_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_e_allE->Fill(Et);
	}
	else if(pID == 22){
	  gamma_count++;
	  gamma_meanE += Et;
	  find_Max(gamma_MaxE,Et,gamma_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID); 
	  h_gamma_allE->Fill(Et);
	}	
	else if(abs(pID) == 211){ 
	  pi_count++; 
	  pi_meanE += Et;
	  find_Max(pi_MaxE,Et,pi_MaxT,Theta);
	  Emiss_part += Et;	 
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_pi_allE->Fill(Et);
	}
	else if(abs(pID) == 111){ 
	  pi0_count++; 
	  pi0_meanE += Et;
	  find_Max(pi0_MaxE,Et,pi0_MaxT,Theta);
	  Emiss_part += Et;	  
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_pi0_allE->Fill(Et);
	}
       	else if(pID == 2112){ 
	  N_count++;
	  N_meanE += Et;
	  find_Max(N_MaxE,Et,N_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_N_allE->Fill(Et);
	}
	else if(pID == -2112){ 
	  aN_count++;
	  aN_meanE += Et;
	  find_Max(aN_MaxE,Et,aN_MaxT,Theta);
	  Emiss_part += Et;	  
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_aN_allE->Fill(Et);
	}
	else if(pID == 2212){ 
	  P_count++; 
	  P_meanE += Et;
	  find_Max(P_MaxE,Et,P_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_P_allE->Fill(Et);
	}
	else if(pID == -2212){ 
	  aP_count++; 
	  aP_meanE += Et;
	  find_Max(aP_MaxE,Et,aP_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_aP_allE->Fill(Et);
	}	
	else if(abs(pID) == 13){ 
	  mu_count++;
	  mu_meanE += Et;
	  find_Max_mu(mu_MaxE,Et,mu_MaxT,Theta,mu_MaxZ,fz,mu_MaxID,ID);
	  //h2_E_Theta_muon -> Fill(Et,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_mu_allE->Fill(Et);
	}	
	else if(pID == 130){ 
	  k0l_count++; 
	  k0l_meanE += Et;	  
	  find_Max(k0l_MaxE,Et,k0l_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_k0l_allE->Fill(Et);
	}	
	else if(pID == 310){ 
	  k0s_count++; 
	  k0s_meanE += Et;	  
	  find_Max(k0s_MaxE,Et,k0s_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_k0s_allE->Fill(Et);
	}	
	else if(abs(pID) == 321){ 
	  k_count++; 
	  k_meanE += Et;	  
	  find_Max(k_MaxE,Et,k_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_k_allE->Fill(Et);
	}	
	else if(abs(pID) == 14 || abs(pID) == 12){ 
	  nu_count++; 
	  nu_meanE += Et;	  
	  find_Max(nu_MaxE,Et,nu_MaxT,Theta);
	  Emiss_part += Et;
	  find_Max_tot(tot_MaxE,Et,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_nu_allE->Fill(Et);
	}	
	else if(abs(pID) == 3122){ 
	  lambda_count++; 
	  lambda_meanE += Et;	  
	  find_Max(lambda_MaxE,Et,lambda_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	}
	else if(abs(pID) == 3312){ 
	  xi_count++; 
	  xi_meanE += Et;	  
	  find_Max(xi_MaxE,Et,xi_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_xi_allE->Fill(Et);
	}
	else if(abs(pID) == 3322){ 
	  xi0_count++; 
	  xi0_meanE += Et;	  
	  find_Max(xi0_MaxE,Et,xi0_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_xi0_allE->Fill(Et);
	}
	else if(abs(pID) == 3112){ 
	  sigma_m_count++; 
	  sigma_m_meanE += Et;	  
	  find_Max(sigma_m_MaxE,Et,sigma_m_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_sigma_m_allE->Fill(Et);
	}
	else if(abs(pID) == 3222){ 
	  sigma_p_count++; 
	  sigma_p_meanE += Et;	  
	  find_Max(sigma_p_MaxE,Et,sigma_p_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_sigma_p_allE->Fill(Et);
	}
	else if((pID == 1000010020)||(pID == 1000010030)||(pID == 1000020030)||(pID == 1000020040)){ 
	  nucl_count++; 
	  nucl_meanE += Ek;	  
	  find_Max(nucl_MaxE,Ek,nucl_MaxT,Theta);
	  Emiss_part += Ek;
	  find_Max_tot(tot_MaxE,Ek,tot_MaxT,Theta,tot_MaxpID,pID);
	  h_nucl_allE->Fill(Et);
	}
	else {
	  others_count++;
	  t_string=string(Form("PID=%i, mp= %f, E_m=%f",pID,mp,Emiss));
	  Tout->Fill();
	}
       	
	//Emiss_part = Emiss_part + Ek;
	
	if((Ek>1000)&&(Theta>90)){
	  t_string=string(Form("Backward particle E_m=%f, E_k=%f, theta=%f, PID=%i ,flux =%i",Emiss,Ek,Theta,pID,ID));
	  Tout->Fill();
	  h_dist->Fill(-5.0/tan(Theta/180*3.1416));
	}

      }//end if function for exiting particles 
      else if((check_ext==0)&&(abs(pID) == 14 || abs(pID) == 12)){ //entering nu are subtracted 
	nu_count--;
      }
    }//end of internal loop 
    
    
    //Check missing energy vs exiting energy
    h2_Emiss_Eex->Fill(Emiss,Emiss_part);

    //Missig energy VS Most Energetic exiting particle
    h2_Emiss_E_tot_Max->Fill(Emiss,tot_MaxE);
    if((Emiss-tot_MaxE)/sqrt(2)>4500){
      t_string=string(Form("High diagonal distance: E_m=%f MaxE=%f MaxID=%i",Emiss,tot_MaxE,tot_MaxpID));
      Tout->Fill();
    }

    if(abs(tot_MaxpID) == 11){
      h2_Emiss_E_e_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 13){
      h2_Emiss_E_muon_Max->Fill(Emiss,tot_MaxE);
    }
    else if((abs(tot_MaxpID)==12)||(abs(tot_MaxpID)==14)){
      h2_Emiss_E_nu_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 22){
      h2_Emiss_E_gamma_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 211){
      h2_Emiss_E_pi_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 2112){
      h2_Emiss_Ek_N_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 2212){
      h2_Emiss_Ek_P_Max->Fill(Emiss,tot_MaxE);
    }
    else if(abs(tot_MaxpID) == 321){
      h2_Emiss_E_k_Max->Fill(Emiss,tot_MaxE);
    }
    else if((abs(tot_MaxpID) == 130)||(abs(tot_MaxpID) == 310)){
      h2_Emiss_E_k0_Max->Fill(Emiss,tot_MaxE);
    }
    else if((abs(tot_MaxpID) == 3122)||(abs(tot_MaxpID) == 3112)||(tot_MaxpID == 1000010020)){
      h2_Emiss_Ek_HB_Max->Fill(Emiss,tot_MaxE);
    }   
    else{
      t_string=string(Form("Unknown max: %i",tot_MaxpID));
      Tout->Fill();
    }
      


    h_eN -> Fill(e_count);
    h_muN -> Fill(mu_count);
    h_nuN -> Fill(nu_count);
    h_gammaN -> Fill(gamma_count);
    h_piN -> Fill(pi_count);
    h_pi0N -> Fill(pi0_count);
    h_NN -> Fill(N_count);
    h_aNN -> Fill(aN_count);
    h_PN -> Fill(P_count);
    h_aPN -> Fill(aP_count);
    h_OC -> Fill(others_count);
    h_kN -> Fill(k_count);
    h_k0lN -> Fill(k0l_count);
    h_k0sN -> Fill(k0s_count);
    h_lambdaN -> Fill(lambda_count);
    h_xiN -> Fill(xi_count);
    h_xi0N -> Fill(xi0_count);
    h_sigma_mN -> Fill(sigma_m_count);
    h_sigma_pN -> Fill(sigma_p_count);
    h_nuclN -> Fill(nucl_count);

    //lot of exiting particle
    if(nu_count>12){ //7 in pure-EM simulations
      t_string=string(Form("lot of neutrinos %i",nu_count));
      Tout->Fill();
    }
    //odd exiting neutrinos used in pure-EM simulations
    /*if(nu_count%2!=0){
      t_string=string(Form("odd neutrinos %i",nu_count));
      Tout->Fill();
      }*/
    if(gamma_count>200){
      t_string=string(Form("lot of gammas %i",gamma_count));
      Tout->Fill();
    }
    if(e_count>20){
      t_string=string(Form("lot of electron %i",e_count));
      Tout->Fill();
    }
    
    
  
    double thresh = 0;
    
    if((e_count>0)&&(e_MaxE >thresh)){
      h_eME -> Fill(e_meanE/e_count);
      h2_E_Theta_e_Max->Fill(e_MaxE,e_MaxT);
    }
    if((mu_count>0)&&(mu_MaxE >thresh)){
      h_muME -> Fill(mu_meanE/mu_count);
      h2_E_Theta_mu_Max->Fill(mu_MaxE,mu_MaxT);
      /*if(mu_MaxID!=106){
      h2_E_z_muon_Max -> Fill(mu_MaxE,mu_MaxZ);
      h2_z_Theta_muon_Max -> Fill(mu_MaxZ,mu_MaxT);
      }*/
    }
    if((nu_count>0)&&(nu_MaxE >thresh)){
      h_nuME -> Fill(nu_meanE/nu_count);
      h2_E_Theta_nu_Max->Fill(nu_MaxE,nu_MaxT);
    }
    if((gamma_count>0)&&(gamma_MaxE >thresh)){
      h_gammaME -> Fill(gamma_meanE/gamma_count);	 
      h2_E_Theta_gamma_Max->Fill(gamma_MaxE,gamma_MaxT); 
    }
    if((pi_count>0)&&(pi_MaxE >thresh)){
      h_piME -> Fill(pi_meanE/pi_count);
      h2_E_Theta_pi_Max->Fill(pi_MaxE,pi_MaxT);
    }
    if((pi0_count>0)&&(pi0_MaxE >thresh)){
      h_pi0ME -> Fill(pi0_meanE/pi0_count);
      h2_E_Theta_pi0_Max->Fill(pi0_MaxE,pi0_MaxT);
    }
    if((N_count>0)&&(N_MaxE >thresh)){
      h_NME -> Fill(N_meanE/N_count);
      h2_E_Theta_N_Max->Fill(N_MaxE,N_MaxT);
    }
    if((aN_count>0)&&(aN_MaxE >thresh)){
      h_aNME -> Fill(aN_meanE/aN_count);
      h2_E_Theta_aN_Max->Fill(aN_MaxE,aN_MaxT);
    }
    if((P_count>0)&&(P_MaxE >thresh)){
      h_PME -> Fill(P_meanE/P_count);	 
      h2_E_Theta_P_Max->Fill(P_MaxE,P_MaxT); 
    }
    if((aP_count>0)&&(aP_MaxE >thresh)){
      h_aPME -> Fill(aP_meanE/aP_count);	 
      h2_E_Theta_aP_Max->Fill(aP_MaxE,aP_MaxT); 
    }
    if((k_count>0)&&(k_MaxE >thresh)){
      h_kME -> Fill(k_meanE/k_count);	 
      h2_E_Theta_k_Max->Fill(k_MaxE,k_MaxT); 
    }
    if((k0l_count>0)&&(k0l_MaxE >thresh)){
      h_k0lME -> Fill(k0l_meanE/k0l_count);	 
      h2_E_Theta_k0l_Max->Fill(k0l_MaxE,k0l_MaxT); 
    }
    if((k0s_count>0)&&(k0s_MaxE >thresh)){
      h_k0sME -> Fill(k0s_meanE/k0s_count);	 
      h2_E_Theta_k0s_Max->Fill(k0s_MaxE,k0s_MaxT); 
    }
    if((lambda_count>0)&&(lambda_MaxE >thresh)){
      h_lambdaME -> Fill(lambda_meanE/lambda_count);	 
      h2_E_Theta_lambda_Max->Fill(lambda_MaxE,lambda_MaxT); 
    }
    if((xi_count>0)&&(xi_MaxE >thresh)){
      h_xiME -> Fill(xi_meanE/xi_count);	 
      h2_E_Theta_xi_Max->Fill(xi_MaxE,xi_MaxT); 
    }
    if((xi0_count>0)&&(xi0_MaxE >thresh)){
      h_xi0ME -> Fill(xi0_meanE/xi0_count);	 
      h2_E_Theta_xi0_Max->Fill(xi0_MaxE,xi0_MaxT); 
    }
    if((sigma_m_count>0)&&(sigma_m_MaxE >thresh)){
      h_sigma_mME -> Fill(sigma_m_meanE/sigma_m_count);	 
      h2_E_Theta_sigma_m_Max->Fill(sigma_m_MaxE,sigma_m_MaxT); 
    } 
    if((sigma_p_count>0)&&(sigma_p_MaxE >thresh)){
      h_sigma_pME -> Fill(sigma_p_meanE/sigma_p_count);	 
      h2_E_Theta_sigma_p_Max->Fill(sigma_p_MaxE,sigma_p_MaxT); 
    } 
    if((nucl_count>0)&&(nucl_MaxE >thresh)){
      h_nuclME -> Fill(nucl_meanE/nucl_count);	 
      h2_E_Theta_nucl_Max->Fill(nucl_MaxE,nucl_MaxT); 
    }
   
          
    //muon analysis
    if(mu_count>0){
      if(mu_MaxE<1000){ //soft muon analysis
	h2_ExitingP->Fill(11.0,e_count);
	h2_ExitingP->Fill(12.0,nu_count);
	h2_ExitingP->Fill(14.0,mu_count);
	h2_ExitingP->Fill(22.0,gamma_count);
      }
      if((mu_count==1)||(mu_count==2)){h2_E_Theta_mu_Max_Exit12->Fill(mu_MaxE,mu_MaxT);}
      else if((mu_count==3)||(mu_count==4)){h2_E_Theta_mu_Max_Exit34->Fill(mu_MaxE,mu_MaxT);}
      else if((mu_count==5)||(mu_count==6)){h2_E_Theta_mu_Max_Exit56->Fill(mu_MaxE,mu_MaxT);}
      else{
	t_string=string(Form("lot of muons %i",mu_count));
	h2_E_Theta_mu_Max_ExitM->Fill(mu_MaxE,mu_MaxT);
      }
    } 
    
    
    /*if((mu_count==0)){ //0 exiting muon Emiss spectrum 
      h_miss_NO_mu->Fill(Emiss);
      if(nu_count==0){ //pure EM Emiss spectrum 
	h_miss_EM->Fill(Emiss);
	t_string=string(Form("pure EM, E_m=%f, theta_gamma_max=%f, theta_e_max=%f",Emiss,gamma_MaxT,e_MaxT));
	Tout->Fill();
      }
      else{
	t_string=string(Form("0 mu, missing E=%f",Emiss));
	Tout->Fill();
      }
      }*/

    
    //0 muon decay & low deposited energy == used only in total-spectrum analysis
    /*if((nu_count==0) && (Emiss<410)){
      h_miss_T->Fill(Emiss);
      t_string=string(Form("Low missing E=%f",Emiss));
      Tout->Fill();
      }*/
    
  }//end if function on deposited energy 

 
 
  
  
  //this->clear_vector();
  return kTRUE;
}

void anaSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
  
  //double bias = 1E4;
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

void anaSelector::clear_vector() {
  
  delete runNo;
  delete evn;
  delete evn_type;
  //generated
  delete gen_pid;
  delete gen_px;
  delete gen_py;
  delete gen_pz;
  delete gen_vx;
  delete gen_vy;
  delete gen_vz;
  //flux//
  delete id; 
  delete pid; 
  delete mpid;
  delete trackE;  
  delete avg_x;
  delete avg_y;
  delete avg_z;
  delete px;
  delete py;
  delete pz;
  delete vx;
  delete vy;
  delete vz;
  delete avg_t;
  delete nsteps;
  delete procID;
  //JPOS_crs//
  delete totEdep;

  runNo=0;
  evn=0;
  evn_type=0;
  
  gen_pid=0;
  gen_px=0;
  gen_py=0;
  gen_pz=0;
  gen_vx=0;
  gen_vy=0;
  gen_vz=0;
  
  id=0; 
  pid=0; 
  mpid=0;
  trackE=0;  
  avg_x=0;
  avg_y=0;
  avg_z=0;
  px=0;
  py=0;
  pz=0;
  vx=0;
  vy=0;
  vz=0;
  avg_t=0;
  nsteps=0;
  procID=0;
  
  totEdep=0;
}









