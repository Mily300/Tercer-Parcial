#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>

using namespace std;

class Auto {
public:
    int precio, anio;
    string modelo;

    void capturar();
    void mostrar();
};

#endif