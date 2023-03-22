#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd;
    unlink("abc");
	fd = open("abc", O_RDWR|O_CREAT|O_EXCL, 0666);
	close(fd);
}
