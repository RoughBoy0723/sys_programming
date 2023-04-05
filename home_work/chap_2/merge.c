#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
		int fd1, fd2, fd3;
		char buf[1];
		if(((fd2 = open(argv[2],O_RDONLY)) < 0)||((fd3 = open(argv[3],O_RDONLY))<0)){
				printf("plz re input");
				exit(1);
		}
		
		fd1 = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0644);
		
		lseek(fd1,0,SEEK_SET);
		while(read(fd2, buf, 1)>0){
				write(fd1,buf,1);
				lseek(fd1, 1, SEEK_CUR);
		}
		
		lseek(fd1,1,SEEK_SET);
		while(read(fd3,buf,1)>0){
				write(fd1,buf,1);
				lseek(fd1,1,SEEK_CUR);
		}	
}
