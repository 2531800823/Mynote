#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char Elimtype;

//线索存储标志位
//Link(0):表示指向左孩子和右孩子的指针
//Thread(0):表示指向前驱后继的线索
typedef enum {Link,Thread}PointerNag;// 枚举法

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerNag ltag;
	PointerNag rtag;
}BiTNode,*BiThrtree;

//创建一颗二叉树，约定用户遵照前序遍历的方式输入数据
CreateBiThrTree(BiThrtree* T)
{
	char c;
	scanf("%c", &c);
	if (' ' == c) {
		*T = NULL;
	}
	else
	{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = c;
		(*T)->ltag = Link;  //指向0
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}



int main()
{
	
	int i,j;
	for(i=1;i<8;i++)
	{
		for(j=i;j<=3;j++)
			printf(" ");
		printf("j=%d",j);
	}
	putchar('\n');

	system("pause");
	return 0;
}
