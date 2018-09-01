#define _CRT_SECURE_NO_WARNINGS

#include"KeyValue.h"

BSTreeNode * BuyNode(BSTKeyType key, BSTValueType value)
{
	BSTreeNode* tree = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	tree->_left = NULL;
	tree->_right = NULL;
	tree->_value = value;
	tree->_key = (BSTKeyType)malloc(strlen(key) + 1);
	strcpy(tree->_key, key);
	return tree;
}
int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
{
	BSTreeNode *cur, *parent;
	if (*ppTree == NULL)
	{
		*ppTree = BuyNode(key,value);
		return 1;
	}
	cur = *ppTree;
	parent = cur;
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return 0;
	}
	if (strcmp(parent->_key, key) < 0)
	{
		parent->_right = BuyNode(key, value);
	}
	else
	{
		parent->_left = BuyNode(key, value);
	}

	return 1;
}
//int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType key)
//{
//	BSTreeNode *root = *ppTree;
//	BSTreeNode *cur, *parent, *replace;
//	if (root == NULL)
//		return 0;
//	cur = *ppTree;
//	parent = cur;
//	while (cur)
//	{
//		if (cmp)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (cur->_data < x)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else if (cur->_data == x)
//		{
//			//parent = cur;
//			if (cur->_left == NULL && cur->_right == NULL)//叶子，左右孩子都为空
//			{
//				if (parent->_left == cur)
//				{
//					parent->_left = NULL;
//					break;
//				}
//				else
//				{
//					parent->_right = NULL;
//					break;
//				}
//			}
//			else if (cur->_left == NULL && cur->_right != NULL)//cur只有左为空
//			{
//				if (parent->_left == cur)
//				{
//					parent->_left = cur->_right;
//					cur->_right = NULL;
//					break;
//				}
//				else
//				{
//					parent->_right = cur->_right;
//					cur->_right = NULL;
//					break;
//				}
//			}
//			else if (cur->_left != NULL && cur->_right == NULL)//cur只有右为空
//			{
//				if (parent->_left == cur)
//				{
//					parent->_left = cur->_left;
//					cur->_left = NULL;
//					break;
//				}
//				else
//				{
//					parent->_right = cur->_left;
//					cur->_left = NULL;
//					break;
//				}
//			}
//			else//cur左右均不为空
//			{
//				parent = cur;
//				replace = cur->_right;
//				while (replace->_left)
//				{
//					parent = replace;
//					replace = replace->_left;
//
//				}
//				BSTDataType tmp = cur->_data;
//				cur->_data = replace->_data;
//				replace->_data = tmp;
//				//return (BSTreeRemove(tree, replace->_data));//交换数字之后，不能构成搜索树
//				///////////////////////////////////////
//				if (replace->_left == NULL && replace->_right == NULL)
//				{
//					if (parent->_left == replace)
//						parent->_left = NULL;
//					else
//						parent->_right = NULL;
//				}
//				else
//				{
//					if (parent->_left == replace)
//					{
//						parent->_left = replace->_right;
//						replace->_right = NULL;
//						break;
//					}
//					else
//					{
//						parent->_right = replace->_right;
//						replace->_right = NULL;
//						break;
//					}
//					/*parent->_right = replace->_right;
//					replace->_right = NULL;
//					break;*/
//				}
//			}
//		}
//		else
//			return 0;
//	}
//	return 1;
//	
//}
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
{
	if (*ppTree == NULL)
		return NULL;
	BSTreeNode *cur = *ppTree;
	if (strcmp(cur->_key, key) > 0)
	{
		return BSTreeFind(&cur->_left, key);
	}
	else if (strcmp(cur->_key, key) < 0)
	{
		return BSTreeFind(&cur->_right, key);
	}
	else
		return cur;
}
void BSTreeInOrder(BSTreeNode** ppTree)
{
	BSTreeNode *cur = *ppTree;
	if (cur == NULL)
		return;
	BSTreeInOrder(&cur->_left);
	printf("%s:%d\n", cur->_key, cur->_value);
	BSTreeInOrder(&cur->_right);
}

//if (*ppTree == NULL)
//return 0;
//BSTreeNode* cur, *parent;
//cur = *ppTree;
//parent = cur;
//while (cur)
//{
//	if (strcmp(cur->_key, key) > 0)
//	{
//		parent = cur;
//		cur = cur->_left;
//	}
//	else if (strcmp(cur->_key, key) < 0)
//	{
//		parent = cur;
//		cur = cur->_right;
//	}
//	else
//	{
//		if (cur->_left == NULL && cur->_right != NULL)//有右无左
//		{
//			if (parent == cur)//第一个元素特殊处理
//			{
//				BSTreeNode* R = cur->_right;
//				parent->_right = R->_right;
//				cur->_right = NULL;
//
//			}
//			else
//			{
//				if (parent->_left = cur)
//					parent->_left = cur->_right;
//				else
//					parent->_right = cur->_right;
//			}
//			/*free(cur);
//			cur = NULL;*/
//		}
//		else if (cur->_left != NULL && cur->_right == NULL)//有左无右
//		{
//			if (parent == cur)
//			{
//				BSTreeNode* R = cur->_left;
//				parent->_left = R->_left;
//				cur->_left = NULL;
//
//			}
//			else
//			{
//				if (parent->_left = cur)
//					parent->_left = cur->_left;
//				else
//					parent->_right = cur->_left;
//			}
//		}
//		else if (cur->_left == NULL && cur->_right == NULL)//无左无右
//		{
//			if (parent == cur)
//			{
//				parent = NULL;
//			}
//			else
//			{
//				if (parent->_left = cur)
//					parent->_left = NULL;
//				else
//					parent->_right = NULL;
//			}
//		}
//		else//有左有右
//		{
//			BSTreeNode* replace = cur->_right;
//			parent = replace;
//			while (replace)
//			{
//				parent = replace;
//				replace = replace->_left;
//			}
//
//		}
//	}
//	/*free(cur);*/
//	cur = NULL;
//}