#include<iostream>
#include<ctime>
using namespace std;

void toBinary(int n)
{
	if ( n != 0 )
	{
		toBinary(n / 2);
		cout << n % 2;
	}
}

int main()
{
	srand(time(0)); 
	int n = rand() % 50;
	cout << n << " ";
	toBinary(n);
	cout << endl;

	system("pause");
	return 0;
}