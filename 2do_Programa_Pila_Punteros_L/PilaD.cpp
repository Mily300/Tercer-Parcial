#include <iostream>
#include <fstream>
#include "pilaD.h"

using namespace std;

PilaD::PilaD() {
    tope = NULL;
}

void PilaD::guardarArchivos() {

    ofstream txt("datos.txt");

    txt << "PILA DINAMICA" << endl;

    Nodo* aux = tope;

    if(aux == NULL){
        txt << "Pila vacia";
    }

    while(aux != NULL){
        txt << aux->dato << endl;
        aux = aux->sig;
    }

    txt.close();


    ofstream csv("datos.csv");

    csv << "Valor" << endl;

    aux = tope;

    while(aux != NULL){
        csv << aux->dato << endl;
        aux = aux->sig;
    }

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<pila>" << endl;

    aux = tope;

    while(aux != NULL){
        xml << "  <dato>"
            << aux->dato
            << "</dato>" << endl;

        aux = aux->sig;
    }

    xml << "</pila>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;
    html << "<h1>Pila Dinamica</h1>" << endl;

    aux = tope;

    while(aux != NULL){
        html << "<p>"
             << aux->dato
             << "</p>" << endl;

        aux = aux->sig;
    }

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;
    json << "\"pila\":[";

    aux = tope;

    while(aux != NULL){

        json << aux->dato;

        if(aux->sig != NULL)
            json << ",";

        aux = aux->sig;
    }

    json << "]" << endl;
    json << "}" << endl;

    json.close();
}

void PilaD::push(int valor) {

    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->sig = tope;
    tope = nuevo;

    guardarArchivos();
}

void PilaD::pop() {

    if (tope != NULL) {

        Nodo* temp = tope;
        tope = tope->sig;

        delete temp;

        guardarArchivos();

    } else {

        cout << "Pila vacia\n";
    }
}

void PilaD::mostrar() {

    if (tope == NULL) {

        cout << "Pila vacia\n";
        return;
    }

    Nodo* aux = tope;

    while (aux != NULL) {

        cout << aux->dato << endl;
        aux = aux->sig;
    }
}
