#include<stdio.h>

int main()

{
	

	int i,j;
	
	int flag=0;
	int l;  
	scanf("%d",&l); //以内的质数
	
	for(i=2;i<=l;i++)
		
	{
		
		flag=0;
		
		for(j=2;j<i;j++)
			
		{
			
			if(i%j==0)
				
			{
				
				flag=1;
				
				break;
				
			}
			
		}
		
		if(flag==0)  //如果等于 0 就是上面那条循环里的 if 没有执行
			
			printf("%d  ",i);
		
	}
	
	return 0;
	
}