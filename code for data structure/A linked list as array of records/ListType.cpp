#include "ListType.h"

//
//// Prototypes of auxiliary functions.
//void GetNode(int& nodeIndex, MemoryType& storage);
//// Returns the index of a free node in nodeIndex.
//void FreeNode(int nodeIndex, MemoryType& storage);
//// Returns nodeIndex to storage.
//void InitializeMemory(int maxItems, MemoryType&);
//// Initializes all memory to the free list.
//// Define end-of-list symbol.
const int NUL = -1;

void InitializeMemory(int maxItems, MemoryType& storage)
{
	for (int index = 1; index < maxItems; index++)
		storage.nodes[index - 1].next = index;
	storage.nodes[maxItems - 1].next = NUL;////////////////I make . next
	storage.free = 0;
} 
void GetNode(int& nodeIndex, MemoryType& storage)
{
	nodeIndex = storage.free;
	storage.free = storage.nodes[nodeIndex].next;   // i go out free and put nodeIndex
} 
void FreeNode(int nodeIndex, MemoryType& storage)
{
	storage.nodes[nodeIndex].next = storage.free;
	storage.free = nodeIndex;
}


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

