#include "pipe.h"

int main(int argc, char *argv[]){
		int fd[2];
		char buf[512];
		pipe(fd);
		if(access(argv[1],F_OK) == 0){
				if(fork() == 0){
						close(1);
						dup(fd[1]);
						close(fd[0]);
						close(fd[1]);
						execl("/bin/cat","/bin/cat",argv[1],(char*)0);		
				}else{
						close(0);
						dup(fd[0]);
						close(fd[0]);
						close(fd[1]);
						execl("/bin/cat","/bin/cat",(char*)0);
				}
		}else{
				int n;
				char file[32];
				read(0,file,sizeof(file));
				strtok(file,"\n");
				int s_fd = open(file,O_RDONLY,(char*)0);
				while((n=read(s_fd,buf,sizeof(buf)))>0)
						write(1,buf,n);
				close(s_fd);
		}
}
