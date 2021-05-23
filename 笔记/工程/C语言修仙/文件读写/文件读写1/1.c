#include<stdio.h>
#include<stdlib.h>
#define MAX 1024
int main(void)
{
	FILE* fp;
	char buffer[MAX];
	if((fp = fopen("lines.txt","w"))==NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}
	fputs("Line one: Heelo world\n",fp);
	fputs("Line two: Heelo love!\n",fp);
	fputs("Line three: I love you!\n",fp);

	fclose(fp);
	
	if((fp = fopen("lines.txt","r"))==NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}
	while(!feof(fp))
	{
		fgets(buffer,MAX,fp);
		printf("%s",buffer);
	}

	return 0;

}