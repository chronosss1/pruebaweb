#include <stdio.h>
#include <unistd.h>

#define CWD_SIZE 200

int cmd_start (int argc, char ** argv){
    char cwd [CWD_SIZE];
    getcwd(cwd, sizeof(cwd));
    printf("%s",cwd);
    return 0;
}