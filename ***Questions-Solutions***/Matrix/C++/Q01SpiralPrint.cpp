#include <iostream>
#include <vector>


void printSpiralOrder(std::vector<std::vector<int>> matrix)
{
  int top = 0;
  int bottom = matrix.size()-1;
  int left = 0;
  int right = matrix[0].size()-1;

  while (true)
    {
      if(left > right)
	{
	  break;
	}
      // print top row
      for(int i = left; i<= right; i++)
	{
	  std::cout<<matrix[top][i]<<" ";
	}
      top++;
      if(top > bottom)
	{
	  break;
	}
      // print right column
      for(int i = top; i<=bottom; i++)
	{
	  std::cout<<matrix[i][right]<<" ";
	}
      right--;
      if(left>right)
	{
	  break;
	}
      // print bottom row
      for (int i=right; i >= left; i--)
	{
	  std::cout<<matrix[bottom][i]<<" ";
	}
      bottom--;
      if(top>bottom)
	{
	  break;
	}
      // print left column
      for (int i = bottom; i>= top; i--)
	{
	  std::cout<<matrix[i][left]<<" ";
	}
      left++;
    }
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
