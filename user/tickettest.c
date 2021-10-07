#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[])
{
     int child, i;

     printf(1, "Parent PID: %d\n", getpid());

     for (i = 0; i < 5; i++) {
          child = fork();
          if (child == 0) {
               settickets(i*10 + 1);
               printf(1, "Child %d PID: %d\n", i, getpid());
               for(;;) {}
          }
     }
     exit();
}