#ifndef CALCULADORANUEVA_H
#define CALCULADORANUEVA_H

#include <iostream>
#include <cmath>
#include "Calculadora.h"
using namespace std;

class CalculadoraNueva : public Calculadora {
public:

    float potencia() {
        return pow(num1, num2);
    }

    float raizPrimerNumero() {
        if(num1 >= 0) {
            return sqrt(num1);
        } else {
            cout << "No se puede sacar raiz de numero negativo.\n";
            return 0;
        }
    }

    float modulo() {
        int a = (int)num1;
        int b = (int)num2;

        if(b != 0) {
            return a % b;
        } else {
            cout << "No se puede calcular modulo entre cero.\n";
            return 0;
        }
    }
};

#endif