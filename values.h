//El tamaño del tablero se modifica con los valores de ROWS y COLUMNS
#include <string>
#include <iostream>
using namespace std;

#define ROWS 6
#define COLUMS 7
#define INF INT_MAX

//main.c
int main();
//board.c
void printHeader(int COL);
int printBoard(int board[ROWS][COLUMS]);
//game.c
int game(int modo);
//moves.c
int isColumnFull(int board[ROWS][COLUMS], int col);
void makeMove(int board[ROWS][COLUMS], int col, int player);
void undoMove(int board[ROWS][COLUMS], int col);
int cpuMove(int board[ROWS][COLUMS], int depth);
//scores.c
int isGameOver(int board[ROWS][COLUMS], int player);
//minimax.c
int minimax(int board[ROWS][COLUMS], int depth, int maximizingPlayer, int alpha, int beta);
int evaluatePosition(int board[ROWS][COLUMS], int player);
//addons.c
int validateOption();
int displayMenu();
int validatePosition(const string& value);