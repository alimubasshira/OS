#include<stdio.h>
#include<unistd.h>

int main()
{
  unsigned char rbuff[128];
  pid_t id;
  int pfd[2];
  pipe(pfd);

  id = fork();

  if(id == 0)
  {
    read(pfd[0],rbuff,128);
    close(pfd[0]);
    printf("child:%s\n",rbuff);
  }
  else
  {
    write(pfd[1],"cdac\n",5);
    close(pfd[1]);
  }

}
