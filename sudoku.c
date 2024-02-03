#include <string.h>
#include <math.h>
#include <stdio.h>
#include "sudoku.h"
#include "matrix.h"

#define N 25

void sudokuGame()
{
	int mat[N][N];
	int size, init=0;
	while (!init)
	{
		init = initBoardSize(N,&size);
	}

	initBoard((int*)mat, size, size*size);

	printMatrix((int*)mat,size,size);

	if (checkBoard((int*)mat,size))
		printf("A valid Sudoku\n");
	else
		printf("Not a valid Sudoku\n");
}

int initBoardSize(int maxSize,int* size)
{
	printf("Enter Sudoku size, sqrt(size) need to be an integer less then %d\n", maxSize);
	scanf("%d",size);
	
	if (*size > maxSize || *size < 1) 
	{
		return 0;
	}
	int sqrtSize =(int)sqrt(*size);
	if (sqrtSize*sqrtSize != *size)
	{
		return 0;
	}

	return 1;
}

void initBoard(int* mat, int size, int elemnts)
{
	for (int i = 0; i < elemnts; i++, mat++)
	{
		printf("enter element %d %d: ", i / size, i % size);
		scanf("%d", mat);
	}
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

int checkSquare(const int* mat, int* arr, int size, int cell) 
{
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