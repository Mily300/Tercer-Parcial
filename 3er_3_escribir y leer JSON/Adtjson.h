#ifndef ADTJSON_H
#define ADTJSON_H

#include <iostream>
#include <fstream>
#include <string>
#include "Tipos.h"
using namespace std;

class AdtJson {
public:

    void escribirDatosBasicos(DatosBasicos datos) {
        ofstream archivo("datos_basicos.json");

        archivo << "{\n";
        archivo << "   \"nombre\": \"" << datos.nombre << "\",\n";
        archivo << "   \"edad\": " << datos.edad << ",\n";
        archivo << "   \"promedio\": " << datos.promedio << "\n";
        archivo << "}\n";

        archivo.close();

        cout << "\nArchivo datos_basicos.json creado correctamente.\n";
    }

    void leerDatosBasicos() {
        ifstream archivo("datos_basicos.json");
        string linea;

        if(!archivo) {
            cout << "\nNo existe el archivo datos_basicos.json\n";
            return;
        }

        cout << "\n--- LEER JSON DATOS BASICOS ---\n";

        while(getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }

    void escribirArreglo(ArregloNumeros arreglo) {
        ofstream archivo("arreglo.json");

        archivo << "{\n";
        archivo << "   \"numeros\": [";

        for(int i = 0; i < arreglo.n; i++) {
            archivo << arreglo.numeros[i];

            if(i < arreglo.n - 1) {
                archivo << ", ";
            }
        }

        archivo << "]\n";
        archivo << "}\n";

        archivo.close();

        cout << "\nArchivo arreglo.json creado correctamente.\n";
    }

    void leerArreglo() {
        ifstream archivo("arreglo.json");
        string linea;

        if(!archivo) {
            cout << "\nNo existe el archivo arreglo.json\n";
            return;
        }

        cout << "\n--- LEER JSON ARREGLO ---\n";

        while(getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }

    void escribirAlumnos(Alumno alumnos[], int n) {
        ofstream archivo("alumnos.json");

        archivo << "{\n";
        archivo << "   \"alumnos\": [\n";

        for(int i = 0; i < n; i++) {
            archivo << "      {\n";
            archivo << "         \"nombre\": \"" << alumnos[i].nombre << "\",\n";
            archivo << "         \"edad\": " << alumnos[i].edad << ",\n";
            archivo << "         \"promedio\": " << alumnos[i].promedio << "\n";
            archivo << "      }";

            if(i < n - 1) {
                archivo << ",";
            }

            archivo << "\n";
        }

        archivo << "   ]\n";
        archivo << "}\n";

        archivo.close();

        cout << "\nArchivo alumnos.json creado correctamente.\n";
    }

    void leerAlumnos() {
        ifstream archivo("alumnos.json");
        string linea;

        if(!archivo) {
            cout << "\nNo existe el archivo alumnos.json\n";
            return;
        }

        cout << "\n--- LEER JSON ADT POO ---\n";

        while(getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
};

#endif
