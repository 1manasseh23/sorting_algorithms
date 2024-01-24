#include <stdlib.h>
#include "sort.h"
/**
 * radix_sort - function that sorts an array of
 * integers in ascending order using
 * the Radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int i, max_digit = 0, exp = 1;
	int *output = NULL, *count = NULL;

	if (!array || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(output);
		return;
	}
	for (i = 0; i < (int)size; i++)
		max_digit = array[i] > max_digit ? array[i] : max_digit;

	while (max_digit / exp > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output[i];
		print_array(array, size);
		exp *= 10;
	}
	free(count);
	free(output);
}
