#include "SortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;


#include "sortedType.h"

struct NodeType     // the decleartion in sorted type.h
{
    ItemType info;
    NodeType* next;
};

SortedType::SortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
}
bool SortedType::IsEmpty()
{
    return listData == NULL;
    //or return length==0;
}

bool SortedType::IsFull() const
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

int SortedType::GetLength() const          // const to not channge in premters
{
    return length;
}

void SortedType::MakeEmpty()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
    ResetList();
}

ItemType SortedType::GetItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);
                                   
    while (moreToSearch && !found)
    {
        switch (item.compareto(location->info))
        {
        case GREATER: location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:   found = true;
            item = location->info;
            break;
        case LESS:    moreToSearch = false;
            break;
        }
    }
    return item;
}

NodeType* SortedType::Head()
{
    return last_insert;
}

void SortedType::PutItem(ItemType item)
{
    NodeType* newNode;  	 // pointer to node being inserted
    NodeType* predLoc;  	 // trailing pointer
    NodeType* location; 	 // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    ///////////////////////////////////////////////////////////do not check if the list is full or not 
    // Find insertion point.
    while (moreToSearch)
    {
        switch (item.compareto(location->info))
        {
        case GREATER: predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case LESS:    moreToSearch = false;
            break;
        }

    }
    // Prepare node for insertion
    newNode = new NodeType;
    newNode->info = item;
    last_insert = newNode;// //////////////////////////in sheets 
    // Insert node into list.
    if (predLoc == NULL)         // Insert as first //
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
void SortedType::PutItemI(ItemType item)        // by anther away
{
    NodeType* newNode;  	 // pointer to node being inserted
    NodeType* location; 	 // traveling pointer

    location = listData;
    // Prepare node for insertion
    newNode = new NodeType;
    newNode->info = item;

    if (length==0|| item.compareto(location->info) == LESS)         // Insert as first //
    {
        newNode->next = listData;
        listData = newNode;
        length++;
        return;
    }
    // Find insertion point.
    while (  (location->next) != NULL&& item.compareto( location->next->info)!=LESS  ) {location = location->next;}

    // Insert node into list.or at last
        newNode->next = location;
        location->next = newNode;
    
    length++;
}

void SortedType::DeleteAallItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    // Locate node to be deleted.
    if (IsEmpty()) { cout << "list is empty \n"; return; }
    // else if (length == 1 && item.compareto(first->info) == EQUAL ) { tempLocation = first; first = last = NULL; } //not must nrxt line make his work
    while (listData != NULL && item.compareto(listData->info) == EQUAL)
    {
        tempLocation = listData;
        listData = listData->next;		// Delete first node.&&first->next;=null
        delete tempLocation;
        length--;
    }
    if (IsEmpty()) { listData = NULL; return; }//not important


    //uou must check if the item in list or not
    NodeType* brforewant = listData;
    location = listData->next;
    while ((location) != NULL) {

        if (item.compareto(location->info) == EQUAL) {


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

void SortedType::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    // Locate node to be deleted.
    if (item.compareto(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;	// Delete first node.
    }
    else
    {
        while (item.compareto((location->next)->info) != EQUAL)
            location = location->next;
        if ((location->next) == NULL) { cout << "item not in list \n"; return; }//imprt
        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void SortedType::ResetList()
{
    currentPos = NULL;
}

ItemType SortedType::GetNextItem()
{
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    item = currentPos->info;
    currentPos = currentPos->next;
    return item;

}

SortedType::~SortedType()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}



