# Makefile rmatrix
CC=gcc
CFLAGS=-s -w -Os -lcurses
PREFIX=$(HOME)
CFILES=		rmatrix.c rmatrixb.c
rmatrix:	$(CFILES)
		$(CC) $(CFLAGS) -o rmatrix rmatrix.c
		$(CC) $(CFLAGS) -o rmatrixb rmatrixb.c
clean:		
		rm rmatrix rmatrixb
install:	
		cp $(CFILES) $(PREFIX)/bin/

