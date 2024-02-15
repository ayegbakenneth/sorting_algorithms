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
