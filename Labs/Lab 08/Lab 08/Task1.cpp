//#include<iostream>
//using namespace std;
//
//int countEvenElements(int *p , int size)
//{
//	if ( size >= 1 )
//	{
//		if ( ( p[size - 1] ) % 2 == 0 ) 
//			return 1 + countEvenElements(p , size - 1);
//		else 
//			return 0 + countEvenElements(p , size - 1);
//	}
//	else return 0;
//}
//
//int main()
//{
//	const int SIZE = 6;
//	int x[SIZE] = { 1 , 2 , 3 , 4 , 5 , 6 };
//	cout << countEvenElements(x , SIZE) << endl;
//	system("pause");
//	return 0;
//}