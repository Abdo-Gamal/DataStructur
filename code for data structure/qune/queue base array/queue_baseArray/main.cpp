#include <iostream>
using namespace std;
#include"QueType.h"
#include"CountedQueType.h"

////////////////////////////////////////////////sheets
ItemType front(QueType& q) {   // not work if I go out the &  I dont know why
	ItemType item;
	q.Dequeue(item);

	QueType tepmque;
	tepmque.Enqueue(item);

	while (!q.IsEmpty()) {
		ItemType it;
		q.Dequeue(it);
		tepmque.Enqueue(it);

	}
	while (!tepmque.IsEmpty()) {
		ItemType it;
		tepmque.Dequeue(it);
		q.Enqueue(it);

	}

	return item;
}


int GetLength(QueType &q) {   // not work if I take out the &  I dont know why

	QueType tepmque;
		ItemType it;
	int length = 0;
	while (!q.IsEmpty()) {
		length++;
		q.Dequeue(it);
		tepmque.Enqueue(it);
	}
	while (!tepmque.IsEmpty()) {
		ItemType it;
		tepmque.Dequeue(it);
		q.Enqueue(it);
	}

	return length;
}
void ReplaceItem(QueType&queue, int oldItem, int newItem) {
	/////////////////////////// itemture ==int
	QueType tem_que, loop_que;
	while (!queue.IsEmpty())
	{
		ItemType it;
		queue.Dequeue(it);
		if (it == oldItem)tem_que.Enqueue(newItem);
		else tem_que.Enqueue(it);
	}
	while (!tem_que.IsEmpty())
	{
		ItemType it;
		tem_que.Dequeue(it);
		queue.Enqueue(it);
	}
	

} // not work if I take out the &  I dont know why
bool Identical(QueType &queue, QueType& queue1)
{
	QueType qu1, qu2;

	bool ok = 1;
	while (!queue.IsEmpty() && !queue1.IsEmpty())
	{
		ItemType it1, it2;
		queue.Dequeue(it1);
		queue1.Dequeue(it2);

		if (it1!= it2) {
			ok = 0;
		}
		qu1.Enqueue(it1);
		qu2.Enqueue(it2);

	}
	if (!queue.IsEmpty() || !queue1.IsEmpty())ok = false;

	queue1.MakeEmpty();
	queue.MakeEmpty();
	while (!qu1.IsEmpty()) {
		ItemType it;
		qu1.Dequeue(it);
		queue.Enqueue(it);
	}
	while (!qu2.IsEmpty()) {
		ItemType it;
		qu2.Dequeue(it);
		queue1.Enqueue(it);
	}

	return ok;

}   // not work if I take out the &  I dont know why
int main() {


	//////////////////queue block

	QueType que;

	que.Enqueue(1);
	que.Enqueue(2);
	que.Enqueue(3);
	cout << que.IsFull()<<"\n\n";
	cout << que.IsEmpty() << "\n\n";

	//////////////////countqueue block

	CountedQueType Cque(500);  /////////take care that the take pramters constractor

	Cque.Enqueue(1);
	Cque.Enqueue(2);
	Cque.Enqueue(3);
	//cout << Cque.GetLength()<<"\n\n\n\n";

	////////////////////////sheets bloks
	   cout<<front(Cque)<<"\n\n";           // take care i send countqueque not queType 
	  // cout << Cque.GetLength() << "\n\n\n\n";
	  // cout << GetLength (Cque)<< "\n\n";
	  // ReplaceItem(Cque, 1, 4);

	  /* while (!Cque.IsEmpty()) {
		   ItemType it;
		   Cque.Dequeue(it);
		   cout << it << " ";
	   }*/
	  cout<< Identical(Cque, que)<<"\n";


}
