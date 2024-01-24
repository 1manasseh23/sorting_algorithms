#include <stdio.h>
#include "sort.h"
void cocktail_sort_list(listint_t **list);
/**
 * cocktail_sort_list - A function that Write a function that
 * sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Doubly linked list to sort
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *tmp = NULL;
	int swapp = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapp = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				tmp = start->next;
				start->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = start;
				tmp->prev = start->prev;
				if (start->prev != NULL)
					start->prev->next = tmp;
				else
					*list = tmp;
				start->prev = tmp;
				tmp->next = start;
				swapp = 1;
				print_list(*list);
			}
		}
		end = start;
		for (; end->prev != NULL; end = end->prev)
		{
			if (end->n < end->prev->n)
			{
				tmp = end->prev;
				end->prev = tmp->prev;
				if (tmp->prev != NULL)
					tmp->prev->next = end;
				tmp->next = end->next;
				if (end->next != NULL)
					end->next->prev = tmp;
				else
					*list = tmp;
				end->next = tmp;
				tmp->prev = end;
				swapp = 1;
				print_list(*list);
			}
		}
	} while (swapp);
}
