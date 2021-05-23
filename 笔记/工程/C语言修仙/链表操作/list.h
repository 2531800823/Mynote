#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//�ڵ�ṹ��
struct Node
{
	int a;
	struct Node* pNext;
};

class List
{
private:
	//ͷβָ�붨��
	Node* g_pHead = NULL;
	Node* g_pEnd = NULL;
public:
	List();
	~List();
private:
	//��ͷ�����ʼ��
	void InitListHead();
	//�����ڵ�
	struct Node* CreateNode(int a);
	
	//ɾͷ
	void DeleteHead();
	//ɾ��β��
	void DeleteTail();
	//�ͷ�����
	void FreeList();
public:
	//β���
	void AddListTail(int a);
	//ͷ���
	void AddListHead(int a);
	//����λ�����
	void AddListRand(int Index, int a);

	//��������
	void ScanList();
	//�����ƶ��ڵ㣬�����ؽڵ��ַ
	struct Node* SelectNode(int a);
	
	//ɾ��ָ���ڵ�
	void DeleteNodeRand(int a);
};




