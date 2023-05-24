#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define LBUF 1024

char* path[4] = {"","/bin/","/usr/bin/","/usr/local/bin/"};

char* set_path(char *str);
void log_write(char *str_read, int fd, time_t timer);
void sigint_handler(int sig);
