//#include<iostream>
//using namespace std;
//
//template <class T>
//class Node
//{
//public:
//	T data;
//	Node <T> *left , *right;
//	Node(T data)
//	{
//		this->data = data;
//		left = right = NULL;
//	}
//};
//
//template <class T>
//class BinaryTree
//{
//	Node <T>*root;
//	// insert node recursive function
//	void insert(Node<T>*& temp , Node<T>*&newNode)
//	{
//		if ( temp == NULL )
//			temp = newNode;
//		else if ( newNode->data < temp->data )
//			insert(temp->left , newNode);
//		else
//			insert(temp->right , newNode);
//	}
//
//	// In-Order Traversal function Recursive
//	void inOrder(Node <T>* temp)const
//	{
//		if ( temp )
//		{
//			inOrder(temp->left);
//			cout << temp->data << " ";
//			inOrder(temp->right);
//		}
//	}
//
//public:
//	// Constructor
//	BinaryTree()
//	{
//		root = NULL;
//	}
//
//	// inserts a node in tree
//	void insertNode(T data)
//	{
//		Node <T>*newNode = new Node<T>(data);
//		insert(root , newNode);
//	}
//
//	bool searchNode(T data)const
//	{
//		Node <T>*temp = root;
//		if ( temp != NULL )
//		{
//			if ( temp->data = data )
//				returen true;
//			else if ( data < temp->data )
//				return searchNode(temp->left , data);
//			else
//				return searchNode(temp->right , data);
//		}
//		else
//			return false;
//	}
//
//	void displayinOrder()const
//	{
//		inOrder(root);
//	}
//
//	~BinaryTree()
//	{
//	}
//};
//
//
//int main()
//{
//	BinaryTree <int> tree;
//	for ( int i = 10; i >= 1; i-- )
//		tree.insertNode(i);
//
//	tree.displayinOrder(); cout << endl;
//	system("pause");
//	return 0;
//}