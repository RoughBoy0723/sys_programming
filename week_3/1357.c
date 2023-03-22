#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
		int fd;
		char buf[1];

		if((fd = open(argv[1], O_RDONLY))<0){
				printf("usage : a.out file-name\n");
				exit(-1);
		}
		
		while(read(fd, buf , 1) > 0 ){
				printf("%c",buf[0]);
				lseek(fd, 1, SEEK_CUR);
		}
		printf("\n");
}
