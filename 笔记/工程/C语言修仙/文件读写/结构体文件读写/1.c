#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Date
{
	int year;
	int month;
	int day;
};

struct Book
{
	char name[40];
	char authoe[40];
	char publisher[40];
	struct Date date;
};

int main(void)
{	
	FILE* fp;
	struct Book* book_for_write,*book_for_read;
	book_for_write=(struct Book*)malloc(sizeof(struct Book));
	book_for_read=(struct Book*)malloc(sizeof(struct Book));
	if(book_for_write ==NULL || book_for_read==NULL)
	{
		printf("�ڴ����ʧ��\n");
			exit(EXIT_FAILURE);
	}
	strcpy(book_for_write->name,"<С����>");
	strcpy(book_for_write->authoe,"����ѧc�����");
	strcpy(book_for_write->publisher,"���������python");
	book_for_write->date.year=2020;
	book_for_write->date.month=03;
	book_for_write->date.day=25;
	
	
	if((fp=fopen("file.txt","w"))==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(EXIT_FAILURE);
	}
	fwrite(book_for_write,sizeof(struct Book),1,fp);
		fclose(fp);
	
	if((fp=fopen("file.txt","r"))==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(EXIT_FAILURE);
	}
	fread(book_for_read,sizeof(struct Book),1,fp);
	printf("����:%s\n",book_for_write->name);
	printf("����:%s\n",book_for_write->authoe);
	printf("������:%s\n",book_for_write->publisher);
	printf("��������:%d-%d-%d\n",book_for_write->date.year,book_for_write->date.month,book_for_write->date.day);


	fclose(fp);
	return 0;
	
}