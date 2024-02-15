#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Exchange of two integers in an array.
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
 * lomuto_partition - According to lomuto partition scheme, order a
 *                    subset of an array.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: Partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, bottom;

	pivot = array + right;
	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Array size
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int body;

	if (right - left > 0)
	{
		body = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, body - 1);
		lomuto_sort(array, size, body + 1, right);
	}
}

/**
 * quick_sort - Arrange an array of integers in ascending order.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: With the Lomuto partition scheme Prints
 *              the array after each exchange of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
