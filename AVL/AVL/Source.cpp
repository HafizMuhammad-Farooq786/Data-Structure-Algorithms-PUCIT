#include <iostream>
using namespace std;
#include<queue>

// class Avl Node
template<class T>
class AVLNode
{
public:
	T data; int height;
	AVLNode *left , *right;
	AVLNode(T d)
	{
		data = d;
		left = right = NULL;
		height = 1;
	}
};

int max(int a , int b)
{
	if ( a > b )	return a;
	return b;
}

template<class T>
class AVLTree
{
	AVLNode <T>*root;
public:
	// Construcor
	AVLTree()
	{
		root = NULL;
	}

	// Rotate Rights
	AVLNode<T>* rotateRight(AVLNode<T> * temp)
	{
		AVLNode* temp1 = temp->left;
		temp->left = temp1->right;
		temp1->right = temp;
		temp->height = 1 + max(height(temp->left) , height(temp->right));
		temp = temp1;
		temp->height = 1 + max(height(temp->left) , height(temp->right));
		return temp;
	}

	// Rotates Left
	AVLNode* rotateLeft(AVLNode * temp)
	{
		AVLNode* temp1 = temp->right;
		temp->right = temp1->left;
		temp1->left = temp;
		temp->height = 1 + max(height(temp->left) , height(temp->right));
		temp = temp1;
		temp->height = 1 + max(height(temp->left) , height(temp->right));
		return temp;
	}

	void insert(T ele)
	{
		root = insert(ele , root);
	}

	AVLNode* setBalance(AVLNode* temp)
	{
		int bf1 = height(temp->left) - height(temp->right) , bf2;
		if ( bf1 > 1 )
		{
			bf2 = height(temp->left->left) - height(temp->left->right);
			if ( bf2 < 0 )
				temp->left = rotateLeft(temp->left);
			temp = rotateRight(temp);
		}
		else if ( bf1 < -1 )
		{
			bf2 = height(temp->right->left) - height(temp->right->right);
			if ( bf2 > 0 )
				temp->right = rotateRight(temp->right);
			temp = rotateLeft(temp);
		}
		return temp;
	}

	// insert function inserts node to tree
	AVLNode* insert(T ele , AVLNode* temp)
	{
		if ( temp == NULL )	temp = new AVLNode(ele);
		else if ( temp->data > ele )	temp->left = insert(ele , temp->left);
		else if ( temp->data < ele )	temp->right = insert(ele , temp->right);
		temp->height = 1 + max(height(temp->left) , height(temp->right));
		return setBalance(temp);
	}

	void deleteN(T ele)
	{
		root = deleteN(ele , root);
	}

	AVLNode* deleteN(T ele , AVLNode* t)
	{
		if ( t == NULL ) return t;
		else if ( t->data > ele )	t->left = deleteN(ele , t->left);
		else if ( t->data < ele )	t->right = deleteN(ele , t->right);
		else
		{
			if ( t->left == NULL && t->right == NULL )
			{
				delete t;
				t = NULL;
				return t;
			}
			else if ( t->left == NULL )
			{
				AVLNode *toDelete = t;
				t = t->right;
				delete toDelete;
			}
			else if ( t->right == NULL )
			{
				AVLNode *toDelete = t;
				t = t->left;
				delete toDelete;
			}

			else
			{
				// finds minimum node from right side
				AVLNode *minN = findMin(t->right);
				t->data = minN->data;
				t->right = deleteN(minN->data , t->right); // SENDS CALL TO DELETE THAT NODE WHICH HAS BEEN REPLACED
			}
		}

		// SETS Hieght
		t->height = 1 + max(height(t->left) , height(t->right));
		return setBalance(t);
	}

	void inOrder()
	{
		inOrder(root);
		cout << '\n';
	}
	void inOrder(AVLNode *temp)
	{
		if ( temp )
		{
			inOrder(temp->left);
			cout << temp->data << ' ';
			inOrder(temp->right);
		}
	}
	AVLNode* findMin(AVLNode *temp)
	{
		if ( temp == NULL )
			return temp;
		while ( temp->left != NULL )
			temp = temp->left;
		return temp;
	}

	int height()
	{
		return height(root);
	}

	int height(AVLNode *t)
	{
		if ( t == NULL )	return 0; return t->height;
	}
};



int main()
{
	AVLTree<char> tree;
	tree.insert('J');
	tree.insert('D');
	tree.insert('M');
	tree.insert('B');
	tree.insert('H');
	tree.insert('K');
	tree.insert('N');
	tree.insert('A');
	tree.insert('E');
	tree.insert('I');
	tree.insert('O');
	tree.insert('U');
	tree.inOrder();
	/*tree.insert(50);
	tree.insert(20);
	tree.insert(80);
	tree.insert(10);
	tree.insert(90);
	tree.insert(30);
	tree.insert(70);
	tree.insert(60);
	tree.insert(55);
	tree.insert(40);
	tree.insert(35);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(10);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(20);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(30);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(50);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(60);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(70);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(70);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(55);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(80);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(40);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(35);
	tree.inOrder();
	cout << "Height:" << tree.height() << '\n';
	tree.deleteN(90);
	cout << "Height:" << tree.height() << '\n';*/
	system("pause");
	return 0;
}