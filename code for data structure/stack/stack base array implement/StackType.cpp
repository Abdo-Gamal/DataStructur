
// File: StackType.cpp

#include "StackType.h"

#include <iostream>
using namespace std;

StackType::StackType()
{
    top = -1;
    max_items = 100;
    items = new ItemType[max_items];           //important /////O(n) 
}
StackType::~StackType()
{
    delete []items;          //important //////////////// O(n)  

}

StackType::StackType(int max)
{
    top = -1;
    max_items = max;
    items = new ItemType[max_items];
}

bool StackType::IsEmpty() const        //////////////O(1)
{
    return (top == -1);
}
bool StackType::IsFull() const      //////////O(1)
{
    return (top == max_items - 1);      //importand   //max_item  is a attribute   not use MAX_Item whitch in  itemType 
                                        //important   // top is index  so we make  top ==max_item-1 
} 

void StackType::MakeEmpty()          //I make it 
{
   top = -1;     //////////////// O(1)

   
}


void StackType::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

void StackType::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top--;
}


ItemType StackType::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}

//sheets requrement

ItemType StackType::PopI()
{
    if (IsEmpty() )
        throw EmptyStack();

    ItemType item;
    item= items[top];
    return item;
}

