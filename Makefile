# Makefile rmatrix
CC=gcc
CFLAGS=-s -w -Os -lcurses
PREFIX=$(HOME)
CFILES=		rmatrix rmatrixb rain/rain
rmatrix:
		$(CC) $(CFLAGS) -o rmatrix rmatrix.c
		$(CC) $(CFLAGS) -o rmatrixb rmatrixb.c
		$(CC) $(CFLAGS) -o rain/rain rain/rain.c
clean:		
		rm rmatrix rmatrixb rain/rain
install:	
		cp $(CFILES) $(PREFIX)/bin/

