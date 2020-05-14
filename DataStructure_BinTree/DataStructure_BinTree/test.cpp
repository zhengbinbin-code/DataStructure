#include"BinTree.hpp"


int main()
{	//创建二叉树
	/*const char* str = "ABC##DE##F##G#H##";
	BinaryTree root = NULL;
	root = CreateTree(str);*/

	//已知前序遍历和中序遍历序列，创建二叉树
	/*char* pstr = "ABCDEFGH";
	char* istr = "CBEDFAGH";
	BinaryTree root = NULL;
	int n = strlen(pstr);
	root = CreateTreePI(pstr, istr, n);*/

	//已知中序遍历和后序遍历序列，创建二叉树
	char* istr = "CBEDFAGH";
	char* lstr = "CEFDBHGA";
	BinaryTree root = NULL;
	int n = strlen(istr);
	root = CreateTreeIL(istr, lstr, n);

	//已知前序遍历和中序遍历序列，（非递归）创建二叉树---------有误
	//char* pstr = "ABCDEFGH";
	//char* istr = "CBEDFAGH";
	//BinaryTree root = NULL;
	//int n = strlen(pstr);
	////root = NiceCreateTreePI(pstr, istr, n);

	printf("非递归中序遍历结果为：\t");
	NiceInOrder(root);
	printf("非递归后序遍历结果为：\t");
	NicePastOrder(root);
	printf("非递归先序遍历结果为：\t");
	NicePreOrder(root);
	cout << endl;

	printf("递归先序遍历结果为：\t");
	PreOrder(root);
	printf("\n");
	printf("递归中序遍历结果为：\t");
	InOrder(root);
	printf("\n");
	printf("递归后序遍历结果为：\t");
	PastOrder(root);
	printf("\n");
	cout << endl;

	printf("非递归后序遍历2结果为：\t");
	StkNicePastOrder(root);
	printf("非递归中序遍历2结果为：\t");
	StkNiceInOrder(root);
	cout << endl;
	
	cout << "层次遍历的结果为：" << "\t";
	LevelOrder(root);
	cout << "弓形层次遍历的结果为：" << "\t";
	LevelOrder2(root);

	////输出第K层的节点测试模块
	//int k = 0;
	//while (cin >> k, k != -1)
	//{
	//	print_kLevel_item(root, k);
	//	cout << endl;
	//}


	system("pause");
	return 0;
}