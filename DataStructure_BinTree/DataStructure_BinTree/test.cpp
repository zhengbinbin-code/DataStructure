#include"BinTree.hpp"


int main()
{	//����������
	/*const char* str = "ABC##DE##F##G#H##";
	BinaryTree root = NULL;
	root = CreateTree(str);*/

	//��֪ǰ�����������������У�����������
	/*char* pstr = "ABCDEFGH";
	char* istr = "CBEDFAGH";
	BinaryTree root = NULL;
	int n = strlen(pstr);
	root = CreateTreePI(pstr, istr, n);*/

	//��֪��������ͺ���������У�����������
	/*char* istr = "CBEDFAGH";
	char* lstr = "CEFDBHGA";
	BinaryTree root = NULL;
	int n = strlen(istr);
	root = CreateTreeIL(istr, lstr, n);*/

	//��֪ǰ�����������������У����ǵݹ飩����������---------����
	//char* pstr = "ABCDEFGH";
	//char* istr = "CBEDFAGH";
	//BinaryTree root = NULL;
	//int n = strlen(pstr);
	////root = NiceCreateTreePI(pstr, istr, n);

	//�ǵݹ��������ģ��
	/*printf("�ǵݹ�����������Ϊ��\t");
	NiceInOrder(root);
	printf("�ǵݹ����������Ϊ��\t");
	NicePastOrder(root);
	printf("�ǵݹ�����������Ϊ��\t");
	NicePreOrder(root);
	cout << endl;*/

	//�ݹ��������ģ��
	/*printf("�ݹ�����������Ϊ��\t");
	PreOrder(root);
	printf("\n");
	printf("�ݹ�����������Ϊ��\t");
	InOrder(root);
	printf("\n");
	printf("�ݹ����������Ϊ��\t");
	PastOrder(root);
	printf("\n");
	cout << endl;*/

	/*printf("�ǵݹ�������2���Ϊ��\t");
	StkNicePastOrder(root);
	printf("�ǵݹ��������2���Ϊ��\t");
	StkNiceInOrder(root);
	cout << endl;*/
	
	//��α�������ģ��
	/*cout << "��α����Ľ��Ϊ��" << "\t";
	LevelOrder(root);
	cout << "���β�α����Ľ��Ϊ��" << "\t";
	LevelOrder2(root);*/

	////�����K��Ľڵ����ģ��
	//int k = 0;
	//while (cin >> k, k != -1)
	//{
	//	print_kLevel_item(root, k);
	//	cout << endl;
	//}

	//���ȼ����в��Դ���
	//PriQueue<int> pq;
	//int x;
	//while (cin >> x, x != -1)	//����-1��ֹͣ����
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

	//BST�����������ñ������Դ���
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

	////BSTɾ�����Դ���
	//int kx;
	//while (cin >> kx, kx != -1)		//����-1ֹͣ
	//{
	//	cout << Remove(&mytree, kx) << endl;
	//	NiceInOrder(&mytree);
	//}


	system("pause");
	return 0;
}