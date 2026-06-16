#include <iostream>
#include "pila.h"
using namespace std;

int main() {
    Pila p;
    int opcion, valor;

    do {
        cout << "\n--- MENU PILA ---\n";
        cout << "1. Push (Insertar)\n";
        cout << "2. Pop (Eliminar)\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> valor;
                p.push(valor);
                break;

            case 2:
                p.pop();
                break;

            case 3:
                cout << "Elementos de la pila:\n";
                p.mostrar();
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
