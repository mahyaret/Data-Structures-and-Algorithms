#include <iostream>


bool rotation(int A[],int B[]){
  int key_i=-1;
  for(int i=0;i<7;i++){
    if(A[0] == B[i]){
      key_i = i;
      break;
    }
  }
  if(key_i==-1)
    return false;

  for(int i=1;i<7;i++){
    if(A[i]!=B[(key_i+i)%7])
      return false;
  }
  return true;

}

int main(){
  int A[]={1,2,3,4,5,6,7};
  int B[]={4,5,6,7,1,2,3};

  std::cout<<((rotation(A,B))?"true":"false")<<std::endl;
  return 0;
}
