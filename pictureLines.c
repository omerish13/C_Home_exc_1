#include "pictureLines.h"
#include <stdio.h>

int checkHorizontalLine(const int* mat, int cols, int rows,int x1,int y1, int x2, int y2)
{
    if (x1 > rows || x1 < 1 || y1 > cols || y1 < 1 || y2 > cols || y2 < 1)
        return 0;

    if (y1 > 1 && (*(mat+(x1*(y1-1)-1)) || (x1 > 1 && *(mat+((x1-1)*(y1-1)-1))) || (x1 < rows && *(mat+((x1+1)*(y1-1)-1)))))
        return 0;
    if (y2 < cols && (*(mat+(x1*(y2+1)-1)) || (x1 > 1 && *(mat+((x1-1)*(y2+1)-1))) || (x1 < rows && *(mat+((x1+1)*(y2+1)-1)))))
        return 0;
    for (int i = 0; i < y2 - y1; i++)
    {
        if (*(mat+(x1*y1+i-1)))
            return 0;
        if (x1 > 1 && *(mat+((x1-1)*y1+i-1)))
            return 0;
        if (x1 < rows && *(mat+((x1+1)*y1+i-1)))
            return 0;
    }

    return 1;
}

int checkVerticalLine(const int* mat, int cols, int rows,int x1,int y1, int x2, int y2)
{
    if (y1 > cols || y1 < 1 || x1 > rows || x1 < 1 || x2 > rows || x2 < 1)
        return 0;

    if (x1 > 1 && (*(mat+((x1-1)*y1-1)) || (y1 > 1 && *(mat+((x1-1)*(y1-1)-1))) || (y1 < cols && *(mat+((x1-1)*(y1+1)-1)))))
        return 0;
    if (x2 < rows && (*(mat+((x2+1)*y1-1)) || (y1 > 1 && *(mat+((x2+1)*(y1-1)-1))) || (y1 < cols && *(mat+((x2+1)*(y1+1)-1)))))
        return 0;
    for (int i = 0; i < x2 - x1; i++)
    {
        if (*(mat+(x1*y1+(i*cols)-1)))
            return 0;
        if (y1 > 1 && *(mat+(x1*(y1-1)+(i*cols)-1)))
            return 0;
        if (y1 < cols && *(mat+(x1*(y1+1)+(i*cols)-1)))
            return 0;
    }

    return 1;
}

void addHorizontalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < y2 - y1; i++)
    {
        *(mat+(x1*y1+i-1)) = 1;
    }
}

void addVerticalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < x2 - x1; i++)
    {
        *(mat+(x1*y1+(i*cols)-1)) = 1;
    }
}

int getLine(int* mat, int cols, int rows, int* x1, int* y1, int* x2, int* y2)
{
    printf("Enter start and end points in mat (x1,y1,x2,y2):\n");
    scanf("%d", x1);
    scanf("%d", y1);
    scanf("%d", x2);
    scanf("%d", y2);

    if (*x1 == *x2 && *y1 < *y2)
    {
        if (checkHorizontalLine((int*)mat,cols,rows,*x1,*x2,*y1,*y2))
        {
            addHorizontalLine((int*)mat,cols,rows,*x1,*x2,*y1,*y2);
            return 1;
        }       
    }

    else if (*x1 < *x2 && *y1 == *y2)
    {
        if (checkVerticalLine((int*)mat,cols,rows,*x1,*x2,*y1,*y2))
        {
            addVerticalLine((int*)mat,cols,rows,*x1,*x2,*y1,*y2);
            return 1;
        }
    }

    return 0;

}

int countLines(int* mat, int cols, int rows)
{
    int count = 0, x1, x2, y1, y2, res;

    char option = 'y';

	

    do {
        printf("\n\n");
	    printf("Please choose one of the following options\n");
	    printf("y - Add Line\n");
	    printf("n - Finish and Exit\n");

	    scanf("%s", &option);
        switch (option)
        {
        case 'y':
            res = getLine((int*)mat,cols,rows,&x1,&y1,&x2,&y2);
            if (res){
                printf("Line Added!");
                count += res;
            }
            else
                printf("Line can't be added!");
            break;

        case 'n':
            break;
        }
    } while (option != 'n');

    return count;
}


int initMatSize(int COLS, int ROWS, int* cols, int* rows)
{
    printf("Enter rows and cols number:\n");
    scanf("%d", rows);
    scanf("%d", cols);

    if (*rows > ROWS || *cols > COLS || *rows < 1 || *cols < 1)
    {
        printf("Error, number of rows or cols is invalid!");
        return 0;
    }
    return 1;
}

void addLines(int COLS, int ROWS)
{
    int rows,cols, res = 0;

    while (!res){
        res = initMatSize(COLS,ROWS,&cols,&rows);
    }

    int mat[rows][cols];

    printf("Number of lines is %d",countLines((int*)mat,cols,rows));
}