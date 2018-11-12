#include <iostream>
#include "Get_sys_hessian.h"
using namespace std;

double Get_sys_hessian(vector<double> values){
  if(values.size()==0){
    cout<<"Get_envelop says : No elements!"<<endl;
    return -1;
  }
  double center=values[0];
  double sumdiff2=0;
  size_t N = values.size();
  for(size_t i = 1; i < N; i++){
    sumdiff2+=pow( center-values[i],2);

  }

  double sys=sqrt(sumdiff2);
  return sys;

}
