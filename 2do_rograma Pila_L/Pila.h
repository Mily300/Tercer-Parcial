#ifndef PILA_H
#define PILA_H

class Pila {
private:
    int datos[5];
    int tope;

public:
    Pila();
    void push(int valor);
    void pop();
    void mostrar();
    void guardarArchivos();
};

#endif
