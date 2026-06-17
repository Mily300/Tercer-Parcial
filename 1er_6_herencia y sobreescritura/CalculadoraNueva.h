#ifndef CALCULADORANUEVA_H
#define CALCULADORANUEVA_H

#include "Calculadora.h"

class CalculadoraNueva : public Calculadora {
public:

    // Multiplicación por sumas sucesivas
    int multiplicacion(int a, int b) override {

        int resultado = 0;

        for(int i = 0; i < b; i++) {
            resultado += a;
        }

        return resultado;
    }

    // División por restas sucesivas
    int division(int a, int b) override {

        if(b == 0) {
            return 0;
        }

        int contador = 0;

        while(a >= b) {
            a = a - b;
            contador++;
        }

        return contador;
    }

    // Potencia por multiplicaciones sucesivas
    int potencia(int a, int b) override {

        int resultado = 1;

        for(int i = 0; i < b; i++) {

            int temporal = 0;

            for(int j = 0; j < a; j++) {
                temporal += resultado;
            }

            resultado = temporal;
        }

        return resultado;
    }
};

#endif