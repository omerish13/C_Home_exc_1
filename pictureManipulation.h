#ifndef __PICTUREMANIPULATION__
#define __PICTUREMANIPULATION__

void initMatrix(int* mat,int size);
void rotateClockwise(int* mat, int size);
void rotateCounterClockwise(int* mat, int size);
void FlipVertical(int* mat, int size);
void FlipHorizontal(int* mat, int size);
void pictureManipulation();


#endif