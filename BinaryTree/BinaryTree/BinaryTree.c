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