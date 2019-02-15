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
//
//template <class T>
//class DLList
//{
//	Node <T>*first;
//	Node <T>*last;
//public:
//	// constructor
//	DLList(){ first = last = null; }
//
//	// adds node at start
//	void addAtStart( T data )
//	{
//		Node<T> *temp = new Node<T>( data );
//		if ( first == last )
//			first = last = temp;
//		else
//		{
//			temp->link = first;
//			first = temp;
//		}
//	}
//
//	// adds node at end of list
//	void addAtLast( T data )
//	{
//		if ( first == null&&last == null )
//			addAtStart( data );
//		else
//		{
//			Node<T> *temp = new Node<T>( data );
//			last->link = temp;
//			last = temp;
//		}
//	}
//
//	bool search( T element ) const
//	{
//		for ( Node<T> *temp = first; temp != null; temp = temp->link )
//		if ( temp->data == element )	return true;
//		return false;
//	}
//
//	void showAll() const
//	{
//		for ( Node<T> *temp = first; temp != null; temp = temp->link )
//			cout << temp->data << ' ';
//		cout << '\n';
//	}
//};
//
//int main()
//{
//	DLList<int> list;
//	list.addAtStart( 2 );
//	list.addAtLast( 3 );
//	list.addAtStart( 5 );
//	list.addAtLast( 10 );
//	list.showAll();
//	system( "pause" );
//	return 0;
//}