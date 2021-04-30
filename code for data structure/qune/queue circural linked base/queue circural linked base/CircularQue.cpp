#include "CircularQue.h"



#include <cstddef> // For NULL.
#include <new> // For bad_alloc.
struct NodeType
{
	ItemType info;
	NodeType* next;
};
CircularQue::CircularQue() // Class constructor.
// Post: front and rear are set to NULL.
{
	rear = NULL;
}
void CircularQue::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
	NodeType* tempPtr,*front;
	front = rear->next;
	while (front != NULL)
	{
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}  //after loop front ==Null
	rear = NULL;
}
// Class destructor.
CircularQue::~CircularQue()
{
	MakeEmpty();
}
bool CircularQue::IsFull() const
// Returns true if there is no room for another NodeType object
// on the free store and false otherwise.
{
	NodeType* location;
	try {
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
bool CircularQue::IsEmpty() const
// Returns true if there are no elements on the queue and false otherwise.
{
	return (rear == NULL);
}
void CircularQue::Enqueue(ItemType newItem)        ///////////////////not test
// Adds newItem to the rear of the queue.
// Pre: Queue has been initialized.
// Post: If (queue is not full), newItem is at the rear of the queue;
// otherwise, a FullQueue exception is thrown.
{
	if (IsFull())
		throw FullQueue();
	else
	{
		NodeType* newNode;
		newNode = new NodeType;
		newNode->info = newItem;
		///////////////////////////////////rear->next==front
		if(rear!=NULL)  //not the first node
		newNode->next = rear->next;   //rear->next==front
		
		
			rear->next = newNode;
		rear = newNode;
	}
}
void CircularQue::Dequeue(ItemType& item)///////////////////not test
// Removes front item from the queue and returns it in item.
// Pre: Queue has been initialized
// Post: If (queue is not empty), the front of the queue has been// removed and a copy returned in item;
// otherwise, an EmptyQueue exception is thrown.
{
	if (IsEmpty())
		throw EmptyQueue();
	else
	{
		NodeType* tempPtr,*front;
		front = rear->next;

		tempPtr = front;
		item = front->info;


		if (front == rear)//if there one node 
			rear = NULL;

		else {
		   rear->next = front->next;//or (rear->next)->nexts
		}
		delete tempPtr;
	}
}