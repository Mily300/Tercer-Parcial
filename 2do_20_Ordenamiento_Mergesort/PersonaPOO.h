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
    
    bool operator<=(const PersonaPOO& otra) const;
    friend ostream& operator<<(ostream& os, const PersonaPOO& p);
};

template <typename T>
void mergeIndirecto(T* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T** L = new T*[n1];
    T** R = new T*[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (*L[i] <= *R[j]) { 
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
    
    delete[] L; 
    delete[] R;
}

template <typename T>
void mergeSort(T* arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeIndirecto(arr, left, mid, right);
}

template <typename T>
void imprimirArreglo(T* arr[], int n) {
    for (int i = 0; i < n; i++) cout << *arr[i] << " | ";
    cout << endl;
}

#endif
