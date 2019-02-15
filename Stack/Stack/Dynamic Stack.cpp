#include<iostream>
using namespace std;

template <class T>
class StackNode
{
public:
	T data;
	StackNode <T>*next;
	StackNode(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

template <class T>
class Stack
{
	StackNode <T>*top;
public:
	// Constructor
	Stack(){ top = NULL; }

	bool isEmpty() const
	{
		if ( !top )
			return true;
		else
			return false;
	}

	// Push data in stack
	void push(T data)
	{
		StackNode<T>*temp = new StackNode<T>(data);
		if ( isEmpty() )
			top = temp;
		else
		{
			temp->next = top;
			top = temp;
		}
	}

	//pops data from stack
	T pop()
	{
		StackNode<T>* temp;
		if ( isEmpty() )
			throw 0;
		else
		{
			T data = top->data;
			temp = top->next;
			delete top;
			top = temp;
			return data;
		}
	}

	void show()const
	{
		StackNode<T>*temp;
		for ( temp = top; temp != NULL; temp = temp->next )
			cout << temp->data << " ";
		cout << endl;
	}

	~Stack()
	{
		StackNode<T>*temp , *next;
		temp = top;
		while ( temp != NULL )
		{
			next = temp->next;
			delete temp;
			temp = next;
		}
	}
};

int main()
{
	Stack <int> st;
	for ( int i = 1; i <= 10; i++ )
		st.push(i);
	st.show();
	for ( int i = 1; i <= 10; i++ )
		cout << st.pop() << endl;

	system("pause");
	return 0;
}