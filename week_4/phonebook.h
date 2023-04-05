#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

typedef struct{
		int index;
		char name[64];
		char number[20];
}PHONEBOOK;
