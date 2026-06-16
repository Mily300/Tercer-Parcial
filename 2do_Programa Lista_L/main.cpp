#include <iostream>
#include "lista.h"
using namespace std;

int main() {
    Lista l;
    int opcion, valor;

    do {
        cout << "\n--- MENU LISTA ---\n";
        cout << "1. Agregar elemento\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> valor;
                l.agregar(valor);
                break;

            case 2:
                cout << "Elementos de la lista:\n";
                l.mostrar();
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 3);

    return 0;
}
