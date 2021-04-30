#include <iostream>
#include<string>
using namespace std;

#include "StackType.h"
#include <iostream>
bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);
	void blancedStack();
int main()
{


	ItemType a = 'a', b = 'b', c;
	StackType stack;


	stack.Push(a);
	stack.Push(b);




	////////////// block for convert from infix to postfixd
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";


	///////////////////////block for calc the expration
	calcAllExpration(postfix);











	
} 

void blancedStack() {


	char symbol;
	StackType stack;
	bool balanced = true;
	char openSymbol;
	cout << "Enter an expression and press return." << endl;
	cin.get(symbol);
	while (symbol != '\n' && balanced)
	{
		if (IsOpen(symbol))
			stack.Push(symbol);
		else if (IsClosed(symbol))
		{
			if (stack.IsEmpty())
				balanced = false;
			else
			{
				openSymbol = stack.Top();
				stack.Pop();
				balanced = Matches(symbol, openSymbol);
			}
		}
		cin.get(symbol);
	}
	if (!stack.IsEmpty())
		balanced = false; if (balanced)
		cout << "Expression is well formed." << endl;
		else
		cout << "Expression is not well formed." << endl;
	//return ;

}


// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
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
				S.Pop();
			}
			S.Push(expression[i]);     // 
		}
		// Else if character is an operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(')
		{
			S.Push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.IsEmpty() && S.Top() != '(') {
				postfix += S.Top();
				S.Pop();
			}
			S.Pop();
		}
	}

	while (!S.IsEmpty()) {
		postfix += S.Top();
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

void calcAllExpration(string postfixt) {
	char exp[1000], buffer[15];                       ////= string
	int i, op1, op2, len, j, x;

	StackType stack;
	j = 0;
	for (i = 0; i < len; i++) {    //ex  55 77 + 

		if (exp[i] >= '0' && exp[i] <= '9') {
			buffer[j++] = exp[i];
		}
		else if (exp[i] == ' ') {    // prapare the number   as we consderate that 
			if (j > 0) {
				buffer[j] = '\0';   // as string  shoud be end with  '\0'
				x = atoi(buffer);   // atoi conveert string to int
				stack.Push(x);
				j = 0;
			}
		}

		else if (IsOperator(exp[i])) {
			op1 = stack.Top();
			stack.Pop();
			op2 = stack.Top();
			stack.Pop();
			stack.Push(performOperation(op1, op2, exp[i]));
		}
	}
	cout << "Answer = " << stack.Top();
	return;

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


