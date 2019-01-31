#include <iostream>

class Node
{
  int data;
  Node *left;
  Node *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

Node * search(int data, Node *child, Node *parent)
{
  if (child == NULL)
    {
      std::cout<<"Data Not Found"<<std::endl;
      return false;
    }
  if (child->data == data)
    {
      if(parent == NULL)
	{
	  std::cout<<"The node with data "<< data << " is a root node."<<std::endl
      return true;
    }

}

int main()
{

  return 0;
}
