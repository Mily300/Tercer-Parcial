#ifndef COLA_H
#define COLA_H

class Cola {
private:
    int datos[5];
    int inicio, fin;

public:
    Cola();
    void encolar(int valor);
    void desencolar();
    void mostrar();
    void guardarArchivos();
};

#endif
