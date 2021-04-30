
#include<iostream>
using namespace std;
#include"UnsortedType.h"
////////////////sheets blocks
 
// to know how creat fun in main
bool isThere2(ItemType it, UnsortedType list) {
	bool ok;
	list.GetItem(it, ok);
	return ok;
}
bool isThere(ItemType it, UnsortedType list) {

	for (int i = 0; i < list.GetLength(); i++) {
		ItemType temp = list.GetNextItem();
		if (it.ComparedTo(temp) == EQUAL) {
			list.ResetList();
			return 1;
		}
	}
	list.ResetList();
	return 0;

}
 void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2)
{
	for (int i = 0; i < list.GetLength(); i++) {
		ItemType it =list.GetNextItem();
		if (it.ComparedTo(item) == GREATER)list2.PutItem(it);
		else list1.PutItem(it);
	}

}

int main() {




}