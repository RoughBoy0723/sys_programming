#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]){
				int stat;
				if(fork() == 0){
								execv(argv[1],argv+1);
								exit(1);
				}else{
								wait(&stat);
								printf("Parent : Child exit status =  [%x]\n", stat>>8);
				}
}
