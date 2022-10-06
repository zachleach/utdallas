#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void err_exit(char *msg);

int
main(int argc, char *argv[])
{
    int fd[2];
    pid_t cpid1, cpid2;

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
     exit(EXIT_FAILURE);
    }

    if (pipe(fd) == -1) 
        err_exit("pipe");
	cpid1 = fork();
	if (cpid1 < 0)
		err_exit("fork 1 failed");
	}

	if (cpid1 == 0) { /* child -- cat */
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]); /* write end is not required */
		char *myargs[] = {"cat", argv[1], 0}
		execvp(myargs[0], myargs);
		err_exit("exec cat failed");
	}

	cpid2 = fork();
	if (cpid2 < 0) {
		err_exit("fork 2 failed");
	}
	if (cpid2 == 0){
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		char *myargs[] = {"wc", 0}
		execvp(myargs[0], myargs);
		err_exit("exec wc failed");

	}
	close(fd[1]);
	close(fd[0]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}

void
err_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

