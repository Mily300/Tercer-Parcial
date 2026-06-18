#include <iostream>
#include <fstream>
#include "archivoTXT.h"

using namespace std;

void ArchivoTXT::capturar() {

    for(int i=0; i<5; i++) {

        cout<<"Nombre "<<i+1<<": ";
        cin>>nombres[i];
    }
}

void ArchivoTXT::escribirTXT() {

    ofstream archivo("personas.txt");

    for(int i=0; i<5; i++) {

        archivo<<nombres[i]<<endl;
    }

    archivo.close();

    cout<<"\nArchivo guardado correctamente.\n";
}

void ArchivoTXT::leerTXT() {

    ifstream archivo("personas.txt");

    string linea;

    cout<<"\nContenido del archivo:\n\n";

    while(getline(archivo,linea)) {

        cout<<linea<<endl;
    }

    archivo.close();
}