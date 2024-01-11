#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x = 100;
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		x = x - 1;
		printf("child (pid:%d) x is %d\n",(int) getpid(),x);
	} else{
		x = x - 10;
		printf("parent (pid:%d) x is %d\n",(int) getpid(),x);
	}
	return 0;
}
