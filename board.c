#include "values.h"
#include <stdio.h>
#include <limits.h>

//Muesta la cabecera del tablero con una letra por columna
void printHeader(int COL) {
printf("\n");
    char albet[7];
        for (int ch = 'A'; ch <='G'; ch++) {
            printf("|%c", ch);
        }
                printf("|");
}

//Muestra el tablero, la cabecera y se actualiza luego de cada jugada
int printBoard(int board[ROWS][COLUMS]){
    printHeader(COLUMS);
    printf("\n");
    int i;
    for (i = 0; i < ROWS; ++i) {
        int j;
        for (j = 0; j < COLUMS; ++j) {
            printf("|%d", board[i][j]);
            if (j + 1 >= COLUMS) {
                printf("|");
            }
        }
        printf("\n");
    }
    return 0;
}