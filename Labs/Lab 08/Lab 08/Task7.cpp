//#include<iostream>
//using namespace std;
//
//int binarySearch(int array[] , int first , int last , int key)
//{
//	int middle;
//	if ( first > last )   return -1;
//	middle = ( first + last ) / 2;
//	if ( array[middle] == key )
//		return middle;
//	if ( array[middle] < key )
//		return binarySearch(array , middle + 1 , last , key);
//	else
//		return binarySearch(array , first , middle - 1 , key);
// }
//
//int main()
//{
//	const int SIZE = 6;
//	int x[SIZE] = { 1 , 2 , 3 , 4 , 5 , 6 };
//	cout << binarySearch(x , 1 , 6 , 5) << endl;
//	system("pause");
//	return 0;
//}