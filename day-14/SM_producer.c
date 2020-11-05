#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include<sys/types.h>
#include<unistd.h>

int *count;
int input;

int main()
{
  int shmfd;

  shmfd = shm_open("/sharedMemory",O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  
  ftruncate(shmfd, sizeof(int));
  count =(int *) mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shmfd,0);
   
  while(1)
  {
   scanf("%d",&input);
   *count = input;
  }
  shm_unlink("/sharedMemory");
  return 0;
}
