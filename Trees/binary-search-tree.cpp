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
  Tree(int x){
    root = new Node(x);
  }
  Node* insert(Node* subRoot, int x){
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
  void insert(int x){
    insert(root,x);
  }
  Node* deleteNode(Node *subRoot, int x){
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
  void deleteNode(int x){
    deleteNode(root,x);
  }
  void inorderTraverse(Node* subRoot){
    if(subRoot!=NULL){
      inorderTraverse(subRoot->left);
      cout<<subRoot->data<<" ";
      inorderTraverse(subRoot->right);
    }
  }
  void inorderTraverse(){
    inorderTraverse(root);
  }
};

int main(){
  /* I want to create the following BST 
              7 
           /     \ 
          3       11 
         /  \    /  \ 
        1    5  9    13 */
  Tree *root = new Tree(7);
  root->insert(3);
  root->insert(11);
  root->insert(1);
  root->insert(5);
  root->insert(9);
  root->insert(13);

  root->inorderTraverse();
  cout<<endl;
  return 0;
}
