#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
		int fd;
		int i=4;

		fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC);

		write(fd, &i ,4);
		close(fd);
}
