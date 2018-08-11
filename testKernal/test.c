//Jason Millette
//4/18/2018
//ECE331
//test program for kernal project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int test;
//    for (int i = 0; i < argc; i++) {
	    int fd;
	    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	    char *directory = "/dev/four_fsk";
	    fd = open(directory, O_WRONLY, mode);
	    printf("%d\n", fd);
        char * str = argv[1];
        int len = strlen(argv[1]);
        test = write(fd, str, len);
	    close(fd);
  //  }
    return 0;
}
