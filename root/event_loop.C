#include <iostream>
#include <ctime>
#include <stdint.h>

#include "TFile.h"
#include "TTree.h"

using namespace std;

// Event weight
struct EventWeight {
	float MC;
	float PU;
};

// Information about the events
struct EventInfo {
	int64_t EvtNum;
	int32_t RunNum;
	int32_t Dsid;
};

// Truth particle definition
struct ParticleTruth {
	float Pt;
	float Pl;
	float Eta;
	float Phi;
	float M;
	int32_t Pid;
};

// Event
struct Event {
	EventInfo Info;
	EventWeight EvtWgt;
	ParticleTruth Top;
	ParticleTruth AntiTop;
	ParticleTruth Bottom;
	ParticleTruth AntiBottom;
	ParticleTruth Wplus;
	ParticleTruth Wminus;
	ParticleTruth Lepton;
	ParticleTruth AntiLepton;
	ParticleTruth Neutrino;
	ParticleTruth AntiNeutrino;
};




void event_loop(TString fname="/home/rmadar/cernbox/ATLAS/Analysis/SM-SpinCorr/data/inputs/root-files/MC16a.410472.PhPy8EG.DAOD_TOPQ1_truth.root",
		TString tname="truth"){

  clock_t start = clock();

  // Input file/Trees
  TFile *fin = TFile::Open(fname);
  TTree *tin = (TTree*) fin->Get(tname);
  tin->SetBranchStatus("*", 0);

  Event evt;
  tin->SetBranchAddress("eventNumber", &evt.Info.EvtNum);
  tin->SetBranchAddress("runNumber", &evt.Info.RunNum);
  tin->SetBranchAddress("mcChannelNumber", &evt.Info.Dsid);
  tin->SetBranchAddress("weight_mc", &evt.EvtWgt.MC);
  tin->SetBranchAddress("weight_pileup", &evt.EvtWgt.PU);
  tin->SetBranchAddress("d_t_beforeFSR_pt", &evt.Top.Pt);
  tin->SetBranchAddress("d_t_beforeFSR_eta", &evt.Top.Eta);
  tin->SetBranchAddress("d_t_beforeFSR_phi", &evt.Top.Phi);
  tin->SetBranchAddress("d_t_beforeFSR_m", &evt.Top.M);
  tin->SetBranchAddress("d_tbar_beforeFSR_pt", &evt.AntiTop.Pt);
  tin->SetBranchAddress("d_tbar_beforeFSR_eta", &evt.AntiTop.Eta);
  tin->SetBranchAddress("d_tbar_beforeFSR_phi", &evt.AntiTop.Phi);
  tin->SetBranchAddress("d_tbar_beforeFSR_m", &evt.AntiTop.M);
  tin->SetBranchAddress("d_b_pt",  &evt.Bottom.Pt);
  tin->SetBranchAddress("d_b_eta", &evt.Bottom.Eta);
  tin->SetBranchAddress("d_b_phi", &evt.Bottom.Phi);
  tin->SetBranchAddress("d_b_m",   &evt.Bottom.M);
  tin->SetBranchAddress("d_bbar_pt",  &evt.AntiBottom.Pt);
  tin->SetBranchAddress("d_bbar_eta", &evt.AntiBottom.Eta);
  tin->SetBranchAddress("d_bbar_phi", &evt.AntiBottom.Phi);
  tin->SetBranchAddress("d_bbar_m",   &evt.AntiBottom.M);
  tin->SetBranchAddress("d_wplus_pt",  &evt.Wplus.Pt);
  tin->SetBranchAddress("d_wplus_eta", &evt.Wplus.Eta);
  tin->SetBranchAddress("d_wplus_phi", &evt.Wplus.Phi);
  tin->SetBranchAddress("d_wplus_m",   &evt.Wplus.M);
  tin->SetBranchAddress("d_wminus_pt",  &evt.Wminus.Pt);
  tin->SetBranchAddress("d_wminus_eta", &evt.Wminus.Eta);
  tin->SetBranchAddress("d_wminus_phi", &evt.Wminus.Phi);
  tin->SetBranchAddress("d_wminus_m",   &evt.Wminus.M);
  tin->SetBranchAddress("d_l_pt",  &evt.Lepton.Pt);
  tin->SetBranchAddress("d_l_eta", &evt.Lepton.Eta);
  tin->SetBranchAddress("d_l_phi", &evt.Lepton.Phi);
  tin->SetBranchAddress("d_lbar_pt",  &evt.AntiLepton.Pt);
  tin->SetBranchAddress("d_lbar_eta", &evt.AntiLepton.Eta);
  tin->SetBranchAddress("d_lbar_phi", &evt.AntiLepton.Phi);
  tin->SetBranchAddress("d_nu_pt",  &evt.Neutrino.Pt);
  tin->SetBranchAddress("d_nu_eta", &evt.Neutrino.Eta);
  tin->SetBranchAddress("d_nu_phi", &evt.Neutrino.Phi);
  tin->SetBranchAddress("d_nu_m",   &evt.Neutrino.M);
  tin->SetBranchAddress("d_nubar_pt",  &evt.AntiNeutrino.Pt);
  tin->SetBranchAddress("d_nubar_eta", &evt.AntiNeutrino.Eta);
  tin->SetBranchAddress("d_nubar_phi", &evt.AntiNeutrino.Phi);
  tin->SetBranchAddress("d_nubar_m",   &evt.AntiNeutrino.M);
    
  int Nentries = tin->GetEntries();
  for (int i=0; i<Nentries; i++){
    
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
  cout << Nentries/1000. << " kEvts)" << endl;
  
}
