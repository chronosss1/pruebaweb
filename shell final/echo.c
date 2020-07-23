#include <stdio.h>

int cmd_start(int argc, char ** argv) {
    int i;
    for (i = 1; argv[i]; i++){
        printf("%s\n", argv[i]);
    }
    return 0;
}
