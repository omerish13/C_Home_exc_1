#include "matrix.h"
#include <stdio.h>

void printMatrix(const int* mat, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%5d",*mat);
			mat++;

		}
		printf("\n");
	}
}