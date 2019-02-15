#include<iostream>
using namespace std;

template <class t>
class Node
{
public:
	t data;
	Node<t>*next;
	Node(t data)
	{
		this->data = data;
		next = NULL;
	}
};

template <class t>
class SLList
{
	Node <t>*head;
public:
	SLList() { head = NULL; }

	void addAtstart(t data)
	{
		Node<t> *temp = new Node<t>(data);
		if ( head )
			temp->next = head;
		head = temp;
	}

	// recursive addat last function
	void addAtlast(t data , Node<t>*ptr)
	{
		if ( ptr->next == NULL )
			ptr->next = new Node<t>(data);
		else
			addAtlast(data , ptr->next);
	}

	// driver function
	void addAtlast(t data)
	{
		if ( !head ) addAtstart(data);
		else
			addAtlast(data , head);
	}

	// function deletes from start
	t deletefromStart()
	{
		if ( head == NULL ) throw 0;
		Node <t>*todel = head;
		head = todel->next;
		t data = todel->data;
		delete todel;
		return data;
	}

	t deletefromLast(Node<t>*ptr)
	{
		if ( ptr->next == NULL )
		{
			t data = ptr->data;
			delete ptr;
			return data;
		}
		else deletefromLast(ptr->next);
	}

	t deletefromLast()
	{
		if ( head == NULL ) throw 0;
		return deletefromLast(head);
	}
	
	

	// recursive show function
	void show(Node<t>*ptr)
	{
		if ( ptr == NULL ) return;
		cout << ptr->data << " ";
		show(ptr->next);
	}

	t maxNode(Node <t>*ptr , Node<t>*ptrNext)
	{
		if ( ptr == NULL ) return NULL;
		t max=NULL;
		if ( ptr->data > ptrNext->data )
		{
			max = ptr->data;
			if (maxNode(ptr , ptrNext->next))
		}
		else
			max = maxNode(ptrNext , ptrNext->next);
		return max;
	}

	t maxNode()
	{
		return maxNode(head , head->next);
	}

	// driver function for show 
	void show() { show(head); }

};

int main()
{
	SLList<int>list;
	list.addAtlast(7);
	list.addAtlast(8);
	list.addAtlast(9);
	list.show(); cout << endl;
	list.deletefromLast();
	list.show();

	cout << list.maxNode();

	system("pause");
	return 0;
}