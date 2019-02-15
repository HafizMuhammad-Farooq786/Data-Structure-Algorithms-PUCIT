#include<iostream>
#include<ctime>
#include<string>
#include"Costumer.h"

// function to print time & date
void printTime()
{
	char buffer[32];
	time_t rawTime = time(NULL);
	tm currTime;
	localtime_s(&currTime , &rawTime);
	asctime_s(buffer , 32 , &currTime);
	cout << buffer;
}

using namespace std;

// Setters
void Costumer::setFName(string fName) { this->fName = fName; }
void Costumer::setLName(string lName) { this->lName = lName; }
void Costumer::setID(int id) { this->id = id; }
void Costumer::setPIN(int pin) { this->pin = pin; }
void Costumer::setBalance(double balance) { this->balance = balance; }

// Getters
string Costumer::getFName()const { return this->fName; }
string Costumer::getLName()const { return this->lName; }
string Costumer::getName()const { return this->fName + this->lName; }
int Costumer::getPIN()const { return this->pin; }
int Costumer::getID()const { return this->id; }
double Costumer::getBalance()const { return this->balance; }

// function to Show Balance
void Costumer::showBalance()const 
{
	system("cls");
	cout << "----------------------------------------\n";
	cout << "\t Name: " << this->fName << " " << this->lName << endl;
	cout << "\t Account No: " << this->id << endl;
	cout << "\t Your Balance is: " << this->balance<< endl;
	cout << "\t "; printTime();
	cout << "----------------------------------------\n";
}

// function Prints balanve details after withdraw
void Costumer::printwithDrawSlip(double amount)const
{
	system("cls");
	cout << "****************************************************\n";
	cout << " \t------------------------------------\n";
	cout << " \t              BANK \n";
	cout << " \t------------------------------------\n";
	cout << "\t Name: " << this->fName << " " << this->lName << endl;
	cout << "\t Account No: " << this->id << endl;
	cout << " \t Previous Balance: " << this->balance << endl;
	cout << " \t Withdrawed Balance: " << amount << endl;
	cout << " \t Current Balance: " << this->balance - amount << endl;
	cout << "\t "; printTime();
	cout << "****************************************************\n";
	
}

// function withdrwas Amount
void Costumer::withDraw()
{
	system("cls");
	double amount;
	cout << "How Much would you like to withdraw? ";
	cin >> amount;
	while ( this->getBalance() < amount )
	{
		cout << "You tryen to rob me? You don't have that much" << endl
			<< "How Much would you like to withdraw?" << endl;
		cin >> amount;
	}
	printwithDrawSlip(amount);
	this->setBalance(this->getBalance() - amount);
}

// function deposits Amount 
void Costumer::deposit()
{
	system("cls");
	double amount;
	cout << "Enter how much you want to Deposit: ";
	cin >> amount;
	while ( amount > 10000 )
	{
		cout << "I would be all about taking more than 10,000 from you and all, "
			<< "but it jacks the program up and robs you." << endl
			<< "How much would you like to deposit?" << endl;
		cin >> amount;
	}
	printDepositSlip(amount);
	this->setBalance(this->getBalance() + amount);
}

// function prints deposit slip
void Costumer::printDepositSlip(double amount)const
{
	system("cls");
	cout << "****************************************************\n";
	cout << " \t------------------------------------\n";
	cout << " \t              BANK \n";
	cout << " \t------------------------------------\n";
	cout << "\t Name: " << this->fName << " " << this->lName << endl;
	cout << "\t Account No: " << this->id << endl;
	cout << " \t Previous Balance: " << this->balance - amount << endl;
	cout << " \t Deposited Balance: " << amount << endl;
	cout << " \t Current Balance: " << this->balance + amount << endl;
	cout << "\t "; printTime();
	cout << "****************************************************\n";
}

// function changes costumer's pin
void Costumer::changePIN()
{
	int p;
	cout << "Enter New PIN(5 digits):  ";
	cin >> p;
	while ( this->pin == p || ( p<10000 || p>99999 ) )
	{
		cout << "Choose a different one New PIN must be different from Old(5 digits): ";
		cin >> p;
	}

	this->setPIN(p);
	cout << "Your PIN Has been Changed!!!! \n\n";
}

void Costumer::displayCostumerMenue()const
{
	cout << '\n';
	cout << "\t 1: Show Balance \n";
	cout << "\t 2: Withdraw Cash \n";
	cout << "\t 3: Change PIN \n";
	cout << "\t 4: Deposit Cash \n";
	cout << "\t 5: Exit to main Menue \n";
	cout << '\n';
}

// '=' Assignmemt operator
Costumer Costumer::operator = ( const Costumer &obj)
{
	this->setFName(obj.getFName());
	this->setLName(obj.getLName());
	this->setID(obj.getID());
	this->setPIN(obj.getPIN());
	this->setBalance(obj.getBalance());
	return *( this );
}

// "==" operator
bool Costumer::operator==( const Costumer &obj )const { return this->id == obj.getID(); }

ostream& operator <<( ostream &out , const Costumer&obj )
{
	out << obj.fName << " " << obj.lName << " " << obj.id << " " << obj.pin << " " << obj.balance << "\n";
	return out;
}

istream& operator >> ( istream &in , Costumer &obj )
{
	in >> obj.fName >> obj.lName >> obj.id >> obj.pin >> obj.balance;
	return in;
}