#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
#include <math.h>

void *square(void* arg){
		sleep(1);
		int x = atoi((char*)arg);
		x *= x;
		printf("%d\n",x);
		pthread_exit(0);
}

int main(int argc, char *argv[]){
		pthread_t t_id[argc-1];
		
		for(int i = 1 ; i < argc ; i++){
				pthread_create(&t_id[i-1],NULL,square,argv[i]);
		}

		for(int j = 0; j < argc-1 ; j++){
				pthread_join(t_id[j],NULL);
		}
		exit(0);
}
