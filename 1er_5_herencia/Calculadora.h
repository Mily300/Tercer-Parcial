#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
using namespace std;

class Calculadora {
protected:
    float num1;
    float num2;

public:
    void capturar() {
        cout << "Ingrese primer numero: ";
        cin >> num1;

        cout << "Ingrese segundo numero: ";
        cin >> num2;
    }

    float sumar() {
        return num1 + num2;
    }

    float restar() {
        return num1 - num2;
    }

    float multiplicar() {
        return num1 * num2;
    }

    float dividir() {
        if(num2 != 0) {
            return num1 / num2;
        } else {
            cout << "No se puede dividir entre cero.\n";
            return 0;
        }
    }
};

#endif