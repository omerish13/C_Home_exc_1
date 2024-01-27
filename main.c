
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "sudoku.h"
#include "pictureLines.h"
#include "pictureManipulation.h"




int main()
{

	char option = 'N';

	printf("\n\n");
	printf("Please choose one of the following options\n");
	printf("S/s - Sudoku\n");
	printf("A/a - All Lines\n");
	printf("P/p - Picture Manipulation\n");
	printf("E/e - Exit\n");

	scanf("%d", &option);
	do
	{
		switch (option)
		{
		case 'S':
		{
			sudokuGame();
			break;
		}
		case 's':
		{
			sudokuGame();
			break;
		}
		case 'A':
		{
			addLines();
			break;
		}
		case 'a':
		{
			addLines();
			break;
		}
		case 'P':
		{
			pictureManipulation();
			break;
		}
		case 'p':
		{
			pictureManipulation();
			break;
		}

		case 'E':
			break;
		case 'e':
			break;
		}
	} while (option != 'E' && option != 'e');
	
}
