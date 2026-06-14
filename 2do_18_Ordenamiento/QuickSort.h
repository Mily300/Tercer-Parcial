#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
using namespace std;

//STRUCT
struct Persona{
    int edad;
    char inicial;
};

//CLASE
class QuickSort{
public:

//ENTEROS
void ordenarInt(int arr[], int ini, int fin);
void mostrarInt(int arr[], int n);

//CHAR
void ordenarChar(char arr[], int ini, int fin);
void mostrarChar(char arr[], int n);

//STRUCT
void ordenarPersona(Persona arr[], int ini, int fin);
void mostrarPersona(Persona arr[], int n);
};

#endif
