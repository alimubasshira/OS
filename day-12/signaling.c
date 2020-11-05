#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t s1,s2;
int a,b;

void *input_thread(void *arg)
{
  while(1)
  {
    //sem_wait(&count_sem);                          //lock	  
    printf("getting inputs\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("got inputs\n");
    //sem_post(&count_sem);                       //unlock
  }
}

void *processing_thread(void *arg)
{
  while(1)
  {
   // sem_wait(&count_sem);                        //lock 	  
    printf("processing started\n");
    sum=a+b;
    printf("processing done.............\n\n Sum = %d",&sum);
   // sem_post(&count_sem);                      //unlock 
  }
}

int main()
{
   pthread_t tid_in,tid_pro;

   printf("thread creation\n");
   
   sem_init(&s1,0,1);            //initialization
   sem_init(&s2,0,1);            //initialization
   
   pthread_create(&tid_in,NULL,input_thread,NULL);
   pthread_create(&tid_pro,NULL,processing_thread,NULL);

   pthread_join(tid_inc,NULL);
   pthread_join(tid_dec,NULL);
   
  // sem_destroy(&count_sem);             
  // sem_destroy(&count_sem);                     
   return 0;
}
