#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t_id[2];
int counter = 0 ;
void* dosomeThing(void *arg);

int main(void){
		int i = 0;
		
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
		counter += 1;
		printf("Job %d started\n",counter);
		
		for(i=0; i <(0xFFFFFFFF);i++)
				;
		printf("Job%d finished\n",counter);
		return NULL;
}
