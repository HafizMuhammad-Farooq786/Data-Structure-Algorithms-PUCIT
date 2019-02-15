#include<iostream>
#include<fstream>
#include<string>
#include"Costumer.h"
#include"Admin.h"
#include"DoubleList.h"
using namespace std;

void MainMenue()
{
	cout << "\t***********************************************\n";
	cout << "                      A.T.M. Main Menue\n";
	cout << "\t***********************************************\n";
	cout << endl;
	cout << "PLEASE ENTER YOUR CHOICE TO CONTINUE\n";
	cout << "\t1: ADMIN LOGIN\n";
	cout << "\t2: USER LOGIN\n";
	cout << "\t3: EXIT\n";
}

void writeFiles(DDLIST<Costumer>&list , Admin &admin,int &count)
{
	fstream out("Accounts.txt");
	out << count << '\n';
	for ( int i = 0; i < count; i++ )
		out << list.delfirst();
	out.close();
	fstream out2("admin.txt");
	out << admin;
	out2.close();
}

void readFiles(DDLIST<Costumer>&list , Admin &admin , int &count)
{
	Costumer temp; Admin ad;
	fstream in("Accounts.txt");
	in >> count;
	for ( int i = 0; i < count; i++ )
	{
		in >> temp;
		list.addAtstart(temp);
	}
	in.close();
	fstream in1("admin.txt");
	in1 >> ad;
	admin = ad;
	in1.close();
}

void getinput(Admin &adm)
{
	Admin temp; int count = 1;
	temp.getInput();
	while ( count != 3 && temp != adm )
	{
		system("cls");
		cout << "Your Username or Password is incoorect Your " << 3 - count << "tries have left \n";
		temp.getInput();
	}
	if ( count == 3 ) MainMenue();
}

int main()
{
	int Account_Counts;
	DDLIST <Costumer> list;
	Admin admin;
	readFiles(list , admin , Account_Counts);
	int choice;
	MainMenue(); 
	cin >> choice;

	while ( choice != 3 )
	{
		if ( choice == 1 )
		{
			Admin ad;
			getinput(admin);
			ad.showAdminmenue();
		}
		if ( choice == 2 )
		{
			Costumer costumer;
			costumer.displayCostumerMenue();
		}
		MainMenue();
		cin >> choice;
	}
	return 0;
}