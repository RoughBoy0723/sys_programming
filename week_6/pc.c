#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
		if(fork() == 0){
				sleep(1);
				printf("child.pid = [%d], ppid =  [%d]\n",getpid(),getppid());
		}else
				printf("parent.pid = [%d], ppid = [%d]\n",getpid(),getppid());

		printf("both\n");
}
