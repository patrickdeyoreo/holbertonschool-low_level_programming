#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}

	return (0);
}

/**
 * _close - close a file descriptor and print an error message upon failure
 * @fd: the file descriptor to close
 */
void _close(int fd)
{
	if (close(fd) != -1)
		return;
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(98);
}

/**
 * _read - read from a file and print an error message upon failure
 * @filename: the name of the file to read from
 * @fd: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 */
void _read(const char *filename, int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	_close(fd);
	exit(98);
}

/**
 * elf_magic - print elf magic
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_magic(const char *filename, int fd)
{
	char magic[16];
	unsigned int i;

	_read(filename, fd, magic, 16);

	if (_strncmp(magic, "\x7f\x45\x4c\x46", 4))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	printf("Magic:   ");
	for (i = 0; i < 16; ++i)
		printf("%02x%c", magic[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - print elf class
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_class(const char *filename, int fd)
{
	char class[8];

	_read(filename, fd, class, 8);
}

/**
 * elf_data - print elf data
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_data(const char *filename, int fd)
{
	char data[8];

	_read(filename, fd, data, 8);
}

/**
 * elf_version - print elf version
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_version(const char *filename, int fd)
{
	char version[8];

	_read(filename, fd, version, 8);
}

/**
 * elf_osabi - print elf osabi
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_osabi(const char *filename, int fd)
{
	char osabi[8];

	_read(filename, fd, osabi, 8);
}

/**
 * elf_abiversion - print elf abiversion
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_abiversion(const char *filename, int fd)
{
	char abiversion[8];

	_read(filename, fd, abiversion, 8);
}

/**
 * elf_type - print elf type
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_type(const char *filename, int fd)
{
	char type[8];

	_read(filename, fd, type, 8);
}

/**
 * elf_entrypoint - print elf entrypoint
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_entrypoint(const char *filename, int fd)
{
	char entrypoint[8];

	_read(filename, fd, entrypoint, 8);
}

/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
	void (*elf_header[])(const char *, int) = {
		elf_magic, elf_class, elf_data, elf_version, elf_osabi,
		elf_abiversion, elf_type, elf_entrypoint, NULL
	};
	int fd;
	unsigned int i;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	for (i = 0; elf_header[i]; ++i)
		elf_header[i](argv[1], fd);

	_close(fd);
	return (0);
}
