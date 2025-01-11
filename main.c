#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 15
#define WIN_CONDITION 5

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

bool checkWin(char board[SIZE][SIZE], int row, int col, char symbol) {
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}}; // prawo, dol‚skosnie \, skosnie /
    for (int d = 0; d < 4; d++) {
        int count = 1;
        for (int step = 1; step < WIN_CONDITION; step++) {
            int r = row + step * directions[d][0];
            int c = col + step * directions[d][1];
            if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == symbol) {
                count++;
            } else {
                break;
            }
        }
        for (int step = 1; step < WIN_CONDITION; step++) {
            int r = row - step * directions[d][0];
            int c = col - step * directions[d][1];
            if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == symbol) {
                count++;
            } else {
                break;
            }
        }
        if (count >= WIN_CONDITION) {
            return true;
        }
    }
    return false;
}

int main() {
    char board[SIZE][SIZE];
    initBoard(board);
    char currentPlayer = 'X';
    int moves = 0;

    while (true) {
        system("clear");
        printBoard(board);
        printf("Gracz %c, podaj wiersz i kolumne (np. 3 5): ", currentPlayer);
        int row, col;
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '.') {
            printf("Nieprawidlowy ruch, sprobuj ponownie.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if (checkWin(board, row, col, currentPlayer)) {
            system("clear");
            printBoard(board);
            printf("Gracz %c wygrywa!\n", currentPlayer);
            break;
        }

        if (moves == SIZE * SIZE) {
            printf("Remis!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
