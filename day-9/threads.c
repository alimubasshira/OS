#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void *arg)
{
  printf("in thread\n");

}

int main()
{
   pthread_t tid;

   printf("before thread creation\n");
   pthread_create(&tid,NULL,thread,NULL);
   printf("after thread creation\n");
   sleep(1);
   return 0;

}
