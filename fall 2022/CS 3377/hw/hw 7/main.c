/*
        Written by Zach Leach for CS 3377 - Assignment 7
        NetID: zcl190002
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*

        MAIN
        
        create a pipe for cat and cat 
        create a pipe for cat and wc 
        
        
        
        PROCESS 1 (CAT --> CAT)
        
        create a child process to execute cat
        make the child process's stdout descriptor point to pipe1-write
        execute cat
        cat writes to stdout (pipe1-write)
        
        
        
        PROCESS 2 (CAT --> WC)
        
        create a child process to execute cat
        make the child process's stdin descriptor point to pipe1-read
        make the child process's stdout descriptor point to pipe2-write
        execute cat
        cat reads from stdin (pipe1-read)
        cat writes to stdout (pipe2-write)
        
        
        
        PROCESS 3 (WC --> STDOUT)
        
        create a child process to execute wc
        make the child process's stdin descriptor point to the shared file (in)
        execute cat
        cat reads from stdin (pipe2-read)
        cat writes to stdout 
        
        
        
        PARENT
        
        wait for child 1 - 3
        
*/
/*

        SIDE NOTES
        
        read calls to a pipe will wait for a write or for write to be be closed
        unclosed pipe-write file descriptors can "hang" the program
        
*/


int main(int argc, char* args[]) {
        pid_t cpid1, cpid2, cpid3;
        
        // make pipes
        int pipe1[2];
        int pipe2[2];
        pipe(pipe1);
        pipe(pipe2);
        
        
        // CHILD 1
        cpid1 = fork();
        if (cpid1 == 0) {
                // stdout = clone write-pipe1
                dup2(pipe1[1], 1);
                
                // close pipe descriptors
                close(pipe1[0]);
                close(pipe1[1]);
                close(pipe2[0]);
                close(pipe2[1]);
                
                // file --> cat --> write-pipe1
                char *execvp_args[] = { "cat", args[0], NULL };
                execvp(execvp_args[0], execvp_args);
        }
        
        
        // CHILD 2
        cpid2 = fork();
        if (cpid2 == 0) {
                // stdin = clone read-pipe1
                // stdout = clone write-pipe2
                dup2(pipe1[0], 0);
                dup2(pipe2[1], 1);
                
                // close pipe file descriptors
                close(pipe1[0]);
                close(pipe1[1]);
                close(pipe2[0]);
                close(pipe2[1]);
                
                // read-pipe1 --> cat --> write-pipe2
                char *execvp_args[] = { "cat", NULL };
                execvp(execvp_args[0], execvp_args);
        }
        
        
        // CHILD 3
        cpid3 = fork();
        if (cpid3 == 0) {
                // stdin = clone read-pipe2
                dup2(pipe2[0], 0);
                
                // close pipe file descriptors
                close(pipe1[0]);
                close(pipe1[1]);
                close(pipe2[0]);
                close(pipe2[1]);
                
                // read-pipe2 --> wc --> stdout
                char *execvp_args[] = { "wc", NULL };
                execvp(execvp_args[0], execvp_args);
        }
        
        
        // PARENT
        // close pipe file descriptors and wait
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        waitpid(cpid1, NULL, 0);
        waitpid(cpid2, NULL, 0);
        waitpid(cpid3, NULL, 0);
}


/*
int main() {
        pid_t cpid1, cpid2;
        
        // make pipe
        int fd[2];
        pipe(fd);
        
        // child 1 
        // file --> cat --> pipe-read
        cpid1 = fork();
        if (cpid1 == 0) {
                // close pipe-read
                //close(fd[0]);
                
                // stdout = pipe-write
                dup2(fd[1], STDOUT_FILENO);
                //close(fd[1]);
                
                // cat writes to stdout file entry (write-end of pipe)
                char *execvp_args[] = { "cat", "file.txt", NULL };
                execvp(execvp_args[0], execvp_args);
        }
        
        
        // child 2
        // pipe-read --> wc --> stdout
        cpid2 = fork();
        if (cpid2 == 0) {
                // close pipe-write
                close(fd[1]);
                
                // stdin = pipe-read
                dup2(fd[0], STDIN_FILENO);
                //close(fd[0]);
                
                // wc reads from stdin file entry (read-end of pipe), then writes to stdout
                char *execvp_args[] = { "wc", NULL };
                execvp(execvp_args[0], execvp_args);
        }
        
        
        // parent
        //close(fd[0]);
        close(fd[1]);
        waitpid(cpid1, NULL, 0);
        waitpid(cpid2, NULL, 0);
}
*/





























