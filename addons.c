#include "values.h"
#include <stdio.h>
#include <limits>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int pointsPlayer=0;
int pointsCPU=0;
int numberofMatch=1;

int displayMenu(){
    int option;
    int winner;
    int player1 =1;
    int player2 =2;
    cout <<"Bienvenido a Conecta4\n";
    do { //Bucle para que el jugador pueda repetir o probar una dificultad distinta
        readParameters("Parameters.txt",pointsPlayer,pointsCPU,numberofMatch);
        cout << "Jugador: " << pointsPlayer <<" - " << pointsCPU << " :CPU";
        cout <<"\n1 => Modo Facil\n";
        cout <<"2 => Modo Intermedio\n";
        cout <<"3 => Modo Dificil\n";
        cout <<"4 => Salir\n";
        option=validateOption();
        switch(option){
         case 1:
            winner = game(option,numberofMatch); //El valor del ganador es retornado luego de cada juego
            recordWinner(winner,pointsPlayer,pointsCPU);//Aumenta la cantidad de victorias en base al ganador de la partida
            numberofMatch++;//Aumenta el número de partidas jugadas para el siguiente registro
            recordParameters("Parameters.txt",pointsPlayer,pointsCPU,numberofMatch); //Actualiza los puntajes y cantidad de partidas jugadas
            break;
        case 2:
            winner = game(option,numberofMatch);
            recordWinner(winner,pointsPlayer,pointsCPU);
            numberofMatch++;
            recordParameters("Parameters.txt",pointsPlayer,pointsCPU,numberofMatch);
            break;
        case 3:
            winner = game(option,numberofMatch);
            recordWinner(winner,pointsPlayer,pointsCPU);
            numberofMatch++;
            recordParameters("Parameters.txt",pointsPlayer,pointsCPU,numberofMatch);
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
        if(playerMove >= 0 && playerMove <=7){ //Verifica que la conversión esté dentro del rango 1-7
            return playerMove-1;
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

//Aumenta el puntaje de victorias del ganador
int recordWinner(int winner,int& pointsPlayer,int& pointsCPU){
    if(winner == 1){
       return pointsPlayer++;
    }else{
       return pointsCPU++;
    }
}

//Guarda la partida indicando el número de partida, el ganador del juego y la dificultad que se jugó
void recordMatch(int board[ROWS][COLUMS],const string& fileName,const string& difficulty,const string& winnerofMatch,int numberofMatch){
    ofstream csvFile;
    csvFile.open(fileName, ios::app); //ios::app es para agregar nuevos registros de partidas al final del archivo en lugar de sobreescribirlas

    if(!csvFile.is_open()){
        cerr << "Error: No se puede abrir el archivo CSV" << endl;//Si no se puede abrir el archivo retorna el error
        return;
    }
    csvFile << "Partida numero: "<< numberofMatch<<endl;
    csvFile << "Ganador: " << winnerofMatch<<endl;
    csvFile << "Dificultad: " << difficulty<<endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMS; ++j) {
            csvFile << board[i][j] << "|";
        }
        csvFile << "\n";
    } 
    csvFile << "----------------\n";
    csvFile.close();
}

//Crea un archivo de parámetros que facilita el conteo de victorias pasada y de partidas jugadas en total
int readParameters(const string& fileName, int& pointsPlayer, int& pointsCPU,int& numberofMatch){
    ifstream readtextFile(fileName); //En este caso no se coloca ios::app por que se busca que se actualicen los valores en lugar de agreagarlos
        if(readtextFile.is_open()){//Valida que se pueda abrir el archivo
            int value;
            string line;
            string tag;
        if(getline(readtextFile, line)){
            istringstream iss(line);//Cada linea dentro del archivo tiene las siguientes partes
            iss >> tag >> value; //tag: la descripción del valor, value: el valor que se necesita y que será actualizado tras cada juego
            if(tag == "Puntaje_Jugador:"){//Si tag de la linea concuerda con el texto colocado, nos devuelve el valor que le corresponde 
                pointsPlayer = value;
            } else{
                cerr << "Error: El formato de la Linea 1 esta mal" << endl; //Caso contrario indica que el tag y el texto colocado tienen diferencias
                 readtextFile.close();
                return 1;
            }
        }else {
            cerr << "Error al leer la primera línea." << std::endl;
            readtextFile.close();
            return 1;
        }//La lógica de revisar la linea, comparar los tag y obtener los valores se repite 
         if(getline(readtextFile, line)){
            istringstream iss(line);
            iss >> tag >> value;
            if(tag == "Puntaje_CPU:"){
                pointsCPU = value;
            }else{
                cerr << "Error: El formato de la Linea 2 esta mal" << endl;
                 readtextFile.close();
                return 1;
            }
        }else {
            cerr << "Error al leer la segunda línea." << std::endl;
            readtextFile.close();
            return 1; // Indica un error
        }
        if(getline(readtextFile, line)){
            istringstream iss(line);
            iss >> tag >> value;
            if(tag == "Partida_Numero:"){
                numberofMatch = value;
            } else{
                cerr << "Error: El formato de la Linea 3 esta mal" << endl;
                 readtextFile.close();
                return 1;
            }
        }else {
            cerr << "Error al leer la tercera línea." << std::endl;
            readtextFile.close();
            return 1;
        }
        readtextFile.close();
    }else{//Si el archivo no puede abrirse debido a que no existe, lo creará por primera vez con valores predefinidos
        recordParameters("Parameters.txt",0,0,1);
    }
return 0;
}

void recordParameters(const string& fileName, int pointsPlayer, int pointsCPU,int numberofMatch){
        ofstream writetextFile;
        writetextFile.open(fileName);//En este caso no se coloca ios::app por que se busca que se actualicen los valores en lugar de agreagarlos
        if(!writetextFile.is_open()){
            cerr << "Error: No se puede abrir el archivo TXT" << endl;
        return;
        }   //Se define la estructura que tendrá cada línea y que será colocada posteriormente en la lectura del archivo
            writetextFile << "Puntaje_Jugador:\t" << pointsPlayer<<"\n";
            writetextFile << "Puntaje_CPU:\t" << pointsCPU<<"\n";
            writetextFile << "Partida_Numero:\t" << numberofMatch<<"\n";
            writetextFile.close();
    }