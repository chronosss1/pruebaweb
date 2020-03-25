## Welcome to I/O FUNCTIONS LIST

You can use the [editor on GitHub](https://github.com/chronosss1/pruebaweb/edit/master/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# titulo
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/chronosss1/pruebaweb/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.


# STDIO


## printf:
int printf : (const char *, ...);

Description:
The function printf() write in the screen the strings introduced in the input.  
It returns an int, if it worked correctly it returns 0 if not it returns -1.


## fprintf:
fprintf(FILE * stream,char *, ...);

Description:
The function fprintf() write in the stream given the strings introduced in the input.  
It returns an int, if it worked correctly it returns 0 if not it returns -1.


## perror:

void perror(const char * s)

Description:
It prints the strings s followed by the error corresponding to the value of errno in that moment.  
It does not return anything.


## scanf:

int scanf(const char * format, char *)  
```diff
- La funcion tiene los argumentos simplificados(en la original son varios) hay que decidir si simplificarlo o mantener varios
```

Description:
It reads from the standard input to the char pointer indicated as 2º argument.  
It returns 0 in success or -1 if not.


## fscanf:

int fscanf(FILE * stream, const char * format, char *)
```diff
- La funcion tiene los argumentos simplificados(en la original son varios) hay que decidir si simplificarlo o mantener varios
```


Description:
It reads from the file stream given to the char pointer indicated as 3º argument.  
It returns 0 in success or -1 if not.

void * mmap(void * address, int size, int options, int flag, int fd, int offset)  
Description: maps size bytes starting at offset bytes of the file pointed by fd(file descriptor) into  the calling process virtual address space.  
Options:  
MM_READ: The mapped area can be read.  
MM_WRITE: The mapped area can be written.  
MM_EXEC: The mapped area can be executed.  
If no options are provided, the file can’t be accessed.  
Flags:  
SHARED: The mapped area can be shared between processes.  
PRIVATE: The mapped area can only be accessed by the caller process.  
It returns the pointer to the mapped area on success, NULL pointer on error.  




# PROCS


## create_proc:

int create_proc(void)

Description: creates a new process, copy of the caller process.  
It returns 0 in success or -1 if not.


## execute

int execute(const char *path, char *const arguments[ ]);

Description: execute the program located in the path with the arguments in arguments by replacing the code of the caller process.  
It returns 0 in success or -1 if not.


## pid_of:

int pid_of(void);  

Description: gives the Process identificator of the caller process.  
It returns a positive integer on success, -1 on error.


## get_priority:

int get_priority(int pid);  

Description: gives the priority of the process whose Process Identifier matchs pid.  
It returns a positive integer on success, -1 on error.


## set_priority:

int set_priority(int pid);  

Description: tryes to change the priority of the process whose Process Identifier matchs pid.  
It returns 0 on success, -1 on error.


## signal:

int signal(int pid, sig_t signal);  

Description: sends the signal “signal” to the process whose PID is pid. This function does not check reception. Only assures signal delivery.  
Signals:  
SIGKILL : kills a process.  
SIGSEGV : kills the process and starts memory dump.  
etc  
It returns 0 if pid is corresponded to a PID , -1 if not.  





## fork:
int fork(void)
Description: creates a new process, copy of the caller process.
It returns 0 in success or -1 if not.


## kill:


int kill(pid_t pid,int sig);

Description:The kill function allows you to send a signal to a process; if it is not specified which one, it will be, by default, the termination signal.


If the operation is successful, the function returns 0; otherwise, the return value is -1.


# STRING.H

## memcpy:



## kill:

void * memcpy ( void * destination, const void * source, size_t num );  

Description:Copies the values of num bytes from the location pointed to by source   directly to the memory block pointed to by destination.  

## memmove
void * memmove ( void * destination, const void * source, size_t num );  

Description:Copies the values of num bytes from the location pointed by source to the memory block pointed by destination.  


## memcmp
int memcmp ( const void * ptr1, const void * ptr2, size_t num );  

Description:Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2  

Returning 0 if they all match or a value different from 0 if they do not.  


# STDLIB.H

## rand
int rand(void);  
Description: Returns a pseudo-randomly generated number, between the range 0-RAN_MAX.  
The function is non-reetrant (it cannot be interrupted).  


## malloc
void * malloc (size_t size);  
Description: This functions allocates the specified size of bytes in the heap of the running process. Returns a pointer to the specified memory.  It returns an error ENOMEM if it cannot allocate such space in heap.  


## system

int system(const char* command);  
Description: Executes the command specified in command in the shell on a child process.   Returns:
	-0 if no shell is avaliable, nonzero value if command is NULL  
	-If child process could not be created it returns -1 and errno is set to indicate such error  
	-If all system calls succeed the return value is the termination value of the child that executed command  


## free

void free(void * pointer);  
Description: Frees the memory space located at ptr from the heap  previously allocated with  malloc(). If it has already been called, or if it has not been allocated its behaviour is undefined. If ptr is NULL nothing happens.  



# UNISTD.H


## lseek


int lseek(int fd, int offset, int whence);  

Description: Puts the file pointer of the file indicated with the file descriptor fd offset bytes from the position indicated with whence  

possible whence values :  

START (0) (offset bytes froward from the start of the file)  
CURRENT(1) (offset bytes from its current position)  
END (2) (offset bytes backwards from the end)  

It returns if it is correct the position of the pointer, it there`s an error it returns -1.  


## rewind
void rewind(int fd);  

(void rewind(file *stream); en c, decidir si dejar int o cambiar a file * como en el de linux)  

Description:  Puts the file pointer of the file indicated with the file descriptor fd at the starting position of the file.  

It does not returns anything.  

(sleep y wakeup en pg 197-198 de libro SO)  



## sleep
int sleep(int seconds);  

Description: It makes the thread which calls it to sleep during the seconds indicated in the input or a signal is received.  

It returns the time of sleep left in seconds or 0 if the time of sleep has elapsed.  




## wakeup

int sleep(thread t);  

(no estoy seguro de esta funcion)  

Description: It wakes the thread t if it is sleeping.  

It returns does not return anything.  



## Alarm

unsigned int alarm(unsigned int seconds);  

Description : alarm() arranges for a SIGALRM signal to be delivered to the calling process in seconds seconds.  
If seconds is zero, no new alarm() is scheduled.  
In any event any previously set alarm() is canceled.  


## Chdir

 int chdir (const char *path);  

Description : chdir() changes the current working directory of the calling process
       to the directory specified in path.. 


## Getcwd

char *getcwd(char * buf, size_t size);  

Description: The getcwd() function copies an absolute pathname of the current working directory to the array pointed to by buf, which is of lenght size.  


## OPEN

int open(const char *pathname, int flags);  

Description: The open() system  call opens the file specified by pathname, the return value is a file descriptor or -1 if an error occurred (in which case, errno is set appropriately).
falta definir flags… unistd.h  


## CLOSE
int close(int fd);  

Description: closes a file descriptor, so that it no longer refers to any file and may be reused.
return zero on success and -1 on error (errno is set appropriately).
definir errores unistd.h  


## READ

ssize_t read(int fd, void *buf, size_t count);  

Description: attempts to read up to count bytes from file description fd into the buffer starting at buf. On success return the number of bytes read and on error return -1 and errno is set appropriately.  


## WRITE

ssize_t write(int fd, const void *buf, size_t count);  

Description: writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd. On success return the number of written bytes and on error return -1 and errno is set appropriately.   
