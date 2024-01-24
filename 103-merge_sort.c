#include <stdlib.h>
#include "sort.h"
#include <stdio.h>
void top_down_split(int *array, int start, int end, int *tmp);
void top_down_merge(int *array, int start, int mid, int end, int *tmp);
/**
 * merge_sort - A function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: Array to sort
 * @size: The size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	top_down_split(array, 0, size, tmp);
	free(tmp);
}

/**
 * top_down_split - A function that splits the array recursively
 * @array: Array to sort
 * @start: Start index
 * @end: end index
 * @tmp: temporary array
 * Return: void
 */

void top_down_split(int *array, int start, int end, int *tmp)
{
	int mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	top_down_split(array, start, mid, tmp);
	top_down_split(array, mid, end, tmp);
	top_down_merge(array, start, mid, end, tmp);
}

/**
 * top_down_merge - A function that merge sub-arrays
 * @array: Array to sort
 * @start: start index
 * @mid: Middle index
 * @end: End of index
 * @tmp: A temporary array
 * Return: void
 */

void top_down_merge(int *array, int start, int mid, int end, int *tmp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = start; i < mid; i++)
	{
		tmp[i] = array[i];
		printf("%d", tmp[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (j = mid; j < end; j++)
	{
		tmp[j] = array[j];
		printf("%d", tmp[j]);
		if (j < end - 1)
			printf(", ");
	}
	printf("\n");
	for (i = start, j = mid, k = start; k < end; k++)
	{
		if (i < mid && (j >= end || tmp[i] <= tmp[j]))
		{
			array[k] = tmp[i];
			i++;
		}
		else
		{
			array[k] = tmp[j];
			j++;
		}
	}
	printf("[Done]: ");
	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}
