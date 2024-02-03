/*
Nisarg Bharucha - 100820217
Shiv Patel - 100818727  
Joshua Cardoz - 100827231
*/


#include "myshell.h"

// Function to print the current directory in the shell prompt
void printCurrentDirectory() {
    char s[100];
    printf("myshell: %s > ", getcwd(s, 100));
}

// Function to change the current directory based on the provided argument
void cdCommand(char* directory) {
    if (directory == NULL) {
        // If no argument is provided, print the current directory
        printCurrentDirectory();
    } else {
        // Change directory, handle error if unsuccessful
        if (chdir(directory) != 0) {
            perror("chdir");
        }
    }
}

// Function to clear the console screen
void clrCommand() {
    system("clear");
}

// Function to list the contents of a directory
void dirCommand(char* directory) {
    if (directory == NULL) {
        // Print an error message if no directory is provided
        printf("dir: missing argument\n");
    } else {
        // Execute 'ls' command on the specified directory
        char command[1024];
        snprintf(command, sizeof(command), "ls %s", directory);
        system(command);
    }
}

// Function to display the environment variables
void environCommand() {
    extern char** environ;
    // Iterate through environment variables and print each one
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

// Function to echo a comment to the console
void echoCommand(char* comment) {
    printf("%s\n", comment);
}

// Function to display help information from a 'readme' file
void helpCommand() {
    system("more readme");
}
