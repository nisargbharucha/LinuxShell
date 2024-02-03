#include "myshell.h"

void printCurrentDirectory() {
    char s[100];
    printf("myshell: %s > ", getcwd(s, 100));
}

void cdCommand(char* directory) {
    if (directory == NULL) {
        printCurrentDirectory();
    } else {
        if (chdir(directory) != 0) {
            perror("chdir");
        }
    }
}

void clrCommand() {
    system("clear");
}

void dirCommand(char* directory) {
    if (directory == NULL) {
        printf("dir: missing argument\n");
    } else {
        char command[1024];
        snprintf(command, sizeof(command), "ls %s", directory);
        system(command);
    }
}

void environCommand() {
    extern char** environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

void echoCommand(char* comment) {
    printf("%s\n", comment);
}

void helpCommand() {
    system("more readme");
}