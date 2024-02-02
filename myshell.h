#ifndef MYSHELL_H
#define MYSHELL_H

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

// Declare functions specific to myshell
void printCurrentDirectory();
void cdCommand(char* directory);
void clrCommand();
void dirCommand(char* directory);
void environCommand();
void echoCommand(char* comment);
void helpCommand();

#endif
