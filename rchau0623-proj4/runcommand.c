#include "proj4.h"

// execute a command with optional wait
int runcommand(char **cline, int where) {
    pid_t pid;
    int status;

    switch(pid=fork()) {
    case -1:
        perror(SHELL_NAME);
        return (-1);
    case 0:
        execvp(*cline,cline);
        //we should never get to this code, sice execve does not return
        perror(*cline);
        exit(1);
    }
    // code for parent
    // if background process print pid and exit
    // program is running in the background
    if(where == BACKGROUND) {
        printf("[Process id %d]\n",pid);
        return (0);
    }

    // wait until all background processes exit
    while((pid=wait(NULL)) > 0) {
    }
}