//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int totalTime = 0;
//
//class Patient
//{
//	int time;
//	int p_No;
//public:
//	static int serial_No;
//
//	Patient() 
//	{
//		time = p_No = 0;
//	}
//
//	Patient(int time)
//	{
//		this->time = time;
//		this->p_No = Patient::serial_No + 1;
//		Patient::serial_No++;
//		totalTime += this->time;
//	}
//
//	void setTime(int t) 
//	{
//		this->time = t;
//	}
//
//	int getTime()const 
//	{
//		return time;
//	}
//
//	void setPatientNumber(int num) 
//	{
//		this->p_No = num;
//	}
//
//	int getPatientNumber()const
//	{
//		return p_No;
//	}
//
//	void served()
//	{
//		time = time - 5;
//		if ( time <= 0 ) 
//			cout << "Patient " << p_No << " Competely served \n";
//		else 
//			cout << "Patient " << p_No << " is served and reamaing time is " << time << " minutes.\n";
//	}
//
//
//	void showTime() const 
//	{
//		cout << "Patient " << p_No << " has time: " << time << " minutes.\n";
//	}
//
//	void entered()const
//	{
//		cout << "Patient " << p_No << " is entered and has time " << time << " minutes.\n";
//	}
//
//	
//	bool isServed()const
//	{
//		if ( this->time <= 0 )
//			return true;
//		else
//			return false;
//	}
//};
//int Patient::serial_No = 0;
//
//template<class T , int size = 5>
//class Queue {
//public:
//	Queue() {
//		first = last = -1;
//	}
//	void enqueue(T);
//	T dequeue();
//	bool isFull()  {
//		return ( first == 0 && last == size - 1 ) || first == last + 1;
//	}
//	bool isEmpty() {
//		return first == -1;
//	} 
//
//	T* getQueue() 
//	{
//		return storage;
//	}
//
//	int getFirst()const
//	{
//		return first;
//	}
//
//	int getLast()const
//	{
//		return last;
//	}
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
//	Queue<Patient> p_queue;
//	Patient p1(rand() % 18 + 3);
//	Patient p2(rand() % 18 + 3);
//	Patient p3(rand() % 18 + 3);
//	p_queue.enqueue(p1);
//	p_queue.enqueue(p2);
//	p_queue.enqueue(p3);
//	p_queue.getQueue()[0].showTime();
//	p_queue.getQueue()[1].showTime();
//	p_queue.getQueue()[2].showTime();
//	
//	while ( !p_queue.isEmpty() )
//	{
//		p_queue.getQueue()[p_queue.getFirst()].served();
//		if ( !( p_queue.getQueue()[p_queue.getFirst()].isServed() ) )
//		{
//			Patient temp = p_queue.dequeue();
//				p_queue.enqueue(temp);
//		}
//		else p_queue.dequeue();
//
//		if ( !p_queue.isFull() && ( rand() % 5 + 1 ) == 3 )
//			{
//			p_queue.enqueue(Patient(( rand() % 18 + 3 )));
//			p_queue.getQueue()[p_queue.getLast()].entered();
//		}
//	}
//
//	cout << "Total " << Patient::serial_No << " Patients served in " << totalTime << " minutes\n";
//
//	system("pause");
//	return 0;
//}