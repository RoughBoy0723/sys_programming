#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_SIZE 50

int main(int argc, char* argv[]){
		int fd[2], pid = 0, size = 0 , status = 0;
		
		char buf[MAX_SIZE];
		memset(buf, 0x00, MAX_SIZE);
		if(pipe(fd)== -1){
				perror("pipe() :");
				exit(1);
		}
		if(fork() == 0){
				close(0);
				dup(fd[0]);
				close(fd[0]);
				close(fd[1]);
				size = read(0,buf,MAX_SIZE);
				execlp(buf,buf,(char *)NULL);
				perror("execlp() :");
				exit(1);
		}

		if(fork() == 0){
				close(1);
				dup(fd[1]);
				close(fd[0]);
				close(fd[1]);
				printf("%s",argv[1]);
				fflush(stdout);
				exit(0);
		}
		close(fd[0]);
		close(fd[1]);
		while(wait(&status) != -1)
				;
		exit(0);
}
