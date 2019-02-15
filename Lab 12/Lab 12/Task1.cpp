//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//void print(int *x , int SIZE , int i)
//{
//	if ( i < SIZE )
//	{
//		print(x , SIZE , 2 * i + 1);
//		cout << x[i] << " ";
//		print(x , SIZE , 2 * ( i + 1 ));
//	}
//}
//
//void printInvalid(int *x , int SIZE , int i)
//{
//	if ( i < SIZE )
//	{
//		if ( x[i] == -1 )
//		{
//			print(x , SIZE , i);
//		}
//		printInvalid(x , SIZE , 2 * i + 1);
//		printInvalid(x , SIZE , 2 * ( i + 1 ));
//	}
//}
//
//int main()
//{
//	int size , value;
//	ifstream in("tree.txt");
//	in >> size;
//	int *x = new int[size];
//	for ( int i = 0; i < size; i++ )
//	{
//		in >> value;
//		x[i] = value;
//	}
//	in.close();
//	printInvalid(x , size , 0);
//
//	system("pause");
//	return 0;
//}