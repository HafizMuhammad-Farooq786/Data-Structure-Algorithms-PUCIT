//#include<iostream>
//using namespace std;
//
//
//int longestRun(int a[] , int size , int index)
//{
//	if ( index < size-1 && a[index] != NULL )
//	{
//		if ( a[index + 1] == a[index] )
//			return 1 + longestRun(a , size , index + 1);
//		else
//			return longestRun(a , size , index + 1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	const int SIZE = 20;
//	int x[SIZE] = { 1, 2, 5, 5, 3, 1, 2, 4, 3, 2, 2, 2, 2, 3, 6, 5, 5, 6, 3, 1 };
//	cout << longestRun(x , SIZE , 0) << endl;
//
//	return 0;
//}