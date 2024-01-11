#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	//char buf[128] = {0};
	int in = open("test.txt",O_WRONLY|O_APPEND);
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		char * s = "child\n";
   		write(in,s,strlen(s));
		printf("child (pid:%d)\n",(int) getpid());
		close(in);
	} else{
		char * s = "parent\n";
   		write(in,s,strlen(s));
		printf("parent (pid:%d)\n",(int) getpid());
		close(in);
	}
	return 0;
}
