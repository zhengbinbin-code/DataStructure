#pragma once

typedef int BTDataType;

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
