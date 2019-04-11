#include "board_print_html.h"
#include "check.h"
#include "move.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char board[8][8] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };

    int bcheck[8][8] = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1},
    };

    FILE* output_html;
    FILE* input;
    output_html = fopen("chessviz.html", "w+");
    fprintf(output_html, R"( <html>
        <head>
        <title>Chessviz</title>
        <style type="text/css">
        table.chessboard {
          border: 5px solid #333;
          border-collapse: collapse;
          height: 320px;
          margin: 20px;
          width: 320px;
        }
        table.chessboard caption {
          text-align: left;
        }
        table.chessboard td {
          background-color: #fff;
          font-size: 25px;
          height: 40px;
          text-align: center;
          vertical-align: middle;
          width: 40px;
        }
        table.chessboard tr:nth-child(odd) td:nth-child(even),
        table.chessboard tr:nth-child(even) td:nth-child(odd) {
          background-color: #999;
        }
        table.chessboard .white.king:before   { content: "\2654"; }
        table.chessboard .white.queen:before  { content: "\2655"; }
        table.chessboard .white.rook:before   { content: "\2656"; }
        table.chessboard .white.bishop:before { content: "\2657"; }
        table.chessboard .white.knight:before { content: "\2658"; }
        table.chessboard .white.pawn:before   { content: "\2659"; }
        table.chessboard .black.king:before   { content: "\265A"; }
        table.chessboard .black.queen:before  { content: "\265B"; }
        table.chessboard .black.rook:before   { content: "\265C"; }
        table.chessboard .black.bishop:before { content: "\265D"; }
        table.chessboard .black.knight:before { content: "\265E"; }
        table.chessboard .black.pawn:before   { content: "\265F"; }
      </style>
        </head>
        <body>)");
    fclose(output_html);
    char str_start[30] = "start_position";
    char str_num[3] = "0.";
    outputHTML(board, str_num, str_start);
    switch (argc) {
    case 1:
        while (1) {
            // getline()
        }
        break;
    case 2:
        input = fopen(argv[1], "a+");
        while (!feof(input)) {
            char sw[10] = "", sb[10] = "", str[2] = "";
            fscanf(input, "%s %s %s", str, sw, sb);
            Check(board, str, sw, sb, bcheck);
        }
        break;
    default:
        printf("ERROR");
        return 1;
    }
    output_html = fopen("chessviz.html", "a+");
    fprintf(output_html, R"(</body>
        </html>)");
    fclose(input);
    fclose(output_html);
    return 0;
}
