#define _CRT_SECURE_NO_WARNINGS

#include"KeyValue.h"
test()
{
	BSTreeNode* tree = NULL;
	char str[10] = { '0' };
	scanf("%s", str);
	BSTreeInsert(&tree, str,1);
	BSTreeInsert(&tree, "C", 1);
	BSTreeInsert(&tree, "B", 1);
	BSTreeInsert(&tree, "Db", 1);

	BSTreeInsert(&tree, "Da", 1);
	BSTreeInsert(&tree, "F", 1);
	BSTreeInsert(&tree, "E", 1);
	BSTreeInOrder(&tree);
	BSTreeNode * Find = BSTreeFind(&tree, "job1");
	if (Find == NULL)
		printf("没有找到需要找的数据\n");
	else
		printf("%s", Find->_key);

	BSTreeRemove(&tree, "F");

	BSTreeInOrder(&tree);
}

void TestBSTree1()
{
	char str[10] = { '0' };
	BSTreeNode* pTree = NULL;
	while (1)
	{
		BSTreeNode* node;
		scanf("%s", str);
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		node = BSTreeFind(&pTree, str);
		if (node)
		{
			node->_value++;
		}
		else
		{
			BSTreeInsert(&pTree, str, 1);
		}
	}

	BSTreeInOrder(&pTree);
}
int main()
{

	test();
	//TestBSTree1();
	system("pause");
	return 0;
}