#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutexattr_t mutex_attr;
pthread_mutex_t count_mutex;
int count = 0;

void *inc_thread(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&count_mutex);                          //lock	  
    count++ ;
    printf("in inc_thread count:%d\n",count);
    pthread_mutex_unlock(&count_mutex);                       //unlock
  }
}

void *dec_thread(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&count_mutex);                        //lock 	  
    count-- ;
    printf("in dec_thread count:%d\n",count);
    pthread_mutex_unlock(&count_mutex);                      //unlock 
  }
}

int main()
{
   pthread_t tid_inc,tid_dec;

   printf("thread creation\n");
   
   pthread_mutexattr_init(&mutex_attr);
   pthread_mutex_init(&count_mutex,&mutex_attr);                        //initialization
   
   pthread_create(&tid_inc,NULL,inc_thread,NULL);
   pthread_create(&tid_dec,NULL,dec_thread,NULL);

   pthread_join(tid_inc,NULL);
   pthread_join(tid_dec,NULL);
   
   pthread_mutex_destroy(&count_mutex);             
   pthread_mutexattr_destroy(&mutex_attr);             
   return 0;
}
