#include <stdio.h>
/*
 *Jason Millette
 *9/11/2018
 *adder program
 *ECE331
 */

int main(int argc, char *argv[]) 
{
/*
 *Adds all numbers
 *in a string then
 *prints result to
 *terminal
 */
int i = 0, j = 0, nums = 1, sum = 0, length = 0, totalCharacters = 1;
if (argv[1][0] == '+' && argv[1][1] == '+') {
	printf("you cant start with two + signs\n");
	return 0;
}

while (argv[1][++i] != '\0') {                                         	//checks for errors and breaks up the string

	if (((argv[1][i] < '0' || argv[1][i] > '9') && (argv[1][i] != '+') )) {
		printf("you entered an invalid character\n");
		return 0;
	} 

	else if ((argv[1][i] == '+') && (argv[1][i+1] == '+') && (argv[1][i+2] == '+')) {
		printf("you have entered 3 or more + sings in a row\n");
		return 0;
	}

	else if (argv[1][i+1] == '\0' && argv[1][i] == '+') {
		printf("you can not end with a + sign\n");
		return 0;
		}

	else if ((argv[1][i] == '+') && (argv[1][i-1] != '+')) nums++;
	
	if (argv[1][i] == '+') 
		argv[1][i] = '\0';
	
	totalCharacters++;
}

for (i = 0; i < totalCharacters; i++) {      //adds all the parsed strings
	j = 0;
	if (argv[1][i] != '\0') {

		while (argv[1][i+j] !='\0') {
			length++;
			j++;
		}

		char number[length+2];
		for (int m = 0; m < length; m++) {
			number[m] = argv[1][i+m];
		}

		number[length] = '\0';
		sum += atoi(number);
		length = 0;
		i += j;
	}
}

if (sum < 0) {
	printf("overflow error\n");
	return 0;
}

printf("sum = %d\n",sum);
return 0;
}
