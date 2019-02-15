#include <iostream>

using namespace std;
class Algebra
{
	int a;
	int b;
public:
	void printData()
	{
		//cout<<this<<endl;
		cout << " a = " << a << endl;
		cout << " b = " << b << endl;
	}
	void inputData()
	{
		cout << "Enter the value of a = ";
		cin >> a;

		cout << "Enter the value of b = ";
		cin >> b;
	}

	int add()
	{
		return a + b;
	}

	int sub()
	{
		return a - b;
	}

	int divide()
	{
		return a / b;
	}

	int multiply()
	{
		return a*b;
	}

	int mod()
	{
		return a%b;
	}

	void setValue(int a, int b)
	{
		//cout<<this<<endl;
		this->a = a;
		this->b = b;

	}

	void setA(int a1)
	{
		a = a1;

	}

	void setB(int b1)
	{
		b = b1;

	}

	int getA()
	{
		return a;
	}

	int getB()
	{

		return b;
	}


	Algebra()
	{
		cout << "Defalt constructor" << endl;
		a = b = 0;
	}

	Algebra(int a1, int b1)
	{
		cout << "paramitrize or overloded constructor" << endl;
		this->a = a1;
		this->b = b1;
	}

	/*Algebra(const Algebra &obj)
	{
		cout << "Copy Const..." << endl;
		this->a = a;
		this->b = b;
	}*/


	~Algebra()
	{
		cout << "Distructor" << endl;
	}
	Algebra add(Algebra &obj)
	{
		Algebra temp;
		temp.a = this->a + obj.a;
		temp.b = this->b + obj.b;
		return temp;
	}

	Algebra sub(Algebra &obj)
	{
		Algebra temp;
		temp.a = this->a - obj.a;
		temp.b = this->b - obj.b;
		return temp;
	}

	Algebra mul(Algebra &obj)
	{
		Algebra temp;
		temp.a = this->a*obj.a;
		temp.b = this->b*obj.b;
		return temp;
	}

	Algebra div(Algebra &obj)
	{
		Algebra temp;
		temp.a = this->a / obj.a;
		temp.b = this->b / obj.b;
		return temp;
	}
	Algebra operator+(const Algebra &obj)const
	{
		return Algebra(a + obj.a, b + obj.b);
	}

	Algebra operator-(const Algebra &obj)const
	{
		return Algebra(a - obj.a, b - obj.b);
	}

	Algebra operator/(const Algebra &obj)const
	{
		return Algebra(a / obj.a, b / obj.b);
	}

	Algebra operator*(const Algebra &obj)const
	{
		return Algebra(a*obj.a, b*obj.b);
	}
	Algebra operator%(const Algebra &obj)const
	{
		return Algebra(a%obj.a, b%obj.b);
	}

	Algebra operator= (const Algebra &obj)
	{
		cout << "this is operator = ";
		//avoid self assignment
		if (this != &obj)
		{
			this->a = obj.a;
			this->b = obj.b;
		}

		return *this;
	}

	Algebra operator+=(const Algebra &obj)//ya dekhna ha
	{
		this->a += obj.a;
		this->b += obj.b;
		return *this;
	}

	Algebra operator*=(const Algebra &obj)//ya dekhna ha
	{
		this->a *= obj.a;
		this->b *= obj.b;
		return *this;
	}

	Algebra operator/=(const Algebra &obj)//ya dekhna ha
	{
		this->a /= obj.a;
		this->b /= obj.b;
		return *this;
	}
	Algebra operator%=(const Algebra &obj)//ya dekhna ha
	{
		this->a %= obj.a;
		this->b %= obj.b;
		return *this;
	}

	bool operator==(const Algebra &obj)
	{
		return(this->a == obj.a&&this->b == obj.b);

	}

	bool operator!=(const Algebra &obj)
	{
		return(this->a != obj.a&&this->b != obj.b);

	}

	bool operator>(const Algebra &obj)
	{
		return(this->a>obj.a&&this->b>obj.b);

	}
	bool operator<(const Algebra &obj)
	{
		return(this->a<obj.a&&this->b<obj.b);

	}

	bool operator>=(const Algebra &obj)
	{
		return(this->a >= obj.a&&this->b >= obj.b);

	}

	bool operator<=(const Algebra &obj)
	{
		return(this->a <= obj.a&&this->b <= obj.b);

	}
	Algebra operator-()
	{
		Algebra temp(-a, -b);
		return temp;

	}

};
void foo()
{
	Algebra a1, a2, a3;
}
void print(Algebra obj)
{


	obj.printData();	//1	2
}

//Passing by reference
void out(Algebra &obj)
{
	obj.printData();
}

int main()
{
	Algebra obj1(1, 2), obj2(1, 3), obj3(5, 6), obj4(9, 8), objr;

	obj1 = obj2 = obj3;
	//obj2=obj3;
	obj1.printData();
	//obj2.printData();


	system("pause");
	return 0;
}
