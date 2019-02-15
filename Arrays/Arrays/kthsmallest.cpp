//#include<iostream>
//using namespace std;
//
//int kthSmallest(int a[], int size, int k)
//{
//	
//	int count = 0;
//	int i = 0;
//	while (count != k && i < size - 1)
//	{
//		if (a[i] < a[i + 1])
//			count++;
//		i++;
//	}
//	small = a[i-1];
//	
//
//
//	/*for (int i = 0; i < size-1; i++){
//		if (count != k)
//		{
//			if (a[i] < a[i + 1] && count != k)
//				count++;
//		}
//		else
//			small = a[i];
//
//	}*/
//	return small;
//
//}
//
//int main()
//{
//	const int SIZE = 7;
//	int A[SIZE] = { 1, 10, 9, 4, 5, 7, 8 };
//	
//	cout << kthSmallest(A, SIZE, 4);
//	system("pause");
//	return 0;
//}