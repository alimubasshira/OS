#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	printf("pid:%d",getpid());
	printf("ppid:%d",getppid());
	return 0;
}
