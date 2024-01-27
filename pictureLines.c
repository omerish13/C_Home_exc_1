#include "pictureLines.h"
#include <stdio.h>

#define ROWS 50
#define COLS 50

int checkLine(const int* mat, int cols, int rows,int x1,int y1, int x2, int y2)
{
    if (x1 > rows || x1 < 1 || y1 > cols || y1 < 1 || y2 > cols || y2 < 1)
        return 0;
    int startCol = y1,endCol = y2, startRow = x1, endRow = x2;
    if (y1 > 1)
        startCol = y1 - 1;
    if (y2 < cols)
        endCol = y2 + 1;
    if (x1 > 1)
        startRow = x1 - 1;
    if (x2 < rows)
        endRow = x2 + 1;
    
    mat += (startRow - 1) * cols;
    for (int i = startRow; i <= endRow; i++)
    {
        for (int j = startCol; j <= endCol; j++,mat++){
            if (*(mat))
                return 0;
        }
        mat += cols - startCol;
    }

    return 1;
}


void addHorizontalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    mat += (x1 - 1)*cols + (y1 - 1);
    for (int i = 0; i < y2 - y1; i++,mat++)
    {
        *(mat) = 1;
    }
}

void addVerticalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    mat += (x1 - 1)*cols + (y1 - 1);
    for (int i = 0; i < x2 - x1; i++,mat+=cols)
    {
        *(mat) = 1;
    }
}

int getLine(int* mat, int cols, int rows, int* x1, int* y1, int* x2, int* y2)
{
    printf("Enter start and end points in mat (x1,y1,x2,y2):\n");
    scanf("%d", x1);
    scanf("%d", y1);
    scanf("%d", x2);
    scanf("%d", y2);

    return checkLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2);
    if (*x1 == *x2 && *y1 < *y2)
    {
        if (checkLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2))
        {
            addHorizontalLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2);
            return 1;
        }       
    }

    else if (*x1 < *x2 && *y1 == *y2)
    {
        if (checkLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2))
        {
            addVerticalLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2);
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
                if (x1 == x2 && y1 < y2)
                {  
                    addHorizontalLine((int*)mat,cols,rows,x1,y1,x2,y2);     
                }

                else if (x1 < x2 && y1 == y2)
                {
                    addVerticalLine((int*)mat,cols,rows,x1,y1,x2,y2);
                }
                printf("Line Added!");
            }
            else
                printf("Line can't be added!");
            count += res;
            break;

        case 'n':
            break;
        }
    } while (option != 'n');

    return count;
}


int initMatSize(int maxRows, int maxCols,int* cols, int* rows)
{
    printf("Enter rows and cols number:\n");
    scanf("%d", rows);
    scanf("%d", cols);

    if (*rows > maxRows || *cols > maxCols || *rows < 1 || *cols < 1)
    {
        printf("Error, number of rows or cols is invalid!");
        return 0;
    }
    return 1;
}

void addLines()
{
    int rows,cols, res = 0;
    int mat[ROWS][COLS] = {0};

    while (!res){
        res = initMatSize(ROWS,COLS,&cols,&rows);
    }


    printf("Number of lines is %d",countLines((int*)mat,cols,rows));
}