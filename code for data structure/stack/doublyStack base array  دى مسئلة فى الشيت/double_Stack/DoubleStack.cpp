#include "DoubleStack.h"
//#include "ItemType.h"
#include <iostream>
using namespace std;

DoubleStack::DoubleStack()
{
    top = -1;
    max_items = 200;
    items = new ItemType[max_items];           //important /////O(1) //as we call new one time 
}
DoubleStack::~DoubleStack()
{
    delete[]items;          //important ////////////////   O(1) //as we call new one time 

}

bool DoubleStack::IsEmptyA() const        //////////////O(1)
{
    return top == -1;
}
bool DoubleStack::IsEmptyB() const        //////////////O(1)
{
    return  max_items == 200;
}
bool DoubleStack::IsFullA() const      //////////O(1)
{
    return ( top == 100- 1);      //importand   //max_item  is a attribute   not use MAX_Item whitch in  itemType 
                                                             //important   // top is index  so we make  top ==max_item-1 
}
bool DoubleStack::IsFull() const      /////////but the  declaration  /////////////////////////////////////////////////////
{
    return  ((max_items-top)==1) ;      //importand   //max_item  is a attribute   not use MAX_Item whitch in  itemType 
                                                             //important   // top is index  so we make  top ==max_item-1 
}
bool DoubleStack::IsFullB() const      //////////O(1)
{
    return (max_items == 100 + 1);      //importand   //max_item  is a attribute   not use MAX_Item whitch in  itemType 
                                                             //important   // top is index  so we make  top ==max_item-1 
}


void DoubleStack::MakeEmptyA()          //I make it 
{
    top = -1;     //////////////// O(1)

}
void DoubleStack::MakeEmptyB()          //I make it 
{
    max_items = 200;   // why 200 as we

}
void DoubleStack::Push(ItemType newItem)
{
    ItemType it;
    it.Initialize(1000);
    
    if (newItem.compareto(it)!=GREATER ) {
        if (IsFullA())
            throw FullStackA();

        top++;
        items[top] = newItem;
    }
    else {     //if (newItem.ComparedTo(it) == GREATER) 
        if (IsFullB())
            throw FullStackB();

        max_items--;
        items[max_items] = newItem;
    }


}
void DoubleStack::PopA()     
{
    if (IsEmptyA())
        throw EmptyStackA();
    top--;
}
void DoubleStack::PopB()
{
    if (IsEmptyB())
        throw EmptyStackB();
    max_items++;
}


ItemType DoubleStack::TopA()
{
    if (IsEmptyA())
        throw EmptyStackA();

    return items[top];
}
ItemType DoubleStack::TopB()
{
    if (IsEmptyB())
        throw EmptyStackB();

    return items[max_items];
}


