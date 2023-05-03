#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]){
				int stat;
				if(fork() == 0){
								execl("/bin/cat","/bin/cat",argv[1], (int*)0);
								exit(1);
				}else{
								wait(&stat);
								printf("Parent : Child exit status =  [%x]\n", stat>>8);
				}
}
