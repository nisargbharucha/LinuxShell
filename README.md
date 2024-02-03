# LinuxShell 

## Introduction
This repository contains the a simple shell built in C. It was created for educational purposes to learn more about low-level programming in Linux, and how to create a UNIX shell using the C language. This shell has basic capabilities including the ability to process simple Linux commands, as well as avoid commands that are not recognized.

## Features
- Internal command: `cd` for changing the current working directory.
- Internal command: `clr` for clearing the screen
- Internal command: `dir` for listing the contents of current working directory
- Internal command: `environ` to list all environment settings
- Internal command: `echo` to display a comment onto the terminal
- Internal command: `help` to display a user manual
- Internal command: `pause` to pause the operation of the shell until `Enter` is pressed
- Internal command: `quit` to quit the shell

- If a command that is not recognized as an internal command, the shell will ignore it and let the user know that it is an invalid command.


## Installation and Compilation 
- To compile this shell, first move your current working directory to the location on your machine the code is located using a series of `cd` commands
- Then run the following command in your terminal: `make`. This will compile all the required files for this shell program to work
- Finally, run the following command `./myshell`
