//El tamaño del tablero se modifica con los valores de ROWS y COLUMNS
#include <string>
#include <iostream>
using namespace std;

#define ROWS 6
#define COLUMS 7
#define INF INT_MAX //El valor máximo y mínimo que puede tomar cada extremo es el infinito, se usa durante el cálculo de movimientos de la CPU

//main.c
int main();
//board.c
void printHeader(int COL);
int printBoard(int board[ROWS][COLUMS]);
//game.c
int game(int option, int number);
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
int recordWinner(int winner,int& pointsPlayer,int& pointsCPU);
void recordMatch(int board[ROWS][COLUMS],const string& fileName,const string& difficulty,const string& winnerofMatch,int numberofMatch);
int readParameters(const string& fileName, int& pointsPlayer, int& pointsCPU,int& numberofMatch);
void recordParameters(const string& fileName, int pointsPlayer, int pointsCPU,int numberofMatch);