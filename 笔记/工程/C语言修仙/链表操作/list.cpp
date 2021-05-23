#include "list.h"

List::List()
{
	//��ͷ�����ʼ��
	InitListHead();
}
List::~List()
{
	//�ͷ�����
	FreeList();
}

//�ͷ�����
void List::FreeList()
{
	Node* pTemp = g_pHead;

	while (pTemp != NULL)
	{
		Node* pT = pTemp;
		pTemp = pTemp->pNext;
		free(pT);
	}
	g_pHead = NULL;
	g_pEnd = NULL;
}

//ɾ��ָ���ڵ�
void List::DeleteNodeRand(int a)
{
	//�ж�������û�ж���
	if (NULL == g_pHead->pNext)
	{
		cout << "�����޽ڵ�\n";
		return;
	}
	//�� index�ڵ�
	Node *pTemp = SelectNode(a);
	if (NULL == pTemp)
	{
		cout << "���޴˽ڵ�\n";
		return;
	}

	//�ҵ���
	//�ҵ�β�ڵ����һ��
	if (pTemp == g_pEnd)
	{
		DeleteTail();
	}
	else
	{
		Node* pT = g_pHead;

		while (pT != NULL)
		{
			if (pTemp == pT->pNext)
			{
				break;
			}
			pTemp = pTemp->pNext;
		}

		//ɾ��
		pT->pNext = pTemp->pNext;
		//�ͷ�
		free(pTemp);	
	}
}

//ɾ��β��
void List::DeleteTail()
{
	//�ж�������û�ж���
	if (NULL == g_pHead->pNext)
	{
		cout << "������β\n";
		return;
	}
	//��һ���ڵ�
	if (g_pHead->pNext == g_pEnd)
	{
		free(g_pEnd);
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
	}
	else
	{
		//�ҵ�β�ڵ����һ��
		Node* pTemp = g_pHead->pNext;

		while (pTemp != NULL)
		{
			if (g_pEnd == pTemp->pNext)
			{
				break;
			}
			pTemp = pTemp->pNext;
		}
		//pTemp����β�͵�ǰһ����
		//�ͷ�β��
		free(g_pEnd);
		//����β��
		g_pEnd = pTemp;
		//β�͵���һ����ֵnULL
		g_pEnd->pNext = NULL;
	}
}

//ɾͷ
void List::DeleteHead()
{
	//�ж�������û�ж���
	if (NULL == g_pHead->pNext)
	{
		cout << "������ͷ\n";
		return;
	}
	//ɾ�� ��ס
	Node* pTemp = g_pHead->pNext;
	//��ͷ
	g_pHead->pNext = g_pHead->pNext->pNext;
	//�ͷ�
	free(pTemp);
}

//����λ�����
void List::AddListRand(int Index, int a)
{
	//�ж�������û�ж���
	if (NULL == g_pHead->pNext)
	{
		cout << "�����޽ڵ�\n";
		return;
	}
	//�� index�ڵ�
	Node *pTemp = SelectNode(Index);
	if (NULL == pTemp)
	{
		cout << "���޴˽ڵ�\n";
		return;
	}

	//�ҵ��ˣ����ӵ�ָ��λ��
	//�����ڵ�
	Node* pNode = CreateNode(a);
	//���� //β�ͽڵ�
	if (pTemp == g_pEnd) 
	{
		AddListTail(a);
	}
	else
	{
		pNode->pNext = pTemp->pNext;
		pTemp->pNext = pNode;
	}
}

//�����ƶ��ڵ㣬�����ؽڵ��ַ
Node* List::SelectNode(int a)
{
	Node* pTemp = g_pHead->pNext;

	while (pTemp != NULL)
	{
		if (a == pTemp->a)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}

	return NULL;
}

//��������
void List::ScanList()
{
	Node* pTemp = g_pHead->pNext;

	while (pTemp != NULL)
	{
		cout <<  pTemp->a << "  ";
		pTemp = pTemp->pNext;
	}
	cout << '\n';
}

//��ͷ�����ʼ��
void List::InitListHead()
{
	//�����ͷ
	g_pHead = (Node*)malloc(sizeof(Node));
	g_pHead->pNext = NULL;
	g_pEnd = g_pHead;
}
//ͷ���
void List::AddListHead(int a)
{
	//����һ���ڵ�
	Node* pTemp = CreateNode(a);
	if (NULL == pTemp)
	{
		cout << "�ڴ治��\n";
		return ;
	}
	//����
	pTemp->pNext = g_pHead->pNext;
	g_pHead->pNext = pTemp;
}

//β���
void List::AddListTail(int a)
{
	//����һ���ڵ�
	Node* pTemp = CreateNode(a);
	if (NULL == pTemp)
	{
		cout << "�ڴ治��\n";
		return ;
	}
	//����
	g_pEnd->pNext = pTemp;
	g_pEnd = pTemp;
}
//�����ڵ�
Node* List::CreateNode(int a)
{
	//����һ���ڵ�
	Node* pTemp = (Node*)malloc(sizeof(Node));
	if (NULL == pTemp)
	{
		cout << "�ڴ治��\n";
		return NULL;
	}
	//�ڵ��Ա��ֵ
	pTemp->a = a;
	pTemp->pNext = NULL;
	//���ؽڵ�
	return pTemp;
}
