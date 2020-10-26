#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t id;
  int x[2],y[2];
  int pfd[2],pipe2[2];
  pipe(pfd);
  pipe(pipe2);

  printf("enter two no:");
  scanf("%d %d",&x[0],&x[1]);

  id = fork();

  if(id == 0)
  {	  
    write(pfd[1],&x,sizeof(x));
    close(pfd[1]); 
    wait(NULL);
    int rdata;
    read(pipe2[0],&rdata,sizeof(rdata));
    close(pipe2[0]);
    printf("sum:%d",rdata);
  }
  else
  {
    read(pfd[0],&y,sizeof(y));
    close(pfd[0]);
    int sum = y[0] + y[1];
    write(pipe2[1],&sum,sizeof(sum));
    close(pipe2[1]);
  }
}
