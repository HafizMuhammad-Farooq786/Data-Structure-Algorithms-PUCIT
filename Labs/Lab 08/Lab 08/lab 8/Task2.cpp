//#include<iostream>
//using namespace std;
//
//int countAdjacent(int *p , int size)
//{
//	if ( size >= 2 )
//	{
//		if ( p[size - 1] > p[size - 2] )
//			return 1 + countAdjacent(p , size - 1);
//		else
//			return 0 + countAdjacent(p , size - 1);
//	}
//	else return 0;
//}
//
//int main()
//{
//	const int SIZE = 6;
//	int x[SIZE] = { 1 , 5 , 3 , 4 , 5 , 6 };
//	cout << countAdjacent(x , SIZE) << endl;
//	system("pause");
//	return 0;
//}