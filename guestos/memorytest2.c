#include<stdio.h>


int main()
{
	//syscall(401,10000000);
	char a[10]="mohitgupt";
	char b[10];
	syscall(402,1,10,a,10,2);
	syscall(402,0,10,b,10,2);	
	printf("b = %s a = %s\n",b,a);
	fflush(stdout);
	//int i;
	//while(1)
	//{
		//for(i=0;i<100000;i++);
		//printf("a\n");
//	}
}

