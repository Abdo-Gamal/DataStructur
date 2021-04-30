#pragma once
#include"ItemType.h"
// Header file for Queue ADT
class FullQueue
{};
class EmptyQueue
{};
typedef char ItemType; //dont forget the ;
struct  NodeType;// this write in header file or cpp file

class CircularQue
{


public:
	CircularQue();
	~CircularQue();
	void MakeEmpty();
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	bool IsEmpty() const;
	bool IsFull() const;
private:
	NodeType* rear;

};

