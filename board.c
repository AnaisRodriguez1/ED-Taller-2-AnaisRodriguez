#include "values.h"
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;


//Muesta la cabecera del tablero con una letra por columna
void printHeader(int COL) {
cout<<"\n";
    char albet[7];
        for (char ch = 'A'; ch <='G'; ch++) {
            cout<<"|" << ch;
        }
                cout<<"|";
}

//Muestra el tablero, la cabecera y se actualiza luego de cada jugada
int printBoard(int board[ROWS][COLUMS]){
    printHeader(COLUMS);
    cout<<"\n";
    int i;
    for (i = 0; i < ROWS; ++i) {
        int j;
        for (j = 0; j < COLUMS; ++j) {
            if(board[i][j]==0){
                cout << "| ";
            }else{
                cout<<"|" << board[i][j];
            }
            if (j + 1 >= COLUMS) {
                cout<<"|";
            }
        }
        cout<<"\n";
    }
    return 0;
}