#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO_FILE "Twoway_pipe"

int main()
{
  int fp;
  char data[2],sum;

  fp=open(FIFO_FILE,O_RDWR);
  if(fp == -1)
     printf("error in opening");

  read(fp,&data,sizeof(data));
  close(fp);
  
  sum = ((data[0]-48) + (data[1]-48)+48);
//  sum = data[0] + data[1];

  write(fp,&sum,sizeof(sum));

  printf("sum of %c and %c is %c\n",data[0],data[1],sum);
  return 0;
}

