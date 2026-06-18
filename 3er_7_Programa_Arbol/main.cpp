#include <iostream>
#include "arbol.h"

using namespace std;

int main() {
    Arbol a;
    int opcion;
    char origen;

    do {
        cout << "\n===== MENU DE GRAFOS/ARBOLES XML =====\n";
        cout << "1. Leer XML\n";
        cout << "2. Mostrar conexiones\n";
        cout << "3. Buscar ruta optima (Dijkstra)\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
        }

        switch(opcion) {
            case 1:
                a.leerXML();
                break;
            case 2:
                a.mostrarConexiones();
                break;
            case 3: {
                char destino;
                cout << "\nIngresa el nodo de ORIGEN (Letra): ";
                cin >> origen;
                cout << "Ingresa el nodo de DESTINO (Letra): ";
                cin >> destino;
                
                a.dijkstra(origen, destino);
                break;
            }
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intenta de nuevo.\n";
        }
    } while(opcion != 4);

    return 0;
}