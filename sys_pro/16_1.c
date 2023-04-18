#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1, cnt;
    char buf[1024];
		char *ptr[1024];

    fd1 = open(argv[1], O_RDONLY);

    cnt = 0;
    read(fd1, buf, sizeof(buf));
		ptr = strtok(buf, " ,\0");
		while(&ptr != NULL){
				cnt++;
				ptr++;
    }
    
    printf("%d",cnt);
    exit(0);
    close(fd1);
}
