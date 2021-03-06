//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar  2 11:30:54 2021 by ROOT version 6.20/04
// from TTree header/Data Header Bank
// found on file: out.root
//////////////////////////////////////////////////////////

#ifndef anaSelector_h
#define anaSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

#include <TH1D.h>
#include <TH2D.h>

// Headers needed by this particular selector
#include <string>
#include <vector>

using namespace std;

class anaSelector : public TSelector {
public :
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

  //header
  vector<double> *runNo;
  vector<double> *evn;
  vector<double> *evn_type;


  //generated
  vector<int> *gen_pid;
  vector<double> *gen_px;
  vector<double> *gen_py;
  vector<double> *gen_pz;

  vector<double> *gen_vx;
  vector<double> *gen_vy;
  vector<double> *gen_vz;

  //flux//
  vector<double> *id; 
  vector<double> *pid; 
  vector<double> *mpid;
  vector<double> *trackE;  
  vector<double> *avg_x;
  vector<double> *avg_y;
  vector<double> *avg_z;
  vector<double> *px;
  vector<double> *py;
  vector<double> *pz;
  vector<double> *vx;
  vector<double> *vy;
  vector<double> *vz;
  vector<double> *avg_t;
  vector<double> *nsteps;
  vector<double> *procID;

  //JPOS_crs//
  vector<double> *totEdep;
 


  //histos
  TH1D *hGen_E;

  TH1D *h_miss_A;
  TH1D *h_miss_C;
  TH1D *h_miss_T;
  TH1D *h_miss_NO_mu;
  TH1D *h_miss_EM;
  
  TH1D *h_mp;

  TH1D *h_eN;
  TH1D *h_muN;
  TH1D *h_nuN;
  TH1D *h_gammaN;
  TH1D *h_piN;
  TH1D *h_pi0N;  
  TH1D *h_NN;
  TH1D *h_aNN;
  TH1D *h_PN;
  TH1D *h_aPN;
  TH1D *h_OC;
  TH1D *h_kN;
  TH1D *h_k0lN;
  TH1D *h_k0sN;
  TH1D *h_lambdaN;
  TH1D *h_xiN;
  TH1D *h_xi0N;
  TH1D *h_sigma_mN;
  TH1D *h_sigma_pN;  
  TH1D *h_nuclN;
  
  TH1D *h_eME;
  TH1D *h_muME;
  TH1D *h_nuME;
  TH1D *h_gammaME;
  TH1D *h_piME;
  TH1D *h_pi0ME;  
  TH1D *h_NME;
  TH1D *h_aNME;
  TH1D *h_PME;
  TH1D *h_aPME;
  TH1D *h_kME;
  TH1D *h_k0lME;
  TH1D *h_k0sME;
  TH1D *h_lambdaME;
  TH1D *h_xiME;
  TH1D *h_xi0ME;
  TH1D *h_sigma_mME;
  TH1D *h_sigma_pME;
  TH1D *h_nuclME;

  TH1D *h_e_allE;
  TH1D *h_mu_allE;
  TH1D *h_nu_allE;
  TH1D *h_gamma_allE;
  TH1D *h_pi_allE;
  TH1D *h_pi0_allE;  
  TH1D *h_N_allE;
  TH1D *h_aN_allE;
  TH1D *h_P_allE;
  TH1D *h_aP_allE;
  TH1D *h_k_allE;
  TH1D *h_k0l_allE;
  TH1D *h_k0s_allE;
  TH1D *h_lambda_allE;
  TH1D *h_xi_allE;
  TH1D *h_xi0_allE;
  TH1D *h_sigma_m_allE;
  TH1D *h_sigma_p_allE;
  TH1D *h_nucl_allE;

  TH2D *h2_E_Theta_e_Max;
  TH2D *h2_E_Theta_mu_Max;
  TH2D *h2_E_Theta_nu_Max;
  TH2D *h2_E_Theta_gamma_Max;
  TH2D *h2_E_Theta_pi_Max;
  TH2D *h2_E_Theta_pi0_Max;  
  TH2D *h2_E_Theta_N_Max;
  TH2D *h2_E_Theta_aN_Max;
  TH2D *h2_E_Theta_P_Max;
  TH2D *h2_E_Theta_aP_Max;
  TH2D *h2_E_Theta_k_Max;
  TH2D *h2_E_Theta_k0l_Max;
  TH2D *h2_E_Theta_k0s_Max;
  TH2D *h2_E_Theta_lambda_Max;
  TH2D *h2_E_Theta_xi_Max;
  TH2D *h2_E_Theta_xi0_Max;
  TH2D *h2_E_Theta_sigma_m_Max;
  TH2D *h2_E_Theta_sigma_p_Max;
  TH2D *h2_E_Theta_nucl_Max;
  
  TH2D *h2_E_z_muon_Max;
  TH2D *h2_z_Theta_muon_Max;
  TH2D *h2_E_Theta_muon;
  TH2D *h2_ExitingP;
  
  TH2D *h2_E_Theta_mu_Max_Exit12;
  TH2D *h2_E_Theta_mu_Max_Exit34;
  TH2D *h2_E_Theta_mu_Max_Exit56;
  TH2D *h2_E_Theta_mu_Max_ExitM;

  TH2D *h2_Emiss_Eex;
  TH2D *h2_Emiss_E_tot_Max; 

  TH2D *h2_Emiss_E_e_Max;
  TH2D *h2_Emiss_E_muon_Max;
  TH2D *h2_Emiss_E_nu_Max;
  TH2D *h2_Emiss_E_gamma_Max;
  TH2D *h2_Emiss_E_pi_Max;
  TH2D *h2_Emiss_Ek_N_Max;
  TH2D *h2_Emiss_Ek_P_Max;
  TH2D *h2_Emiss_E_k_Max; 
  TH2D *h2_Emiss_E_k0_Max; 
  TH2D *h2_Emiss_Ek_HB_Max; 


  TH1D *h_dist;

 
  double m_EOT;

  TTree *Tout;
  int t_runNo, t_evn;
  string t_string;

  anaSelector(TTree * /*tree*/ =0) { 
 
    //INIT TO ZERO ALL POINTERS
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

    //histos
    hGen_E=0;
    
    h_miss_A=0;
    h_miss_C=0;
    h_miss_T=0;
    h_miss_NO_mu=0;
    h_miss_EM=0;
  
    h_mp=0;
   
    h_eN=0;
    h_muN=0;
    h_nuN=0;
    h_gammaN=0;
    h_piN=0;
    h_pi0N=0;  
    h_NN=0;
    h_aNN=0;
    h_PN=0;
    h_aPN=0;
    h_OC=0;
    h_kN=0;
    h_k0lN=0;
    h_k0sN=0;
    h_lambdaN=0;
    h_xiN=0;
    h_xi0N=0;
    h_sigma_mN=0;
    h_sigma_pN=0;
    h_nuclN=0;

    h_eME=0;
    h_muME=0;
    h_nuME=0;
    h_gammaME=0;
    h_piME=0;
    h_pi0ME=0;  
    h_NME=0;
    h_aNME=0;
    h_PME=0;
    h_aPME=0;
    h_kME=0;
    h_k0lME=0;
    h_k0sME=0;
    h_lambdaME=0;
    h_xiME=0;
    h_xi0ME=0;
    h_sigma_mME=0;
    h_sigma_pME=0;
    h_nuclME=0;

    h_e_allE=0;
    h_mu_allE=0;
    h_nu_allE=0;
    h_gamma_allE=0;
    h_pi_allE=0;
    h_pi0_allE=0;  
    h_N_allE=0;
    h_aN_allE=0;
    h_P_allE=0;
    h_aP_allE=0;
    h_k_allE=0;
    h_k0l_allE=0;
    h_k0s_allE=0;
    h_lambda_allE=0;
    h_xi_allE=0;
    h_xi0_allE=0;
    h_sigma_m_allE=0;
    h_sigma_p_allE=0;
    h_nucl_allE=0;
    
    h2_E_Theta_e_Max=0;
    h2_E_Theta_mu_Max=0;
    h2_E_Theta_nu_Max=0;
    h2_E_Theta_gamma_Max=0;
    h2_E_Theta_pi_Max=0;
    h2_E_Theta_pi0_Max=0;  
    h2_E_Theta_N_Max=0;
    h2_E_Theta_aN_Max=0;
    h2_E_Theta_P_Max=0;
    h2_E_Theta_aP_Max=0;
    h2_E_Theta_k_Max=0;
    h2_E_Theta_k0l_Max=0;
    h2_E_Theta_k0s_Max=0;
    h2_E_Theta_lambda_Max=0;
    h2_E_Theta_xi_Max=0;
    h2_E_Theta_xi0_Max=0;
    h2_E_Theta_sigma_m_Max=0;
    h2_E_Theta_sigma_p_Max=0;
    h2_E_Theta_nucl_Max=0;
    
    h2_E_z_muon_Max=0;
    h2_z_Theta_muon_Max=0;
    h2_E_Theta_muon=0;
    h2_ExitingP=0;
    
    h2_E_Theta_mu_Max_Exit12=0;
    h2_E_Theta_mu_Max_Exit34=0;
    h2_E_Theta_mu_Max_Exit56=0;
    h2_E_Theta_mu_Max_ExitM=0;

    h2_Emiss_Eex=0;
    h2_Emiss_E_tot_Max=0;
   
    h2_Emiss_E_e_Max=0;
    h2_Emiss_E_muon_Max=0;
    h2_Emiss_E_nu_Max=0;
    h2_Emiss_E_gamma_Max=0;
    h2_Emiss_E_pi_Max=0;
    h2_Emiss_Ek_N_Max=0;
    h2_Emiss_Ek_P_Max=0;
    h2_Emiss_E_k_Max=0; 
    h2_Emiss_E_k0_Max=0; 
    h2_Emiss_Ek_HB_Max=0; 
     
    
    
    h_dist=0;
     

    Tout=0;

  }
   virtual ~anaSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   void setEOT(double n);
   void clear_vector();
   ClassDef(anaSelector,1);

};

#endif

#ifdef anaSelector_cxx
void anaSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

  //Set branch addresses. For friends, use friend_name.branch_name  
  fChain=tree;
  fChain->SetBranchStatus("*",0);
  
  //fChain->SetBranchStatus("time",0);
  //fChain->SetBranchStatus("user",0);
  
  fChain->SetBranchStatus("runNo",1);
  fChain->SetBranchAddress("runNo",&runNo);
  fChain->SetBranchStatus("evn",1);
  fChain->SetBranchAddress("evn",&evn);
  fChain->SetBranchStatus("evn_type",1);
  fChain->SetBranchAddress("evn_type",&evn_type);

  
  fChain->SetBranchStatus("generated.pid",1);
  fChain->SetBranchStatus("generated.px",1);
  fChain->SetBranchStatus("generated.py",1);
  fChain->SetBranchStatus("generated.pz",1);
  fChain->SetBranchStatus("generated.vx",1);
  fChain->SetBranchStatus("generated.vy",1);
  fChain->SetBranchStatus("generated.vz",1);

  fChain->SetBranchStatus("flux.id",1); 
  fChain->SetBranchStatus("flux.pid",1); 
  fChain->SetBranchStatus("flux.mpid",1);
  fChain->SetBranchStatus("flux.trackE",1); 
  fChain->SetBranchStatus("flux.avg_x",1);
  fChain->SetBranchStatus("flux.avg_y",1);
  fChain->SetBranchStatus("flux.avg_z",1);
  fChain->SetBranchStatus("flux.px",1);
  fChain->SetBranchStatus("flux.py",1);
  fChain->SetBranchStatus("flux.pz",1);
  fChain->SetBranchStatus("flux.vx",1);
  fChain->SetBranchStatus("flux.vy",1);
  fChain->SetBranchStatus("flux.vz",1);
  fChain->SetBranchStatus("flux.avg_t",1);
  fChain->SetBranchStatus("flux.nsteps",1);
  fChain->SetBranchStatus("flux.procID",1);
  
  fChain->SetBranchStatus("JPOS_crs.totEdep",1);
  
  
  fChain->SetBranchAddress("generated.pid",&gen_pid);
  fChain->SetBranchAddress("generated.px",&gen_px);
  fChain->SetBranchAddress("generated.py",&gen_py);
  fChain->SetBranchAddress("generated.pz",&gen_pz);
  fChain->SetBranchAddress("generated.vx",&gen_vx);
  fChain->SetBranchAddress("generated.vy",&gen_vy);
  fChain->SetBranchAddress("generated.vz",&gen_vz);

  fChain->SetBranchAddress("flux.id",&id); 
  fChain->SetBranchAddress("flux.pid",&pid); 
  fChain->SetBranchAddress("flux.mpid",&mpid);
  fChain->SetBranchAddress("flux.trackE",&trackE); 
  fChain->SetBranchAddress("flux.avg_x",&avg_x);
  fChain->SetBranchAddress("flux.avg_y",&avg_y);
  fChain->SetBranchAddress("flux.avg_z",&avg_z);
  fChain->SetBranchAddress("flux.px",&px);
  fChain->SetBranchAddress("flux.py",&py);
  fChain->SetBranchAddress("flux.pz",&pz);
  fChain->SetBranchAddress("flux.vx",&vx);
  fChain->SetBranchAddress("flux.vy",&vy);
  fChain->SetBranchAddress("flux.vz",&vz);
  fChain->SetBranchAddress("flux.avg_t",&avg_t);
  fChain->SetBranchAddress("flux.nsteps",&nsteps);
  fChain->SetBranchAddress("flux.procID",&procID);

  fChain->SetBranchAddress("JPOS_crs.totEdep",&totEdep);

}

Bool_t anaSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef anaSelector_cxx
