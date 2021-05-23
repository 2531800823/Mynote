#include<stdio.h>
int main(void)
{
		int i;
	long int f1,f2;
	f1=f2=1;

	for(i=1;i<=20;i++)
	{
		printf("%12ld %12ld",f1,f2);
		if(i%2==0) //控制输出，每四行输出换行
			printf("\n");
		f1=f1+f2;  //后一个数是前面两个数的和
		f2=f1+f2;	//后一个数是前面两个数的和
	}
	return 0;

}//1  1  2 3 5 8 13