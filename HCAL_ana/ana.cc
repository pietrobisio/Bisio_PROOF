#include <iostream>
#include <fstream>
#include "TChain.h"
#include "TApplication.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TCanvas.h"
#include "TProof.h"

#include "anaSelector.h"

using namespace std;

int nproof,nEOT;
bool showGUI = false;

string ofname;
string fileName;
vector<string> fileNames;

TApplication gui("gui", 0, NULL);


void parseCommandLine(int argc, char **argv) {

	nproof = 0;
	ofname = "";

	for (int ii = 0; ii < argc; ii++) {
		string command = string(argv[ii]);
		if (command == "-o") {
			ofname = string(argv[ii + 1]);
			cout << "out fname is: " << ofname << endl;
		} else if (command == "-nproof") {
			nproof = atoi(argv[ii + 1]);
		} else if (command == "-f") {
			int jj = 0;
			while (1) {
				fileName = string(argv[ii + jj + 1]);
				jj++;
				if (fileName[0] == '-') break;
				if ((ii + jj + 1) == argc) break;
				fileNames.push_back(fileName);
			}
		} else if (command == "-GUI") showGUI = true;
	}
}

int main(int argc, char **argv) {

	if (argc == 1) {
		cout << "-o ofname" << endl;
		cout << "-f name of file (can be more than one, -f file1 file2 file3)" << endl;
		cout << "-nproof N of proof nodes" << endl;
		cout << "-GUI show gui at end" << endl;
		exit(0);
	}

	parseCommandLine(argc, argv);
	anaSelector *myAnaSelector = new anaSelector();

	TChain *anaChain = new TChain("header");
	TChain *anaChain_generated = new TChain("generated");
	TChain *anaChain_flux = new TChain("flux");	
	TChain *anaChain_JPOS_crs = new TChain("JPOS_crs");

	int nFiles;
	vector<string> good_fileNames;

	/*Determine the ACTUAL number of EOTs from the data itself*/
	double nEOT = 0;
	vector<double> *runNo=0;
	vector<double> *evn=0;
	for (int ii=0;ii<fileNames.size();ii++){
	  TFile *f=new TFile(fileNames[ii].c_str());
	  TTree *t=(TTree*)f->Get("header");
	  t->SetBranchAddress("runNo",&runNo);
	  t->SetBranchAddress("evn",&evn);
	  t->GetEntry(t->GetEntries()-1); //get LAST event

	  if ((*runNo)[0]==0){ //runNo == 0 tags that the last event is a SPECIAL one containing the number of simulated entries
	    nEOT += (*evn)[0];
	    good_fileNames.push_back(fileNames[ii]);
	  } else{
	    cout<<fileNames[ii]<<" IS BAD, ignore "<<endl;
	  }
	  f->Close();
	  delete f;

	}


	/*Here add files*/
	for (int ii = 0; ii < good_fileNames.size(); ii++) {
	  anaChain->          Add(good_fileNames[ii].c_str());
	  anaChain_generated->Add(good_fileNames[ii].c_str());
	  anaChain_flux->     Add(good_fileNames[ii].c_str());
	  anaChain_JPOS_crs-> Add(good_fileNames[ii].c_str());
	}
	anaChain->AddFriend(anaChain_generated);
	anaChain->AddFriend(anaChain_flux);
	anaChain->AddFriend(anaChain_JPOS_crs);
	

	
	nFiles = anaChain->GetListOfFiles()->GetEntries();
	cout << "N files are: " << nFiles << endl;
	cout << "N positrons are: "<<nEOT << endl;

	if (nproof != 0) {
		cout << "USING PROOF WITH " << nproof << " WORKERS! " << endl;
		TProof *proof = TProof::Open(Form("workers=%i,", nproof));
		proof->Exec("gSystem->Load(\"libRooFit.so\")");
		proof->Exec("gSystem->Load(\"/project/Gruppo3/fiber7/pbisio/gemc2_6/Bisio_PROOF/HCAL_ana/libanaSelector.so\")");
		proof->SetParameter("PROOF_Packetizer", "TPacketizer");
		anaChain->SetProof(1);
	}
	//myFlukaSelector->setEOT(nEOTxfileFluka * nFlukaFiles);
	myAnaSelector->setEOT(nEOT);
	//anaChain->Process(myAnaSelector,"stf");
	anaChain->Process(myAnaSelector);

       
	/*Save if requested*/
	if (ofname.length() != 0) {
		TFile *fout = new TFile(ofname.c_str(), "RECREATE");
		fout->cd();


		TListIter iter1(myAnaSelector->GetOutputList());
		TObject *obj1;

		while (obj1 = iter1.Next()) {
			if (obj1->InheritsFrom(TH1::Class())) obj1->Write();
			if (obj1->InheritsFrom(TTree::Class())) obj1->Write();
		}

		

		fout->Write();
		fout->Close();

	}

	if (showGUI) {
		gui.Run(1);
	}

}
