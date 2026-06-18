#ifndef CALCULADORARECURSIVA_H
#define CALCULADORARECURSIVA_H

#include <iostream>

using namespace std;

class CalculadoraRecursiva {
public:
    int multiplicar(int a, int b);
    int dividir(int a, int b);
    int potencia(int base, int exp);
    int factorial(int n);
    int fibonacci(int n);
};

#endif