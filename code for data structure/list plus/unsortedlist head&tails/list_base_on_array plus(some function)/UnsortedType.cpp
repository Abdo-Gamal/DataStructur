#include "UnsortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;


UnsortedType::UnsortedType(int size )
{
	if (size <= 0)	MAX_ITEMS = 10;
	else  MAX_ITEMS = size;
	info=new ItemType[MAX_ITEMS];
	
	length = 0;
	currentPos = -1;
}

UnsortedType::~UnsortedType()
{
	delete[]info;
}


void UnsortedType::IsertElement(ItemType newItem, int pos)
{
	if (IsFull())cout << "list is full \n";        // see how we call
	else if (pos<0 || pos> length) cout << "out of range \n";
	for (int i = length ; i > pos; i--) 
	{
		info[i] = info[i - 1];

	}
	info[pos] = newItem;
	length++; // to determinde the pos i will put in it 
}

void UnsortedType::IsertElementNODoublecate(ItemType item, int pos)
{
	if (IsFull())cout << "list is full \n";        // see how we call

	else if (pos < 0 || pos >length)cout << "out of range ....!\n";
	//bool ok; GetItem(item, ok);
	else {
		if (search(item) == -1) IsertElement(item, pos);
		else cout << "item in the list \n";
	}
}

void UnsortedType::Update(ItemType item, int pos)
{
	if (pos < 0 || pos >= length)cout << "out of liset\n";
	else {
		info[pos] = item;

	}
}

ItemType UnsortedType::getElement( int pos)
{
	if (pos < 0 || pos >=length)cout << "out of liset....!\n";
	else {
		return info[pos];
	}
}

void UnsortedType::prindElment(int pos)
{
	if (pos < 0 || pos >=length)cout << "out of liset\n";
	else  info[pos].printf(cout);
}

void UnsortedType::PutItemAtEnd(ItemType item)
{
	// Post: item is in the list.
	if (IsFull())cout << " list is full\n";
	else {
		info[length] = item;
		length++;
	}
}
void UnsortedType::MakeEmpty()     //why not make current =-1;
{
	// Post: list is empty.
	length = 0;
	currentPos = -1;
}


void UnsortedType::RemoveByIndex(int pos )
{
	if (IsEmpty())cout << "list is empty \n";
	else if (pos<0 || pos>=length)cout << "out the range \n";
	else {
		for (int i = pos; i < length; i++) {
			info[i] = info[i + 1];
		}
		length--;
	}
}
void UnsortedType::DeletefirstItem(ItemType item)
{
	    //Pre:  item's key has been initialized.
		//       An element in the list has a key that matches item's.
		// Post: No element in the list has a key that matches item's.
	bool ok = 0;
	int location = 0;
	GetItem(item,ok);
	if (ok) {
		while (location < length && item.compareto(info[location]) != EQUAL)     //location < length not nust 
			location++;

		info[location] = info[length - 1];
		length--;
	}
	else cout << "item not in the list \n";
}

void UnsortedType::DeleteAllItem(ItemType item) 
{
	bool ok = 0;
	int location = 0;
	GetItem(item, ok);
	if (ok) {

		while (location < length ) {   //location < length not nust 

			if (item.compareto(info[location]) == EQUAL) {

				info[location] = info[length - 1];
				length--;
				//location = 0;
			}
			else location++;
		}
	}
	else cout << "item not in the list \n";

}
int UnsortedType::search(ItemType item){
	ItemType curItem;
       for(int i=0;i<length;i++)         // IF you put in dent only make  lenth instase of MAX_ITEMS
       {
		   curItem = GetNextItem();
		   if (item.compareto(curItem) == EQUAL) {
			   ResetList();
			   return i;
		   }

       }
	   ResetList();
	  return -1;
}



bool UnsortedType::IsFull() const
{

	return (length == MAX_ITEMS);
}

bool UnsortedType::IsEmpty() const
{
	return length == 0;
}

int UnsortedType::GetLength() const
{

	return length;
}

bool UnsortedType::GetItem(ItemType item, bool& found)
{
	  //Pre:  Key member(s) of item is initialized.
		// Post: If found, item's key matches an element's key then return 1 else retun 0 
	
	bool moreToSearch; 
	int location = 0;
	found = false;
	// moreToSearch = (location < length);
	while ( (location < length)  && !found)
	{
		if (item.compareto(info[location]) != EQUAL)location++;
		else {found = 1;}

	}
	return found;
}


void UnsortedType::ResetList()
{
	// Post: currentPos has been initialized.
	currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
	// Pre:  ResetList was called to initialized iteration.
	// No transformer has been executed since last call.
	// currentPos is defined
	if (IsEmpty())cout << " list is empty \n";
	else if (currentPos+1 < length) {                 //
		currentPos++;
		return info[currentPos];
	}
	else cout << " you go out of list \n";

}

int UnsortedType::GetMAX_ITEMS()
{
	return MAX_ITEMS;
}
