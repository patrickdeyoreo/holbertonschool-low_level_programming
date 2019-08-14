#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 1
 */
int main(int argc, const char *argv[])
{
	int fd_in, fd_out;
	ssize_t bytes_read;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argv[1]);
		exit(98);
	}
	fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_out < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = read(fd_in, buffer, 1024)))
		write(fd_out, buffer, bytes_read);
	if (close(fd_in) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_in);
		if (close(fd_out) < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
					fd_out);
		exit(100);
	}
	if (close(fd_out) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_out);
		exit(100);
	}

	return (0);
}
