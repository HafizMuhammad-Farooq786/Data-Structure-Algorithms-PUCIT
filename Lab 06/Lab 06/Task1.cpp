//#include <iostream>
//#include <ctime>
//
//#define null 0
//using namespace std;
//
//template <class T>
//class Node
//{
//public:
//	T data;
//	Node *link;
//	Node( T data )
//	{
//		this->data = data;;
//		this->link = null;
//	}
//};
//
//template <class T>
//class DLList
//{
//	Node <T>*first;
//	Node <T>*last;
//	Node<T> header;
//public:
//	// constructor
//	DLList( ):header(null)
//	{
//		last = first = &header;
//	}
//
//	// adds node at start
//	void addAtStart( T data )
//	{
//		Node<T> *temp = new Node<T>( data );
//		if ( first == last )
//		{
//			first->link = temp;
//			last = temp;
//		}
//		else
//		{
//			temp->link = first->link;
//			first->link = temp;
//		}
//	}
//
//	// adds node at end of list
//	void addAtLast( T data )
//	{
//		if ( first == last )
//			addAtStart( data );
//		else
//		{
//			Node<T> *temp = new Node<T>( data );
//			last->link = temp;
//			last = temp;
//		}
//	}
//
//	// Computes and return sum
//	T sumofList( ) const
//	{
//		T sum = 0;
//		for ( Node<T> *temp = first->link; temp != null; temp = temp->link )
//			sum = sum + temp->data;
//		return sum;
//	}
//	
//	// Returns count of elements
//	int countElements()const
//	{
//		int count = 0;
//		for ( Node<T> *temp = first->link; temp != null; temp = temp->link )
//			count++;
//		return count;
//	}
//
//	// returns pointer to highest
//	Node<T>* highestElelment( ) const
//	{
//		Node <T> *temp;
//		Node<T>*highPoint=nullptr;
//		T high = first->link->data;
//		for (temp=first->link ; temp != null; temp = temp->link )
//		{
//			if ( temp->data > high )
//			{
//				high = temp->data;
//				highPoint = temp;
//			}
//		}
//		return highPoint;
//	}
//
//	// shows all vales of list
//	void showAll( ) const
//	{
//		for ( Node<T> *temp = first->link; temp != null; temp = temp->link )
//			cout << temp->data << ' ';
//		cout << '\n';
//	}
//};
//
//int main( )
//{
//	DLList<int> list;
//	DLList<int> list2;
//
//	list.addAtLast( 3 );
//	list.addAtLast( 65 );
//	list.addAtStart( 1 );
//	list.addAtLast( 11 );
//	cout << "Sum of list is: " << list.sumofList() << endl;
//
//	cout << "Total values are: " << list.countElements() << endl;
//	list.showAll();
//	list2.addAtLast( list.highestElelment()->data );
//	list2.showAll();
//	
//	system( "pause" );
//	return 0;
//}