#include <iostream>
#include "pilaD.h"
using namespace std;

int main() {
    PilaD p;
    int opcion, valor;

    do {
        cout << "\n--- MENU PILA DINAMICA ---\n";
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
