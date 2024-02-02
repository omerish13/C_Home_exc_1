#ifndef __SUDOKU__
#define __SUDOKU__

void sudokuGame();
int initBoardSize(int maxSize,int* size);
void initBoard(int* mat, int size, int elemnts);
void showBoard(const int* mat, int size);
int checkBoard(const int* mat, int size);
int checkRow(const int* mat,int* arr,int size, int cell);
int checkCol(const int* mat,int* arr,int size, int cell);
int checkSquare(const int* mat,int* arr,int size, int cell);


#endif