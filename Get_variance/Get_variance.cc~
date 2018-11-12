#include <vector>
#include <iostream>
#include "Get_variance.h"
using namespace std;
double Get_variance(vector<double> values){
  if(values.size()==0){
    cout<<"Get_envelop says : No elements!"<<endl;
    return -1;
  }
  double sum=0;
  double sum2=0;
  size_t N =  values.size();
  for(size_t i = 0; i < N; i++){
    double value=values[i];
    sum+=value;
    sum2+=value*value;
     

  }
  double avg = sum/N;
  double sqavg=sum2/N;
  double variance = sqavg- avg*avg;
  return variance;

}
