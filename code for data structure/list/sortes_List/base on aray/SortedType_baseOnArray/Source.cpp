#include<iostream>
#include "SortedType.h"
#include"ItemType.h"
using namespace std;

void margesort(SortedType list1, SortedType list2, SortedType& result) {

	list1.ResetList();       //  very important 
	list2.ResetList();      //  very important

	for (int i = 0; i < list1.GetLength(); i++) {

		result.PutItem(list1.GetNextItem());
	}
	for (int i = 0; i < list2.GetLength(); i++) {

		result.PutItemI(list2.GetNextItem());
	}
	list1.ResetList();
	list2.ResetList();

}
//void margesort2(SortedType list1, SortedType list2, SortedType& result) {    /////// if result in type unsortedType
//
//	for (int i = 0; i < list1.GetLength(); i++) {
//		
//		if (list1.GetNextItem().compareto(list2.GetNextItem()) == LESS ) {
//			result.PutItem(list1.GetNextItem());
//		   }
//
//	}
//
//}


int main() {

	ItemType it,it1,it2,it3;
	it.Initialize(8);
	it1.Initialize(9);
	it2.Initialize(10);
	it3.Initialize(11);

	SortedType list3;
	SortedType list1;
	SortedType list2;

	list1.PutItem(it);
	list1.PutItem(it1);
	list1.PutItem(it2);
	

	////////////////////////////////hsetts
	/*cout << list1.Getmax_Item() << "\n";
	cout << list1.GetLength() << "\n";
	cout << list1.Getmax_Item() << "\n";
	for (int i = 0; i < list1.GetLength(); i++) {
		list1.GetNextItem().printf(cout);
		cout << " ";
	}*/
	try {
		list1.PutItemand_throwException(it2);
	}
	catch (exception e) {
		cout << " is full \n\n\n";
	}

	//list2.PutItem(it3);

	/*margesort(list1, list2, list3);
	cout << list3.GetLength() << "\n";

	for (int i = 0; i < list3.GetLength(); i++) {
		list3.GetNextItem().printf(cout);
	}*/

}
