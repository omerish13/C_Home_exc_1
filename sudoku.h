#ifndef __SUDOKU__
#define __SUDOKU__

int checkRow(const int* mat,int* arr,int size, int cell);
int checkCol(const int* mat,int* arr,int size, int cell);
int checkSquare(const int* mat,int* arr,int size, int cell);
int checkBoard(const int* mat, int size);
void showBoard(const int* mat, int size);
void initBoard(int* mat, int size);
int initBoardSize(int maxSize,int* size);
void sudokuGame();


#endif

