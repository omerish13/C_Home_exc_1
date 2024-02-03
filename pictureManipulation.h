#ifndef __PICTUREMANIPULATION__
#define __PICTUREMANIPULATION__

void pictureManipulation();
void initPictureSize(int maxSize, int* matSize);
void initMatrix(int* mat,int size, int minNum, int maxNum);
void rotateClockwise(int* mat, int size);
void rotateCounterClockwise(int* mat, int size);
void FlipHorizontal(int* mat, int size);
void FlipVertical(int* mat, int size);

#endif