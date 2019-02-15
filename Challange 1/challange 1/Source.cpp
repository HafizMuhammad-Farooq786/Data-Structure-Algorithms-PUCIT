//#include <iostream>
//using namespace std;
//
//int findnumber( int *p , const int size , int last , int lastindex )
//{
//	for ( int i = lastindex; i < size; i++ )
//		if (   i != last && p [i] == 4 )
//			return i;
//}
//
//int* fix34( int *a , const int size )
//{
//	int tempIndex , temp , last = -1 , lastIndex = 0;
//	for ( int i = 0; i < size-1 ; i++ )
//	{
//		if ( ( a [i] == 3 ) && ( a [i + 1] != 4 ) )
//		{
//			lastIndex = tempIndex = findnumber( a , size , last , lastIndex );
//			temp = a [i + 1];
//			a [i + 1] = 4;
//			a [tempIndex] = temp;
//			last = i + 1;
//		}
//	}
//	return a;
//}
//
//void show( int *p , const int size )
//{
//	for ( int i = 0; i < size; i++ )
//		cout << p [i] << " ";
//	cout << endl;
//}
//
//int main()
//{
//	const int size = 6;
//	int arr [size] = { 3 , 1 , 1 , 3 , 4 , 4 };
//	int *p = fix34( arr , size);
//	show( p , size );
//
//	system( "pause" );
//	return 0;
//}