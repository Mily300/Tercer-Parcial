#include <iostream>
#include "Digrafo.h"
#include "DigrafoADT.h"

using namespace std;

int main() {

    Digrafo d;
    DigrafoADT adt;

    int opcion;

    do {

        cout << "\n===== MENU DIGRAFO =====\n";
        cout << "1. Crear digrafo\n";
        cout << "2. Agregar arista\n";
        cout << "3. Mostrar matriz\n";
        cout << "4. Mostrar aristas\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:

            adt.crearDigrafo(d);
            break;

        case 2:

            adt.agregarArista(d);
            break;

        case 3:

            adt.mostrarMatriz(d);
            break;

        case 4:

            adt.mostrarAristas(d);
            break;

        case 5:

            cout << "\nSaliendo...\n";
            break;

        default:

            cout << "\nOpcion no valida.\n";
        }

    } while(opcion != 5);

    return 0;
}
