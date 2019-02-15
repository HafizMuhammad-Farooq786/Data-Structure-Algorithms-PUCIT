#include<iostream>
using namespace std;

template <class T>
class LongTerms
{
public:
	T* next , prv;
	T data;

	LongTerms(T data)
	{
		this->data = data;
		next = prv = NULL;
	}

};

template<class T>
class longList
{
	LongTerms<T>*head , tail;
public:
	longList()
	{
		head = new Node <T>(NULL);
		tail = new Node <T>(NULL);
		head->next = tail;
		tail->prv = head;
	}

	void addAtLast(T data)
	{
		Node <T> *temp = new Node<T>(data);
		temp->prv = tail->prv;
		tail->prv = temp;
		temp->next = tail;
		temp->prv->next = temp;
	}

	void addAtStart(T data)
	{
		Node <T> *temp = new Node<T>(data);
		temp->next = head->next;
		head->next = temp;
		temp->prv = head;
		temp->next->prv = temp;
	}


	friend istream& operator >> ( istream &in , longList obj );
	friend ostream& operator << ( ostream &out , const longList &obj );
};

template <class T>
istream& operator >> ( istream &in , longList obj )
{
	
}

