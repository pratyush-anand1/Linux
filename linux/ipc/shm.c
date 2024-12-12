#include "header.h"

/* To overcome the slowness of the msg queue ipc we use SHARED MEMORY
It allows two or more processes to share the same region in the physical memory.
One process copies the data into shared memory that data is immidiately available to all other process sharing the same segment
This provides fastest and most efficient IPC since no kernel intervention is required
Functions of shared memory are :
1)
*/



int main() {
  int id;
  char *p;
  while(1) {
    id = shmget(2,50,IPC_CREAT | 0666);
    perror("shmget");
    printf("id = %d\n",id);
    p = shmat(id,0,0); // attach into memory
    printf("Enter the String.....\n");
    scanf("%s",p);
  }
}