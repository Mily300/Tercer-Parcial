#ifndef PERSONA_H
#define PERSONA_H

struct Persona {
    char nombre[20];
    int edad;
};

class ListaPersonas {
private:
    Persona personas[3];

public:
    void llenar();
    void mostrar();
};

#endif
