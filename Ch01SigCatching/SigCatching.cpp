/*
 * 1.10ReadCommandsFromStandardInputAndExecuteThem.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */

#include "../lib/apuesunyj.h"
#include <sys/wait.h>

static void sig_int(int); // our signal-catching function,static limit this function in this file

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    if (signal(SIGINT, sig_int) == SIG_ERR) // catch the ctrl + c signal
    {
        err_sys("signal error");
    }

    printf("%% "); /* print prompt (printf requires %% to print %) */
    // ctrl + c invoke function sig_int, ctrl + d end this loop
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        }
        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {   /* child */
            execlp(buf, buf, (char *) 0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    printf("EOF(ctrl + d) received\n");
    printf("bye bye\n");
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt by signal ctrl + c \n%% ");
}
