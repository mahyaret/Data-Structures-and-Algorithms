#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a, int x, int low, int high){
  int mid = (low + high)/2;
  if(x<a[mid]){
    return binarySearch(a,x,low,mid);
  }else if(x>a[mid]){
    return binarySearch(a,x,mid,high);
  }else{
    return mid;
  }
}

int binarySearch(vector<int> &a, int x){
  binarySearch(a,x,0,a.size());
}

int main(){
  vector<int> targetArray = {1,4,5,8,9,10,14,16,22,31,45};
  cout<<"14 is at "<<binarySearch(targetArray,14)<<endl;
  return 0;
}
