//#include<iostream>
//using namespace std;
//#define SEN -1
//
//int Max(int left , int right)
//{
//	if ( left > right )
//		return left;
//	else 
//		return right;
//}
//
//int findHieght(int *x,int i,int SIZE)
//{
//	if ( i < SIZE &&x[i] != SEN )
//		return 1 + Max(findHieght(x , 2 * i + 1 , SIZE) , findHieght(x , 2 * ( i + 1 ) , SIZE));	
//	else
//		return 0;
//}
//
//int main()
//{
//	int x[] = { 8 , 3 , 10 , 1 , 6 , SEN , 14 , SEN , SEN , 4 , 7 , SEN , SEN , 13 , SEN };
//	cout << "Hieght of tree is: "<<findHieght(x,0,15)<<endl;
//	system("pause");
//	return 0;
//}