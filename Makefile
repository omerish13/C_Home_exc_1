CC = gcc
OBJS = main.o sudoku.o pictureLines.o pictureManipulation.o matrix.o
EXEC = demo
DEBUG = -g
CFLAGS = -Wall -Werror $(DEBUG)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

matrix.o: matrix.c matrix.h
pictureLines.o: pictureLines.c pictureLines.h matrix.h
pictureManipulation.o: pictureManipulation.c pictureManipulation.h matrix.h
sudoku.o: sudoku.c sudoku.h matrix.h



clean:
	rm -f $(OBJS) $(EXEC)
