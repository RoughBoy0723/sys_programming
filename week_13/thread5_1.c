#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t_id[2];
int counter = 0 ;
pthread_mutex_t lock;

void* dosomeThing(void *arg);

int main(void){
		int i = 0;

		if(pthread_mutex_init(&lock,NULL) != 0){
				printf("\nmutex init failed\n");
				return 1;
		}
		
		while(i<2){
				if(pthread_create(&(t_id[i]),NULL,dosomeThing,NULL))
						printf("can't create thread\n");
				i++;
		}
		pthread_join(t_id[0],NULL);
		pthread_join(t_id[1],NULL);

		return 0;
}

void *dosomeThing(void *arg){
		unsigned long i = 0;
		pthread_mutex_lock(&lock);
		counter += 1;
		printf("Job %d started\n",counter);
		
		for(i=0; i <(0xFFFFFFFF);i++)
				;
		printf("Job%d finished\n",counter);
		pthread_mutex_unlock(&lock);
		return NULL;
}
