#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd, len;
	char buf[512];
	if((fd = open("/dev/tty",O_RDONLY)) < 0 ){
		perror("open");
		exit(1);
	}
	sleep(10);
	if((len = read(fd,buf,512)) > 0) {
		buf[len-1] = 0 ;
		printf("[%d] : [%s]\n",len,buf);
	}
	else
		printf("NO Input\n");
}
