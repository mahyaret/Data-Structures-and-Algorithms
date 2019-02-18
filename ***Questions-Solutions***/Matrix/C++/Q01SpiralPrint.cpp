#include <iostream>
#include <vector>

void printSpiralOrder(std::vector<std::vector<int>> matrix, int m, int n)
{
  //Not complete!
}

void printSpiralOrder(std::vector<std::vector<int>> matrix)
{
  printSpiralOrder(matrix, matrix.size(), matrix[0].size());
}

int main ()
{
  std::vector<std::vector<int>> matrix =
    {
      { 1,  2,  3,  4, 5},
      {16, 17, 18, 19, 6},
      {15, 24, 25, 20, 7},
      {14, 23, 22, 21, 8},
      {13, 12, 11, 10, 9}
    };

  printSpiralOrder(matrix);
  
  return 0;
}
