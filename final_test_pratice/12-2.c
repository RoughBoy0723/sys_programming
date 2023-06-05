#include "pipe.h"

int main(int argc, char *argv[]){
		int stat;
		if(fork() == 0)
				execv(*(argv+1),&argv[1]);
		wait(&stat);
		printf("Parent : child exit code = %d\n",stat);
}
