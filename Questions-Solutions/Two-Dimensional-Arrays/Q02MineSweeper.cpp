#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> click(std::vector<std::vector<int>> field,int i,int j){
  std::queue<std::vector<int>> toCheck;

  if(field[i][j]==0){

    field[i][j] = -2;
    toCheck.push({i,j});
  }
  std::vector<int> pair;
  while(!toCheck.empty()){
    pair=toCheck.front();
    i= pair[0];
    j=pair[1];
    toCheck.pop();
    for(int a=i-1;a<=i+1;a++){
      for(int b=j-1;b<=j+1;b++){
        if(a>=0 && b>=0 && a<5 && b<5 && field[a][b]==0){
          field[a][b]=-2;
        }
      }
    }
  }
  return field;
}


void mineSweeper(int bombs[3][2],int num_cols,int num_rows){
  std::vector<std::vector<int>> field(5,std::vector<int>(5));

  int numOfBombs = 3;


  for(int i=0;i<numOfBombs;i++){
    field[bombs[i][0]][bombs[i][1]]=-1;
    for(int a=(bombs[i][0]-1);a<=(bombs[i][0]+1);a++){
      for(int b=(bombs[i][1]-1);b<=(bombs[i][1]+1);b++){
        if(a>=0 && b>=0 && a<num_rows && b<num_cols && field[a][b]!=-1){
          field[a][b]++;
        }
      }
    }
  }

  field = click(field,3,0);

  for(int i=0;i<num_rows;i++){
    for(int j=0;j<num_cols;j++){
      std::cout<<field[i][j]<<" ";
    }
    std::cout<<"\n";
  }

}

int main (){
  int bombs[3][2]= {{0,0},{3,3},{1,2}};
  int num_cols =5;
  int num_rows =5;
  mineSweeper(bombs,num_cols,num_rows);
  return 0;
}
