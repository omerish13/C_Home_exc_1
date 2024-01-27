#include "pictureManipulation.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// #include <ctype.h>
#define MAX 10
#define MIN 1
#define SIZE 5

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

void initMatrix(int* mat,int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++,mat++)
        {
            *mat = MIN + (rand()%(MAX-MIN+1));
        }
        
    }
    
}

void printMatrix(const int* mat, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *mat); 
            mat++;
        }
        printf("\n");
    }
}

void pictureManipulation()
{
    int mat[SIZE][SIZE] = {0};
    initMatrix((int*)mat,SIZE);
    char option;

    do {
        // printMatrix((int*)mat,SIZE,SIZE);
        printf("\n\n");
	    printf("What do you want to do?\n");
	    printf("a - Rotate 90 degrees clockwise\n");
        printf("b - Rotate 90 degrees counter clockwise\n");
        printf("c - Flip verticly\n");
        printf("d - Flip horizantly\n");
	    printf("e - Finish and Exit\n");

	    scanf("%c", &option);
        switch (option)
        {
            case 'a':
            {
                rotateClockwise((int*)mat,SIZE);
                break;
            }
            case 'b':
            {
                rotateCounterClockwise((int*)mat,SIZE);
                break;
            }
            case 'c':
            {
                FlipVertical((int*)mat,SIZE);
                break;
            }
            case 'd':
            {
                FlipHorizontal((int*)mat,SIZE);
                break;
            }
            case 'e':
            {
                break;
            }
        }
    } while (option != 'e');

}
