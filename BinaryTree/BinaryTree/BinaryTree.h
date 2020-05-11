#pragma once

typedef char BTDataType;

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
//����������
BTNode* Rebulid(char* a, int* pi);
//ǰ�����
void PrevOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PastOrder(BTNode* root);
//����������
void TreeDestory(BTNode* root);
//����һ�Ŷ�������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//�������
void TreeLevelOrder(BTNode* root);





			
