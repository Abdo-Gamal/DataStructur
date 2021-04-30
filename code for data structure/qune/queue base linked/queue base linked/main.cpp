#include<iostream>
#include"QueType.h"

using namespace std;


int main() {
 




    QueType queue;

    queue.Enqueue('a');
    queue.Enqueue('b');
    queue.Enqueue('c');

   cout<< queue.IsEmpty();


}