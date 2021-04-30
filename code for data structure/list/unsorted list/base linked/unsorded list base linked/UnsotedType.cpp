#include "UnsotedType.h"
#include<iostream>
using namespace std;
// This file contains the linked implementation of class
// UnsortedType.


UnsortedType::UnsortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
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
// Post: Number of items in the list is returned.
{
    return length;
}
bool UnsortedType::IsEmpty() {
    return listData == NULL;
}
void UnsortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{

    if (IsFull()) {
        cout << "is full abdo so sorry\n";
    }
    else {
        NodeType* location;			// Declare a pointer to a node

        location = new NodeType;		// Get a new node 
        location->info = item;		// Store the item in the node
        location->next = listData;	// Store address of first node 
                              //   in next field of new node
        listData = location;		// Store address of new node into
                              //   external pointer
        length++;				// Increment length of the list
    }
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
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

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{

    if (IsEmpty()) {
        cout << "is empty \n\n";

    }
    else {

        NodeType* location = listData;
        NodeType* tempLocation;

        // Locate node to be deleted.
        if (item.ComparedTo(listData->info) == EQUAL)
        {
            tempLocation = location;
            listData = listData->next;		// Delete first node.
        }
        else
        {
            while (location->next != NULL && item.ComparedTo((location->next)->info) != EQUAL)
                location = location->next;

            if (location->next == NULL) {
                cout << "item not in list sory amy abdo \n\n";
            }
            else
            {


                // Delete node at location->next
                tempLocation = location->next;
                location->next = (location->next)->next;
        delete tempLocation;
        length--;
            }
        }
    }
}

void UnsortedType::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
    return item;
}


UnsortedType::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}


////////////////////////////////sheets 
UnsortedType UnsortedType::tail()     ///not works

{
    UnsortedType newlist;
    ResetList();
    NodeType * cur = listData->next;
    while (cur != NULL)
    {
        newlist.PutItem(cur->info);
        cur = cur->next;
    }
    newlist.ResetList();
    return newlist;
}


void UnsortedType::DeleteAallItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    // Locate node to be deleted.
    if (IsEmpty()) { cout << "list is empty \n"; return; }
    // else if (length == 1 && item.compareto(first->info) == EQUAL ) { tempLocation = first; first = last = NULL; } //not must nrxt line make his work
    while (listData != NULL && item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = listData;
        listData = listData->next;		// Delete first node.&&first->next;=null
        delete tempLocation;
        length--;
    }


    //uou must check if the item in list or not
    NodeType* brforewant = listData;
    location = listData->next;
    while ((location) != NULL) {

        if (item.ComparedTo(location->info) == EQUAL) {


            tempLocation = location;
            brforewant->next = (location->next);//tempLocation->next;  if want delde lasr element  (location->next)->next;==null
            location = (location->next);//////////////import  move location to next 
                                                    // if (location->next)==last element  then (location->next)->next==null


            delete tempLocation;
            length--;
        }
        else {
            brforewant = location;
            location = location->next;
        }
    }


}