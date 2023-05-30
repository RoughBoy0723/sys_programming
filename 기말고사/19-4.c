#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void print(char *text){
    printf("%s",text);
    sleep(1);
    exit(1);
}

int main(){
    pthread_t t_id;
    int res;
    pthread_create(&t_id,NULL,print,"This is thread");
    pthread_join(&t_id, (int**)res);
    if(res == 1){
        printf("OK");
        exit(0);
    }
}