#include<iostream>
using namespace std;

class MaxHeap
{
	int size, n;
	int *p;
public:

	int parent(int i) const
	{
		return i / 2;
	}

	// constructor
	MaxHeap(int size)
	{
		this->size = size;
		n = 0;
		p = new int [size];
	}

	void insert(int key)
	{
		if ( n < size )
		{
			p[n++] = key;
			int i = n;
			while ( i>0 && p[i] > p[parent(i)] )
			{
				swap(p[i] , p[parent(i)]);;
				i = parent(i);
			}
		}
	}

	void buildHeap()
	{
		for ( int i = n / 2; i >= 0; i-- )
			heapify(i);
	}

	int left(int i)const
	{
		return 2 * i + 1;
	}

	int right(int i)const
	{
		return 2 * ( i + 1 );
	}

	void heapify(int i)
	{
		if ( i >= n ) return;
		int largest = left(i);
		if ( largest >= n ) return;
		if ( largest + 1 < n && p[largest] < p[ largest + 1] )
			largest++;
		if ( p[i] < p[largest] )
		{
			swap(p[i],p[largest]);
			heapify(largest);
		}
	}

	void show()const
	{
		for ( int i = 0; i < n; i++ )
			cout << p[i] << " ";
		cout << endl;
	}

	// revoves priority element from heap
	int remove()
	{
		if ( n == 0 ) throw ( 0 );
		n--;
		int temp = p[0];
		p[0] = p[n];
		heapify(0);
		return temp;
	}

	// destructor
	~MaxHeap()
	{
		delete[]p;
	}
};

int main()
{
	MaxHeap m1(10);
	for ( int i = 0; i < 10; i++ )
		m1.insert(i);
	m1.buildHeap();
	m1.show();
	m1.remove();
	m1.remove();
	m1.remove();
	m1.remove();
	m1.show();
	system("pause");
	return 0;
}