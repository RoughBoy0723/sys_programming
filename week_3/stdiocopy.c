#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLENGTH 128

int main() {
    char buf[MAXLENGTH];
	int size = 0;

	while((size = read(0, buf, MAXLENGTH))>0){
		write(1,buf,size);
	}
}
