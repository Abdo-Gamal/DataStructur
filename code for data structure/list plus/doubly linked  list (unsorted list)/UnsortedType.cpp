#include "UnsortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;
typedef NodeType* NodePtr;



UnsortedType::UnsortedType()
{
	first = last = NULL;
	length = 0;
}

UnsortedType::~UnsortedType()
{
	// Post: List is empty; all items have been deallocated.
	
		NodeType* tempPtr;

		while (first != NULL)
		{
			tempPtr = first;
			first = first->next;
			delete tempPtr;
		}
}

void UnsortedType::MakeEmpty()
{
	// Post: List is empty; all items have been deallocated.
	{
		NodeType* tempPtr;

		while (first != NULL)
		{
			tempPtr = first;
			first = first->next;
			delete tempPtr;
		}
		length = 0;
	}

}

bool UnsortedType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}


int UnsortedType::GetLength() const
{
	return length;
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
	bool moreToSearch;
	NodeType* location;

	location = first;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.compareto(location->info))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			item = location->info;
			break;
		}
	}
	return item;
}

bool UnsortedType::IsEmpty()
{
	return first == NULL;
	//or return length==0;
}
void UnsortedType::print()
{
	NodePtr cur;
	cur = first;
	while (cur!=NULL)
	{
		cur->info.printf(cout);;
		cur = cur->next;
	}
}
void UnsortedType::Revarse_print()
{
	NodePtr cur;
	cur = last;
	while (cur != NULL)
	{
		cur->info.printf(cout);
		cout << " ";
		cur = cur->prev;
	}
	cout << "\n";
}


void UnsortedType::printITem(int pos)
{
	if (pos<0 || pos>length) { cout << " out of range \n"; return; }
	NodePtr cur;
	cur = first;
	int cnt = 0;
	while (cnt < pos) {cur = cur->next; cnt++;}
	cur->info.printf(cout);;
}
void UnsortedType::push_front(ItemType item) 
// item is in the list; length has been incremented.
{
	NodePtr location;			// Declare a pointer to a node

	location = new NodeType;		// Get a new node 
	location->info = item;		// Store the item in the node

	if (first == NULL)last = location;
	 location->next = first; 	// Store address of first node 
	 location->prev = NULL; 	
	 if (first != NULL) first->prev = location;
		                       //   in next field of new node
	first = location;		// Store address of new node into
						  //   external pointer
	length++;				// Increment length of the list
}
void UnsortedType::PutItemAtPos(int pos, ItemType item)
{

	if (pos<0 || pos>length) { cout << "out of range \n"; }
	else if (pos == 0)push_front(item);
	else if (pos == length)push_back(item);
	else {

	  NodePtr newnode = new NodeType;         // dont forget new ...//nodePtr is #
	   newnode->info = item;

		NodePtr cur = first;
		for (int i = 0; i < pos - 1; i++)
			cur = cur->next;

		newnode->prev = cur;
		newnode->next = cur->next;

		cur->next = newnode;                      //to joint node before pos by newnode 
		newnode->next->prev = newnode;          //to joint node after pos by newnode 
		length++;
	}
}
void UnsortedType::push_back(ItemType item)
{
	NodePtr location;			// Declare a pointer to a node

	location = new NodeType;		// Get a new node 
	location->info = item;		// Store the item in the node

	if (first == NULL)first = location;// to make first point to first node 
	else last->next = location;  
	location->prev = last;
	location->next = NULL; 	// Store address of first node 
	last = location;
	//   in next field of new node
  // Store address of new node into
	//   external pointer
	length++;
}

void UnsortedType::pop_front()
{
	if (IsEmpty()) {cout << "no item \n";return;}
	NodePtr cur;cur = first;                          //to point on first node
	if (length == 1)last = NULL;            //not must as we dont use last to show if list is empty or not
	first = cur->next;                             // to make first point to second node or null if lenth ==1
	first->prev = NULL;
	delete cur;           
	length--;
}

void UnsortedType::pop_back()
{
	if (IsEmpty()) { cout << "no item\n"; return; }
	NodePtr  temp=last;
	last = last->prev;                       
	last->next = NULL;
	delete temp;        // make node empty
	if (length == 1) {first = NULL; last = NULL;}
	length--;
}
void UnsortedType::DeletePos(int pos)
{
	NodeType* location = first;
	NodeType* tempLocation;
	// Locate node to be deleted.
	if (pos<0&&pos>=length) { cout << "out of range  \n"; return; }

	if (IsEmpty()) { cout << "list is empty \n"; return; }
	
	else if (pos == 0&&length==1) { tempLocation = first; first = last = NULL; }//not must nrxt line make his work
	else if (pos == 0)
	{
		tempLocation = location;
		first = first->next;		// Delete first node.&&first->next;=null
	}
	else
	{

	       for (int i = 0; i < pos; i++) {        ////////////////  i<pos  not i<pos-1
		      location = location->next;            //element before want to delete
	       }
		
		tempLocation = location    ;           //element want to delete
		(location->next)->prev = (location->prev);          //tempLocation->next;  
		(location->prev)->next = (location->next);				      	// if (location->next)==last element  then (location->next)->next==null
		if (tempLocation == last)last = location;// to make last point to last newnode

	}
	delete tempLocation;
	length--;


}
void UnsortedType::DeleteItem(ItemType item)
{
	     // Pre:  item's key has been initialized.
         //       An element in the list has a key that matches item's.
        // Post: No element in the list has a key that matches item's.
	
		NodeType* location = first;
		NodeType* tempLocation;
		// Locate node to be deleted.
	  if (IsEmpty()) { cout << "list is empty \n"; return; }
	   // else if (length == 1 && item.compareto(first->info) == EQUAL ) { tempLocation = first; first = last = NULL; } //not must nrxt line make his work
	    else if( item.compareto(first->info) == EQUAL)
		{
			tempLocation = location;
			first = first->next;		// Delete first node.&&first->next;=null
	    }
		else
		{

		  //uou must check if the item in list or not
			while ( (location)!=NULL &&item.compareto(location->info) != EQUAL)// location now equel to element want to deldet not element before
				location = location->next;
				
			if ( (location) == NULL) { cout << "item not in list \n"; return; }//this mean that locat go out of list (ans this is reason for go out of while);
			                                            
			else if( location->next == NULL) //this mean that you want delete last elements
			{
				pop_back();
			}
			else {
				tempLocation = location;           //element want to delete
				(location->next)->prev = (location->prev);          //tempLocation->next;  
				(location->prev)->next = (location->next);				      	// if (location->next)==last element  then (location->next)->next==null
				if (tempLocation == last)last = location;// to make last point to last newnode
			}
		
		}
		delete tempLocation;
		length--;
	

}
int   UnsortedType::serche(ItemType item)
{
	NodePtr cur;
	cur = first;
	int pos = 0;
	while (cur != NULL)
	{
		if ((cur->info).compareto(item)) {
			return pos;
		}
		cur = cur->next;
		pos++;
	}
	return -1;
}



void UnsortedType::ResetList()
{
	// Post: Current position has been initialized.
	
		currentPos = NULL;
	
}

ItemType UnsortedType::GetNextItem()
{
	// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
	
		ItemType item;
		if (currentPos == NULL)
			currentPos = first;
		else
			currentPos = currentPos->next;
		item = currentPos->info;
		return item;
	
}
