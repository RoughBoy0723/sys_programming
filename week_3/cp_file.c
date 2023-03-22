#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#define MAXLENGTH 256

int copyfile(char *, char *);

int main(int argc, char *argv[]){
		if(argc < 3){
				fprintf(stderr, "USage %s infile outfile\n", argv[0]);
				exit(-1);
		}

		copyfile(argv[1], argv[2]);
		exit(0);
		return -1;
}

int copyfile(char *source_file, char *target_file){
		int size = 0, fd1 = 0, fd2 = 0;
		int buf[MAXLENGTH];
		if ((fd1 = open(source_file, O_RDONLY)) < 0){
				perror(source_file);
				return -1;
		}

		if ((fd2 = open(target_file,O_WRONLY|O_CREAT|O_TRUNC,0666))< 0){
				perror(target_file);
				close(fd2);
				return -1;
		}
		memset(buf,0x00,sizeof(buf));

		while((size = read(fd1, buf, MAXLENGTH))>0){
				write(fd2,buf,size);
		}
		close(fd1);
		close(fd2);
		return 0;
}
