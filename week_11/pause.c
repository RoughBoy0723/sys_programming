#include <stdio.h>
#include <unistd.h>

int main(){
		alarm(1);
		pause();
		fprintf(stderr,"good\n");
}
