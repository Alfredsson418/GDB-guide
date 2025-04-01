#include <stdio.h>

struct foo {
	int	  bar;
	char *vaar;
};

int print_me() {
	int x = 10;
	printf("Hello there! %d\n", x);
	x = 15;
	return x;
}

int main() {
	struct foo ex;
	ex.bar	= 10;
	ex.vaar = "Hello World!";

	for (; ex.bar < 13; ex.bar++) {
		printf("%d\n", ex.bar);
	}

	return 0;
}
