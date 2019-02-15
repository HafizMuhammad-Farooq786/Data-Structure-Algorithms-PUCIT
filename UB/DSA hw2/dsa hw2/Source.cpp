//#include <iostream>
//#include<string>
//#include <list>
//#include<fstream>
//#include<cctype>
//using namespace std;
//
//// -----Process Class-----------//
//class Process{
//private:
//	// data memebers
//	string processName;
//	int executionTime;
//	int waitingTime;
//	int turnaroundTime;
//	int arrivalTime;
//	int reaminingTime;
//	int executionStartTime;
//	int executionEndingTime;
//
//public:
//	// sets process name
//	void setProcessName(string processName){
//		this->processName = processName;
//	}
//
//	// sets process exection time
//	void setExecutionTime(int executionTime){
//		this->executionTime = executionTime;
//	}
//
//	// sets process Arrival time
//	void setArrivalTime(int time){
//		this->arrivalTime = time;
//	}
//
//	// sets process execution start time
//	void setExecutionStartTime(int time){
//		this->executionStartTime = time;
//	}
//
//	// sets process execution end Time
//	void setExecutionEndTime(int time){
//		this->executionEndingTime = time;
//	}
//
//	// sets turnAroundTime
//	void calcTurnAroundTime(){
//		this->turnaroundTime = this->executionEndingTime - this->arrivalTime;
//	}
//
//	// Determines WaitingTime 
//	void calcWaitingTime(){
//		this->waitingTime = this->executionStartTime - this->arrivalTime;
//	}
//
//	// sets process remaining time
//	void setRemainingTime(int time){
//		this->reaminingTime = time;
//	}
//
//	// returns process name
//	string getProcessName()const{
//		return this->processName;
//	}
//
//	// returns Execution time
//	int getExecutionTime()const{
//		return this->executionTime;
//	}
//
//	// returns waiting time
//	int getWaitingTime()const{
//		return this->waitingTime;
//	}
//
//	// returns turnAround time
//	int getTurnaroundTime()const{
//		return turnaroundTime;
//	}
//
//	// returns arrival time
//	int getArrivalTime()const{
//		return this->arrivalTime;
//	}
//
//	// returns remaining time
//	int getRemainingTime()const{
//		return this->reaminingTime;
//	}
//
//	// returns Execution start time
//	int getExecutionStartTime()const{
//		return this->executionStartTime;
//	}
//
//	// returns Execution end time
//	int getExecutionEndTime()const{
//		return this->executionEndingTime;
//	}
//
//	//Constructors
//	Process(string processName, int executionTime,int arrivalTime){
//		this->setProcessName(processName);
//		this->setExecutionTime(executionTime);
//		this->setArrivalTime(arrivalTime);
//		this->setRemainingTime(this->executionTime);
//	}
//
//	Process(){
//
//	}
//
//	void decrRemainingTime(){
//		this->reaminingTime--;
//	}
//
//	//"=" operator
//	Process operator = (Process obj){
//		this->processName = obj.getProcessName();
//		this->reaminingTime = obj.getRemainingTime();
//		this->executionTime = obj.getExecutionTime();
//		this->waitingTime = obj.getWaitingTime();
//		this->turnaroundTime = obj.getTurnaroundTime();
//		this->arrivalTime = obj.getArrivalTime();
//		this->executionStartTime = obj.getExecutionStartTime();
//		this->executionEndingTime = obj.getExecutionEndTime();
//		return *(this);
//	}
//
//	bool operator > (const Process obj)const{
//		return (this->getExecutionTime() > obj.getExecutionTime()) ? true : false;
//	}
//
//	void display(){
//		cout << this->getProcessName() << " " << this->getExecutionTime() << endl;
//	}
//
//	friend ostream & operator<< (ostream &, const Process &);
//};
//
////overloaded stream insertion operator
//ostream & operator<< (ostream &out, const Process &obj){
//	out << obj.getProcessName() << " " << obj.getExecutionTime() << " " << obj.getWaitingTime() << " " << obj.getTurnaroundTime() << endl;
//	return out;
//}
//
//bool compare_nocase(const Process & first, const Process & second)
//{
//	if (first > second)
//		return true;
//	else
//		return false;
//}
//
////class handles ececution of processes
//class ProcessExecution{
//private:
//	list<Process> ProcessList;
//	int clock;
//	int numOfProcesses;
//	double totalTurnTime;
//	double totalWaitTime;
//
//public:
//	
//	// Constructor
//	ProcessExecution(){
//		this->clock = 0;
//		this->totalTurnTime = 0.0;
//		this->totalWaitTime = 0.0;
//		this->numOfProcesses = 0;
//	}
//
//	int getClock(){
//		return this->clock;
//	}
//
//	void incrementTotals(int wait,int turn){
//		this->totalTurnTime += turn;
//		this->totalWaitTime += wait;
//	}
//
//	void incrementClock(){
//		clock++;
//	}
//
//	// this function displays contents of processList
//	void displayProcessList(){
//		list<Process>::iterator iter;
//		for (iter = ProcessList.begin(); iter != ProcessList.end(); iter++)
//			iter->display();
//	}
//
//	// this function deletes contents of file
//	void deleteFile(){
//		fstream dataFile;
//		dataFile.open("readyList.txt", ios::trunc);
//		dataFile.close();
//	}
//
//	void displayAverages(){
//		cout << "Average Turn Around Time: "<<this->totalTurnTime/this->numOfProcesses<<endl;
//		cout << "Average Waiting Time: " << this->totalWaitTime / this->numOfProcesses<<endl;
//	}
//
//	// this function Reads file Contents
//	void readFile(){
//		fstream dataFile;
//		dataFile.open("readyList.txt", ios::in);
//		string name;
//		int time;
//		while (!dataFile.eof()){
//			dataFile >> name;
//			dataFile >> time;
//			this->ProcessList.push_front(Process(name, time, this->clock));
//		}
//		dataFile.close();
//		this->deleteFile();
//	}
//
//	void startExecution(){
//		readFile();
//		this->ProcessList.sort(compare_nocase);
//		while (!this->ProcessList.empty()){
//			int execTime = this->ProcessList.front().getExecutionTime();
//			this->ProcessList.front().setExecutionStartTime(this->clock);
//			for (int i = execTime; i > 0; i--){
//				this->ProcessList.front().decrRemainingTime();
//				this->incrementClock();
//			}
//			this->ProcessList.front().setExecutionEndTime(this->clock);
//			this->ProcessList.front().calcWaitingTime();
//			ProcessList.front().calcTurnAroundTime();
//			cout << this->ProcessList.front();
//			this->displayProcessList();
//			this->incrementTotals(this->ProcessList.front().getWaitingTime(), this->ProcessList.front().getTurnaroundTime());
//			this->numOfProcesses++;
//			this->ProcessList.pop_front();
//		}
//	}
//};
//
//
//int main(){
//	ProcessExecution e;
//	e.startExecution();
//	e.displayAverages();
//}