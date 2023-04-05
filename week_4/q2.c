#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
		int fd;
		int i;

		fd = open("tmp.txt", O_RDONLY);
		read(fd,&i,4);
		printf("i = [%d]\n",i);
		close(fd);
}
