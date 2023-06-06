#include "pipe.h"

int main(){
		int fd,s_fd, n;
		mknod(exam,S_IFIFO|0666,0);
		char buf[32];
		char t_line[512];
		while(1){
				s_fd =  open(exam,O_RDONLY,(char*)0);
				read(s_fd, buf,sizeof(buf));
				close(s_fd);
				printf("request = %s\n",buf);
				fd = open(buf, O_RDONLY,(char*)0);

				s_fd =  open(exam,O_WRONLY,(char*)0);

				while((n=read(fd,t_line,sizeof(t_line)))>0){
						printf("send : %s\n",t_line);
						write(s_fd,t_line,n);
				}
				close(fd);
				close(s_fd);
		}
		unlink(exam);
}
