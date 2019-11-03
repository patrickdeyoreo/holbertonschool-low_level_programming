#include "deck.h"
#include <stdio.h>

#define DECKSIZE 52
#define N_VALUES 13

/**
 * cmp_cards - compare two cards
 * @a: a double pointer to a deck node
 * @b: a double pointer to a deck node
 *
 * Return:
 * integer < 0 if *a < *b,
 * integer > 0 if *a > *b,
 * otherwise 0
 */
int cmp_cards(const deck_node_t **a, const deck_node_t **b)
{
	static const char values[N_VALUES] = {
		'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'
	};
	const card_t *cards[2];
	int indices[] = {0, 0};

	cards[0] = (*a)->card;
	cards[1] = (*b)->card;

	if (cards[0]->kind != cards[1]->kind)
		return (cards[0]->kind - cards[1]->kind);

	while (indices[0] < N_VALUES && *cards[0]->value != values[indices[0]])
		indices[0] += 1;

	while (indices[1] < N_VALUES && *cards[1]->value != values[indices[1]])
		indices[1] += 1;

	return (indices[0] - indices[1]);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: a double pointer to the head of a doubly-linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *cards[DECKSIZE];
	deck_node_t *card = NULL;
	size_t index = 0;

	if (deck)
	{
		for (card = *deck; card; card = card->next)
			cards[index++] = card;

		qsort(cards, DECKSIZE, sizeof(*cards),
			(int (*)(const void *, const void *)) cmp_cards);

		index = 0;
		cards[index]->prev = NULL;
		while (index < DECKSIZE - 1)
		{
			cards[index]->next = cards[index + 1];
			index++;
			cards[index]->prev = cards[index - 1];
		}
		cards[index]->next = NULL;
		*deck = *cards;
	}
}
