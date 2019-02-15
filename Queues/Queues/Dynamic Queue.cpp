#include<iostream>
using namespace std;

template<class T>
class QueueNode
{
public:
	T data;
	QueueNode<T> *next;

	QueueNode(T data)
	{
		this->data = data;
		next = NULL;
	}
};

template <class T>
class Queue
{
	QueueNode<T>*first , *last;
	int numElements;
public:
	Queue()
	{
		first = last = NULL;
		numElements = 0;
	}

	bool isEmpty()const
	{
		if ( first == NULL && last == NULL )
			return true;
		else
			return false;
	}

	void Enqueue(T data)
	{
		QueueNode<T>*temp = new QueueNode<T>(data);
		if ( isEmpty() )
			first = last = temp;
		else
		{
			last->next = temp;
			last = temp;
		}
	}

	T Dequeue()
	{
		QueueNode<T>*temp;
		if ( isEmpty() ) throw 0;

		temp = first;
		first = temp->next;
		T data = temp->data;
		delete temp;
		return data;
	}

	void show()const
	{
		if ( isEmpty() ) throw 0;
		for ( QueueNode<T> *temp = first; temp != NULL; temp = temp->next )
			cout << temp->data << " ";
		cout << endl;
	}

	~Queue()
	{
		QueueNode<T>*temp , *next;
		temp = first;
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
	Queue <int> q;
	for ( int i = 1; i <= 10; i++ )
		q.Enqueue(i);
	q.show();
	cout << q.Dequeue() << endl;
	cout << q.Dequeue() << endl;
	cout << q.Dequeue() << endl;
	system("pause");
	return 0;
}