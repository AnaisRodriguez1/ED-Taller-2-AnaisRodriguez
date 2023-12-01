#include "values.h"
#include "game.c"
#include "board.c"
#include "moves.c"
#include "scores.c"
#include "minimax.c"

#include <stdio.h>
#include <limits.h>

//Menu para seleccionar la dificultad de la CPU en Conecta 4
int main(){
    int modo;
    printf("Bienvenido a Conecta4\n");

    do { //Bucle para que el jugador pueda repetir o probar una dificultad distinta
        printf("\n1 => Modo Facil\n"
           "2 => Modo Intermedio\n"
           "3 => Modo Dificil\n"
           "4 => Salir\n"
           "\nSeleccione una opcion: ");
        scanf("%d", &modo);
        switch(modo){
         case 1:
            game(modo);
            printf("Juegas denuevo?\n");
            break;
        case 2:
            game(modo);
            printf("Juegas denuevo?\n");
            break;
        case 3:
            game(modo);
            printf("Juegas denuevo?\n");
            break;
        case 4:
            printf("Regresa pronto\n");
            return 0;
}
    }while (modo !=4);
    return 0;
}