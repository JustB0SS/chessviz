#ifndef MOVE_H
#define MOVE_H

#include "board_print_html.h"
#include "check.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int RockTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb);
int KnightTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb);
int BishopTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb);
int QueenTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb);
int KingTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb);
int PawnTest(
        char a[][8],
        int b[][8],
        int fx,
        int fy,
        int tx,
        int ty,
        int atk,
        int wb);
int LongRock(char a[][8], int b[][8], int wb);
int ShortRock(char a[][8], int b[][8], int wb);

#endif
