#include <iostream>
#include <vector>
#include <ctime>
#include <stdint.h>

#include "TFile.h"
#include "TString.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

using namespace std;

void branch_f64s(TString fname="../data.root") {

  clock_t start = clock();

  // Input file/Trees
  TFile *fin = TFile::Open(fname);
  TTree *tin = (TTree*) fin->Get("F64s");
  tin->SetBranchStatus("N", 0);

  vector<Double_t> Var1, Var2, Var3, Var4, Var5, Var6, Var7, Var8, Var9, Var10;
  vector<Double_t> Var11, Var12, Var13, Var14, Var15, Var16, Var17, Var18, Var19, Var20;
  vector<Double_t> Var21, Var22, Var23, Var24, Var25, Var26, Var27, Var28, Var29, Var30;
  tin->Branch("Var1", &Var1);
  tin->Branch("Var2", &Var2);
  tin->Branch("Var3", &Var3);
  tin->Branch("Var4", &Var4);
  tin->Branch("Var5", &Var5);
  tin->Branch("Var6", &Var6);
  tin->Branch("Var7", &Var7);
  tin->Branch("Var8", &Var8);
  tin->Branch("Var9", &Var9);
  tin->Branch("Var10", &Var10);
  tin->Branch("Var11", &Var11);
  tin->Branch("Var12", &Var12);
  tin->Branch("Var13", &Var13);
  tin->Branch("Var14", &Var14);
  tin->Branch("Var15", &Var15);
  tin->Branch("Var16", &Var16);
  tin->Branch("Var17", &Var17);
  tin->Branch("Var18", &Var18);
  tin->Branch("Var19", &Var19);
  tin->Branch("Var20", &Var20);
  tin->Branch("Var21", &Var21);
  tin->Branch("Var22", &Var22);
  tin->Branch("Var23", &Var23);
  tin->Branch("Var24", &Var24);
  tin->Branch("Var25", &Var25);
  tin->Branch("Var26", &Var26);
  tin->Branch("Var27", &Var27);
  tin->Branch("Var28", &Var28);
  tin->Branch("Var29", &Var29);
  tin->Branch("Var30", &Var30);

  int Nentries = tin->GetEntries();
  for (int i=0; i<Nentries; i++){

    // Load the event
    tin->GetEntry(i);

    double x1 = Var1[0] + Var2[0] + Var3[0] + Var4[0] + Var5[0] + Var6[0] + Var7[0] + Var8[0] + Var9[0] + Var10[0]; 
    double x2 = Var11[0] + Var12[0] + Var13[0] + Var14[0] + Var15[0] + Var16[0] + Var17[0] + Var18[0] + Var19[0] + Var20[0]; 
    double x3 = Var21[0] + Var22[0] + Var23[0] + Var24[0] + Var25[0] + Var26[0] + Var27[0] + Var28[0] + Var29[0] + Var30[0]; 
    
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



void reader_f64s(TString fname="../data.root") {

  clock_t start = clock();

  // Reader
  TTreeReader reader("F64s", TFile::Open(fname));
  TTreeReaderArray<Double_t> Var1(reader, "Var1");
  TTreeReaderArray<Double_t> Var2(reader, "Var2");
  TTreeReaderArray<Double_t> Var3(reader, "Var3");
  TTreeReaderArray<Double_t> Var4(reader, "Var4");
  TTreeReaderArray<Double_t> Var5(reader, "Var5");
  TTreeReaderArray<Double_t> Var6(reader, "Var6");
  TTreeReaderArray<Double_t> Var7(reader, "Var7");
  TTreeReaderArray<Double_t> Var8(reader, "Var8");
  TTreeReaderArray<Double_t> Var9(reader, "Var9");
  TTreeReaderArray<Double_t> Var10(reader, "Var10");
  TTreeReaderArray<Double_t> Var11(reader, "Var1");
  TTreeReaderArray<Double_t> Var12(reader, "Var2");
  TTreeReaderArray<Double_t> Var13(reader, "Var3");
  TTreeReaderArray<Double_t> Var14(reader, "Var4");
  TTreeReaderArray<Double_t> Var15(reader, "Var5");
  TTreeReaderArray<Double_t> Var16(reader, "Var6");
  TTreeReaderArray<Double_t> Var17(reader, "Var7");
  TTreeReaderArray<Double_t> Var18(reader, "Var8");
  TTreeReaderArray<Double_t> Var19(reader, "Var9");
  TTreeReaderArray<Double_t> Var20(reader, "Var10");
  TTreeReaderArray<Double_t> Var21(reader, "Var1");
  TTreeReaderArray<Double_t> Var22(reader, "Var2");
  TTreeReaderArray<Double_t> Var23(reader, "Var3");
  TTreeReaderArray<Double_t> Var24(reader, "Var4");
  TTreeReaderArray<Double_t> Var25(reader, "Var5");
  TTreeReaderArray<Double_t> Var26(reader, "Var6");
  TTreeReaderArray<Double_t> Var27(reader, "Var7");
  TTreeReaderArray<Double_t> Var28(reader, "Var8");
  TTreeReaderArray<Double_t> Var29(reader, "Var9");
  TTreeReaderArray<Double_t> Var30(reader, "Var10");

  int i(0);
  while (reader.Next()) {

    double x1 = Var1[0] + Var2[0] + Var3[0] + Var4[0] + Var5[0] + Var6[0] + Var7[0] + Var8[0] + Var9[0] + Var10[0]; 
    double x2 = Var11[0] + Var12[0] + Var13[0] + Var14[0] + Var15[0] + Var16[0] + Var17[0] + Var18[0] + Var19[0] + Var20[0]; 
    double x3 = Var21[0] + Var22[0] + Var23[0] + Var24[0] + Var25[0] + Var26[0] + Var27[0] + Var28[0] + Var29[0] + Var30[0]; 
    
    if (i%100000==0) {
      cout << "Processing event " << i << endl;
    }
    i++;
  }
  
  clock_t stop = clock();
  Double_t dt = Double_t(stop - start) / CLOCKS_PER_SEC;
  cout.precision(2);
  cout << dt*1000/(i/1000.)  <<  " ms/kEvt (" << dt << " s for ";
  cout.precision(3);
  cout << i/1000. << " kEvts)" << endl;
  
}
