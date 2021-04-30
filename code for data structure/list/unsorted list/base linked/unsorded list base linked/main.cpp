
#include<iostream>
#include"UnsotedType.h"
using namespace std;

///////////////////////////////////////seets 
UnsortedType tail(UnsortedType& list) {////////////not work I dont know why

	UnsortedType newlist;
	list.ResetList();
	newlist.ResetList();
	list.GetNextItem();
	for (int i = 1; i < list.GetLength(); i++) {
		newlist.PutItem(list.GetNextItem());
	}

	list.ResetList();            //not important as list make reset by self
	newlist.ResetList();
	return newlist;

}
int main() {


	ItemType it1, it2, it3, tt;
	UnsortedType list;

	it1.Initialize(10);
	it2.Initialize(11);
	it3.Initialize(12);
	tt.Initialize(15);

	list.PutItem(it1);
	list.PutItem(it2);
	list.PutItem(it3);





	///////////////////////////////////////////////////////////////////////////////sheets block
	 UnsortedType list2 = list.tail();           ///// not work
	   //UnsortedType list3= tail(list);        ///// not work
	 //   cout << "length = " << list2.GetLength() << "\n";



}


