#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void generateBombs(char[16][16]);
void checkSurroundings(char);
int gameLoss(char);
void printGameBoard(char[16][16]);

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    char gameBoard[16][16] = {};     // Tamanho de um jogo de dificuldade média (40 bombas).
    generateBombs(gameBoard);

    printGameBoard(gameBoard);

    char posicao = gameBoard[0][1];
    checkSurroundings(posicao);


    return 0;
}

void generateBombs(char gameBoard[16][16]) {
    for(int i=0; i<40;i++) {
        int randomLine = rand() % 17;
        int randomColumn = rand() % 17;

        char bombPosition = gameBoard[randomLine][randomColumn];
        if (bombPosition == '0') {
            bombPosition = '!';
        }
        else {
            do {
                int randomLine = rand() % 17;
                int randomColumn = rand() % 17;

                char bombPosition = gameBoard[randomLine][randomColumn];
            } while (bombPosition == '0');

            bombPosition = '!';
        }
    }
}

void checkSurroundings(char position) {
    for (int i=position-1; i<=3; i = i++) {
        char i;
        checkSurroundings(i);
    }
}

//int gameWinner() {}

int gameLoss(char position) {
    if (position == '!') {
        return 1;
    }
    return 0;
}

void printGameBoard(char gameBoard[16][16]) {
    printf("   ");
    for (int i = 0; i < 16; i++) {
        printf("| %d ", i);
    }
    printf("\n");

    for(int i = 0; i < 16; i++) {
        printf(" %d ", i);
        for (int j = 0; j < 16; j++) {
            printf("| %c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}