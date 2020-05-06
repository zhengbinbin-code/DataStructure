#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>//memset
#include<stack>
#include<iostream>
#include<queue>

using namespace std;

typedef char BTDatatype;
#define END '#'

typedef struct BtNode	//BinaryTreeNode
{
	struct BtNode* leftchild;
	struct BtNode* rightchild;
	BTDatatype data;
}BtNode, *BinaryTree;

struct BtNode* Buynode()
{
	struct BtNode *s = (struct BtNode*)malloc(sizeof(struct BtNode));
	if (NULL == s)
	{
		exit(1);
	}
	memset(s, 0, sizeof(struct BtNode));
	return s;
}

void Freenode(struct BtNode* p)
{
	free(p);
}

//递归前序遍历
void PreOrder(struct BtNode *p)
{
	if (p != NULL)
	{
		printf("%c ", p->data);
		PreOrder(p->leftchild);
		PreOrder(p->rightchild);
	}
}

//递归中序遍历
void InOrder(struct BtNode *p)
{
	if (p != NULL)
	{
		InOrder(p->leftchild);
		printf("%c ", p->data);
		InOrder(p->rightchild);
	}
}

//递归后序遍历
void PastOrder(struct BtNode *p)
{
	if (p != NULL)
	{
		PastOrder(p->leftchild);
		PastOrder(p->rightchild);
		printf("%c ", p->data);
	}
}

//创建二叉树树
struct BtNode* CreateTree(const BTDatatype* &str)
{
	struct BtNode* s = NULL;
	if (NULL != str && *str != END)
	{
		s = Buynode();
		s->data = *str;
		s->leftchild = CreateTree(++str);
		s->rightchild = CreateTree(++str);
	}
	return s;
}

int FindIndex(const BTDatatype *istr, int n, BTDatatype x)
{
	int pos = -1;
	for (int i = 0; i < n; ++i)
	{
		if (istr[i] == x)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

//已知前序遍历和中序遍历序列，创建二叉树
BtNode* CreateTreePI(const BTDatatype* pstr, const BTDatatype* istr, int n)
{
	if (NULL == pstr || NULL == istr || n < 1)
	{
		return NULL;
	}
	BtNode* s = NULL;
	if (n>0)
	{
		s = Buynode();
		s->data = *pstr;
		int pos = FindIndex(istr, n, *pstr);
		if (-1 == pos)
		{
			exit(1);
		}
		s->leftchild = CreateTreePI(pstr + 1, istr, pos);
		s->rightchild = CreateTreePI(pstr + 1 + pos, istr + 1 + pos, n - pos - 1);
	}
	return s;
}

//已知中序遍历和后序遍历序列，创建二叉树
BtNode* CreateTreeIL(const BTDatatype* istr, const BTDatatype* lstr, int n)
{
	if (NULL == istr || NULL == lstr || n < 1)
	{
		return NULL;
	}
	BtNode* s = NULL;
	if (n>0)
	{
		s = Buynode();
		s->data = lstr[n-1];
		int pos = FindIndex(istr, n, lstr[n - 1]);
		if (-1 == pos)
		{
			exit(1);
		}
		s->leftchild = CreateTreeIL(istr, lstr, pos);
		s->rightchild = CreateTreeIL(istr + 1 + pos, lstr + pos, n - pos - 1);
		
	}
	return s;
}

//非递归中序遍历二叉树
void NiceInOrder(struct BtNode *ptr)
{
	if (NULL == ptr)
	{
		return;
	}
	stack<struct BtNode* > st;
	while (!st.empty() || ptr != NULL)
	{
		while (ptr != NULL)
		{
			st.push(ptr);
			ptr = ptr->leftchild;
		}
		ptr = st.top();
		st.pop();
		cout << ptr->data << " ";
		ptr = ptr->rightchild;
	}
	cout << endl;
}

//非递归后序遍历二叉树
void NicePastOrder(struct BtNode *ptr)
{
	if (NULL == ptr)
	{
		return;
	}
	stack<struct BtNode* > st;
	BtNode* tag = NULL;
	while (!st.empty() || ptr != NULL)
	{
		while (ptr != NULL)
		{
			st.push(ptr);
			ptr = ptr->leftchild;
		}
		ptr = st.top();
		st.pop();
		if (ptr->rightchild == NULL || ptr->rightchild == tag)
		{
			cout << ptr->data << " ";
			tag = ptr;
			ptr = NULL;
		}
		else
		{
			st.push(ptr);
			ptr = ptr->rightchild;
		}
	}
	cout << endl;
}

//非递归先序遍历二叉树
void NicePreOrder(struct BtNode *ptr)
{
	if (NULL == ptr)
	{
		return;
	}
	stack<struct BtNode* > st;
	st.push(ptr);
	while (!st.empty())
	{
		ptr = st.top();
		st.pop();
		cout << ptr->data << " ";
		if (ptr->rightchild != NULL)
		{
			st.push(ptr->rightchild);
		}
		if (ptr->leftchild != NULL)
		{
			st.push(ptr->leftchild);
		}
	}
	cout << endl;
}

struct StkNode
{
	struct BtNode* pnode;
	int popnum;
public:
	StkNode(struct BtNode* p = NULL) :pnode(p), popnum(0){}
};

//非递归后序遍历2
void StkNicePastOrder(struct BtNode* ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<StkNode> st;
	st.push(StkNode(ptr));
	while (!st.empty())
	{
		StkNode node = st.top();
		st.pop();
		if (++node.popnum == 3)
		{
			cout << node.pnode->data << " ";
		}
		else
		{	
			st.push(node);
			if (node.popnum == 1 && node.pnode->leftchild != nullptr)
			{
				st.push(StkNode(node.pnode->leftchild));
			}
			else if (node.popnum == 2 && node.pnode->rightchild != nullptr)
			{
				st.push(StkNode(node.pnode->rightchild));
			}
		}
	}
	cout << endl;
}

//非递归中序遍历2
void StkNiceInOrder(struct BtNode* ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<StkNode> st;
	st.push(StkNode(ptr));
	while (!st.empty())
	{
		StkNode node = st.top();
		st.pop();
		if (++node.popnum == 2)
		{
			cout << node.pnode->data << " ";
			if (node.pnode->rightchild != nullptr)
			{
				st.push(StkNode(node.pnode->rightchild));
			}
		}
		else
		{
			st.push(node);
			if (node.popnum == 1 && node.pnode->leftchild != nullptr)
			{
				st.push(StkNode(node.pnode->leftchild));
			}
		}
	}
	cout << endl;
}

//层次遍历
void LevelOrder(struct BtNode* ptr)
{
	if (nullptr == ptr)
	{
		return;
	}
	queue<struct BtNode*>qu;
	qu.push(ptr);
	while (!qu.empty())
	{
		ptr = qu.front();
		qu.pop();
		cout << ptr->data << " ";
		if (ptr->leftchild != nullptr)
		{
			qu.push(ptr->leftchild);
		}
		if (ptr->rightchild != nullptr)
		{
			qu.push(ptr->rightchild);
		}
	}
	cout << endl;
}

//弓形层次遍历
void LevelOrder2(struct BtNode* ptr)
{
	if (nullptr == ptr)
	{
		return;
	}
	stack<struct BtNode*>st;
	queue<struct BtNode*>qu;
	st.push(ptr);
	while (!qu.empty() || !st.empty())
	{
		while (!st.empty())
		{
			ptr = st.top();
			st.pop();
			cout << ptr->data << " ";
			if (ptr->rightchild != nullptr)
			{
				qu.push(ptr->rightchild);
			}
			if (ptr->leftchild != nullptr)
			{
				qu.push(ptr->leftchild);
			}
		}
		while (!qu.empty())
		{
			ptr = qu.front();
			qu.pop();
			cout << ptr->data << " ";
			if (ptr->rightchild != nullptr)
			{
				st.push(ptr->rightchild);
			}
			if (ptr->leftchild != nullptr)
			{
				st.push(ptr->leftchild);
			}
		}
	}
	cout << endl;
}

////已知前序遍历和中序遍历序列，创建二叉树(非递归)
//BtNode* NiceCreateTreePI(const BTDatatype *pstr, const BTDatatype *istr, int n)
//{
//	stack<BtNode*> st;
//	int i = 0, j = 0;
//	BtNode *root = Buynode();
//	root->data = pstr[0];
//	st.push(root);
//	for (i = 1; i < n; ++i)
//	{
//		BtNode* s = Buynode();
//		s->data = pstr[i];
//		if (!st.empty())
//		{
//			st.top()->leftchild = s;
//		}
//		st.push(s);
//		BtNode* tmp = nullptr;
//		while (!st.empty() && st.top()->data == istr[j])
//		{
//			tmp = st.top();
//			st.pop();
//			++j;
//		}
//		if (tmp != nullptr && i < n)
//		{
//			BtNode* s = Buynode();
//			s->data = pstr[++i];
//			tmp->rightchild = s;
//			st.push(s);
//		}
//	}
//	return root;
//}





























