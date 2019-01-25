#include <iostream>
#include <vector>


bool isSafe(std::vector<std::vector<char>> chessMat, int row, int column)
{
  //Sharing same column
  for (int i=0; i<row; i++)
    {
      if (chessMat[i][column] == 'Q')
	{
	  return false;
	}
    }
  
  //Sharing same \ diagnal
  for (int i=row, j=column; i>=0 && j>=0; i--, j--)
    {
      if (chessMat[i][j] == 'Q')
	{
	  return false;
	}
    }
  
  //Sharing same / diagnal
  for (int i=row, j=column; i>=0 && j<chessMat.size(); i--, j++)
    {
      if (chessMat[i][j] == 'Q')
	{
	  return false;
	}
    }
  return true;
}
	      

void displayMat(std::vector<std::vector<char>> chessMat)
{
  for (auto row : chessMat)
    {
      for (auto item : row)
	{
	  std::cout<<item<<" ";
	}
      std::cout<<std::endl;
    }
}

void nQueen(std::vector<std::vector<char>> chessMat, int row=0)
{
  if (row == chessMat.size())
    {
      displayMat(chessMat);
      std::cout<<std::endl;
      return;
    }
  for (int i = 0; i < chessMat.size(); i++)
    {
      if(isSafe(chessMat, row, i))
	{
	  chessMat[row][i] = 'Q';
	  nQueen(chessMat, row+1);
	  //chessMat[row][i] = '+';
	}
    }
}

int main()
{
  std::vector<std::vector<char>> chessMat = {{'+','+','+','+'},
					     {'+','+','+','+'},
					     {'+','+','+','+'},
					     {'+','+','+','+'}};

  //displayMat(chessMat);
  // std::cout<<"(2,0) :"<<isSafe(chessMat,2,0)<<std::endl;
  //std::cout<<"(1,1) :"<<isSafe(chessMat,1,1)<<std::endl;
  //std::cout<<"(2,3) :"<<isSafe(chessMat,2,3)<<std::endl;
  //std::cout<<"(3,2) :"<<isSafe(chessMat,3,2)<<std::endl;
  nQueen(chessMat);
  return 0;
}
