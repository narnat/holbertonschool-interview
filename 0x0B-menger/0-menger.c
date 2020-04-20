#include "menger.h"

/**
 * put_space - Check whether to put space or not
 * in base 3, coordinates (1, 1) means not to print a space
 * @row: row index
 * @col: col index
 * Return: 1 to print space, 0 to print character
*/
int put_space(size_t row, size_t col)
{
	for (; row && col; row /= 3, col /= 3)
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
	return (0);
}

/**
 * menger - Menger sponge genrator, using # as basic units with value of 1
 * @level: Level of Menger cube
 */
void menger(int level)
{
	size_t size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			printf(put_space(row, col) ? " " : "#");
		printf("\n");
	}

}
