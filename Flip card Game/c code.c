#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // 4x4 grid (8 pairs)
#define TOTAL_PAIRS (SIZE * SIZE / 2)

char *emojis[] = {"😀", "😎", "😂", "😜", "❤", "🔥", "🌟", "🎉"};
char board[SIZE][SIZE];
char display[SIZE][SIZE];

void shuffleBoard() {
    int indexes[SIZE * SIZE] = {0};
    int totalPairs = SIZE * SIZE / 2;
    int used[totalPairs];

    for (int i = 0; i < totalPairs; i++) used[i] = 0;
    srand(time(NULL));

    for (int i = 0; i < SIZE * SIZE; i++) {
        int idx;
        do {
            idx = rand() % totalPairs;
        } while (used[idx] >= 2);
        used[idx]++;
        board[i / SIZE][i % SIZE] = idx;
        display[i / SIZE][i % SIZE] = '*';
    }
}

void printBoard() {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == '*')
                printf(" %c  ", '*');
            else
                printf(" %s  ", emojis[board[i][j]]);
        }
        printf("\n");
    }
}

void playGame() {
    int x1, y1, x2, y2, matchesP1 = 0, matchesP2 = 0;
char P1[10],P2[10];
printf("\nPlayer 1:");
scanf("%s ",P1);
printf("\nPlayer :");
scanf("%s ",P2);
    int currentPlayer = 1;

    while ((matchesP1 + matchesP2) < TOTAL_PAIRS) {
        printBoard();
        if(currentPlayer==1)
           printf("\nPlayer %d %s's turn\n", currentPlayer,P1);
        else
           printf("\nPlayer %d %s's turn\n", currentPlayer,P2);
        
        printf("Enter first card position (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter second card position (row and column): ");
        scanf("%d %d", &x2, &y2);

        if (board[x1][y1] == board[x2][y2] && (x1 != x2 || y1 != y2)) {
            display[x1][y1] = board[x1][y1];
            display[x2][y2] = board[x2][y2];
            printf("Match found!\n");

            if (currentPlayer ==1)
                matchesP1++;
            else
                matchesP2++;
        } else {
            printf("No match! .\n");
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    printf("\nGame Over!\n");
    if (matchesP1 > matchesP2)
        printf("Player %sWins with %d matches!\n", P1,matchesP1);
    else if (matchesP2 > matchesP1)
        printf("Player %s Wins with %d matches!\n", P2,matchesP2);
    else
        printf("It's a Tie!\n");
}

int main() {
    shuffleBoard();
    playGame();
    return 0;
}