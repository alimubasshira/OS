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

  printf("enter two value:");
  scanf("%c %c",&data[0],&data[1]);

//  mkfifo(FIFO_FILE, S_IFIFO|640);

  fp=open(FIFO_FILE,O_RDWR);
  if(fp==-1)
	  printf("error in opening");

  write(fp,&data,sizeof(data));
  
  read(fp,&sum,sizeof(sum));
  close(fp);

  printf("sum of %c and %c is %c\n",data[0],data[1],sum);
  return 0;
}
