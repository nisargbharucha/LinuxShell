#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include "myshell.h"

int main() {
    char input[1024];
    char* s;

    char shellPath[1024];
    if ((s = getenv("_")) != NULL) {
        strcpy(shellPath, s);
        setenv("shell", shellPath, 1);
    }

    // Check if input is coming from a terminal
    if (isatty(fileno(stdin))) {
        // Interactive mode: solicit input from the user
        while (1) {
            printCurrentDirectory();

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            char* command = strtok(input, " ");
            char* argument = strtok(NULL, " ");

            if (strcmp(command, "cd") == 0) {
                cdCommand(argument);
            } else if (strcmp(command, "clr") == 0) {
                clrCommand();
            } else if (strcmp(command, "dir") == 0) {
                dirCommand(argument);
            } else if (strcmp(command, "environ") == 0) {
                environCommand();
            } else if (strcmp(command, "echo") == 0) {
                echoCommand(argument);
            } else if (strcmp(command, "help") == 0) {
                helpCommand();
            } else if (strcmp(command, "pause") == 0) {
                printf("Press Enter to continue...");
                getchar();
            } else if (strcmp(command, "quit") == 0) {
                break;
            } else {
                // External program invocation
                pid_t child_pid = fork();

                if (child_pid == -1) {
                    perror("fork");
                } else if (child_pid == 0) {
                    // Child process
                    char parent_env[1024];
                    snprintf(parent_env, sizeof(parent_env), "parent=%s", getenv("shell"));
                    setenv("parent", parent_env, 1);

                    // Execute the external program
                    execlp(command, command, argument, NULL);

                    // If execlp fails
                    perror("execlp");
                    exit(EXIT_FAILURE);
                } else {
                    // Parent process
                    int status;
                    waitpid(child_pid, &status, 0);
                    // Optionally, you can check the exit status of the child process
                }
            }
        }
    } else {
        // Batch mode: read commands from the file
        while (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            printf("Executing command from file: %s\n", input);

            char* command = strtok(input, " ");
            char* argument = strtok(NULL, " ");

            if (strcmp(command, "cd") == 0) {
                cdCommand(argument);
            } else if (strcmp(command, "clr") == 0) {
                clrCommand();
            } else if (strcmp(command, "dir") == 0) {
                dirCommand(argument);
            } else if (strcmp(command, "environ") == 0) {
                environCommand();
            } else if (strcmp(command, "echo") == 0) {
                echoCommand(argument);
            } else if (strcmp(command, "help") == 0) {
                helpCommand();
            } else if (strcmp(command, "pause") == 0) {
                printf("Press Enter to continue...");
                getchar();
            } else if (strcmp(command, "quit") == 0) {
                break;
            } else {
                // External program invocation
                pid_t child_pid = fork();

                if (child_pid == -1) {
                    perror("fork");
                } else if (child_pid == 0) {
                    // Child process
                    char parent_env[1024];
                    snprintf(parent_env, sizeof(parent_env), "parent=%s", getenv("shell"));
                    setenv("parent", parent_env, 1);

                    // Execute the external program
                    execlp(command, command, argument, NULL);

                    // If execlp fails
                    perror("execlp");
                    exit(EXIT_FAILURE);
                } else {
                    // Parent process
                    int status;
                    waitpid(child_pid, &status, 0);
                    // Optionally, you can check the exit status of the child process
                }
        }
    }

    return 0;

    }
}
