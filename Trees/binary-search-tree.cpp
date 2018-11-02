#include <iostream>

using namespace std;//Once again, this is not a good practice!

class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data = x;
    left = right = NULL;
  }
};
class Tree{
public:
  Node *root;
  Node* newNode(int x){
    Node* newNode = new Node(x);
    return newNode;
  }
  Node* insert(Node* node, int x){
    if(node == NULL){
      return newNode(x);
    }
    if(x < node->data){
      node->left = insert(node->left, x);
    }else{
      node->right = insert(node->right,x);
    }
    return node;
  }
  Node* deleteNode(Node* root, int x){
    if(root==NULL){
      return root;
    }
    if(root->data > x){
      root->left = deleteNode(root->left,x);
      return root;
    }

    if(root->right==NULL){
      Node* temp=root->left;
      delete root;
};
