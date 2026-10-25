# Makefile rmatrix
CC=gcc
CFLAGS=-w -s -Os -lcurses
CFLAGS2=-w -s -Os
PREFIX=$(HOME)
CFILES=		rmatrix rmatrixb rain/rain ematrix kmatrix
rmatrix:
		$(CC) -o rmatrix rmatrix.c $(CFLAGS)
		$(CC) -o rmatrixb rmatrixb.c $(CFLAGS)
		$(CC) -o rain/rain rain/rain.c $(CFLAGS)
		$(CC) -o ematrix ematrix.c $(CFLAGS2)
		$(CC) -o kmatrix kmatrix.c $(CFLAGS2)
debug:
		$(CC) -o rmatrix rmatrix.c -lcurses
		$(CC) -o rmatrixb rmatrixb.c -lcurses
		$(CC) -o rain/rain rain/rain.c -lcurses
		$(CC) -o ematrix ematrix.c
		$(CC) -o kmatrix kmatrix.c
clean:		
		rm rmatrix rmatrixb rain/rain ematrix kmatrix
install:	rmatrix rmatrixb rain/rain ematrix kmatrix
		cp $(CFILES) $(PREFIX)/bin/

