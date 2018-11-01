//Singly-linked lists can be used for implementing Stacks and Queues
//For Stack implementation, push() and pop() are defined.
//For Queue implementation, add() and remove() are defined.
#include <iostream>

using namespace std;

class Node{
public:
  int data;
  int numOfNodes;
  Node *head;
  Node *next;
  Node *tail;
  Node(int x){
    data = x;
    numOfNodes = 0;
    head=next=tail= NULL;
  }
  ~Node(){
    Node *tempHeadHolder = head;
    while(tempHeadHolder!=NULL){
      Node *tempPlaceHolder;
      tempHeadHolder=tempHeadHolder->next;
      delete tempPlaceHolder;
    }
  }
  //Stack
  void push(int x){
    Node *newNode = new Node(x);
    newNode->next = this;
    //cout<<newNode->data<<" ";
    head = newNode;
    if(numOfNodes==0){
      tail = newNode;
    }
    numOfNodes++;
  }
  int pop(){
    if(numOfNodes==0){
      return (int)NULL;
    }
    int x = head->data;
    Node *tempHeadHolder = head;
    head = head->next;
    delete tempHeadHolder;
    numOfNodes--;
    if(numOfNodes==0){
      tail = NULL;
    }
    return x;
  }
  //Queue
  void add(int x){
    Node *newNode = new Node(x);
    if(numOfNodes==0){
      head = newNode;
    }else{
      tail->next = newNode;
    }
    tail = newNode;
    numOfNodes++;
  }
  int remove(){
    return pop();
  }
};

int main(){
  Node *n = new Node(1);
  //cout<<n->data<<" ";
  n->push(2);
  n->push(3);
  n->push(4);
  n->push(5);

  cout<<n->data<<" "<<n->next->data;
  cout<<endl;
  return 0;
}
