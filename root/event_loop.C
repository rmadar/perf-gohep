#include <iostream>
#include <ctime>

#include "TFile.h"
#include "TTree.h"

using namespace std;

void event_loop(TString fname="/home/rmadar/cernbox/ATLAS/Analysis/SM-SpinCorr/data/inputs/root-files/MC16a.410472.PhPy8EG.DAOD_TOPQ1_truth.root",
		TString tname="truth"){

  clock_t start = clock();

  // Input file/Trees
  TFile *fin = TFile::Open(fname);
  TTree *tin = (TTree*) fin->Get(tname);
  tin->SetBranchStatus("*", 0);

  tin->SetBranchStatus("eventNumber", 1);
  tin->SetBranchStatus("runNumber", 1); 
  tin->SetBranchStatus("mcChannelNumber", 1); 
  
  // Weights informations
  tin->SetBranchStatus("weight_mc", 1); 
  tin->SetBranchStatus("weight_pileup", 1); 
  
  // Top/Anti-top quark
  tin->SetBranchStatus("d_t_beforeFSR_pt", 1); 
  tin->SetBranchStatus("d_t_beforeFSR_eta", 1); 
  tin->SetBranchStatus("d_t_beforeFSR_phi", 1); 
  tin->SetBranchStatus("d_t_beforeFSR_m", 1); 
  tin->SetBranchStatus("d_tbar_beforeFSR_pt", 1); 
  tin->SetBranchStatus("d_tbar_beforeFSR_eta", 1); 
  tin->SetBranchStatus("d_tbar_beforeFSR_phi", 1); 
  tin->SetBranchStatus("d_tbar_beforeFSR_m", 1); 
  
  // b-quarks
  tin->SetBranchStatus("d_b_pt", 1); 
  tin->SetBranchStatus("d_b_eta", 1); 
  tin->SetBranchStatus("d_b_phi", 1); 
  tin->SetBranchStatus("d_b_m", 1); 
  tin->SetBranchStatus("d_bbar_pt", 1); 
  tin->SetBranchStatus("d_bbar_eta", 1); 
  tin->SetBranchStatus("d_bbar_phi", 1); 
  tin->SetBranchStatus("d_bbar_m", 1); 
  
  // W-bosons
  tin->SetBranchStatus("d_wplus_pt", 1); 
  tin->SetBranchStatus("d_wplus_eta", 1); 
  tin->SetBranchStatus("d_wplus_phi", 1); 
  tin->SetBranchStatus("d_wplus_m", 1); 
  tin->SetBranchStatus("d_wminus_pt", 1); 
  tin->SetBranchStatus("d_wminus_eta", 1); 
  tin->SetBranchStatus("d_wminus_phi", 1); 
  tin->SetBranchStatus("d_wminus_m", 1); 
  
  // Leptons/Anti-lepton
  tin->SetBranchStatus("d_l_pt", 1); 
  tin->SetBranchStatus("d_l_eta", 1); 
  tin->SetBranchStatus("d_l_phi", 1); 
  tin->SetBranchStatus("d_lbar_pt", 1); 
  tin->SetBranchStatus("d_lbar_eta", 1); 
  tin->SetBranchStatus("d_lbar_phi", 1); 
  
  // Neutrinos/Anti-neutrino
  tin->SetBranchStatus("d_nu_pt", 1); 
  tin->SetBranchStatus("d_nu_eta", 1); 
  tin->SetBranchStatus("d_nu_phi", 1); 
  tin->SetBranchStatus("d_nu_m", 1); 
  tin->SetBranchStatus("d_nubar_pt", 1); 
  tin->SetBranchStatus("d_nubar_eta", 1); 
  tin->SetBranchStatus("d_nubar_phi", 1); 
  tin->SetBranchStatus("d_nubar_m", 1);
    
  int Nentries = tin->GetEntries();
  for (int i=0; i<Nentries ; i++){
    
    // Load the event
    tin->GetEntry(i);

    // Print
    if (i%100000==0) {
      cout << "Processing event " << i << endl;
    }
  }
  
  clock_t stop = clock();
  double dt = double(stop - start) / CLOCKS_PER_SEC;
  cout.precision(2);
  cout << dt*1000/(Nentries/1000.)  <<  " ms/kEvt (" << dt << " s for ";
  cout.precision(3);
  cout << Nentries/1000. << "kEvts)" << endl;
  
}
