#include "ListType.h"
#include<iostream>
using namespace std;

// Prototypes of auxiliary functions.
void GetNode(int& nodeIndex, MemoryType& storage);
// Returns the index of a free node in nodeIndex.
void FreeNode(int nodeIndex, MemoryType& storage);
// Returns nodeIndex to storage.


int main() {

	ListType list;
	
	//list = 1;
	

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

