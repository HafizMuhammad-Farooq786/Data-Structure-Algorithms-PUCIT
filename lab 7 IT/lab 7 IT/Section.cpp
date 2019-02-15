#include<iostream>
#include<string>
using namespace std;

void numbers(string &prifix , int level)
{
	if ( level == 0 )
		cout << prifix << endl;
	else
	{
		numbers(prifix + "1." , level - 1);
		numbers(prifix + "2." , level - 1);
		numbers(prifix + "3." , level - 1);
		numbers(prifix + "4." , level - 1);
		numbers(prifix + "5." , level - 1);
		numbers(prifix + "6." , level - 1);
		numbers(prifix + "7." , level - 1);
		numbers(prifix + "8." , level - 1);
		numbers(prifix + "9." , level - 1);
	}
}

int main()
{
	string a = "THERBLIG";
	numbers(a , 3);
	system("pause");
	return 0;
}