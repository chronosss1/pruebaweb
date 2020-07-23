#include <stdio.h>
#include <unistd.h>

int cmd_start(int argc, char ** argv){
    if (argv[1] == NULL)
        chdir("/");
    else
    {
        if (chdir(argv[1]))
            printf("Could not change directory");
    }
    return 0;
}