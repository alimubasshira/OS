#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t s1,s2;
int a,b,sum;

void *input_thread(void *arg)
{
  while(1)
  {
    sem_wait(&s2);                          //lock	  
    printf("getting inputs\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("got inputs\n");
    sem_post(&s1);                       //unlock
  }
}

void *processing_thread(void *arg)
{
  while(1)
  {
    sem_wait(&s1);                        //lock 	  
    printf("processing started\n");
    sum=a+b;
    printf("sum = %d\nprocessing done.............\n",sum);
    sem_post(&s2);                      //unlock 
  }
}

int main()
{
   pthread_t tid_in,tid_pro;

   printf("thread creation\n");
   
   sem_init(&s1,0,0);            //initialization
   sem_init(&s2,0,1);            //initialization

   printf("threads creadted\n");
   
   pthread_create(&tid_in,NULL,input_thread,NULL);
   pthread_create(&tid_pro,NULL,processing_thread,NULL);

   pthread_join(tid_in,NULL);
   pthread_join(tid_pro,NULL);
   
   sem_destroy(&s1);             
   sem_destroy(&s2);                     
   return 0;
}
