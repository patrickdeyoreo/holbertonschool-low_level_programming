#include "deck.h"
#include <stdio.h>

#define DECKSIZE 52

/**
 * strcmp - compare two strings
 * @s1: a string to compare
 * @s2: the other string to compare
 *
 * Return:
 * integer < 0 if s1 < s2,
 * integer > 0 if s1 > s2,
 * otherwise 0
 */
int strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 += 1;
		s2 += 1;
	}
	if (*s1)
		return (1);
	if (*s2)
		return (-1);

	return (0);
}

/**
 * compare - compare two cards
 * @a: a double pointer to a deck node
 * @b: a double pointer to a deck node
 *
 * Return:
 * integer < 0 if *a < *b,
 * integer > 0 if *a > *b,
 * otherwise 0
 */
int compare(const void *a, const void *b)
{
	static const char * const values[] = {
		"Ace",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"Jack",
		"Queen",
		"King"
	};
	const card_t *cards[2];
	unsigned int indices[] = {0, 0};

	cards[0] = (* (const deck_node_t **) a)->card;
	cards[1] = (* (const deck_node_t **) b)->card;

	if (cards[0]->kind != cards[1]->kind)
		return (cards[0]->kind - cards[1]->kind);

	while (strcmp(cards[0]->value, values[indices[0]]))
		indices[0] += 1;

	while (strcmp(cards[1]->value, values[indices[1]]))
		indices[1] += 1;

	return (indices[0] - indices[1]);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: a double pointer to the head of a doubly-linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *cards[DECKSIZE], *card;
	size_t index = 0;

	if (deck)
	{
		for (card = *deck; card; card = card->next)
			cards[index++] = card;
		qsort(cards, DECKSIZE, sizeof(card), compare);
		cards[index = 0]->prev = NULL;
		while (index < DECKSIZE - 1)
		{
			cards[index]->next = cards[index + 1];
			index += 1;
			cards[index]->prev = cards[index - 1];
		}
		cards[index]->next = NULL;
		*deck = *cards;
	}
}
