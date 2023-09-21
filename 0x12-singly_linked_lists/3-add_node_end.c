#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnd;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	newnd = malloc(sizeof(list_t));
	if (!newnd)
		return (NULL);

	newnd->str = strdup(str);
	newnd->len = len;
	newnd->next = NULL;

	if (*head == NULL)
	{
		*head = newnd;
		return (newnd);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = newnd;

	return (newnd);
}

