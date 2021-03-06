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
#include <TH3D.h>

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
 
  //JPOS_HCAL
  vector<double> *HCAL_sector; //dovrebbero essere int, se li uso come tali non funziona
  vector<double> *HCAL_layer;
  vector<double> *HCAL_channel;
  vector<double> *HCAL_t0;
  vector<double> *HCAL_Etot;
  vector<double> *HCAL_EtotB;
  vector<double> *HCAL_hit_pos;


  //histos
  TH1D *hGen_E;
  
  TH1D *h_hit_05;
  TH1D *h_hit_1;
  TH1D *h_hit_2;
  TH1D *h_hit_3;
  TH1D *h_hit_4;

  TH2D *h2;
  
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

    HCAL_sector=0;
    HCAL_layer=0;
    HCAL_channel=0;
    HCAL_t0=0;
    HCAL_Etot=0;
    HCAL_EtotB=0;
    HCAL_hit_pos=0;

    
    //histos
    hGen_E=0;
    
    h_hit_05=0;
    h_hit_1=0;
    h_hit_2=0;
    h_hit_3=0;
    h_hit_4=0;
    
    h2=0;

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

  fChain->SetBranchStatus("JPOS_HCAL.sector",1);
  fChain->SetBranchStatus("JPOS_HCAL.layer",1);
  fChain->SetBranchStatus("JPOS_HCAL.channel",1);
  fChain->SetBranchStatus("JPOS_HCAL.t0",1);
  fChain->SetBranchStatus("JPOS_HCAL.Etot",1);
  fChain->SetBranchStatus("JPOS_HCAL.EtotB",1);
  fChain->SetBranchStatus("JPOS_HCAL.hit_pos",1);

   
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

  fChain->SetBranchAddress("JPOS_HCAL.sector",&HCAL_sector);
  fChain->SetBranchAddress("JPOS_HCAL.layer",&HCAL_layer);
  fChain->SetBranchAddress("JPOS_HCAL.channel",&HCAL_channel);
  fChain->SetBranchAddress("JPOS_HCAL.t0",&HCAL_t0);
  fChain->SetBranchAddress("JPOS_HCAL.Etot",&HCAL_Etot);
  fChain->SetBranchAddress("JPOS_HCAL.EtotB",&HCAL_EtotB);
  fChain->SetBranchAddress("JPOS_HCAL.hit_pos",&HCAL_hit_pos);



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
