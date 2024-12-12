#include "header.h"

/*
A named pipe is also known as FIFO is a type of pipe that allows communication between unrelated processes
named pipes exists in a special file in the file system enabling independent process to communicate
named pipes are also unidirectional by default if we need two way communication we will need to make 
two named pipes which adds complexity
named pipes are blocking in nature and can lead to performance bottlenecks if not handled carefully
Named pipes can only be used for communication between processes on the same machine for communication
on other machines we will need to use network-based IPC like sockets.
Named pipes exists in the file system hence they are file system dependent
*/


// f1 is used to communicate from fifo2.c to fifo1.c and f2 vice versa

int main() {
    int fd,fd1;
    char a[20];

    mkfifo("f1",0666);
    perror("mkfifo");
    mkfifo("f2",0666);
    perror("mkfifo");

    fd = open("f1",O_RDWR);
    fd1 = open("f2",O_RDWR);

    printf("pid = %d\n",getpid());

    if(fork()) {
        while(1) {
            read(fd,a,sizeof(a));
            printf("data = %s\n",a);
            printf("Enter the data....\n");
            scanf("%s",a);
            write(fd,a,strlen(a)+1);
        }
    }else {
        while(1) {
           printf("Enter the data....\n");
            scanf("%s",a);
            write(fd1,a,strlen(a)+1);
        }
    }
}