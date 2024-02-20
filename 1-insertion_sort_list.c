#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * insertion_sort_list - fun to sorts doubly linked list of integers in an
 *                      ascending order
 *
 * @list: pointer to the head of the linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swaping_node, *new_swap;

	if (list == NULL || *list == NULL)
		return;

	swaping_node = (*list)->next;

	while (swaping_node != NULL)
	{
		new_swap = swaping_node->next;

		while (swaping_node->prev != NULL && swaping_node->prev->n > swaping_node->n)
		{
			swaping_node->prev->next = swaping_node->next;
			if (swaping_node->next != NULL)
				swaping_node->next->prev = swaping_node->prev;
			swaping_node->next = swaping_node->prev;
			swaping_node->prev = swaping_node->next->prev;
			swaping_node->next->prev = swaping_node;
			if (swaping_node->prev == NULL)
				*list = swaping_node;
			else
				swaping_node->prev->next = swaping_node;
			print_list(*list);
		}

		swaping_node = new_swap;
	}
}
