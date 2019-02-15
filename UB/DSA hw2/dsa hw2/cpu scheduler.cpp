#include <iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

//*******************Queue********************************//
template<class T, int size = 100>
class Queue {
public:
	Queue() {first = last = -1;}
	bool isFull()  {return (first == 0 && last == size - 1) || first == last + 1;}
	bool isEmpty() {return first == -1;} 

	void displayAll(){
		for (int i = first; i <= last; i++)
			-storage[i];
	}

	void sortQueue(){
		int j;
		for (int i = first; i <= last; i++){
			j = i;
			while (j>0 && storage[j] > storage[j - 1]){
				swap(storage[j], storage[j - 1]);
				j--;
			}
		}
	}
	void enqueue(T);
	T dequeue();

private:
		int first, last;
		T storage[size];
};

template<class T, int size>
void Queue<T, size>::enqueue(T el) {
	if (isFull())   throw (0);
	if (last == size - 1 || last == -1) {
		storage[0] = el;
		last = 0;
		if (first == -1)
			first = 0;
	}
	else storage[++last] = el;
}
template<class T, int size>
T Queue<T, size>::dequeue() {
	if (isEmpty())  throw(0);
	T tmp = storage[first];
	if (first == last)
		last = first = -1;
	else if (first == size - 1)
		first = 0;
	else first++;
	return tmp;
}
//---------------------------------------------------------------------//

//***************************Process Class****************************//
class Process{
private:
	// data memebers
	string processName;
	int executionTime;
	int waitingTime;
	int turnaroundTime;
	int arrivalTime;
	int reaminingTime;
	int executionStartTime;
	int executionEndingTime;

public:
	// sets process name
	void setProcessName(string processName){
		this->processName = processName;
	}

	// sets process exection time
	void setExecutionTime(int executionTime){
		this->executionTime = executionTime;
	}

	// sets process Arrival time
	void setArrivalTime(int time){
		this->arrivalTime = time;
	}

	// sets process execution start time
	void setExecutionStartTime(int time){
		this->executionStartTime = time;
	}

	// sets process execution end Time
	void setExecutionEndTime(int time){
		this->executionEndingTime = time;
	}

	// sets turnAroundTime
	void calcTurnAroundTime(){
		this->turnaroundTime = this->executionEndingTime - this->arrivalTime;
	}

	// Determines WaitingTime 
	void calcWaitingTime(){
		this->waitingTime = this->executionStartTime - this->arrivalTime;
	}

	// sets process remaining time
	void setRemainingTime(int time){
		this->reaminingTime = time;
	}

	// returns process name
	string getProcessName()const{
		return this->processName;
	}

	// returns Execution time
	int getExecutionTime()const{
		return this->executionTime;
	}

	// returns waiting time
	int getWaitingTime()const{
		return this->waitingTime;
	}

	// returns turnAround time
	int getTurnaroundTime()const{
		return turnaroundTime;
	}

	// returns arrival time
	int getArrivalTime()const{
		return this->arrivalTime;
	}

	// returns remaining time
	int getRemainingTime()const{
		return this->reaminingTime;
	}

	// returns Execution start time
	int getExecutionStartTime()const{
		return this->executionStartTime;
	}

	// returns Execution end time
	int getExecutionEndTime()const{
		return this->executionEndingTime;
	}

	//Constructors
	Process(string processName, int executionTime, int arrivalTime){
		this->setProcessName(processName);
		this->setExecutionTime(executionTime);
		this->setArrivalTime(arrivalTime);
		this->setRemainingTime(this->executionTime);
	}

	Process(){}

	void decrRemainingTime(){ this->reaminingTime--; }

	//"=" operator
	Process operator = (Process obj){
		this->processName = obj.getProcessName();
		this->reaminingTime = obj.getRemainingTime();
		this->executionTime = obj.getExecutionTime();
		this->waitingTime = obj.getWaitingTime();
		this->turnaroundTime = obj.getTurnaroundTime();
		this->arrivalTime = obj.getArrivalTime();
		this->executionStartTime = obj.getExecutionStartTime();
		this->executionEndingTime = obj.getExecutionEndTime();
		return *(this);
	}

	// Comparision on base of Execution time
	bool operator > (const Process obj)const{
		return (this->getExecutionTime() > obj.getExecutionTime()) ? true : false;
	}

	// Disaplays info of a process
	void operator - ()const{
		cout << this->getProcessName() << " " << this->getExecutionTime() << endl;
	}

	friend ostream & operator<< (ostream &, const Process &);
};

//overloaded stream insertion operator
ostream & operator<< (ostream &out, const Process &obj){
	out << "Executed Process: " << obj.getProcessName() << " " << obj.getExecutionTime() << " " << obj.getWaitingTime() << " " << obj.getTurnaroundTime() << endl;
	return out;
}
//--------------------------------------------------//

//**********************Execution Class**********************************//
class Execution{
	Queue<Process> processQueue;
	int clock;
	int numOfProcesses;
	double totalTurnTime;
	double totalWaitTime;
public:
	Execution(){
		numOfProcesses = clock = 0;
		totalTurnTime = totalWaitTime = 0.0;
	}

	void wait(){
		cout << "*****************************\n";
		cout << "Press enter to continue: ";
		while (cin.get() != '\n')
				cout << "Press Enter to continue: ";
		cout << "*****************************\n";
	}

	void incClock(){
		clock++;
		if (clock % 15 == 0){
			wait();
			readFile();
		}
	}

	// deletes file's current contents
	void deleteFile(){
		fstream dataFile;
		dataFile.open("readyList.txt", ios::out);
		dataFile.open("readyList.txt", ios::trunc);
		dataFile.close();
	}

	// this function Reads file Contents
	void readFile(){
		fstream dataFile;
		dataFile.open("readyList.txt", ios::in);
		string name="\0";
		int time=NULL;
		while (!dataFile.eof()){
			dataFile >> name;
			dataFile >> time;
			if (name == "\0" && time == NULL)
				break;
			this->processQueue.enqueue(Process(name, time, this->clock));
		}
		dataFile.close();
		processQueue.sortQueue();
		this->deleteFile();
	}

	void incrementTotals(int wait, int turn){
		this->totalTurnTime += turn;
		this->totalWaitTime += wait;
	}

	// Function executes processes
	void startExecution(){
		readFile();
		Process p;
		while (!processQueue.isEmpty()){
			cout << "___________________________________________\n";
			cout << "\tProcess in Ready Queue\n";
			processQueue.displayAll();
			cout << "___________________________________________\n";

			p = processQueue.dequeue();
			int execTime = p.getExecutionTime();
			p.setExecutionStartTime(this->clock);
			for (int i = execTime; i > 0; i--){
				p.decrRemainingTime();
				incClock();
			}

			p.setExecutionEndTime(this->clock);
			p.calcWaitingTime();
			p.calcTurnAroundTime();
			cout << p;
			this->incrementTotals(p.getWaitingTime(), p.getTurnaroundTime());
			this->numOfProcesses++;
		}
	}

	void displayAverages(){
		cout << "\nAverage Turn Around Time: " << this->totalTurnTime / this->numOfProcesses << endl;
		cout << "Average Waiting Time: " << this->totalWaitTime / this->numOfProcesses << endl;
	}
};

int main(){
	Execution e;
	e.startExecution();
	e.displayAverages();
	return 0;
}