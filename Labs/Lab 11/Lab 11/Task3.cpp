#include <iostream>
#include<cmath>
#include <fstream>

using namespace std;
#define null 0
#define SEN -1

class BTNode
{
public:
	int data;
	BTNode * left , *right;
	BTNode(int d)
	{
		this->data = d;
		left = right = NULL;
	}
};

class BST
{
	BTNode *root;

	//In-Order Traversal function Recursive
	void inOrder(BTNode* temp)const
	{
		if ( temp )
		{
			inOrder(temp->left);
			cout << temp->data << " ";
			inOrder(temp->right);
		}
	}

	// delete LeafNode Recursive Function
	BTNode* deleteLeafNode(BTNode * temp)
	{
		BTNode * toDelete;
		if ( temp == NULL ) return temp;
		if ( temp->left == NULL &&temp->right == NULL )
		{
			toDelete = temp;
			delete toDelete;
			temp = NULL;
			return temp;
		}
		temp->right = deleteLeafNode(temp->right);
		temp->left = deleteLeafNode(temp->left);
		return temp;
	}

	// Count LeafNode Recursive Function
	int countLeafNode(BTNode *temp)
	{
		if ( temp == NULL ) return 0;
		if ( temp->left == NULL &&temp->right == NULL ) return 1;
		return countLeafNode(temp->right) + countLeafNode(temp->left);
	}

	// Counts 1 Leaf Child Node
	int count1Child(BTNode *temp)
	{
		if ( temp == NULL )
			return 0;
		if ( temp->left == NULL &&temp->right == NULL )
			return 0 + count1Child(temp->right) + count1Child(temp->left);
		else if ( temp->left != NULL &&temp->right != NULL )
			return 0 + count1Child(temp->right) + count1Child(temp->left);
		else
			return 1 + count1Child(temp->right) + count1Child(temp->left);
	}

	// Counts 2 Child
	int count2Child(BTNode *temp)
	{
		if ( temp == NULL )
			return 0;
		if ( temp->left != NULL &&temp->right != NULL )
			return 1 + count2Child(temp->right) + count2Child(temp->left);
		if ( temp->left == NULL || temp->right == NULL )
			return 0 + count2Child(temp->right) + count2Child(temp->left);
	}

	int Max(int left , int right)
	{
		if ( left > right )
			return left;
		else
			return right;
	}

	// counts Hieght of tree;
	int findHieght(BTNode *temp)
	{
		if ( temp == NULL ) return 0;
		return 1 + Max(findHieght(temp->left) , findHieght(temp->right));
	}

	/*void toArray(int *x , BTNode *temp , int &i )
	{
		if ( temp == NULL ) return;
		toArray(x , temp->left , i * 2 + 1);
		if ( temp->data == NULL )
			x[i] = SEN;
		else
			x[i] = temp->data;
		toArray(x , temp->right , (i* 2) + 2);
	}*/

	void preOrder(BTNode* temp)const
	{
		if (temp)
		{
			cout << temp->data << " ";
			preOrder(temp->left);
			preOrder(temp->right);
		}
	}


	void postOrder(BTNode* temp)const
	{
		if (temp)
		{
			postOrder(temp->left);
			postOrder(temp->right);
			cout << temp->data << " ";
		}
	}

public:
	BST()
	{
		root = null;
	}
	void insert(int ele)
	{
		root = insert(ele , root);
	}
	BTNode* insert(int ele , BTNode* temp)
	{
		if ( temp == null )	temp = new BTNode(ele);
		else if ( temp->data >= ele )	temp->left = insert(ele , temp->left);
		else if ( temp->data < ele )	temp->right = insert(ele , temp->right);
		return temp;
	}
	void inOrder()
	{
		inOrder(root);
		cout << '\n';
	}
	void inOrder(BTNode *temp)
	{
		if ( temp )
		{
			inOrder(temp->left);
			cout << temp->data << ' ';
			inOrder(temp->right);
		}
	}
	int findMax(BTNode *t)
	{
		if ( !t->right )	return t->data;
		return findMax(t->right);
	}
	int findMin(BTNode *t)
	{
		if ( !t->left )	return t->data;
		return findMin(t->left);
	}
	void deleteV(int ele)
	{
		root = deleteV(ele , root);
	}
	BTNode* deleteV(int ele , BTNode* temp)
	{
		if ( temp == null );
		else if ( temp->data > ele )	temp->left = deleteV(ele , temp->left);
		else if ( temp->data < ele )	temp->right = deleteV(ele , temp->right);
		else
		{
			if ( !temp->left && !temp->right )
			{
				delete temp;	temp = null;
			}
			else if ( !temp->left )
			{
				BTNode *toDel = temp;	temp = temp->right;	delete toDel;
			}
			else if ( !temp->right )
			{
				BTNode *toDel = temp;	temp = temp->left;	delete toDel;
			}
			else
			{
				int newV = findMin(temp->right); temp->data = newV;	temp->right = deleteV(newV , temp->right);
			}
		}
		return temp;
	}

	void inOrder()const
	{
		inOrder(root);
	}

	void preOrder()const
	{
		preOrder(root);
	}

	void postOrder()const
	{
		postOrder(root);
	}

	void deleteLeafNode()
	{
		root = deleteLeafNode(root);
	}

	int countLeafNode()
	{
		return countLeafNode(root);
	}

	int count1Child()
	{
		return count1Child(root);
	}

	int count2Child()
	{
		return count2Child(root);
	}

	int findHieght()
	{
		return findHieght(root);
	}

	//void toArray(int *x)
	//{
	//	int i = 0;
	//	toArray(x , root , i);
	//}
};


int main()
{
	BST tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(8);
	tree.insert(4);
	tree.insert(7);
	tree.insert(2);
	tree.insert(9);
	tree.insert(1);
	tree.insert(10);
	tree.inOrder();
	tree.preOrder(); cout << endl;
	tree.postOrder();
	
	/*int size , value;
	ifstream in("in1.txt");
	in >> size;
	for ( int i = 0; i < size; i++ )
	{
		in >> value;
		tree.insert(value);
	}
	in.close();
	cout<<tree.findHieght()<<endl;*/


	system("pause");
	return 0;
}