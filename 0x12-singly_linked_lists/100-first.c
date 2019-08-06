#include <stdio.h>

void init(void) __attribute__((constructor));

/**
 * init - execute before main
 */
void init(void)
{
	printf("%s\n%s\n",
	"You're beat! and yet, you must allow,",
	"I bore my house upon my back!"
	);
}
