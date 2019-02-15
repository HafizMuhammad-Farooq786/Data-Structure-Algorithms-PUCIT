#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int size = 32 * 4;
//int hashfunction(string s)
//{
//	return(int) ( ( int ) s[s.length() - 1] * ( int ) s[0] * ( int ) s[s.length() - 2] + s.length() ) % 96;
//}

int hashfunction(string str)
{
	int sum = 0;
	for ( int i = 0; i < str.length(); i++ )
		sum = sum + str[i] * (i+4);
	sum = sum - str.length();
	return sum % size;
}

int main()
{
	string w;
	int hash;
	int count = 0;
	
	string *p = new string[size] ;
	for ( int i = 0; i < size; i++ )
		p[i] = "";
	ifstream in("keywords.txt");
	for ( int i = 0; i < 32; i++ )
	{
		in >> w;
		hash = hashfunction(w);
		if ( p[hash] != "" )
			count++;
		p[hash] = w;
	}
	in.close();
	cout << "Collisions are: " << count << endl; 

	/*for ( int i = 0; i < 64; i++ )
		cout << p[i] << " ";
	cout << endl;*/
	

	/*int count = 0;
	ifstream in2("keywords.txt");
	for ( int i = 0; i < 32; i++ )
	{
		in2 >> w;
		if ( p[hashfunction(w)] == w )
		{
			cout << w << "\t" << hashfunction(w) << endl;
			count++;
		}
	}
	in2.close();
	cout << count << endl;
	cout << "Collisions are: " << 32 - count << endl;*/

	system("pause");
	return 0;
}