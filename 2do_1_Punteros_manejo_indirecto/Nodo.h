#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;

class Nodo {
private:
    string informacion;
    Nodo* siguiente;

public:
    Nodo(string info);

    void setSiguiente(Nodo* sig);
    Nodo* getSiguiente() const;
    string getInformacion() const;
};

void agregarNodo(Nodo*& inicio, Nodo*& actual, string info);
void mostrarNodos(Nodo* inicio);

#endif
