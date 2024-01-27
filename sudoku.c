#include "sudoku.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

#define N 25

int checkRow(const int* mat,int* arr,int size, int cell)
{
	memset(arr, 0, size * sizeof(int));
	int value;
	for (int i = 0; i < size; i++)
	{
		value = *(mat+cell+i)-1;
		if (value < 0 || value > size-1 || *(arr+value))
			return 0;
		else
			*(arr+value) = 1;
	}
	
	return 1;
}

int checkCol(const int* mat,int* arr,int size, int cell)
{
	memset(arr, 0, size * sizeof(int));
	int value;
	for (int i = 0; i < size; i++)
	{
		value = *(mat+cell+size*i)-1;
		if (value < 0 || value > size-1 || *(arr+value))
			return 0;
		else
			*(arr+value) = 1;
	}
	
	return 1;
}

int checkSquare(const int* mat, int* arr, int size, int cell) {
    int sqrtSize = (int)sqrt(size);
    memset(arr, 0, size * sizeof(int));

    const int *squareStart = mat + ((cell / size / sqrtSize) * sqrtSize) * size + (cell % size / sqrtSize) * sqrtSize;

    for (int i = 0; i < size; i++) {
        const int *currentCell = squareStart + (i / sqrtSize) * size + (i % sqrtSize);
        int value = *currentCell - 1;
        int *arrCell = arr + value;

        if (value < 0 || value > size-1 || *arrCell) {
            return 0;
        } else {
            *arrCell = 1;
        }
    }
    return 1;
}

int checkBoard(const int* mat, int size)
{
	int arr[size]; 
	for (int i = 0; i < size; i++)
	{
		if (!checkRow(mat,arr,size,i*size))
			return 0;
		
		if (!checkCol(mat,arr,size,i))
			return 0;
		
		if (!checkSquare(mat,arr,size,i))
			return 0;
	}
	return 1;
}

void showBoard(const int* mat, int size)
{
	int sqrtSize = (int)sqrt(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j % sqrtSize == 0)
				printf("|");
			printf("%5d",*mat);
			mat++;

		}
		if (i % sqrtSize == 1)
		{
			printf("\n");
			for (int i = 0; i < size*5; i++)
				printf("-");
		}
		printf("\n");
	}
}

void initBoard(int* mat, int size)
{
	printf("Please enter %d elemnts for mat\n", size);
	for (int i = 0; i < size; i++, mat++)
	{
		scanf("%d", mat);
	}
}

int initBoardSize(int maxSize,int* size)
{
	printf("Please enter the size of the board (board size will be size, and should be smaller than %d):\n", maxSize);
	scanf("%d",size);
	
	if (*size > maxSize || *size < 1) 
	{
		printf("Error, size should be smaller than %d and greater then 1\n",maxSize);
		return 0;
	}
	int sqrtSize =(int)sqrt(*size);
	if (sqrtSize*sqrtSize != *size)
	{
		printf("Error, size is non-square number, please replace size to a square number\n");
		return 0;
	}

	return 1;
}

void sudokuGame()
{
	int mat[N][N];
	int size, init=0;
	while (!init)
	{
		init = initBoardSize(N,&size);
	}

	initBoard((int*)mat,size*size);

	showBoard((int*)mat,size);

	if (checkBoard((int*)mat,size))
		printf("Sudoku Board is valid!\n");
	else
		printf("Sudoko Board isn't valid!\n");
}
