#ifndef PERSONAPOO_H
#define PERSONAPOO_H
#include <string>
#include <iostream>

using namespace std;

class PersonaPOO {
private:
    string nombre;
    int edad;

public:
    PersonaPOO();
    PersonaPOO(string n, int e);

    void imprimir() const;
    
    bool operator<(const PersonaPOO& otra) const;
    friend ostream& operator<<(ostream& os, const PersonaPOO& p);
};

template <typename T>
int particion(T* arr[], int low, int high) {
    T* pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (*arr[j] < *pivot) {
            i++;
            T* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    T* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

template <typename T>
void quickSortIndirecto(T* arr[], int low, int high) {
    if (low < high) {
        int pi = particion(arr, low, high);
        quickSortIndirecto(arr, low, pi - 1);
        quickSortIndirecto(arr, pi + 1, high);
    }
}

template <typename T>
void imprimirArreglo(T* arr[], int n) {
    for (int i = 0; i < n; i++) cout << *arr[i] << " | ";
    cout << endl;
}

#endif
