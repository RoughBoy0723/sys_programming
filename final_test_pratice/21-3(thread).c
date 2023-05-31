#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX 512

void *square(int x){
    sleep(1);
    printf("%d",x*x);
    exit(0);
}

int main(int argc, char *argv[]){
    pthread_t t_id;
    for(int i = 0 ; i < argc, i++){
        pthread_create(&t_id, NULL , square, argv[i+1]);
    }
}