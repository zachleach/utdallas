#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){
	
	printf("Hello before fork...my pid is %d \n", getpid());
    int rc = fork();
	if (rc == 0){ // code for child only
		printf("I am CHILD...my pid is %d \n", getpid());
	} 
	else { // code for parent only
		wait();
		printf("I am PARENT...my pid is %d and my child's pid is %d\n", getpid(), rc);
		
	}
	// executed by both child and parent
	printf("BYE...my pid is %d \n", getpid());
}

