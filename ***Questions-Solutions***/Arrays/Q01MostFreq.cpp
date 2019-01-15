#include <iostream>
#include <map>

struct mostFreq{
  int num;
  int value;
};

int main(){
  int array[6] = {1,1,2,3,1,2};
  mostFreq a[6];
  std::map<int,int> b;
  for(int i=0;i<6;i++){
    b[array[i]]++;
  }
  int max = 0;
  int index =0;
  for(auto a : b){
    if(max<a.second){
      max = a.second;
      index = a.first;
    }
  }
  std::cout<<index<<std::endl;
  return 0;
}
