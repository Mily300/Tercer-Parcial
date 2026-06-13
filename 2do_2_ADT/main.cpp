#include <iostream>
#include <cstdlib>
#include "AdtColeccion.h"
#include "logger.h"

using namespace std;


void insertarElemento(ADT_Coleccion<int>* coleccion, Logger& log) {
    int numero;
    cout << "\nIngresa el numero entero a guardar: ";
    cin >> numero;
    coleccion->insertar(numero);
    log.registrar("insertar", "Elemento insertado", numero);
}

void mostrarColeccion(ADT_Coleccion<int>* coleccion, Logger& log) {
    cout << "\n";
    coleccion->mostrar();
    log.registrar("mostrar", "Se mostro la coleccion", "OK");
}

void eliminarElemento(ADT_Coleccion<int>* coleccion, Logger& log) {
    cout << "\n";
    bool vacia = coleccion->estaVacia();
    coleccion->eliminar();
    if (vacia)
        log.registrar("eliminar", "Intento de eliminar en coleccion vacia", "Error");
    else
        log.registrar("eliminar", "Ultimo elemento eliminado", "OK");
}


int menu() {
    int opcion;
    cout << "\nMenu ADT Coleccion\n";
    cout << "\n1 - Insertar un numero";
    cout << "\n2 - Mostrar la coleccion";
    cout << "\n3 - Eliminar el ultimo elemento";
    cout << "\n4 - Salir del menu\n";
    cout << "\nTeclee la opcion deseada : ";
    cin >> opcion;
    return opcion;
}


int main() {
    ADT_Coleccion<int>* miColeccion = new ColeccionArreglo<int>(5);
    int opcion;
    Logger log("2do_2-ADT Coleccion");

    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menu();

        switch (opcion) {
            case 1:
                insertarElemento(miColeccion, log);
                break;
            case 2:
                mostrarColeccion(miColeccion, log);
                break;
            case 3:
                eliminarElemento(miColeccion, log);
                break;
            case 4:
                cout << "\nHasta luego";
                delete miColeccion;
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
