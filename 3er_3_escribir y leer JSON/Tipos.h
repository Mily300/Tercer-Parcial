#ifndef TIPOS_H
#define TIPOS_H

#include <iostream>
#include <string>
using namespace std;

struct DatosBasicos {
    string nombre;
    int edad;
    float promedio;
};

struct ArregloNumeros {
    int numeros[10];
    int n;
};

class Alumno {
public:
    string nombre;
    int edad;
    float promedio;

    void capturar() {
        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        cout << "Promedio: ";
        cin >> promedio;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio: " << promedio << endl;
    }
};

#endif
