#include <fstream>
#include <iostream>
#include<fstream>
#include"ItemType.h"
#include"UnsortedType.h"
using namespace std;

//solve sheets
 //to know how creat fun in main
//bool isThere2(ItemType it, UnsortedType list) {
//	bool ok;
//	list.GetItem(it, ok);
//	return ok;
//}
//bool isThere(ItemType it, UnsortedType list) {
//
//	for (int i = 0; i < list.GetLength(); i++) {
//		ItemType temp = list.GetNextItem();
//		if (it.compareto(temp) == EQUAL) {
//			list.ResetList();
//			return 1;
//		}
//	}
//	list.ResetList();
//	return 0;
//
//}
 /*void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2)
{
	for (int i = 0; i < list.GetLength(); i++) {
		if (list.getElement(i).compareto(item) == GREATER)list2.PutItemAtEnd(list.getElement(i));
		else list1.PutItemAtEnd(list.getElement(i));
	}

}*/


int main() {
	int n;
	cout << "enter size of arr\n";
	cin >> n;
	UnsortedType list(n);
	ItemType temp;

	for (int i = 0; i <list.GetMAX_ITEMS(); i++) {
	  temp.Initialize(22);
	 list.IsertElementNODoublecate(temp,0);
	 // list.IsertElement(temp,i);
	  // list.PutItemAtEnd(temp);
	 
	}
	cout << list.GetLength() << "\n\n";
	//for (int i = 0; i < n; i++) {
	//	list.getElement(i).printf(cout);
	//	cout << " ";
	//}
	//cout << "\n\n";

	//ItemType it;
	//it.Initialize(22);
	//list.DeleteAllItem(it);
	//cout << list.GetLength() << "\n\n";
	//for (int i = 0; i < list.GetLength(); i++) {
	//	list.getElement(i).printf(cout);
	//	cout << " ";
	//}
	ItemType it;
	int pos = 0;
	it.Initialize(22);
	bool ok;

	cout << "empty "<<list.IsEmpty()<<"\n";
	cout <<"full "<< list.IsFull()<<"\n";
	cout << "GetItem "<<list.GetItem(it, ok)<<"\n";
	cout << "item in index 0 = ";
	list.getElement(0).printf(cout);
	cout << "\n";
	cout <<"search for 22 "<< list.search(it)<<"\n";
	cout << "lenth "<<list.GetLength() << "  and all item \n\n";
	for (int i = 0; i < list.GetLength(); i++) {
		list.getElement(i).printf(cout);
		cout << " ";
	}
	cout << "\n";
	 list.ResetList();
	 list.MakeEmpty();

	//list.DeletefirstItem(it);
	cout <<" lengh "<< list.GetLength() << "*\n\n";
	for (int i = 0; i < list.GetLength(); i++) {
		list.getElement(i).printf(cout);
		cout << " ";
	}
	cout << "\n";
	//cout<<isThere(it,list);
	
}