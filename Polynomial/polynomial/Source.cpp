#include<iostream>
using namespace std;

struct Term
{
	int co_eff;
	int exponet;
};

class PolyNomial
{
	// data Members
	Term *p;
	int term;

	int equaltoThis(int x) const
	{
		for (int i=0;i<this->getterm();i++)
			if (p[i].exponet==x)
				return i;
		return -1;
	}

	
	int equaltoObj(int x,PolyNomial obj) const
	{
		for (int i=0;i<obj.getterm();i++)
			if (obj.p[i].exponet==x)
				return i;
		return -1;
	}

public:
	// Getter
	int getterm () const {return term;}

	// setter
	void setterm (int term) {this->term=term;}

	// Constructor
	PolyNomial ()
	{
		this->setterm (0);
		this->p=NULL;
	}

	// Copy Constructor
	PolyNomial (const PolyNomial &obj )
	{
		this->setterm (obj.getterm());
		p=new Term[this-> term];
		for (int i=0 ; i<term ; i++)
		{
			this->p[i].co_eff=obj.p[i].co_eff;
			this->p[i].exponet=obj.p[i].exponet;
		}
	}

	// Destructor
	~PolyNomial () {delete []p;}

	// input Function
	void input ()
	{
		int terms;
		cout<<"Enter no terms of PolyNomial: ";
		cin>>terms;
		this->setterm(terms);
		
		for (int i= this-> term-1 ; i >= 0; i--)
		{
			cout<<"Enter Co-eff. & exponent respectively for term "<<i+1<<endl;
			cin>>p[i].co_eff;
			cin.ignore();
			cin>>p[i].exponet;
		}
	}

	PolyNomial add (const PolyNomial & obj) const
	{
		PolyNomial answer;
		this->getterm()>obj.getterm() ? answer.setterm(this->getterm()): answer.setterm(obj.getterm());
		if (obj.getterm()>this->getterm())
		{
			for (int i=0; i<answer.getterm() ; i++)
			{
				if (equaltoThis(obj.p[i].exponet)==-1)
				{
					answer.p[i].co_eff=obj.p[i].co_eff;
					answer.p[i].exponet=obj.p[i].exponet;
				}
				else
				{
					answer.p[i].co_eff=obj.p[i].co_eff+this->p[equaltoThis(obj.p[i].exponet)].co_eff;
					answer.p[i].exponet=obj.p[i].exponet;
				}
			
			}
		}

		else if (obj.getterm()<this->getterm())
		{
			for (int i=0; i<answer.getterm() ; i++)
			{
				if (equaltoObj(this->p[i].exponet,obj)==-1)
				{
					answer.p[i].co_eff=obj.p[i].co_eff;
					answer.p[i].exponet=obj.p[i].exponet;
				}
				else
				{
					answer.p[i].co_eff=obj.p[i].co_eff+this->p[equaltoObj(this->p[i].exponet,obj)].co_eff;
					answer.p[i].exponet=obj.p[i].exponet;
				}
			}
		}

		/*else
		{
			answer.setterm(this->getterm()*2);
			for (int i=0,k=0; i<answer.getterm() ; i++)
			{
				if (equaltoThis(obj.p[k].exponet)==-1)
				{
					answer.p[i].co_eff=obj.p[k].co_eff;
					answer.p[i].exponet=obj.p[k].exponet;
					k++;
				}
				else
				{
					answer.p[i].co_eff=obj.p[k].co_eff+this->p[equaltoThis(obj.p[k].exponet)].co_eff;
					answer.p[i].exponet=obj.p[k].exponet;
					k++;
				}
			}
		}*/
		return answer;

	}

	void show ()
	{
		for (int i=this->getterm()-1;i>=0;i--)
			cout <<this->p[i].exponet<<" ";
		cout<<endl;
		for (int i=this->getterm()-1;i>=0;i--)
			cout <<this->p[i].co_eff;
		cout<<endl;
	}

};

int main ()
{
	PolyNomial a,b;
	a.input();
	b.input();

	a.show();
	b.show();

	PolyNomial c=a.add(b);
	c.show();
	system ("pause");
	return 0;
}