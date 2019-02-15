//#include <iostream>
//#include <ctime>
//
//#define null 0
//
//using namespace std;
//
//template <class T>
//class Node{
//public:
//	T data;
//	Node *link;
//	Node( T data ){
//		this->data = data;;
//		this->link = null;
//	}
//};
//template <class T>
//class SLList{
//	Node <T>*first;
//public:
//	SLList( ){ first = null; }
//	void addAtStart( T data ){
//		Node<T> *temp = new Node<T>( data );
//		if ( first )	temp->link = first;
//		first = temp;
//	}
//	void addAtLast( T data ){
//		if ( !first )	addAtStart( data );
//		else{
//			Node<T> *temp;
//			for ( temp = first; temp->link != null; temp = temp->link );
//			temp->link = new Node<T>( data );
//		}
//	}
//	bool search( T element ) const{
//		for ( Node<T> *temp = first; temp != null; temp = temp->link )
//		if ( temp->data == element )	return true;
//		return false;
//	}
//	void showAll( ) const{
//		for ( Node<T> *temp = first; temp != null; temp = temp->link )
//			cout << temp->data << ' ';
//		cout << '\n';
//	}
//
//	/********************************************************************************************
//	*	From onwards we have functions which we have not studied in classes but I am putting	*
//	*	some comments so that students can understand.											*
//	********************************************************************************************/
//	//Check whether or not list is empty
//	bool isEmpty( ) const{ return !first; }//if there is no element first must be null and null means true
//
//	//Delete first element and return, if no first element throw exception
//	T deleteFirst( ){
//		if ( !first )	throw( 1 );		//If no element exist throw exception
//		Node<T> *toDelete = first;	//Here we are taking a pointer to point to node which is going to be deleted
//		T data = first->data;		//Store data in some T type variable
//		first = first->link;		//Move first to second node as first node is going to be deleted
//		delete toDelete;				//delete node, if pointer is pointing to some object, this will delete the object
//		return data;
//	}
//	/*
//	Delete first element and return, if list is empty throw exception
//	There may be only 1 element so delete first node and set first to null
//	otherwise to delete any other element pointer should be on the previous element
//	to manage pointer of previous element
//	*/
//	T deleteLast( ){
//		if ( !first )	throw( 2 );		//If no element exist throw exception
//		T data;						//data is to store data of last element before deletion
//		Node<T> *toDelete , *temp;	//toDelete will point to last element & temp pointer to move in the list
//		if ( first->link == null )	{//there is only first element
//			data = first->data;		toDelete = first;	first = null;
//		}
//		else{						//there exist 2 or more nodes in the list
//			for ( temp = first; temp->link->link != 0; temp = temp->link );//Move pointer to second last element
//			toDelete = temp->link;				//store address of last node in pointer toDelete
//			data = toDelete->data;				//store data of last node in variable data
//			temp->link = null;					//place null to the link of second last node, it is last node now
//		}
//		delete toDelete;					//delete last node
//		return data;
//	}
//	/*
//	Search & delete if found return true else false
//	There are 3 situations possible. One is there is no element in the list, second element exist on
//	first node. Third element exist on any other node
//	*/
//	bool deleteNode( T data ){
//		if ( !first )		throw( 3 );		//If no element exist throw exception
//		Node<T> *toDelete = 0 , *temp;
//		if ( first->data == data ){ toDelete = first; first = first->link; }
//		else if ( first->link ){//Minimum 2 Nodes exist because first->link is not null			
//			//Keep pointer to previous node, start from second node where pointer is on first node
//			//Move temp till end of list until data found on some node
//			for ( temp = first; temp->link != 0 && temp->link->data != data; temp = temp->link );
//			if ( temp->link ){				//means data found next to temp otherwise temp->link will be null
//				toDelete = temp->link;		//store address of node to delete in toDelete pointer
//				temp->link = temp->link->link;//link temp with next to next				
//			}
//			if ( toDelete ){ delete toDelete;	return true; }//if toDelete is not null, delete that node & return true
//			return false;					//means data not found in the list
//		}
//	}
//	/*
//	Delete nth node. If nth node does not exist throw exception
//	otherwise delete nth node & return data of nth node
//	*/
//	T deleteNodeN( int n ){
//		if ( !first )		throw( n );		//Nth node does not exist
//		int i = 2;						//i is used when we have to delete node 2+ means not first node
//		Node<T> *toDelete = 0 , *temp;
//		if ( n == 1 ){ toDelete = first; first = null; }
//		else {	//n is 2 or more			
//			//Keep pointer to previous node, start from second node where pointer is on first node
//			//Move temp till end of list until data found on some node
//			for ( temp = first; temp->link != 0 && i<n; temp = temp->link , i++ );
//			if ( temp->link ){				//means data found next to temp otherwise temp->link will be null
//				toDelete = temp->link;		//store address of node to delete in toDelete pointer
//				temp->link = temp->link->link;//link temp with next to next				
//			}
//			if ( toDelete ){
//				T data = toDelete->data;
//				delete toDelete;
//				return data;
//			}//if toDelete is not null, delete that node & return true
//		}
//		throw( n );	//nth node does not exist
//	}
//};
//
//int main( ){
//	srand( time( 0 ) );
//	int i , choice , value;
//	SLList<int> list;
//	for ( i = 1; i <= 10; i++ ){
//		choice = rand( ) % 2;
//		value = rand( ) % 90 + 10;
//		if ( choice == 1 )	{ cout << "Adding " << value << " at Start\n";  list.addAtStart( value ); }
//		else				{ cout << "Adding " << value << " at End\n";  list.addAtLast( value ); }
//	}
//	list.showAll( );
//	//Now I am testing rest of the functions, when you will understand previous functions then uncomment this code
//	/*for (i = 1; i <= 8; i++){
//	choice = rand() % 4+1;
//	if (choice == 1)		{	cout << "Deleting First Node having value:" << list.deleteFirst() <<'\n';	 }
//	else if (choice == 2)	{ cout << "Deleting Last Node having value:" << list.deleteLast() << '\n'; }
//	else if (choice == 3)	{
//	value = rand() % 90 + 10;
//	cout << "Deleting Node having value:" << value<< '\t';
//	if (list.deleteNode(value))	cout << "Value exist & deleted\n";
//	else                        cout << "Value does not exist\n";
//	}
//	else{
//	try{
//	value = rand() % 8+1;
//	cout << "Deleting Node from position:" << value << '\n';
//	int data=list.deleteNodeN(value);
//	cout << "Data of node "<<value<<" was:" << data << '\n';
//	}
//	catch (int n){ cout <<"Node "<<n<<" does not exist\n"; }
//	}
//	}
//	list.showAll();	*/
//
//	return 0;
//}