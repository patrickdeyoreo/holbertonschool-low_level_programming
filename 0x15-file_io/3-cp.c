#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * _close - close a file descriptor and print an error if it fails
 * @fd: the file descriptor to close
 *
 * Return: 0 upon success, -1 upon failure
 */
int _close(int fd)
{
	if (!close(fd))
		return (0);

	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	return (-1);
}

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
	char buffer[BUFSIZE];

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
		_close(fd_in);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = read(fd_in, buffer, BUFSIZE)))
		write(fd_out, buffer, bytes_read);

	if (_close(fd_in) < 0)
	{
		close(fd_out);
		exit(100);
	}
	if (_close(fd_out) < 0)
		exit(100);

	return (0);
}
