#include <unistd.h>

int main(){
		int size = 0;
		char temp[512];

		while(1){
				size = read(0, temp, 512);
				write(1,temp,size);
		}
}
