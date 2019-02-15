#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class patient
{
	int time;
	int s_no;
public:
	patient()
	{
		set_time(0);
		set_s_no(0);
	}
	patient(int time , int s_no)
	{
		set_time(time);
		set_s_no(s_no);
	}

	void set_time(int time){ this->time = time; }
	int get_time(){ return time; }
	void set_s_no(int s_no){ this->s_no = s_no; }
	int get_s_no(){ return s_no; }
	void enter()const { cout << "patient " << s_no << " is entered and has time " << time << " minute" << endl; }
	friend ostream &operator<<( ostream &output , const patient  & pt );
	friend istream &operator>>( istream  &input , patient  &pt );
};

ostream &operator<<( ostream &output , const patient  & pt ) {
	if (pt.time<=0)
		output << "patient " << pt.s_no << " is completely served" << endl;
	else
		output << "patient " << pt.s_no << " is served remaining time " << pt.time << " minute " << endl;
	return output;
}
istream &operator>>( istream  &input , patient  &pt ) {
	input >> pt.time; 
	return input;
}


template<class T>
class Queue {
public:
	Queue(int size = 5) {
		first = last = -1;
		if ( size < 5 )
			size = 5;
		this->size = size;
		storage = new T[size];
		count = 0;
	}
	void enqueue(T);
	T dequeue();
	bool isFull()   const
	{
		return ( count == size );
	}
	bool isEmpty()  const
	{
		return count == 0;
	}
	int getSize() const
	{
		return count;
	}
private:
	int first , last , size , count;
	T *storage;
};
template<class T>
void Queue<T>::enqueue(T el) {
	if ( isFull() )
		throw ( 1 );
	count++;
	if ( last == size - 1 || last == -1 )
	{
		storage[0] = el;
		last = 0;
		if ( first == -1 )
			first = 0;
	}
	else storage[++last] = el;
}
template<class T>
T Queue<T>::dequeue() {
	if ( isEmpty() )
		throw( 2 );
	count--;
	T tmp = storage[first];
	if ( first == last )
		last = first = -1;
	else if ( first == size - 1 )
		first = 0;
	else first++;
	//    cout<<"First is at:"<<first<<' '<<"Value at first is:"<<storage[first]<<'\n';
	return tmp;
}

int main()
{
	// you did well only problem was sequence and serial no 
	//of patient & decrement of time. i have fixed it. and instructions were about randoms so i also have fixed that.
	// great job.......!!!!!!

	srand(time(0));
	patient p1(rand() % 18 + 3 , 1);
	cout << "Patient " << p1.get_s_no() << " has time " << p1.get_time() << " minutes " << endl;
	patient p2(rand() % 18 + 3 , 2);
	cout << "Patient " << p2.get_s_no() << " has time " << p2.get_time() << " minutes " << endl;
	patient p3(rand() % 18 + 3 , 3);
	cout << "Patient " << p3.get_s_no() << " has time " << p3.get_time() << " minutes " << endl;

	Queue<patient>obj;
	obj.enqueue(p1);
	obj.enqueue(p2);
	obj.enqueue(p3);
	int i = 3;

	while ( !obj.isEmpty() )
	{
		patient time = obj.dequeue();
		time.set_time(time.get_time() - 5);    // time should be decremented because its dequeued
		if ( time.get_time() > 0 )            // if requires more time enqueue it again
		{
			obj.enqueue(patient(time.get_time(),time.get_s_no()));
		}

		cout << time;             // served patient status 

		int c = ( rand() % 5 ) + 1;
		if ( c == 3 && !obj.isFull())     // entering new patient
		{
			i++;
			patient pt(rand() % 18 + 3 , i);
			obj.enqueue(pt);
			pt.enter();
		}
	}

	system("pause");
	return 0;
}