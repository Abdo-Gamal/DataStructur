#pragma once
#include "ItemType.h" 
#include<iostream>
using namespace std;
//const int MAX_ITEMS = 100;
//int MAX_ITEMS=10;
class UnsortedType
{

public:

	//========================================================================= Constructor
	UnsortedType(int );
	~UnsortedType();

	//==================================================================================transeormers  make chanfe
	void RemoveByIndex(int );
	void IsertElement(ItemType, int pos);
	void IsertElementNODoublecate(ItemType, int pos);
	void Update(ItemType, int pos);
	ItemType getElement( int pos);
	void prindElment(int pos);

	// Function: Returns the list to the empty state.
	//pre:none
	// Post:  List is empty.
	void MakeEmpty();
	// Function: Adds item to list.
	// Pre:  List has been initialized.
	//       List is not full.
	//       item is not in list.
	// Post: item is in list.
	void PutItemAtEnd(ItemType item);
	// Function: Deletes the element whose key matches item's key.
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	//       One and only one element in list has a key matching item's key.
	// Post: No element in list has a key matching item's key.

	void DeletefirstItem(ItemType item);
	void DeleteAllItem(ItemType item);
	//================================================================================observer return
	int search(ItemType item);
	//Function:Divides list into two lists according to the key of item
	//Preconditions: list has been initialized and is not empty.
	//Postconditions:list1 contains all the items of list whose keys are less than or
	//equal to item’s key;
	///list2 contains all the items of list whose keys are greater than	item’s key.
	void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1,	UnsortedType& list2);

	// Function:  Determines whether list is full.
	// Pre:  List has been initialized.
	// Post: Function value = (list is full)
	bool IsFull() const;

	bool IsEmpty() const;

	// Function: Determines the number of elements in list.
	// Pre:  List has been initialized.
	// Post: Function value = number of elements in list
	int GetLength() const;

	// Function: Retrieves list element whose key matches item's key (if
	//           present).
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	//       item's key, then found = true and someItem is returned.
	// 	 otherwise found = false and item is returned.
	//       List is unchanged.
	bool GetItem(ItemType, bool&);

	//============================================================================itrator

	// Function: Initializes current position for an iteration through the list.
	// Pre:  List has been initialized.
	// Post: Current position is prior to list.
	void ResetList();
	// Function: Gets the next element in list.
	// Pre:  List has been initialized and has not been changed since last call.
	//       Current position is defined.
	//       Element at current position is not last in list.
	//	     
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.
	ItemType GetNextItem();
	int GetMAX_ITEMS();

private:
	int length;
	//ItemType info[MAX_ITEMS];// we can make it dynamic ans determind size in the rentime int*info=new[Maxsize];
	ItemType* info;
	int MAX_ITEMS;
	int currentPos;
};

