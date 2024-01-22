#include <stdio.h>
#include "sort.h"
void swap(int *a, int *b);

void print_array(const int *array, size_t size);
/**
 * selection_sort - A function that sorts a doubly linked
 * list of integers in ascending order
 * using the Insertion sort algorithm
 * @array: A pointer for after each time you swap two elements
 * @size: Size of the element
 * Return: 0
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, mid_idx;

	for (i = 0; i < size - 1; i++)
	{
		mid_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mid_idx])
				mid_idx = j;
		}
		if (mid_idx != i)
		{
			swap(&array[mid_idx], &array[i]);
			print_array(array, size);
		}
	}
}
