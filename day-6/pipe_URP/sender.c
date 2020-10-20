#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int fd;
  fd = open("pipeFile",O_WRONLY);
  if(fd==0)
  {
    printf("error");
  }
  write(fd,"mubasshira\n",11);
  close(fd);
  return 0;
}
