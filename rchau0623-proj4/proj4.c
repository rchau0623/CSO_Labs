
#include "proj4.h"

/*
 * Bug 1: Only the first command works properly
 * Location: procline.c, lines: 64 - 68.
 * Description: An if statement is used to check if the first arguement 
 *     is "exit". If so, then the shell exits. This is not done within 
 *     "runcommand" because running "exit(0)" in "runcommand" will only 
 *     succeed in exiting the "runcommand" function.
 * 
 * Bug 2: cd command does not behave as expected
 * Location: procline.c, lines: 46 - 60.
 * Description: Using an if statement to catch if the first argument is 
 *     "cd", the second argument must then be checked for. In the event 
 *     that only "cd" is entered, the "getenv" function is used to return 
 *     to the home directory. If a reachable directory that is readable 
 *     by the "chdir" function is entered following "cd", then "chdir" is 
 *     used to jump to that directory. In the event that the first argument
 *     is not "cd", then the shell runs normally, calling "runcommand".
 * 
 * Bug 3: exit command does not terminate the shell
 * Location: procline.c, lines: 37 - 44.
 * Description: An if statement is used to check if the first argument is 
 *     "exit". If so, then the shell exits. This is not done within 
 *     "runcommand" because running "exit(0)" in "runcommand" will only 
 *     succeed in exiting"runcommand".
 * 
 * Bug 4: Pressing Ctrl+C should not kill the shell
 * Location: proj4.c, lines: 45-51, 60 - 64.
 * Description: Using the "signal" function to catch and handle "CTRL+C", or 
 *     "SIGINT". A function "sigint_handler" is implented such that the function 
 *     of "SIGINT" is ignored when used as an argument in the shell, but will 
 *     terminate foreground processes running in the shell without terminating 
 *     the shell itself.
 * 
 * Bug 5: Background processes are not reaped
 * Location: runcommand.c, lines 26 - 28.
 * Description: Using a while loop, this function continues to wait until all 
 *     background processes exit.
 *     
 */ 

int main()
{
    // BUG 4:
    // Using the signal function to catch and handle "CTRL+C", or "SIGINT". 
    // A function "sigint_handler" is implented such that the function of 
    // SIGINT is ignored when used as an argument in the shell, but will 
    // terminate foreground processes running in the shell without terminating 
    // the shell itself.
    signal(SIGINT, sigint_handler);

    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput(  ) != EOF ) {
        procline();
    }
    return 0;
}

//This function ignores the given signal then reinitializes itself.
void sigint_handler(int sig){	
	signal(sig,SIG_IGN);
	signal(SIGINT, sigint_handler);
}

