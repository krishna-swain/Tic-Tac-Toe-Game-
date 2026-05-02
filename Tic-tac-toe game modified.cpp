#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char board[3][3];
char player1[30], player2[30];
int p1Wins = 0, p2Wins = 0, draws = 0;
void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;
}
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n-----------\n");
    }
    printf("\n");
}
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}
void takeTurn(char playerName[], char symbol) {
    int move;
    while (1) {
        printf("%s, enter your move (1 to 9): ", playerName);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("That spot is already taken. Try again.\n");
            continue;
        } else {
            board[row][col] = symbol;
            break;
        }
    }
}
int main() {
    char playAgain;
    int matchNumber = 1;
    printf("                                   *****************************************\n");
    printf("                                       Welcome  To  Tic - Tac - Toe Game  \n");
    printf("                                   *****************************************\n");
    printf("Enter name for Player 1 (X): ");
    scanf("%s", player1);
    printf("Enter name for Player 2 (O): ");
    scanf("%s", player2);

    do {
        printf("\n======= Match %d =======\n", matchNumber++);
        resetBoard();
        int turn = 0;

        while (1) {
            displayBoard();
            if (turn % 2 == 0)
                takeTurn(player1, 'X');
            else
                takeTurn(player2, 'O');

            if (checkWin()) {
                displayBoard();
                if (turn % 2 == 0) {
                    printf("\n%s wins this match!\n", player1);
                    p1Wins++;
                } else {
                    printf("\n%s wins this match!\n", player2);
                    p2Wins++;
                }
                break;
            }
            if (isDraw()) {
                displayBoard();
                printf("\nThis match is a draw!\n");
                draws++;
                break;
            }

            turn++;
        }

        // Show current results after each match
        printf("\nCurrent Results:\n");
        printf("%s Wins: %d\n", player1, p1Wins);
        printf("%s Wins: %d\n", player2, p2Wins);
        printf("Draws: %d\n", draws);

        printf("\nDo you want to play another match? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! Hope you had fun. See you next time!\n");
    return 0;
}
