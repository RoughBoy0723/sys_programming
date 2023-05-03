#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
				int child1, child2, pid, status;

				if((child1 = fork())==0){
								execl("/bin/date","/bin/date",(char*)0);
				}
				if((child2 = fork())==0){
								execl("/bin/date","/bin/date","-x",(char*)0);
				}

				printf("\tparent: wating for children\n");
				while((pid = wait(&status)) != -1){
								if(pid == child1){
												printf("\tparent: first child: %d\n",(status>>8));
								}
								else if(pid == child2){
												printf("\tparent: second child: %d\n",(status >> 8));
								}
				}
				printf("\tparent: all children treminated\n");
				exit(0);
}
