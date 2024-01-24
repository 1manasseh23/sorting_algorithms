#include <stdlib.h>
#include "sort.h"
void heapify(int *array, int size, int i, size_t orig_size);
void swap(int *a, int *b);
/**
 * heap_sort - A function that sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * @array: Array to sort
 * @size: The size of array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
/**
 * heapify - A function that heapifies a subtree
 * @array: Array to sort
 * @size: Size of the array
 * @i: The index of root node
 * @orig_size: original size of the array
 * Return: void
 */

void heapify(int *array, int size, int i, size_t orig_size)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, orig_size);
	}
}
/**
 * swap - A function that swap two integers
 * @a: First integer
 * @b: Second integer
 * Return: void
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
