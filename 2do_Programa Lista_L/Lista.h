#ifndef LISTA_H
#define LISTA_H

class Lista {
private:
    int datos[5];
    int n;

public:
    Lista();
    void agregar(int valor);
    void mostrar();
    void guardarArchivos();
};

#endif
