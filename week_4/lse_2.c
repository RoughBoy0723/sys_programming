#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
		int fd;
		char buf[1];

		if((fd=open(argv[0],O_RDONLY))<0){
				printf("usage:a.out file-name\n");
				exit (-1);
		}
		
		lseek(fd, -2, SEEK_END);
		while(1){
				read(fd,buf,1);
				printf("%c", buf[0]);
				if(lseek(fd,-2,SEEK_CUR) == 0){
						read(fd,buf,1);
						printf("%c",buf[0]);
						break;
				}

		}
		printf("\n");
		return 0;
}
