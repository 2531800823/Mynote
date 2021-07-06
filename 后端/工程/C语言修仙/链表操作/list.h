#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//节点结构体
struct Node
{
	int a;
	struct Node* pNext;
};

class List
{
private:
	//头尾指针定义
	Node* g_pHead = NULL;
	Node* g_pEnd = NULL;
public:
	List();
	~List();
private:
	//空头链表初始化
	void InitListHead();
	//创建节点
	struct Node* CreateNode(int a);
	
	//删头
	void DeleteHead();
	//删除尾巴
	void DeleteTail();
	//释放链表
	void FreeList();
public:
	//尾添加
	void AddListTail(int a);
	//头添加
	void AddListHead(int a);
	//任意位置添加
	void AddListRand(int Index, int a);

	//遍历链表
	void ScanList();
	//查找制定节点，并返回节点地址
	struct Node* SelectNode(int a);
	
	//删除指定节点
	void DeleteNodeRand(int a);
};




