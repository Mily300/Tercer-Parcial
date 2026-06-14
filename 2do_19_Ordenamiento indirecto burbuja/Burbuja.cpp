#include "Burbuja.h"

//ENTEROS
void Burbuja::ordenarInt(int arr[], int idx[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[idx[j]] > arr[idx[j+1]]){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

void Burbuja::mostrarInt(int arr[], int idx[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[idx[i]]<<" ";
    }
    cout<<endl;
}

//CHAR
void Burbuja::ordenarChar(char arr[], int idx[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[idx[j]] > arr[idx[j+1]]){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

void Burbuja::mostrarChar(char arr[], int idx[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[idx[i]]<<" ";
    }
    cout<<endl;
}

//STRUCT
void Burbuja::ordenarPersona(Persona arr[], int idx[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[idx[j]].edad > arr[idx[j+1]].edad){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

void Burbuja::mostrarPersona(Persona arr[], int idx[], int n){
    for(int i=0;i<n;i++){
        cout<<"Edad: "<<arr[idx[i]].edad
            <<" Inicial: "<<arr[idx[i]].inicial<<endl;
    }
}
