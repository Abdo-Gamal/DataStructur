#include "UnsortedType.h"
#include<iostream>
using namespace std;
// Implementation file for Unsorted.h


UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}
bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}
int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
        case LESS:
        case GREATER: location++;
            moreToSearch = (location < length);
            break;
        case EQUAL: found = true;
            item = info[location];
            break;
        }
    }
    return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
    length = 0;
    currentPos = -1;// take care
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
    if (IsFull()) {

        cout << "is full\n";
    }
    else {
        info[length] = item;
        length++;
    }
}
void UnsortedType::DeleteAllItem(ItemType item)
{
    bool ok = 0;
    int location = 0;
    GetItem(item, ok);
    if (ok) {

        while (location < length) {   //location < length not nust 

            if (item.ComparedTo(info[location]) == EQUAL) {

                info[location] = info[length - 1];
                length--;
                //location = 0;
            }
            else location++;
        }
    }
    else cout << "item not in the list \n";

}

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL&&location<length)
        location++;

    if (item.ComparedTo(info[location]) == EQUAL) {
        info[location] = info[length - 1];
        length--;
    }
    else {

        cout << " item type not in list sorry abdo \n";
    }
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
    if (currentPos + 1 <= length) {
        cout << "out of range\n";
    }
    else {
        currentPos++;
        return info[currentPos];
    }
}

