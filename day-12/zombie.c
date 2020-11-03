#include<stdio.h>
#include<unistd.h>

int main()
{
   pid_t id;

   id = fork();

   if(id == 0)
   {
     printf("child started\n");
     sleep(2);
     printf("child end\n");
   }
   else
   {
     printf("parent started\n");
     sleep(12);
     printf("parent end\n");
   }
   
   return 0;
}
