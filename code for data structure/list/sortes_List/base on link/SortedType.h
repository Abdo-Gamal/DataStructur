#pragma once
#include<iostream>
#include"ItemType.h"
using namespace std;


// Header file for Sorted List ADT.  
struct NodeType;

class SortedType
{
public:
    SortedType();     // Class constructor	
	bool IsEmpty();
    ~SortedType();    // Class destructor

    bool IsFull() const;
    int  GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType& item, bool& found);
    NodeType* Head();              // requrement in sheets4   ans spscification in 

    void PutItem(ItemType item);
	void PutItemI(ItemType item);
	void DeleteAallItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();

private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
    NodeType* last_insert;   // reqirent in seets  

};

