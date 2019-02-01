#include <iostream>

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

void search(int data, Node *child, Node *parent)
{
  if (child == NULL)
    {
      std::cout<<"Data Not Found"<<std::endl;
      return;
    }
  if (child->data == data)
    {
      if(parent == NULL)
	{
	  std::cout<<"The node with data "<< data << " is a root node."<<std::endl;
	}
      else if(data > parent->data)
	{
	  std::cout<<"The node with data "<< data << " is the right node of "<< parent->data<<"."<<std::endl;
	}
      else if(data < parent->data)
	{
	  std::cout<<"The node with data " << data << " is the left node of "<< parent->data<<"."<<std::endl;
	}
      return;
    }

  if (child->data > data){
    return search(data, child->left, child);
  }
  return search(data, child->right, child);

}

int main()
{
  /* Let the tree be: 
              7 
           /     \ 
          3       11 
         /  \    /  \ 
        1    5  9    13 */
  Node *root = new Node(7);
  root->right = new Node(11);
  root->right->right = new Node(13);
  root->right->left = new Node(9);
  root->left = new Node(3);
  root->left->right = new Node(5);
  root->left->left = new Node(1);

  search(7, root, NULL);
  search(5, root, NULL);
  search(9, root, NULL);
  
  return 0;
}
