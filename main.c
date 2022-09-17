#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    char gameBoard[16][16];     // Tamanho de um jogo de dificuldade média (40 bombas).
    generateBombs(gameBoard);

    char posicao = gameBoard[0][1];
    checkSurroundings(posicao);


    return 0;
}

void generateBombs(char *gameBoard[]) {
    
    for(int i=0; i<40;i++) {
        int randomLine = rand() % 17;
        int randomColumn = rand() % 17;

        char bombPosition = gameBoard[randomLine][randomColumn];
        if (bombPosition == NULL) {
            bombPosition = '!';
        }
        else {
            do {
                int randomLine = rand() % 17;
                int randomColumn = rand() % 17;

                char bombPosition = gameBoard[randomLine][randomColumn];
            } while (bombPosition != NULL);

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

int gameWinner() {}

int gameLoss(char position) {
    if (position == '!') {
        return 1;
    }
    return 0;
}