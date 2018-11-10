#include <iostream>
#include <map>
#include <vector>

int main(){
  int A[6] = {1,2,2,3,12,42};
  int B[4] = {3,12,21,34};
  std::vector<int> a;
  int p1=0,p2=0;
  for(int i=0;i<6;i++){
    if(A[p1] == B[p2]){
      std::cout<<A[p1]<<" ";
      p1++;
      p2++;
    }
    if(A[p1]>B[p2]){
      p2++;
    }
    if(A[p1]<B[p2]){
      p1++;
    }

  }
  std::cout<<std::endl;

  return 0;
}
