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
		pipe(fd);
		if(fork() == 0){
				close(fd[1]);
				read(fd[0], &buf, strlen(argv[1]));
				write(1, &buf,strlen(argv[1]));
				write(1,"\n",1);
		}else{
				close(fd[0]);
				write(fd[1],argv[1],strlen(argv[1]));
				close(fd[1]);
		}
}
