#include<stdio.h>


int main()
{
  char a[1000]="mohitgupt";
  char b[1000];
  /* syscall(402,1,1000,a,100,2); */
  /* syscall(402,0,1000,b,100,2); */
  printf("b = %s a = %s\n",b,a);
  int i;
  for(i=0;i<10000;i++)
    {
      printf("b\n");
      fflush(stdout);
    }
}

