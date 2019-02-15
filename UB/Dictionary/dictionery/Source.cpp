//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//template <class T>
//class Node{
//public:
//	T data;
//	Node *next;
//	Node(T data){
//		this->data = data;;
//		this->next = NULL;
//	}
//};
//
//template <class t>
//class SLList
//{
//	Node <t>*head;
//public:
//	SLList() { head = NULL; }
//
//	void addAtstart(t data)
//	{
//		Node<t> *temp = new Node<t>(data);
//		if (head)
//			temp->next = head;
//		head = temp;
//	}
//
//	bool isEmpty(){
//		return (head);
//	}
//
//	// recursive addat last function
//	void addAtlast(t data, Node<t>*ptr)
//	{
//		if (ptr->next == NULL)
//			ptr->next = new Node<t>(data);
//		else
//			addAtlast(data, ptr->next);
//	}
//
//	// driver function
//	void addAtlast(t data)
//	{
//		if (!head) addAtstart(data);
//		else
//			addAtlast(data, head);
//	}
//
//	// function deletes from start
//	t deletefromStart()
//	{
//		if (head == NULL) throw 0;
//		Node <t>*todel = head;
//		head = todel->next;
//		t data = todel->data;
//		delete todel;
//		return data;
//	}
//
//	t deletefromLast(Node<t>*ptr)
//	{
//		if (ptr->next == NULL)
//		{
//			t data = ptr->data;
//			delete ptr;
//			return data;
//		}
//		else deletefromLast(ptr->next);
//	}
//
//	t deletefromLast()
//	{
//		if (head == NULL) throw 0;
//		return deletefromLast(head);
//	}
//
//	// recursive show function
//	void show(Node<t>*ptr)
//	{
//		if (ptr == NULL) return;
//		cout << ptr->data << " ";
//		show(ptr->next);
//	}
//
//	t maxNode(Node <t>*ptr, Node<t>*ptrNext)
//	{
//		if (ptr == NULL) return NULL;
//		t max = NULL;
//		if (ptr->data > ptrNext->data)
//		{
//			max = ptr->data;
//			if (maxNode(ptr, ptrNext->next))
//		}
//		else
//			max = maxNode(ptrNext, ptrNext->next);
//		return max;
//	}
//
//	t maxNode()
//	{
//		return maxNode(head, head->next);
//	}
//
//	// driver function for show 
//	void show() { show(head); }
//};
//
//class EnglishWord {
//public:
//	SLList<string> meaninglist;
//	string word;
//	void addRomanUrduMaeaning(string meaning){ this->meaninglist.addAtlast(meaning); }
//	bool operator == (const EnglishWord obj) const{ return (word == obj.word); }
//	bool operator < (const EnglishWord obj) const{ return (word < obj.word); }
//	bool operator >(const EnglishWord obj) const{ return (word > obj.word); }
//};
//
//template <class T>
//class BTNode{
//public:
//	T data;
//	BTNode<T> * left, *right;
//	BTNode(T d){
//		this->data = d;
//		left = right = NULL;
//	}
//};
//
//class BinaryTree
//{
//	string unitName;
//	// insert node recursive function
//	void insert(BTNode<EnglishWord>*& temp, BTNode<EnglishWord>*&newNode)
//	{
//		if ( temp == NULL )
//			temp = newNode;
//		else if ( newNode->data < temp->data )
//			insert(temp->left , newNode);
//		else
//			insert(temp->right , newNode);
//	}
//
//	bool searchNode(BTNode<EnglishWord>*& temp, EnglishWord data)const
//	{
//		if (temp != NULL)
//		{
//			if (temp->data == data)
//				return true;
//			else if (data < temp->data)
//				return searchNode(temp->left, data);
//			else
//				return searchNode(temp->right, data);
//		}
//		else
//			return false;
//	}
//
//	void searchNodeandAddMeaning(BTNode<EnglishWord>*& temp, EnglishWord data,string meaning)const
//	{
//		if (temp != NULL)
//		{
//			if (temp->data == data)
//				temp->data.addRomanUrduMaeaning(meaning);
//			else if (data < temp->data)
//				searchNodeandAddMeaning(temp->left, data, meaning);
//			else
//				searchNodeandAddMeaning(temp->right, data, meaning);
//		}
//	}
//
//	//// In-Order Traversal function Recursive
//	//void inOrder(Node <T>* temp)const
//	//{
//	//	if ( temp )
//	//	{
//	//		inOrder(temp->left);
//	//		cout << temp->data << " ";
//	//		inOrder(temp->right);
//	//	}
//	//}
//
//public:
//	BTNode <EnglishWord>*root;
//	// Constructor
//	BinaryTree(){ root = NULL; }
//
//	// inserts a node in tree
//	void insertNode(EnglishWord data)
//	{
//		BTNode <EnglishWord>*newNode = new BTNode<EnglishWord>(data);
//		insert(root , newNode);
//	}
//
//	bool searchNode(EnglishWord data)
//	{
//		return searchNode(root, data);
//	}
//
//	bool isEmpty(){
//		if (root == NULL)
//			return true;
//		return false;
//	}
//
//	void searchNodeandAddMeaning(EnglishWord data, string meaning)
//	{
//		return searchNodeandAddMeaning(root, data, meaning);
//	}
//
//	//void displayinOrder()const
//	//{
//	//	inOrder(root);
//	//}
//
//	void readFile(){
//		string line;
//		fstream datafile("input.txt", ios::in);
//		while (datafile >> line)
//		{
//			if (line[0] == '$')
//			{
//				/*if (!isEmpty())
//				{
//					ofstream out("output.txt", ios::app);
//					out << root->data.word << " : "; 
//					while ( !root->data.meaninglist.isEmpty())
//						out << root->data.meaninglist.deletefromStart()<<", ";
//
//				}*/
//				string unit = line;
//				datafile >> line;
//				this->unitName = unit + " " + line;
//				ofstream out("output.txt",ios::app);
//				out << unitName << "\n";
//				out.close();
//				//cout << this->unitName;
//			}
//
//			else
//			{
//				EnglishWord w;
//				string romanUrdu = line, englishWord, colon;
//				datafile >> colon >> englishWord;
//				w.word = englishWord;
//				w.meaninglist.addAtlast(romanUrdu);
//				if (this->searchNode(w))
//					this->searchNodeandAddMeaning(w, romanUrdu);
//				else
//					this->insertNode(w);
//			}
//		}
//		datafile.close();
//		root->data.meaninglist.show();
//	}
//	 
//	~BinaryTree()
//	{
//	}
//};
//
////template <class T>
////class BinaryTree
////{
////	BTNode <T>*root;
////	// insert node recursive function
////	void insert(BTNode<T>*& temp, BTNode<T>*&newNode)
////	{
////		if ( temp == NULL )
////			temp = newNode;
////		else if ( newNode->data < temp->data )
////			insert(temp->left , newNode);
////		else
////			insert(temp->right , newNode);
////	}
////
////	//// In-Order Traversal function Recursive
////	//void inOrder(Node <T>* temp)const
////	//{
////	//	if ( temp )
////	//	{
////	//		inOrder(temp->left);
////	//		cout << temp->data << " ";
////	//		inOrder(temp->right);
////	//	}
////	//}
////
////public:
////	// Constructor
////	BinaryTree(){ root = NULL; }
////
////	// inserts a node in tree
////	void insertNode(T data)
////	{
////		BTNode <T>*newNode = new BTNode<T>(data);
////		insert(root , newNode);
////	}
////
////	bool searchNode(T data)const
////	{
////		BTNode <T>*temp = root;
////		if (temp != NULL)
////		{
////			if ( temp->data ==data )
////				returen true;
////			else if (data < temp->data)
////				return searchNode(temp->left, data);
////			else
////				return searchNode(temp->right , data);
////		}
////		else
////			return false;
////	}
////
////	//void displayinOrder()const
////	//{
////	//	inOrder(root);
////	//}
////	 
////	~BinaryTree()
////	{
////	}
////};
//
//class Convert{
//	string unitName;
//	BinaryTree bt;
//
//public:
//
//	void writeToFile(){
//		fstream datafile("output.txt", ios::out, ios::app);
//		datafile << this->unitName << "\n";
//	
//		datafile.close();
//	}
//
//	void readFile(){
//		string line;
//		fstream datafile("input.txt", ios::in);
//		while (datafile>>line)
//		{
//			if (line[0] == '$')
//			{
//				if (!bt.isEmpty())
//				{
//				
//				}
//				
//				string unit = line;
//				datafile >> line;
//				this->unitName = unit + " " + line;
//
//				//cout << this->unitName;
//			}
//				
//			else
//			{
//				EnglishWord w;
//				string romanUrdu = line, englishWord, colon;
//				datafile >>  colon >> englishWord;
//				w.word = englishWord;
//				w.meaninglist.addAtlast(romanUrdu);
//				if (bt.searchNode(w))
//					bt.searchNodeandAddMeaning(w,romanUrdu);
//				else
//					bt.insertNode(w);
//			}
//		}
//		datafile.close();
//	}
//};
//
//int main(){
//	/*Convert c;
//	c.readFile();*/
//	BinaryTree b;
//	b.readFile();
//	return 0;
//}