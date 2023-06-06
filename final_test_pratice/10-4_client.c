#include "pipe.h"

int main(int argc, char *argv[]){
		int n;
		char buf[512];

		int fd = open(exam,O_WRONLY,(char*)0);	
		int out_fd = open("output",O_WRONLY|O_CREAT|O_TRUNC,0666);

		write(fd,argv[1],sizeof(argv[1]));

		close(fd);

		fd = open(exam,O_RDONLY,(char*)0);
		
		while((n = read(fd,buf, sizeof(buf)))>0){
				printf("%s\n",buf);
				write(out_fd,buf,n);
		}
		close(fd);
		close(out_fd);
}
