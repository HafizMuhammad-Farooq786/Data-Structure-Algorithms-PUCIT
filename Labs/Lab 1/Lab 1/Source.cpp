#include<iostream>
using namespace std;

// Selection Sort 
void SelectionSort(int* A, int n)
{
	int start=0;			// 1
	int  minIndex=0;		//1
	int minValue;
	while ( start < (n - 1))		//n times
	{
		minIndex = start;			// n-1 times
		minValue = A[start];		// n-1 times
		int i= start+1;				// n-1 times
		while ( i < n )          
		{
			if (A[i] < minValue)
			{
				minValue = A[i];
				minIndex = i;
			}
			i++;
		}
		A[minIndex] = A[start];		// n-1 times
		A[start] = minValue;       //  n-1 times
		start++;				  //   n-1 times
	}
}

void BubbleSort (int *A, int n)
{
	bool swap;
	int temp;
	do
	{
		swap = false;
		for (int i = 0; i < (n - 1); i++)
		{
			if (A[i] > A[i+ 1])
			{
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

// insertion Sort
void InsertionSort(double* A, int n)
{
	int i=0,j=1;
	while ( j < n )
	{
		double key = A[j];
		while (i >= 0 && key < A[i] )
		{
			A [i+1] = A[i];
			i--;
		}
		A[i+1] = key;
		j++;
		i = j-1;
	}
}

// Show Functiion that displays an Array of integers
void show (double *p, int n)
{
	for (int i=0;i<n;i++)
		cout<<p[i]<<endl;
}

// function to take input in array
void input (int *p, int n)
{
	for (int i=0; i < n ;i++)
		cin>>p[i];
}

int main ()
{
	double x[32]={79.4,75.2,88.1,58.3,71.6,81.9,77.8,48.6,95.5,68.9,69.4,83.5,73.0,74.2,83.2,70.8,74.2,80.7,82.7,72.1,81.8,65.7,73.8,71.6,90.6,67.6,64.2,59.4,55.9,82.9,63.9,77.6};
	InsertionSort(x,32);
	show(x,32);
	system("pause");
	return 0;
}
//int main ()
//{
//	int a[10]={1,5,-6,7,9,8,10,3,4,2};
//	//InsertionSort (a,10);
//	/*SelectionSort (a,10);*/
//	BubbleSort (a,10);
//	show (a,10);			// dfunction to show Array
//
//	int size;
//	int *p;
//	cout <<"Enter size of Array: ";
//	cin>>size;
//	p=new int[size];
//	cout<<"Enter Values in array\n";
//	input (p,size);			// function to takeinput in Array
//
//	int choice;
//	cout <<"1. Selection Sort\n";
//	cout <<"2. Bubble Sort\n";
//	cout <<"3. insertion Sort\n";
//
//	cout<<"Enter 1,2 or 3 to sort: ";
//	cin>>choice;
//	if (choice==1)
//	{
//		SelectionSort (p,size);
//		cout<<"Array after Sorting\n";
//		show(p,size);
//	}
//
//	else if (choice==2)
//	{
//		BubbleSort (p,size);
//		cout<<"Array after Sorting\n";
//		show(p,size);
//	}
//
//	else if (choice==3)
//	{
//		InsertionSort (p,size);
//		cout<<"Array after Sorting\n";
//		show(p,size);
//	}
//
//	cout<<endl;
//	delete[]p;
//
//	system ("pause");
//	return 0;
//}