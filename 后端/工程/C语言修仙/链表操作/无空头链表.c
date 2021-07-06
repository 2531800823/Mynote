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
////链表头尾指针
//struct Node* g_pHead = NULL;
//struct Node* g_pEnd = NULL;
//
////创建链表，在链表中增加一个数据  头添加
//void AddListHead(int a);
////创建链表，在链表中增加一个数据  尾添加
//void AddListTail(int a);
////指定位置插入节点
//void AddListRand(int index, int a);
//
////遍历链表  查 / 查指定的   改
//void ScanList();
////查询指定的节点
//struct Node* SelectNode(int a);
//
////链表清空
//void FreeList();
////头删除
//void DeleteListHead();
////尾删除
//void DeleteListTail();
////删除指定节点
//void DeleteListRand(int a);
//
//
////栈    头添加+头删除
////队列  头添加+尾删除  尾添加+头删除
//
//int main(void)
//{
//	int a[10] = { 1,2,3,4};
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		AddListHead(a[i]);
//	}
//	ScanList();
//	DeleteListRand(1);
//	DeleteListRand(2);
//	DeleteListRand(3);
//	DeleteListRand(4);
//	DeleteListRand(5);
//
//	ScanList();
//
//	//释放连边
//	FreeList();
//
//	system("pause");
//	return 0;
//}
//
////删除指定节点
//void DeleteListRand(int a)
//{
//	//链表判断
//	if (NULL == g_pHead)
//	{
//		printf("链表为NULL，无需释放\n");
//		return;
//	}
//	//链表有东西，找这个节点
//	struct Node* pTemp = SelectNode(a);
//	if (NULL == pTemp)
//	{
//		printf("查无此节点\n");
//		return;
//	}
//	//找打了
//	//头
//	if (g_pHead == pTemp)
//	{
//		DeleteListHead();
//	}
//	//尾
//	else if(pTemp == g_pEnd)
//	{
//		DeleteListTail();
//	}
//	else  //有多个节点
//	{ 
//		//找删除节点的前一个节点
//		struct Node* pT = g_pHead;
//		while (pT->pNext != pTemp)
//		{
//			pT = pT->pNext;
//		}
//		//找到了
//		//链接
//		pT->pNext = pTemp->pNext;
//		//释放
//		free(pTemp);
//	}
//}
//
////删除指定节点
////void DeleteListRand(int a)
////{
////	//链表判断
////	if (NULL == g_pHead)
////	{
////		printf("链表为NULL，无需释放\n");
////		return;
////	}
////	//链表有东西，找这个节点
////	struct Node* pTemp = SelectNode(a);
////	if (NULL == pTemp)
////	{
////		printf("查无此节点\n");
////		return;
////	}
////	//找打了
////	//只有一个节点
////	if (g_pHead == g_pEnd)
////	{
////		DeleteListHead();
////	}
////	//有两个节点
////	else if(g_pHead->pNext == g_pEnd)
////	{
////		if (g_pHead == pTemp)
////		{
////			DeleteListHead();
////		}
////		else
////		{
////			DeleteListTail();
////		}
////	}
////	else  //有多个节点
////	{ 
////		if (g_pHead == pTemp)
////		{
////			DeleteListHead();
////		}
////		else if (g_pEnd == pTemp)
////		{
////			DeleteListTail();
////		}
////		else
////		{
////			//找删除节点的前一个节点
////			struct Node* pT = g_pHead;
////			while (pT->pNext != pTemp)
////			{
////				pT = pT->pNext;
////			}
////			//找到了
////			//链接
////			pT->pNext = pTemp->pNext;
////			//释放
////			free(pTemp);
////		}
////	}
////}
//
////尾删除
//void DeleteListTail()
//{
//	//链表检测
//	if (NULL == g_pHead)
//	{
//		printf("链表为NULL，无需释放\n");
//		return;
//	}
//	//链表不为空
//	//链表有1个节点
//	if (g_pHead == g_pEnd)
//	{
//		free(g_pHead);
//		g_pHead = NULL;
//		g_pEnd = NULL;
//	}
//	else
//	{
//		//找尾巴前一个节点
//		struct Node* pTemp = g_pHead;
//		while (pTemp->pNext != g_pEnd)
//		{
//			pTemp = pTemp->pNext;
//		}
//		//找到了，删尾巴
//		//释放尾巴
//		free(g_pEnd);
//		//尾巴迁移
//		g_pEnd = pTemp;
//		//尾的下一个指针赋值NULL;
//		g_pEnd->pNext = NULL;
//	}
//}
//
////头删除
//void DeleteListHead()
//{
//	//链表检测
//	if (NULL == g_pHead)
//	{
//		printf("链表为NULL，无需释放\n");
//		return;
//	}
//	if (g_pHead == g_pEnd)
//	{
//		free(g_pHead);
//		g_pHead = NULL;
//		g_pEnd = NULL;
//	}
//	else
//	{
//		//记住旧的头
//		struct Node* pTemp = g_pHead;
//		//头的下一个节点变成新的头
//		g_pHead = g_pHead->pNext;
//		//释放旧的头
//		free(pTemp);
//	}
//}
//
////指定位置插入节点
//void AddListRand(int index, int a)
//{
//	//链表为空
//	if (NULL == g_pHead)  
//	{
//		printf("链表没有节点\n");
//		return;
//	}
//	//找位置
//	struct Node* pt = SelectNode(index);
//	if (NULL == pt)
//	{
//		printf("没有指定节点\n");
//		return;
//	}
//
//	//有此节点
//	//给a创建节点
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	//节点成员进行赋值
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//链接到链表上
//	if (pt == g_pEnd)
//	{
//		//尾巴得下一个 指向新得节点
//		g_pEnd->pNext = pTemp;
//		//新节点是最后一个，变成尾巴
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//先连
//		pTemp->pNext = pt->pNext;
//		//后短
//		pt->pNext = pTemp;
//	}
//}
//
////链表清空
//void FreeList()
//{
//	//记录头，防止头被修改，丢内存
//	struct Node *pTemp = g_pHead;
//	while (pTemp != NULL)
//	{
//		struct Node* pt = pTemp;
//		pTemp = pTemp->pNext;
//		free(pt);
//	}
//	//头尾清空
//	g_pHead = NULL;
//	g_pEnd = NULL;
//}
//
////查询指定的节点
//struct Node* SelectNode(int a)
//{
//	struct Node *pTemp = g_pHead;
//	//!ptep bool
//	//pt != 4  tp != 0  int 
//	while (pTemp != NULL)
//	{
//		if (a == pTemp->a)
//		{
//			return pTemp;
//		}
//
//		pTemp = pTemp->pNext;
//	}
//
//	//没找到
//	return NULL;
//}
//
////遍历链表  查 / 查指定的
//void ScanList()
//{
//	struct Node *pTemp = g_pHead;
//	//!ptep bool
//	//pt != 4  tp != 0  int 
//	while (pTemp != NULL)
//	{
//		printf("%d  ", pTemp->a);
//
//		pTemp = pTemp->pNext;
//	}
//	printf("\n");
//}
//
////创建链表，在链表中增加一个数据  尾添加
//void AddListTail(int a)
//{
//	//创建一个节点
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//
//	//节点数据进行赋值
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//链接
//	if (NULL == g_pHead || NULL == g_pEnd)
//	{
//		//链表没有东西，空链表， 即使头 也是尾巴
//		g_pHead = pTemp;
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//不为空  往尾巴上添加
//		g_pEnd->pNext = pTemp;
//		//尾巴一直指向最后一个节点
//		g_pEnd = pTemp;
//	}
//	//g_pEnd = pTemp;
//}
//
////创建链表，在链表中增加一个数据  头添加
//void AddListHead(int a)
//{
//	//创建一个节点
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//
//	//节点数据赋值
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//接在链表上
//	if (NULL == g_pHead)
//	{
//		//链表为空，新节点即使头也是尾巴
//		g_pHead = pTemp;
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//新节点的下一个指向头
//		pTemp->pNext = g_pHead;
//		//新节点就是头了
//		g_pHead = pTemp;
//	}
//}