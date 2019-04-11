#include "move.h"

int KingTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    if (a[tx][ty] == '.' && !atk)
        return 1;
    if (a[tx][ty] != '.' && atk
        && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
        return 1;
    else
        return 2;
    return 0;
}

int PawnTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = (tx - fx), y = (ty - fy), k = 1;
    if (x > 0 && wb)
        return 0;
    else if (x < 0 && !wb)
        return 0;
    if (abs(x) == 1 && !atk && y == 0) {
        if (a[tx][ty] == '.')
            return 1;
    }
    if (x < 0)
        k = -k;
    if (abs(x) == 2 && !atk && y == 0) {
        if (a[tx - k][ty] != '.')
            return 3;
        if (a[tx][ty] == '.')
            return 1;
        else
            return 3;
    }
    if (atk && abs(x) == 1 && abs(y) == 1 && a[tx][ty] != '.'
        && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
        return 1;
    return 0;
}
