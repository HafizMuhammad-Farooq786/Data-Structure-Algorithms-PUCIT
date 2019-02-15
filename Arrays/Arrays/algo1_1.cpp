//#include<iostream>
//using namespace std;
//
//void printarray(int *a, int n){
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//}
//
//void BubbleSort(int *array, int n) {
//	bool swapped = true;
//	int j = 0;
//	int temp;
//
//	while (swapped) {
//		swapped = false;
//		j++;
//		for (int i = 0; i < n - j; ++i) {
//			if (array[i] > array[i + 1]) {
//				temp = array[i];
//				array[i] = array[i + 1];
//				array[i + 1] = temp;
//				swapped = true;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int A[100] = { 1, 13, 56, 43, 38, 47, 94, 21, 46, 55, 80, 85, 94, 80, 43, 55, 65,
//		59, 0, 74, 27, 21, 20, 91, 52, 43, 20, 26, 2, 8, 24, 17, 36, 54,
//		91, 10, 39, 89, 38, 46, 32, 40, 4, 39, 54, 21, 24, 60, 67, 10, 64,
//		22, 29, 43, 69, 82, 86, 54, 33, 92, 85, 61, 21, 45, 51, 87, 79, 34,
//		94, 4, 87, 16, 62, 91, 98, 43, 44, 9, 23, 9, 97, 41, 3, 69, 37,
//		12, 92, 66, 7, 80, 69, 21, 48, 98, 51, 85, 45, 19, 64, 20 };
//
//	BubbleSort(A, 100);
//	printarray(A, 100);
//	system("pause");
//	return 0;
//}