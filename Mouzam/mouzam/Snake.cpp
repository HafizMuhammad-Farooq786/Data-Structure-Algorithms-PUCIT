#include <iostream>
#include "ConsoleFunctions.h"
using namespace std;

class Node
{
public:
	char c;
	Node *next , *prv;
	Node()
	{
		next = prv = NULL;
		this->c = '*';
	}

	Node(char cr)
	{
		next = prv = NULL;
		this->c = cr;
	}
};


class snakeGame
{
	//head and tail of snake 
	Node* head;
	Node* tail;
	int mapwidth;
	int mapheight;

	//add here any data members, if you need 
public:
	ConsoleFunctions cf;
	snakeGame();
	~snakeGame();
	void addToTail();
	void print();
	void createFruit();
	void onCollision();
	void move();
	void startGame();
	//add here any member functions, if you need 
};


snakeGame::snakeGame()
{
	cf.getConsoleSize(mapheight , mapwidth);
	head = new Node(4);
	tail = new Node();
	head->next = tail;
	tail->prv = head;
	addToTail();
	addToTail();
}

void snakeGame::addToTail()
{
	Node *temp = new Node();
	temp->prv = tail->prv;
	tail->prv = temp;
	temp->next = tail;
	temp->prv->next = temp;
}
snakeGame::~snakeGame()
{
	//destroy any dynamically created memory 
}
void snakeGame::print()
{
	for ( Node *temp = head; temp->next != NULL; temp = temp->next )
		cout << temp->c;
}

void snakeGame::createFruit()
{
	int x = 0;
	int y = 0;

	do {
		// Generate random x and y values within the map
		x = rand() % ( mapwidth - 2 ) + 1;
		y = rand() % ( mapheight - 2 ) + 1;
		cf.SetCursorAt(x , y);
		cf.}

}
void snakeGame::onCollision()
{
	//code if collision with a fruit 
	//code if collision with itself 
}

void snakeGame::move()
{
	char c;
	// declare any variables if needed  	while(1) 
	{
		// write your code here, if needed cf.DetectEvent(); 
		if ( cf.IsKeyPressEvent(c) )
		{
			if ( c == 72 )
			{
			}

			else if ( c == 80 )
			{
			}

			else if(c == 75)
			{
			}
			else if ( c == 77 )
			{
			}
			else
			{

			}
		}
		else
		{
			//code if no key is hit, simply the snake should move 
		}

		//write your code here, if needed 
	}
}

void snakeGame::startGame()
{
	move();
}

int main()
{
	snakeGame s;

	s.print();
	system("pause");
	return 0;
}