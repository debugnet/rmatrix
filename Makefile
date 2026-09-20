# Makefile rmatrix
CC=gcc
CFLAGS=-w -s -Os -lcurses
CFLAGS2=-w -s -Os
PREFIX=$(HOME)
CFILES=		rmatrix rmatrixb rain/rain
rmatrix:
		$(CC) -o rmatrix rmatrix.c $(CFLAGS)
		$(CC) -o rmatrixb rmatrixb.c $(CFLAGS)
		$(CC) -o rain/rain rain/rain.c $(CFLAGS)
		$(CC) -o ematrix ematrix.c $(CFLAGS2)
debug:
		$(CC) -o rmatrix rmatrix.c -lcurses
		$(CC) -o rmatrixb rmatrixb.c -lcurses
		$(CC) -o rain/rain rain/rain.c -lcurses
		$(CC) -o ematrix ematrix.c
clean:		
		rm rmatrix rmatrixb rain/rain
install:	rmatrix rmatrixb rain/rain
		cp $(CFILES) $(PREFIX)/bin/

