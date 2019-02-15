#ifndef DOUBLELIST
#define DOUBLELIST
using namespace std;

// Node class
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
		first = new Node<T> (NULL);
		last = new Node <T>(NULL);
		first->next = last;
		last->prv = first;
	}

	// Copy Constructor
	DDLIST(const DDLIST & obj){ *( this ) = obj; }

	// destructor
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

	void addAtstart(T);
	void addAtlast(T);
	T delfirst();
	T dellast();	
	bool deleteNode(T);
	template <class T>
	friend ostream& operator << ( ostream& , const DDLIST<T>& );
};
#endif