#ifndef STACK_H
#define STACK_H
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

	bool isEmpty() const;
	void push(T);
	T pop();
	T peak();
	~Stack();
};
#endif