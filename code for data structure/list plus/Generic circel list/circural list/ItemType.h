#pragma once
#include <fstream>
#include <iostream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
//template<class itemtype>
class ItemType 
{
private:
	int value;
public:
	ItemType();
	ItemType(int item);
	void Initialize(int a);
	RelationType compareto(ItemType)const;
	void printf(std::ostream&)const;
};






using namespace std;

ItemType::ItemType()
{
	value = 0;

}

void ItemType::Initialize(int a)
{
	value = a;
}

RelationType ItemType::compareto(ItemType otherItem) const
{
	if (value < otherItem.value)return LESS;
	else if (value > otherItem.value) return GREATER;
	else return EQUAL;
}

//to pring on file or consl
void ItemType::printf(std::ostream& out) const
{
	// pre:  out has been opened.
   // post: value has been sent to the stream out.
	out << value;
}

