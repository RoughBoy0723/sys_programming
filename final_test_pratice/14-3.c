#include "pipe.h"

int main(int argc, char *argv[]){
		int fd,pd[2],n;
		pipe(pd);
		char buf[512];
		fd = open(argv[1],O_RDONLY,(char*)0);
		if(fork()==0){
				close(0);
				dup(pd[0]);
				close(pd[0]);
				close(pd[1]);
				while((n=read(0,buf,sizeof(buf)))>0)
						write(1,buf,n);

		}else{		
				close(1);
				dup(pd[1]);
				close(pd[0]);
				close(pd[1]);
				while((n=read(fd,buf,sizeof(buf))) > 0){
						write(1,buf,n);
				}
		}
		exit(0);
}
