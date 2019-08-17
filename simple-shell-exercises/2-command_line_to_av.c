#include <stdlib.h>
#include <unistd.h>

/**
 * _isspace - check if a character is whitespace
 * @c: the character to check
 *
 * Return: If c is a whitespace character, return 1.
 * If not, return 0.
 */
int _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}

/**
 * _memcpy - copy a memory area
 * @dest: a pointer to the start of the target area
 * @src: a pointer to the start of the source area
 * @n: the number of bytes to copy
 *
 * Description: This function copies n bytes from the memory area at src
 * to the memory area at dest. These memory areas must not overlap.
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	while (n--)
		*pos++ = *src++;

	return (dest);
}

/**
 * count_words - count the words in a string
 * @str: the string to evaluate
 *
 * Return: If str is NULL, return -1.
 * Otherwise, return the number of words in str.
 */
ssize_t count_words(const char *str)
{
	ssize_t word_count;

	if (!str)
		return (-1);

	for (word_count = 0; *str; ++word_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}

	return (word_count);
}

/**
 * strtow - split a string into words (tokens)
 * @str: the string to tokenize
 *
 * Return: If memory allocation fails or str is NULL, return NULL.
 * Otherwise, return an array containing the words in str, terminated by NULL.
 */
char **strtow(const char *str)
{
	char **tokens;
	ssize_t tok_count;
	size_t tok_len;

	tok_count = count_words(str);
	tokens = malloc(sizeof(char *) * (tok_count + 1));
	if (!tokens)
		return (NULL);

	for (tok_count = 0; *str; ++tok_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok_len = 1;
		while (str[tok_len] && !_isspace(str[tok_len]))
			++tok_len;

		tokens[tok_count] = malloc(sizeof(char) * (tok_len + 1));
		if (!tokens[tok_count])
		{
			while (tok_count)
				free(tokens[--tok_count]);
			free(tokens);
			return (NULL);
		}
		_memcpy(tokens[tok_count], str, tok_len);
		tokens[tok_count][tok_len] = '\0';

		str += tok_len;
	}
	tokens[tok_count] = NULL;

	return (tokens);
}

