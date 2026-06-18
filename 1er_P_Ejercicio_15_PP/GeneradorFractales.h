#ifndef GENERADORFRACTALES_H
#define GENERADORFRACTALES_H

#include <iostream>
#include <string>

using namespace std;

class GeneradorFractales {
public:
    char tableroSierpinski[32][64];

    void inicializarTablero();
    void generarCantor(int n, string linea);
    void generarSierpinski(int x, int y, int n);
    void imprimirSierpinski();
};

#endif