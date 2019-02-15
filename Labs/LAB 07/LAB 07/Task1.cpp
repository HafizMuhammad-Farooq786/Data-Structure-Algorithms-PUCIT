#include<iostream>
using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node *next , *prv;
	Node(T data)
	{
		this->data = data;
		next = prv = NULL;
	}

};
template <class T>
class DDLIST
{
	Node <T> *first , *last;
public:
	// constructor
	DDLIST()
	{
		first = new Node <T>(NULL);
		last = new Node <T>(NULL);
		first->next = last;
		last->prv = first;
	}

	// Copy Constructor
	DDLIST(const DDLIST & obj){ *( this ) = obj; }

	void addAtstart(T data)
	{
		Node <T> *temp = new Node<T>(data);
		temp->next = first->next;
		first->next = temp;
		temp->prv = first;
		temp->next->prv = temp;
	}

	void addAtlat(T data)
	{
		Node <T> *temp = new Node<T>(data);
		temp->prv = last->prv;
		last->prv = temp;
		temp->next = last;
		temp->prv->next = temp;
	}

	// Delete Eement at first
	T delfirst()
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

	// delete from last
	T dellast()
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

	// Deletes Node Where data is found
	bool deleteNode(T data)
	{
		Node<T>*toDel;
		if ( first->next == last ) cout << "No element!!!!\n";
		for ( Node <T>*temp = first->next; temp->next != NULL; temp = temp->next )
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

	void printForward() const
	{
		for ( Node <T>*temp = first->next; temp->next != NULL; temp = temp->next )
			cout << temp->data << " ";
		cout << endl;
	}

	void printReverse()const
	{
		for ( Node <T> *temp = obj.last->prv; temp->prv != NULL; temp = temp->prv )
			cout << temp->data << " ";
		cout << endl;
	}

	void BubbleSort()
	{
		bool swap;
		Node<T> temp;
		do
		{
			swap = false;
			for ( Node< T> *i = first->next; i->next != NULL; i = i->next )
			{
				if ( first->data > first->next->data )
				{
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
					swap = true;
				}
			}
		} while ( swap );
	}

	void addElementinOrder(T el)
	{


	}

	// Oveloaded '=' Operator
	DDLIST operator = ( const DDLIST & obj )
	{
		for ( Node <T> *temp = obj.last->prv; temp->prv != NULL; temp = temp->prv )
			this->addAtstart(temp->data);
		return *( this );
	}

	// Overloaded '>' Operator
	bool operator > ( const DDLIST &obj )const
	{
		int c1 = 0 , c2 = 0;
		Node <T>*temp = this->first->next;
		for ( ; temp->next != NULL; temp = temp->next , c1++ );
		temp = obj.first->next;
		for ( ; temp->next != NULL; temp = temp->next , c2++ );
		return ( c1 > c2 ) ? true : false;
	}

	// Destructor
	~DDLIST()
	{
		Node <T>*temp = first;
		Node <T> *toDel;
		while ( temp != first )
		{
			toDel = temp;
			temp = temp->next;
			delete toDel;
		}
	}
};
int main()
{
	DDLIST<int>obj;
	DDLIST<int>obj1;
	DDLIST <int> obj2;

	obj.addAtstart(10);
	obj.addAtstart(9);
	obj.addAtstart(8);
	obj.addAtstart(7);
	obj.addAtstart(6);
	obj2 = obj;
	obj2.show();
	// obj1
	//obj1.addAtstart(10);
	//obj1.addAtstart(9);
	//obj1.addAtstart(8);
	//obj1.addAtstart(7);
	//obj1.addAtstart(6);
	//obj1.addAtlat(11);
	//obj.show();
	//obj.addAtlat(11);
	//obj.addAtlat(12);
	//obj.addAtlat(13);
	//obj.show();

	/*if ( obj.deleteNode(10) )
	cout << "Element is deleted\n";
	else cout << "Element does not exist!!!!\n";
	obj.show();*/


	//if ( obj1>obj)
	//	cout << "Greater\n";
	//else cout << "lesss!!!!\n";

	//cout << "DEleted element AT FIRST " << obj.delfirst() << endl;
	//cout << "DEleted element AT FIRST " << obj.delfirst() << endl;
	//cout << "DEleted element AT last " << obj.dellast() << endl;
	//cout << "DEleted element AT last " << obj.dellast() << endl;
	/*obj.show();*/
	system("pause");
	return 0;
}