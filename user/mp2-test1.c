/**
 * This file is used to spawn children processes and set their ticket counts.
 * The children live forever, as it processes an infinite loop.
**/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[]){
     int i;
     int rc;

     printf(1, "Parent PID: %d\n", getpid());

     for (i = 1; i <= 5; i++)  {
          rc = fork();
          if (rc==0)  //the child
          {
               settickets(i * 10);      //Child process
               printf(1,"Child %d PID: %d\n",i,getpid());
               for(;;){}
          }
     }

     exit();
}