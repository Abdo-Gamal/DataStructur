#include<iostream>
#include "SortedType.h"
#include"ItemType.h"
using namespace std;

SortedType::SortedType()
{
	length = 0;
	currentPos = -1;
	MAX_ITEMS = 3;
	info = new ItemType[MAX_ITEMS];
}


void SortedType::MakeEmpty()
{
	length = 0;
	currentPos = -1;
}
bool SortedType::IsFull() const
{
	return (length == MAX_ITEMS);
}
int SortedType::GetLength() const
{
	return length;
}
int SortedType::Getmax_Item() const
{
	return MAX_ITEMS;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
	int midPoint;
	int first = 0;
	int last = length - 1;

	found = false;
	while (first <= last && !found)
	{
		midPoint = (first + last) / 2;
		switch (item.compareto(info[midPoint]))
		{
		case LESS: last = midPoint - 1;
			break;
		case GREATER: first = midPoint + 1;
			break;
		case EQUAL: found = true;
			item = info[midPoint];
			break;
		}
	}
	return item;
}
bool SortedType::GetItemI(ItemType item)// test it 
{
	bool found=false;
	int midPoint;
	int first = 0;
	int last = length - 1;

	found = false;
	while (first <= last && !found)
	{
		midPoint = (first + last) / 2;

		if ( item.compareto(info[midPoint])==LESS) {
			if (item.compareto(info[midPoint]) == EQUAL) {found = true;break;}

			last = midPoint - 1;
		}
		else {
			first = midPoint + 1;
		}

	}
	return found;
}
void SortedType::PutItem(ItemType item)
{
	bool moreToSearch;
	int location = 0;
	// i change body to isfull  to solve problem in sheets 
	if (IsFull()) 
	{
		
		cout << "is full and we will make new  dinameic list and double his size \n"; 
		MAX_ITEMS *= 2;
		ItemType* newinfo = new ItemType[MAX_ITEMS];
		newinfo = info;

		ItemType* info = new ItemType[MAX_ITEMS];
		info = newinfo;
		
		
	}

	moreToSearch = (location < length);
	while (moreToSearch)
	{
		switch (item.compareto(info[location]))
		{
		case LESS: moreToSearch = false;
			break;
		case GREATER: location++;
			moreToSearch = (location < length);
			break;
		case EQUAL: location++;
			moreToSearch = (location < length);
			break;
		}
	}
	for (int index = length; index > location; index--)
		info[index] = info[index - 1];
	info[location] = item;
	length++;
}

void SortedType::PutItemI(ItemType item) // I write it
{
	if (IsFull()) { cout << "is full \n"; return; }

	int location = 0;
	while (location < length && item.compareto(info[location]) != LESS)location++;   // location< = ?????or location< ??? ans(<)

	for (int index = length; index > location; index--)
		info[index] = info[index - 1];
	info[location] = item;
	length++;
}
void SortedType::PutItemand_throwException(ItemType item) //throw exception      //or  throws exception        
{
	bool moreToSearch;
	int location = 0;
	exception e;
	if (IsFull()) { 
			throw e;
	}

	moreToSearch = (location < length);
	while (moreToSearch)
	{
		switch (item.compareto(info[location]))
		{
		case LESS: moreToSearch = false;
			break;
		case GREATER: location++;
			moreToSearch = (location < length);
			break;
		case EQUAL: location++;
			moreToSearch = (location < length);
			break;
		}
	}
	for (int index = length; index > location; index--)
		info[index] = info[index - 1];
	info[location] = item;
	length++;
}
void SortedType::ResetList()
// Post: currentPos has been initialized.
{
	currentPos = -1;
}

ItemType SortedType::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
	if (IsEmpty())cout << " list is empty \n";
	else if (currentPos + 1 < length) {                 //
		currentPos++;
		return info[currentPos];
	}
	else cout << " you go out of list \n";
}
//SortedType::~SortedType()  // not work as a array is static not dinamic  
//{
//	delete[]info;
//}
bool SortedType::IsEmpty() const
{
	return length == 0;
}
void SortedType::DeleteItem(ItemType item)
{
	bool ok;
	GetItem(item, ok);
	if (IsEmpty()) { cout << "is empty \n"; return; }
	//if (!ok) { cout << "elsement not in list \n"; return; }

	int location = 0;
	while (item.compareto(info[location]) != EQUAL && location <= length) {
		if (location == length) { cout << "elsement not in list \n\n"; return; }   //rather than 
		location++;

	}

		for (int index = location + 1; index < length; index++)
			info[index - 1] = info[index];
		length--;
}
void SortedType::DeleteAllItem(ItemType item)
{
	bool ok;
	GetItem(item, ok);
	if (IsEmpty()) { cout << "is empty \n"; return; }
	//if (!ok) { cout << "elsement not in list \n"; return; }

	int location = 0;
	ok = 1;
	while (location < length) {
		
		if (item.compareto(info[location]) == EQUAL) {

			for (int index = location + 1; index < length; index++)
				info[index - 1] = info[index];
			length--;
			ok = 0;
		}
		else location++;
	}
	if (ok) { cout << "elsement not in list \n"; return; }

}
// in sheet 
