#include "check.h"

void Check(char board[8][8], char* s, char* sw, char* sb, int bcheck[8][8])
{
    int move = 0;
    int attackW = 0;
    int attackB = 0;
    int rk = 0;
    // int takeAccros = 0;
    int mat = 0;
    char fw, fb;
    char fromxw, fromyw, toxw, toyw, fromxb, fromyb, toxb, toyb;

    switch (strlen(sw)) {
    case 3:
        if (strcmp(sw, "O-O") == 0) {
            rk = 1;
        }
        break;
    case 4:
        if (strcmp(sw, "O-O#") == 0) {
            rk = 1;
        } else if (strcmp(sw, "O-O+") == 0) {
            rk = 1;
        }
        break;
    case 5:
        if (strcmp(sw, "O-O-O") == 0) {
            rk = 1;
            break;
        } else if (sw[0] >= 'a' && sw[0] <= 'h')
            fromyw = sw[0];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[0]);
            exit(1);
        }
        if (sw[1] >= '1' && sw[1] <= '8')
            fromxw = sw[1];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[1]);
            exit(1);
        }
        if (sw[2] == '-')
            attackW = 0;
        else if (sw[2] == 'x')
            attackW = 1;
        else {
            printf("ERROR expected x or - found %c\n", sw[2]);
            exit(1);
        }
        if (sw[3] >= 'a' && sw[3] <= 'h')
            toyw = sw[3];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[3]);
            exit(1);
        }
        if (sw[4] >= '1' && sw[4] <= '8')
            toxw = sw[4];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[4]);
            exit(1);
        }
        fw = 'P';
        break;
    case 6: // type 2
        if (strcmp(sw, "O-O-O#") == 0) {
            rk = 1;
            mat = 1;
            break;
        } else if (strcmp(sw, "O-O-O+") == 0) {
            rk = 1;
            break;
        } else if (
                sw[0] == 'K' || sw[0] == 'Q' || sw[0] == 'R' || sw[0] == 'N'
                || sw[0] == 'B' || sw[0] == 'P')
            fw = sw[0];
        else {
            printf("ERROR expected K Q R N B P found %c\n", sw[0]);
            exit(1);
        }
        if (sw[1] >= 'a' && sw[1] <= 'h')
            fromyw = sw[1];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[1]);
            exit(1);
        }
        if (sw[2] >= '1' && sw[2] <= '8')
            fromxw = sw[2];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[2]);
            exit(1);
        }
        if (sw[3] == '-')
            attackW = 0;
        else if (sw[3] == 'x')
            attackW = 1;
        else {
            printf("ERROR expected x or - found %c\n", sw[3]);
            exit(1);
        }
        if (sw[4] >= 'a' && sw[4] <= 'h')
            toyw = sw[4];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[4]);
            exit(1);
        }
        if (sw[5] >= '1' && sw[5] <= '8')
            toxw = sw[5];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[5]);
            exit(1);
        }
        break;
    case 7:
        if (sw[0] == 'K' || sw[0] == 'Q' || sw[0] == 'R' || sw[0] == 'N'
            || sw[0] == 'B' || sw[0] == 'P')
            fw = sw[0];
        else {
            printf("ERROR expected K Q R N B P found %c\n", sw[0]);
            exit(1);
        }
        if (sw[1] >= 'a' && sw[1] <= 'h')
            fromyw = sw[1];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[1]);
            exit(1);
        }
        if (sw[2] >= '1' && sw[2] <= '8')
            fromxw = sw[2];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[2]);
            exit(1);
        }
        if (sw[3] == '-')
            attackW = 0;
        else if (sw[3] == 'x')
            attackW = 1;
        else {
            printf("ERROR expected x or - found %c\n", sw[3]);
            exit(1);
        }
        if (sw[4] >= 'a' && sw[4] <= 'h')
            toyw = sw[4];
        else {
            printf("ERROR expected a b c d e f g h found %c\n", sw[4]);
            exit(1);
        }
        if (sw[5] >= '1' && sw[5] <= '8')
            toxw = sw[5];
        else {
            printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sw[5]);
            exit(1);
        }
        if (sw[6] == '#')
            mat = 1;
        break;
    }
    // Black
    if (!mat) {
        switch (strlen(sb)) {
        case 3:
            if (strcmp(sb, "O-O") == 0) {
                rk = 1;
                break;
            }
        case 4:
            if (strcmp(sb, "O-O#") == 0) {
                rk = 1;
            } else if (strcmp(sb, "O-O+") == 0) {
                rk = 1;
            }
            break;
        case 5:
            if (strcmp(sb, "O-O-O") == 0) {
                rk = 1;
                break;
            } else if (sb[0] >= 'a' && sb[0] <= 'h')
                fromyb = sb[0];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[0]);
                exit(1);
            }
            if (sb[1] >= '1' && sb[1] <= '8')
                fromxb = sb[1];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[1]);
                exit(1);
            }
            if (sb[2] == '-')
                attackB = 0;
            else if (sb[2] == 'x')
                attackB = 1;
            else {
                printf("ERROR expected x or - found %c\n", sb[2]);
                exit(1);
            }
            if (sb[3] >= 'a' && sb[3] <= 'h')
                toyb = sb[3];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[3]);
                exit(1);
            }
            if (sb[4] >= '1' && sb[4] <= '8')
                toxb = sb[4];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[4]);
                exit(1);
            }
            fb = 'p';
            break;
        case 6: // type 2
            if (strcmp(sb, "O-O-O#") == 0) {
                rk = 1;
                mat = 1;
                break;
            } else if (strcmp(sb, "O-O-O+") == 0) {
                rk = 1;
                break;
            } else if (
                    sb[0] == 'K' || sb[0] == 'Q' || sb[0] == 'R' || sb[0] == 'N'
                    || sb[0] == 'B' || sb[0] == 'P')
                fb = sb[0] + 32;
            else {
                printf("ERROR expected K Q R N B P found %c\n", sb[0]);
                exit(1);
            }
            if (sb[1] >= 'a' && sb[1] <= 'h')
                fromyb = sb[1];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[1]);
                exit(1);
            }
            if (sb[2] >= '1' && sb[2] <= '8')
                fromxb = sb[2];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[2]);
                exit(1);
            }
            if (sb[3] == '-')
                attackB = 0;
            else if (sb[3] == 'x')
                attackB = 1;
            else {
                printf("ERROR expected x or - found %c\n", sb[3]);
                exit(1);
            }
            if (sb[4] >= 'a' && sb[4] <= 'h')
                toyb = sb[4];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[4]);
                exit(1);
            }
            if (sb[5] >= '1' && sb[5] <= '8')
                toxb = sb[5];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[5]);
                exit(1);
            }
            break;
        case 7:
            if (sb[0] == 'K' || sb[0] == 'Q' || sb[0] == 'R' || sb[0] == 'N'
                || sb[0] == 'B' || sb[0] == 'P')
                fb = sb[0] + 32;
            else {
                printf("ERROR expected K Q R N B P found %c\n", sb[0]);
                exit(1);
            }
            if (sb[1] >= 'a' && sb[1] <= 'h')
                fromyb = sb[1];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[1]);
                exit(1);
            }
            if (sb[2] >= '1' && sb[2] <= '8')
                fromxb = sb[2];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[2]);
                exit(1);
            }
            if (sb[3] == '-')
                attackB = 0;
            else if (sb[3] == 'x')
                attackB = 1;
            else {
                printf("ERROR expected x or - found %c\n", sb[3]);
                exit(1);
            }
            if (sb[4] >= 'a' && sb[4] <= 'h')
                toyb = sb[4];
            else {
                printf("ERROR expected a b c d e f g h found %c\n", sb[4]);
                exit(1);
            }
            if (sb[5] >= '1' && sb[5] <= '8')
                toxb = sb[5];
            else {
                printf("ERROR expected 1 2 3 4 5 6 7 8 found %c\n", sb[5]);
                exit(1);
            }
            break;
        }
    }
    if (strlen(sw) != 0) {
        int x = fromxw - 48, y = fromyw - 96, xt = toxw - 48, yt = toyw - 96;
        x = 8 - x;
        y--;
        xt = 8 - xt;
        yt--;
        if (rk == 1) {
            if (LongRock(board, bcheck, 1)) {
                move = 4;
            }
            if (ShortRock(board, bcheck, 1)) {
                move = 4;
            }
        } else if (fw == board[x][y]) {
            switch (fw) {
            case 'N':
                move = KnightTest(board, x, y, xt, yt, attackW, 1);
                break;
            case 'B':
                move = BishopTest(board, x, y, xt, yt, attackW, 1);
                break;
            case 'Q':
                move = QueenTest(board, x, y, xt, yt, attackW, 1);
                break;
            case 'K':
                move = KingTest(board, x, y, xt, yt, attackW, 1);
                break;
            case 'R':
                move = RookTest(board, x, y, xt, yt, attackW, 1);
                break;
            case 'P':
                move = PawnTest(board, bcheck, x, y, xt, yt, attackW, 1);
                break;
            }
        } else {
            printf("ERROR false figure %c expected %c in string %s%s\n",
                   board[x][y],
                   fw,
                   s,
                   sw);
            exit(1);
        }
        switch (move) {
        case 0:
            printf("ERROR wrong move in string %s%s\n", s, sw);
            break;
        case 1:
            board[x][y] = '.';
            board[xt][yt] = fw;
            bcheck[x][y] = 0;
            bcheck[xt][yt] = 0;
            break;
        case 2:
            printf("ERROR wrong move or attack  in string %s%s\n", s, sw);
            break;
        case 3:
            printf("ERROR on path find enemy  in string %s%s\n", s, sw);
            break;
        case 5:
            printf("ERROR wrong order of move in string %s%s\n", s, sw);
            break;
        case 6:
            printf("ERROR wrong move of Pawn in string %s%s\n", s, sw);
            break;
        }
        outputHTML(board, s, sw);
    }
    if (strlen(sb) != 0) {
        move = 0;
        int x = fromxb - 48, y = fromyb - 96, xt = toxb - 48, yt = toyb - 96;
        x = 8 - x;
        y--;
        xt = 8 - xt;
        yt--;
        if (rk == 1) {
            if (LongRock(board, bcheck, 0)) {
                move = 4;
            }
            if (ShortRock(board, bcheck, 0)) {
                move = 4;
            }
        } else if (fb == board[x][y]) {
            switch (fb) {
            case 'n':
                move = KnightTest(board, x, y, xt, yt, attackB, 0);
                break;
            case 'b':
                move = BishopTest(board, x, y, xt, yt, attackB, 0);
                break;
            case 'q':
                move = QueenTest(board, x, y, xt, yt, attackB, 0);
                break;
            case 'k':
                move = KingTest(board, x, y, xt, yt, attackB, 0);
                break;
            case 'r':
                move = RookTest(board, x, y, xt, yt, attackB, 0);
                break;
            case 'p':
                move = PawnTest(board, bcheck, x, y, xt, yt, attackB, 0);
                break;
            }
        } else {
            printf("ERROR false figure %c expected %c in string %s%s\n",
                   board[x][y],
                   fb,
                   s,
                   sb);
            exit(1);
        }
        switch (move) {
        case 0:
            printf("ERROR wrong move in string %s%s\n", s, sb);
            break;
        case 1:
            board[x][y] = '.';
            board[xt][yt] = fb;
            bcheck[x][y] = 0;
            bcheck[xt][yt] = 0;
            break;
        case 2:
            printf("ERROR wrong move or attack in string %s%s\n", s, sb);
            break;
        case 3:
            printf("ERROR on path find enemy in string %s%s\n", s, sb);
            break;
        case 5:
            printf("ERROR wrong order of move in string %s%s\n", s, sb);
            break;
        case 6:
            printf("ERROR wrong move of Pawn in string %s%s\n", s, sb);
            break;
        }
        outputHTML(board, s, sb);
    }
}