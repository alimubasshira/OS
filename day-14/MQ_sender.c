#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>


int main()
{
  struct mq_attr cdacmq_attr;	
  mqd_t mqfd;

   cdacmq_attr.mq_flags   = 0;       /* Flags (ignored for mq_open()) */
   cdacmq_attr.mq_maxmsg  = 4;      /* Max. # of messages on queue */
   cdacmq_attr.mq_msgsize = 128;     /* Max. message size (bytes) */
   cdacmq_attr.mq_curmsgs = 0;     /* # of messages currently in queue
                                       (ignored for mq_open()) */
 
  mqfd = mq_open("/massage_queue",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);
    
  mq_send(mqfd,"sana\n",5,0);

  mq_close(mqfd);

  return 0;
}
