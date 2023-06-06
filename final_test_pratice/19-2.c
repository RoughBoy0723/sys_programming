#include "pipe.h"

int main(){
		if(fork() == 0 ){
				execl("/bin/ls","/bin/ls","-l",(char*)0);
		}
		wait((int*)0);
		printf("OK\n");
}
