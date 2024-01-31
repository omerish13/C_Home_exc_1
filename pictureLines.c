#include "pictureLines.h"
#include <stdio.h>

#define ROWS 50
#define COLS 50

int checkLine(const int* mat, int cols, int rows,int x1,int y1, int x2, int y2)
{
    if (y1 > (rows - 1) || y1 < 0 || y2 < 0 || y2 > (rows - 1) || x1 > (cols -1) || x1 < 0 || x2 > (cols - 1) || x2 < 0 || (x1 != x2 && y1 != y2) || x1 > x2 || y1 > y2)
    {
        printf("Line paramaters illigal\n");
        return 0;
    }
    int startCol = x1, endCol = x2, startRow = y1, endRow = y2;
    if (x1 > 0)
        startCol = x1 - 1;
    if (x2 < cols - 1)
        endCol = x2 + 1;
    if (y1 > 0)
        startRow = y1 - 1;
    if (y2 < rows - 1)
        endRow = y2 + 1;
    
    mat += startRow * cols;
    for (int i = startRow; i < endRow; i++)
    {
        for (int j = startCol; j < endCol; j++,mat++)
        {
            if (*(mat))
            {
                printf("Line: %d, %d, %d, %d was not inserted to image\n", x1, y1, x2, y2);
                return 0;
            }
        }
        mat += cols - startCol;
    }

    return 1;
}


void addHorizontalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    mat += y1*cols + x1;
    for (int i = 0; i <= x2 - x1; i++,mat++)
    {
        *(mat) = 1;
    }
}

void addVerticalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2)
{
    mat += y1*cols + x1;
    for (int i = 0; i <= y2 - y1; i++,mat+=cols)
    {
        *(mat) = 1;
    }
}

int getLine(int* mat, int cols, int rows, int* x1, int* y1, int* x2, int* y2)
{
    printf("Insert line parameters x1, y1, x2, y2\n");
    scanf(" %d", x1);
    scanf(" %d", y1);
    scanf(" %d", x2);
    scanf(" %d", y2);

    if (checkLine((int*)mat,cols,rows,*x1,*y1,*x2,*y2))
        return 1;     
    return 0;

}

int countLines(int* mat, int cols, int rows)
{
    int count = 0, x1, x2, y1, y2, res;

    int option = 1;

	

    do {
        switch (option)
        {
        case 1:
            res = getLine((int*)mat,cols,rows,&x1,&y1,&x2,&y2);
            if (res)
            {
                if (x1 == x2 && y1 < y2)
                {  
                    addVerticalLine((int*)mat,cols,rows,x1,y1,x2,y2);     
                }

                else if (x1 < x2 && y1 == y2)
                {
                    addHorizontalLine((int*)mat,cols,rows,x1,y1,x2,y2);
                }
                showPicture((int*)mat, cols, rows);
            }
            count += res;

        case 0:
            break;
        }
	    printf("Do you want to enter a new line? 1 for yes, 0 no\n");

	    scanf(" %d", &option);
    } while (option != 0);

    return count;
}


void initMatSize(int maxRows, int maxCols,int* cols, int* rows)
{
    int res = 0;
    while (res != 1)
    {
        printf("Insert number of rows for big Matrix between 1 and %d\n", maxRows);
        scanf(" %d", rows);
        if (*rows <= maxRows && *rows > 0)
        {
            res = 1;
        }
    }
    res = 0;
    while (res != 1)
    {
        printf("Insert number of columns for big Matrix: between 1 and %d\n", maxCols);
        scanf(" %d", cols);
        if (*cols <= maxCols && *cols > 0)
        {
            res = 1;
        }
    }
 
}

void showPicture(const int* mat, int cols, int rows)
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

void addLines()
{
    int rows,cols;
    int mat[ROWS][COLS] = {0};

    printf("Mat ROWS: %d , COLS: %d\n", ROWS, COLS);

    initMatSize(ROWS,COLS,&cols,&rows);

    printf("Effective size %d*%d\n", rows, cols);

    printf("Final picture after adding %d lines\n", countLines((int*)mat,cols,rows));
    showPicture((int*)mat, cols, rows);
    printf("\n");
}

