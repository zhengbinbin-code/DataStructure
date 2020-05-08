#pragma once

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	//struct BinaryTreeNode* _parent;
	BTDataType _data;
}BTNode;

//�������ڵ����
int BinaryTreeSize(BTNode* root);
//������Ҷ�ӽ�����
int BinaryTreeLeafSize(BTNode* root);
//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
