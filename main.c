#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
int clearscreen();
int timeout();
int main(int argc, char **argv)
{
	struct winsize sz;

	ioctl(0, TIOCGWINSZ, &sz);
	printf("Screen width: %i  Screen height: %i\n", sz.ws_col, sz.ws_row);
	clearscreen();
	printf("A\n");
	clearscreen();
	timeout();
	printf("B\n");
	timeout();
	clearscreen();
	printf("C\n");
	return 0;
}

int timeout()
{
	struct timespec tim,rem;
	tim.tv_nsec=500000000L;
	tim.tv_sec=0;
	nanosleep(&tim,&rem);
	return 0;	
}

int clearscreen()
{
	printf("\e[1;1H\e[2J");
	return 0;
}
