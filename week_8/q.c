#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
				int pid, st;
				if(fork() == 0){
								execl("./child","./child",(char*) 0);
								perror("fork error");
								exit(-1);
				}
				pid = wait(&st);
				printf("pid = [%d], status = [%x]\n",pid,st);
}
