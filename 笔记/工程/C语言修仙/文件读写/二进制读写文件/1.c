#include<stdio.h>
#include<stdlib.h>


int main(void)
{	
	FILE* fp;
	if((fp=fopen("text.txt","wb"))==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(EXIT_FAILURE);
	}
	fputc('5',fp);
	fputc('2',fp);
	fputc('1',fp);
	fputc('\n',fp);
	fclose(fp);
	return 0;

}