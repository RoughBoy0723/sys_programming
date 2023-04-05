#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
		int fd1, fd2;
		char buf[1];
		if((fd1 = open(argv[1],O_RDONLY)) < 0){
				printf("plz re select th FILE");
				exit(1);
		}
		fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
		

		lseek(fd1, -2, SEEK_END);

		while(1){
				read(fd1, buf, 1);
				write(fd2, buf, 1);
				if(lseek(fd1,-2,SEEK_CUR) == 0){
						read(fd1,buf,1);
						write(fd2,buf,1);
						break;
				}
		}
		

}
