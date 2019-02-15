//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int totalTime = 0;
//
//class Patient
//{
//	// Data Members
//	int time;
//	int patient_Num;
//public:
//
//	static int serial;  	// static data member to track patient number
//	// Constructors
//	Patient() { time = patient_Num = 0; }
//	Patient(int time) 
//	{
//		this->time = time;
//		this->patient_Num = Patient::serial + 1;
//		Patient::serial++;
//		totalTime += this->time;
//	}
//
//	// Time Access Methods
//	void setTime(int t) { this->time = t; }
//	int getTime()const { return time; }
//
//	// Patient num Acceesors
//	void setPatientNum(int num) { this->patient_Num = num; }
//	int getPatientNum()const { return patient_Num; }
//	
//	// Function for serving Patient
//	void served() 
//	{ 
//		time = time - 5;
//		if ( time <= 0 ) cout << "Patient " << patient_Num << " Competely served \n";
//		else cout << "Patient " << patient_Num << " is served and reamaing time is " << time << " minutes.\n";
//	}
//
//	// Function Shows Time of Patient
//	void showTime() const { cout << "Patient " << patient_Num << " has time: " << time << " minutes.\n"; }
//
//	// Function Shows Time of Patient(New Entered)
//	void entered()const { cout << "Patient " << patient_Num << " is entered and has time " << time<< " minutes.\n"; }
//
//	// Function Tells if Patient is served or not
//	bool isServed() { return (this->time <= 0) ? true : false; }
//};
//int Patient::serial = 0;
//
//// Template QUEUE class //
//template<class T , int size = 5>
//class Queue 
//{
//public:
//	Queue() { first = last = -1; }
//	void enqueue(T);
//	T dequeue();
//	bool isFull()  { return ( first == 0 && last == size - 1 ) || first == last + 1; }
//	bool isEmpty() { return first == -1; }
//	T* getStorage() { return storage; }
//	int getFirst()const { return first; }
//	int getLast()const { return last; }
//private:
//		int first , last;
//		T storage[size];
//};
//
//template<class T , int size>
//void Queue<T , size>::enqueue(T el) {
//	if ( isFull() )   throw ( 1 );
//	if ( last == size - 1 || last == -1 ) {
//		storage[0] = el;
//		last = 0;
//		if ( first == -1 )
//			first = 0;
//	}
//	else storage[++last] = el;
//}
//
//template<class T , int size>
//T Queue<T , size>::dequeue() {
//	if ( isEmpty() )  throw( 0 );
//	T tmp = storage[first];
//	if ( first == last )
//		last = first = -1;
//	else if ( first == size - 1 )
//		first = 0;
//	else first++;
//	return tmp;
//}
//
//int main()
//{
//	srand(time(0));
//	Queue<Patient> PQ;
//	for ( int i = 0; i < 3; i++ )           // Enques 3 objects in Queue
//	{
//		PQ.enqueue(Patient(( rand() % 18 + 3 )));     
//		PQ.getStorage()[i].showTime();
//	}
//
//	try
//	{
//		while ( !PQ.isEmpty() )
//		{
//			PQ.getStorage()[PQ.getFirst()].served();                       // serving patinet
//			if ( !( PQ.getStorage()[PQ.getFirst()].isServed() ) )          // if patine is not completely served
//			{
//				Patient temp = PQ.dequeue();
//				PQ.enqueue(temp);                                    // enquing it again
//			}
//			else PQ.dequeue();                                  // if patient is completely served then enqueing it again.
//
//			if ( !PQ.isFull() && ( rand() % 5 + 1 ) == 3 )       // generating random number for entery of new patinet
//			{
//				PQ.enqueue(Patient(( rand() % 18 + 3 )));
//				PQ.getStorage()[PQ.getLast()].entered();
//			}
//		}
//	}
//	catch ( int k )
//	{
//		if ( k == 1 ) cout << "Patient Queue is Full...\n";
//		else cout << "Patient queue is empty...\n";
//	}
//	cout << "Total " << Patient::serial << " Patients served in " << totalTime << " minutes\n";
//
//	system("pause");
//	return 0;
//}