#include "values.h"
#include <stdio.h>
#include <limits.h>

//Lógica minimax que tuliza el tablero de juego, nivel de complejidad, rol maximin para el jugador, factores alpha y beta para el PODA
int minimax(int board[ROWS][COLUMS], int depth, int maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || isGameOver(board, 1) || isGameOver(board, 2)) { //En caso se programe con un nivel de dificultad = 0 o esté en una situación,
        return evaluatePosition(board, 2) - evaluatePosition(board, 1); // la CPU no tendrá opciones a explorar 
    }

    if (maximizingPlayer) { //Comienza la evaluación del valor max del nodo para alpha, comparando los factores alpha y beta
        int maxEval = -INF;

        for (int col = 0; col < COLUMS; ++col) {
            if (!isColumnFull(board, col)) {
                makeMove(board, col, 2);
                int eval = minimax(board, depth - 1, 0, alpha, beta);
                maxEval = maxEval > eval ? maxEval : eval;
                undoMove(board, col);

                alpha = alpha > eval ? alpha : eval; //Compara el valor que toma alpha del nodo padre con los alpha de los siguientes nodos

                if (beta <= alpha) { //En cuanto detecta que un Alpha es mayor que Beta, se queda con dicho valor
                    break;
                }
            }
        }

        return maxEval; //Retorna el mayor valor obtenido
    } else {
        int minEval = INF; //En su contraparte, aquí se evalúa el menor valor que puede tomar el factor beta

        for (int col = 0; col < COLUMS; ++col) {
            if (!isColumnFull(board, col)) {
                makeMove(board, col, 1);
                int eval = minimax(board, depth - 1, 1, alpha, beta);
                minEval = minEval < eval ? minEval : eval;
                undoMove(board, col);

                beta = beta < eval ? beta : eval; //Compara el valor que toma beta del nodo padre con los beta de los siguientes nodos

                if (beta <= alpha) { //En cuanto detecta que un Beta es menor que Alpha, se queda con dicho valor
                    break;
                }
            }
        }

        return minEval; //Retorna el menor valor obtenido
    }
}
int evaluatePosition(int board[ROWS][COLUMS], int player) {
    int score = 0;

    // Evaluar filas y columnas para determina el puntaje que tiene jugador y CPU, determinando una posible victoria inminente dependiendo del tablero actual
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; ++k) {
                if (board[i][j + k] == player) {
                    countPlayer++;
                } else if (board[i][j + k] != 0) {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                score += 1000;
            } else if (countPlayer == 3 && countOpponent == 0) {
                score += 100;
            } else if (countPlayer == 2 && countOpponent == 0) {
                score += 10;
            } else if (countPlayer == 1 && countOpponent == 0) {
                score += 1;
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLUMS; ++j) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j] == player) {
                    countPlayer++;
                } else if (board[i + k][j] != 0) {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                score += 1000;
            } else if (countPlayer == 3 && countOpponent == 0) {
                score += 100;
            } else if (countPlayer == 2 && countOpponent == 0) {
                score += 10;
            } else if (countPlayer == 1 && countOpponent == 0) {
                score += 1;
            }
        }
    }

    // Se realiza el mismo análisis de las filas y columnas pero en este caso, de manera diagonal
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j + k] == player) {
                    countPlayer++;
                } else if (board[i + k][j + k] != 0) {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                score += 1000;
            } else if (countPlayer == 3 && countOpponent == 0) {
                score += 100;
            } else if (countPlayer == 2 && countOpponent == 0) {
                score += 10;
            } else if (countPlayer == 1 && countOpponent == 0) {
                score += 1;
            }
        }
    }

    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLUMS - 4; ++j) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; ++k) {
                if (board[i - k][j + k] == player) {
                    countPlayer++;
                } else if (board[i - k][j + k] != 0) {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                score += 1000;
            } else if (countPlayer == 3 && countOpponent == 0) {
                score += 100;
            } else if (countPlayer == 2 && countOpponent == 0) {
                score += 10;
            } else if (countPlayer == 1 && countOpponent == 0) {
                score += 1;
            }
        }
    }

    return score;
}