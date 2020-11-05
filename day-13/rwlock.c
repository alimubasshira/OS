#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_rwlock_t count_rwlock;
int count = 0;

void *read1_thread(void *arg)
{
    pthread_rwlock_rdlock(&count_rwlock);                          //lock	  
    printf("T1: in thread count: %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);                          //unlock
    printf("T1: After critical section\n");
}

void *read2_thread(void *arg)
{
    pthread_rwlock_rdlock(&count_rwlock);                          //lock	  
    printf("T2: in thread count: %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);                          //unlock
    printf("T2: After critical section\n");
}
void *read3_thread(void *arg)
{
    pthread_rwlock_rdlock(&count_rwlock);                          //lock	  
    printf("T3: in thread count: %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);                          //unlock
    printf("T3: After critical section\n");
}
void *write_thread(void *arg)
{
    pthread_rwlock_rdlock(&count_rwlock);                          //lock	  
    count++;
    pthread_rwlock_unlock(&count_rwlock);                          //unlock
    printf("w1: After critical section\n");
}

int main()
{
   pthread_t tid_read1,tid_read2,tid_read3,tid_write;
 
   pthread_rwlock_init(&count_rwlock,NULL);            //initialization
   
   pthread_create(&tid_read1,NULL,read1_thread,NULL);
   pthread_create(&tid_read2,NULL,read2_thread,NULL);
   pthread_create(&tid_read3,NULL,read3_thread,NULL);
   pthread_create(&tid_write,NULL,write_thread,NULL);

   pthread_join(tid_read1,NULL);
   pthread_join(tid_read2,NULL);
   pthread_join(tid_read3,NULL);
   pthread_join(tid_write,NULL);
   
   pthread_rwlock_destroy(&count_rwlock);                          
               
   return 0;
}
