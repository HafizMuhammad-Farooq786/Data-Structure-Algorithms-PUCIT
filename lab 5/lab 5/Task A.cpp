#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

template<class T>
class Queue {
public:
	Queue( int size = 20 )
	{
		first = last = -1;
		if ( size < 20 )	size = 20;
		this->size = size;
		storage = new T [size];
		count = 0;
	}

	void enqueue( T );
	T dequeue();

	bool isFull()   const { return ( count == size ); }

	bool isEmpty()  const { return count == 0; }

	int getSize() const { return count; }

	void show() const
	{
		for ( int i = 0; i < count; i++ )
			cout << storage [i] << " ";
		cout << endl;
	}
private:
	int first , last , size , count;
	T *storage;
};

template<class T>
void Queue<T>::enqueue( T el )
{
	if ( isFull() )   throw ( 1 );
	count++;
	if ( last == size - 1 || last == -1 ) {
		storage [0] = el;
		last = 0;
		if ( first == -1 )
			first = 0;
	}
	else storage [++last] = el;
}

template<class T>
T Queue<T>::dequeue()
{
	if ( isEmpty() )  throw( 2 );
	count--;
	T tmp = storage [first];
	if ( first == last )
		last = first = -1;
	else if ( first == size - 1 )
		first = 0;
	else first++;
	//    cout<<"First is at:"<<first<<' '<<"Value at first is:"<<storage[first]<<'\n';
	return tmp;
}

// Function returns index of suitable value
int findEmployee( string p[] , int size , string str )
{
	for ( int i = 0; i < size; i++ )
	if ( p [i] == str )
		return i;
	return -1;
}

void showHouses( string p[] , int size )
{
	for ( int i = 0; i < size; i++ )
		cout << p [i] << " ";
	cout << endl;
}


int main()
{
	//***********************************************
	//					Task A
	//***********************************************
	string small_house [30] , big_house [10];
	ifstream in( "residences.in" );
	cout << "BIg houses \n";			// Printing big houses
	for ( int i = 0; i < 10; i++ )
	{
		in >> big_house [i];
		cout << big_house [i] << " ";
	}

	cout << endl << "Small hoses \n";		// Printing Small houses
	for ( int i = 0; i < 30; i++ )
	{
		in >> small_house [i];
		cout << small_house [i] << " ";
	}
	cout << endl;
	in.close();

	Queue <string> small_Queue;
	Queue <string> big_Queue;

	ifstream in2 ( "queue.in" );
	string emp;
	for ( int i = 0; i < 4; i++ )
	{
		in2 >> emp;
		big_Queue.enqueue( emp );
	}
	cout << "Big house qeue\n";
	big_Queue.show ();			// Printing big houses queue

	for ( int i = 0; i < 6; i++ )
	{
		in2 >> emp;
		small_Queue.enqueue( emp );
	}
	cout << "Small Hose Queue \n";
	small_Queue.show ();				// Printing small houses queue
	in2.close ();

	//***********************************************
	//					End Task A
	//***********************************************

	//***********************************************
	//					 Task B
	//***********************************************

	/*ifstream in3 ("emp.in");
	for (int i=0;i<20;i++)
	{
	in>>emp;
	if (findEmployee(small_house,30,emp)!=-1)			// checking in small hoses array
	{
	small_house[findEmployee(small_house,30,emp)]=small_Queue.dequeue();
	}
	else if (findEmployee(big_house,10,emp)!=-1)		// checking in big houses array
	{
	big_house[findEmployee(big_house,10,emp)]=big_Queue.dequeue();
	}
	else
	small_Queue.enqueue(emp);				// storing in small queue
	}
	in3.close();*/

	//***********************************************
	//					End Task B
	//***********************************************



	//***********************************************
	//					 Task C
	//***********************************************
	ofstream out ( "residences.out" );		// opening file for writing arrays
	for ( int i = 0; i < 10; i++ )
		out << big_house [i] << "\n";

	for ( int i = 0; i < 30; i++ )
		out << small_house [i] << "\n";

	out.close ();

	ofstream out2 ( "queue.out" );
	out2 << small_Queue.getSize() << " " << big_Queue.getSize() << "\n";			// wrting metadata
	int j = small_Queue.getSize() , k = big_Queue.getSize();

	for ( int i = 0; i < j; i++ )			// Writing small queuq
		out2 << small_Queue.dequeue() << "\n";

	for ( int i = 0; i < k; i++ )			// Writing small queuq
		out2 << big_Queue.dequeue() << "\n";
	out2.close();


	//***********************************************
	//					End Task C
	//***********************************************

	system ( "pause" );
	return 0;
}