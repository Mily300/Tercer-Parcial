#ifndef BURBUJA_H
#define BURBUJA_H

#include <iostream>
using namespace std;

struct Persona{
    int edad;
    char inicial;
};

class Burbuja{
public:

    void ordenarInt(int arr[], int n);
    void mostrarInt(int arr[], int n);

    void ordenarChar(char arr[], int n);
    void mostrarChar(char arr[], int n);

    void ordenarPersona(Persona arr[], int n);
    void mostrarPersona(Persona arr[], int n);
};

#endif