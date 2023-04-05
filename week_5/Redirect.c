#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	close(1);
	if(open(argv[1],O_WRONLY|O_CREAT|O_TRUNC, 0644) <0 ){
		perror(argv[1]);
		exit(1);
	}
	close(2);
	if(dup(1)<0){
		perror(argv[0]);
		exit(2);
	}
	printf("1:stdout----\n");
	fprintf(stderr,"2:stderr----\n");
	printf("3:stdout----\n");
        fprintf(stderr,"4:stderr----\n");
}
