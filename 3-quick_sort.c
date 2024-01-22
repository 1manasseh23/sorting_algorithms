#include <stdio.h>
#include "sort.h"
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
void quick_sort_helper(int *array, int low, int high);
int partition(int *array, int low, int high);
/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: Pointer for after each time you swap two elements
 * @size: The size of element
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quick_sort_helper(array, 0, size - 1);
}
/**
 * quick_sort_helper - A function that sort the two
 * partition recursively
 * @array: Pointer for after each time you swap two elements
 * @low: The position of the element if is low
 * @hight: The position of the element if is high
 * Return: 0
 */

void quick_sort_helper(int *array, int low, int hight)
{
	int pt;

	if (low >= hight)
		return;

	pt = partition(array, low, hight);
	print_array(array, hight + 1);
	quick_sort_helper(array, low, pt - 1);
	quick_sort_helper(array, pt + 1, hight);
}
/**
 * partition - A function that divides the array into
 * two partition and return the ps index
 * @array: The array of element to divide
 * @low: The position of the partition if is low
 * @hight: The position of the partition if is high
 * Return: Sorted elements
 */

int partition(int *array, int low, int hight)
{
	int ps = array[hight];
	int i = low - 1;
	int j;

	for (j = low; j < hight; j++)
	{
		if (array[j] < ps)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, hight + 1);
			}
		}
	}
	if (array[i + 1] > ps)
	{
		swap(&array[i + 1], &array[hight]);
		print_array(array, hight + 1);
	}
	return (i + 1);
}
/**
 * swap - A function that swat two position
 * of an element in Array
 * @a: The pointer to the fisrt element to check fo swaping
 * @b: The element to swap with a
 * Return: 0
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
