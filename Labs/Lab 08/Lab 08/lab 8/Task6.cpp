#include<iostream>
using namespace std;

void moveDiscs(int num , char fromPeg , char toPeg , char tempPeg)
{
	if ( num > 0 )
	{
		moveDiscs(num - 1 , fromPeg , tempPeg , toPeg);
		cout << "Move a disc " << num << " from " << fromPeg << " to  " << toPeg << endl;
		moveDiscs(num - 1 , tempPeg , toPeg , fromPeg);
	}
}

int main()
{
	moveDiscs(3 , 'A' , 'C' , 'B');
	system("pause");
	return 0;
}