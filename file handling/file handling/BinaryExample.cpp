#include<iostream>
#include<fstream>
using namespace std;

void printArray(int *x , const int SIZE) 
{
	for (int i = 0; i<SIZE; i++ )
		cout << x[i] << ' ';
	cout << '\n';
}

int main() 
{
	ofstream out1("abc.txt");
	ofstream out2("abc.bin" , ios::binary);
	const int SIZE = 10;
	int i , x[SIZE] = { 2 , 5 , 1 , 9 , 8 , 6 , 4 , 3 , 7 , 0 } , y[SIZE];
	for ( i = 0; i<SIZE; i++ )
		out1 << x[i] << ' ';
	out2.write(( char* )x , sizeof( int )*SIZE);
	out1.close();
	out2.close();
	ifstream in1("abc.bin" , ios::binary);
	in1.read(( char* )y , sizeof( int )*SIZE);
	cout << "Array X:";
	printArray(x , SIZE);
	cout << "\nArray Y:";
	printArray(y , SIZE);
	system("pause");

	return 0;
}