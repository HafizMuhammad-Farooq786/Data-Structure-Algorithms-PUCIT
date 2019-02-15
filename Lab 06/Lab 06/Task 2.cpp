//#include <iostream>
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
//class LinStack
//{
//	Node <T>*first;
//	Node <T>*last;
//	Node<T> header;
//public:
//	 constructor
//	LinStack( ):header(null)
//	{
//		last = first = &header;
//	}
//
//	 adds node at start
//	void push( T data )
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
//	T pop()
//	{
//			Node<T>*todelete = first->link;
//			first->link = todelete->link;
//			T d = todelete->data;
//			delete todelete;
//			return d;
//	}
//
//	 shows all vales of list
//	void showAll( ) const
//	{
//		for ( Node<T> *temp = first->link; temp != null; temp = temp->link )
//			cout << temp->data << ' ';
//		cout << '\n';
//	}
//};
//
//
//*********************************
//       Class Linqueue
//*********************************
//template <class T>
//class LinQueue
//{
//	Node <T>*first;
//	Node <T>*last;
//	Node<T> header;
//public:
//	 constructor
//	LinQueue( ) :header( null )
//	{
//		last = first = &header;
//	}
//
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
//	void Enqueue( T data )
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
//	T Dequeue()
//	{
//		Node<T>*todelete = first->link;
//		first->link = todelete->link;
//		T d = todelete->data;
//		delete todelete;
//		return d;
//	}
//
//	 shows all vales of list
//	void showAll( ) const
//	{
//		for ( Node<T> *temp = first->link; temp != null; temp = temp->link )
//			cout << temp->data << ' ';
//		cout << '\n';
//	}
//};
//
//int main()
//{
//	LinStack<int> st;
//	st.push(3);
//	st.push( 5 );
//	cout << st.pop()<<endl;
//	cout << st.pop( ) << endl;
//	st.showAll();
//
//	LinQueue<int> qu;
//	qu.Enqueue( 1 );
//	qu.Enqueue( 2 );
//	qu.Enqueue( 3 );
//	cout << qu.Dequeue() << " ";
//	cout << qu.Dequeue( ) << " ";
//	cout << qu.Dequeue( ) << " ";
//
//	system( "pause" );
//	return 0;
//}