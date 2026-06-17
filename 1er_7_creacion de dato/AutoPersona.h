#ifndef AUTOPERSONA_H
#define AUTOPERSONA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Auto {
public:
    int precio;
    int anio;

    void capturar() {
        cout << "\nIngrese precio del auto: ";
        cin >> precio;

        cout << "Ingrese anio del auto: ";
        cin >> anio;
    }

    void mostrar() {
        cout << "Precio: " << precio << "  ";
        cout << "Anio: " << anio << endl;
    }
};

class Persona {
public:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

    void capturar() {
        cout << "\nNombre: ";
        cin >> nombre;

        cout << "Apellido paterno: ";
        cin >> ap;

        cout << "Apellido materno: ";
        cin >> am;

        cout << "Genero: ";
        cin >> genero;

        cout << "Edad: ";
        cin >> edad;
    }

    void mostrar() {
        cout << nombre << " " << ap << " " << am;
        cout << "  Genero: " << genero;
        cout << "  Edad: " << edad << endl;
    }
};

void generarTXT(Auto autos[], int contAutos, Persona personas[], int contPersonas) {
    ofstream archivo("resultado.txt");

    archivo << "LISTA DE AUTOS\n\n";

    for(int i = 0; i < contAutos; i++) {
        archivo << "Auto " << i + 1 << endl;
        archivo << "Precio: " << autos[i].precio << endl;
        archivo << "Anio: " << autos[i].anio << endl;
        archivo << endl;
    }

    archivo << "\nLISTA DE PERSONAS\n\n";

    for(int i = 0; i < contPersonas; i++) {
        archivo << "Persona " << i + 1 << endl;
        archivo << "Nombre: " << personas[i].nombre << " "
                << personas[i].ap << " "
                << personas[i].am << endl;
        archivo << "Genero: " << personas[i].genero << endl;
        archivo << "Edad: " << personas[i].edad << endl;
        archivo << endl;
    }

    archivo.close();
}

void generarCSV(Auto autos[], int contAutos, Persona personas[], int contPersonas) {
    ofstream archivo("resultado.csv");

    archivo << "AUTOS\n";
    archivo << "Precio,Anio\n";

    for(int i = 0; i < contAutos; i++) {
        archivo << autos[i].precio << ","
                << autos[i].anio << endl;
    }

    archivo << "\nPERSONAS\n";
    archivo << "Nombre,ApellidoPaterno,ApellidoMaterno,Genero,Edad\n";

    for(int i = 0; i < contPersonas; i++) {
        archivo << personas[i].nombre << ","
                << personas[i].ap << ","
                << personas[i].am << ","
                << personas[i].genero << ","
                << personas[i].edad << endl;
    }

    archivo.close();
}

void generarJSON(Auto autos[], int contAutos, Persona personas[], int contPersonas) {
    ofstream archivo("resultado.json");

    archivo << "{\n";
    archivo << "\"autos\": [\n";

    for(int i = 0; i < contAutos; i++) {
        archivo << "{";
        archivo << "\"precio\": " << autos[i].precio << ",";
        archivo << "\"anio\": " << autos[i].anio;
        archivo << "}";

        if(i < contAutos - 1) {
            archivo << ",";
        }

        archivo << "\n";
    }

    archivo << "],\n";
    archivo << "\"personas\": [\n";

    for(int i = 0; i < contPersonas; i++) {
        archivo << "{";
        archivo << "\"nombre\": \"" << personas[i].nombre << "\",";
        archivo << "\"apellidoPaterno\": \"" << personas[i].ap << "\",";
        archivo << "\"apellidoMaterno\": \"" << personas[i].am << "\",";
        archivo << "\"genero\": \"" << personas[i].genero << "\",";
        archivo << "\"edad\": " << personas[i].edad;
        archivo << "}";

        if(i < contPersonas - 1) {
            archivo << ",";
        }

        archivo << "\n";
    }

    archivo << "]\n";
    archivo << "}\n";

    archivo.close();
}

void generarXML(Auto autos[], int contAutos, Persona personas[], int contPersonas) {
    ofstream archivo("resultado.xml");

    archivo << "<?xml version=\"1.0\"?>\n";
    archivo << "<datos>\n";

    archivo << "   <autos>\n";

    for(int i = 0; i < contAutos; i++) {
        archivo << "      <auto>\n";
        archivo << "         <precio>" << autos[i].precio << "</precio>\n";
        archivo << "         <anio>" << autos[i].anio << "</anio>\n";
        archivo << "      </auto>\n";
    }

    archivo << "   </autos>\n";

    archivo << "   <personas>\n";

    for(int i = 0; i < contPersonas; i++) {
        archivo << "      <persona>\n";
        archivo << "         <nombre>" << personas[i].nombre << "</nombre>\n";
        archivo << "         <apellidoPaterno>" << personas[i].ap << "</apellidoPaterno>\n";
        archivo << "         <apellidoMaterno>" << personas[i].am << "</apellidoMaterno>\n";
        archivo << "         <genero>" << personas[i].genero << "</genero>\n";
        archivo << "         <edad>" << personas[i].edad << "</edad>\n";
        archivo << "      </persona>\n";
    }

    archivo << "   </personas>\n";
    archivo << "</datos>\n";

    archivo.close();
}

#endif