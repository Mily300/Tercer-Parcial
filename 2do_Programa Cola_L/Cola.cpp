#include <iostream>
#include <fstream>
#include "cola.h"

using namespace std;

Cola::Cola() {
    inicio = 0;
    fin = -1;
}

void Cola::guardarArchivos() {

    ofstream txt("datos.txt");

    txt << "COLA\n";

    if(inicio > fin){
        txt << "Cola vacia";
    } else {
        for(int i = inicio; i <= fin; i++){
            txt << datos[i] << endl;
        }
    }

    txt.close();


    ofstream csv("datos.csv");

    csv << "Valor" << endl;

    for(int i = inicio; i <= fin; i++){
        csv << datos[i] << endl;
    }

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<cola>" << endl;

    for(int i = inicio; i <= fin; i++){
        xml << "  <dato>"
            << datos[i]
            << "</dato>" << endl;
    }

    xml << "</cola>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;
    html << "<h1>Cola</h1>" << endl;

    for(int i = inicio; i <= fin; i++){
        html << "<p>"
             << datos[i]
             << "</p>" << endl;
    }

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;
    json << "\"cola\":[";

    for(int i = inicio; i <= fin; i++){

        json << datos[i];

        if(i < fin)
            json << ",";
    }

    json << "]" << endl;
    json << "}" << endl;

    json.close();
}

void Cola::encolar(int valor) {

    if (fin < 4) {

        fin++;
        datos[fin] = valor;

        guardarArchivos();

    } else {

        cout << "Cola llena\n";
    }
}

void Cola::desencolar() {

    if (inicio <= fin) {

        inicio++;

        guardarArchivos();

    } else {

        cout << "Cola vacia\n";
    }
}

void Cola::mostrar() {

    if (inicio > fin) {

        cout << "Cola vacia\n";
        return;
    }

    for (int i = inicio; i <= fin; i++) {
        cout << datos[i] << endl;
    }
}
