#include<iostream>
using namespace std;

int sumArray(int a[] , int size)
{
	if ( size > 0 )
		return a[size - 1] + sumArray(a , size - 1);
	else
		return 0;
}

bool splitArray(int a[] , int size)
{
	if ( size == 0 ) return true;
	if ( size == 1 ) return false;
	if ( size == 2 )
	{
		if ( a[0] == a[1] ) 
			return true;
		else 
			return false;
	}
	if ( sumArray(a , size) % 2 == 0 )
		return true;
	else
		return false;
}

int main()
{
	const int size = 5;
	int a[size] = {1,1,1,1,1};
	if ( splitArray(a , size) )
		cout << "True\n";
	else
		cout << "False\n";
	system("pause");
	return 0;
}