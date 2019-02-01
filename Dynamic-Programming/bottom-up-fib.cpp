#include <iostream>


int fib(int n)
{
  if (n <= 1)
    {
      return n;
    }

  int currentFib = 1;
  int previousFib = 0;
  for (int i=0; i<n-1; i++)
    {
      int newFib = currentFib + previousFib;
      previousFib = currentFib;
      currentFib = newFib;
      
    }
  return currentFib;
}
      


int main()
{
  std::cout<<fib(8)<<std::endl;
  return 0;
}
