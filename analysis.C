#include <iostream>
//#include <string>
#include <vector>
#include "TString.h"
#include "TFile.h"
#include "TLatex.h"
#include <stdio.h>
#include "TTree.h"
#include "TCut.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TBrowser.h"
#include "TClassTable.h"
#include "TSystem.h"
#include "TROOT.h"
#include "ROOT/RDataFrame.hxx"
#include "TMath.h"

void analysis() {

Double_t E,px,py,pz;
Char_t particle[15];

//create tree file

TFile *t = TFile::Open("tree.root", "RECREATE");

TTree *tree = new TTree("t", "table with data from g4");

tree->Branch("Particle", &particle, "Particle/C");
tree->Branch("E", &E, "E/D");
tree->Branch("px", &px, "px/D");
tree->Branch("py", &py, "py/D");
tree->Branch("pz", &pz, "pz/D");
//Mudar para data.csv
FILE *f = fopen("1000gev.txt", "r");
char line[300];

while(fgets(line,300,f)){
     sscanf(&line[0], "%s %lf %lf %lf %lf",&particle, &E, &px,&py,&pz);
          //cout << alpha << "\n";
          tree->Fill();
      }


 fclose(f);
 tree->Print();
 tree->Write();

delete t;

}
