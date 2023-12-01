#include "values.h"
#include <stdio.h>
#include <limits.h>

//Evalúa si la columna ya no puede recibir más valores
int isColumnFull(int board[ROWS][COLUMS], int col) {
    return board[0][col] != 0;
}

//Coloca la ficha de cada jugador en la posición seleccionada
void makeMove(int board[ROWS][COLUMS], int col, int player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == 0) {
            board[i][col] = player;
            break;
        }
    }
}

//Permite al CPU replantear su jugada
void undoMove(int board[ROWS][COLUMS], int col) {
    for (int i = 0; i < ROWS; ++i) {
        if (board[i][col] != 0) {
            board[i][col] = 0;
            break;
        }
    }
}

//Permite a la CPU evaluar su siguiente jugada, basándose en el estado actual del tablero y sus posibilidades 
int cpuMove(int board[ROWS][COLUMS], int depth) {
    int bestMove = -1;
    int maxEval = -INF;
    int alpha = -INF;
    int beta = INF;

    for (int col = 0; col < COLUMS; ++col) {
        if (!isColumnFull(board, col)) {
            makeMove(board, col, 2);
            int eval = minimax(board, depth, 0, alpha, beta);  //Utiliza el algoritmo minimax elaborado
            undoMove(board, col); //En caso la jugada no le ayude a la CPU, regresa y explora otras opciones

            if (eval > maxEval) {
                maxEval = eval;
                bestMove = col;
            }
        }
    }

    return bestMove;
}