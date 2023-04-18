#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd1, cnt, n;
    char buf[256];

  	fd1 = open(argv[1], O_RDONLY);
    
		read(fd1, buf, sizeof(buf));

    char *ptr = strtok(buf, " ");

		while(ptr != NULL){
				if(strcmp(ptr, argv[2])==0){
				    printf("Found\n");
				    exit(0);
				}
				ptr = strtok(NULL," ,\n");
		}

    printf("NOT Found\n");
}
