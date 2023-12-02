#include "values.h"
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

//Valida según el jugador que reciba como parámetro
int isGameOver(int board[ROWS][COLUMS], int player){
       // Verificar filas y columnas
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return 1; // Resultado: Ganador
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLUMS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return 1; // Resultado: Ganador
            }
        }
    }

    // Verificar diagonales
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {;
                return 1; // Resultado: Ganador
            }
        }
    }

    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return 1; // Resultado: Ganador
            }
        }
    }

    // Verificar estado del juego
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMS; ++j) {
            if (board[i][j] == 0) {
                return 0; // Resultado: Juego en curso
            }
        }
    }
return -1; // Resultado: Empate   
}
