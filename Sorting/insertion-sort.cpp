#include <iostream>

void insertionSort(int array [], int arraySize)
{
  //Starting from second element since the first element is "sorted"
  for (int sortedIterator = 1; sortedIterator<arraySize; sortedIterator++)
    {
      int currentValue = array[sortedIterator];
      int unsortedIterator = sortedIterator;
      
      //Place the the current value in the right place
      //in the sorted subset array[0..sortedIterator-1]
      while(unsortedIterator>0 && array[unsortedIterator-1]>currentValue)
	{
	  array[unsortedIterator] = array[unsortedIterator-1];
	  unsortedIterator--;
	}
      array[unsortedIterator]=currentValue;
    }
}

//helper function to display the array
void display(int array[],int arraySize)
{
  for (int displayIterator=0; displayIterator<arraySize; displayIterator++)
    {
      std::cout<<array[displayIterator]<<" "<<std::endl;
    }
  std::cout<<std::endl;
}
int main ()
{
  int array [] = {3,8,5,4,1,9,-2};
  int arraySize = sizeof(array)/sizeof(array[0]);

  insertionSort(array, arraySize);

  display(array, arraySize);
  
  return 0;
}
