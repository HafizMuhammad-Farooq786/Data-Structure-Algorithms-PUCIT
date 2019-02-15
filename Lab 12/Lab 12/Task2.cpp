#include<iostream>
#include<fstream>
using namespace std;

void swap(int &p , int &q)
{
	int temp;
	temp = q;
	q = p;
	p = temp;
}

void printinOrder(int *x , int SIZE , int i)
{
	if ( i < SIZE &&x[i]!=-1)
	{
		printinOrder(x , SIZE , 2 * i + 1);
		cout << x[i] << " ";
		printinOrder(x , SIZE , 2 * ( i + 1 ));
	}
}

void preOrder(int *x , int SIZE , int i)
{
	if ( i < SIZE &&x[i]!=-1)
	{
		cout << x[i] << " ";

		preOrder(x , SIZE , 2 * i + 1);
		
		preOrder(x , SIZE , 2 * ( i + 1 ));
	}
}
void printInvalid(int *x , int SIZE , int i)
{
	if ( i < SIZE )
	{
		if ( x[i] == -1 )
		{
			if ( 2 * i + 1 < SIZE )
				swap(x[i] , x[2 * i + 1]);
			else if ( 2 * ( i + 1 ) < SIZE )
				swap(x[i] ,x[ 2 * ( i + 1 )]);
		}
		printInvalid(x , SIZE , 2 * i + 1);
		printInvalid(x , SIZE , 2 * ( i + 1 ));
	}
}

int main()
{
	int size , value;
	ifstream in("tree.txt");
	in >> size;
	int *x = new int[size];
	for ( int i = 0; i < size; i++ )
	{
		in >> value;
		x[i] = value;
	}
	in.close();
	printInvalid(x , size , 0);
	cout << "IN-ORDER: "; printinOrder(x , size , 0);
	cout << endl;
	cout << "PRE-ORDER: "; preOrder(x , size , 0);
	cout << endl;

	system("pause");
	return 0;
}