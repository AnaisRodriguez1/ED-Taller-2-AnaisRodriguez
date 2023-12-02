#include "values.h"
#include <stdio.h>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

int displayMenu(){
    int option;
    cout <<"Bienvenido a Conecta4\n";
    do { //Bucle para que el jugador pueda repetir o probar una dificultad distinta
        cout <<"\n1 => Modo Facil\n";
        cout <<"2 => Modo Intermedio\n";
        cout <<"3 => Modo Dificil\n";
        cout <<"4 => Salir\n";
        option=validateOption();
        switch(option){
         case 1:
            game(option);
            break;
        case 2:
            game(option);
            break;
        case 3:
            game(option);
            break;
        case 4:
            cout <<"Regresa pronto\n";
            return 0;
}
    }while (option !=4);
    return 0;
}

int validateOption(){
    string mode;
    int option;
        cout <<"\nSeleccione una opcion: ";
        cin >> mode;
    try{
        option = stoi(mode); //stoi intenta convertir lo que se le brinde como parámetro a un número
        if(option >= 1 && option <=4){ //Verifica que la conversión esté dentro del rango 1-4 
            return option;
        }else{
            cerr << "\nError: No es una option valida\n";
        }
    } catch (const invalid_argument& e) { //Si la conversión falla, muestra un mensaje de error
        cerr << "Error: La entrada no es un numero valido.\n" << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: El numero ingresado esta fuera del rango valido.\n" << endl;
    }

    // Limpiar el estado de error y el buffer de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return -1;  // Valor no válido para indicar error
}

int validatePosition(const string& value){
    int playerMove;
    try{
        playerMove = stoi(value); //stoi intenta convertir lo que se le brinde como parámetro a un número
        if(playerMove >= 1 && playerMove <=7){ //Verifica que la conversión esté dentro del rango 1-7
            return playerMove;
        }else{
            cerr << "\nError: No es una option valida\n";
            return -1;
        }
    } catch (const invalid_argument& e) { //Si la conversión falla, muestra un mensaje de error
        cerr << "Error: La entrada no es un numero valido.\n" << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: El numero ingresado esta fuera del rango valido.\n" << endl;
    }

    // Limpiar el estado de error y el buffer de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return -1; // Valor no válido para indicar error
}