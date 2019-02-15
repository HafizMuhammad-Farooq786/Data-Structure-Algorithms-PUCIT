#include<iostream>
#include<fstream>
using namespace std;

//Database file records
struct AccountRecord{
	int recNum; //Record number
	int acctID; //Student identifier
	char firstName[10]; //First name
	char lastName[10]; //Last name
	char program[10]; //degree program of a student
	double cgpa; //Student’s CGPA
};

struct IndexEntry{
	int acctID; //(Key) Account identifier
	long recNum; //Record number
	//Return key field
	int getKey() const{
		return acctID;
	}
};

class BTNode
{
public:
	IndexEntry data;
	BTNode * left, *right;
	BTNode(IndexEntry d){
		this->data = d;
		left = right = NULL;
	}
};

class BST
{
	BTNode *root;
	long index;
public:
	BST(){
		root = NULL;
		index = 0;
	}

	void insert(IndexEntry d ){
		d.recNum = index;
		root = insert(d, root);
		index++;
	}

	BTNode* insert(IndexEntry d, BTNode* temp){
		if (temp == NULL)
			temp = new BTNode(d);
		else if (temp->data.acctID > d.acctID)
			temp->left = insert(d, temp->left);
		else if (temp->data.acctID < d.acctID)
			temp->right = insert(d, temp->right);
		return temp;
	}

	int search(int ID){
		if (root != NULL)
			return search(ID, root);
		else return -999;
	}

	int search(int ID, BTNode* temp){
		if (temp == NULL)
			return -999;
		if (temp->data.acctID == ID)
			return temp->data.recNum;
		else if (temp->data.acctID > ID)
			return search(ID, temp->left);
		else
			return search(ID, temp->right);
	}

	void showAll(){
		showAll(root);
	}

	void showAll(BTNode* temp){
		if (temp){
			showAll(temp->right);
			cout << temp->data.acctID << endl;
			showAll(temp->left);
		}
	}

};

void readFile(BST & tree){
	fstream f;
	AccountRecord ar;
	IndexEntry entry;
	f.open("records.dat", ios::in | ios::binary);
	while (!f.eof()){
		f.read(reinterpret_cast<char *>(&ar), sizeof(ar));
		entry.acctID = ar.acctID;
		tree.insert(entry);
	}
	f.close();
}

AccountRecord searchfromFile(int record){
	AccountRecord s;
	fstream f;
	f.open("records.dat", ios::in | ios::binary);

	while (!f.eof()){
		f.read(reinterpret_cast<char *>(&s), sizeof(s));
		if (record == s.recNum){
			f.close();
			return s;
		}
	}
	f.close();
}

void displayAccountRecord(AccountRecord s){
	cout << s.recNum << "\t" << s.acctID << "\t" << s.firstName << "\t" << s.lastName << "\t" << s.program << "\t" << s.cgpa << endl;
}

int main(){
	int id;
	BST tree;
	readFile(tree);
	tree.showAll();
	char choice='Y';
	while (choice == 'Y' || choice == 'y'){
		cout << "Enter ID to serach: ";
		cin >> id;
		displayAccountRecord(searchfromFile(tree.search(id)));
		cout << "Do You want to search another ID:[Y/N]";
		cin >> choice;
	}
	return 0;
}