#include "QuickSort.h"

//ENTEROS
void swapInt(int &a, int &b){
    int t = a; a = b; b = t;
}

int particionInt(int arr[], int ini, int fin){
    int pivote = arr[fin];
    int i = ini - 1;

    for(int j=ini;j<fin;j++){
        if(arr[j] < pivote){
            i++;
            swapInt(arr[i], arr[j]);
        }
    }
    swapInt(arr[i+1], arr[fin]);
    return i+1;
}

void QuickSort::ordenarInt(int arr[], int ini, int fin){
    if(ini < fin){
        int pi = particionInt(arr, ini, fin);
        ordenarInt(arr, ini, pi-1);
        ordenarInt(arr, pi+1, fin);
    }
}

void QuickSort::mostrarInt(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

// ---------- CHAR ----------
void swapChar(char &a, char &b){
    char t = a; a = b; b = t;
}

int particionChar(char arr[], int ini, int fin){
    char pivote = arr[fin];
    int i = ini - 1;

    for(int j=ini;j<fin;j++){
        if(arr[j] < pivote){
            i++;
            swapChar(arr[i], arr[j]);
        }
    }
    swapChar(arr[i+1], arr[fin]);
    return i+1;
}

void QuickSort::ordenarChar(char arr[], int ini, int fin){
    if(ini < fin){
        int pi = particionChar(arr, ini, fin);
        ordenarChar(arr, ini, pi-1);
        ordenarChar(arr, pi+1, fin);
    }
}

void QuickSort::mostrarChar(char arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

// ---------- STRUCT ----------
void swapPersona(Persona &a, Persona &b){
    Persona t = a; a = b; b = t;
}

int particionPersona(Persona arr[], int ini, int fin){
    int pivote = arr[fin].edad;
    int i = ini - 1;

    for(int j=ini;j<fin;j++){
        if(arr[j].edad < pivote){
            i++;
            swapPersona(arr[i], arr[j]);
        }
    }
    swapPersona(arr[i+1], arr[fin]);
    return i+1;
}

void QuickSort::ordenarPersona(Persona arr[], int ini, int fin){
    if(ini < fin){
        int pi = particionPersona(arr, ini, fin);
        ordenarPersona(arr, ini, pi-1);
        ordenarPersona(arr, pi+1, fin);
    }
}

void QuickSort::mostrarPersona(Persona arr[], int n){
    for(int i=0;i<n;i++){
        cout<<"Edad: "<<arr[i].edad<<" Inicial: "<<arr[i].inicial<<endl;
    }
}
