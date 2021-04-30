#include "QueType.h"
#include <cstddef> // For NULL.
#include <new> // For bad_alloc.
struct NodeType
{
	ItemType info;
	NodeType* next;
};
QueType::QueType() // Class constructor.
// Post: front and rear are set to NULL.
{
	front = NULL;
	rear = NULL;
} 
void QueType::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
	NodeType* tempPtr;
	while (front != NULL)
	{
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}  //after loop front ==Null
		rear = NULL;
} 
// Class destructor.
QueType::~QueType()
{
	MakeEmpty();
} 
bool QueType::IsFull() const
// Returns true if there is no room for another NodeType object
// on the free store and false otherwise.
{
	NodeType* location;
	try {
		location = new NodeType;
		delete location;
		return false;
	}
		catch(std::bad_alloc exception)
	{
		return true;
	}
} 
bool QueType::IsEmpty() const
// Returns true if there are no elements on the queue and false otherwise.
{
	return (front == NULL);
} 
void QueType::Enqueue(ItemType newItem)
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

		newNode->next = NULL;   //as it put in the last 
		if (rear == NULL)// empty list
			front = newNode;
		else
			rear->next = newNode;
		rear = newNode;
	}
} 
void QueType::Dequeue(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre: Queue has been initialized
// Post: If (queue is not empty), the front of the queue has been// removed and a copy returned in item;
// otherwise, an EmptyQueue exception is thrown.
{
	if (IsEmpty())
		throw EmptyQueue();
	else
	{
		NodeType* tempPtr;
		tempPtr = front;
		item = front->info;

		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete tempPtr;
	}
}