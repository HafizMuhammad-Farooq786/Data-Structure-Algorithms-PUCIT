#include <iostream>
#include<string>
#include<fstream>
#define null 0
using namespace std;

class Player
{
public: 
	string fN , sN; 
	int matches , inns , nOut , runs , highest , _100s , _50s;
	float avg;
	Player *nextP;
	friend ostream& operator<<( ostream& out , const Player &p );
	friend istream& operator>>( istream& in ,  const Player &p );
	Player(){ nextP = null; }

//	 Overloaded '=' operator
	Player operator = ( const Player &obj )
	{
		this->fN = obj.fN;
		this->sN = obj.sN;
		this->matches = obj.matches;
		this->inns = obj.inns;
		this->nOut = obj.nOut;
		this->runs = obj.runs;
		this->highest = obj.highest;
		this->_100s = obj._100s;
		this->_50s = obj._50s;
		this->avg = obj.avg;
		this->nextP = obj.nextP;
	}
};

ostream& operator<<( ostream& out , const Player &p )
{
	out << p.fN << " " << p.sN << "\t" << p.matches << "\t" << p.inns << "\t" << p.nOut << "\t" << p.runs
		<< "\t" << p.highest << "\t" << p.avg << "\t" << p._100s << "\t" << p._50s << endl;
	return out;
}

istream& operator>>( istream& in , Player &p )
{
	in >> p.fN >> p.sN >> p.matches >> p.inns >> p.nOut >> p.runs >> p.highest
		>> p.avg >> p._100s >> p._50s;
	return in;
}
class PList
{
	Player *first;
	Player*last;
	Player header;
	public:
		Player * getFirst() const
		{
			return first;
		}
		 //constructor
		PList( ) :header()
		{
			last = first = &header;
		}
	
		 //adds Player at start
		void add( Player data)
		{
			Player *temp = new Player(data );
			if ( first == last )
			{
				first->nextP = temp;
				last = temp;
			}
			else
			{
				temp->nextP = first->nextP;
				first->nextP = temp;
			}
		}
	
		// adds Player at end of list
		void addAtLast(Player data )
		{
			if ( first == last )
				add( data );
			else
			{
				Player *temp = new Player( data );
				last->nextP = temp;
				last = temp;
			}
		}
		friend ostream& operator<<( ostream& out , const PList &p );
};

ostream& operator<<( ostream& out ,  PList const &p )
{
	for ( Player *temp = p.getFirst()->nextP; temp != null; temp = temp->nextP )
		out << temp;
	return out;
}

int main()
{
	ifstream in( "players.txt" );
	Player p;
	PList list;
	in>>p;
	cout<<p;
	/*while ( in >> p.fN >> p.sN >> p.matches >> p.inns >> p.nOut >> p.runs >> p.highest >> p.avg >> p._100s >> p._50s )*/
		list.add(p);
	cout<<list;
	system( "pause" );
	return 0;
}