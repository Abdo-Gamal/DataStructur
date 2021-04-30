#include <iostream>
using namespace std;

#include "StackType.h"
#include<string>
#include <iostream>
bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);
bool IsOperand(char C);
void blancedStack();
int performOperation(int op1, int op2, char op);
void calcAllExpration(string postfixt);
int HasHigherPrecedence(char op1, char op2);
bool IsOperator(char C);

//bool IsOperator(char C);


/*
  Infix to postfix conversion in C++
  Input Postfix expression must be in a desired format.
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
*//*
  Infix to postfix conversion in C++
  Input Postfix expression must be in a desired format.
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
*/
// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);
////////////////////////////////////////sheets blocks
ItemType Top(StackType& stack) {    //  & is very important 

	ItemType TopItem;
	TopItem=stack.PopI();

	 stack.Push(TopItem);
	return TopItem;


}
void plandrim( string s) {

	cout << s << "\n\n\n\n";
	StackType stack, reve_stack;
	for (int i = 0; i < s.size(); i++) {
		stack.Push(s[i]);

	}
	
	bool ok = true;
	for (int i = 0; i < s.size(); i++) {


		if (stack.Top() != s[i]) {
			ok = false;
			break;
		}

		stack.Pop();

	}
	//cout <<( (ok) ? " plandrim\n" : "not plandrim \n");
	if (ok)cout << "plandrim\n";
	else cout << "not plandrim\n";
}
void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem) {
	StackType tem_stack;
	while (!stack.IsEmpty())
	{
               if(stack.Top()==oldItem)tem_stack.Push(newItem);
	         else tem_stack.Push(stack.Top());

		stack.Pop();

	}
	while (!tem_stack.IsEmpty())
	{
		stack.Push(tem_stack.Top());
                 
		tem_stack.Pop();
	}
	
}
bool Identical(StackType& stack1, StackType& stack2)
{
	StackType sk1, sk2;

	bool ok = 1;
	while (!stack1.IsEmpty()&&!stack2.IsEmpty() )
	{
		if (stack1.Top() != stack2.Top()) {
			ok = 0;
			//break;
		}
		sk1.Push(stack1.Top());
		sk2.Push(stack2.Top());

		stack1.Pop();
		stack2.Pop();

	}
	 if (!stack1.IsEmpty() || !stack2.IsEmpty())ok= false;
	
	stack1.MakeEmpty();
	stack2.MakeEmpty();
	while (!sk1.IsEmpty()) {
		stack1.Push(sk1.Top());
		sk1.Pop();
	}
	while (!sk2.IsEmpty()) {
		stack2.Push(sk2.Top());
		sk2.Pop();
	}

	 return ok;

}
int main()
{

	//////////////////block for my calass
	//ItemType a='a', b='b';
	StackType stack, stack2;;
	;
	//stack.Push(a);
	//stack.Push(b);
	
	//cout << stack.Top();
	//stack.Pop();
	////////////////////sheets block
	//Top(stack);
	///
	//string s;
	//cin.ignore();////////////very important
	//getline(cin, s, '.');
	//plandrim(s);
	//////
	/*ReplaceItem(stack, 'a', 's');
	while (!stack.IsEmpty())
	{
		cout<<stack.Top()<<"\n";
		stack.Pop();
	}*/
	////
	/*stack2.Push(a);
	b = 'k';
	stack2.Push(b);
	cout<<Identical(stack, stack2)<<"\n";
*/












	////////////// block for convert from infix to postfixd
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output =" << postfix << "\n";
	

	/////////////////////block for calc the expration
	calcAllExpration(postfix);




}


void blancedStack() {
	      //= = >                           /////// work on char stack


	//char symbol;
	//StackType stack;
	//bool balanced = true;
	//char openSymbol;
	//cout << "Enter an expression and press return." << endl;
	//cin.get(symbol);
	//while (symbol != '\n' && balanced)
	//{
	//	if (IsOpen(symbol))
	//		stack.Push(symbol);
	//	else if (IsClosed(symbol))
	//	{
	//		if (stack.IsEmpty())
	//			balanced = false;
	//		else
	//		{
	//			openSymbol = stack.Top();
	//			stack.Pop();
	//			balanced = Matches(symbol, openSymbol);
	//		}
	//	}
	//	cin.get(symbol);
	//}
	//if (!stack.IsEmpty())
	//	balanced = false; if (balanced)
	//	cout << "Expression is well formed." << endl;
	//	else
	//	cout << "Expression is not well formed." << endl;
	////return ;

}
// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)//==>                           /////// work on intager stack
{
	// Declaring a Stack from Standard template library in C++. 
	StackType S;
	string postfix = ""; // Initialize postfix as empty string.
	for (unsigned int i = 0; i < expression.length(); i++) {

		// Scanning each  from left. 
		// If character is a delimitter, move on. 
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(expression[i]))
		{
			while (!S.IsEmpty() && S.Top() != '(' && HasHigherPrecedence(S.Top(), expression[i]))/////////(+-    then  come *
			{
				postfix += S.Top();
				postfix += ' ';///////////////////////not work convert number to alpha
				S.Pop();
			}
			S.Push(expression[i]);     // 
		}
		// Else if character is an operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
			postfix += ' ';
		}

		else if (expression[i] == '(')
		{
			S.Push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while ( !S.IsEmpty() && S.Top() != '(') {
				postfix += S.Top();
				postfix += ' ';
				S.Pop();
			}
			S.Pop();
		}
	}

	while (!S.IsEmpty()) {
		postfix += S.Top();
		postfix += ' ';//  postfix += S.Top()+' '  not  true  this not  add space but calc char+ char=anther atchar
		S.Pop();
	}

	return postfix;
}
bool IsOpen(char symbol)
{
	if ((symbol == '(') || (symbol == '{') || (symbol == '['))
		return true;
	else
		return false;
}

bool IsClosed(char symbol)
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool Matches(char symbol, char openSymbol)
{
	return (((openSymbol == '(') && symbol == ')')
		|| ((openSymbol == '{') && symbol == '}')
		|| ((openSymbol == '[') && symbol == ']'));
}
// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	case '$':
		weight = 3;
		break;

	}
	return weight;
}
// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}

///////////////////////////block for calc postfix expretion
void calcAllExpration(string postfixt) {
	char exp[1000], buffer[15];                       ////= string
	int i, op1, op2, len, j, x;
	 //len = strlen(exp);   to get lengh of array 
	len = postfixt.size();
	StackType stack;
	j = 0;
	for (i = 0; i < len; i++) {    //ex  55 77 + 

		if (postfixt[i] >= '0' && postfixt[i] <= '9') {
			buffer[j++] = postfixt[i];
		}
		else if (postfixt[i] == ' ') {    // prapare the number   as we consderate that 
			if (j > 0) {
				buffer[j] = '\0';   // as string  shoud be end with  '\0'
				cout << buffer<<"*\n";
				x = atoi(buffer);   // atoi conveert string to int
				stack.Push(x);
				j = 0;
			}
		}

		else if (IsOperator(postfixt[i])) {
			op1 = stack.Top();
			stack.Pop();
			op2 = stack.Top();
			stack.Pop();
			stack.Push(performOperation(op1, op2, postfixt[i]));
		}
	}
	cout << "Answer = " << stack.Top();
	return ;

}

int performOperation(int op1, int op2, char op)
{
	int ans;
	switch (op) {
	case '+':
		ans = op2 + op1;
		break;
	case '-':
		ans = op2 - op1;
		break;
	case '*':
		ans = op2 * op1;
		break;
	case '/':
		ans = op2 / op1;
		break;
	}
	return ans;
}


