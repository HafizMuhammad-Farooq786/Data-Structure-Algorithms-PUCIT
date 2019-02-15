#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Class Node that is used in LINK LIST
template <class T>
class Node{
public:
	T data;
	Node *next;
	Node(T data){
		this->data = data;;
		this->next = NULL;
	}
};

// template LINK LIST CLASS
template <class t>
class SLList
{
	Node <t>*head;
public:
	SLList() { head = NULL; }

	void addAtstart(t data){
		Node<t> *temp = new Node<t>(data);
		if (head)
			temp->next = head;
		head = temp;
	}

	bool isEmpty(){  
		if (head == NULL)
			return true;
		return false;
	}

	// recursive addat last function
	void addAtlast(t data, Node<t>*ptr){
		if (ptr->next == NULL)
			ptr->next = new Node<t>(data);
		else
			addAtlast(data, ptr->next);
	}

	// driver function
	void addAtlast(t data){
		if (!head) addAtstart(data);
		else
			addAtlast(data, head);
	}

	// function deletes from start
	t deletefromStart(){
		if (head == NULL) 
			throw 0;
		Node <t>*todel = head;
		head = todel->next;
		t data = todel->data;
		delete todel;
		return data;
	}

	t deletefromLast(Node<t>*ptr){
		if (ptr->next == NULL){
			t data = ptr->data;
			delete ptr;
			return data;
		}
		else deletefromLast(ptr->next);
	}

	t deletefromLast(){
		if (head == NULL) throw 0;
		return deletefromLast(head);
	}

	void freeList(){
		Node<t> *temp;
		while (head!=NULL){
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
		}
	}

	~SLList(){}

	template<class t>
	friend ostream & operator<< (ostream &, const SLList<t> &);
};

// Overloaded << operator helpful for writing data to file
template<class t>
ostream & operator<< (ostream & out, const SLList<t>& obj){
	for (Node<t> *temp = obj.head; temp != NULL; temp = temp->next)
		out << temp->data << ",";
	out << endl;
	return out;
}

// Class to hold data for an english Word along with it's Roman urdu meaning
class EnglishWord {
public:
	SLList<string> meaninglist;
	string word;
	void addRomanUrduMaeaning(string meaning){ this->meaninglist.addAtlast(meaning); }
	bool operator == (const EnglishWord obj) const{ return (word == obj.word); }
	bool operator < (const EnglishWord obj) const{ return (word < obj.word); }
	bool operator >(const EnglishWord obj) const{ return (word > obj.word); }
	friend ostream & operator<< (ostream &, const EnglishWord &);
};

ostream & operator << (ostream & out, const EnglishWord & obj){
	out << obj.word << " : " << obj.meaninglist;
	return out;
}

// Class used for a single Node of BST
template <class T>
class BTNode{
public:
	T data;
	BTNode<T> * left, *right;
	BTNode(T d){
		this->data = d;
		left = right = NULL;
	}
};

// Class BST
template <class T>
class BinaryTree
{
	bool searchNode(BTNode<T>*& temp,T data)
	{
		if (temp != NULL){
			if (temp->data == data)
				return true;
			else if (data < temp->data)
				return searchNode(temp->left, data);
			else
				return searchNode(temp->right, data);
		}
		else
			return false;
	}

	void searchNodeandAddMeaning(BTNode<T>*& temp, EnglishWord data, string meaning)const
	{
		if (temp != NULL)
		{
			if (temp->data == data)
				temp->data.addRomanUrduMaeaning(meaning);
			else if (data < temp->data)
				searchNodeandAddMeaning(temp->left, data, meaning);
			else
				searchNodeandAddMeaning(temp->right, data, meaning);
		}
	}

	// insert node recursive function
	void insert(BTNode<T>*& temp, BTNode<T>*&newNode)
	{
		if ( temp == NULL )
			temp = newNode;
		else if ( newNode->data < temp->data )
			insert(temp->left , newNode);
		else
			insert(temp->right , newNode);
	}

	// Writes trre's Data to output file
	void writetreetoFile(BTNode<T>*& temp){
		ofstream out("output.txt", ios::app);
		if (temp!=NULL)
		{
			writetreetoFile(temp->left);
			out << temp->data;
			writetreetoFile(temp->right);
		}
		out.close();
	}

	void deleteTree(BTNode<T>*& t){

		if (t == NULL)
			return;
		if (t->left != NULL)
			deleteTree(t->left);
		if (t->right != NULL)
			deleteTree(t->right);
		delete t;
	}

public:
	BTNode <T>*root;
	// Constructor
	BinaryTree(){ root = NULL; }

	// inserts a node in tree
	void insertNode(T data)
	{
		BTNode <T>*newNode = new BTNode<T>(data);
		insert(root , newNode);
	}

	bool searchNode(T data){
		return searchNode(root, data);
	}

	void searchNodeandAddMeaning(EnglishWord data, string meaning){
		return searchNodeandAddMeaning(root, data, meaning);
	}

	void writetreetoFile(){
		writetreetoFile(root);
	}

	void deleteTree(){
		deleteTree(root);
	}

	bool isEmpty(){
		if (root == NULL)
			return true;
		return false;
	}
	 
	~BinaryTree(){
		deleteTree();
	}
};

// Class Reads data from input File and then writes output to file
class Convert{
	BinaryTree<EnglishWord> *b = new BinaryTree<EnglishWord>();
	string unitName;
public:

	// this is corefunction used tree's other function to
	// read data from file and then writes back to output-file
	void readFile(){	
		string line;
		fstream datafile("input.txt", ios::in);
		while (!datafile.eof())
		{
			datafile >> line;
			if (line[0] == '$'){

				if (!b->isEmpty()){    // If new unit $ starts and words are lready in tree 
					b->writetreetoFile(); // then writes unit words to file
					delete b;  // deletes tree
					b = new BinaryTree<EnglishWord>(); // Makes a new one for next $UNIT
				}
				string unit = line;
				datafile >> line;
				this->unitName = unit + " " + line;
				
				ofstream out("output.txt", ios::app);   // Writes Unit Name to Output File
				out << unitName << "\n";
				out.close();
			}

			else{
				EnglishWord w;
				string romanUrdu = line, englishWord, colon;
				datafile >> colon >> englishWord;    // reading Word from File
				w.word = englishWord;
				w.meaninglist.addAtlast(romanUrdu);  // Adding Roman Urdu Meaning To List

				if (b->searchNode(w))    // If English word already exists then inserts Roman Urdu meaning to word's list 
					b->searchNodeandAddMeaning(w, romanUrdu);
				else
					b->insertNode(w);    //if English Word doesnot exist then adds word into tree
			}
		}
		datafile.close(); 
		b->writetreetoFile();
		delete b;
	}
};

int main(){
	Convert c;
	c.readFile();
	cout << "Done Data is written to file..............\n";
	return 0;
}