#pragma once

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	//struct BinaryTreeNode* _parent;
	BTDataType _data;
}BTNode;

//二叉树节点个数
int BinaryTreeSize(BTNode* root);
//二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//构建二叉树
BTNode* Rebulid(char* a, int* pi);
//前序遍历
void PrevOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PastOrder(BTNode* root);
//二叉树销毁
void TreeDestory(BTNode* root);
//查找一颗二叉树的值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//层序遍历
void TreeLevelOrder(BTNode* root);





			
