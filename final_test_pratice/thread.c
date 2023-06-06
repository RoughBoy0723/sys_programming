#include "pipe.h"

void *func(void *argv){
		sleep(1);
		int x = atoi((char*) argv);
		printf("%d\n",x*x);
		pthread_exit(0);
}

int main(int argc, char *argv[]){
		pthread_t t_id[argc-1];
		
		for(int i = 0 ; i < argc-1 ; i++)
				pthread_create(&t_id[i],NULL,func,argv[i+1]);


		for(int j = 0 ; j <argc-1 ; j++)
				pthread_join(t_id[j],NULL);
		exit(1);
}
