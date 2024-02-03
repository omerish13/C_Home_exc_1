#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pictureManipulation.h"
#include "matrix.h"
#define MAX 99
#define MIN 1
#define SIZE 8

void pictureManipulation()
{
    int mat[SIZE][SIZE] = {0};
    int matSize;
    initPictureSize(SIZE,&matSize);
    initMatrix((int*)mat, matSize, MIN, MAX);
    int option;

    do {
        printMatrix((int*)mat,matSize,matSize);
        printf("\n\n");
	    printf("Please choose one of the following options\n");
	    printf("1 - 90 degree clockwise\n");
        printf("2 - 90 degree counter clockwise\n");
        printf("3 - Flip Horizontal\n");
        printf("4 - Flip Vertical\n");
	    printf("-1 - Quit\n");

	    scanf(" %d", &option);
        switch (option)
        {
            case 1:
            {
                rotateClockwise((int*)mat,matSize);
                printf("--------- picture after manipulation ---------\n");
                break;
            }
            case 2:
            {
                rotateCounterClockwise((int*)mat,matSize);
                printf("--------- picture after manipulation ---------\n");
                break;
            }
            case 3:
            {
                FlipHorizontal((int*)mat,matSize);
                printf("--------- picture after manipulation ---------\n");
                break;
            }
            case 4:
            {
                FlipVertical((int*)mat,matSize);
                printf("--------- picture after manipulation ---------\n");
                break;
            }
            case -1:
            {
                break;
            }
        }
    } while (option != -1);
    printf("Bye bye\n");

}

void initPictureSize(int maxSize, int* matSize)
{
    int res = 0;
    printf("Max mat size is: %d\n", maxSize);
    while (res != 1)
    {
        printf("Insert picture size between 1 and %d\n", maxSize);
        scanf("%d", matSize);
        if (*matSize <= maxSize && *matSize > 0)
        {
            res = 1;
        }
    }
    printf("effecive mat size is: %d\n", *matSize);
}

void initMatrix(int* mat,int size, int minNum, int maxNum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++,mat++)
        {
            *mat = minNum + (rand()%(maxNum-minNum + 1));
        }
        
    }  
}

void rotateClockwise(int* mat, int size)
{
    int temp;
    for (int i = 0; i < size/2; i++)
    {
        for (int j = i; j < size - i - 1; j++)
        {
            temp = *(mat+ i * size + j);
            *(mat+ i * size + j) = *(mat + (size - 1 - j) * size + i);
            *(mat + (size - 1 - j) * size + i) = *(mat + (size - 1 - i) * size + (size - 1 - j));
            *(mat + (size - 1 - i) * size + (size - 1 - j)) = *(mat + j * size + (size - 1 - i));
            *(mat + j * size + (size - 1 - i)) = temp;
        }
        
    }
    
}

void rotateCounterClockwise(int* mat, int size)
{
    int temp;
    for (int i = 0; i < size/2; i++)
    {
        for (int j = i; j < size - i - 1; j++)
        {
            temp = *(mat+ i * size + j);
            *(mat+ i * size + j) = *(mat + j * size + (size - 1 - i));
            *(mat + j * size + (size - 1 - i)) = *(mat + (size - 1 - i) * size + (size - 1 - j));
            *(mat + (size - 1 - i) * size + (size - 1 - j)) = *(mat + (size - 1 - j) * size + i);
            *(mat + (size - 1 - j) * size + i) = temp;
        }
        
    }
    
}

void FlipHorizontal(int* mat, int size)
{
    int temp;
    int *top, *bottom;

    for (int i = 0; i < size / 2; i++)
    {
        top = mat + i * size;
        bottom = mat + size * (size-i-1);
        for (int j = 0; j < size; j++,top++,bottom++)
        {
            temp = *top;
            *top = *bottom;
            *bottom = temp;
        }
        
    }
    
}

void FlipVertical(int* mat, int size)
{
    int temp;
    int *start, *end;
    for (int i = 0; i < size; i++)
    {
        start = mat+i*size;
        end = mat+i*size +size - 1;
        for (int j = 0; j < size / 2; j++,start++,end--)
        {
            temp = *start;
            *start = *end;
            *end = temp;
        }
        
    }
    
}