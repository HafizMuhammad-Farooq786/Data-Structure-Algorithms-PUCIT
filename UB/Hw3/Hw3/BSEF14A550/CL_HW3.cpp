#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

template <class T>
class Stack
{
	T *el;
	int p, size;
public:
	Stack(int s = 100){
		size = s;
		p = -1;
		el = new T[size];
	}

	bool isFull() const{ return (p == size - 1); }
	bool isEmpty() const{ return (p == -1); }
	T topEl(){
		if (!isEmpty())
			return el[p];
		throw (0);
	}

	void push(T element){
		if (!isFull())
			el[++p] = element;
	}

	T pop(){
		if (!isEmpty())
			return el[p--];
		throw (0);
	}
	~Stack(){ delete[] el; }
};

class Value{
public:
	bool isNeagtive;
	int value;

	Value(){
		isNeagtive = false;
		value = 0;
	}
	friend ostream & operator<< (ostream &, const Value&);
};

//overloaded stream insertion operator
ostream & operator<< (ostream &out, const Value &obj){
	if (obj.isNeagtive)
		out << "~" << obj.value << endl;
	else
		out << obj.value << endl;
	return out;
}

class Variable{
public:
	char name;
	char opr;
	Value val;
	friend ostream & operator<< (ostream &, const Variable&);
};

ostream & operator<< (ostream &out, const Variable &obj){
	out << obj.name << " " << obj.opr << "" << obj.val;
	return out;
}

class EvaluateExpression{
public:
	//string input;
	Variable variableArray[26];
	int varCount;
	EvaluateExpression(){
		varCount = 0;
	}

	bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '~'); }

	int solveOperator(int a, int b, char op){
		if (op == '*') return a*b;
		else if (op == '/') return a / b;
		else if (op == '%') return a%b;
		else if (op == '+') return a + b;
		else if (op == '-') return a - b;
	}

	int getPrecedence(char c){
		if (c == '*') return 6;
		else if (c == '/') return 5;
		else if (c == '%') return 4;
		else if (c == '+') return 3;
		else if (c == '-') return 2;
		else if (c == '~') return 1;
		else if (c == '=') return 0;
		else return -1;
	}

	void displayAllVariables()
	{
		for (int i = 0; i < varCount; i++)
			cout << variableArray[i];
	}

	bool variablealreadyExist(char c){
		for (int i = 0; i < varCount; i++){
			if (variableArray[i].name == c)
				return true;
		}
		return false;
	}

	void Evaluate(string input){
		Stack <int>valStack;
		Stack <char>opStack;
		Variable v;

		for (int i = input.length() - 1; i >= 0; i--)
		{
			if (input[i] == ')')
				opStack.push(')');
			else if (input[i] == '(')
				opStack.pop();
			else if (isdigit(input[i]))
				valStack.push(input[i] - 48);

			else if (this->isOperator(input[i]))
			{
				if (input[i] == '~')
				{
					v.val.isNeagtive = true;
					valStack.push(-valStack.pop());
				}
				else if (opStack.isEmpty())
					opStack.push(input[i]);
				else
				{
					if (input[i] == '='&& (opStack.topEl() == ')'))
						opStack.push('=');
					else if (this->getPrecedence(opStack.topEl()) > this->getPrecedence(input[i]))
					{
						while (!opStack.isEmpty() && this->getPrecedence(opStack.topEl()) > this->getPrecedence(input[i])){
							int a = valStack.pop();
							int b = valStack.pop();
							valStack.push(solveOperator(a, b, opStack.pop()));
						}

						opStack.push(input[i]);
					}	
					else
						opStack.push(input[i]);
				}
			}

			else if (isalpha(input[i]))
			{
				// Checks if Value of variable already Exists or not
				if (variablealreadyExist(input[i]) && (i != 0))
				{
					for (int k = 0; k < varCount; k++){
						if (input[i] == variableArray[k].name )
							valStack.push(variableArray[k].val.value);
					}
				}

				// saves value of variable in Variable array
				else
				{
					if (variablealreadyExist(input[i]))
					{
						for (int k = 0; k < varCount; k++)
						{
							if (input[i] == variableArray[k].name)
							{
								variableArray[k].val.value = valStack.topEl();
								variableArray[k].val.isNeagtive = v.val.isNeagtive;
							}
						}
						
					}

					else
					{
						v.name = input[i];
						v.val.value = valStack.topEl();
						v.opr = opStack.pop();
						variableArray[varCount++] = v;
					}
				}
					
			}
		}
	}
}; 

int main(){
	fstream f;
	string exp="";
	EvaluateExpression e;
	//f.open("input.txt", ios::in);
	//getline(f, exp);
	//while (f&& exp!="#")
	//{
	//	//cout << exp << endl;
	//	e.Evaluate(exp);
	//	//e.displayAllVariables();
	//	getline(f, exp);
	//}
	//
	//f.close();
	e.Evaluate("A=B=4");
	e.Evaluate("C=(D=2)*2");	
	/*e.Evaluate("D=A*3");
	e.Evaluate("B=D/3");
	e.Evaluate("B=B*B");*/

	e.displayAllVariables();
	return 0;
}