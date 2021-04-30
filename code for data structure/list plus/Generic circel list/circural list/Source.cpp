#include <fstream>
#include <iostream>
#include"circural_list.h"
using namespace std;

int main() {

	/*ItemType<in it(0);
	ItemType<char> it2(0);
	ItemType<double> it3(0);
*/

	circural_list<int> list;

	//cout<<list.IsFull()<<"\n";
	//cout<<list.IsEmpty()<<"\n";

	 list.PutItem(1);

	 list.PutItem(4);
	 list.PutItem(2);

	 for (int i = 0; i < list.GetLength(); i++) {

		 cout << list.GetNextItem()<<" ";
	 }

	 list.DeleteItem(1);
	 list.DeleteItem(4);
	 list.DeleteItem(2);

}
