#include <vector>
#include <iostream>
#include "Get_envelop.h"
using namespace std;
void Get_envelop(vector<double> values,double &min, double &max){
  if(values.size()==0){
    cout<<"Get_envelop says : No elements!"<<endl;
    return;
  }
  double maximum=values[0];
  double minimum=values[0];
  
  for(size_t i = 0; i < values.size(); i++){
    double value=values[i];
    if(maximum < value){
      maximum=value;
      //  cout<<"index of maximum="<<i<<endl;
    }
    if(minimum > value){
      minimum=value;
      //cout<<"index of minimum="<<i<<endl;

    }     

  }

  max=maximum;
  min=minimum;
}
