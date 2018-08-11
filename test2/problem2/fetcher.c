#include<stdio.h>

int main (int argc, char *argv[])
{
	if (argc != 3) {
		printf("Enter the hostname and port\n");
		return 1;
	}

    return 0;
}
