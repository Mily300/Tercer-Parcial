#include <iostream>
#include <fstream>
#include "pila.h"

using namespace std;

Pila::Pila() {
    tope = -1;
}

void Pila::guardarArchivos() {

    ofstream txt("datos.txt");

    txt << "PILA" << endl;

    if(tope == -1){
        txt << "Pila vacia";
    } else {
        for(int i = tope; i >= 0; i--){
            txt << datos[i] << endl;
        }
    }

    txt.close();


    ofstream csv("datos.csv");

    csv << "Valor" << endl;

    for(int i = tope; i >= 0; i--){
        csv << datos[i] << endl;
    }

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<pila>" << endl;

    for(int i = tope; i >= 0; i--){
        xml << "  <dato>"
            << datos[i]
            << "</dato>" << endl;
    }

    xml << "</pila>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;
    html << "<h1>Pila</h1>" << endl;

    for(int i = tope; i >= 0; i--){
        html << "<p>"
             << datos[i]
             << "</p>" << endl;
    }

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;
    json << "\"pila\":[";

    for(int i = tope; i >= 0; i--){

        json << datos[i];

        if(i > 0)
            json << ",";
    }

    json << "]" << endl;
    json << "}" << endl;

    json.close();
}

void Pila::push(int valor) {

    if(tope < 4){

        tope++;
        datos[tope] = valor;

        guardarArchivos();

    } else {

        cout << "Pila llena\n";
    }
}

void Pila::pop() {

    if(tope >= 0){

        tope--;

        guardarArchivos();

    } else {

        cout << "Pila vacia\n";
    }
}

void Pila::mostrar() {

    if(tope == -1){

        cout << "Pila vacia\n";
        return;
    }

    for(int i = tope; i >= 0; i--){
        cout << datos[i] << endl;
    }
}
