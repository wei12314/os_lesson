#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		close(STDOUT_FILENO);
		printf("child (pid:%d)\n",(int) getpid());
	} else{
		printf("parent (pid:%d)\n",(int) getpid());
	}
	return 0;
}
