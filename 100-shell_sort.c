#include <stdio.h>
#include "sort.h"
void print_array(const int *array, size_t size);
/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
