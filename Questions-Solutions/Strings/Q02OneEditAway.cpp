#include <iostream>


bool isOneEditAway(std::string A,std::string B){
  int count=0;
  if(A.length() == B.length()){
    for (int i=0;i<A.length();i++){
      if(A[i] != B[i]){
        count++;
      }
      if(count>1)
        return false;
    }
  }else{
    count =0;
    int i=0;
    while(i<B.length()){
      if(A[i+count]==B[i])
        i++;
      else
        count++;

      if(count>1)
        return false;
    }
  }
  return true;
}

int main(){
  std::string A="asre";
  std::string B="abde";

  std::cout<<(isOneEditAway(A,B)?"true":"false")<<std::endl;

  return 0;
}
