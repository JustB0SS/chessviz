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

    FILE* input;
    switch (argc) {
    case 1:
        while (1) {
            // getline()
        }
        break;
    case 2:
        input = fopen(argv[1], "a+");
        while (!feof(input)) {
            char sw[10], sb[10], str[2];
            fscanf(input, "%s %s %s", str, sw, sb);
            if (strlen(sw) > 0 && strlen(sb) > 0 && strlen(str) > 0)
                Check(board, str, sw, sb, bcheck);
        }
        break;
    default:
        printf("ERROR");
        return 1;
    }
    fclose(input);
    return 0;
}