#include "values.h"
#include <stdio.h>
#include <limits.h>
#include <string>
#include <iostream>
using namespace std;

int game(int option){
    int board[ROWS][COLUMS] = {0};
    string value;
    int playerMove;
    int score = 0;
    cout <<"\nEmpieza el juego\n";
    while (!isGameOver(board, 1) && !isGameOver(board, 2)) { //Valida que el juego aún no haya terminado
    
        if (option == 1){
            cout <<"\n   Modo Facil";
            printBoard(board);
            cout <<"\nIngresa tu movimiento (columna del 1 al 7): ";
            cin >> value;
            playerMove = validatePosition(value);//Valida que el dato ingresado por la terminal sea válido para la lógica
            int depth = 2;//Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) {//Valida que la columna no se encuentre llena o sea una columna valida
            cout <<"Movimiento invalido. Ingresa otro movimiento: ";
            cin >> value;
            playerMove = validatePosition(value);//Valida que el dato ingresado por la terminal sea válido para la lógicay
        }

        makeMove(board, playerMove-1, 1);   //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            cout <<"\nHas ganado! Juegas denuevo?\n";    //Valida si se cumplen las condiciones para que el jugador gane
            score = 1;
            break;
            }

        int cpu = cpuMove(board,depth); //La CPU analiza en que posición puede colocar su ficha, dependiendo de la jugada anterior y el grado de dificultad
        cout <<"La CPU hace su movimiento en la columna: " << cpu+1 << endl;
        makeMove(board, cpu, 2);    //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            cout <<"\nLa CPU ha ganado! Juegas denuevo?\n";//Valida si se cumplen las condiciones para que la CPU gane
            score = 2;
            break;
        }
        }else if (option == 2){
            cout <<"\n   Modo Medio";
            printBoard(board);
            cout <<"\nIngresa tu movimiento (columna del 1 al 7): ";
            cin >> value;
            playerMove = validatePosition(value); //Valida que el dato ingresado por la terminal sea válido para la lógica
            int depth = 4; //Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) { //Valida que la columna no se encuentre llena o sea una columna valida
            cout <<"Movimiento invalido. Ingresa otro movimiento: ";
            cin >> value;
            playerMove = validatePosition(value); //Valida que el dato ingresado por la terminal sea válido para la lógica
        }

        makeMove(board, playerMove-1, 1); //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            cout <<"\nHas ganado! Juegas denuevo?\n"; //Valida si se cumplen las condiciones para que el jugador gane
        }

        int cpu = cpuMove(board,depth);
        cout <<"La CPU hace su movimiento en la columna: " << cpu+1 << endl;
        makeMove(board, cpu, 2);    //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            cout <<"\nLa CPU ha ganado! Juegas denuevo?\n"; //Valida si se cumplen las condiciones para que la CPU gane
        }
        }
        else if (option == 3){
            cout <<"\n  Modo Dificil";
            printBoard(board);
            cout <<"\nIngresa tu movimiento (columna del 1 al 7): ";
            cin >> value;
            playerMove = validatePosition(value); //Valida que el dato ingresado por la terminal sea válido para la lógica
            int depth = 6; //Grado de dificultad para la CPU en minimax en este modo
            while (playerMove < 0 || playerMove > COLUMS || isColumnFull(board, playerMove)) { //Valida que la columna no se encuentre llena o sea una columna valida
            cout <<"Movimiento invalido. Ingresa otro movimiento: ";
            cin >> value;
            playerMove = validatePosition(value); //Valida que el dato ingresado por la terminal sea válido para la lógica
        }

        makeMove(board, playerMove-1, 1); //Coloca la ficha en el tablero, siendo en este caso un "1"

        if (isGameOver(board, 1)) {
            printBoard(board);
            cout <<"\nHas ganado! Juegas denuevo?\n"; //Valida si se cumplen las condiciones para que el jugador gane
        }

        int cpu = cpuMove(board,depth);
        cout <<"La CPU hace su movimiento en la columna: " << cpu+1 << endl;
        makeMove(board, cpu, 2); //Coloca la ficha en el tablero, siendo en este caso un "2"

        if (isGameOver(board, 2)) {
            printBoard(board);
            cout <<"\nLa CPU ha ganado! Juegas denuevo?\n"; //Valida si se cumplen las condiciones para que la CPU gane
        }
        }
        
    }
    cout << score;
    return score;
}