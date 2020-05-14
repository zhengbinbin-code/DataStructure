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
	char* istr = "CBEDFAGH";
	char* lstr = "CEFDBHGA";
	BinaryTree root = NULL;
	int n = strlen(istr);
	root = CreateTreeIL(istr, lstr, n);

	//��֪ǰ�����������������У����ǵݹ飩����������---------����
	//char* pstr = "ABCDEFGH";
	//char* istr = "CBEDFAGH";
	//BinaryTree root = NULL;
	//int n = strlen(pstr);
	////root = NiceCreateTreePI(pstr, istr, n);

	printf("�ǵݹ�����������Ϊ��\t");
	NiceInOrder(root);
	printf("�ǵݹ����������Ϊ��\t");
	NicePastOrder(root);
	printf("�ǵݹ�����������Ϊ��\t");
	NicePreOrder(root);
	cout << endl;

	printf("�ݹ�����������Ϊ��\t");
	PreOrder(root);
	printf("\n");
	printf("�ݹ�����������Ϊ��\t");
	InOrder(root);
	printf("\n");
	printf("�ݹ����������Ϊ��\t");
	PastOrder(root);
	printf("\n");
	cout << endl;

	printf("�ǵݹ�������2���Ϊ��\t");
	StkNicePastOrder(root);
	printf("�ǵݹ��������2���Ϊ��\t");
	StkNiceInOrder(root);
	cout << endl;
	
	cout << "��α����Ľ��Ϊ��" << "\t";
	LevelOrder(root);
	cout << "���β�α����Ľ��Ϊ��" << "\t";
	LevelOrder2(root);

	////�����K��Ľڵ����ģ��
	//int k = 0;
	//while (cin >> k, k != -1)
	//{
	//	print_kLevel_item(root, k);
	//	cout << endl;
	//}


	system("pause");
	return 0;
}