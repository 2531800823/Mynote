#include<stdio.h>

int main()

{
	

	int i,j;
	
	int flag=0;
	int l;  
	scanf("%d",&l); //���ڵ�����
	
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
		
		if(flag==0)  //������� 0 ������������ѭ����� if û��ִ��
			
			printf("%d  ",i);
		
	}
	
	return 0;
	
}