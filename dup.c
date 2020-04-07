#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "provisional.h"
int dupNuevo(int fd) {
    /*
    return assign_fd(fd,DUP,0); //return __fcntl (fd, F_DUPFD, 0);
    */
   return fcntl (fd, F_DUPFD, 0);
}
/*
// haría la función de fnctl en linuxfcntl (fd, F_DUPFD, 0);
assign_fd(int fd,int cmd) { // no entiendo del todo como funciona, tampoco estoy seguro de si lo tiene
                            // que hacer nuestro grupo o solo definirla
}
*/