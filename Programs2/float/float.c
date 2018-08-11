#include <stdio.h>
#include <regex.h>
/*
 * Jason Millette
 * 2/18/2018
 * float match
 * ECE331
 */

int main(int argc, char *argv[]) 
/*
 * increments through
 * all arguments and
 * tests for matches
 * then prints results
 */
{
	int match;
	char *regularExpression = "^((\\s*[+-]?))([0-9]+\\.?[0-9]*$|[0-9]*\\.[0-9]+$)";
	regex_t re;
	if (argc < 2) {     //checks for arguments
		printf("You must enter a test\n");
		return 1;
	}

	for (int i = 1; i < argc; i++) {     //checks for errors
		if (regcomp(&re, regularExpression, REG_EXTENDED) != 0) {
			printf("error occured\n");
			return 2;
		}

		match = regexec(&re, argv[i],  0, NULL, 0);
		regfree(&re);  //frees memory
		if (!match) 
			printf("%s -> pass\n",argv[i]);
		else
			printf("%s fail\n",argv[i]);
	}

	return 0;
}
