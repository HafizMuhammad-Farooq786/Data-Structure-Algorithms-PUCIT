#include<iostream>
#include<ctime>
using namespace std;
#define SEN -99 

class BST
{
	int SIZE;
	int *x;

	void showInorder(int index)
	{
		if ( index < SIZE &&x[index] != SEN )
		{
			showInorder(2 * index + 1);
			cout << x[index] << " ";
			showInorder(2 * ( index + 1 ));
		}
	}



	bool insertElement(int val , int index)
	{
		if ( index >= SIZE ) 
			return false;
		if ( x[index] == SEN )
		{
			x[index] = val;
			return true;
		}

		if ( x[index] > val ) 
			return insertElement(val , 2 * index + 1);
		else
			return insertElement(val , 2 * ( index + 1 ));
	}

	bool searchElement(int val , int index)
	{
		if ( index >= SIZE ) return false;
		if ( x[index] == val)
			return true;

		if ( x[index] > val ) return searchElement(val , 2 * index + 1);
		else return searchElement(val , 2 * ( index + 1 ));
	}

public:
	BST(int size) 
	{
		this->SIZE = size;
		x = new int[SIZE];
		for ( int i = 0; i < SIZE; i++ )
			x[i] = -99;
	}

	bool insertElement(int value)
	{
		return insertElement(value , 0);
	}

	bool search(int value)
	{
		return searchElement(value , 0);
	}

	void showInorder()
	{
		showInorder(0);
	}

};

int main()
{
	srand(time(0));
	BST t1(10);
	for ( int i = 0; i < 10; i++ )
		t1.insertElement(rand ()%100);
	t1.showInorder();

	system("pause");
	return 0;
}