#include<iostream>
#include"DoubleList.h"
using namespace std;

template <class T>
void DDLIST::addAtstart(T data)
{
	Node <T> *temp = new Node<T>(data);
	temp->next = first->next;
	first->next = temp;
	temp->prv = first;
	temp->next->prv = temp;
}

template <class T>
void DDLIST::addAtlast(T data)
{
	Node <T> *temp = new Node<T>(data);
	temp->prv = last->prv;
	last->prv = temp;
	temp->next = last;
	temp->prv->next = temp;
}

template<class T>
T DDLIST::delfirst()
{
	Node<T>*temp;
	T data;
	if ( first->next == last ) cout << "No element!!!!\n";
	temp = first->next;
	data = temp->data;
	first->next = temp->next;
	temp->next->prv = first;
	delete temp;
	return data;
}

template<class T>
T DDLIST::dellast()
{
	Node<T>*temp;
	T data;
	if ( first->next == last ) cout << "No element!!!!\n";
	temp = last->prv;
	data = temp->data;
	last->prv = temp->prv;
	temp->prv->next = last;
	delete temp;
	return data;
}

template<class T>
bool DDLIST::deleteNode(T data)
{
	Node<T>*toDel;
	if ( first->next == last ) cout << "No element!!!!\n";
	for ( Node <T>*temp = first->next; temp->next != last; temp = temp->next )
	{
		if ( temp->data == data )
		{
			toDel = temp;
			temp->prv->next = temp->next;
			temp->next->prv = temp->prv;
			delete toDel;
			return true;
		}
	}
	return false;
}

template<class T>
ostream& operator << ( ostream &out , const DDLIST<T> &obj )
{
	for ( Node <T>*temp = first->next; temp->next != last; temp = temp->next )
		out << t->data;
	return out;
}