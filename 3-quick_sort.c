#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Partitions an array using Lomuto scheme
 * @array: Array of integers
 * @low: Starting position
 * @high: Ending position
 * @size: Size of the array
 *
 * Return: Position of the pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
size_t i;
size_t j;
int pivot;

pivot = array[high];
i = low;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
i++;
}
}

if (i != high && array[i] != array[high])
{
swap(&array[i], &array[high]);
print_array(array, size);
}

return (i);
}

/**
 * quick_sort_recursive - Sorts an array recursively
 * @array: Array of integers
 * @low: Starting position
 * @high: Ending position
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
size_t pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);

if (pivot > 0)
quick_sort_recursive(array, low, pivot - 1, size);

quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array using Quick sort
 * @array: Array of integers
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
