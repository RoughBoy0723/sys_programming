#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int mySumAscii(char buf[]){
    int sum = 0;
    while(scanf("%c",buf)>0){
        sum += int(buf);
    }
    return sum;
}

int main(){
    printf("[%d]\n", mySumAscii("A"));
    printf("[%d]\n", mySumAscii("AB"));
    printf("[%d]\n", mySumAscii("ABC"));
}