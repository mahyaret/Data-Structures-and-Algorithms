#include <iostream>
#include <vector>
#include <queue>


class Node{
public:
  int value;
  Node *next;
  Node(){
    next = NULL;
    value = -1;
  }
};

int nth_element_end(Node* listHead,int n){


  Node *right=listHead;
  Node *left=listHead;

  for(int i=0;i<=n;i++){
    if(right == NULL)
      return -1;
    right = right->next;
  }

   while(right != NULL){
    right = right->next;
    left = left->next;
   }

  return left->value;
}


void push(Node** head_ref, int new_data)
{


  /* allocate node */
  Node* new_node = new Node();

  /* put in the data */
  new_node->value = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

int main(){


  Node* head = new Node();
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  std::cout<<nth_element_end(head,2)<<std::endl;
  return 0;
}
