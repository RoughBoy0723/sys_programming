#include "pipe.h"


char *argv[4] = {"one","two","three","four"};
int main(){
		int stat;
		for(int i = 0; i < 4; i++){
				if(fork()==0)
						execl("/bin/echo","/bin/echo",*(argv+i),(char*)0);
		}
		while(wait(&stat)>0)
				printf("%x\n",stat);
		exit(1);
}
