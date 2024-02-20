#include "sort.h"
#include <stdio.h>
/**
 * swap - swaping fuc a node with the next node in the list
 *
 * @list: pointer to the beginning of the list
 * @node: the node to swap
 *
 * Return: void
 */

void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}
/**
 * cocktail_sort_list - func sorts list of integers in ascending order
 *                      with the Cocktail shaker sort algorithm
 *
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *x;

	if (list == NULL || *list == NULL)
		return;
	x = *list;

	while (swapped != 0)
	{
		swapped = 0;
		while (x->next != NULL)
		{
			if (x->next->n < x->n)
			{
				swap(list, x);
				swapped = 1;
				print_list(*list);
			}
			else
				x = x->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;
		while (x->prev != NULL)
		{
			if (x->prev->n > x->n)
			{
				swap(list, x->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				x = x->prev;
		}
	}
}
