#include "UnsortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;
//seets 
UnsortedType tail(UnsortedType& list) {

	UnsortedType newlist;
	list.ResetList(); 
	newlist.ResetList();
	  list.GetNextItem();
	for (int i = 1; i < list.GetLength(); i++) {
		newlist.push_front( list.GetNextItem());
	}

	list.ResetList();            //not important as list make reset by self
	newlist.ResetList();
	return newlist;

}
int main() {

	ItemType it1,it2,it3,tt;
	UnsortedType list;

	it1.Initialize(10);
	it2.Initialize(11);
	it3.Initialize(12);
	tt.Initialize(15);

	list.PutItem(it1);
	list.PutItem(it2);
	list.PutItem(it3);

	/*list.PutItemAtPos(3,it2);
	list.PutItemAtPos(3, it2);
	list.PutItemAtPos(3, it2);
	list.push_back(it1);
	list.push_back(it1);
	list.push_back(it1);*/

	//// cout << "isempty = " << list.IsEmpty() << "\n";
	// // list.DeleteItem(it1);
	// /* cout << "length = " << list.GetLength() << "\n";
	//  cout << "\n";
	//  cout << "\n";
      list.print();
	//  list.DeleteItem(it2);
	//  cout << "length = " << list.GetLength() << "\n";
	  cout << "\n";
	  cout << "\n";
	//  list.print();*/
	//  /* list.DeleteItem(tt);

	//   cout << "length = " << list.GetLength() << "\n";
	//   cout << "\n";
	//   cout << "\n";
	//   list.print();
	//   cout << "\n";
	//   cout << "\n";
	//   list.DeleteItem(it3);
	//   cout << "length = " << list.GetLength() << "\n";
	//   cout << "\n";
	//   cout << "\n";
	//   list.print();
	//   cout << "\n";
	//   cout << "\n";*/
	//   /*  list.DeletePos(0);
	//	 cout << "length = " << list.GetLength() << "\n";
	//	 list.print();
	//	 cout << "\n";
	//	 cout << "\n";
	//	 list.DeletePos(0);
	//	 cout << "length = " << list.GetLength() << "\n";
	//	 list.print();
	//	 cout << "\n";
	//	 cout << "\n";
	//	 list.DeletePos(0);
	//	 cout << "length = " << list.GetLength() << "\n";
	//	 list.print();
	//	 cout << "\n";
	//	 cout << "\n";
 //  */
	////list.reverse();
	///*list.print();
	//cout << "\n";
	//cout << "\n";
	//cout << "length = " << list.GetLength() << "\n";
	//*/
	//cout << "length = " << list.GetLength() << "\n";
	//cout << "\n";
	//list.print();
	//cout << "\n";

	//list.DeleteAallItem(it1);
	//cout << "\n";
	//cout << "length = " << list.GetLength() << "\n";
	//cout << "\n";
	//list.print();

	//NodeType* pt2=new NodeType, * first=new NodeType;       //sheets
	// UnsortedType newlist = tail(list);                               ///// not work
	//newlist.print();
	//newlist.GetLength();
	 /* list.reverse();
	    cout << "\n";
	  cout << "\n";
	  list.print();*/

	    // UnsortedType list2 = list.tail2();           ///// not work
		// list2.print();
		// UnsortedType list3= tail(list);        ///// not work
		// cout << "length = " << list3.GetLength() << "\n";
}