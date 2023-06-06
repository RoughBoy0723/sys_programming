#include "pipe.h"

int main(){
		int stat;
		if(fork() == 0){
				execl("/bin/ps","/bin/ps","-axl",(char*)0);
		}
		wait(&stat);
		printf("%d\n",stat);
}
