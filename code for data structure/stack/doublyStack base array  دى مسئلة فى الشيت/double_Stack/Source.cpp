#include <iostream>
#include "DoubleStack.h"
using namespace std;



int main() {

	ItemType it1, it2, it3, it4;
	DoubleStack stack ;
	it1.Initialize(222);
	it1.Initialize(2001);

	cout<<stack.IsEmptyA()<<"\n";
	cout << stack.IsEmptyB() << "\n";
	stack.Push(it1);
	stack.Push(it2);

	cout << stack.IsEmptyA() << "\n";
	cout << stack.IsEmptyB() << "\n";




}