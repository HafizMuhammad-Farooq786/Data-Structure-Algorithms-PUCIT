//#include<iostream>
//using namespace std;
//
//class AVLNode
//{
//public:
//	int data , height;
//	AVLNode*right , *left;
//	AVLNode(int d = 0)
//	{
//		data = d;
//		left = right = NULL;
//		height = 1;
//	}
//};
//
//int height(AVLNode *temp)
//{
//	if ( temp == NULL )
//		return 0;
//	return temp->height;
//}
//AVLNode* insert(AVLNode *t , int d)
//{
//	if ( t == NULL )
//		return new AVLNode(d);
//	if ( d<t->data )
//		t->left = insert(t->left , d);
//	else
//		t->right = insert(t->right , d);
//	return balance(t);
//}
//AVLNode* balance(AVLNode *t)
//{
//	int bf1 = height(t->left) - height(t->right) , bf2;
//	if ( bf1>1 )
//	{
//		bf2 = height(t->left->left) - height(t->left->right);
//		if ( bf2<0 )
//			t->left = rotateLeft(t->left);
//		t = rotateRight(t);
//	}
//	else if ( bf1<-1 )
//	{
//		bf2 = height(t->right->left) - height(t->right->right);
//		if ( bf2>0 )
//			t->right = rotateRight(t->right);
//		t = rotateLeft(t);
//	}
//	return t;
//}
//AVLNode* deleteN(AVLNode *t , int d)
//{
//	if ( t == NULL ) return t;
//	if ( d<t->data )t->left = deleteN(t->left , d);
//	else if ( d>t->data )
//		t->right = deleteN(t->right , d);
//	else
//	{
//		if ( t->left == NULL && t->right == NULL )
//		{
//			delete t;
//			t = NULL;
//		}
//		else if ( t->left == NULL )
//		{
//			AVLNode *toDelete = t;
//			t = t->right; delete toDelete;
//		}
//		else if ( t->right == NULL )
//		{
//			AVLNode *toDelete = t;
//			t = t->left;
//			delete toDelete;
//		}
//		else
//		{
//			AVLNode *minN = findMin(t->right);
//			t->data = minN->data;
//			t->right = deleteN(t->right , minN->data);
//		}
//	}return balance(t);//same as insertion}