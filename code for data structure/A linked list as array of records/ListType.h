#pragma once

	struct NodeType
	{

		int info;
		int next;
	};
	struct MemoryType {
		int free;
		NodeType* nodes;
	};

const int NUL = -1;
void InitializeMemory(int maxItems, MemoryType&);
// Initializes all memory to the free list.
// Define end-of-list symbol.
class ListType
{

		
	public :// Member function prototypes go here
		
		ListType();
		ListType(int max);
		~ListType();

	private:
		int listData;
		int currentPos;
		int length;
		int maxItems;
		MemoryType storage;
		
};





ListType::ListType(int max)
{
	length = 0;
	maxItems = max;
	storage.nodes = new NodeType[max];
	InitializeMemory(maxItems, storage);
	listData = NUL;
}
ListType::ListType()
{
	length = 0;
	maxItems = 500;
	storage.nodes = new NodeType[500];
	InitializeMemory(500, storage);
	listData = NUL;
}
ListType::~ListType()
{
	delete[] storage.nodes;
}
void InitializeMemory(int maxItems, MemoryType& storage)
{
	for (int index = 1; index < maxItems; index++)
		storage.nodes[index - 1].next = index;
	storage.nodes[maxItems - 1].next = NUL;////////////////I make . next
	storage.free = 0;
}



