#include "header.h"

/*
msg queues are an IPC mechanism that allows processes to communicate by sending and recieving msgs.
Unlike pipes and shared memory msg queues allows asynchronous,structured communication b/w processes.
asynchronous communication means a process can send a msg to the queueand continue executing without
waiting for the nsg to be recieved. Data is transffered in the form of discrete msgs each msg can have
its own structureand be processed independently this is different from pipe where the data is treated as
a continous stream of bytes.Even this can be used by unrelated processes.
Each nsg on msg queue has typically has an association type allowing the recievers to fetch specific types
of msgs based on priority or content. 
It is bi-directional in nature
msg queues are managed by the kernel so it is persistent across process lifetimes allowing communication even 
if one of the processes terminates.

When two process has to communicate through message queues kernel stores it in a linked list send the data to it
and kernel has to do a lot of work that's why it is slowest IPC. Overall it adds overhead hence slow.

Functions : msgget() , msgsnd() , msgrcv() , msgctl()(control operation)

To check the message queue in the linux terminal we pass command 'ipcs -q'
and to delete the msg queue we pass command -> 'ipcrm -q id'
*/

struct msgbuf {
    long mtype;
    char data[20];
};

int main(int argc , char **argv) {
int id;
struct msgbuf v;
id = msgget(3,IPC_CREAT | 0666);
perror("msgget");
v.mtype = atoi(argv[1]);
strcpy(v.data,argv[2]);     
printf("id = %d\n",id);
msgsnd(id,&v,strlen(v.data)+1,0);
}