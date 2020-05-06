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

    double x1(0), x2(0), x3(0);
    for (unsigned i=0 ; i<Var1.size() ; i++) {
      x1 += Var1[i] + Var2[i] + Var3[i] + Var4[i] + Var5[i] + Var6[i] + Var7[i] + Var8[i] + Var9[i] + Var10[i]; 
      x2 += Var11[i] + Var12[i] + Var13[i] + Var14[i] + Var15[i] + Var16[i] + Var17[i] + Var18[i] + Var19[i] + Var20[i]; 
      x3 += Var21[i] + Var22[i] + Var23[i] + Var24[i] + Var25[i] + Var26[i] + Var27[i] + Var28[i] + Var29[i] + Var30[i]; 
    }
        
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

void branch_f64(TString fname="../data.root") {

  clock_t start = clock();

  // Input file/Trees
  TFile *fin = TFile::Open(fname);
  TTree *tin = (TTree*) fin->Get("F64");
  tin->SetBranchStatus("N", 0);

  Double_t Var1, Var2, Var3, Var4, Var5, Var6, Var7, Var8, Var9, Var10;
  Double_t Var11, Var12, Var13, Var14, Var15, Var16, Var17, Var18, Var19, Var20;
  Double_t Var21, Var22, Var23, Var24, Var25, Var26, Var27, Var28, Var29, Var30;
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

    double x1 = Var1 + Var2 + Var3 + Var4 + Var5 + Var6 + Var7 + Var8 + Var9 + Var10; 
    double x2 = Var11 + Var12 + Var13 + Var14 + Var15 + Var16 + Var17 + Var18 + Var19 + Var20; 
    double x3 = Var21 + Var22 + Var23 + Var24 + Var25 + Var26 + Var27 + Var28 + Var29 + Var30; 
    
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

  int iEvt(0);
  while (reader.Next()) {

    double x1(0), x2(0), x3(0);
    for (unsigned i=0 ; i<Var1.GetSize() ; i++) {
      x1 += Var1[i] + Var2[i] + Var3[i] + Var4[i] + Var5[i] + Var6[i] + Var7[i] + Var8[i] + Var9[i] + Var10[i]; 
      x2 += Var11[i] + Var12[i] + Var13[i] + Var14[i] + Var15[i] + Var16[i] + Var17[i] + Var18[i] + Var19[i] + Var20[i]; 
      x3 += Var21[i] + Var22[i] + Var23[i] + Var24[i] + Var25[i] + Var26[i] + Var27[i] + Var28[i] + Var29[i] + Var30[i]; 
    }
    
    if (iEvt%100000==0) {
      cout << "Processing event " << iEvt << endl;
    }
    iEvt++;
  }
  
  clock_t stop = clock();
  Double_t dt = Double_t(stop - start) / CLOCKS_PER_SEC;
  cout.precision(2);
  cout << dt*1000/(iEvt/1000.)  <<  " ms/kEvt (" << dt << " s for ";
  cout.precision(3);
  cout << iEvt/1000. << " kEvts)" << endl;
  
}


void reader_f64(TString fname="../data.root") {

  clock_t start = clock();

  // Reader
  TTreeReader reader("F64", TFile::Open(fname));
  TTreeReaderValue<Double_t> Var1(reader, "Var1");
  TTreeReaderValue<Double_t> Var2(reader, "Var2");
  TTreeReaderValue<Double_t> Var3(reader, "Var3");
  TTreeReaderValue<Double_t> Var4(reader, "Var4");
  TTreeReaderValue<Double_t> Var5(reader, "Var5");
  TTreeReaderValue<Double_t> Var6(reader, "Var6");
  TTreeReaderValue<Double_t> Var7(reader, "Var7");
  TTreeReaderValue<Double_t> Var8(reader, "Var8");
  TTreeReaderValue<Double_t> Var9(reader, "Var9");
  TTreeReaderValue<Double_t> Var10(reader, "Var10");
  TTreeReaderValue<Double_t> Var11(reader, "Var1");
  TTreeReaderValue<Double_t> Var12(reader, "Var2");
  TTreeReaderValue<Double_t> Var13(reader, "Var3");
  TTreeReaderValue<Double_t> Var14(reader, "Var4");
  TTreeReaderValue<Double_t> Var15(reader, "Var5");
  TTreeReaderValue<Double_t> Var16(reader, "Var6");
  TTreeReaderValue<Double_t> Var17(reader, "Var7");
  TTreeReaderValue<Double_t> Var18(reader, "Var8");
  TTreeReaderValue<Double_t> Var19(reader, "Var9");
  TTreeReaderValue<Double_t> Var20(reader, "Var10");
  TTreeReaderValue<Double_t> Var21(reader, "Var1");
  TTreeReaderValue<Double_t> Var22(reader, "Var2");
  TTreeReaderValue<Double_t> Var23(reader, "Var3");
  TTreeReaderValue<Double_t> Var24(reader, "Var4");
  TTreeReaderValue<Double_t> Var25(reader, "Var5");
  TTreeReaderValue<Double_t> Var26(reader, "Var6");
  TTreeReaderValue<Double_t> Var27(reader, "Var7");
  TTreeReaderValue<Double_t> Var28(reader, "Var8");
  TTreeReaderValue<Double_t> Var29(reader, "Var9");
  TTreeReaderValue<Double_t> Var30(reader, "Var10");

  int i(0);
  while (reader.Next()) {

    double x1 = *Var1 + *Var2 + *Var3 + *Var4 + *Var5 + *Var6 + *Var7 + *Var8 + *Var9 + *Var10; 
    double x2 = *Var11 + *Var12 + *Var13 + *Var14 + *Var15 + *Var16 + *Var17 + *Var18 + *Var19 + *Var20; 
    double x3 = *Var21 + *Var22 + *Var23 + *Var24 + *Var25 + *Var26 + *Var27 + *Var28 + *Var29 + *Var30; 
    
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
