#include "sortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;


int main() {

	sortedType<int> list;
	cout<<list.IsEmpty()<<"\n";
	cout<<list.GetLength()<<"\n";
	cout<<list.IsFull()<<"\n";

	list.putItem(1);
	list.putItem(4);
	 list.putItem(2);
	cout << list.GetLength() << "\n";

	list.ResetList();               // very important
	for (int i = 0; i < list.GetLength(); i++) {
		cout << list.GetNextItem()<<" ";

	}
	//list.ResetList();               // very important
	//list.DeleteItem(5);
	list.DeleteItem(1);
	list.DeleteItem(4);
	list.DeleteItem(2);
	//cout << list.GetLength() << "\n";
	list.ResetList();               // very important
	for (int i = 0; i < list.GetLength(); i++) {
		cout << list.GetNextItem() << " ";

	}

}