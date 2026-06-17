#include "Burbuja.h"

// ENTEROS
void Burbuja::ordenarInt(int arr[], int n){
    int aux;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void Burbuja::mostrarInt(int arr[], int n){

    cout<<"\nEnteros ordenados:\n";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

// CARACTERES
void Burbuja::ordenarChar(char arr[], int n){

    char aux;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void Burbuja::mostrarChar(char arr[], int n){

    cout<<"\nCaracteres ordenados:\n";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

// PERSONAS
void Burbuja::ordenarPersona(Persona arr[], int n){

    Persona aux;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            if(arr[j].edad > arr[j+1].edad){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void Burbuja::mostrarPersona(Persona arr[], int n){

    cout<<"\nPersonas ordenadas por edad:\n";

    for(int i=0;i<n;i++){

        cout<<"Edad: "
            <<arr[i].edad
            <<" Inicial: "
            <<arr[i].inicial
            <<endl;
    }
}