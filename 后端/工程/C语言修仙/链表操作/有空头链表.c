//#include <stdio.h>
//#include <stdlib.h>
//
////节点结构体
//struct Node
//{
//	int a;
//	struct Node* pNext;
//};
//
////头尾指针定义
//struct Node* g_pHead = NULL;
//struct Node* g_pEnd = NULL;
//
////空头链表初始化
//void InitListHead();
////创建节点
//struct Node* CreateNode(int a);
//
////尾添加
//void AddListTail(int a);
////头添加
//void AddListHead(int a);
////任意位置添加
//void AddListRand(int Index, int a);
//
////遍历链表
//void ScanList();
////查找制定节点，并返回节点地址
//struct Node* SelectNode(int a);
//
////删头
//void DeleteHead();
////删除尾巴
//void DeleteTail();
////删除指定节点
//void DeleteNodeRand(int a);
////释放链表
//void FreeList();
//
//int main(void)
//{
//	//空头链表初始化
//	InitListHead();
//
//	//操作
//	AddListTail(1);
//	AddListTail(2);
//	AddListTail(3);
//	AddListTail(4);
//
//
//	ScanList();
//	DeleteNodeRand(1);
//	DeleteNodeRand(2); 
//	DeleteNodeRand(3); 
//	DeleteNodeRand(4);
//	DeleteNodeRand(1);
//
//	ScanList();
//
//	FreeList();
//	system("pause");
//	return 0;
//}
//
////释放链表
//void FreeList()
//{
//	struct Node* pTemp = g_pHead;
//
//	while (pTemp != NULL)
//	{
//		struct Node* pT = pTemp;
//		pTemp = pTemp->pNext;
//		free(pT);
//	}
//	g_pHead = NULL;
//	g_pEnd = NULL;
//}
//
////删除指定节点
//void DeleteNodeRand(int a)
//{
//	//判断链表有没有东西
//	if (NULL == g_pHead->pNext)
//	{
//		printf("链表无节点\n");
//		return;
//	}
//	//找 index节点
//	struct Node *pTemp = SelectNode(a);
//	if (NULL == pTemp)
//	{
//		printf("查无此节点\n");
//		return;
//	}
//
//	//找到了
//	//找到尾节点的上一个
//	if (pTemp == g_pEnd)
//	{
//		DeleteTail();
//	}
//	else
//	{
//		struct Node* pT = g_pHead;
//
//		while (pT != NULL)
//		{
//			if (pTemp == pT->pNext)
//			{
//				break;
//			}
//			pTemp = pTemp->pNext;
//		}
//
//		//删除
//		pT->pNext = pTemp->pNext;
//		//释放
//		free(pTemp);	
//	}
//}
//
////删除尾巴
//void DeleteTail()
//{
//	//判断链表有没有东西
//	if (NULL == g_pHead->pNext)
//	{
//		printf("链表无尾\n");
//		return;
//	}
//	//有一个节点
//	if (g_pHead->pNext == g_pEnd)
//	{
//		free(g_pEnd);
//		g_pHead->pNext = NULL;
//		g_pEnd = g_pHead;
//	}
//	else
//	{
//		//找到尾节点的上一个
//		struct Node* pTemp = g_pHead->pNext;
//
//		while (pTemp != NULL)
//		{
//			if (g_pEnd == pTemp->pNext)
//			{
//				break;
//			}
//			pTemp = pTemp->pNext;
//		}
//		//pTemp就是尾巴的前一个了
//		//释放尾巴
//		free(g_pEnd);
//		//变新尾巴
//		g_pEnd = pTemp;
//		//尾巴的下一个赋值nULL
//		g_pEnd->pNext = NULL;
//	}
//}
//
////删头
//void DeleteHead()
//{
//	//判断链表有没有东西
//	if (NULL == g_pHead->pNext)
//	{
//		printf("链表无头\n");
//		return;
//	}
//	//删除 记住
//	struct Node* pTemp = g_pHead->pNext;
//	//变头
//	g_pHead->pNext = g_pHead->pNext->pNext;
//	//释放
//	free(pTemp);
//}
//
////任意位置添加
//void AddListRand(int Index, int a)
//{
//	//判断链表有没有东西
//	if (NULL == g_pHead->pNext)
//	{
//		printf("链表无节点\n");
//		return;
//	}
//	//找 index节点
//	struct Node *pTemp = SelectNode(Index);
//	if (NULL == pTemp)
//	{
//		printf("查无此节点\n");
//		return;
//	}
//
//	//找到了，连接到指定位置
//	//创建节点
//	struct Node* pNode = CreateNode(a);
//	//链接 //尾巴节点
//	if (pTemp == g_pEnd) 
//	{
//		AddListTail(a);
//	}
//	else
//	{
//		pNode->pNext = pTemp->pNext;
//		pTemp->pNext = pNode;
//	}
//}
//
////查找制定节点，并返回节点地址
//struct Node* SelectNode(int a)
//{
//	struct Node* pTemp = g_pHead->pNext;
//
//	while (pTemp != NULL)
//	{
//		if (a == pTemp->a)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->pNext;
//	}
//
//	return NULL;
//}
//
////遍历链表
//void ScanList()
//{
//	struct Node* pTemp = g_pHead->pNext;
//
//	while (pTemp != NULL)
//	{
//		printf("%d  ", pTemp->a);
//		pTemp = pTemp->pNext;
//	}
//	printf("\n");
//}
//
////空头链表初始化
//void InitListHead()
//{
//	//链表空头
//	g_pHead = (struct Node*)malloc(sizeof(struct Node));
//	g_pHead->pNext = NULL;
//	g_pEnd = g_pHead;
//}
////头添加
//void AddListHead(int a)
//{
//	//创建一个节点
//	struct Node* pTemp = CreateNode(a);
//	if (NULL == pTemp)
//	{
//		printf("内存不足\n");
//		return ;
//	}
//	//链接
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
//
////尾添加
//void AddListTail(int a)
//{
//	//创建一个节点
//	struct Node* pTemp = CreateNode(a);
//	if (NULL == pTemp)
//	{
//		printf("内存不足\n");
//		return ;
//	}
//	//链接
//	g_pEnd->pNext = pTemp;
//	g_pEnd = pTemp;
//}
////创建节点
//struct Node* CreateNode(int a)
//{
//	//创建一个节点
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	if (NULL == pTemp)
//	{
//		printf("内存不足\n");
//		return NULL;
//	}
//	//节点成员赋值
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//	//返回节点
//	return pTemp;
//}
