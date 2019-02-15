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
//	bool Swap;
//	do
//	{
//		Swap=false;
//		for(int i=0;i<size-1;i++)
//		{
//			if (x[i]>x[i+1])
//			{
//				swap(x[i],x[i+1]);
//				Swap=true;
//			}
//		}
//	}while(Swap);
//
//	for (int i=0;i<size;i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
//
//	system ("pause");
//	return 0;
//}