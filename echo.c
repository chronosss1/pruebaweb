#include <stdio.h>
#include "echo.h"
#define INPUT_SIZE 4096

void void_echo(void) {
  while (1) {
    char input[INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);
    printf("%s", input);
  }
}

void input_echo(char ** input) {
  for (char ** ptr = input; *ptr; ptr++)
    printf("%s ", *ptr);
  printf("\n");
}


void echo(int num_args, char ** args) {
  if (num_args == 1) void_echo();
  else input_echo(args+1);
}


void main(int argc,char ** argv) {
  echo(argc, argv);
}
