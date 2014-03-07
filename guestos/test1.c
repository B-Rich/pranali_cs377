#include<stdio.h>


int main()
{
	syscall(401,10);
	
	int i;
	while(1)
	{
		for(i=0;i<100000;i++);
		printf("a\n");
	}
}

