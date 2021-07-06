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
////ͷβָ�붨��
//struct Node* g_pHead = NULL;
//struct Node* g_pEnd = NULL;
//
////��ͷ�����ʼ��
//void InitListHead();
////�����ڵ�
//struct Node* CreateNode(int a);
//
////β���
//void AddListTail(int a);
////ͷ���
//void AddListHead(int a);
////����λ�����
//void AddListRand(int Index, int a);
//
////��������
//void ScanList();
////�����ƶ��ڵ㣬�����ؽڵ��ַ
//struct Node* SelectNode(int a);
//
////ɾͷ
//void DeleteHead();
////ɾ��β��
//void DeleteTail();
////ɾ��ָ���ڵ�
//void DeleteNodeRand(int a);
////�ͷ�����
//void FreeList();
//
//int main(void)
//{
//	//��ͷ�����ʼ��
//	InitListHead();
//
//	//����
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
////�ͷ�����
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
////ɾ��ָ���ڵ�
//void DeleteNodeRand(int a)
//{
//	//�ж�������û�ж���
//	if (NULL == g_pHead->pNext)
//	{
//		printf("�����޽ڵ�\n");
//		return;
//	}
//	//�� index�ڵ�
//	struct Node *pTemp = SelectNode(a);
//	if (NULL == pTemp)
//	{
//		printf("���޴˽ڵ�\n");
//		return;
//	}
//
//	//�ҵ���
//	//�ҵ�β�ڵ����һ��
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
//		//ɾ��
//		pT->pNext = pTemp->pNext;
//		//�ͷ�
//		free(pTemp);	
//	}
//}
//
////ɾ��β��
//void DeleteTail()
//{
//	//�ж�������û�ж���
//	if (NULL == g_pHead->pNext)
//	{
//		printf("������β\n");
//		return;
//	}
//	//��һ���ڵ�
//	if (g_pHead->pNext == g_pEnd)
//	{
//		free(g_pEnd);
//		g_pHead->pNext = NULL;
//		g_pEnd = g_pHead;
//	}
//	else
//	{
//		//�ҵ�β�ڵ����һ��
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
//		//pTemp����β�͵�ǰһ����
//		//�ͷ�β��
//		free(g_pEnd);
//		//����β��
//		g_pEnd = pTemp;
//		//β�͵���һ����ֵnULL
//		g_pEnd->pNext = NULL;
//	}
//}
//
////ɾͷ
//void DeleteHead()
//{
//	//�ж�������û�ж���
//	if (NULL == g_pHead->pNext)
//	{
//		printf("������ͷ\n");
//		return;
//	}
//	//ɾ�� ��ס
//	struct Node* pTemp = g_pHead->pNext;
//	//��ͷ
//	g_pHead->pNext = g_pHead->pNext->pNext;
//	//�ͷ�
//	free(pTemp);
//}
//
////����λ�����
//void AddListRand(int Index, int a)
//{
//	//�ж�������û�ж���
//	if (NULL == g_pHead->pNext)
//	{
//		printf("�����޽ڵ�\n");
//		return;
//	}
//	//�� index�ڵ�
//	struct Node *pTemp = SelectNode(Index);
//	if (NULL == pTemp)
//	{
//		printf("���޴˽ڵ�\n");
//		return;
//	}
//
//	//�ҵ��ˣ����ӵ�ָ��λ��
//	//�����ڵ�
//	struct Node* pNode = CreateNode(a);
//	//���� //β�ͽڵ�
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
////�����ƶ��ڵ㣬�����ؽڵ��ַ
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
////��������
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
////��ͷ�����ʼ��
//void InitListHead()
//{
//	//�����ͷ
//	g_pHead = (struct Node*)malloc(sizeof(struct Node));
//	g_pHead->pNext = NULL;
//	g_pEnd = g_pHead;
//}
////ͷ���
//void AddListHead(int a)
//{
//	//����һ���ڵ�
//	struct Node* pTemp = CreateNode(a);
//	if (NULL == pTemp)
//	{
//		printf("�ڴ治��\n");
//		return ;
//	}
//	//����
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
//
////β���
//void AddListTail(int a)
//{
//	//����һ���ڵ�
//	struct Node* pTemp = CreateNode(a);
//	if (NULL == pTemp)
//	{
//		printf("�ڴ治��\n");
//		return ;
//	}
//	//����
//	g_pEnd->pNext = pTemp;
//	g_pEnd = pTemp;
//}
////�����ڵ�
//struct Node* CreateNode(int a)
//{
//	//����һ���ڵ�
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	if (NULL == pTemp)
//	{
//		printf("�ڴ治��\n");
//		return NULL;
//	}
//	//�ڵ��Ա��ֵ
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//	//���ؽڵ�
//	return pTemp;
//}
