#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a, int x){
  int low = 0, high = a.size();
  while(high!=low){
    int mid = (high + low)/2;
    if(x<a[mid]){
      high = mid;
    }else if(x>a[mid]){
      low = mid + 1;
    }else{
      return mid;
    }
  }
  return low;
}

int main(){
  vector<int> targetArray = {1,4,5,8,9,10,14,16,22,31,45};
  cout<<"14 is at "<<binarySearch(targetArray,14)<<endl;
  return 0;
}
