#include "sort.h"

/**
 * swap_ints - Function that swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int eric;

	eric = *a;
	*a = *b;
	*b = eric;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Description: The Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t ken, a, c;

	if (array == NULL || size < 2)
		return;

	for (ken = 1; ken < (size / 3);)
		ken = ken * 3 + 1;

	for (; ken >= 1; ken /= 3)
	{
		for (a = ken; a < size; a++)
		{
			c = a;
			while (c >= ken && array[c - ken] > array[c])
			{
				swap_ints(array + c, array + (c - ken));
				c -= ken;
			}
		}
		print_array(array, size);
	}
}
