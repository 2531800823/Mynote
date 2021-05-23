//#include <stdio.h>
//#include <stdlib.h>
//
////�ڵ�ṹ��
//struct Node
//{
//	int a;
//	struct Node* pNext;
//};
//
////����ͷβָ��
//struct Node* g_pHead = NULL;
//struct Node* g_pEnd = NULL;
//
////��������������������һ������  ͷ���
//void AddListHead(int a);
////��������������������һ������  β���
//void AddListTail(int a);
////ָ��λ�ò���ڵ�
//void AddListRand(int index, int a);
//
////��������  �� / ��ָ����   ��
//void ScanList();
////��ѯָ���Ľڵ�
//struct Node* SelectNode(int a);
//
////�������
//void FreeList();
////ͷɾ��
//void DeleteListHead();
////βɾ��
//void DeleteListTail();
////ɾ��ָ���ڵ�
//void DeleteListRand(int a);
//
//
////ջ    ͷ���+ͷɾ��
////����  ͷ���+βɾ��  β���+ͷɾ��
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
//	//�ͷ�����
//	FreeList();
//
//	system("pause");
//	return 0;
//}
//
////ɾ��ָ���ڵ�
//void DeleteListRand(int a)
//{
//	//�����ж�
//	if (NULL == g_pHead)
//	{
//		printf("����ΪNULL�������ͷ�\n");
//		return;
//	}
//	//�����ж�����������ڵ�
//	struct Node* pTemp = SelectNode(a);
//	if (NULL == pTemp)
//	{
//		printf("���޴˽ڵ�\n");
//		return;
//	}
//	//�Ҵ���
//	//ͷ
//	if (g_pHead == pTemp)
//	{
//		DeleteListHead();
//	}
//	//β
//	else if(pTemp == g_pEnd)
//	{
//		DeleteListTail();
//	}
//	else  //�ж���ڵ�
//	{ 
//		//��ɾ���ڵ��ǰһ���ڵ�
//		struct Node* pT = g_pHead;
//		while (pT->pNext != pTemp)
//		{
//			pT = pT->pNext;
//		}
//		//�ҵ���
//		//����
//		pT->pNext = pTemp->pNext;
//		//�ͷ�
//		free(pTemp);
//	}
//}
//
////ɾ��ָ���ڵ�
////void DeleteListRand(int a)
////{
////	//�����ж�
////	if (NULL == g_pHead)
////	{
////		printf("����ΪNULL�������ͷ�\n");
////		return;
////	}
////	//�����ж�����������ڵ�
////	struct Node* pTemp = SelectNode(a);
////	if (NULL == pTemp)
////	{
////		printf("���޴˽ڵ�\n");
////		return;
////	}
////	//�Ҵ���
////	//ֻ��һ���ڵ�
////	if (g_pHead == g_pEnd)
////	{
////		DeleteListHead();
////	}
////	//�������ڵ�
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
////	else  //�ж���ڵ�
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
////			//��ɾ���ڵ��ǰһ���ڵ�
////			struct Node* pT = g_pHead;
////			while (pT->pNext != pTemp)
////			{
////				pT = pT->pNext;
////			}
////			//�ҵ���
////			//����
////			pT->pNext = pTemp->pNext;
////			//�ͷ�
////			free(pTemp);
////		}
////	}
////}
//
////βɾ��
//void DeleteListTail()
//{
//	//������
//	if (NULL == g_pHead)
//	{
//		printf("����ΪNULL�������ͷ�\n");
//		return;
//	}
//	//����Ϊ��
//	//������1���ڵ�
//	if (g_pHead == g_pEnd)
//	{
//		free(g_pHead);
//		g_pHead = NULL;
//		g_pEnd = NULL;
//	}
//	else
//	{
//		//��β��ǰһ���ڵ�
//		struct Node* pTemp = g_pHead;
//		while (pTemp->pNext != g_pEnd)
//		{
//			pTemp = pTemp->pNext;
//		}
//		//�ҵ��ˣ�ɾβ��
//		//�ͷ�β��
//		free(g_pEnd);
//		//β��Ǩ��
//		g_pEnd = pTemp;
//		//β����һ��ָ�븳ֵNULL;
//		g_pEnd->pNext = NULL;
//	}
//}
//
////ͷɾ��
//void DeleteListHead()
//{
//	//������
//	if (NULL == g_pHead)
//	{
//		printf("����ΪNULL�������ͷ�\n");
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
//		//��ס�ɵ�ͷ
//		struct Node* pTemp = g_pHead;
//		//ͷ����һ���ڵ����µ�ͷ
//		g_pHead = g_pHead->pNext;
//		//�ͷžɵ�ͷ
//		free(pTemp);
//	}
//}
//
////ָ��λ�ò���ڵ�
//void AddListRand(int index, int a)
//{
//	//����Ϊ��
//	if (NULL == g_pHead)  
//	{
//		printf("����û�нڵ�\n");
//		return;
//	}
//	//��λ��
//	struct Node* pt = SelectNode(index);
//	if (NULL == pt)
//	{
//		printf("û��ָ���ڵ�\n");
//		return;
//	}
//
//	//�д˽ڵ�
//	//��a�����ڵ�
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	//�ڵ��Ա���и�ֵ
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//���ӵ�������
//	if (pt == g_pEnd)
//	{
//		//β�͵���һ�� ָ���µýڵ�
//		g_pEnd->pNext = pTemp;
//		//�½ڵ������һ�������β��
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//����
//		pTemp->pNext = pt->pNext;
//		//���
//		pt->pNext = pTemp;
//	}
//}
//
////�������
//void FreeList()
//{
//	//��¼ͷ����ֹͷ���޸ģ����ڴ�
//	struct Node *pTemp = g_pHead;
//	while (pTemp != NULL)
//	{
//		struct Node* pt = pTemp;
//		pTemp = pTemp->pNext;
//		free(pt);
//	}
//	//ͷβ���
//	g_pHead = NULL;
//	g_pEnd = NULL;
//}
//
////��ѯָ���Ľڵ�
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
//	//û�ҵ�
//	return NULL;
//}
//
////��������  �� / ��ָ����
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
////��������������������һ������  β���
//void AddListTail(int a)
//{
//	//����һ���ڵ�
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//
//	//�ڵ����ݽ��и�ֵ
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//����
//	if (NULL == g_pHead || NULL == g_pEnd)
//	{
//		//����û�ж����������� ��ʹͷ Ҳ��β��
//		g_pHead = pTemp;
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//��Ϊ��  ��β�������
//		g_pEnd->pNext = pTemp;
//		//β��һֱָ�����һ���ڵ�
//		g_pEnd = pTemp;
//	}
//	//g_pEnd = pTemp;
//}
//
////��������������������һ������  ͷ���
//void AddListHead(int a)
//{
//	//����һ���ڵ�
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//
//	//�ڵ����ݸ�ֵ
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//
//	//����������
//	if (NULL == g_pHead)
//	{
//		//����Ϊ�գ��½ڵ㼴ʹͷҲ��β��
//		g_pHead = pTemp;
//		g_pEnd = pTemp;
//	}
//	else
//	{
//		//�½ڵ����һ��ָ��ͷ
//		pTemp->pNext = g_pHead;
//		//�½ڵ����ͷ��
//		g_pHead = pTemp;
//	}
//}