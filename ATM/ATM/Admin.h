#ifndef ADMIN_H
#define ADMIN_H
#include<string>
using namespace std;

class Admin
{
	string userName , password;
public:
	Admin()
	{
		userName = password = "";
	}
	Admin(string userName , string password)
	{
		setPassword(password);
		setuserName(userName);
	}

	void setPassword(string);
	void setuserName(string);
	string getPassword()const;
	string getUsername()const;
	void showAdminmenue()const;
	void getInput();

	friend ostream& operator <<( ostream& , const Admin& );
	friend istream& operator >>( istream & , Admin& );
	Admin operator =( const Admin& );
	bool operator == ( const Admin & )const;
	bool operator !=( const Admin& )const;
};
#endif