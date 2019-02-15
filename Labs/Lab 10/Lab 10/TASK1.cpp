#include<iostream>
using namespace std;
#define SEN -1

void inOrder(int *x , int i , int SIZE)
{
	if ( i < SIZE &&x[i] != SEN )
	{
		inOrder(x , 2 * i + 1 , SIZE);
		cout << x[i] << " ";
		inOrder(x , 2 * ( i + 1 ) , SIZE);
	}
}

void preOrder(int *x , int i , int SIZE)
{
	if ( i < SIZE &&x[i] != SEN )
	{
		cout << x[i] << " ";
		preOrder(x , 2 * i + 1 , SIZE);
		preOrder(x , 2 * ( i + 1 ) , SIZE);
	}
}

void postOrder(int *x , int i , int SIZE)
{
	if ( i < SIZE &&x[i] != SEN )
	{
		postOrder(x , (2 * i) + 1 , SIZE);
		postOrder(x , 2 * ( i + 1 ) , SIZE);
		cout << x[i] << " ";
	}
}

int main()
{
	int x[15] = { 8 , 3 , 10 , 1 , 6 , SEN, 14 , SEN , SEN , 4 , 7 , SEN , SEN , 13 , SEN };

	cout << "in Order: "; inOrder(x , 0 , 15);
	cout << endl;
	cout << "pre Order: "; preOrder(x , 0 , 15);
	cout << endl;
	cout << "post Order: "; postOrder(x , 0 , 15);
	cout << endl;
	system("pause");
	return 0;
}