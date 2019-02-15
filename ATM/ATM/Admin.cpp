#include<iostream>
#include"Admin.h"
using namespace std;

void Admin::setuserName(string userName){ this->userName = userName; }
void Admin::setPassword(string password){ this->password = password; }
string Admin::getPassword()const { return password; }
string Admin::getUsername()const { return userName; }

void Admin:: getInput()
{
	string userName , password;
	cout << "Enter UserName: ";
	cin >> userName;
	cout << "Enter Pasword: ";
	cin >> password;
	setuserName(userName);
	setPassword(password);
}

//// displays admin menue
void Admin::showAdminmenue()const
{
	cout << '\n';
	cout << "\t 1: Create a Coustmer Account \n";
	cout << "\t 2: Delete a Coustmer Account \n";
	cout << "\t 3: SHOW ACCOUNTS \n";
	cout << "\t 4: Change Password \n";
	cout << "\t 5: EXIT  to Main Menue\n";
	cout << '\n';
}

bool Admin::operator ==( const Admin &obj )const 
{
	return ( ( this->getPassword() == obj.getPassword() ) && ( this->getUsername() == obj.getUsername() ) );
}

bool Admin ::operator!= ( const Admin &obj )const
{
	return !( *( this ) == obj );
}
Admin Admin::operator=( const Admin &obj )
{
	this->setuserName(obj.getUsername());
	this->setPassword(obj.getPassword());
	return *( this );
}

ostream& operator <<( ostream &out , const Admin&obj )
{
	out << obj.getUsername() << " " << obj.getPassword();
	return out;
}

istream& operator >>( istream &in , Admin &obj )
{
	in >> obj.userName >> obj.password;
	return in;
}