#pragma once

// The class definition for StackType using templates.
class FullStack
	// Exception class used by Push when stack is full.
{};
class EmptyStack
	// Exception class used by Pop and Top when stack is empty.
{};
const int MAX_ITEMS = 400;
// MaxItems.h must be provided by the user of this class.
// This file must contain the definition of MAX_ITEMS,
// the maximum number of items on the stack.
template<class ItemType>

class StackType
{
public: StackType();
	  bool IsEmpty() const;
	  bool IsFull() const;
	  void Push(ItemType item);
	  void Pop();
	  ItemType Top() const;
private:
	int top;
	ItemType items[MAX_ITEMS];

};

template<class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	return (top == MAX_ITEMS - 1);

}

template<class ItemType>
void StackType<ItemType>::Push(ItemType item)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = item;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top() const
{
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}
