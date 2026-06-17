#include "MergeSort.h"

// ENTEROS
void mergeInt(int arr[], int ini, int mitad, int fin) {
    int n1 = mitad - ini + 1;
    int n2 = fin - mitad;

    int *izq = new int[n1];
    int *der = new int[n2];

    for(int i = 0; i < n1; i++) {
        izq[i] = arr[ini + i];
    }

    for(int j = 0; j < n2; j++) {
        der[j] = arr[mitad + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while(i < n1 && j < n2) {
        if(izq[i] <= der[j]) {
            arr[k] = izq[i];
            i++;
        } else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = der[j];
        j++;
        k++;
    }

    delete[] izq;
    delete[] der;
}

void MergeSort::ordenarInt(int arr[], int ini, int fin) {
    if(ini < fin) {
        int mitad = (ini + fin) / 2;

        ordenarInt(arr, ini, mitad);
        ordenarInt(arr, mitad + 1, fin);
        mergeInt(arr, ini, mitad, fin);
    }
}

void MergeSort::mostrarInt(int arr[], int n) {
    cout << "\nEnteros ordenados:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// CARACTERES
void mergeChar(char arr[], int ini, int mitad, int fin) {
    int n1 = mitad - ini + 1;
    int n2 = fin - mitad;

    char *izq = new char[n1];
    char *der = new char[n2];

    for(int i = 0; i < n1; i++) {
        izq[i] = arr[ini + i];
    }

    for(int j = 0; j < n2; j++) {
        der[j] = arr[mitad + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while(i < n1 && j < n2) {
        if(izq[i] <= der[j]) {
            arr[k] = izq[i];
            i++;
        } else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = der[j];
        j++;
        k++;
    }

    delete[] izq;
    delete[] der;
}

void MergeSort::ordenarChar(char arr[], int ini, int fin) {
    if(ini < fin) {
        int mitad = (ini + fin) / 2;

        ordenarChar(arr, ini, mitad);
        ordenarChar(arr, mitad + 1, fin);
        mergeChar(arr, ini, mitad, fin);
    }
}

void MergeSort::mostrarChar(char arr[], int n) {
    cout << "\nCaracteres ordenados:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// PERSONAS
void mergePersona(Persona arr[], int ini, int mitad, int fin) {
    int n1 = mitad - ini + 1;
    int n2 = fin - mitad;

    Persona *izq = new Persona[n1];
    Persona *der = new Persona[n2];

    for(int i = 0; i < n1; i++) {
        izq[i] = arr[ini + i];
    }

    for(int j = 0; j < n2; j++) {
        der[j] = arr[mitad + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while(i < n1 && j < n2) {
        if(izq[i].edad <= der[j].edad) {
            arr[k] = izq[i];
            i++;
        } else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = der[j];
        j++;
        k++;
    }

    delete[] izq;
    delete[] der;
}

void MergeSort::ordenarPersona(Persona arr[], int ini, int fin) {
    if(ini < fin) {
        int mitad = (ini + fin) / 2;

        ordenarPersona(arr, ini, mitad);
        ordenarPersona(arr, mitad + 1, fin);
        mergePersona(arr, ini, mitad, fin);
    }
}

void MergeSort::mostrarPersona(Persona arr[], int n) {
    cout << "\nPersonas ordenadas por edad:\n";

    for(int i = 0; i < n; i++) {
        cout << "Edad: " << arr[i].edad
             << " Inicial: " << arr[i].inicial << endl;
    }
}