#include <iostream>
#include <vector>

// Data structure for queue

class queue
{
  int *data;  //array to store queue elements
  int maxSize;//maximum capacity of the queue
  int front;  //front points to front element in the queue
  int rear;   //rear points to last element in the queue
  int size;   //current capacity of the queue
public:
  queue(int size)
  {
    data = new int[size]();
    maxSize = size;
    front = 0;
    rear = -1;
    size = 0;
  }
  // Utility function to return the size of the queue
  int size(queue *pt)
  {
    return size;
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
    return data[front];
  }

  // Utility function to add an element x in the queue
  void enQueue(queue *pt, int x)
  {
    if (size(pt) == maxSize)
      {
	std::cout<<"OverFlow!"<<std::endl;
      }

    std::cout<<"Inserting "<<x<<std::endl;

    rear = (rear + 1)%maxSize; // Circular queue
    data[rear] = x;
    size++;

    std::cout<<"front = "<<front<<", rear"<<rear<<std::endl;
  }

  // Utility function to remove element from the queue
  void deQueue(queue *pt)
  {
    if(isEmpty(pt)) // front == rear
      {
	std::cout<<"UnderFlow!"<<std::endl;
      }

    std::cout<<"Removing "<< front
  

  
};



int main()
{

  return 0;
}
