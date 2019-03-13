#include <iostream>
#include "binary-search-tree.h"

using namespace std;

int test_all(){
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

  cout<<"inOrderTraverse: ";
  root->inOrderTraverse();
  cout<<endl;
  cout<<"preOrderTraverse: ";
  root->preOrderTraverse();
  cout<<endl;
  cout<<"postOrderTraverse: ";
  root->postOrderTraverse();
  cout<<endl;
  return 0;
}
int main()
{
	int result;
	
	printf("Running Example tests .. \n");
	result = test_all();

	if (result == 0) 
		printf ("tests passed.\n");
	else
		printf ("tests failed.\n");

    return result;  /* remember the value 0 is considered passing in a travis-ci sense */

}
