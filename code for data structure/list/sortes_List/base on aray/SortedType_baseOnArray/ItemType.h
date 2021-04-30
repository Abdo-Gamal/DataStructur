#pragma once
#include <fstream>
#include <iostream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{

private:
	int value;
public:
	ItemType();
	void Initialize(int a);
	RelationType compareto(ItemType)const;
	void printf(std::ostream&)const;

};

