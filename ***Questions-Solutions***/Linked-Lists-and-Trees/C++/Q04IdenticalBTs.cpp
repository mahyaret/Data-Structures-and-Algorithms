#include <iostream>
#include <vector>


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


bool isIdentical(Node* x, Node* y)
{
  if (x == NULL && y == NULL)
    {
      return true;
    }

  return (x && y) && (x->data == y->data) &&
    isIdentical(x->left, y->left) &&
    isIdentical(x->right, y->right);
}
  
int main()
{
  /* Let both of the trees be: 
              7 
           /     \ 
          3       11 
         /  \    /  \ 
        1    5  9    13 */
  Node *root_x = new Node(7);
  root_x->right = new Node(11);
  root_x->right->right = new Node(13);
  root_x->right->left = new Node(9);
  root_x->left = new Node(3);
  root_x->left->right = new Node(5);
  root_x->left->left = new Node(1);

  Node *root_y = new Node(7);
  root_y->right = new Node(11);
  root_y->right->right = new Node(13);
  root_y->right->left = new Node(9);
  root_y->left = new Node(3);
  root_y->left->right = new Node(5);
  root_y->left->left = new Node(1);


  std::cout<<isIdentical(root_x,root_y)<<std::endl;
  return 0;
}
