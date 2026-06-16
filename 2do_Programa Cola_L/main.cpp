#include <iostream>
#include "cola.h"
using namespace std;

int main() {
    Cola c;
    int opcion, valor;

    do {
        cout << "\n--- MENU COLA ---\n";
        cout << "1. Encolar\n";
        cout << "2. Desencolar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> valor;
                c.encolar(valor);
                break;

            case 2:
                c.desencolar();
                break;

            case 3:
                cout << "Elementos de la cola:\n";
                c.mostrar();
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 4);

    return 0;
}
