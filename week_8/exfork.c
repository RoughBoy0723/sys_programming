#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
				if(fork() == 0){
								execl("/bin/echo","/bin/echo","this","is","message 1",(char*)NULL);
								perror("exec one failed");
								exit(0);
				}
				if(fork() == 0){
								execl("/bin/echo","/bin/echo","this","is","message 2", (char*)NULL);
								perror("exec two failed");
								exit(1);
				}
				if(fork() == 0 ){
								execl("/bin/echo","/bin/echo","this","is","message 3", (char*)NULL);
								perror("exec three failed");
								exit(2);
				}
				printf("parent program finished");
}
