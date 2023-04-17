#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int myStrlen(char *word){
    char buf;
    int cnt = 0;
	for(int i = 0 ;word[i]; i++){
        cnt++;
    }
    return cnt;
}

int main(){
    printf("[%d]\n",myStrlen("This"));
    printf("[%d]\n",myStrlen("This is"));
    printf("[%d]\n",myStrlen("This is test."));
}
