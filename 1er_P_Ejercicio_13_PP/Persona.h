#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre, ap, am, genero;
    int edad;

    void capturar();
    void mostrar();
};

#endif