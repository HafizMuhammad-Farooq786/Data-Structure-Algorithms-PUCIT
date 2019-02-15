#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

bool isBalance(int number)
{
	int sum = 0 , count = 0;
	while ( number != 0 )
	{
		sum = sum + ( number % 10 );
		number = number /10;
		count++;
	}
	if ( count % 2 == 0 )
		return  ( sum % 2 == 0 ) ? true : false;
	else 
		return false;
}

int main()
{
	bool result;
	int n;
	srand(time(0));
	ofstream out("out.txt");
	for ( int i = 1; i <=100; i++ )
	{
		n = rand() % 10000000;
		result = isBalance(n);
		out << n << " " << result << "\n";
	}
	out.close();

	ifstream in("out.txt");
	for ( int i = 1; i <= 100; i++ )
	{
		in >> n >> result;
		cout << n << "\t" << result << "\n";
	}
	in.close();
	system("pause");
	return 0;
}