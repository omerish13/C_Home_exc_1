#include "pictureManipulation.h"
#include <stdio.h>
#define MAX 50
#define MIN 1
#define SIZE 10

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
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size / 2; j++,mat++)
        {
            temp = *mat;
            *mat = *(mat + j * size + (size - 1 - i));
            *(mat + j * size + (size - 1 - i)) = temp;
        }
        mat += size / 2;
        
    }
    
}

void FlipHorizontal(int* mat, int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = i; j < size; j++,mat++)
        {
            temp = *mat;
            *mat = *(mat + (size - 1 - j) * size + i);
            *(mat + (size - 1 - j) * size + i) = temp;
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

void pictureManipulation()
{
    int mat[SIZE][SIZE] = {0};
    initMatrix(mat,SIZE);
    int option;

    do {
        printf("\n\n");
	    printf("What do you want to do?\n");
	    printf("1 - Rotate 90 degrees clockwise\n");
        printf("2 - Rotate 90 degrees counter clockwise\n");
        printf("3 - Flip verticly\n");
        printf("4 - Flip horizantly\n");
	    printf("-1 - Finish and Exit\n");

	    scanf("%s", &option);
        switch (option)
        {
        case 1:
        {
            rotateClockwise(&mat,SIZE);
            break;
        }
        case 2:
        {
            rotateCounterClockwise(&mat,SIZE);
            break;
        }
        case 3:
        {
            FlipVertical(&mat,SIZE);
            break;
        }
        case 4:
        {
            FlipHorizontal(&mat,SIZE);
            break;
        }
        case -1:
            break;
        }
    } while (option != -1);

}
