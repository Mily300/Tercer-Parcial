#include "Nodo.h"
#include <cstddef>
#include <iostream>

Nodo::Nodo(string info) {
    informacion = info;
    siguiente = NULL;
}

void Nodo::setSiguiente(Nodo* sig) {
    siguiente = sig;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente;
}

string Nodo::getInformacion() const {
    return informacion;
}

void agregarNodo(Nodo*& inicio, Nodo*& actual, string info) {
    Nodo* nuevoNodo = new Nodo(info);
    
    if (inicio == NULL) {
        inicio = nuevoNodo;
        actual = nuevoNodo;
    } else {
        actual->setSiguiente(nuevoNodo);
        actual = nuevoNodo;
    }
    cout << ">> Nodo agregado exitosamente en memoria." << endl;
}

void mostrarNodos(Nodo* inicio) {
    if (inicio == NULL) {
        cout << ">> La cadena esta vacia." << endl;
    } else {
        cout << "\nRecorriendo los punteros en memoria:\n[INICIO] -> ";
        Nodo* temporal = inicio;
        while (temporal != NULL) {
            cout << "[ " << temporal->getInformacion() << " ] -> ";
            temporal = temporal->getSiguiente();
        }
        cout << "NULL" << endl;
    }
}
