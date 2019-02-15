#include<iostream>
#include"Stack.h"
using namespace std;

template <class T>
bool Stack<T>::isEmpty()const
{
	if ( !top )
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::push(T data)
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

template <class T>
T Stack<T>::pop()
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

template <class T>
T Stack<T>::peak()
{
	if ( isEmpty() ) 
		throw 0;
	return top->data;
}

template <class T>
Stack<T>::~Stack()
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