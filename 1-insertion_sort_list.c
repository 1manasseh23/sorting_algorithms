#include "sort.h"
#include <stdio.h>
void print_list(const listint_t *list);
/**
 * insertion_sort_list - A function that sorts a doubly linked
 * list of integers in ascending order using
 * the Insertion sort algorithm
 * @list: A duble pointer to the each time you swap two elements
 * Return: 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cnt, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cnt = (*list)->next;
	while (cnt != NULL)
	{
		tmp = cnt->next;
		while (cnt->prev != NULL && cnt->n < cnt->prev->n)
		{
			cnt->prev->next = cnt->next;
			if (cnt->next != NULL)
			{
				cnt->next->prev = cnt->prev;
			}
			cnt->next = cnt->prev;
			cnt->prev = cnt->prev->prev;
			cnt->next->prev = cnt;
			if (cnt->prev == NULL)
			{
				*list = cnt;
			}
			else
			{
				cnt->prev->next = cnt;
			}
			print_list(*list);
		}
		cnt = tmp;
	}
}
