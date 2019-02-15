//#include<iostream>
//using namespace std;
//#define SEN -1
//
//template<class T>
//class QueueNode
//{
//public:
//	T data;
//	QueueNode<T> *next;
//
//	QueueNode(T data)
//	{
//		this->data = data;
//		next = NULL;
//	}
//};
//
//template <class T>
//class Queue
//{
//	QueueNode<T>*first , *last;
//	int numElements;
//public:
//	Queue()
//	{
//		first = last = NULL;
//		numElements = 0;
//	}
//
//	bool isEmpty()const
//	{
//		if ( first == NULL && last == NULL )
//			return true;
//		else
//			return false;
//	}
//
//	void Enqueue(T data)
//	{
//		QueueNode<T>*temp = new QueueNode<T>(data);
//		if ( isEmpty() )
//			first = last = temp;
//		else
//		{
//			last->next = temp;
//			last = temp;
//		}
//	}
//
//	T Dequeue()
//	{
//		QueueNode<T>*temp;
//		if ( isEmpty() )
//			throw 0;
//
//		temp = first;
//		first = temp->next;
//		T data = temp->data;
//		delete temp;
//		return data;
//	}
//
//	void show()const
//	{
//		if ( isEmpty() ) throw 0;
//		for ( QueueNode<T> *temp = first; temp != NULL; temp = temp->next )
//			cout << temp->data << " ";
//		cout << endl;
//	}
//
//	~Queue()
//	{
//		QueueNode<T>*temp , *next;
//		temp = first;
//		while ( temp != NULL )
//		{
//			next = temp->next;
//			delete temp;
//			temp = next;
//		}
//	}
//};
//
//
//void printUsingQueue(int x[] , int SIZE)
//{
//	Queue<int> qu;
//	for ( int i = 0; i < SIZE; i++ )
//	{
//		if ( x[i] != SEN )
//			qu.Enqueue(x[i]);
//	}
//	qu.show();
//}
//
//void printTree(int x[] ,int i , int SIZE)
//{	
//	if ( i ==SIZE )
//	{
//		for ( int j = pow(2 , i - 1) + ( SIZE - 1 ); j < ( pow(2 , i - 1) + pow(2 , i) + ( SIZE - 1 ) ); j++ )
//		{
//			if ( x[j] != SEN )
//				cout << x[j] << " ";
//		}
//	}
//	else
//		printTree(x , i + 1 , SIZE);
//}
//
//
//int main()
//{
//	int x[] = { 8 , 3 , 10 , 1 , 6 , SEN , 14 , SEN , SEN , 4 , 7 , SEN , SEN , 13 , SEN };
//	cout << "Print Using queue: "; printUsingQueue(x , 15);
//	cout << endl;
//	cout << "print TREE" << endl;
//	printTree(x , 0,15);
//	system("pause");
//	return 0;
//}