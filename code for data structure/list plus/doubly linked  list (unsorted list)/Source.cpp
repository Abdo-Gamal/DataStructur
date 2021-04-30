#include "UnsortedType.h"
#include<iostream>
#include"ItemType.h"
using namespace std;


int main() {

	ItemType it1,it2,it3,tt;
	UnsortedType list;

	it1.Initialize(10);
	it2.Initialize(11);
	it3.Initialize(12);
	tt.Initialize(15);

	list.push_back(it1);
	//list.push_front(it1);
	//list.push_front(it1);
	//list.PutItemAtPos(1,it2);
	//list.PutItemAtPos(3, it2);
	//list.PutItemAtPos(3, it2);
	//list.push_back(it3);
	//list.push_back(it3);
	//list.push_back(it3);


	//cout<<"length = "<<list.GetLength()<<"\n";
	  list.print();                                     // print all element not one
	  cout << "\n";
	  //for (int i = 0; i < list.GetLength(); i++) {
		 // list.printITem(6);                                // print one  element not all 
		 // cout << " ";
	  //}
	// list.pop_front();
	 // list.pop_back();
	 // cout << "length = " << list.GetLength() << "\n";

	 // cout << "isempty = " << list.IsEmpty() << "\n";
	 // list.DeleteItem(it1);
	 /* cout << "length = " << list.GetLength() << "\n";
	  cout << "\n";
	  cout << "\n";
	  list.print();
	  list.DeleteItem(it2);
	  cout << "length = " << list.GetLength() << "\n";
	  cout << "\n";
	  cout << "\n";
	  list.print();*/
	 /* list.DeleteItem(tt);

	  cout << "length = " << list.GetLength() << "\n";
	  cout << "\n";
	  cout << "\n";
	  list.print();
	  cout << "\n";
	  cout << "\n";
	  list.DeleteItem(it3);
	  cout << "length = " << list.GetLength() << "\n";
	  cout << "\n";
	  cout << "\n";
	  list.print();
	  cout << "\n";
	  cout << "\n";*/
	/*  list.DeletePos(0);
	  cout << "length = " << list.GetLength() << "\n";
	  list.print();
	  cout << "\n";
	  cout << "\n";
	  list.DeletePos(0);
	  cout << "length = " << list.GetLength() << "\n";
	  list.print();
	  cout << "\n";
	  cout << "\n";
	  list.DeletePos(0);
	  cout << "length = " << list.GetLength() << "\n";
	  list.print();
	  cout << "\n";
	  cout << "\n";
*/
	 list.reverse();
	 list.print();
	 cout << "\n";
	 cout << "\n";
	 cout << "length = " << list.GetLength() << "\n";

}