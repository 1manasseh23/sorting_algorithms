#include "sort.h"
#include <stdio.h>
void print_array(const int *array, size_t size);

/**
 * bubble_sort - A function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: pointer to the element to swap
 * @size: the size of the element
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; ++i)
	{

		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
