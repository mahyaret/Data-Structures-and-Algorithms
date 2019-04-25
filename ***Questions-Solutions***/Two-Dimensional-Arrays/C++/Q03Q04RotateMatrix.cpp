#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct pair{
    int newi;
    int newj;
};

pair rotate_sub(int i,int j,int n){
    pair out;
    out.newi = j;
    out.newj = n-1-i;
    return out;
}

void rotate(std::vector<std::vector<int>> ar,int n){
    int current_i;
    int current_j;
    pair p;
    for(int i=0;i<ceil((float)n/2);i++){
        for(int j=0;j<floor((float)n/2);j++){
            std::vector<int> tmp{-1,-1,-1,-1};
            current_i = i;
            current_j = j;
            for(int k=0;k<4;k++){
                tmp[k] = ar[current_i][current_j];
                p=rotate_sub(current_i,current_j,n);
                current_i = p.newi;
                current_j = p.newj;
            }
            for(int k=0;k<4;k++){
                ar[current_i][current_j] = tmp[(k+3)%4];
                p = rotate_sub(current_i,current_j,n);
                current_i = p.newi;
                current_j = p.newj;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<ar[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

int main(){
    
    std::vector<std::vector<int>> ar{{1,2,3,4,5},
        {6,7,8,9,1},
        {2,3,4,5,6},
        {7,8,9,1,2},
        {3,4,5,6,7}};
    rotate(ar,5);
    
    return 0;
}
