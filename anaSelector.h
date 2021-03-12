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
  
  TH1D *h_piN;
  TH1D *h_muN;
  TH1D *h_eN;
  TH1D *h_gammaN;
  TH1D *h_nuN;
  TH1D *h_NN;
  TH1D *h_PN;

  TH1D *h_piME;
  TH1D *h_muME;
  TH1D *h_eME;
  TH1D *h_gammaME;
  TH1D *h_nuME;
  TH1D *h_NME;
  TH1D *h_PME;
  
  TH2D *h2_E_Theta_pi_Max;
  TH2D *h2_E_Theta_mu_Max;
  TH2D *h2_E_Theta_e_Max;
  TH2D *h2_E_Theta_gamma_Max;
  TH2D *h2_E_Theta_nu_Max;
  TH2D *h2_E_Theta_N_Max;
  TH2D *h2_E_Theta_P_Max; 
  
  TH2D *h2_Emiss_Eex;
  TH2D *h2_E_Theta_muon;
  TH2D *h2_z_Theta_muon;
  TH2D *h2_ExitingP;
  
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
   
    h_piN=0;
    h_muN=0;
    h_eN=0;
    h_gammaN=0;
    h_nuN=0;
    h_NN=0;
    h_PN=0;
    
    h_piME=0;
    h_muME=0;
    h_eME=0;
    h_gammaME=0;
    h_nuME=0;
    h_NME=0;
    h_PME=0;

    h2_E_Theta_pi_Max=0;
    h2_E_Theta_mu_Max=0;
    h2_E_Theta_e_Max=0;
    h2_E_Theta_gamma_Max=0;
    h2_E_Theta_nu_Max=0;
    h2_E_Theta_N_Max=0;
    h2_E_Theta_P_Max=0; 

    h2_Emiss_Eex=0;
    h2_E_Theta_muon=0;
    h2_z_Theta_muon=0;
    h2_ExitingP=0;

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

  fChain->SetBranchAddress("runNo",&runNo);
  fChain->SetBranchAddress("evn",&evn);
  fChain->SetBranchAddress("evn_type",&evn_type);

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
