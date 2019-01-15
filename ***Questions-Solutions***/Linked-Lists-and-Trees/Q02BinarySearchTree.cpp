#include <iostream>
#include <vector>
#include <queue>


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


bool isBinarySearchTree(Node *treeHead,int upperLimit = 0, int lowerLimit=0){
  if(lowerLimit!=0 && treeHead->value<lowerLimit)
    return false;
  if(upperLimit!=0 && treeHead->value>upperLimit)
    return false;
  //std::cout<<upperLimit<<" " <<lowerLimit<<"\n";
  bool rightBST=true;
  bool leftBST=true;
  if(treeHead->right != NULL)
    rightBST = isBinarySearchTree(treeHead->right,upperLimit,treeHead->value);
  if(rightBST && treeHead->left != NULL)
    leftBST = isBinarySearchTree(treeHead->left,treeHead->value,lowerLimit);
  //std::cout<<"Right BST: "<<rightBST<<" "<<"Left BST: "<<leftBST<<"\n";
  return rightBST && leftBST;
}


int main(){
  Node *tree = new Node(4);
  tree->right = new Node(5);
  tree->left = new Node(2);
  tree->left->right = new Node(3);
  tree->left->left = new Node(1);
  tree->right->right = new Node(6);
  tree->right->right->right = new Node(7);

  std::cout<<isBinarySearchTree(tree)<<"\n";

  return 0;
}
