#pragma once
#include"ItemType.h"

template<class ItemType>
struct   NodeType   // the decleartion in sorted type.h
{
    ItemType info;
    NodeType<ItemType>* next;       // take care
};
template<class ItemType>
class circural_list
{

public:
    circural_list();     // Class constructor	
    bool IsEmpty();
    ~circural_list();    // Class destructor

    bool IsFull() const;
    int  GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType& item, bool& found);

    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void DeleteAallItem(ItemType item);

    ItemType GetNextItem();

private:
    NodeType<ItemType>* listData;
    NodeType<ItemType>* currentPos;    // take care
    int length;

};

template<class ItemType>
inline circural_list<ItemType>::circural_list()
{
    length = 0;
    listData = NULL;


}

template<class ItemType>
inline bool circural_list<ItemType>::IsEmpty()
{
    return listData == NULL;
    //or return length==0;
}

template<class ItemType>
 circural_list<ItemType>::~circural_list()
{
    NodeType<ItemType>* tempPtr,*location;

    location = listData->next;
    while (location != listData)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }


    delete location;
}

template<class ItemType>
inline bool circural_list<ItemType>::IsFull() const
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
inline int circural_list<ItemType>::GetLength() const
{
    return length;
}

template<class ItemType>
inline void circural_list<ItemType>::MakeEmpty()
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
    ResetList();
}

template<class ItemType>
inline ItemType circural_list<ItemType>::GetItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType<ItemType>* location;

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
 

template<class ItemType>
inline void circural_list<ItemType>::ResetList()
{
    currentPos = NULL;
}

template<class ItemType>
inline ItemType circural_list<ItemType>::GetNextItem()
{
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData->next;


    item = currentPos->info;
    currentPos = currentPos->next;
    return item;

}

/////////////////////////new in class
//not function member it is helper function 
template<class ItemType>

void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found)
// Assumption: ItemType is a type that has a ComparedTo function.
// Pre: List is not empty.
// Post: If there is an element someItem whose key matches item's
// key, then found = true; otherwise, found = false.
// If found, location contains the address of someItem and
// predLoc contains the address of someItem's predecessor;
// otherwise, location contains the address of item's logical
// successor and predLoc contains the address of item's
// logical predecessor.
{
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;
    found = false;
    while (moreToSearch && !found)
    {
        if (item<location->info)
            moreToSearch = false; 
        else if (item==(location->info))
            found = true;
            else
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template<class ItemType>
void circural_list<ItemType>::PutItem(ItemType item)

{
    NodeType<ItemType>* newNode; 
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location; bool found;
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL)
    {
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;
        // If this is the last node in the list, reassign listData.
        if (  (listData->info) < item)
            listData = newNode;
    }
    else // Inserting into an empty list.
    {
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template<class ItemType>
    void circural_list<ItemType>::DeleteItem(ItemType item)
    {
        NodeType<ItemType>* location;
        NodeType<ItemType>* predLoc;
        bool found;

        FindItem(listData, item, location, predLoc, found);
        if (predLoc == location) // Only node in list?
            listData = NULL;
        else {
            predLoc->next = location->next;
            if (location == listData) // Deleting last node in list?
                listData = predLoc;
        }
            delete location;
        length--;
  }

  ///////////////////////////////sheets 

template<class ItemType>
inline void circural_list<ItemType>::DeleteAallItem(ItemType item)   ///work
{

    bool moreToSearch = true;
    NodeType<ItemType> *location= listData->next;
    NodeType<ItemType>* predLoc = listData;
    bool found = false;

    while (moreToSearch && !found&& location != listData->next)
    {
        if (item<  (location->info) )
            moreToSearch = false;

        else if (item==(location->info) ) {

            if (predLoc == location) // Only node in list?
                listData = NULL;
            else {
                predLoc->next = location->next;
                if (location == listData) // Deleting last node in list?
                    listData = predLoc;
            }

            delete location;
            length--;
         }
          else
           {
            predLoc = location;
            location = location->next;
            }
    }

}


  