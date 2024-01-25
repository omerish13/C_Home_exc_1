CC = gcc
OBJS = main.o sudoku.o pictureLines.o
EXEC = demo
DEBUG = -g
CFLAGS = -Wall -Werror $(DEBUG)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

main.o: main.c sudoku.h pictureLines.h
pictureLines.o: pictureLines.c pictureLines.h
sudoku.o: sudoku.c sudoku.h



clean:
	rm -f $(OBJS) $(EXEC)
