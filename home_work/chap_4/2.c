#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
		char ch;
		
		close(0);
		open(argv[1],O_RDONLY);
		close(1);
		open(argv[2], O_WRONLY|O_CREAT|O_EXCL);

		while(scanf("%c",&ch) > 0) {
				printf("%c",ch);
		}
}
