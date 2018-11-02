//Singly-linked lists can be used for implementing Stacks and Queues
//For Stack implementation, push() and pop() are defined.
//For Queue implementation, add() and remove() are defined.
#include <iostream>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node(int x){
    data = x;
    next= NULL;
  }
};
class LinkedList{
public:
  Node *head;
  Node *tail;
  int numOfNodes;
  LinkedList(){
    head = tail = NULL;
    numOfNodes = 0;
  }
  ~LinkedList(){
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
    newNode->next = head;
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
//Overloading << operator
ostream& operator<<(ostream &out, const LinkedList *param){
  Node *obj = param->head;
  while(obj!=NULL){
    out<<obj->data<<" ";
    obj = obj->next;
  }
  return out;
}

int main(){
  LinkedList *list = new LinkedList();

  list->push(1);
  list->push(2);
  list->push(3);
  list->push(4);
  list->push(5);

  cout<<list<<endl;
  //cout<<list->head->data<<" "<<list->head->next->data<<endl;
  //cout<<list->tail->data;
  cout<<endl;
  return 0;
}
