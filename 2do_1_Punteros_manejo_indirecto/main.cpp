#include <iostream>
#include <string>
#include <cstdlib>
#include "Nodo.h"
#include "logger.h"

using namespace std;


void capturaNodo(Nodo*& inicio, Nodo*& actual, Logger& log) {
    string info;
    cout << "\nIngresa una sola palabra para guardar en el nodo: ";
    cin >> info;
    agregarNodo(inicio, actual, info);
    log.registrar("agregar_nodo", "Nodo insertado", info);
}

void impresion(Nodo* inicio, Logger& log) {
    mostrarNodos(inicio);
    string cadena = "[INICIO] -> ";
    Nodo* tmp = inicio;
    while (tmp != NULL) {
        cadena += "[ " + tmp->getInformacion() + " ] -> ";
        tmp = tmp->getSiguiente();
    }
    cadena += "NULL";
    log.registrar("mostrar_cadena", "Estado actual de la lista", cadena);
}

void liberarMemoria(Nodo*& inicio) {
    Nodo* temporal;
    while(inicio != NULL) {
        temporal = inicio;
        inicio = inicio->getSiguiente();
        delete temporal;
    }
}


int menu() {
    int opcion;
    cout << "\nMenu Punteros Para El Manejo Indirecto Con Clases Y Estructuras\n";
    cout << "\n1 - Agregar un nuevo eslabon (Nodo)";
    cout << "\n2 - Mostrar toda la cadena unida";
    cout << "\n3 - Salir del menu\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;
    return opcion;
}


int main() {
    Nodo* inicio = NULL;
    Nodo* actual = NULL;
    int opcion;
    Logger log("2do_1-Punteros Manejo Indirecto");

    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menu(); 

        switch (opcion) {
            case 1:
                capturaNodo(inicio, actual, log);
                break;
            case 2:
                impresion(inicio, log);
                break;
            case 3:
                cout << "\nHasta luego";
                liberarMemoria(inicio);
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
