#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#include "fcntl.h"
#include "assert.h"

int main(int argc, char *argv[])
{
     char *arg;
     int fd = open("tmp", O_WRONLY | O_CREATE);
     assert(fd != -1);

     arg = (char *)0x0;
     assert(write(fd, arg, 10) == -1);

     arg = (char *)0x400;
     assert(write(fd, arg, 1024) == -1);

     arg = (char *)0xfff;
     assert(write(fd, arg, 2) == -1);

     printf(1, "TEST PASSED\n");
     exit();
}