#include "Find_and_add_histo.h"
#include <iostream>
#include <vector>
using namespace std;
//void Find_and_add_histo(TString filename, TString directory, TString variable, std::vector<TH1D*> &vH){
vector<TH1D*> Find_and_add_histo(TString filename, TString directory, TString variable){
  std::vector<TH1D*> vH;
  //TFile *file=TFile::Open(filename);
  
  /*
  myfile = new TFile();
  mylist = new TList();
  key= new TKey();
  hlist = new TList();
  hkey= new TKey();
  dir = new TDirectoryFile();
  h = new TH1D();
  */  
  TFile *myfile=TFile::Open(filename);
  //TList *list=(TList*)file->GetListOfKeys();
  TList *mylist=(TList*)myfile->GetListOfKeys();
  //  TString object_name="";
  //  TString object_name="";
  //TKey *key=(TKey*)list->First();
  TKey *key=(TKey*)mylist->First();


  while( 1 ){

    //    TString dirname=key->GetName();
    TString dirname=key->GetName();
    if( dirname.Contains(directory)   ){
      TDirectoryFile* dir=(TDirectoryFile*)myfile->Get(dirname);
      TList *hlist=(TList*)dir->TDirectoryFile::GetListOfKeys();
      TKey *hkey=(TKey*)hlist->First();
      TString object_name="";
      while(1 ){
	TString hname=hkey->GetName();
        if( hname.Contains(variable)   ){
          object_name=dirname+"/"+hname;


	  break;//now we got the name of histogram, break the while loop;
        }
        if(hkey==hlist->Last()) break;
	hkey=(TKey*)hlist->After(hkey);
      }//end of while hlist
      //delete hkey;
      cout<<"file="<<filename<<" // histogram="<<object_name<<endl;
      TH1D *h=(TH1D*)myfile->Get(object_name)->Clone();
      h->SetDirectory(0);
      TH1::AddDirectory(0);
      vH.push_back(h);
      //delete h; ->no

    }//if W match                                                                                                                                                                              
    if(key==mylist->Last()) break;
    key=(TKey*)mylist->After(key);
    
  }
  //  delete mylist;
  myfile->Close();
  delete myfile;
  myfile=NULL;
  //  delete mylist;
  //  delete key;

  return vH;
}
