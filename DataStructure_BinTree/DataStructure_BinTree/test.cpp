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
	/*char* istr = "CBEDFAGH";
	char* lstr = "CEFDBHGA";
	BinaryTree root = NULL;
	int n = strlen(istr);
	root = CreateTreeIL(istr, lstr, n);*/

	//已知前序遍历和中序遍历序列，（非递归）创建二叉树---------有误
	//char* pstr = "ABCDEFGH";
	//char* istr = "CBEDFAGH";
	//BinaryTree root = NULL;
	//int n = strlen(pstr);
	////root = NiceCreateTreePI(pstr, istr, n);

	//非递归遍历测试模块
	/*printf("非递归中序遍历结果为：\t");
	NiceInOrder(root);
	printf("非递归后序遍历结果为：\t");
	NicePastOrder(root);
	printf("非递归先序遍历结果为：\t");
	NicePreOrder(root);
	cout << endl;*/

	//递归遍历测试模块
	/*printf("递归先序遍历结果为：\t");
	PreOrder(root);
	printf("\n");
	printf("递归中序遍历结果为：\t");
	InOrder(root);
	printf("\n");
	printf("递归后序遍历结果为：\t");
	PastOrder(root);
	printf("\n");
	cout << endl;*/

	/*printf("非递归后序遍历2结果为：\t");
	StkNicePastOrder(root);
	printf("非递归中序遍历2结果为：\t");
	StkNiceInOrder(root);
	cout << endl;*/
	
	//层次遍历测试模块
	/*cout << "层次遍历的结果为：" << "\t";
	LevelOrder(root);
	cout << "弓形层次遍历的结果为：" << "\t";
	LevelOrder2(root);*/

	////输出第K层的节点测试模块
	//int k = 0;
	//while (cin >> k, k != -1)
	//{
	//	print_kLevel_item(root, k);
	//	cout << endl;
	//}

	//优先级队列测试代码
	//PriQueue<int> pq;
	//int x;
	//while (cin >> x, x != -1)	//输入-1以停止输入
	//{
	//	pq.Push(x);
	//}
	//while (!pq.IsEmpty())
	//{
	//	int x = pq.Front();	pq.Pop();
	//	cout << x << " ";
	//}
	//cout << endl;

	//BSTree mytree;
	//Init_BSTree(&mytree);
	////Insert();
	//int kx;
	//cin >> kx;
	//BstNode* p = SearchValue(&mytree, kx);

	//BST树遍历、逆置遍历测试代码
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 81, 94, 88, 100 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BSTree mytree;
	Init_BSTree(&mytree);
	for (int i = 0; i < n; ++i)
	{
		Insert(&mytree,arr[i]);
	}
	NiceInOrder(&mytree);
	ResNiceInOrder(&mytree);

	////BST删除测试代码
	//int kx;
	//while (cin >> kx, kx != -1)		//输入-1停止
	//{
	//	cout << Remove(&mytree, kx) << endl;
	//	NiceInOrder(&mytree);
	//}


	system("pause");
	return 0;
}