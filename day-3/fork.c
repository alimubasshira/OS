#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	printf("before new process pid :%d  ppid:%d\n",getpid(),getppid());
	pid_t id =fork();

	printf("after new process pid :%d   ppid:%d\n",getpid(),getppid());
	return 0;
}
