//para compilar
// gcc shellv2.c -ldl -o shell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dlfcn.h>
#define MAXSIZE 200
#define MAXSIZEV2 210
#define MAXSEG 30
#define rootfolder "./"
#define FILELEN 15
#define F_SIZE 200
#define DIR_SIZE 1024 //esto no estoy seguro de que siempre sea así o como va
#define FUNCPATH "/media/sf_compartir_ubuntu/ASOC/v3/" //es la directorio en el que se guardan las librerías dinámicas

struct library {
    void * handler;
    int (* pointer) (int,char**);
    char name[MAXSIZE];
};

struct library * loaded_functions[F_SIZE]; //igual hay que implementar algo por si se llenara supongo
int funcs_size = 0;
int filled = 0;

int exitShell (char ** blocks){
    return (!strcmp(blocks[0],"exit") || !strcmp(blocks[0],"quit") || !strcmp(blocks[0],"bye"));
}s

int search_boundaries (int funcs_size, int filled){
    if (filled)
        return F_SIZE-1;
    else
        return funcs_size;
    
}

int parse (char * input, char ** blocks){
    int i=1;
    if ((blocks[0] = strtok (input, "\n \0"))==NULL){
        return -1;
    }
    while ((blocks[i]=strtok(NULL,"\n \0"))!=NULL){
        i++;
    }

    return 0;
}

int processCommand(char ** blocks){
    pid_t pid = fork();
    if (pid<0){
        perror("Process could not be created");
    }else if (pid==0){
        if (execv(blocks[0], blocks) == -1)
            perror("");
        exit(0);
    }else{
        wait(NULL);
    }
    return 0;
}

int exec_function(struct library * lib,char ** argv) {
    int argc = 1;
    return lib -> pointer(argc,argv);
}

void mark_filled(int funcs_size){
    if (funcs_size==F_SIZE)
        filled = 1;
}

int load_cmd(const char * path, struct library * lib) {
    printf("loading path: %s\n", path);
    void * handler = dlopen(path, RTLD_LAZY);
    if (!handler) { printf("dlopen failure: %s\n", dlerror()); return 0;}
    int (*ptr)(int, char**) = dlsym(handler, "cmd_start");
    lib -> handler = handler;
    lib -> pointer = ptr;
    strcpy(lib->name, path);
    printf("Loading function: %s on position: %d\n", path, funcs_size);
    loaded_functions[funcs_size] = lib;
    funcs_size++;
    mark_filled(funcs_size);
    funcs_size = funcs_size%F_SIZE;
    return 1;
}

void process_name(char * input, char * output) { //hacer bien esta función(realmente creo que esto es mas eficiente que llamar a otra función)
    char buf [MAXSIZE];
    strcpy(buf, "./");
    strcat(buf, input);
    strcat(buf, ".so\0");
    strcpy(output, buf);
}

int search_function(const char * path,char ** blocks) {
    int i = 0;
    printf("Searching up to: %d \n", funcs_size);
    for (i = 0; i < search_boundaries(funcs_size, filled); i++) {
        if (!strcmp(loaded_functions[i]->name, path)) {
            printf("loaded_funtion number: %d; name: %s\n", i, loaded_functions[i]->name);
            exec_function(loaded_functions[i],blocks);
            return 1;
        }
    }
    return 0;
}

void prompt() {
	char cwd[DIR_SIZE+1];
	getcwd(cwd, sizeof(cwd));
	strcat(cwd, ">");
	printf("%s", cwd);
}

char * concatenate(const char *s1, const char *s2) {
    char *s3 = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(s3,s1);
    strcat(s3,s2);
    return s3;
}


int main (int argc, char ** argv){
    int exit = 1;
    char * input = (char *) malloc (sizeof(char)*MAXSIZE);
    char ** blocks = (char **) malloc (sizeof(char*)*MAXSEG);
    struct library *lib;
    char buf [MAXSIZEV2];
    char path [MAXSIZE];

    while (1){
        printf("ASOC>");
        prompt();
        fgets(input, MAXSIZE, stdin);
        if (parse(input,blocks))
            continue;
        if (exitShell(blocks))
            return 0;
        process_name(blocks[0],path);
        char * fpath = concatenate(FUNCPATH,path);
        if (!search_function(fpath,blocks)) {
            lib = malloc (sizeof(struct library));
            if (load_cmd(fpath,lib)) {
                int result = exec_function(lib,blocks);
                printf("returned %d\n", result);
            }
        }
    }
}