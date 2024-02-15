#include "sort.h"

/**
 * swap_ints - To exchange two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int ken;

	ken = *a;
	*a = *b;
	*b = ken;
}

/**
 * selection_sort - Arrange an array of integers in ascending order
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: After each swap, print the array.
 */
void selection_sort(int *array, size_t size)
{
	int *luv;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		luv = array + i;
		for (j = i + 1; j < size; j++)
			luv = (array[j] < *luv) ? (array + j) : luv;

		if ((array + i) != luv)
		{
			swap_ints(array + i, luv);
			print_array(array, size);
		}
	}
}
