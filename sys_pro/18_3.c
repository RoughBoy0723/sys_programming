#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
		int pid;

		if(pork() == 0){
				execl(argv[1],argv[1], (char *)0);
		}else{
				wait((int* )0);
				printf("parent exit");
				exit(0);
		}


}
