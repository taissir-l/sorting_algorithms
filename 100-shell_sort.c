#include "sort.h"

/**
 * shell_sort - function to sorts an array of integers in
 *         ascending order using the Shell sort algorithm
 *
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, x = 1;
	int a;

	if (array == NULL || size < 2)
		return;
	while (x < size / 3)
		x = x * 3 + 1;
	while (x > 0)
	{
		for (i = x; i < size; i++)
		{
			a = array[i];
			for (j = i; j >= x && array[j - x] > a; j = j - x)
				array[j] = array[j - x];
			array[j] = a;
		}
		x = (x - 1) / 3;
		print_array(array, size);
	}
}
