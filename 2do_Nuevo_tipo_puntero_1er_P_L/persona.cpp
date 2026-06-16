#include <iostream>
#include <fstream>
#include "persona.h"

using namespace std;

void ListaPersonas::llenar() {

    for (int i = 0; i < 3; i++) {

        cout << "Nombre: ";
        cin >> personas[i].nombre;

        cout << "Edad: ";
        cin >> personas[i].edad;
    }

    ofstream txt("datos.txt");

    txt << "LISTA DE PERSONAS\n\n";

    for (int i = 0; i < 3; i++) {
        txt << "Nombre: " << personas[i].nombre << endl;
        txt << "Edad: " << personas[i].edad << endl;
        txt << "------------------" << endl;
    }

    txt.close();


    ofstream csv("datos.csv");

    csv << "Nombre,Edad" << endl;

    for (int i = 0; i < 3; i++) {
        csv << personas[i].nombre << ","
            << personas[i].edad << endl;
    }

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<personas>" << endl;

    for (int i = 0; i < 3; i++) {
        xml << "  <persona>" << endl;
        xml << "    <nombre>"
            << personas[i].nombre
            << "</nombre>" << endl;

        xml << "    <edad>"
            << personas[i].edad
            << "</edad>" << endl;

        xml << "  </persona>" << endl;
    }

    xml << "</personas>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;
    html << "<h1>Lista de Personas</h1>" << endl;

    for (int i = 0; i < 3; i++) {

        html << "<p>";
        html << personas[i].nombre;
        html << " - ";
        html << personas[i].edad;
        html << "</p>" << endl;
    }

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;
    json << "\"personas\":[" << endl;

    for (int i = 0; i < 3; i++) {

        json << "{";
        json << "\"nombre\":\""
             << personas[i].nombre
             << "\",";

        json << "\"edad\":"
             << personas[i].edad;

        json << "}";

        if (i < 2)
            json << ",";

        json << endl;
    }

    json << "]" << endl;
    json << "}" << endl;

    json.close();
}

void ListaPersonas::mostrar() {

    Persona *p = personas;

    for (int i = 0; i < 3; i++) {

        cout << "Nombre: "
             << (p + i)->nombre
             << endl;

        cout << "Edad: "
             << (p + i)->edad
             << endl;

        cout << "----\n";
    }
}
