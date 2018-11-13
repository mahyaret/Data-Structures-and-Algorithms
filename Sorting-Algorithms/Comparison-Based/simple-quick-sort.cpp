/*Quicksort: Pick a random pivot element, x, from a; partition a into the set of elements less than x, 
the set of elements equal to x, and the set of elements greater than x; and, finally, recursively sort the 
first and third sets in this partition.*/

#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int i, int n){
  if (n<=1) return;
  int x = a[i+rand()%n];
  int p = i-1, j=i, q=i+n; // Not a good parctice!
  //a[i]...a[p]<x, a[p+1]...a[q-1]?x, a[q]...a[i+n-1]>x
  int tempSwap;
  while (j<q){
    if(a[j]<x){
      tempSwap = a[j];
      a[j] = a[++p];
      a[p] = tempSwap;
      j++;
    }else if(a[j]>x){
      tempSwap = a[j];
      a[j] = a[--q];
      a[q] = tempSwap;
    }else{
      j++;
    }
  }
  //a[i]...a[p]<x, a[p+1]...a[q-1]=x, a[q]...a[i+n-1]>x
  quickSort(a, i, p-i+1);
  quickSort(a, q, n-(q-i));
}


void quickSort(vector<int> &a){
  quickSort(a,0,a.size());
}

int main(){
  vector<int> arrayToBeSorted = {13,8,5,2,4,0,6,9,7,3,12,1,10,11};
  quickSort(arrayToBeSorted);
  for (int element:arrayToBeSorted){
    cout<<element<<" ";
  }
  return 0;
}
