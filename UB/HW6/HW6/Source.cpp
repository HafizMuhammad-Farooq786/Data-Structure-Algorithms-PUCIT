#include<iostream>
#include<fstream>
using namespace std;

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

class BTNode{
public:
	IndexEntry data;
	BTNode * left, *right;

	BTNode(IndexEntry d){
		this->data = d;
		left = right = NULL;
	}
};

class BST{
	BTNode * root;
	long recordNum;
public:
	BST(){
		root = NULL;
		recordNum = 0;
	}
	
	void insert(IndexEntry ele){
		ele.recNum = recordNum;
		root = insert(ele, root);
		recordNum++;
	}

	BTNode* insert(IndexEntry ele, BTNode* temp){
		if (temp == NULL)
			temp = new BTNode(ele);

		else if (temp->data.acctID > ele.acctID)
			temp->left = insert(ele, temp->left);
		
		else if (temp->data.acctID < ele.acctID)
			temp->right = insert(ele, temp->right);
		return temp;
	}

	int retrieve(int accountID){
		if (root != NULL){
			 return retrieve(accountID, root);
		}
		else return -99;
	}

	int retrieve(int accountID, BTNode* temp){
		if (temp == NULL)
			return -99;
		if (temp->data.acctID == accountID)
			return temp->data.recNum;
		else if (temp->data.acctID > accountID)
			return retrieve(accountID, temp->left);
		else
			return retrieve(accountID, temp->right);
	}

	void show()const{
		show(root);
	}

	void show(BTNode* temp)const{
		if ( temp ){
			show(temp->right);
			cout << temp->data.acctID <<endl;
			show(temp->left);
		}
	}
};

AccountRecord searchFile(int recordNo){
	AccountRecord student;
	fstream file;
	file.open("records.dat", ios::in | ios::binary);

	while (!file.eof()){
		file.read(reinterpret_cast<char *>(&student), sizeof(student));
		if (recordNo == student.recNum){
			file.close();
			return student;
		}
	}
	file.close();
}

int main(){
	BST t;
	AccountRecord student;
	fstream file;
	IndexEntry ie;
	int id, recordNo;

	file.open("records.dat", ios::in | ios::binary);
	while (!file.eof()){
		file.read(reinterpret_cast<char *>(&student), sizeof(student));
		ie.acctID = student.acctID;
		t.insert(ie);
	}
	file.close();
	t.show();

	cout << "Enter ID to search: ";
	cin >> id;
	recordNo = t.retrieve(id);
	if (recordNo == -99)
		cout << "NO RECORDS Found....\n";
	else{
		student = searchFile(recordNo);
		cout << "ID: " << student.acctID << endl;
		cout << "Name: " << student.firstName << " " << student.lastName << endl;
		cout << "Program: " << student.program << endl;
		cout << "CGPA: " << student.cgpa << endl;
	}
	return 0;
}