#pragma once
#include"BinaryTree.h"
#include<stdio.h>

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;
	if (root->_left == NULL && root->_right == NULL) return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* Rebulid(char* a, int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = Rebulid(a, pi);
		++(*pi);
		root->_right = Rebulid(a, pi);
		return root;
	}
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void PastOrder(BTNode* root)
{
	if (root == NULL)
		return;
	PastOrder(root->_left);
	PastOrder(root->_right);
	printf("%c ", root->_data);
}

void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestory(root->_left);
	TreeDestory(root->_right);
	free(root);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	return NULL;
}

void TreeLevelOrder(BTNode* root)
{

}



