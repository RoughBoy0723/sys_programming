#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
		int fd, i = 6;
		char buf[128];

		fd = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC,0664);

		sprintf(buf, "%d" ,i);
		write(fd, buf, strlen(buf));
		close(fd);
}
