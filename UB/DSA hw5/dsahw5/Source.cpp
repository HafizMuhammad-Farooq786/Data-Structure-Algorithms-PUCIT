#include<iostream>
#include<string>
#include<list>
#include<fstream>

using namespace std;

template<class T>
class QueueNode{
public:
	T data;
	QueueNode<T> *next;
	
	QueueNode(T data){
		this->data = data;
		next = NULL;
	}
};

template <class T>
class Queue{
	QueueNode<T>*first, *last;
public:
	Queue(){
		first = last = NULL;
	}

	bool isEmpty()const{
		if (first == NULL && last == NULL)
			return true;
		else
			return false;
	}

	void Enqueue(T data){
		QueueNode<T>*temp = new QueueNode<T>(data);
		if (isEmpty())
			first = last = temp;
		else{
			last->next = temp;
			last = temp;
		}
	}

	T Dequeue(){
		QueueNode<T>*temp;
		if (isEmpty())
			throw 0;

		if (first == last){
			temp = first;
			last = first = NULL;
		}
		else{
			temp = first;
			first = temp->next;
		}
		T data = temp->data;
		delete temp;
		return data;
	}

	void show()const{
		if (isEmpty()) 
			throw 0;
		for (QueueNode<T> *temp = first; temp != NULL; temp = temp->next)
			cout << temp->data << endl;
		cout << endl;
	}

	// Destructor
	~Queue(){
		QueueNode<T>*temp, *next;
		temp = first;
		while (temp != NULL){
			next = temp->next;
			delete temp;
			temp = next;
		}
	}

};

//************Class Process Hanles all Attributes Related Process*******/
class Process{
	// data Members
	string processName;
	int serviceTime;
	int arrivalTime;
	int finishTime;
	int turnAroundTime;
	int waitingTime;
	int timeSlice;
	int remainingTime;

public:
	Process(){
		this->processName = "";
		this->arrivalTime = 0;
		this->finishTime = 0;
		this->serviceTime = 0;
		this->timeSlice = 0;
		this->turnAroundTime = 0;
		this->waitingTime = 0;
		this->remainingTime = this->serviceTime;
	}

	Process(string name, int arrivalTime, int serviceTime, int timeSlice){
		this->setProcessName(name);
		this->setArrivalTime(arrivalTime);
		this->setServiceTime(serviceTime);
		this->setSliceTime(timeSlice);
		this->setFinishTime(0);
		this->setTurnAroundTime();
		this->setWaitingTime();
		this->remainingTime = this->serviceTime;
	}

	/**************Attributes Setters*****************/
	void setProcessName(string name){
		this->processName = name;
	}

	void setArrivalTime(int time){
		this->arrivalTime = time;
	}

	void setFinishTime(int time){
		this->finishTime = time;
	}

	void setServiceTime(int time){
		this->serviceTime = time;
	}

	void setSliceTime(int time){
		this->timeSlice = time;
	}

	void setRemainingTime(int time){
		this->remainingTime = time;
	}

	void setTurnAroundTime(){
		this->turnAroundTime = this->finishTime - this->arrivalTime;
	}

	void setWaitingTime(){
		this->waitingTime = this->turnAroundTime - this->serviceTime;
	}

	/*********************Getters fro Attributes***********************/
	string getProcessName()const{
		return this->processName;
	}

	int getArrivalTime()const{
		return this->arrivalTime;
	}

	int getFinishTime()const{
		return this->finishTime;
	}

	int getServiceTime()const{
		return this->serviceTime;
	}

	int getTimeSlice()const{
		return this->timeSlice;
	}

	int getRemainingTime()const{
		return this->remainingTime;
	}

	int getTurnAroundTime()const{
		return this->turnAroundTime;
	}

	int getWaitingTime()const{
		return this->waitingTime;
	}
	/*****************************************/

	bool operator < (const Process & obj)const{
		if (this->arrivalTime == obj.getArrivalTime()){
			if (this->serviceTime < obj.getServiceTime())
				return true;
			else
				return false;
		}
		else if (this->arrivalTime < obj.getArrivalTime())
			return true;
		else
			return false;
	}

	friend ostream & operator <<(ostream &, const Process &);
};

ostream & operator << (ostream & out, const Process & obj){
	out << obj.getProcessName() << " " << obj.getArrivalTime() << " " << obj.getServiceTime()
		<< " " << obj.getFinishTime() << " " << obj.getTurnAroundTime() << " " << obj.getWaitingTime();
	return out;
}

// Class Executes Processes
class Execution{
	Queue<Process> processQueue;
	Process *plist;
	int numofProcesses;
	int CLOCK;

public:
	Execution(){
		this->numofProcesses = 0;
		this->CLOCK= 0;
	}

	void sortProcess(){
		bool swap;
		Process temp;
		do{
			swap = false;
			for (int i = 0; i < this->numofProcesses - 1; i++){
				if (plist[i + 1] < plist[i]){
					temp = plist[i];
					plist[i] = plist[i + 1];
					plist[i + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}

	void addtoQueue(){
		for (int i = 0; i < numofProcesses; i++)
			if (plist[i].getArrivalTime() == this->CLOCK)
				this->processQueue.Enqueue(plist[i]);
	}

	void readFile(){
		int timeSclice;
		ifstream in("input.txt");
		in >> numofProcesses;
		plist = new Process[numofProcesses];
		in >> timeSclice;
		for (int i = 0; i < numofProcesses; i++){
			int arrival, service;
			string name;
			in >> name >> arrival >> service;
			plist[i] = Process(name, arrival, service, timeSclice);
		}
		sortProcess();
		in.close();
	}

	void execute(){
		addtoQueue();
		while (!this->processQueue.isEmpty()){
			Process p = this->processQueue.Dequeue();
			p.setRemainingTime(p.getRemainingTime() - p.getTimeSlice());
			CLOCK++;
			if (p.getRemainingTime() == 0){
				p.setFinishTime(this->CLOCK);
				p.setTurnAroundTime();
				p.setWaitingTime();
				this->addtoQueue();
				cout << p<<endl;
			}
			else{
				this->addtoQueue();
				this->processQueue.Enqueue(p);
			}
		}
	}

	~Execution(){
		delete[]plist;
	}
};

int main(){
	Execution e;
	e.readFile();
	e.execute();
	return 0;
}