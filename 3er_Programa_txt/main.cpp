#include <iostream>
#include "archivoTXT.h"

using namespace std;

int main() {

    ArchivoTXT a;

    int opcion;

    do {

        cout<<"\n--- MENU TXT ---\n";
        cout<<"1. Capturar datos\n";
        cout<<"2. Guardar TXT\n";
        cout<<"3. Leer TXT\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion) {

            case 1:
                a.capturar();
                break;

            case 2:
                a.escribirTXT();
                break;

            case 3:
                a.leerTXT();
                break;
        }

    } while(opcion!=4);

    return 0;
}