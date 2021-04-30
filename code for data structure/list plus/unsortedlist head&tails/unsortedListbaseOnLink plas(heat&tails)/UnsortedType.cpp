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

UnsortedType UnsortedType::tail2()     ///not works

{
	UnsortedType newlist;
	ResetList();
	NodePtr cur = first->next;
	while (cur!=NULL)
	{
		newlist.PutItem(cur->info);
		cur=cur->next;
	}
	newlist.ResetList();
	return newlist;
}
//void UnsortedType::tail3( UnsortedType & newlist)     ///not works
//
//{
//	NodePtr cur = first->next;
//	while (cur != NULL)
//	{
//		newlist.push_front(cur->info);
//		cur = cur->next;
//	}
//
//}

UnsortedType::~UnsortedType()
{
	// Post: List is empty; all items have been deallocated.
	
		NodeType* tempPtr;

		while (first != NULL)
		{
			tempPtr = first;
			first = first->next;
			cout << "* " << tempPtr << endl;
			delete tempPtr;
		}
}

void UnsortedType::MakeEmpty()
{
	// Post: List is empty; all items have been deallocated.
	
		NodeType* tempPtr;

		while (first != NULL)
		{
			tempPtr = first;
			first = first->next;// first after last element ==null and this make isempty is work
			delete tempPtr;
		}
		length = 0;
		currentPos = NULL;             // important 
		
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
void UnsortedType::reverse()
{
	if (IsEmpty()) { cout << "is empty \n"; return; }
	NodePtr cur=NULL, perv=NULL;
	while (first->next != NULL) {  
		cur = first;
		first = first->next;
		cur->next = perv;
		perv = cur;
	}
	 first->next=cur;

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
		newnode->next = cur->next;                //to joint node after pos by newnode 
		cur->next = newnode;                      //to joint node before pos by newnode 
		length++;
	}
}

void UnsortedType::push_back(ItemType item)
{
	NodePtr location;			// Declare a pointer to a node

	location = new NodeType;		// Get a new node 
	location->info = item;		// Store the item in the node

	if (first == NULL)first = location;// to make first point to first node 
	else last->next = location;             //
	location->next = NULL; 	 // Store address of first node 
	last = location;
	//   in next field of new node
  // Store address of new node into
	//   external pointer
	length++;
}
void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
	NodeType* location;			// Declare a pointer to a node

	location = new NodeType;		// Get a new node 
	location->info = item;		// Store the item in the node
	location->next = first;	// Store address of first node 
						  //   in next field of new node
	 first = location;		// Store address of new node into
						  //   external pointer
	length++;				// Increment length of the list
}

void UnsortedType::DeleteAallItem( ItemType item)
{
	NodeType* location = first;
	NodeType* tempLocation;
	// Locate node to be deleted.
	if (IsEmpty()) { cout << "list is empty \n"; return; }
	// else if (length == 1 && item.compareto(first->info) == EQUAL ) { tempLocation = first; first = last = NULL; } //not must nrxt line make his work
	while (first !=NULL&&item.compareto(first->info) == EQUAL)
	{
		tempLocation = first;
		first = first->next;		// Delete first node.&&first->next;=null
		delete tempLocation;
		length--;
	}
	if (IsEmpty()) { last = first = NULL; return; }
	

		//uou must check if the item in list or not
		NodePtr brforewant=first;
		location = first->next;
		while ((location) != NULL ) {

			if (item.compareto(location->info) == EQUAL) {

				
				tempLocation = location;
				brforewant->next = (location->next);//tempLocation->next;  if want delde lasr element  (location->next)->next;==null
				location = (location->next);//////////////import  move location to next 
														// if (location->next)==last element  then (location->next)->next==null
				if (tempLocation == last)last = brforewant;// to make last point to last newnode
				

	           delete tempLocation;
	           length--;
			}
			else {
				brforewant = location;
				location = location->next;
			}
		}
	

}
void UnsortedType::pop_front()
{
	if (IsEmpty()) {cout << "no item \n";return;}
	NodePtr cur;cur = first;                          //to point on first node
	if (length == 1)last = NULL;            //not must as we dont use last to show if list is empty or not
	first = cur->next;                             // to make first point to second node
	delete cur;           
	length--;
}

void UnsortedType::pop_back()
{
	if (IsEmpty()) { cout << "no item\n"; return; }
	NodePtr before_last=first,temp=last;
	while (before_last!=last)before_last = before_last->next;// you can add pointer point to  before_last in the private secssion
	last = before_last;
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
	
	//else if (pos == 0&&length==1) { tempLocation = first; first = last = NULL; }//not must nrxt line make his work
	else if (pos == 0)
	{
		tempLocation = location;
		first = first->next;		// Delete first node.&&first->next;=null
	}
	else
	{

	       for (int i = 0; i < pos-1; i++) {
		      location = location->next;            //element before want to delete
	       }
		
		tempLocation = location->next;           //element want to delete
		location->next = (location->next)->next;//tempLocation->next;  
											      	// if (location->next)==last element  then (location->next)->next==null
		if (tempLocation == last)last = location;// to make last point to last newnode

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
			while ( (location->next)!=NULL &&item.compareto((location->next)->info) != EQUAL)
				location = location->next;
				
			if ( (location->next) == NULL) { cout << "item not in list \n"; return; }
			                                    // Delete node at location->next
			tempLocation = location->next;
			location->next = (location->next)->next;//tempLocation->next;  
													// if (location->next)==last element  then (location->next)->next==null
			if (tempLocation == last)last = location;// to make last point to last newnode

		}
		delete tempLocation;
		length--;
	

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
	
		if (IsEmpty()) { cout << "is empty \n";  }////important
		else {
		ItemType item ;
			if (currentPos == NULL)
				currentPos = first;
			else
				currentPos = currentPos->next;

			item = currentPos->info;
			return item;
		}
	
}
