#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<signal.h>
/*
 * Jason Millette
 * 3/8/2018
 * ECE331
 */

int main()
/*
 * creates child
 * then sleeps forever
 * then sends HUP
 * then quits
 */
{
	uint32_t pid;  //using uint to make it more widely supported
	pid = fork();
	if (pid < 0) {
		printf("pid < 0: error\n"); //checks for error
		return 1;
	}

	else if (pid == 0) {
	/*
	 * tells child to sleep
	 * indefinitely
	 */
		while(1) {
			sleep(1);
		}
	}
	
	else {
	/*
	 * sends HUP
	 * to child
	 * then returns
	 */
		kill(pid,SIGHUP);
		return 0;
	}
}
