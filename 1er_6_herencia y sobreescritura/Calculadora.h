#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
using namespace std;

class Calculadora {
public:

    virtual int multiplicacion(int a, int b) {
        return a * b;
    }

    virtual int division(int a, int b) {
        return a / b;
    }

    virtual int potencia(int a, int b) {
        int resultado = 1;

        for(int i = 0; i < b; i++) {
            resultado *= a;
        }

        return resultado;
    }

    int suma(int a, int b) {
        return a + b;
    }

    int resta(int a, int b) {
        return a - b;
    }

    virtual ~Calculadora() {}
};

#endif