#include "header.h"

struct msgbuf {
    long mtype;
    char data[20];
};

int main() {
    int id;
    struct msgbuf v;
    id = msgget(3,IPC_CREAT | 0666);
    perror("msgget");
    printf("before recieving the message...\n");
    msgrcv(id,&v,20,2,0); // 2 is the msg type
    printf("Data = %s\n",v->data);
}