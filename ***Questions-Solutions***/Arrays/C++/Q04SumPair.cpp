#include <iostream>
#include <list>


void findPair(std::list<int> array, int sum)
{
  array.sort();
  for (auto element:array)
    {
      std::cout<<element<<" ";
    }
  std::cout<<"Pair Not Found!"<<std::endl;
}

int main()
{
  std::list<int> array = { 8, 7, 2, 5, 3, 1};
  int sum = 10;

  findPair(array, sum);
  return 0;
}
