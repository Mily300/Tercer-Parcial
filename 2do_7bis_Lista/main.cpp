#include <iostream>
#include <cstdlib>
#include "ListaDinamica.h"
#include "logger.h"

using namespace std;

void insertarElemento(ListaDinamica<int>* lista, Logger& log) {
    int numero;
    cout << "\nIngresa un numero entero a la lista: ";
    cin >> numero;
    lista->insertar(numero);
    log.registrar("insertar", "Elemento insertado al final", numero);
}

void mostrarLista(ListaDinamica<int>* lista, Logger& log) {
    cout << "\n";
    lista->mostrar();
    log.registrar("mostrar", "Estado de la lista", lista->snapshot());
}

void eliminarElemento(ListaDinamica<int>* lista, Logger& log) {
    cout << "\n";
    bool vacia = (lista->snapshot() == "Lista vacia");
    lista->eliminar();
    if (vacia)
        log.registrar("eliminar", "Intento en lista vacia", "Error");
    else
        log.registrar("eliminar", "Elemento del inicio eliminado", "OK");
}


int menu() {
    int opcion;
    cout << "\nMenu Lista Dinamica (7 Bis)\n";
    cout << "\n1 - Insertar elemento al final";
    cout << "\n2 - Mostrar lista";
    cout << "\n3 - Eliminar elemento (inicio)";
    cout << "\n4 - Salir del menu\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;
    return opcion;
}


int main() {
    ListaDinamica<int>* miLista = new ListaDinamica<int>();
    int opcion;
    Logger log("2do_7bis-Lista Dinamica");

    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menu();

        switch (opcion) {
            case 1:
                insertarElemento(miLista, log);
                break;
            case 2:
                mostrarLista(miLista, log);
                break;
            case 3:
                eliminarElemento(miLista, log);
                break;
            case 4:
                cout << "\nHasta luego";
                delete miLista;
                log.registrar("salir", "Sesion terminada", "OK");
                repeticion++; 
                break;
            default:
                cout << "\nOpcion invalida";
        }

        cout << endl;
    }

    log.guardar();
    cout << endl;
    return 0;
}
