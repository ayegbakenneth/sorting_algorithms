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
	size_t j, length = size;
	bool cruize = false;

	if (array == NULL || size < 2)
		return;

	while (cruize == false)
	{
		cruize = true;
		for (j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				cruize = false;
			}
		}
		length--;
	}
}
