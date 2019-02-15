#ifndef COSTUMER_H
#define COSTUMER_H

#include<string>
using namespace std;

class Costumer
{
	string fName , lName;
	int id , pin;
	double balance;
public:
	// default Constructor
	Costumer()
	{
		setFName("\0");
		setLName("\0");
		setID(NULL);
		setPIN(NULL);
		setBalance(NULL);
	}

	// Parameter Constructor
	Costumer(string fName , string lName , int id , int pin , double balance)
	{
		setFName(fName);
		setLName(lName);
		setID(id);
		setPIN(pin);
		setBalance(balance);
	}

	//copy Constructor
	Costumer(const Costumer&obj)
	{
		this->setFName(obj.getFName());
		this->setLName(obj.getLName());
		this->setID(obj.getID());
		this->setPIN(obj.getPIN());
		this->setBalance(obj.getBalance());
	}

	// settters
	void setFName(string);
	void setLName(string);
	void setID(int);
	void setPIN(int);
	void setBalance(double);

	// getters
	string getFName()const;
	string getLName()const;
	string getName()const;
	int getID()const;
	int getPIN()const;
	double getBalance()const;

	// functions
	void displayCostumerMenue()const;
	void showBalance()const;
	void withDraw();
	void printwithDrawSlip(double)const;
	void deposit();
	void printDepositSlip(double)const;
	void changePIN();

	// operators
	friend ostream& operator <<( ostream& , const Costumer& );
	friend istream& operator >>( istream & , Costumer& );
	Costumer operator =( const Costumer& );
	bool operator == ( const Costumer & )const;
};

#endif