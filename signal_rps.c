#include <signal.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned cnt = 0;


void sfh() {
	cnt += 1;
	return;
}

void alarmh() {
	printf("%u\n", cnt);
	exit(0);
}


int main() {
	struct sigaction sh;
	memset(&sh, 0, sizeof(sh));
	sh.sa_handler = sfh;
	sigaction(SIGSEGV, &sh, NULL);
	char *ptr = NULL;
	sh.sa_handler = alarmh;
	sigaction(SIGALRM, &sh, NULL);
	alarm(1);
	*ptr = 5;
	return 0;
}
