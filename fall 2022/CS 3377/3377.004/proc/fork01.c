#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int x  = getpid();
	fork();
	// sleep(100);
	// if x == getpid() then parent else child
	printf("who am I? x: %d  \n", x);

}

