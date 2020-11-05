#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barr;

void *serial(void *arg)
{
   printf("serial :initialization started\n");
   sleep(2);   
   printf("serial :initialization ended\n");	
   pthread_barrier_wait(&barr);
   printf("serial :ready to execute\n");	
}

void *ethernet(void *arg)
{
   printf("ethernet :initialization started\n");
   sleep(10);   
   printf("ethernet :initialization ended\n");	
   pthread_barrier_wait(&barr);
   printf("ethernet :ready to execute\n");	
}

void *lcd(void *arg)
{
   printf("lcd :initialization started\n");
   sleep(4);   
   printf("lcd :initialization ended\n");	
   pthread_barrier_wait(&barr);
   printf("lcd :ready to execute\n");	
}

void *adc(void *arg)
{
   printf("adc :initialization started\n");
   sleep(6);   
   printf("adc :initialization ended\n");	
   pthread_barrier_wait(&barr);
   printf("adc :ready to execute\n");	
}
  

int main()
{
   pthread_t s,e,l,a;

   pthread_barrier_init(&barr, NULL, 4);
   pthread_create(&s, NULL, serial, NULL);
   pthread_create(&e, NULL, ethernet, NULL);
   pthread_create(&l, NULL, lcd, NULL);
   pthread_create(&a, NULL, adc, NULL);
  
   pthread_join(s,NULL);
   pthread_join(e,NULL);
   pthread_join(e,NULL);
   pthread_join(e,NULL);

   pthread_barrier_destroy(&barr);
   
   return 0;
}   
