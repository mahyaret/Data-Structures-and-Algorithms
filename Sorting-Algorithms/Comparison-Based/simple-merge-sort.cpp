#include <iostream>
#include <vector>

using namespace std; //Not a good practice!

void merge(vector<int> &a0, vector<int> &a1, vector<int> &a) {
  int i0 = 0, i1 = 0;
  for (int i = 0; i < a.size(); i++) {
    if (i0 == a0.size())
      a[i] = a1[i1++];
    else if (i1 == a1.size())
      a[i] = a0[i0++];
    else if (a0[i0] < a1[i1])
      a[i] = a0[i0++];
    else
      a[i] = a1[i1++];
  }
}

void mergeSort(vector<int> &a) {//integer for simplicity :)
  if (a.size() <= 1) return;
  vector<int> a0(0);
  a0.insert(a0.begin(),a.begin(),a.begin()+a.size()/2);
  vector<int> a1(0);
  a1.insert(a1.begin(),a.begin()+a.size()/2,a.end());
  mergeSort(a0);
  mergeSort(a1);
  merge(a0, a1, a);
}

int main(){
  vector<int> vectorToBeSorted = {13,8,5,2,4,0,6,9,7,3,12,1,10,11};
  mergeSort(vectorToBeSorted);
  for(int element:vectorToBeSorted){
    cout<<element<<" ";
  }
  return 0;
}

