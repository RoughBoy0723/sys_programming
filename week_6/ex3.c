#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
		execl("/bin/date","wow",(char*)0);
		printf("Something Wrong\n");
}
