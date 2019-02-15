//# include<iostream>
//#include <ctime>
//using namespace std;
//int main ()
//{
//	const int size=100;
//	int x[size];
//	srand(time(0));
//	for (int i=0;i<size ;i++)
//	{
//		x[i]=rand()%10;
//		cout<<x[i]<<" ";
//	}
//	cout<<endl<<"After sorting \n";
//
//	int startScan, minIndex,minValue;
//	for (startScan=0;startScan<size-1;startScan++)
//	{
//		minIndex=startScan;
//		minValue=x[startScan];
//		for (int i=startScan+1;i<size;i++)
//		{
//			if (x[i]<minValue)
//			{
//				minValue=x[i];
//				minIndex=i;
//			}
//		}
//		x[minIndex]=x[startScan];
//		x[startScan]=minValue;
//	}
//
//	for (int i=0;i<size;i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
//
//	system ("pause");
//	return 0;
//}