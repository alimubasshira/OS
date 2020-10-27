#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t count_sem;
int count = 0;

void *inc_thread(void *arg)
{
  while(1)
  {
    sem_wait(&count_sem);                          //lock	  
    count++ ;
    printf("in inc_thread count:%d\n",count);
    sem_post(&count_sem);                       //unlock
  }
}

void *dec_thread(void *arg)
{
  while(1)
  {
    sem_wait(&count_sem);                        //lock 	  
    count-- ;
    printf("in dec_thread count:%d\n",count);
    sem_post(&count_sem);                      //unlock 
  }
}

int main()
{
   pthread_t tid_inc,tid_dec;

   printf("thread creation\n");
   
   sem_init(&count_sem,0,1);            //initialization
   
   pthread_create(&tid_inc,NULL,inc_thread,NULL);
   pthread_create(&tid_dec,NULL,dec_thread,NULL);

   pthread_join(tid_inc,NULL);
   pthread_join(tid_dec,NULL);
   
   sem_destroy(&count_sem);             
               
   return 0;
}
