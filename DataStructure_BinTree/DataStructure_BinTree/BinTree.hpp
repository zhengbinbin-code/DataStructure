#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>//memset
#include<stack>
#include<iostream>
#include<queue>
#include<assert.h>

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

//输出第K层的节点
void print_kLevel_item(BtNode* ptr, int k)
{
	if (NULL == ptr || k < 0)	return;
	if (ptr != NULL && k == 0)
	{
		cout << ptr->data << " ";
	}
	else
	{
		print_kLevel_item(ptr->leftchild, k - 1);
		print_kLevel_item(ptr->rightchild, k - 1);
	}
}

int GetDepth(BtNode* ptr)
{
	if (ptr == NULL)
		return 0;
	int leftDepth = GetDepth(ptr->leftchild);
	int rightDepth = GetDepth(ptr->rightchild);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//判断是否为满二叉树---非递归
bool Is_Full_BinTree(BtNode* ptr)
{
	bool res = true;
	if (NULL == ptr)	return res;
	queue<BtNode*> q1,q2;
	int n = 1;
	q1.push(ptr);
	while (!q1.empty() || !q2.empty())
	{
		int i = 0;
		if (q1.size() < n)
		{
			res = false;
			break;
		}
		while (i < n)
		{
			BtNode* p = q1.front();	q1.pop();
			if (p->leftchild != NULL)
			{
				q2.push(p->leftchild);
			}
			if (p->rightchild != NULL)
			{
				q2.push(p->rightchild);
			}
			++i;
		}
		n += n;
		i = 0;
		if (q2.size() < n)
		{
			res = false;
			break;
		}
		while (i < n)
		{
			BtNode* p = q2.front();	q2.pop();
			if (p->leftchild != NULL)
			{
				q1.push(p->leftchild);
			}
			if (p->rightchild != NULL)
			{
				q1.push(p->rightchild);
			}
			++i;
		}
		n += n;
	}
	return res;
}

//判断是否为满二叉树---递归
bool Is_Full_BinTree2(BtNode* ptr)
{
	return (ptr == NULL) ||
		(Is_Full_BinTree2(ptr->leftchild) &&
		Is_Full_BinTree2(ptr->rightchild) &&
		GetDepth(ptr->leftchild) == GetDepth(ptr->rightchild));
}

//判断是否为完全二叉树
bool Is_Comp_BinTree(BtNode* ptr)
{
	bool res = true;
	if (NULL == ptr)	return res;
	queue<BtNode*> qu;
	qu.push(ptr);
	while (!qu.empty())
	{
		ptr = qu.front();	qu.pop();
		if (NULL == ptr)	break;
		qu.push(ptr->leftchild);
		qu.push(ptr->rightchild);
	}
	while (!qu.empty())
	{
		ptr = qu.front();	qu.pop();
		if (NULL != ptr)
		{
			res = false;
			break;
		}
	}
	return res;
}

//优先级队列
const int MAXSIZE = 100;
const int INCSIZE = 100;

template<class T>
class PriQueue
{
public:
	PriQueue() :maxsize(MAXSIZE), cursize(0)
	{
		data = new T[maxsize];
	}
	PriQueue(T* arr, int n)
	{
		maxsize = n > MAXSIZE ? n : MAXSIZE;
		cursize = n;
		data = new T[maxsize];
		/*for (int i = 0; i < n; ++i)
		{
			Push(arr[i]);
		}*/
		for (int i = 0; i < n; ++i)
		{
			data[i] = ar[i];
		}
		MakeHeap();
	}
	~PriQueue()
	{
		delete[]data;
		data = nullptr;
		maxsize = cursize = 0;
	}

	int GetSize() const
	{
		return cursize;
	}
	bool IsEmpty() const
	{
		return GetSize() == 0;
	}
	T& Front()
	{
		return data[0];
	}
	const T& Front() const
	{
		return data[0];
	}
	void Pop()
	{
		data[0] = data[cursize - 1];
		--cursize;
		AdjustDown(0, cursize - 1);
	}
	void Push(const T& x)
	{
		if (cursize >= maxsize)	return;
		data[cursize] = x;
		AdjustUp(cursize);
		++cursize;
	}
private:
	T* data;
	int maxsize;	
	int cursize;	//节点个数
	void AdjustUp(int begin)
	{
		int j = begin, i = (j - 1) / 2;
		T tmp = data[j];
		while (j > 0)
		{
			if (data[i] <= tmp)	break;
			data[j] = data[i];
			j = i;
			i = (j - 1) / 2;
		}
		data[j] = tmp;
	}
	void AdjustDown(int begin, int end)
	{
		int i = begin, j = i * 2 + 1;
		T tmp = data[i];
		while (j <= end)
		{
			if (j<end && data[j] >data[j + 1])	++j;
			if (tmp <= data[j])	break;
			data[i] = data[j];
			i = j;
			j = i * 2 + 1;
		}
		data[i] = tmp;
	}
	void MakeHeap()
	{
		int end = cursize - 1;
		int pos = (end - 1) / 2;
		while (pos >= 0)
		{
			AdjustDown(pos, end);
			--pos;
		}
	}
};

typedef int KeyType;
typedef struct BstNode
{
	struct BstNode* leftchild;
	struct BstNode* parent;
	struct BstNode* rightchild;
	KeyType key;
}BstNode;

typedef struct
{
	BstNode* head;
	int cursize;
}BSTree;

BstNode* BuyNode()
{
	BstNode* s = (BstNode*)malloc(sizeof(*s));
	if (NULL == s)	exit(EXIT_FAILURE);
	memset(s, 0, sizeof(BstNode));
	return s;
}

void FreeNode(BstNode* p)
{
	free(p);
}

void Init_BSTree(BSTree* ptree)
{
	assert(ptree != NULL);
	ptree->head = BuyNode();
	ptree->cursize = 0;
}

//非递归查找
BstNode* FindValue(BSTree* ptree, KeyType kx)
{
	if (ptree == NULL)	return NULL;
	BstNode* p = ptree->head->parent;//root
	while (p != NULL && p->key != kx)
	{
		p = kx < p->key ? p->leftchild : p->rightchild;
	}
	return p;
}

//递归查找
BstNode* Search(BstNode* ptr, KeyType kx)
{
	if (ptr == NULL || ptr->key == kx)	
		return ptr;
	else if (ptr->key > kx)	
		return Search(ptr->leftchild, kx);
	else	
		return Search(ptr->rightchild, kx);
}
BstNode* SearchValue(BSTree* ptree, KeyType kx)
{
	BstNode* p = NULL;
	if (ptree != NULL)
	{
		p = Search(ptree->head->parent, kx);
	}
	return p;
}

BstNode* First(BstNode* ptr)
{
	if (ptr != NULL && ptr->leftchild != NULL)
	{
		ptr = ptr->leftchild;
	}
	return ptr;
}
BstNode* Next(BSTree* ptree, BstNode* ptr)
{
	if (ptr == NULL)	return NULL;
	if (ptr->rightchild != NULL)
	{
		return First(ptr->rightchild);
	}
	else
	{
		BstNode* pa = ptr->parent;
		while (pa != ptree->head && ptr != pa->leftchild)
		{
			ptr = pa;
			pa = ptr->parent;
		}
		if (pa == ptree->head)
		{
			pa = NULL;
		}
		return pa;
	}
}
void NiceInOrder(BSTree* ptree)	//中序遍历(从小到大)---先找第一个,然后找下一个......
{
	assert(ptree != NULL);
	for (BstNode* p = First(ptree->head->parent); p != NULL; p = Next(ptree, p))
	{
		cout << p->key << " ";
	}
	cout << endl;
}

BstNode* Last(BstNode* ptr)
{
	while (ptr != NULL && ptr->rightchild != NULL)
	{
		ptr = ptr->rightchild;
	}
	return ptr;
}
BstNode* Prev(BSTree* ptree, BstNode* ptr)
{
	if (ptr == NULL)	return NULL;
	if (ptr->leftchild != NULL)
	{
		return Last(ptr->leftchild);
	}
	else
	{
		BstNode* pa = ptr->parent;
		while (pa != ptree->head && ptr != pa->rightchild)
		{
			ptr = pa;
			pa = ptr->parent;
		}
		if (pa == ptree->head)
		{
			pa = NULL;
		}
		return pa;
	}
}
void ResNiceInOrder(BSTree* ptree)
{
	assert(ptree != NULL);
	for (BstNode* p = Last(ptree->head->parent); p != NULL; p = Prev(ptree, p))
	{
		cout << p->key << " ";
	}
	cout << endl;
}

bool Insert(BSTree* ptree, KeyType kx)
{
	if (ptree->head->parent == NULL)
	{
		BstNode* root = BuyNode();
		root->key = kx;
		ptree->head->parent = root;
		ptree->head->leftchild = root;
		ptree->head->rightchild = root;
		root->parent = ptree->head;
		ptree->cursize += 1;
		return true;
	}
	BstNode* pa = ptree->head;			//head
	BstNode* p = ptree->head->parent;	//root
	while (p != NULL && p->key != kx)
	{
		pa = p;
		p = kx < p->key ? p->leftchild : p->rightchild;
	}
	if (p != NULL && p->key == kx)	return false;
	p = BuyNode();
	p->parent = pa;
	p->key = kx;
	if (pa->key < p->key)
	{
		pa->rightchild = p;
		if (p->key > ptree->head->rightchild->key)
		{
			ptree->head->rightchild = p;
		}
	}
	else
	{
		pa->leftchild = p;
		if (p->key < ptree->head->leftchild->key)
		{
			ptree->head->leftchild = p;
		}
	}
	ptree->cursize += 1;
	return true;
}






























