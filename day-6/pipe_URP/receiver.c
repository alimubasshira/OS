#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  unsigned char rbuff[128];
  int fd;
  fd = open("pipeFile",O_RDONLY);
  read(fd,rbuff,128);
  printf("In receiver:%s\n",rbuff);
  close(fd);
  return 0;
}
