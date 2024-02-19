#include "sort.h"

/**
 * pick_highest - Pick the highest value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: Maximum integer in the array.
 */
int pick_highest(int *array, int size)
{
	int highest, j;

	for (highest = array[0], j = 1; j < size; j++)
	{
		if (array[j] > highest)
			highest = array[j];
	}

	return (highest);
}

/**
 * counting_sort - Using the counting sort algorithm to sort an array.
 * @array: The array
 * @size: Array size.
 *
 * Description: Counting array after setting it up and prints.
 */
void counting_sort(int *array, size_t size)
{
	int *lookup, *organised, highest, j;

	if (array == NULL || size < 2)
		return;

	organised = malloc(sizeof(int) * size);
	if (organised == NULL)
		return;
	highest = pick_highest(array, size);
	lookup = malloc(sizeof(int) * (highest + 1));
	if (lookup == NULL)
	{
		free(organised);
		return;
	}

	for (j = 0; j < (highest + 1); j++)
		lookup[j] = 0;
	for (j = 0; j < (int)size; j++)
		lookup[array[j]] += 1;
	for (j = 0; j < (highest + 1); j++)
		lookup[j] += lookup[j - 1];
	print_array(lookup, highest + 1);

	for (j = 0; j < (int)size; j++)
	{
		organised[lookup[array[j]] - 1] = array[j];
		organised[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = organised[j];

	free(organised);
	free(lookup);
}
