#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Node{
public:
  int value;
  Node *right;
  Node *left;

  Node(int v){
    value = v;
    right = NULL;
    left = NULL;
  }

};

bool  pathToX(Node *treeHead,int x,std::stack<int> &path){
  if(treeHead == NULL)
    return false;
  if(treeHead->value == x){
    path.push(treeHead->value);
    return true;
  }
  bool leftPath = pathToX(treeHead->left,x,path);
  if(leftPath){
    path.push(treeHead->value);
    return true;
  }
  bool rightPath = pathToX(treeHead->right,x,path);
  if(rightPath){
    path.push(treeHead->value);
    return true;
  }
  return false;
}

int LCA(Node *treeHead,int x,int y){
  std::stack<int> pathX;
  pathToX(treeHead,x,pathX);
  std::stack<int> pathY;
  pathToX(treeHead,y,pathY);
  int out =0;
  while(!pathX.empty() && !pathY.empty()){
    if(pathX.top()==pathY.top()){
      out = pathX.top();
    }
    pathX.pop();
    pathY.pop();
  }
  return out;
}

int main(){
  Node *tree = new Node(4);
  tree->right = new Node(5);
  tree->left = new Node(2);
  tree->left->right = new Node(3);
  tree->left->left = new Node(1);
  tree->right->right = new Node(6);
  tree->right->right->right = new Node(7);

  std::cout<<LCA(tree,2,3)<<"\n";

  /*std::cout<<"***********\n";
  std::vector<int> pathX;
  pathToX(tree,2,pathX);

  for(int p:pathX){
    std::cout<<p<<"\n";
  }
  std::cout<<"***********\n";
  std::vector<int> pathY;
  pathToX(tree,3,pathY);

  for(int p:pathY){
    std::cout<<p<<"\n";
    }*/


  return 0;
}
