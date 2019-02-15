//#include <iostream>
//#include <fstream>
//#include<ctime>
//
//using namespace std;
//#define null 0
//
//class BTNode
//{
//public:
//	int data;
//	BTNode * left , *right;
//	BTNode(int d)
//	{
//		this->data = d;
//		left = right = NULL;
//	}
//};
//
//class BT
//{
//	BTNode *root;
//
//
//public:
//	BT()
//	{
//		root = null;
//	}
//	void insert(int ele)
//	{
//		root = insert(ele , root);
//	}
//
//	BTNode* insert(int ele , BTNode* temp)
//	{
//		if ( temp == null )	
//			temp = new BTNode(ele);
//		else
//		{
//			int n = rand() % 100+1;
//			if ( n%2 == 0 )
//				temp->left = insert(ele , temp->left);
//			else
//				temp->right = insert(ele , temp->right);
//		}
//		return temp;
//	}
//
//
//	int findMax(BTNode *t)
//	{
//		if ( !t->right )	return t->data;
//		return findMax(t->right);
//	}
//	int findMin(BTNode *t)
//	{
//		if ( !t->left )	return t->data;
//		return findMin(t->left);
//	}
//	void deleteV(int ele)
//	{
//		root = deleteV(ele , root);
//	}
//	BTNode* deleteV(int ele , BTNode* temp)
//	{
//		if ( temp == null );
//		else if ( temp->data > ele )	temp->left = deleteV(ele , temp->left);
//		else if ( temp->data < ele )	temp->right = deleteV(ele , temp->right);
//		else
//		{
//			if ( !temp->left && !temp->right )
//			{
//				delete temp;	temp = null;
//			}
//			else if ( !temp->left )
//			{
//				BTNode *toDel = temp;	temp = temp->right;	delete toDel;
//			}
//			else if ( !temp->right )
//			{
//				BTNode *toDel = temp;	temp = temp->left;	delete toDel;
//			}
//			else
//			{
//				int newV = findMin(temp->right); temp->data = newV;	temp->right = deleteV(newV , temp->right);
//			}
//		}
//		return temp;
//	}
//
//	int Max(int left , int right)
//	{
//		if ( left > right )
//			return left;
//		else
//			return right;
//	}
//
//	int findHieght(BTNode *temp)
//	{
//		if ( temp == NULL ) return 0;
//		return 1 + Max(findHieght(temp->left) , findHieght(temp->right));
//	}
//	int hieght()
//	{
//		return findHieght(root);
//	}
//
//	void inOrder()
//	{
//		inOrder(root);
//	}
//
//	void inOrder(BTNode *temp)
//	{
//		if ( temp == NULL )
//			return;
//		inOrder(temp->left);
//		cout << temp->data<<" ";
//		inOrder(temp->right);
//	}
//};
//
//int main()
//{
//	srand(time(0));
//	BT tree;
//	int size , value;
//	ifstream in("tree1.txt");
//	in >> size;
//	for ( int i = 0; i < size; i++ )
//	{
//		in >> value;
//		tree.insert(value);
//	}
//	in.close();
//
//	cout << tree.hieght() << " "<<endl;
//	tree.inOrder();
//
//	system("pause");
//	return 0;
//}