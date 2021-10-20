#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <assert.h>

#include <multiformat/multiaddr.h>

typedef void(*test_function)(void);

int
main(
	int argc,
	char **argv
) {
	const test_function tests[] = {
	};

	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
		tests[i]();

	exit(EXIT_SUCCESS);
}
