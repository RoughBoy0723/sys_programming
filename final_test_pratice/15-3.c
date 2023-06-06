#include "pipe.h"

int main(int argc, char *argv[]){
		int fd[2], c_fd,n;
		pipe(fd);
		if(fork()==0){
				close(1);
				dup(fd[1]);
				close(fd[0]);
				close(fd[1]);
				execl("/bin/cat","/bin/cat",argv[1],(char*)0);
		}else{
				char buf[32];
				close(fd[1]);
				while((n=read(fd[0],buf,32))>0)
						write(1,buf,n);
				exit(1);
		}
}
