#ifndef GET_ENVELOP_HISTO_H
#define GET_ENVELOP_HISTO_H
#include <TH1D.h>
#include <TGraphAsymmErrors.h>
TGraphAsymmErrors* Get_envelop_histo(vector<TH1D*> vH, TString type,int idx_center);

#endif
