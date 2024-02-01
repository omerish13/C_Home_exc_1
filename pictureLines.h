#ifndef __PICTURELINES__
#define __PICTURELINES__

void addLines();
void initMatSize(int maxRows, int maxCols,int* cols, int* rows);
void showPicture(const int* mat, int cols, int rows);
int countLines(int* mat, int cols, int rows);
int getLine(int* mat, int cols, int rows, int* x1, int* y1, int* x2, int* y2);
int checkLine(const int* mat, int cols, int rows, int x1, int y1, int x2, int y2);
void addHorizontalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2);
void addVerticalLine(int* mat, int cols, int rows, int x1, int y1, int x2, int y2);

#endif