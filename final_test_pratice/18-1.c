#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
		int fd[2];
		char buf[512];
		pipe(fd);
		if(fork()==0){
				close(1);
				dup(fd[1]);
				close(fd[0]);
				close(fd[1]);
				execl("/bin/ps","/bin/ps","-e",(char*)0);
		}
		if(fork()==0){
				close(0);
				dup(fd[0]);
				close(fd[0]);
				close(fd[1]);
				execl("/bin/grep","/bin/grep","child",(char*)0);
		}
		close(fd[0]);
		close(fd[1]);

		while(wait((int*)0) != -1)
				;
		exit(0);
}
