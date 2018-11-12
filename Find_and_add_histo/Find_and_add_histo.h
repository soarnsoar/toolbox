#ifndef FIND_AND_ADD_HISTO_H
#define FIND_AND_ADD_HISTO_H

#include <TString.h>
#include <TFile.h>
#include <TList.h>
#include <TKey.h>
#include <TH1D.h>
#include <vector>
#include <TDirectoryFile.h>

//void Find_and_add_histo(TString filename, TString directory, TString variable, std::vector<TH1D*> &vH);
vector<TH1D*> Find_and_add_histo(TString filename, TString directory, TString variable);
//TFile *myfile;
//TList *mylist;
//TString object_name;
//TKey *key;
//TString dirname;
//TDirectoryFile *dir;
//TList *hlist;
//TKey *hkey;
//TString hname;
//TH1D *h;

#endif
