#include "pipe.h"

int main(int argc, char *argv[]){
		int fd[2];
		pipe(fd);
		char path[16];
		strcpy(path,argv[2]);

		if(fork()==0){
				close(1);
				dup(fd[1]);
				close(fd[0]);
				close(fd[1]);
				execv(path,&argv[2]);
		}else{
				close(fd[1]);
				int n;
				int s_fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
				char buf[1024];
				while((n =read(fd[0],buf,1024))>0)
						write(s_fd,buf,n);
				close(fd[0]);
		}
}
