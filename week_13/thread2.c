#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *thread(void *arg){
		char *ret;
		printf("thread() entered with argument '%s'\n",(char *)arg);
		if((ret=(char*)malloc(20))== NULL){
				printf("malloc() error");
				exit(2);
		}
		strcpy(ret,"This is a test");
		pthread_exit(ret);
}

int main(){
		pthread_t t_id;
		void *rt;

		if(pthread_create(&t_id,NULL,thread,"thread 1") != 0){
				perror("pthread_create() error");
				exit(1);
		}
		if(pthread_join(t_id,&rt) != 0 ){
				perror("pthread_join() error");
				exit(1);
		}
		printf("thread exited with '%s'\n", (char*)rt);
		free(rt);
}
