/*
 * Jason Millette
 * 2/11/2018
 * number of bytes
 * ECE331
 */
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc, char *argv[])
/*
 * Increments through
 * all arguments and
 * adds their file
 * size to the total
 */
{
	struct stat buf;
	int total = 0;

	if (argc < 2) {                      //checks for input file                    
		printf("enter a file(s)\n");
		return 0;
	}       

	for (int i = 1; i < argc; i++) {                 
		if (stat(argv[i],&buf) < 0) {
			printf("%s\n", strerror(errno));  //checks and prints error
			return 0;
		}

		total += buf.st_size;
	}

	printf("%d\n",total);
	return 0;
}
