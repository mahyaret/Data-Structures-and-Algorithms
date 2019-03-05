#include <iostream>

class Stack{
  int _maxSize;
  int _top;
  int *_data;

public:
  Stack(int capacity)
  {
    _maxSize = capacity;
    _top = -1;
    _data = new int(_maxSize);
  }

  int size()
  {
    return _top+1;
  }
  
  bool isEmpty()
  {
    return (_top == -1);
  }
  
  bool isFull()
  {
    return (_top == _maxSize-1);
  }
  
  void push(int datum)
  {
    if (isFull())
      {
	std::cout<<"The Stack is full!"<<std::endl;
	return;
      }
    _data[++_top] = datum;
  }
  
  int peek()
  {
    if (isEmpty())
      {
	std::cout<<"Stack is empty!"<<std::endl;
	return 0;
      }
    return _data[_top];
  }
  int pop()
  {
    if(isEmpty())
      {
	std::cout<<"Nothing to pop!"<<std::endl;
	return 0;
      }
    return _data[--_top];
  }
};


int main()
{
  Stack* st = new Stack(5);

  st->push(1);
  st->push(2);
  st->push(3);

  std::cout<<"Top element is "<<st->peek()<<std::endl;
  std::cout<<"Stack size is "<<st->size()<<std::endl;

  st->pop();
  st->pop();
  st->pop();

  if(st->isEmpty())
    {
      std::cout<<"Stack is empty"<<std::endl;
    }
  else
    {
      std::cout<<"Stack is not empty"<<std::endl;
    }
		       
  return 0;
}
