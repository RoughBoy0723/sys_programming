#include "phonebook.h"

int main(int argc, char *argv[]){
		int fd, size;
		PHONEBOOK phonebook;


		if(argc < 2){
				fprintf(stderr, "Usage : %s filename\n",argv[0]);
				exit(-1);
		}

		if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664))<0){
				perror(argv[1]);
				exit(-2);
		}

		while(1){
				memset(&phonebook, 0x00, sizeof(PHONEBOOK));
				
				fprintf(stdee, "Insert Index : ");
				fflush(stderr);
				if((size = read(0, phonbook.index, sizeof(phonebook.index)))<0)
						break;
				phonebook.index[size] = 0;


				fprintf(stderr, "Insert Name : ");
				fflush(stderr);
				if((size = read(0,phonebook.name, sizeof(phonebook.name))) < 0)
						break;
				phonebook.name[size] = 0;
				if((phonebook.name[0] == ' ')||(phonebook.name[0] =='.'))
						break;
				
				fprintf(stderr,"Insert Customer Phone Number : ");
				fflush(stderr);
				if((size = read(0, phonebook.phonenumber, sizeof(phonebook.phonenumber)))<0)
						break;
				phonebook.phonenumber[size] = 0;

				write(&phonebook,sizeof(PHONEBOOK));

		}

		close(fd);
		exit(0);
}
