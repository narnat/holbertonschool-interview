#include "slide_line.h"
#include <limits.h>

/**
 * slide_left - slides array @line to left
 * @line: array of values, all of which is power of 2 or 0
 * @size: size of @line
 */
void slide_left(int *line, size_t size)
{
	size_t i = 0, j = 1;
	int last_val = line[0];

	for (; j < size; ++j)
	{
		if (line[j])
		{
			if (!last_val)
				last_val = line[j];
			else if (last_val == line[j])
			{
				line[i++] = last_val * 2;
				last_val = 0;
			}
			else
			{
				line[i++] = last_val;
				last_val = line[j];
			}
		}
	}

	if (last_val)
		line[i++] = last_val;

	for (; i < size; ++i)
		line[i] = 0;
}

/**
 * slide_right - slides array @line to right
 * @line: array of values, all of which is power of 2 or 0
 * @size: size of @line
 */
void slide_right(int *line, size_t size)
{
	int i = size - 1, j = size - 2;
	int last_val = line[i];

	for (; j >= 0; --j)
	{
		if (line[j])
		{
			if (!last_val)
				last_val = line[j];
			else if (last_val == line[j])
			{
				line[i--] = last_val * 2;
				last_val = 0;
			}
			else
			{
				line[i--] = last_val;
				last_val = line[j];
			}
		}
	}

	if (last_val)
		line[i--] = last_val;

	for (; i >= 0; --i)
		line[i] = 0;
}

/**
 * slide_line - slides array @line to left or right
 * @line: array of values, all of which is power of 2 or 0
 * @size: size of @line
 * @direction: either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);

	direction == SLIDE_LEFT
		? slide_left(line, size)
		: slide_right(line, size);

	return (1);
}
