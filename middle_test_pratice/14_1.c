#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct{
				char name[20];
				int age;
} A;

int main(int argc, char *argv[]){
				int fd1;
				A a;
				
				fd1 = open(argv[1], O_APPEND|O_CREAT|O_WRONLY,0600);
				while(1){
								memset(&a, 0x00, sizeof(a));
								fprintf(stderr,"insert name : ");
								fflush(stderr);
								read(0, &a.name, sizeof(a.name));

								if(a.name[0] == '.')
												exit(0);
								sleep(1);
								fprintf(stderr,"insert age : ");
								fflush(stderr);
								read(0, &a.age, sizeof(a.age));
								
								write(fd1, &a, sizeof(a));
				}
				close(fd1);
}
