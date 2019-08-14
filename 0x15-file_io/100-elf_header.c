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
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * _read - read from a file and print an error message upon failure
 * @filename: the name of the file to read from
 * @fd: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 */
void _read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_close(fd);
	exit(98);
}

/**
 * elf_magic - print elf magic
 * @filename: the name of the file
 * @fd: file descriptor to read from
 */
void elf_magic(const char *buffer)
{
	unsigned int i;

	if (_strncmp(buffer, "\x7f\x45\x4c\x46", 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("Magic:   ");
	for (i = 0; i < 16; ++i)
		printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - print elf class
 * @buffer: the name of the file
 */
int elf_class(const char *buffer)
{
	int bit_mode;

	if (buffer[4] == 1)
		bit_mode = 32;
	else
		bit_mode = 64;

	printf("%-35s ELF%d\n", "Class:", bit_mode);
	return (bit_mode);
}

/**
 * elf_data - print elf data
 * @buffer: the name of the file
 */
void elf_data(const char *buffer)
{
	if (buffer[5] == 1)
		printf("%-35s 2's complement, little endian\n", "Data:");
	else
		printf("%-35s 2's complement, big endian\n", "Data:");
}

/**
 * elf_version - print elf version
 * @buffer: the name of the file
 */
void elf_version(const char *buffer __attribute__((unused)))
{
	printf("%-35s 1 (current)\n", "Version:");
}

/**
 * elf_osabi - print elf osabi
 * @buffer: the name of the file
 */
void elf_osabi(const char *buffer)
{
	char *os_table[] = {
		"UNIX - System V",
		"HP-UX",
		"NetBSD",
		"Linux",
		"GNU Hurd",
		"Solaris",
		"AIX",
		"IRIX",
		"FreeBSD",
		"Tru64",
		"Novell Modesto",
		"OpenBSD",
		"OpenVMS",
		"NonStop Kernel",
		"AROS",
		"Fenix OS",
		"CloudABI"
	};

	printf("%-35s %s\n", "OS/ABI:", os_table[(int) buffer[7]]);
}

/**
 * elf_abiversion - print elf abiversion
 * @buffer: the name of the file
 */
void elf_abiversion(const char *buffer)
{
	printf("%-35s %d\n", "ABI Version:", buffer[8]);
}

/**
 * elf_type - print elf type
 * @buffer: the name of the file
 */
void elf_type(const char *buffer)
{
	char *type_table[] = {
		"NONE",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	printf("%-35s %s\n", "Type:", type_table[(int) buffer[16]]);
}

/**
 * elf_type - print elf type
 * @buffer: the name of the file
 */
void elf_entrypoint(int address_size, const char *buffer)
{
	printf("%-35s 0x", "Entry point address:");

	buffer += address_size - 1;

	while (!*(buffer) && address_size > 0)
		--buffer, --address_size;

	printf("%x", *buffer);

	while (--address_size > 0)
		printf("%02x", *(--buffer));

	printf("\n");
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
	char buffer[18];
	unsigned int i;
	int bit_mode, fd;
	void (*elf_header[])(const char *) = {
		elf_data, elf_version, elf_osabi, elf_abiversion,
		elf_type, NULL
	};

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	_read(fd, buffer, 18);

	elf_magic(buffer);

	bit_mode = elf_class(buffer);

	for (i = 0; elf_header[i]; ++i)
		elf_header[i](buffer);

	lseek(fd, 24, SEEK_SET);

	_read(fd, buffer, bit_mode / 8);
	_close(fd);

	elf_entrypoint(bit_mode / 8, buffer);

	return (0);
}
