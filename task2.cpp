#include<iostream>
#include<conio.h>
using namespace std;



template<class T>
class Node{
public:
	T data;
	Node* next;
	Node(T data)
	{
		this->data = data;
		next == NULL;
	}
};
template<class T>
class Qeue{
	Node<T> *first;
public:
	Qeue()
	{
		first = new Node<T>(0);
	}
	void addatlastdriver(Node<T> *temp, T data)
	{
		if (!temp->next)
		{
			Node<T> *toadd = new Node<T>(data);
			temp->next = toadd;
			toadd->next = NULL;
		}
		else
			addatlastdriver(temp->next, data);

	}
	void printdriver(Node<T> *temp)
	{
		if (!temp)
			return;
		else
		{
			cout << temp->data << " ";
			printdriver(temp->next);
		}
	}
	void print()
	{
		printdriver(first->next);
	}
	void enqeue(T data)
	{
		addatlastdriver(first, data);
	}
	T deqeue()
	{
		if (first->next != NULL)
		{
			T el = first->next->data;
			Node<T> todel = first->next;
			first->next = first->next->next;
			delete todel;
		}

	}
	T stop()
	{
		if (first->next != NULL)
		{
			return 
		}
	}
};
template<class T>
void inorder(int *y, int i, int size, Qeue<T> x)
{
	if (i < size && y[i] != -1)
	{
		inorder(y, (2 * i) + 1, size, x);
		x.enqeue(y[i]);
		inorder(y, 2 * (i + 1), size, x);
	}
}

template<class T>
void preorder(int *y, int i, int size, Qeue<T> x)
{
	if (i < size && y[i] != -1)
	{
		x.enqeue(y[i]);
		preorder(y, (2 * i) + 1, size, x);
		preorder(y, 2 * (i + 1), size, x);
	}
}

template<class T>
void postorder(int *y, int i, int size, Qeue<T> x)
{
	if (i < size && y[i] != -1)
	{

		postorder(y, (2 * i) + 1, size, x);
		postorder(y, 2 * (i + 1), size, x);
		x.enqeue(y[i]);
	}
}

void printlevel(int *x,int i,int level)
{
	if (i == level)
	{
		for (int j = pow(2, i - 1)+(level-1); j < (pow(2, i-1)+pow(2,i)+(level-1)); j++)
		{
			if (x[j]!=-1)
			cout << x[j]<<" ";
		}
	}
	else
	printlevel(x, i + 1, level);
}
int height(int *x, int i, int size)
{
	if (i >= size)
		return 0;
	else
		return 1 + height(x,( i + pow(2, i)), size);

}

void findlevel(int *y, int size, int level)
{
	if (level < height(y, 0, size))
	{
		if (level == 0)
		cout << y[0] << endl;
		else
		printlevel(y, 0, level);
	}
	else
		cout << "level does not exist\n";
}
int main(){

	Qeue<int> x,a,b;
	int y[15] = { 8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7,  -1, -1, 13, -1 };
	findlevel(y, 15, 3);
	/*inorder(y, 0, 15,x);
	x.print();
	cout << endl;
	preorder(y, 0, 15, a);
	a.print();
	cout << endl;
	postorder(y, 0, 15,b);
	b.print();
	*/
	//cout<<height(y, 0, 15);
	
	_getch();
}