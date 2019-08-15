#include <elf.h>
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
 * @buffer: the ELF header
 */
void elf_magic(const char *buffer)
{
	unsigned int i;

	if (_strncmp(buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < 16; ++i)
		printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - print elf class
 * @buffer: the ELF header
 *
 * Return: the bit mode of the executable (32 or 64)
 */
int elf_class(const char *buffer)
{
	int bit_mode = 0;

	if (buffer[EI_CLASS] == ELFCLASS32)
		bit_mode = 32;
	else if (buffer[EI_CLASS] == ELFCLASS64)
		bit_mode = 64;

	printf("  %-34s ELF%d\n", "Class:", bit_mode);

	return (bit_mode);
}

/**
 * elf_data - print elf data
 * @buffer: the ELF header
 */
void elf_data(const char *buffer)
{
	printf("  %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (buffer[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %d>\n", buffer[EI_DATA]);
}

/**
 * elf_version - print elf version
 * @buffer: the ELF header
 */
void elf_version(const char *buffer)
{
	printf("  %-34s %d", "Version:", buffer[EI_VERSION]);

	if (EV_CURRENT == buffer[EI_VERSION])
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - print elf osabi
 * @buffer: the ELF header
 */
void elf_osabi(const char *buffer)
{
	const char *os_table[18] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 18)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %d>\n", buffer[EI_OSABI]);
}

/**
 * elf_abiversion - print elf abiversion
 * @buffer: the ELF header
 */
void elf_abiversion(const char *buffer)
{
	printf("  %-34s %d\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - print elf type
 * @buffer: the ELF header
 */
void elf_type(const char *buffer)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	printf("  %-34s ", "Type:");

	if (buffer[16] < 5)
		printf("%s\n", type_table[(unsigned int) buffer[16]]);
	else
		printf("<unknown: %d>\n", buffer[16]);
}

/**
 * elf_type - print elf type
 * @bit_mode: the bit mode of the executable (32 or 64)
 * @buffer: the ELF header
 */
void elf_entrypoint(unsigned int bit_mode, const char *buffer)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	buffer += address_size;

	while (address_size && !*(--buffer))
		--address_size;

	printf("%x", *buffer & 0xff);

	while (--address_size > 0)
		printf("%02x", *(--buffer) & 0xff);

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
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
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

	elf_entrypoint(bit_mode, buffer);

	return (0);
}
