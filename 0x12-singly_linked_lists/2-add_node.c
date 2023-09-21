#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newnd;
	unsigned int len = 0;

	while (str[len])
		len++;

	newnd = malloc(sizeof(list_t));
	if (!newnd)
		return (NULL);

	newnd->str = strdup(str);
	newnd->len = len;
	newnd->next = (*head);
	(*head) = newnd;

	return (*head);
}

