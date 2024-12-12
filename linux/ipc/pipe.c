#include "header.h"

/* Pipe is unidirectional byte stream It has two ends one forreading and other for writing
Pipe is simply a buffer maintained in the kernel memory and this buffer has a maximum capacity
Further writes to the buffer than the capacity will block the write call
Read System call will act as a blocking system if you are trying to read from a pipe that is empty
Similarly write will act as blocking system if we are trying to write on a full pipe

If the reading process doesn't close the write end of the pipe the reader won't be able to see the end
of the file even after it has read all the data from the pipe so read() would block
Similarly if write process tries to write for which no process has open read descriptor the kernel sends
SIGPIPE signal to the descriptor

Pipe is only for related processes for unrelated processes we use Named Pipe(FIFO)
*/

int main() {
    int p[2],ret;
    ret = pipe(p);

    if(ret < 0) {
        perror("pipe error");
        return;
    }
    
    printf("p[0]=%d and p[1]=%d\n",p[0],p[1]);

    if(fork() == 0) {  //child 
       while(1) {
        sleep(1);
        char b[20];
        printf("Before reading in the child process.....\n");
        read(p[0],20);
        printf("After reading in the child process.... %s\n",b);
       }
       
    } else { // parent
       while(1) {
        sleep(2); // just to sync the process
        char a[20];
        printf("Enter the data.... \n");
        scanf("%s",a);
        write(p[1],a,strlen(a)+1);
       }
    }
}