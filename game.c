#include "values.h"
#include <stdio.h>
#include <limits.h>

int game(int modo){
    int board[ROWS][COLUMS] = {0};
    printf("\nEmpieza el juego\n");
    while (!isGameOver(board, 1) && !isGameOver(board, 2)) { //Valida que el juego aún no haya terminado
        if (modo == 1){
            printf("\n   Modo Facil");
            printBoard(board);
            int playerMove;
            printf("\nIngresa tu movimiento (columna del 1 al 7): ");
            scanf("%d", &playerMove);
            int depth = 2;//Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) {//Valida que la columna no se encuentre llena o sea una columna valida
            printf("Movimiento inválido. Ingresa otro movimiento: ");
            scanf("%d", &playerMove);
        }

        makeMove(board, playerMove-1, 1);   //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            printf("Has ganado!\n");    //Valida si se cumplen las condiciones para que el jugador gane
            break;
            }

        int cpu = cpuMove(board,depth); //La CPU analiza en que posición puede colocar su ficha, dependiendo de la jugada anterior y el grado de dificultad
        printf("La CPU hace su movimiento en la columna: %d\n", cpu+1);
        makeMove(board, cpu, 2);    //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            printf("La CPU ha ganado!\n");//Valida si se cumplen las condiciones para que la CPU gane
            break;
        }
        }else if (modo == 2){
            printf("\n   Modo Medio");
            printBoard(board);
            int playerMove;
            printf("\nIngresa tu movimiento (columna del 1 al 7): ");
            scanf("%d", &playerMove);
            int depth = 4; //Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) { //Valida que la columna no se encuentre llena o sea una columna valida
            printf("Movimiento inválido. Ingresa otro movimiento: ");
            scanf("%d", &playerMove);
        }

        makeMove(board, playerMove-1, 1); //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            printf("Has ganado!\n"); //Valida si se cumplen las condiciones para que el jugador gane
        }

        int cpu = cpuMove(board,depth);
        printf("La CPU hace su movimiento en la columna: %d\n", cpu+1);
        makeMove(board, cpu, 2);    //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            printf("La CPU ha ganado!\n"); //Valida si se cumplen las condiciones para que la CPU gane
        }
        }
        else if (modo == 3){
            printf("\n  Modo Dificil");
            printBoard(board);
            int playerMove;
            printf("\nIngresa tu movimiento (columna del 1 al 7): ");
            scanf("%d", &playerMove);
            int depth = 6; //Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) { //Valida que la columna no se encuentre llena o sea una columna valida
            printf("Movimiento inválido. Ingresa otro movimiento: ");
            scanf("%d", &playerMove);
        }

        makeMove(board, playerMove-1, 1); //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            printf("Has ganado!\n"); //Valida si se cumplen las condiciones para que el jugador gane
        }

        int cpu = cpuMove(board,depth);
        printf("La CPU hace su movimiento en la columna: %d\n", cpu+1);
        makeMove(board, cpu, 2); //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            printf("La CPU ha ganado!\n"); //Valida si se cumplen las condiciones para que la CPU gane
        }
        }
    }

}