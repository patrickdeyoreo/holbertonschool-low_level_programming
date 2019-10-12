#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/**
 * struct hash_node_s - hash table node
 * @next: a pointer to the next element in a chain
 * @key: the key of an item in a hash table
 * @value: the associated value
 *
 * Description: Each key is unique within a hash table.
 */
typedef struct hash_node_s
{
	struct hash_node_s *next;
	char *key;
	char *value;
} hash_node_t;

/**
 * struct hash_table_s - hash table
 * @array: an array of size @size
 * @size: the size of @array
 *
 * Description: At each array index is a pointer to the first node
 * of a singly-linked list, each of which will be used as the head
 * of a chain of elements for the purpose of resolving collisions.
 */
typedef struct hash_table_s
{
	hash_node_t **array;
	unsigned long int size;
} hash_table_t;

/**
 * struct shash_node_s - Node of a sorted hash table
 * @next: a pointer to the next element in a chain
 * @sprev: a pointer to the previous element in a sorted list
 * @snext: a pointer to the next element in a sorted list
 * @key: the key of an item in a hash table
 * @value: the associated value
 *
 * Description: Each key is unique within a hash table.
 */
typedef struct shash_node_s
{
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
	char *key;
	char *value;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @array: An array of size @size
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 * @size: The size of the array
 *
 * Description: At each array index is a pointer to the first node
 * of a singly-linked list, each of which will be used as the head
 * of a chain of elements for the purpose of resolving collisions.
 * Additionally, a doubly-linked list is maintained across chains,
 * providing sorted access to the elements in the table.
 */
typedef struct shash_table_s
{
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
	unsigned long int size;
} shash_table_t;

unsigned long int hash_djb2(const unsigned char *);
unsigned long int key_index(const unsigned char *, unsigned long int);

hash_table_t *hash_table_create(unsigned long int);
int hash_table_set(hash_table_t *ht, const char *, const char *);
char *hash_table_get(const hash_table_t *, const char *);
void hash_table_print(const hash_table_t *);
void hash_table_delete(hash_table_t *);

shash_table_t *shash_table_create(unsigned long int);
int shash_table_set(shash_table_t *ht, const char *, const char *);
char *shash_table_get(const shash_table_t *, const char *);
void shash_table_print(const shash_table_t *);
void shash_table_print_rev(const shash_table_t *);
void shash_table_delete(shash_table_t *);

#endif /* HASH_TABLES_H */
