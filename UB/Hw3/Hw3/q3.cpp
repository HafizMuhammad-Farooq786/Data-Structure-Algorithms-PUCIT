//#include<iostream>
//using namespace std;
//
//int findSpecial(int *A, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (A[i] == A[j])
//				count++;
//		}
//		if (count == 1)
//			return A[i];
//	}
//}
//
//int findSpecial2(int *A, int n)
//{
//	if (A[0] != A[1]) 
//		return A[0];
//	else if (A[n - 1] != A[n - 2]) 
//		return A[n - 1];
//	else
//	{
//		for (int i = 1; i < n - 1; i++)
//		{
//			if ((A[i] != A[i - 1]) && (A[i] != A[i + 1]))
//				return A[i];
//		}
//	}
//}
//
//int main()
//{
//	int a[] = { 9, 2, 3, 1, 4, 4, 3, 1, 2, 10, 9 };
//	int b[] = { 8, 8, 8, 8, 7, 7, 4, 4, 3, 2, 2 };
//	cout << findSpecial(a, 11) << endl;
//	cout << findSpecial2(b, 11) << endl;
//	return 0;
//}