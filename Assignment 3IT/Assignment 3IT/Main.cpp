#include<iostream>
#include<string>
#include"Stack.cpp"
using namespace std;

// function checks if given char is '(' or not
bool isSBrace(char c)
{
	if ( c == '(' )
		return true;
	else
		return false;
}

// function checks if given char is ')' or not
bool isEBrace(char c)
{
	if ( c == ')' )
		return true;
	else
		return false;
}

// function checks if given character is an operend or not
bool isOperand(char c)
{
	if ( ( c >= 'a'&&c <= 'z' ) || ( c >= 'A'&&c <= 'Z' ) )
		return true;
	else
		return false;
}

// function checks if given character is an operator or not
bool isOperator(char c)
{
	if ( c == '+' || c == '-' || c == '%' || c == '*' || c == '/' )
		return true;
	else
		return false;
}

// function returns the precedence of operators
int getPrecedence(char c)
{
	if ( c == '*' )
		return 5;
	else if ( c == '/' )
		return 4;
	else if ( c == '%' )
		return 3;
	else if ( c == '+' )
		return 2;
	else if ( c == '-' )
		return 1;
	else
		return -1;
}

//*************************************
//            class Expression        *
//*************************************
class Expression
{
	// this function reverse the given string regarding Braces
	string reverse(string str)
	{
		string exp;
		for ( int i = str.length() - 1; i >= 0; i-- )
		{
			if ( isSBrace(str[i]) )
				exp.resize(exp.length() + 1 , ')');
			else if ( isEBrace(str[i]) )
				exp.resize(exp.length() + 1 , '(');
			else
				exp.resize(exp.length() + 1 , str[i]);
		}
		return exp;
	}

	// function mades a new string that is in b/w of braces 
	// if input is (A+B)*C ut will return 'A+B' as new string for further processing
	string BraceString(int start , string exp)
	{
		int count = 0;
		for ( unsigned int i = start + 1; !isEBrace(exp[i]) && i < exp.length(); i++ )
			count++;
		string str(exp , start + 1 , count);
		return str;
	}

public:
	// function 1
	string InfixToPostfix(string infixExp)
	{
		Stack<char>st;
		string str;
		int length = infixExp.length();

		for ( int i = 0; i<length; i++ )
		{
			if ( isOperand(infixExp[i]) )
				str.resize(str.length() + 1 , infixExp[i]);

			if ( isOperator(infixExp[i]) )
			{
				if ( st.isEmpty() )
					st.push(infixExp[i]);
				else
				{
					while ( !st.isEmpty() && ( getPrecedence(st.peak()) > getPrecedence(infixExp[i]) ) )
						str.resize(str.length() + 1 , st.pop());
					st.push(infixExp[i]);
				}
			}

			if ( isSBrace(infixExp[i]) )
			{
				string s = InfixToPostfix(BraceString(i , infixExp));
				for (unsigned int k = 0; k < s.length(); k++ )
					str.resize(str.length() + 1 , s[k]);
				i = i + s.length();
			}
		}

		while ( !st.isEmpty() )
			str.resize(str.length() + 1 , st.pop());
		return str;
	}

	// Function 2
	string InfixToPrefix(string infixExp)
	{
		return reverse(InfixToPostfix(reverse(infixExp)));
	}

	// function 3
	string PostfixToInfix(string postFixExp)
	{
		string str;
		Stack<string>st;
		for ( unsigned int i = 0; i < postFixExp.length(); i++ )
		{
			if ( isOperand(postFixExp[i]) )
			{
				string s;
				s.resize(s.length() + 1 , postFixExp[i]);
				st.push(s);
			}
			if ( isOperator(postFixExp[i]) )
			{
				string s = '('+st.pop() + postFixExp[i] + st.pop()+')';
				st.push(s);
			}
		}
		return st.pop();
	}

	// FUNCTION 4
	string PrefixToInfix(string preFixExp)
	{
		return reverse(PostfixToInfix(reverse(preFixExp)));
	}

	// FUNCTION 5
	string PrefixToPostfix(string preFixExp)
	{
		string s = PrefixToInfix(preFixExp);
		string str;
		for (unsigned int i = 1; i < s.length() - 1; i++ )
			str.resize(str.length() + 1 , s[i]);
		return InfixToPostfix(str);
	}

	// FUNCTION 6
	string PostfixToPrefix(string postFixExp)
	{
		string s = PostfixToInfix(postFixExp);
		string str;
		for ( unsigned int i = 1; i < s.length() - 1; i++ )
			str.resize(str.length() + 1 , s[i]);
		return InfixToPrefix(str);
	}
};

void takeInput(string &input)
{
	cout << "Enter Expression: ";
	cin >> input;
}

void Menue()
{
	cout << "1: Infix Expression To Postfix Expression\n";
	cout << "2: Infix Expression To Prefix Expression\n";
	cout << "3: Postfix Expression To Infix Expression\n";
	cout << "4: Prefix Expression To Infix Expression\n";
	cout << "5: Prefix Expression To Postfix Expression\n";
	cout << "6: Postfix Expression To Prefix Expression\n";
	cout << "7: EXIT\n";
}

int main()
{
	Expression e;
	int choice;
	string expression;
	Menue();
	cout << "Enter your choice: ";
	cin >> choice;

	while ( choice != 7 )
	{
		switch ( choice )
		{
			case 1:
				takeInput(expression);
				cout <<"Your Desired Expression "<< e.InfixToPostfix(expression) << endl;
				break;
			case 2:
				takeInput(expression);
				cout << "Your Desired Expression " << e.InfixToPrefix(expression) << endl;
				break;
			case 3:
				takeInput(expression);
				cout << "Your Desired Expression " << e.PostfixToInfix(expression) << endl;
				break;
			case 4:
				takeInput(expression);
				cout << "Your Desired Expression " << e.PrefixToInfix(expression) << endl;
				break;
			case 5:
				takeInput(expression);
				cout << "Your Desired Expression " << e.PrefixToPostfix(expression) << endl;
				break;
			case 6:
				takeInput(expression);
				cout << "Your Desired Expression " << e.PostfixToPrefix(expression) << endl;
				break;
		}
		cout << endl;
		Menue();
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return 0;
}