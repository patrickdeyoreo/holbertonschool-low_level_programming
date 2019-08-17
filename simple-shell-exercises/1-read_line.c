#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_read;

	write(STDERR_FILENO, "$ ", 2);

	n_read = getline(&line, &len, stdin);

	if (n_read > 0)
		write(STDOUT_FILENO, line, n_read);
	else
		write(STDOUT_FILENO, "\n", 1);

	free(line);

	if (n_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
