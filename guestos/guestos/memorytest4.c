#include<stdio.h>
#include<stdlib.h>
#include<sys/syscall.h>

int main()
{
	char a[5];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	a[3] = 'd';
	a[4] = 'e';

	syscall(402, 1, 5, a, 45, 1);
	syscall(402, 0, 5, a, 45, 1);
	
	int i =0;
	for(i=0;i<200;i++)
	{
		printf("i is %d\n", i);
		fflush(stdout);
	}	
	return 0;

}
