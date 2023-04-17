#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    int fd1, fd2;
    char buf[1];
    if((fd1 = open(argv[1],O_WRONLY|O_CREAT|O_EXCL))<0){
        printf("%s 파일이름:exist\n",argv[1]);
        exit(0);
    }
    fd2=open(argv[2],O_RDONLY);

    while(read(fd2,buf,1) > 0){
        write(fd1,buf,1);
    }
}
