#include "Get_envelop_histo.h"
#include <Get_sys_hessian.h>
#include <Get_envelop.h>
#include <iostream>
using namespace std;
TGraphAsymmErrors* Get_envelop_histo(vector<TH1D*> vH, TString type,int idx_center=0){
  int Nbins= vH[idx_center]->GetNbinsX();

  double x[Nbins];
  double y[Nbins];

  double exh[Nbins];
  double exl[Nbins];

  double eyh[Nbins];
  double eyl[Nbins];

  for(int i = 1; i <= vH[idx_center]->GetNbinsX(); i++){//for each X bin                                                                              
    size_t N = vH.size();
    vector<double> vy;

    for(size_t ih=0; ih<N; ih++){
      vy.push_back(vH[ih]->GetBinContent(i));

    }
    double ycenter = vH[idx_center]->GetBinContent(i);

    double ymax=-1;
    double ymin=-1;

    if(type=="envelop"){
      Get_envelop(vy,ymin,ymax);
    }
    else if(type=="hessian"){
      double sigma=Get_sys_hessian(vy);
      ymax=ycenter+Get_sys_hessian(vy);
      ymin=ycenter-Get_sys_hessian(vy);

    }
    else{
      cout<<"Get_envelop_histo says : Please set type of systematics "<<endl;
    }
    x[i-1]=vH[idx_center]->GetBinCenter(i);
    exh[i-1]=0; exl[i-1]=0;
    y[i-1]=ycenter;
    
    eyh[i-1]=ymax-ycenter;
    eyl[i-1]=-ymin+ycenter;
    

    vy.clear();
    

  }//end of each bin
  TGraphAsymmErrors *envH=new TGraphAsymmErrors(vH[idx_center]->GetNbinsX(),x,y,exl,exh,eyl,eyh);

  return envH;
}
