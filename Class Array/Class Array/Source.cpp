#include<iostream>
using namespace std;

class Array
{
	// Data Members
    int size;
	int *p;
	bool sorted;
public:

	// parameterized Constructor
	Array (int size)
	{
		sorted=false;
		this->size=size;
		this->p = new int[this->size];
		for (int i = 0; i < this->size; i++)
			p[i] = NULL;
	}

	// Destrctor
	~Array () { (this->size == 1) ? delete p : delete[]p; }

	// add function to add the element at end of array
	void add (int num)
	{
		if (p[size-1]==NULL)
		{
			bool adjusted=false;
			for (int i=0; i < size && !adjusted ;i++)
			{
				if(p[i]==NULL)
				{
					p[i]=num;
					adjusted=true;
					this->sorted=false;
				}
			}
		}

		else
		{
			resize(size+1);
			p[size-1]=num;
			this->sorted=false;
		}
	}

	// delete function
	void remove (int value)
	{
		if(binarySearch(value))
		{
			int index=0;
			for (int i=0;i<size;i++)
			{
				if(p[i]==value)
					index=i;
			}
			for(int j=index;j<size;j++)
			{
				p[j]=p[j+1];
			}
			resize(size-1);
		}
		else
		{
			cout <<"element does not exists...";
		}
	}

	// Linear Search 
	bool linearSearch(int value)
	{
		int index=0;
		bool found = false; 
		while (index < size && !found)
		{
			if (p[index] == value) 
			{
				found = true; 
				return true;
			}
			index++; 
		}
		return false; 
	}

	// Binary Search 
	bool binarySearch (int value)
	{
		int first = 0,last = size - 1, middle; 
		bool found = false; 
		while (!found && first <= last)
		{
			middle = (first + last) / 2;
			if (p[middle] == value)
			{
				found = true;
				return true;
			}
			else if (p[middle] > value) 
				last = middle - 1;
			else
				first = middle + 1;
		}
		return false;
	}

	// Sort Function (Selection Sort)
	void sort()
	{
		int startScan, minIndex, minValue;
		for (startScan = 0; startScan < (size - 1); startScan++)
		{
			minIndex = startScan;
			minValue = p[startScan];
			for(int index = startScan + 1; index < size; index++)
			{
				if (p[index] < minValue)
				{
					minValue = p[index];
					minIndex = index;
				}
			}
			p[minIndex] = p[startScan];
			p[startScan] = minValue;
		}
		this->sorted=true;
	}

	// Count function to count a value
	int count (int value)
	{
		int c=0,index=0;
		while (index < size)
		{
			if (p[index] == value) 
			{ 
				c++;
			}
			index++; 
		}
		return c;
	}
		

	// Resize Function
	void resize (int newSize)
	{
		int *q=new int[newSize];
		if (newSize>this->size)
		{
			for(int i=0;i<this->size;i++)
				q[i]=p[i];
		}
		else
		{
			for(int i=0;i<newSize;i++)
				q[i]=p[i];
		}
		this->size=newSize;
		delete[]p;
		p=q;
		q=NULL;
	}

	void show ()
	{
		for (int i=0;i<size;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}

};

int main()
{
	Array a1(5);
	for (int i=0;i<5;i++)
		a1.add(i+1);
	a1.add(6);
	a1.add(10);
	a1.add(0);
	a1.show();
	a1.remove(4);
	a1.sort();
	cout<<a1.count(0)<<endl;
	
	a1.show();

	system("pause");
	return 0;
}