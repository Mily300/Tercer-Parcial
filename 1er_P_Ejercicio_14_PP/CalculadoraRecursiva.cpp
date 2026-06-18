#include "CalculadoraRecursiva.h"

int CalculadoraRecursiva::multiplicar(int a, int b) {
    if (b == 0) return 0;
    if (b > 0) return a + multiplicar(a, b - 1);
    return 0;
}

int CalculadoraRecursiva::dividir(int a, int b) {
    if (b == 0) {
        cout << "Error, division por cero" << endl;
        return 0;
    }

    if (a < b) return 0;

    return 1 + dividir(a - b, b);
}

int CalculadoraRecursiva::potencia(int base, int exp) {
    if (exp == 0) return 1;

    return multiplicar(base, potencia(base, exp - 1));
}

int CalculadoraRecursiva::factorial(int n) {
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}

int CalculadoraRecursiva::fibonacci(int n) {
    if (n <= 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}