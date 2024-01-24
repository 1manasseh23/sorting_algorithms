#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void bitonic_merge_sort(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	bitonic_merge(array, size, 1);
}

/**
 * bitonic_merge - Recursively merges two halves of the array in a bitonic manner
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t k = size / 2;
		printf("Merging [%lu/%lu] (%s):\n", k, size, (dir == 1) ? "UP" : "DOWN");

		bitonic_merge(array, k, 1);

		bitonic_merge(array + k, k, 0);

		bitonic_merge_sort(array, size, dir);
	}
}

/**
 * bitonic_merge_sort - Sorts and merges two halves of the array
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_merge_sort(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t i, j;
		size_t h = size / 2;

		for (i = 0; i < h; i++)
		{
			j = i + h;
			if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}

		bitonic_merge_sort(array, h, dir);
		bitonic_merge_sort(array + h, h, dir);
	}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
