#include "move.h"

int RockTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = (tx - fx), y = (ty - fy), k = 1, i;
    if (x == 0) {
        if (y < 0)
            k = -k;
        if (abs(y) > 1) {
            for (i = fy + k; i != ty - k; i += k) {
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
            for (i = fx + k; i != tx - k; i += k) {
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

int QueenTest(char a[][8], int fx, int fy, int tx, int ty, int atk, int wb)
{
    int x = (tx - fx), y = (ty - fy), k = 1, kx = 1, ky = 1, i, j;
    if (x == 0) {
        if (y < 0)
            k = -k;
        if (abs(y) > 1) {
            for (i = fy + k; i != ty - k; i += k) {
                if (a[fx][i] != '.')
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
    } else if (y == 0) {
        if (x < 0)
            k = -k;
        if (abs(x) > 1) {
            for (i = fx + k; i != tx - k; i += k) {
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
    } else if (abs(x) == abs(y)) {
        if (x < 0)
            kx = -kx; //-1
        if (y < 0)
            ky = -ky; //-1
        i = fx;
        j = fy;
        while (i != tx - kx && j != ty - ky) {
            i += kx;
            j += ky;
            if (a[i][j] != '.')
                return 3;
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

int LongRock(char a[][8], int b[][8], int wb)
{
    if (wb) {
        if (b[7][4] == 1 && a[7][4] == 'K' && b[7][0] == 1 && a[7][0] == 'R'
            && a[7][3] != '.' && a[7][2] != '.' && a[7][1] != '.') {
            b[7][4] = 0;
            b[7][0] = 0;
            a[7][2] = 'K';
            a[7][3] = 'R';
            a[7][4] = '.';
            a[7][0] = '.';
            return 1;
        }
    } else {
        if (b[0][4] == 1 && a[0][4] == 'k' && b[0][0] == 1 && a[0][0] == 'r'
            && a[0][3] == '.' && a[0][2] == '.' && a[0][1] == '.') {
            b[0][4] = 0;
            b[0][0] = 0;
            a[0][2] = 'k';
            a[0][3] = 'r';
            a[0][4] = '.';
            a[0][0] = '.';
            return 1;
        }
    }
    return 0;
}
int ShortRock(char a[][8], int b[][8], int wb)
{
    if (wb) {
        if (b[7][4] == 1 && a[7][4] == 'K' && b[7][7] == 1 && a[7][7] == 'R'
            && a[7][6] == '.' && a[7][5] == '.') {
            b[7][4] = 0;
            b[7][7] = 0;
            a[7][6] = 'K';
            a[7][5] = 'R';
            a[7][4] = '.';
            a[7][7] = '.';
            return 1;
        }
    } else {
        if (b[0][4] == 1 && a[0][4] == 'k' && b[0][7] == 1 && a[0][7] == 'r'
            && a[0][6] == '.' && a[0][5] == '.') {
            b[0][4] = 0;
            b[0][7] = 0;
            a[0][6] = 'k';
            a[0][5] = 'r';
            a[0][4] = '.';
            a[0][7] = '.';
            return 1;
        }
    }
    return 0;
}