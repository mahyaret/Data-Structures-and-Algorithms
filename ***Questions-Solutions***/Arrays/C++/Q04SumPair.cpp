#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void findPair(std::vector<int> array, int sum)
{
  std::sort(array.begin(), array.end());
  int startIndex = 0;
  int endIndex = array.size()-1;

  while(startIndex < endIndex)
    {
      if(array[startIndex] + array[endIndex] == sum)
	{
	  std::cout<<array[startIndex]<<","<<array[endIndex]<<std::endl;
	  startIndex ++;
	  endIndex --;
	}
      if((sum - array[startIndex]) > array[endIndex])
	{
	  startIndex ++;
	}
      if((sum - array[startIndex]) < array[endIndex])
	{
	  endIndex --;
	}
    }
}

int main()
{
  std::vector<int> array = { 8, 7, 2, 5, 3, 1};
  int sum = 10;

  findPair(array, sum);
  return 0;
}
