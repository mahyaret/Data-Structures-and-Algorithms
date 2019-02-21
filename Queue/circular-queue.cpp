#include <iostream>
#include <vector>

// Data structure for queue

class queue
{
  int* _data;  //array to store queue elements
  int  _maxSize;//maximum capacity of the queue
  int  _front;  //front points to front element in the queue
  int  _rear;   //rear points to last element in the queue
  int  _size;   //current capacity of the queue
public:
  queue(int size)
  {
    _data = new int[size]();
    _maxSize = size;
    _front = 0;
    _rear = -1;
    _size = 0;
  }
  // Utility function to return the size of the queue
  int size(queue *pt)
  {
    return _size;
  }

  // Utility function to check if the queue is empty or not
  int isEmpty(queue *pt)
  {
    return !size(pt);
  }
  // Utility function to return front element in queue
  int front(queue *pt)
  {
    if (isEmpty(pt))
      {
	std::cout<<"UnderFlow!"<<std::endl;
      }
    return _data[_front];
  }

  // Utility function to add an element x in the queue
  void enQueue(queue *pt, int x)
  {
    if (size(pt) == _maxSize)
      {
	std::cout<<"OverFlow!"<<std::endl;
      }

    std::cout<<"Inserting "<<x<<" ";

    _rear = (_rear + 1)%_maxSize; // Circular queue
    _data[_rear] = x;
    _size++;

    std::cout<<"front = "<<_front<<" rear = "<<_rear<<std::endl;
  }

  // Utility function to remove element from the queue
  void deQueue(queue *pt)
  {
    if(isEmpty(pt)) // front == rear
      {
	std::cout<<"UnderFlow!"<<std::endl;
      }

    std::cout<<"Removing "<< front(pt)<<" ";

    _front = (_front + 1)%_maxSize;
    _size--;

    std::cout<<"front = "<<_front<< " rear = "<< _rear<<std::endl;
  }
};



int main()
{
  queue *pt = new queue(5);

  pt->enQueue(pt, 1);
  pt->enQueue(pt, 2);
  pt->enQueue(pt, 3);
  pt->enQueue(pt, 4);

  pt->deQueue(pt);
  pt->deQueue(pt);
  pt->deQueue(pt);
  pt->deQueue(pt);

  pt->enQueue(pt, 5);
  pt->enQueue(pt, 6);

  std::cout<<"size = "<< pt->size(pt) << std::endl;

  if(pt->isEmpty(pt))
    {
      std::cout<<"Queue is empty."<<std::endl;
    }
  else
    {
      std::cout<<"Queue is not empty."<<std::endl;
    }
  
  return 0;
}
