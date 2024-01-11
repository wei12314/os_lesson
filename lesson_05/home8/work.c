#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int pi[2];
	char str[100];
	int f[2];
	int p = pipe(pi);
	if(p < 0){
		fprintf(stderr, "pipe failed");
		exit(1);
	}

	for(int i = 0; i < 2; i ++){
		f[i] = fork();
		if(f[i] < 0){
			fprintf(stderr, "fork failed");
			exit(1);
		} else if(f[i] == 0){
			switch(i){
				case 0:
					{
					char* s = strdup("0pro trans");
					dup2(pi[1],STDOUT_FILENO);
					puts(s);
					break;
					}
				case 1:
					{
					dup2(pi[0],STDIN_FILENO);
					gets(str);
					printf("2 is %s",str);
					return 2;
					}
			}
			break;
		}
	}
	waitpid(f[0],NULL,0);
	waitpid(f[1],NULL,0);
	return 0;
}
