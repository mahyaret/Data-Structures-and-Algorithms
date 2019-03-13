#include <iostream>
#include "binary-search-tree.h"

using namespace std;//Once again, this is not a good practice!

Node::Node(int x){
  data = x;
  left = right = NULL;
}
Tree::Tree(int x){
  root = new Node(x);
}
Node* Tree::insert(Node* subRoot, int x){
  if(subRoot == NULL){
    return new Node(x);
  }
  if(x < subRoot->data){
    subRoot->left = insert(subRoot->left, x);
  }else{
    subRoot->right = insert(subRoot->right,x);
  }
  return subRoot;
}
void Tree::insert(int x){
  insert(root,x);
}
Node* Tree::deleteNode(Node *subRoot, int x){
  if(subRoot==NULL){
    return subRoot;
  }
  if(subRoot->data > x){
    subRoot->left = deleteNode(subRoot->left,x);
    return subRoot;
  }else if(subRoot->data < x){
    subRoot->right = deleteNode(subRoot->right,x);
    return subRoot;
  }
  if(subRoot->left==NULL){
    Node* temp=subRoot->right;
    delete subRoot;
    return temp;
  }else if(subRoot->right==NULL){
    Node* temp=subRoot->left;
    delete subRoot;
    return temp;
  }else{
    Node * successorParent=subRoot->right;//For sure it's on the right!
    
    Node * successor =subRoot->right;
    while(successor->left!=NULL){//For sure is on the left!
      successorParent=successor;
      successor=successor->left;
    }
    successorParent->left=successor->right;
    
    subRoot->data = successor->data;
    
    delete successor;
    return subRoot;
  }
}
void Tree::deleteNode(int x){
  deleteNode(root,x);
}
void Tree::inOrderTraverse(Node* subRoot){
  if(subRoot!=NULL){
    inOrderTraverse(subRoot->left);
    cout<<subRoot->data<<" ";
    inOrderTraverse(subRoot->right);
  }
}
void Tree::preOrderTraverse(Node* subRoot){
  if(subRoot!=NULL){
    cout<<subRoot->data<<" ";
    preOrderTraverse(subRoot->left);
    preOrderTraverse(subRoot->right);
  }
}
void Tree::postOrderTraverse(Node* subRoot){
  if(subRoot!=NULL){
    postOrderTraverse(subRoot->left);
    postOrderTraverse(subRoot->right);
    cout<<subRoot->data<<" ";
  }
}
void Tree::inOrderTraverse(){
  inOrderTraverse(root);
}
void Tree::preOrderTraverse(){
  preOrderTraverse(root);
}
void Tree::postOrderTraverse(){
  postOrderTraverse(root);
}

