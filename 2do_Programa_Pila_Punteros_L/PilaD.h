#include <iostream>
#include "pilaD.h"
using namespace std;

PilaD::PilaD() {
    tope = NULL;
}

void PilaD::push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->sig = tope;
    tope = nuevo;
}

void PilaD::pop() {
    if (tope != NULL) {
        Nodo* temp = tope;
        tope = tope->sig;
        delete temp;
    } else {
        cout << "Pila vacia\n";
    }
}

void PilaD::mostrar() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* aux = tope;
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->sig;
    }
}
