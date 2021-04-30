#pragma once
//#include "sortedType.h"
#include<iostream>
using namespace std;

template <class ItemType>
struct NodeType {
	ItemType info;
	NodeType<ItemType>* next,*prev;

};
template <class ItemType>
class sortedType
{


public:
	void printITem(int pos);
	sortedType();
	// Constructor
	~sortedType();
	// Destructor
	void MakeEmpty();
	// Function: Returns the list to the empty state.
	// Post:  List is empty.
	bool IsFull() const;
	// Function:  Determines whether list is full.
	// Pre:  List has been initialized.
	// Post: Function value = (list is full)

	int GetLength() const;
	// Function: Determines the number of elements in list.
	// Pre:  List has been initialized.
	// Post: Function value = number of elements in list

	ItemType GetItem(ItemType& item, bool& found);
	// Function: Retrieves list element whose key matches item's key (if
	//           present).
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	//       item's key, then found = true and someItem is returned;	
	// 	 otherwise found = false and item is returned.
	//       List is unchanged.

	bool IsEmpty();

	void putItem(ItemType item);
	// Function: Adds item to list.
	// Pre:  List has been initialized.
	//       List is not full.
	//       item is not in list.
	// Post: item is in list.

	void DeleteItem(ItemType item);

	// Function: Deletes the element whose key matches item's key.
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	//       One and only one element in list has a key matching item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Function: Initializes current position for an iteration through the list.
	// Pre:  List has been initialized.
	// Post: Current position is prior to list.

	ItemType GetNextItem();
	// Function: Gets the next element in list.
	// Pre:  List has been initialized and has not been changed since last call.
	//       Current position is defined.
	//       Element at current position is not last in list.
	//	     
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.




private:
	NodeType<ItemType>* listData, * currentPos; 
	int length;


};




template<class ItemType>
 sortedType<ItemType>::sortedType()
{
	listData= NULL;
	length = 0;
}
 template<class ItemType>
 sortedType<ItemType>::~sortedType()
{
	// Post: List is empty; all items have been deallocated.

	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
 		delete tempPtr;
	}
}
 template<class ItemType>
void sortedType< ItemType>::MakeEmpty()
{
	// Post: List is empty; all items have been deallocated.
	{
		NodeType<ItemType>* tempPtr;

		while (listData != NULL)
		{
			tempPtr = listData;
			listData = listData->next;
			delete tempPtr;
		}
		length = 0;
	}

}
template<class ItemType>
bool sortedType< ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	NodeType<ItemType>* location;
	try
	{
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<class ItemType>
int sortedType< ItemType>::GetLength() const
{
	return length;
}
template<class ItemType>
ItemType sortedType<ItemType>::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (location != NULL && !found&& item != (location->info))
	{
		 location = location->next;
		if (item != (location->info))
		   found = true;
		
	}
	return item;
}
template<class ItemType>
bool sortedType< ItemType>::IsEmpty()
{
	return listData == NULL;
	//or return length==0;
}
template<class ItemType>

void sortedType< ItemType>::putItem(ItemType item)
// item is in the list; length has been incremented.
{
	NodeType<ItemType>* location,*newNode;			// Declare a pointer to a node
	bool found;
	newNode = new NodeType<ItemType>;		// Get a new node 
	newNode->info = item;		// Store the item in the node

	if (listData != NULL) {

		FindItem(listData, item, location, found);

		if (location->next == NULL&&location->info <=item) { // add at last postion
			newNode->next = NULL;
			newNode->prev = location;
			location->next = newNode;
		}
		else {

			if (listData->info >= item) {//put in first posation
				newNode->prev = NULL;
				newNode->next = location;
				location->prev = newNode;





	
			}
			else {  //put in middel
				newNode->prev = (location->prev);
				newNode->next = location;

				(location->prev)->next = newNode;
				location->prev = newNode;
			}
		}

	}
	else {//list is empty
		
		listData = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	
	
	length++;				// Increment length of the list


}


template<class ItemType>

void sortedType<ItemType>::DeleteItem(ItemType item)
{
	// Pre:  item's key has been initialized.
	//       An element in the list has a key that matches item's.
   // Post: No element in the list has a key that matches item's.

	NodeType<ItemType>* tempLocation;
		NodeType<ItemType>* location;
	// Locate node to be deleted.
	if (IsEmpty()) { cout << "list is empty \n"; return; }
	else if (item==(listData->info) )//remove first node
	{
		location = listData;

		tempLocation = location;
		listData = listData->next;		// Delete first node.&&first->next;=null
		if(listData!=NULL)( listData)->prev = NULL;
		length--;

	}
	else
	{
		bool found;
		FindItem(listData, item, location, found);

		//you must check if the item in list or not
		
		if (found == true) {

				tempLocation = location;           //element want to delete
			 if (location->next == NULL) //this mean that you want delete last elements
			{
			   location->next = NULL;

			}
			else {// delete fom midle
				(location->next)->prev = (location->prev);          //tempLocation->next;  
				(location->prev)->next = (location->next);				      	// if (location->next)==last element  then (location->next)->next==null
			}
		    delete tempLocation;
		   length--;
		}
		else
		{
			cout << "item not in list \n";
		}
	}
	}
	


/////////////////////////////////this is not member function this is call helper or aux.....
template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item,NodeType<ItemType>*& location, bool& found)// why pointer sent by refrance
	// Assumption: ItemType is a type that has a ComparedTo function.
	// Pre: List is not empty.
	// Post: If there is an element someItem whose key matches item's
	// key, then found = true; otherwise, found = false.
	// If found, location contains the address of someItem;
	// otherwise, location contains the address of the logical
	// successor of item.
{
	bool moreToSearch = true;
	location = listData;
	found = false; 
	while (moreToSearch && !found)
	{
		if (item<(location->info) )
			moreToSearch = false;
		else if (item==(location->info))
			found = true;
		else
		{
			////i change it 
			if (location->next != NULL) {// to not go out from list
				location = location->next;
			}
			else {
				moreToSearch = false;
			}
			//moreToSearch = (location != NULL);
		}
	}
}

///////////////////////////////////////////////

template<class ItemType>

void sortedType< ItemType>::ResetList()
{
	// Post: Current position has been initialized.

	currentPos = NULL;

}
template<class ItemType>

ItemType sortedType< ItemType>::GetNextItem()
{
	// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.

	ItemType item;
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;
	return item;

}

