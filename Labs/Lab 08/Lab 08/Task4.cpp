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
//	Node *next;
//	Node(T data){
//		this->data = data;;
//		this->next = null;
//	}
//};
//
//template <class T>
//class SLListRec
//{
//	Node <T>*head;
//public:
//	SLListRec(){ head = null; }
//
//	void addAtStart(T data){
//		Node<T> *temp = new Node<T>(data);
//		if ( head )	temp->next = head;
//		head = temp;
//	}
//
//	//Recursive function to add node at the end
//	Node<T>* addAtLast(T data , Node<T> *temp){
//		if ( !temp ){ temp = new Node<T>(data); }
//		else temp->next = addAtLast(data , temp->next);
//		return temp;
//	}
//	//Driver function to send first call to recursive function because head is data member & not accessible outside class
//	void addAtLast(T data){
//		head = addAtLast(data , head);
//	}
//
//	//Recursive function to show all data recusively
//	void showAll(Node<T> *temp){
//		if ( temp ){
//			cout << temp->data << ' ';
//			showAll(temp->next);
//		}
//	}
//	//Driver function to send first call to recursive function because head is data member & not accessible outside class
//	void showAll(){
//		showAll(head);
//	}
//
//	//Recursive function to show data in reverse
//	void showReverse(Node<T>*temp)
//	{
//		if ( temp == null ){ return; }
//		else
//		{
//			showReverse(temp->next);
//			cout << temp->data << " ";
//		}
//	}
//
//	//Driver function to send first call to recursive function because head is data member & not accessible outside class
//	void showReverse()
//	{
//		showReverse(this->head);
//	}
//
//	//Recursive function to delete all nodes
//	void deleteAll(Node<T> *temp)
//	{
//		if ( temp )
//		{
//			deleteAll(temp->next);
//			delete ( temp );
//		}
//	}
//
//	Node<T>* deleteAtLast(Node<T> *temp){
//		if ( temp->next == NULL ){ return temp; }
//		else temp = deleteAtLast( temp->next);
//		return temp;
//	}
//
//	// function deletes last elemnet
//	T deleteLastElement()
//	{
//		T d;
//		Node<T>*temp = deleteAtLast(head);
//		d = temp->data;
//		delete temp;
//		return d;
//	}
//
//
//	~SLListRec(){ deleteAll(head); }
//};
//
//int main()
//{
//	srand(time(0));
//	int i , choice , value;
//	SLListRec <int> list;
//	for ( i = 1; i <= 10; i++ )
//	{
//		choice = rand() % 2;
//		value = rand() % 90 + 10;
//		if ( choice == 1 )	{ cout << "Adding " << value << " at Start\n";  list.addAtStart(value); }
//		else				{ cout << "Adding " << value << " at End\n";  list.addAtLast(value); }
//	}
//	list.showAll();
//	cout << "Deleting " << list.deleteLastElement() << " from last\n";
//	list.showAll();
//	cout << endl;
//	list.showReverse();
//	cout << endl;
//	system("pause");
//	return 0;
//}