#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int fd1, cnt;
    fd1 = open(argv[1], O_RDWR);

    lseek(fd1, atoi(argv[2]), SEEK_SET);
	for(int i = 0 ; i < atoi(argv[3]) ; i++){
		write(fd1, argv[4], 1);
	}
	close(fd1);
}
//1. 반복문 돌리면서 즉각 바꿔주기   바꿔주는 함수 가 무엇인지
//2. 파일을 받아와서 부분만 바꿔주기  바꿔주기만하면됨
