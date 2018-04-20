
#include "proj4.h"


/* shell input line */
int procline(void)
{

    char *arg[MAXARG + 1];  //pointer array for runcommand
    int toktype;        // type of token in command
    int narg ;          // number of arguments so far
    int type;           //type =  FOREGROUND or BACKGROUND


    while ( 1 ) // loop forever
    {
        // take action according to token type
        switch(toktype = gettok(&arg[narg]))

        {

        case ARG:
            if(narg < MAXARG)
                narg++;
            break;

        case EOL:
        case SEMICOLON:
        case AMPERSAND:
            if(toktype == AMPERSAND)
                type = BACKGROUND;
            else
                type = FOREGROUND;

            if(narg != 0)
            { 
                // BUG 3:
                // An if statement is used to check if the first arguement is "exit".
                // If so, then the shell exits. This is not done within "runcommand"
                // because running "exit(0)" in "runcommand" will only succeed
                // in exiting"runcommand".
                if(strcmp(arg[0],"exit") == 0) {
                    exit(0);
                }
                arg[narg] = 0;
                // BUG 2:
                // Using an if statement to catch if the first argument is cd.
                if (strcmp(arg[0],"cd") == 0) {
                    // In the event that only "cd" is entered, the getenv function
                    // is used to return to the home directory.
                    if (arg[1] == NULL) {
                        chdir(getenv("HOME"));
                    } else {
                        // If a reachable directory that is readable by the chdir function is
                        // entered following "cd" then chdir is used to jump to that directory.
                        chdir(arg[1]);
                    }
                } else {
                    runcommand(arg,type);
                }
            }
            
            if( toktype == EOL )
                // BUG 1: 
                // As a result of "EOL" being reached we must reset "narg" before 
                // returning, or else it will persist and indexes of "arg" with
                // undesired content will be accessed.
            	narg = 0; 
                return;
            narg = 0;
            break;
        }
    }
}
