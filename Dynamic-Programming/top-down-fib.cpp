#include <iostream>
#include <map>


int fib(int n, std::map<int,int> fibs)
{
  if (n <= 1)
    {
      return n;
    }

  if(fibs.find(n) == fibs.end())
    {
      fibs[n] = fib(n-1,fibs) + fib(n-2,fibs);
    }

  return fibs[n];
}


int main(){
  std::map<int, int> fibs;
  std::cout<<fib(8,fibs)<<std::endl;
  return 0;
}
