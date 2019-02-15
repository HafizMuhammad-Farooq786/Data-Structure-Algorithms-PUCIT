//#include<iostream>
//using namespace std;
//
//int count8s(int n)
//{
//	if ( ( n / 10 == 0 ) && ( n % 10 != 8 ) ) return 0;
//	else
//	{
//		if ( n % 10 == 8 && ( ( n / 10 ) % 10 == 8 ) ) return 2 + count8s(n / 10);
//		else if ( n % 10 == 8 ) return 1 + count8s(n / 10);
//		else return 0 + count8s(n / 10);
//	}
//}
//
//int main()
//{
//	cout << count8s(8388) << endl;
//
//	system("pause");
//	return 0;
//}