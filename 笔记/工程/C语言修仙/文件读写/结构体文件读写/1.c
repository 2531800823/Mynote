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
		printf("内存分配失败\n");
			exit(EXIT_FAILURE);
	}
	strcpy(book_for_write->name,"<小甲鱼>");
	strcpy(book_for_write->authoe,"带你学c带你飞");
	strcpy(book_for_write->publisher,"零基础入门python");
	book_for_write->date.year=2020;
	book_for_write->date.month=03;
	book_for_write->date.day=25;
	
	
	if((fp=fopen("file.txt","w"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}
	fwrite(book_for_write,sizeof(struct Book),1,fp);
		fclose(fp);
	
	if((fp=fopen("file.txt","r"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}
	fread(book_for_read,sizeof(struct Book),1,fp);
	printf("书名:%s\n",book_for_write->name);
	printf("作者:%s\n",book_for_write->authoe);
	printf("出版社:%s\n",book_for_write->publisher);
	printf("出版日期:%d-%d-%d\n",book_for_write->date.year,book_for_write->date.month,book_for_write->date.day);


	fclose(fp);
	return 0;
	
}