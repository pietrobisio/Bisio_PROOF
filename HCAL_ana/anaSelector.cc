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
   
   h_hit_05=new TH1D("h_hit_05","h_hit_05",500,-0.5,499.5);
   h_hit_1=new TH1D("h_hit_1","h_hit_1",500,-0.5,499.5);
   h_hit_2=new TH1D("h_hit_2","h_hit_2",500,-0.5,499.5);
   h_hit_3=new TH1D("h_hit_3","h_hit_3",500,-0.5,499.5);
   h_hit_4=new TH1D("h_hit_4","h_hit_4",500,-0.5,499.5);

   h2 = new TH2D("h2","h2",50,-0.5,49.5,50,-0.5,49.5);

    
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


  int hitN05 = 0;
  int hitN1 = 0;
  int hitN2 = 0;
  int hitN3 = 0;
  int hitN4 = 0;
    

  for(int j=0;j<(HCAL_EtotB->size()); j++){
    double E_pad=(*HCAL_EtotB)[j];
    //cout<<E_pad<<" "<<(*HCAL_sector)[j]" "<<(*HCAL_t0)[j]<<endl;
   if(((*HCAL_sector)[j]==6) && ((*HCAL_t0)[j]<500) && ((*HCAL_layer)[j]<49)){
     if(E_pad>0.5){hitN05++;}
     if(E_pad>1){hitN1++;}
     if(E_pad>2){hitN2++;}
     if(E_pad>3){hitN3++;}
     if(E_pad>4){hitN4++;}
   }
  }
  
  h_hit_05->Fill(hitN05);
  h_hit_1->Fill(hitN1);
  h_hit_2->Fill(hitN2);
  h_hit_3->Fill(hitN3);
  h_hit_4->Fill(hitN4);

  if(hitN2<4){
    for(int j=0;j<(HCAL_EtotB->size()); j++){
      if(((*HCAL_EtotB)[j]>2) && ((*HCAL_sector)[j]==6) && ((*HCAL_t0)[j]<100)){
	h2->Fill((*HCAL_layer)[j],(*HCAL_channel)[j]);
      }
    }
  }
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

