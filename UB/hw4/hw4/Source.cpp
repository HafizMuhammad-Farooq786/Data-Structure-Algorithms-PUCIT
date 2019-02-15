#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
	friend class StudentList;
private:
	int id; //id of a student.
	string name; //name of a student.
	float cpga; //cgpa of a student.
	Student *next; //address of the next available object.
public:
	Student(int id, string name, float cgpa, Student *next){
		this->id = id;
		this->cpga = cgpa;
		this->name = name;
		this->next = next;
	}
};

class StudentList{
private:
	Student *head; //start of the list
	Student *cursor; //current item of the list
public:

	StudentList(){//Constructor
		this->head = NULL;
		this->cursor = head;
	}

	// returns copy pointed by cursor
	Student getCursor(){
		return *(cursor);
	}

	// checks if list is Empty or not
	bool isEmpty()const{
		return this->head == NULL ? true : false;
	}

	// GOES to begging of list
	void gotoBeginning(){
		this->cursor = head;
	}

	// moves cursor to end
	void gotoEnd(){
		if (isEmpty()){
			cout << "Empty List\n";
			return;
		}
		if (this->cursor->next == NULL)//if already on end
			return;
		Student *temp;
		for (temp = cursor; temp->next != NULL; temp = temp->next);
		cursor = temp;
	}

	// moves cursor to Next position
	bool gotoNext(){
		if (isEmpty()){
			cout << "Empty List\n";
			return false;
		}
		if (this->cursor->next == NULL)
			return false;
		this->cursor = cursor->next;
	}

	// inserts sudent in list
	void insert(const Student &newStd){
		if (isEmpty()){
			head = new Student(newStd.id, newStd.name, newStd.cpga, NULL);
			this->cursor = head;
			return;
		}
		this->cursor->next = new Student(newStd.id, newStd.name, newStd.cpga, NULL);
		this->cursor = this->cursor->next;
	}

	// removes item from list matches id
	void remove(int id){
		if (isEmpty()){
			cout << "Empty List\n";
			return;
		}

		Student *toDelete = 0; Student *temp;

		if (head->id == id){
			if (cursor == head)
				cursor = head->next;
			toDelete = head;
			head= head->next;
			delete toDelete;
			return;
		}

		if (isFound(id)){
			for (temp = head; temp->next != NULL && temp->next->id != id; temp = temp->next);
			if (temp->next){
				toDelete = temp->next;
				if (cursor == toDelete){
					if (toDelete->next == NULL)
						gotoBeginning();
					else
						cursor = toDelete->next;
				}
				temp->next = temp->next->next;
			}
		}
		else
			cout << "No Student matches with required id\n";
		if (toDelete!=NULL)
			delete toDelete;
	}

	// outputs list data
	void showStructure() const{
		if (isEmpty()){
			cout << "Empty List\n";
			return;
		}
		else{
			for (Student *temp = head; temp!= NULL; temp = temp->next)
				cout << temp->name << "\t" << temp->id << "\t" << temp->cpga << "\n";
		}
	}
	
	// moves backward one position
	bool gotoPrior(){
		if (cursor == head)
			return false;
		Student *temp = cursor;
		gotoBeginning();
		for (; cursor->next != temp; cursor = cursor->next);
		return true;
	}

	// replace data of student with passed data if ID is matched
	void replace(const Student &newStd){
		if (isEmpty()){
			cout << "Empty List\n";
			return;
		}

		if (isFound(newStd.id)){
			for (Student *temp = head; temp != NULL; temp = temp->next){
				if (newStd.id == temp->id){
					temp->cpga = newStd.cpga;
					temp->id = newStd.id;
					temp->name = newStd.name;
				}
			}
		}
		else
			this->insert(newStd);
	}

	// search function based on CGPA
	void search(float cgpa){
		if (isEmpty()){
			cout << "Empty List\n";
			return;
		}

		if (isFound(cgpa)){
			cout << "Follwig Student(s) have Required CGPA\n";
			for (Student *temp = head; temp != NULL; temp = temp->next){
				if (temp->cpga == cgpa)
					cout << temp->name << "\t" << temp->id << "\t" << temp->cpga << "\n";
			}
		}
		else
			cout << "NO student match in list with required CGPA\n";
	}

	// destructor
	~StudentList(){
		while (head!=NULL){
			gotoEnd();
			remove(cursor->id);
			gotoEnd();
		}
	}

	//******************************************************************
	//           functions are written for assistance
	bool isFound(int id)const{
		for (Student *temp = head; temp != NULL; temp = temp->next){
			if (id == temp->id)
				return true;
		}
		return false;
	}

	bool isFound(float cgpa)const{
		for (Student *temp = head; temp != NULL; temp = temp->next){
			if (temp->cpga == cgpa)
				return true;
		}
		return false;
	}

	void showCursor(){
		cout << cursor->name << "\t" << cursor->id << "\t" << cursor->cpga << endl;
	}
	//*****************************************************************
};

int main(){
	StudentList list;
	ifstream in("input.txt");
	while (!in.eof()){
		int id;
		string name;
		float cgpa;
		in >> id >> name >> cgpa;
		list.insert(Student(id, name, cgpa,NULL));
	}
	cout << "Displays data in lsit\n";
	list.showStructure();
	cout << endl;

	cout << "After Delete student with id 50\n"; list.remove(50);
	list.showStructure();
	cout << endl;

	cout << "Moving cursor to one position backward\n";list.gotoPrior();
	list.showCursor();

	cout << "Move cursor to One position forward\n";list.gotoNext();
	list.showCursor();

	cout << "Move Cursor to Start\n";list.gotoBeginning();
	list.showCursor();

	cout << "Move cursor to End\n";list.gotoEnd();
	list.showCursor();

	in.close();
	return 0;
}