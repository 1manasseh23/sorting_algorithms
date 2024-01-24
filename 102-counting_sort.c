#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - A function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: Array to sort
 * @size: The size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count = NULL, *output = NULL;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		max = array[i] > max ? array[i] : max;
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
