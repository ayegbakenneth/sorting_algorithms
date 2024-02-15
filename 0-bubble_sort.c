#include "sort.h"

/**
 * swap_ints - Exchange two int value in an array.
 * @a: Integer one to swap.
 * @b: Integer two to swap.
 */
void swap_ints(int *a, int *b)
{
	int ken;

	ken = *a;
	*a = *b;
	*b = ken;
}

/**
 * bubble_sort - Arrange the array of numbers in ascending order.
 * @array: Integers to sort.
 * @size:  Array size.
 *
 * Description: After the swap then print.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, total = size;
	bool cruize = false;

	if (array == NULL || size < 2)
		return;

	while (cruize == false)
	{
		cruize = true;
		for (i = 0; i < total - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				cruize = false;
			}
		}
		cruize--;
	}
}
