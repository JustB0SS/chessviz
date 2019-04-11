#ifndef CHECK_H
#define CHECK_H

#include "board_print_html.h"
#include "move.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

void Check(char board[8][8], char* s, char* sw, char* sb, int bcheck[8][8]);

#endif