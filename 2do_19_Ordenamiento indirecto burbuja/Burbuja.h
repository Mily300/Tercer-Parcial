#ifndef BURBUJA_H
#define BURBUJA_H

#include <iostream>
using namespace std;

//STRUCT
struct Persona{
    int edad;
    char inicial;
};

//CLASE
class Burbuja{
public:

    // ENTEROS
    void ordenarInt(int arr[], int idx[], int n);
    void mostrarInt(int arr[], int idx[], int n);

    // CHAR
    void ordenarChar(char arr[], int idx[], int n);
    void mostrarChar(char arr[], int idx[], int n);

    // STRUCT
    void ordenarPersona(Persona arr[], int idx[], int n);
    void mostrarPersona(Persona arr[], int idx[], int n);
};

#endif
