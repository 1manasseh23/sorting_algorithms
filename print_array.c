#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b);

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
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
