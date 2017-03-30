#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<T>* queueLink;
      SortedListDoublyLinked<T>* sortList;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);					//add and remove items in FIFO order
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();	//iterate over the items in sorted order

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   queueLink = new QueueLinked<T>();
   sortList = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete queueLink;
   delete sortList;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove
bool Hybrid<T>::isEmpty()
{
	//returns "TRUE" if the QueueLinked $ SortedListDoublyLinked has no data
	if (!queueLink-> isEmpty()||sortList->sze == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

void Hybrid<T>::enqueue(T* item)
{
	//Our QueueLinked||		[BACK]-Items-[FRONT]
	//Adds a T* item to our QueueLinked & SortedListDoublyLinked, in FIFO order. So front of our stack is adding an item. 
	//When enqueue is called on the Hybrid ADT, the item is enqueued on the queue, an O(1) operation. The item must also be added to the sorted list, an O(n) operation,
}

T* Hybrid<T>::dequeue()
{
	//Our QueueLinked||		[BACK]-Items-[FRONT]
	//Takes the item in the back of our QueueLinked & SortedListDoublyLinked, and returns it. 
}
ListDoublyLinkedIterator* Hybrid<T>::iterator()
{
	//iterates through SortedListDoublyLinked
}





#endif
