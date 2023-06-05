#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){
		int stat,pid;
		if((pid=fork())==0){
				execl("/bin/date","/bin/date","-u",(char*)0);
		}
		wait(&stat);
		printf("child pid : %d\n",pid);
		printf("exit value : %d\n",stat);
}
