#include "funciones.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void MenuJuego(int &n,char r1[10][2][100], int &contador){
    cout << "\n\nIngrese el número de opción que desee utilizar"<<'\n'<<'\n';
    cout << "(1) Jugar a completar..."<<'\n';
    cout << "(2) Mostrar..."<<'\n';
    cout << "(3) Salir"<<'\n'<<'\n';
    cout << "Ingrese el número: "<<'\n';
    cin >> n;
    switch (n){
        case 1: JugarCompletarRegranes(n,r1,contador);
        break;
        case 2: MostrarResultados(contador);
        break;
    }
}

void JugarCompletarRegranes(int &n,char r1[10][2][100],int &contador){
    int eleccion;
    char completar[100];
    bool aprobar = true;
    srand(time(nullptr));
    int nrefran=rand()%2;

    for (int j=0;j<100;j++){
        cout << r1[nrefran][0][j];
    }

    cout << "\nIngrese 1 si desea jugar, 2 si desea omitir el refrán";
    cin >> eleccion;

    if (eleccion==1){
        cout << "\nIngrese su respuesta: ";
        cin >> completar;
        for (int i=0; i<100; i++){
            if (completar[i]!=r1[nrefran][1][i]){
                aprobar = false;
            }
        }
        if (aprobar){
            cout << "\nExcelente, usted ha ganado un punto";
            contador++;
        }else{
            cout << "\nSigue intentando";
        }
        MenuJuego(n,r1,contador);
    } else{
        JugarCompletarRegranes(n,r1,contador);
    }

}

void MostrarResultados(int contador){
    cout << "\nTu puntaje es: " << contador;
}
