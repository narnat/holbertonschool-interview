#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}

		printf(" %c ", (i == 1 ? '+' : ' '));

		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid2[i][j]);
		}
		printf("\n");
	}
}

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int grid1[3][3] = {
		{3, 3, 3},
		{3, 3, 3},
		{3, 3, 3}
	};
	int grid2[3][3] = {
		{1, 3, 1},
		{3, 3, 3},
		{1, 3, 1}
	};
	sandpiles_sum(grid1, grid2);
	printf("=\n");
	print_grid(grid1);

	printf("====================\n====================\n");

	int grid3[3][3] = {
		{3, 3, 3},
		{3, 3, 3},
		{3, 3, 3}
	};
	int grid4[3][3] = {
		{1, 3, 1},
		{3, 3, 3},
		{1, 3, 1}
	};
	sandpiles_sum1(grid3, grid4);
	printf("=\n");
	print_grid(grid3);

	printf("****************************************\n");
	int grid5[3][3] = {
		{4, 3, 4},
		{3, 3, 3},
		{4, 3, 4}
	};
	int grid6[3][3] = {
		{2, 3, 2},
		{3, 3, 3},
		{2, 3, 2}
	};
	sandpiles_sum(grid5, grid6);
	printf("=\n");
	print_grid(grid5);

	printf("====================\n====================\n");

	int grid7[3][3] = {
		{4, 3, 4},
		{3, 3, 3},
		{4, 3, 4}
	};
	int grid8[3][3] = {
		{2, 3, 2},
		{3, 3, 3},
		{2, 3, 2}
	};
	sandpiles_sum1(grid7, grid8);
	printf("=\n");
	print_grid(grid7);

	printf("****************************************\n");
	{
		int grid1[3][3] = {
			{2, 2, 2},
			{2, 2, 2},
			{2, 2, 2}
		};
		int grid2[3][3] = {
			{2, 1, 2},
			{1, 0, 1},
			{2, 1, 2}
		};
		sandpiles_sum(grid1, grid2);
		printf("=\n");
		print_grid(grid1);

		printf("====================\n====================\n");

		int grid3[3][3] = {
			{2, 2, 2},
			{2, 2, 2},
			{2, 2, 2}
		};
		int grid4[3][3] = {
			{2, 1, 2},
			{1, 0, 1},
			{2, 1, 2}
		};
		sandpiles_sum1(grid3, grid4);
		printf("=\n");
		print_grid(grid3);
	}

	return (EXIT_SUCCESS);
}
