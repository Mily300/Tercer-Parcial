#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
using namespace std;

struct Persona {
    int edad;
    char inicial;
};

class MergeSort {
public:
    void ordenarInt(int arr[], int ini, int fin);
    void ordenarChar(char arr[], int ini, int fin);
    void ordenarPersona(Persona arr[], int ini, int fin);

    void mostrarInt(int arr[], int n);
    void mostrarChar(char arr[], int n);
    void mostrarPersona(Persona arr[], int n);
};

#endif