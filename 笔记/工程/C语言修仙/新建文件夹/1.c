#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char Elimtype;

//�����洢��־λ
//Link(0):��ʾָ�����Ӻ��Һ��ӵ�ָ��
//Thread(0):��ʾָ��ǰ����̵�����
typedef enum {Link,Thread}PointerNag;// ö�ٷ�

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerNag ltag;
	PointerNag rtag;
}BiTNode,*BiThrtree;

//����һ�Ŷ�������Լ���û�����ǰ������ķ�ʽ��������
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
		(*T)->ltag = Link;  //ָ��0
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
