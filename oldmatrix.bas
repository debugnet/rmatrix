RANDOMIZE TIMER
SCREEN 12
WIDTH 80, 60
CLS
SLEEP 2
COLOR 10
lines = 64
DIM y(lines, 4)
initmatrix:
FOR bla = 1 TO lines
y(bla, 1) = -INT(RND * 60)
y(bla, 2) = INT(RND * 60)
y(bla, 3) = INT(RND * 80) + 1
y(bla, 4) = INT(RND * 225) + 31
NEXT bla
FOR k = 0 TO 2000
FOR bla = 1 TO lines
COLOR 10
IF y(bla, 1) > 1 THEN v = SCREEN(y(bla, 1) - 1, y(bla, 3)) ELSE v = SCREEN(60, y(bla, 3))
IF y(bla, 1) > 1 THEN LOCATE y(bla, 1) - 1, y(bla, 3) ELSE LOCATE 60, y(bla, 3)
PRINT CHR$(v);
FOR delay = 0 TO 3
IF INKEY$ <> "" GOTO endmatrix
xa = INT(RND * 60) + 1
ya = INT(RND * 80) + 1
LOCATE xa, ya
IF SCREEN(xa, ya) <> 32 THEN PRINT CHR$(INT(RND * 225) + 31);
NEXT delay
COLOR 15
IF y(bla, 1) < 1 GOTO step1
LOCATE y(bla, 1), y(bla, 3)
PRINT CHR$(y(bla, 4));
step1:
IF y(bla, 2) < 1 GOTO step2
LOCATE y(bla, 2), y(bla, 3)
PRINT " ";
xa = INT(RND * lines)
step2:
IF xa <= bla THEN y(bla, 1) = y(bla, 1) + 1
IF xa <= bla THEN y(bla, 2) = y(bla, 2) + 1
IF xa <= bla THEN y(bla, 4) = INT(RND * 225) + 31
IF y(bla, 1) > 60 THEN y(bla, 1) = -INT(RND * 30)
IF y(bla, 2) > 60 THEN y(bla, 2) = -INT(RND * 2)
IF y(bla, 1) < 1 AND y(bla, 2) < 1 THEN y(bla, 3) = INT(RND * 80) + 1
NEXT bla
NEXT k
CLS
GOTO initmatrix
endmatrix:
SCREEN 0
CLS
SYSTEM

