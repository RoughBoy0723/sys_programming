#include <stdio.h>
#include <stlib.h>
#include <signal.h>

void func(){
    printf("timeout\n");
    exit(1);
}

int main(int argc, char *argv[]){
    signal(SIGALRM,func);
    int cnt = atoi(argv[1]);
    alarm(cnt);
}
