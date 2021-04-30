#pragma once
#include <iostream>
#include"ItemType.h"
using namespace std;
//typedef int ItemType;
//   
   //   Class specification for Stack ADT in file Stack1.h

class FullStackA  // Exception class thrown by Push when stack is full.
{
public:

    FullStackA() { cout << " stack A overflow \n"; }

};
class FullStackB  // Exception class thrown by Push when stack is full.
{
public:

    FullStackB() { cout << " stack B overflow \n"; }

};

class EmptyStackA
    // Exception class thrown by Pop and Top when stack is emtpy.
{
public:
   EmptyStackA() { cout << " stack A underflow \n"; }

};
class EmptyStackB
    // Exception class thrown by Pop and Top when stack is emtpy.
{
public:

     EmptyStackB() { cout << " stack B underflow \n"; }

};
class DoubleStack
{


public:

    DoubleStack();
    ~DoubleStack();
    bool IsEmptyA() const;
    // Class constructor.
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsEmptyB() const;
    bool IsFullA() const;
    bool IsFullB() const;

    void MakeEmptyA();

    void MakeEmptyB();
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //     otherwise, newItem is at the top of the stack.
    void PopA();
    void PopB();

    // Function: Removes top item from the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //     otherwise, top element has been removed from stack.
    ItemType TopA();
    ItemType TopB();

    // Function: Returns a copy of top item on the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //     otherwise, top element has been removed from stack.


private:
    int top;
    int max_items;
    ItemType* items;  // as you make dynamic  array you should make deconstractor dinamic  array put in heap in the memry and you not memery should delet it 
};



