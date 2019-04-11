#include "move.h"

int RockTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = (tx - fx), y = (ty - fy), k = 1, i;
    if (x == 0) {
        if (y < 0)
            k = -k;
        if (abs(y) > 1) {
            for (i = fy + k; i != ty; i += k) {
                if (a[fx][i] != '.')
                    return 3;
            }
        }
        if (a[tx][ty] == '.' && !atk)
            return 1;
        if (a[tx][ty] != '.' && atk
            && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
            return 1;
    } else if (y == 0) {
        if (x < 0)
            k = -k;
        if (abs(x) > 1) {
            for (i = fx + k; i != tx; i += k) {
                if (a[i][fy] != '.')
                    return 3;
            }
        }

        if (a[tx][ty] == '.' && !atk)
            return 1;
        else if (
                a[tx][ty] != '.' && atk
                && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
            return 1;
        else
            return 2;
    } else
        return 0;
    return 0;
}

int BishopTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = (tx - fx), y = (ty - fy), kx = 1, ky = 1, i = fx, j = fy;
    if (abs(x) != abs(y))
        return 0;
    if (x < 0)
        kx = -kx;
    if (y < 0)
        ky = -ky;
    while (i != tx - kx) {
        i += kx;
        j += ky;
        if (a[i][j] != '.')
            return 0;
    }
    if (a[tx][ty] == '.' && !atk)
        return 1;
    else if (
            a[tx][ty] != '.' && atk
            && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
        return 1;
    else
        return 2;
    return 0;
}

int KnightTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = abs(tx - fx), y = abs(ty - fy);
    if (x == 2 && y == 1 && a[tx][ty] == '.' && !atk)
        return 1;
    else if (x == 1 && y == 2 && a[tx][ty] == '.' && !atk)
        return 1;
    else if (
            x == 2 && y == 1 && a[tx][ty] != '.' && atk
            && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
        return 1;
    else if (
            x == 1 && y == 2 && a[tx][ty] != '.' && atk
            && ((wb && a[tx][ty] > 97) || (!wb && a[tx][ty] < 97)))
        return 1;
    else
        return 2;
    return 0;
}

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
