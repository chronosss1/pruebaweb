CCFLAGS = -Wall -g



shell: shell.o

	gcc $(CCFLAGS) -o shell shell.c



provisional.o: provisional.h dup.c
	gcc $(CCFLAGS) -c dup.c



shell.o: provisional.h shell.c

	gcc $(CCFLAGS) -c shell.c



shell-static: provisional.o shell.o

	gcc $(CCFLAGS) -o shell-static -static provisional.o shell.o





all: clean shell.o shell provisional.o





clean:

	rm shell *.o



cleanstatic:

	rm shell-static